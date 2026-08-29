# Recovery journal: 004B98E0 `shape_color_trans_unclipped`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Shape.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Shape.cpp`.
- Earlier recovery note: `recovery_notes/Shape_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:f22359f633da03485151 -->
### `target-session` `build/target_sessions/004B98E0_shape_color_trans_unclipped.json:1-221`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=159; shape=84.31372549019608: Clean typed split-row reconstruction baseline; verify current source before hypotheses.
probe 2 variant; result=MISMATCH; diff=137; shape=89.32038834951456: Hypothesis 1: use the exact sibling row-home topology with p2 carrying the persistent row address and one working destination cursor.
probe 3 control-flow; result=MISMATCH; diff=135; shape=90.29126213592232: Hypothesis 2: model the binary-proven shared source-advance tail with explicit labels, leaving literal and end-row arms outside that tail.
probe 5 liveness; result=MISMATCH; diff=135; shape=96.11650485436893: Hypothesis 3: reuse the dead draw-area parameter home for the persistent row pointer, matching the oracle's [esp+1C] row home.
probe 6 control-flow; result=MISMATCH; diff=132; shape=97.0873786407767: Hypothesis 4: combine the oracle row-home reuse with explicit shared source advancement and skip the shared tail for literal/end-row arms.
probe 7 variant; result=MISMATCH; diff=132; shape=97.0873786407767: Hypothesis 5: split literal end formation into a destination copy followed by compound count addition to recover the oracle's ECX count and EAX end registers. [same emitted code as probe 6]
probe 8 layout; result=MISMATCH; diff=132; shape=97.0873786407767: Hypothesis 6: use the proven 256-byte palette payload view from the exact mirror-shadow donor to test table index/value register coloring.
probe 9 layout; result=MISMATCH; diff=132; shape=97.0873786407767: Hypothesis 7: retain the typed palette view as a named local, matching the exact donor's table-view declaration and testing its liveness effect. [same emitted code as probe 8]
probe 10 variant; result=MISMATCH; diff=132; shape=97.0873786407767: Hypothesis 8: materialize the solid-run palette result as a scoped int before memset to recover the oracle's EDX index and EAX color setup. [same emitted code as probe 9]
probe 11 variant; result=MISMATCH; diff=156; shape=92.23300970873787: Hypothesis 9: express the literal bound directly as dst < dst + (count & 0xFF) to force the oracle's count-in-ECX/end-in-EAX lowering.
probe 14 variant; result=MISMATCH; diff=132; shape=95.14563106796116: Hypothesis 10: use a proven pointer-address integer end bound to test whether VC5 schedules the literal count in ECX and destination end in EAX.
probe 15 variant; result=MISMATCH; diff=132; shape=97.0873786407767: Hypothesis 11: materialize a typed palette index and int color before the solid memset to force the oracle's index/value register roles. [same emitted code as probe 13]
probe 16 liveness; result=MISMATCH; diff=132; shape=97.0873786407767: Hypothesis 12: keep one function-scope palette index across literal and solid arms to alter the index/value register basin without changing the byte ABI. [same emitted code as probe 15]
probe 17 variant; result=MISMATCH; diff=132; shape=97.0873786407767: Hypothesis 13: apply a period-plausible register qualifier to the shared palette index to test direct register color control. [same emitted code as probe 16]
probe 18 control-flow; result=MISMATCH; diff=132; shape=97.0873786407767: Hypothesis 14: let the solid arm fall through to the shared source advance, while skip jumps into it and literal/end-row arms jump around it. [same emitted code as probe 17]
probe 19 variant; result=MISMATCH; diff=163; shape=94.11764705882354: Hypothesis 15: express the literal iteration in the oracle's observed order: load source index, advance source and destination, then write the translated prior destination byte.
probe 24 baseline; result=MISMATCH; diff=137; shape=89.32038834951456: Fresh baseline after restoring the pinned natural row-pointer source; establish current codegen before probes. [same emitted code as probe 22]
probe 25 liveness; result=MISMATCH; diff=277; shape=80.55555555555556: Restore the reviewed natural row-pointer reconstruction; remove the diagnostic p2 pointer carrier and raw cursor form.
probe 26 variant; result=MISMATCH; diff=159; shape=84.31372549019608: Restore the reviewed natural row pointer with its original staged orientation and destination setup, without p2 cursor casting. [same emitted code as probe 1]
probe 27 liveness; result=MISMATCH; diff=159; shape=84.31372549019608: Natural row-pointer declaration-order probe: place row before count without parameter-home casts or cursor aliases. [same emitted code as probe 26]
probe 28 liveness; result=MISMATCH; diff=248; shape=82.52427184466019: Natural counted-row probe: assign a separate rows local inside the positive height guard, matching period sibling loop structure.
probe 29 control-flow; result=MISMATCH; diff=255; shape=85.29411764705883: Test binary-proven shared source-advance and command-done tails with typed src/dst pointers; retain no raw cursor or parameter carrier.
probe 30 variant; result=MISMATCH; diff=165; shape=82.3529411764706: Natural literal-loop post-increment probe; keep the reviewed row pointer and test only expression evaluation order.
probe 31 liveness; result=MISMATCH; diff=159; shape=84.31372549019608: Natural literal index temporary probe; test register coloring with a typed local while keeping row as a real pointer. [same emitted code as probe 27]
probe 32 layout; result=MISMATCH; diff=159; shape=84.31372549019608: Natural declaration-order probe matching the recovered source order: read Orien before width, retain typed row pointer. [same emitted code as probe 31]
probe 33 layout; result=MISMATCH; diff=159; shape=84.31372549019608: Natural typed palette payload probe from the exact Shape.cpp sibling; retain the row pointer and byte-pointer ABI.
probe 34 liveness; result=MISMATCH; diff=159; shape=84.31372549019608: Natural solid-run color local probe; test palette result register coloring without changing row ownership or source cursor model. [same emitted code as probe 32]
probe 35 variant; result=MISMATCH; diff=255; shape=85.29411764705883: Natural solid-arm statement-order probe: advance destination before source after memset, matching observed call-tail ordering. [same emitted code as probe 29]
probe 38 baseline; result=MISMATCH; diff=159; shape=84.31372549019608: Recheck claimed clean natural row-pointer source before new evidence-based probes; original disassembly and Ghidra listing now expose payload pointer advance before AlignedWidth. [same emitted code as probe 37]
probe 39 variant; result=MISMATCH; diff=159; shape=84.31372549019608: Natural payload-pointer advance probe: increment the proven Shape_Header pointer before the AlignedWidth setup, following the Ghidra payload transition. [same emitted code as probe 38]
probe 41 variant; result=MISMATCH; diff=159; shape=84.31372549019608: Natural typed payload expression probe: combine the proven header increment with payload-pointer conversion in one expression to test VC5 liveness and setup scheduling. [same emitted code as probe 39]
probe 43 layout; result=MISMATCH; diff=157; shape=84.31372549019608: Diagnostic typed payload-owner probe: keep a Shape_Header pointer at hdr+1 and read the proven preceding header through typed indexing, testing the original EDI payload/header register basin without raw addresses.
probe 45 variant; result=MISMATCH; diff=152; shape=85.29411764705883: Natural evaluation-order probe: form stride from AlignedWidth and the orientation assignment in one typed expression, testing the original ESI-before-call schedule.
probe 46 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Natural area-alias probe on the improved typed stride expression: retain one TDrawArea pointer across the setup to test early td-home loading without parameter mutation. [same emitted code as probe 45]
probe 48 variant; result=MISMATCH; diff=152; shape=85.29411764705883: Natural commutative-order probe: evaluate the orientation assignment as the left multiply operand, testing whether VC5 preserves the original EAX pitch product while retaining typed setup. [same emitted code as probe 46]
probe 49 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Natural declaration-init probe: initialize Orien at declaration, then multiply the typed AlignedWidth result, testing whether VC5 preserves the improved one-expression basin without an assignment expression. [same emitted code as probe 48]
probe 50 liveness; result=MISMATCH; diff=156; shape=82.3529411764706: Natural declaration-lifetime probe: defer the proven height calculation until after stride setup, testing whether VC5 keeps width in EBP without the improved typed expression's early home store.
probe 52 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Natural reviewed table-payload probe: view the proven byte palette as a 256-byte typed payload, matching the exact Shape.cpp sibling's ownership model while testing index/value allocation.
probe 56 variant; result=MISMATCH; diff=240; shape=84.31372549019608: Hypothesis 1: use direct td->Orien in stride while keeping named Orien for orientation branch; tests whether repeated typed member access restores original receiver preload and setup order.
probe 57 variant; result=MISMATCH; diff=251; shape=84.46601941747574: Hypothesis 2: mirror the exact Shape.cpp draw sibling's setup declaration order: form typed stride first, then header height/payload, then row locals; tests whether TU declaration order controls the target's early receiver and header schedule.
probe 59 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 3: use the exact sibling's unqualified member spelling for shape_header; tests whether same-TU member lookup form changes the early load basin without changing ownership or layout. [same emitted code as probe 55]
probe 61 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 4: narrow the orientation local to int, matching the proven TDrawArea member width; tests whether VC5's signed-width type affects setup register coloring and compare lowering. [same emitted code as probe 59]
probe 63 liveness; result=MISMATCH; diff=251; shape=84.46601941747574: Hypothesis 5: declare and initialize orientation before header height and payload; tests whether an earlier live area value causes VC5 to preload the incoming td home before callee-save pushes.
probe 65 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 6: reverse the declarations of persistent row and byte count; tests whether independent local declaration order swaps their entry-home coalescing toward the oracle. [same emitted code as probe 61]
probe 67 control-flow; result=MISMATCH; diff=255; shape=85.29411764705883: Hypothesis 7: encode the binary-proven common source-advance tail with natural local labels; literal skip and solid runs share one src increment, while literal copies fall through command_done.
probe 69 control-flow; result=MISMATCH; diff=246; shape=86.40776699029126: Hypothesis 8: express the proven counted outer scan as a for loop with a pre-test and decrement update; tests whether VC5's natural loop lowering matches the oracle's row reset and backedge.
probe 71 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 9: place the typed payload pointer after the orientation load and before the AlignedWidth expression, matching the original add-header-pointer schedule. [same emitted code as probe 65]
probe 73 variant; result=MISMATCH; diff=277; shape=80.55555555555556: Hypothesis 10: form the persistent row pointer directly in each orientation arm instead of naming a destination offset; tests whether branch-local address ownership matches the original ESI setup. [same emitted code as probe 25]
probe 75 variant; result=MISMATCH; diff=277; shape=80.55555555555556: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_162252: 64 variants, 46 invariant-eligible, 0 exact
probe 76 variant; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 11: remove redundant parentheses from the typed height expression; tests whether VC5's expression tree and operand scheduling recover the original EBP/ESI height setup. [same emitted code as probe 71]
probe 77 variant; result=MISMATCH; diff=159; shape=84.31372549019608: Hypothesis 12: stage the proven pitch calculation as an assignment followed by compound multiplication; tests whether VC5 keeps the AlignedWidth result in EAX and recovers the oracle's post-call IMUL. [same emitted code as probe 41]
probe 79 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 13: remove the named orientation local and use direct typed member expressions for stride and branch; tests whether avoiding long-lived Orien lets VC5 reuse ESI for header ymin before the call. [same emitted code as probe 76]
probe 81 context; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 15: use the exact same-TU donor's class keyword for TShape instead of struct; tests whether class declaration context changes VC5 member code generation. [same emitted code as probe 79]
probe 82 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 16: lift the per-row destination cursor declaration to function scope while retaining its assignment at row entry; tests whether the persistent typed cursor matches the oracle's ESI lifetime. [same emitted code as probe 81]
probe 83 control-flow; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 17: express the binary bottom-tested command loop as for(;;) with an explicit done break; tests an alternate natural control form without changing the command CFG. [same emitted code as probe 82]
probe 85 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 18: narrow the byte-count lifetime to one outer row iteration while keeping one shared count for both command arms; tests whether scope changes count/row parameter-home coalescing. [same emitted code as probe 83]
probe 87 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 19: scope the shared byte-count declaration to each command-loop iteration; tests whether a short count lifetime frees the td home for row while preserving both command-arm assignments. [same emitted code as probe 85]
probe 89 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 20: split the done flag declaration from its zero assignment; tests whether VC5's initialization site changes the p3 home store and row-loop branch basin. [same emitted code as probe 87]
probe 92 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 1: replace the narrow TDrawArea overlay with the reviewed 0x100-byte Drawarea.cpp API surface, including BITMAPINFO256, tagRECT, DirectDraw surface descriptor, and named ownership fields; all touched widths and offsets remain unchanged. [same emitted code as probe 52]
probe 93 layout; result=MISMATCH; diff=257; shape=85.4368932038835: Hypothesis 2: use the reviewed TShape field ownership from exact Shape.cpp siblings: Shape_File_Header, Shape_Offsets, SLhape_File_Header, and Shape_Info at the proven offsets; no touched access changes.
probe 95 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 3: isolate reviewed typed TShape ownership on the narrow baseline: Shape_File_Header, Shape_Offsets, SLhape_File_Header, and Shape_Info replace unused void* fields without changing offsets. [same emitted code as probe 92]
probe 97 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 4: replace only the unused TDrawArea API fields with their reviewed named types, BITMAPINFO256* and tagRECT, while preserving the narrow field span and all touched widths. [same emitted code as probe 95]
probe 98 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 5: model td as the reviewed class TDrawArea rather than a struct, preserving the proven narrow field surface; this tests canonical API ownership and decorated parameter identity. [same emitted code as probe 97]
probe 100 liveness; result=MISMATCH; diff=158; shape=84.31372549019608: Hypothesis 6: follow exact sibling RLE declaration order by establishing payload src before height, then keep the proven orientation/stride locals; tests whether payload lifetime changes td/width home assignment.
probe 102 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 7: combine the canonical class TDrawArea ABI with typed TShape ownership, but retain the narrow proven layouts; tests whether both real API surfaces interact in the VC5 front end. [same emitted code as probe 98]
probe 103 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 8: use the reviewed class TShape surface with public shape fields and typed ownership, matching the donor header's class form while preserving the target's public member ABI. [same emitted code as probe 102]
probe 105 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 9: declare destination offset before row and count, then declare row before the byte count; this follows the source lifetime from orientation setup to row assignment and tests a real local-order axis. [same emitted code as probe 91]
probe 106 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 10: match the exact shadow sibling's row-local order by declaring the working destination before the per-row done flag; tests whether declaration lifetime changes td/count home coalescing. [same emitted code as probe 105]
probe 108 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 11: declare the persistent row pointer before the AlignedWidth stride local, while keeping count after stride; this tests whether the row's proven td-home lifetime begins before the API call. [same emitted code as probe 106]
probe 110 context; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 12: add the real same-TU sibling shape method surface from the caller and exact donors to the local TShape class; tests whether canonical member declaration context changes the local-home basin. [same emitted code as probe 103]
probe 111 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 13: separate stride declaration from its assignment after orientation initialization; tests whether a real delayed local lifetime changes VC5's saved-register and frame allocation. [same emitted code as probe 110]
probe 113 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 14: use a real C++ bool for the end-of-row flag, supported by the Ghidra/PDB local interpretation, while retaining byte stores and tests through natural lowering. [same emitted code as probe 108]
probe 115 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 15: split the proven width declaration from its header-field assignment at the same setup point; tests whether PDB local initialization timing affects the width/stride homes. [same emitted code as probe 113]
probe 117 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 16: split the payload cursor declaration from its proven hdr+1 assignment; tests whether an explicit payload initialization site alters the td/width register schedule. [same emitted code as probe 115]
probe 120 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 1: replace the narrow TDrawArea overlay with the canonical Drawarea.cpp API field types: long dimensions, tagRECT, DrawSystem/BitmapInfo/DirectDraw pointer ownership, and full 0x100-byte span. This tests real API declaration context rather than raw offsets. [same emitted code as probe 111]
probe 122 context; result=MISMATCH; diff=257; shape=85.4368932038835: Hypothesis 2: restore the period Windows API header in the Shape.cpp translation-unit context before the proven external memset pragma. This tests whether Windows declarations change VC5 scheduling without changing the narrow field ABI. [same emitted code as probe 93]
probe 124 context; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 3: use the period memory.h CRT declaration context before pragma function(memset), distinct from the prior string.h check. This tests whether the real API header selects the original memset lowering basin. [same emitted code as probe 120]
probe 126 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 4 revised after compile correction: model the API Bits field as char* and use one explicit byte-pointer cast at the proven destination formation. This keeps behavior and tests byte pointee signedness. [same emitted code as probe 119]
probe 128 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 5: use an int row-width local because the period TDrawArea dimensions and VC5 arithmetic are four-byte API values, while the PDB width label is only a generated long candidate. This tests whether width signed width controls the early EBP spill and local homes. [same emitted code as probe 126]
probe 130 context; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 6: add the real TDrawArea member API declaration neighborhood from Drawarea.cpp (SetInfo, offset/clip/clear/size, lock/DC methods) while keeping the proven field layout. This tests class member context, not only field offsets. [same emitted code as probe 128]
probe 132 liveness; result=MISMATCH; diff=148; shape=92.15686274509804: Hypothesis 7: honor the PDB parameter-home evidence by carrying the persistent row base through td's incoming TDrawArea home after the initial API accesses, using a typed pointer cast and ordinary row advance. This is a direct diagnostic of the proven td-home role, not a new behavior model.
probe 133 liveness; result=MISMATCH; diff=148; shape=92.15686274509804: Hypothesis 8: retain the binary-proven td-home row carrier, then name the API palette index and translated byte at each use. This tests whether real byte temporaries reproduce the original EDX index plus CL/AL result colors without raw register control. [same emitted code as probe 132]
probe 135 liveness; result=MISMATCH; diff=148; shape=92.15686274509804: Hypothesis 9: remove the separate row alias and carry the computed destination directly in td's proven incoming home, then advance that typed carrier each row. This tests the smallest PDB-home source shape against the prior row-plus-td diagnostic. [same emitted code as probe 133]
probe 137 liveness; result=MISMATCH; diff=159; shape=84.31372549019608: Hypothesis 10: materialize AlignedWidth into the stride local, then compound-multiply by the saved orientation. This tests the API call result lifetime and whether VC5 preserves the original EAX-to-stride store order. [same emitted code as probe 77]
probe 139 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 11: express the proven 256-byte palette API as an array parameter instead of a byte pointer. The ABI remains a pointer, but this tests whether source array semantics select the original table-base/index register order. [same emitted code as probe 130]
probe 141 layout; result=MISMATCH; diff=148; shape=92.15686274509804: Hypothesis 12: combine the binary-proven td-home row carrier with the canonical Drawarea.cpp API class surface and long field types. This tests whether real API ownership changes the home/register basin only when the PDB local reuse is present.
probe 143 liveness; result=MISMATCH; diff=246; shape=86.40776699029126: Hypothesis 13: keep the header-derived width live through the API setup and create a fresh counted rows local only inside the positive guard. This tests the PDB delayed width-home store and separates height-test lifetime from row-loop lifetime. [same emitted code as probe 69]
probe 145 context; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 14: bind the real TDrawArea receiver to a named area alias before shape-header setup, then use that alias for all API reads and AlignedWidth. This tests natural receiver lifetime and early home loading without changing ownership or offsets. [same emitted code as probe 139]
probe 147 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 15: use the API's int orientation width for the local instead of long, matching Ghidra's int iVar2 while preserving the dword field and signed predicate. This tests local width effects on the ESI orientation and EBP height colors. [same emitted code as probe 145]
probe 149 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 16: use an int stride local, matching Ghidra's int iVar6 and the four-byte API pitch product, while retaining the long-returning AlignedWidth declaration. This tests the local ABI width without changing arithmetic behavior. [same emitted code as probe 147]
probe 151 context; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 17: restore the period stdlib.h context used by neighboring Drawarea code while keeping the local memset declaration and pragma. This tests unrelated CRT declarations as a translation-unit basin without adding behavior. [same emitted code as probe 149]
probe 153 context; result=MISMATCH; diff=257; shape=85.4368932038835: Hypothesis 18: use the combined string.h plus memory.h context found across the same-TU CRT donor family before the proven memset pragma. This tests the header combination rather than repeating either single-header basin.
probe 156 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173203: 8 variants, 8 invariant-eligible, 0 exact
probe 157 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173313: 128 variants, 64 invariant-eligible, 0 exact
probe 158 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173417: 128 variants, 64 invariant-eligible, 0 exact
probe 159 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173641: 96 variants, 48 invariant-eligible, 0 exact
probe 160 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173714: 576 variants, 192 invariant-eligible, 0 exact
probe 161 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173820: 2 variants, 2 invariant-eligible, 0 exact
probe 162 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173849: 8 variants, 6 invariant-eligible, 0 exact
probe 163 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173904: 3 variants, 3 invariant-eligible, 0 exact
probe 164 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173914: 9 variants, 9 invariant-eligible, 0 exact
probe 165 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_173955: 2 variants, 1 invariant-eligible, 0 exact
probe 166 variant; result=MISMATCH; diff=152; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260817_174031: 2 variants, 2 invariant-eligible, 0 exact
probe 168 context; result=MISMATCH; diff=257; shape=85.4368932038835: TU hypothesis 1: use the exact same-TU CRT donor surface: include <string.h> before #pragma function(memset), then declare extern-C memset. This tests header order and period declaration context, without changing target semantics. [same emitted code as probe 153]
probe 169 context; result=MISMATCH; diff=257; shape=85.4368932038835: TU hypothesis 2: restore the neighboring Shape.cpp declaration bank from exact donor 004B99F0: Shape_Offsets, Shape_File_Header/SLhape_File_Header, Shape_Info, typed TShape members, and preceding/following shape method declarations. This tests original class/member context, not body semantics. [same emitted code as probe 122]
probe 170 context; result=MISMATCH; diff=152; shape=85.29411764705883: TU hypothesis 4: model the proven neighboring Shape.cpp function order by compiling the exact-shape forward decoder before the target, with its memcpy declaration and sibling body. This tests same-TU optimizer context and member declaration order, not target behavior. [same emitted code as probe 124]
probe 171 context; result=MISMATCH; diff=257; shape=85.4368932038835: TU hypothesis 5: restore period Windows SDK context with <windows.h> before the manual memset surface. Shape.cpp's neighboring clipped routines use RECT/Windows declarations, so this tests supported header-state influence without changing the target body. [same emitted code as probe 169]
probe 172 context; result=MISMATCH; diff=257; shape=85.4368932038835: TU hypothesis 6: restore the period RECT type in TDrawArea::ClipRect, with <windows.h> context, instead of a flat byte span. The ground-truth type dump proves a RECT at +0x28; this tests real SDK type context. [same emitted code as probe 171]
probe 173 context; result=MISMATCH; diff=152; shape=85.29411764705883: TU hypothesis 7: keep the target body unchanged but restore only the ground-truth TShape pointer declaration kinds (forward-declared Shape_File_Header, Shape_Offsets, SLhape_File_Header, Shape_Info) instead of void pointers. This isolates class declaration type context. [same emitted code as probe 170]
probe 174 context; result=MISMATCH; diff=152; shape=85.29411764705883: TU hypothesis 8: restore only the original Shape.cpp TShape member function declaration order around the target, while keeping the same local field declarations and body. This isolates member-order compiler context from layout types. [same emitted code as probe 173]
probe 175 context; result=MISMATCH; diff=257; shape=85.4368932038835: TU hypothesis 9: restore the period low-level file API header <io.h>, supported by Shape.cpp constructor/load neighbors using open/read/close/tell. This tests file-scope CRT declaration state, not target semantics. [same emitted code as probe 172]
probe 176 context; result=MISMATCH; diff=152; shape=85.29411764705883: TU hypothesis 10: restore period <fcntl.h> context used by the Shape.cpp load path for open-mode constants. This tests a second supported file-API header basin without changing code semantics. [same emitted code as probe 167]
probe 177 context; result=MISMATCH; diff=152; shape=85.29411764705883: TU hypothesis 11: restore the period Windows-style min macro state used by neighboring clipped shape code, without invoking it in the target. This tests macro front-end context as a supported TU axis. [same emitted code as probe 176]
probe 178 context; result=MISMATCH; diff=152; shape=85.29411764705883: TU hypothesis 12: use public class declarations for the ground-truth Shape_Header, TDrawArea, and TShape types, matching the original type dump while preserving all offsets and access. This tests class-kind metadata without body changes. [same emitted code as probe 177]
probe 179 abi; result=MISMATCH; diff=152; shape=85.29411764705883: TU hypothesis 13: model the original TShape as a class with default-private member access, matching the PDB decorated target's private thiscall surface, while leaving the proven public draw-area field surface unchanged. This tests ABI ownership metadata without steering registers. [same emitted code as probe 178]
probe 180 abi; result=MISMATCH; diff=152; shape=85.29411764705883: TU hypothesis 14: use the ground-truth ABI class kinds together: public TDrawArea (PAV receiver) and private TShape member (AAE target), while keeping the proven body and offsets. This tests exact decorated ownership context. [same emitted code as probe 179]
probe 181 abi; result=MISMATCH; diff=152; shape=85.29411764705883: TU hypothesis 15: complete the ground-truth class declaration kinds by making Shape_Header public class too, while retaining the ABI-correct TDrawArea/TShape classes. This tests type declaration context with identical layout and bytes. [same emitted code as probe 180]
probe 182 context; result=MISMATCH; diff=294; shape=66.07142857142857: TU hypothesis 16: isolate the exact donor declaration order by placing #pragma function(memset) before the extern-C memset prototype, but omit the header already shown harmful. This tests pragma/prototype front-end order.
probe 184 other; result=MISMATCH; diff=152; shape=85.29411764705883: PDB range audit: Shape.obj S_GPROC32 starts at section 0001:000B88E0, Cb=0x10C, DebugStart=0, DebugEnd=0x100, one S_END; cvdump lines and FPO map the same 268-byte boundary. No stale range or boundary evidence. [same emitted code as probe 183]
probe 185 other; result=MISMATCH; diff=152; shape=85.29411764705883: PDB local audit: target has only this plus formal homes, drawarea/shape_x0/shape_y0/shape_num/color_table, count-like done, save_buffer, command, and one named width at BPREL -4. No S_DEFRANGE, S_REGREL32, or alternate local range records exist. [same emitted code as probe 184]
probe 186 other; result=MISMATCH; diff=152; shape=85.29411764705883: PDB block and inline audit: the complete Shape.obj symbol stream has zero S_BLOCK32, S_INLINESITE, S_LABEL32, S_FRAMEPROC, S_DEFRANGE, and S_REGREL32 records. Inline and hidden-block context cannot explain the prologue. [same emitted code as probe 185]
probe 187 other; result=MISMATCH; diff=152; shape=85.29411764705883: PDB line audit: Shape.cpp has 30 target line/address pairs from 841 through 905. The pairs cover setup, all decoder arms, row tail, and epilogue. The line map has no gap that could hide an inline or macro body. [same emitted code as probe 186]
probe 188 abi; result=MISMATCH; diff=152; shape=85.29411764705883: PDB type audit: TDrawArea is a non-polymorphic 0x100-byte class with Bits +8 PUCHAR, Height/Pitch/Orien +1C/+20/+24 INT4, and RECT +28. TShape is 0x20 bytes; the target is private thiscall, UCHAR return, five stack parameters, and zero this adjustment. [same emitted code as probe 187]
probe 189 abi; result=MISMATCH; diff=152; shape=85.29411764705883: ABI object audit: current /Z7 type records have the same touched offsets and function arity, but struct declarations emit QAEEPAUTDrawArea while the original private class emits AAEEPAVTDrawArea. Prior class/private and full typed-surface probes changed decoration only, not target code bytes; no natural ABI basin is supported. [same emitted code as probe 188]
probe 190 flags; result=MISMATCH; diff=152; shape=85.29411764705883: Compiler fingerprint audit: original Shape.obj S_COMPILE is C, Pentium, hardware FP, NEAR data/code, no PCode, Microsoft optimizing compiler 11.00. The /Z7 VC5 object reports the identical record; config CL is 11.00.7022. No compiler-version mismatch supports a source change. [same emitted code as probe 189]
probe 191 flags; result=MISMATCH; diff=152; shape=85.29411764705883: FPO/COFF audit: original EXE FPO row for 004B98E0 is Proc=268, Locals=8, Regs=4, Prolog=0, no SEH, FPO frame, Params=20. Current .debug decodes to cbProc=0x10C, two local dwords, four saved regs, zero prologue, five parameters. Frame metadata is already exact. [same emitted code as probe 190]
probe 192 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Compiler-object local audit: a fresh /Z7 object records td,p2,p3,p4,pal plus count, stride, width, row, and done; no blocks, inline sites, or range records. Its named locals consume two negative dword homes, unlike the old PDB's one named width plus an unnamed optimized home. This is allocator evidence, not a hidden aggregate. [same emitted code as probe 191]
probe 193 other; result=MISMATCH; diff=152; shape=85.29411764705883: Exact-shape object audit: current 004BA900 mirror-unclipped object has .debug Proc=0xDC, locals=0, params=3, four saved regs, matching its original FPO row; target object has the same relocation model and target FPO fields. Exact sibling evidence confirms the pinned VC5 object path. [same emitted code as probe 192]
probe 194 abi; result=MISMATCH; diff=152; shape=85.29411764705883: COFF relocation audit: target object has exactly two REL32 relocations, AlignedWidth at text offset 36 and _memset at offset 209. The original has direct calls 00444B40 and 0054DA60. No wrapper, inline helper, or wrong CRT call target explains the mismatch. [same emitted code as probe 193]
probe 195 control-flow; result=MISMATCH; diff=152; shape=85.29411764705883: Run-decoder CFG audit: original has 101 instructions, 9 conditional signals, 4 jumps, and one return. It uses one common source increment at 004B99BA for skip/solid arms; the natural candidate emits 102 instructions and one extra skip-arm increment. Calls and all major RLE blocks remain aligned, so this is localized CFG/liveness drift, not behavior uncertainty. [same emitted code as probe 194]
probe 196 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Parameter-home audit: original preloads td into EBX before callee-save pushes, then stores row through td's incoming home [esp+1C]; count uses p2's home [esp+20]; done uses p3's home [esp+24]. The natural build swaps row and count homes. History shows only explicit home casts recover this, and policy rejects those forms. [same emitted code as probe 195]
probe 197 flags; result=MISMATCH; diff=152; shape=85.29411764705883: Object metadata audit: baseline COFF .text is 0x110 bytes with a 0x10C function symbol and four trailing padding bytes; .debug is associative. A fresh /Z7 compile gives the same 0x10C symbol range and 0x10C Cb, with no hidden code or boundary escape. [same emitted code as probe 196]
probe 198 context; result=MISMATCH; diff=152; shape=85.29411764705883: Compiler/link audit: original PE reports linker 5.00, NB10 age1_x1 PDB, 1998 timestamp; current pinned LINK is 5.00.7022 and CL is 11.00.7022. Shape.obj S_COMPILE and current /Z7 S_COMPILE agree. No macro, inline, or service-pack lead is supported by repository evidence. [same emitted code as probe 197]
probe 199 other; result=MISMATCH; diff=152; shape=85.29411764705883: Shape FPO matrix audit: original draw siblings report locals/params 28/6 for shape_draw, 4/4 for shape_draw_unclipped, 8/5 for this target, 4/4 for shadow_unclipped, 8/7 for draw_clipped, and 12/9 for color_clipped. The target's 8-byte local frame is normal for this decoder family, not a missing stack allocation. [same emitted code as probe 198]
probe 200 control-flow; result=MISMATCH; diff=152; shape=85.29411764705883: Line/CFG audit: PDB line 864 writes done, line 865 is the loop test at the shared tail, and line 896 owns the single common source increment. This confirms the extra natural skip increment is a real localized source-topology mismatch, but it does not justify a non-natural goto or alias scaffold. [same emitted code as probe 199]
probe 201 other; result=MISMATCH; diff=152; shape=85.29411764705883: PDB absence audit: no macro records or inlinee-line records occur for Shape.obj, and its module has no block/label records. The old PDB cannot conceal a helper expansion or nested lexical block that would alter the prologue. [same emitted code as probe 200]
probe 202 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: PDB/object liveness conclusion: original has two local dword slots by FPO, but only one named negative local. The missing slot is an ordinary optimized or unnamed compiler home, not proof of a source aggregate. Current natural source already has the exact frame and no supported declaration axis remains. [same emitted code as probe 201]
probe 204 other; result=MISMATCH; diff=152; shape=85.29411764705883: Final no-change checkpoint: the fresh /Z7 object and original PDB both expose the same VC5 FPO shape, while only the source-selected register/home basin differs. No policy-valid edit is retained and no shared source file changed. [same emitted code as probe 203]
probe 206 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Canonical PDB declaration probe: class spellings, private TShape decoder, typed Shape payload records, typed palette offset, and typed TShape ownership. [same emitted code as probe 205]
probe 207 abi; result=MISMATCH; diff=257; shape=85.4368932038835: Full PDB TDrawArea layout probe: replace gap overlay with canonical fields and typed palette/decoder neighbors; keep ordinary row ownership. [same emitted code as probe 168]
probe 209 control-flow; result=MISMATCH; diff=255; shape=85.29411764705883: Bounded decoder correction: share the proven source-byte increment after skip and solid arms, while the end-row arm bypasses it; no row-home or parameter-home steering. [same emitted code as probe 67]
probe 211 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Typed decoder payload probe: name the Shape_Header-plus-one payload owner before byte-stream decoding; retain ordinary source cursor. [same emitted code as probe 210]
probe 212 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Canonical field-width probe: use the PDB TDrawArea int Orien type instead of a widened long local. [same emitted code as probe 211]
probe 213 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Canonical width-width probe: use an int local for the proven Shape_Header height delta and loop count. [same emitted code as probe 212]
probe 214 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Direct member payload probe: remove the named Shape_Header alias and let the decoder reread the owned header directly. [same emitted code as probe 213]
probe 215 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Typed palette ownership probe: name the incoming uchar palette pointer without altering decoder source order or row ownership. [same emitted code as probe 214]
probe 216 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Orientation liveness probe: reread the typed TDrawArea Orien field instead of keeping a named local across address setup. [same emitted code as probe 215]
probe 217 layout; result=MISMATCH; diff=277; shape=80.55555555555556: Natural destination-address probe: fold the orientation offset into each row pointer assignment instead of a separate dest_off local. [same emitted code as probe 73]
probe 219 baseline; result=MISMATCH; diff=152; shape=85.29411764705883: Claim baseline: canonical typed Shape_Header/TDrawArea/TShape source, 268B/8B, two ordered calls, 152 strict diff. [same emitted code as probe 218]
probe 220 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 1: declare the persistent row pointer before the shared byte count so natural dead-parameter home allocation follows row/count order. [same emitted code as probe 219]
probe 221 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 2: place the typed draw-area orientation read before Shape_Header width/payload declarations, matching the original decompiler ABI evaluation order and early td home preload. [same emitted code as probe 220]
probe 222 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 3: model the one-byte RLE stream as a typed Shape_Payload record, replacing the raw byte cursor while preserving bytewise decoder ABI and fault order. [same emitted code as probe 174]
probe 223 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 4: scope the shared command count inside each row, so row remains long-lived while count has only decoder-arm lifetime and can naturally take the p2 home. [same emitted code as probe 222]
probe 224 control-flow; result=MISMATCH; diff=269; shape=80.58252427184466: Hypothesis 5: follow the exact decoder sibling and Ghidra source order by mutating the y formal only in the negative orientation arm, then form one typed row address.
probe 225 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 6: declare the long-lived row pointer at function entry before header and decoder locals, testing whether canonical declaration scope/order selects the oracle td row home without a cast. [same emitted code as probe 223]
probe 226 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 7: declare the orientation destination offset before stride and decoder locals, testing whether natural local declaration order selects oracle stride EAX versus offset ESI coloring. [same emitted code as probe 225]
probe 227 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 8: use the period 32-bit int width for the row stride while retaining long-return AlignedWidth, testing whether the oracle local stride home is width-typed. [same emitted code as probe 226]
probe 228 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 9: make the command byte a function-scope local, matching the exact sibling/decompiler local surface while keeping count, done, and payload records typed. [same emitted code as probe 227]
probe 229 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 10: make the end-of-row flag function-scope and reinitialize it per row, matching the decompiler byte local while preserving the proven p3 store/fault order. [same emitted code as probe 228]
probe 230 control-flow; result=MISMATCH; diff=248; shape=86.27450980392157: Hypothesis 11: order the solid-arm destination advance before payload advance, matching the oracle add-destination then shared source-increment order while preserving skip and end-row fault order.
probe 231 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 12: model the shape header plus one-byte payload tail as one typed Shape_Record, testing whether canonical payload ownership recovers row/count liveness without cursor or home scaffolding. [same emitted code as probe 229]
probe 232 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 13: join row declaration with its typed destination initialization after orientation offset formation, testing natural declaration/initialization timing against the oracle row home. [same emitted code as probe 231]
probe 233 control-flow; result=MISMATCH; diff=251; shape=86.13861386138613: Hypothesis 14: use one typed working row pointer through each RLE row instead of a persistent row plus inner dst, testing whether natural pointer liveness recovers the oracle row home and row-end store.
probe 234 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 15: bind each typed payload byte to a scoped pixel local before palette lookup, testing natural index/value evaluation order against the oracle EDX/ECX table registers. [same emitted code as probe 232]
probe 235 control-flow; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 16: express command decoding as in-place byte shift followed by count assignment, matching the oracle SHR AL then byte-home store at both odd and even arms. [same emitted code as probe 234]
probe 236 liveness; result=MISMATCH; diff=246; shape=86.40776699029126: Hypothesis 17: copy the proven header width into a counted rows local only inside the positive-height guard, testing whether delayed count home allocation recovers the oracle post-setup width store.
probe 237 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 18: move the destination-offset declaration to function scope before decoder locals, testing the full natural local declaration order for stride, row, and count homes. [same emitted code as probe 235]
probe 238 control-flow; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 19: spell the proven decoder backedge as an explicit done==0 comparison, testing whether VC5 preserves the oracle TEST AL/JE layout from the typed row-control structure. [same emitted code as probe 237]
probe 242 baseline; result=MISMATCH; diff=152; shape=85.29411764705883: Fresh-claim baseline: retained natural typed split-row RLE source, 268B/8B, 2 ordered calls, 152 strict diff; original row/count homes and setup read order remain unmatched. [same emitted code as probe 241]
probe 243 control-flow; result=MISMATCH; diff=255; shape=85.29411764705883: Hypothesis 1: route skip and solid source-byte advances through one local goto tail, matching the oracle shared INC EDI while preserving no advance on end marker; tests whether structured common-tail source can recover cursor CFG and memory effects.
probe 245 abi; result=MISMATCH; diff=253; shape=74.07407407407408: Hypothesis 2: widen the shared RLE count local to unsigned int, testing whether its binary dword reload/mask and p2-home use reflect an int source rather than a byte source; this preserves command counts and loop memory effects.
probe 247 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 3: represent the persistent row base as a long address and cast only at dereference, testing whether the original dword parameter-home and ESI row arithmetic reflect integer address ownership; verify pointer arithmetic and row memory effects remain identical. [same emitted code as probe 242]
probe 249 control-flow; result=MISMATCH; diff=246; shape=86.40776699029126: Hypothesis 4: use a top-tested outer while(width > 0) with an explicit decrement, testing whether the oracle's delayed row-count store and backedge come from a while form rather than the retained do/while. [same emitted code as probe 236]
probe 251 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 5: remove the named orientation local and use direct td->Orien in both stride formation and the orientation guard, testing whether repeated member ownership delays the load and recovers the oracle header-before-orientation setup order. [same emitted code as probe 247]
probe 253 layout; result=MISMATCH; diff=150; shape=85.29411764705883: Hypothesis 6: delay the payload cursor declaration until after orientation and stride formation, testing whether declaration timing makes VC5 schedule the header width loads before the draw-area orientation read while keeping the same packed-stream owner.
probe 254 liveness; result=MISMATCH; diff=249; shape=82.52427184466019: Hypothesis 7: keep the height expression in the outer positive guard and declare the counted width only inside that guard, testing whether the oracle's late width-home store comes from short-lived loop-counter scope rather than a function-wide width local.
probe 256 liveness; result=MISMATCH; diff=261; shape=81.73076923076923: Hypothesis 8: bind each literal payload byte to a short-lived index local before advancing src and indexing pal, testing whether explicit byte liveness restores the oracle EDX payload index and ECX palette lookup register roles without changing loop writes.
probe 258 liveness; result=MISMATCH; diff=148; shape=92.15686274509804: Hypothesis 9: carry each row base through the incoming td home by reusing td as a typed byte-address cursor after setup, testing the binary-proven td-home row lifetime while checking row traversal and all RLE writes remain unchanged; diagnostic only if compiler-steering. [same emitted code as probe 141]
probe 259 control-flow; result=MISMATCH; diff=255; shape=92.15686274509804: Hypothesis 10: express the RLE shared source increment with explicit advance_source and command_end labels, matching the oracle's skip/solid INC EDI tail while branching around it for literal and end commands; loop writes and cursor ownership are preserved.
probe 261 liveness; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 11: scope the command count inside each outer row, testing whether the original p2-byte home is a row-local decoder temporary rather than a function-scope local; row traversal and per-command payload effects stay unchanged. [same emitted code as probe 251]
probe 263 abi; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 12: mark the proven read-only shape header and packed payload cursor const, testing whether const alias information recovers the original header-first setup scheduling without changing any payload read or destination write. [same emitted code as probe 261]
probe 265 layout; result=MISMATCH; diff=158; shape=84.31372549019608: Hypothesis 13: declare the payload cursor and orientation before the header height expression, testing the decompiler's orientation-first source order against the oracle's register colors and setup scheduling.
probe 267 abi; result=MISMATCH; diff=265; shape=80.95238095238095: Hypothesis 14: widen the packed command temporary to unsigned int, testing whether VC5's AL shift and byte count stores arise from an int command promoted from the payload; all decoder branches retain the same byte-stream effects.
probe 269 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 15: replace the one-byte Shape_Payload view with the direct uchar stream proven by Ghidra, testing whether canonical byte ownership changes VC5 cursor and palette index scheduling while preserving every source read and destination write. [same emitted code as probe 263]
probe 273 variant; result=MISMATCH; diff=150; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260822_124855: 576 variants, 192 invariant-eligible, 0 exact
probe 274 layout; result=MISMATCH; diff=150; shape=85.29411764705883: Hypothesis 17: reduce untouched TShape members to void* and use the direct uchar payload cursor, matching the structured-lab G0000 type surface; only proven shape_header ownership remains typed, with identical RLE reads/writes and calls. [same emitted code as probe 273]
probe 275 layout; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 18: reproduce structured-lab G0000 by combining the narrow untouched-member surface, direct uchar payload, and payload declaration before orientation; this isolates declaration order as the remaining 150-to-148 lead while preserving all RLE memory effects. [same emitted code as probe 269]
probe 276 context; result=MISMATCH; diff=152; shape=85.29411764705883: Hypothesis 19: make the target method public, matching the structured-lab representative's access surface while retaining the narrow class types and direct uchar stream; tests whether VC5 access context selects the 148-byte lab basin. [same emitted code as probe 275]
probe 278 variant; result=MISMATCH; diff=246; shape=94.11764705882354: Hypothesis 20: replay the best historical shape basin with private ABI preserved: narrow untouched member surface, long Orien, separate rows, td-carried destination, direct uchar payload, and explicit shared-tail labels. Measure natural supported topology; reject any cast/goto scaffolding if gains depend on it.
probe 280 variant; result=MISMATCH; diff=251; shape=86.40776699029126: Hypothesis 21: retain only natural parts of the historical shape basin: narrow untouched TShape members, direct uchar payload, long orientation, and a separate rows counter, while keeping ordinary row pointer, loops, and private ABI. This tests supported type/lifetime gains without td casts or labels.
probe 282 liveness; result=MISMATCH; diff=249; shape=86.13861386138613: Hypothesis 22: use one function-scope destination cursor instead of a persistent row plus nested dst, testing the natural single-cursor RLE topology used by exact mirror donors while preserving row stride and every destination write.
probe 284 layout; result=MISMATCH; diff=150; shape=85.29411764705883: Hypothesis 23: put the orientation local before the header width calculation, following Ghidra's source-order lead while leaving payload after stride and preserving the ordinary row/cursor source; measure first-block and shape effects. [same emitted code as probe 274]
probe 286 abi; result=MISMATCH; diff=150; shape=85.29411764705883: Hypothesis 24: model the palette as a fixed 256-byte Shape_Color_Table with a value member, testing whether canonical table ownership changes literal/solid index register colors while preserving the same pointer ABI, calls, and byte reads. [same emitted code as probe 284]
probe 288 control-flow; result=MISMATCH; diff=246; shape=86.27450980392157: Hypothesis 25: reverse the non-memory solid-arm updates to dst += count then src++, matching the oracle ADD ESI,EBP followed by shared INC EDI order; no read/write or fault effect changes because both are local pointer arithmetic.
probe 290 layout; result=MISMATCH; diff=269; shape=79.6116504854369: Hypothesis 26: mutate p3 only in the negative-orientation arm and form one common row address, testing the decompiler's parameter-reuse lead against the oracle's two arm-specific IMUL paths; pointer arithmetic and row memory effects remain identical.
probe 292 abi; result=MISMATCH; diff=150; shape=85.29411764705883: Hypothesis 27: widen only the orientation local from int to period long, isolating whether VC5 register colors and signed field arithmetic use the historical long source type; all pointer and RLE effects stay unchanged. [same emitted code as probe 286]
probe 294 variant; result=MISMATCH; diff=150; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260822_125731: 12 variants, 12 invariant-eligible, 0 exact
probe 295 variant; result=MISMATCH; diff=150; shape=85.29411764705883: variant lab build\variant_lab\004B98E0_shape_color_trans_unclipped\20260822_125805: 32 variants, 11 invariant-eligible, 0 exact
probe 296 layout; result=MISMATCH; diff=150; shape=85.29411764705883: Hypothesis 28: qualify the read-only draw-area parameter register using VC5's accepted syntax, testing register-color allocation without changing ABI, ownership, calls, or RLE memory effects. [same emitted code as probe 292]
probe 298 context; result=MISMATCH; diff=150; shape=85.29411764705883: Hypothesis 29: use the period sibling spelling  without explicit this->, testing whether member-expression context changes the initial this/td register basin while preserving exact header ownership and all memory effects. [same emitted code as probe 296]
probe 300 context; result=MISMATCH; diff=150; shape=85.29411764705883: Hypothesis 30: capture td in a named area alias before header setup and use that alias for all draw-area reads, testing whether an explicit receiver lifetime recovers the original early td-home load without pointer casts or behavior change. [same emitted code as probe 298]
probe 303 control-flow; result=MISMATCH; diff=252; shape=82.24299065420561: Mirror the exact same-TU forward decoder topology: direct header payload, direct orientation reads, row base, rows assigned inside the positive guard, and one working destination. This preserves all palette reads, RLE effects, calls, and fault order.
probe 305 liveness; result=MISMATCH; diff=255; shape=85.4368932038835: Reuse the decoded command byte after shifting instead of a separate function-scope count. This tests natural command ownership and parameter-home allocation while preserving byte width, stream reads, palette reads, calls, and fault order.
probe 307 liveness; result=MISMATCH; diff=150; shape=85.29411764705883: Carry the proven row start through the dead x-coordinate parameter, as exact same-TU Shape.cpp decoders do. Keep a typed initial row, reset the working destination from p2, and advance p2 once per row.
probe 309 liveness; result=MISMATCH; diff=150; shape=85.29411764705883: Start the shared narrow count lifetime only after the positive-height guard and after row setup. This tests whether natural block scope assigns row before count while preserving all reads, writes, calls, and fault order. [same emitted code as probe 302]
probe 311 liveness; result=MISMATCH; diff=251; shape=86.40776699029126: Keep header height separate from the loop row counter, and assign rows only inside the positive-height guard. Original assembly carries height through AlignedWidth and stores rows after the guard. Exact same-TU decoders use this natural lifetime. [same emitted code as probe 280]
probe 312 liveness; result=MISMATCH; diff=246; shape=86.40776699029126: Combine separate height and guarded rows with direct draw-area orientation reads, matching the exact same-TU forward decoder expression. This removes the named orientation lifetime without changing read count or fault order. [same emitted code as probe 249]
probe 313 liveness; result=MISMATCH; diff=132; shape=97.0873786407767: From the exact-setup same-TU row-home source, form the literal endpoint in two natural statements: copy dst, then add the narrow count. The original copies ESI to EAX before adding the count, and the split keeps destination overlap and read order unchanged. [same emitted code as probe 20]
probe 314 liveness; result=MISMATCH; diff=132; shape=97.0873786407767: Widen the narrow literal count in a named unsigned run after copying dst into the endpoint. This tests the original ECX count and EAX endpoint schedule without changing the byte-derived range or memory order. [same emitted code as probe 313]
probe 315 liveness; result=MISMATCH; diff=132; shape=95.14563106796116: Use one period-natural post-increment assignment for each translated literal pixel. This preserves source-before-destination reads and pixel overlap behavior while testing the original EDX index, CL palette value, and delayed destination store schedule.
probe 316 liveness; result=MISMATCH; diff=163; shape=94.11764705882354: Name the byte palette index before advancing the payload, then store and advance the destination. This mirrors the original EDX byte index lifetime while preserving source-before-destination reads and overlap behavior.
probe 317 abi; result=MISMATCH; diff=150; shape=95.14563106796116: Use the language-promoted unsigned integer type for the named byte palette index. This preserves zero extension and table range while testing register allocation without the narrow local spill.
probe 318 liveness; result=MISMATCH; diff=150; shape=95.14563106796116: Name the translated palette byte instead of its index, then advance src, store color, and advance dst. This preserves the palette read before the overlapping destination write while testing the target CL value lifetime. [same emitted code as probe 317]
probe 319 liveness; result=MISMATCH; diff=132; shape=97.0873786407767: Give the binary-proven literal endpoint function scope while assigning it only in the nonzero literal arm. This tests whether the longer endpoint lifetime keeps EAX for the pointer and ECX for the narrow count without changing behavior. [same emitted code as probe 314]
probe 320 liveness; result=MISMATCH; diff=132; shape=97.0873786407767: Declare the persistent destination before the shared byte count, following ownership order rather than count-first stack allocation. This tests endpoint register color while preserving the exact setup and parameter homes. [same emitted code as probe 319]
probe 321 abi; result=MISMATCH; diff=132; shape=97.0873786407767: Make the byte-to-pointer-offset promotion explicit as period long. The range remains 0..127, but this tests whether VC5 keeps the count in ECX and copies dst to EAX before addition. [same emitted code as probe 320]
probe 322 context; result=MISMATCH; diff=2; shape=100.0: Restore the period string header used by exact same-TU decoder siblings while retaining pragma function(memset). This tests authentic Shape.cpp intrinsic context at the localized endpoint basin.
probe 323 layout; result=MISMATCH; diff=2; shape=100.0: Model the proven palette parameter as one fixed 256-byte color table and index its byte array. Exact same-TU table decoders use this typed payload to select the original SIB base/index order without changing reads or ABI. [same emitted code as probe 322]
probe 324 liveness; result=MISMATCH; diff=148; shape=94.1747572815534: Use VC5-era register qualification for the branch-local narrow palette index. This tests the exact EDX index without a stack spill. It preserves one payload read, one palette read, and source-before-destination fault order.
probe 325 layout; result=MISMATCH; diff=2; shape=100.0: Spell both byte-table reads as explicit pointer addition and dereference. This preserves the palette ABI and exact read order while testing the remaining SIB base/index orientation. [same emitted code as probe 323]
probe 326 layout; result=MISMATCH; diff=2; shape=100.0: Test C/C++ commutative subscript orientation, with the byte index as the left operand and palette pointer as the subscript. This preserves both palette addresses and fault order while isolating the two remaining SIB bytes. [same emitted code as probe 325]
```
<!-- end-recovered:f22359f633da03485151 -->

