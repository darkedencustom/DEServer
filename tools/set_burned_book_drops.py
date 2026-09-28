#!/usr/bin/env python3
"""Burned Original Book (CommonQuestItem 53) drops for the monsters a JC (level 150+) character hunts.

    python3 tools/set_burned_book_drops.py            show the plan, change nothing
    python3 tools/set_burned_book_drops.py --write    rewrite the chosen data/<base>.<race>.bin files

The book is the currency for the JC skill books (the exchange NPC comes later). It used to be a hardcoded
1 in 300 roll in MonsterManager::addItem; it now lives in the loot files like every other drop, so it shows
up in Tools/BinEditor and can be tuned there.

Which files: MonsterInfo decides, read live from the database (HasTreasure = 1 rows only, grouped by the .bin
base the gameserver derives - MonsterInfo.cpp ~735). A file gets the book when
  * every monster that loads it is level >= JC_LEVEL (bosses, named monsters, Class19/50/93/94, Hell Garden...), or
  * its regular (non-chief) monsters reach JC_LEVEL: the tier files Class14 and Class15 and PlumpyBoar, where JC
    characters hunt the field monsters. Their lower-level members (Class14 starts at 132) drop it too.
Class9-12 are left out: only a few high-level chiefs there pass 150, their field monsters stop at 118.

What goes in: one extra treasure entry holding only the book:
  * ratios 999999, so the entry always rolls (Treasure::loadFromFile keeps 999999, forces anything else to 40000);
  * item class 91 at class ratio 100000 (the only class; a class wins (ratio-1)/total of the time);
  * item type 53 at weight 100000 * BOOK_CHANCE out of the fixed 100000 type range.
It is an independent roll, on top of the file's normal loot. A chief that drops the book re-rolls that entry up
to CHIEF_ITEM_BONUS_NUM (4) more times.

Safe to run twice: an existing book-only entry is replaced, not added again. The gameserver reads the files at
boot: restart it after --write. Undo: git checkout on the files the dry run lists.
"""
import argparse
import collections
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..'))
DATA = os.path.join(ROOT, 'data')
sys.path.insert(0, os.path.join(ROOT, 'db'))
sys.path.insert(0, HERE)
from dbconn import MySQL, add_connection_args  # noqa: E402
from export_treasure_names import rows, bin_base  # noqa: E402

JC_LEVEL = 150
BOOK_CHANCE = 1 / 300          # per kill
ITEM_CLASS_COMMON_QUEST_ITEM = 91
BOOK_TYPE = 53                 # CommonQuestItemInfo 53, migration 1.3.4
RATIO_MODULUS = 100000         # TREASURE_RATIO_MODULUS
CLASS_RATIO = 100000
RACES = ('slayer', 'vampire', 'ousters')


def read_bin(path):
    d = open(path, 'rb').read()
    o = 0

    def i32():
        nonlocal o
        v = struct.unpack_from('<i', d, o)[0]
        o += 4
        return v
    treasures = []
    for _ in range(i32()):
        t = {'ratios': [i32(), i32(), i32(), i32()], 'classes': []}
        for _ in range(i32()):
            c = {'itemClass': i32(), 'ratio': i32(), 'types': []}
            for _ in range(i32()):
                ty = {'itemType': i32(), 'ratio': i32(), 'options': []}
                for _ in range(i32()):
                    ty['options'].append((i32(), i32()))
                c['types'].append(ty)
            t['classes'].append(c)
        treasures.append(t)
    if o != len(d):
        sys.exit('%s: parsed %d of %d bytes' % (path, o, len(d)))
    return treasures


def pack_bin(treasures):
    out = [struct.pack('<i', len(treasures))]
    for t in treasures:
        out.append(struct.pack('<5i', *t['ratios'], len(t['classes'])))
        for c in t['classes']:
            out.append(struct.pack('<3i', c['itemClass'], c['ratio'], len(c['types'])))
            for ty in c['types']:
                out.append(struct.pack('<3i', ty['itemType'], ty['ratio'], len(ty['options'])))
                for opt in ty['options']:
                    out.append(struct.pack('<2i', *opt))
    return b''.join(out)


