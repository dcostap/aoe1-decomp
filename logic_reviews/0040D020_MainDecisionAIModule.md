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

### Round 1 — concurrent blind cohort, 2026-08-02

- `sa-0efb67c9` — `openai-codex/gpt-5.6-luna`, max thinking
- `sa-02b3a14b` — `deepseek/deepseek-v4-flash`, max thinking

Both reviewers independently verified the object layout, derived-vptr store,
null and non-null delete paths, post-delete nulling, three scalar zero stores,
and direct base-destructor call. Neither found a normal successful-destruction
difference.

The Luna reviewer reported no definite behavioral difference but left exact EH
registration/state behavior unestablished. The DeepSeek reviewer extracted the
original FuncInfo and unwind funclet and identified a frame/funclet slot mismatch:
the original state-zero cleanup reads the delete argument rather than the real
object pointer. It called that path dead for this binary while acknowledging a
different outcome if `free` faults and an outer handler unwinds through it.

## Main-agent adjudication

- **Normal destruction:** verified. The vptr value/timing, conditional scalar
  deallocation, nulling, zero stores, base-dtor call, and final state agree.
- **Original EH metadata:** direct extraction from `empiresx.exe` confirms
  `FuncInfo 0x578948`, `maxState=1`, and unwind entry `state 0 -> -1`, action
  `0x55C670`. The original writes state zero before the nullable delete and
  restores `-1` before the direct base destructor, so this cleanup is active
  during `operator delete`.
- **Original cleanup pointer:** action `0x55C670` executes
  `mov ecx,[ebp-0x18]` then tail-jumps to `AIModule::~AIModule` at `0x40E360`.
  With the original three-slot registration plus saved ESI/EDI, `[entry_esp-0x18]`
  is the pushed delete argument during the call, not `this`. The rebuilt
  four-slot family homes the real object and its cleanup uses that home. Thus,
  if unwinding crosses the delete call, original and rebuilt destroy different
  addresses.
- **Reachability claim:** absence of ordinary `__CxxThrowException` calls in the
  current game does not prove this path behaviorally irrelevant under project
  policy. A malformed object/heap can make `free` fault, and an outer SEH handler
  can cause second-pass unwind through this frame. The reviewer itself identified
  the resulting original memory-corrupting cleanup versus rebuilt clean-object
  cleanup. That is an executable error-path difference, not merely byte topology.
- **Frame observability:** even without unwind, the original and rebuilt expose
  different `FS:[0]` registration layouts during the body. Normal game code is
  not shown inspecting them, but the difference reinforces that the EH gap
  cannot be adjudicated as universally unobservable.

Round 1 therefore verifies all ordinary paths but does **not** satisfy the
no-substantive-open-finding promotion gate. The original's defective cleanup is
part of the behavior oracle, including on fault/unwind paths.

## Integrated changes

Before phase entry, the source was normalized from gap-only/nonvirtual stubs to the binary-backed polymorphic layout and natural C++ lifetime operations. The full-TU probe reproduced the same pinned VC5 EH family.

## Final decision

Remain in `src/scratch`; do not promote to `src/verified_logic`. A future
promotion requires either a natural compiler/TU surface that reproduces the
original three-slot frame and erroneous cleanup address or a project-level
decision explicitly excluding this demonstrated fault/unwind behavior. Do not
encode the bad funclet manually or with forbidden assembly.