<!-- recovered:c3e661fcf26b023cbcfe -->
### `0923cad7edb1` `src/scratch/004B98E0_shape_color_trans_unclipped.cpp:1-224`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004B98E0, TShape::shape_color_trans_unclipped, 268 bytes
// Source: Shape.cpp lines 841-905
// Status: SCRATCH — behavior and call set are reconstructed; remaining drift is
// the VC5 prologue/local-home/register basin and broad instruction placement.
//
// Known from the executable: TShape+0x0C is the Shape_Header, the payload starts
// at hdr+1, TDrawArea fields are Bits+0x08/Height+0x1C/Orien+0x24, and the RLE
// stream has literal, skip, solid, and end-of-row commands.  The repeat arm is
// a real memset call.  The pretested literal loop is retained because the binary
// has an initial destination/end compare before its copy body.
//
// Attempt log:
// - baseline: natural typed RLE reconstruction, but manual solid fill omitted
//   the binary memset call (193B, 259 differing bytes).
// - restored the external C memset surface with #pragma function(memset): calls
//   became 2/2 aligned and the candidate grew to 245B (254 differing bytes).
// - negative-first orientation dispatch improved setup/CFG (247B, 233 diff).
// - one shared byte count across command arms recovered parameter-slot reuse
//   (same size, 232 diff); typed Shape_Header and row-guard declaration were
//   canonical cleanup/duplicate basins.
// - changed the literal run to a pretested `while (dst < end)` as required by
//   the observed initial `cmp/jae`; current natural candidate is 251B, 234
//   differing bytes, 100% ordered calls, 9/9 conditional CFG signals.
// - setup declaration/order variants were codegen duplicates.  Remaining lead:
//   recover the original 8-byte local frame and early saved-register coloring;
//   do not replace this typed source with raw cursor/volatile scaffolding.
// sa508a60b0_shape3 probes (2026-08-09):
// - Rechecked the clean typed baseline: 251B/234 strict bytes with both calls
//   and the pretested literal loop aligned, but no local frame.
// - A natural separate `width` row counter assigned after destination setup
//   improved the strict metric to 230B without changing behavior or call set;
//   initializing it earlier instead moved header loads before the save prologue
//   and produced a worse 249B basin. Retained the after-destination form.
// - The remaining structural blocker is the oracle's 8-byte frame and its
//   delayed parameter-home allocation; no ABI or ownership uncertainty remains.
// sa-1a59a700-r1-004B98E0 probes (2026-08-11):
// - Collapsing header height and the post-destination counter into one natural
//   width local recovered the 8-byte frame, but stored width before the call and
//   remained a broad 254-byte mismatch; an area alias and orientation-first
//   spelling were emitted-code duplicates.
// - Split the binary-supported persistent row base from the per-row RLE cursor;
//   this reached exact effective size/frame (268B/8B) with both ordered calls,
//   while the standalone candidate remains 255 differing bytes.  Its remaining
//   mismatch is the setup/home basin: row and byte-count homes are swapped
//   relative to the oracle and literal/table index registers are oppositely
//   colored.  Moving count to setup scope and row declaration order were
//   duplicates.
// - A scoped literal index added 15 bytes and was rolled back; separate cursor
//   increment and period <string.h> context were duplicates/worse (261B).
// - Retained the readable one-width split-row reconstruction.  Calls, RLE CFG,
//   ownership, and effective size/frame are aligned; remaining lead is the
//   original Shape.cpp prologue/local-home/register basin, not behavior.
// orch2-4B98E0-home probes (2026-08-12):
// - Reused td as the persistent row home and p2 as the byte-count home after
//   setup, while capturing td before the delayed header load.  Size/frame and
//   calls stayed aligned, but strict diff stayed 255 and shape fell to 77.78%;
//   rolled back as a worse parameter-reuse basin.
// - A named td capture with delayed header load but natural row/count locals
//   was emitted-code identical to the clean source; rolled back.  The donor
//   home lead is exhausted without a source-quality improvement.
// shardE-4B98E0 probes (2026-08-13):
// - Applied the exact same-TU sibling cursor topology with a persistent typed
//   destination home and byte count.  It improved shape to 92.16% and exact
//   blocks to 73.27%, but remained 255 bytes different; the direct-address
//   variant was 269B/246 diff and retained no canonical source advantage.
// - Reordering pitch/header declarations, palette-index spelling, address
//   terms, and direct-formal aliases produced duplicates or a 283B/263 diff.
//   Restored the clean typed split-row reconstruction; calls and ownership
//   remain exact, while the setup/register basin is unresolved.
// sa7d813de0-r1-shape probes (2026-08-13):
// - Rechecked the paused source and exact Shape.cpp siblings.  Full proven
//   TShape/TDrawArea field surfaces were codegen duplicates; retained them.
// - The natural split statement `*dst = pal[*src]; src++;` and the matching
//   solid-arm cursor order reduce strict drift to 159 bytes at exact size and
//   frame.  Calls, RLE effects, and ownership stay aligned.
// - A diagnostic persistent-row cast through td reached 155 bytes and 91.18%
//   shape, but it is decompiler-shaped parameter-home steering.  The living
//   source keeps the ordinary row pointer instead.
// - Stride-first setup, p2 count reuse, index temporaries, pointer-add table
//   spelling, and redundant area aliases gave duplicates or worse basins.
// - Remaining drift is the original Shape.cpp prologue/register basin and
//   table index/value coloring.  No behavior or call uncertainty remains.
// sa-e6fe2895-r1 probes (2026-08-16):
// - The exact same-TU sibling cursor topology, with p2 carrying the row base
//   after setup, improved the clean natural candidate to 268B/137 diff and
//   89.32% shape.  Setup through the first row guard is exact.
// - A diagnostic reuse of the dead td home for the row pointer, plus explicit
//   shared source-advance labels, reached 268B/132 diff, 97.09% shape, and
//   94.06% exact blocks.  The binary supports the row home and shared tail,
//   but the cast is compiler-steering, so it was rolled back.
// - Literal bound spellings, typed palette views, scoped index/color locals,
//   register qualification, and explicit pointer increment order were
//   duplicates or worse.  Calls, size, frame, and behavior stayed aligned.
// - The pinned p2 row-home source was later rejected by main review as
//   compiler-steering.  The living source retains the ordinary row pointer.
// sa-899d6337-r1 probes (2026-08-17):
// - Restored the ordinary row-pointer source after the p2 pointer-carrier
//   checkpoint.  It builds at 268B/8B with both calls aligned and 159 strict
//   differing bytes; it is the retained natural source model.
// - Natural row/count order, a separate counted-row local, shared source
//   advance labels, literal post-increment, typed index/color locals, staged
//   orientation order, and typed palette payload access were duplicates or
//   worse.  Solid-arm statement order was also worse.  All were rolled back.
// - Do not retain p2 pointer casts, raw cursor forms, or metric-only control
//   flow.  Remaining drift is the VC5 prologue/local-home and register basin;
//   ABI, ownership, calls, and RLE behavior remain resolved.
// sa-eaa9dd7e-r1 probes (2026-08-17):
// - Re-read the complete local lessons, matching workflow, dossier, original
//   assembly, Ghidra listing, ABI evidence, and same-TU donors.  The original
//   uses td's incoming home for the persistent row, p2's home for the byte
//   count, and a separate 8-byte pitch/width frame.  Its two direct calls and
//   byte-stream ownership are already resolved.
// - A typed header increment, a typed payload-owner view, a natural area alias,
//   and a typed palette payload were duplicates or metric-only basins.  They
//   were rolled back.  Shared-tail and parameter-home steering remain rejected.
// - Initializing Orien at declaration and using the typed expression
//   `td->AlignedWidth() * Orien` is the best new natural basin: 268B/8B,
//   2/2 ordered calls, 152 strict differing bytes, and 85.29% shape.  It is
//   not exact.  The remaining mismatch starts in VC5 local-home/register
//   allocation and the literal table-index register basin.
// sa-08179dd2-r1 TU audit (2026-08-17):
// - Tested same-TU CRT header order, Windows/RECT context, <io.h>/<fcntl.h>,
//   a Windows-style min macro, the ground-truth class declaration kinds, the
//   full neighboring member declaration bank, and the exact preceding
//   shape_draw_unclipped donor body.  These contexts either reproduced the
//   clean 268B/152-diff output or moved to the harmful 271B/257-diff basin.
// - The exact preceding donor definition did not change the target output.
//   Function order is therefore not the controlling source context here.
// - The public TDrawArea/private TShape class spelling reproduced the PDB
//   AAEEPAV decorated ABI surface with unchanged bytes.  It did not recover
//   the oracle prologue or local homes, so it is ABI evidence only.
// - The clean source and default /O2 /Oy flags are restored.  No tested
//   translation-unit context naturally selects the oracle parameter-home
//   basin.  Remaining drift is source liveness/home allocation, not a proven
//   missing header, macro, declaration, function order, or flag.
// - Object audit confirms the 268-byte range, two local words, five parameters,
//   FPO/COFF shape, compiler, and no hidden inline cause. Oracle assigns row to
//   the td home and count to p2; the natural source reverses them. A row-home
//   cast remains rejected, and the extra skip-arm source increment stays open.
// sa-d8c4454d-r1:
// - Canonicalized the PDB class spellings and private decoder ABI. Added the
//   proven Shape_File_Header, Shape_Offsets, SLhape_File_Header, and Shape_Info
//   payload types. Calls stayed 2/2 and output stayed 268B with an 8B frame.
// - A full TDrawArea field layout added 3 bytes and was rejected. The narrow
//   typed overlay keeps only the proven decoder fields and class spelling.
// - A shared source increment after skip and solid arms reached 268B but 255
//   differing bytes. Restored the simple natural arm increments. It changed
//   control flow and did not preserve the best source basin.
// - Typed payload aliases, canonical Orien/width widths, a palette alias,
//   direct header reads, and folded destination arithmetic were duplicates or
//   worse. No parameter-home or row-home steering is retained.
// sa-697357dc-r1:
// - Completed a fresh 20-probe natural-source pass from the 268B/152-diff
//   frontier. Every probe preserved 268B/8B, two ordered calls, and behavior.
// - A one-byte Shape_Payload record models the proven packed stream without a
//   raw cursor. It is codegen-identical to the byte form and remains canonical.
// - Tested payload record ownership, decoder ABI spelling, row/count declaration
//   order, scoped locals, solid/skip order, row-pointer forms, and loop guards.
//   All natural variants were duplicates or worse.
// - The oracle still assigns the row pointer to td's home and count to p2's
//   home. Only rejected home casts or pointer carriers reach the 132-byte basin.
//   The retained source uses no casts, aliases, volatility, or compiler steering.
// - Accepted-drift audit: do not promote this candidate. RLE cursor effects,
//   palette reads, memset arguments, row movement, and returns align. However,
//   the rebuild reads td->Orien before a shape-header field that the original
//   reads first. Invalid header or draw-area pointers therefore fault in a
//   different order.
// sa-575307d7-r1 fresh pass (2026-08-22):
// - Baseline rebuilt at 268B/8B with both ordered calls and 152 strict diff.
// - Tested a shared source-increment goto tail, int count, integer row address,
//   outer while form, direct Orien reads, short-lived width scope, literal index
//   local, scoped count, const header/payload, orientation-first declarations,
//   int command, and a raw uchar payload cursor. These were worse or emitted
//   duplicates. Memory reads, RLE writes, row movement, calls, and cleanup were
//   kept unchanged in each test.
// - Moving the payload cursor declaration after stride is a natural declaration
//   order variant. It improved the clean candidate to 268B/8B and 150 strict
//   differing bytes. It is retained; no exact result was found.
// - Reusing td as a byte-address row cursor recovered the oracle td home and
//   92.16% shape/56.44% exact blocks, but is compiler-steering type punning. An
//   explicit shared-tail variant reached 73.27% exact blocks but 255 diff.
//   Both were rolled back. The oracle row/count homes are now proven, but the
//   natural source does not select them.
// - Strict accepted-drift review remains negative: the residue is broad setup,
//   register, and cursor-tail drift, not a small localized equivalent. The
//   natural rebuild also reads td->Orien before header fields, unlike the
//   executable. This changes invalid-input fault order, so do not promote.
// sa-575307d7-r1 continued shape pass (2026-08-22):
// - The 576-case structured source lab found no exact variant. Its natural
//   baseline family kept size, frame, calls, and 85.29% shape. Table, cursor,
//   loop, declaration, and update axes did not improve the pinned source.
//   Reported lower positional values in lab output masked object relocations;
//   they did not survive authoritative checking as a source gain.
// - A narrow-member/direct-byte/long-orientation/separate-row group reached
//   86.41% shape but 251 diff and 270 bytes. A private-ABI replay of the old
//   compiler-steering basin reached 94.12% shape and 75.25% exact blocks but
//   246 diff. Both were rolled back because strict drift grew and the source
//   needed td pointer casts or shared labels.
// - Single destination cursor, p3 parameter reuse, reversed solid updates,
//   orientation-first declarations, long Orien, register td, unqualified
//   shape_header, area alias, and typed palette were duplicates or worse.
//   The solid update probe reached 86.27% shape and 40.59% exact blocks but
//   246 diff; it was not retained as metric-only scaffolding.
// - A 12-case VC5-small flag lab emitted one group with no flag movement. A
//   32-case ambient declaration lab produced 11 eligible 268-byte variants,
//   all at the same first divergence; other variants were 271 bytes. Neither
//   context axis is a useful lead.
// sa-b67e446d-r1 exact-codegen pass (2026-08-23):
// - Replayed the binary-proven td row home, p2 byte-count home, guarded row
//   count, and shared source-advance tails from exact same-TU decoders. This
//   diagnostic source matched setup through +0x87 and reached 268B/132 diff,
//   but retained rejected td pointer punning and goto-based tail steering.
// - Adding the period <string.h> context changed that diagnostic to 268B with
//   all 101 instruction shapes and both calls aligned. Only two SIB bytes
//   remained: original palette reads use [edx+ebx], while VC5 emitted the
//   equivalent [ebx+edx]. Palette structs, references, pointer addition,
//   reversed subscripting, pointer typedefs, and array-parameter spelling did
//   not change those bytes. Narrow index locals changed the frame or prologue.
// - The two-byte frontier is not retained because its td cast and labels are
//   compiler-steering forms, not the simplest supported source. The natural
//   typed row reconstruction remains authoritative. Its known fault-order
//   difference also blocks semantic acceptance: it reads td->Orien before the
//   original header-field reads on invalid input.
// FLAGS: /nologo /c /O2 /Oy
```
<!-- end-recovered:c3e661fcf26b023cbcfe -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
