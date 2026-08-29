# Recovery journal: 005032E0 `checkTradeBoats`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:efc055a1751fe87e8fc9 -->
### `d050eea3c` `src/taitacmd.cpp:16323-16336`

Mapping: `strong`. next mapped function definition is checkTradeBoats at old line 16339.

```text
// Attempt log:
// - Baseline reconstruction: restored the typed Tribe tactical module, embedded
// [non-comment lines omitted during migration]
// - Probe 2 control-flow: a do/while with an inner break emitted the opposite
// [non-comment lines omitted during migration]
// - Probe 3 control-flow: the ordinary descending for loop plus source-local
// [non-comment lines omitted during migration]
//   CFG rather than compiler-steering register aliases.
// - Probe 4 control-flow: replacing the found label with break plus a
// [non-comment lines omitted during migration]
//   restored the exact for/label reconstruction.
```
<!-- end-recovered:efc055a1751fe87e8fc9 -->

<!-- recovered:49445289851590ec1087 -->
### `6a2aef2e2` `src/taitacmd.cpp:13784-13792`

Mapping: `strong`. next mapped function definition is checkTradeBoats at old line 13795.

```text
// __thiscall, void
//
//   tradeBoats ManagedArray, MainDecision object lookup, resourceAI threshold
//   checks, and aiPlayer trade-attribute dispatch from the original call set.
//   signed backedge (js-to-exit plus jmp-to-loop) and grew to 407 bytes; rolled
//   back.
//   found/next labels reproduced the original jns backedge, boundary, and all
//   406 bytes exactly.  The labels preserve the observed found and next-boat
//   post-loop resource guard changed liveness/saves and broad block layout;
```
<!-- end-recovered:49445289851590ec1087 -->

<!-- recovered:582fd3e779f8f456291b -->
### `bf81de068f12` `src/scratch/005032E0_checkTradeBoats.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 005032E0 TribeTacticalAIModule::checkTradeBoats (406 B)
// PDB source: taitacmd.cpp
// __thiscall
```
<!-- end-recovered:582fd3e779f8f456291b -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
