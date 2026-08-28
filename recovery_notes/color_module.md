# color.cpp source reunification

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\color.cpp`.
- Source: `src/color.cpp`.
- Header: `include/color.h`.
- Flags: `config/flags/default.rsp`.
- The module has eight normal owners and one nearby compiler-generated scalar
  deleting destructor.

| VA | PDB lines | bytes | owner | state |
| --- | --- | ---: | --- | --- |
| `00423EE0` | 23-67 | 449 | `RGE_translate_palette` | scratch |
| `004240B0` | 71-157 | 661 | `RGE_fade_palette` | accepted drift |
| `00424350` | 162-186 | 203 | `RGE_Color_Table::RGE_Color_Table(int)` | matching |
| `00424440` | 191-209 | 169 | `RGE_Color_Table::RGE_Color_Table(FILE*, short)` | matching |
| `004244F0` | 214-239 | 243 | `RGE_Color_Table::RGE_Color_Table(char*)` | matching |
| `004245F0` | 245-319 | 424 | `RGE_Color_Table::RGE_Color_Table(TDrawArea*, long, tagPALETTEENTRY*, tagPALETTEENTRY*)` | matching |
| `004247A0` | 323-324 | 7 | `RGE_Color_Table::~RGE_Color_Table` | matching |
| `004247B0` | 329-335 | 88 | `RGE_Color_Table::save` | matching |

The address sequence follows the source-line sequence. Exact anchors are the
six matching constructors, destructor, and save method. The generated entry at
`00424420` is the scalar deleting destructor and has no handwritten owner.
The class layout in `include/color.h` gives `RGE_Color_Table` a size of
`0x128` bytes, with its virtual destructor and table fields at the proven
binary offsets. `RGE_translate_palette` is a free `__cdecl` function. The
class owner of that free function is unknown.

## Migration

`src/color.cpp` is the direct compiler-facing owner for all eight normal
functions. It defines the owners in PDB order and includes the module-local
`include/color.h` header. The old `src/color_tu.cpp` wrapper and all eight
source-bank fragments are removed. The old context header becomes
`include/color.h`.

The source has no owner `.cpp` includes, source-bank fragments, context macros,
manual vtable stores, inline assembly, fallback declarations, or codegen-only
forms. It uses the named executable source string for debug time calls instead
of a raw storage address. The two accepted-drift functions keep their reviewed
natural reconstructions. The six exact functions keep their proven field
layout, calls, loop order, and fault order.

## Header composition

The PDB records at `00424350`, `00424440`, `004244F0`, `004245F0`, `004247A0`,
and `004247B0` all name `color.cpp` as their primary source. They define the
four constructors, the virtual destructor, and `save` for `RGE_Color_Table`.
The type dump `inventory/types/dumps/RGE_Color_Table.txt` proves one vtable at
`+0x00`, fields at `+0x04` through `+0x27`, the table at `+0x28`, and size
`0x128`.

`include/color.h` now owns the complete `RGE_Color_Table` declaration. It
keeps the four constructors, the virtual destructor, `save`, and the proven
`0x128` layout. It only forward-declares `TDrawArea`.

`include/drawarea.h` now only forward-declares `RGE_Color_Table`. It owns the
canonical `TDrawArea` and `TDrawSystem` surfaces. Its `TDrawArea` layout is
size `0x100`; `GetPalette` and `SetPalette` are declared at lines 212-213.
`TDrawSystem` is the drawarea-owned size `0x47C` surface.

`src/color.cpp` includes `drawarea.h` after `color.h` for the complete
`TDrawArea` method surface. `src/drawarea.cpp` includes `color.h` after
`drawarea.h` for the complete `RGE_Color_Table` fields used by
`TDrawArea::SetShadowTable`. No duplicate support layout remains in either
module header.

## Validation

The candidate proposal and report are under
`build/candidate_tus/color_natural/`. The candidate compiles all eight normal
owners and the generated destructor in one direct translation unit.

| VA | result | rebuilt bytes | positional diff | relocations | boundary escapes |
| --- | --- | ---: | ---: | ---: | ---: |
| `00423EE0` | MISMATCH | 456 | 437 | 0 | 1 |
| `004240B0` | MISMATCH | 661 | 10 | 0 | 0 |
| `00424350` | MATCH | 203 | 0 | 0 | 0 |
| `00424440` | MATCH | 169 | 0 | 0 | 0 |
| `004244F0` | MATCH | 243 | 0 | 0 | 0 |
| `004245F0` | MATCH | 424 | 0 | 0 | 0 |
| `004247A0` | MATCH | 7 | 0 | 0 | 0 |
| `004247B0` | MATCH | 88 | 0 | 0 | 0 |
| `00424420` | MATCH | 30 | 0 | 0 | 0 |

The six exact owners and generated destructor remain exact. The
`RGE_translate_palette` observation retains a 437-byte difference and one
boundary escape from its known structural overflow. No relocation target
mismatch exists. Its source status is scratch; the natural body remains
unchanged.

The grouped candidate validation is the authoritative migration check. A
focused cached check was attempted with `--no-build --no-history`, but the
registered global `color_cpp` entry still points to the removed wrapper. The
checker therefore stopped before cache selection. The coordinator must update
that registry before focused checks can run on the final source tree.

The paired grouped checks ran after this header repair. Color used
`build/candidate_tus/color_natural/proposal.json` and wrote
`build/candidate_tus/color_header_boundary/report.json` and
`build/candidate_tus/color_header_boundary/report.txt`.

Color passed its six exact owners and generated destructor. Each had zero byte
differences, zero relocation mismatches, and zero boundary escapes. The
scratch `00423EE0` observation differed by 437 bytes with one boundary escape.
The accepted-drift `004240B0` observation differed by 10 bytes with no
boundary escape. The color summary was 6/6 exact, 1/1 generated, 0/2 observed,
and zero comparison errors. Its full-module flag remained false because
observed drift is not exact.

The Drawarea grouped check used the temporary proposal
`C:\Users\Darius\AppData\Local\Temp\pi-subagents\sa-16e9b1db\drawarea_header_boundary.json`
and wrote `build/candidate_tus/drawarea_header_boundary/report.json` and
`build/candidate_tus/drawarea_header_boundary/report.txt`. All 48 matching
owners passed with zero byte differences, relocation mismatches, and boundary
escapes. The 13 observed rows had zero comparison errors after the six
overloaded symbols were added. Their results were:

| VA | result | positional diff | boundary escapes |
| --- | --- | ---: | ---: |
| `00442A90` | MISMATCH | 453 | 0 |
| `00443520` | MISMATCH | 326 | 1 |
| `00443CB0` | MISMATCH | 7 | 0 |
| `00444040` | MISMATCH | 1 | 0 |
| `00444680` | MISMATCH | 218 | 0 |
| `00444C30` | MISMATCH | 21 | 0 |
| `00444D50` | MISMATCH | 718 | 0 |
| `00445840` | MISMATCH | 328 | 2 |
| `004459A0` | MATCH | 0 | 0 |
| `00445A60` | MISMATCH | 3 | 0 |
| `00445AF0` | MISMATCH | 4 | 0 |
| `00446230` | MISMATCH | 68 | 1 |
| `004463B0` | MISMATCH | 326 | 0 |

The Drawarea summary was 48/48 exact, 1/13 observed, zero comparison errors,
and full-module false because the accepted-drift and scratch rows are not all
exact. Both grouped reports are recorded above. No focused checks or global
tools ran.

## Integration note

The coordinator must update the global `color_cpp` translation-unit registry to
point to `src/color.cpp` and map its exact owners directly to that source. This
module migration does not change global ownership configuration.
