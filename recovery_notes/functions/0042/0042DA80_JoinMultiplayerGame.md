# Recovery journal: 0042DA80 `JoinMultiplayerGame`

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


<!-- recovered:5da5f2954c145f9b1bd8 -->
### `ec85456a7adf` `src/accepted_drift/0042DA80_JoinMultiplayerGame.cpp:1-16`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0042DA80 TCommunications_Handler::JoinMultiplayerGame
// Source: Com_hand.cpp lines 5781-5853
// Attempt log:
// 1: natural raw-offset reconstruction from packet, mirroring CreateMultiplayerGame descriptor layout; first mismatch was descriptor GUID offset (+4 vs +8).
// 2: corrected DPSESSIONDESC2 layout to dwSize/dwFlags/guidInstance/guidApplication; improved to one scheduling hunk after descriptor fill.
// 3: changed guidInstance/guidApplication fields to nested GUID_LOCAL aggregate assignments; improved to a tiny single-hunk drift.
// 4: introduced explicit dp local before Open; fixed DirectPlay virtual-call register choice (eax/edx) and left only the log/descriptor-store hunk.
// 5: tried session GUID local before the debug log; no change.
// 6: tried log local loaded before app GUID copy; worsened by interleaving app-copy stores with log argument pushes, reverted.
// 7: tried delaying app.d3 assignment until after the debug log; worsened broadly because descriptor was incomplete across the call, reverted.
// 8: tried direct FIELD_GUID(0x12EC) aggregate without app pointer; same codegen as best.
// 9: tried volatile debug-log global; compile/type mismatch and not useful, reverted.
// 10: tried char* vs const char* log prototype/string macros; no codegen change.
// 11: restored the proven TDebuggingLog::Log owner for both calls to 00436610.
// This also keeps the complete grouped Com_hand.cpp context compilable.
// ACCEPTED_DRIFT suggestion: remaining 16 edit bytes are a localized, behavior-equivalent scheduling difference around storing dSess2.guidApplication.d3 relative to pushing args for the debug Log call. Both versions store the same dword to the same local stack slot before the call; no calls or predicates differ.
```
<!-- end-recovered:5da5f2954c145f9b1bd8 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
