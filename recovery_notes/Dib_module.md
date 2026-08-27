# Dib.cpp source reunification

## Context gate

- PDB source: `C:\\msdev\\work\\age1_x1\\Dib.cpp`.
- Source lines run from 72 through 2031.
- All 28 normal owners are free functions. No class owner applies.
- The address sequence is the packet order, not numeric order near the end:
  `DibBlt`, `TransDibBlt`, `ClipDibBlt`, `GetDibDim`, `TileDibBlt`,
  `DibCheckTrans`, `GetPaletteFromDib`, `ReadPalette`, `DibOpenFile`,
  `ReadDibBits`, `DibWriteClipped`, `DibWriteFile`, `DibCreatePalette`,
  `DibReadBitmapInfo`, `DibFromBitmap`, `DibSetUsage`, `DibDraw`, `DibCopy`,
  `DibCreate`, `xlatClut8`, `xlatClut4`, `xlatRle8`, `xlatRle4`, `memmove`,
  `DibMapToPalette`, `CreateIdentityPalette`, `CopyPalette`, `DibFree`.
- Exact anchors are the 19 owners registered by the former `dib_prefix`
  group. `DibFromBitmap` also has a target-only exact source. The four
  accepted-drift owners and four scratch owners have documented local evidence
  in their former source headers.
- The final owner is `src/Dib.cpp`; the former wrapper and function fragments
  are not compiler-facing sources.

## Reunification

The module now has one normal source file and one normal header. The header owns
DIB, transparency-line, and palette-blit layouts. The source keeps each body in
PDB order and keeps the natural period declarations needed by these functions.

The module removes the old wrapper, per-function includes, context-only header,
and duplicate source-bank owners. The registered translation-unit entry points
all exact owners at `src/Dib.cpp`. It does not claim nonexact or accepted-drift
owners as registered exact owners.

## Regression ledger

The grouped audit `build/audits/dib_reunified/report.txt` compiled all 28
owners with no compile error.

- The 19 former registered exact owners remain `MATCH`, with zero positional
  bytes, zero relocation-target differences, and no boundary escape.
- `DibFromBitmap` is `MATCH` in the reunified module. It is now registered in
  the `dib` translation-unit entry.
- `DibBlt` remains its documented accepted drift at 317 differing bytes.
- `TransDibBlt` remains scratch at 603 differing bytes.
- `TileDibBlt` remains scratch at 1104 differing bytes.
- `DibCheckTrans` remains its documented accepted drift at 197 differing
  bytes.
- `xlatRle8` remains its documented accepted drift at 3 differing bytes.
- `DibMapToPalette` remains scratch at 879 differing bytes and escapes its
  original boundary with one reported boundary escape.
- `xlatClut4` remains accepted drift and now emits 36 differing bytes. Its
  grouped extraction reports one boundary escape.
- `memmove` remains scratch and emits 39 differing bytes. Its grouped body
  grouped extraction reports two boundary escapes.

These boundary escapes are context regressions from the old fragment wrapper,
not behavior changes. No source was changed to hide them.

The candidate validator was also run. It rejected this natural module because
it requires exact owners in `src/matching` and one source include per owner.
That rule does not support a reunified source owner. The grouped audit is the
valid migration check.

## Open questions

- The old exact group used a wrapper with declarations interleaved between
  function bodies. A normal header moves those declarations to module scope.
  This is the required source shape, but it can alter VC5 register scheduling.
- `DibFromBitmap` was exact in isolation and nonexact in the old full wrapper.
  The natural module now keeps it exact and registers that owner.
- The old `DibMapToPalette` owner used local imported-helper declarations.
  The reunified source keeps those ABI declarations without adding a wrapper.
