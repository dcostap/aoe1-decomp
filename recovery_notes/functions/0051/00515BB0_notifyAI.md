# Recovery journal: 00515BB0 `notifyAI`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tplayer.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tplayer.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:69b7a403092a32339743 -->
### `6e2375c51785` `src/scratch/00515BB0_notifyAI.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00515BB0 TRIBE_Player::notifyAI
// Attempt log:
// 1: natural source from packet/decompiler with explicit switch.
// 2: fixed tributeNotify receiver to PlayerAI as TribeMainDecisionAIModule surface.
// 3: first build same-size but broad diff from class surface adding vptr/base offsets (+40/+23C/+11468); removed inherited surfaces and used explicit gaps/casts.
// 4: offsets fixed, but first mismatch remains at dispatch shape: compiler inlines 0x1F9 case before 0x72/0x74 notify path; original lays default return then 0x1F9 out-of-line.
// 5: rewrote dispatch as one switch over all interesting event ids; improved top dispatch shape and kept exact size, but placed 0x72/0x74/0x201 notify block before the 0x202+ jump-table family instead of original late shared notify block.
// 6: kept raw PlayerAI plus casts; fixes module offsets (+0xCEC/+0x1146C) versus earlier typed empty-member padding.
// 7: tried /GX; unchanged.
// 8: tried /O2 without /Oy; unchanged.
// 9: current best same-size 531 B; early guard, object/unitAI call surface, module offsets, and call set are right, but broad dispatch/block-placement mismatch remains.
// 10: left in scratch: not accepted_drift-safe because many event cases are laid out in different order despite behavior-equivalent source.
```
<!-- end-recovered:69b7a403092a32339743 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
