# Recovery journal: 004AB300 `set_unit_player`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_sed.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_sed.cpp`.
- Earlier recovery note: `recovery_notes/scr_sed.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3a5fb03e14eca45a0069 -->
### `d050eea3c` `src/scr_sed.cpp:1456-1456`

Mapping: `strong`. comment lies after mapped function set_unit_player at old line 1408.

```text
        // BINARY NOTE: the offset zero store follows the positive-count test.
```
<!-- end-recovered:3a5fb03e14eca45a0069 -->

<!-- recovered:202734c4d530bd96ddc2 -->
### `target-session` `build/target_sessions/004AB300_set_unit_player.json:1-141`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=533; shape=84.52830188679245: Baseline current typed reconstruction; measure exactness, frame, calls, and boundary before new hypotheses.
probe 2 control-flow; result=MISMATCH; diff=759; shape=85.32818532818533: Hypothesis 1: direct unit_list_info[out] member expressions, without a named record pointer, restore the original index-scaled address arithmetic and loop topology.
probe 4 liveness; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 2: declare the allocation-loop error flag at its first use, matching the PDB's late zero-store and allowing the earlier output-index home to be reused. [same emitted code as probe 1]
probe 5 liveness; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 3: hoist the string-result declaration before the allocation loop so VC5 can keep the allocated pointer in EBP across the copy instead of adding a stack spill. [same emitted code as probe 4]
probe 6 liveness; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 4: assign calloc directly into strings[i] and use that member for the guard/copy, matching exact donor patterns that keep the allocation result in a saved register. [same emitted code as probe 5]
probe 7 layout; result=MISMATCH; diff=649; shape=85.0: Hypothesis 5: make the accepted-list output index a short, matching the original movsx word home at +481 and its later 16-bit compare behavior.
probe 9 liveness; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 6: hoist the master-object count declaration to function scope, testing whether VC5 assigns its short register to EDI as in the original first scan. [same emitted code as probe 6]
probe 11 liveness; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 7: reuse one int index for accepted unit records and the later allocation error flag, matching Ghidra's observed shared home and original source-variable lifetime. [same emitted code as probe 9]
probe 12 behavior; result=MISMATCH; diff=563; shape=84.16988416988417: Hypothesis 8: model the allocation failure flag as bool, following the decompiler's bVar5 candidate, to test whether VC5 emits the original flag stores and register lifetime.
probe 14 control-flow; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 9: express the second master-object scan as a for-loop with both observed induction updates in its increment clause, testing source CFG and update scheduling. [same emitted code as probe 11]
probe 16 context; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 11: add the period standard-library declaration context for calloc/free/qsort, testing whether VC5 changes the register and frame basin. [same emitted code as probe 14]
probe 18 context; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 12: add the period memory.h declaration context beside string.h, testing another supported VC5 front-end basin. [same emitted code as probe 16]
probe 20 context; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 13: restore the period Windows SDK header context, testing whether this TU's standard declarations select the original VC5 codegen basin. [same emitted code as probe 18]
probe 22 abi; result=MISMATCH; diff=533; shape=84.90566037735849: Hypothesis 14: correct RGE_Base_Game master_obj_id ownership to +0x3FC by accounting for its vptr, eliminating the rebuilt +0x400 access seen in the original-vs-rebuilt range.
probe 23 layout; result=MISMATCH; diff=533; shape=84.90566037735849: Hypothesis 15: model TRIBE_Screen_Sed's real polymorphic class surface and reduce its leading gap by the vptr, preserving all proven field offsets while testing front-end class context. [same emitted code as probe 22]
probe 24 abi; result=MISMATCH; diff=533; shape=84.90566037735849: Hypothesis 16: replace placeholder base virtual names with the reviewed RGE_Base_Game surface while preserving the proven set_player slot +0x14 and get_string slot +0x20. [same emitted code as probe 23]
probe 25 variant; result=MISMATCH; diff=533; shape=84.90566037735849: variant lab build\variant_lab\004AB300_set_unit_player\20260817_145844: 4 variants, 4 invariant-eligible, 0 exact
probe 26 liveness; result=MISMATCH; diff=533; shape=84.52830188679245: Hypothesis 17: use a distinct short allocation-loop index, keeping the earlier master scan index dead and testing whether VC5 preserves EBP for the calloc result.
probe 27 variant; result=MISMATCH; diff=545; shape=78.9272030651341: Hypothesis 18: use an int allocation-loop index separate from the earlier short scan index, testing whether VC5 keeps the calloc result in EBP while preserving the observed word compare elsewhere.
probe 28 layout; result=MISMATCH; diff=532; shape=90.22556390977444: Hypothesis 19: narrow the selected-row local to short, testing the decompiler's sVar16 candidate against the original full-width stack loads before the scroll call.
probe 29 variant; result=MISMATCH; diff=532; shape=90.22556390977444: variant lab build\variant_lab\004AB300_set_unit_player\20260817_150157: 4 variants, 4 invariant-eligible, 0 exact
probe 30 control-flow; result=MISMATCH; diff=761; shape=87.64478764478764: Hypothesis 20: with the newly proven short selected local and exact frame, direct unit_list_info[out] expressions may restore the original per-record index arithmetic rather than the running-byte-offset lowering.
probe 32 control-flow; result=MISMATCH; diff=533; shape=90.22556390977444: Hypothesis 21: move the second master scan's object-offset initialization inside a positive-count do/while guard, matching the original test-before-xor CFG and PDB line 2172 block.
probe 33 liveness; result=MISMATCH; diff=533; shape=90.22556390977444: Hypothesis 22: register-qualify the master count to test whether VC5 selects EDI for the observed original count register; retain only if source policy and bytes support it. [same emitted code as probe 32]
probe 34 liveness; result=MISMATCH; diff=533; shape=90.22556390977444: Hypothesis 23: hoist the proven short selected-row declaration while retaining its late zero assignment, testing whether declaration scope changes the early ESI/EDI zero-register color. [same emitted code as probe 33]
probe 35 variant; result=MISMATCH; diff=533; shape=90.22556390977444: variant lab build\variant_lab\004AB300_set_unit_player\20260817_150522: 512 variants, 512 invariant-eligible, 0 exact
probe 36 layout; result=MISMATCH; diff=493; shape=95.78544061302682: Hypothesis 24: combine the proven short selected local with a short accepted-output index, testing whether the original word load and index-scaled record addressing emerge together.
probe 37 control-flow; result=MISMATCH; diff=446; shape=98.46743295019157: Hypothesis 25: combine both proven short locals with direct indexed record expressions, testing whether VC5 restores the original arithmetic order and base-load schedule.
probe 38 liveness; result=MISMATCH; diff=506; shape=95.0: Hypothesis 26: bind the accepted record's text destination before the virtual get_string call, testing whether its LEA completes before the independent global receiver load.
probe 40 liveness; result=MISMATCH; diff=493; shape=95.78544061302682: Hypothesis 27: use a named accepted-record pointer with both short indices, testing whether the alias changes the virtual-call receiver/argument schedule without losing the exact frame. [same emitted code as probe 36]
probe 41 liveness; result=MISMATCH; diff=493; shape=95.78544061302682: Hypothesis 28: use a typed List_Info reference for the accepted record, testing whether reference aliasing preserves the original virtual-call argument scheduling. [same emitted code as probe 40]
probe 42 abi; result=MISMATCH; diff=446; shape=98.46743295019157: Hypothesis 29: use the canonical RGE_Base_Game class name and reviewed set_game_mode arity, testing global relocation identity and virtual-call scheduling.
probe 43 control-flow; result=MISMATCH; diff=446; shape=98.46743295019157: Hypothesis 30: spell the virtual output as an explicit address-of element, testing whether VC5 schedules the record-base add before the global receiver load. [same emitted code as probe 42]
probe 44 abi; result=MISMATCH; diff=446; shape=98.46743295019157: Hypothesis 31: pass the accepted List_Info record base as the get_string buffer, matching the assembly's record-base destination and Ghidra's pointer shape. [same emitted code as probe 43]
probe 45 abi; result=MATCH; diff=0; shape=100.0: Hypothesis 32: use the reviewed long get_string ID surface, testing whether the canonical overload changes the virtual argument scheduling or call identity.
probe 58 layout; result=MATCH; diff=0; shape=100.0: Exact-finish policy audit: model the proven TScreenPanel base and keep derived fields at their original offsets. Test whether canonical inheritance remains exact. [same emitted code as probe 56]
probe 61 layout; result=MISMATCH; diff=1; shape=100.0: Policy hypothesis P1: replace fake RGE_Base_Game virtual slots, VPAD TListPanel slots, and gap-only UI bases with reviewed canonical names, inheritance, and natural fields. Keep raw master cursor temporarily to isolate declaration effects.
probe 62 abi; result=MISMATCH; diff=1; shape=100.0: Policy hypothesis P2: retain the canonical named get_string overload set and insert the known long-returning overload before the buffered long overload to test VC5 slot lowering. [same emitted code as probe 61]
probe 63 abi; result=MISMATCH; diff=1; shape=100.0: Policy hypothesis P3: reorder only the canonical get_string overload declarations. Test whether VC5 overload grouping, rather than the fake-slot names, selects the +0x20 dispatch.
probe 64 abi; result=MISMATCH; diff=1; shape=100.0: Policy hypothesis P4: test the remaining canonical get_string overload order with the one-argument long form first. [same emitted code as probe 62]
probe 65 abi; result=MISMATCH; diff=1; shape=100.0: Policy hypothesis P5: test the canonical buffered, single-long, int/long overload order. [same emitted code as probe 63]
probe 66 abi; result=MATCH; diff=0; shape=100.0: Policy hypothesis P6: use the reviewed canonical get_string order: int/long buffer, long buffer, then long-only.
probe 67 layout; result=MISMATCH; diff=644; shape=91.5057915057915: Policy hypothesis P7: replace raw char-byte master cursors with typed RGE_Master_Static_Object** cursors and natural dereference/increment. Test whether typed pointer ownership preserves the exact loop basin.
probe 68 layout; result=MISMATCH; diff=515; shape=93.82239382239382: Policy hypothesis P8: use direct typed indexed access player->master_objects[index] in both scans. Test the requested natural array form without raw cursor arithmetic.
probe 69 liveness; result=MISMATCH; diff=639; shape=87.59398496240601: Policy hypothesis P9: retain natural indexed access but cache the proven typed master_objects array member once per scan. Test whether a named array base restores original load/register scheduling.
probe 71 layout; result=MISMATCH; diff=5; shape=99.61389961389962: Policy hypothesis P10: convert only the first count scan to player->master_objects[index], while keeping the second scan raw. Isolate whether the first loop can use natural indexing without disturbing the later exact basin.
probe 72 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: Policy hypothesis P11: split direct-index scan declarations from assignments and assign index before count. Test whether VC5 restores the original zero-before-count instruction order. [same emitted code as probe 71]
probe 73 liveness; result=MISMATCH; diff=679; shape=95.38461538461539: Policy hypothesis P12: narrow only the first direct-array index to short, matching the proven short scan domain. Test whether VC5 emits the original zero and dword cursor schedule.
probe 74 control-flow; result=MISMATCH; diff=638; shape=98.47328244274809: Policy hypothesis P14: express the first natural indexed scan as a bounded for loop with index and countdown updates. Test whether standard loop lowering restores the proven zero-before-count order.
probe 75 layout; result=MISMATCH; diff=511; shape=94.2084942084942: Policy hypothesis P15: convert only the second list-building scan to direct player->master_objects[i] indexing, keeping the first count scan exact. Isolate the later loop's natural-array cost.
probe 76 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: Policy hypothesis P16: direct-index first scan with countdown declared before index. Test whether declaration order alone fixes the five-byte zero/count swap. [same emitted code as probe 72]
probe 77 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: Policy hypothesis P17: use an independent int master_index for the second natural array scan, avoiding the later short list index. Test whether a full-width typed index restores the second-loop register basin. [same emitted code as probe 76]
probe 78 liveness; result=MISMATCH; diff=641; shape=98.08429118773947: Policy hypothesis P18: cache only the first scan's typed array base, while retaining natural indexing in both scans. Test whether a scoped named base forces the original initialization order without raw arithmetic.
probe 79 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: Policy hypothesis P19: place the first direct-index counter in an outer scope and the countdown inside a nested scan block. Test whether VC5 honors the natural initialization lifetime and restores exact order. [same emitted code as probe 77]
probe 80 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: Policy hypothesis P20: combine direct-index counter declarations in one initializer while preserving the do/while. Test whether VC5 emits index zero before the count load. [same emitted code as probe 79]
probe 81 control-flow; result=MISMATCH; diff=638; shape=98.47328244274809: Policy hypothesis P21: place the natural index in the for initializer while keeping the countdown in the loop scope. Test the final period-plausible loop form for exact ordering. [same emitted code as probe 74]
probe 82 layout; result=MISMATCH; diff=5; shape=99.61389961389962: Policy cleanup P22: replace TRIBE_Screen_Sed offset gaps with reviewed named fields and canonical view/panel inheritance. Keep direct indexed master scans and record emitted policy-valid result. [same emitted code as probe 80]
probe 85 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P01: reverse first typed scan declaration order to index before countdown. Test whether natural zero initialization follows original xor-before-movsx schedule. [same emitted code as probe 84]
probe 86 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P02: split the typed scan index declaration from its zero assignment, after the count declaration. Test whether the original initialization point is statement-driven rather than declaration-driven. [same emitted code as probe 85]
probe 87 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P03: assign the typed scan index to zero before declaring and initializing the countdown. Test the original zero-first statement order with natural indexed ownership. [same emitted code as probe 86]
probe 88 abi; result=MISMATCH; diff=5; shape=99.61389961389962: P04: add an explicit signed int cast when materializing the countdown from the proven short field. Test whether conversion spelling selects the original zero/count scheduling. [same emitted code as probe 87]
probe 89 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P05: spell the first typed array access as explicit pointer addition and dereference. Test whether equivalent typed ownership has a distinct VC5 scheduling basin. [same emitted code as probe 88]
probe 90 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P06: combine the natural countdown and index declarations in one statement. Test whether VC5's declaration grouping changes initialization scheduling without changing ownership or control flow. [same emitted code as probe 89]
probe 91 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P07: derive the first scan countdown from the canonical player master_object_num member instead of the named short n. Test ownership/CSE effects on the zero/count schedule while retaining the proven field type. [same emitted code as probe 90]
probe 92 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P08: split the countdown declaration from its assignment while keeping the natural index initializer after it. Test whether a real assignment statement changes the VC5 initialization scheduler. [same emitted code as probe 91]
probe 93 control-flow; result=MISMATCH; diff=5; shape=99.61389961389962: P09: use the natural compound countdown update count -= 1 instead of postfix decrement. Test whether VC5's assignment form affects the zero/count schedule or loop update. [same emitted code as probe 92]
probe 94 control-flow; result=MISMATCH; diff=5; shape=99.61389961389962: P10: use prefix decrement on the natural typed countdown. Test whether VC5 distinguishes prefix from compound/postfix decrement in the do/while update. [same emitted code as probe 93]
probe 95 context; result=MISMATCH; diff=5; shape=99.61389961389962: P11: restore the period standard-library context by including stdlib.h alongside string.h. Test whether VC5 front-end context selects the original zero/count order without source steering. [same emitted code as probe 94]
probe 96 abi; result=MISMATCH; diff=5; shape=99.61389961389962: P12: qualify the proven master_objects array as a read-only pointer array. Test whether canonical const ownership affects VC5 load scheduling without changing layout or behavior. [same emitted code as probe 95]
probe 97 control-flow; result=MISMATCH; diff=638; shape=98.47328244274809: P13: express the proven positive-count scan as a for loop with countdown and typed index updates. Test whether period-plausible loop syntax preserves the original CFG and zero-before-count schedule. [same emitted code as probe 81]
probe 98 abi; result=MISMATCH; diff=5; shape=99.61389961389962: P14: express the proven pointer-array member through a local class typedef, preserving the same pointer layout and natural indexed expression. Test whether declaration identity changes VC5 scheduling. [same emitted code as probe 96]
probe 99 abi; result=MISMATCH; diff=5; shape=99.61389961389962: P15: widen the natural typed scan index to unsigned int, matching its nonnegative array domain. Test whether index signedness changes VC5 initialization scheduling while preserving the proven pointer stride. [same emitted code as probe 98]
probe 100 abi; result=MISMATCH; diff=676; shape=95.0: P16: use a proven-domain short for the first typed array index, matching the short master count and later scan index. Test whether narrow index storage naturally yields the original pointer/count order.
probe 101 abi; result=MISMATCH; diff=5; shape=99.61389961389962: P17: use the period-plausible long type for the positive countdown while retaining the proven short field and int typed index. Test whether VC5's source width choice changes initialization order. [same emitted code as probe 99]
probe 102 context; result=MISMATCH; diff=5; shape=99.61389961389962: P18: restore the related UI declaration order seen in local screen sources: define TListPanel before TDropDownPanel. Test whether canonical class/TU context selects the original zero/count schedule. [same emitted code as probe 101]
probe 103 context; result=MISMATCH; diff=5; shape=99.61389961389962: P19: use the period Windows UI context with the real SDK RECT type instead of a local tagRECT clone. Test whether canonical header ownership selects the original zero/count schedule. [same emitted code as probe 102]
probe 104 context; result=MISMATCH; diff=5; shape=99.61389961389962: P20: add the period memory.h context alongside string.h while retaining canonical reviewed declarations. Test whether a standard header combination selects the original zero/count schedule. [same emitted code as probe 103]
probe 107 abi; result=MISMATCH; diff=627; shape=99.23076923076923: P01: type the first-scan countdown as short, matching the source field width. Test whether natural narrow countdown ownership emits zero before the sign-extended count.
probe 109 abi; result=MISMATCH; diff=5; shape=99.61389961389962: P02: type the first-scan index as long, a period-plausible named integer with the same 32-bit width. Test whether index type selects the original zero-first schedule. [same emitted code as probe 106]
probe 111 abi; result=MISMATCH; diff=5; shape=99.61389961389962: P03: type the first-scan index as unsigned long. Test whether the unsigned period integer domain changes VC5's zero/count register assignment without changing array behavior. [same emitted code as probe 109]
probe 113 control-flow; result=MISMATCH; diff=5; shape=99.61389961389962: P04: use the natural truth-test form while (count) for the first scan. Test whether condition representation owns the original zero/count ordering without changing the positive-count guard. [same emitted code as probe 111]
probe 115 behavior; result=MISMATCH; diff=5; shape=99.61389961389962: P05: express the first scan's disabled test as natural boolean negation. Test whether object-field truth semantics, rather than an equality spelling, changes the zero/count scheduling. [same emitted code as probe 113]
probe 117 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P06: spell the first typed array load as pointer addition and dereference, an ordinary equivalent expression. Test whether the exact call expression changes array-index scheduling. [same emitted code as probe 115]
probe 119 liveness; result=MISMATCH; diff=641; shape=98.08429118773947: P07: name the first scan's typed array base as a local pointer, preserving direct indexing. Test whether natural array-base ownership makes the zero index live before the count load. [same emitted code as probe 78]
probe 121 behavior; result=MISMATCH; diff=592; shape=98.46153846153847: P08: bind the first scan element as a typed reference to the pointer-array slot. Test whether natural array-element ownership changes the required zero/count evaluation order.
probe 123 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P09: initialize the first-scan countdown from the canonical player field instead of the named n local. Test whether direct field ownership selects the original zero-first schedule. [same emitted code as probe 117]
probe 125 abi; result=MISMATCH; diff=5; shape=99.61389961389962: P10: use a long-typed zero literal for the int index initializer. Test whether literal conversion ownership changes VC5 scheduling; retain only if it reflects a natural source distinction. [same emitted code as probe 123]
probe 128 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175017: 512 variants, 512 invariant-eligible, 0 exact
probe 129 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175213: 1 variants, 1 invariant-eligible, 0 exact
probe 130 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175412: 1 variants, 1 invariant-eligible, 0 exact
probe 131 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175458: 1 variants, 1 invariant-eligible, 0 exact
probe 132 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175604: 4 variants, 4 invariant-eligible, 0 exact
probe 133 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175634: 4 variants, 4 invariant-eligible, 0 exact
probe 134 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175656: 4 variants, 4 invariant-eligible, 0 exact
probe 135 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175718: 4 variants, 4 invariant-eligible, 0 exact
probe 136 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175746: 1 variants, 1 invariant-eligible, 0 exact
probe 137 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175815: 1 variants, 1 invariant-eligible, 0 exact
probe 138 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175852: 1 variants, 1 invariant-eligible, 0 exact
probe 139 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_175928: 1 variants, 0 invariant-eligible, 0 exact
probe 140 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_180000: 1 variants, 1 invariant-eligible, 0 exact
probe 142 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_185820: 2 variants, 1 invariant-eligible, 0 exact
probe 144 variant; result=MISMATCH; diff=5; shape=99.61389961389962: variant lab build\variant_lab\004AB300_set_unit_player\20260817_190013: 4 variants, 2 invariant-eligible, 0 exact
probe 147 abi; result=MISMATCH; diff=5; shape=99.61389961389962: Canonical panel ownership probe: move set_text overloads to the evidence-backed TTextPanel surface and remove the one-slot TListPanel facade; test whether named inheritance preserves target codegen. [same emitted code as probe 146]
probe 148 abi; result=MISMATCH; diff=5; shape=99.61389961389962: Canonical UI ABI probe: replace remaining void-pointer panel slot parameters with reviewed TDrawArea, TPanel, text/button/input/edit/scrollbar/slider owner types; preserve the known named virtual slots. [same emitted code as probe 147]
probe 150 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P11: reorder the natural indexed first-scan declarations to match the raw donor's evidence-backed index-before-count ownership. Test whether VC5 emits zero initialization before sign-extended count without a raw cursor. [same emitted code as probe 149]
probe 151 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P12: source the first-scan count directly from the canonical player field while keeping the short n for the second scan. Test whether direct field ownership makes VC5 schedule index zero before the count conversion. [same emitted code as probe 150]
probe 152 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P13: split first-scan index declaration from its zero assignment, with count declared between them. Test whether delayed assignment retains the original zero-first initialization schedule through a natural scope form. [same emitted code as probe 151]
probe 153 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P14: combine natural first-scan index and count initializers in one declaration, preserving index-before-count source order. Test whether declaration grouping changes VC5's independent initialization order. [same emitted code as probe 152]
probe 154 control-flow; result=MISMATCH; diff=638; shape=98.47328244274809: P15: express the guarded first scan as a natural top-tested while(count != 0), retaining direct typed indexing and the observed count decrement. Test whether VC5's loop lowering changes the zero/count initialization schedule. [same emitted code as probe 97]
probe 156 control-flow; result=MISMATCH; diff=641; shape=97.31800766283524: P16: replace the first guarded do/count-down scan with a natural bounded for(index = 0; index < n; ++index) over the typed pointer array. Test whether canonical indexed loop lowering can produce the zero-first schedule.
probe 158 control-flow; result=MISMATCH; diff=5; shape=99.61389961389962: P17: use the natural do/while(--count != 0) spelling for the guarded indexed first scan. Test whether VC5 preserves the observed dec/jne while changing initialization scheduling. [same emitted code as probe 153]
probe 160 control-flow; result=MISMATCH; diff=638; shape=98.47328244274809: P18: express the same guarded count-down indexed scan as a for loop with observed count and index updates in one increment list. Test whether natural update grouping affects the zero/count initialization order. [same emitted code as probe 154]
probe 162 control-flow; result=MISMATCH; diff=5; shape=99.61389961389962: P19: use natural truth-test do/while(count) after the observed count decrement. Test whether VC5's truth-test spelling affects scheduling while preserving the direct indexed scan. [same emitted code as probe 158]
probe 163 control-flow; result=MISMATCH; diff=644; shape=97.72727272727273: P20: use the natural guarded while(count-- != 0) indexed scan. Test whether a pre-tested count-down loop can retain the target topology and emit the zero initialization first.
probe 165 layout; result=MISMATCH; diff=627; shape=99.23076923076923: P21: keep the first-scan count in the proven short field width instead of widening it to int. Test whether natural narrow-count ownership changes the zero/count initialization order without changing the observed dec loop. [same emitted code as probe 107]
probe 167 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P22: spell the first canonical array element as pointer-plus-index dereference, without a moving cursor. Test whether VC5 schedules the typed index initialization differently from bracket indexing. [same emitted code as probe 162]
probe 170 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P1: declare the direct-index first-scan index before its count, matching the raw donor's offset-before-count declaration scope. Test whether VC5 restores xor ecx/ecx before movsx edx/di without a raw cursor. [same emitted code as probe 169]
probe 172 layout; result=MISMATCH; diff=627; shape=99.23076923076923: P2: keep the first-scan count in its proven short field width while retaining canonical typed indexing. Test whether PDB short-count ownership changes the initialization order without a cursor. [same emitted code as probe 165]
probe 174 control-flow; result=MISMATCH; diff=638; shape=98.47328244274809: P3: combine canonical index and count declarations in a for header, with observed increment and decrement order. Test whether VC5 schedules zero before the widened count. [same emitted code as probe 160]
probe 176 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P4: spell the first canonical array load as typed pointer-plus-index dereference rather than bracket notation. Test whether equivalent canonical ownership reaches the original zero-before-count scheduling. [same emitted code as probe 170]
probe 178 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P5: make the second-scan index function-scope, then initialize it inside its proven guard. Test whether PDB-like shared loop-local scope changes first-scan register scheduling. [same emitted code as probe 176]
probe 180 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P6: hoist first-scan index and count declarations to function scope, with assignments inside the positive-count guard. Test PDB-like declaration scope while keeping typed player-array ownership and loop topology. [same emitted code as probe 178]
probe 182 liveness; result=MISMATCH; diff=17; shape=99.22779922779922: P7: load the canonical short master-object count before the list-size initialization, matching a function-scope count declaration possibility. Test whether count liveness alters the final zero/count order.
probe 184 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P8: make the first-scan master record a function-scope typed local and assign it inside the loop. Test whether PDB-like object-local scope changes the independent zero/count schedule. [same emitted code as probe 180]
probe 186 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P9: hoist the proven short output row and second-scan index declarations to function scope, retaining their original assignments. Test whether PDB local homes and scope affect the first scan's independent initialization order. [same emitted code as probe 184]
probe 188 layout; result=MISMATCH; diff=676; shape=95.0: P10: use a PDB-supported short first-scan index with the canonical typed array. Test whether the named short local can retain the target loop while restoring zero-first scheduling. [same emitted code as probe 100]
probe 190 control-flow; result=MISMATCH; diff=605; shape=98.84615384615384: P11: reverse the first-scan source update statements while preserving the target's emitted dec/add loop update as a natural dependency-order test.
probe 192 control-flow; result=MISMATCH; diff=5; shape=99.61389961389962: P12: replace the first-scan post-decrement with natural compound subtraction, retaining the same signed count behavior. Test VC5 update lowering and setup scheduling. [same emitted code as probe 186]
probe 194 control-flow; result=MISMATCH; diff=5; shape=99.61389961389962: P13: use expanded count = count - 1 in the first scan. Test whether VC5's natural expression lowering differs from post-decrement at the setup and loop backedge. [same emitted code as probe 192]
probe 196 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P14: reuse one typed integer index across the two non-overlapping scans, matching the compiler's repeated offset temp and PDB loop-local overlap. Test whether shared source lifetime changes first-scan setup. [same emitted code as probe 194]
probe 198 control-flow; result=MISMATCH; diff=601; shape=98.84615384615384: P15: use a natural signed do/while count > 0 after pre-decrement, keeping the direct typed index and count-down intent. Test whether VC5 preserves the target dec/jnz and zero/count order.
probe 200 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P16: make the first-scan short-to-int count widening explicit at its declaration. Test whether VC5 extension timing changes the count load relative to typed index zeroing. [same emitted code as probe 196]
probe 202 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P17: spell the widened first-scan count as period-correct long, which is the same 32-bit width on VC5. Test whether source type identity affects initialization scheduling. [same emitted code as probe 200]
probe 204 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P18: split first-scan index and count declarations from their assignments, with index zero assigned before count widening. Test the VC5 declaration/initializer scheduling rule directly. [same emitted code as probe 202]
probe 206 liveness; result=MISMATCH; diff=5; shape=99.61389961389962: P19: put the first-scan count in a nested declaration scope while keeping the typed index outside. Test whether VC5 scope boundaries force zero initialization before count extension. [same emitted code as probe 204]
probe 208 control-flow; result=MISMATCH; diff=641; shape=97.31800766283524: P20: use the canonical bounded for(index = 0; index < n; ++index) direct array scan as the final loop-form reassessment. Compare its natural topology and initialization against the count-down frontier. [same emitted code as probe 156]
probe 214 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P1 layout: restore the reviewed RGE_Master_Static_Object fields through button_pict so disabled is at binary-proven +0x4E, not +0x4D. This tests the two remaining byte displacement mismatches without changing traversal or calls.
probe 215 layout; result=MISMATCH; diff=5; shape=99.61389961389962: P2 type/order: use a natural unsigned index declared before the signed count in the first typed-array scan. Test whether VC5 emits the original zero-before-sign-extension order without a byte cursor. [same emitted code as probe 214]
probe 216 variant; result=MATCH; diff=0; shape=100.0: P4 exact candidate: use a natural int byte offset over the proven master_objects pointer array in both scans, with repeated member rereads. This reproduces the original stride and tests whether the exact checkpoint survives the canonical scr_sed context.
probe 217 variant; result=MISMATCH; diff=5; shape=99.61389961389962: Exact walkback A: revert only the first count scan from byte offset to typed index, while retaining the exact second scan and reviewed object layout. This tests whether the first cursor is independently required. [same emitted code as probe 215]
probe 218 variant; result=MATCH; diff=0; shape=100.0: Exact walkback B: revert only the second list-building scan from byte offset to typed index, while retaining the exact first scan and reviewed object layout. This tests whether the second cursor is independently required. [same emitted code as probe 216]
```
<!-- end-recovered:202734c4d530bd96ddc2 -->

