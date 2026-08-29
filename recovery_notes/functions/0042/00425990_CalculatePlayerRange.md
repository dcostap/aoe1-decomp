# Recovery journal: 00425990 `CalculatePlayerRange`

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

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
