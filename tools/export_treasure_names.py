#!/usr/bin/env python3
"""Export the names the treasure .bin editor shows (items, options, monsters) to a JSON file.

    python3 tools/export_treasure_names.py                # writes Tools/BinEditor/names.json in the client repo
    python3 tools/export_treasure_names.py --out x.json   # or anywhere else

Run it from WSL (it uses the mysql client through db/dbconn.py, so the same DE_DB_* env vars or
--host/--user/--password/--db flags apply). Re-run it after adding items, options or monsters so
the editor's drop-downs know about them. The editor works without the file, it just shows numbers.

What goes in:
  item_classes   ItemClass id -> enum name (from src/server/gameserver/Item.h)
  items          per class: ItemType -> EName, native name, ItemLevel, unique flag; plus the class's
                 MAX(ItemType), which is what TreasureItemType::loadFromFile accepts (isPossibleItem)
  options        OptionType -> EName, nickname (STR+1), native name, option class, level
  monsters       every MonsterInfo row: type, names, level, class, chief/regen/treasure flags and the
                 .bin base name the gameserver derives for it (MonsterInfo.cpp ~735)
  server_vars    the AttrInfo knobs the roll math uses (3 ITEM_PROBE_RATIO, 9 PREMIUM_ITEM_PROBE_PERCENT,
                 18 UNIQUE_ITEM_RATIO, 55 CHIEF_ITEM_BONUS_NUM)
"""
import argparse
import datetime
import json
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..'))
sys.path.insert(0, os.path.join(ROOT, 'db'))
from dbconn import MySQL, add_connection_args  # noqa: E402

ITEM_H = os.path.join(ROOT, 'src', 'server', 'gameserver', 'Item.h')
INFO_MANAGER_CPP = os.path.join(ROOT, 'src', 'server', 'gameserver', 'ItemInfoManager.cpp')
DEFAULT_OUT_CANDIDATES = [
    '/mnt/d/GitHub/DEClient_v664/Tools/BinEditor/names.json',
    os.path.join(HERE, 'treasure_names.json'),
]
SERVER_VARS = {3: 'ITEM_PROBE_RATIO', 9: 'PREMIUM_ITEM_PROBE_PERCENT', 18: 'UNIQUE_ITEM_RATIO',
               55: 'CHIEF_ITEM_BONUS_NUM'}


def rows(db, sql):
    """Like MySQL.query, but split on newlines only: str.splitlines() also breaks on U+0085 and friends,
    which the mojibake native-name columns contain."""
    p = subprocess.run(db._base + ['-N', '-B', '--default-character-set=utf8mb4', db.db],
                       input=sql.encode('utf-8'), capture_output=True)
    if p.returncode:
        sys.exit('mysql failed: ' + p.stderr.decode('utf-8', 'replace').strip())
    return [line.split(chr(9)) for line in p.stdout.decode('utf-8', 'replace').split(chr(10)) if line != '']


def item_classes():
    """ItemClass id -> enum name, in enum order (the comments in Item.h are not trusted)."""
    src = open(ITEM_H, encoding='latin1').read()
    body = re.search(r'enum\s+ItemClass\s*\{(.*?)\}', src, re.S).group(1)
    names = []
    for line in body.splitlines():
        line = line.split('//')[0].strip().rstrip(',')
        if line.startswith('ITEM_CLASS_') and line != 'ITEM_CLASS_MAX':
            names.append(line[len('ITEM_CLASS_'):])
    return {i: n for i, n in enumerate(names)}


def class_tables(classes):
    """ItemClass id -> *Info table, from the m_InfoClassManagers[...] = g_pXInfoManager lines."""
    src = open(INFO_MANAGER_CPP, encoding='latin1').read()
    by_name = {n: i for i, n in classes.items()}
    out = {}
    for enum_name, mgr in re.findall(r'm_InfoClassManagers\[Item::ITEM_CLASS_(\w+)\]\s*=\s*g_p(\w+)InfoManager', src):
        if enum_name in by_name:
            out[by_name[enum_name]] = mgr + 'Info'
    return out


def native(s):
    """The Name columns hold CP949 (or GBK) bytes read back as latin1; show them as text when they decode."""
    try:
        raw = s.encode('latin1')
    except UnicodeEncodeError:
        return s
    for enc in ('cp949', 'gbk'):
        try:
            return raw.decode(enc)
        except UnicodeDecodeError:
            pass
    return s


REQ_KEYS = {'STR': 'STR %s', 'DEX': 'DEX %s', 'INT': 'INT %s', 'LEV': 'Lv %s', 'SUM': 'stat sum %s',
            'ADV': 'Adv %s', 'GEN': None}


