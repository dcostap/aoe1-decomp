// 004F21F0 TribeTacticalAIModule::taskActiveSoldiers(unsigned long,unsigned long)
// PDB: taitacmd.cpp:3769-5404
// First pass: start from the full repo-local Ghidra approximation, kept below as
// the line-by-line porting guide.  The compileable body below intentionally ports
// only the top iterator/action-gate skeleton first; next passes should replace the
// large TODO body with successive Ghidra blocks and watch edit/resync diff.
// Attempt log:
// - seeded full Ghidra decompiler output under #if 0 from inventory/functions/004F/004F21F0_taskActiveSoldiers.txt.
// - built a compileable first skeleton for the opening group-selection/list-walk/action gate.
// - check_function cannot yet diff: current .text is 352 bytes vs original 9580; next step is to port the inactive-group body until the object is large enough for normal diff metrics.
// - mechanical full-Ghidra compile probe showed labels embedded between if/else arms and static-call surfaces need manual cleanup, so keep porting block-by-block rather than bulk-uncommenting.
// - ported first inactive non-attack defend/relic branches (types 0x65/0x68/0x6d) with rough typed helper surfaces; rebuilt .text now 1408 bytes, still below original size for diff extraction.
// - added timeout tail, first attack-opener scaffold (type 100/0x67), and active action-0x0d assist/enter scaffold; rebuilt .text now 2368 bytes, still below original size for diff extraction.
// - ported rough active transport/boarding/action maintenance scaffolds for actions 0xf, 0x10, 7, 2, 4, 0xc/0x13, and 3, plus inactive fallback attack selection/resizing and post-attack influence hooks. Current .text is 7872 bytes, still below original 9580 so check_function cannot yet produce edit/resync metrics.
// - filled enough remaining scaffold detail to reach full extraction length; current check_function is MISMATCH 76.4301% positional / 172.2651% edit, first mismatch offset 12. Frame size now matches 0xD0; next leading issue is early `xor ebp,ebp` and zero-register use before the original first emits it, plus broad approximate-body drift.
// - removed zero initialization of the inactive-branch object locals and forced raw offsets for nextActive/attackState; edit diff improved materially. Current check_function: MISMATCH 76.4823% positional / 153.0167% edit, first mismatch offset 12. Rebuilt still has early `xor ebp,ebp`; keeping frame at 0xD0 currently requires scratch_frame[0x38].
// - corrected local RGE_World layout so world_time is at +4 as observed in original early idle-time loads, restored inactive-branch mem/commander zero initialization to match the Ghidra/original state setup, and reshaped the relic timeout branch to preserve md before consecutiveIdleUnitCount. Current check_function: MISMATCH 76.0647% positional / 162.8497% edit, first mismatch offset 12.
// - temporarily removed the inactive-branch mem/commander zero assignments again because they hoisted an early zero register and broke the opening. With scratch_frame[0x34], the prologue/opening now matches through offset 87; current check_function: MISMATCH 76.0543% positional / 152.7035% edit, first mismatch is sentinel register choice (`lea ebp,[edi+9D4]` vs original `lea ebx,[edi+9D4]`). Need later recover the original delayed `xor ebp; xor ebx` inactive setup without re-hoisting.
// - probed an explicit inUse local/zero-derived mem init: it made the sentinel register match but shrank frame to 0xCC and reintroduced early `xor ebp`, so rolled back. Probed delaying/deriving allOutsideTransport initialization and raw param reloads; no improvement over current opening/edit-diff baseline.
// - ran a small focused local variant sweep over scratch_frame size (0x30/0x34/0x38) and inactive-branch setup spellings (none/zero/after-type/split-decl/volatile-zero). Best retained opening is still scratch_frame[0x34] with no mem/commander zero init: frame 0xD0 and first mismatch 87. Zero-init variants either shrink the frame or hoist `xor ebp`; volatile zero improves positional slightly but breaks the prologue/frame.
// - unified the inactive attack-selection subpaths to use the outer ObjectMemory* (matching Ghidra's single pOVar27-style state) and added local relic-branch zeroing; this improves positional diff but worsens edit diff. Current check_function: MISMATCH 75.8455% positional / 162.5574% edit, first mismatch remains offset 87 sentinel register allocation.
// - promoted local RGE_Master/ObjectList/RGE_Player layout facts from type inventory (master_obj +8, objects +0x0c, los +0x28, obj_max +0x2c, object list count +8, player id +0x4a) and expanded the active transport action 0x0d/0x0f/0x10 scaffolds with transport capacity, idle-entry, staging-point, defender-escort, and owner-id gates from the Ghidra guide. Current check_function: MISMATCH 75.9603% positional / 164.2067% edit, first mismatch offset 87.
// - delayed allOutsideTransport initialization to the attack-selection branch and adjusted scratch_frame to 0x28 to preserve the 0xD0 frame after adding staging locals; expanded active action 0x10 reset path with the relic move fallback from Ghidra. Current check_function: MISMATCH 76.2630% positional / 165.3653% edit, first mismatch offset 87.
// - added the Ghidra-observed non-enemy target reset/gather branch for active action 2/subtype -1 and exposed a local md->isEnemy surface. Current check_function: MISMATCH 76.1378% positional / 162.4322% edit, first mismatch still offset 87.
// - added the action 2 playNumberValue recovery path from the Ghidra LAB_004f436b area: when the commander has unitAI and no playStatus, reset playNumberValue to -1 and clear attackState.active. Current check_function: MISMATCH 76.1065% positional / 167.4530% edit, first mismatch offset 87.
// - corrected the local RGE_Static_Object field layout to match type inventory (owner +0x0C, inside_obj +0x20, objects +0x24, hp +0x30, world coords +0x38/+0x3C/+0x40, object_state +0x48, actions +0x184), switched damaged-unit retreat HP source to hp, and added the action 2 / sn[0x31]==2 reset-task branch. Current check_function: MISMATCH 75.1044% positional / 155.1044% edit, first mismatch offset 12 from early zero-register setup.
// - removed the hoisted inactive mem/commander zero init again and reshaped action 4 closer to Ghidra (allUnitsIdle/isGathered gate, higherPriorityObjectToDefend with master object_group, else task 9). Fixed action 0xc/0x13 cleanup condition to include buildListLength and the type-100 group-count arm. Current check_function: MISMATCH 75.6472% positional / 140.2714% edit, first mismatch back to offset 87.
// - made the action 2 invalid-target sn[0x31]==2 reset/task path skip the replacement-target retask path, matching the Ghidra control-flow split instead of falling through. Current check_function: MISMATCH 75.9916% positional / 148.2255% edit, first mismatch offset 87.
// - probed returning to inactive mem/commander zero-init with current larger body; it now worsens edit/prologue, so rolled back to no early zero-init. Updated the default target higher-priority check to pass targetObj->master_obj->object_group like the Ghidra iVar36 path. Current check_function: MISMATCH 75.9186% positional / 151.4509% edit, first mismatch offset 87.
// - corrected more local layout facts from type inventory: ObjectMemory x/y/z/owner are +8/+9/+A/+B with group at +6; TacticalAIGroup direct playNumberValue/numberObjectsToDestroyValue are +0x1D0/+0x2CC; UnitAIModule::playStatus is +0x12C; TribeMainDecisionAIModule build/info/strategy offsets are +0x104/+0xCEC/+0x10E74; TribeTacticalAIModule sn starts at +0x194. Current check_function: MISMATCH 75.2610% positional / 170.9186% edit, first mismatch offset 87.
// - natural-source probe: local references for attackState.active and nextActiveGroup made the source nicer and preserved first mismatch 87, but worsened edit diff, so rolled back; keep raw offset access until a broader class-surface rewrite is justified.
// - corrected TacticalAIGroup sizeof/local tail to 0x330 and TribeTacticalAIModule gap_after_groups to 0x280, enabling natural this->groups.next, &this->groups, nextActiveSoldierGroupToTaskValue, and attackState_active field access with identical codegen to the raw-offset version. Current check_function: MISMATCH 75.2610% positional / 170.9186% edit, first mismatch offset 87.
// - replaced raw offsets for playersToAttack, lastGroupAttackTime, lastAttackResponseTime, attackEnabledValue, and AttackState with natural fields, including a real AttackState wrapper at +0xFAC and fuller Build/Information module sizes. Codegen stayed stable and edit diff improved from the raw-field surface. Current check_function: MISMATCH 75.2610% positional / 148.7265% edit, first mismatch offset 87.
// - reshaped inactive attack target selection to match the Ghidra/natural ManagedArray flow more closely: resize playersToAttack only when the target lookup path actually needs player[0], then call objectToAttack/objectToAttackByGroup unconditionally after ensuring capacity; also removed null guards in active action 7/replacement retarget paths after ensure. Current check_function: MISMATCH 76.0334% positional / 165.8351% edit, first mismatch offset 87.
// - moved inactive-branch mem/commander/allOutside initialization up to the start of the !inUse arm to mirror original early zero/init stores, then enlarged scratch_frame to keep the original 0xD0 frame. Added missing attackState.active clears on several inactive setAction(1) exits. Current check_function: MISMATCH 76.0543% positional / 159.5720% edit, first mismatch offset 30 (sentinel register allocation ebx/ebp).
// - naturalized the initial null tests from `(unsigned long)cur == 0` to `cur == 0`; codegen unchanged. Probed moving RESET_GROUP's numberObjectsToDestroy store after setTargetType to mimic the late shared reset block, but edit diff worsened, so rolled back.
// - restored the PDB-proven XYZPoint layout (three ints, size 0x0c) and binary-observed RGE_Static_Object virtual surfaces: weaponRange at +0x10c, canPath(XYZPoint,...) at +0x198, canPathWithAdditionalPassability at +0x1a4, and find-first-path-point at +0x1a8. Replaced the approximate direct helper calls across the major pathing branches with natural typed virtual dispatch. Edit/resync diff improved substantially from 159.5720% to 128.9040%, and equal bytes rose from 1693 to 3013.
// - current path-surface baseline: MISMATCH 78.0063% positional / 128.9040% edit. The natural locals now produce a 0xD4 frame (original 0xD0), so first mismatch is frame size at offset 2; one excess 4-byte local/home remains to identify. A full relic fallback port raised the frame to 0xDC and worsened edit diff, so it was rolled back pending shared-stack-local modeling.
// - restored the second influence-path virtual call as findAvoidancePath at vtable +0x1cc, with the proven XYZPoint* / weaponRange / mode arguments, replacing the temporary nonsensical float-to-Path cast. Current check_function: MISMATCH 77.4217% positional / 130.4593% edit, 2949 equal bytes. This correct call surface needs 12 more local bytes in the current block-scoped model (frame 0xE0); hoisting one XYZPoint across the inactive arm over-collapsed the frame to 0xC8 and worsened edit diff, so rolled back.
// - restored the full relic exception-path fallback and the three binary-observed +0x194 canAttack gates; the virtual call surfaces now include +0x10c/+0x194/+0x198/+0x1a4/+0x1a8/+0x1cc and the md enemy test at +0x1c.
// - replaced the incorrect large catch-all idle/unit-retask scaffold with the Ghidra-observed final HP/unit-loss check, and routed terminal task requests through one shared task tail. Relative to the session baseline this cut rebuilt size from 10576 to 9936, calls from 487 to 448, and CFG conditionals from 264 to 236 (original 9580/440/233); frame is now exact at 0xD0.
// - current check_function: MISMATCH 94.1224% positional / 116.2037% edit, 3358 equal bytes, first mismatch +0x60. The opening matches through sentinel setup; remaining first hunk is original `xor ebp; cmp esi,ebp` versus rebuilt `test esi,esi`. Size is now only +356 rather than +996, so continue structural/call-tail cleanup before register coloring.
// - corrected the action-2 play gate: target acquisition/retask now runs only for playNumberValue==-1, while the play-status recovery is the separate original fallback. Restored repeated unit/retreatLocation/unitAI/targetLocation calls visible in the binary and the redundant subtype check.
// - moved the victory-condition target-selection/grow logic onto the type-100/0x67 attack-enabled arm instead of the unrelated inactive generic-type arm. Shared only the binary-observed ManagedArray delete tail and the active exception-path finish; this removed the duplicate objectToAttackByGroup path and brought direct-call totals much closer.
// - reshaped the active action dispatch around the original 0xc/0x13/3 gates, shared the action-7 timeout path, restored the second assist-group lookup, and routed the defend exception path through the observed common attack-state clear. This moved ordered call alignment from the first relic failure calls to the post-relic-success tail.
// - current check_function: MISMATCH 92.2547% positional / 116.7328% edit, shape 52.82%, longest aligned run 96, frame exact 0xD0. Rebuilt is now 9380 vs 9580 (-200), 435 vs 440 calls, 231 vs 233 conditionals, and 64 vs 69 jumps. First mismatch remains +0x60 (`test esi,esi` vs zero-in-EBP compare); first ordered call divergence is now +0x36A after the relic fallback, where rebuilt still places one setAction failure block before the direct-success setters.
// - inverted the action-0x10 type-100 reset arm to keep its commander/canAttack path inline before the non-100 gather path, matching the original physical order; shape rose from 52.82% to 53.66% and ordered-call alignment from 80.00% to 81.36%.
// - inverted the action-2 valid-target subtype dispatch so non-default subtypes stay inline and subtype -1 becomes the late handler, matching the original +1C9C compare chain and post-epilogue handler family. This was the major structural breakthrough: shape rose to 69.12%, call alignment to 85.23%, and edit/resync similarity to 41.08%.
// - reordered action-0x13 predicates to isGathered -> elapsed-time/consecutive-idle -> allUnitsIdle, following the original call order. Kept despite broad address movement because all three calls now align in order.
// - restored the binary-observed independent transport inside-object tests instead of an else-if simplification. This recovered the second commander call and removeUnit block, made CFG conditional counts exact (233/233), reduced target-count differences from 11 to 8, and raised shape/call alignment to 70.33%/86.82%.
// - spelling the outer action-2 invalid-target predicate first (as suggested by PDB line order) and naming a null-group local were codegen-neutral; retained the natural negative invalid-target source, but rolled back the unused null local.
// - current baseline: MISMATCH 92.0564% positional / 51.68% bounded edit, shape 70.33%, 3911 equal bytes, frame exact 0xD0. Rebuilt is 9387 vs 9580 (-193), 436 vs 440 calls, conditionals exact at 233/233, jumps 62 vs 69. First mismatch remains +0x60 (`test esi,esi` versus `xor ebp; cmp esi,ebp`); first ordered divergence remains the early relic success/failure block placement around +0x360.
// - rewrote the transport-loop invalid-object/invalid-unitAI cases as natural nested branches rather than goto handlers; this preserved both binary-observed logCommonHistory call sites and improved bounded edit similarity.
// - restored the missing +0x10c weaponRange virtual call in the defend-object canPath predicate and the type-0x67 guard that skips the attack exception-path fallback; both aggregate call counts now match the original.
// - made the two defend-object null failures exit immediately, preventing VC5 from merging their distinct setAction calls. Split the inactive default-task selection so its action result is materialized for the shared task tail.
// - shared the defend/relic gather-location and set-in-use tail through one label, matching the original common +27F4 tail and eliminating one extra call of each kind. The three float values intentionally reuse the pending-task stack homes.
// - corrected the active attack exception fallback to nested type/path/path-point gates and duplicated its natural completion tail. This recovered the missing task call and brought rebuilt size from -193 to -41 bytes; VC5 did not tail-merge targetLocation/waitCode as far as the original, leaving one extra call of each.
// - modeled the two path-point outputs as distinct float locals (including the defend gatherAux); frame returned to the exact 0xD0.
// - current baseline: rebuilt 9539 vs 9580 (-41), 441 vs 440 calls, frame exact 0xD0, shape 71.17%, bounded edit 49.40%, and 4145 equal bytes. Remaining aggregate call gaps are one missing setAction plus one extra setTargetLocation and setWaitCode; CFG has one extra conditional and four fewer jumps. First mismatch remains +0x60 (`test esi,esi` versus `xor ebp; cmp esi,ebp`).
// - split the active exception-path canPath failure from the type/path-point rejection. The former also clears numberObjectsToDestroy, matching the distinct original +09E8 failure block and recovering the last missing setAction call.
// - precompute the exception-path target coordinates in the three pending-task homes before converging the active-selection and action-7 paths. Sharing only the calls after task preserves both task call sites while tail-sharing setAction/target/type/location/in-use/wait. This made all 440 aggregate call counts exact.
// - hoisted the reused ObjectMemory pointer to function scope so the converged exception tail does not need an artificial fourth pending local. The defend canPath output is one float, while its two find-first-path outputs remain distinct floats; correcting that surface keeps the frame at the exact 0xD0.
// - inverted the defend and active-attack direct canPath branches so the exception fallback is source-inline and direct success is the else arm, matching the original cold-block order. Shape improved from 69.99% to 73.99% and call alignment from 87.73% to 90.45%. Applying the same common failure label to defend/relic over-merged five setter calls, so that probe was rolled back.
// - current baseline: rebuilt/original size exactly 9580, calls exactly 440 with zero target-count differences, frame exactly 0xD0, saved registers exact, shape 73.99%, call alignment 90.45%, bounded edit 46.19%, and 4415 equal bytes. CFG is close at 234/233 conditionals and 67/69 jumps. First mismatch is +0x57 because the rebuilt second sentinel compare uses eax and `test esi,esi`, while original keeps the sentinel in ebx then emits `xor ebp; cmp esi,ebp`.
// - removed the incorrect playNumber=-1 store from the active-selection null-commander failure. This moved the block into the original +090B family, improved strict diff to 91.88%, and extended ordered call alignment from the early 30s to 57 calls.
// - rewrote the active exception fallback as linear negative guards (type, additional canPath, then positive path-point success), preserving the original distinct canPath failure and rejection blocks. Splitting task/setAction/setTarget/setTargetType before the shared coordinate/set-location tail raised the ordered call prefix to 109 and shape above 75%.
// - the original direct canPath and additional-passability canPath use distinct float output homes; modeling `point` and `exceptionPoint` separately restores the exact 0xD0 frame after the exception-prefix split. The action-0x0f invalid reset also requires the observed numberObjectsToDestroy=0 store.
// - action-0x0f and action-0x10 invalid resets appear to converge at the old LAB_004f37f1 source label. Explicitly unifying them removes the extra target/targetType pair, but VC5 then over-merges one unrelated setAction/setInUse pair and shrinks the function by 52 bytes; rolled back pending a source shape that preserves those setters naturally.
// - current baseline: size exactly 9580, frame exactly 0xD0, saved registers exact, shape 75.66%, call alignment 90.95% with a 109-call prefix, and CFG 234/233 conditionals plus 66/69 jumps. Calls are 442/440: only one extra setTarget and setTargetType site remain, localized to reset-tail sharing. First mismatch remains +0x57 at the second sentinel/null test.
// - unified the action-0x0f/0x10 invalid reset at the binary-observed common tail, then isolated the action-0x10 attack failure with a local label and natural direct task call. This prevents VC5 from merging that setInUse/setAction pair with the distant action-7 timeout tail: aggregate calls are now exact at 440, size is -27, shape 75.70%, and call alignment 91.59%.
// - restored the original combined inactive task gate (`allOutside || action()!=2`), extending the exact ordered call prefix from 109 to 215. The loss-check task now uses the observed post-setAction action() call and a direct task tail, which restores exact size/call totals and also fixes the opening sentinel register to EBX.
// - action-0x10 performs the target/object lookup before its type test even though non-type-100 paths discard the result. Reusing pendingTaskCode for that binary-observed pointer home preserves the exact 0xD0 frame. Current milestone: size/frame/calls exact, shape 76.53%, call alignment 92.27% with prefix 225, edit/resync similarity 55.41%; first mismatch is now +0x60 at the zero-in-EBP null compare.
// - inlined the action-0x10 taskAttacker target/location arguments to recover the original right-to-left call order, extending the ordered prefix to 255. This removes two artificial float homes and exposes an 8-byte frame deficit that still needs a real local-layout fix.
// - restored the binary-observed lastAttackResponseTime update and changed the action-0x10 success to task the group's post-setAction action value with args (1,0). The natural direct suffix merges with the loss-check suffix as in the original and extends the ordered call prefix to 323.
// - isolated the action-7 timeout with its natural direct task call, preventing VC5 from merging its setAction with a distant identical tail. Aggregate calls return to exact and the ordered prefix reaches 358. A direct-task spelling for the sn[0x31]==2 reset added an action call and collapsed the early prefix, so it was rolled back.
// - the non-default action-2 idle-timeout reset must exit immediately; letting it fall into the play-status recovery was behaviorally wrong and encouraged setter-tail merging. Restoring the direct ContinueLoop edge keeps its target-type/location calls distinct, raises shape to 77.86% and call alignment to 92.95%, and extends the ordered prefix to 360.
// - enlarging the action-7 auxiliary output window from 4 to 12 bytes restored the 0xD0 frame and improved block coverage, but it is not justified by the float* callee surface and changed the sentinel register, so it was rolled back. The current 0xC8 frame is an exposed real-local modeling deficit, not a padding invitation.
// - an explicit goto split for subtype==-1 moved that cold handler too early, reduced call alignment to 88.86%, and was rolled back; keep the positive non-default subtype body for now.
// - modeled the defend-distance selection as a real float and restored two shared gather-coordinate homes from the Ghidra fVar topology; frame is now exact at 0xD0 and the original +0407/+040F FILD blocks are exact. Reversed several equivalent threshold predicates to preserve binary-observed compare operand order, raising exact-block coverage from 33.04% to 37.08% and the longest aligned run from 96 to 106 while keeping all 440 call counts exact. Current size is +42, shape 78.24%, call prefix 360; first mismatch is +0x57 at the sentinel/zero-register choice.
// - rolled back focused sentinel probes (direct member comparison, register local, and a scoped zero/null alias): they either compiled identically or changed only four unrelated later bytes; none recovered the original `lea ebx` / `xor ebp; cmp esi, ebp` opening.
// - worker pass: 20 evidence-led checks. Best current source is 9618 bytes versus 9580, with 440/440 calls and 37.43% exact-block coverage.
// - BINARY NOTE: original defend null exits and action-7 exception completion jump to the common tail at 004F4548 after their state stores. The temporary clear_attack_state tail preserves the single original store; direct copies make VC5 emit four stores.
// - BINARY NOTE: original action-2 reset paths place the target-location store before the numberObjectsToDestroy store in their cold reset tail.
// - reordered action-2 handling to the binary-supported positive valid-target branch first, with invalid-target replacement/reset as the else arm; emitted code stayed effectively duplicate (six changed bytes, one fewer diff byte) with no CFG or call movement, but the source now follows the decompiler-supported fallthrough.
// - rolled back positive `isEnemy` arm order: it improved size/call-site count slightly but reduced block/edit alignment and did not move the misplaced virtual-dispatch block into the original +0x2400 family.
// - second worker pass: 20 evidence-led checks. The best source is 9609 bytes versus 9580, with 440/440 calls and an exact 0xD0 frame.
// - corrected stuffAvoidancePath to the proven two-argument member ABI. This made original block +0x0C33 exact and removed two bytes.
// - restored PDB source order for action-2 target handling and the original enemy-arm polarity. Ordered call alignment rose to 93.41%.
// - changed the byte state test to `object_state > 2`. This recovered original CMP 2 / JA and made block +0x1C92 exact.
// - remaining structural blocker: the subtype -1 handler stays inline near rebuilt +0x1EAD. Original VC5 places its only incoming block after both epilogues at +0x2400.
// - original PDB symbols show one source label only: ContinueLoop at original +0x2362. Other labels here are temporary compiler-tail models.
// - original PDB locals include attackAsAttack, defendDistance, tAreaMin, tAreaMax, point, pathDistance, gatherX, and gatherY.
// - tAreaMin and tAreaMax are 16-byte Waypoint values. Modeling both makes the original 63-instruction action-2 block exact, but exposes conflicting synthetic homes.
// - direct location expressions recover exact local blocks. Defer them until common-tail structure preserves the call surface and exact 0xD0 frame.
// - the direct relic path passes relic->type, not constant 0x6d. This aligns the next defender block at original +0x3ac and improves strict diff by 51 bytes.
// - relic canPath failure handling ends at PDB line 4219 and exits through ContinueLoop. Keeping that behavior currently makes VC5 merge one unrelated setter tail.
// - placing the relic exit in each completed branch preserves behavior and recovers exact blocks at original +0x1e3c and +0x1ef8.
// - original relic and defender path failures share the later active setAction block. Spelling all three failure tails directly lets VC5 recover that join without source labels and improves strict diff by 15 bytes.
// - removed an unreachable duplicate inactive target block and its trampoline. They never emitted code; inactive selection now targets the live common region directly.
// - Ghidra shows an explicit clear-tail edge after defender exception completion. Relic completion instead falls through to the end of its type arm. Moving the relic clear edge to that boundary is codegen-neutral and matches this source evidence.
// - an outer-loop continue restores the missing relic setter sites, but skips group advancement and the time-limit check. Do not use that diagnostic shape as behavior evidence.

