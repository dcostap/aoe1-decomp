# Function notes: 0046D280 `passable`

Module notes: `decomp_notes/pathsys_module.md`.

## Recovered attempt history

<!-- recovered:166c63b39d33b5ff4776 -->
### `target-session` `build/target_sessions/0046D280_passable.json:1-47`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=837; shape=66.27218934911242: Baseline current typed reconstruction before new hypotheses.
probe 2 liveness; result=MISMATCH; diff=842; shape=64.17910447761194: Hypothesis 2: use an int success flag because original initializes and tests the dead checkObjects home as a dword.
probe 4 control-flow; result=MISMATCH; diff=837; shape=66.27218934911242: Hypothesis 3: remove the packed-byte temporary and keep the direct obstruction indexed expression, matching the original repeated cursor arithmetic. [same emitted code as probe 1]
probe 5 liveness; result=MISMATCH; diff=837; shape=66.27218934911242: Hypothesis 4: declare all footprint integer bounds before assignment to reproduce original long-lived parameter-home and register allocation bands. [same emitted code as probe 4]
probe 6 liveness; result=MISMATCH; diff=830; shape=67.95252225519287: Hypothesis 5: scope tileOffset inside the positive row guard so VC5 cannot hoist its computation before the observed min/max test.
probe 7 liveness; result=MISMATCH; diff=830; shape=67.95252225519287: Hypothesis 6: lift terrain to a function-scope int local, matching the original byte store then dword reload at stack home -0x4. [same emitted code as probe 6]
probe 8 liveness; result=MISMATCH; diff=840; shape=68.04733727810651: Hypothesis 7: cache currentTerrainTable inside each tile test to force the original terrain-table load before terrain exception checks.
probe 9 layout; result=MISMATCH; diff=829; shape=73.45132743362832: Hypothesis 8: model the terrain byte as uchar, matching the original byte extraction and later zero-extension.
probe 10 liveness; result=MISMATCH; diff=829; shape=73.45132743362832: Hypothesis 9: move the uchar terrain declaration before footprint integers, testing declaration-order control of the original -0x4 terrain home. [same emitted code as probe 9]
probe 11 liveness; result=MISMATCH; diff=960; shape=64.39169139465875: Hypothesis 10: use direct master radius member expressions instead of cached radius locals, testing the source load schedule around the first footprint bound.
probe 12 liveness; result=MISMATCH; diff=829; shape=73.45132743362832: Hypothesis 11: scope uchar terrain inside the tile guard after tileOffset, testing whether VC5 assigns target terrain home -0x4 and tileOffset -0x8. [same emitted code as probe 10]
probe 13 liveness; result=MISMATCH; diff=1019; shape=71.9298245614035: Hypothesis 12: reverse radius local declaration order to test whether VC5 assigns radiusY to target stack home -0x1c.
probe 14 liveness; result=MISMATCH; diff=829; shape=73.45132743362832: Hypothesis 13: declare maskA before maskB, testing register/load order against original maskB-in-EAX then maskA-in-EBX sequence. [same emitted code as probe 12]
probe 15 liveness; result=MISMATCH; diff=849; shape=71.09144542772862: Hypothesis 14: use an int foundBlockingGroup in the uchar-terrain basin, testing the original dword zero/test tail without losing the frame.
probe 16 layout; result=MISMATCH; diff=829; shape=73.45132743362832: Hypothesis 15: write computed xMin and yMax through proven dead float parameter homes, testing whether explicit home reuse reproduces target entry-relative stores. [same emitted code as probe 14]
probe 17 liveness; result=MISMATCH; diff=834; shape=74.2603550295858: Hypothesis 17: cache terrainTable inside the tile guard while retaining uchar terrain, testing whether this basin recovers target pointer-before-exception scheduling.
probe 18 liveness; result=MISMATCH; diff=834; shape=74.2603550295858: Hypothesis 18: make tileOffset a function-scope local assigned inside the row guard, testing stack-home swap with uchar terrain. [same emitted code as probe 17]
probe 19 layout; result=MISMATCH; diff=844; shape=66.86217008797654: Hypothesis 19: use typed row indexing for the first tile instead of char-pointer plus tileOffset, testing whether VC5 recovers original row/stride lowering.
probe 20 control-flow; result=MISMATCH; diff=782; shape=74.04129793510324: Hypothesis 20: test table-threshold first, then terrain exceptions, because original loads and begins FPU compare before exception branches.
probe 21 liveness; result=MISMATCH; diff=832; shape=69.91150442477876: Hypothesis 21: materialize terrain table value before the exception guard while keeping source guard order, testing target's fld-before-exception-branch schedule.
probe 22 control-flow; result=MISMATCH; diff=805; shape=64.91228070175438: Hypothesis 22: permute terrain guard to exception2, table threshold, exception1, testing compiler schedule around the target's two exception branches.
probe 23 control-flow; result=MISMATCH; diff=782; shape=74.04129793510324: Hypothesis 23: nest exception checks inside the table-threshold guard, testing whether target's FPU-first path came from nested source control flow. [same emitted code as probe 20]
probe 24 layout; result=MISMATCH; diff=782; shape=74.33628318584071: Hypothesis 24: make local_14 signed int because target general scan uses SAR for col>>2, while uint source emitted SHR.
probe 25 liveness; result=MISMATCH; diff=793; shape=67.45562130177515: Hypothesis 25: split signed byteOffset and shiftIndex locals before the obstruction test, testing target ECX/SAR and EBX/AND register roles.
probe 26 liveness; result=MISMATCH; diff=782; shape=74.33628318584071: Hypothesis 26: assign signed col directly to signed local_14, removing the stale unsigned cast before the SAR-backed obstruction index. [same emitted code as probe 24]
probe 27 layout; result=MISMATCH; diff=793; shape=67.45562130177515: Hypothesis 27: name the per-row obstruction base before byte indexing, matching target's separate row stride and col/4 address terms. [same emitted code as probe 25]
probe 28 liveness; result=MISMATCH; diff=782; shape=74.33628318584071: Hypothesis 28: name mapByte and shift temporaries to preserve map-load-before-shift-load source evaluation in the general obstruction scan. [same emitted code as probe 26]
probe 30 liveness; result=MISMATCH; diff=1016; shape=64.70588235294117: Hypothesis 30: retain only radiusX local and use direct radiusY members, testing source ownership of the target radiusY spill.
probe 31 liveness; result=MISMATCH; diff=782; shape=74.33628318584071: Hypothesis 31: restore declaration-with-initializer scopes for footprint locals, testing whether target parameter-home reuse depends on declaration timing. [same emitted code as probe 29]
probe 32 liveness; result=MISMATCH; diff=782; shape=74.33628318584071: Hypothesis 32: inline the four radius-to-tile conversions while retaining xTile/yTile, testing whether target lacks named radius-result locals. [same emitted code as probe 31]
probe 33 context; result=MISMATCH; diff=782; shape=74.33628318584071: Hypothesis 33: restore period math.h context for floor declarations, testing whether standard header state selects the target VC5 basin.
probe 34 control-flow; result=MISMATCH; diff=829; shape=73.74631268436578: Hypothesis 34: preserve exception-first semantics as nested guards while testing whether VC5 still hoists the terrain FPU load.
probe 36 liveness; result=MISMATCH; diff=782; shape=74.33628318584071: Hypothesis 1: reorder footprint bound declarations to put yMin, xMin, yMax, xMax before the x/y tile temporaries, testing target parameter-home reuse without changing bound evaluation. [same emitted code as probe 35]
probe 38 liveness; result=MISMATCH; diff=796; shape=69.76047904191617: Hypothesis 2: make terrain a function-scope unsigned int, matching the decompiler's carried terrain value and testing whether its byte store moves to the target -0x4 home.
probe 40 layout; result=MISMATCH; diff=856; shape=57.48502994011976: Hypothesis 3: use typed row indexing (map_row_offset[row] + minX) instead of a named byte-offset cursor, matching the target's row/stride address form and testing the redundant xMin preload.
probe 42 liveness; result=MISMATCH; diff=1024; shape=72.3342939481268: Hypothesis 4: declare radiusY before radiusX while retaining use order, testing whether VC5's local slot assignment moves the target radiusY spill from -0x10 to -0x1c.
probe 44 control-flow; result=MISMATCH; diff=782; shape=75.51622418879056: Hypothesis 5: reverse the first two fast-path overlap predicates to xMin > maxTarget.x and yMin > maxTarget.y, matching the target's compare-register/branch polarity while preserving behavior.
probe 45 layout; result=MISMATCH; diff=788; shape=75.58823529411765: Hypothesis 6: replace the fast-path local obstruction cursor with direct typed obstructionValue indexing, testing whether VC5 emits the target memory-test plus row-stride topology.
probe 47 liveness; result=MISMATCH; diff=788; shape=75.58823529411765: Hypothesis 7: declare each fast-path row counter before its obstruction cursor, matching target pointer/counter register roles without changing the scan.
probe 49 liveness; result=MISMATCH; diff=833; shape=71.976401179941: Hypothesis 8: initialize terrain-scan tile bounds in target-like order maxX, minX, maxY, minY, testing the observed target parameter-home and register setup sequence.
probe 51 liveness; result=MISMATCH; diff=782; shape=75.51622418879056: Hypothesis 9: make the byte terrain temporary function-scope, matching the decompiler's carried uVar9 lifetime and testing the target -0x4 stack home. [same emitted code as probe 44]
probe 52 liveness; result=MISMATCH; diff=782; shape=75.51622418879056: Hypothesis 10: reuse one function-scope obstruction cursor across the mutually exclusive fast loops, matching the decompiler's single puVar13 and testing target pointer register coloring. [same emitted code as probe 51]
probe 53 liveness; result=MISMATCH; diff=782; shape=75.51622418879056: Hypothesis 11: declare shift before mapByte but assign mapByte first, testing whether local declaration order forces target's map-byte spill and shift-load order. [same emitted code as probe 52]
probe 54 control-flow; result=MISMATCH; diff=799; shape=74.34402332361516: Hypothesis 12: mirror the decompiler's packed scan with one carried local_14 column and explicit rowBase cursor, testing target loop rotation and row-stride ownership.
probe 56 layout; result=MISMATCH; diff=699; shape=76.03550295857988: Hypothesis 13: materialize maskIndex *= 2 before loading the two mask words, testing target's explicit shift-plus-scale-4 address lowering.
probe 57 liveness; result=MISMATCH; diff=699; shape=76.03550295857988: Hypothesis 14: make packed-scan mapByte and shift function-scope byte temporaries, testing whether their carried homes reproduce target's map-byte spill. [same emitted code as probe 56]
probe 58 layout; result=MISMATCH; diff=999; shape=73.51190476190476: Hypothesis 15: remove named xTile/yTile and use four direct scaled-coordinate bounds, testing whether VC5 reuses dead parameter homes while preserving the six target ftol calls.
```
<!-- end-recovered:166c63b39d33b5ff4776 -->

<!-- recovered:f9d92eb5519383b3c1e9 -->
### `056a20c24f68` `src/scratch/0046D280_passable.cpp:1-50`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0046D280 PathingSystem::passable(RGE_Moving_Object*, float, float, int)
// pathsys.cpp lines 2049-2217 (1207B)
//
// Attempt log:
// - Replaced the former 128-byte placeholder with the packet-supported typed
//   terrain/map/obstruction reconstruction.  The executable uses the moving
//   object's master radius and terrain table, four sub-tile footprint bounds,
//   optional terrain-row scanning, temporary obstruction-map removal, the
//   short-row mask fast path, and the general packed obstruction scan.
// - The source deliberately uses named RGE_Map/RGE_Tile/RGE_Static_Object
//   ownership and ordinary casts/loops; the original executable remains the
//   behavior oracle for the still-unmatched FPU expression grouping.
// - Final bounded pass: the 11 direct calls and their order are aligned,
//   including both addToObstructionMap cleanup tails.  The remaining drift is
//   the VC5 local/frame/FPU grouping and the large scan CFG (rebuilt 1076B,
//   frame 0x18 versus target 1207B, frame 0x20); this is left as a readable
//   reconstruction rather than padded or volatile compiler steering.
// - Probe 12 split each footprint bound into ordinary multiply, subtraction,
//   and -400 statements.  It improved resync similarity but worsened strict
//   diff by 7 bytes, so restore the validated typed reconstruction.
// - Structural follow-up: split the fast obstruction scan into the original
//   zero-mask and two-word-mask loops, with the DAT_00584F24 word loaded first.
//   This improved the structural diff from 1016 to 1003 bytes.
// - Kept explicit scaled tile variables and bound subtraction statements.
//   The rebuilt size moved from -131 to -10 bytes, with 66.27% shape match.
// - Named the fixed tile-row byte offset used by the terrain scan.  The best
//   restored checkpoint is 837 bytes of positional diff, frame 0x1C, and
//   9.88% exact-block coverage; the remaining gap is stack-home/CFG layout.
// - Follow-up probes 2-34 tested flag width, terrain local width/scope,
//   declaration order, tile-pointer forms, guard nesting/order, radius forms,
//   mask order, signed packed indices, and math-header context.  Most changes
//   were duplicate compiler basins or worse.  The retained basin uses a byte
//   terrain local, a signed packed index, a table-threshold-first terrain guard,
//   and the natural typed row/tile and split mask loops.
// - Best current clean reconstruction: 1200 rebuilt bytes, frame 0x20,
//   76.04% shape similarity, 699 positional diff bytes, 22.46% exact-block
//   coverage, and all 11 direct calls aligned.  Reversing the first two fast
//   overlap predicates to match the target compare polarity improved shape.
// - A distinct source improvement is `maskIndex *= 2` before the two mask
//   loads.  It recovers the target's explicit shift and scale-4 address form.
//   It reduced positional diff from 782 to 699 and closed the size gap to 7.
//   Function-scope byte temporaries and one obstruction cursor were natural,
//   target-supported tests.  They duplicate the same emitted code.
// - Tested bound declaration order, unsigned terrain scope, typed row indexing,
//   radius order, fast cursor declaration order, tile-bound order, and a
//   carried general-scan row cursor.  These were worse or duplicate basins.
// - The unresolved gap is source-level VC5 register/home allocation in the
//   footprint prelude and packed obstruction scan.  The original reloads
//   xMin, yMin, and xMax through dead parameter homes.  Current typed source
//   preserves the proven behavior and call set without volatile or assembly.
```
<!-- end-recovered:f9d92eb5519383b3c1e9 -->
