# Recovery journal: 00439E50 `DibReadBitmapInfo`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Dib.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Dib.cpp`.
- Earlier recovery note: `recovery_notes/Dib_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:b7f7fb9716e5ce2806ff -->
### `target-session` `build/target_sessions/00439E50_DibReadBitmapInfo.json:1-10`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=277; shape=94.94949494949495: Canonical DIBUTILS typed reconstruction: exact frame, saved registers, calls, and first 0xF0 bytes; mismatch begins at color-table guard and later REP-copy lowering.
probe 2 control-flow; result=MISMATCH; diff=277; shape=94.94949494949495: Hypothesis: explicit nNumColors != 0 comparison prevents VC5 hoisting the size load before the outer color guard. [same emitted code as probe 1]
probe 3 variant; result=MISMATCH; diff=277; shape=94.94949494949495: Hypothesis: explicit post-read FixBitmapInfo statements, rather than the macro invocation, match the historical #if 0 source expansion and alter local liveness. [same emitted code as probe 2]
probe 4 context; result=MISMATCH; diff=277; shape=94.94949494949495: Hypothesis: restore the period DIBUTILS unused HANDLE hbi = NULL declaration, which may affect VC5 front-end/register state without changing frame size. [same emitted code as probe 3]
probe 5 control-flow; result=MISMATCH; diff=297; shape=93.46733668341709: Hypothesis: spell the first color-count computation as an explicit assignment plus short-circuit if, preserving nNumColors test before the bit-count load.
probe 6 layout; result=MISMATCH; diff=277; shape=94.94949494949495: Hypothesis: direct period expression for the palette pointer, rather than the DibColors macro call, preserves the original pdib base register and post-copy add topology. [same emitted code as probe 4]
probe 7 liveness; result=MISMATCH; diff=224; shape=93.29896907216495: Diagnostic hypothesis: volatile bit-count reread blocks the observed pre-guard load hoist while retaining the same color-count expression.
probe 8 layout; result=MISMATCH; diff=277; shape=94.94949494949495: Hypothesis: retain a named byte base for the allocated DIB before adding biSize, which may recover the original EDX size load and ESI base copy. [same emitted code as probe 6]
probe 9 context; result=MISMATCH; diff=277; shape=94.94949494949495: Context probe: remove unused windowsx.h while keeping period Windows DIBUTILS declarations, to test header-state influence on post-read scheduling. [same emitted code as probe 8]
probe 10 context; result=MATCH; diff=0; shape=100.0: Context probe: reduce the target to windows.h plus local DIBUTILS declarations, removing unused CRT and memory headers.
```
<!-- end-recovered:b7f7fb9716e5ce2806ff -->

<!-- recovered:2de7a65a7b97a9f818a6 -->
### `6b1e42984560` `src/scratch/00439E50_DibReadBitmapInfo.cpp:1-28`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00439E50 DibReadBitmapInfo
// Attempt log:
// - initial natural DIB loader from packet/decompiler with local Win16 bitmap
//   structs had the right 544-byte size but broad prologue/register drift.
// - restored the period DIBUTILS source family: ordered `off/size/i/nNumColors`
//   locals, native BITMAPFILEHEADER/BITMAPINFOHEADER/BITMAPCOREHEADER types,
//   aggregate `*pdib = bi`, and the RGBTRIPLE-to-RGBQUAD conversion loop.
// - this is the canonical source reconstruction to test before any focused
//   frame/register probes; no raw stack offsets or register forcing retained.
// - split/nested color-count guards and exact historical WIDTHBYTES macro
//   variants did not close the localized post-read scheduling gap; a focused
//   27-variant lab found no exact output. The best diagnostic volatile reread
//   moved structure but worsened positional bytes and was rolled back.
// - reversed width-times-bitcount operands and removed an unproven stdlib
//   include; both emitted the same code. A first-guard volatile reread moved
//   the first mismatch three bytes earlier and worsened the diff, then was
//   restored.
// - left in scratch: frame/saved-register and call topology match, but the
//   original keeps a second bit-count reload and different late RGB-table
//   branch/register schedule beginning at 00439F40.
// - tried the period typed FixBitmapInfo macro for post-read header cleanup;
//   it kept the DIBUTILS API surface but was a codegen duplicate, so it stays
//   as the more natural source form with no metric change.
// - restored the DIBUTILS trailing BI_BITFIELDS no-op guard from the published
//   header; it was a codegen duplicate and was removed from the clean source.
// - same-TU DibCreatePalette donor suggested direct color-count staging;
//   direct and separate temporary forms worsened or duplicated the first hunk.
//   A positive nested guard improved only diagnostic bytes and was rolled back.
```
<!-- end-recovered:2de7a65a7b97a9f818a6 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