#if 0
Source: taitacmd.cpp.decomp
// Offset: 0x004F21F0
void taskActiveSoldiers(TribeTacticalAIModule* this_, ulong param_2, ulong param_3) {
--- Ghidra decompiler output ---

/* WARNING: Variable defined which should be unmapped: commanderObj */
/* public: void __thiscall TribeTacticalAIModule::taskActiveSoldiers(unsigned long,unsigned long) */

void __thiscall
TribeTacticalAIModule::taskActiveSoldiers(TribeTacticalAIModule *this,ulong param_1,ulong param_2)

{
  uchar uVar1;
  uchar uVar2;
  byte bVar3;
  int *piVar4;
  code *pcVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  XYPoint XVar9;
  XYPoint XVar10;
  byte bVar11;
  uchar uVar12;
  int iVar13;
  ulong uVar14;
  RGE_Static_Object *pRVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *piVar19;
  Path *pPVar20;
  TacticalAIGroup *pTVar21;
  UnitAIModule *pUVar22;
  RGE_Action *pRVar23;
  Waypoint *pWVar24;
  int iVar25;
  AIModule *this_00;
  AIModule *this_01;
  RGE_Static_Object *pRVar26;
  ObjectMemory *pOVar27;
  uint uVar28;
  TacticalAIGroup *this_02;
  float10 fVar29;
  float fVar30;
  float fVar31;
  Waypoint *pWVar32;
  TribeMainDecisionAIModule *pTVar33;
  float fVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  RGE_Static_Object *commanderObj;
  int allInsideTransport;
  int allOutsideTransport;
  RGE_Static_Object *unitObj;
  XYPoint stagingPoint;
  XYZPoint point_ffffff44;
  uchar targetZone;
  XYZPoint point;
  XYZPoint point_ffffff60;
  XYZPoint point_ffffff6c;
  float pathDistance_ffffff78;
  RGE_Action_Object *transportObject;
  float pathDistance_ffffff80;
  float pathDistance;
  float pathDistance_ffffff88;
  XYPoint commanderPoint;
  XYZPoint point_ffffff94;
  RGE_Static_Object *targetObj;
  Waypoint tAreaMin;
  Waypoint tAreaMax;
  XYZPoint targetPoint;
  float gatherY;
  float gatherY_ffffffd4;
  XYPoint startPoint;
  float gatherX_ffffffe0;
  float gatherY_ffffffe4;
  float pathDistance_ffffffe8;
  float gatherX_ffffffec;
  float gatherX_fffffff0;
  float gatherX;
  float gatherY_fffffff8;
  undefined1 auStack_4 [4];
  
  this_02 = (this->groups).next;
  if (this->nextActiveSoldierGroupToTaskValue != -1) {
    while (((this_02 != &this->groups && (this_02 != (TacticalAIGroup *)0x0)) &&
           (iVar13 = TacticalAIGroup::id(this_02), iVar13 != this->nextActiveSoldierGroupToTaskValue
           ))) {
      this_02 = this_02->next;
    }
    iVar13 = TacticalAIGroup::id(this_02);
    if (iVar13 != this->nextActiveSoldierGroupToTaskValue) {
      this_02 = (this->groups).next;
    }
  }
  if (this_02 != &this->groups) {
    do {
      if (this_02 == (TacticalAIGroup *)0x0) break;
      iVar13 = TacticalAIGroup::type(this_02);
      if (((iVar13 == 0x6b) || (iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x6c)) ||
         ((iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x6a ||
          ((iVar13 = TacticalAIGroup::action(this_02), iVar13 == 0 ||
           (iVar13 = TacticalAIGroup::action(this_02), iVar13 == 1)))))) {
        this_02 = this_02->next;
      }
      else {
        iVar13 = TacticalAIGroup::allUnitsIdle(this_02,this->md,1);
        if (iVar13 == 0) {
          TacticalAIGroup::setConsecutiveIdleUnitCount
                    (this_02,*(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4));
        }
        iVar13 = TacticalAIGroup::inUse(this_02);
        if (iVar13 == 0) {
          pOVar27 = (ObjectMemory *)0x0;
          pRVar26 = (RGE_Static_Object *)0x0;
          allOutsideTransport = 1;
          iVar13 = TacticalAIGroup::type(this_02);
          if ((iVar13 != 100) && (iVar13 = TacticalAIGroup::type(this_02), iVar13 != 0x67)) {
            iVar13 = TacticalAIGroup::type(this_02);
            if ((iVar13 == 0x65) || (iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x68)) {
              iVar13 = TacticalAIGroup::commander(this_02);
              pOVar27 = TribeInformationAIModule::objectToDefend(&this->md->informationAI,iVar13);
              if (pOVar27 == (ObjectMemory *)0x0) {
                TacticalAIGroup::setAction(this_02,1);
              }
              else {
                iVar13 = TacticalAIGroup::commander(this_02);
                pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                if (pRVar26 != (RGE_Static_Object *)0x0) {
                  if (pOVar27->type == 0x6d) {
                    iVar13 = this->sn[0x16];
                  }
                  else {
                    iVar13 = this->sn[0x39];
                  }
                  uVar12 = pOVar27->x;
                  uVar1 = pOVar27->y;
                  uVar2 = pOVar27->z;
                  unitObj = (RGE_Static_Object *)pRVar26->_padding_;
                  fVar29 = (float10)(**(code **)&unitObj[1].inObstructionMapValue)
                                              (pOVar27->id,&commanderPoint,1,0xffffffff,0xffffffff);
                  iVar35 = (*(code *)unitObj[3]._padding_)(uVar12,uVar1,uVar2,(float)fVar29);
                  if (iVar35 != 0) {
                    pOVar27->attackAttempts = 1;
                    TacticalAIGroup::setTarget(this_02,pOVar27->id);
                    TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                    TacticalAIGroup::setTargetLocation
                              (this_02,(float)pOVar27->x,(float)pOVar27->y,(float)pOVar27->z);
                    fVar31 = (float)pOVar27->z;
                    fVar30 = (float)pOVar27->y;
                    fVar34 = (float)pOVar27->x;
LAB_004f27f4:
                    TacticalAIGroup::setGatherLocation(this_02,fVar34,fVar30,fVar31);
                    TacticalAIGroup::setInUse(this_02,1);
                    goto LAB_004f2d49;
                  }
                  iVar13 = (*(code *)unitObj[3].owner)
                                     (uVar12,uVar1,uVar2,(float)iVar13,pOVar27->id,&commanderPoint,1
                                      ,0x16,1,0xffffffff,0xffffffff);
                  if ((iVar13 != 0) &&
                     (iVar13 = (*(code *)unitObj[3].sprite)(2,&gatherX_fffffff0,auStack_4),
                     iVar13 == 1)) {
                    pOVar27->attackAttempts = 1;
                    TacticalAIGroup::task(this_02,this,this->md,0xe,1,0);
                    TacticalAIGroup::setAction(this_02,0xd);
                    TacticalAIGroup::setTarget(this_02,pOVar27->id);
                    TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                    TacticalAIGroup::setTargetLocation
                              (this_02,(float)pOVar27->x,(float)pOVar27->y,(float)pOVar27->z);
                    TacticalAIGroup::setInUse(this_02,1);
                    TacticalAIGroup::setWaitCode(this_02,200);
                    goto LAB_004f4548;
                  }
                  goto LAB_004f2afb;
                }
                TacticalAIGroup::setAction(this_02,1);
              }
            }
            else {
              iVar13 = TacticalAIGroup::type(this_02);
              if (iVar13 == 0x6d) {
                pTVar33 = this->md;
                uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                if ((((RGE_Player *)pTVar33->_padding_)->world->world_time - uVar14) / 1000 < 0x3c)
                {
                  TacticalAIGroup::setAction(this_02,1);
                }
                else {
                  pRVar15 = MainDecisionAIModule::object
                                      ((MainDecisionAIModule *)pTVar33,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,
                                       -1);
                  if (pRVar15 == (RGE_Static_Object *)0x0) {
                    TacticalAIGroup::setAction(this_02,1);
                  }
                  else {
                    iVar13 = TacticalAIGroup::commander(this_02);
                    pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                    if (pRVar26 == (RGE_Static_Object *)0x0) {
                      TacticalAIGroup::setAction(this_02,1);
                    }
                    else {
                      uVar16 = __ftol();
                      uVar17 = __ftol();
                      uVar18 = __ftol();
                      unitObj = (RGE_Static_Object *)pRVar26->_padding_;
                      iVar13 = (*(code *)unitObj[3]._padding_)
                                         (uVar16,uVar17,uVar18,(float)this->sn[0x17],pRVar15->id,
                                          &pathDistance,1,0xffffffff,0xffffffff);
                      if (iVar13 != 0) {
                        TacticalAIGroup::setTarget(this_02,pRVar15->id);
                        TacticalAIGroup::setTargetType(this_02,(uint)pRVar15->type);
                        TacticalAIGroup::setTargetLocation
                                  (this_02,pRVar15->world_x,pRVar15->world_y,pRVar15->world_z);
                        fVar31 = pRVar15->world_z;
                        fVar30 = pRVar15->world_y;
                        fVar34 = pRVar15->world_x;
                        goto LAB_004f27f4;
                      }
                      iVar13 = (*(code *)unitObj[3].owner)
                                         (uVar16,uVar17,uVar18,(float)this->sn[0x17],pRVar15->id,
                                          &pathDistance,1,0x16,1,0xffffffff,0xffffffff);
                      if (iVar13 == 0) {
                        TacticalAIGroup::setConsecutiveIdleUnitCount
                                  (this_02,*(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4));
                        TacticalAIGroup::setAction(this_02,1);
                      }
                      else {
                        iVar13 = (*(code *)unitObj[3].sprite)(2,&gatherX,&pathDistance_ffffffe8);
                        if (iVar13 != 1) goto LAB_004f2afb;
                        TacticalAIGroup::task(this_02,this,this->md,0xe,1,0);
                        TacticalAIGroup::setAction(this_02,0xd);
                        TacticalAIGroup::setTarget(this_02,pRVar15->id);
                        TacticalAIGroup::setTargetType(this_02,(uint)pRVar15->type);
                        TacticalAIGroup::setTargetLocation
                                  (this_02,pRVar15->world_x,pRVar15->world_y,pRVar15->world_z);
                        TacticalAIGroup::setInUse(this_02,1);
                        TacticalAIGroup::setWaitCode(this_02,200);
                      }
                    }
                  }
                }
              }
              else {
LAB_004f2d49:
                iVar13 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
                if ((iVar13 == 0xb) &&
                   ((((iVar13 = TacticalAIGroup::type(this_02), iVar13 == 100 ||
                      (iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x67)) &&
                     (this->sn[0x67] == 1)) &&
                    ((pOVar27 != (ObjectMemory *)0x0 && (pRVar26 != (RGE_Static_Object *)0x0)))))) {
                  TribeInformationAIModule::addEnemyInfluences
                            (&this->md->informationAI,(uint)pOVar27->owner,pOVar27->id);
                  TribeInformationAIModule::addPriorAttackInfluences
                            (&this->md->informationAI,(uint)pOVar27->owner,pOVar27->id);
                  targetPoint.z = (int)pOVar27->y;
                  targetPoint.y = (int)pOVar27->x;
                  unitObj = (RGE_Static_Object *)pRVar26->_padding_;
                  fVar29 = (float10)(**(code **)&unitObj[1].inObstructionMapValue)(pOVar27->id);
                  pPVar20 = (Path *)(**(code **)&unitObj[3].curr_damage_percent)
                                              (&targetPoint.y,(float)fVar29);
                  if (pPVar20 != (Path *)0x0) {
                    stuffAvoidancePath(this,this_02,pPVar20);
                  }
                }
                if ((allOutsideTransport != 0) ||
                   (iVar13 = TacticalAIGroup::action(this_02), iVar13 != 2)) {
LAB_004f452d:
                  iVar13 = 0;
                  iVar36 = 1;
                  iVar35 = TacticalAIGroup::action(this_02);
                  goto LAB_004f4539;
                }
                pTVar33 = this->md;
                iVar13 = 0;
                iVar36 = 1;
                iVar35 = 0x15;
LAB_004f4540:
                TacticalAIGroup::task(this_02,this,pTVar33,iVar35,iVar36,iVar13);
              }
            }
            goto LAB_004f4548;
          }
          if (this->attackEnabledValue == 0) {
            (this->attackStateValue).active = 0;
          }
          else {
            if ((this->sn[0xa2] != 0) && (iVar13 = TacticalAIGroup::type(this_02), iVar13 != 0x67))
            {
              pOVar27 = TribeInformationAIModule::objectMemory
                                  (&this->md->informationAI,iRam00000000);
LAB_004f2ae2:
              iVar13 = TacticalAIGroup::commander(this_02);
              pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
              if (pRVar26 == (RGE_Static_Object *)0x0) {
LAB_004f2afb:
                TacticalAIGroup::setAction(this_02,1);
              }
              else {
                uVar12 = pOVar27->y;
                uVar1 = pOVar27->x;
                unitObj = (RGE_Static_Object *)pRVar26->_padding_;
                pcVar5 = *(code **)&unitObj[1].inObstructionMapValue;
                uVar2 = pOVar27->z;
                fVar29 = (float10)(*pcVar5)(pOVar27->id,&pathDistance_ffffff88,1,pOVar27->owner,0x1b
                                           );
                iVar13 = (*(code *)unitObj[3]._padding_)(uVar1,uVar12,uVar2,(float)fVar29);
                if (iVar13 != 0) {
                  this->lastGroupAttackTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
                  if (this->sn[0x47] == 1) {
                    this->lastAttackResponseTime =
                         *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
                  }
                  TacticalAIGroup::setTarget(this_02,pOVar27->id);
                  TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                  TacticalAIGroup::setTargetLocation
                            (this_02,(float)pOVar27->x,(float)pOVar27->y,(float)pOVar27->z);
                  TacticalAIGroup::setInUse(this_02,1);
                  checkForCoopAttack(this,(uint)pOVar27->owner,(uint)pOVar27->x,(uint)pOVar27->y);
                  goto LAB_004f2d49;
                }
                iVar13 = TacticalAIGroup::type(this_02);
                if (iVar13 != 0x67) {
                  fVar29 = (float10)(*pcVar5)(pOVar27->id,&pathDistance_ffffff88,1,0x16,1,
                                              pOVar27->owner,0x1b);
                  iVar13 = (*(code *)unitObj[3].owner)(uVar1,uVar12,uVar2,(float)fVar29);
                  if (iVar13 == 0) {
                    this_02->numberObjectsToDestroyValue = 0;
                    TacticalAIGroup::setAction(this_02,1);
                    this_02->playNumberValue = -1;
                    (this->attackStateValue).active = 0;
                    goto LAB_004f4552;
                  }
                  iVar13 = (*(code *)unitObj[3].sprite)(2,&gatherY_fffffff8,&gatherY_ffffffd4);
                  if (iVar13 == 1) {
                    TacticalAIGroup::task(this_02,this,this->md,0xe,1,0);
                    TacticalAIGroup::setAction(this_02,0xd);
                    TacticalAIGroup::setTarget(this_02,pOVar27->id);
                    TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                    bVar11 = pOVar27->z;
                    bVar3 = pOVar27->y;
                    uVar28 = (uint)pOVar27->x;
                    goto LAB_004f3cf9;
                  }
                }
                TacticalAIGroup::setAction(this_02,1);
                this_02->playNumberValue = -1;
              }
              goto LAB_004f4548;
            }
            uVar28 = (*(int *)(*(int *)(this->md->_padding_ + 0x3c) + 4) - this->lastGroupAttackTime
                     ) / 1000;
            if ((((this->lastGroupAttackTime == 0) || (this->sn[0x2f] != 2)) || (uVar28 == 0)) ||
               (uVar14 = attackLimiterTime(this,0x2e), uVar14 <= uVar28)) {
              if (((this->lastGroupAttackTime == 0) || (this->sn[0x2f] != 1)) ||
                 (uVar14 = attackLimiterTime(this,0x2e), uVar14 <= uVar28)) {
                iVar13 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
                if (iVar13 == 0) {
                  iVar13 = itemToCapture(this);
                  pOVar27 = TribeInformationAIModule::objectMemory(&this->md->informationAI,iVar13);
                  if (pOVar27 == (ObjectMemory *)0x0) {
                    if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                       (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                      iVar13 = 0;
                      if (0 < (this->playersToAttack).maximumSizeValue) {
                        do {
                          if (0 < iVar13) break;
                          iVar35 = iVar13 + 1;
                          piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                          iVar13 = iVar35;
                        } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                      }
LAB_004f29d8:
                      operator_delete((this->playersToAttack).value);
                      (this->playersToAttack).value = piVar19;
                      (this->playersToAttack).maximumSizeValue = 1;
                    }
LAB_004f29f7:
                    piVar4 = (this->playersToAttack).value;
                    piVar19 = &allOutsideTransport;
                    iVar13 = TacticalAIGroup::commander(this_02);
                    pOVar27 = TribeInformationAIModule::objectToAttack
                                        (&this->md->informationAI,*piVar4,1,1,iVar13,piVar19);
LAB_004f2ac7:
                    if (pOVar27 == (ObjectMemory *)0x0) {
                      TacticalAIGroup::setAction(this_02,1);
                      (this->attackStateValue).active = 0;
                      goto LAB_004f4552;
                    }
                  }
                }
                else {
                  iVar13 = TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI);
                  if (iVar13 != 4) {
                    if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                       (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                      iVar13 = 0;
                      if (0 < (this->playersToAttack).maximumSizeValue) {
                        do {
                          if (0 < iVar13) break;
                          iVar35 = iVar13 + 1;
                          piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                          iVar13 = iVar35;
                        } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                      }
                      operator_delete((this->playersToAttack).value);
                      (this->playersToAttack).value = piVar19;
                      (this->playersToAttack).maximumSizeValue = 1;
                    }
                    pOVar27 = TribeInformationAIModule::objectToAttackByGroup
                                        (&this->md->informationAI,*(this->playersToAttack).value,
                                         this_02,&this->attackStateValue,param_1);
                    if ((this->attackStateValue).active == 1) goto LAB_004f45bf;
                    goto LAB_004f2ac7;
                  }
                  iVar13 = itemToBringToArea(this);
                  pOVar27 = TribeInformationAIModule::objectMemory(&this->md->informationAI,iVar13);
                  if (pOVar27 == (ObjectMemory *)0x0) {
                    if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                       (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                      iVar13 = 0;
                      if (0 < (this->playersToAttack).maximumSizeValue) {
                        do {
                          if (0 < iVar13) break;
                          iVar35 = iVar13 + 1;
                          piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                          iVar13 = iVar35;
                        } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                      }
                      goto LAB_004f29d8;
                    }
                    goto LAB_004f29f7;
                  }
                }
                pOVar27->attackAttempts = pOVar27->attackAttempts + 1;
                goto LAB_004f2ae2;
              }
              (this->attackStateValue).active = 0;
            }
            else {
              (this->attackStateValue).active = 0;
            }
          }
        }
        else {
          iVar13 = TacticalAIGroup::action(this_02);
          if (iVar13 == 0xd) {
            iVar13 = TacticalAIGroup::waitCode(this_02);
            if (iVar13 == 200) {
              iVar13 = TacticalAIGroup::assistGroupID(this_02);
              if (iVar13 == -1) {
                iVar13 = TacticalAIGroup::commander(this_02);
                pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                if (pRVar26 == (RGE_Static_Object *)0x0) {
                  (this->attackStateValue).active = 0;
                  goto LAB_004f4552;
                }
                commanderPoint.y = __ftol();
                __ftol();
                pTVar21 = bestGroup(this,0x6a,1,-1,(XYPoint *)&commanderPoint.y,-1);
                if ((pTVar21 != (TacticalAIGroup *)0x0) ||
                   (pTVar21 = bestGroup(this,0x6a,0,-1,(XYPoint *)&commanderPoint.y,-1),
                   pTVar21 != (TacticalAIGroup *)0x0)) {
                  iVar13 = TacticalAIGroup::id(pTVar21);
                  TacticalAIGroup::setAssistGroupID(this_02,iVar13);
                  iVar13 = TacticalAIGroup::type(pTVar21);
                  TacticalAIGroup::setAssistGroupType(this_02,iVar13);
                  TacticalAIGroup::setAction(pTVar21,0xc);
                  TacticalAIGroup::setInUse(pTVar21,1);
                  iVar13 = TacticalAIGroup::id(this_02);
                  TacticalAIGroup::setAssistGroupID(pTVar21,iVar13);
                  goto LAB_004f2f57;
                }
              }
              else {
                iVar38 = -1;
                iVar36 = -1;
                iVar35 = -1;
                iVar13 = TacticalAIGroup::assistGroupID(this_02);
                pTVar21 = group(this,iVar13,iVar35,iVar36,iVar38);
LAB_004f2f57:
                if (pTVar21 != (TacticalAIGroup *)0x0) {
                  iVar13 = TacticalAIGroup::commander(pTVar21);
                  pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                  if ((pRVar26 == (RGE_Static_Object *)0x0) ||
                     (pRVar26->objects->number_of_objects <
                      (short)(ushort)pRVar26->master_obj->obj_max)) {
                    unitObj = (RGE_Static_Object *)0x0;
                    allOutsideTransport = 0;
                    iVar13 = TacticalAIGroup::numberUnits(this_02);
                    if (0 < iVar13) {
                      do {
                        iVar13 = TacticalAIGroup::unit(this_02,allOutsideTransport);
                        pRVar26 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)this->md,iVar13);
                        if ((pRVar26 != (RGE_Static_Object *)0x0) &&
                           (pUVar22 = RGE_Static_Object::unitAI(pRVar26),
                           pUVar22 != (UnitAIModule *)0x0)) {
                          pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                          iVar35 = UnitAIModule::currentAction(pUVar22);
                          if (iVar35 == -1) {
                            unitObj = (RGE_Static_Object *)0x1;
                            iVar35 = TacticalAIGroup::commander(pTVar21);
                            taskToEnter(this,iVar13,iVar35);
                          }
                        }
                        iVar35 = allOutsideTransport + 1;
                        allOutsideTransport = iVar35;
                        iVar13 = TacticalAIGroup::numberUnits(this_02);
                      } while (iVar35 < iVar13);
                    }
                    if (unitObj != (RGE_Static_Object *)0x0) goto LAB_004f43ca;
                    TacticalAIGroup::setAction(this_02,0xf);
                    (this->attackStateValue).active = 0;
                  }
                  else {
                    TacticalAIGroup::setAction(this_02,0xf);
                    (this->attackStateValue).active = 0;
                  }
                  goto LAB_004f4552;
                }
              }
              TacticalAIGroup::setAssistGroupID(this_02,-1);
              TacticalAIGroup::setAssistGroupType(this_02,-1);
              (this->attackStateValue).active = 0;
              goto LAB_004f4552;
            }
LAB_004f43ca:
            (this->attackStateValue).active = 0;
          }
          else {
            iVar13 = TacticalAIGroup::action(this_02);
            if (iVar13 == 0xf) {
              iVar38 = -1;
              iVar36 = -1;
              iVar35 = -1;
              iVar13 = TacticalAIGroup::assistGroupID(this_02);
              pTVar21 = group(this,iVar13,iVar35,iVar36,iVar38);
              if (pTVar21 != (TacticalAIGroup *)0x0) {
                iVar13 = TacticalAIGroup::commander(pTVar21);
                pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                if (pRVar26 != (RGE_Static_Object *)0x0) {
                  if ((short)(ushort)pRVar26->master_obj->obj_max <=
                      pRVar26->objects->number_of_objects) {
                    TacticalAIGroup::removeUnboardedUnits(this_02,this,this->md);
                  }
                  point.x = 0xff;
                  unitObj = (RGE_Static_Object *)0x1;
                  allInsideTransport = 0;
                  iVar13 = TacticalAIGroup::numberUnits(this_02);
                  if (0 < iVar13) {
                    do {
                      iVar13 = TacticalAIGroup::unit(this_02,allInsideTransport);
                      allOutsideTransport =
                           (int)MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if ((RGE_Static_Object *)allOutsideTransport == (RGE_Static_Object *)0x0) {
                        AIModule::logCommonHistory(this_00,(char *)this,s_____Unit__d_is_invalid_);
                      }
                      else {
                        pUVar22 = RGE_Static_Object::unitAI
                                            ((RGE_Static_Object *)allOutsideTransport);
                        if (pUVar22 == (UnitAIModule *)0x0) {
                          AIModule::logCommonHistory
                                    (this_01,(char *)this,s_____Unit__d_has_invalid_unitAI_);
                        }
                        else {
                          iVar13 = TacticalAIGroup::unit(this_02,allInsideTransport);
                          iVar35 = TacticalAIGroup::commander(this_02);
                          pRVar26 = (RGE_Static_Object *)allOutsideTransport;
                          if (iVar13 == iVar35) {
                            TacticalAIGroup::targetLocation(this_02);
                            iVar13 = __ftol();
                            TacticalAIGroup::targetLocation(this_02);
                            iVar35 = __ftol();
                            pRVar26 = (RGE_Static_Object *)allOutsideTransport;
                            XVar10.y = iVar35;
                            XVar10.x = iVar13;
                            bVar11 = RGE_Static_Object::lookupZone
                                               ((RGE_Static_Object *)allOutsideTransport,XVar10);
                            point.x = (int)bVar11;
                          }
                          allOutsideTransport = (int)pRVar26->inside_obj;
                          if (((RGE_Static_Object *)allOutsideTransport != (RGE_Static_Object *)0x0)
                             && (iVar13 = TacticalAIGroup::commander(pTVar21),
                                *(int *)(allOutsideTransport + 4) == iVar13)) {
                            pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                            iVar13 = UnitAIModule::currentAction(pUVar22);
                            if (iVar13 != -1) {
                              stopUnit(this,pRVar26->id,100);
                              goto LAB_004f323d;
                            }
                          }
                          allOutsideTransport = (int)pRVar26->inside_obj;
                          if (((RGE_Static_Object *)allOutsideTransport == (RGE_Static_Object *)0x0)
                             || (iVar13 = TacticalAIGroup::commander(pTVar21),
                                *(int *)(allOutsideTransport + 4) == iVar13)) {
                            if (pRVar26->inside_obj == (RGE_Static_Object *)0x0) {
                              unitObj = (RGE_Static_Object *)0x0;
                              pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                              iVar13 = UnitAIModule::currentOrder(pUVar22);
                              if (iVar13 != 700) {
                                pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                                iVar13 = UnitAIModule::currentOrder(pUVar22);
                                if (iVar13 != 0x2cd) {
                                  iVar13 = TacticalAIGroup::commander(pTVar21);
                                  iVar35 = TacticalAIGroup::unit(this_02,allInsideTransport);
                                  taskToEnter(this,iVar35,iVar13);
                                }
                              }
                            }
                          }
                          else {
                            TacticalAIGroup::removeUnit(this_02,pRVar26->id,this->md);
                          }
                        }
                      }
LAB_004f323d:
                      allInsideTransport = allInsideTransport + 1;
                      iVar13 = TacticalAIGroup::numberUnits(this_02);
                    } while (allInsideTransport < iVar13);
                  }
                  if (unitObj != (RGE_Static_Object *)0x0) {
                    TacticalAIGroup::targetLocation(this_02);
                    iVar13 = __ftol();
                    TacticalAIGroup::targetLocation(this_02);
                    iVar35 = __ftol();
                    iVar36 = TacticalAIGroup::commander(this_02);
                    iVar37 = 0xf;
                    iVar38 = TacticalAIGroup::target(this_02);
                    XVar9.y = iVar35;
                    XVar9.x = iVar13;
                    iVar13 = TribeInformationAIModule::findStagingPoint
                                       (&this->md->informationAI,XVar9,(XYPoint *)&stagingPoint.y,1,
                                        1,iVar38,iVar37,iVar36);
                    if (iVar13 == 0) {
                      TacticalAIGroup::targetLocation(this_02);
                      stagingPoint.y = __ftol();
                      TacticalAIGroup::targetLocation(this_02);
                      point_ffffff44.x = __ftol();
                    }
                    fVar31 = (float)point_ffffff44.x - -0.5;
                    fVar30 = (float)stagingPoint.y - -0.5;
                    iVar13 = TacticalAIGroup::commander(pTVar21);
                    taskTransporter(this,iVar13,fVar30,fVar31);
                    TacticalAIGroup::setTargetLocation
                              (pTVar21,(float)stagingPoint.y,(float)point_ffffff44.x,-1.0);
                    TacticalAIGroup::setAction(pTVar21,0xc);
                    TacticalAIGroup::setTargetType(pTVar21,point.x);
                    TacticalAIGroup::setAction(this_02,0x10);
                    TacticalAIGroup::task(this_02,this,this->md,0x16,0,1);
                    iVar13 = TacticalAIGroup::numberUnits(pTVar21);
                    if (1 < iVar13) {
                      iVar13 = 0;
                      allOutsideTransport = 0;
                      iVar35 = TacticalAIGroup::numberUnits(pTVar21);
                      if (0 < iVar35) {
                        do {
                          iVar35 = TacticalAIGroup::unit(pTVar21,iVar13);
                          iVar36 = TacticalAIGroup::commander(pTVar21);
                          iVar13 = allOutsideTransport;
                          if (iVar35 != iVar36) {
                            iVar35 = TacticalAIGroup::unit(pTVar21,allOutsideTransport);
                            pRVar26 = MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)this->md,iVar35);
                            if (pRVar26 != (RGE_Static_Object *)0x0) {
                              iVar38 = 99;
                              fVar31 = pRVar26->master_obj->los * 0.5;
                              iVar35 = TacticalAIGroup::commander(pTVar21);
                              iVar36 = TacticalAIGroup::unit(pTVar21,iVar13);
                              taskDefender(this,iVar36,iVar35,fVar31,iVar38);
                            }
                          }
                          iVar13 = iVar13 + 1;
                          allOutsideTransport = iVar13;
                          iVar35 = TacticalAIGroup::numberUnits(pTVar21);
                        } while (iVar13 < iVar35);
                      }
                    }
                  }
                  goto LAB_004f4548;
                }
              }
              goto LAB_004f37f1;
            }
            iVar13 = TacticalAIGroup::action(this_02);
            if (iVar13 == 0x10) {
              iVar38 = -1;
              iVar36 = -1;
              iVar35 = -1;
              iVar13 = TacticalAIGroup::assistGroupID(this_02);
              stagingPoint.x = (int)group(this,iVar13,iVar35,iVar36,iVar38);
              if ((TacticalAIGroup *)stagingPoint.x != (TacticalAIGroup *)0x0) {
                iVar13 = TacticalAIGroup::commander((TacticalAIGroup *)stagingPoint.x);
                pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                pathDistance_ffffff80 = (float)pRVar26;
                if (((pRVar26 != (RGE_Static_Object *)0x0) &&
                    (pUVar22 = RGE_Static_Object::unitAI(pRVar26), pUVar22 != (UnitAIModule *)0x0))
                   && (pRVar26->owner->id == *(short *)(this->md->_padding_ + 0x4a))) {
                  unitObj = (RGE_Static_Object *)0x1;
                  allOutsideTransport = 1;
                  allInsideTransport = 0;
                  iVar13 = TacticalAIGroup::numberUnits(this_02);
                  if (0 < iVar13) {
                    do {
                      iVar13 = TacticalAIGroup::unit(this_02,allInsideTransport);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if ((pRVar26 != (RGE_Static_Object *)0x0) &&
                         (pUVar22 = RGE_Static_Object::unitAI(pRVar26),
                         pUVar22 != (UnitAIModule *)0x0)) {
                        if (pRVar26->inside_obj == (RGE_Static_Object *)0x0) {
                          allOutsideTransport = 0;
                          iVar13 = TacticalAIGroup::target(this_02);
                          pRVar15 = MainDecisionAIModule::object
                                              ((MainDecisionAIModule *)this->md,iVar13);
                          iVar13 = TacticalAIGroup::type(this_02);
                          if ((iVar13 == 100) && (pRVar15 != (RGE_Static_Object *)0x0)) {
                            pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                            if (pUVar22 != (UnitAIModule *)0x0) {
                              pUVar22 = RGE_Static_Object::unitAI(pRVar26);
                              iVar13 = UnitAIModule::currentTarget(pUVar22);
                              iVar35 = TacticalAIGroup::target(this_02);
                              if (iVar13 != iVar35) {
                                iVar13 = pRVar26->_padding_;
                                fVar29 = (float10)(**(code **)(iVar13 + 0x10c))
                                                            (0,1,0xffffffff,0xffffffff);
                                fVar31 = (float)fVar29;
                                iVar35 = TacticalAIGroup::target(this_02);
                                iVar13 = (**(code **)(iVar13 + 0x194))(iVar35,fVar31);
                                if (iVar13 == 1) {
                                  iVar25 = 0;
                                  iVar37 = -1;
                                  iVar38 = 0;
                                  pWVar32 = (Waypoint *)0x0;
                                  iVar36 = -1;
                                  iVar13 = TacticalAIGroup::target(this_02);
                                  pWVar24 = TacticalAIGroup::targetLocation(this_02);
                                  fVar31 = pWVar24->y;
                                  pWVar24 = TacticalAIGroup::targetLocation(this_02);
                                  fVar30 = pWVar24->x;
                                  iVar35 = TacticalAIGroup::unit(this_02,allInsideTransport);
                                  taskAttacker(this,iVar35,fVar30,fVar31,iVar13,iVar36,pWVar32,
                                               iVar38,iVar37,iVar25);
                                }
                              }
                            }
                          }
                          else {
                            iVar35 = 100;
                            iVar13 = TacticalAIGroup::unit(this_02,allInsideTransport);
                            stopUnit(this,iVar13,iVar35);
                          }
                        }
                        else {
                          unitObj = (RGE_Static_Object *)0x0;
                        }
                      }
                      allInsideTransport = allInsideTransport + 1;
                      iVar13 = TacticalAIGroup::numberUnits(this_02);
                    } while (allInsideTransport < iVar13);
                  }
                  fVar31 = pathDistance_ffffff80;
                  if (allOutsideTransport == 1) {
                    uVar12 = RGE_Action_List::have_action
                                       (*(RGE_Action_List **)((int)pathDistance_ffffff80 + 0x184));
                    if ((uVar12 == '\0') ||
                       (pRVar23 = RGE_Action_List::get_action
                                            (*(RGE_Action_List **)((int)fVar31 + 0x184)),
                       pRVar23->state == '\x02')) {
                      iVar13 = stagingPoint.x;
                      pWVar24 = TacticalAIGroup::targetLocation((TacticalAIGroup *)stagingPoint.x);
                      fVar31 = pWVar24->y - -0.5;
                      pWVar24 = TacticalAIGroup::targetLocation((TacticalAIGroup *)iVar13);
                      fVar30 = pWVar24->x - -0.5;
                      iVar35 = TacticalAIGroup::commander((TacticalAIGroup *)iVar13);
                      taskTransporter(this,iVar35,fVar30,fVar31);
                      TacticalAIGroup::setAction((TacticalAIGroup *)iVar13,0xc);
                    }
                  }
                  else if (unitObj != (RGE_Static_Object *)0x0) {
                    iVar38 = -1;
                    iVar36 = -1;
                    iVar35 = -1;
                    iVar13 = TacticalAIGroup::assistGroupID(this_02);
                    pTVar21 = group(this,iVar13,iVar35,iVar36,iVar38);
                    if (pTVar21 != (TacticalAIGroup *)0x0) {
                      TacticalAIGroup::setTarget(pTVar21,-1);
                      TacticalAIGroup::setTargetType(pTVar21,-1);
                      TacticalAIGroup::setAction(pTVar21,1);
                      TacticalAIGroup::setInUse(pTVar21,0);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,-1,0x6d,-1,-1,-1,-1,-1,
                                           -1,-1,-1);
                      if (pRVar26 != (RGE_Static_Object *)0x0) {
                        fVar31 = pRVar26->world_y;
                        fVar30 = pRVar26->world_x;
                        iVar35 = 0x32;
                        iVar13 = TacticalAIGroup::commander(pTVar21);
                        moveUnit(this,iVar13,fVar30,fVar31,iVar35);
                      }
                    }
                    iVar13 = TacticalAIGroup::type(this_02);
                    if (iVar13 != 100) {
                      iVar13 = TacticalAIGroup::type(this_02);
                      if ((iVar13 != 0x65) &&
                         (iVar13 = TacticalAIGroup::type(this_02), iVar13 != 0x6d))
                      goto LAB_004f3825;
                      pWVar24 = TacticalAIGroup::targetLocation(this_02);
                      fVar31 = pWVar24->z;
                      pWVar24 = TacticalAIGroup::targetLocation(this_02);
                      fVar30 = pWVar24->y;
                      pWVar24 = TacticalAIGroup::targetLocation(this_02);
                      TacticalAIGroup::setGatherLocation(this_02,pWVar24->x,fVar30,fVar31);
                      TacticalAIGroup::setInUse(this_02,0);
                      TacticalAIGroup::setAction(this_02,1);
                      pTVar33 = this->md;
                      iVar13 = 1;
                      iVar36 = 1;
                      iVar35 = 1;
                      goto LAB_004f4540;
                    }
                    iVar13 = TacticalAIGroup::commander(this_02);
                    pRVar26 = MainDecisionAIModule::object((MainDecisionAIModule *)this->md,iVar13);
                    if (pRVar26 == (RGE_Static_Object *)0x0) {
LAB_004f376c:
                      TacticalAIGroup::setInUse(this_02,1);
                      TacticalAIGroup::setAction(this_02,7);
                      pTVar33 = this->md;
                      iVar13 = 1;
                      iVar36 = 0;
                      iVar35 = 7;
                      goto LAB_004f4540;
                    }
                    iVar13 = pRVar26->_padding_;
                    fVar29 = (float10)(**(code **)(iVar13 + 0x10c))(0,1,0xffffffff,0xffffffff);
                    fVar31 = (float)fVar29;
                    iVar35 = TacticalAIGroup::target(this_02);
                    iVar13 = (**(code **)(iVar13 + 0x194))(iVar35,fVar31);
                    if (iVar13 != 1) goto LAB_004f376c;
                    this->lastGroupAttackTime = *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4)
                    ;
                    if (this->sn[0x47] == 1) {
                      this->lastAttackResponseTime =
                           *(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4);
                    }
                    iVar13 = 2;
LAB_004f4526:
                    TacticalAIGroup::setAction(this_02,iVar13);
                    goto LAB_004f452d;
                  }
                  goto LAB_004f4548;
                }
              }
LAB_004f37f1:
              TacticalAIGroup::setTarget(this_02,-1);
              this_02->numberObjectsToDestroyValue = 0;
              TacticalAIGroup::setTargetType(this_02,-1);
              TacticalAIGroup::setAction(this_02,1);
              TacticalAIGroup::setInUse(this_02,0);
              (this->attackStateValue).active = 0;
            }
            else {
LAB_004f3825:
              iVar13 = TacticalAIGroup::action(this_02);
              if (iVar13 != 0xc) {
                iVar13 = TacticalAIGroup::action(this_02);
                if (iVar13 != 0x13) {
                  iVar13 = TacticalAIGroup::action(this_02);
                  if (iVar13 != 3) {
LAB_004f3a51:
                    iVar13 = TacticalAIGroup::action(this_02);
                    if (iVar13 == 7) {
                      iVar13 = TacticalAIGroup::commander(this_02);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                         (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                        iVar13 = 0;
                        if (0 < (this->playersToAttack).maximumSizeValue) {
                          do {
                            if (0 < iVar13) break;
                            iVar35 = iVar13 + 1;
                            piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                            iVar13 = iVar35;
                          } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                        }
                        operator_delete((this->playersToAttack).value);
                        (this->playersToAttack).value = piVar19;
                        (this->playersToAttack).maximumSizeValue = 1;
                      }
                      pOVar27 = TribeInformationAIModule::objectToAttackByGroup
                                          (&this->md->informationAI,*(this->playersToAttack).value,
                                           this_02,&this->attackStateValue,param_1);
                      if ((this->attackStateValue).active == 1) goto LAB_004f45bf;
                      pRVar15 = (RGE_Static_Object *)0x0;
                      if (pOVar27 != (ObjectMemory *)0x0) {
                        pRVar15 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)this->md,pOVar27->id);
                      }
                      if (((pRVar26 == (RGE_Static_Object *)0x0) || (pOVar27 == (ObjectMemory *)0x0)
                          ) || (pRVar15 == (RGE_Static_Object *)0x0)) {
LAB_004f3d28:
                        uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                        if ((uint)(this->sn[0x58] << 2) <
                            (*(int *)(*(int *)(this->md->_padding_ + 0x3c) + 4) - uVar14) / 1000) {
                          TacticalAIGroup::setAction(this_02,7);
                          pTVar33 = this->md;
                          iVar13 = 1;
                          iVar36 = 0;
                          iVar35 = 7;
                          goto LAB_004f4540;
                        }
                        goto LAB_004f3d75;
                      }
                      uVar12 = pOVar27->y;
                      uVar1 = pOVar27->z;
                      uVar2 = pOVar27->x;
                      iVar13 = pRVar26->_padding_;
                      allOutsideTransport = *(undefined4 *)(iVar13 + 0x10c);
                      fVar29 = (float10)(*(code *)allOutsideTransport)
                                                  (pOVar27->id,&transportObject,1,pOVar27->owner,
                                                   0x1b);
                      iVar35 = (**(code **)(iVar13 + 0x198))(uVar2,uVar12,uVar1,(float)fVar29);
                      if (iVar35 == 1) {
                        TacticalAIGroup::setAction(this_02,2);
                        TacticalAIGroup::setTarget(this_02,pOVar27->id);
                        TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                        stagingPoint.x = (int)pOVar27->x;
                        TacticalAIGroup::setTargetLocation
                                  (this_02,(float)stagingPoint.x,(float)pOVar27->y,(float)pOVar27->z
                                  );
                        TacticalAIGroup::setInUse(this_02,1);
                        pTVar33 = this->md;
                        iVar13 = 1;
                        iVar36 = 0;
                        iVar35 = 2;
                        goto LAB_004f4540;
                      }
                      fVar29 = (float10)(*(code *)allOutsideTransport)
                                                  (pOVar27->id,&transportObject,1,0x16,1,
                                                   pOVar27->owner,0x1b);
                      iVar35 = (**(code **)(iVar13 + 0x1a4))(uVar2,uVar12,uVar1,(float)fVar29);
                      if ((iVar35 != 1) ||
                         (iVar13 = (**(code **)(iVar13 + 0x1a8))(2,&gatherY_ffffffe4,&startPoint),
                         iVar13 != 1)) goto LAB_004f3d28;
                      TacticalAIGroup::task(this_02,this,this->md,0xe,1,0);
                      TacticalAIGroup::setAction(this_02,0xd);
                      TacticalAIGroup::setTarget(this_02,pOVar27->id);
                      TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                      bVar11 = pOVar27->z;
                      bVar3 = pOVar27->y;
                      uVar28 = (uint)pOVar27->x;
                      stagingPoint.x = uVar28;
LAB_004f3cf9:
                      TacticalAIGroup::setTargetLocation
                                (this_02,(float)uVar28,(float)bVar3,(float)bVar11);
                      TacticalAIGroup::setInUse(this_02,1);
                      TacticalAIGroup::setWaitCode(this_02,200);
                      this_02->playNumberValue = -1;
                      goto LAB_004f4548;
                    }
LAB_004f3d75:
                    iVar13 = TacticalAIGroup::action(this_02);
                    if ((iVar13 == 2) && (this_02->playNumberValue == -1)) {
                      if (this->sn[0x5b] < 100) {
                        iVar35 = 0;
                        iVar13 = TacticalAIGroup::numberUnits(this_02);
                        if (0 < iVar13) {
                          do {
                            iVar13 = TacticalAIGroup::unit(this_02,iVar35);
                            stagingPoint.x =
                                 (int)MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)this->md,iVar13);
                            if ((RGE_Static_Object *)stagingPoint.x == (RGE_Static_Object *)0x0) {
LAB_004f3e53:
                              iVar35 = iVar35 + 1;
                            }
                            else {
                              iVar13 = TacticalAIGroup::unitOriginalHitPoints(this_02,iVar35);
                              iVar36 = __ftol();
                              iVar38 = TacticalAIGroup::unitOriginalHitPoints(this_02,iVar35);
                              if (((iVar13 - iVar36) * 100) / iVar38 <= this->sn[0x5b])
                              goto LAB_004f3e53;
                              iVar36 = 100;
                              pWVar24 = TacticalAIGroup::retreatLocation(this_02);
                              fVar31 = pWVar24->y;
                              pWVar24 = TacticalAIGroup::retreatLocation(this_02);
                              fVar30 = pWVar24->x;
                              iVar13 = TacticalAIGroup::unit(this_02,iVar35);
                              moveUnit(this,iVar13,fVar30,fVar31,iVar36);
                              pTVar33 = this->md;
                              iVar13 = TacticalAIGroup::unit(this_02,iVar35);
                              TacticalAIGroup::removeUnit(this_02,iVar13,pTVar33);
                              iVar13 = TacticalAIGroup::numberUnits(this_02);
                              if (iVar13 == 0) break;
                            }
                            iVar13 = TacticalAIGroup::numberUnits(this_02);
                          } while (iVar35 < iVar13);
                        }
                      }
                      iVar13 = TacticalAIGroup::target(this_02);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if ((pRVar26 != (RGE_Static_Object *)0x0) && (pRVar26->object_state < 3)) {
                        iVar13 = TacticalAIGroup::subType(this_02);
                        if (iVar13 == -1) {
                          iVar13 = (**(code **)(*(int *)this->md->_padding_ + 0x1c))
                                             ((int)pRVar26->owner->id);
                          if (iVar13 == 0) {
                            iVar13 = TacticalAIGroup::allUnitsIdle(this_02,this->md,0);
                            if (iVar13 != 1) {
                              pTVar33 = this->md;
                              iVar13 = 1;
                              iVar36 = 0;
                              iVar35 = 0x14;
                              goto LAB_004f4540;
                            }
                            iVar13 = TacticalAIGroup::commander(this_02);
                            pRVar26 = MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)this->md,iVar13);
                            if (pRVar26 == (RGE_Static_Object *)0x0) {
                              (this->attackStateValue).active = 0;
                              goto LAB_004f4552;
                            }
                            iVar13 = pRVar26->_padding_;
                            fVar29 = (float10)(**(code **)(iVar13 + 0x10c))
                                                        (0,1,0xffffffff,0xffffffff);
                            fVar31 = (float)fVar29;
                            iVar35 = TacticalAIGroup::target(this_02);
                            iVar13 = (**(code **)(iVar13 + 0x194))(iVar35,fVar31);
                            if (iVar13 == 1) {
                              iVar36 = 0;
                              iVar35 = 0x14;
                              iVar13 = 1;
                              goto LAB_004f4539;
                            }
                            TacticalAIGroup::setGatherLocation
                                      (this_02,pRVar26->world_x,pRVar26->world_y,pRVar26->world_z);
                            TacticalAIGroup::setInUse(this_02,0);
                            TacticalAIGroup::setAction(this_02,1);
                            TacticalAIGroup::setTarget(this_02,-1);
                            TacticalAIGroup::setTargetType(this_02,-1);
                            this_02->numberObjectsToDestroyValue = 0;
                            TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                          }
                          else {
                            TacticalAIGroup::setInUse(this_02,0);
                            TacticalAIGroup::setAction(this_02,1);
                            TacticalAIGroup::setTarget(this_02,-1);
                            TacticalAIGroup::setTargetType(this_02,-1);
                            TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                            this_02->numberObjectsToDestroyValue = 0;
                            iVar13 = TacticalAIGroup::commander(this_02);
                            pRVar26 = MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)this->md,iVar13);
                            if (pRVar26 != (RGE_Static_Object *)0x0) {
                              TacticalAIGroup::setGatherLocation
                                        (this_02,pRVar26->world_x,pRVar26->world_y,pRVar26->world_z)
                              ;
                            }
                          }
                          goto LAB_004f4548;
                        }
                        iVar13 = TacticalAIGroup::subType(this_02);
                        if ((((iVar13 != 0) &&
                             (iVar13 = TacticalAIGroup::subType(this_02), iVar13 == 4)) &&
                            (pRVar26->owner->id == *(short *)(this->md->_padding_ + 0x4a))) &&
                           (iVar13 = TribeMainDecisionAIModule::isMoveable(this->md,pRVar26->id),
                           iVar13 != 0)) {
                          TacticalAIGroup::addUnit(this_02,pRVar26->id,this->md);
                          pWVar24 = TribeStrategyAIModule::targetPoint1(&this->md->strategyAI);
                          fVar31 = pWVar24->x;
                          fVar30 = pWVar24->y;
                          fVar34 = pWVar24->z;
                          pWVar24 = TribeStrategyAIModule::targetPoint2(&this->md->strategyAI);
                          fVar6 = pWVar24->x;
                          fVar7 = pWVar24->y;
                          fVar8 = pWVar24->z;
                          targetPoint.x = *(int *)&pWVar24->facetToNextWaypoint;
                          TacticalAIGroup::setInUse(this_02,0);
                          TacticalAIGroup::setAction(this_02,1);
                          TacticalAIGroup::setTarget(this_02,-1);
                          this_02->numberObjectsToDestroyValue = 0;
                          TacticalAIGroup::setTargetType(this_02,-1);
                          TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                          TacticalAIGroup::setGatherLocation
                                    (this_02,(fVar6 + fVar31) * 0.5,(fVar7 + fVar30) * 0.5,
                                     (fVar8 + fVar34) * 0.5);
                        }
                        uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                        if ((uint)this->sn[0x4c] <
                            (*(int *)(*(int *)(this->md->_padding_ + 0x3c) + 4) - uVar14) / 1000) {
                          TacticalAIGroup::setInUse(this_02,0);
                          TacticalAIGroup::setAction(this_02,1);
                          TacticalAIGroup::setTarget(this_02,-1);
                          TacticalAIGroup::setTargetType(this_02,-1);
                          TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                          this_02->numberObjectsToDestroyValue = 0;
                          (this->attackStateValue).active = 0;
                          goto LAB_004f4552;
                        }
                        goto LAB_004f436b;
                      }
                      if (this->sn[0x31] == 2) {
                        TacticalAIGroup::setAction(this_02,1);
                        TacticalAIGroup::setTarget(this_02,-1);
                        this_02->numberObjectsToDestroyValue = 0;
                        TacticalAIGroup::setTargetType(this_02,-1);
                        TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                        iVar13 = 0;
                        iVar36 = 1;
                        iVar35 = TacticalAIGroup::action(this_02);
                        pTVar33 = this->md;
                        goto LAB_004f4540;
                      }
                      iVar13 = TacticalAIGroup::commander(this_02);
                      pRVar26 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)this->md,iVar13);
                      if (pRVar26 == (RGE_Static_Object *)0x0) {
                        (this->attackStateValue).active = 0;
                        goto LAB_004f4552;
                      }
                      if (((this->playersToAttack).maximumSizeValue + -1 < 0) &&
                         (piVar19 = (int *)operator_new(4), piVar19 != (int *)0x0)) {
                        iVar13 = 0;
                        if (0 < (this->playersToAttack).maximumSizeValue) {
                          do {
                            if (0 < iVar13) break;
                            iVar35 = iVar13 + 1;
                            piVar19[iVar13] = (this->playersToAttack).value[iVar13];
                            iVar13 = iVar35;
                          } while (iVar35 < (this->playersToAttack).maximumSizeValue);
                        }
                        operator_delete((this->playersToAttack).value);
                        (this->playersToAttack).value = piVar19;
                        (this->playersToAttack).maximumSizeValue = 1;
                      }
                      pOVar27 = TribeInformationAIModule::objectToAttackByGroup
                                          (&this->md->informationAI,*(this->playersToAttack).value,
                                           this_02,&this->attackStateValue,param_1);
                      if ((this->attackStateValue).active == 1) {
LAB_004f45bf:
                        iVar13 = TacticalAIGroup::id(this_02);
                        this->nextActiveSoldierGroupToTaskValue = iVar13;
                        return;
                      }
                      if (pOVar27 != (ObjectMemory *)0x0) {
                        uVar12 = pOVar27->y;
                        uVar1 = pOVar27->x;
                        uVar2 = pOVar27->z;
                        iVar13 = pRVar26->_padding_;
                        fVar29 = (float10)(**(code **)(iVar13 + 0x10c))
                                                    (pOVar27->id,&gatherX_ffffffec,1,pOVar27->owner,
                                                     0x1b);
                        iVar13 = (**(code **)(iVar13 + 0x198))(uVar1,uVar12,uVar2,(float)fVar29);
                        if (iVar13 == 1) {
                          TacticalAIGroup::setTarget(this_02,pOVar27->id);
                          TacticalAIGroup::setTargetType(this_02,(int)pOVar27->type);
                          stagingPoint.x = (int)pOVar27->x;
                          TacticalAIGroup::setTargetLocation
                                    (this_02,(float)stagingPoint.x,(float)pOVar27->y,
                                     (float)pOVar27->z);
                          TacticalAIGroup::setInUse(this_02,1);
                          pTVar33 = this->md;
                          iVar13 = 0;
                          iVar36 = 0;
                          iVar35 = 2;
                          goto LAB_004f4540;
                        }
                      }
                      iVar13 = TacticalAIGroup::targetType(this_02);
                      TacticalAIGroup::setInUse(this_02,0);
                      TacticalAIGroup::setAction(this_02,1);
                      TacticalAIGroup::setTarget(this_02,-1);
                      this_02->numberObjectsToDestroyValue = 0;
                      TacticalAIGroup::setTargetType(this_02,-1);
                      TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                      if (this->sn[0x31] == 0) {
                        TacticalAIGroup::setGatherLocation
                                  (this_02,pRVar26->world_x,pRVar26->world_y,pRVar26->world_z);
                        goto LAB_004f4548;
                      }
                      if (((this->sn[0x31] != 3) || (iVar13 == 0x7e)) || (iVar13 == 0x59))
                      goto LAB_004f4548;
                      if (this->sn[0x87] == 1) {
                        iVar35 = __ftol();
                        iVar13 = this->sn[0x88];
                        iVar36 = __ftol();
                        TribeInformationAIModule::blotExploredMap
                                  (&this->md->informationAI,iVar36 - iVar13,iVar35 - iVar13,
                                   iVar36 + iVar13,iVar13 + iVar35);
                      }
                      TacticalAIGroup::setInUse(this_02,1);
                      TacticalAIGroup::setAction(this_02,7);
                      iVar13 = 1;
                      iVar36 = 0;
                      iVar35 = 7;
                    }
                    else {
LAB_004f436b:
                      iVar13 = TacticalAIGroup::action(this_02);
                      if ((iVar13 == 2) && (this_02->playNumberValue != -1)) {
                        iVar13 = TacticalAIGroup::commander(this_02);
                        pRVar26 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)this->md,iVar13);
                        if ((pRVar26 != (RGE_Static_Object *)0x0) &&
                           ((pUVar22 = RGE_Static_Object::unitAI(pRVar26),
                            pUVar22 != (UnitAIModule *)0x0 &&
                            (pUVar22 = RGE_Static_Object::unitAI(pRVar26),
                            pUVar22->playStatus == (AIPlayStatus *)0x0)))) {
                          this_02->playNumberValue = -1;
                          (this->attackStateValue).active = 0;
                          goto LAB_004f4552;
                        }
                        goto LAB_004f43ca;
                      }
                      iVar13 = TacticalAIGroup::action(this_02);
                      if (iVar13 != 4) {
LAB_004f4499:
                        iVar13 = TacticalAIGroup::action(this_02);
                        if ((iVar13 != 3) &&
                           (iVar13 = TacticalAIGroup::action(this_02), iVar13 != 0xd)) {
                          iVar13 = TacticalAIGroup::currentHitPoints(this_02,this->md);
                          iVar35 = TacticalAIGroup::originalHitPoints(this_02);
                          iVar36 = TacticalAIGroup::originalHitPoints(this_02);
                          iVar38 = TacticalAIGroup::numberUnits(this_02);
                          iVar37 = TacticalAIGroup::originalUnitNumber(this_02);
                          iVar25 = TacticalAIGroup::originalUnitNumber(this_02);
                          if ((this->sn[0x1e] < ((iVar35 - iVar13) * 100) / iVar36) ||
                             (this->sn[0x1f] < ((iVar37 - iVar38) * 100) / iVar25)) {
                            iVar13 = 3;
                            goto LAB_004f4526;
                          }
                        }
                        goto LAB_004f4552;
                      }
                      iVar13 = TacticalAIGroup::allUnitsIdle(this_02,this->md,1);
                      if ((iVar13 != 1) ||
                         (iVar13 = TacticalAIGroup::isGathered(this_02,this,this->md), iVar13 != 0))
                      {
                        iVar13 = TacticalAIGroup::target(this_02);
                        pRVar26 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)this->md,iVar13);
                        if (pRVar26 != (RGE_Static_Object *)0x0) {
                          iVar36 = (int)pRVar26->master_obj->object_group;
                          iVar13 = TacticalAIGroup::targetType(this_02);
                          iVar35 = TacticalAIGroup::commander(this_02);
                          pOVar27 = TribeInformationAIModule::higherPriorityObjectToDefend
                                              (&this->md->informationAI,iVar35,iVar13,iVar36);
                          if (pOVar27 == (ObjectMemory *)0x0) goto LAB_004f4499;
                          iVar13 = TacticalAIGroup::target(this_02);
                          pOVar27 = TribeInformationAIModule::objectMemory
                                              (&this->md->informationAI,iVar13);
                          if (pOVar27 != (ObjectMemory *)0x0) {
                            pOVar27->attackAttempts = 0;
                          }
                        }
                        TacticalAIGroup::setAction(this_02,1);
                        TacticalAIGroup::setInUse(this_02,0);
                        goto LAB_004f448e;
                      }
                      iVar36 = 1;
                      iVar35 = 9;
                      iVar13 = 0;
                    }
