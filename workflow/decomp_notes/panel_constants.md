# Text and list panel constants

## Scope

Base commit: `d5114bccc5fbdcce530f646b77e4a27fa413d343`.

Changed files:

- `include/pnl_lst.h`
- `src/pnl_lst.cpp`
- `src/Pnl_txt.cpp`
- `workflow/decomp_notes/panel_constants.md`

Name border styles, scroll modes, and virtual-key values in the two panel source owners.
Keep integer fields, byte arguments, signatures, layouts, casts, arithmetic, and control flow unchanged.
No parameter or local variable names changed. This task does not include local-name recovery.

Use numeric macros in the existing shared owner header.
They expand to the original integer literals without adding storage or enum types.
All `TEXT_PANEL_*` names are descriptive cleanup names, not recovered original names.
`VK_*` names come from the pinned VC5 Windows headers.

## Border styles

The original executable supplies the behavior evidence.
Its local listing is `orig/ghidra_decomp/pnl_txt.cpp.asm`.
`TTextPanel::draw_border()` starts at `0047D570`.

| Value | Cleanup name | Border operation |
| --- | --- | --- |
| 0 | `TEXT_PANEL_BEVEL_NONE` | Skip the border. |
| 1 | `TEXT_PANEL_BEVEL_OUTLINE` | Draw a rectangle with `outline_color`. |
| 2 | `TEXT_PANEL_BEVEL_SINGLE` | Draw one bevel layer with colors 6, 1. |
| 3 | `TEXT_PANEL_BEVEL_DOUBLE` | Draw two bevel layers with colors 6, 5, 2, 1. |
| 4 | `TEXT_PANEL_BEVEL_TRIPLE` | Draw three bevel layers with colors 6, 5, 4, 3, 2, 1. |
| 5 | `TEXT_PANEL_BEVEL_SINGLE_REVERSED` | Reverse the single-layer color order. |
| 6 | `TEXT_PANEL_BEVEL_DOUBLE_REVERSED` | Reverse the double-layer color order. |
| 7 | `TEXT_PANEL_BEVEL_TRIPLE_REVERSED` | Reverse the triple-layer color order. |

Do not label these styles raised or sunken. Callers supply the colors.
`TTextPanel::Style` describes text rendering, not these border modes.
Do not reuse its numerically equal enum values.

`orig/ghidra_decomp/pnl_lst.cpp.asm` records `TListPanel::set_bevel_info()` at `00478350`.
Values 3 and 6 select spacing 2. Values 4 and 7 select spacing 3.
Values 1, 2, and 5 select spacing 1. The default also selects spacing 1.
`TTextPanel::set_bevel_info()` selects corresponding border widths but defaults to width 0.
Keep those defaults and pixel counts unchanged.

`TListPanel::draw_highlight_bar()` starts at `00478CD0` in the same original listing.
List highlights draw bevel colors in the opposite order from the panel border.
Values 0 and 1 still draw a highlight rectangle with color `0xFF`.
The cleanup names the switch selectors without changing either drawing policy.

## Scroll modes

`TTextPanel::scroll()` starts at `0047D060` in the original executable.
The byte selector has these operations:

| Value | Cleanup name | Operation |
| --- | --- | --- |
| 0 | `TEXT_PANEL_SCROLL_RELATIVE` | Add the signed line argument to `top_line`. |
| 1 | `TEXT_PANEL_SCROLL_SET_LINE` | Set `top_line` from the line argument. |
| 2 | `TEXT_PANEL_SCROLL_DOWN` | Advance one line. |
| 3 | `TEXT_PANEL_SCROLL_UP` | Move back one line. |
| 4 | `TEXT_PANEL_SCROLL_PAGE_DOWN` | Advance `draw_lines - 1` lines. |
| 5 | `TEXT_PANEL_SCROLL_PAGE_UP` | Move back `draw_lines - 1` lines. |
| 6 | `TEXT_PANEL_SCROLL_FIRST_LINE` | Set `top_line` to zero. |
| 7 | `TEXT_PANEL_SCROLL_LAST_LINE` | Set `top_line` to `num_lines - 1`. |

The existing `calc_draw_info()` call keeps its original clipping behavior.
`TListPanel::scroll_cur_line()` starts at `00478920` and accepts modes 1 through 7.
It applies those commands to selection and calls the base scrolling function when needed.
Mode 0 is not a relative-selection command. The list switch still takes its default path for zero.
Do not replace scrollbar notification codes with these scroll-mode names.
Their equal numbers identify a different domain.

