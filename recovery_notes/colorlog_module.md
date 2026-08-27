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

## Header composition repair

The header consumes `include/basegame.h` for the PDB-owned `RGE_Base_Game`
layout and `include/drawarea.h` for the PDB-owned `TDrawArea` and `TDrawSystem`
layouts. The source includes `include/rge_base_game_global.h` for the
process-wide pointer. The public header declares no foreign class or record.
It does not include `panel.h`.

The PDB type dump proves the consumed draw members:

- `TDrawArea::Width` is at `+0x18`; `DrawSurface` is at `+0x3C`.
- `TDrawSystem::Wnd` is at `+0x04`; `DrawArea` is at `+0x0C`;
  `PrimarySurface` is at `+0x1C`; `ScreenMode` is at `+0x479`.

The `RGE_Base_Game` owner packet and type dump prove `draw_system` at `+0x48`
and `prog_mode` at `+0x1B0`. The original assembly reads these members at
`00424832` and `00424845`. The remaining assembly reads the draw members at
`00424862`, `00424873`, `0042489F`, `004248A9`, `0042491A`, `00424927`,
`0042497D`, and `004249A0`.

`src/colorlog.cpp` already uses the canonical member names. Its only source
change is the private include of `rge_base_game_global.h`. No private
`RGE_Base_Game`, `TDrawSystem`, or `TDrawArea` copy remains.

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

The final grouped candidate validation used
`build/candidate_tus/colorlog_canonical/proposal.json` after the global-pointer
include moved into `src/colorlog.cpp`.

- `00424810` returned `MATCH` and `0.0000%`.
- Original and rebuilt sizes are both 442 bytes.
- Relocation target mismatches: 0.
- Boundary escapes: 0.
- Compile errors: none.

The report is `build/candidate_tus/colorlog_canonical/report.txt`.
