# Logic review: 0040CDF0 `MainDecisionAIModule::MainDecisionAIModule`

## Phase transition

Ordinary exact matching is suspended after repeated independent assignments and a final faithful full-`aimdmod.cpp` translation-unit experiment under `/O2 /Oy /GX`. The canonical candidate remains `src/scratch/0040CDF0_MainDecisionAIModule.cpp`.

Current validated checker state:

- original/rebuilt meaningful size: 113/78 bytes;
- saved registers: `esi` / `esi`;
- calls: 1/1, target-aligned (`AIModule` base constructor);
- instructions: 29/23;
- instruction shape: 55.17%;
- strict difference: 106 bytes, first mismatch `0040CDF0`;
- rebuilt emits no EH frame, while the original begins with an FS-first three-slot EH frame.

Cumulative matching work covered thin and full base surfaces, complete virtual declarations, visible base/derived/member destructors, managed-array lifetime variants, natural and explicit delayed-vptr forms, initializer/body ordering, TU/header context, optimization and EH flags, and a full temporary TU containing both constructors and the destructor. VC5 repeatedly emits either the current no-EH basin or an incompatible push-first saved-`this` EH family. The final full-TU probe was codegen-identical to the canonical candidate.

The source models the binary-backed `AIModule` fields, base-constructor call, `player`, all four managed-array initialization stores, and the delayed derived-vptr write. The explicit vtable field/store is retained because exact donor `0040E2D0` uses the same pre-vtable surface and the executable proves delayed derived-vptr timing.

### Semantic questions at entry

1. Verify every base-constructor argument and the derived field offsets/stores.
2. Verify the delayed derived-vptr value and ordering, including partial-construction state.
3. Determine whether the original FS-first EH frame has any reachable cleanup or propagation effect not represented by the candidate when the base constructor throws.
4. Verify that no post-base operation can throw and require additional target-local cleanup.
5. Verify normal return value/object state and all parameter widths.

## Review rounds

No blind cohort has been launched because the user instructed the orchestrator to start no additional subagents.

## Main-agent adjudication

Pending fresh blind semantic review.

## Integrated changes

The candidate was normalized to full binary-backed field ownership before phase entry. Full-TU validation did not alter the pinned VC5 EH basin.

## Final decision

Pending. The function remains in `src/scratch` and must not move to `src/verified_logic` without complete fresh review cohorts and evidence-backed adjudication of EH and partial-construction behavior.
