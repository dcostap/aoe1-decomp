# scr_cred.cpp source reunification

## Source context

The PDB source is `C:\\msdev\\work\\age1_x1\\scr_cred.cpp`.
The sixteen normal owners span lines 46 through 753 and keep this address order:

`004926E0`, `00492970`, `00492A40`, `00492A50`, `00492CC0`, `00492D50`,
`00492D70`, `00492DB0`, `00492E70`, `00492F70`, `00492F80`, `00492FB0`,
`00493070`, `00493160`, `00493420`, `00493540`.

`TRIBE_Credits_Screen` owns the first eight methods. `TScrollTextPanel` owns
`00492E70` through `00493160`. The two palette functions are free functions.
The scalar deleting destructor at `00492950` and vector deleting destructor at
`00492F50` are compiler generated. They have no PDB source-line owners.

The exact constructor, destructor, event, panel, and palette symbols anchor the
source sequence. The merged source has one compiler-facing owner for every
normal function in this PDB compiland.

## Migration

`src/scr_cred.cpp` now contains all sixteen function bodies in PDB order.
`include/scr_cred.h` is the module-local declaration header. The old
`src/scr_cred_tu.cpp` wrapper and all per-function bank sources were removed.
The source has no `.cpp` includes, context macros, inline assembly, raw vtable
field, or fallback declaration block.

The accepted-drift body at `00492FB0` remains unchanged in behavior. Its x87
multiply uses the equivalent VC5 `fimul` encoding rather than the original
`fild` plus `fmulp` pair.

## Validation

The final grouped audit was:

`python tools/audit_translation_unit_observed.py --group scr_cred --jobs 1 --output-dir build/audits/scr_cred_final --print-full`

It compiled `src/scr_cred.cpp` with the existing `/GX` response file and found
all sixteen normal owners. Fourteen registered exact owners stayed `MATCH` with
zero positional differences, zero relocation target mismatches, and zero
boundary escapes. Standalone checks also report `MATCH` and `0.0000%` for the
fourteen exact owners.

The grouped observed result for `00492FB0` is 184 bytes with 84 differing bytes,
zero relocation mismatches, and zero boundary escapes. This is the recorded
accepted drift. The direct checker cannot select this owner alone because the
merged source also defines `TRIBE_Credits_Screen::handle_idle`.

The grouped observed result for scratch owner `00493160` is 666 bytes with 614
differing bytes, one missing ordered `TextOutA` call, zero relocation mismatches,
and zero boundary escapes. The full source keeps the natural 23-call body, but
VC5 merges one tail call in the authentic prefix context. The owner remains
scratch.

The generated destructor checks remain compiler-generated and are not source
owners. Source policy inspection found no wrapper include, context macro, inline
assembly, placeholder virtual slot, or raw vtable field.

## Evidence blocker

`tools/validate_candidate_tu.py` still requires exact proposal owners to be in
`src/matching` and requires each owner as one wrapper include. It rejects a
valid direct module proposal whose exact owners map to `src/scr_cred.cpp`.
The final direct-source audit and standalone checks provide the validation until
that tool supports registered source modules.
