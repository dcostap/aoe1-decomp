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
| `00423EE0` | 23-67 | 449 | `RGE_translate_palette` | accepted drift |
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

The six exact owners and generated destructor remain exact. The two accepted
drift observations retain their pre-migration gaps. `RGE_translate_palette`
has one boundary escape from its known structural overflow. No relocation
target mismatch exists.

The grouped candidate validation is the authoritative migration check. A
focused cached check was attempted with `--no-build --no-history`, but the
registered global `color_cpp` entry still points to the removed wrapper. The
checker therefore stopped before cache selection. The coordinator must update
that registry before focused checks can run on the final source tree.

## Integration note

The coordinator must update the global `color_cpp` translation-unit registry to
point to `src/color.cpp` and map its exact owners directly to that source. This
module migration does not change global ownership configuration.
