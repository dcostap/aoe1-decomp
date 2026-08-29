# Recovery journal: 004A9CC0 `set_scenario_mode`

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


<!-- recovered:7e39d0b23a67bbc0c435 -->
### `target-session` `build/target_sessions/004A9CC0_set_scenario_mode.json:1-27`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=122; shape=98.59872611464968: Baseline existing natural reconstruction; establish exact size, calls, and remaining diffs.
probe 2 layout; result=MISMATCH; diff=122; shape=98.59872611464968: H2: model unit_list as base TPanel and cast only for currentLineNumber; tests whether implicit upcast controls argument register.
probe 4 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H3: reverse diplomacy pointer initialization order, testing allocator coloring for ppv versus ppf. [same emitted code as probe 1]
probe 6 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H4: declare diplomacy counter before pointer locals, testing VC5 register-color assignment order. [same emitted code as probe 4]
probe 8 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H5: scope and initialize diplomacy loop counter inside its block, testing declaration lifetime against original stack home. [same emitted code as probe 6]
probe 10 abi; result=MISMATCH; diff=122; shape=98.59872611464968: H6: widen diplomacy counter from int to long, testing decompiler long-counter evidence for original stack home. [same emitted code as probe 8]
probe 12 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H7: take diplomacy counter address through a local pointer, testing whether the original stack home reflects address-taken liveness. [same emitted code as probe 2]
probe 14 control-flow; result=MISMATCH; diff=122; shape=98.59872611464968: H8: expand diplomacy pointer and counter increments into explicit additions, testing VC5 scheduling and induction lowering. [same emitted code as probe 10]
probe 16 control-flow; result=MISMATCH; diff=123; shape=98.47133757961784: H9: reverse equivalent diplomacy loop comparison operand order, testing spill and compare lowering.
probe 18 control-flow; result=MISMATCH; diff=122; shape=98.59872611464968: H10: reverse diplomacy player-index comparison operands, testing allocator and branch lowering.
probe 20 abi; result=MISMATCH; diff=122; shape=98.59872611464968: H11: narrow diplomacy get_line result local from long to int, testing return-width/liveness codegen. [same emitted code as probe 14]
probe 22 abi; result=MISMATCH; diff=122; shape=98.59872611464968: H12: type diplomacy friend-box cursor as TPanel** with explicit proven-layout cast, testing pointer surface and register coloring. [same emitted code as probe 12]
probe 24 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H13: scope diplomacy cursor declarations inside the case block, testing local lifetime and register homes. [same emitted code as probe 20]
probe 26 layout; result=MISMATCH; diff=122; shape=98.59872611464968: H14: spell diplomacy cursor bases as row-plus-one and address-of-element, matching exact donor source style. [same emitted code as probe 24]
probe 28 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H15: initialize diplomacy cursor locals at declaration after the count guard, testing initialization-site liveness.
probe 30 liveness; result=MISMATCH; diff=534; shape=94.73039215686275: H16: remove diplomacy p temporary and spell both branch outcomes directly, testing pointer lifetime and register pressure.
probe 32 abi; result=MISMATCH; diff=122; shape=98.59872611464968: H17: type diplomacy selected-panel temporary as TButtonPanel* rather than TPanel*, testing virtual surface type. [same emitted code as probe 26]
probe 34 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H18: spell selected diplomacy neighbor as pointer-plus-one dereference, testing source-expression basin. [same emitted code as probe 32]
probe 36 control-flow; result=MISMATCH; diff=2354; shape=92.53365973072215: H19: invert diplomacy conditional and place selected-panel activation in each arm, testing source branch topology.
probe 38 abi; result=MISMATCH; diff=122; shape=98.59872611464968: H20: make the diplomacy selected-panel upcast explicit, testing whether pointer conversion spelling changes register allocation. [same emitted code as probe 22]
probe 40 variant; result=MISMATCH; diff=122; shape=98.59872611464968: variant lab build\variant_lab\004A9CC0_set_scenario_mode\20260817_160350: 128 variants, 128 invariant-eligible, 0 exact
probe 41 layout; result=MISMATCH; diff=122; shape=98.59872611464968: H21: model unit_list as intermediate TTextPanel and cast only for currentLineNumber; tests class-surface type effects. [same emitted code as probe 38]
probe 42 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H22: qualify diplomacy AlliedVictory cursor with register, testing whether observed EBX ownership reflects source register intent. [same emitted code as probe 34]
probe 43 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H23: qualify diplomacy counter with register, testing whether original stack home is a compiler spill despite register intent. [same emitted code as probe 42]
probe 44 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H24: qualify both diplomacy cursors and counter with register, testing combined source register hints. [same emitted code as probe 43]
probe 45 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H25: reverse the two function-scope loop-local declarations, testing VC5 declaration-order coloring. [same emitted code as probe 44]
probe 49 liveness; result=MISMATCH; diff=122; shape=98.59872611464968: H26: declare and initialize diplomacy cursors inside the guarded block in original friend-box then AlliedVictory order; tests declaration-site coloring without changing calls or fault order. [same emitted code as probe 48]
```
<!-- end-recovered:7e39d0b23a67bbc0c435 -->

<!-- recovered:8248a6670edfe6cd0909 -->
### `f5ba6af5b34f` `src/scratch/004A9CC0_set_scenario_mode.cpp:1-38`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004A9CC0 TRIBE_Screen_Sed::set_scenario_mode | scr_sed.cpp:1150-1535
// __thiscall set_scenario_mode(ScenarioMode), ret 4
// Attempt log:
// 1: natural reconstruction from packet/Ghidra with real PDB field names; two-pass
//    do-while like the exact set_map_type donor; per-array set_active loops modeled
//    like the exact ~TRIBE_Screen_Sed (walking pointer pp + count); case source
//    order follows the binary's physical layout (1,2,3,4,6,7,9,10,5,8).
// 2: layout fixes: TScreenPanel needs its 0x384 pad (0xF4+0x384=0x478); classes with
//    virtuals place data at +4 (vptr); RGE_Diamond_Map_View::set_active is slot 5.
// 3: case-8 (Options) has the save branch INLINE (if(!active){save}else{load}); all
//    other cases have the active/load branch inline.
// 4: activate_victory_proper_fields is (int,int) per PDB mangling (IAEXHH), not (long,int).
// 5: BREAKTHROUGH: rge_base_game must be a declared extern global, not the absolute-
//    deref macro (*(RGE_Base_Game**)0x62C574). The macro form shifted case-4 register
//    allocation by +8 bytes (set_game_mode arg temp, master_obj_id condition, B032/B038
//    global loads) and cascaded; the extern form made size/frame/calls exact (diff 1581->122).
// 6: diplomacy loop uses pointer-walk ppv/ppf + i counter; lVar5 >= 0 (test/jl); i++ order
//    after ppv++.
// LEFT IN SCRATCH (diff 122 / 4.70%, size exact, calls 100%): the case-5 diplomacy loop
//    homes i to [esp+10h] in the original (ppv in ebx) but VC5 homes ppv to [esp+10h] and
//    keeps i in ebx in the rebuilt, adding ~2 instr/iteration. Tried: indexed vs pointer
//    forms, all declaration/increment orders, function-vs-case scope, register hints,
//    lVar5 long/int, p placement, compare spellings, full typed class surface (worse).
//    Also 3-byte set_curr_child arg-register difference at +036A (mov eax vs mov ecx).
// Next lead: case-5 loop register home is allocator-driven; try a variant-lab axis on the
//    loop-top access order (player_text first vs AlliedVictory first) or the p local's
//    live range across the je.
// Follow-up session: an explicit TPanel cast, child/parent locals, and a register-qualified
// child local did not move the set_curr_child hunk. A canonical TButtonPanel p local and a
// function-scope p likewise emitted the unchanged 122-byte form. The focused diplomacy lab
// confirmed that loading AlliedVictory before player_text makes the frame 0x10; declaring p
// before the text access is emitted-identical to the clean text-first form. A focused call
// lab (direct, paired locals, reference alias) also left the +036A register difference.
// Current pass: baseline remains 122 bytes / 4.6959% nonexact with exact size, frame,
// and 157-call parity. H2-H25 tested field types, cursor scopes, declaration order,
// comparison and increment spellings, branch shape, pointer casts, and register hints;
// all emitted the same 122-byte basin or worsened structure. An ambient 128-variant
// declaration sweep also produced one unchanged group. Keep the clean baseline pinned.
```
<!-- end-recovered:8248a6670edfe6cd0909 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
