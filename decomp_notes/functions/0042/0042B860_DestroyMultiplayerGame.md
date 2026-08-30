# Function notes: 0042B860 `DestroyMultiplayerGame`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:b6ae95333efb7a58e901 -->
### `target-session` `build/target_sessions/0042B860_DestroyMultiplayerGame.json:1-3`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MISMATCH; diff=2; shape=99.36708860759494: Validate the completed natural local field view and canonical helper calls.
probe 2 layout; result=MISMATCH; diff=1; shape=99.36708860759494: Restore the proven PlayerStopTurn anchor at +0x13C0 while keeping canonical helper calls.
probe 3 layout; result=MATCH; diff=0; shape=100.0: Use conditional local-view indexing to preserve the proven +0x13C0 PlayerStopTurn anchor.
```
<!-- end-recovered:b6ae95333efb7a58e901 -->

<!-- recovered:fd7830dc55c5372052ef -->
### `912332e8f578` `src/scratch/0042B860_DestroyMultiplayerGame.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0042B860 TCommunications_Handler::DestroyMultiplayerGame
// Attempt log:
// initial direct source from original asm: explicit field stores and natural empty-string assignments.
```
<!-- end-recovered:fd7830dc55c5372052ef -->
