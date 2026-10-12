# `scr_trb.cpp` cleanup report

## Scope and commits

- Module: `src/scr_trb.cpp`
- Paired header: `include/scr_trb.h` (owned by owner 11)
- Exact base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `6ced4d26dd1c9bf873c58ba8649f46971dea79b6`
- Reviewed report head before correction: `a5909d1b9ce46a9006aa5297e47fc6cfc8ec4f90`
- Final full delivery hash before this report amendment: `9ddbb8ae246de4fa28b04f55d514443f264c2ff3`
- Changed files in this delivery:
  - `src/scr_trb.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/scr_trb.md`
- The report is committed after the source commit above.

## Correction history

- `6ced4d26dd1c9bf873c58ba8649f46971dea79b6`: source cleanup commit.
- `a5909d1b9ce46a9006aa5297e47fc6cfc8ec4f90`: reviewed report head before this correction.
- `9ddbb8ae246de4fa28b04f55d514443f264c2ff3`: correction commit with the source and report fixes.
- This report amendment creates a newer final head. The delivery response records that full head.

## Evidence inspected

The source registry selected five normal packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B75A0_TribeSelectTribeScreen.txt` (VA `004B75A0`, source lines 37-157)
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B7DF0_TribeSelectTribeScreen.txt` (VA `004B7DF0`, source lines 162-172)
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B7EE0_action.txt` (VA `004B7EE0`, source lines 178-197)
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B7F70_fillTribeText.txt` (VA `004B7F70`, source lines 202-233)
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B8070_tribeName.txt` (VA `004B8070`, source lines 238-261)

I also inspected the compiler-generated packet:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004B7DD0_scalar_deleting_destructor.txt` (VA `004B7DD0`)

The source registry is:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/scr_trb.cpp.json`

The complete procedure-scoped PDB index is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- SHA256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`

Other shared evidence paths checked for provenance:

- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
  - SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Current base language resource: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  - SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Current expansion resource: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  - SHA256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- Original expansion resource: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  - SHA256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`
- Preserved pre-cleanup build directory: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`

## PDB coverage and name recovery

All five normal source functions have scoped PDB coverage. Each record had `this` in `ECX`. No function-static records were present.

| VA and function | Scoped parameters and locals | Cleanup result |
| --- | --- | --- |
| `004B75A0` `TribeSelectTribeScreen::TribeSelectTribeScreen` (58 line records; body `004B75A0-004B7DC4`) | `tabList` (`TPanel*[40 bytes]`, `-0x34`), `buttonSound` (`TDigital*`, `-0x50`), `i` (`int`, `-0x4c`), `font` (`RGE_Font*`, `-0x48`), `secondHeight` (`int`, `-0x5c`), `secondWidth` (`int`, `-0x54`), and `backgroundName` (`char[10]`, `-0x40`) | Existing source names match the PDB names. `width`, `backgroundPanel`, and `button` have no scoped PDB records. I left these mappings unchanged. |
| `004B7DF0` `TribeSelectTribeScreen::~TribeSelectTribeScreen` (11 line records; body `004B7DF0-004B7ED2`) | No stack symbols; `this` in `ECX` | The two source loop counters named `i` have no scoped PDB mapping. I left them unchanged. |
| `004B7EE0` `TribeSelectTribeScreen::action` (14 line records; body `004B7EE0-004B7F6B`) | `fromPanel` (`TPanel*`, `+0x4`), `actionIn` (`long`, `+0x8`), `a1` (`unsigned long`, `+0xc`), and `a2` (`unsigned long`, `+0x10`) | Recovered the exact PDB spellings. Renamed `sender` to `fromPanel`, `actionType` to `actionIn`, `param3` to `a1`, and `param4` to `a2` in the definition and uses. |
| `004B7F70` `TribeSelectTribeScreen::fillTribeText` (20 line records; body `004B7F70-004B8041`) | `t` (`int`, `+0x4`) | Recovered the exact PDB spelling. Renamed `tribeIdx` to `t` in the definition and switch. |
| `004B8070` `TribeSelectTribeScreen::tribeName` (21 line records; body `004B8070-004B80CF`) | `i` (`int`, `+0x4`) | Recovered the exact PDB spelling. Renamed generated `param_1` to `i` in the definition and switch. |

The scalar-deleting destructor at `004B7DD0` has no PDB procedure record and remains compiler-generated. It has no source body to edit.

No invented names were added. The constructor's existing `width`, `backgroundPanel`, and `button` locals remain unresolved because the scoped PDB index does not record them. The destructor's loop counters also remain unresolved. I did not force reused-stack-slot mappings.

## Constants, strings, and comments

- No numeric literal, enum, call target, cast, type, declaration scope, evaluation order, or string literal changed.
- The static tribe names and information strings remain unchanged. They are not resource-ID lookups.
- No resource ID was added or renamed. No `resource_ids.h` request is needed.
- Removed line-band comments, compiler-evidence comments, and the speculative loop-intent comment. These comments did not explain source behavior. No new source comment was needed.
- Corrected one indentation error and placed the changed short function definition in 1TBS form.

## Shared header request

Owner 11 should update `include/scr_trb.h` parameter names without changing any type or ABI:

```cpp
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
void fillTribeText(int t);
char* tribeName(int i);
```

Evidence: the scoped PDB records at `004B7EE0`, `004B7F70`, and `004B8070` in the indexed file above. This request affects only declaration spelling. I did not edit the header.

## Possible code-generation effects

The edits change source names, comments, whitespace, indentation, and brace placement only. They should not change executable instructions, data, calls, or layout. Parameter names can change debug records. Comment removal and brace placement can change source line records. No compiler or matching check was run, so these effects remain unverified.

## Validation status

I ran evidence extraction, `git diff --check`, and a complete Git diff review. I did **not** run compilation, matching, audits, tests, a build, or the game command, as required for this cleanup wave.
