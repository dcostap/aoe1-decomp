# Recovery journal: 0043E650 `check_food`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_dip.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dlg_dip.cpp`.
- Earlier recovery note: `recovery_notes/dlg_dip_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:aee1259c770f2bb7ada0 -->
### `target-session` `build/target_sessions/0043E650_check_food.json:1-3`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MATCH; diff=0; shape=100.0: Baseline emitted bytes MATCH: 135 bytes, 4 calls, protected PDB owner not yet represented; current source declares public member and checker reports rebuilt QAEH.
probe 2 abi; result=MATCH; diff=0; shape=100.0: Changed the target member to protected. This restores PDB symbol IA EH while preserving the exact body, boundary, calls, receiver reloads, cleanup, and result publication. [same emitted code as probe 1]
probe 3 other; result=MATCH; diff=0; shape=100.0: Walkback: reverted protected to public. Bytes remain identical, but owner changes from required IA EH to public QAEH. Reject this byte-identical public symbol. [same emitted code as probe 2]
```
<!-- end-recovered:aee1259c770f2bb7ada0 -->

<!-- recovered:a58de7b47ad69ceb30fb -->
### `00492347d989` `src/scratch/0043E650_check_food.cpp:1-14`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TribeDiplomacyDialog::check_food
// VA: 0043E650
// dlg_dip.cpp:811-840
// 135 bytes, not matched (parked)
// VC5 allocates stack slot for the conditional hasFood variable
// (push ecx + mov [esp+N],val pattern) while the original uses
// ebp directly (xor ebp,ebp / mov ebp,1). The stack variable adds
// ~25 bytes of codegen vs the register-based pattern.
// 5 source forms tried. 4 relocations.
// Attempt log:
// v0: int hasFood with separate if/else → 144 bytes + push ecx
// v1: correct field offsets → same size
// v2: goto-based control flow, no else → 160 bytes
// v3: goto + ternary in loop → 160 bytes
```
<!-- end-recovered:a58de7b47ad69ceb30fb -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
