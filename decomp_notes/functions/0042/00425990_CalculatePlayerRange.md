# Function notes: 00425990 `CalculatePlayerRange`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:9099ba5ae5c503971182 -->
### `00492347d989` `src/scratch/00425990_CalculatePlayerRange.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TCommunications_Handler::CalculatePlayerRange
// VA: 00425990
// Com_hand.cpp:236-257
// 130 bytes, ~2 byte positional diff (parked)
// VC5 quirk: original uses `xor eax; mov ax,[mem]; cmp eax,edi; jg/jl; mov eax,edi; mov [mem],ax`
// for the HighPlayerNumber/LowPlayerNumber update, but any source form with temps
// generates extra `and` instructions (load ax → copy to other reg → and 0FFFFh).
// Best compact form: 128 bytes (no extra and instructions, uses `mov [mem],di` directly
// instead of `mov eax,edi; mov [mem],ax` — 2 bytes short).
// 8+ attempts across all variants. 0 relocations.
// Same behavior, same field layout.
```
<!-- end-recovered:9099ba5ae5c503971182 -->