LAB_004f4539:
                    pTVar33 = this->md;
                    goto LAB_004f4540;
                  }
                  pTVar33 = this->md;
                  uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                  if ((uint)this->sn[0x4c] <
                      (*(int *)(*(int *)(pTVar33->_padding_ + 0x3c) + 4) - uVar14) / 1000) {
                    TacticalAIGroup::setInUse(this_02,0);
                    TacticalAIGroup::setAction(this_02,1);
                    TacticalAIGroup::setTarget(this_02,-1);
                    this_02->numberObjectsToDestroyValue = 0;
                    TacticalAIGroup::setTargetType(this_02,-1);
                    TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
                    (this->attackStateValue).active = 0;
                    goto LAB_004f4552;
                  }
                  iVar13 = TacticalAIGroup::isGathered(this_02,this,pTVar33);
                  if (iVar13 == 0) goto LAB_004f3a51;
                  TacticalAIGroup::setAction(this_02,1);
                  TacticalAIGroup::setInUse(this_02,0);
                  iVar13 = TacticalAIGroup::type(this_02);
                  if ((iVar13 == 0x65) || (iVar13 = TacticalAIGroup::type(this_02), iVar13 == 0x68))
                  {
                    iVar13 = TacticalAIGroup::target(this_02);
                    pOVar27 = TribeInformationAIModule::objectMemory
                                        (&this->md->informationAI,iVar13);
                    if (pOVar27 != (ObjectMemory *)0x0) {
                      pOVar27->attackAttempts = 0;
                    }
                  }
                  iVar13 = BuildAIModule::buildListLength((BuildAIModule *)&this->md->buildAI);
                  if ((iVar13 == 0) &&
                     (((iVar13 = TacticalAIGroup::type(this_02), iVar13 == 100 &&
                       (iVar13 = numberGroups(this,100,-1), 1 < iVar13)) ||
                      (iVar13 = TacticalAIGroup::type(this_02), iVar13 != 100)))) {
                    iVar13 = TacticalAIGroup::type(this_02);
                    if (iVar13 == 0x66) {
                      this->sn[0x2a] = this->sn[0x2a] + -1;
                    }
                    else {
                      iVar13 = TacticalAIGroup::type(this_02);
                      if (iVar13 == 0x65) {
                        this->sn[0x26] = this->sn[0x26] + -1;
                      }
                      else {
                        iVar13 = TacticalAIGroup::type(this_02);
                        if (iVar13 == 100) {
                          this->sn[0x24] = this->sn[0x24] + -1;
                        }
                      }
                    }
                    TacticalAIGroup::removeUnits(this_02,this->md);
                    TacticalAIGroup::setAction(this_02,0);
                    (this->attackStateValue).active = 0;
                    goto LAB_004f4552;
                  }
