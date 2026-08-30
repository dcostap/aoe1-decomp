# Function notes: 0050FA90 `change_terrain`

Module notes: `decomp_notes/tmap_module.md`.

## Recovered attempt history

<!-- recovered:e7733de255dedd90e645 -->
### `target-session` `build/target_sessions/0050FA90_change_terrain.json:1-65`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=347; shape=84.02777777777777: Current clean scratch reconstruction: typed map tiles, terrain XOR, player notification, clipped 3x3 border refresh; 0x1c frame and three calls, but 12 bytes longer than oracle.
probe 2 liveness; result=MISMATCH; diff=347; shape=84.02777777777777: Added a short x0 alias and used it for the player notification and x clipping, testing whether the original early EDI x color and parameter-home reuse require a named coordinate. [same emitted code as probe 1]
probe 4 control-flow; result=MISMATCH; diff=421; shape=85.41666666666667: Matched the oracle's TEST current_player/JLE shape by spelling the lower validity bound as <= 0 instead of < 1.
probe 6 layout; result=MISMATCH; diff=347; shape=84.02777777777777: Tested the older raw byte-overlay ownership: unsigned-char row pointers, explicit 24-byte tile stride, and byte offsets 5/6. This is a codegen probe only; typed fields remain canonical unless evidence improves. [same emitted code as probe 2]
probe 8 variant; result=MISMATCH; diff=337; shape=82.63888888888889: Used direct typed map_row_offset[y][x].terrain access for the first tile instead of a named tile pointer, testing whether the oracle's saved tile pointer requires an explicit local.
probe 10 liveness; result=MISMATCH; diff=347; shape=84.02777777777777: Reordered coordinate local declarations to test whether VC5's saved-register and stack-home coloring follows the source declaration sequence. [same emitted code as probe 6]
probe 12 liveness; result=MISMATCH; diff=347; shape=84.02777777777777: Introduced a short y0 alias for the initial tile, first player notification, and row clipping. This tests the oracle's early EBX y color and later parameter-home reuse. [same emitted code as probe 10]
probe 14 abi; result=MISMATCH; diff=347; shape=82.63888888888889: Added the proven RGE_Map virtual destructor surface to test whether the missing base vptr context selects the oracle's prologue and register basin.
probe 15 abi; result=MISMATCH; diff=347; shape=84.02777777777777: Corrected the virtual RGE_Map layout to vptr + 4-byte gap, keeping map_width at +8 and map_row_offset at +8D8C; tested full base ABI context. [same emitted code as probe 12]
probe 16 liveness; result=MISMATCH; diff=337; shape=82.63888888888889: Used a local terrain-byte pointer for the initial terrain read/write, testing the oracle's retained tile-address register and byte store form. [same emitted code as probe 8]
probe 18 liveness; result=MISMATCH; diff=346; shape=84.02777777777777: Added explicit short x and int x/y aliases following the decompiler's distinct coordinate live ranges, then used narrow aliases for tests and widened aliases for indexing and calls.
probe 19 liveness; result=MISMATCH; diff=346; shape=84.02777777777777: Kept widened x1/y1 aliases for tile indexing and calls, but restored direct x parameter use for clipping predicates and endpoint assignment to test the original parameter register lifetime. [same emitted code as probe 18]
probe 20 control-flow; result=MISMATCH; diff=421; shape=85.41666666666667: Tested the positive validity guard (curr_player > 0 && curr_player < player_num) to match the oracle's TEST/JLE lower bound while preserving the same player selection behavior.
probe 22 behavior; result=MISMATCH; diff=338; shape=82.97872340425532: Tested keeping the pre-border byte unmasked and masking it only in the comparison. The oracle's masked old-border register before get_border_type favors the explicit mutation form.
probe 25 variant; result=MISMATCH; diff=368; shape=78.47222222222223: Tested proven short x and widened x/y aliases from the local Ghidra variable evidence while retaining typed map indexing and natural loops.
probe 27 liveness; result=MISMATCH; diff=368; shape=78.47222222222223: Tested declaration-initialized proven short x and widened x/y aliases before typed first-tile access; retained natural neighborhood loops. [same emitted code as probe 25]
probe 29 liveness; result=MISMATCH; diff=368; shape=78.47222222222223: Tested Ghidra-supported x/y aliases declared before typed map and player locals, retaining natural typed neighborhood updates. [same emitted code as probe 27]
probe 31 liveness; result=MISMATCH; diff=347; shape=84.02777777777777: Tested only proven short x alias and widened y index before typed first-tile access; retained direct formal x and natural loops. [same emitted code as probe 24]
probe 32 liveness; result=MISMATCH; diff=347; shape=84.02777777777777: Tested the binary-proven split x roles: formal x for zero guard, short x alias for decrement and upper bound, with typed map access. [same emitted code as probe 31]
probe 34 liveness; result=MISMATCH; diff=347; shape=84.02777777777777: Tested Ghidra-supported distinct formal x guard, short x bound alias, and widened typed map x/y indices to recover target register ownership. [same emitted code as probe 32]
probe 36 control-flow; result=MISMATCH; diff=345; shape=57.4468085106383: Tested guarded natural do-while row and column updates against the original nested-loop CFG; retained typed tile ownership.
probe 39 control-flow; result=MISMATCH; diff=350; shape=80.55555555555556: Swapped local coordinate parameter names to the binary-proven row/column roles: first argument drives map rows and outer loop, second drives tile columns and inner loop; test whether natural typed source recovers the oracle prologue and CFG.
probe 41 behavior; result=MISMATCH; diff=350; shape=80.55555555555556: Tested the period map.cpp row/column ownership indicated by set_terrain_absolute: first formal indexes map rows and outer loop, second formal indexes tile columns and inner loop, with calls ordered as row/column APIs. [same emitted code as probe 39]
probe 44 liveness; result=MISMATCH; diff=348; shape=69.50354609929079: Tested faithful Ghidra-style coordinate aliases: short x copy plus int x/y copies, with aliases used for initial tile, player notification, bounds, and loop indexing. This tests whether explicit source copies recover the original EDI/EBX parameter colors and early push order.
probe 46 control-flow; result=MISMATCH; diff=421; shape=85.41666666666667: Tested the original TEST/JLE lower-bound form directly: curr_player <= 0 instead of curr_player < 1. The executable uses TEST AX,AX followed by JLE, so this checks the source predicate that naturally lowers to that shape. [same emitted code as probe 4]
probe 48 layout; result=MISMATCH; diff=347; shape=84.02777777777777: Tested the exact donor's raw byte tile ownership and explicit 24-byte stride: unsigned-char tile cursor, offsets 5/6, and integer column scaling. This tests whether the target shares the donor's pointer-arithmetic codegen basin rather than the typed RGE_Tile basin. [same emitted code as probe 43]
probe 50 layout; result=MISMATCH; diff=337; shape=82.63888888888889: Tested direct typed map_row_offset[y][x].terrain for the initial terrain read/write. The original keeps the initial tile pointer only through that store and recomputes loop tiles later, so this is a natural lifetime reduction rather than raw-address scaffolding. [same emitted code as probe 16]
probe 51 control-flow; result=MISMATCH; diff=411; shape=84.02777777777777: Tested the combined binary-shaped predicate and direct initial map access: curr_player <= 0 gives TEST/JLE, while direct typed indexing keeps the initial tile lifetime short. This separates a proved branch form from the prior direct-index layout probe.
probe 53 liveness; result=MISMATCH; diff=347; shape=84.02777777777777: Tested period register storage on the two read-only coordinate parameters to probe whether source register hints recover the oracle's EBX/EDI coordinate colors and pre-map-save sequence. This is a compiler-input experiment, not retained without clear improvement. [same emitted code as probe 48]
probe 55 liveness; result=MISMATCH; diff=346; shape=84.02777777777777: Tested Ghidra-style x/y copies declared after the target locals, while retaining the natural mutable y outer loop. This isolates declaration placement and alias lifetime from the prior all-alias loop probe. [same emitted code as probe 19]
probe 57 liveness; result=MISMATCH; diff=346; shape=84.02777777777777: Tested reordered widened coordinate aliases: y int first, x int second, then x short, with aliases used for the initial map and bounds. This targets the oracle's reversed EBX(y)/EDI(x) entry colors without changing loop CFG. [same emitted code as probe 55]
probe 59 liveness; result=MISMATCH; diff=347; shape=84.02777777777777: Tested inner-loop declaration scope: declared col inside the outer row loop instead of at function scope. This tests whether the original col2 stack lifetime and register color are loop-local, while preserving the same natural CFG and field ownership. [same emitted code as probe 53]
probe 61 liveness; result=MISMATCH; diff=347; shape=84.02777777777777: Tested a scoped RGE_Map* base alias for the paired width/height clamps. The target retains this in ECX across both member loads, unlike the clean build's reload; this tests whether explicit base ownership recovers that natural register lifetime. [same emitted code as probe 59]
probe 63 control-flow; result=MISMATCH; diff=369; shape=75.17241379310344: Tested natural post-test bound mutation: increment x/y before assigning col_end/row_end. The oracle stores each bound only after its compare, while the clean col_end=x; if(++end) form emits an extra pre-compare store and a this reload.
probe 65 control-flow; result=MISMATCH; diff=375; shape=93.66197183098592: Tested conditional bound assignments: col_end = (x == width - 1) ? x : x + 1 and the matching row form. This tests whether VC5 emits the oracle's common post-branch bound store without mutating the formal parameters.
probe 66 liveness; result=MISMATCH; diff=375; shape=93.66197183098592: Starting from the exact-size conditional-bound basin, widened the two negative neighbor computations to explicit int arithmetic before narrowing to short. This tests the oracle's LEA EAX from sign-extended coordinate copies instead of DEC on the parameter register. [same emitted code as probe 65]
probe 67 behavior; result=MISMATCH; diff=375; shape=93.66197183098592: In the exact-size conditional-bound basin, removed the initial old_border temporary and used the direct terrain XOR member expression. This tests whether direct rereads recover the oracle's parameter-terrain load before the tile-byte load without changing behavior. [same emitted code as probe 66]
probe 68 liveness; result=MISMATCH; diff=375; shape=93.66197183098592: Tested a source-level new_terrain copy initialized before the first tile load. This probes whether an explicit input byte lifetime recovers the oracle's terrain-parameter load before the old tile-byte load. [same emitted code as probe 67]
probe 69 behavior; result=MISMATCH; diff=375; shape=93.66197183098592: Tested expanded XOR/AND assignment in the exact-size conditional-bound basin: load old terrain, mutate the byte parameter, mask, then store XOR old. This probes whether statement boundaries recover the oracle's byte schedule. [same emitted code as probe 68]
probe 70 liveness; result=MISMATCH; diff=375; shape=93.66197183098592: In the exact-size conditional-bound basin, split the initial tile pointer from the loop tile pointer. This tests whether a distinct initial pointer keeps EAX as the store base and recovers the oracle's [eax+5] old-terrain load. [same emitted code as probe 69]
probe 71 behavior; result=MISMATCH; diff=375; shape=93.66197183098592: Tested a real changed-byte intermediate in the exact-size bound basin: changed = terrain; XOR old_border; mask; store changed XOR old_border. This preserves the shipped byte transformation while probing a natural parameter-first evaluation shape. [same emitted code as probe 70]
probe 72 liveness; result=MISMATCH; diff=407; shape=95.74468085106383: Tested a branch-local widened x copy for col_start in the exact-size conditional-bound basin. The original uses LEA EAX from the sign-extended x value, while the current basin uses DEC EDI; this tests a natural scoped copy for that topology.
probe 73 liveness; result=MISMATCH; diff=407; shape=95.74468085106383: Final structural probe in this claim: added a branch-local widened y copy for row_start, matching the oracle's LEA EAX from sign-extended EBP rather than the current EBX decrement. Retain only if it improves the exact-size conditional-bound source.
probe 77 behavior; result=MISMATCH; diff=423; shape=91.03448275862068: Restored the decompiler-supported distinct widened x/y coordinates, direct terrain expression, TEST/JLE player guard, and post-compare bound mutation. This tests the original input-read order and coordinate lifetimes together.
probe 79 behavior; result=MISMATCH; diff=365; shape=94.4055944055944: Used the direct terrain member expression to preserve the executable's input-byte-first read order and changed the player lower guard to the observed TEST/JLE form.
probe 80 behavior; result=MISMATCH; diff=406; shape=73.04964539007092: Expanded the terrain byte transform by mutating the incoming byte parameter before its home is reused for border state. This tests the executable's input-byte-first read and shipped XOR order.
probe 81 liveness; result=MISMATCH; diff=365; shape=94.4055944055944: Used the existing byte local as the new-terrain accumulator. This preserves the input-byte-first fault state without mutating the formal parameter or adding a steering-only local. [same emitted code as probe 79]
probe 82 liveness; result=MISMATCH; diff=365; shape=94.4055944055944: Qualified the read/write terrain parameter as register. This tests whether its source storage class causes the input-byte-first load while preserving parameter-home reuse later. [same emitted code as probe 81]
probe 83 context; result=MISMATCH; diff=269; shape=95.83333333333333: Added the period-supported stdlib context that is required by an exact later tmap.cpp anchor. This tests authentic translation-unit front-end state on the unresolved input-byte load order.
probe 84 liveness; result=MISMATCH; diff=392; shape=99.29078014184397: Added scoped widened coordinate values at the first neighbor-bound use under the authentic stdlib context. This tests the oracle LEAs from the existing ESI/EBP widened coordinates.
probe 85 layout; result=MISMATCH; diff=392; shape=99.29078014184397: Changed the two lower neighborhood bounds to int, as proved by their full-width stack stores and Ghidra homes. This tests natural integer promotion without explicit coordinate aliases. [same emitted code as probe 84]
probe 86 liveness; result=MISMATCH; diff=392; shape=99.29078014184397: Qualified the read-only x parameter as register after proving int lower bounds. This tests whether VC5 selects the oracle's full-width incoming EDI load without changing coordinate semantics. [same emitted code as probe 85]
probe 87 liveness; result=MISMATCH; diff=392; shape=99.29078014184397: Added the decompiler-supported short x copy beside the widened x value and used it for the lower guard and upper result. This tests the oracle's full-width formal load plus distinct narrow lifetime. [same emitted code as probe 86]
probe 88 control-flow; result=MISMATCH; diff=392; shape=99.29078014184397: Declared each int lower bound at its one-line conditional initializer, matching the PDB line bands 291-292 and the decompiler's full-width homes. This tests declaration timing and branch topology together. [same emitted code as probe 87]
probe 89 context; result=MISMATCH; diff=392; shape=99.29078014184397: Restored the authentic polymorphic RGE_Map prefix under the now-proved stdlib context. This tests whether the PDB owner surface selects the remaining full-width coordinate load and border schedule. [same emitted code as probe 88]
probe 90 liveness; result=MISMATCH; diff=392; shape=99.29078014184397: Restored the decompiler's exact narrow-x, widened-y, widened-x declaration order and used each value for its proved role. This tests the oracle's full-width loads and lower-bound LEAs as one natural lifetime model.
probe 91 liveness; result=MISMATCH; diff=394; shape=99.29078014184397: Moved the old-border low-nibble reduction after get_border_type in source. The value remains in saved EBX, while VC5 can schedule the mask in the oracle's final pre-call slot.
probe 92 behavior; result=MISMATCH; diff=381; shape=95.8041958041958: Expressed the old low nibble only where the post-call comparison consumes it. This tests whether VC5 naturally prepares the saved-byte mask in the oracle's pre-call slot.
probe 94 context; result=MISMATCH; diff=392; shape=99.29078014184397: Replaced duplicated target-local classes with canonical tmap_context.h before grouped owner test; preserves input-first transform, writes, calls, and PDB owner ABI. [same emitted code as probe 93]
probe 95 context; result=MISMATCH; diff=392; shape=99.29078014184397: Added real exact 0050F410 constructor owner before 0050F860 and targets in the PDB-ordered wrapper; canonical virtual map surface preserves input-first behavior and +8/+C/+8D8C. [same emitted code as probe 94]
probe 97 context; result=MISMATCH; diff=392; shape=99.29078014184397: Fresh grouped check: src/tmap_tu.cpp includes real PDB-ordered owners 0050F410, 0050F760, 0050F7A0, 0050F7B0, 0050F7C0, 0050F7F0, 0050F800, 0050F860, then 0050F8D0 and this owner. With /nologo /c /O2 /Oy /GX, owner symbol matches PDB and output remains 428B/392-diff; grouped context does not select the original EDI dword load. [same emitted code as probe 96]
probe 101 liveness; result=MISMATCH; diff=392; shape=99.29078014184397: Test a natural int x_value alias at the initial tile lookup to explain the oracle's full incoming x load. [same emitted code as probe 100]
probe 102 layout; result=MISMATCH; diff=269; shape=97.87234042553192: Test the source-donor short lower-bound locals against the current int-bound reconstruction; binary stack homes will decide retention.
probe 104 baseline; result=MISMATCH; diff=392; shape=99.29078014184397: Fresh Phase 4 baseline after prior-results review; authentic tmap.cpp wrapper and conditional-bound source retained. [same emitted code as probe 103]
probe 105 abi; result=MISMATCH; diff=392; shape=99.29078014184397: Test genuine int copies of both short coordinate formals at the initial typed tile lookup. This targets the oracle's dword incoming x load while retaining canonical typed ownership. [same emitted code as probe 104]
```
<!-- end-recovered:e7733de255dedd90e645 -->

<!-- recovered:1c0f170fdcbda6113a90 -->
### `7219a9ef8fce` `src/scratch/0050FA90_change_terrain.cpp:1-76`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0050FA90 change_terrain (427B)
// tmap.cpp
//
// Attempt log:
// baseline: clean reconstruction from the tmap.cpp packet and the exact
// set_terrain_absolute donor's tile/XOR ownership.
// probes 2-7: raw byte addressing, parameter-home cursor reuse, border-nibble
// scheduling, and packet-local aliases were tested; the typed/raw structure
// stabilized at an exact 0x1c frame with three correctly aligned calls.
// probes 8-9: <=0 current-player spelling and alias declaration order changed
// branch/layout families without resolving the saved-this/top scheduling gap.
// fresh pass: typed RGE_Tile fields and a separate inner col cursor preserved
// the best structural basin (347 differing bytes, 0x1c frame, 3 aligned calls).
// Live initial x/y aliases and a retained map-row alias were duplicates or
// broader. A terrain-byte pointer moved the metric to 337 but was restored as
// unsupported scheduling scaffolding. The positive player-validity predicate
// was a duplicate of the older 421-byte basin and was restored.
// shardA4-50FA90-r1: declaration-initialized the first typed tile, but VC5
// emitted the same 439-byte basin; restored to the clean assignment form.
// shardA4-50FA90-r1: used the direct terrain XOR expression from the exact
// map donor; VC5 again emitted the same basin, so kept the named old byte.
// shardD10_50FA90: gave RGE_Player its canonical polymorphic surface while
// preserving diam_tile_list at +0x6C for the typed notification call; this
// was a codegen duplicate, so restored the narrow local surface.
// shard-dd8102ca: direct typed map indexing and a terrain-byte pointer reduced
// strict diff to 337, but worsened the block shape and were restored. Widened
// x/y aliases changed only clipping LEAs. A full RGE_Map vptr surface was a
// codegen duplicate. Keeping old_border masked before get_border_type matched
// the oracle's live-byte ordering better than a late mask.
// left in scratch: canonical neighborhood behavior and field ownership are
// reconstructed; remaining drift is VC5 prologue/register scheduling. The
// rebuilt body remains 12 bytes longer than the 427-byte oracle.
// sa-44c7d2a6-r1: local Ghidra evidence supports distinct narrow and widened
// coordinate lives, but typed alias variants were duplicates or worse. A
// guarded do-while rewrite changed the CFG and frame, so the natural for
// loops remain authoritative. The unresolved gap is structural codegen only.
// sa-956e4590-r1: verified the target's row/column roles against the original
// map access and tested swapped parameter naming and coordinate expressions;
// both emitted the same or worse nonexact structural basin. Restored the
// pinned natural map_row_offset[y] + x reconstruction for final validation.
// sa-961a69cd-r1: tested the original bound-store topology. The clean
// col_end=x; if (x != width-1) ++col_end form emitted two pre/post stores and
// a 439-byte body. Conditional bound assignments emitted the original
// common post-branch stores, exact 427-byte size, 142 instructions, and
// 93.66% shape similarity. Retained the conditional form as the best natural
// structural reconstruction. Direct/raw tile forms, coordinate aliases,
// register hints, and loop-scope changes were duplicates or worse.
// Earlier accepted-drift audit: do not promote the old source. It read the
// external tile byte before the incoming terrain byte and changed fault state.
// sa-557c93eb-r1: the exact later tmap.cpp stdlib context plus a natural byte
// accumulator recovered the executable's input-byte-first terrain transform.
// The first 0x88 bytes then matched exactly. Binary stack homes prove that
// col_start and row_start are int values. Restoring those widths also recovered
// every neighbor-bound block and both lower-bound LEAs. The remaining basin is
// one byte longer: VC5 reads x into DI, while the executable reads the complete
// incoming dword into EDI. Short lower bounds restore that load but lose the
// proved int-bound LEA. Scoped aliases, register hints, declaration timing,
// and the polymorphic map prefix were duplicates or worse. The retained source
// preserves the executable's tile-fault read order and all map writes/calls.
// sa-13047c13-r1 grouped context: the owner-include wrapper compiled this
// owner after 0050F8D0 in PDB order with /O2 /Oy /GX. Exact sibling anchors
// 0050F410, 0050F760, 0050F7A0, 0050F7B0, 0050F7F0, 0050F800, and 0050F860
// stayed exact in fresh standalone checks. The grouped owner symbol is
// PDB-qualified, but the target remains 428 bytes with a 392-byte diff. The
// grouped context does not recover the original EDI dword load.
// sa-7e83054e-r1 fresh context gate: module tmap.cpp, source band 264-314,
// owner TRIBE_Map, address sequence follows 0050F8D0, and exact wrapper
// anchors through 0050F860 are proved by the PDB line map and grouped checks.
// The copied prior journal rejects equivalent int-coordinate alias forms, so
// they were not repeated. The remaining drift is the original dword x load
// versus VC5's short load and the later byte-store schedule.
// sa-11e4b4c9-r1 captain validation: the fresh dossier confirms module tmap.cpp,
// band 264-314, TRIBE_Map ownership, and the address sequence above. Wrapper
// anchors remain exact. Baseline is 428 rebuilt bytes versus 427, with 392
// strict differing bytes, 3 ordered calls, and one boundary escape. The clean
// source is restored; the dword x load and byte-store schedule remain open.
```
<!-- end-recovered:1c0f170fdcbda6113a90 -->

## Worker updates

### wave21-change-terrain-cleanup

- Removed only the dead initial `old_border = terrain` assignment in `src/tmap.cpp`.
- Retained the canonical typed `old_border = tile->terrain_type` assignment, unchecked initial tile access, row-major closure, border comparison order, and all three calls.
- Focused check: rebuilt 428 bytes versus the 427-byte original; frame `0x1C`, 141 instructions, 100.00% shape, 100.00% ordered calls, and 394 differing bytes. The owner symbol matches. The first strict mismatch is offset `+0x11`; the one-byte size drift remains.
- The cleanup changed 18 bytes in two spans. It improved block coverage to 100.00% but increased strict diff by 2 bytes from the clean checkpoint. This is a scratch result, not an exact match.
- Registered `tmap_cpp` neighbor audit completed in `build/audits/workers/wave21-change-terrain-cleanup/tmap_cpp/report.txt`. All 16 registered exact neighbors remained `MATCH` with zero new diff. The target owner matched; its grouped result remained a 394-byte mismatch with the original-boundary issue.
