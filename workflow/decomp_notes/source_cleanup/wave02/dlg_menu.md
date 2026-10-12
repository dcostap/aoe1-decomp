# `src/dlg_menu.cpp` cleanup report

## Delivery

- Module: `src/dlg_menu.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source head commit: `d26604d77fcf83b0b61a08b467c5ab30df85f3dc`
- Worker-local resource import provenance: `5bc93fcb069dce227999254757e001423ec4959e`
- Root approval: `8c56055b7feee1526f296bd306036a4c34f38041`
- Assigned report: `workflow/decomp_notes/source_cleanup/wave02/dlg_menu.md`
- Changed files: `src/dlg_menu.cpp`, this report
- Header owner: owner 10 owns `include/dlg_menu.h`. This worker did not edit it.

The source registry is `config/functions/src/dlg_menu.cpp.json`. It selects three
normal procedures in PDB order:

| VA | symbol | registry status | source coverage |
| --- | --- | --- | --- |
| `0043F340` | `??0TribeMenuDialog@@QAE@PAVTScreenPanel@@@Z` | `matching` | complete |
| `0043F6B0` | `??1TribeMenuDialog@@UAE@XZ` | `matching` | complete |
| `0043F720` | `?action@TribeMenuDialog@@MAEJPAVTPanel@@JKK@Z` | `matching` | complete |

The compiler-generated scalar deleting destructor at `0043F690` is not a
handwritten source procedure. It remains outside this source file's edits.

## Original-name recovery

Evidence came from the procedure-scoped PDB reference at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The selected packets came from the source registry and
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/`.
The original body evidence is the original PE at
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.

The PDB records these symbols for every normal procedure:

- `0043F340` constructor: stack `+0x4` is `parentPanel` (`TScreenPanel*`).
  Register `ecx` is `this` (`TribeMenuDialog*`).
- `0043F6B0` destructor: no stack symbols. Register `ecx` is `this`
  (`TribeMenuDialog*`).
- `0043F720` action: stack `+0x4` is `fromPanel` (`TPanel*`), `+0x8` is
  `actionIn` (`long`), `+0xC` is `a1` (`unsigned long`), and `+0x10` is
  `a2` (`unsigned long`). Register `ecx` is `this` (`TribeMenuDialog*`).

The source now uses all five recovered parameter spellings:

- `parent` -> `parentPanel` in the constructor.
- `panel` -> `fromPanel`, `id` -> `actionIn`, `param3` -> `a1`, and
  `param4` -> `a2` in `action`.

No PDB local symbols are present for the three normal procedures. I left the
existing local declarations unchanged because their original mappings are not
proved:

- Constructor: `i`, `bi`, `y`, `by`, `by2`, and `p`.
- Destructor: `count` and `pp`.
- Action: the scoped `obj` and `ep` declarations.

The packet decompiler names and `local_*` values are not treated as original
source names. The generated scalar deleting destructor has PDB stack
`__flags` (`unsigned int`, `+0x4`) and register `this`; it has no source-body
rename.

## Resource and constant evidence

The source now reuses the existing `STRING_ID_MENU_HELP` macro from
`include/resource_ids.h` for `0x23F5`. The packet call site passes this ID to
`create_button`, and the text is `Help`. No new macro was defined in this
worker.

Resource extraction used `tools/inspect_pe_strings.py` after its help output
was checked. The actual base lookup input is
`C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`, SHA256
`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`,
language `0x0409` (`1033`). `TRIBE_Game::get_string` first checks
`StringTableX` and then falls back to the base `StringTable`; see
`src/tribegam.cpp` and `src/basegame.cpp`. The inspected expansion inputs have
no entries for these IDs:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA256
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

The worker imported the following reviewed definitions from
`include/resource_ids.h` in local commit
`5bc93fcb069dce227999254757e001423ec4959e`. Root approved them in
`8c56055b7feee1526f296bd306036a4c34f38041`. They are new cleanup names, not
recovered original macro names. Each ID is an RT_STRING lookup through the
panel/game string path. The base-language result is from the file and
language listed above.

