# Game-button command IDs

Base commit: `04fcb4e261c34dfbf908b9d9bc6880678af07197`.
The commit that adds this report contains the complete cleanup.

## Scope

Changed files:

- `include/tribegam.h`
- `src/scr_game.cpp`
- `src/tribegam.cpp`
- `workflow/decomp_notes/button_commands.md`

Added 33 `TRIBE_UI_COMMAND_*` macros in the existing game header.
These are descriptive cleanup names, not recovered original macro names.
They name the command domain shared by game buttons and `RGE_STRING_TYPE_COMMAND` text lookup.
They do not name button notifications, network commands, AI orders, action types, or game modes.

Replaced 168 literal uses: 136 in the game screen and 32 in the game text lookup.
That count includes three resource arguments, which now use existing `RGE_RESOURCE_*` names.
The other 165 substitutions name UI command IDs.

The game-screen changes cover both dispatch paths, fixed buttons, button setup, command comparisons, and hotkey selection.
They also name the command arguments passed to `calc_text_msg`; that function still ignores this argument.
The text-lookup changes cover only the existing command-label switch.

All macros expand to unsuffixed integer literals with the same values and effective `int` type.
No storage, enum type, signature, layout, include, registry entry, or compiler profile changed.
Applied clang-format 21.1.8 with the existing project settings to the three source/header files.
Only calls that grew with the command names needed new wrapping.

## Original executable evidence

Authority: `config/executable.json` and the repo-local original executable:

`orig/empiresx.exe`

SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

Read the executable bytes directly with PE parsing and x86 instruction decoding.
The game-button dispatcher starts at `004987A0`; its enabled command table starts at `00498944`.
The command-label path starts at `00522C14`; its table starts at `0052332C`.
Both tables contain entries for IDs 1 through 33.
Supporting symbol names and source locations come from the original instruction listings and existing declarations.
The listings are reference evidence, not the behavior oracle.

The following names use the `TRIBE_UI_COMMAND_` prefix.
Targets name the methods called by the original dispatcher.
Caption IDs remain in the separate `STRING_ID_*` resource domain.

| ID | Name suffix | Original target | Caption resource |
| --- | --- | --- | --- |
| 1 | WORK | `command_work`, `0049D200` | `1005` |
| 2 | MOVE | `command_move`, `0049C890` | `1006` |
| 3 | BUILD | `command_build`, `0049BD70` | `1007` |
| 4 | TRADE | `command_trade`, `0049CEA0` | `1008` |
| 5 | STOP | `command_stop`, `0049CE10` | `1009` |
| 6 | UNSELECT | `command_unselect`, `0049D040` | `100A` |
| 7 | UNLOAD | `command_unload`, `0049CFF0` | `100B` |
| 8 | GROUP | `command_group`, `0049C540` | `100C` |
| 9 | UNGROUP | `command_ungroup`, `0049CFB0` | `100D` |
| `0A` | FORMATION | Default return; label only | `100E` |
| `0B` | CANCEL | `command_cancel`, `0049BEA0` | `100F` |
| `0C` | MORE | `command_more`, `0049C800` | `1010` |
| `0D` | CHAT | `command_chat`, `0049BF50` | `1011` |
| `0E` | DIPLOMACY | `command_diplomacy`, `0049C1B0` | `1012` |
| `0F` | MENU | `command_menu`, `0049C770` | `1013` |
| `10` | TRADE_WITH | `command_trade_with`, `0049CEB0` | `1014` |
| `11` | RESEARCH | `command_research`, `0049CAF0` | `1015` |
| `12` | TRAIN | `command_train`, `0049CEC0` | `1016` |
| `13` | PLACE_BUILDING | `command_building`, `0049BDB0` | `1017` |
| `14` | CANCEL_CONSTRUCTION | `command_cancel_building`, `0049BF20` | `1018` |
| `15` | HELP | `setup_popup_help`, `0046A360` | `1019` |
| `16` | STAND_GROUND | `command_stand_ground`, `0049D2C0` | `101A` |
| `17` | ATTACK_GROUND | `command_attack_ground`, `0049D2F0` | `101B` |
| `18` | SCORE | `command_score`, `0049C650` | No command-label case |
| `19` | TRADE_FOOD_FOR_GOLD | `command_trade_attribute(0)`, `0049D340` | `1020` |
| `1A` | TRADE_WOOD_FOR_GOLD | `command_trade_attribute(1)`, `0049D340` | `1021` |
| `1B` | TRADE_STONE_FOR_GOLD | `command_trade_attribute(2)`, `0049D340` | `1022` |
| `1C` | HEAL | `command_heal`, `0049C5B0` | `101C` |
| `1D` | CONVERT | `command_convert`, `0049C160` | `101D` |
| `1E` | ATTACK | `command_attack`, `0049BD20` | `101E` |
| `1F` | REPAIR | `command_repair`, `0049C600` | `101F` |
| `20` | INCREMENT_QUEUE | `command_train(id, 1)`, `0049CEC0` | `1025` |
| `21` | DECREMENT_QUEUE | `command_train(id, -1)`, `0049CEC0` | `1026` |

