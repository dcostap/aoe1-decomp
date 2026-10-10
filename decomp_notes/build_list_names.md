# AI build-list slot names

## Scope

The starting commit is `e280e8190`.
This change names the 125 build-list slots used by `TRIBE_Player::intelligentBuildListAndRulesSelection`
(`00515E00`) and the 16 `TRIBE_Player::setup*` civilization functions.
It edits `src/tplayer.cpp`, `include/resource_ids.h`, `docs/resource_ids.md`, and
`decomp_notes/game_command_help_ids.md`.

The `BUILD_LIST_*` macros are defined at the top of `src/tplayer.cpp`, because no other module uses the slots.
Each name is the file name that the slot loads, so the names come from shipped resource data.
The macro spelling is a cleanup convention.

## How the slot becomes a file

1. The civilization `setup*` function and the following adjustments add weights to `int buildLists[125]`.
2. A weighted random draw picks `selectedBuildList`.
3. `get_string(selectedBuildList + 0x26930, b, 256)` writes the file path into `b`.
4. The caller passes `b` to `BuildAIModule::loadBuildList`, which calls `fopen` on it.
   If `fopen` fails, `loadBuildList` returns 0. The caller's `do`/`while` loop then runs the whole selection again.

`0x26930` is now `STRING_ID_AI_BUILD_LIST_FIRST` in `include/resource_ids.h`.

## Why the strings seemed to be missing

String-table IDs are 16 bits wide. `LoadStringA` uses only the low 16 bits of its ID.
`0x26930 + slot` therefore loads string `0x6930 + slot` (decimal 26928 through 27052).
Earlier searches used the full ID (158000 and up), and `tools/inspect_pe_strings.py` correctly reports that ID as missing.

`TRIBE_Game::get_string` tries the expansion module first and then the base module:

- `orig/.../XPack/languagex.dll`, SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`,
  has 117 of the 125 slots. Its paths start with `data2\`.
- `runtime/language.dll`, SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`,
  has slots 0 through 59. Its paths start with `data\`. It supplies the eight slots that the expansion module lacks:
  2, 5, 8, 12, 13, 14, 15, and 21 (the Walls and Trireme lists).

Every slot from 0 through 124 has text in one of the two modules.
The slot table is `build/cleanup-2026-10-10/build_list_table.txt`, made by `build_list_table.py`.

The same 16-bit rule explains the 28 high help IDs in `include/resource_ids.h`.
For example, `0x1D4DD` (`STRING_ID_HELP_GAME_STOP`) loads `0xD4DD`, "Click to stop the current action."
All 28 have text that agrees with their names. The resource-ID comments and `docs/resource_ids.md` now say this.

## Cross-checks with the code

The names agree with the code that uses the slots. The code was not used to choose them.

- Slots 13 and 14 are Trireme Bronze and Trireme Iron. Water maps add weight to them.
  When either slot is chosen, the code sets `SNMinimumBoatAttackGroupSize` and `SNMaximumBoatAttackGroupSize`.
- `setupEgyptian` weights Death Match Egypt and Death Match Egypt Water by map type.
  It also weights Immortal Egypt, Egypt War Elephants, Egypt Chariots, Egypt Chariot Archer, and Egypt Archers Bronze.
- The most-built-unit adjustment moves weight between related lists. One case adds archers and priests and subtracts
  both elephant lists.

## Data notes

Twelve slot paths name a file that is not in the pinned `XPack/data2` directory:

| Slot | Path | Note |
| --- | --- | --- |
| 2, 5, 8, 12, 15, 21 | `data\... Walls.ai` | Base-game paths; the pinned set has no base `data` directory. |
| 72, 73 | `data2\Assyria Archer Bronze.ai`, `...Iron.ai` | The shipped files are named `Assyria Archers ...`. |
| 80 | `data2\Egypt Chariot Archer.ai` | The shipped file is `Egypt Chariot Archers.ai`. |
| 90 | `data2\Persia Bronze Water.ai` | The shipped file is `Persian Bronze Water.ai`. |
| 94, 95 | `data2\Sumeria Bronze Water.ai`, `...Iron Water.ai` | No similar file is shipped. |

Slots 13 and 14 also use `data\` paths. Files with those names exist in the pinned `data2`, but the paths do not point there.
When a slot's file is missing, the load fails and the selection runs again.
These notes describe the pinned files only. No runtime test checked the effect.

## Source form changes

- `buildLists[(N) - 1]` became `buildLists[NAME]`, where `NAME` is slot `N - 1`.
  The constant index is the same value.
- `if (0 < (buildLists[X])) (buildLists[X]) = (buildLists[X]) / 3;` became
  `if (buildLists[X] > 0) { buildLists[X] /= 3; }`.
- `b[N]` in the `setup*` functions and the `case` labels of both `switch (selectedBuildList)` statements use the names.
- The comment that said the build-list range was absent from the DLL was removed.

The local `difficultyLevel` in `intelligentBuildListAndRulesSelection` holds the most-built unit category and
later a loop index. The PDB places `mostBuiltUnit1` and `i` in one stack slot and `difficultyLevel` in another.
This change does not rename or move locals.

## Validation

Artifacts are under `build/cleanup-2026-10-10/build-lists`.

- An audit of the 45 groups that depend on `src/tplayer.cpp` or `include/resource_ids.h` compiled all groups.
  All 1,171 exact claims passed.
- All 45 non-debug object payloads equal the `c41e6039a` baseline. The commits after that baseline left their payloads unchanged.
- `git diff --check` and the line-ending check passed. clang-format 21.1.8 was applied to `src/tplayer.cpp`.

No linked executable build, image audit, automated tests, or runtime suites ran.