LAB_004f448e:
                  (this->attackStateValue).active = 0;
                  goto LAB_004f4552;
                }
                iVar13 = TacticalAIGroup::isGathered(this_02,this,this->md);
                if (iVar13 == 0) {
                  pTVar33 = this->md;
                  uVar14 = TacticalAIGroup::consecutiveIdleUnitCount(this_02);
                  iVar13 = *(int *)(*(int *)(pTVar33->_padding_ + 0x3c) + 4);
                  iVar35 = TacticalAIGroup::allUnitsIdle(this_02,pTVar33,1);
                  if ((iVar35 == 1) && (5 < (iVar13 - uVar14) / 1000)) {
                    TacticalAIGroup::setConsecutiveIdleUnitCount
                              (this_02,*(ulong *)(*(int *)(this->md->_padding_ + 0x3c) + 4));
                    pTVar33 = this->md;
                    iVar13 = 0;
                    iVar36 = 1;
                    iVar35 = 9;
                    goto LAB_004f4540;
                  }
                }
              }
LAB_004f4548:
              (this->attackStateValue).active = 0;
            }
          }
        }
LAB_004f4552:
                    /* Symbol Ref: {@symbol ContinueLoop} */
        if ((this->attackStateValue).active != 0) {
          return;
        }
        this_02 = this_02->next;
        if ((this_02 == &this->groups) || (this_02 == (TacticalAIGroup *)0x0)) {
          this->nextActiveSoldierGroupToTaskValue = -1;
        }
        else {
          iVar13 = TacticalAIGroup::id(this_02);
          this->nextActiveSoldierGroupToTaskValue = iVar13;
        }
        uVar14 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x14fe);
        if (param_2 <= uVar14 - param_1) {
          return;
        }
      }
    } while (this_02 != &this->groups);
  }
  this->nextActiveSoldierGroupToTaskValue = -1;
  return;
}


}
#endif

