# Recovery journal: 00453C40 `check_placement`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/m_s_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\m_s_obj.cpp`.
- Earlier recovery note: `recovery_notes/m_s_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:c5335b915551cf385cd6 -->
### `d050eea3c` `src/m_s_obj.cpp:785-785`

Mapping: `strong`. next mapped function definition is check_placement at old line 801.

```text
                // ORIGINAL BUG: The beta save stream writes two bytes here.
```
<!-- end-recovered:c5335b915551cf385cd6 -->

<!-- recovered:37217ecc9ce253d43011 -->
### `d050eea3c` `src/m_s_obj.cpp:820-820`

Mapping: `strong`. comment lies after mapped function check_placement at old line 801.

```text
    // BINARY NOTE: The beta executable transposes the upper placement edges.
```
<!-- end-recovered:37217ecc9ce253d43011 -->

<!-- recovered:7e35c143c4985e016229 -->
### `target-session` `build/target_sessions/00453C40_check_placement.json:1-50`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1720; shape=72.6510067114094: Baseline current semantically faithful source: frame 0x44, size 1898/1909, 11 calls, 82/82 CFG; first mismatch prologue register order. Record current frontier before new hypotheses.
probe 2 layout; result=MISMATCH; diff=1720; shape=72.6510067114094: Hypothesis 1: register-qualified map pointer should preserve map in EBX and free a home, matching original map register lifetime. [same emitted code as probe 1]
probe 3 liveness; result=MISMATCH; diff=1720; shape=72.6510067114094: Hypothesis 2: explicit self alias for all master-field reads may make the receiver a persistent source local and select original EBP coloring.
probe 4 layout; result=MISMATCH; diff=1720; shape=72.6510067114094: Hypothesis 3: materialize terrain index before loading player world, matching original early this-relative terrain load ordering and receiver color. [same emitted code as probe 3]
probe 5 layout; result=MISMATCH; diff=1735; shape=72.94117647058823: Hypothesis 4: reorder edge declarations to left, right, bottom, top, matching original x87 stack setup where left is formed first, right radius is loaded, then bottom and top are completed.
probe 6 layout; result=MISMATCH; diff=1720; shape=72.6510067114094: Hypothesis 5: expand each edge into initialization plus compound assignment to preserve source evaluation dependencies and the original x87 load/add/sub topology. [same emitted code as probe 2]
probe 7 abi; result=MISMATCH; diff=1804; shape=71.71381031613977: Hypothesis 6: keep the four ftol-derived placement bounds as int locals, matching original full-width homes and later word compares from the observed stack accesses.
probe 8 control-flow; result=MISMATCH; diff=1792; shape=70.03367003367003: Hypothesis 7: remove separate center coordinate locals and assign the four perimeter bounds directly in the decompiler-proven center order, preserving center copies as local dependencies.
probe 9 context; result=MISMATCH; diff=1718; shape=72.81879194630872: Hypothesis 8: remove the world alias and use direct player-world chains in decompiler order, testing whether the original receiver and map register lifetimes come from expression ownership.
probe 10 context; result=MISMATCH; diff=1720; shape=72.6510067114094: Hypothesis 9: direct player-world chains but terrain-table expression first, matching original emitted terrain load before map while avoiding a world alias.
probe 11 liveness; result=MISMATCH; diff=1718; shape=72.81879194630872: Hypothesis 11: name the tile object-list address before the node walk, matching original LEA node-slot ownership and carried inner-loop address.
probe 12 control-flow; result=MISMATCH; diff=1721; shape=72.14765100671141: Hypothesis 12: use the decompiler's radius-selection source order p8==0 radius, else construction, while preserving the same branch polarity and values.
probe 13 layout; result=MISMATCH; diff=1718; shape=72.81879194630872: Hypothesis 13: bind the repeated float epsilon as one const local, testing whether one compiler literal object and shared lifetime recover the original bound subtraction schedule. [same emitted code as probe 11]
probe 14 control-flow; result=MISMATCH; diff=1836; shape=69.42148760330579: Hypothesis 14: split the four placement-bound rejects into sequential guards, testing whether original branch block layout comes from separate source statements.
probe 15 liveness; result=MISMATCH; diff=1777; shape=71.07023411371237: Hypothesis 15: cache map width and height as named locals, matching original separate width/height loads and repeated bound/clamp use.
probe 16 layout; result=MISMATCH; diff=1735; shape=73.10924369747899: Hypothesis 16: use edge declaration order left, right, top, bottom to test the original x87 stack setup and top/bottom store ordering.
probe 17 liveness; result=MISMATCH; diff=1718; shape=72.81879194630872: Hypothesis 17: split the radius local declaration into separate statements, testing whether VC5 local numbering or lifetime ordering controls the early x87 home layout. [same emitted code as probe 9]
probe 18 variant; result=MISMATCH; diff=1718; shape=72.81879194630872: variant lab build\variant_lab\00453C40_check_placement\20260817_160828: 4 variants, 0 invariant-eligible, 0 exact
probe 19 abi; result=MISMATCH; diff=1718; shape=72.81879194630872: Hypothesis 18: use bool flag locals instead of unsigned-char flags, matching Ghidra bool provenance. Variant lab separately tested four edge declaration orders; no exact and lbrt remained best family. [same emitted code as probe 17]
probe 20 liveness; result=MISMATCH; diff=1805; shape=65.59322033898304: Hypothesis 19: cache map_row_offset in one rows pointer because all observed accesses share that owner; expected to reduce repeated owner expressions if canonical.
probe 24 liveness; result=MISMATCH; diff=1730; shape=72.0: Hypothesis 1: scope a current_y copy inside the overlap guard so the row induction variable can naturally coalesce with the dead p10 home observed at entry+0x178.
probe 26 liveness; result=MISMATCH; diff=1733; shape=73.01854974704891: Hypothesis 2: keep one pointer-to-object-list slot across each overlap row and advance it by six entries, matching the original row setup before the inner column loop and its +0x18 cursor.
probe 27 liveness; result=MISMATCH; diff=1706; shape=72.69681742043551: Hypothesis 3: combine the persistent object-list cursor with a guard-scoped current_y row copy, testing whether row liveness then naturally uses the dead p10 home while preserving the proven inner +0x18 walk.
probe 28 layout; result=MISMATCH; diff=1706; shape=72.69681742043551: Hypothesis 4: reverse the local declaration order of overlap col2 and persistent node_slot, testing whether VC5 assigns EDI to the column and EBP to the object-list cursor as in the original overlap loop. [same emitted code as probe 27]
probe 29 control-flow; result=MISMATCH; diff=1814; shape=70.4201680672269: Hypothesis 5: replace named placement-edge temporaries with the decompiler-supported direct bound expressions and direct ftol casts, while preserving the binary-proven transposed upper axes and persistent overlap cursor.
probe 31 abi; result=MISMATCH; diff=1739; shape=73.10924369747899: Hypothesis 6: model the decompiler-supported float overlap cursor and explicit int-plus-one update, while keeping the persistent object-list pointer; test whether VC5 reduces it to the original word compare without short-local pressure.
probe 32 layout; result=MISMATCH; diff=1706; shape=72.69681742043551: Hypothesis 7: complete the proven RGE_Master_Static_Object tail layout from exact m_s_obj.cpp donors, testing whether the canonical 0xB8 class extent changes this-relative register coloring without raw overlays. [same emitted code as probe 28]
probe 33 context; result=MISMATCH; diff=1706; shape=72.69681742043551: Hypothesis 8: extend the reviewed exact-donor virtual surface after alignment, testing whether the complete m_s_obj.cpp class declaration changes VC5 front-end or register context for this direct-member body.
probe 34 liveness; result=MISMATCH; diff=1706; shape=72.69681742043551: Hypothesis 9: declare the four placement bound shorts at function scope before radius locals, matching the decompiler's long-lived sVar12..sVar15 order and testing whether ftol results recover original stack homes. [same emitted code as probe 33]
probe 35 liveness; result=MISMATCH; diff=1706; shape=72.69681742043551: Hypothesis 10: name the current row's RGE_Tile pointer before taking the first object-list slot, testing whether the original separate row/tile pointer topology emerges without raw cursor arithmetic.
probe 36 liveness; result=MISMATCH; diff=1706; shape=72.69681742043551: Hypothesis 11: split the current overlap row and first tile into named typed pointers before taking objects.list, testing whether VC5 emits the original separate tile-address and +0x10 LEA topology.
probe 37 layout; result=MISMATCH; diff=1706; shape=72.69681742043551: Hypothesis 12: hoist center, perimeter, request, flag, and radius declarations into one VC5-era function-scope block, with radius values after the short coordinates, to test declaration-order-driven ftol homes and prologue colors. [same emitted code as probe 36]
probe 39 context; result=MISMATCH; diff=1725; shape=72.20338983050847: Diagnostic owner wrapper replaced shared world/map vptr declarations with gap-only offset-equivalent classes. Full TU result stayed 1725-byte diff, 1888-byte compare, exact 0x44 frame and 11 ordered calls. No map/world context gain; variant not retained.
probe 43 baseline; result=MISMATCH; diff=1725; shape=72.20338983050847: Fresh canonical full-TU baseline before one shared declaration or source-order correction. [same emitted code as probe 42]
probe 44 layout; result=MISMATCH; diff=1725; shape=72.20338983050847: Use the authentic RGE_Tile terrain and border bitfields from the target's local declaration in the shared TU type.
probe 45 abi; result=MISMATCH; diff=1718; shape=72.81879194630872: Correct the shared RGE_Visible_Map::get_visible declaration to the PDB-mangled const int,int member surface used by the original direct call.
probe 47 context; result=MISMATCH; diff=1720; shape=73.38983050847457: Hypothesis 1: use one authentic player->world local, read terrain table before map, then preserve the original source-order setup reads.
probe 49 abi; result=MISMATCH; diff=1719; shape=65.59322033898304: Hypothesis 2: the original radius selection reads p7 at entry+0x1c; p8 is an unused incoming slot later reused for the visibility flag. Preserve that parameter meaning and source fault order.
probe 51 context; result=MISMATCH; diff=1720; shape=73.38983050847457: Hypothesis 3: direct member reads in authentic order, terrain table before map, without a world alias, should restore the original early read sequence and preserve fault order.
probe 53 liveness; result=MISMATCH; diff=1754; shape=72.74275979557069: Hypothesis 4: use direct moving-master radius field expressions in source order, avoiding unsupported cached radius aliases while retaining the true master owner and publication path.
probe 55 liveness; result=MISMATCH; diff=1733; shape=73.14189189189189: Hypothesis 5: model the proven moving-object list-field cursor as a typed node-slot pointer with the observed six-word tile stride, while preserving object fields, radius reads, publication, and cleanup.
probe 56 liveness; result=MISMATCH; diff=1706; shape=73.55932203389831: Hypothesis 6: keep one moving overlap row induction local with the proven list-field cursor, matching the original row reread and update lifetime without altering fault order.
probe 57 liveness; result=MISMATCH; diff=1778; shape=71.01694915254237: Hypothesis 7: cache the proven map row-offset member once inside the overlap scan so the moving-object row cursor and field reads match the original reload/store topology.
probe 58 liveness; result=MISMATCH; diff=1706; shape=73.55932203389831: Hypothesis 8: declare the moving-master radius temporaries in the outer function scope, then assign them at the proven field-read point, testing whether VC5 reuses dead incoming homes while preserving source-order x87 reads. [same emitted code as probe 56]
probe 59 liveness; result=MISMATCH; diff=1706; shape=73.55932203389831: Hypothesis 9: declare the moving-object column induction before the row/list cursor, testing the binary-proven EDI-column and EBP-list register orientation without aliases or volatility. [same emitted code as probe 58]
probe 60 liveness; result=MISMATCH; diff=1706; shape=73.55932203389831: Hypothesis 10: period-plausible register qualification of the first bound short may recover the original EDI x-min / EBP-this allocation without fake volatility or raw assembly. [same emitted code as probe 59]
probe 61 liveness; result=MISMATCH; diff=1743; shape=73.60406091370558: Hypothesis 11: replace the list-field pointer arithmetic with a natural contiguous tile pointer and tile++ while preserving the moving-object field owner and 0x18 stride.
probe 62 layout; result=MISMATCH; diff=1751; shape=73.60406091370558: Hypothesis 12: order the edge declarations as left, right, bottom, top to test the original x87 preload sequence while preserving the shipped axis transposition and epsilon tests.
probe 63 layout; result=MISMATCH; diff=1705; shape=73.55932203389831: Hypothesis 13: represent the two proven placement radii as one typed local pair to test the original contiguous x87 homes while preserving field ownership and branch order.
probe 64 liveness; result=MISMATCH; diff=1706; shape=73.55932203389831: Hypothesis 14: use a scope-local current-master receiver only in the moving-object scan, matching the original this reload before radius and publication checks without changing the ABI.
```
<!-- end-recovered:7e35c143c4985e016229 -->

