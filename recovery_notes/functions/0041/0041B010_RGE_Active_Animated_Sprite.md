# Recovery journal: 0041B010 `RGE_Active_Animated_Sprite`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/asprite.cpp`.
- PDB source: `C:\msdev\work\age1_x1\asprite.cpp`.
- Earlier recovery note: `recovery_notes/0041B010_RGE_Active_Animated_Sprite.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:7484242c14856b9c5020 -->
### `de39face081d` `src/matching/0041B010_RGE_Active_Animated_Sprite.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0041B010 RGE_Active_Animated_Sprite (constructor)
// PDB source: asprite.cpp
// Attempt log:
// - baseline: existing reconstruction had the wrong base layout and no EH frame (250 diff bytes).
// - layout: restored RGE_Active_Sprite ownership, virtual destructor, and DAT_0056ee78/80 globals (227 diff bytes).
// - control-flow: positive flag guard restored the random-path inline / zero-frame cold arm (231 diff bytes).
// - liveness: natural rnd/tot_time locals matched the integer parameter-home reuse, but the frame stayed 4 bytes short.
// - behavior: a separate frame_time value preserved the FPU product across __ftol and produced an exact 259-byte match.
// - TU context: duration and pause_between_loops are the shared +0x68/+0x6C
//   RGE_Sprite fields; the old narrow aliases selected the wrong shared fields.
// - exact finish: count, tot_time, rnd, frame_time declaration order is required
//   with those canonical fields; each independent walkback lost grouped exactness.
// FLAGS: /GX is required for the original constructor EH frame.
```
<!-- end-recovered:7484242c14856b9c5020 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