typedef unsigned char uchar;
typedef unsigned long ulong;

extern unsigned long debug_timeGetTime(const char* file, int line);
extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);
static const char s_C__msdev_work_age1_x1_taitacmd_c[] = "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";

struct XYPoint { int x; int y; };
struct XYZPoint { int x; int y; int z; };
struct Waypoint { float x; float y; float z; int facetToNextWaypoint; };

class TribeTacticalAIModule;
class TribeMainDecisionAIModule;
class RGE_Static_Object;
class ObjectMemory;
class TacticalAIGroup;
class TribeInformationAIModule;
struct AttackState;
class RGE_Player;
class RGE_World;
class UnitAIModule;
class TribeStrategyAIModule;
class BuildAIModule;
class RGE_Action;
class RGE_Action_List;
class AIPlayStatus;

class Path;
void __cdecl logCommonHistory(TribeTacticalAIModule*, const char*, ...);

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class VPlayerIsEnemy {
public:
    VPAD4(0) VPAD2(4) VPAD1(6)
    virtual int isEnemy(int player_id); // +0x1c
};

// RGE_Static_Object virtual-call views.  Keep these separate from the flat data
// layout below: the real object already owns the vptr at +0, while each view
// exposes only the binary-observed slot needed by a particular call surface.
class VObjWeaponRange {
public:
    VPAD64(0) VPAD2(64) VPAD1(66)
    virtual float weaponRange(); // +0x10c
};
class VObjCanMove {
public:
    VPAD64(0) VPAD32(64) VPAD4(96) VPAD2(100)
    virtual int canPath(XYZPoint point, float range, int target_id, float* out,
                        int a, int b, int c); // +0x198
};
class VObjCanAttack {
public:
    VPAD64(0) VPAD32(64) VPAD4(96) VPAD1(100)
    virtual int canAttack(int target_id, float range); // +0x194
};
class VObjCanPath {
public:
    VPAD64(0) VPAD32(64) VPAD8(96) VPAD1(104)
    virtual int canPathWithAdditionalPassability(XYZPoint point, float range, int target_id,
                                                  float* out, int a, int b, int c,
                                                  int d, int e); // +0x1a4
};
class VObjPathPoint {
public:
    VPAD64(0) VPAD32(64) VPAD8(96) VPAD2(104)
    virtual int findFirstTerrainAlongExceptionPath(int mode, float* out, float* aux); // +0x1a8
};
class VObjFindAvoidancePath {
public:
    VPAD64(0) VPAD32(64) VPAD16(96) VPAD2(112) VPAD1(114)
    virtual Path* findAvoidancePath(XYZPoint* point, float range, int mode); // +0x1cc
};

class AIPlayStatus {};
class RGE_Action { public: char gap_00[0x0C]; unsigned char state; };
class RGE_Action_List { public: unsigned char have_action(); RGE_Action* get_action(); };
class UnitAIModule { public: char gap_000[0x12C]; AIPlayStatus* playStatus; int currentAction(); int currentOrder(); int currentTarget(); };
class MasterObject { public: char gap_00[0x10]; short id; short copy_id; short object_group; char gap_16[0x12]; float los; unsigned char obj_max; };
class ObjectList { public: char gap_00[0x08]; short number_of_objects; };
class TribeStrategyAIModule { public: int currentVictoryCondition(); Waypoint* targetPoint1(); Waypoint* targetPoint2(); };
class BuildAIModule { public: char gap_000[0x05C0]; int buildListLength(); };

class RGE_World {
public:
    int pad_00;
    int world_time;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world;
    char gap_40[0x0A];
    short id;
};

class ObjectMemory {
public:
    int id;                 // +0x00
    short type;             // +0x04
    short group;            // +0x06
    unsigned char x;        // +0x08
    unsigned char y;        // +0x09
    unsigned char z;        // +0x0A
    unsigned char owner;    // +0x0B
    short hitPoints;        // +0x0C
    char gap_0E[0x02];
    int attackAttempts;     // +0x10
};

class RGE_Static_Object {
public:
    void* vtable_ptr;              // +0x00
    int id;                        // +0x04
    MasterObject* master_obj;      // +0x08
    RGE_Player* owner;             // +0x0C
    char gap_10[0x10];
    RGE_Static_Object* inside_obj; // +0x20
    ObjectList* objects;           // +0x24
    char gap_28[0x08];
    float hp;                      // +0x30
    char gap_34[0x04];
    float world_x;                 // +0x38
    float world_y;                 // +0x3C
    float world_z;                 // +0x40
    char gap_44[0x04];
    unsigned char object_state;    // +0x48
    char gap_49[0x05];
    unsigned char type;            // +0x4E
    char gap_4F[0x135];
    RGE_Action_List* actions;      // +0x184

