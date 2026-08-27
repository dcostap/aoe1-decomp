# move_obj.cpp module recovery

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\move_obj.cpp`.
- Source order is the reviewed address and line sequence from 0045C450 through 00460F40.
- The module has 51 normal owners and 18,917 normal bytes.
- The compiler-facing owner is `src/move_obj.cpp`.
- Shared class and API layouts live in `include/move_obj.h`.
- The nearby 0045C5A0 deleting destructor remains compiler-generated.

## Migration

The former `src/move_obj_tu.cpp` wrapper included one fragment per owner. The
module now defines all 51 normal owners in one source file, in PDB order.
Fallback class declarations, source-bank includes, context macros, and wrapper
machinery are removed. The source keeps the reviewed owner status for each
function in `config/source_modules/move_obj.json`.

The matching owners had standalone exact checks before this structural move.
Grouped output can change when the full source context changes. Such changes
are structural migration regressions, not new behavior claims. Re-run grouped
checks before exact promotion.

## Remaining reviewed status

- `0045D150`, `00460940`, and `00460F40` remain accepted drift.
- `0045D3D0`, `0045DB90`, and `0045E970` remain scratch.
- All other normal owners retain their reviewed source-bank status.

## Structural audit

The observed translation-unit audit compiled all 51 owners from
`src/move_obj.cpp`. It found 15 registered exact owners and 17 additional
grouped matches. The following owners regressed in the full source context:

- 0045C700: 3 bytes, direct destructor target differs.
- 0045C790: 2 bytes, direct relocation target differs.
- 0045D150: 10 bytes, accepted drift remains closed.
- 0045D3D0: 113 bytes, boundary escape.
- 0045D6C0: 1117 bytes.
- 0045DB90: 3037 bytes, direct relocation targets differ.
- 0045E970: 2799 bytes, direct relocation target differs.
- 0045F820: 365 bytes, boundary escape.
- 0045F9D0: 390 bytes, boundary escape.
- 0045FBC0: 637 bytes, boundary escape.
- 0045FED0: 431 bytes, boundary escape.
- 004600F0: 228 bytes, boundary escape.
- 00460210: 2 bytes.
- 004603B0: 1 byte.
- 00460570: 1 byte.
- 00460710: 243 bytes, boundary escape.
- 004608D0: 29 bytes.
- 00460900: 34 bytes.
- 00460940: 9 bytes, accepted drift remains closed.
- 00460970: 1 byte.
- 00460C00: 249 bytes, boundary escape.
- 00460F40: 16 bytes, accepted drift remains closed.

Removing the incorrect `RGE_Static_Object::stopObject` virtual declaration
from the module header fixed the inherited new-angle slot. It restored exact
output for 00460EB0 and reduced the grouped mismatch set. The current audit
report is `build/audits/move_obj_observed2/report.json`.
