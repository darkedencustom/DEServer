#!/usr/bin/env python3
"""Heart of Cabracam drop rate for the Menegroth floor monsters.

    python3 tools/set_menegroth_heart_drops.py            show the plan, change nothing
    python3 tools/set_menegroth_heart_drops.py --write    rewrite the 18 floor-monster .bin files

Each Menegroth floor (zones 1701-1718, one per race per floor) spawns one monster family, MonsterInfo 928-945,
none of them chiefs. They have MonsterClass 0, so they load data/<EName>.<race>.bin (MonsterInfo.cpp ~735), and
no other monster shares those files. Every file has a single loot entry, and the floor's heart (CommonQuestItem,
item class 91, types 12-17) sat inside it as one class at ratio 1000 of ~100,000, about 1 in 100 per kill.
It takes 4 hearts to open a floor's Cabracam, so that was ~400 kills per floor.

Now each file gets one extra treasure entry that holds only the floor's heart:
  * ratios 999999, so the entry always rolls (Treasure::loadFromFile keeps 999999 and forces anything else
    to 40000), and the chance is exactly the type weight: HEART_CHANCE per kill;
  * the old heart class inside the main entry is set to ratio 0, so hearts come only from the new entry.
The entry is an independent roll, so hearts come on top of the normal loot, which keeps its old odds.
The Cabracam bosses (Cabracam1-6.<race>.bin, 1 in 100 for their own floor's heart) are untouched.

Safe to run twice: a previous heart-only entry is replaced, not added again. The gameserver reads these files
at boot: restart it after --write. Undo: git checkout on the 18 files listed by the dry run.
"""
import argparse
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DATA = os.path.join(HERE, '..', 'data')

HEART_CHANCE = 0.10        # per kill, the floor's heart
ITEM_CLASS_COMMON_QUEST_ITEM = 91
RATIO_MODULUS = 100000     # TREASURE_RATIO_MODULUS: item types are picked out of this
CLASS_RATIO = 100000       # only class in the entry; a pick of exactly 0 misses (Treasure.cpp ~887)

# Floor monster file base name -> Heart of Cabracam item type (CommonQuestItemInfo 12-17).
FLOORS = (
    ('Cerberus', 12),      # B1, MonsterInfo 928-930
    ('Manticoret', 13),    # B2, 931-933
    ('BogletH', 14),       # B3, 934-936
    ('BogletB', 15),       # B4, 937-939
    ('Massacre', 16),      # B5, 940-942
    ('PlumpyBoar', 17),    # B6, 943-945
)
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


def is_heart_entry(t, heart):
    # Only this floor's heart-only entry. Other single-purpose class 91 entries (the Burned Original Book from
    # tools/set_burned_book_drops.py sits in PlumpyBoar) belong to other tools and must survive a re-run.
    return (len(t['classes']) == 1 and t['classes'][0]['itemClass'] == ITEM_CLASS_COMMON_QUEST_ITEM
            and [ty['itemType'] for ty in t['classes'][0]['types']] == [heart])


def is_single_class_entry(t):
    return len(t['classes']) == 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--write', action='store_true', help='rewrite the files (default: show the plan)')
    args = ap.parse_args()

    weight = round(HEART_CHANCE * RATIO_MODULUS)
    print('heart chance per kill: 1 in %g' % (RATIO_MODULUS / weight))
    changed = 0
    for name, heart in FLOORS:
        for race in RACES:
            path = os.path.join(DATA, '%s.%s.bin' % (name, race))
            before = open(path, 'rb').read()
            loaded = read_bin(path)
            # keep the heart entry where it is (other tools append their own entries after it)
            slot = next((i for i, t in enumerate(loaded) if is_heart_entry(t, heart)), None)
            treasures = [t for t in loaded if not is_heart_entry(t, heart)]
            old = []
            for t in treasures:
                if is_single_class_entry(t):
                    continue            # another tool's entry; the old heart slot was inside the main entry
                for c in t['classes']:
                    if c['itemClass'] == ITEM_CLASS_COMMON_QUEST_ITEM and c['ratio']:
                        if [ty['itemType'] for ty in c['types']] != [heart]:
                            sys.exit('%s: class %d holds %s, expected only type %d' % (
                                path, c['itemClass'], [ty['itemType'] for ty in c['types']], heart))
                        old.append(c['ratio'])
                        c['ratio'] = 0
            treasures.insert(len(treasures) if slot is None else slot, {'ratios': [999999] * 4, 'classes': [{
                'itemClass': ITEM_CLASS_COMMON_QUEST_ITEM, 'ratio': CLASS_RATIO,
                'types': [{'itemType': heart, 'ratio': weight, 'options': []}]}]})
            after = pack_bin(treasures)
            print('  %-24s heart type %d  %s' % (
                os.path.basename(path), heart,
                'old main-entry slot %s switched off' % old if old else 'no old slot'))
            if after != before:
                changed += 1
                if args.write:
                    open(path, 'wb').write(after)
                    if read_bin(path) != treasures:
                        sys.exit('%s: read-back mismatch' % path)
    print('\n%d file(s) %s' % (changed, 'written - restart the gameserver' if args.write else 'would change (dry run)'))


if __name__ == '__main__':
    main()
