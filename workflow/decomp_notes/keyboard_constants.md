# Keyboard constants

## Scope and commits

The user requested two separate commits.

First commit: `600cb97f067bd05b34ce5ede1ea001cf93d40ff5`, `Name text and list panel constants`.
It contains the previous panel cleanup and its report. It excludes the unrelated `.idea/` directory.

This keyboard cleanup starts from that commit.
It changes 197 literal uses and one existing comment across 23 source owners.
It does not add headers, constants, enum types, storage, parameters, or local variables.
No source owner, registry entry, compiler profile, signature, layout, or runtime asset changes.

Changed source files:

- `src/Pnl_drop.cpp`, `src/Pnl_inp.cpp`, `src/Scr_sels.cpp`
- `src/dlg_abt.cpp`, `src/dlg_list.cpp`, `src/dlg_msg.cpp`, `src/dlg_sedm.cpp`
- `src/pnl_edit.cpp`, `src/rpnl_tbx.cpp`
- `src/scr_cam.cpp`, `src/scr_cj.cpp`, `src/scr_game.cpp`, `src/scr_info.cpp`
- `src/scr_load.cpp`, `src/scr_main.cpp`, `src/scr_mp.cpp`, `src/scr_mps.cpp`
- `src/scr_name.cpp`, `src/scr_save.cpp`, `src/scr_sed.cpp`, `src/scr_sing.cpp`
- `src/tribegam.cpp`, `src/vw_main.cpp`

This report is `workflow/decomp_notes/keyboard_constants.md`.
No parameter or local variable names changed. Local-name recovery is outside this task.

## Identification and SDK evidence

The search covered keyboard handlers, character handlers, hotkey assignments, keyboard messages, and Windows key-state calls.
Each replacement has a reviewed keyboard or character-input role.
Do not replace unrelated switch selectors merely because their numbers equal a key code.

Pinned SDK evidence:
`C:/Program Files (x86)/DevStudio/VC/include/WINUSER.H`.

- Lines 295 through 329 define mouse buttons, control keys, modifiers, navigation keys, Insert, and Delete.
- Lines 332 and 333 state that digit and letter virtual keys equal ASCII `0` through `9` and `A` through `Z`.
- Lines 355 through 378 define the function keys. This pass uses the needed F1 through F9 and F11 definitions.
- Lines 1322 through 1326 define `WM_KEYDOWN`, `WM_KEYUP`, `WM_CHAR`, and `WM_SYSKEYDOWN`.

Use SDK names for virtual-key and keyboard-message values.
Use character literals for digit keys, letter keys, printable input, and character-control values.
These are SDK names and standard character spellings, not newly recovered original game macro names.
The existing Windows includes already supply every SDK name used here.

Examples:

| Context | Before | After |
| --- | --- | --- |
| Group key selector | `case 0x30` | `case '0'` |
| Group number arithmetic | `key - 0x30` | `key - '0'` |
| Game function-key selector | `case 0x70` | `case VK_F1` |
| Game key-up pause check | `wParam == 0x13` | `wParam == VK_PAUSE` |
| Text carriage-return check | `key == 13` | `key == '\r'` |
| Character speed command | `case 0x2D` | `case '-'` |
| Editor key Delete | `case 0x2E` | `case VK_DELETE` |
| Cancel-button hotkey | `hotkey = 0x1B` | `hotkey = VK_ESCAPE` |
| Keyboard state index | `pbKeyState[0x26]` | `pbKeyState[VK_UP]` |
| Mouse-button state query | `GetAsyncKeyState(1)` | `GetAsyncKeyState(VK_LBUTTON)` |

Keep virtual keys separate from character input.
For example, value 13 means Pause in a virtual-key check but carriage return in a character check.

## Original executable evidence

The original executable remains the behavior oracle. Its local assembly listings expose these relevant instructions:

- `orig/ghidra_decomp/scr_game.cpp.asm`, `TRIBE_Screen_Game::key_down_action`, starts at `00497440`.
  The cheat decoder compares with `0x7A`, `0x61`, `0x5A`, `0x41`, `0x30`, and `0x39` at `004974FD` through `0049751B`.
  It subtracts `0x20` at `00497507`.
  Group and developer-player commands subtract `0x30` at `004975E2` and `0049760A`.
  The cheat-buffer length check uses the separate value `0x32` at `00497530`.
- `orig/ghidra_decomp/pnl_inp.cpp.asm`, `TInputPanel::char_action`, starts at `00476FA0`.
  Its control-character checks compare with 8, 9, 10, 13, and 27 at `00476FA8` through `00476FCE`.
  Its following signed comparison preserves the original rejection boundary.
- `orig/ghidra_decomp/tribegam.cpp.asm`, `TRIBE_Game::action_key_down`, starts at `00529F60`.
  Video controls compare with 13, 27, and 32 at `00529F72` through `00529F7C`.
  The help key check compares with `0x70` at `00529FA8`.
