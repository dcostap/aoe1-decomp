# Function notes: 00540010 `pick_best_target`

Module notes: `decomp_notes/vw_main_module.md`.

## Recovered attempt history

<!-- recovered:428dd3bd29a85960b970 -->
### `d050eea3c` `src/vw_main.cpp:1208-1208`

Mapping: `strong`. comment lies after mapped function pick_best_target at old line 1204.

```text
    // BINARY NOTE: task ownership is RGE_Master_Action_Object, not its static
```
<!-- end-recovered:428dd3bd29a85960b970 -->

<!-- recovered:a7df4e6adee760f8644b -->
### `target-session` `build/target_sessions/00540010_pick_best_target.json:1-42`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=621; shape=77.51937984496124: Initial clean-source checker baseline from existing natural reconstruction; establish calls, boundary, frame.
probe 2 layout; result=MISMATCH; diff=680; shape=77.60617760617761: Hypothesis 1: model the selected object master at +8 and route primary action/flag comparisons through the master object, as original MOV [selected+8] and later master-relative accesses prove.
probe 3 abi; result=MISMATCH; diff=621; shape=77.51937984496124: Hypothesis 2: rename the +E4 virtual from local pick_score to evidence-backed RGE_View pick_weight and use that semantic method at both scoring sites; test whether class ABI spelling changes VC5 output. [same emitted code as probe 1]
probe 4 abi; result=MISMATCH; diff=621; shape=75.5813953488372: Hypothesis 3: replace generic virtual slots with the reviewed TPanel/RGE_View surface and inherited pick_weight at vslot +E4; preserve natural class ownership instead of a manual vtable.
probe 5 control-flow; result=MISMATCH; diff=678; shape=74.1444866920152: Hypothesis 4: restore two natural counted zero-initialization loops for the score arrays, replacing memset, because original emits two REP STOSD loops without a byte-tail cleanup.
probe 6 liveness; result=MISMATCH; diff=621; shape=77.51937984496124: Hypothesis 5: keep a separate int master_count derived from the pick result, testing whether original count use and pointer lifetime require distinct source values rather than repeated pointer-to-int casts. [same emitted code as probe 3]
probe 7 liveness; result=MISMATCH; diff=621; shape=77.51937984496124: Hypothesis 6: reorder ordinary locals to the PDB/decompiler declaration evidence (count, selected list, j, target count) to test VC5 stack-home allocation without adding unsupported state. [same emitted code as probe 6]
probe 8 layout; result=MISMATCH; diff=692; shape=76.24521072796935: Hypothesis 7: retain selected-object ownership but use a typed master_obj at +8 for the primary task list and master-relative eligibility fields, matching original selected+8 and master-relative reads.
probe 9 control-flow; result=MISMATCH; diff=680; shape=95.78544061302682: Hypothesis 9: use a natural while(k < object_count) inner scan after the proven positive-count guard, testing branch polarity against original JL backedge and shared skip tail.
probe 10 abi; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 10: correct get_selected_objects_to_command return width to the exact donor unsigned-char ABI, matching original TEST AL rather than rebuilt TEST EAX.
probe 11 control-flow; result=MISMATCH; diff=644; shape=96.86274509803921: Hypothesis 11: combine the char helper ABI with natural array-zero loops, testing whether REP STOSD without a compiler byte-tail preserves the original initialization basin after EAX liveness changes.
probe 12 context; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 12: use the period standard string.h declaration for memset instead of a local prototype, testing header/intrinsic context as the cause of original REP STOSD lowering.
probe 13 abi; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 13: model the compiler-era memset return as void because the result is unused, testing whether the declaration controls VC5 REP STOSD versus byte-tail lowering. [same emitted code as probe 10]
probe 14 other; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 14: express the dynamic dword byte count as an unsigned shift before memset, testing whether VC5 recognizes the count as a dword multiple and removes byte-tail code. [same emitted code as probe 13]
probe 15 abi; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 15: use signed int for the local memset byte-count parameter, testing whether VC5 count signedness removes its defensive byte-tail path while preserving natural C memset. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=651; shape=96.47058823529412: Hypothesis 16: use typed int-pointer cursor loops for each score array, testing whether VC5 lowers a proven dword induction to the original REP STOSD family without raw cursors.
probe 17 control-flow; result=MISMATCH; diff=660; shape=94.65648854961832: Hypothesis 17: reverse the two independent score-array zero stores to test VC5 scheduling and source-order evidence while preserving behavior.
probe 18 liveness; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 18: extend the record cursors to function scope while keeping their assignments at the observed loop entries, testing whether long-lived cursor homes reproduce original [esp+10] and final scan ownership. [same emitted code as probe 15]
probe 19 liveness; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 19: retain a separate int master_count through all bounds and fills with the corrected char helper ABI and while scan, testing count lifetime without pointer casts. [same emitted code as probe 18]
probe 20 abi; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 20: use the inventory-supported int pick_objects return and int master_obj count instead of a pointer return, testing whether count signedness drives original REP STOSD and source ABI.
probe 21 abi; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 21: replace generic action-system slots and raw action+6 access with reviewed RGE_Task_List get_target_task/is_attack_task and typed RGE_Task::action_type, preserving the observed vslots and five/one arguments.
probe 22 abi; result=MISMATCH; diff=657; shape=93.89312977099236: Hypothesis 22: replace all generic view/vtable slots with the reviewed TPanel/RGE_View surface and inherited pick_weight at +E4, while retaining typed task ABI and the strong while-loop CFG.
probe 23 layout; result=MISMATCH; diff=655; shape=95.80152671755725: Hypothesis 23: complete the reviewed RGE_View data surface with cur_render_area/+F4 and calc_draw_count/+F8 before world/player, restoring the proven +FC/+100 fields without raw layout arithmetic. [same emitted code as probe 20]
probe 24 layout; result=MISMATCH; diff=664; shape=95.81749049429658: Hypothesis 24: promote the proven selected-object +8 master pointer to a typed RGE_Master_Static_Object, use master task/flag/type fields for the primary path, and preserve object task fields for the fallback path.
probe 25 layout; result=MISMATCH; diff=664; shape=95.81749049429658: Hypothesis 25: replace vptr placeholder data with natural polymorphic destructors for proven RGE_Player, RGE_Game_World, RGE_Static_Object, and master-object layouts while preserving observed offsets. [same emitted code as probe 24]
probe 27 control-flow; result=MISMATCH; diff=653; shape=96.56488549618321: Removed the redundant positive object-count wrapper around the fallback while loop. This natural form recovered the original memory compare, cut three bytes, and left only two dynamic zero-fill tails.
probe 30 control-flow; result=MISMATCH; diff=652; shape=97.6470588235294: Replace dynamic memset calls with two natural indexed zero loops. This tests the original REP STOSD-only lowering in the current typed source.
probe 32 other; result=MISMATCH; diff=666; shape=95.81749049429658: Mask each natural memset byte count to dword alignment. This tests whether VC5 can prove zero byte tails from an explicit aligned size.
probe 34 context; result=MISMATCH; diff=653; shape=96.56488549618321: Declare memset as an explicit compiler intrinsic. This tests whether the authentic optimized module used pragma-selected intrinsic lowering. [same emitted code as probe 29]
probe 36 context; result=MISMATCH; diff=683; shape=87.3076923076923: Use period STL fill ranges over the two int arrays. This tests typed element-count lowering without byte remainders.
probe 38 liveness; result=MISMATCH; diff=668; shape=95.05703422053232: Keep a named byte count across two natural typed zero loops, then derive each dword loop count. This tests the original shared EDX byte count and repeated SHR setup.
probe 40 control-flow; result=MISMATCH; diff=646; shape=96.89922480620154: Walk each int array while a shared byte count decreases by sizeof(int). This tests whether VC5 lowers a byte-unit fill to the original repeated SHR/REP STOSD form.
probe 41 control-flow; result=MISMATCH; diff=660; shape=89.10505836575875: Use do/while for both byte-counted dword fills under the proven positive count guard. This removes redundant loop entry tests and tests exact REP lowering.
probe 43 control-flow; result=MISMATCH; diff=686; shape=88.41698841698842: Use nonzero termination for two exact-multiple byte-count loops. This tests whether VC5 removes rounded trip counts and emits direct SHR/REP STOSD fills.
probe 45 liveness; result=MISMATCH; diff=659; shape=96.49805447470817: Derive each typed loop count from one named byte count, then use nonzero decrement loops. This tests shared byte-count retention with canonical REP STOSD recognition.
probe 46 control-flow; result=MISMATCH; diff=668; shape=89.84375: Use do/while nonzero loops for counts derived from one byte count under the positive guard. This tests removal of the two redundant entry tests.
probe 48 context; result=MISMATCH; diff=653; shape=96.56488549618321: Use the period stdlib and string headers together, as supported by exact adjacent vw_main owners. This tests authentic CRT intrinsic context. [same emitted code as probe 34]
probe 50 layout; result=MISMATCH; diff=653; shape=96.56488549618321: Use authentic game ownership: player +24 is the master-object array, selected objects use the static-object layout, and fallback task fields belong to master objects. Use the reviewed short helper inputs.
probe 51 variant; result=MISMATCH; diff=653; shape=96.56488549618321: variant lab build\variant_lab\00540010_pick_best_target\20260823_184208: 11 variants, 11 invariant-eligible, 2 exact
probe 52 control-flow; result=MATCH; diff=0; shape=99.60629921259843: Apply the lab winner: two natural indexed loops with != bounds. VC5 lowers them to the exact REP STOSD-only fills.
probe 53 context; result=MATCH; diff=0; shape=99.60629921259843: Walkback: remove the now-unused memset declaration. Exactness must not depend on incidental ambient CRT context. [same emitted code as probe 52]
probe 54 control-flow; result=MATCH; diff=0; shape=99.60629921259843: Exact walkback: post-increment is incidental. Changing the first or second != bound independently to < is non-exact (walkback-first-less and walkback-second-less). Both != bounds are required. [same emitted code as probe 53]
```
<!-- end-recovered:a7df4e6adee760f8644b -->

<!-- recovered:bca64def790cbf1d3cae -->
### `51a444b9b02f` `src/scratch/00540010_pick_best_target.cpp:1-23`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00540010 pick_best_target (823B)
// vw_main.cpp
// Attempt log:
// initial natural reconstruction from packet; compiles but .text is 800B vs original 823B.
// tried source model with typed RGE_Main_View/RGE_View fields at +FC/+100 and vtable padding for +E4 score call.
// tried direct typed action-system virtuals for [vtable+4]/[vtable+8] calls instead of raw helper wrappers.
// tried explicit goto next_target to mirror original single shared target-advance block.
// tried do/while outer and inner loops to mirror original bottom tests.
// tried stack local order selected_count/selected_objects/j/target_count/master/cur/arrays to force 0x224 frame.
// tried explicit PickedObjInfo[12-byte] walking so info[-1].picked and info->action match +(-4)/+0 access.
// tried list fallback as a typed ObjectList at player +0x22/+0x24 to match fallback scan.
// tried final best scan with running Picked_Objects pointer and direct out-param guarded store.
// probe: corrected the view geometry to world (+FC)/player (+100), matching exact vw_main donors;
// probe: int pick_score is behavior-backed by the original direct EAX add, but is 5B farther than char.
// probe: typed player object_count/object_list is canonical but changed the frame to 0x220; kept the named fields.
// probe: inventory ABI confirms RGE_Pick_Obj_Info is 12 bytes with object_id at +0 and confidence at +4;
// kept the natural typed record walk, which raises shape similarity to 74.14% without changing calls or size.
// probe: replaced scalar zero loops with natural memset(..., master_obj * sizeof(int)); this recovers the original
// byte-count-to-stosd initialization family and improves the strict diff from 678 to 621 bytes.
// probe: function-scope record cursor, explicit view alias, and j-before-target_count declarations were codegen duplicates.
// probe: inner for-loop spelling was worse (837B/681-byte diff); restored the natural do/while target scan.
// final gap: calls, filters, score accumulation, attacking output, and best-object return match the binary;
// VC5 local lifetime and block layout remain non-exact. Left in scratch.
```
<!-- end-recovered:bca64def790cbf1d3cae -->