## Virtual keys

Pinned definitions: `C:/Program Files (x86)/DevStudio/VC/include/WINUSER.H`, lines 304 through 323.
The existing `panel.h` Windows include already supplies them. No include changed.

| Original value | SDK name |
| --- | --- |
| `0x0D` | `VK_RETURN` |
| `0x21` | `VK_PRIOR` |
| `0x22` | `VK_NEXT` |
| `0x23` | `VK_END` |
| `0x24` | `VK_HOME` |
| `0x26` | `VK_UP` |
| `0x28` | `VK_DOWN` |

Keep parent-panel action codes, mouse flags, panel types, timers, and other numeric domains unchanged.

## Validation

Reports: `build/panel-constant-cleanup/`.

The preserved pre-cleanup compiler report is
`build/validation/clang-format-120/final/functions/report.json`.
Before editing, all 225 current input fingerprints and object hashes matched that report.
The integration-only global source also matched its recorded input fingerprint and object hash.
See `baseline-inputs.json` and `baseline-global-inputs.json`.

The source replaces 98 literal uses across two owners.
Expanding the macros restores `src/pnl_lst.cpp` byte for byte.
Expanding and formatting restores `src/Pnl_txt.cpp` byte for byte.
The latter only changes the constructor initializer wrapping beside its new border name.
The header adds only the two definition groups and their comments.
All three files preserve their line endings. See `source-scope.json`.

| Check | Result | Report |
| --- | --- | --- |
| Function compilation | All 225 configured groups compile. | `functions/report.json` |
| Integration globals | `src/game_globals.cpp` compiles with its configured `default` profile. | `game_globals.json` |
| Object parity | All 226 C/C++ objects have equal non-debug bytes, sizes, flags, relocations, and allocated symbol identities. | `object-comparison.json` |
| Exact claims | All 5,013 exact claims pass. No compile error or failed exact claim. | `functions/report.json` |
| Function observations | All 5,426 rows remain identical, including ownership, direct-symbol findings, differences, and policy findings. | `function-comparison.json` |
| Matching owners | All 5,013 owners pass. No duplicate owners, owner mismatches, class/free mismatches, or repair items. | `owners.json`, `owners.txt` |
| Source scope | Only literal substitutions, the new header groups, and adjacent initializer wrapping changed. | `source-scope.json` |
| Fresh input fingerprints | All 225 group input fingerprints and object hashes remain current. Global inputs and object hash also pass. | `final-inputs.json`, `final-global-inputs.json` |

The object comparison excludes debug sections and file/debug symbols.
Private compiler serial labels retain their section and offset identity.
External and function symbol identities remain exact. No instruction, program data, or relocation difference is ignored.
`git diff --check` passes. All listed validation commands completed successfully.
The first final-input check stopped at its 60-second shell limit.
The separate repeat completed with exit zero. No compiler or object comparison failed.

Existing nonexact observations remain unchanged:
217 behavior-recovery observations, 140 accepted-drift observations, 44 grouped mismatches, and 12 boundary problems.
Existing source-policy findings also remain unchanged.

Commands, from the repository root:

```text
python -B build/panel-constant-cleanup/check_scope.py
python -B tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/panel-constant-cleanup/functions
python -B build/panel-constant-cleanup/compile_globals.py --output-dir build/panel-constant-cleanup
python -B build/object-state-cleanup/compare_objects.py --before build/validation/clang-format-120/final/functions/objects --after build/panel-constant-cleanup/functions/objects --output build/panel-constant-cleanup/object-comparison.json
python -B build/action-result-cleanup/compare_functions.py --baseline build/validation/clang-format-120/final/functions/report.json --cleaned build/panel-constant-cleanup/functions/report.json --output build/panel-constant-cleanup/function-comparison.json
python -B tools/audit_matching_owners.py --function-report build/panel-constant-cleanup/functions/report.json --output build/panel-constant-cleanup/owners.json --text-output build/panel-constant-cleanup/owners.txt
python -B build/game-setting-cleanup/check_final_inputs.py --report build/panel-constant-cleanup/functions/report.json --output build/panel-constant-cleanup/final-inputs.json
git diff --check
```

No linked executable build, linked-image audit, automated tests, menus, or gameplay ran for this task.
The runtime build selection stays unchanged. Object parity is not complete game correctness.
