# Recovery journal: 00411F80 `ResourceItem`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/airesitm.cpp`.
- PDB source: `C:\msdev\work\age1_x1\airesitm.cpp`.
- Earlier recovery note: `recovery_notes/00411F80_ResourceItem.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:52be10ac76f39ae8bfed -->
### `target-session` `build/target_sessions/00411F80_ResourceItem.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 variant; result=MATCH; diff=0; shape=100.0: Grouped baseline had 12 differing bytes. Direct this->valueValue[i], sortedValue[i], sortedIndexValue[i] stores reduced it to 2 bytes; while/break and cursor variants worsened. Final source retains the 2-byte improvement. Report: build/audits/tu_orchestration/results/airesitm/final-prejournal/report.json
```
<!-- end-recovered:52be10ac76f39ae8bfed -->

<!-- recovered:15946d2ebfbd4f0fba7c -->
### `3ee24e94c6d9` `src/scratch/00411F80_ResourceItem.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00411F80 | ResourceItem::ResourceItem(int count, int* source) | airesitm.cpp:59-70 | 105 bytes
//
// Best result: 27 positional / 15 edit diff (78/105 bytes identical).
// First mismatch at offset 40. Prologue + init (40 bytes) matches exactly.
// Remaining: instruction scheduling differences (store order, i++ position,
// i>=8 check at loop bottom instead of top). All behavior, reg alloc,
// memory effects match. Equivalent VC5 scheduling drift.
```
<!-- end-recovered:15946d2ebfbd4f0fba7c -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
