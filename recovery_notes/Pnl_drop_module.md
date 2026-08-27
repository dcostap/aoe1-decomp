# Pnl_drop.cpp module merge

- PDB source: `C:\\msdev\\work\\age1_x1\\Pnl_drop.cpp`.
- Source: `src/Pnl_drop.cpp`.
- Header: `include/pnl_drop.h`.
- Packet: `build/tu_plans/pnl_drop_cpp/Pnl_drop_cpp/packet.json`.

## Source order

The source keeps all 40 normal owners in PDB order:

`00473ED0`, `00473F50`, `00473FD0`, `00474340`, `00474350`, `00474400`,
`00474420`, `00474450`, `004744A0`, `00474550`, `004745E0`, `00474600`,
`00474630`, `00474670`, `00474820`, `00474880`, `00475110`, `00475130`,
`00475150`, `00475160`, `004751C0`, `004751E0`, `00475210`, `00475230`,
`00475250`, `004752A0`, `004752D0`, `00475300`, `00475330`, `00475360`,
`00475380`, `004753A0`, `004753C0`, `004753E0`, `00475400`, `00475420`,
`00475440`, `00475460`, `00475470`, `004754C0`.

The source owns `TDropDownPanel` and `TDropDownButtonPanel`. The module-local
header contains the reviewed panel declarations and layouts. The source contains
all function bodies in source order.

The migration removes the wrapper, per-function `.cpp` includes, context macro,
fallback declarations, and bank fragments. The scalar deleting destructor at
`00473F30` and vector deleting destructor at `00475490` remain compiler-generated.

## Status

The packet lists 37 matching owners, two scratch owners, and one accepted-drift
owner:

- Scratch: `00473FD0` (`setup`) and `00474880` (`set_mode`).
- Accepted drift: `004754C0` (`TDropDownButtonPanel::handle_mouse_move`).
- Matching: the other 37 normal owners.

The source-shape migration does not claim grouped byte equality. The merged TU
audit rechecked all 40 normal owners.

## Evidence and regressions

The PDB identifies `Pnl_drop.cpp`, lines 26-860, and the address sequence above.
Exact constructor, destructor, event, forwarding, and list-helper donors use the
same panel header and direct owner surface. The setup and set_mode bodies retain
the latest typed scratch reconstructions. The accepted-drift body retains the
reviewed nine-call forwarding behavior.

The old wrapper registration used `src/pnl_drop_tu.cpp` and
`config/flags/default_gx.rsp`. The new registry entry uses `src/Pnl_drop.cpp` and
maps the 37 registered exact owners directly to that source. Setup and set_mode
remain observed. The accepted-drift owner remains unregistered.

Final grouped validation used:

`python tools/audit_translation_unit_observed.py --group pnl_drop --jobs 1 --output-dir build/audits/Pnl_drop_final --print-full`

The audit compiled one source module and included all 40 normal owners. The 37
registered exact owners remain `MATCH` with zero positional differences, zero
relocation target mismatches, and zero boundary escapes. The accepted-drift owner
`004754C0` remains a 15-byte grouped mismatch with no relocation or boundary
change.

The two scratch owners remain unresolved. `00473FD0` (`setup`) has 162 differing
bytes with no relocation or boundary change. `00474880` (`set_mode`) has 889
differing bytes, four relocation target mismatches, and one boundary escape.
The boundary and relocation differences come from the natural merged header and
enum call declarations. Earlier alias-rich context measured 875 differing bytes
with no relocation mismatch, but it retained unused fallback aliases. The
natural form is kept for source recovery and the regression is recorded here.

The generated scalar destructor at `00473F30` and vector destructor at `00475490`
remain compiler-generated and are not normal source owners. Their grouped object
checks both report `MATCH`, 30 bytes, zero relocation mismatches, and no boundary
escapes. Standalone validation of `00473ED0` and `00475470` reports
`Result: MATCH` and `0.0000%`. Source policy checks report no wrapper include,
context macro, inline assembly, or fallback declaration in the merged module.