<!-- recovered:416eaf14de22ff7b734e -->
### `25eae7bf7cb5` `src/scratch/004AB300_set_unit_player.cpp:1-68`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004AB300 TRIBE_Screen_Sed::set_unit_player
// Exact-finish log:
// - Baseline: 850 rebuilt bytes versus 879 original bytes, frame 0x10 versus 0x0C.
// - Decisive: short output and selected locals restored the original homes and frame.
// - Decisive: a guarded do/while scan restored test-before-offset initialization.
// - Decisive: direct indexed records restored the original 0x66 index arithmetic.
// - Decisive: long get_string ID restored the original virtual-call schedule.
// - ABI: RGE_Base_Game::master_obj_id is at +0x3FC after its vptr.
// - First exact checkpoint: 0.0000% positional difference, 2026-08-17.
// - Walkback: long get_string ID, short locals, guarded scan, and direct records are required.
// - Walkback: the expanded screen and base declaration surfaces were incidental.
// - Policy audit: canonical TScreenPanel inheritance remains exact.
// Policy repair:
// - Replaced RGE_Base_Game fake slots with the reviewed named prefix and fields.
// - Replaced generated TListPanel padding slots with the named TPanel/TTextPanel/TListPanel surface.
// - Replaced screen offset gaps with reviewed TRIBE_Screen_Sed fields and base types.
// - Replaced master-object byte cursors with typed indexed array access.
// - Canonical declarations retain exact size, frame, calls, and all but five bytes.
// - The remaining five bytes are VC5's zero/count initialization order in the first
//   natural indexed scan. The raw byte cursor is exact but is not policy-valid.
// TU audit:
// - PDB evidence places this function in scr_sed.cpp after the exact comparator
//   at 004AB2D0. The comparator body was restored before this function as a test.
// - Repository evidence supports the nested List_Info type and full player,
//   master-object, view, map, panel, and base-game surfaces. Those surfaces did
//   not change the five-byte hunk. An earlier broad TTextPanel context changed
//   the call surface and was rejected; the focused four-slot audit below is
//   codegen-neutral.
// - Tested 512 ambient declaration counts, exact donor macros, standard header
//   order and placement, external declaration order, exact donor ABI widths,
//   and the preceding comparator. All valid context variants stayed in one
//   five-byte codegen group.
// - The pinned period flags remain /nologo /c /O2 /Oy. Prior /Od history was
//   broad and did not preserve the target shape.
// - TU conclusion: local evidence does not recover a natural context that
//   changes this zero/count scheduling. Keep this policy-valid baseline.
// Object audit:
// - FPO and current debug metadata match the 879-byte body, 0xC frame, saved
//   registers, parameter count, and VC5 compiler. PDB shows no inline frame.
// - The raw-cursor exact form remains rejected. No object record supports a
//   different natural owner for the five-byte instruction-order difference.
// Panel audit:
// - Moved the four reviewed set_text slots to TTextPanel and removed the
//   one-slot TListPanel facade. The target codegen stayed unchanged.
// - Replaced remaining generic panel slot pointer types with the reviewed
//   TDrawArea, TPanel, text, button, input, edit, scrollbar, and slider types.
//   The target codegen stayed unchanged.
// - No generic panel slots or padding macros remain in this source.
// Frontier audit (sa-8c9700ac-r1, 20 probes):
// - PDB names val as short, i as short at VFRAME+8, j as short at VFRAME-12,
//   and end_i/default_item as overlapping short locals. It names no master
//   array or object local. The target PDB assigns both frontier instructions
//   to closing line 2172, so it does not prove their source order.
// - Canonical RGE_Player ownership remains master_object_num at +0x22 and the
//   typed master_objects pointer array at +0x24. Canonical TPanel/TTextPanel,
//   TListPanel, and TScreenPanel surfaces preserve all panel call slots.
// - Declaration scope, index/count order, short/int/long count width, typed
//   pointer-plus-index spelling, shared index lifetime, update spelling, and
//   do/while/for loop forms were compiled and checked. Natural variants either
//   stayed in the 879-byte five-byte group or lost the target loop topology.
// - Exact same-TU neighbors at 004AB2D0 and 004AB670, plus exact set_player and
//   create_list donors, support the current ownership and period source model.
//   They provide no evidence for a natural zero-before-count scheduling rule.
// - BINARY NOTE: the original emits xor ecx,ecx then movsx edx,di at +0xE8;
//   every policy-valid direct-array form emits the reverse order. The exact
//   byte-offset cursor donor is not retained because it is not canonical typed
//   array source. Keep this clean five-byte frontier.
// FLAGS: default config/flags/default.rsp (/nologo /c /O2 /Oy).
```
<!-- end-recovered:416eaf14de22ff7b734e -->

<!-- recovered:6944299b994d309b9fed -->
### `25eae7bf7cb5` `src/scratch/004AB300_set_unit_player.cpp:176-178`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Keep the helper declarations on the owning classes used by the exact
// player/view methods.  These are separate game-state surfaces in the
// original TU, even though all four methods use the same player object.
```
<!-- end-recovered:6944299b994d309b9fed -->

<!-- recovered:8c854f3c205e07193205 -->
### `25eae7bf7cb5` `src/scratch/004AB300_set_unit_player.cpp:269-270`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Canonical TPanel/TTextPanel/TListPanel surfaces from the reviewed UI donors.
// The target uses only TListPanel::set_text at virtual slot +0xE0.
```
<!-- end-recovered:8c854f3c205e07193205 -->

<!-- recovered:33972c52199ddd427939 -->
### `25eae7bf7cb5` `src/scratch/004AB300_set_unit_player.cpp:485-486`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // These are the canonical TTextPanel slots.  Keep text ownership on the
    // text panel instead of declaring a one-slot TListPanel facade.
```
<!-- end-recovered:33972c52199ddd427939 -->

<!-- recovered:5429f83b5e826230db29 -->
### `25eae7bf7cb5` `src/scratch/004AB300_set_unit_player.cpp:655-670`

Mapping: `exact`. historical standalone source path names this target VA.

```text
                // BINARY NOTE: direct indexing preserves the four-byte pointer stride.
// [non-comment lines omitted during migration]
        // BINARY NOTE: the offset zero store follows the positive-count test.
```
<!-- end-recovered:5429f83b5e826230db29 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
