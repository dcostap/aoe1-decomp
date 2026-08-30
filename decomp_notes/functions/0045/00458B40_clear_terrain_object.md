# Function notes: 00458B40 `clear_terrain_object`

Module notes: `decomp_notes/map_module.md`.

## Recovered attempt history

<!-- recovered:f6a5913fd1b37b253fca -->
### `target-session` `build/target_sessions/00458B40_clear_terrain_object.json:1-75`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=332; shape=75.38461538461539: Current clean typed reconstruction before new probes; establish baseline metrics and call set.
probe 2 variant; result=MISMATCH; diff=332; shape=75.38461538461539: Collapsed current_node alias to test whether direct node member access recovers target ECX object and EBX map coloring. [same emitted code as probe 1]
probe 4 variant; result=MISMATCH; diff=331; shape=75.38461538461539: Widened result accumulator to int with a short return cast, testing whether VC5 assigns the long-lived result to EBP while preserving the proven return width.
probe 6 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Removed the named object_id local and used the proven master_obj->id expression directly, testing whether VC5 keeps the AX/EAX value and recovers target comparison and result liveness. [same emitted code as probe 2]
probe 8 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Removed the named master_obj alias while retaining object_id, testing the adjacent create_terrain_object source shape and direct master-member placement call. [same emitted code as probe 6]
probe 10 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Moved result declaration after all object locals while keeping its pre-call initialization, testing declaration-order register allocation for target EBX map and EBP result. [same emitted code as probe 8]
probe 12 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Combined the adjacent create_terrain_object cleanup shape: no current_node or master_obj aliases, direct node walk and direct master-member access. [same emitted code as probe 10]
probe 14 variant; result=MISMATCH; diff=332; shape=75.38461538461539: Applied register to the short result local as a focused compiler-input probe for the target EBP result allocation; retain only if binary evidence supports it. [same emitted code as probe 12]
probe 16 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Removed both object_id and master_obj locals, testing fully direct master-member expressions for target EBP result reuse and ECX object retention. [same emitted code as probe 14]
probe 18 control-flow; result=MISMATCH; diff=314; shape=72.64957264957265: Changed only the inner terrain-type scan from nested if/do-break to a guarded while, directly testing the target's single compare/backedge topology.
probe 20 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Reordered locals to the adjacent create_terrain_object pattern: result, node, object, object_id, object_type, master alias. [same emitted code as probe 16]
probe 21 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Delayed result=-1 until immediately before get_terrain, testing whether declaration versus initialization site selects the target register lifetime. [same emitted code as probe 20]
probe 23 variant; result=MISMATCH; diff=332; shape=75.38461538461539: Applied register hints to the pointer locals as a diagnostic allocator probe for target node/object/master saved-register colors; not retained without binary support. [same emitted code as probe 21]
probe 25 context; result=MISMATCH; diff=332; shape=75.38461538461539: Restored the reviewed map.cpp virtual prefix while preserving proven field offsets, testing whether complete period class context changes VC5 register allocation. [same emitted code as probe 23]
probe 27 abi; result=MISMATCH; diff=332; shape=75.38461538461539: Removed the map virtual destructor and widened the leading gap to preserve proven offsets, testing whether non-polymorphic TU context selects target register colors. [same emitted code as probe 25]
probe 29 layout; result=MISMATCH; diff=332; shape=75.38461538461539: Introduced a named typed tile pointer for the proven row-offset tile ownership, testing whether tile lifetime changes map/result register allocation. [same emitted code as probe 27]
probe 32 baseline; result=MISMATCH; diff=332; shape=75.38461538461539: Revisit baseline: pinned typed map, tile, node, static/master ownership and ordinary do scan; confirm prior 356-byte structural basin before new probes. [same emitted code as probe 31]
probe 33 liveness; result=MISMATCH; diff=336; shape=52.84552845528455: Use current_node->node directly only in the placement-success cleanup, matching the oracle reload at +0xC50; preserve typed object ownership and ordinary control flow.
probe 35 liveness; result=MISMATCH; diff=336; shape=52.84552845528455: Keep the placement-success current-node reload, but declare its typed object alias inside the remove-now arm; test whether this preserves the oracle's late reload without collapsing the earlier cleanup call site. [same emitted code as probe 33]
probe 37 liveness; result=MISMATCH; diff=340; shape=54.47154471544715: Remove the transient object alias and use current_node->node for all typed object fields and cleanup; test whether the oracle's ECX object and ESI node lifetimes emerge naturally.
probe 39 control-flow; result=MISMATCH; diff=332; shape=75.38461538461539: Replace the outer guarded do scan with a natural top-tested while over the typed node pointer; test the oracle's initial null branch and shared loop tail without changing terrain ownership. [same emitted code as probe 32]
probe 41 liveness; result=MISMATCH; diff=324; shape=53.78151260504202: Scope the typed object alias to ID and terrain-removal work, then use current_node->node for placement arguments and final cleanup; this tests the oracle's object-dead-before-check lifetime while retaining all three cleanup sites.
probe 43 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Use the typed master id directly for range tests, result, and terrain compatibility; test whether VC5 keeps the AX/EAX id value and removes the short local home naturally. [same emitted code as probe 39]
probe 45 control-flow; result=MISMATCH; diff=336; shape=65.38461538461539: Use the decompiler-supported natural cleanup order: destroy when remove_now is zero, otherwise guarded delete; test whether explicit source polarity preserves three distinct cleanup call sites.
probe 47 liveness; result=MISMATCH; diff=336; shape=52.84552845528455: Combine the late current-node cleanup reload with a result-first, current-node-first local declaration order; test whether target EBP result, ESI node, EDI master, and EBX map coloring emerges from ordinary typed lifetimes. [same emitted code as probe 35]
probe 49 liveness; result=MISMATCH; diff=336; shape=52.84552845528455: Keep the late current-node cleanup reload while moving master and object declarations to the end of the typed local set; test VC5 declaration-order coloring for the target saved registers. [same emitted code as probe 47]
probe 51 liveness; result=MISMATCH; diff=355; shape=68.75: Swap the typed loop induction ownership: current_node carries the active list node and node carries next; update current_node before each ordinary continue and at the shared tail.
probe 54 control-flow; result=MISMATCH; diff=335; shape=41.935483870967744: Use current_node->node only for the old-terrain destroy arm, to prevent VC5 merging its destroy call with the placement destroy tail while retaining the natural typed scan.
probe 57 layout; result=MISMATCH; diff=332; shape=75.38461538461539: Probe 1: restored canonical map.cpp row,col formal order and ownership spelling: get_terrain(col,row), map_row_offset[row][col], following exact create_terrain_object donor. This tests whether the prior equivalent renamed formals selected the wrong VC5 source basin. [same emitted code as probe 56]
probe 58 control-flow; result=MISMATCH; diff=332; shape=75.38461538461539: Probe 2: nested positive range-removal arm from the decompiler, replacing early continues while preserving all seven calls. This tests control-flow tail merging and object-in-ECX lifetime. [same emitted code as probe 57]
probe 59 control-flow; result=MISMATCH; diff=332; shape=75.38461538461539: Probe 3: explicit loop_tail label and gotos for all proven skip/cleanup exits. Tests whether source continue lowering, rather than behavior, caused the shared-tail CFG and register lifetime mismatch. [same emitted code as probe 58]
probe 61 liveness; result=MISMATCH; diff=330; shape=75.38461538461539: Probe 4: widened only the carried result accumulator to int. Tests whether EBP result allocation and EBX map color emerge despite the original sign-extended BP return.
probe 63 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Probe 5: removed the named master_obj alias and used object->master_obj directly for ID and placement. Tests whether alias lifetime keeps the object receiver in ECX. [same emitted code as probe 59]
probe 65 variant; result=MISMATCH; diff=332; shape=75.38461538461539: Probe 6: register-hinted only the short result because the oracle carries it in EBP. Diagnostic allocator test; do not retain without source evidence. [same emitted code as probe 63]
probe 67 control-flow; result=MISMATCH; diff=347; shape=52.892561983471076: Probe 7: mirrored the complete Ghidra CFG with an inner range-filter do loop inside an outer infinite loop, shared next-node null exit, and nested table/placement branches.
probe 69 variant; result=MISMATCH; diff=347; shape=52.892561983471076: variant lab build\variant_lab\00458B40_clear_terrain_object\20260822_125141: 8 variants, 8 invariant-eligible, 0 exact
probe 70 variant; result=MISMATCH; diff=347; shape=52.892561983471076: variant lab build\variant_lab\00458B40_clear_terrain_object\20260822_125245: 32 variants, 32 invariant-eligible, 0 exact
probe 71 liveness; result=MISMATCH; diff=337; shape=75.78125: Probe 8: separated result declaration from initialization and initialized after tile-list load. Tests whether declaration scope and init site recover the oracle EBP accumulator.
probe 73 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Probe 9: separate result declaration and statement assignment immediately before get_terrain, isolating initializer lowering from target EBP OR initialization. [same emitted code as probe 65]
probe 75 abi; result=MISMATCH; diff=331; shape=75.38461538461539: Probe 10: int result accumulator with a narrow cast only at return. Tests whether a wide callee-saved lifetime recovers EBP result and map/object register colors. [same emitted code as probe 4]
probe 77 control-flow; result=MISMATCH; diff=336; shape=65.38461538461539: Probe 11: canonical Ghidra cleanup polarity in all three arms: destroy for remove_now==0, else null-check and delete. Tests branch layout and call merging without behavior change. [same emitted code as probe 45]
probe 80 liveness; result=MISMATCH; diff=337; shape=75.78125: Probe 12: moved result declaration and initializer to immediately after tile-list load, matching the decompiler sVar4 lifetime instead of only moving assignment. [same emitted code as probe 71]
probe 81 liveness; result=MISMATCH; diff=337; shape=75.78125: Probe 13: combined result declaration after tile load with direct node->node/node->next access. Tests interaction of decompiler lifetime with removal of current-node alias. [same emitted code as probe 80]
probe 82 liveness; result=MISMATCH; diff=337; shape=75.78125: Probe 14: initialized node at its declaration after get_terrain, adjacent to the moved result declaration. Tests declaration scope and parameter-home reuse for the node cursor. [same emitted code as probe 81]
probe 84 abi; result=MISMATCH; diff=332; shape=75.38461538461539: Probe 15: modeled slot-0 cleanup as explicit virtual delete_obj(1) instead of C++ delete. Ghidra proves slot-0 plus push 1; tests destructor lowering versus receiver moves. [same emitted code as probe 73]
probe 86 layout; result=MISMATCH; diff=313; shape=42.3728813559322: Probe 16: named the terrain obj_types base as a typed short pointer before the reverse scan. Tests source cursor ownership versus repeated typed member indexing.
probe 88 liveness; result=MISMATCH; diff=332; shape=75.38461538461539: Probe 17: moved object_type beside result after tile-list load. Tests a late scan-local lifetime with the target BP result carrier. [same emitted code as probe 84]
probe 90 variant; result=MISMATCH; diff=332; shape=75.38461538461539: variant lab build\variant_lab\00458B40_clear_terrain_object\20260822_125911: 4 variants, 4 invariant-eligible, 0 exact
probe 91 control-flow; result=MISMATCH; diff=345; shape=71.32352941176471: Probe 18: early null return before the bottom-tested do loop, matching the decompiler's initial null guard. Tests block polarity and result lifetime.
probe 93 liveness; result=MISMATCH; diff=332; shape=53.71900826446281: Probe 19: combined late current_node->node reload before placement cleanup with result declaration after tile load. Tests interaction around final delete/destroy calls.
probe 94 liveness; result=MISMATCH; diff=332; shape=53.71900826446281: Probe 20: branch-local placement_object alias for the late current-node reload and final cleanup. Tests whether named ownership prevents VC5 merging the table-hit delete call. [same emitted code as probe 93]
probe 95 control-flow; result=MISMATCH; diff=372; shape=64.44444444444444: Probe 21: split three delete sites with local labels and share only the target table/placement destroy label, matching proven decompiler CFG edges.
probe 97 variant; result=MISMATCH; diff=372; shape=64.44444444444444: variant lab build\variant_lab\00458B40_clear_terrain_object\20260822_130324: 128 variants, 128 invariant-eligible, 0 exact
probe 98 context; result=MISMATCH; diff=326; shape=77.16535433070867: Probe 22: restored period RGE_Static_Object trailing virtual context and complete RGE_Map virtual/nonvirtual declaration prefix from local aoe1 headers. Lab found 349-byte basin with all seven calls; validate living source.
probe 99 variant; result=MISMATCH; diff=326; shape=77.16535433070867: variant lab build\variant_lab\00458B40_clear_terrain_object\20260822_130500: 128 variants, 128 invariant-eligible, 0 exact
probe 100 variant; result=MISMATCH; diff=326; shape=77.16535433070867: variant lab build\variant_lab\00458B40_clear_terrain_object\20260822_130533: 256 variants, 256 invariant-eligible, 0 exact
probe 101 liveness; result=MISMATCH; diff=326; shape=77.16535433070867: Probe 23: iteration-local const master pointer alias, testing whether scope/constness preserves target EDI master value through placement. [same emitted code as probe 100]
probe 102 variant; result=MISMATCH; diff=326; shape=77.16535433070867: variant lab build\variant_lab\00458B40_clear_terrain_object\20260822_130727: 128 variants, 128 invariant-eligible, 0 exact
probe 103 liveness; result=MISMATCH; diff=334; shape=77.6: Probe 24: full period class context plus result declaration after tile-list load. Variant lab predicted a 347-byte seven-call basin with 11.97% exact blocks.
probe 104 liveness; result=MISMATCH; diff=334; shape=77.6: Probe 25: removed the iteration-local master alias from the improved full-context basin and used direct object->master_obj expressions, following Ghidra ownership. [same emitted code as probe 103]
probe 105 variant; result=MISMATCH; diff=334; shape=77.6: variant lab build\variant_lab\00458B40_clear_terrain_object\20260822_130919: 256 variants, 256 invariant-eligible, 0 exact
probe 106 control-flow; result=MISMATCH; diff=346; shape=73.84615384615384: Probe 26: early node-null return combined with full class context and late result declaration, following the Ghidra initial guard.
probe 107 liveness; result=MISMATCH; diff=334; shape=77.6: Probe 27: moved object_type next to late result declaration in the full-context basin, testing scan-local scope against target AX induction. [same emitted code as probe 105]
probe 108 liveness; result=MISMATCH; diff=334; shape=77.6: Probe 28: moved object declaration into each node-loop iteration, testing whether target ECX receiver is iteration-local rather than function-scope. [same emitted code as probe 107]
probe 109 liveness; result=MISMATCH; diff=334; shape=77.6: Probe 29: made current_node iteration-local, matching decompiler pRVar3 assignment, with improved full-context source. [same emitted code as probe 108]
probe 110 control-flow; result=MISMATCH; diff=334; shape=77.6: Probe 30: top-tested while(node) rotation with unchanged object/next update order, testing loop rotation against target initial guard and shared tail. [same emitted code as probe 109]
probe 112 context; result=MISMATCH; diff=334; shape=77.6: Probe 31: restored reviewed RGE_Object_List virtual load and nonvirtual method surface while preserving its proven 0xC layout. Tests nested list class context. [same emitted code as probe 111]
probe 113 control-flow; result=MISMATCH; diff=303; shape=77.77777777777777: Probe 32: short-circuit while reverse scan matching decompiler topology, testing one initial sign test and bottom backedge.
probe 116 control-flow; result=MISMATCH; diff=303; shape=77.77777777777777: Probe 33: split while guard from table predicate, preserving explicit match break and decrement. Tests whether short-circuit lowering caused call-site loss. [same emitted code as probe 113]
probe 120 liveness; result=MISMATCH; diff=326; shape=77.16535433070867: Moved short result initialization before get_terrain and removed current_node alias to test original EBP sentinel/EBX map allocation; emitted 349 bytes with stack sentinel and no gain. [same emitted code as probe 102]
probe 123 liveness; result=MISMATCH; diff=324; shape=55.08474576271186: Reloaded current_node->node after check_placement before final cleanup to match the oracle's proven publication reload; source basin lost one destructor call and emitted 332 bytes.
probe 126 context; result=MISMATCH; diff=334; shape=77.6: Restored the period map.cpp header surface used by exact 00458600: windows.h, stdio.h, and stdlib.h. The clear target stayed in the 347-byte basin, so headers alone are insufficient. [same emitted code as probe 119]
probe 127 control-flow; result=MISMATCH; diff=334; shape=77.6: Replaced the while scan with the binary's natural positive if/do-while shell and preserved all cleanup/fault paths; VC5 emitted the same 347-byte basin. [same emitted code as probe 126]
probe 130 liveness; result=MISMATCH; diff=334; shape=77.6: Moved the result declaration to function scope while keeping its initialization after the tile-list load; VC5 retained the 347-byte full-context basin and stack result. [same emitted code as probe 127]
probe 132 context; result=MISMATCH; diff=334; shape=77.6: Restored the exact 00458600 terrain-set layout: full period RGE_TOB_Picts, tiles, border, density, and placement fields, plus map.cpp headers. It preserved the 347-byte seven-call basin and fixed all proven terrain offsets. [same emitted code as probe 130]
```
<!-- end-recovered:f6a5913fd1b37b253fca -->

<!-- recovered:d4a3ea96cb9caaad1d2f -->
### `489810cbdcd9` `src/scratch/00458B40_clear_terrain_object.cpp:1-117`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00458B40 RGE_Map::clear_terrain_object
// map.cpp lines 2096-2162
//
// Walk the object list attached to a tile.  Objects inside the caller's ID
// range are retained; out-of-range objects are removed when they belong to
// the old terrain, or when the master placement test says they should go.
// The remove_now flag selects virtual deletion versus destroy_obj().
//
// Attempt log:
// - Baseline reconstruction uses named RGE_Map terrain/object ownership,
//   typed virtual destructor/destroy surfaces, and a natural node scan.
// - Collapsing the transient node alias, moving the result declaration, and
//   capturing `this` as a map local were codegen duplicates.  A guarded-while
//   object-type scan lost the two removal call sites and was restored.
// - The proven col,row signature/row-offset ownership is retained; it is also
//   a codegen duplicate.  The best clean candidate remains broad (356 emitted
//   bytes versus 321), with all seven call targets aligned but wrong prologue,
//   register coloring, and object-type scan topology.
// Main-agent audit restored canonical polymorphic map ownership and retained
// the ordinary typed tile-object scan and destruction paths.
// Current worker: a named master_obj, object-before-node declaration order,
// and a for-loop node increment were separately tested; the first two were
// emitted-code duplicates and the for form widened the body to 358 bytes.
// The original call pushes the second tile coordinate first; testing the
// source-level get_terrain(row,col) order against the map_row_offset[col][row]
// ownership is the next structural lead.
// The tile's +0x10 access is the list member of its inline RGE_Object_List,
// not an independently owned pointer; the nested typed surface is now tested.
// The oracle has one initial null guard and a bottom-tested shared tail; test
// the natural positive if/do-while form instead of a top-tested while.
// The placement arm reuses the master pointer loaded for the ID test; retain a
// named local so that this proven cross-branch lifetime can be tested directly.
// This worker's get_terrain(row,col) order moved the mismatch 334 -> 332 bytes;
// current-node/master locals, declaration order, and the inline list surface
// were emitted-code duplicates.  Delayed result initialization worsened the
// result, while an int accumulator was only a one-byte diagnostic improvement;
// the period-plausible short result is retained.  A single guarded while scan
// collapsed two required removal call sites and emitted 301 bytes, so the
// nested if/do scan was restored.  Final current candidate is 356 bytes with
// all seven call targets aligned; the 35-byte prologue/register and scan gap
// remains a structural blocker for this assignment.
// sa-e790ae6f-r1 probe 22: restore the period class declaration context that
// the local source lacked: RGE_Static_Object virtuals after destroy_obj and
// the complete RGE_Map virtual/nonvirtual prefix.  A 128-variant lab found
// this supported surface changes the target basin from 356 to 349 bytes,
// while preserving all seven call targets.  The added methods do not change
// any proven field offset.
// Probes 1-21 tested canonical row/col ownership, positive and nested CFG
// forms, explicit tail labels, result widths and init sites, direct versus
// named master/object aliases, register hints, cleanup polarity, node and
// result scopes, late placement reloads, and split cleanup labels.  The
// 347-byte full-context source below is the best clean all-call basin; the
// late-reload and label variants lost a required call site.
// sa-e790ae6f-r1 probe 24: combine the full period class context with the
// decompiler-proven result declaration after the tile-list load.  The lab
// produced a 347-byte, seven-call basin with 11.97% exact blocks.
// sa-e790ae6f-r1 probe 25: remove the iteration-local master alias from the
// improved basin and use direct typed object->master_obj expressions.  The
// Ghidra source names only the object pointer, so this tests owner spelling.
// Probes 26-30: early-null return, late scan-local scope, iteration-local
// object/current-node aliases, and top-tested while were tested.  They either
// worsened shape or emitted the same 347-byte basin.  Keep the simple loop.
// sa-e790ae6f-r1 probe 31: restore the reviewed RGE_Object_List method
// surface, including its real virtual load slot, while preserving the proven
// 0xC layout.  This tests nested list class context omitted by the prior basin.
// sa-e790ae6f-r1 probe 32: replace the guarded reverse do loop with the
// decompiler's short-circuit while predicate.  The target has one initial
// sign test and a bottom backedge; test this exact source topology.
// sa-e790ae6f-r1 probe 33: split the while guard from the table predicate:
// while (object_type >= 0) { if (match) break; --object_type; }.  This keeps
// the target's explicit comparison while avoiding the short-circuit lowering
// that removed two cleanup call sites.
// sa-e790ae6f-r1 probe 27: move object_type next to the late result
// declaration in the full-context basin.  This tests scan-local scope against
// the target's AX induction value.
// sa-e790ae6f-r1 probe 28: move the object declaration into the node-loop
// iteration.  This tests whether the target ECX receiver is an iteration-local
// value rather than a function-scope pointer.
// sa-e790ae6f-r1 probe 29: make current_node iteration-local as well, matching
// the decompiler's pRVar3 assignment inside the scan.  Test its interaction
// with the improved full-context source.
// sa-e790ae6f-r1 probe 30: use a top-tested while(node) scan with the same
// object/next update order.  This tests loop rotation against the target's
// initial guard and bottom shared tail.
// Probe 26: use the early node-null return with the improved full-context and
// late-result source.  The Ghidra listing shows this initial guard explicitly.
// sa-e790ae6f-r1 probe 23: make the master pointer a const, iteration-local
// alias.  The target carries one master value in EDI from ID load through the
// placement call; this tests whether scope and constness preserve that value.
//
// sa-0ba55ae7 pass: baseline check confirmed 356 bytes, 7/7 ordered calls,
// no frame, and 332 differing bytes.  Direct object/master expressions,
// adjacent create_terrain_object declaration order, result width and init
// placement, complete map virtual context, register hints, and a named tile
// pointer were all codegen duplicates.  The inner guarded while scan removed
// two required call sites and was restored.  The clean typed reconstruction
// remains unresolved; the next useful evidence is a compiler-basin donor or
// source declaration proof for the target EBX map and EBP result allocation.
//
// sa-4633c59f-r1 revisit: the pinned source remains the clean 356-byte basin.
// A placement-only current_node->node reload reproduced four late exact blocks
// but merged one earlier cleanup call, yielding 346 bytes and 6 calls.  Scoping
// or removing the object alias merged more cleanup calls.  Direct master-id
// use, cleanup-polarity reversal, declaration reordering, and swapping the
// active/next node locals were duplicates or worse.  Restore the typed source
// until a period declaration or compiler-basin donor explains the EBX/EBP
// allocation and the target's separate cleanup sites.

// sa-18f9837d-r1 finish: the period map.cpp header surface and the complete
// RGE_Tile_Set terrain layout from exact 00458600 were restored.  They preserve
// all proven offsets and keep the 347-byte, seven-call natural basin.
// Short-circuit terrain scans and placement-node reloads moved registers closer
// but merged a required cleanup call.  Explicit cleanup labels also worsened
// the call graph.  Those forms were discarded.  The remaining gap is the
// source lifetime that selects the original EBX/EBP/ESI/EDI allocation.
// BINARY NOTE (map TU wave02): The shared object and tile surfaces change the
// grouped local basin.  Shared layout repair is outside this source file.
```
<!-- end-recovered:d4a3ea96cb9caaad1d2f -->