    UnitAIModule* unitAI();
    unsigned char lookupZone(XYPoint p);
    float pathDistance(int target_id, void* out, int a, int b, int c);
    float pathDistance2(int target_id, void* out, int a, int b, int c, int d, int e);
    int canMoveTo(int x, int y, int z, float distance);
    int canPathTo(int x, int y, int z, float distance, int target_id, void* out, int a, int b, int c, int d, int e);
    int pathPoint(int mode, float* out, void* aux);
};

class TribeInformationAIModule {
public:
    char gap_00000[0x10090];
    ObjectMemory* objectToDefend(int commander_id);
    ObjectMemory* objectMemory(int id);
    ObjectMemory* objectToAttack(int player, int a, int b, int commander, int* all_outside_transport);
    ObjectMemory* objectToAttackByGroup(int player, TacticalAIGroup* group, AttackState* attack_state, ulong time_limit);
    ObjectMemory* higherPriorityObjectToDefend(int commander, int target_type, int object_group);
    void blotExploredMap(int x1, int y1, int x2, int y2);
    void addEnemyInfluences(unsigned int owner, int id);
    void addPriorAttackInfluences(unsigned int owner, int id);
    int findStagingPoint(XYPoint target, XYPoint* out, int a, int b, int target_id, int action, int commander);
};

class TribeMainDecisionAIModule {
public:
    char gap_0000[0x00F0];
    RGE_Player* player;                 // +0x00F0
    char gap_00F4[0x0010];
    BuildAIModule buildAI;              // +0x0104
    char gap_06C4[0x0628];
    TribeInformationAIModule informationAI; // +0x0CEC
    char gap_10D7C[0x00F8];
    TribeStrategyAIModule strategyAI;   // +0x10E74

    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
    int isEnemy(int player_id);
    int isMoveable(int id);
};

struct ManagedArray_int {
    int* value;                // +0x00
    int numberValue;           // +0x04
    int desiredNumberValue;    // +0x08
    int maximumSizeValue;      // +0x0C
};

struct AttackState {
    char gap_00[0x28];
    int active;                // +0x28
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;     // +0x04
    TacticalAIGroup* prev;     // +0x08
    char gap_00C[0x01C4];
    int playNumberValue;       // +0x1D0
    char gap_1D4[0x00F8];
    int numberObjectsToDestroyValue; // +0x2CC
    char gap_2D0[0x0060];

    int id();
    int type();
    int inUse();
    int action();
    int subType();
    int commander();
    int numberUnits();
    int unit(int index);
    int target();
    int targetType();
    Waypoint* targetLocation();
    Waypoint* retreatLocation();
    int unitOriginalHitPoints(int index);
    int currentHitPoints(TribeMainDecisionAIModule* md);
    int originalHitPoints();
    int originalUnitNumber();
    int isGathered(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int waitCode();
    int assistGroupID();
    int allUnitsIdle(TribeMainDecisionAIModule*, int);
    ulong consecutiveIdleUnitCount();
    void setAction(int);
    void setTarget(int);
    void setTargetType(int);
    void setTargetLocation(float, float, float);
    void setGatherLocation(float, float, float);
    void setInUse(int);
    void setWaitCode(int);
    void setAssistGroupID(int);
    void setAssistGroupType(int);
    int task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int);
    void setConsecutiveIdleUnitCount(ulong);
    void removeUnboardedUnits(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    int removeUnit(int unit_id, TribeMainDecisionAIModule*);
    void removeUnits(TribeMainDecisionAIModule*);
    int addUnit(int unit_id, TribeMainDecisionAIModule*);
};

class TribeTacticalAIModule {
public:
    char gap_0000[0x00F0];             // +0x0000
    TribeMainDecisionAIModule* md;     // +0x00F0
    char gap_00F4[0x00A0];             // +0x00F4
    int sn[226];                       // +0x0194
    char gap_051C[0x04B8];             // +0x051C
    TacticalAIGroup groups;            // +0x09D4 sentinel (next observed at +0x09D8)
    int groupIDValue;                  // +0x0D04
    int numberGroupsValue;             // +0x0D08
    unsigned long lastGroupAttackTime; // +0x0D0C
    unsigned long lastGroupRebalanceTime; // +0x0D10
    unsigned long lastAttackResponseTime; // +0x0D14
    char gap_0D18[0x0010];
    ManagedArray_int playersToAttack;  // +0x0D28
    char gap_0D38[0x00E0];
    int attackEnabledValue;            // +0x0E18
    char gap_0E1C[0x0164];
    int nextIdleSoldierGroupToTaskValue; // +0x0F80
    int nextActiveSoldierGroupToTaskValue; // +0x0F84
    char gap_0F88[0x0024];             // +0x0F88
    AttackState attackStateValue;      // +0x0FAC

    ulong attackLimiterTime(int sn_id);
    int itemToCapture();
    int itemToBringToArea();
    void checkForCoopAttack(int owner, int x, int y);
    TacticalAIGroup* bestGroup(int type, int in_use, int subtype, XYPoint* near_point, int action);
    TacticalAIGroup* group(int id, int type, int subtype, int action);
    int taskToEnter(int unit_id, int transport_id);
    int taskTransporter(int transport_id, float x, float y);
    int taskDefender(int unit_id, int target_id, float distance, int code);
    int taskAttacker(int unit_id, float x, float y, int target, int subtype, Waypoint* waypoint, int a, int b, int c);
    int moveUnit(int unit_id, float x, float y, int code);
    int stopUnit(int unit_id, int code);
    int numberGroups(int type, int action);
    void stuffAvoidancePath(TacticalAIGroup* group, Path* path);
    void taskActiveSoldiers(ulong param_1, ulong param_2);
};

void TribeTacticalAIModule::taskActiveSoldiers(ulong param_1, ulong param_2)
{
#define RESET_GROUP(g) do { \
    (g)->setInUse(0); \
    (g)->setAction(1); \
    (g)->setTarget(-1); \
    (g)->numberObjectsToDestroyValue = 0; \
    (g)->setTargetType(-1); \
    (g)->setTargetLocation(-1.0f, -1.0f, -1.0f); \
} while (0)
#define TASK_GROUP(code, arg1, arg2) do { \
    pendingTaskCode = (code); \
    pendingTaskArg1 = (arg1); \
    pendingTaskArg2 = (arg2); \
    goto task_group; \
} while (0)
    TacticalAIGroup* cur;
    int pendingTaskCode;
    int pendingTaskArg1;
    int pendingTaskArg2;
    ObjectMemory* mem;
    int t;
    float directGatherY;
    float directGatherZ;

    cur = this->groups.next;
    if (this->nextActiveSoldierGroupToTaskValue != -1) {
        while (cur != &this->groups) {
            if (cur == 0) {
                break;
            }
            if (cur->id() == this->nextActiveSoldierGroupToTaskValue) {
                break;
            }
            cur = cur->next;
        }
        if (cur->id() != this->nextActiveSoldierGroupToTaskValue) {
            cur = this->groups.next;
        }
    }

    if (cur != &this->groups) {
        do {
            if (cur == 0) {
                break;
            }

            t = cur->type();
            if (t == 0x6b || cur->type() == 0x6c || cur->type() == 0x6a ||
                cur->action() == 0 || cur->action() == 1) {
                cur = cur->next;
                continue;
            }

            if (!cur->allUnitsIdle(this->md, 1)) {
                cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
            }

            if (!cur->inUse()) {
                RGE_Static_Object* commanderObj;
                int attackAsAttack;

                mem = 0;
                commanderObj = 0;
                attackAsAttack = 1;
                t = cur->type();
                if (t != 100 && cur->type() != 0x67) {
                    t = cur->type();
                    if (t == 0x65 || cur->type() == 0x68) {
                        int commander;
                        XYZPoint point;
                        float defendDistance;
                        float pathDistance;
                        float gatherX;
                        float gatherY;

                        commander = cur->commander();
                        mem = this->md->informationAI.objectToDefend(commander);
                        if (mem == 0) {
                            cur->setAction(1);
                            goto clear_attack_state;
                        } else {
                            commander = cur->commander();
                            commanderObj = this->md->object(commander);
                            if (commanderObj == 0) {
                                cur->setAction(1);
                                goto clear_attack_state;
                            } else {
                                if (mem->type == 0x6d) {
                                    defendDistance = (float)this->sn[0x16];
                                } else {
                                    defendDistance = (float)this->sn[0x39];
                                }
                                point.z = mem->z;
                                point.x = mem->x;
                                point.y = mem->y;
                                if (!((VObjCanMove*)commanderObj)->canPath(point,
                                        ((VObjWeaponRange*)commanderObj)->weaponRange(),
                                        mem->id, &pathDistance, 1, -1, -1)) {
                                    if (((VObjCanPath*)commanderObj)->canPathWithAdditionalPassability(
                                            point, defendDistance, mem->id, &pathDistance,
                                            1, 0x16, 1, -1, -1) &&
                                        ((VObjPathPoint*)commanderObj)->findFirstTerrainAlongExceptionPath(
                                            2, &gatherX, &gatherY) == 1) {
                                        mem->attackAttempts = 1;
                                        cur->task(this, this->md, 0x0e, 1, 0);
                                        cur->setAction(0x0d);
                                        cur->setTarget(mem->id);
                                        cur->setTargetType((int)mem->type);
                                        cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                        cur->setInUse(1);
                                        cur->setWaitCode(200);
                                        goto clear_attack_state;
                                    } else {
                                        cur->setAction(1);
                                        goto clear_attack_state;
                                    }
                                } else {
                                    mem->attackAttempts = 1;
                                    cur->setTarget(mem->id);
                                    cur->setTargetType((int)mem->type);
                                    cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                    directGatherZ = (float)mem->z;
                                    directGatherY = (float)mem->y;
                                    *(float*)&pendingTaskArg2 = (float)mem->x;
                                    goto inactive_direct_gather;
                                }
                            }
                        }
                    } else {
                        t = cur->type();
                        if (t == 0x6d) {
                            RGE_Static_Object* relic;
                            TribeMainDecisionAIModule* md;
                            unsigned long idle;
                            unsigned long elapsed;

                            md = this->md;
                            idle = cur->consecutiveIdleUnitCount();
                            elapsed = (md->player->world->world_time - idle) / 1000;
                            if (elapsed < 60) {
                                cur->setAction(1);
                                goto clear_attack_state;
                            } else {
                                relic = md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
                                if (relic == 0) {
                                    cur->setAction(1);
                                    goto clear_attack_state;
                                } else {
                                    commanderObj = this->md->object(cur->commander());
                                    if (commanderObj == 0) {
                                        cur->setAction(1);
                                        goto clear_attack_state;
                                    } else {
                                        XYZPoint point;
                                        float pathDistance;
                                        float gatherX;
                                        float gatherY;
                                        point.x = (int)relic->world_x;
                                        point.y = (int)relic->world_y;
                                        point.z = (int)relic->world_z;
                                        if (!((VObjCanMove*)commanderObj)->canPath(point,
                                                (float)this->sn[0x17], relic->id,
                                                &pathDistance, 1, -1, -1)) {
                                            if (!((VObjCanPath*)commanderObj)->canPathWithAdditionalPassability(
                                                    point, (float)this->sn[0x17], relic->id,
                                                    &pathDistance, 1, 0x16, 1, -1, -1)) {
                                                cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
                                                cur->setAction(1);
                                                goto clear_attack_state;
                                            } else if (((VObjPathPoint*)commanderObj)->findFirstTerrainAlongExceptionPath(
                                                           2, &gatherX, &gatherY) == 1) {
                                                cur->task(this, this->md, 0x0e, 1, 0);
                                                cur->setAction(0x0d);
                                                cur->setTarget(relic->id);
                                                cur->setTargetType((int)relic->type);
                                                cur->setTargetLocation(relic->world_x, relic->world_y, relic->world_z);
                                                cur->setInUse(1);
                                                cur->setWaitCode(200);
                                            } else {
                                                cur->setAction(1);
                                                goto clear_attack_state;
                                            }
                                        } else {
                                            cur->setTarget(relic->id);
                                            cur->setTargetType((int)relic->type);
                                            cur->setTargetLocation(relic->world_x, relic->world_y, relic->world_z);
                                            *(float*)&pendingTaskArg2 = relic->world_x;
                                            directGatherY = relic->world_y;
                                            directGatherZ = relic->world_z;
                                            goto inactive_direct_gather;
                                        }
                                    }
                                }
                            }
                            goto clear_attack_state;
                        } else {
                            goto inactive_post_setup;
active_target_selection:
                            int* players;
                            int* newPlayers;
                            if (this->md->strategyAI.currentVictoryCondition() == 0) {
                                int capture;
                                capture = this->itemToCapture();
                                mem = this->md->informationAI.objectMemory(capture);
                                if (mem == 0) {
                                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                        newPlayers = (int*)operator_new(4);
                                        if (newPlayers != 0) {
                                            int i;
                                            i = 0;
                                            while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                                newPlayers[i] = this->playersToAttack.value[i];
                                                i++;
                                            }
                                            goto inactive_resize_commit;
                                        }
                                    }
                                    goto inactive_object_to_attack;
                                }
                            } else if (this->md->strategyAI.currentVictoryCondition() == 4) {
                                int bring;
                                bring = this->itemToBringToArea();
                                mem = this->md->informationAI.objectMemory(bring);
                                if (mem == 0) {
                                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                        newPlayers = (int*)operator_new(4);
                                        if (newPlayers != 0) {
                                            int i;
                                            i = 0;
                                            while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                                newPlayers[i] = this->playersToAttack.value[i];
                                                i++;
                                            }
                                            goto inactive_resize_commit;
                                        }
                                    }
                                    goto inactive_object_to_attack;
                                }
                            } else {
                                if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                    int* newPlayers;
                                    newPlayers = (int*)operator_new(4);
                                    if (newPlayers != 0) {
                                        int i;
                                        i = 0;
                                        while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                            newPlayers[i] = this->playersToAttack.value[i];
                                            i++;
                                        }
                                        operator_delete(this->playersToAttack.value);
                                        this->playersToAttack.value = newPlayers;
                                        this->playersToAttack.maximumSizeValue = 1;
                                    }
                                }
                                players = this->playersToAttack.value;
                                mem = this->md->informationAI.objectToAttackByGroup(*players, cur, &this->attackStateValue, param_1);
                                if (this->attackStateValue.active == 1) {
                                    this->nextActiveSoldierGroupToTaskValue = cur->id();
                                    return;
                                }
                                goto active_target_selected_common;
                            }
                            goto active_target_selected_common;
inactive_resize_commit:
                            operator_delete(this->playersToAttack.value);
                            this->playersToAttack.value = newPlayers;
                            this->playersToAttack.maximumSizeValue = 1;
inactive_object_to_attack:
                            players = this->playersToAttack.value;
                            mem = this->md->informationAI.objectToAttack(*players, 1, 1,
                                                                         cur->commander(),
                                                                         &attackAsAttack);
                            goto active_target_selected_common;
                        }
                    }
                } else {
                    int attackEnabled;
                    int* players;
                    int* newPlayers;
                    unsigned long lastAttackTime;
                    unsigned long elapsed;

                    attackEnabled = this->attackEnabledValue;
                    if (attackEnabled == 0) {
                        this->attackStateValue.active = 0;
                    } else {
                        if (this->sn[0xa2] != 0 && cur->type() != 0x67) {
                            mem = this->md->informationAI.objectMemory(*(int*)0);
                            goto attack_target_ready;
                        }
                        lastAttackTime = this->lastGroupAttackTime;
                        elapsed = (this->md->player->world->world_time - lastAttackTime) / 1000;
                        if (lastAttackTime != 0 && this->sn[0x2f] == 2 && elapsed != 0 && this->attackLimiterTime(0x2e) > elapsed) {
                            this->attackStateValue.active = 0;
                        } else if (lastAttackTime != 0 && this->sn[0x2f] == 1 && this->attackLimiterTime(0x2e) > elapsed) {
                            this->attackStateValue.active = 0;
                        } else {
                            if (this->md->strategyAI.currentVictoryCondition() == 0) {
                                int capture;
                                capture = this->itemToCapture();
                                mem = this->md->informationAI.objectMemory(capture);
                                if (mem == 0) {
                                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                        newPlayers = (int*)operator_new(4);
                                        if (newPlayers != 0) {
                                            int i;
                                            i = 0;
                                            while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                                newPlayers[i] = this->playersToAttack.value[i];
                                                i++;
                                            }
                                            goto active_resize_commit;
                                        }
                                    }
                                    goto active_object_to_attack;
                                }
                            } else if (this->md->strategyAI.currentVictoryCondition() == 4) {
                                int bring;
                                bring = this->itemToBringToArea();
                                mem = this->md->informationAI.objectMemory(bring);
                                if (mem == 0) {
                                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                        newPlayers = (int*)operator_new(4);
                                        if (newPlayers != 0) {
                                            int i;
                                            i = 0;
                                            while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                                newPlayers[i] = this->playersToAttack.value[i];
                                                i++;
                                            }
                                            goto active_resize_commit;
                                        }
                                    }
                                    goto active_object_to_attack;
                                }
                            } else {
                                if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                    int* generalPlayers;
                                    generalPlayers = (int*)operator_new(4);
                                    if (generalPlayers != 0) {
                                        int i;
                                        i = 0;
                                        while (i < this->playersToAttack.maximumSizeValue && i < 1) {
                                            generalPlayers[i] = this->playersToAttack.value[i];
                                            i++;
                                        }
                                        operator_delete(this->playersToAttack.value);
                                        this->playersToAttack.value = generalPlayers;
                                        this->playersToAttack.maximumSizeValue = 1;
                                    }
                                }
                                players = this->playersToAttack.value;
                                mem = this->md->informationAI.objectToAttackByGroup(
                                    *players, cur, &this->attackStateValue, param_1);
                                if (this->attackStateValue.active == 1) {
                                    this->nextActiveSoldierGroupToTaskValue = cur->id();
                                    return;
                                }
                                goto active_target_selected_common;
                            }
                            goto active_target_selected_common;
active_resize_commit:
                            operator_delete(this->playersToAttack.value);
                            this->playersToAttack.value = newPlayers;
                            this->playersToAttack.maximumSizeValue = 1;
