# Function notes: 0045A030 `get_border_type`

Module notes: `decomp_notes/map_module.md`.

## Recovered attempt history

<!-- recovered:9b2af6d174514d00c27d -->
### `target-session` `build/target_sessions/0045A030_get_border_type.json:1-33`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1014; shape=47.32394366197183: Baseline canonical typed reconstruction: frame/saved regs and 8 direct calls match; code is 977 bytes versus 1115, first mismatch +0x10, source uses late xi assignment and direct parameter guards.
probe 2 liveness; result=MISMATCH; diff=1014; shape=45.63380281690141: Hypothesis 2: assign xi before the combined bounds guard, because original stores sign-extended x to local [esp+0x2c] immediately after the width compare. Test whether early xi liveness reproduces the early stack home.
probe 4 control-flow; result=MISMATCH; diff=1026; shape=47.04225352112676: Hypothesis 3: split x bounds from y bounds and assign xi between them. Original stores converted x at +0x2c before reading/testing y, unlike the combined-guard baseline.
probe 6 liveness; result=MISMATCH; diff=1014; shape=47.32394366197183: Hypothesis 4: move xi declaration before yMax/xMax. Original reuses the x local home [esp+0x2c] for the diagonal terrain; source declaration order may assign xi that home. [same emitted code as probe 1]
probe 7 control-flow; result=MISMATCH; diff=1014; shape=46.76056338028169: Hypothesis 5: reverse only the upper-bound comparisons to map_width <= x and map_height <= y. Original loads width/height before sign-extending the coordinate and compares coordinate-left.
probe 9 abi; result=MISMATCH; diff=1014; shape=47.32394366197183: Hypothesis 6: use donor-supported explicit long casts in the initial coordinate upper bounds. Exact get_tile_type uses (long)x/(long)y and loads bounds before sign extension; test whether this restores target entry scheduling. [same emitted code as probe 6]
probe 10 layout; result=MISMATCH; diff=1076; shape=43.38028169014085: Hypothesis 7: cache the repeated terrain border row in a short* borders local. Original computes one +0x14a/current*408 row pointer in ECX and reuses it across all border comparisons; baseline recomputed flattened table indices.
probe 12 layout; result=MISMATCH; diff=1075; shape=40.563380281690144: Hypothesis 8: cache the complete RGE_Tile_Set owner instead of only short* borders. Original may retain a typed terrain-set pointer while indexing its borders array; compare against the rejected raw short-pointer basin.
probe 14 abi; result=MISMATCH; diff=1061; shape=47.605633802816904: Hypothesis 9: materialize a separate int current from the byte terrain before the eight helper calls. Original reloads and masks the current terrain into ESI before each push; baseline pushed the byte-local's full home without that mask.
probe 16 liveness; result=MISMATCH; diff=1014; shape=47.32394366197183: Hypothesis 10: declare the current tile pointer at function scope before the byte locals, then assign it after row setup. Original current-tile pointer home is +0x20, while baseline late declaration got +0x28. [same emitted code as probe 9]
probe 17 liveness; result=MISMATCH; diff=673; shape=57.183098591549296: Hypothesis 11: keep the x cursor xi separate from the eighth neighbor byte. Original local +0x2c holds converted x early, then a different byte terrain value later; source currently reuses xi for both roles.
probe 18 liveness; result=MISMATCH; diff=673; shape=57.183098591549296: Hypothesis 12: with separate final-neighbor storage, declare xi before yMax/xMax. Original homes show yMax +0x28, x cursor +0x2c, xMax +0x30; h11 had yMax/x cursor swapped. [same emitted code as probe 17]
probe 19 liveness; result=MISMATCH; diff=673; shape=57.183098591549296: Hypothesis 13: declare cur before every byte local. Original cur pointer home +0x20 and ter_lft +0x10 suggest declaration/lifetime ordering may reserve cur's pointer slot before the byte locals. [same emitted code as probe 18]
probe 20 liveness; result=MISMATCH; diff=673; shape=57.183098591549296: Hypothesis 14: swap ter_final and ter_top declaration order. The final neighbor should coalesce into the original x-local home +0x2c, while ter_top already occupies the incoming y home +0x40. [same emitted code as probe 19]
probe 21 abi; result=MISMATCH; diff=1061; shape=52.11267605633803: Hypothesis 15: use signed char storage for neighbor terrains while preserving unsigned pointer ABI via casts. Original byte-local stack behavior may come from period char locals, not unsigned-char locals.
probe 23 liveness; result=MISMATCH; diff=673; shape=57.183098591549296: Hypothesis 16: assign xi immediately after the combined bounds guard, before row-table setup. Original writes converted x to its home before y/row work; test this timing with the separate final-neighbor local. [same emitted code as probe 20]
probe 24 layout; result=MISMATCH; diff=1015; shape=40.73319755600814: Hypothesis 17: name only the first terrain border-row pointer, while later comparisons retain direct typed accesses. Original lookup begins from one LEA row pointer, but full-row caching previously over-optimized the body.
probe 25 control-flow; result=MISMATCH; diff=673; shape=57.183098591549296: Hypothesis 18: spell the all-same branch as a binary-supported shared border_path label. Original has seven JNE edges to the general lookup and one final JE to the late zero tail; test whether explicit branch-target structure restores that layout. [same emitted code as probe 23]
probe 26 layout; result=MISMATCH; diff=673; shape=57.183098591549296: Hypothesis 19: express the current tile as &rows[y][xi] rather than rows[y] + xi. Original keeps a typed tile pointer at +0x20; this tests whether indexed-address ownership selects its home and address schedule. [same emitted code as probe 25]
probe 27 liveness; result=MISMATCH; diff=1030; shape=52.394366197183096: Hypothesis 20: type the final neighbor as int and pass its byte address. Original final LEA is [esp+0x2c], an aligned dword home also used by converted x; h11's unsigned-byte final used unaligned +0x13.
probe 29 control-flow; result=MISMATCH; diff=673; shape=57.183098591549296: Hypothesis 21: replace the optimized else-if edge chain with explicit shared write_edge labels. Original has twelve ordered tests and one common +0x436 tail; labels model that proven topology. [same emitted code as probe 28]
probe 30 variant; result=MISMATCH; diff=910; shape=41.561181434599156: Diagnostic hypothesis 22: use a volatile border-table view in the normal edge tree to prevent VC5 from dropping later ordered tests. This tests whether the original twelve-condition CFG is a memory-observation basin; do not retain volatility without exact policy support.
probe 31 variant; result=MISMATCH; diff=1057; shape=50.985915492957744: Diagnostic hypothesis 23: force volatile byte rereads only in the all-same test. Original has eight explicit mov AL stack loads rather than memory cmp; test this codegen cause, then reject volatility unless it is source-supported.
probe 32 liveness; result=MISMATCH; diff=891; shape=43.23144104803494: Hypothesis 24: preload the four cardinal border-table values into short locals before the normal edge tree. Original normal path visibly preloads left/right, then bottom/tile into BX/DI/DX/CX before ordered tests; direct expressions missed that source shape.
probe 33 control-flow; result=MISMATCH; diff=891; shape=43.23144104803494: Hypothesis 25: combine cardinal border-value preloads with explicit shared edge labels. Test whether a forced common tail removes h24's duplicated epilogues while retaining its full twelve-test CFG. [same emitted code as probe 32]
probe 35 control-flow; result=MISMATCH; diff=961; shape=42.16101694915254: Hypothesis 1: follow the Ghidra source topology in the normal edge tree: cache the first and tile border values, preserve the nested 3/4 tests, and use the proven shared write tail. Test whether the missing normal CFG and 155-byte size gap come from VC5 flattening repeated direct expressions.
probe 37 control-flow; result=MISMATCH; diff=961; shape=42.16101694915254: Hypothesis 2: use function-scope short border_lft and border_tile locals, matching the Ghidra sVar3/sVar4 topology and shared 3/4 write tail, while preserving the clean prefix. [same emitted code as probe 35]
probe 39 control-flow; result=MISMATCH; diff=961; shape=42.16101694915254: Hypothesis 3 rerun after restoring the declared short locals: reproduce the decompiler's full normal-tree CFG with function-scope border_lft/border_tile values and explicit edge labels that all jump to one shared write tail. [same emitted code as probe 37]
probe 41 context; result=MISMATCH; diff=674; shape=56.33802816901409: Hypothesis 4: restore the period map.cpp Windows SDK context with windows.h. A matching preclean_elevation donor proves this ambient header can alter VC5 output without changing function semantics.
probe 43 control-flow; result=MISMATCH; diff=972; shape=41.89473684210526: Hypothesis 5: preserve only the decompiler-proven first short border value, but keep tile and later lookups direct. This tests whether one sVar3-like temporary gives the original left-first topology without the two-local basin.
probe 45 liveness; result=MISMATCH; diff=679; shape=54.08450704225352: Hypothesis 6: cache only the first and tile border lookup values as named short locals, then retain the natural ordered else-if edge tree. This tests the Ghidra sVar3/sVar4 lifetime without explicit labels or four-value preload pressure.
probe 47 abi; result=MISMATCH; diff=673; shape=57.183098591549296: Hypothesis 7: type the edge selector as period char, matching Ghidra's cVar13 and the original CL-based byte result, instead of unsigned char. [same emitted code as probe 34]
probe 49 abi; result=MISMATCH; diff=961; shape=42.16101694915254: Hypothesis 8: combine the decompiler-shaped named short edge tree with a char edge selector. Test whether the original CL result width removes the large duplicated-tail basin seen with unsigned edge. [same emitted code as probe 39]
```
<!-- end-recovered:9b2af6d174514d00c27d -->

<!-- recovered:9c147f12ee42c32c1f6b -->
### `489810cbdcd9` `src/scratch/0045A030_get_border_type.cpp:1-50`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA 0045A030 RGE_Map::get_border_type
// map.cpp:2845-3012
// Attempt log:
// 1: Direct natural reconstruction from packet: neighbor terrain sampling, check_for_border calls, terrain-border lookup and edge code selection.
// 2: Modeled map layout facts used by asm: width +8, height +0xC, row table +0x8D8C, tile stride 24, terrain byte at +5 masked by 0x1F, output byte at +6.
// 3: Modeled eight neighbor samples in original order (left/right/top/bottom/corners by row +/-1 and offset +/-24), including boundary fallback to current terrain.
// 4: Added eight check_for_border(current,&neighbor) calls in the original order.
// 5: Added all-same-neighbor early zero-out path.
// 6: Added border lookup as raw table at this+0x14A + current*408, neighbor index*2, matching original address math better than an oversized C array.
// 7: Added border validity checks: 0xFFFF, negative, >=16, and terrain-enabled byte at this+0x338C + border*1440.
// 8: Added special word [edx+0x392A] == 1 case by composing low border nibble with bitmask of four cardinal neighbors.
// 9: Added normal edge selection ordering for 1,2,3,4,9,10,11,12,5,6,7,8 and final zero-out fallback.
// 10: Default /O2 /Oy compiles but is size-short: configured 1115 exceeds rebuilt .text 848. Source is behaviorally broad but too high-level/optimized relative to original stack-slot-heavy VC5 shape.
// 11: Probed /Od: exact size 1115 but broad wrong basin from offset 0 (91.7489% positional); removed flag.
// 12: Probed /O2 /Oy /Og-: exact size 1115 but same broad wrong basin from offset 0; removed flag.
// 13: Tried removing helper terrain_at and inlining row[offset] loads; default shrank further (944 -> 848), confirming original likely needs source-shaped stack-slot/parameter reuse rather than helper abstraction.
// 14: Replaced raw displacement table and gap-only class with the period-plausible RGE_Map/RGE_Tile/RGE_Tile_Set/RGE_Border_Set surfaces. The named borders[] access is the canonical owner of +0x14A and +0x338C, while the real virtual-prefix/map layout preserves +0x8/+0xC/+0x8D8C.
// 15: Reordering persistent row/current declarations was a codegen duplicate.
// 16: Self-alias, split-boundary, nested/assignment-carry, and shared-goto variants were rejected: they were unchanged or expanded the function to 1509-1568 bytes.
// 17: Promoting x to an explicit int cursor moved its stack home closer (986 bytes, diff 1016) but still left the saved-this/row register basin and byte-local homes wrong; full virtual-prefix context changed only one byte.
// 18: Restored the cleaner canonical typed reconstruction as the best current source. Remaining blocker is structural VC5 register/local-home allocation (original this=EDI, rows=ESI, x home +2C, y=EBP; rebuilt this=ESI, rows=EBP and different byte homes), not calls or layout.
// 19: Re-tested separate typed x/y bounds guards from the exact get_tile_type donor; VC5 emitted the same code, so restored the canonical combined guard.
// 20: In this claim, moved named x/y cursors before split guards; prologue and frame basin worsened, so restored clean source.
// 21: Reused x/y parameter homes for terrain bytes; frame shrank and CFG moved, but positional diff widened, so restored.
// 22: Swapped max-local declaration order; emitted code was unchanged.
// 23: Initialized an outer row cursor before the column cursor; size shrank and first-block structure worsened, so restored.
// 24: Put promoted cursor assignments in the bounds predicate; diff improved to 994, but code size fell to 944 and the source became decompiler-shaped, so restored.
// 25: Final claim state retains the canonical typed source. Calls and frame match; remaining gap is saved-this/row register and local-home allocation.
// 26: This claim tested early x assignment, declaration order, bound operand order, cached table pointers, current-int materialization, signed bytes, and current-tile address forms. Most were duplicates or worse.
// 27: Keeping the eighth neighbor as a separate unsigned-char local instead of reusing the x cursor reduced positional diff from 1014 to 673 bytes and kept all eight call sites at the original offsets. This is the current best source shape.
// 28: Volatile all-same reads and a volatile border-table view produced extra frames or code, so they are rejected as metric-only steering.
// 29: Cardinal border preload locals restored the full normal decision CFG but grew the function to 1324 bytes. The simpler direct typed chain remains the clean source.
// 30: Ghidra-shaped short border_lft/border_tile locals with explicit edge labels produced a 1389-byte duplicated-tail basin (diff 961), so restore the clean chain.
// 31: windows.h changed the basin slightly to 964 bytes (diff 674), but did not recover the target CFG; restore the no-header source context.
// 32: Two named short border lookup values in the natural else-if tree produced 1006 bytes (diff 679) and lost exact early blocks; restore the direct chain.
// 33: A char edge selector was a codegen duplicate of the clean unsigned-byte source (960 bytes, diff 673); retain the simpler typed form.
// Translation-unit context: map.cpp, source lines 2845-3012, RGE_Map owner.
// The shared map surface preserves the owner symbol. The pre-bug-fix source was
// 960 bytes with a 673-byte diff. Its PDB-order grouped result was nonexact.
// ORIGINAL BUG: the border table uses the first neighbor that differs from the
// center terrain. The 0045A253 join and 0045A259 AL store prove this lookup order.
// This can select a different border. Do not replace it with ter_lft lookup.
// The named border_table pointer is required by the original current-border base.
// Context recovery pass: border_table reduced the standalone result from 960 to
// 913 bytes and the positional diff from 673 to 611 bytes. Eight calls stayed ordered.
// A nested border-neighbor expression restores the shipped first-mismatch lookup.
// It emits 1328 bytes, 461 instructions, and 78.87% exact-block coverage.
// Keep it for behavior. The extra 213 bytes remain a code-generation blocker.
// BINARY NOTE (map TU wave02): The authentic grouped wrapper preserves the
// unresolved border-selection basin and four boundary escapes.
```
<!-- end-recovered:9c147f12ee42c32c1f6b -->
