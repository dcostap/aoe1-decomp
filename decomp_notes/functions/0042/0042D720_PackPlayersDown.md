# Function notes: 0042D720 `PackPlayersDown`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:7496c895f06258b3cbb8 -->
### `b6e159352e2d` `src/scratch/0042D720_PackPlayersDown.cpp:1-23`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0042D720 TCommunications_Handler::PackPlayersDown
// Source: Com_hand.cpp lines 5669-5714
// Attempt log:
// 1: initial reconstruction from packet: scan player slots, move later occupied slot down, copy two name strings and player metadata columns.
// 2: changed early numPlayers guard to wrap loop and fall through to final SetSelfPlayer call like original.
// 3: rewrote inner search with goto move_found/next_player so found branch jumps directly to copy; duplicated first human check.
// 4: split inner human/computer tests into separate statements inside one do/while.
// 5: spelled outer tests with numPlayers on left; no improvement.
// 6: made inner source index volatile; much worse (first mismatch offset 2), rolled back.
// 7: tested direct array assignments as current best; remaining mismatch begins with initial branch distance due later block layout.
// 8: reordered locals (dst before offset); no codegen change.
// 9: restored local order; tried source-level helper GetPlayerName/log order is already matching call order.
// 10: left in scratch: behavior and main copy/log calls are understood, but block layout differs. Rebuilt keeps the no-player final call close, then inner search duplicates/peels the first IsPlayerHuman check and shifts the copy block by +0x0B; original has a compact do-loop with found branches directly to copy and no post-loop recheck. Not accepted_drift-safe due broad shifted mismatch.
// 11: replacing the inner do-loop with a top-tested while and naming the final
// SetSelfPlayer call removed the peeled call site and reached 563/563 bytes;
// the remaining drift is only the two commutative name-destination LEA
// encodings at +00A0/+00D4. Pointer, array-index, and reversed-add spellings
// did not change those bytes; named pointer temporaries worsened the frame.
// 12: reversed the destination pointer-add operands in both typed name copies;
// codegen was unchanged, so restored the natural pointer-plus-offset form.
// 13: modeled both name buffers as typed NAME arrays and used the natural first
// element member for the destination; codegen was unchanged, so restored the
// clean pointer-plus-offset source.
```
<!-- end-recovered:7496c895f06258b3cbb8 -->