active_object_to_attack:
                            players = this->playersToAttack.value;
                            mem = this->md->informationAI.objectToAttack(*players, 1, 1,
                                                                         cur->commander(),
                                                                         &attackAsAttack);
active_target_selected_common:
                            if (mem == 0) {
                                cur->setAction(1);
                                this->attackStateValue.active = 0;
                            } else {
                                mem->attackAttempts = mem->attackAttempts + 1;
attack_target_ready:
                                commanderObj = this->md->object(cur->commander());
                                if (commanderObj == 0) {
                                    cur->setAction(1);
                                    goto clear_attack_state;
                                } else {
                                    float point;
                                    XYZPoint targetPoint;
                                    targetPoint.x = mem->x;
                                    targetPoint.y = mem->y;
                                    targetPoint.z = mem->z;
                                    if (!((VObjCanMove*)commanderObj)->canPath(targetPoint,
                                            ((VObjWeaponRange*)commanderObj)->weaponRange(), mem->id,
                                            &point, 1, mem->owner, 0x1b)) {
                                        float exceptionPoint;
                                        float gatherX2;
                                        float aux2;
                                        if (cur->type() == 0x67) {
                                            goto active_exception_rejected;
                                        }
                                        if (!((VObjCanPath*)commanderObj)->canPathWithAdditionalPassability(
                                                targetPoint, ((VObjWeaponRange*)commanderObj)->weaponRange(),
                                                mem->id, &exceptionPoint, 1, 0x16, 1,
                                                mem->owner, 0x1b)) {
                                            cur->numberObjectsToDestroyValue = 0;
                                            cur->setAction(1);
                                            cur->playNumberValue = -1;
                                            this->attackStateValue.active = 0;
                                            goto ContinueLoop;
                                        }
                                        if (((VObjPathPoint*)commanderObj)->findFirstTerrainAlongExceptionPath(
                                                2, &gatherX2, &aux2) == 1) {
                                            pendingTaskCode = (int)mem;
                                            cur->task(this, this->md, 0x0e, 1, 0);
                                            cur->setAction(0x0d);
                                            cur->setTarget(mem->id);
                                            cur->setTargetType((int)mem->type);
                                            *(float*)&pendingTaskCode = (float)mem->x;
                                            *(float*)&pendingTaskArg1 = (float)mem->y;
                                            *(float*)&pendingTaskArg2 = (float)mem->z;
                                            goto exception_after_task;
                                        }
active_exception_rejected:
                                        cur->setAction(1);
                                        cur->playNumberValue = -1;
                                        goto clear_attack_state;
                                    } else {
                                        this->lastGroupAttackTime = this->md->player->world->world_time;
                                        if (this->sn[0x47] == 1) {
                                            this->lastAttackResponseTime = this->md->player->world->world_time;
                                        }
                                        cur->setTarget(mem->id);
                                        cur->setTargetType((int)mem->type);
                                        cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                        cur->setInUse(1);
                                        this->checkForCoopAttack((unsigned int)mem->owner, (unsigned int)mem->x, (unsigned int)mem->y);
                                    }
                                }
                            }
                        }
                    }
                }
                goto inactive_post_setup;
inactive_direct_gather:
                cur->setGatherLocation(*(float*)&pendingTaskArg2,
                                       directGatherY,
                                       directGatherZ);
                cur->setInUse(1);
inactive_post_setup:
                if (this->md->strategyAI.currentVictoryCondition() == 0x0b &&
                    mem != 0 && commanderObj != 0 && this->sn[0x67] == 1 &&
                    (cur->type() == 100 || cur->type() == 0x67)) {
                    XYZPoint targetTile;
                    Path* avoidancePath;
                    this->md->informationAI.addEnemyInfluences((unsigned int)mem->owner, mem->id);
                    this->md->informationAI.addPriorAttackInfluences((unsigned int)mem->owner, mem->id);
                    targetTile.x = (int)mem->x;
                    targetTile.y = (int)mem->y;
                    targetTile.z = 1;
                    avoidancePath = ((VObjFindAvoidancePath*)commanderObj)->findAvoidancePath(
                        &targetTile, ((VObjWeaponRange*)commanderObj)->weaponRange(), 1);
                    if (avoidancePath != 0) {
                        this->stuffAvoidancePath(cur, avoidancePath);
                    }
                }
                if (attackAsAttack != 0 || cur->action() != 2) {
                    TASK_GROUP(cur->action(), 1, 0);
                }
                TASK_GROUP(0x15, 1, 0);
            } else {
                t = cur->action();
                if (t == 0x0d) {
                    if (cur->waitCode() == 200) {
                        TacticalAIGroup* assist;
                        assist = 0;
                        if (cur->assistGroupID() == -1) {
                            RGE_Static_Object* commanderObj2;
                            XYPoint commanderPoint2;
                            commanderObj2 = this->md->object(cur->commander());
                            if (commanderObj2 == 0) {
                                this->attackStateValue.active = 0;
                            } else {
                                commanderPoint2.x = (int)commanderObj2->world_x;
                                commanderPoint2.y = (int)commanderObj2->world_y;
                                assist = this->bestGroup(0x6a, 1, -1, &commanderPoint2, -1);
                                if (assist == 0) {
                                    assist = this->bestGroup(0x6a, 0, -1, &commanderPoint2, -1);
                                }
                                if (assist != 0) {
                                    cur->setAssistGroupID(assist->id());
                                    cur->setAssistGroupType(assist->type());
                                    assist->setAction(0x0c);
                                    assist->setInUse(1);
                                    assist->setAssistGroupID(cur->id());
                                }
                            }
                        } else {
                            assist = this->group(cur->assistGroupID(), -1, -1, -1);
                        }
                        if (assist != 0) {
                            RGE_Static_Object* transportObj;
                            transportObj = this->md->object(assist->commander());
                            if (transportObj == 0 || transportObj->objects->number_of_objects < transportObj->master_obj->obj_max) {
                                int i;
                                int didTask;
                                didTask = 0;
                                i = 0;
                                while (i < cur->numberUnits()) {
                                    int unit_id;
                                    RGE_Static_Object* unitObj2;
                                    UnitAIModule* ai;
                                    unit_id = cur->unit(i);
                                    unitObj2 = this->md->object(unit_id);
                                    if (unitObj2 != 0) {
                                        ai = unitObj2->unitAI();
                                        if (ai != 0) {
                                            ai = unitObj2->unitAI();
                                            if (ai->currentAction() == -1) {
                                                didTask = 1;
                                                this->taskToEnter(unit_id, assist->commander());
                                            }
                                        }
                                    }
                                    i++;
                                }
                                if (!didTask) {
                                    cur->setAction(0x0f);
                                    this->attackStateValue.active = 0;
                                }
                            } else {
                                cur->setAction(0x0f);
                                this->attackStateValue.active = 0;
                            }
                        } else {
                            cur->setAssistGroupID(-1);
                            cur->setAssistGroupType(-1);
                            this->attackStateValue.active = 0;
                        }
                    } else {
                        this->attackStateValue.active = 0;
                    }
                } else if (cur->action() == 0x0f) {
                    TacticalAIGroup* assist;
                    RGE_Static_Object* transportObj;

                    assist = this->group(cur->assistGroupID(), -1, -1, -1);
                    if (assist != 0) {
                        transportObj = this->md->object(assist->commander());
                        if (transportObj != 0) {
                            int i;
                            int needTransporter;
                            unsigned char targetZone;

                            if (transportObj->objects->number_of_objects >= transportObj->master_obj->obj_max) {
                                cur->removeUnboardedUnits(this, this->md);
                            }
                            targetZone = 0xff;
                            needTransporter = 1;
                            i = 0;
                            while (i < cur->numberUnits()) {
                                int unit_id;
                                RGE_Static_Object* unitObj2;
                                UnitAIModule* ai;

                                unit_id = cur->unit(i);
                                unitObj2 = this->md->object(unit_id);
                                if (unitObj2 == 0) {
                                    logCommonHistory(this, (const char*)0x005883D4);
                                } else {
                                    ai = unitObj2->unitAI();
                                    if (ai == 0) {
                                        logCommonHistory(this, (const char*)0x005883B4);
                                    } else {
                                        if (cur->unit(i) == cur->commander()) {
                                            Waypoint* loc;
                                            XYPoint zp;
                                            loc = cur->targetLocation();
                                            zp.x = (int)loc->x;
                                            loc = cur->targetLocation();
                                            zp.y = (int)loc->y;
                                            targetZone = unitObj2->lookupZone(zp);
                                        }
                                        if (unitObj2->inside_obj != 0 && unitObj2->inside_obj->id == assist->commander()) {
                                            if (unitObj2->unitAI()->currentAction() != -1) {
                                                this->stopUnit(unitObj2->id, 100);
                                            }
                                        }
                                        if (unitObj2->inside_obj == 0 || unitObj2->inside_obj->id == assist->commander()) {
                                            if (unitObj2->inside_obj == 0) {
                                                needTransporter = 0;
                                                if (unitObj2->unitAI()->currentOrder() != 700 && unitObj2->unitAI()->currentOrder() != 0x2cd) {
                                                    this->taskToEnter(cur->unit(i), assist->commander());
                                                }
                                            }
                                        } else {
                                            cur->removeUnit(unitObj2->id, this->md);
                                        }
                                    }
                                }
                                i++;
                            }
                            if (needTransporter != 0) {
                                Waypoint* loc;
                                XYPoint targetPoint;
                                XYPoint staging;
                                loc = cur->targetLocation();
                                targetPoint.x = (int)loc->x;
                                loc = cur->targetLocation();
                                targetPoint.y = (int)loc->y;
                                if (this->md->informationAI.findStagingPoint(targetPoint, &staging, 1, 1, cur->target(), 0x0f, cur->commander()) == 0) {
                                    loc = cur->targetLocation();
                                    staging.x = (int)loc->x;
                                    loc = cur->targetLocation();
                                    staging.y = (int)loc->y;
                                }
                                this->taskTransporter(assist->commander(), (float)staging.x + 0.5f, (float)staging.y + 0.5f);
                                assist->setTargetLocation((float)staging.x, (float)staging.y, -1.0f);
                                assist->setAction(0x0c);
                                assist->setTargetType(targetZone);
                                cur->setAction(0x10);
                                cur->task(this, this->md, 0x16, 0, 1);
                                if (assist->numberUnits() > 1) {
                                    int j;
                                    j = 0;
                                    while (j < assist->numberUnits()) {
                                        if (assist->unit(j) != assist->commander()) {
                                            RGE_Static_Object* defenderObj;
                                            defenderObj = this->md->object(assist->unit(j));
                                            if (defenderObj != 0) {
                                                this->taskDefender(assist->unit(j), assist->commander(), defenderObj->master_obj->los * 0.5f, 99);
                                            }
                                        }
                                        j++;
                                    }
                                }
                            }
                        } else {
                            goto reset_action10;
                        }
                    } else {
                        goto reset_action10;
                    }
                } else if (cur->action() == 0x10) {
                    TacticalAIGroup* assist;
                    assist = this->group(cur->assistGroupID(), -1, -1, -1);
                    if (assist != 0) {
                        RGE_Static_Object* transportObj;
                        transportObj = this->md->object(assist->commander());
                        if (transportObj != 0 && transportObj->unitAI() != 0 && transportObj->owner->id == this->md->player->id) {
                            int i;
                            int allOutside;
                            int needReset;
                            allOutside = 1;
                            needReset = 1;
                            i = 0;
                            while (i < cur->numberUnits()) {
                                int unit_id;
                                RGE_Static_Object* unitObj2;
                                unit_id = cur->unit(i);
                                unitObj2 = this->md->object(unit_id);
                                if (unitObj2 != 0 && unitObj2->unitAI() != 0) {
                                    if (unitObj2->inside_obj == 0) {
                                        allOutside = 0;
                                        pendingTaskCode = (int)this->md->object(cur->target());
                                        if (cur->type() == 100) {
                                            RGE_Static_Object* targetObj;
                                            targetObj = (RGE_Static_Object*)pendingTaskCode;
                                            if (targetObj != 0) {
                                                UnitAIModule* attackAI;
                                                attackAI = unitObj2->unitAI();
                                                if (attackAI != 0) {
                                                    attackAI = unitObj2->unitAI();
                                                if (attackAI->currentTarget() != cur->target()) {
                                                    if (((VObjCanAttack*)unitObj2)->canAttack(
                                                            cur->target(), ((VObjWeaponRange*)unitObj2)->weaponRange()) == 1) {
                                                        this->taskAttacker(cur->unit(i),
                                                            cur->targetLocation()->x,
                                                            cur->targetLocation()->y,
                                                            cur->target(), -1, 0, 0, -1, 0);
                                                    }
                                            }
                                                }
                                            }
                                        } else {
                                            this->stopUnit(cur->unit(i), 100);
                                        }
                                    } else {
                                        needReset = 0;
                                    }
                                }
                                i++;
                            }
                            if (allOutside == 1) {
                                if (transportObj->actions == 0 || transportObj->actions->have_action() == 0 || transportObj->actions->get_action()->state == 2) {
                                    Waypoint* loc;
                                    float transportX;
                                    float transportY;
                                    loc = assist->targetLocation();
                                    transportY = loc->y + 0.5f;
                                    loc = assist->targetLocation();
                                    transportX = loc->x + 0.5f;
                                    this->taskTransporter(assist->commander(), transportX, transportY);
                                    assist->setAction(0x0c);
                                }
                            } else if (needReset != 0) {
                                TacticalAIGroup* resetAssist;
                                resetAssist = this->group(cur->assistGroupID(), -1, -1, -1);
                                if (resetAssist != 0) {
                                    resetAssist->setTarget(-1);
                                    resetAssist->setTargetType(-1);
                                    resetAssist->setAction(1);
                                    resetAssist->setInUse(0);
                                    RGE_Static_Object* relicObj;
                                    relicObj = this->md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
                                    if (relicObj != 0) {
                                        this->moveUnit(resetAssist->commander(), relicObj->world_x, relicObj->world_y, 50);
                                    }
                                }
                                if (cur->type() == 100) {
                                    RGE_Static_Object* commanderObjT;
                                    commanderObjT = this->md->object(cur->commander());
                                    if (commanderObjT == 0) {
                                        goto action10_attack_failure;
                                    } else {
                                        if (((VObjCanAttack*)commanderObjT)->canAttack(
                                                cur->target(), ((VObjWeaponRange*)commanderObjT)->weaponRange()) == 1) {
                                            this->lastGroupAttackTime = this->md->player->world->world_time;
                                            if (this->sn[0x47] == 1) {
                                                this->lastAttackResponseTime = this->md->player->world->world_time;
                                            }
                                            cur->setAction(2);
                                            cur->task(this, this->md, cur->action(), 1, 0);
                                            goto clear_attack_state;
                                        } else {
action10_attack_failure:
                                            cur->setInUse(1);
                                            cur->setAction(7);
                                            cur->task(this, this->md, 7, 0, 1);
                                            goto clear_attack_state;
                                        }
                                    }
                                } else {
                                    if (cur->type() != 0x65 && cur->type() != 0x6d) {
                                        goto loss_check;
                                    }
                                    Waypoint* tloc;
                                    float gatherX;
                                    float gatherY;
                                    float gatherZ;
                                    tloc = cur->targetLocation();
                                    gatherZ = tloc->z;
                                    tloc = cur->targetLocation();
                                    gatherY = tloc->y;
                                    tloc = cur->targetLocation();
                                    gatherX = tloc->x;
                                    cur->setGatherLocation(gatherX, gatherY, gatherZ);
                                    cur->setInUse(0);
                                    cur->setAction(1);
                                    TASK_GROUP(1, 1, 1);
                                }
                            }
                        } else {
                            goto reset_action10;
                        }
                    } else {
reset_action10:
                        cur->setTarget(-1);
                        cur->setTargetType(-1);
                        cur->setAction(1);
                        cur->setInUse(0);
                        this->attackStateValue.active = 0;
                    }
                } else {
                    if (cur->action() == 0x0c) goto action0c;
                    if (cur->action() == 0x13) goto action13;
                    if (cur->action() == 3) goto action3;
                    if (cur->action() == 7) {
                    RGE_Static_Object* commanderObj3;
                    RGE_Static_Object* targetObj;
                    int* players;

                    commanderObj3 = this->md->object(cur->commander());
                    if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                        int* newPlayers;
                        newPlayers = (int*)operator_new(4);
                        if (newPlayers != 0) {
                            int k;
                            k = 0;
                            while (k < this->playersToAttack.maximumSizeValue && k < 1) {
                                newPlayers[k] = this->playersToAttack.value[k];
                                k++;
                            }
                            operator_delete(this->playersToAttack.value);
                            this->playersToAttack.value = newPlayers;
                            this->playersToAttack.maximumSizeValue = 1;
                        }
                    }
                    players = this->playersToAttack.value;
                    mem = this->md->informationAI.objectToAttackByGroup(*players, cur, &this->attackStateValue, param_1);
                    if (this->attackStateValue.active == 1) {
                        this->nextActiveSoldierGroupToTaskValue = cur->id();
                        return;
                    }
                    targetObj = 0;
                    if (mem != 0) {
                        targetObj = this->md->object(mem->id);
                    }
                    if (commanderObj3 == 0 || mem == 0 || targetObj == 0) {
                        goto action7_timeout;
                    } else {
                        float pathOut;
                        XYZPoint targetPoint7;
                        targetPoint7.x = mem->x;
                        targetPoint7.y = mem->y;
                        targetPoint7.z = mem->z;
                        if (((VObjCanMove*)commanderObj3)->canPath(targetPoint7,
                                ((VObjWeaponRange*)commanderObj3)->weaponRange(), mem->id,
                                &pathOut, 1, mem->owner, 0x1b) == 1) {
                            cur->setAction(2);
                            cur->setTarget(mem->id);
                            cur->setTargetType((int)mem->type);
                            cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                            cur->setInUse(1);
                            TASK_GROUP(2, 0, 1);
                        } else {
                            char aux7[4];
                            float gather7;
                            if (((VObjCanPath*)commanderObj3)->canPathWithAdditionalPassability(
                                    targetPoint7, ((VObjWeaponRange*)commanderObj3)->weaponRange(),
                                    mem->id, &pathOut, 1, 0x16, 1,
                                    mem->owner, 0x1b) == 1 &&
                                ((VObjPathPoint*)commanderObj3)->findFirstTerrainAlongExceptionPath(
                                    2, &gather7, (float*)aux7) == 1) {
                                cur->task(this, this->md, 0x0e, 1, 0);
                                cur->setAction(0x0d);
                                cur->setTarget(mem->id);
                                cur->setTargetType((int)mem->type);
                                *(float*)&pendingTaskCode = (float)mem->x;
                                *(float*)&pendingTaskArg1 = (float)mem->y;
                                *(float*)&pendingTaskArg2 = (float)mem->z;
exception_after_task:
                                cur->setTargetLocation(*(float*)&pendingTaskCode,
                                                       *(float*)&pendingTaskArg1,
                                                       *(float*)&pendingTaskArg2);
                                cur->setInUse(1);
                                cur->setWaitCode(200);
                                cur->playNumberValue = -1;
                                goto clear_attack_state;
                            } else {
                                goto action7_timeout;
                            }
                        }
                    }
                    goto action7_done;
action7_timeout:
                    {
                        unsigned long idle;
                        idle = cur->consecutiveIdleUnitCount();
                        if ((this->md->player->world->world_time - idle) / 1000 >
                            (unsigned int)(this->sn[0x58] << 2)) {
                            cur->setAction(7);
                            cur->task(this, this->md, 7, 0, 1);
                            goto clear_attack_state;
                        }
                    }
action7_done:
                    ;
                } else if (cur->action() == 2) {
                    RGE_Static_Object* targetObj2;
                    int targetType;
                    int i;

                    if (cur->playNumberValue == -1) {
                    if (this->sn[0x5b] < 100) {
                        i = 0;
                        while (i < cur->numberUnits()) {
                            int unit_id;
                            RGE_Static_Object* unitObj2;
                            unit_id = cur->unit(i);
                            unitObj2 = this->md->object(unit_id);
                            if (unitObj2 != 0) {
                                int oldhp;
                                int curhp;
                                oldhp = cur->unitOriginalHitPoints(i);
                                curhp = (int)unitObj2->hp;
                                if (((oldhp - curhp) * 100) / cur->unitOriginalHitPoints(i) > this->sn[0x5b]) {
                                    Waypoint* retreat;
                                    float retreatX;
                                    float retreatY;
                                    retreat = cur->retreatLocation();
                                    retreatY = retreat->y;
                                    retreat = cur->retreatLocation();
                                    retreatX = retreat->x;
                                    this->moveUnit(cur->unit(i), retreatX, retreatY, 100);
                                    cur->removeUnit(cur->unit(i), this->md);
                                    if (cur->numberUnits() == 0) {
                                        break;
                                    }
                                } else {
                                    i++;
                                }
                            } else {
                                i++;
                            }
                        }
                    }

                    targetObj2 = this->md->object(cur->target());
                    if (targetObj2 == 0 || targetObj2->object_state > 2) {
                        ObjectMemory* replacement;
                        RGE_Static_Object* replacementCommander;
                        int* players2;
                        if (this->sn[0x31] == 2) {
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->numberObjectsToDestroyValue = 0;
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            TASK_GROUP(cur->action(), 1, 0);
                        } else {
                            replacementCommander = this->md->object(cur->commander());
                            if (replacementCommander == 0) {
                                this->attackStateValue.active = 0;
                                goto ContinueLoop;
                            }
                            if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                                int* newPlayers;
                                newPlayers = (int*)operator_new(4);
                                if (newPlayers != 0) {
                                    int k;
                                    k = 0;
                                    while (k < this->playersToAttack.maximumSizeValue && k < 1) {
                                        newPlayers[k] = this->playersToAttack.value[k];
                                        k++;
                                    }
                                    operator_delete(this->playersToAttack.value);
                                    this->playersToAttack.value = newPlayers;
                                    this->playersToAttack.maximumSizeValue = 1;
                                }
                            }
                            players2 = this->playersToAttack.value;
                            replacement = this->md->informationAI.objectToAttackByGroup(
                                *players2, cur, &this->attackStateValue, param_1);
                            if (this->attackStateValue.active == 1) {
                                this->nextActiveSoldierGroupToTaskValue = cur->id();
                                return;
                            }
                            if (replacement != 0) {
                                float path2;
                                XYZPoint replacementPoint;
                                replacementPoint.x = replacement->x;
                                replacementPoint.y = replacement->y;
                                replacementPoint.z = replacement->z;
                                if (((VObjCanMove*)replacementCommander)->canPath(replacementPoint,
                                        ((VObjWeaponRange*)replacementCommander)->weaponRange(),
                                        replacement->id, &path2, 1, replacement->owner, 0x1b) == 1) {
                                    cur->setTarget(replacement->id);
                                    cur->setTargetType((int)replacement->type);
                                    cur->setTargetLocation((float)replacement->x, (float)replacement->y, (float)replacement->z);
                                    cur->setInUse(1);
                                    TASK_GROUP(2, 0, 0);
                                }
                            }
                            targetType = cur->targetType();
                            cur->setInUse(0);
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            if (this->sn[0x31] == 0) {
                                cur->setGatherLocation(replacementCommander->world_x,
                                                       replacementCommander->world_y,
                                                       replacementCommander->world_z);
                            } else if (this->sn[0x31] == 3 &&
                                       targetType != 0x7e && targetType != 0x59) {
                                if (this->sn[0x87] == 1) {
                                    int cx;
                                    int cy;
                                    int radius;
                                    cx = (int)replacementCommander->world_x;
                                    cy = (int)replacementCommander->world_y;
                                    radius = this->sn[0x88];
                                    this->md->informationAI.blotExploredMap(cx - radius, cy - radius, cx + radius, cy + radius);
                                }
                                cur->setInUse(1);
                                cur->setAction(7);
                                TASK_GROUP(7, 0, 1);
                            }
                        }
                    } else if (cur->subType() != -1) {
                        unsigned long idle;
                        if (cur->subType() != 0 && cur->subType() == 4 &&
                            targetObj2->owner->id == this->md->player->id &&
                            this->md->isMoveable(targetObj2->id)) {
                            Waypoint* p1;
                            Waypoint* p2;
                            float mx;
                            float my;
                            float mz;
                            cur->addUnit(targetObj2->id, this->md);
                            p1 = this->md->strategyAI.targetPoint1();
                            p2 = this->md->strategyAI.targetPoint2();
                            mx = (p1->x + p2->x) * 0.5f;
                            my = (p1->y + p2->y) * 0.5f;
                            mz = (p1->z + p2->z) * 0.5f;
                            cur->setInUse(0);
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->numberObjectsToDestroyValue = 0;
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            cur->setGatherLocation(mx, my, mz);
                        }
                        idle = cur->consecutiveIdleUnitCount();
                        if ((this->md->player->world->world_time - idle) / 1000 >
                            (unsigned int)this->sn[0x4c]) {
                            cur->setInUse(0);
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            cur->numberObjectsToDestroyValue = 0;
                            this->attackStateValue.active = 0;
                            goto ContinueLoop;
                        }
                    } else {
                        if (((VPlayerIsEnemy*)this->md->player)->isEnemy(
                                targetObj2->owner->id) != 0) {
                            RGE_Static_Object* commanderObj8;
                            cur->setInUse(0);
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            cur->numberObjectsToDestroyValue = 0;
                            commanderObj8 = this->md->object(cur->commander());
                            if (commanderObj8 != 0) {
                                cur->setGatherLocation(commanderObj8->world_x,
                                                       commanderObj8->world_y,
                                                       commanderObj8->world_z);
                            }
                            goto clear_attack_state;
                        } else {
                            if (cur->allUnitsIdle(this->md, 0) != 1) {
                                TASK_GROUP(0x14, 0, 1);
                            } else {
                                RGE_Static_Object* commanderObj4;
                                commanderObj4 = this->md->object(cur->commander());
                                if (commanderObj4 == 0) {
                                    this->attackStateValue.active = 0;
                                    goto ContinueLoop;
                                } else if (((VObjCanAttack*)commanderObj4)->canAttack(
                                               cur->target(),
                                               ((VObjWeaponRange*)commanderObj4)->weaponRange()) == 1) {
                                    TASK_GROUP(0x14, 0, 1);
                                } else {
                                    cur->setGatherLocation(commanderObj4->world_x,
                                                           commanderObj4->world_y,
                                                           commanderObj4->world_z);
                                    cur->setInUse(0);
                                    cur->setAction(1);
                                    cur->setTarget(-1);
                                    cur->setTargetType(-1);
                                    cur->numberObjectsToDestroyValue = 0;
                                    cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                    goto clear_attack_state;
                                }
                            }
                        }
                    }
                    }
                    if (cur->action() == 2 && cur->playNumberValue != -1) {
                        RGE_Static_Object* commanderObj9;
                        commanderObj9 = this->md->object(cur->commander());
                        if (commanderObj9 != 0 && commanderObj9->unitAI() != 0 && commanderObj9->unitAI()->playStatus == 0) {
                            cur->playNumberValue = -1;
                            this->attackStateValue.active = 0;
                        }
                    }
                } else if (cur->action() == 4) {
                    if (cur->allUnitsIdle(this->md, 1) != 1 || cur->isGathered(this, this->md) != 0) {
                        RGE_Static_Object* targetObj4;
                        targetObj4 = this->md->object(cur->target());
                        if (targetObj4 != 0) {
                            ObjectMemory* higher;
                            higher = this->md->informationAI.higherPriorityObjectToDefend(cur->commander(), cur->targetType(), (int)targetObj4->master_obj->object_group);
                            if (higher == 0) {
                                goto loss_check;
                            }
                            ObjectMemory* oldTarget;
                            oldTarget = this->md->informationAI.objectMemory(cur->target());
                            if (oldTarget != 0) {
                                oldTarget->attackAttempts = 0;
                            }
                            cur->setAction(1);
                            cur->setInUse(0);
                        } else {
                            goto loss_check;
                        }
                    } else {
                        TASK_GROUP(9, 1, 0);
                    }
                    } else {
                        goto loss_check;
                    }
                    goto active_dispatch_done;
