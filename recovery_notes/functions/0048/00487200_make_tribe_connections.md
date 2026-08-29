# Recovery journal: 00487200 `make_tribe_connections`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/rmm_shal.cpp`.
- PDB source: `C:\msdev\work\age1_x1\rmm_shal.cpp`.
- Earlier recovery note: `recovery_notes/rmm_shal_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:cc8d15a89d9f5840f8ac -->
### `d050eea3c` `src/rmm_shal.cpp:79-82`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 00487200 RGE_RMM_Shallows_Generator::make_tribe_connections
// PDB source lines 106-245, size 1172 bytes.
// The source preserves the current reviewed scratch reconstruction.
// Its scratch status and measured result remain unchanged by this move.
```
<!-- end-recovered:cc8d15a89d9f5840f8ac -->

<!-- recovered:a5cec1706dd74929461d -->
### `d050eea3c` `src/rmm_shal.cpp:210-210`

Mapping: `ambiguous`. comment lies after mapped function make_tribe_connections at old line 77.

```text
            // BINARY NOTE: This bound remains live for the outer row loop.
```
<!-- end-recovered:a5cec1706dd74929461d -->

<!-- recovered:ae3ef8c56a868b63dc85 -->
### `target-session` `build/target_sessions/00487200_make_tribe_connections.json:1-65`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=935; shape=61.12531969309463: Baseline current scratch: 1144 bytes, frame 0xDC, 935 differing bytes, 14/14 calls ordered; source already contains prior clean notes.
probe 2 behavior; result=MISMATCH; diff=997; shape=72.72727272727273: H1: Corrected random water-area bound to retain upper-y in end_x, compare lVar8 <= end_x, and restore lVar8 after push as original assembly shows. Tests source semantics and loop topology.
probe 4 abi; result=MISMATCH; diff=935; shape=61.12531969309463: H2: Replaced opaque random-map field types with period-supported canonical RGE_Map pointer, RGE_Tile row table, long dimensions, and typed parent. Tests class ownership/type context without changing body expressions.
probe 5 abi; result=MISMATCH; diff=935; shape=61.12531969309463: H3: Changed target parameter declarations from int to PDB-proven long. Tests signed-width ABI spelling while preserving body and canonical base field types. [same emitted code as probe 4]
probe 6 liveness; result=MISMATCH; diff=935; shape=61.12531969309463: H4 retry: Complete declaration-order/long-width test after aligning find_path output declaration with its PDB-proven long* surface.
probe 7 abi; result=MISMATCH; diff=934; shape=61.63682864450128: H5: Passed the stack's y-field address to init_stack/deinit_stack, matching the original LEA +4 relative to the pop head. Tests the binary-proven asymmetric helper address pattern.
probe 8 layout; result=MISMATCH; diff=931; shape=61.38107416879795: H6: Replaced raw 24-byte tile cursors with canonical RGE_Tile row ownership and typed tile indexing. Tests whether period layout names recover the repeated map access basin.
probe 9 layout; result=MISMATCH; diff=934; shape=61.63682864450128: H7: Kept typed RGE_Tile outer ownership but restored the inner scan's byte-offset cursor, matching the original +5/+0x18 addressing without compiler-generated division.
probe 10 control-flow; result=MISMATCH; diff=935; shape=60.61381074168798: H8: Reordered switch cases to the PDB line order 7,6,11,9,10,5,8,4. Tests compiler handler layout against the executable's source-line bands.
probe 11 layout; result=MISMATCH; diff=934; shape=61.63682864450128: H9: Removed the local search-map row alias and used the reviewed unsigned-char row field directly. Tests whether direct ownership changes the switch receiver schedule.
probe 12 context; result=MISMATCH; diff=939; shape=53.452685421994886: H10: Restored the neighboring same-TU virtual base surface and named RGE_Shallows_Info aggregate. Tests canonical inheritance/type context without changing proven offsets.
probe 13 liveness; result=MISMATCH; diff=934; shape=61.63682864450128: H11: Used the decompiler's otherwise-unmapped x local as the moving column coordinate, replacing the prior y alias. Tests natural coordinate naming and declaration-color pressure. [same emitted code as probe 11]
probe 14 liveness; result=MISMATCH; diff=1076; shape=61.49870801033592: H12: Assigned the initial destination coordinates directly into the live tx1/ty locals instead of staging through iVar2/iVar9. Tests whether this recovers the original pre-loop homes and load order.
probe 15 abi; result=MISMATCH; diff=934; shape=61.63682864450128: H13: Declared debug_rand with the observed external C cdecl surface, testing direct-call decoration and string-relocation codegen.
probe 16 variant; result=MISMATCH; diff=934; shape=61.63682864450128: H14: Replaced the first three random-area multiply-by-two expressions with explicit shifts, matching the original SHL instruction form. Tests arithmetic lowering independently of loop structure. [same emitted code as probe 15]
probe 17 liveness; result=MISMATCH; diff=935; shape=64.9616368286445: H15: Matched the decompiler's source-role evidence by carrying the first endpoint y through done and passing done to find_path, leaving end_y for the later water-area bound.
probe 18 liveness; result=MISMATCH; diff=935; shape=64.9616368286445: H16: Moved the coordinate locals before the random temporaries, following the decompiler's long x/y/ty2/end_x/tx1/end_y/ty/done/tx2 order. Tests local-home allocation for the initial endpoint block. [same emitted code as probe 17]
probe 19 control-flow; result=MISMATCH; diff=935; shape=65.47314578005115: H19: Removed the pop result temporary and used the typed pop_stack call directly as the while predicate. Tests the original TEST/JNE pop-loop topology against the prior CMP temporary form.
probe 20 abi; result=MISMATCH; diff=944; shape=59.07928388746803: H20: Applied the binary-proven asymmetric Map_Stack surface: helper head arguments use stack.y, while pop cost uses the stack base as float*. Removed the separate cost local.
probe 21 liveness; result=MISMATCH; diff=935; shape=65.47314578005115: H22: Moved the tx2 termination flag to the front of the scalar declaration sequence, testing whether its zero/store home can move from [esp+18] to the original [esp+2C]. [same emitted code as probe 19]
probe 22 behavior; result=MISMATCH; diff=996; shape=62.8992628992629: H23: Restored the binary-supported random-area bounds and lVar8 restoration after push. This fixes the prior known semantic defect: upper-y is retained in end_x and the outer loop compares against it.
probe 23 liveness; result=MISMATCH; diff=991; shape=63.05418719211823: H24: Removed the decompiler-only lVar8=done assignment after the inner push call, retaining the proven upper-bound loop. Tests whether VC5 naturally reloads the live row value across the call.
probe 24 abi; result=MISMATCH; diff=996; shape=68.55036855036855: H25: Isolated the pop head-address change while retaining the separate stack_cost output and push head. Tests the original pop-only asymmetric pointer evidence.
probe 25 abi; result=MISMATCH; diff=996; shape=68.55036855036855: H26: Extended the stack.y head address to all push_stack sites while keeping the separate cost output. Tests whether the helper family shares the original sentinel subobject.
probe 26 layout; result=MISMATCH; diff=996; shape=68.55036855036855: H27: Replaced the high-level zero loop with the decompiler-supported pointer/count loop and declared its natural pfVar7/iVar4 temporaries. Tests whether source loop ownership recovers terrain and frame placement.
probe 27 abi; result=MISMATCH; diff=991; shape=74.2014742014742: H28: Removed the separate cost home from the all-stack.y family and passed the stack base as the proven float output. Tests whether the frame can retain terrain at the original offset.
probe 28 liveness; result=MISMATCH; diff=991; shape=74.2014742014742: H29: Moved the in_zone scalar after the aggregate and terrain locals, testing whether one scalar lifetime was the four-byte local offset blocking the original terrain placement. [same emitted code as probe 27]
probe 30 liveness; result=MISMATCH; diff=991; shape=74.2014742014742: H30 source-role: restored the decompiler-supported moving y local and left x unmapped. Tests the original coordinate home and register topology without changing behavior. [same emitted code as probe 29]
probe 31 liveness; result=MISMATCH; diff=991; shape=74.2014742014742: H31 declaration order: moved tx2 after the coordinate locals, following the decompiler declaration family. Tests whether the tx2 home and stack/terrain offset shift recover the original first hunk. [same emitted code as probe 30]
probe 32 liveness; result=MISMATCH; diff=991; shape=74.2014742014742: H32 local recovery: removed the decompiler-unmapped x scalar while retaining moving y. Tests whether the unused declaration itself controls local-home allocation.
probe 33 liveness; result=MISMATCH; diff=991; shape=74.2014742014742: H33 declaration topology: restored the best historical scalar, coordinate, in_zone, stack, and terrain order while retaining current natural zeroing and typed stack alias. Tests declaration-driven home placement. [same emitted code as probe 32]
probe 34 abi; result=MISMATCH; diff=991; shape=74.2014742014742: H34 reviewed layout: changed Map_Stack::cost from int to the inventory-proven float type. Tests canonical field typing while preserving the 24-byte layout and alias call sites. [same emitted code as probe 33]
probe 35 layout; result=MISMATCH; diff=991; shape=74.2014742014742: H35 canonical tile layout: replaced the raw 24-byte tile overlay with the inventory-proven RGE_Tile member layout and direct terrain_type accesses. Tests whether proper ownership changes array lowering without changing offsets. [same emitted code as probe 34]
probe 36 layout; result=MISMATCH; diff=991; shape=74.2014742014742: H36 inner-scan ownership: removed the cached row and tile locals, repeating the binary-proven map-row expression for both terrain predicates. Tests the original duplicate row-pointer load and redundant read topology.
probe 37 layout; result=MISMATCH; diff=905; shape=75.0: H37 loop addressing: changed the water-area row lookup to the binary-proven byte-offset row-table form, keeping iVar2 and iVar9 as moving byte offsets. Tests removal of compiler-generated divisions and recovery of original inner-loop topology.
probe 38 abi; result=MISMATCH; diff=910; shape=69.84536082474227: H38 ABI control: added a separate stack_cost output for pop_stack while retaining the byte-offset row lookup. This deliberately tests the cost-output home effect; it is not a retention candidate if the proven stack-base output diverges.
probe 39 liveness; result=MISMATCH; diff=905; shape=75.0: H39 coordinate declaration order: swapped the y and ty2 declarations while preserving their proven semantic roles. Tests whether VC5 assigns the original [esp+10]/[esp+14] homes by declaration order. [same emitted code as probe 37]
probe 40 liveness; result=MISMATCH; diff=905; shape=75.0: H40 register-liveness: marked reused iVar2 as register, testing whether the binary-proven row-byte-offset carrier stays in a saved register through the water scan. [same emitted code as probe 39]
probe 41 abi; result=MISMATCH; diff=1072; shape=56.83453237410072: H41 width hypothesis: changed the decompiler-reported in_zone local to float. Tests the generated type against the observed integer-only clamp and loop compare; expected to reject if x87 code appears.
probe 42 layout; result=MISMATCH; diff=905; shape=75.0: H42 redundant-read topology: retained the row4 local for the first terrain test and repeated the proven row-table expression for the 0x16 test. Tests whether the original second row-pointer load is codegen-active.
probe 43 layout; result=MISMATCH; diff=909; shape=76.22739018087856: H43 tile-bitfield hypothesis: represented terrain_type and border_type as the reviewed bitfields and used a typed tile for the second inner predicate. Tests whether VC5 bitfield lowering explains the original duplicate row read.
probe 44 abi; result=MISMATCH; diff=905; shape=75.0: H44 decompiler-width hypothesis: narrowed iVar2 and iVar9 to their generated int types while retaining long coordinate state and the byte-offset scan. Tests whether these reused random/endpoint locals control frame and register colors. [same emitted code as probe 42]
probe 45 liveness; result=MISMATCH; diff=953; shape=69.72704714640199: H45 natural cursor naming: introduced a scoped row_offset byte cursor for the water-area row table instead of reusing random iVar2. Tests whether explicit cursor ownership recovers the original saved-register and frame topology.
probe 46 abi; result=MISMATCH; diff=905; shape=75.0: H46 tx2 width: narrowed the branch flag to int while retaining signed semantics. Tests whether its home and zero-register lifetime control the original +2C slot. [same emitted code as probe 44]
probe 47 abi; result=MISMATCH; diff=905; shape=75.0: H47 endpoint widths: narrowed the reused initial and outer-bound end_x/done locals to int, following generated iVar width evidence while preserving long path coordinates. [same emitted code as probe 46]
probe 49 context; result=MISMATCH; diff=1072; shape=56.354916067146284: Use canonical base/info/tile surfaces, PDB float in_zone, and typed map-row publication on stack drain.
probe 50 control-flow; result=MISMATCH; diff=1073; shape=55.39568345323741: Order the switch bodies as PDB lines 163-186: 7, 6, 11, 9, 10/5, and 8/4 fall-through.
probe 51 liveness; result=MISMATCH; diff=1011; shape=80.719794344473: Use the decompiler-proven integer comparisons of PDB float in_zone, allowing VC5 to retain its integer value.
probe 52 behavior; result=MISMATCH; diff=1017; shape=77.07808564231738: Retain the executable's integer in_zone path: no x87 or ftol calls exist despite the optimized PDB home type.
probe 54 behavior; result=MISMATCH; diff=1021; shape=70.99236641221374: Use the PDB homes directly: terrain base at -A0, stack at -B8, float output at -BC, done at -C4, and integer tx2 bound at -C0.
probe 55 liveness; result=MISMATCH; diff=978; shape=63.61323155216285: Restore the decompiler-proven endpoint lifetimes: point1 in end_x/done, point2 in retained scalar values, then reuse those homes after find_path.
probe 56 liveness; result=MISMATCH; diff=978; shape=63.61323155216285: Separate the pop cost output from the PDB in_zone declaration to test whether two proven scalar homes precede Map_Stack.
probe 57 control-flow; result=MISMATCH; diff=955; shape=62.086513994910945: Use the PDB line map's natural nested area loops at lines 214-217, with y1 and x1 as the row and column cursors.
probe 58 liveness; result=MISMATCH; diff=955; shape=64.8854961832061: Map PDB coordinate roles directly: x/y are current coordinates, x1/y1 are point1 and area cursors, and tx2/ty2 retain point2 before reuse as upper bounds.
probe 59 liveness; result=MISMATCH; diff=955; shape=64.8854961832061: Follow the decompiler and emitted homes: y is horizontal and x is vertical, so their address-taken pop homes match the shipped x/y coordinate slots. [same emitted code as probe 58]
probe 60 control-flow; result=MISMATCH; diff=950; shape=64.63104325699746: Use one PDB line-139 validation expression, then initialize the line-145 carried coordinates after the complete guard.
probe 61 liveness; result=MISMATCH; diff=955; shape=64.8854961832061: Validate the carried x/y values after target equality, then use those carried locals for the bounds guard.
probe 62 liveness; result=MISMATCH; diff=955; shape=64.8854961832061: Keep the PDB-era random result as one function-scope long across all four sites, matching the shipped shift/multiply schedule.
probe 63 control-flow; result=MISMATCH; diff=938; shape=75.38461538461539: Use a typed row-pointer cursor across the PDB lines 214-217 outer loop, preserving the proven row table without byte arithmetic.
probe 64 liveness; result=MISMATCH; diff=938; shape=78.71794871794872: Reuse end_x and done for point1 before their later area and termination roles, matching the shipped optimized local-home overlap.
probe 65 liveness; result=MISMATCH; diff=938; shape=78.71794871794872: Retain point2 in the decompiler-proven iVar2/iVar9 values, then reuse iVar2 at the random sites after target validation.
probe 66 liveness; result=MISMATCH; diff=938; shape=77.94871794871794: Assign the vertical carried coordinate before the horizontal coordinate to test the PDB x/y home order.
probe 67 liveness; result=MISMATCH; diff=936; shape=79.74358974358974: Restore the decompiler-proven tx2 termination flag, while keeping the random horizontal bound in a separate integer value and pop cost in PDB float in_zone.
probe 68 liveness; result=MISMATCH; diff=936; shape=79.74358974358974: Use PDB y1 for point1.y and its later area-row cursor lifetime, while end_x retains point1.x before its upper-bound reuse. [same emitted code as probe 67]
probe 69 control-flow; result=MISMATCH; diff=955; shape=67.0886075949367: Retest natural indexed area rows with the corrected tx2 termination and separate zone bound lifetimes.
```
<!-- end-recovered:ae3ef8c56a868b63dc85 -->

<!-- recovered:8ddbd57e11c29ffaa7ac -->
### `39e9afd59709` `src/scratch/00487200_make_tribe_connections.cpp:1-33`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00487200 make_tribe_connections
// rmm_shal.cpp lines 106-245

// Attempt log:
// - Baseline first-pass decompiler translation had exact size but 1153 differing bytes.
// - Correct map-row ownership and local stack size restored the 0xE0 frame and improved shape.
// - Switch order alone regressed; original fall-through cases 8->4 and 10->5 were required.
// - Canonical Map_Stack plus a single natural pop loop reached exact size and 964 differing bytes.
// - Calls remain 14/14 ordered and the current source keeps named map and stack ownership.
// - Paused: frame was 0xD8 versus 0xE0, with broad register and block-layout drift remaining.
// - Main-agent ABI audit restored typed Map_Stack helper calls and a separate
//   pop cost output. The frame improved to 0xDC and positional drift fell to 956 bytes.
// - Tried keeping the water-area row bound live across both natural loops; size grew
//   by 88 bytes and drift worsened, so restored the prior clean source.
// - Hoisted the initial y/ty2 carry before the bounds guard; this improved the
//   structural diff from 956 to 935 bytes and matched more loop blocks.
// - Reordered stack_cost before Map_Stack to model the original separate cost
//   home; VC5 kept the same frame and bytes, so the lead was rolled back.
// - Follow-up probes corrected the water-area upper bound and retained the
//   binary's stack.y helper surface. The clean bounded result is 1224 bytes,
//   frame 0xE0, shape 74.20%, and 991 differing bytes. The older 1144-byte
//   result had a known wrong outer-loop bound and is not the final behavior model.
// - A byte-offset row-table cursor reduced the result to 1172 bytes and 905
//   differing bytes. Main review rejected that metric-only cursor and kept
//   typed row ownership. The frame remains four bytes short without padding.
// - Binary assembly uses integer bounds for the random water-area loops;
//   changing in_zone from float to long removed an x87 sequence and restored
//   the 1172-byte size. The frame remains 0xDC versus the original 0xE0.
// - Repeating the inner water-tile member read improved resynchronization
//   (edit cost 621 versus 708) without changing the strict 906-byte drift.
// - A typed row-table pointer restored the 0xE0 frame but increased strict
//   drift and was rejected. Explicit pop-result, zero-local, declaration-order,
//   and next-row-local probes were neutral or worse and were restored.
```
<!-- end-recovered:8ddbd57e11c29ffaa7ac -->

<!-- recovered:922729c85dfcf0e00f2c -->
### `39e9afd59709` `src/scratch/00487200_make_tribe_connections.cpp:75-89`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // BINARY NOTE: The shipped caller passes the sentinel through stack.y.
// [non-comment lines omitted during migration]
    // Keep the first step coordinates live before the bounds guard. The
    // original loop carries these values across its back edge.
```
<!-- end-recovered:922729c85dfcf0e00f2c -->

<!-- recovered:9394f7b667acbf1f55a9 -->
### `39e9afd59709` `src/scratch/00487200_make_tribe_connections.cpp:138-139`

Mapping: `exact`. historical standalone source path names this target VA.

```text
            // Pop from stack and modify terrain tiles
            // BINARY NOTE: pop_stack receives stack.y, but its cost output aliases stack.
```
<!-- end-recovered:9394f7b667acbf1f55a9 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
