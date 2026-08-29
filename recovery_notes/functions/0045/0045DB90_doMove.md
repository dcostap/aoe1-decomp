# Recovery journal: 0045DB90 `doMove`

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


<!-- recovered:8a2ef389d33d7f027b83 -->
### `d050eea3c` `src/move_obj.cpp:834-855`

Mapping: `ambiguous`. next mapped function definition is doMove at old line 938.

```text
// Owner checkpoint: move_obj.cpp:663-815, 1232 bytes, 50 ordered calls,
// [non-comment lines omitted during migration]
        // BINARY NOTE: the inline helper is required for the original Path receiver schedule.
// [non-comment lines omitted during migration]
    // BINARY NOTE: the executable keeps this constant guard and its unreachable cleanup arm.
```
<!-- end-recovered:8a2ef389d33d7f027b83 -->

<!-- recovered:46461c6a69559156015e -->
### `d050eea3c` `src/move_obj.cpp:883-883`

Mapping: `strong`. next mapped function definition is doMove at old line 938.

```text
            // BINARY NOTE: natural casts keep __ftol input on x87 ST0.
```
<!-- end-recovered:46461c6a69559156015e -->

<!-- recovered:1762db712294669fb787 -->
### `d050eea3c` `src/move_obj.cpp:916-916`

Mapping: `strong`. next mapped function definition is doMove at old line 938.

```text
        // BINARY NOTE: cast each floor result before subtracting the float tile bias.
```
<!-- end-recovered:1762db712294669fb787 -->

<!-- recovered:e21841348a1fbcff6232 -->
### `6a2aef2e2` `src/move_obj.cpp:715-725`

Mapping: `ambiguous`. next mapped function definition is doMove at old line 817.

```text
// The canonical RGE_Moving_Object, Path, and UnitAIModule surfaces live in
// include/move_obj.h. The source uses those named declarations.
// default flags, and 0.0000% difference before source reunification.
// [non-comment lines omitted during migration]
        // the inline helper is required for the original Path receiver schedule.
```
<!-- end-recovered:e21841348a1fbcff6232 -->

<!-- recovered:b3521400ede1147c94f7 -->
### `6a2aef2e2` `src/move_obj.cpp:1245-1283`

Mapping: `ambiguous`. comment lies after mapped function doMove at old line 817.

```text
//   complete named RGE_Static_Object and RGE_Master_Static_Object virtual surfaces.
// - repeated currentWaypoint() expressions to preserve the original ordered calls;
//   the final direct snap call now matches all 83 original call sites.
// - inlined the target-radius predicate as one typed expression; this is the cleanest
// - reversed the first turnTimer guard to the original negative-first source shape;
// - promoting one Waypoint* across the repeated path scans collapsed the frame to
// - reordering the real arithmetic locals to the dossier order was emitted-code
// - cached displayPathObjectID before the display gate, matching its original
//   three evidence-backed hypotheses;
//   remaining evidence points to original local-frame/register topology and VC5
//   tail/block scheduling, not a missing call or virtual-surface declaration.
// - reintroduced the decompiler's zero-initialized first-turn temporary; it
// - restored named target-distance and radius temporaries from the original
// - naming the owner world and radius components was emitted-code duplicate or
//   worse; kept only the natural target-distance temporaries.
// - the shipped second-turn x87 block starts with fsin; the retained reverse
//   assignment order follows that binary order.
// - the late next-distance value uses a qword store and fmul.
//   A natural double local restores the original 0x2C frame.
//   eight bytes in the reduced double-local source.
// - unresolved: current result is 2814 differing bytes, 72.35% shape, and
//   names newY, dX, newX, newAngle, tempZ, alreadyMoving, angleDelta,
//   facetDelta, numberFacets, curDistance, distanceToCover, speedOffset,
//   result, targetDX, targetDY, and dY, with optimized stack-slot aliases.
//   call alignment; and reusing found for passable was another duplicate.
//   local roles. The angleDelta spelling was emitted-code duplicate evidence.
// - the shipped fallback publishes the passability coordinates,
//   then rereads both floor expressions for teleport. Keep both direct calls.
// - the late next-distance path keeps one double coordinate
//   product, then rounds the distance to float before its ordered tests.
// - the preceding exact move_obj.cpp definitions were restored in the
//   shape, 0x2C frame, and all 83 direct-call sites aligned. Exact finish
//   remains unresolved at the first local home and steering x87 block.
//   same bytes, calls, frame, boundary, and owner, so the standalone context
// - the original uses EDI for the facet count, then spills it to
// - the original late next-distance block keeps the mixed float
//   and qword x87 sequence. A double local lowered to two qword stores and
// - the original dword alreadyMoving home is required. A bool
//   were restored. Keep named target reads and the ordered object rereads.
```
<!-- end-recovered:b3521400ede1147c94f7 -->