action0c:
                    this->attackStateValue.active = 0;
                    goto active_dispatch_done;
action13:
                    {
                    if (cur->isGathered(this, this->md) == 0) {
                        unsigned long idle;
                        idle = cur->consecutiveIdleUnitCount();
                        if (5 < (this->md->player->world->world_time - idle) / 1000 &&
                            cur->allUnitsIdle(this->md, 1) == 1) {
                            cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
                            TASK_GROUP(9, 1, 0);
                        }
                    }
                    }
                    goto active_dispatch_done;
action3:
                    {
                    unsigned long idle;
                    idle = cur->consecutiveIdleUnitCount();
                    if ((this->md->player->world->world_time - idle) / 1000 >
                        (unsigned int)this->sn[0x4c]) {
                        cur->setInUse(0);
                        cur->setAction(1);
                        cur->setTarget(-1);
                        cur->numberObjectsToDestroyValue = 0;
                        cur->setTargetType(-1);
                        cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        this->attackStateValue.active = 0;
                    } else {
                        if (cur->isGathered(this, this->md) == 0) {
                            goto active_dispatch_done;
                        }
                        cur->setAction(1);
                        cur->setInUse(0);
                        if (cur->type() == 0x65 || cur->type() == 0x68) {
                            ObjectMemory* oldTarget;
                            oldTarget = this->md->informationAI.objectMemory(cur->target());
                            if (oldTarget != 0) {
                                oldTarget->attackAttempts = 0;
                            }
                        }
                        if (this->md->buildAI.buildListLength() == 0 &&
                            ((cur->type() == 100 && this->numberGroups(100, -1) > 1) || cur->type() != 100)) {
                            if (cur->type() == 0x66) {
                                this->sn[0x2a] = this->sn[0x2a] - 1;
                            } else if (cur->type() == 0x65) {
                                this->sn[0x26] = this->sn[0x26] - 1;
                            } else if (cur->type() == 100) {
                                this->sn[0x24] = this->sn[0x24] - 1;
                            }
                            cur->removeUnits(this->md);
                            cur->setAction(0);
                            this->attackStateValue.active = 0;
                        } else {
                            this->attackStateValue.active = 0;
                        }
                    }
                    }
                    goto active_dispatch_done;
loss_check:
                    {
                    if (cur->action() != 3 && cur->action() != 0x0d) {
                        int hpLoss;
                        int currentUnits;
                        int unitLoss;

                        hpLoss = ((cur->originalHitPoints() - cur->currentHitPoints(this->md)) * 100) /
                                 cur->originalHitPoints();
                        currentUnits = cur->numberUnits();
                        unitLoss = ((cur->originalUnitNumber() - currentUnits) * 100) /
                                   cur->originalUnitNumber();
                        if (hpLoss > this->sn[0x1e] || unitLoss > this->sn[0x1f]) {
                            cur->setAction(3);
                            cur->task(this, this->md, cur->action(), 1, 0);
                            goto clear_attack_state;
                        }
                    }
#if 0
                    int currentHP;
                    int originalHP;
                    int currentUnits;
                    int originalUnits;
                    int i;
                    int idleUnits;
                    currentHP = cur->currentHitPoints(this->md);
                    originalHP = cur->originalHitPoints();
                    currentUnits = cur->numberUnits();
                    originalUnits = cur->originalUnitNumber();
                    idleUnits = 1;
                    i = 0;
                    while (i < cur->numberUnits()) {
                        int unit_id;
                        RGE_Static_Object* unitObj2;
                        UnitAIModule* ai;
                        unit_id = cur->unit(i);
                        unitObj2 = this->md->object(unit_id);
                        if (unitObj2 == 0) {
                            idleUnits = 0;
                        } else {
                            ai = unitObj2->unitAI();
                            if (ai == 0) {
                                idleUnits = 0;
                            } else {
                                if (ai->currentAction() != -1) {
                                    idleUnits = 0;
                                }
                                if (ai->currentOrder() == 700 || ai->currentOrder() == 0x2cd) {
                                    idleUnits = 0;
                                }
                                if (unitObj2->inside_obj != 0) {
                                    idleUnits = 0;
                                }
                            }
                        }
                        i++;
                    }
                    if (idleUnits != 0 && cur->allUnitsIdle(this->md, 1) == 1) {
                        unsigned long idle;
                        idle = cur->consecutiveIdleUnitCount();
                        if (5 < (this->md->player->world->world_time - idle) / 1000) {
                            cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
                            TASK_GROUP(9, 1, 0);
                        }
                    }
                    if (originalHP != 0 && originalUnits != 0 &&
                        (this->sn[0x1e] < ((originalHP - currentHP) * 100) / originalHP ||
                         this->sn[0x1f] < ((originalUnits - currentUnits) * 100) / originalUnits)) {
                        cur->setAction(3);
                        TASK_GROUP(3, 1, 0);
                    }
                    if (cur->type() == 0x65 || cur->type() == 0x68 || cur->type() == 0x6d) {
                        ObjectMemory* mem2;
                        mem2 = this->md->informationAI.objectMemory(cur->target());
                        if (mem2 != 0 && cur->isGathered(this, this->md) != 0) {
                            mem2->attackAttempts = 0;
                            cur->setAction(1);
                            cur->setInUse(0);
                        }
                    }
                    if (cur->target() != -1) {
                        RGE_Static_Object* targetObj3;
                        targetObj3 = this->md->object(cur->target());
                        if (targetObj3 == 0 || targetObj3->object_state >= 3) {
                            RESET_GROUP(cur);
                        } else if (cur->targetType() != -1) {
                            ObjectMemory* higher;
                            higher = this->md->informationAI.higherPriorityObjectToDefend(cur->commander(), cur->targetType(), (int)targetObj3->master_obj->object_group);
                            if (higher != 0) {
                                ObjectMemory* oldTarget;
                                oldTarget = this->md->informationAI.objectMemory(cur->target());
                                if (oldTarget != 0) {
                                    oldTarget->attackAttempts = 0;
                                }
                                cur->setAction(1);
                                cur->setInUse(0);
                            }
                        }
                        if (cur->inUse() != 0) {
                            int j;
                            j = 0;
                            while (j < cur->numberUnits()) {
                                int unit_id2;
                                RGE_Static_Object* unitObj3;
                                UnitAIModule* ai2;
                                unit_id2 = cur->unit(j);
                                unitObj3 = this->md->object(unit_id2);
                                if (unitObj3 != 0) {
                                    ai2 = unitObj3->unitAI();
                                    if (ai2 != 0) {
                                        if (ai2->currentTarget() != cur->target() || ai2->currentAction() == -1) {
                                            Waypoint* loc;
                                            float attackX;
                                            float attackY;
                                            loc = cur->targetLocation();
                                            attackY = loc->y;
                                            loc = cur->targetLocation();
                                            attackX = loc->x;
                                            this->taskAttacker(unit_id2, attackX, attackY, cur->target(), cur->subType(), 0, 0, -1, 0);
                                        }
                                    } else {
                                        this->stopUnit(unit_id2, 100);
                                    }
                                }
                                j++;
                            }
                        }
                    }
                    if (cur->numberUnits() == 0) {
                        cur->setTarget(-1);
                        cur->numberObjectsToDestroyValue = 0;
                        cur->setTargetType(-1);
                        cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        cur->setInUse(0);
                        cur->setAction(1);
                        cur->setAssistGroupID(-1);
                        cur->setAssistGroupType(-1);
                        if (cur->waitCode() != 0) {
                            cur->setWaitCode(0);
                        }
                        if (cur->assistGroupID() != -1) {
                            cur->setAssistGroupID(-1);
                        }
                        if (cur->assistGroupID() == -1) {
                            cur->setAssistGroupType(-1);
                        }
                        if (cur->targetType() != -1) {
                            cur->setTargetType(-1);
                        }
                    }
                    this->attackStateValue.active = 0;
#endif
                    }
active_dispatch_done:
                    ;
                }
            }

            goto ContinueLoop;
clear_attack_state:
            this->attackStateValue.active = 0;
            goto ContinueLoop;
task_group:
            cur->task(this, this->md, pendingTaskCode, pendingTaskArg1, pendingTaskArg2);
            this->attackStateValue.active = 0;
ContinueLoop:
            if (this->attackStateValue.active != 0) {
                return;
            }
            cur = cur->next;
            if (cur == &this->groups || !cur) {
                this->nextActiveSoldierGroupToTaskValue = -1;
            } else {
                this->nextActiveSoldierGroupToTaskValue = cur->id();
            }
            if (debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c, 0x14fe) - param_1 >= param_2) {
                return;
            }
        } while (cur != &this->groups);
    }
    this->nextActiveSoldierGroupToTaskValue = -1;
#undef RESET_GROUP
#undef TASK_GROUP
}
