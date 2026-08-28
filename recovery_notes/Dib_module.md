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

The module now has one normal source file and one normal header. The shared
`bitmap_info.h` and `picture_types.h` headers own the bitmap and transparency
records. The DIB header consumes those records without duplicate definitions.
The source keeps each body in PDB order and keeps the natural period
declarations needed by these functions.

The source owns the evidence-bounded `SrcXTbl[0x500]` table. It uses the
canonical `RGE_Base_Game` and `TDrawSystem` declarations, plus the canonical
`rge_base_game` declaration. Win32 calls use the reviewed SDK declarations.
`RESFILE_load` uses its reviewed C++ declaration with typed output references.

The module removes the old wrapper, per-function includes, context-only header,
and duplicate source-bank owners. The registered translation-unit entry points
all exact owners at `src/Dib.cpp`. It does not claim nonexact or accepted-drift
owners as registered exact owners.

## Regression ledger

The final repaired grouped audit
`build/audits/dib_review_repaired_final/report.txt`
compiled all 28 owners with no compile error.

- Fourteen of the 20 registered owners remain `MATCH`, with zero positional
  bytes, zero relocation-target differences, and no boundary escape.
- Six registered owners regress in the natural source context: `ReadPalette`
  687 bytes, `DibWriteClipped` 142 bytes, `DibCreatePalette` 194 bytes,
  `DibReadBitmapInfo` 277 bytes, `DibDraw` 59 bytes, and `xlatClut8` 1 byte.
- The canonical resource-header fanout also regressed `DibOpenFile` by 22
  bytes and `DibSetUsage` by 7 bytes. Both owners are scratch and are not
  registered as exact.
- `DibBlt` remains accepted drift at 325 differing bytes.
- `TransDibBlt` remains scratch at 919 differing bytes.
- `TileDibBlt` remains scratch at 1106 differing bytes.
- `DibCheckTrans` remains accepted drift at 197 differing bytes.
- `xlatClut4` remains accepted drift at 36 differing bytes.
- `xlatRle8` remains accepted drift at 3 differing bytes.
- `DibMapToPalette` remains scratch at 926 differing bytes and has one
  boundary escape.
- `memmove` remains scratch at 39 differing bytes and has two boundary
  escapes.

The direct declaration repairs keep `ReadDibBits` and `CopyPalette` exact.
The typed blitter repairs preserve source behavior but change VC5 code shape.
The six registered regressions need repair after the structural migration.

These boundary escapes are context regressions from the old fragment wrapper,
not behavior changes. No source was changed to hide them.

The candidate validator was also run. It rejected this natural module because
it requires exact owners in `src/matching` and one source include per owner.
That rule does not support a reunified source owner. The grouped audit is the
valid migration check.

## Open questions

- The old exact group used a wrapper with declarations interleaved between
  function bodies. A normal header moves those declarations to module scope.
  This is the required source shape, but it alters VC5 register scheduling.
- `DibFromBitmap` remains exact in the repaired natural module.
- The current grouped audit records all six exact-owner regressions. Do not
  promote those owners until their final source context is repaired.
- `DibRgeBaseGameView` and `DibDrawSystemView` are removed. `DibCreatePalette`
  now uses the canonical `RGE_Base_Game` and `TDrawSystem` providers.
- No shared header currently owns `shape_file_first` or `RESFILE_load`. Their
  module-local declarations use the target's reviewed C++ symbols. A coordinator
  may move them to shared headers when their global owners are reunified.
