# Function notes: 00412F00 `UnitAIModule`

Module notes: `decomp_notes/aiuaimod_module.md`.

## Recovered attempt history

<!-- recovered:811aa47e887c22a4e18d -->
### `d050eea3c` `src/aiuaimod.cpp:10-11`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// --- matching/00412F00_UnitAIModule.cpp ---
// VA: 00412F00 UnitAIModule ctor (356B)
```
<!-- end-recovered:811aa47e887c22a4e18d -->

<!-- recovered:f677b0cf2d77c3db629e -->
### `d050eea3c` `src/aiuaimod.cpp:13-13`

Mapping: `strong`. comment lies after mapped function UnitAIModule at old line 1.

```text
// EH frame (/GX)
```
<!-- end-recovered:f677b0cf2d77c3db629e -->

<!-- recovered:d6465984315e2b3f87f9 -->
### `target-session` `build/target_sessions/00412F00_UnitAIModule.json:1-7`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=88; shape=95.83333333333333: Baseline current natural constructor with typed EH member, delayed vptr, and proven call ABIs.
probe 2 variant; result=MISMATCH; diff=121; shape=92.70833333333333: Test body assignments instead of scalar initializer list; source-history donor used this natural form.
probe 4 variant; result=MISMATCH; diff=88; shape=95.83333333333333: Use scalar delete in ManagedIntArray destructor, matching exact UnitAIModule destructor donor; keep new[] allocation. [same emitted code as probe 1]
probe 6 variant; result=MISMATCH; diff=88; shape=95.83333333333333: Use integer -1 implicit float conversion for target coordinates; test literal typing as scheduler axis. [same emitted code as probe 4]
probe 8 variant; result=MISMATCH; diff=88; shape=95.83333333333333: Explicit empty ManagedIntArray constructor and member initializer; test original member-construction EH scheduling.
probe 10 variant; result=MATCH; diff=0; shape=100.0: Model attackingUnits as a real member constructor initialized with capacity 10; move its zeroing/allocation into initializer execution.
probe 11 abi; result=MATCH; diff=0; shape=100.0: Keep the exact member-capacity constructor while using scalar delete, as the exact UnitAIModule destructor donor proves this ManagedArray bug. [same emitted code as probe 10]
```
<!-- end-recovered:d6465984315e2b3f87f9 -->

<!-- recovered:928f8ffe3ffd7d503958 -->
### `b3eaae6c44b0` `src/scratch/00412F00_UnitAIModule.cpp:1-36`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00412F00 UnitAIModule ctor (356B)
// aiuaimod.cpp
// EH frame (/GX)
// [non-comment lines omitted during migration]
//
// Attempt log:
// - The first isolated typed candidate had the right four calls and layout but
//   no EH frame. Correcting setAdjustedIdleTimeout to its proven thiscall
//   member ABI removed the spurious caller push/cleanup.
// - Modeling the proven ManagedArray<int> member with its inline scalar-delete
//   destructor restored the original EH frame, 356-byte size, phase local,
//   delayed vptr position, call-site cleanup, and exact 34-instruction tail.
// - The current natural source uses the binary-proven novtable/delayed-vptr
//   surface, scalar initializer list, real managed-array destructor, and
//   standard new/member-call ABIs. Current best: 356/356 bytes, 4/4 ordered
//   calls, 95.83% shape, 88 positional differing bytes; the tail from
//   +0xF4 through +0x164 is exact.
// - Tried natural compiler-owned vptr, a declaration-only member destructor,
//   a local allocation result, register-qualified obj, and the template
//   spelling; none changed the remaining hunk. Original pushes EDI and loads
//   obj before MOV ESI,this, saves this only before the first allocation, and
//   keeps push 0x28 after the +0x38..+0x5C stores. VC5 currently moves MOV
//   ESI,this/EH-local save ahead of PUSH EDI and hoists that argument push.
// - Added the full UnitAIModule virtual ABI and typed OrderEvent/NotifyEvent
//   queue surfaces; the emitted constructor stayed identical.
// - Replaced proven waypoint padding with the typed Waypoint array and last
//   position aggregate, then typed both queue pointers; both probes stayed
//   identical. An empty ManagedArray default constructor also had no effect.
// - Split initializer-list prefixes, a natural zeroing member constructor,
//   new int[10], and the likely standard-header pair. The split lab found no
//   exact source; new int[10] and headers emitted the same 88-byte result.
// - Pausing with the best source: remaining drift is the constructor's first
//   block liveness/EH scheduling. Calls, layout, size, and tail are aligned.
//   No inline asm or compiler-only filler used.
```
<!-- end-recovered:928f8ffe3ffd7d503958 -->