def requirement(req_ability):
    """'(GEN,1)(SUM,30)' -> 'M, stat sum 30' (ItemInfo.cpp parseReqAbility keys: STR DEX INT LEV GEN SUM ADV)."""
    parts = []
    for key, val in re.findall(r'\(([A-Z]+),(\d+)\)', req_ability or ''):
        if key == 'GEN':
            parts.append({'1': 'M', '2': 'F'}.get(val, 'GEN ' + val))
        elif key in REQ_KEYS:
            parts.append(REQ_KEYS[key] % val)
        else:
            parts.append('%s %s' % (key, val))
    return ', '.join(parts)


def bin_base(ename, monster_class):
    if monster_class:
        return 'Class%d' % monster_class
    base = ename.split('[')[0]
    return base.replace(' ', '')


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--out', help='output file (default: the client Tools/BinEditor/names.json if that folder exists)')
    add_connection_args(ap)
    args = ap.parse_args()
    out = args.out
    if not out:
        for cand in DEFAULT_OUT_CANDIDATES:
            if os.path.isdir(os.path.dirname(cand)):
                out = cand
                break

    db = MySQL(args)
    classes = item_classes()
    tables = class_tables(classes)
    existing = {r[0] for r in rows(db, "SELECT TABLE_NAME FROM information_schema.TABLES WHERE TABLE_SCHEMA=DATABASE()")}

    unique = set()
    for r in rows(db, "SELECT ItemClass, ItemType FROM UniqueItemInfo"):
        unique.add((int(r[0]), int(r[1])))

    items = {}
    for cid in sorted(classes):
        table = tables.get(cid)
        entry = {'table': table, 'max_type': None, 'types': {}}
        if table and table in existing:
            cols = {r[0] for r in rows(db, 
                "SELECT COLUMN_NAME FROM information_schema.COLUMNS WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME='%s'" % table)}
            sel = ['ItemType',
                   'EName' if 'EName' in cols else "''",
                   'Name' if 'Name' in cols else "''",
                   'ItemLevel' if 'ItemLevel' in cols else '0',
                   'ReqAbility' if 'ReqAbility' in cols else "''"]
            found = rows(db, "SELECT %s FROM %s ORDER BY ItemType" % (', '.join(sel), table))
            for r in found:
                t = int(r[0])
                rec = {'e': r[1], 'n': native(r[2])}
                if r[3] not in ('0', '', 'NULL'):
                    rec['tier'] = int(r[3])     # ItemLevel: the server's item tier index, not a player requirement
                req = requirement(r[4])
                if req:
                    rec['req'] = req
                if (cid, t) in unique:
                    rec['unique'] = True
                entry['types'][t] = rec
            if found:
                entry['max_type'] = max(entry['types'])
        items[cid] = entry

    options = {}
    for r in rows(db, "SELECT OptionType, Name, Nickname, HName, Class, OptionLevel FROM OptionInfo ORDER BY OptionType"):
        options[int(r[0])] = {'e': r[1], 'nick': r[2], 'n': native(r[3]), 'cls': int(r[4]), 'lvl': int(r[5])}

    monsters = []
    for r in rows(db, "SELECT MType, EName, HName, IFNULL(Level,0), MonsterClass, Chief, NormalRegen, HasTreasure "
                      "FROM MonsterInfo ORDER BY MType"):
        mtype, ename, hname, level, mclass, chief, regen, treasure = r
        monsters.append({'t': int(mtype), 'e': ename, 'n': native(hname), 'lvl': int(level), 'cls': int(mclass),
                         'chief': int(chief), 'regen': int(regen), 'treasure': int(treasure),
                         'bin': bin_base(ename, int(mclass))})

    server_vars = {}
    for r in rows(db, "SELECT attrID, attr1, comm FROM AttrInfo WHERE attrID IN (%s)" % ','.join(map(str, SERVER_VARS))):
        server_vars[SERVER_VARS[int(r[0])]] = {'id': int(r[0]), 'value': int(r[1]), 'comment': r[2]}

    doc = {
        'generated': datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S'),
        'item_classes': {str(k): v for k, v in classes.items()},
        'items': {str(k): {'table': v['table'], 'max_type': v['max_type'],
                           'types': {str(t): rec for t, rec in v['types'].items()}} for k, v in items.items()},
        'options': {str(k): v for k, v in options.items()},
        'monsters': monsters,
        'server_vars': server_vars,
    }
    with open(out, 'w', encoding='utf-8') as f:
        json.dump(doc, f, ensure_ascii=False, indent=1)
    n_items = sum(len(v['types']) for v in items.values())
    print('%s: %d item classes, %d item types, %d options, %d monsters' % (out, len(classes), n_items, len(options), len(monsters)))


if __name__ == '__main__':
    main()
