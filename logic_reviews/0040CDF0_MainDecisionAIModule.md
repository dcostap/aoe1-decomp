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

### Round 1 — concurrent blind cohort, 2026-08-02

- `sa-47849d84` — `openai-codex/gpt-5.6-luna`, max thinking
- `sa-5de0aea2` — `deepseek/deepseek-v4-flash`, max thinking

Both reviewers independently verified the signature, base-constructor arguments,
derived layout, successful-path stores, delayed derived-vptr value/timing, return
value, and final object state. Neither found a successful-construction data or
call difference.

The DeepSeek reviewer judged the absent target-local EH registration
behaviorally inert because the visible body has no throwing operation after the
base constructor. The Luna reviewer independently identified the original EH
metadata's base-destructor unwind action, the rebuilt store-order difference,
the unresolved vtable symbol requirement, and an inactive local `AIModuleID`
constructor declaration whose parameter order disagrees with exact donors.

## Main-agent adjudication

- **Normal construction:** verified. The call, arguments, field widths/offsets,
  final values, derived vptr, and implicit constructor return agree.
- **Original EH metadata:** direct extraction from `empiresx.exe` at
  `FuncInfo 0x5788F0` proves `maxState=1` and one unwind-map entry
  `state 0 -> -1`, action `0x55C630`. That action loads the object from
  `[ebp-0x18]` and tail-jumps to `AIModule::~AIModule` at `0x40E360`.
  However, the function initializes its state word to `-1`, never writes state
  zero, and has no IP-to-state map (`nIPMapEntries=0`), so the cleanup action is
  not shown reachable by the visible executable path. The metadata is real, but
  no concrete cleanup-outcome difference is currently proved.
- **FS chain:** the original installs its registration before calling the base
  constructor; the rebuild installs none. This is directly observable to an
  exception/signal handler or code that walks `FS:[0]`, even if no ordinary
  successful call does so. The two reviewers did not establish an ordinary
  caller-reachable observer.
- **Store/fault order:** original emitted code stores `player` at `+0xF0` before
  zeroing `+0xF4..+0x100`; the current rebuilt code zeroes `+0xF4..+0x100`
  before storing `player`. The C++ statements are in original order, but VC5
  reschedules them. Final state matches for a valid object; an invalid or
  boundary-mapped `this` can fault at a different first address and after
  different partial writes. Under the project's executable-fault policy this is
  a substantive unresolved edge, not silently harmless drift.
- **Vtable symbol:** `MainDecisionAIModule_vtable` must eventually be defined at
  the original vtable relocation/address. The symbolic donor-style declaration
  expresses the intended ownership but the current per-function corpus is not a
  complete link, so this remains an integration requirement rather than a
  proved target-body difference.
- **Local declaration concern:** exact `AIModuleID` donors support
  `AIModuleID(char*, int)`, while this file declares `(int, char*)`. This target
  does not call that constructor directly, so it does not alter target behavior,
  but it should be corrected during the next source-normalization pass.

Round 1 therefore does **not** meet the no-substantive-open-finding gate. The
successful path is verified, but the emitted fault/store order and original-only
FS registration remain unresolved.

## Integrated changes

The candidate was normalized to full binary-backed field ownership before phase entry. Full-TU validation did not alter the pinned VC5 EH basin.

### Post-round matching follow-up, 2026-08-10

A fresh Luna matching worker tested nine additional natural ABI, member-lifetime,
aggregate, header-surface, and destructor-declaration hypotheses. Correcting the
inactive `AIModuleID` declaration to the exact-donor `AIModuleID(char*, int)` ABI
and using an inline `ManagedArray<int>` default constructor with a natural
`player(param_3)` initializer preserved the canonical delayed derived-vptr write
while making the emitted successful-path stores match the executable's order:
`player` at `+0xF0` now precedes the four zero stores at `+0xF4..+0x100`.

Main-agent validation confirmed the retained candidate remains 78/113 bytes with
one aligned base-constructor call, 106 strict differing bytes, and no emitted EH
frame. Thus the prior partial-write/first-fault store-order finding is resolved,
but the original-only FS-first three-slot registration remains unchanged. The
worker restored and validated the readable typed source and paused the lease; no
custom flags or manual EH/vptr machinery were added.

## Final decision

Remain in `src/scratch`. Do not promote to `src/verified_logic` from this round.
The player-first emitted store-order issue is now resolved. The remaining blocker
is the executable's FS-first three-slot registration versus the pinned compiler's
no-EH output (or incompatible push-first family under forced lifetime surfaces).
A future promotion requires a natural compiler/TU surface reproducing that frame,
or a project-level decision explicitly excluding the observable registration and
fault/unwind behavior already documented above.
