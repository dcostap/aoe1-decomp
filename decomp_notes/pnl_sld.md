# pnl_sld.cpp source reunification

## Context

The PDB identifies `C:\\msdev\\work\\age1_x1\\pnl_sld.cpp` as the owner of ten
normal functions. Their source-line order is also their address order in the
module. The nearby scalar deleting destructors at `0047BD10` and `0047BE10`
are compiler-generated and are not handwritten owners.

| VA | PDB lines | bytes | owner |
| --- | ---: | ---: | --- |
| `0047BCE0` | 24-25 | 38 | `TVerticalSliderPanel` constructor |
| `0047BD30` | 30 | 11 | `TVerticalSliderPanel` destructor |
| `0047BD40` | 39-54 | 127 | `TVerticalSliderPanel::setup` |
| `0047BDC0` | 60-75 | 28 | `TVerticalSliderPanel::set_rect` |
| `0047BDE0` | 80 | 5 | `TVerticalSliderPanel::draw` |
| `0047BDF0` | 126-127 | 18 | `THorizontalSliderPanel` constructor |
| `0047BE30` | 132 | 11 | `THorizontalSliderPanel` destructor |
| `0047BE40` | 141-156 | 127 | `THorizontalSliderPanel::setup` |
| `0047BEC0` | 162-176 | 102 | `THorizontalSliderPanel::set_rect` |
| `0047BF30` | 181 | 5 | `THorizontalSliderPanel::draw` |

The constructor anchors, setup anchors, and virtual method anchors identify the
owning classes and their order. The module header records the proven
`TVerticalSliderPanel` and `THorizontalSliderPanel` surfaces and sizes.

## Header composition repair

`include/pnl_sld.h` now consumes `include/Pnl_scbr.h` for the canonical
`TScrollBarPanel` owner. That header composes the canonical `pnl_lst.h`,
`panel.h`, `drawarea.h`, `Shape.h`, and `color.h` owners. The slider header
declares only the PDB-owned `TVerticalSliderPanel` and
`THorizontalSliderPanel` classes and their size records.

The copied `TPanel` and `TScrollBarPanel` layouts and their size checks are
removed. No canonical owner is missing. No compiler or validator command ran
in this header-composition wave.

## Migration

`src/pnl_sld.cpp` is the direct compiler-facing source owner for all ten normal
functions. It follows PDB order and has no `.cpp` includes, context macros,
fallback declarations, raw address fields, inline assembly, or manual vtables.
The setup methods use the named `one_step` and `page_step` members at offsets
`0xFC` and `0x100`. The horizontal rectangle method uses the named inherited
fields `pnl_x`, `pnl_wid`, and `pnl_hgt`, then writes the canonical `RECT` and
tab fields for the proven rectangle calculations. The former local aliases
`left1`, `left2`, `right1`, `right2`, `min_right`, `span`, and `min_left` are
removed.

The old `src/pnl_sld_tu.cpp` wrapper, ten source-bank fragments, and
`include/pnl_sld_context.h` are removed. The module-local header is now
`include/pnl_sld.h`. The source-module manifest records all ten normal owners as
`matching` and records the repaired header composition. The two scalar deleting
destructors remain outside the handwritten owner list.

## Validation

The grouped candidate translation-unit validation uses
`config/flags/default.rsp` and compares all ten normal owners plus both
compiler-generated destructors. The first compile exposed the stale aliases
in the horizontal rectangle method. After replacing them with canonical
inherited fields, the final run reported `MATCH` for all twelve rows, with
zero positional difference, boundary escapes, and relocation target
mismatches. Its report is under `build/candidate_tus/pnl_sld/`.

The global translation-unit registry already points all ten normal owners to
`src/pnl_sld.cpp` and keeps the qualified symbols. No registry update is
needed for this module.
