# vis_unit.cpp source reunification

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\vis_unit.cpp`.
- The compiland owns 13 normal handwritten functions.
- Their source-line bands are 49-88, 91-125, 129-168, 172-258, 265-434,
  445-474, 477-518, 521-533, 537-554, 559-611, 616-665, 669-703, and
  708-792.
- Their address order is `0053B5A0`, `0053B670`, `0053B730`, `0053B7E0`,
  `0053B9A0`, `0053BB30`, `0053BBE0`, `0053BD10`, `0053BD70`, `0053BE00`,
  `0053BED0`, `0053BFD0`, and `0053C050`.
- `Visible_Unit_Manager` owns the first five functions.
  `Visible_Resource_Manager` owns the remaining eight.

## Migration

- `src/vis_unit.cpp` now owns all 13 function bodies in PDB order.
- `include/vis_unit.h` owns the records and both manager classes.
- The source includes the canonical map, world, player, object, master-object,
  and combat-object headers.
- `RGE_Tile_List_Node` uses its canonical `row` and `col` fields.
  `RGE_Tile::objects` uses the canonical object-list owner.
- `RGE_Combat_Object::VUR_Ptrs` supplies the proven derived field at `+0x194`.
- The old wrapper and per-function source fragments were removed.
- No source include, context macro, manual vtable, inline assembly, or raw
  offset overlay remains in the direct source.

## Global provider

`vis_unit.cpp` owns `VisibleUnitManager` at `0087D800`.
The PDB symbol is `?VisibleUnitManager@@3PAVVisible_Unit_Manager@@A`.

`vis_unit.h` declares it as a C++ `extern` pointer.
`vis_unit.cpp` provides the one typed definition. It has no local `void*` view.

`VISIBLE_UNIT_REC` and `VISIBLE_UNIT_PTR` are structures. Their public fields
and sizes stay `0x08`. `Update_Unit_Info` emits
`PAPAUVISIBLE_UNIT_REC@@`, as required by the PDB.

The probe object defines the PDB global symbol. It also emits the expected
`Update_Unit_Info` and `GetVisibleUnits` decorated symbols.

## Validation

- Direct grouped builds use `src/vis_unit.cpp` and the `vis_unit` source module.
- Exact direct checks passed for `0053B5A0`, `0053B670`, `0053BB30`,
  `0053BBE0`, `0053BD10`, `0053BD70`, `0053BE00`, `0053BED0`, and `0053BFD0`.
- `0053BE00` passed with canonical map, world, player, tile-list, and object
  owners. It remained 195 bytes with matching calls and boundaries.
- `0053B9A0` remains nonexact after direct migration. The natural typed-record
  scan emits 394 bytes with 371 differing bytes and a 0x10 frame.
  The oracle has 387 bytes and a 0x1C frame. A function-only `/Oy-` pragma
  moves the candidate to 381 bytes and 279 differing bytes, but it is not
  retained because the module has no reviewed function flag or pragma source.
  The earlier exact checkpoint used forbidden inline assembly.
- `0053B7E0` remains nonexact. The direct natural source emits 450 bytes with
  284 differing bytes and the correct 0x10 frame. The typed combat owner and
  VUR pointer repair are retained because they are binary-supported.
- `0053C050` remains nonexact. The direct natural source emits 349 bytes with
  308 differing bytes and the correct 0x10 frame. The oracle reads
  `VR_ListUsed[type]` before `VR_List[type]`; the source keeps the typed scan
  and its behavior, but the receiver-save and allocation basin remain open.

- The full 13-row visibility candidate still has nine exact owner matches.
  The focused Map constructor `004550A0` and combat consumers `0042FA50`,
  `00430610`, and `00430680` remain exact.

## Binary evidence for open drift

- `0053B9A0` has an oracle EBP frame with homes for found, four bounds, the
  selected player-data row, and the moving count. It mutates the category
  count and category pointer homes. The natural direct source keeps these
  values in registers or smaller homes under default `/O2 /Oy`.
- `0053C050` saves `this` in ESI before its initial list-count checks. It then
  loads `VR_ListUsed[type]` before loading `VR_List[type]`. The natural source
  has matching calls, CFG, and distance arithmetic, but VC5 keeps a different
  receiver and index lifetime.
- These facts are diagnostics. They do not justify a carrier, raw overlay, or
  compiler-only alias.

## Current classification

`0053B9A0` is scratch, not matching. The previous exact body used forbidden
inline assembly. It is absent from direct owner registration.

The full 13-owner direct candidate reports nine exact matches. Observed rows
are `0053B730` (9 bytes), `0053B7E0` (284 bytes), `0053B9A0` (371 bytes), and
`0053C050` (308 bytes). Their relocation mismatches are zero. Boundary escapes
are zero, two, one, and zero respectively.
