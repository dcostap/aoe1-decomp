# Picture.cpp source reunification

- PDB source: `C:\\msdev\\work\\age1_x1\\Picture.cpp`.
- Source: `src/Picture.cpp`.
- Header: `include/Picture.h`.
- Flags: `config/flags/default.rsp`.

## Context gate

- The PDB packet proves `Picture.cpp` as the source module.
- The packet proves the source lines and order: 11-22, 25-76, 79-88,
  91-109, 112-123, 126-197, 200-216, 219-221, 224-241, 246-252,
  and 256-286.
- The PDB symbols prove `TPicture` owns all 11 normal functions.
- The address sequence is `0046DDE0`, `0046DE30`, `0046DFA0`, `0046DFC0`,
  `0046E020`, `0046E0B0`, `0046E270`, `0046E2C0`, `0046E2D0`, `0046E370`,
  and `0046E3E0`.
- The original assembly and existing checks prove the constructor, destructor,
  save/load, draw, tile, and pixel call and boundary anchors.
- The packet reports no nearby compiler-generated owners.

## Migration

`src/Picture.cpp` owns all 11 bodies in PDB order. It replaces the old wrapper,
source-bank fragments, and `picture_context.h`. The module has one direct source
owner and one module-local header. It has no source-bank includes, fallback class
declarations, context-selection macro, inline assembly, or absolute address.

The header models the proven DIB, transparency, draw-area, and `TPicture`
layouts. The source uses typed fields and ordinary pointer expressions. The
accepted-drift status of `0046E270` remains unchanged.

## Prior state and validation

The old `picture` translation unit registered 10 exact owners. `0046E270` was
accepted drift and was not registered. A structural migration can change grouped
code generation while the source moves.

The constrained candidate check used `build/candidate_tus/Picture.json`. It
compiled all 11 owners. Eight of the ten exact owners returned `MATCH`.
`0046DE30` differed by 119 bytes and reported one boundary escape after the
typed module merge. `0046E3E0` differed by 96 bytes after the natural pointer
indexing cleanup. The known accepted six-byte drift remained at `0046E270`.
The other eight exact owners returned `MATCH`, with zero relocation target
mismatches. `0046DE30` and `0046E3E0` are scratch and are removed from the
direct exact registry. No focused rebuild was run after this candidate check.

## Header ownership repair

`include/Picture.h` uses `include/drawarea.h` for Windows bitmap records,
`BITMAPINFO256`, and `TDrawArea`. It no longer copies these owner types.

`include/picture_types.h` owns the shared `LINEINFO` and `TRANSINFO` records.
`Picture.h` owns `TPicture`. Their PDB sizes are 0x10, 0x18, and 0x20 bytes.

Source-local declarations now own the DIB and file helper declarations used
by `Picture.cpp`. This keeps foreign declarations out of the public header.

Focused checks of constructor, destructor, load, aligned width, draw, and tile
all report `MATCH` after this header change. The existing scratch and
accepted-drift rows remain unchanged.
