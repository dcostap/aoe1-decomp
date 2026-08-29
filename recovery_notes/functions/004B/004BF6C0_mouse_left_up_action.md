# Recovery journal: 004BF6C0 `mouse_left_up_action`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/spnl_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\spnl_obj.cpp`.
- Earlier recovery note: `recovery_notes/spnl_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:677c47b004c10fa3602d -->
### `target-session` `build/target_sessions/004BF6C0_mouse_left_up_action.json:1-4`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 2 context; result=MISMATCH; diff=1; shape=100.0: Authentic spnl_obj context probe: adding polymorphic TPanel and virtual target owner corrected the decorated symbol to UAE, while the minimal proven global offset still emitted the same five-instruction body. Full RGE field declarations did not solve the load destination. [same emitted code as probe 1]
probe 3 layout; result=MISMATCH; diff=1; shape=100.0: Layout probe: RGE_Base_Game vptr plus gap 0x1AC places prog_mode at +0x1B0. TRIBE_Panel_Object intermediate inheritance and proven Scenario panel offsets did not change target bytes. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=1; shape=100.0: Liveness probe: direct nonvolatile unused prog_mode expression is removed by VC5 in complete context; volatile field/reference forms preserve the load but violate the no-fake-volatility rule. [same emitted code as probe 3]
probe 5 variant; result=MISMATCH; diff=1; shape=100.0: Exact-finish probe: complete polymorphic context plus an explicit volatile local RGE_Base_Game pointer produced MATCH, 0.0000%, correct owner, calls, boundary, and ret 0x10. Walkback removed volatility and restored baseline; candidate rejected by policy. [same emitted code as probe 4]
```
<!-- end-recovered:677c47b004c10fa3602d -->

<!-- recovered:2be713025337d7dd7abd -->
### `912332e8f578` `src/accepted_drift/004BF6C0_mouse_left_up_action.cpp:2-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// ACCEPTED_DRIFT: unused fault-preserving member load goes to eax in original and volatile ecx in rebuilt before eax is set to 1; same call, read address, return, and stack cleanup.
// Attempt log:
// - Baseline is exact in size, call set, boundary, and cleanup. It differs only in the load destination byte.
// - Virtual TPanel/RGE context restored the PDB owner and field offset but kept the ECX load destination.
// - An exact probe used a volatile local object pointer with the complete class context. It was rejected as fake volatility.
// - Restored this clean source. Needed evidence: a policy-compliant source form that keeps the proven unused read in EAX.
```
<!-- end-recovered:2be713025337d7dd7abd -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
