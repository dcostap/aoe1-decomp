# Mouseptr.cpp source reunification

The module now uses `src/Mouseptr.cpp` in PDB source order. The former
per-function wrapper and source-bank fragments are removed. `include/Mouseptr.h`
owns the mouse-pointer layout and uses the canonical `TDrawArea` and
`TDrawSystem` declarations from `include/drawarea.h`.

## PDB source order

`0045AE50` constructor, `0045B000` destructor, `0045B040` `Shutdown_Mouse`,
`0045B0A0` `Restore_Mouse`, `0045B120` `setup`, `0045B290` through `0045B2E0`
mode and window helpers, `0045B310` `LoadCursors`, `0045B560`
`delete_surfaces`, `0045B5D0` `create_surfaces`, `0045B760`
`update_mouse_position`, `0045BA60` `draw`, `0045BD60` `erase`, `0045BE20`
`set_facet`, `0045BE80` `set_game_facet`, `0045BEE0` through `0045BF90`
state helpers, `0045C010` `Poll`, and `0045C300` `GetDDBltError`.

## Status and regressions

Before migration, 20 owners were registered exact, three were accepted drift,
and the constructor was scratch. The plan packet records these counts.

The migration keeps the constructor as scratch. It keeps `delete_surfaces`,
`draw`, and `set_game_facet` as accepted drift. Their source now uses natural
`delete`, canonical DirectDraw member calls, and canonical draw-area types.

The current policy audit retains `delete_surfaces` as accepted drift. Its fresh
check has 93 positional differences but only 35 edit bytes. The frame, five
calls, CFG, owner symbol, relocations, and boundary all match. The medium
instruction-scheduling difference is limited to entry register and block
order, so it remains localized equivalent drift. The other two rows remain
accepted drift pending their own fresh checks.

The candidate grouped build found 19 of 20 exact owners. `Poll` regressed from
exact to a 10-byte positional mismatch. It stays scratch and is removed from
direct exact ownership. The constructor remains 338 bytes
different, `delete_surfaces` is 93 bytes different, `draw` is 53 bytes
different, and `set_game_facet` is 13 bytes different. These are stale exact
claims for the unified source until the integration owner repairs or removes
them. All four observed owners kept the expected symbols and boundaries.

The old wrapper depended on per-function `.cpp` includes. The old fragments
used local context headers, direct vtable macros, and explicit delete helpers.
The unified source has no wrapper, fragment include, raw vtable macro, inline
assembly, or codegen-only function.

The first candidate validation was a preflight rejection. It ran before module
metadata existed, so it did not compile the candidate. The final candidate
validation compiled one grouped object with `/nologo /c /O2 /Oy /GX` and found
no comparison errors. It did not find a fully exact module.

## Evidence

The source order and owner set come from `build/tu_plans/Mouseptr_cpp/packet.json`.
The `TMousePointer` size is `0x254` in the reviewed layout. The canonical
`TDrawArea` surface comes from `include/drawarea.h`. The original module uses
`/nologo /c /O2 /Oy /GX` from `config/flags/mouseptr_module_gx.rsp`.
