# Function notes: 00513D00 `reimburse_obj_cost`

## Recovered attempt history

<!-- recovered:fd20702f70d5f0ca3c76 -->
### `5868718576a8` `src/scratch/00513D00_reimburse_obj_cost.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: register usage differs, rebuilt uses lea edx instead of add eax
// attempt 2: better reg usage but loop counter in edi, table in ebx
// attempt 3: hoist table load, counter in ebx now
// attempt 4: do/while loop, same reg alloc
// left in scratch: VC5 picks different registers (ebx counter, ebx/edx for FPU addr)
// original uses esi for counter, edi for table base, edx for FPU addr
// behavior fully correct, size matches (82 bytes), benign codegen drift
```
<!-- end-recovered:fd20702f70d5f0ca3c76 -->
