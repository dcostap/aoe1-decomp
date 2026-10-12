# tpnl_inv.cpp source reunification

## Context gate

- PDB source: `C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp`.
- The eight normal owners follow source lines 33 through 265.
- `TRIBE_Panel_Inven` owns each normal body.
- The address order is `0051A5C0`, `0051A6B0`, `0051A6D0`, `0051A770`,
  `0051AAD0`, `0051ABF0`, `0051AC10`, and `0051ACA0`.
- The constructor, virtual slots, helper calls, and resource IDs anchor it.
- `0051A690` is a generated scalar deleting destructor.

## Ownership

`src/tpnl_inv.cpp` owns all normal bodies in PDB order.
`include/tpnl_inv.h` owns only `TRIBE_Panel_Inven`.
It uses the canonical panel, shape, player, base-game, and draw-area owners.

The source has no wrapper, fragment include, copied foreign layout, raw cursor,
manual vtable, or inline assembly.

The destructor calls `TPanel::~TPanel` in its body. The executable then uses
compiler cleanup for a second base-destructor call.

`handle_idle` needs an `int` changed flag. The executable stores it as a dword.

## Validation

The preserved natural candidate used `/nologo /c /O2 /GX`.
It matched all eight normal owners and the generated deleting destructor.
The candidate had no relocation mismatch or boundary escape.

The direct source replaces the old `tpnl_inv_tu.cpp` wrapper.
The module metadata now records the direct canonical owner.