IDs above 9 and all addresses/resource IDs in this table use hexadecimal notation.
`MORE`, `TRAIN`, and `PLACE_BUILDING` describe the called operations, not new caption text.
Their existing caption text remains `Next (X)`, `Create`, and `Build`.

## Resource evidence

`TRIBE_Game::get_string` tries the expansion table, then the base table when the expansion lookup returns zero.
Inspected both resource files without loading or executing them.
All reported payloads use language `0409`.

- Pinned expansion: `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.
  SHA256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
- Staged base fallback: `runtime/language.dll`.
  SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
  This staged file is not claimed as a pinned original file.

The expansion lacks IDs `1005` through `101F` and has empty slots at `1020` through `1022`.
The base fallback supplies those captions:

| Resource range | Exact payloads, in ID order |
| --- | --- |
| `1005`–`100D` | `Work (W)`; `Move (M)`; `Build (B)`; `Trade`; `Stop (S)`; `Unselect (ESC)`; `Unload (L)`; `Group (G)`; `Ungroup (U)` |
| `100E`–`1017` | `Formation`; `Cancel (ESC)`; `Next (X)`; `Chat`; `Diplomacy`; `Menu`; `Trade with`; `Research`; `Create`; `Build` |
| `1018`–`101F` | `Cancel construction`; `? Help (SHIFT+F1)`; `Stand Ground (D)`; `Attack Ground (T)`; `Heal (E)`; `Convert (C)`; `Attack (A)`; `Repair (R)` |
| `1020`–`1022` | `Trade food for gold.`; `Trade wood for gold.`; `Trade stone for gold.` |

The expansion supplies `1025`: `Increment Queue (,)`, and `1026`: `Decrement Queue (.)`.
Both base-table slots are empty.
No resource IDs, caption strings, language lookup calls, or lookup order changed.

## Preserved behavior

- Formation still has a text selector but no button-dispatch handler.
- Score still has no case in the command-label switch.
- The restricted dispatch path still allows the same ten command IDs.
- Train still uses `right_btn ? -1 : 1`; explicit queue commands still pass `1` or `-1`.
- Training counts, queue flags, resource indices, item IDs, and notification IDs remain separate domains.
- Build-menu and building-placement commands remain separate IDs.
- Slot indices, picture indices, help IDs, page IDs, and dynamic object/research IDs remain unchanged.
- No parameter or local names changed. This task did not repeat the PDB local-name review.

## Validation

Reports are under `build/button-command-cleanup/`.
The preserved baseline uses `build/key-constant-cleanup/functions/report.json` and its objects.
Before edits, all 225 recorded input fingerprints and object hashes matched the current tree.
The retained global object and all 78 recorded global inputs also matched the pre-edit source versions.
The global-input check used the recorded Git version for the changed header, without changing working files.

Ran these final checks:

- Compiled all 225 configured function groups with the pinned VC5 recipes; no compile errors occurred.
- Compiled integration-only `src/game_globals.cpp` with the configured `default` profile.
- Compared all 226 C/C++ non-debug object payloads against the baseline; no differences occurred.
  This covers section bytes, sizes, flags, relocations, and allocated symbol identities.
  Private compiler labels retain their section/offset identity; debug records are excluded.
- Checked all 5,013 exact function claims; all passed.
- Compared all 5,426 function observations and summaries; none changed, appeared, or disappeared.
- Checked matching ownership: no duplicate owners, owner mismatches, class/free mismatches, or repair entries occurred.
- Rechecked all 225 final input fingerprints and object hashes; all matched the fresh report.
- Rechecked the final global input fingerprint, all 78 input records, and its object hash; all matched.
- Reversed all substitutions and restored baseline formatting; both sources matched their baseline bytes.
- Removed the new definition group for comparison; the header matched its baseline bytes.
- Checked all 168 substituted numeric values and preserved LF line endings.
- Ran `git diff --check`; it passed.

The 413 nonmatching observations remain unchanged.
They include 217 verified-logic observations, 140 accepted-drift observations, 44 grouped mismatches, and 12 boundary problems.
This cleanup does not resolve those existing limits or prove full game behavior.

No linked executable build, assembly rebuild, linked-image audit, runtime suite, or automated test suite ran.
Runtime executable selection remains unchanged.
The user requested generated-output parity and matching checks only.
Unrelated `src/player.cpp`, `src/tplayer.cpp`, and `.idea/` changes remain outside this commit.
