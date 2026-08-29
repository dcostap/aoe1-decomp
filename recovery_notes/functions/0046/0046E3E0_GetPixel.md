# Recovery journal: 0046E3E0 `GetPixel`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Picture.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Picture.cpp`.
- Earlier recovery note: `recovery_notes/Picture_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3585310abd40ad5bd81f -->
### `d661f1606d56` `src/scratch/0046E3E0_GetPixel.cpp:1-29`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0046E3E0 TPicture::GetPixel
// Picture.cpp lines 256-286
//
// Attempt log:
// - Existing scratch was a decompiler-shaped bpp/pixel-format reconstruction;
//   it had no AlignedWidth calls and did not model the proven orientation/row
//   addressing behavior.
// - Reconstructed the canonical TPicture layout and four orientation/row cases;
//   all four direct AlignedWidth call sites and the signed bounds now align.
// - A ternary `(orientation != 1) ? 1 : -1` reproduces VC5's original
//   dec/neg/sbb/and-eax/dec transform; x <= 0 reproduces test/jle.
// - Tried outer-arm order, an explicit dispatch label, a shared stride local,
//   and explicit if/else. VC5 retains a different outer branch/block basin and
//   merges one pair of call tails; best emitted probe was 123 differing bytes.
// - Final source keeps the period-plausible four-return form and the binary-
//   supported `Height - y - 1` row expression; residual drift is CFG/block
//   placement and call-tail merging, not an unresolved field or behavior fact.
//
// Fresh pass (orch-luna-46e3e0-w2, prior 10 probes not repeated):
// - Reversing the mode arms to nonzero-first with `Height - y - 1` improved the
//   structural diff from 129 to 107 bytes and reproduced the original `test/je`
//   dispatch topology; this is the retained source-level CFG hypothesis.
// - Pointer-base and row-offset spellings improved edit/resync diagnostics and
//   exposed the original Bits/row/Width scheduling, but remained nonexact.
// - A raw 32-bit address variant reached 94 differing bytes, then was rolled
//   back as compiler-steering scaffolding rather than period-plausible source.
// - Final fresh-pass state retains the natural nonzero-first four-arm source;
//   residual drift is the +4-byte arithmetic/register basin in the pixel arms.
//
```
<!-- end-recovered:3585310abd40ad5bd81f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
