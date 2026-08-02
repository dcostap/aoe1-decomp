# Logic review: 0040D020 `MainDecisionAIModule::~MainDecisionAIModule`

## Phase transition

Ordinary exact matching is suspended after repeated independent assignments, source/flag/EH experiments, canonical polymorphic normalization, and a final faithful full-`aimdmod.cpp` translation-unit experiment under `/O2 /Oy /GX`. The candidate remains `src/scratch/0040D020_MainDecisionAIModule.cpp`.

Current validated checker state:

- original/rebuilt size: 112/117 bytes;
- saved registers: `esi, edi` / `esi, edi`;
- calls: 2/2, target-aligned (`operator delete`, base destructor);
- instructions: 30/32;
- instruction shape: 78.12%;
- strict difference: 99 bytes, first mismatch `0040D020`;
- original uses an FS-first three-slot EH entry; pinned VC5 emits a push-first four-slot frame with a saved-`this` home.

Cumulative matching work covered natural `delete`, local/direct member forms, virtual base and derived destructor surfaces, `novtable` and manual-vptr diagnostics, delete/free variants, zero-store ordering, implicit and explicit base destruction, EH/TU/header context, broad flags, and a full temporary TU containing related constructors/destructors. No plausible source recovered the original EH family.

The normalized source models the real polymorphic `AIModule`/`MainDecisionAIModule` ownership, named `ManagedArray<int>`, natural scalar `delete`, post-delete nulling, three scalar zero stores, compiler-generated derived-vptr restoration, and implicit base destruction. Manual vptr and base-destructor plumbing were removed.

### Semantic questions at entry

1. Verify the derived-vptr store value and its ordering before the member load.
2. Verify null and non-null delete paths, scalar-delete semantics, and whether nulling occurs only after successful delete return.
3. Verify widths/order of all managed-array zero stores.
4. Verify the direct base-destructor call, object pointer, and normal cleanup.
5. Establish whether the original FS-first EH state/cleanup differs behaviorally from the rebuilt push-first frame when delete or base destruction throws, including propagation and partially destroyed object state.
6. Verify there is no additional target-local cleanup hidden by the EH metadata.

## Review rounds

No blind cohort has been launched because the user instructed the orchestrator to start no additional subagents.

## Main-agent adjudication

Pending fresh blind semantic review.

## Integrated changes

Before phase entry, the source was normalized from gap-only/nonvirtual stubs to the binary-backed polymorphic layout and natural C++ lifetime operations. The full-TU probe reproduced the same pinned VC5 EH family.

## Final decision

Pending. The function remains in `src/scratch` and must not move to `src/verified_logic` without complete fresh review cohorts and evidence-backed adjudication of EH, throwing cleanup, and partial-destruction behavior.