- `TButtonPanel::handle_key_down()` compares incoming virtual keys with the `hotkey` field.
  `TPanel` sends Windows key messages to these handlers and character messages to `char_action()`.
  These existing input paths establish the button-field and character-input domains.

The source scan also found AI IDs, button-action IDs, drawing opcodes, and other non-keyboard selectors.
Those literals remain unchanged.

## Types and preserved behavior

The SDK macros expand to the same positive integer values.
Character literals have type `char` in C++.
In these uses, integer promotions and destination conversions preserve the original values and operation types.
All introduced character values are ASCII values below 128.
`TInputPanel::insert_character(long)` still receives newline value 10 through its existing, non-overloaded signature.

Keep signedness, casts, widths, comparisons, arithmetic structure, fall-through, and call order unchanged.
For example, the existing addition to a negative digit offset remains `key = key + (-'0')`.
Do not change its structure during this cleanup.

The cheat decoder still applies its lowercase-value range to virtual-key input.
That range overlaps numeric-keypad and function-key codes.
The cleanup names the character bounds without changing that original behavior.
It retains the `0x20` conversion offset and the separate 50-character buffer limit.
It also keeps the original overlapping buffer copy.

Keep localized hotkey resource lookups, resource-ID arithmetic, and caller-supplied text unchanged.
Do not replace resource IDs with key names.
Zero hotkey sentinels, modifier flags, command IDs, pixel counts, and mode values remain numeric where unchanged.

## Validation

Report root: `build/key-constant-cleanup/`.
Preserved pre-cleanup function report: `build/panel-constant-cleanup/functions/report.json`.
Before editing, all 225 group input fingerprints and object hashes matched that report.
The integration-only globals also matched their recorded input fingerprint and object hash.
See `baseline-inputs.json` and `baseline-global-inputs.json`.

`source-scope.json` verifies all 197 substituted numeric values against the pinned SDK or ASCII character value.
The inverse recorded replacements restore every changed source file byte for byte to the base commit.
All 23 files preserve their line endings and physical line counts.
No formatting pass ran. `git diff --check` passes.

| Check | Result | Report |
| --- | --- | --- |
| Function compilation | All 225 configured groups compile. No compile errors. | `functions/report.json` |
| Integration globals | `src/game_globals.cpp` compiles with its configured `default` profile. | `game_globals.json` |
| Object parity | All 226 C/C++ objects retain equal non-debug section bytes, sizes, flags, relocations, and allocated symbol identities. | `object-comparison.json` |
| Exact claims | All 5,013 exact claims pass. | `functions/report.json` |
| Function observations | All 5,426 observations remain identical, including ownership, direct-symbol findings, byte differences, and policy findings. | `function-comparison.json` |
| Matching owners | All 5,013 owners pass. No duplicate owners, owner mismatches, class/free mismatches, or repair items. | `owners.json`, `owners.txt` |
| Source scope | All 23 source files restore to the baseline through inverse substitutions. All numeric values and line endings pass. | `source-scope.json` |
| Final input fingerprints | All 225 group input fingerprints and object hashes match the validated snapshot. Global inputs and object hash pass. | `final-inputs.json`, `final-global-inputs.json` |

The object comparison excludes debug sections and file/debug symbols.
Private compiler serial labels retain their section and offset identity.
External and function symbol identities remain exact. No instruction, program data, or relocation difference is ignored.
All listed validation commands completed with exit zero.

Separate edits appeared in `src/player.cpp` and `src/tplayer.cpp` during validation.
This pass did not make or review them. The fresh compiler sweep covered their current contents.
Their current input fingerprints match the report. See `unrelated-inputs.json`.
They remain outside both cleanup commits. The unrelated `.idea/` directory also remains untouched.

Existing nonexact observations remain unchanged:
217 behavior-recovery observations, 140 accepted-drift observations, 44 grouped mismatches, and 12 boundary problems.
Existing source-policy findings also remain unchanged.

Commands, from the repository root:

```text
python -B build/key-constant-cleanup/check_scope.py
python -B tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/key-constant-cleanup/functions
python -B build/panel-constant-cleanup/compile_globals.py --output-dir build/key-constant-cleanup
python -B build/object-state-cleanup/compare_objects.py --before build/panel-constant-cleanup/functions/objects --after build/key-constant-cleanup/functions/objects --output build/key-constant-cleanup/object-comparison.json
python -B build/action-result-cleanup/compare_functions.py --baseline build/panel-constant-cleanup/functions/report.json --cleaned build/key-constant-cleanup/functions/report.json --output build/key-constant-cleanup/function-comparison.json
python -B tools/audit_matching_owners.py --function-report build/key-constant-cleanup/functions/report.json --output build/key-constant-cleanup/owners.json --text-output build/key-constant-cleanup/owners.txt
python -B build/game-setting-cleanup/check_final_inputs.py --report build/key-constant-cleanup/functions/report.json --output build/key-constant-cleanup/final-inputs.json
git diff --check
```

No linked executable build, linked-image audit, automated tests, menus, or gameplay ran for this task.
The runtime build selection stays unchanged. Cleanup parity is not complete game correctness.
