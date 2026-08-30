# Function notes: 004F99B0 `taskPlay`

Module notes: `decomp_notes/taitacmd_module.md`.

## Recovered attempt history

<!-- recovered:b52b7299cebc6b76e66b -->
### `d050eea3c` `src/taitacmd.cpp:9801-9818`

Mapping: `ambiguous`. next mapped function definition is taskPlay at old line 9956.

```text
//   tail improved this to 1030B/916 diff, with all 32 ordered calls aligned.
// - A shared success-tail variant was diagnostic only (937B/936 diff) and was
//   rolled back.  Remaining blocker: 0x1C versus 0x18 frame and stack-home/
//   register-color differences; checker remains in STRUCTURAL RECONSTRUCTION.
// - Replaced the raw debug-file address with the named source string. This does
// [non-comment lines omitted during migration]
// - Continued probes: a positive object/UnitAI guard restored the late null
// [non-comment lines omitted during migration]
// - Continued probes: direct task-result predicates removed false stack stores.
// [non-comment lines omitted during migration]
// - Separate found-index, union-overlay, array-slot, and header-context probes
//   did not improve this result and were rolled back.
// - Current worker probes: taskResult-first flag initialization reduced the
// [non-comment lines omitted during migration]
//   overlays, and tail-label variants were worse or codegen duplicates.
```
<!-- end-recovered:b52b7299cebc6b76e66b -->

<!-- recovered:a9580a584c7f61172370 -->
### `d050eea3c` `src/taitacmd.cpp:9899-9899`

Mapping: `strong`. next mapped function definition is taskPlay at old line 9956.

```text
    // BINARY NOTE: The found record remains live through all later task calls.
```
<!-- end-recovered:a9580a584c7f61172370 -->

<!-- recovered:a32a7744616e2c7e52d0 -->
### `d050eea3c` `src/taitacmd.cpp:9958-9962`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// ---------------------------------------------------------------------------
// PDB source owner: 004F99B0_taskPlay.cpp
// ---------------------------------------------------------------------------
// 004F99B0 TribeTacticalAIModule::taskPlay
// taitacmd.cpp:8231-8251, 281 bytes
```
<!-- end-recovered:a32a7744616e2c7e52d0 -->

<!-- recovered:ce496aa0adaa488e946c -->
### `6a2aef2e2` `src/taitacmd.cpp:8467-8489`

Mapping: `ambiguous`. next mapped function definition is taskPlay at old line 8625.

```text
// taitacmd.cpp: 7988-8225
//   calls).  The source was reset to the same-TU typed tactical-AI surface
//   before further code-generation work.
//   object / UnitAI member calls, resource-AI member call, and the natural
//   four-distribution task loop.  The five-word tried array models the binary's
//   object slot at element zero and four task flags at elements one through
//   four; the fallback passes element one as the output flag array.
//   the clean typed candidate is 910B versus 1018B (50.30% shape, 934 strict
//   diff bytes); the remaining structural gap is return/block topology.
//   reached 900B/926 diff bytes but lost the proven 0x18 frame and was rolled
// - Direct indexed/typed gatherer fields recovered the original folded
//   this-relative addressing and raised shape to 66.39%; a named gatherer
// - Initializing taskResult with triedTasking[1..3] removed the unsupported
//   fifth flag slot and recovered most structural islands.  A shared null
//   not change code generation.
//   return; desired[-4] < *desired restored the paired distribution cursor.
//   A gatherer pointer re-anchor after the first task branch restored the
//   original register colors and the strongest clean nonexact result: 962B,
//   83.93% shape, 421 strict-diff bytes, and the 0x18 frame.
//   strict diff to 418B and raised shape to 84.23% without changing the 0x18
//   frame or 32-call order. Cursor rewrites, direct indexing, object-window
// - The remaining structural gap is the target's late success/failure block
//   order and its one extra instruction; no supported exact source was found.
```
<!-- end-recovered:ce496aa0adaa488e946c -->

<!-- recovered:f4d3f7ae8577f7be0ab7 -->
### `30c9a04a1db9` `src/scratch/004F99B0_taskPlay.cpp:1-22`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004F99B0 TribeTacticalAIModule::taskPlay
// taitacmd.cpp:8231-8251, 281 bytes
//
// int __thiscall TribeTacticalAIModule::taskPlay(int param_1, int* param_2, int param_3, int param_4,
//     int param_5, Waypoint* waypoints, int waypointCount)
// ret 1Ch cleanup (7 stack params + this in ecx)
//
// Flow:
// 1. If waypoints != NULL and count > 0: iterate waypoints (16B stride)
//    and call addWaypoint(param_1, (int)x, (int)y) via __ftol
// 2. Search/grow unitsTasked IntArray for param_1 (same pattern)
// 3. Dispatch mission: this->md->missionObj->vtable[0x4C](param_1..param_5)
// 4. Return 1
//
// === Attempt log ===
// 1: First 7 bytes match (push ebx, push ebp, mov ebp param_1, push esi)
//    this→edi vs orig this→esi (registers swapped with Waypoint* ptr)
//    AddWaypoint loop uses esi for waypoint ptr vs orig edi
//    Array search: count→edx, maxSz→esi, value ptr→ecx (cascade from reg swap)
//    Virtual dispatch: vtable[0x4C] call has correct 5-param pattern
//    Same TU-context register cascade as all taitacmd functions
// BLOCKER: TU-context register swap (this↔Waypoint*)
```
<!-- end-recovered:f4d3f7ae8577f7be0ab7 -->
