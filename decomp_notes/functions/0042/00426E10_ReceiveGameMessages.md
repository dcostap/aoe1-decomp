# Function notes: 00426E10 `ReceiveGameMessages`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:26d9baddbb4f4ef001f6 -->
### `659487cbad53` `src/scratch/00426E10_ReceiveGameMessages.cpp:1-22`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00426E10 TCommunications_Handler::ReceiveGameMessages
// Source: Com_hand.cpp lines 912-952
// Attempt log:
// 1: initial reconstruction from packet/decompiler; wrong frame (0x10) and FPU conversion shape.
// 2: explicit __int64 casts worsened EBX/liveness and FPU shape.
// 3: zero/double local no codegen change.
// 4: __int64 local_8 worsened dplay stack shape.
// 5: restore array and use direct zero constants.
// 6: restore qword local_8 rate math (best edit diff).
// 7: volatile local_8 worsened frame/scheduling; rolled back.
// 8: named elapsed_float from qword local improved FPU but still frame/register drift.
// 9: zero local no codegen change.
// 10: mark COM v44 as __stdcall to match pushed-this virtual call.
// 11: explicit flag/bit locals worsened liveness; rolled back.
// 12: /Og and /Ob0 flag probes no change; removed flags.
// session: making packet counters/last counters unsigned long recovered the original
// qword FPU conversions, exact frame/size, and most block topology; direct elapsed
// arithmetic is the clean surviving reconstruction. Captured dplay-id and named
// debug-byte variants were codegen-worse; the remaining drift is debug-flag register
// order plus wait-output initialization scheduling.
// Left in scratch: behavior modeled with exact frame/size, but debug-flag register
// order, wait-output initialization scheduling, and relocation-bearing literals remain.
```
<!-- end-recovered:26d9baddbb4f4ef001f6 -->
