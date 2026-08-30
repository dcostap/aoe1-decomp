# Function notes: 00429FD0 `ClearRXandTX`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:d825977123b50cefe4da -->
### `e97829620091` `src/scratch/00429FD0_ClearRXandTX.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00429FD0 TCommunications_Handler::ClearRXandTX
// Source: Com_hand.cpp lines 3161-3170
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 16: match original offset-increment-before-stores order
// Retry 2026-05-19 target-only:
// try 1: revalidated baseline: exact size 136B, MISMATCH 95 positional bytes / 69.85%, edit diff 32B; behavior and stores mostly align after resync.
// try 2: split rx base load (`rx=this->rx_array; entry=rx+offset`); no codegen change, still uses EDX base then `mov esi,ebp; add esi,edx` instead of original `mov esi,[edi+1524]; add esi,ebp`.
// try 3: split tx base and pre-zero using `*(entry+offset)=0; entry+=offset`; worsened by swapping zero/offset registers (EBP/EBX), rolled back.
// try 4: /G5 flag probe; no codegen change, removed flag.
// try 5: cast address arithmetic through int for rx/tx; no codegen change.
// GIVEUP: remaining drift is broad but behavior-equivalent register/address scheduling across both loops: rebuilt uses EDX as array-base temp and schedules tx `lea edi` after count/xor, while original loads base directly into ESI and schedules `lea edi` before count/xor. Not proposing accepted_drift without approval because positional diff is large despite small edit diff.
```
<!-- end-recovered:d825977123b50cefe4da -->
