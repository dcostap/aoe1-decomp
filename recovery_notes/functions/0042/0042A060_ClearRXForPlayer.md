# Recovery journal: 0042A060 `ClearRXForPlayer`

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


<!-- recovered:77856f59d25b5a08e87a -->
### `target-session` `build/target_sessions/0042A060_ClearRXForPlayer.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Module closure probe: corrected original-FPO member access/return/parameter declaration; final grouped object emits the expected symbol. Body remains a grouped mismatch and is not changed beyond declaration repair.
```
<!-- end-recovered:77856f59d25b5a08e87a -->

<!-- recovered:316c2ac1b3269b5f5260 -->
### `5868718576a8` `src/scratch/0042A060_ClearRXForPlayer.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: RXEntry class with index-based loop; wrong loop counter/register usage
// attempt 2: byte-offset loop with void* arithmetic; registers swapped (ebp=this, ebx=zero)
// attempt 3: unsigned int loop counter; same register swap issue
// attempt 4: same; VC5 picks ebp for this, ebx for zero, esi for counter
// attempt 5: same; loop bound adjust; same register swap
// Original uses ebx=this, ebp=zero, edi=counter, eax=base, esi=entry, edx=player
// VC5 uses ebp=this, ebx=zero, esi=counter, edi=base, ecx=player
// Left in scratch: benign register-allocation drift, behavior fully correct
```
<!-- end-recovered:316c2ac1b3269b5f5260 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
