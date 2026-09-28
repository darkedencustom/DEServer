#!/usr/bin/env python3
"""Level-matched pre-JC skill book drops for the regular field monsters.

    python3 tools/gen_skillbook_drops.py            show the plan, change nothing
    python3 tools/gen_skillbook_drops.py --write    rewrite data/Class1-14.<race>.bin

Regular monsters share one drop file per tier: MonsterInfo.MonsterClass N (the [N] in "Hoble [4]") loads
data/ClassN.slayer/.vampire/.ousters.bin (MonsterInfo.cpp ~735), and chiefs of that tier use the same files.
Before this, only tiers 3, 5, 6 and 12 dropped books, from inside their main loot entry, and every one of
them offered the same books whatever the tier's level (a level 25 Big Fang could drop Magic Shield 2).
Their weights also summed past 100,000, so the entries after that point (Magma Detonation) never dropped.

Now each tier file gets one extra treasure entry that holds only item class 97 (skill books):
  * the books of that race whose skill level S fits the tier, i.e. the tier's regular monster levels
    overlap [S - WINDOW_BELOW, S + WINDOW_ABOVE];
  * ratios 999999, so the entry always rolls (the common setting in these files; Treasure::loadFromFile
    keeps 999999 and forces anything else to 40000), and the chance is exactly the type weights:
    BOOK_CHANCE per kill for "a book for the killer's race", split evenly across the eligible books,
    with no single book above BOOK_CAP;
  * the old book class inside the main entry is set to ratio 0 (the loader skips it), so books come only
    from the level-matched entry. Bosses and named monsters (Tepez, Bathory, ...) and Class15+ are untouched.
The entry is an independent roll, so books come on top of the normal loot. A chief that drops one re-rolls
the same entry up to CHIEF_ITEM_BONUS_NUM (4) more times, so chiefs are slightly better sources.

Safe to run twice: a previous book-only entry is replaced, not added again. The gameserver reads these files
at boot: restart it after --write. Undo: git checkout data/Class*.bin.
"""
import argparse
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DATA = os.path.join(HERE, '..', 'data')

BOOK_CHANCE = 1 / 500      # per kill, any book for the killer's race, split across the eligible books ...
BOOK_CAP = 1 / 1500        # ... but no single book more likely than this (a tier with 1-2 books drops less)
WINDOW_BELOW = 10          # a book drops from monsters up to this many levels under its skill level
WINDOW_ABOVE = 25          # ... and up to this many levels over it
ITEM_CLASS_SKILL_BOOK = 97
RATIO_MODULUS = 100000     # TREASURE_RATIO_MODULUS: item types are picked out of this
CLASS_RATIO = 100000       # only class in the entry; a pick of exactly 0 misses (Treasure.cpp ~887)

# Regular (NormalRegen, non-chief) monster levels per tier, from MonsterInfo (2026-09-28).
TIERS = {
    1: (1, 2),      # Kid, Turning Soul, Dead Body, Turning Dead
    2: (5, 20),     # Soldier, Alcan, Captain, Iron Teeth, Mutant, Red Eye
    3: (23, 38),    # Big Fang, Estroider, Widows, Moderas, Vandalizer, Dirty Strider
    4: (35, 45),    # Hoble, Blood Warlock, Golemer
    5: (50, 58),    # Shadow Wing, Reaper, Crimson Slaughter
    6: (60, 66),    # Chaos Knight, Dark Screamer, Hell Wizard
    7: (70, 73),    # Chaos Guardian, Hell Guardian
    8: (99, 99),    # Dark Guardian, Lord Chaos
    9: (90, 90),    # Lord Darkness
    10: (86, 100),  # Chaos Greed, Dark Haze, Hell Fiend, Mum Rimmon, Shaman Oaf, ...
    11: (96, 110),  # Dark Berith, Dim Gargoyle, Flieger, Gefreiter, Mutant Edger, Tug Leg
    12: (112, 118), # Bone Guardian, Giant Os, Hauptmann, Mount Crag, Siamese
    13: (124, 128), # Lunga Testa, Volva Medusa
    14: (132, 194), # Lich Jel, Ash Balog, Icy Ruffian, Tug Legger, Roi Cadavru, Oberst, ...
}