<!-- recovered:92033f53968033da0eac -->
### `target-session` `build/target_sessions/0045DB90_doMove.json:1-51`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=3105; shape=46.43823264201984: Baseline clean natural reconstruction before new probes.
probe 2 control-flow; result=MISMATCH; diff=3116; shape=45.53651938683499: Hypothesis: model Ghidra's separate retry-success flag as an explicit natural while condition, not a do-while predicate.
probe 3 liveness; result=MISMATCH; diff=3277; shape=46.34806131650135: Hypothesis: initialize retry-success at function entry, matching original EBP zero state before the first retry scan.
probe 4 liveness; result=MISMATCH; diff=3277; shape=46.34806131650135: Hypothesis: move the retry-success declaration before float locals to reproduce VC5's original saved-register and stack-home coloring. [same emitted code as probe 3]
probe 5 liveness; result=MISMATCH; diff=3277; shape=46.34806131650135: Hypothesis: use declaration initialization for retry-success, which can select VC5's register zeroing and home placement differently from a later assignment. [same emitted code as probe 4]
probe 6 behavior; result=MISMATCH; diff=3277; shape=46.34806131650135: Hypothesis: reverse the commutative Y-radius sum to match the original fld targetRadiusY then fadd master radius_y order. [same emitted code as probe 5]
probe 7 liveness; result=MISMATCH; diff=3170; shape=45.26600541027953: Hypothesis: name the Y-radius operands before subtraction to preserve the original target-radius-first x87 operand order.
probe 8 behavior; result=MISMATCH; diff=3317; shape=46.34806131650135: Hypothesis: preserve the original path-result flag across the zero-distance waypoint passable call; the assembly does not overwrite EBP with passable's EAX.
probe 9 context; result=MISMATCH; diff=3289; shape=46.61857529305681: Hypothesis: cache displayPathObjectID before each display gate, matching Ghidra's observed pre-gate load.
probe 10 behavior; result=MISMATCH; diff=3304; shape=46.70874661857529: Hypothesis: retain the moveToNextWaypoint result in path_result after the zero-distance waypoint path; original stores EAX in EBP before the closest-distance store.
probe 11 liveness; result=MISMATCH; diff=3267; shape=46.61857529305681: Hypothesis: use Ghidra's observed bool retry-success type, which may keep the flag in EBP and free the original stack homes.
probe 12 control-flow; result=MISMATCH; diff=3267; shape=46.61857529305681: Hypothesis: use the Ghidra-natural negated bool loop condition instead of an explicit comparison to false. [same emitted code as probe 11]
probe 13 behavior; result=MISMATCH; diff=3293; shape=46.97926059513075: Hypothesis: second retry-path one-waypoint fractional snap returns the binary's fixed 1, not the local path-search result.
probe 14 control-flow; result=MISMATCH; diff=3278; shape=69.52209197475203: Hypothesis: mirror Ghidra's explicit cached waypoint-count do-loop in both action-log scans.
probe 15 liveness; result=MISMATCH; diff=3278; shape=69.52209197475203: Hypothesis: reset the retry flag before the path result store, matching original EBP zeroing and zero-register reuse for pathingGroupMembers. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=3227; shape=70.96483318304779: Hypothesis: use the direct owner master-object chain for display calls, matching the original nested receiver setup rather than a named master alias.
probe 17 behavior; result=MISMATCH; diff=3301; shape=72.22723174030658: Hypothesis: reverse the one-waypoint fraction branch from the prior decompiler-shaped source; assembly teleports on exact half-cell fractions and uses the range-failure tail otherwise.
probe 18 behavior; result=MISMATCH; diff=3323; shape=72.22723174030658: Hypothesis: match Ghidra's asymmetric one-waypoint branches: first retry uses passable-failure-or-half-cell tail; second retry uses passable-success half-cell tail.
probe 19 liveness; result=MISMATCH; diff=3076; shape=69.16140667267808: Hypothesis: scope each retry-success local to its own loop, matching Ghidra's local bool lifetime and allowing post-loop zero-state reuse.
probe 20 liveness; result=MISMATCH; diff=3076; shape=69.16140667267808: Hypothesis: preserve the path-range tail's observed zero-register argument as a scoped natural zero local, preventing VC5 tail merge with the common success call.
probe 21 liveness; result=MISMATCH; diff=3323; shape=72.22723174030658: Follow-up grouped test: retain all Ghidra-backed behavior and display/log loop changes while widening retry-success lifetime to function scope for original EBP prologue coloring. [same emitted code as probe 18]
probe 22 liveness; result=MISMATCH; diff=3076; shape=69.16140667267808: Follow-up: scoped retry locals plus the proven zero path_result as the path-range tail argument, to preserve EBP-zero push and separate virtual-call shape. [same emitted code as probe 19]
probe 24 liveness; result=MISMATCH; diff=3076; shape=69.16140667267808: Hypothesis: a narrow zero argument on the first range-success removeAll call prevents VC5 tail merging while preserving the original two virtual vslot+1C0 call sites. [same emitted code as probe 20]
probe 25 liveness; result=MISMATCH; diff=3076; shape=69.16140667267808: Hypothesis: the PDB line-1078 zeroing is a scoped natural zero local for the first path-range success call; carry that local through the virtual argument and path-member reset to preserve its separate call site. [same emitted code as probe 24]
probe 27 control-flow; result=MISMATCH; diff=3078; shape=72.85843101893597: Hypothesis: remove the explicit shared range-success label and write each source success arm directly, so VC5 retains the original unique path-range virtual call and shared later success shape through natural duplicate statements.
probe 28 liveness; result=MISMATCH; diff=3078; shape=72.94860234445446: Hypothesis: match Ghidra's recovered local declaration order: distance/local_20, distanceToGoal, dY, newDY. This may recover the original vtable stack home and avoid the extra early newDY copy.
probe 29 liveness; result=MISMATCH; diff=3078; shape=72.94860234445446: Hypothesis: follow the Ghidra local declaration order by placing Path*, Waypoint*, and path_result before the float locals. This may recover the original early cached-vtable home and branch local allocation. [same emitted code as probe 28]
probe 30 control-flow; result=MISMATCH; diff=3064; shape=75.20288548241659: Hypothesis: use the binary-supported <= 1 spelling for every numberUserDefinedWaypointsValue threshold. Original blocks compare the count with 1 and use JLE; current < 2 emitted CMP 2/JGE and changed return/add topology.
probe 31 behavior; result=MISMATCH; diff=3044; shape=75.02254283137962: Hypothesis: invert every count-return branch to the original positive form: count > 1 performs the +5 or +4 continuation and returns 1; the fall-through returns 0. The binary uses CMP 1/JLE to a shared zero return, and the first one-waypoint path returns EBX=1, not the path-search result.
probe 32 control-flow; result=MISMATCH; diff=3080; shape=73.9404869251578: Hypothesis: recover the binary's common findTilePath call tail by selecting endpoint integers in each waypoint-count arm, then issuing one natural findTilePath call. Ghidra shows one shared call after branch-local endpoint setup and two common __ftol conversions.
probe 33 control-flow; result=MISMATCH; diff=3044; shape=75.02254283137962: Hypothesis: model the first trivial-move result as a nonzero dispatch with a zero-result else fall-through. Original uses CMP/JNE to the result chain and a unique result-zero status/return block; this source form may retain that block.
probe 34 behavior; result=MISMATCH; diff=2992; shape=75.20288548241659: Hypothesis: reverse the commutative radius-magnitude sum to x*x + y*y. The original x87 block multiplies the stored +30 radius before the +34 radius, while the current y*y + x*x source emits the opposite FPU order.
probe 35 behavior; result=MISMATCH; diff=3051; shape=74.30117222723175: Hypothesis: use direct nested currentWaypoint member expressions for the zero-distance passable call. Original pushes path_result first, then obtains Y and X from two calls; the named y/waypoint source introduced an extra store and changed setup order.
probe 36 control-flow; result=MISMATCH; diff=2987; shape=74.39134355275023: Hypothesis: split the path-result-zero range-success guard from the retry-path guard. Original has two independent TEST EBP checks: one before the range test and one before retry setup; the single current outer if removes the second redundant predicate.
probe 37 behavior; result=MISMATCH; diff=3104; shape=75.38322813345356: Hypothesis: replace top-level retry_dx/retry_dy temporaries with direct userDefinedWaypoints coordinate expressions in both retry scans. Original reuses one stack integer home and its x87 sequence does not materialize two named float deltas.
probe 42 control-flow; result=MISMATCH; diff=2992; shape=75.20288548241659: Hypothesis: express the first doTrivialMove result as the binary's zero arm first, then 1/6 and 2/3/4 arms, to preserve the distinct rangeStatus return block.
probe 44 control-flow; result=MISMATCH; diff=2976; shape=75.47339945897205: Hypothesis: use the positive currentWaypoint guard so the null-path path_result=0 block follows the successful waypoint body, matching the original JE to the later zero arm.
probe 45 liveness; result=MISMATCH; diff=2976; shape=75.47339945897205: Hypothesis: remove the explicit object-radius locals and use the proven master radius members directly, reducing artificial addressable liveness before the path scan.
probe 46 control-flow; result=MISMATCH; diff=3062; shape=74.93237150586114: Hypothesis: use one natural findTilePath statement with branch-local integer endpoints and a <=0 count guard, matching the original shared call tail and test/jle shape.
probe 48 liveness; result=MISMATCH; diff=2976; shape=75.47339945897205: Hypothesis: place the scalar distance locals before Path and Waypoint pointer declarations, testing the PDB/decompiler scalar-first local basin while retaining the positive null guard. [same emitted code as probe 45]
probe 49 liveness; result=MISMATCH; diff=2984; shape=75.29305680793507: Hypothesis: reuse the existing distance and dY locals for the two retry scans, matching the decompiler's carried float temporaries instead of retaining retry-only locals.
probe 51 behavior; result=MISMATCH; diff=3065; shape=75.83408476104599: Hypothesis: use direct currentWaypoint member expressions through the initial zero-distance and passable path, matching the repeated donor calls without retaining an early waypoint alias.
probe 53 control-flow; result=MISMATCH; diff=2988; shape=74.66185752930568: Hypothesis: split the path-result-zero range-success guard from retry setup into two independent guards, matching the original repeated TEST EBP and late retry block.
probe 54 control-flow; result=MISMATCH; diff=2987; shape=74.39134355275023: Hypothesis: retain the independent path-result-zero guards but restore the original negative currentWaypoint guard, isolating the earlier extra virtual-call effect.
probe 56 behavior; result=MISMATCH; diff=2976; shape=75.47339945897205: Hypothesis: remove the redundant path_result=1 assignment in the zero-distance waypoint arm. The original carries the earlier EBP=1 value into the guarded passable call and pushes it before waypoint reads. [same emitted code as probe 48]
probe 57 behavior; result=MISMATCH; diff=3047; shape=75.83408476104599: Hypothesis: use direct nested currentWaypoint expressions for the zero-distance passable call. Right-to-left evaluation should push the carried path_result, then Y and X calls in the observed order without a temporary Y home.
probe 59 control-flow; result=MISMATCH; diff=3088; shape=74.84220018034264: Hypothesis: make the first retry scan a natural do/while, matching the original call-first loop and bottom TEST EBP backedge.
probe 61 liveness; result=MISMATCH; diff=2976; shape=75.47339945897205: Hypothesis: scope retry coordinate locals inside each retry loop, preventing retry-only homes from displacing the original distanceToGoal and x87 scratch slots.
probe 62 liveness; result=MISMATCH; diff=2976; shape=75.38322813345356: Hypothesis: declare distanceToGoal at its first use after waypoint processing, matching the binary's late zero home and testing whether its scope controls the original [esp+1c] slot.
probe 63 liveness; result=MISMATCH; diff=2976; shape=75.38322813345356: Hypothesis: join the late distanceToGoal declaration and zero initialization, testing the PDB-line initialization form while preserving its late stack home. [same emitted code as probe 62]
probe 64 control-flow; result=MISMATCH; diff=3042; shape=75.92425608656447: Hypothesis: spell both retry waypoint-count exits as <=0, matching the original TEST EAX/JLE guards rather than VC5's CMP 1/JL lowering for <1.
```
<!-- end-recovered:92033f53968033da0eac -->

<!-- recovered:6bb38b60eb501910787a -->
### `ed599f2a6eab` `src/scratch/0045DB90_doMove.cpp:4-26`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Attempt log:
// - Reconstructed the moving-object, Path, PathingSystem, player, and waypoint
//   ownership from the packet, exact move_obj.cpp donors, and original x87 flow.
// - The speed reset is the inherited RGE_Animated_Object field at +0x88;
//   trail_remainder begins at +0x8c and is not the field written by doMove.
// - Ghidra shows a separate retry-success local in both scans. Scoped natural
//   retry loops remove the two peeled virtual-call sites and preserve the 0x18
//   frame. Explicit cached waypoint-count loops match the action-log CFG.
// - Binary control flow also requires the moveToNextWaypoint result, the fixed
//   second retry-path return of 1, and asymmetric one-waypoint branches.
// - Direct success arms, rather than one explicit shared label, preserve both
//   original +0x1C0 virtual call sites. The count tests use the binary's <= 1
//   and > 1 forms. The radius sum uses x*x + y*y for the observed x87 order.
// - Qualified owner: RGE_Moving_Object::doMove in move_obj.cpp. The packet
//   boundary is 0045DB90-0045E966 (3543 bytes). The canonical move_obj TU
//   protects the neighboring findPath and doTrivialMove anchors.
// - The final natural frontier is diff 2976, 75.38% shape, 3395 rebuilt bytes,
//   and 105/105 ordered calls. A positive waypoint guard, direct radius
//   members, late distanceToGoal initialization, and scoped retry locals are
//   retained because they improve or preserve the frontier without changing
//   the owner or call surface. The remaining gap is register, stack-home,
//   loop CFG, and x87 scheduling. No padding, manual vtable, or opaque codegen
//   form is retained.
```
<!-- end-recovered:6bb38b60eb501910787a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
