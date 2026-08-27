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
`TPanel`, `TScrollBarPanel`, `TVerticalSliderPanel`, and
`THorizontalSliderPanel` surfaces and sizes.

## Migration

`src/pnl_sld.cpp` is the direct compiler-facing source owner for all ten normal
functions. It follows PDB order and has no `.cpp` includes, context macros,
fallback declarations, raw address fields, inline assembly, or manual vtables.
The setup methods use the named `one_step` and `page_step` members at offsets
`0xFC` and `0x100`. The horizontal rectangle method uses the named inherited
fields for the proven rectangle calculations.

The old `src/pnl_sld_tu.cpp` wrapper, ten source-bank fragments, and
`include/pnl_sld_context.h` are removed. The module-local header is now
`include/pnl_sld.h`. The source-module manifest records all ten normal owners as
`matching`. The two scalar deleting destructors remain outside the handwritten
owner list.

## Validation

The candidate translation-unit validation uses `config/flags/default.rsp` and
compares all ten normal owners plus both compiler-generated destructors. Its
report is under `build/candidate_tus/pnl_sld/`.

The global translation-unit registry still names the removed wrapper and source
bank fragments. This captain did not edit `config/translation_units.json` or
other ownership data. The main integration owner must replace that registered
entry with `src/pnl_sld.cpp` and keep the same qualified symbols.