def is_book_entry(t):
    return (len(t['classes']) == 1 and t['classes'][0]['itemClass'] == ITEM_CLASS_COMMON_QUEST_ITEM
            and [ty['itemType'] for ty in t['classes'][0]['types']] == [BOOK_TYPE])


def book_entry(weight):
    return {'ratios': [999999] * 4, 'classes': [{
        'itemClass': ITEM_CLASS_COMMON_QUEST_ITEM, 'ratio': CLASS_RATIO,
        'types': [{'itemType': BOOK_TYPE, 'ratio': weight, 'options': []}]}]}


def choose_files(db):
    """base -> (reason, monsters) for every .bin base that should carry the book."""
    by_bin = collections.defaultdict(list)
    for mtype, ename, level, mclass, chief in rows(db, 'SELECT MType, EName, IFNULL(Level,0), MonsterClass, Chief '
                                                    'FROM MonsterInfo WHERE HasTreasure = 1'):
        by_bin[bin_base(ename, int(mclass))].append((int(mtype), ename, int(level), int(chief)))
    chosen, skipped = {}, {}
    for base, ms in sorted(by_bin.items()):
        if not all(os.path.exists(os.path.join(DATA, '%s.%s.bin' % (base, r))) for r in RACES):
            if any(m[2] >= JC_LEVEL for m in ms):
                skipped[base] = 'no .bin file'
            continue
        levels = [m[2] for m in ms]
        regular = [m[2] for m in ms if not m[3]]
        if min(levels) >= JC_LEVEL:
            chosen[base] = ('all level %d-%d' % (min(levels), max(levels)), ms)
        elif regular and max(regular) >= JC_LEVEL:
            chosen[base] = ('field monsters reach %d (file spans %d-%d)' % (max(regular), min(levels), max(levels)), ms)
        elif max(levels) >= JC_LEVEL:
            skipped[base] = 'only chiefs reach 150 (field monsters stop at %d)' % max(regular or [0])
    return chosen, skipped


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--write', action='store_true', help='rewrite the files (default: show the plan)')
    add_connection_args(ap)
    args = ap.parse_args()

    weight = round(BOOK_CHANCE * RATIO_MODULUS)
    print('book chance per kill: 1 in %.0f (type weight %d of %d)' % (
        RATIO_MODULUS / (weight * (CLASS_RATIO - 1) / CLASS_RATIO), weight, RATIO_MODULUS))
    chosen, skipped = choose_files(MySQL(args))

    changed = 0
    for base, (reason, ms) in sorted(chosen.items()):
        print('  %-24s %s' % (base, reason))
        for race in RACES:
            path = os.path.join(DATA, '%s.%s.bin' % (base, race))
            before = open(path, 'rb').read()
            treasures = [t for t in read_bin(path) if not is_book_entry(t)]
            for t in treasures:
                for c in t['classes']:
                    if c['itemClass'] == ITEM_CLASS_COMMON_QUEST_ITEM and any(
                            ty['itemType'] == BOOK_TYPE for ty in c['types']):
                        sys.exit('%s: the book is already inside another entry; fix that by hand first' % path)
            treasures.append(book_entry(weight))
            after = pack_bin(treasures)
            if after != before:
                changed += 1
                if args.write:
                    open(path, 'wb').write(after)
                    if read_bin(path) != treasures:
                        sys.exit('%s: read-back mismatch' % path)
    print('\nleft out:')
    for base, why in sorted(skipped.items()):
        print('  %-24s %s' % (base, why))
    print('\n%d file(s) in %d bases %s' % (changed, len(chosen),
                                           'written - restart the gameserver' if args.write else 'would change (dry run)'))


if __name__ == '__main__':
    main()