`TEasy_Panel::popupYesNoDialog(long, char*, int, int)` loads the confirmation
ID into a text buffer, then passes that text to the dialog overload. These
confirmation resources are message text. At `Panel_ez.cpp:1416`, the adjacent
`QuitAndLoadDialog`, `QuitGameDialog`, `RestartDialog`, and `ResignDialog`
strings pass to `new TMessageDialog(message)`. They name dialog panels. The
dialog `setup` call uses `popup_info_file_name` and `popup_info_id` separately.
These strings do not select resource payloads.

| ID | exact base text | call-site purpose | applied cleanup name |
| --- | --- | --- | --- |
| `0x23F9` | `About` | menu button label | `STRING_ID_MENU_ABOUT` |
| `0x2437` | `Achievements` | menu button label | `STRING_ID_MENU_ACHIEVEMENTS` |
| `0x2438` | `Save` | menu button label | `STRING_ID_MENU_SAVE` |
| `0x2439` | `Quit Game` | menu button label | `STRING_ID_MENU_QUIT_GAME` |
| `0x243A` | `Game Settings` | menu button label | `STRING_ID_MENU_GAME_SETTINGS` |
| `0x243B` | `Cancel` | menu button label | `STRING_ID_MENU_CANCEL` |
| `0x243C` | `Load` | menu button label | `STRING_ID_MENU_LOAD` |
| `0x243E` | `Scenario Instructions` | menu button label | `STRING_ID_MENU_SCENARIO_INSTRUCTIONS` |
| `0x243F` | `Restart` | menu button label | `STRING_ID_MENU_RESTART` |
| `0x2440` | `Resign` | multiplayer menu button label | `STRING_ID_MENU_RESIGN` |
| `0x269E` | `Achievements` | title passed to `TribeAchievementsScreen` | `STRING_ID_ACHIEVEMENTS_TITLE` |
| `0x0C1C` | `Are you sure you want to quit and load a new game?` | quit-and-load confirmation message text | `STRING_ID_CONFIRM_QUIT_AND_LOAD` |
| `0x0C1D` | `Are you sure you want to quit this game?` | quit confirmation message text | `STRING_ID_CONFIRM_QUIT_GAME` |
| `0x0C1E` | `Are you sure you want to restart this game?` | restart confirmation message text | `STRING_ID_CONFIRM_RESTART_GAME` |
| `0x0C1F` | `Are you sure you want to resign?` | resign confirmation message text | `STRING_ID_CONFIRM_RESIGN` |

The runtime expansion and pinned original expansion returned missing entries,
not empty slots, for every requested ID. The missing expansion results do not
change the known roles established by the call sites and base strings.

No source comment was added. Existing literals, lookup calls, fallback order,
format arguments, and buffer contracts remain unchanged.

## Code-generation and ownership notes

Parameter renames affect names only. They do not change types, calling
conventions, layouts, symbol identity, call targets, or evaluation order.
`STRING_ID_MENU_HELP` expands to the existing literal `0x23F5`; it introduces no
object or storage. Signature wrapping and definition brace placement changed
for 1TBS presentation only.
No helper, layout, cast, control-flow, declaration scope, or initialization
point was changed. The unresolved local mappings above remain possible code
review points.

Shared requests:

1. Owner 10 may update the unassigned declaration names in `include/dlg_menu.h`
   to `parentPanel`, `fromPanel`, `actionIn`, `a1`, and `a2`.
2. Root approved all resource IDs in
   `8c56055b7feee1526f296bd306036a4c34f38041`. The worker-local import
   provenance is `5bc93fcb069dce227999254757e001423ec4959e`.
   `STRING_ID_MENU_HELP` was already present and remains reused.

The preserved pre-cleanup reference is under
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`.
This worker did not change or build it.

Compilation, matching, audits, and tests were not run.
