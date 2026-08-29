# Recovery journal: 0042C690 `AnalyzeCommunicationsStatus`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_hand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Com_hand.cpp`.
- Earlier recovery note: `recovery_notes/com_hand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:2c549a2e6bce0c0eea5b -->
### `target-session` `build/target_sessions/0042C690_AnalyzeCommunicationsStatus.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Module closure probe: corrected original-FPO member access/return/parameter declaration; final grouped object emits the expected symbol. Body remains a grouped mismatch and is not changed beyond declaration repair.
```
<!-- end-recovered:2c549a2e6bce0c0eea5b -->

<!-- recovered:f817344342a765a5863a -->
### `c9edebbc790d` `src/matching/0042C690_AnalyzeCommunicationsStatus.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0042C690 TCommunications_Handler::AnalyzeCommunicationsStatus
// Initial source from packet/decompiler; exact-match in progress.
```
<!-- end-recovered:f817344342a765a5863a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
