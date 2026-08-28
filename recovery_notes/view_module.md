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

`validate_candidate_tu.py` compiled the direct source on current main. The 48
registered owners report `MATCH`, `0.0000%`, correct ownership, boundaries,
and relocations.

The other 31 rows keep their existing scratch,
accepted-drift, or verified-logic status. This merge does not claim new
behavior for them.

The candidate records decorated names for the five overloaded rows. It has no
comparison errors.

Direct source compilation succeeds with the pinned VC5 compiler.