# Pre-JC books: SkillBookInfo ItemType -> (name, SkillBalance.Level, races). Races as SkillBookInfo.Race bits.
SLAYER, VAMPIRE, OUSTERS = 1, 2, 4
BOOKS = {
    4: ('Freeze Ring 1', 20, SLAYER),
    8: ('Curse Of Blood 1', 20, VAMPIRE),
    14: ('Mist Of Soul 1', 20, OUSTERS),
    6: ('Bat Storm 1', 30, VAMPIRE),
    10: ('Blood Drain 2', 40, VAMPIRE),
    11: ('Bloody Shout 1', 50, VAMPIRE),
    17: ('Magic Avoid 1', 50, SLAYER | VAMPIRE | OUSTERS),
    37: ('Magma Detonation 1', 50, SLAYER),
    39: ('Squally Barrier 1', 50, OUSTERS),
    0: ('Magic Shield 1', 60, SLAYER),
    2: ("Eagle's Eye 1", 60, SLAYER),
    16: ('Energy Burst', 60, OUSTERS),
    5: ('Freeze Ring 2', 80, SLAYER),
    9: ('Curse Of Blood 2', 80, VAMPIRE),
    12: ('Bloody Shout 2', 80, VAMPIRE),
    13: ('Bloody Wings', 80, VAMPIRE),
    15: ('Mist Of Soul 2', 80, OUSTERS),
    7: ('Bat Storm 2', 100, VAMPIRE),
    18: ('Magic Avoid 2', 100, SLAYER | VAMPIRE | OUSTERS),
    38: ('Magma Detonation 2', 100, SLAYER),
    40: ('Squally Barrier 2', 100, OUSTERS),
    1: ('Magic Shield 2', 120, SLAYER),
    3: ("Eagle's Eye 2", 120, SLAYER),
    19: ('Magic Avoid 3', 150, SLAYER | VAMPIRE | OUSTERS),
}
RACES = (('slayer', SLAYER), ('vampire', VAMPIRE), ('ousters', OUSTERS))


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
    return len(t['classes']) == 1 and t['classes'][0]['itemClass'] == ITEM_CLASS_SKILL_BOOK


def eligible(tier, race_bit):
    lo, hi = TIERS[tier]
    return sorted((level, item_type) for item_type, (_, level, races) in BOOKS.items()
                  if races & race_bit and lo <= level + WINDOW_ABOVE and hi >= level - WINDOW_BELOW)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--write', action='store_true', help='rewrite the files (default: show the plan)')
    args = ap.parse_args()

    total = round(BOOK_CHANCE * RATIO_MODULUS)
    cap = round(BOOK_CAP * RATIO_MODULUS)
    print('book chance per kill: 1 in %d split across the eligible books, at most 1 in %d per book; '
          'window skill level -%d / +%d'
          % (round(1 / BOOK_CHANCE), round(1 / BOOK_CAP), WINDOW_BELOW, WINDOW_ABOVE))
    changed = 0
    for tier in sorted(TIERS):
        print('\nClass%d (monster levels %d-%d)' % ((tier,) + TIERS[tier]))
        for race, bit in RACES:
            path = os.path.join(DATA, 'Class%d.%s.bin' % (tier, race))
            before = open(path, 'rb').read()
            treasures = [t for t in read_bin(path) if not is_book_entry(t)]
            muted = 0
            for t in treasures:
                for c in t['classes']:
                    if c['itemClass'] == ITEM_CLASS_SKILL_BOOK and c['ratio']:
                        c['ratio'] = 0
                        muted += 1
            books = eligible(tier, bit)
            if books:
                share = min(total // len(books), cap)
                treasures.append({'ratios': [999999] * 4, 'classes': [{
                    'itemClass': ITEM_CLASS_SKILL_BOOK, 'ratio': CLASS_RATIO,
                    'types': [{'itemType': it, 'ratio': share, 'options': []} for _, it in books]}]})
            after = pack_bin(treasures)
            if books:
                listing = ', '.join('%s (%d)' % (BOOKS[it][0], lv) for lv, it in books)
                print('  %-7s any 1 in %-5d each 1 in %-5d %s' % (
                    race, round(RATIO_MODULUS / (share * len(books))), round(RATIO_MODULUS / share), listing))
            else:
                print('  %-7s no books' % race)
            if muted:
                print('          old flat book entry switched off')
            if after != before:
                changed += 1
                if args.write:
                    open(path, 'wb').write(after)
                    if read_bin(path) != treasures:
                        sys.exit('%s: read-back mismatch' % path)
    print('\n%d file(s) %s' % (changed, 'written - restart the gameserver' if args.write else 'would change (dry run)'))


if __name__ == '__main__':
    main()
