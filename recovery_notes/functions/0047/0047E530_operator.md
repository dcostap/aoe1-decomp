# Recovery journal: 0047E530 `operator+`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/point.cpp`.
- PDB source: `C:\msdev\work\age1_x1\point.cpp`.
- Earlier recovery note: `recovery_notes/0047E530_operator.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:562e79ecaad5ebdeda0c -->
### `target-session` `build/target_sessions/0047E530_operator.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=?; diff=?; shape=?: Baseline authentic point wrapper: grouped target differs by 7 bytes; owner and boundary unverified in current unregistered state.
probe 2 baseline; result=?; diff=?; shape=?: Authentic point_tu grouped candidate: 0047E530 differs by 7 bytes; emitted target hoists mov edx,[ecx+8] before sub esp,0xc. Owner is unverified because target is not registered and standalone checker cannot select decorated operator symbol.
```
<!-- end-recovered:562e79ecaad5ebdeda0c -->

<!-- recovered:7a1187b4fbc33a810c65 -->
### `7a7d40948229` `src/scratch/0047E530_operator.cpp:1-15`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0047E530 XYZ::operator+ (point.cpp:70-73, 75 bytes)
// Default flags.
//
// The original creates a temporary via XYZ(int,int,int) ctor
// then copies to hidden return storage pointer.
//
// Attempts:
// Probe 1: named temp ctor init without game_globals include -> 36%; VC5 hoisted this->z before stack alloc.
// Probe 2-3: temp vars, expr reorder -> same 36%
// Variant lab (5 variants, 4 axes - ctor_temp, assign_temp, return_direct, this_first/other_first):
//   all ctor_temp variants stayed in same 36% group without include context.
// Standalone game_globals context matched, but the authentic point.cpp TU still
// differs by 7 bytes. Keep this natural constructor form and leave unresolved.
// Authentic TU probes for operand order, named z, return form, assignment, and
// pragmas did not improve the result. All probes were restored.
```
<!-- end-recovered:7a1187b4fbc33a810c65 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
