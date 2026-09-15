# `src/pnl_dlg.cpp` cleanup report

## Scope and hashes

- Module: `src/pnl_dlg.cpp`
- Header owner: owner 18 owns `include/pnl_dlg.h`; this worker did not edit it.
- Base commit from `git rev-parse`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Base source SHA-256 from Git: `1f1429a06c8fed05e0a4d7503e79fd8294f89617c0757d055fd2c48074805dd2`
- Final source SHA-256: `c67fbf4cd5ffa7100c5f6b4fd73f95752b5b63c1ee6e6d475e2a63d880906dfb`
- Final commit: see the delivery record for the full Git hash.
- Changed files:
  - `src/pnl_dlg.cpp`
  - `decomp_notes/source_cleanup/wave03/pnl_dlg.md`

The source keeps the five handwritten functions in PDB source order. It also
keeps the adjacent compiler-generated vector-deleting destructor outside the
source owner. The cleanup restores procedure-scoped parameter names and moves
function opening braces to 1TBS style. It does not change executable logic.

Evidence identity used during review:

- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`, SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Registry packet:
  `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/pnl_dlg.cpp.json`.
  It selects `config/flags/gx.rsp` through the `gx` build profile.
- Preserved baseline report:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`, SHA-256 `fddd62868626e21ec7282183fa1cf84ad5b0b14fc719c8830a266d6ed0f155b3`.
- PDB scope:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
- Original procedure packets:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00473C10_TDialogPanel.txt`,
  `00473C60_vector_deleting_destructor.txt`,
  `00473C80_setup.txt`,
  `00473D60_setup.txt`,
  `00473E40_TDialogPanel.txt`, and
  `00473EC0_set_focus.txt`.
- Existing module notes:
  `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/pnl_dlg.md` and
  `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/functions/0047/00473C80.md` and
  `00473D60.md`.

## Original-name recovery coverage

The scoped PDB records were inspected for every assigned source owner and for
the adjacent generated function. All five handwritten owners have a scoped
record with `this` in `ecx`. The PDB has no function-static or local records
for these source owners.

| VA | Function and original range | PDB parameters and result |
| --- | --- | --- |
| `00473C10` | `TDialogPanel::TDialogPanel`, `00473C10-00473C53` | `+0x4 panel_name_in` (`char*`); `this` is `TDialogPanel*` in `ecx` |
| `00473C60` | compiler-generated vector-deleting destructor, `00473C60-00473C7D` | Scoped record has `+0x4 __flags` (`unsigned int`) and `this` in `ecx`; no source PDB span or handwritten declaration |
| `00473C80` | `TDialogPanel::setup`, `00473C80-00473D5A` | `render_area_in`, `parent_in`, `wid_in`, `hgt_in`, `info_file_name`, `resource_file_id`, `allow_shadow_area_in`; types are `TDrawArea*`, `TPanel*`, `long`, `long`, `char*`, `long`, and `int` |
| `00473D60` | `TDialogPanel::setup`, `00473D60-00473E32` | `render_area_in`, `parent_in`, `wid_in`, `hgt_in`, `color_in`, `allow_shadow_area_in`; types are `TDrawArea*`, `TPanel*`, `long`, `long`, `unsigned char`, and `int` |
| `00473E40` | `TDialogPanel::~TDialogPanel`, `00473E40-00473EBF` | No parameters beyond `this`; `this` is `TDialogPanel*` in `ecx` |
| `00473EC0` | `TDialogPanel::set_focus`, `00473EC0-00473ECC` | `+0x4 have_focus_in` (`int`); `this` is `TDialogPanel*` in `ecx` |

The source changes recover these PDB names:

- Constructor `name` becomes `panel_name_in`.
- Long `setup` `info_file_name_in` becomes the exact PDB spelling
  `info_file_name`.
- Short `setup` placeholders `param_1` through `param_6` become the six
  procedure-scoped PDB names listed above.
- `set_focus` parameter `focus` becomes `have_focus_in`.

The existing locals `width`, `height`, and the short-setup local `parent` have
clear uses but no procedure-scoped PDB records. Their original names and stack
mappings are unresolved, so this cleanup does not claim them as recovered names.
No reused stack slot was forced into a new declaration. The generated
vector-deleting destructor has no source declaration to clean.

All parameter types remain unchanged. The source definition names can differ
from the unnamed declarations in `include/pnl_dlg.h` without changing the ABI.

## Constants, resources, comments, and names

No numeric constant was replaced. Existing `0xB`, zero values, `1`, `-1`, and
other literal arguments remain unchanged. No resource lookup occurs in this
module. No resource ID was investigated, so no DLL extraction or resource-ID
mapping is needed. No new comment was added.

Recovered original names are `panel_name_in`, `render_area_in`, `parent_in`,
`wid_in`, `hgt_in`, `info_file_name`, `resource_file_id`,
`allow_shadow_area_in`, `color_in`, and `have_focus_in`. No new descriptive
local or parameter name was invented. Existing descriptive locals remain
unclaimed as original names because the PDB gives no local records.

## Code-generation risks and unresolved mappings

The source edits rename parameters and move opening braces only. They do not
alter an ABI symbol, type, cast, declaration scope, storage duration, call
target, literal value, evaluation order, control flow, field offset, or object
layout. Brace movement can change debug line metadata. No line-dependent macro
occurs in this file. Final compiler-output validation remains required.

The two setup owners remain known mismatch areas in the existing module notes.
This cleanup does not claim a new match or accepted drift. The existing source
keeps the original parent/null dimension branches, calls, failure stores,
modal updates, and parent-child updates. The unused parent-position calls in
the long setup remain unchanged.

## Shared requests

Request to owner 18 for optional declaration-name cleanup in
`include/pnl_dlg.h`:

- `TDialogPanel(char* panel_name_in)`
- Long setup parameters: `render_area_in`, `parent_in`, `wid_in`, `hgt_in`,
  `info_file_name`, `resource_file_id`, `allow_shadow_area_in`
- Short setup parameters: `render_area_in`, `parent_in`, `wid_in`, `hgt_in`,
  `color_in`, `allow_shadow_area_in`
- `set_focus(int have_focus_in)`

Evidence is the procedure-scoped records at VAs `00473C10`, `00473C80`,
`00473D60`, and `00473EC0` in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The header request is non-blocking. The header currently uses unnamed
parameters, and this worker did not edit it. No shared resource declaration is
requested.

## Validation status

Compilation, matching, audits, and tests were not run. No compiler, build,
matching, audit, test, or game command was run for this assignment. The full
source diff was reviewed, and `git diff --check` passed.
