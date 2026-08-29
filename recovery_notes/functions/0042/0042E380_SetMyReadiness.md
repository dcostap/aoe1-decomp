# Recovery journal: 0042E380 `SetMyReadiness`

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


<!-- recovered:3e4b4c60f5168907d8bb -->
### `912332e8f578` `src/accepted_drift/0042E380_SetMyReadiness.cpp:1-10`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0042E380 TCommunications_Handler::SetMyReadiness
// Source: Com_hand.cpp lines 6191-6258
// Attempt log:
// 1: natural raw-offset reconstruction with MSGFORMAT_SETREADYOPTIONS local; frame was 0x24 because packet has extra byte at +0x24.
// 2: add trailing guaranteed-delivery byte/pad to force 0x28 local frame; only rdy field scheduling drift remains.
// 3: reorder packet field assignments and name MeHost temp to match original store/load schedule; remaining 20-byte diff is localized packet-store scheduling/register allocation.
// 4: tried moving User7 assignment after User1; worsened to 49-byte diff, rolled back.
// ACCEPTED_DRIFT: reviewed localized packet-fill scheduling/register-allocation drift only.
// Calls, frame size, packet size, stack cleanup, field offsets, packet offsets, return value, and memory effects match;
// remaining byte differences are equivalent store order/register choices while filling independent rdy fields.
```
<!-- end-recovered:3e4b4c60f5168907d8bb -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
