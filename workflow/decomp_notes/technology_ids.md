# Technology ID names

## Scope

The starting commit is `8a96e8bf8`.
This change adds `TECH_*` macros to `include/tech.h` and uses them where code passes or compares a research ID.
A technology ID is the index into `TRIBE_Tech::tech_tree`. AI build lists use the same IDs on `R` lines.
`src/taibldmd.cpp` now includes `tech.h`. No layouts, signatures, locals, or registry entries changed.

## Name source

Each name is the record name stored in the game data.
The macro spelling uppercases it and turns each run of other characters into `_`,
so `Tool Age` becomes `TECH_TOOL_AGE` and `TC -> Granary` becomes `TECH_TC_GRANARY`.

- File: `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/data2/empires.dat`,
  SHA256 `5ea86fadafc9f92dcc692d6210f377a1f6c0d82280b5b2a30a46b492b7c5253c`.
- `TRIBE_World::world_init` reads the `TRIBE_Tech` section last.
  `build/cleanup-2026-10-10/dat_techs.py` reads it with the field order of
  `TRIBE_Tech::TRIBE_Tech(int, TRIBE_World*)`: 52 fixed bytes, a 16-bit name length, and the name.
- An offset counts only when every record parses and the last one ends exactly at the end of the data.
  Two offsets pass. The one with 127 records is the section start.
  The other starts at record 13, because the end of record 12's name, `'r'` and a null, reads as a count of 114.
- 118 of the 127 records have a name, and the names are unique. Empty records have no macro.
- Some names are internal labels, such as `A01, B01, F01, I01 ->Tool Age` or `shadow gb->tc`.
  They keep that spelling (`TECH_A01_B01_F01_I01_TOOL_AGE`, `TECH_SHADOW_GB_TC`).

## Cross-checks

- Build-list `R` lines give an ID and a name. Across the pinned `data2/*.ai` files, 66 of 72 IDs agree.
  Two differ only in spelling (`Metallurgy`, `Ballistics`), and 38 is `Heavy_Horse_Archer` in the lists but
  `Advanced Horse Archer` in the data. The lists also use 83, 200, and 211, which have no named record.
- `TribeBuildAIModule::isAgeResearch` accepts 101, 102, and 103: `Tool Age`, `Bronze Age`, and `Iron Age`.
  The PDB names the `initialize` locals for those IDs `toolAgeIndex`, `bronzeAgeIndex`, and `ironAgeIndex`.
- An existing `@bug` comment calls research 7 Trireme and mentions the Heavy Transport and Medium War Ship
  inserts. Those are 7, 8, and 5.
- `TRIBE_Diplomacy_Dialog` hides one column after `Coinage` (30) is researched. In the original game, Coinage
  removes the tribute fee.

## Substituted contexts

- research `typeID()` tests in `TribeBuildAIModule::initialize`, the `insertResearch` arguments, the
  `insertResearch` guard, and `isAgeResearch`;
- `undo_tech` of the three internal age records in `TRIBE_Building_Object` (`t_b_obj.cpp`);
- `get_tech_state(TECH_COINAGE)` in `dlg_dip.cpp`.

`insertResearch` passes `MASTER_OBJECT_DOCK_1` as the building, which is its `buildFrom` argument.
`typeID <= 6` in the `insertResearch` guard stays numeric because it is a range bound.
Tech state values, such as `== 3`, are outside this change.

## Original bug documented

In `TribeBuildAIModule::initialize`, the warship top-up block compares `warshipCount` with SN `0xE0`.
The original (`004D41A2`) then calls `insertResearch(0x13, index)`, and research 19 is `Monotheism`.
`insertResearch` returns 0 unless the ID is 5, 7, or 8, so the loop never inserts an item.
The source keeps the call and has a `//! @bug` comment.

## Validation

Artifacts are under `build/cleanup-2026-10-10/techs` and `techs-bld`.

- An audit of the 15 groups affected by `tech.h` and the three edited files compiled 14 groups at first.
  `taibldmd` failed until it included `tech.h`, and was then audited again.
- All 576 exact claims passed (551 and 25). All 15 non-debug object payloads equal the `c41e6039a` baseline.

No linked executable build, image audit, automated tests, or runtime suites ran.
