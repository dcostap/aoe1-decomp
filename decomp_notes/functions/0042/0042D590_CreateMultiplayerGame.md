# Function notes: 0042D590 `CreateMultiplayerGame`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:2b1742040d1a01d1c286 -->
### `target-session` `build/target_sessions/0042D590_CreateMultiplayerGame.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Use a proven vslot+0x60 Open caller view and add the canonical MyGameTitle field at +0x11FA.
```
<!-- end-recovered:2b1742040d1a01d1c286 -->

<!-- recovered:326bd25933aced23161f -->
### `3719bc4b64cd` `src/scratch/0042D590_CreateMultiplayerGame.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0042D590 TCommunications_Handler::CreateMultiplayerGame
// Source: Com_hand.cpp lines 5584-5666
// Attempt log:
// 1: natural raw-offset reconstruction with DPSESSIONDESC2 local; compiler hoisted ApplicationGUID loads before memset and delayed MeHost store.
// 2: use volatile MeHost store/ApplicationGUID reads and source order matching original session descriptor fill; MeHost fixed but descriptor stores still rescheduled.
// 3: fill descriptor through raw dword pointer in original offset order; constants still delayed after argument push and app loads use direct addressing.
// 4: revert to compact struct field form with nonvolatile ApplicationGUID pointer; worsened to 50.5% positional.
// 5: restore volatile ApplicationGUID pointer best (~47.7% positional), leave broad descriptor-fill scheduling unresolved.
// Left in scratch: behavior modeled, but descriptor-fill scheduling diverges (ApplicationGUID loads/constants and push timing), shifting the DirectPlay/Open/error-success tail. Not accepted_drift.
```
<!-- end-recovered:326bd25933aced23161f -->
