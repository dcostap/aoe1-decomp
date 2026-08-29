# Recovery journal: 0051F560 `record_special_event`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tpnl_tml.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tpnl_tml.cpp`.
- Earlier recovery note: `recovery_notes/tpnl_tml_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:c9c75528b0619951d97f -->
### `00492347d989` `src/scratch/0051F560_record_special_event.cpp:1-19`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0051F560 Time_Line_Panel::record_special_event
// Size: 156 bytes
//
// Attempt log:
// Probe 1 (event_local, sizeof): 105 bytes diff, EBX for param_4
// Probe 2 (direct_ref): 136 bytes diff (function size grew), EBX for param_4
// Probe 3 (calloc decl explicit): same
// Probe 4 (long p4 = param_4 local): same
// Probe 5 (__cdecl calloc): same
// Probe 6 (*(unsigned char*)&param_4): same
// Probe 7 (no p4 local): same
// Probe 8 (extern "C" calloc): same
// Probe 9 (variant_lab attempt - template error): n/a
// Probe 10 (various small tweaks): same
//
// Remaining: 136 bytes diff (87.2%). VC5 uses EBX for param_4; original uses EDI.
// All source restructuring attempts produce same EBX allocation.
// VC5 register allocation invariant — cannot force EDI through source changes.
// Left in scratch.
```
<!-- end-recovered:c9c75528b0619951d97f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
