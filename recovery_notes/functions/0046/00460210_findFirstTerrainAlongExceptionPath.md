# Recovery journal: 00460210 `findFirstTerrainAlongExceptionPath`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/move_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\move_obj.cpp`.
- Earlier recovery note: `recovery_notes/move_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d74710cd9459ea8163e0 -->
### `d050eea3c` `src/move_obj.cpp:2204-2209`

Mapping: `strong`. next mapped function definition is findFirstTerrainAlongExceptionPath at old line 2246.

```text
// - Baseline had the correct 276-byte structure but scheduled the two exception
// [non-comment lines omitted during migration]
//   the late branch target and produced an exact match.
// - Main-agent audit restored canonical map/world/player destructor ownership;
```
<!-- end-recovered:d74710cd9459ea8163e0 -->

<!-- recovered:c7e76430b8eed5a13467 -->
### `d050eea3c` `src/move_obj.cpp:2251-2251`

Mapping: `strong`. comment lies after mapped function findFirstTerrainAlongExceptionPath at old line 2246.

```text
// Standalone owner checkpoint: 406-byte owner with the exact XYPoint virtual ABI.
```
<!-- end-recovered:c7e76430b8eed5a13467 -->

<!-- recovered:3ab7e539a1d8122cb9e0 -->
### `d050eea3c` `src/move_obj.cpp:2282-2282`

Mapping: `strong`. comment lies after mapped function findFirstTerrainAlongExceptionPath at old line 2246.

```text
            // ORIGINAL BUG: The original 00460210 body writes the x-derived
```
<!-- end-recovered:3ab7e539a1d8122cb9e0 -->

<!-- recovered:832a8f5d94408c8c9a46 -->
### `6a2aef2e2` `src/move_obj.cpp:1989-1995`

Mapping: `strong`. next mapped function definition is findFirstTerrainAlongExceptionPath at old line 2031.

```text
// - Replaced the placeholder with the period-plausible pathing implementation.
//   The point bounds are checked through owner->world->map; exception fields are
//   set before selecting pathSystem versus aiPathSystem, and both branches call
//   the real path finder with the four object-coordinate conversions.
//   stores in the opposite order (5 differing bytes).
//   branch opcode; placing the aiPathSystem arm first made the zero-useAI path
//   emitted code remains exact.
```
<!-- end-recovered:832a8f5d94408c8c9a46 -->

<!-- recovered:abf437b8bf11906db7ff -->
### `ebd68efd7045` `src/scratch/00460210_findFirstTerrainAlongExceptionPath.cpp:1-21`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00460210 RGE_Moving_Object::findFirstTerrainAlongExceptionPath
// Attempt log:
// 1: placeholder helper-only source was structurally unrelated to the 406-byte oracle.
// 2: reconstructed the exception-path segment scan from the packet: typed XYPoint
//    locals, repeated currentWaypoint/natural float-to-int conversions,
//    firstTileAlongLine vslot +1B4,
//    and the -1.0 output sentinel. Initial typed baseline follows the original
//    local declaration order; further VC5 stack-home tuning may be needed.
// 3: natural top-tested while plus one named success result reached exact size/frame,
//    26/26 calls, and 16 differing bytes; residual drift is local stack-home ordering
//    and branch-tail displacement around the coordinate temporaries.
// 4: direct zero returns for early path failures matched the oracle's separate
//    return tail and reduced drift to 12 bytes. A named contiguous segment
//    aggregate reached 9 bytes but was not retained; separate XYPoint locals
//    remain the natural source. Remaining drift is local-home allocation only.
// 5: testing the evidence-backed contiguous segment with pointer ABI and
//    explicit y-field addresses; the loop counter remains separate.
// 6: the segment/pointer form kept size, frame, and ordered calls aligned but
//    emitted the same 12-byte local-home drift; retained as the clean lead.
// Main-agent audit restored the exact-donor XYPoint* virtual ABI. The casts
// document the executable's overlapping point windows. Emitted code is unchanged.
```
<!-- end-recovered:abf437b8bf11906db7ff -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
