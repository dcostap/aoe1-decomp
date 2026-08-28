# view.cpp source module

## Scope

- PDB source: `C:\\msdev\\work\\age1_x1\\view.cpp`.
- Source: `src/view.cpp`.
- Header: `include/view.h`.
- Flags: `config/flags/00533510_RGE_View.rsp`.

The module has 79 normal owners. `src/view.cpp` keeps them in PDB source
order. It is their only compiler-facing source.

The compiler-generated deleting destructor at `00533740` is not a normal
owner. VC5 emits it from the constructor and destructor context.

## Type ownership

`view.h` owns the public View and DClip declarations. It also owns the shared
PDB pick records:

- `RGE_Pick_Info`, 0x14 bytes, view.cpp lines 3566-3575;
- `RGE_Pick_Obj_Info`, 0x0C bytes, view.cpp lines 3577-3585; and
- `extern RGE_Pick_Obj_Info Picked_Objects[]`.

`RGE_Main_View` consumes these records. It must not define another copy.
`Picked_Objects` remains an external declaration. This module does not define
its storage.

The tile-edge, queued-blit, selected-display, overlay-sprite, and short pick
list records stay private to `src/view.cpp`. No other public module needs their
complete definitions.

## Validation

`validate_candidate_tu.py` compiled the direct source on current main. The 47
registered owners report `MATCH`, `0.0000%`, correct ownership, boundaries,
and relocations.

The other 31 rows keep their existing scratch,
accepted-drift, or verified-logic status. This merge does not claim new
behavior for them.

The candidate records decorated names for the five overloaded rows. It has no
comparison errors.

Direct source compilation succeeds with the pinned VC5 compiler.

## Natural-source audit

The direct source has no wrapper, fragment include, context macro, absolute
address, field-alias macro, alias union, `volatile`, or `register` form.

It uses the PDB field names for DClip, selected-display records, pick records,
tile object lists, and queued blits. It uses `TDrawArea::Wnd` for cursor
placement. File relocation work uses byte pointers only for the loaded tile
edge buffers.

The audit demoted `005381C0` to scratch. `Update_Render_Pointers` now uses
the canonical pixel buffer and pitch. Its direct candidate result is a
164-byte mismatch with one boundary escape. The remaining 47 exact rows still
report `MATCH`, `0.0000%`.

## Final source repair

The source uses C++ `new` and `delete` for View-owned objects. It keeps the
explicit `TPanel::~TPanel()` call. The original View destructor has two panel
destructor calls.

The source uses the CRT, I/O, and Windows headers. It has no local CRT, I/O,
Windows API, allocation, or deallocation declarations.

PDB records only the reference form of `get_border_edge_pictures`. The header
has only that form. `draw_tile` passes its four result variables as lvalues.
`set_player` uses `-9999.0f` for both cached view coordinates.

The final direct candidate retains all 47 exact `MATCH`, `0.0000%` rows. It
has no comparison errors, relocation errors, or boundary errors.
