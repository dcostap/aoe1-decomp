# Function notes: 00534A00 `ProcessQueuedBlit`

Module notes: `decomp_notes/view_module.md`.

## Recovered attempt history

<!-- recovered:e5e1464b5f31cc1196aa -->
### `target-session` `build/target_sessions/00534A00_ProcessQueuedBlit.json:1-129`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=199; shape=75.32467532467533: Baseline canonical typed COM/RECT source after claim; confirm current metrics and first mismatch.
probe 2 abi; result=MISMATCH; diff=199; shape=75.32467532467533: ABI probe: mark ProcessQueuedBlit protected, matching original Ghidra decorated IAEXH symbol rather than public QAEXH. [same emitted code as probe 1]
probe 4 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: Liveness probe: name the constant BltFast flags argument to test whether VC5 delays source-address materialization and reuses EBP. [same emitted code as probe 2]
probe 7 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_103201: 5 variants, 5 invariant-eligible, 0 exact
probe 8 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: Natural local declaration probe: declare the typed source RECT before the queue entry pointer to test EBP/address liveness; keep only if it reduces the extra EBX save. [same emitted code as probe 7]
probe 10 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: Natural scope probe: move the source RECT declaration to function scope while keeping its guarded use; test whether VC5 selects the original EBP local-address basin. [same emitted code as probe 8]
probe 12 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: Natural ABI probe: make the proven post-call force-home store address-taken through an int pointer; test whether VC5 preserves the original result store and post-call register order without volatility. [same emitted code as probe 10]
probe 14 context; result=MISMATCH; diff=199; shape=75.32467532467533: Canonical TU-context probe: restore the proven 13-slot TPanel virtual surface used by adjacent view.cpp donors and test whether class context changes the COM/register basin. [same emitted code as probe 12]
probe 16 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: Natural pointer-scope probe: declare the queue entry pointer at function scope and assign it inside the valid-index guard; test pointer-home lifetime against the original EBP/EBX basin. [same emitted code as probe 14]
probe 17 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_103631: 640 variants, 640 invariant-eligible, 0 exact
probe 20 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: Natural destination-coordinate locals after RECT stores; test whether precomputing both call coordinates frees EDX before the COM vtable load and removes the extra EBX save. [same emitted code as probe 19]
probe 22 context; result=MISMATCH; diff=195; shape=73.07692307692308: Natural period header context probe: add <string.h> before the reviewed typed COM/RECT declarations and test whether VC5 changes the save/register and call scheduling basin.
probe 24 layout; result=MISMATCH; diff=199; shape=75.32467532467533: Natural TDrawArea ownership probe: restore its period polymorphic surface while preserving DrawSurface at +0x3C; test whether the true class surface changes ProcessQueuedBlit register allocation. [same emitted code as probe 20]
probe 26 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: Combined natural source shape: compute destination coordinates, then cache the DrawSurface, then invoke BltFast through that cache; test whether statement order frees EDX before the virtual call. [same emitted code as probe 24]
probe 28 control-flow; result=MISMATCH; diff=199; shape=74.02597402597402: Natural final-bound operand-order probe: put Blit_Queue_Size on the left to reproduce the original size-first load and compare topology.
probe 30 context; result=MISMATCH; diff=195; shape=73.07692307692308: Natural SDK-context combination probe: use the pinned windows.h RECT and string.h declarations together, then test whether the historical view.cpp header basin changes the COM scheduling. [same emitted code as probe 22]
probe 32 abi; result=MISMATCH; diff=199; shape=75.32467532467533: Natural DirectDraw ABI-surface probe: restore the full IDirectDrawSurface virtual method prefix after the used slots, preserving the reviewed BltFast/GetBltStatus slots. [same emitted code as probe 26]
probe 34 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: Natural result-local probe: bind BltFast's int result, then assign it to the dead force parameter; test whether VC5 preserves the original parameter-home store and register reuse. [same emitted code as probe 32]
probe 37 baseline; result=MISMATCH; diff=199; shape=75.32467532467533: Claim baseline: pinned natural typed COM/RECT source; target spans and instruction causes reviewed before new probes. [same emitted code as probe 36]
probe 38 abi; result=MISMATCH; diff=199; shape=75.32467532467533: H1: use natural long result local before assigning force; tests return-width/local-home scheduling against the observed post-call stack store. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H2: cache render_area and its DrawSurface immediately before BltFast; tests natural receiver ownership and register reuse without a fake ABI. [same emitted code as probe 38]
probe 40 liveness; result=MISMATCH; diff=206; shape=74.02597402597402: H3: carry Current_Blit through a named local index; tests whether the original loop index had a distinct source lifetime and final-check reuse.
probe 41 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H4: use a natural TDrawArea reference for both BltFast receiver and source argument; tests reference ownership against the original ECX receiver schedule. [same emitted code as probe 39]
probe 42 liveness; result=MISMATCH; diff=203; shape=71.42857142857143: H5: name both proven blit offsets before RECT and destination expressions; tests whether shared offset lifetimes recover the original EDX/ECX schedule.
probe 43 context; result=MISMATCH; diff=195; shape=73.07692307692308: H6: restore period string/memory header context before the reviewed declarations; tests front-end TU state without changing the body. [same emitted code as probe 30]
probe 44 context; result=MISMATCH; diff=195; shape=73.07692307692308: H7: include the repository period type forward-declaration context before local reviewed types; tests whether broad view.cpp declaration state changes the VC5 basin. [same emitted code as probe 43]
probe 45 control-flow; result=MISMATCH; diff=199; shape=75.32467532467533: H9: combine the force/status predicate into one natural short-circuit guard; tests whether the original branch block came from a combined expression. [same emitted code as probe 41]
probe 46 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H10: materialize a typed source pointer after all RECT stores and pass it to BltFast; tests whether delayed address-taking recovers the original EBP source-top lifetime. [same emitted code as probe 45]
probe 47 context; result=MISMATCH; diff=195; shape=73.07692307692308: H11: use the period Windows RECT plus string/memory header combination; tests supported SDK declaration context with the canonical body. [same emitted code as probe 44]
probe 48 abi; result=MISMATCH; diff=199; shape=75.32467532467533: H12: bind the DirectDraw receiver as a typed reference and pass its address as the source surface; tests a natural COM receiver lifetime without manual vtable calls. [same emitted code as probe 46]
probe 49 layout; result=MISMATCH; diff=199; shape=75.32467532467533: H13: use int-width RECT fields instead of long aliases; tests the only remaining same-width signed field-type axis without changing layout. [same emitted code as probe 48]
probe 50 layout; result=MISMATCH; diff=199; shape=75.32467532467533: H14: test unsigned RECT field provenance; width and layout remain fixed, while signedness can change VC5 extension and register scheduling. [same emitted code as probe 49]
probe 51 control-flow; result=MISMATCH; diff=199; shape=75.32467532467533: H15: express the proven shared queue-failure tail with nested positive guards and one local finish label; tests block topology while preserving all three failure edges. [same emitted code as probe 50]
probe 52 abi; result=MISMATCH; diff=199; shape=75.32467532467533: H16: add explicit proven long-width casts at RECT field reads; tests whether VC5 preserves a source-level widening boundary before additions. [same emitted code as probe 51]
probe 53 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H17: expand the Current_Blit increment into an ordinary assignment; tests whether the shipped inc/store order depends on compound increment syntax. [same emitted code as probe 52]
probe 54 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H18: use compound assignment for Current_Blit; tests a distinct VC5 assignment-lowering form against the original inc instruction. [same emitted code as probe 53]
probe 55 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H19: use prefix increment for Current_Blit; tests whether source result-use semantics affect VC5's saved-register color. [same emitted code as probe 54]
probe 56 control-flow; result=MISMATCH; diff=199; shape=75.32467532467533: H20: bind the final Current_Blit-plus-one predicate to a natural next-index local; tests whether the original final compare retained a distinct temporary.
probe 58 context; result=MISMATCH; diff=209; shape=76.0: H1 new: combine exact neighboring draw.cpp TDrawArea field/method surface with the full period TPanel virtual prefix; tests whether the adjacent render TU declaration basin changes COM liveness.
probe 60 context; result=MISMATCH; diff=195; shape=73.07692307692308: H2 new: use the repository VC5 windows.h RECT declaration without string/memory headers; tests whether the native SDK RECT basin alone changes address-taking and COM scheduling. [same emitted code as probe 47]
probe 62 context; result=MISMATCH; diff=199; shape=75.32467532467533: H3 new: add the exact neighboring draw.cpp ambient extern and helper-type declarations, without bodies or target use; tests whether original view.cpp front-end declaration state controls the save/register basin. [same emitted code as probe 57]
probe 64 abi; result=MISMATCH; diff=199; shape=75.32467532467533: H4 new: model the period SDK aliases RECT/LPRECT/DWORD at the COM signature and local source rectangle; tests alias-driven call scheduling without changing proven widths. [same emitted code as probe 62]
probe 66 layout; result=MISMATCH; diff=209; shape=76.0: H5 new: restore the complete period TDrawArea data surface from adjacent Clear.cpp, including real DrawSystem and render fields; tests whether owning-class extent, not a gap overlay, changes the COM receiver basin.
probe 68 context; result=MISMATCH; diff=199; shape=75.32467532467533: H6 new: add exact neighboring RGE_View nonvirtual method declarations in original source order (update/CreateBlitQueue/draw_view/draw); tests method-context state without adding fake helpers or body code. [same emitted code as probe 64]
probe 70 context; result=MISMATCH; diff=199; shape=75.32467532467533: H7 new: compile the exact adjacent CreateBlitQueue source body before ProcessQueuedBlit with its proven render_rect owner; tests whether original view.cpp preceding-function state changes target register coloring. [same emitted code as probe 68]
probe 72 abi; result=MISMATCH; diff=199; shape=75.32467532467533: H8 new: use the period RGE_View long scalar convention for ProcessQueuedBlit's wait/force parameter; tests whether source parameter width/lifetime preserves the original post-call home store. [same emitted code as probe 70]
probe 74 context; result=MISMATCH; diff=195; shape=73.07692307692308: H9 new: add exact neighboring CreateBlitQueue's stdlib header context alone; tests allocator declaration state as a VC5 front-end basin without changing target source semantics. [same emitted code as probe 60]
probe 76 control-flow; result=MISMATCH; diff=199; shape=75.32467532467533: H10 new: express the final queue completion as Current_Blit < (Blit_Queue_Size - 1), testing threshold ownership and VC5 load order separately from prior operand reversal.
probe 78 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H11 new: bind a natural RECT reference immediately before the COM call and pass its address; tests whether reference ownership delays source-address materialization without a pointer wrapper. [same emitted code as probe 72]
probe 80 abi; result=MISMATCH; diff=199; shape=75.32467532467533: H12 new: use period HRESULT typedef returns across the exact DirectDraw interface, including BltFast/GetBltStatus; tests COM result ownership and optimizer treatment without ABI width changes. [same emitted code as probe 78]
probe 82 context; result=MISMATCH; diff=199; shape=75.32467532467533: H13 new: mirror the exact adjacent draw.cpp RGE_View declaration surface by removing unused derived virtual declarations and retaining only TPanel's proved prefix. [same emitted code as probe 80]
probe 84 context; result=MISMATCH; diff=195; shape=73.07692307692308: H14 new: compile the exact matching same-TU view.cpp pick reconstruction before ProcessQueuedBlit; tests whether a real neighboring function body and its API declarations alter VC5 COM liveness. [same emitted code as probe 74]
probe 86 abi; result=MISMATCH; diff=199; shape=75.32467532467533: H15 new: make the proven read-only queue entry pointer const; tests alias analysis and source-member liveness around the COM call without changing layout or ownership. [same emitted code as probe 82]
probe 89 variant; result=MISMATCH; diff=199; shape=75.32467532467533: H1-H4 fresh lab 20260817_173819: 24 size/frame/call-set eligible variants tested queue record pointer, four clipping +1 spellings, direct versus aliased COM receiver, and RECT lifetime before/inside the index guard. All compiled to one 219B group, diff=199, first mismatch +3; no source axis changed the extra EBX save. [same emitted code as probe 88]
probe 90 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H5 fresh lab 20260817_173930: swapped queue-entry and local-RECT declaration order to test real temporary lifetimes and entry ownership. Both size/frame/call-set variants emitted the same 219B group, diff=199, first mismatch +3. Declaration order is not the blocker. [same emitted code as probe 89]
probe 91 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H6 fresh lab 20260817_174002: moved the real tagRECT local from the guarded block to function scope. Both natural scope forms stayed one 219B group, diff=199, first mismatch +3. The local lifetime does not explain the original EBP versus EBX color. [same emitted code as probe 90]
probe 92 abi; result=MISMATCH; diff=199; shape=75.32467532467533: H7 fresh lab 20260817_174037: represented the queue record as a pointer or a reference, while retaining the proven 32-byte src/dest layout and API call order. Both variants emitted one 219B group, diff=199, first mismatch +3. Pointer ownership is supported; reference ownership does not change the basin. [same emitted code as probe 91]
probe 93 control-flow; result=MISMATCH; diff=199; shape=75.32467532467533: H8 fresh lab 20260817_174114: compared post-status Current_Blit++ with explicit Current_Blit = Current_Blit + 1. Both natural update forms emitted one 219B group, diff=199, first mismatch +3. The increment spelling does not control the saved-register basin. [same emitted code as probe 92]
probe 94 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H9 fresh lab 20260817_174144: compared assigning BltFast's result to the dead force parameter with an explicit discarded result. Both variants emitted one 219B group, diff=199, first mismatch +3. The original post-call parameter-home store remains a translation-unit/codegen artifact, not a real result lifetime in this isolated source. [same emitted code as probe 93]
probe 95 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H10 fresh lab 20260817_174217: introduced named dest-left and dest-top temporaries before BltFast versus direct member expressions. Both size/frame/call-set variants emitted one 219B group, diff=199, first mismatch +3. Destination coordinate temporary lifetime is not controlling. [same emitted code as probe 94]
probe 96 abi; result=MISMATCH; diff=199; shape=75.32467532467533: H11 fresh lab 20260817_174254: used a literal 16 or a named unsigned long blit_flags for BltFast. Both natural ABI forms emitted one 219B group, diff=199, first mismatch +3. The flags value does not change API setup or register pressure. [same emitted code as probe 95]
probe 97 control-flow; result=MISMATCH; diff=199; shape=75.32467532467533: H12 fresh lab 20260817_174325: changed the final completion guard from Current_Blit + 1 < Blit_Queue_Size to Current_Blit < Blit_Queue_Size - 1. Both stayed 219B/diff=199/first +3; the size-minus-one form only improved edit resync 66->53 and is not an exactness lead. [same emitted code as probe 96]
probe 98 control-flow; result=MISMATCH; diff=199; shape=75.32467532467533: H13 fresh lab 20260817_174400: compared the nested force/status early-return guard with one combined && predicate. Both natural forms emitted one 219B group, diff=199, first mismatch +3. The positive status gate topology is not the source of the extra save. [same emitted code as probe 97]
probe 100 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175008: 5 variants, 5 invariant-eligible, 0 exact
probe 101 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175039: 5 variants, 5 invariant-eligible, 0 exact
probe 102 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175055: 5 variants, 5 invariant-eligible, 0 exact
probe 103 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175111: 25 variants, 25 invariant-eligible, 0 exact
probe 104 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175138: 25 variants, 25 invariant-eligible, 0 exact
probe 105 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175228: 7680 variants, 7680 invariant-eligible, 0 exact
probe 106 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175357: 7680 variants, 5120 invariant-eligible, 0 exact
probe 107 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175809: 6 variants, 6 invariant-eligible, 0 exact
probe 108 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175926: 10 variants, 10 invariant-eligible, 0 exact
probe 109 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_175950: 6 variants, 6 invariant-eligible, 0 exact
probe 110 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_180007: 5 variants, 5 invariant-eligible, 0 exact
probe 111 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_180118: 5 variants, 5 invariant-eligible, 0 exact
probe 112 variant; result=MISMATCH; diff=199; shape=75.32467532467533: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260817_180151: 5 variants, 5 invariant-eligible, 0 exact
probe 114 abi; result=MISMATCH; diff=199; shape=75.32467532467533: Source-gate audit: corrected BltBatch to canonical DDBLTBATCH*, DWORD, DWORD while preserving slots 7/13, and replaced force-home alias with a natural ignored BltFast result. [same emitted code as probe 113]
probe 115 abi; result=MISMATCH; diff=195; shape=73.07692307692308: Source-gate canonicalized the DirectDraw surface to period windows.h/ddraw.h declarations. Native DDBLTBATCH keeps BltFast at slot 7 and GetBltStatus at slot 13; BltFast result remains naturally ignored. [same emitted code as probe 84]
probe 116 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: Used a plain ignored BltFast call statement, not a force assignment or no-effect alias. Native ddraw slots and call order remain unchanged. [same emitted code as probe 115]
probe 118 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H1 nested the proven outer Queued_Blits positive guard, matching the decompiler topology without changing calls or fault order. [same emitted code as probe 117]
probe 119 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: H2 declared the typed RECT before the queue-record pointer within the natural queue-range block, testing PDB local order. [same emitted code as probe 118]
probe 120 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: H3 moved the typed RECT to function scope, matching the PDB-visible local lifetime without adding initialization or changing fault order. [same emitted code as probe 119]
probe 121 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H4 combined the force test and native GetBltStatus predicate, a natural short-circuit form from the original decomp. [same emitted code as probe 120]
probe 122 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H5 used the explicit nonzero queue guard from the period decompiler source, with the same nested control flow. [same emitted code as probe 121]
probe 123 liveness; result=MISMATCH; diff=197; shape=67.94871794871794: H6 tested canonical RECT field declaration order left/top/right/bottom against the observed top/left/bottom/right PDB band.
probe 124 abi; result=MISMATCH; diff=195; shape=73.07692307692308: H7 used the SDK RECT alias instead of tagRECT for the local, testing native period declaration spelling. [same emitted code as probe 122]
probe 125 liveness; result=MISMATCH; diff=214; shape=65.82278481012658: H8 zero-initialized the typed RECT to test whether the PDB local had aggregate initialization; this is a behavior-risk probe only.
probe 127 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: H9 widened the queue-record pointer to function scope, matching the decompiler's pBVar3 local lifetime while keeping typed indexed ownership. [same emitted code as probe 124]
probe 128 abi; result=MISMATCH; diff=195; shape=73.07692307692308: H10 used RECT rather than tagRECT for the inner local record, keeping the native SDK type and natural queue scope. [same emitted code as probe 127]
probe 131 abi; result=MISMATCH; diff=195; shape=73.07692307692308: H11 tested the alternate period-sized long force parameter, while retaining native COM calls and no parameter-home reuse. [same emitted code as probe 130]
probe 132 abi; result=MISMATCH; diff=195; shape=73.07692307692308: H12 replaced literal 16 with the native DDBLTFAST_WAIT flag macro, testing period DirectDraw spelling. [same emitted code as probe 131]
probe 133 abi; result=MISMATCH; diff=195; shape=73.07692307692308: H13 replaced GetBltStatus literal 1 with native DDGBS_CANBLT, preserving the documented status gate. [same emitted code as probe 132]
probe 134 layout; result=MISMATCH; diff=195; shape=73.07692307692308: H14 widened proven 32-bit queue and offset members to period LONG types, testing canonical Windows integer ownership. [same emitted code as probe 133]
probe 135 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H15 expanded Current_Blit post-increment into explicit addition, testing the original line-1262 update spelling. [same emitted code as probe 134]
probe 136 control-flow; result=MISMATCH; diff=195; shape=71.7948717948718: H16 reversed the final remaining-queue comparison to size-greater-than-index-plus-one, testing the decompiler operand direction.
probe 138 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H17 tested prefix increment for Current_Blit against the shipped inc/store/update band. [same emitted code as probe 135]
probe 139 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H18 added the natural braced single-return tail after the BltFast call, testing source block scope. [same emitted code as probe 138]
probe 140 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H19 used the natural negated force predicate from the decompiler's param==0 gate. [same emitted code as probe 139]
probe 141 layout; result=MISMATCH; diff=195; shape=73.07692307692308: H20 used typed pointer addition for the 32-byte queue record, testing period array lowering without raw cursor arithmetic. [same emitted code as probe 140]
probe 145 layout; result=MISMATCH; diff=195; shape=73.07692307692308: H1 used an explicit RECT pointer cast to &src.top, matching the decompiler's address-taken field while preserving the proven four-dword call buffer.
probe 146 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: H2 introduced a named source-RECT pointer after all coordinate stores; tests whether a source-level pointer lifetime reproduces the original delayed LEA without changing the call ABI. [same emitted code as probe 144]
probe 147 layout; result=MISMATCH; diff=195; shape=73.07692307692308: H3 replaced the gap-only TDrawArea with the donor-proven period field surface through DrawSurface and SurfaceDesc; tests whether canonical owner context changes the save/register basin. [same emitted code as probe 146]
probe 148 liveness; result=MISMATCH; diff=199; shape=75.32467532467533: H4 removed the queue-entry alias and used direct typed indexed member expressions for every source and destination field; tests whether pointer lifetime caused EBX retention. [same emitted code as probe 114]
probe 149 layout; result=MISMATCH; diff=195; shape=73.07692307692308: H5 modeled the proven 32-byte queue record as two four-word arrays rather than RECT members; tests whether flat word ownership reproduces the original pointer-plus-SIB lowering. [same emitted code as probe 147]
probe 150 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: H6 kept the source RECT declaration before the queue-entry pointer, testing declaration-order pressure on the call block and saved register colors. [same emitted code as probe 149]
probe 151 abi; result=MISMATCH; diff=195; shape=73.07692307692308: H7 cached DrawSurface in a local used as both COM receiver and source argument; tests whether one surface identity reduces the extra receiver/vtable register. [same emitted code as probe 150]
probe 152 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H8 used the compact negated force predicate instead of equality-to-zero, testing whether the first status guard source form changes condition lowering or source line scheduling. [same emitted code as probe 151]
probe 153 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H9 split the queue, negative-index, and upper-bound tests into explicit guards with a shared clear label; tests whether original short blocks were source-nested rather than a combined predicate. [same emitted code as probe 152]
probe 154 liveness; result=MISMATCH; diff=196; shape=72.36842105263158: H10 named the incremented queue index and reused it for bounds, entry indexing, and final continuation; tests whether original index carry or field reload drives the body topology.
probe 155 control-flow; result=MISMATCH; diff=195; shape=73.07692307692308: H11 switched the Current_Blit update to prefix increment, testing whether VC5 preserves source update position or uses a different value-flow basin. [same emitted code as probe 153]
probe 156 control-flow; result=MISMATCH; diff=195; shape=71.7948717948718: H12 reversed the final continuation comparison to size-left greater-than-index-plus-one, directly testing the original size-first load and JL operand order. [same emitted code as probe 136]
probe 157 liveness; result=MISMATCH; diff=195; shape=73.6842105263158: H13 cached Blit_Queue_Size inside the valid-entry block and reused it for the final continuation; tests whether original size-first reload is a named local lifetime.
probe 158 abi; result=MISMATCH; diff=195; shape=73.07692307692308: H14 widened both the declaration and definition force parameter to long, testing period Windows LONG declaration context with the same stack ABI. [same emitted code as probe 155]
probe 159 layout; result=MISMATCH; diff=195; shape=73.07692307692308: H15 changed all queue-state and offset members to period LONG, preserving proven 32-bit signed widths while testing declaration-type context and member load scheduling. [same emitted code as probe 158]
probe 160 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: H16 assigned the BltFast HRESULT to the already-dead force parameter, testing the original decompiler-observed post-call parameter-home store as natural source liveness. [same emitted code as probe 159]
probe 161 liveness; result=MISMATCH; diff=183; shape=76.0: H17 forced the BltFast result into a volatile local, testing whether the original parameter-home store reflects required result liveness rather than TU-specific dead-store behavior.
probe 162 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: H18 materialized destination left and top into separate locals before the COM call, testing explicit left-first source evaluation and its register-color effect. [same emitted code as probe 160]
probe 163 abi; result=MISMATCH; diff=214; shape=72.72727272727273: H19 cached the render-area owner only for the source-surface argument while keeping the receiver direct; tests distinct receiver/source alias scheduling.
probe 164 abi; result=MISMATCH; diff=195; shape=73.07692307692308: H20 cached render_area and DrawSurface only in the status guard, testing whether receiver aliasing before the second call changes the original prologue and saved-register pressure. [same emitted code as probe 162]
probe 165 variant; result=MISMATCH; diff=195; shape=73.07692307692308: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260822_125031: 640 variants, 640 invariant-eligible, 0 exact
probe 166 variant; result=MISMATCH; diff=195; shape=73.07692307692308: variant lab build\variant_lab\00534A00_ProcessQueuedBlit\20260822_125112: 5 variants, 5 invariant-eligible, 0 exact
probe 167 layout; result=MISMATCH; diff=195; shape=73.07692307692308: H21 re-tested the decompiler's &src.top call with an explicit RECT cast and captured its emitted address and local-slot effect for the odd original stack layout. [same emitted code as probe 145]
probe 168 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: H22 kept a source pointer alias but passed pointer-plus-zero, testing whether an explicit typed pointer expression prevents VC5 from hoisting the RECT LEA across the flags push. [same emitted code as probe 164]
probe 169 abi; result=MISMATCH; diff=195; shape=73.07692307692308: H23 cached the COM receiver only, while retaining a direct source-surface argument; tests whether receiver liveness alone selects ECX and removes the extra vtable save. [same emitted code as probe 168]
probe 170 liveness; result=MISMATCH; diff=195; shape=73.07692307692308: H25 took the force parameter address and assigned BltFast through that pointer, testing the proven post-call parameter-home store with nonvolatile natural source liveness. [same emitted code as probe 169]
probe 172 liveness; result=MISMATCH; diff=195; shape=77.02702702702703: H1 assigned the natural BltFast result to the dead force parameter, testing the proven post-call parameter-home store in the current typed source.
probe 173 abi; result=MISMATCH; diff=195; shape=77.02702702702703: H3 used the period minimal IDirectDrawSurface declaration with typed BltFast/GetBltStatus slots, testing source-header declaration context without native ddraw.h. [same emitted code as probe 172]
probe 174 layout; result=MISMATCH; diff=195; shape=77.02702702702703: H4 restored the full proven TPanel field surface and period member names, testing field-aware alias context while preserving the 0xF4 base layout. [same emitted code as probe 173]
probe 179 context; result=MISMATCH; diff=195; shape=77.02702702702703: Built a generated view.cpp-context wrapper under build/experiments with the configured exact view anchors 00534100..00538590 and target body, pinned view flags, and native ddraw.h. All grouped anchors compile, target owner is ?ProcessQueuedBlit@RGE_View@@IAEXH@Z, target remains 215 bytes / 191 differing bytes in the extra-EBX basin. This confirms the current configured TU context does not recover the original no-EBX schedule; do not alter source or config. [same emitted code as probe 178]
```
<!-- end-recovered:e5e1464b5f31cc1196aa -->

<!-- recovered:43e88bf50a89fc0db488 -->
### `912332e8f578` `src/scratch/00534A00_ProcessQueuedBlit.cpp:1-190`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_View::ProcessQueuedBlit (00534A00)
// PDB source: view.cpp:1218-1318
// Size: 219 bytes
//
// Attempt log:
// - Old parked state: wrong ss slot mapping (src.right written to index 3),
//   missing src.bottom entry, ss[5]-induced sub esp,14h frame. Rewrote from scratch.
// - Canonical ownership (ground truth): render_area(TDrawArea*)@+0x20,
//   DrawSurface(IDirectDrawSurface*)@TDrawArea+0x3C; Queued_Blits@+0x2D8,
//   Blit_Queue@+0x2DC, Blit_Queue_Size@+0x2E0, Current_Blit@+0x2E8,
//   Blit_Offset_X@+0x2EC, Blit_Offset_Y@+0x2F0. Blit_Queue_Entry = 32B
//   { tagRECT src; tagRECT dest; }.
// - Vtable evidence: [vtable+0x34] = GetBltStatus(this,1) (2 args __stdcall),
//   [vtable+0x1C] = BltFast(this, dest.left+OX, dest.top+OY, DrawSurface,
//   &src, 16) (6 args __stdcall) — DirectDraw surface COM calls.
// - RECT math (binary-observed field processing order top,left,bottom,right):
//   src.top = st+OY, src.left = sl+OX, src.bottom = sb+OY+1, src.right = sr+OX+1;
//   dest coords = dl+OX, dt+OY. Final check loads Blit_Queue_Size first then
//   Current_Blit+1 (size on the left of the comparison).
// - Post-call dead store of the BltFast result into the force parameter home
//   ([esp+20h] = E+4) implies the original source reused the dead force param
//   as the call-result scratch (force = BltFast(...)).
// - Probe 1 (baseline): src.bottom=BltFast + left,top,right,bottom field order:
//   diff=197, shape=67.95%; store eliminated; field order left,top,right,bottom
//   (rebuilt preserved source order -> original wrote top,left,bottom,right).
// - Probe 2 (layout, current): top,left,bottom,right field order + force=BltFast:
//   diff=195, shape=73.08%; RECT region now matches; remaining drift is the
//   extra push ebx (vtable lands in ebx instead of edx -> one extra saved reg),
//   the &src lea/push interleave (rebuilt hoists &src before push 16), dest
//   register roles, the eliminated post-call param-slot store, and final-check
//   load order (size-first vs CB-first).
// - Left in scratch: pure VC5 register/scheduling/encoding drift inside the
//   isolated scratch TU; the post-call dead store is eliminated by VC5 here but
//   was kept in the original view.cpp TU (TU-context-sensitive DSE/scheduling).
// - Continuation: reversing the final bound comparison made the branch shape
//   worse without changing the byte diff; restored the clean source.
// - Continuation: adding the proven TPanel base improved shape but worsened the
//   byte diff; the SDK ddraw.h surface, four-dword RECT buffer, narrow surface
//   local, volatile RECT, CINTERFACE/lpVtbl calls, and unused-call-result forms
//   were duplicates or worse.
// - Main-agent normalization retained the proven TPanel inheritance and base
//   render-area ownership despite the slightly worse positional metric; the
//   shape improves and canonical source remains authoritative over register
//   steering in this unresolved function.
// - Session follow-up: the size-left final-bound spelling and a late typed
//   surface local were rolled back (the former worsened CFG and the latter was
//   a codegen duplicate).  Keep this canonical COM/RECT source; remaining
//   drift is the isolated VC5 save/register and argument scheduling basin.
// FLAGS: none. Inline asm forbidden.
// Best retained source: canonical typed COM/RECT reconstruction, 219 bytes,
// frame 0x10, 2/2 calls aligned, diff=199.
// Main-agent audit confirmed canonical panel/draw-area/DirectDraw ownership;
// no dead-store or COM scheduling steering survives.
// Matching-worker continuation: an early typed surface cache worsened the
// resync basin (203 differing bytes), while restoring the full donor TPanel
// virtual surface was a codegen duplicate.  Retain the clean 219-byte source;
// the unresolved gap remains the isolated COM vtable/save-register and
// parameter-home scheduling basin, not call/ABI/layout uncertainty.
// fresh orch-view-02 pass: a late source-RECT pointer and named destination
//   coordinate locals were codegen duplicates; restored clean.
// fresh pass: 16 natural RECT/call-form variants produced four groups and no
//   exact result; all 12 size-eligible variants retained the extra EBX save.
// fresh pass: debug-context flag lab (64 variants, /Zd /Zi /Z7) produced no
//   distinct winning group or exact match; default flags remain authoritative.
// fresh pass: volatile force preserved a post-call home store and improved
//   resync by one byte but grew to 221 bytes; diagnostic only, restored.
// fresh pass: reordered RECT stores, function-scope RECT/entry locals, flat
//   long[8] queue access, and reference-parameter RECT ABI were duplicates or
//   worse; canonical typed COM/RECT source retained.
// wave21 probe: replaced gap-only panel/view declarations with the proven
//   TPanel/RGE_View field ownership, including Blt_Queue_Allocated and the
//   render rectangles; emitted code was unchanged (219B, diff=199).
// wave21 probe: added the proven RGE_View virtual dispatch declarations to
//   restore the view.h-shaped derived context; emitted code was unchanged.
// sa-f48fba19-r1 pass: the full inferred TPanel/RGE_View virtual slot surface
//   was a codegen duplicate; a late TDrawArea receiver local, address-taken
//   force-result pointer, and named source-left temporary were also duplicates.
// sa-f48fba19-r1 pass: windows.h/standard RECT context reached the prior
//   diagnostic 195-byte group but worsened shape and retained EBX; DWORD
//   BltFast signedness was duplicate. A narrow volatile force-home store
//   improved resync but grew to 221 bytes, and a late queue-size local plus
//   short-circuit early guard were duplicates; all were rolled back.
// orch-00534A00-L pass: baseline after claim remained 219B, diff=199, with
//   2/2 ordered calls and an extra EBX save from the first paired hunk.
// orch-00534A00-L pass: assigning the result to src.bottom, using an entry
//   reference, reversing destination add operands, restoring 51 RGE_View
//   slots, and using C-interface lpVtbl calls were codegen duplicates.
// orch-00534A00-L pass: windows.h RECT context reached diff=195 but reduced
//   shape and resync. Restored the canonical local RECT source; blocker is
//   TU-sensitive VC5 save/register and COM argument scheduling.
// follow-534A00-r1: exact view.cpp TPanel virtual surface and reduced RGE_View
//   surface were duplicate; positive status-gate topology was also duplicate.
// follow-534A00-r1: donor RGE_View destructor, opaque BltFast source pointer,
//   full TDrawArea extent, and IDirectDrawSurface:IUnknown inheritance were
//   each codegen duplicates; restored canonical typed ownership after each.
// Paused: the remaining mismatch is the extra EBX save and COM argument/source
//   scheduling basin; no canonical ownership or virtual-slot uncertainty remains.
// sa09-ProcessQueuedBlit reassessment: pointer arithmetic, RECT/entry declaration
//   order, aggregate and zero RECT initialization, late surface/entry aliases,
//   discarded BltFast result, explicit queued guard, reversed bound terms, and
//   SDK DWORD coordinate types were duplicates or worse. Restored this clean
//   typed source; the first mismatch remains the extra EBX save at +0003.
// sa-f2967bfc-r1 continuation: protected access matched the original IAEXH
//   symbol but did not change codegen. A named BltFast flags value was also a
//   duplicate. Restored the canonical source; the extra EBX save remains.
// sa-d5f42b52-r1 continuation: source-RECT declaration order and function scope,
//   queue-entry pointer scope, an address-taken force result, and the proven
//   TPanel virtual surface were all codegen duplicates (219B, diff=199).
//   A natural five-form source lab (surface alias, entry reference, aggregate
//   RECT, and direct queue indexing) produced only two nonexact groups; all
//   size-eligible variants retained the extra EBX save. A 128-sample neutral
//   ambient declaration sweep also produced no new group. Restore the pinned
//   source; the isolated save/register and COM scheduling basin remains.
// sa-900450cb reassessment: destination-coordinate locals, string.h and
// windows.h context, a polymorphic TDrawArea, a full DirectDraw method surface,
// a named BltFast result, and size-left final-bound spelling were each natural
// probes. They were duplicate or worse (the headers reached diff=195 with
// weaker shape). Restored the pinned 219-byte source; extra EBX save remains.

// sa-cd1ad2b3-r1 strict-span audit: the 14 spans total 199 bytes. The first
//   span is the extra EBX save. It shifts every later branch and stack home.
//   The first paired body hunk then shows early &src materialization before
//   push 16. This keeps the source-top value in EBX instead of EBP. It also
//   changes RECT stores, the receiver color, and COM push order. The final
//   hunk is separate: VC5 removes the dead BltFast result store, loads
//   Current_Blit before Blit_Queue_Size, and swaps CMP operands. The epilogue
//   has the matching EBX pop and two trailing NOPs.
// sa-cd1ad2b3-r1 H1-H20: long result, area/surface pointer and reference
//   aliases, named index and offset locals, period header contexts, combined
//   status guard, delayed RECT pointer, int/unsigned RECT fields, nested
//   failure guards, explicit casts, increment spellings, and a named final
//   index were duplicate, worse, or invalid-context probes. No probe changed
//   the 219-byte clean source basin.
// sa-cd1ad2b3-r1 conclusion: extra EBX save, COM argument/source scheduling,
//   and dead-result-store behavior remain isolated VC5/TU-context drift.
//   Restore and retain the pinned natural typed source.

// sa-7575e400-r1 context follow-up: full adjacent TDrawArea declarations,
// adjacent CreateBlitQueue and matching pick bodies, ambient draw.cpp
// declarations, SDK aliases, HRESULT returns, and removed derived virtuals
// did not change the 219-byte target basin. The full TDrawArea surface grew
// the target to 223 bytes and 209 differing bytes. Native windows.h and the
// allocator/string header contexts reached the known 195-byte group but kept
// weaker shape and the extra EBX save. A size-minus-one final threshold kept
// 199 differing bytes and improved edit resync only; it did not improve the
// strict positional result. Long force, a RECT reference, and a const queue
// entry were duplicates or invalid ABI choices. All experiments were restored.
// Source-gate audit: keep the typed queue records and native DirectDraw slot
// order from the period VC4.2 headers. Ignore the BltFast result instead of
// aliasing the force home.
// Validation: the canonical interface keeps the two ordered calls at
// vslot+0x34 and vslot+0x1C. The source-gate build remains 219 bytes with a
// 195-byte mismatch; the old extra EBX save and scheduling drift remain.
//
// sa-0cd276c8-r1 continuation: H1-H25 retested address-taken RECT forms,
// full TDrawArea fields, direct queue indexing, array-word records, local
// declaration order, surface aliases, predicate spellings, nested bounds,
// named index and queue-size lifetimes, LONG member types, result-home forms,
// destination locals, and receiver-only aliases. All retained-size variants
// kept the 219-byte / 195-difference basin and 2/2 ordered virtual calls.
// A volatile result local was diagnostic only: it reached 183 differences and
// 76.00% shape but added unsupported memory effects, so it was removed.
// A focused five-variant manual-DirectDraw context lab produced two groups;
// the best remained 199 differences. The canonical source is restored.
// Evidence conclusion: the extra EBX save starts at +0003 and shifts all
// later homes and branches. The remaining differences alter instruction
// topology, register ownership, and call argument scheduling. They are broad,
// not a localized behavior-equivalent residue. No accepted-drift case is
// supported.

// sa-d3e4876f-r1 continuation: assigning the BltFast result to force was
// eliminated by VC5. The period drawarea header did not compile with the
// proven method arity. A minimal typed DirectDraw interface was a codegen
// duplicate. A full proven TPanel field surface was also a duplicate. Each
// was restored.
// Authentic-context audit: a temporary view.cpp wrapper included the real
// view prefix and defined the exact RGE_View member. It retained the extra
// EBX save and the same COM argument schedule. No config or anchor changed.
// Fresh validation remains MISMATCH: 215 rebuilt bytes versus 219 original,
// 195 differing bytes, 2/2 ordered calls, and first mismatch at +0003.

// sa-dfd48413-r1 exact-finish audit: translation_unit_prefixes.py rejects this
// target because view.cpp has no configured target owner. A generated wrapper
// using the current view prefix and native VC5 view flags compiled the target,
// but it is not an authentic context: the prefix omits PDB owners between
// calc_draw_vars and ProcessQueuedBlit, and its grouped anchors are not exact.
// Its target stayed in the 215-byte extra-EBX basin (191 common-byte changes,
// plus the four-byte boundary gap). Do not claim this wrapper as exact context.
// Missing evidence: the complete period view.cpp source prefix and a reviewed
// grouped-owner manifest that can validate exact anchors without config edits.
```
<!-- end-recovered:43e88bf50a89fc0db488 -->

<!-- recovered:671207f54a223d8e30f0 -->
### `912332e8f578` `src/scratch/00534A00_ProcessQueuedBlit.cpp:225-227`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // RGE_View's own virtual surface is part of the original view.h context;
    // these declarations are not used by ProcessQueuedBlit, but preserve the
    // derived type's real dispatch boundary for this TU.
```
<!-- end-recovered:671207f54a223d8e30f0 -->
