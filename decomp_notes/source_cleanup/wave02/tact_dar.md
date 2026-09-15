# `tact_dar.cpp` cleanup report

## Delivery

- Module: `src/tact_dar.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Previous source commit: `38d2d77200e0af6a40aa21698a6f5cf89654bb55`
- Previous report commit: `7ff3dbb54e27970fdbe0349fbb2518628f48cee3`
- Final source commit: `033fb5bb41bc182ba34e68a686666108c3deea02`
- Report correction commit: follows this source commit and contains this report correction only.
- Changed files:
  - `src/tact_dar.cpp`
  - `decomp_notes/source_cleanup/wave02/tact_dar.md`

The final source commit owns the corrected module code. The later report
correction commit records this delivery without changing source code.

## Cleanup result

The source keeps all eight handwritten functions in PDB order. I restored the
procedure-scoped PDB names where the mapping is direct. I moved function braces
to 1TBS form. I corrected the `check_objects` local-name mapping. I did not
change statements, calls, types, literals, layouts, or symbol names.

No comments, constants, or resource IDs were added or changed.

## Original-name recovery coverage

I inspected all eight registry procedures. The source registry is
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tact_dar.cpp.json`.
It records seven `matching` functions and `004CE740` `accepted_drift`.
The PDB records use module `C:\\msdev\\work\\age1_x1\\tact_dar.cpp`.

| VA | Procedure | PDB parameters | PDB locals | Source result |
| --- | --- | --- | --- | --- |
| `004CE530` | first constructor | `infile`, `obj_in` | none | Renamed `file` to `infile` and `object` to `obj_in`. |
| `004CE5F0` | target constructor | `obj_in`, `task_in`, `target_obj_in` | none | Renamed `object`, `task`, and `target` to the PDB names. |
| `004CE670` | position constructor | `obj_in`, `task_in`, `x`, `y`, `z` | none | Renamed `object` and `task`; retained the PDB names `x`, `y`, and `z`. |
| `004CE6D0` | `save` | `outfile` | none | Renamed `file` to `outfile`. |
| `004CE700` | `first_in_stack` | `first_time` | none | Renamed `value` to `first_time`. |
| `004CE720` | `set_state` | `new_state` | none | Renamed `value` to `new_state`. |
| `004CE740` | `update` | none | none | No scoped parameter or local name was available. |
| `004CE7A0` | `check_objects` | none | `map`, `x1`, `x0` | Renamed the first horizontal bound from `map_x` to PDB local `x1`; restored the inner loop variable to `x`; retained `map` and `x0`. |

Every procedure also has the PDB register symbol `this` in `ecx`. No source
change was needed for that register mapping. This is complete coverage of the
eight functions in the registry.

The PDB has no scoped records for the source names `size`, `timer`, `obj`,
`master`, `map_y`, `y0`, or `y`. I left these mappings unchanged. The former
`map_x` name was not retained because the PDB's `x1` declaration owns that
first horizontal bound. I did not force names into reused or optimized stack
slots.

The recovered names retain original spelling. No new descriptive parameter or
local names were invented in this change.

## Evidence

- Scoped PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Function packets selected by the source registry:
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE530_TRIBE_Action_Discovery_Artifact.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE5F0_TRIBE_Action_Discovery_Artifact.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE670_TRIBE_Action_Discovery_Artifact.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE6D0_save.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE700_first_in_stack.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE720_set_state.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE740_update.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE7A0_check_objects.txt`
- Original PE behavior reference:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Preserved pre-cleanup object:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tact_dar.obj`
  SHA256: `f622716efb0cb181f939634cf173ecd106241f61496b2f9767c7e7f5ceefd078`
- Preserved pre-cleanup executable:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  SHA256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

The packets show the original function boundaries, source line records, and
call targets. The PDB JSON supplies the parameter, local, and register names.
For `004CE7A0`, the packet's Ghidra listing declares `short x1` and `short x0`.
The original assembly stores the first horizontal bound at `004CE7CD`, clips
that value at `004CE804` and `004CE816`, and reloads it at `004CE86A`. The same
value drives the inner horizontal traversal. This maps the existing
`short map_x` declaration to `short x1`; it does not map the loop variable to
`x1`. The loop variable remains `short x` after this correction. Its type,
scope, conversion, clipping, and traversal expression remain unchanged.
No resource lookup occurs in this module, so no resource ID evidence or naming
request applies.

## Header and shared-file requests

- Allowed header: `include/tact_dar.h`
- Header edits: none.
- Shared declaration requests: none. Its declarations have unnamed parameters,
  so source-only parameter recovery keeps the interface unchanged.
- Resource-ID requests: none.

## Risk and unresolved points

The edits rename source identifiers and change brace placement only. They do not
change ABI types, storage, member layout, call order, literal values, or public
symbols. The correction changes only which source identifier names the existing
first horizontal bound and inner loop. Identifier and formatting effects remain
unvalidated until the final wave build. The accepted drift at `004CE740` remains
unchanged.

The missing scoped records listed above prevent stronger claims about those
source-local names. I left them unchanged. The source still uses the existing
`DAT_00575070`, `DAT_00575078`, and `DAT_0057507c` globals and the existing
narrowing casts.

## Correction history

The first cleanup commit `38d2d77200e0af6a40aa21698a6f5cf89654bb55` renamed
the inner loop variable to `x1` based on an incorrect reading of the PDB local.
Root review identified that packet `004CE7A0` assigns PDB local `x1` to the
first horizontal bound instead. Source correction commit
`033fb5bb41bc182ba34e68a686666108c3deea02` renames `map_x` to `x1` and restores
the loop variable name `x`. The correction preserves every expression and
declaration property. The prior report commit is
`7ff3dbb54e27970fdbe0349fbb2518628f48cee3`; this report records the correction.

## Validation status

I ran Git diff review and `git diff --check`. I did not run a compiler, build,
matching check, audit, or test.

**Compilation, matching, audits, and tests were not run.**