<!-- recovered:5e96ce9f1dacb2bebd73 -->
### `b7fd2baf398f` `src/scratch/00453C40_check_placement.cpp:1-135`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00453C40 check_placement (1909B)
// m_s_obj.cpp, lines 778-1011
// RGE_Master_Static_Object::check_placement (vt[8], slot 0x20)
// Validates placement of an object/building at (x,y): map bounds, center and
// surrounding required terrain, terrain movement cost, elevation, visibility,
// and overlap with existing objects.
//
// ATTEMPT LOG:
// probe1 (baseline): full clean reconstruction from original asm/Ghidra. frame=0x44/0x44,
//   calls 11/11 aligned, CFG cond 82/82, jumps 5/5, returns 9/9 all match. positional diff
//   1820B (95%) because FPU scheduling + register alloc + statement order differ broadly.
//   code_size 1777 vs 1909 (-132).
// probe2 (layout): load world->terrains[terrain] before world->map to match orig load order
//   (orig: edx=[world+54h] terrains first, ebx=[world+28h] map). No diff change; first
//   mismatch moved +0x11 -> +0x16. Remaining gap is not load order but FPU scheduling.
// probe3 (semantic/structure): audited the executable instead of trusting the prior decompiler
//   scaffold. The placement bounds use x/y +/- radius with a -0.001f upper-edge epsilon; the
//   perimeter is top/right/bottom/left around [x_min..x_max]x[y_min..y_max]; elevation is a
//   switch over flag 1/2; and the object scan uses +/-3.0f tile bounds. Rebuilt those facts with
//   short coordinate locals, explicit float edge temps, and the binary's nested x-then-y loops.
// probe4 (behavior): the semantic reconstruction moved to frame 0x44, 1863B, 71.48% shape,
//   and 1762B strict diff. It also kept all 11 calls and 82/82 conditional CFG parity. The
//   prior 62% result was not pure FPU scheduling: center acceptance must not overwrite the
//   full placement box used by the later cost/elevation scan.
// probe5 (context): a temporary world pointer and declaration-order variant was worse; the
//   living source uses direct player->world chains. Probe6 (behavior) restored the 0x44 frame
//   after separating immutable box bounds from the four perimeter-edge coordinates.
// probe7/8 (context): direct chains were unchanged; terrain-table-before-map moved the strict
//   diff to 1761B but did not recover the original saved-register coloring.
// probe9 (liveness): split edge assignments worsened the emitted body; restored explicit float
//   initializers. Probe10 (control-flow): mutating the outer box cursor worsened shape/frame;
//   restored a separate x cursor. Probe11 (liveness): a left-only pre-test temp was worse.
// probe12 (control-flow): changed the overlap column pass to the packet-proven guarded do/while;
//   metrics stayed at 1761B/71.31% with frame 0x44. Kept because it reflects the original
//   do/while/pointer progression rather than the earlier broad decompiler-shaped scaffold.
//
// ===== worker_sa26 session (10 probes) =====
// probe14 (control-flow): radius selection arm order swapped to `if (p8 != 0) {construction}
//   else {radius}` — binary has construction INLINE with je to the radius path (PDB 819/820
//   inline, 824/825 at target). diff 1761->1758.
// probe15 (behavior): traced original FPU stack byte-by-byte: the beta binary has TRANSPOSED
//   axes in the placement box — test2 compares map_width <= (radius_y_value + y) - 0.001 and
//   test4 map_height <= (radius_x_value + x) - 0.001; x_max=(int)(ry+y-0.001), y_max=(int)(rx+x-0.001).
//   The earlier scratch had "corrected" the geometry; the original bug must be reproduced.
//   The perimeter column/row ranges and the +/-3 overlap scan confirm the transposition is
//   consistent (matters only when radius_x != radius_y). 1758->1757.
// probe16 (layout): added `RGE_Game_World* world = player->world;` (PDB lines 779/806/807).
//   codegen-neutral (0 bytes) but kept as line-accurate.
// probe17 (layout): edge declaration order left,bottom(x-derived),right(y-derived),top with
//   -0.001 in declarations — 1789 (worse; extra fxch in fstp sequence). restored.
// probe18 (restore): back to 1757.
// probe19 (layout): -0.001 epsilon moved INTO the bound tests (PDB line 833 attribution;
//   original applies the fsubs at the compare site) with left,bottom,right,top declaration
//   order — 1745. The fsubs then land in the compare blocks (rebuilt B004/B006) rather than
//   the first FPU block, so this is not a final shape, but the slot layout improved overall.
// probe20 (layout): anchored the top/bottom perimeter walk pointers at the terrain byte
//   ((unsigned char*)&row[col] + 5) so the +5 folds into the addressing LEA (Ghidra shows
//   pbVar17 anchored at field_0x5). 1745->1746 but shape 71.48->72.23 and the interior
//   elevation/visibility region became byte-shape exact. (bitfield &: first attempt failed C2104.)
// probe21 (layout): edge-coordinate assignment order per PDB: center path y_min,x_min,x_max,
//   y_max (854-855); non-center x_max,x_min,y_min,y_max (860-862). interior +14 but overlap
//   -17; net 1753. shape 72.33, exact-blocks 37.48.
// probe22 (liveness): staged master->radius_x/y/z into locals mrx/mry/mrz (original reuses the
//   dead [esp+74]/[6C]/[68] parameter homes and re-reads the slots in the distance test).
//   BIG win: 1753->1720, size gap -54->-11 (1898/1909), shape 72.65, resync 67.31.
// probe23 (layout): ry-first radius branch assignment (ry before rx) to break the join-store
//   coalescing — 1723 (worse). restored.
// probe24 (layout): -0.001 back in the edge declarations (left,right(y),top,bottom(x)) keeping
//   byte anchors + mrx staging — 1731. FPU block closer but center-check region worse; restored
//   the condition-form.
// probe26 (layout): one shared perimeter counter declared before the short box coordinates
//   (a natural declaration-order lead from the first-hunk evidence) changed only 14 emitted
//   bytes, with no positional or shape gain; restored the scoped counters.
// probe27-45 (worker_sa0966ff4c): completed 20 meaningful hypotheses. Register-qualified
//   map, a receiver alias, an early terrain-index local, expanded edge assignments, int box
//   bounds, direct node-slot aliases, split bound guards, cached map dimensions, alternate
//   edge declaration permutations, and cached map-row pointers either duplicated the basin
//   or worsened frame/shape. A bool spelling for the two terrain flags was codegen-neutral.
//   Direct map-first player->world expressions gave the best clean frontier: 1718B strict
//   diff, 72.82% shape, 0x44 frame, 11/11 calls, and 82/82 conditional CFG signals.
//   A four-way edge-order variant lab found no exact result; the original lbrt order remained
//   the smallest source and size basin. No exact result was reached.
// - Follow-up: a cursor from one tile's objects.list member to the next improved
//   the strict diff to 1706 bytes. The executable proves the +0x18 tile stride
//   and the +0x10 list-field anchor. The current source keeps this typed cursor.
//
// ===== worker_sa-fced9769 session =====
// BINARY NOTE: PDB order and live status selected check_placement at 00453C40.
// It is the first unowned normal m_s_obj.cpp sibling after setup at 00452B00.
// The owner is RGE_Master_Static_Object. The original range is 00453C40-004543B4.
// The target has 11 direct calls, 82 conditional signals, and nine returns.
//
// Hypotheses tested in this claim included world-read order, flag ownership,
// direct moving-master reads, typed row and list cursors, radius local scope,
// induction declaration order, register qualification, edge order, a radius
// pair, and a scoped current-master alias. World aliases and direct field reads
// were worse or neutral. A typed list-field cursor with a row induction local
// returned the best strict diff: 1706B, 1897/1909B, 73.56% shape, 38.16% exact
// blocks, 11/11 ordered calls, and 82/82 conditional signals. No exact result.
// The best source keeps the real moving-object fields, source read order, x87
// checks, object-id publication, and normal cleanup. It uses no inline assembly,
// fake volatility, config edits, or shared-header edits.
//
// LEFT IN SCRATCH: semantically faithful, period-plausible reconstruction reproducing the
//   original placement box. Best recorded state: 1706B strict diff, 67.89% resync similarity,
//   73.56% shape, 1897/1909 size, 590/587 instructions, 11/11 calls, 82/82 conditional CFG,
//   and 38.16% exact-block coverage. No exact result was reached.
// ABI audit: visible.cpp proves const get_visible(int, int). The standalone
//   owner declaration now uses that exact member surface. This changed no
//   strict metric, but it restores the direct target identity.
// NEXT LEADS:
//  * Original saves this in EBP and carries map in EBX; the clean source currently saves this
//    in ESI and leaves map in a local. This is a real declaration/liveness axis, not a reason
//    to add fake aliases or volatility. The interior/overlap regions now match shape exactly,
//    so the whole remaining diff is the early-region coloring + slot layout + the radius
//    branch join-store coalescing (original stores BOTH radius values in each branch; rebuilt
//    coalesces radius_y_value to the join because both branches leave it in EAX).
//  * The initial FPU topology is close in values/order but stack homes differ: original stores
//    left/right/top/bottom at [74]/[3c]/[2c]/[28]; current homes are compiler-selected. A later
//    worker should try a natural local declaration/order reproducer for the original's
//    `fld ry; fld rx; fadd x; fxch st2; fst [74]; fxch; fadd y` schedule (store left BEFORE
//    computing ry+y) — declaration-form -0.001 puts the fsubs in the first FPU block but
//    reorders the fst; condition-form matches the compare-site fsubs but defers them.
//  * Original overlap reuses the dead p10 home at [esp+7c] for the current row and keeps
//    overlap_x_min in edi (reloaded per row); current source keeps the row as a short local.
//    Verify whether a natural row-local declaration can recover that coalescing without
//    changing the proven unsigned-char parameter ABI.
// Context probe: an authentic owner-order wrapper with offset-equivalent,
// gap-only RGE_Game_World and RGE_Map declarations kept the 1725-byte current
// diff, exact 0x44 frame, and 11 ordered calls. Shared world/map vptr context is
// not the early prologue cause. The diagnostic variant was not retained.
// Shared-ABI correction: the original direct target is the const
// RGE_Visible_Map::get_visible(int, int) member. Restoring that declaration
// reduced the current full-TU drift from 1725 to 1718 bytes. It also reduced
// the size gap from 23 to 11 bytes without changing the 22 exact anchors.
```
<!-- end-recovered:5e96ce9f1dacb2bebd73 -->

<!-- recovered:8bd7d078dff4c2b6521f -->
### `b7fd2baf398f` `src/scratch/00453C40_check_placement.cpp:300-308`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // BINARY-PROVEN GEOMETRY: the original beta code swaps the coordinate
    // axes for the upper edges. The executable computes the four edges in
    // declaration order left, bottom(x-derived), right(y-derived), top, then
    // tests: left<0, width<=right-0.001, top<0, height<=bottom-0.001 (the
    // -0.001 inward epsilon is applied inside the bound tests). right is
    // Y-derived and bottom is X-derived (an original transposition bug,
    // relevant only when radius_x != radius_y). The perimeter scans bound
    // columns by [x_min..x_max] and rows by [y_min..y_max] where
    // x_max=(int)right and y_max=(int)bottom.
```
<!-- end-recovered:8bd7d078dff4c2b6521f -->

<!-- recovered:d9ff5c138af684a3e99e -->
### `b7fd2baf398f` `src/scratch/00453C40_check_placement.cpp:334-335`

Mapping: `exact`. historical standalone source path names this target VA.

```text
        // The center tile must be one of the requested terrain types. The
        // original converts y before x and reads the center only after bounds.
```
<!-- end-recovered:d9ff5c138af684a3e99e -->

<!-- recovered:07cfbf07cafc1fd23f76 -->
### `b7fd2baf398f` `src/scratch/00453C40_check_placement.cpp:362-364`

Mapping: `exact`. historical standalone source path names this target VA.

```text
        // Top edge (row y_min-1), columns x_min..x_max. The original anchors
        // the walk pointer at the terrain-type byte (+5), folding it into the
        // addressing LEA.
```
<!-- end-recovered:07cfbf07cafc1fd23f76 -->

<!-- recovered:848457490aab9f004549 -->
### `b7fd2baf398f` `src/scratch/00453C40_check_placement.cpp:486-488`

Mapping: `exact`. historical standalone source path names this target VA.

```text
                            // The original stages the three radii into local
                            // slots (reusing dead parameter homes) before the
                            // compares, then reuses them in the distance test.
```
<!-- end-recovered:848457490aab9f004549 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
