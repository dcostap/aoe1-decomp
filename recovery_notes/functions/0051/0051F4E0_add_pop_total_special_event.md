# Recovery journal: 0051F4E0 `add_pop_total_special_event`

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


<!-- recovered:983d46552a51df8a3973 -->
### `target-session` `build/target_sessions/0051F4E0_add_pop_total_special_event.json:1-7`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=6; shape=94.5945945945946: Baseline current accepted-drift source: 6-byte parameter register permutation; exact size, call count, and field stores.
probe 2 layout; result=MISMATCH; diff=6; shape=94.5945945945946: Replaced local Special_Events and Time_Line_Panel overlays with expanded canonical context; tested whether proven fields and inheritance alter the register basin. [same emitted code as probe 1]
probe 3 control-flow; result=MISMATCH; diff=7; shape=97.29729729729729: Tested PDB-line-guided field order: preload pop_total between the first four zero stores and the remaining zero stores, matching the original line-556 load band.
probe 4 liveness; result=MISMATCH; diff=6; shape=94.5945945945946: Tested a natural const local that preloads pop_total before the zero-fill while retaining event-before-pop source order, to separate register lifetime from store order. [same emitted code as probe 2]
probe 5 liveness; result=MISMATCH; diff=6; shape=94.5945945945946: Moved the pop_total copy declaration into the PDB-guided first-zero block, testing whether declaration scope places the load before later zero stores while keeping event-before-pop store order. [same emitted code as probe 4]
probe 6 control-flow; result=MATCH; diff=0; shape=100.0: Tested event-before-pop source order inside the PDB-guided early zero region, keeping only one event store, to probe the target event/pop store ordering.
probe 9 context; result=MATCH; diff=0; shape=100.0: Recover natural event store order in authentic tpnl_tml.cpp context [same emitted code as probe 8]
```
<!-- end-recovered:983d46552a51df8a3973 -->

<!-- recovered:c5dbf0ce27ec6ebd07d2 -->
### `00492347d989` `src/scratch/0051F4E0_add_pop_total_special_event.cpp:1-21`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0051F4E0 Time_Line_Panel::add_pop_total_special_event()
// Source: tpnl_tml.cpp lines 544-575
// Size: 124 bytes, __thiscall, ret 10h (4 params)
//
// Attempt log:
// Probe 1: Natural struct with field-order assignments — 6 bytes diff
//   Pure register allocation: original uses edx=pop_total, ecx=icon_flag
//   Rebuilt reverses: ecx=pop_total, edx=icon_flag
// Probe 2: Moved pop_total assignment up (before zero-fill) — worse (21 bytes)
// Probe 3: Swapped icon_flag before pop_total in source — fixed reg alloc, reversed store order
// Probe 4: Exact struct types from type dump — still 6 bytes (edx/ecx swap)
// Probe 5: const locals for pop_total/icon_flag — still 6 bytes
// Probe 6: Renamed params (pt/iflg) + icon_flag first in source — fixed regs, wrong store order
//
// Remaining 6 bytes: pure VC5 register allocation symmetry
//   Original: edx=pop_total, ecx=icon_flag, edx=time_slice_events
//   Rebuilt:  edx=icon_flag, ecx=pop_total, ecx=time_slice_events
//   All behaviorally identical (params are symmetric for the allocator)
//   Store order matches, zero-fill matches, calloc matches
//   Cannot break the register symmetry from C++ source alone.
// Parked in scratch per Boss direction.
```
<!-- end-recovered:c5dbf0ce27ec6ebd07d2 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
