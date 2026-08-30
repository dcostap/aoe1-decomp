# Function notes: 004E41C0 `damageInflictedPerSecond`

Module notes: `decomp_notes/taiinfmd_module.md`.

## Recovered attempt history

<!-- recovered:6237e3c9e96c254400f1 -->
### `target-session` `build/target_sessions/004E41C0_damageInflictedPerSecond.json:1-4`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MATCH; diff=0; shape=100.0: Fresh rebuild confirms PDB-qualified TribeInformationAIModule::damageInflictedPerSecond in taiinfmd.cpp lines 8228-8257, boundary 004E41C0-004E4238, exact six-call/frame/CFG and bytes; natural loop preserves terrain local, object/player rereads, x87 order, and cleanup.
probe 2 liveness; result=MATCH; diff=0; shape=100.0: Exact-finish reversion test: remove the numerator local and inline target->damageCapability(obj); this tests whether the required fstp/call/fdivr ordering needs that local. [same emitted code as probe 1]
probe 3 behavior; result=MISMATCH; diff=118; shape=82.22222222222223: Exact-finish negative test: cache the initial group count and remove the loop reread. The executable rereads numberUnits after each iteration, so this tests both codegen and required behavior.
probe 5 liveness; result=MATCH; diff=0; shape=100.0: Walkback retained: removing the unused numerator temp remains exact. The direct expression is the smaller natural VC5 source while preserving the x87 call/divide/add order. [same emitted code as probe 2]
```
<!-- end-recovered:6237e3c9e96c254400f1 -->

<!-- recovered:d9a19c6baf01b6e37fb3 -->
### `00492347d989` `src/scratch/004E41C0_damageInflictedPerSecond.cpp:1-24`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004E41C0 TribeInformationAIModule::damageInflictedPerSecond()
// Source: taiinfmd.cpp lines 8228-8257
// Size: 121 bytes, __thiscall, returns float
//
// Attempt log (9 probes):
// Probe 1: Virtual class with 66 methods (64 dummies + 2 real) — 81 diff bytes
//   EH overhead from virtual class declaration
// Probe 2: __declspec(novtable) — still 81 bytes
// Probe 3: Raw function pointers via vtable struct — 88 bytes (__cdecl push all args)
// Probe 4: Fixed loop structure (do-while, i=0 before call numberUnits) — 32 bytes!
//   Virtual calls at +0x100 and +0x104 work correctly!
// Probe 5: Declare hp separately — 32 bytes
// Probe 6: rVal = temp / hp + rVal — 32 bytes
// Probe 7: rVal += temp / hp — 32 bytes
// Probe 8: float ratio = temp / hp; rVal += ratio — 32 bytes
// Probe 9: rVal = (temp / hp) + rVal — 32 bytes
//
// Remaining 32 bytes: FPU scheduling + jump target offsets
//   - Both fstp to memory and fdivr/fadd sequence match structurally
//   - Rebuilt uses `fld [mem]; fxch; fstp [mem]; fdiv [mem]` instead of `fdivr [mem]`
//   - Same FPU result, different x87 scheduling (compiler heuristic difference)
//   - Jump offsets shift by the FPU code size difference
// All semantically equivalent. Pure VC5 FPU scheduling artifact.
// Parked in scratch per Boss direction.
```
<!-- end-recovered:d9a19c6baf01b6e37fb3 -->
