# `Colorlog.cpp` source module recovery

## Ownership and order

The PDB source is `C:\\msdev\\work\\age1_x1\\Colorlog.cpp`.
The module has one normal owner:

- `color_log`, lines 13 to 68, 442 bytes

The owner is a free `__cdecl` function. The source order has no other normal,
compiler-generated, or padding owner in this module.

The executable links five calls in this owner. They are one `ClientToScreen`
call and four virtual `IDirectDrawSurface::Blt` calls. The guard chain checks the
color-log flag, the game pointer, program mode, the draw system, and the primary
surface. These checks link the owner to the `Colorlog.cpp` source context.

## Recovered context

The source uses the period Windows and DirectDraw declarations. The module
header owns the `TDrawArea`, `TDrawSystem`, and `RGE_Base_Game` layouts used by
the function. It also declares the two external game values.

The function builds two ten-pixel rectangles and one point. It converts the
point to screen coordinates in screen mode two. It then fills the primary and
draw-area surfaces with each input color. The source keeps the observed update
order and the DirectDraw flag value.

## Migration

`src/colorlog.cpp` now owns the complete handwritten module definition.
`include/colorlog.h` is the module-local declaration header. The former
`src/colorlog_tu.cpp` wrapper and matching-bank fragment are removed.

The direct translation-unit entry uses `src/colorlog.cpp` for the owner. The
source has no wrapper, source-bank include, context macro, fallback declaration,
raw address expression, or inline assembly.

## Validation

The candidate translation-unit check compiled the direct source with
`config/flags/default.rsp`. It reports `MATCH` and zero differing bytes. The
check confirms the 442-byte boundary, matching relocations, and the free
`__cdecl` owner. The candidate report is
`build/candidate_tus/colorlog_natural/report.txt`.
