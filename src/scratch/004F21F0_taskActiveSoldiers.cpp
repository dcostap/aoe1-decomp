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
struct XYZPoint { float x; float y; float z; };
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
void stuffAvoidancePath(TribeTacticalAIModule*, TacticalAIGroup*, Path*);
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
    char gap_49[0x13B];
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
    void task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int);
    void setConsecutiveIdleUnitCount(ulong);
    void removeUnboardedUnits(TribeTacticalAIModule*, TribeMainDecisionAIModule*);
    void removeUnit(int unit_id, TribeMainDecisionAIModule*);
    void removeUnits(TribeMainDecisionAIModule*);
    void addUnit(int unit_id, TribeMainDecisionAIModule*);
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
    void checkForCoopAttack(unsigned int owner, unsigned int x, unsigned int y);
    TacticalAIGroup* bestGroup(int type, int in_use, int subtype, XYPoint* near_point, int action);
    TacticalAIGroup* group(int id, int type, int subtype, int action);
    void taskToEnter(int unit_id, int transport_id);
    void taskTransporter(int transport_id, float x, float y);
    void taskDefender(int unit_id, int target_id, float distance, int code);
    void taskAttacker(int unit_id, float x, float y, int target, int subtype, Waypoint* waypoint, int a, int b, int c);
    void moveUnit(int unit_id, float x, float y, int code);
    void stopUnit(int unit_id, int code);
    int numberGroups(int type, int action);
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
    TacticalAIGroup* cur;
    TacticalAIGroup* sentinel;
    int t;
    char scratch_frame[0x34];

    cur = this->groups.next;
    if (this->nextActiveSoldierGroupToTaskValue != -1) {
        sentinel = &this->groups;
        while (cur != sentinel) {
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

    sentinel = &this->groups;
    if (cur != sentinel) {
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
                int allOutsideTransport;
                ObjectMemory* mem;
                RGE_Static_Object* commanderObj;

                mem = 0;
                commanderObj = 0;
                allOutsideTransport = 1;
                t = cur->type();
                if (t != 100 && cur->type() != 0x67) {
                    t = cur->type();
                    if (t == 0x65 || cur->type() == 0x68) {
                        int commander;
                        int distance;
                        float pathDistance;
                        float gatherX;
                        unsigned char x;
                        unsigned char y;
                        unsigned char z;
                        XYPoint commanderPoint;

                        commander = cur->commander();
                        mem = this->md->informationAI.objectToDefend(commander);
                        if (mem == 0) {
                            cur->setAction(1);
                        } else {
                            commander = cur->commander();
                            commanderObj = this->md->object(commander);
                            if (commanderObj == 0) {
                                cur->setAction(1);
                            } else {
                                if (mem->type == 0x6d) {
                                    distance = this->sn[0x16];
                                } else {
                                    distance = this->sn[0x39];
                                }
                                x = mem->x;
                                y = mem->y;
                                z = mem->z;
                                pathDistance = commanderObj->pathDistance(mem->id, &commanderPoint, 1, -1, -1);
                                if (commanderObj->canMoveTo(x, y, z, pathDistance)) {
                                    mem->attackAttempts = 1;
                                    cur->setTarget(mem->id);
                                    cur->setTargetType((int)mem->type);
                                    cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                    cur->setGatherLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                    cur->setInUse(1);
                                } else {
                                    if (commanderObj->canPathTo(x, y, z, (float)distance, mem->id, &commanderPoint, 1, 0x16, 1, -1, -1) &&
                                        commanderObj->pathPoint(2, &gatherX, scratch_frame) == 1) {
                                        mem->attackAttempts = 1;
                                        cur->task(this, this->md, 0x0e, 1, 0);
                                        cur->setAction(0x0d);
                                        cur->setTarget(mem->id);
                                        cur->setTargetType((int)mem->type);
                                        cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                        cur->setInUse(1);
                                        cur->setWaitCode(200);
                                    } else {
                                        cur->setAction(1);
                                    }
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
                                this->attackStateValue.active = 0;
                            } else {
                                relic = md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
                                if (relic == 0) {
                                    cur->setAction(1);
                                    this->attackStateValue.active = 0;
                                } else {
                                    commanderObj = md->object(cur->commander());
                                    if (commanderObj == 0) {
                                        cur->setAction(1);
                                        this->attackStateValue.active = 0;
                                    } else {
                                        float dist;
                                        float pathDistance_6d;
                                        dist = commanderObj->pathDistance(relic->id, &pathDistance_6d, 1, -1, -1);
                                        if (commanderObj->canMoveTo((int)relic->world_x, (int)relic->world_y, (int)relic->world_z, dist)) {
                                            cur->setTarget(relic->id);
                                            cur->setTargetType(0x6d);
                                            cur->setTargetLocation(relic->world_x, relic->world_y, relic->world_z);
                                            cur->setGatherLocation(relic->world_x, relic->world_y, relic->world_z);
                                            cur->setInUse(1);
                                        } else {
                                            cur->setAction(1);
                                            this->attackStateValue.active = 0;
                                        }
                                    }
                                }
                            }
                        } else {
                            int currentVictory;
                            int* players;
                            currentVictory = this->md->strategyAI.currentVictoryCondition();
                            if (currentVictory == 0) {
                                int capture;
                                capture = this->itemToCapture();
                                mem = this->md->informationAI.objectMemory(capture);
                                if (mem == 0) {
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
                                    mem = this->md->informationAI.objectToAttack(*players, 1, 1, cur->commander(), &allOutsideTransport);
                                }
                            } else if (currentVictory == 4) {
                                int bring;
                                bring = this->itemToBringToArea();
                                mem = this->md->informationAI.objectMemory(bring);
                                if (mem == 0) {
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
                                    mem = this->md->informationAI.objectToAttack(*players, 1, 1, cur->commander(), &allOutsideTransport);
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
                            }
                            if (mem == 0) {
                                cur->setAction(1);
                                this->attackStateValue.active = 0;
                            } else {
                                mem->attackAttempts = mem->attackAttempts + 1;
                                commanderObj = this->md->object(cur->commander());
                                if (commanderObj == 0) {
                                    cur->setAction(1);
                                    this->attackStateValue.active = 0;
                                } else {
                                    float dist;
                                    XYPoint pathOut;
                                    dist = commanderObj->pathDistance2(mem->id, &pathOut, 1, mem->owner, 0x1b, 0, 0);
                                    if (commanderObj->canMoveTo(mem->x, mem->y, mem->z, dist)) {
                                        this->lastGroupAttackTime = this->md->player->world->world_time;
                                        cur->setTarget(mem->id);
                                        cur->setTargetType((int)mem->type);
                                        cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                        cur->setInUse(1);
                                        this->checkForCoopAttack((unsigned int)mem->owner, (unsigned int)mem->x, (unsigned int)mem->y);
                                    } else {
                                        cur->setAction(1);
                                        this->attackStateValue.active = 0;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    int attackEnabled;
                    unsigned long lastAttackTime;
                    unsigned long elapsed;

                    attackEnabled = this->attackEnabledValue;
                    if (attackEnabled == 0) {
                        this->attackStateValue.active = 0;
                    } else {
                        lastAttackTime = this->lastGroupAttackTime;
                        elapsed = (this->md->player->world->world_time - lastAttackTime) / 1000;
                        if (lastAttackTime != 0 && this->sn[0x2f] == 2 && elapsed != 0 && this->attackLimiterTime(0x2e) > elapsed) {
                            this->attackStateValue.active = 0;
                        } else if (lastAttackTime != 0 && this->sn[0x2f] == 1 && this->attackLimiterTime(0x2e) > elapsed) {
                            this->attackStateValue.active = 0;
                        } else {
                            int* players;
                            players = this->playersToAttack.value;
                            mem = 0;
                            if (players != 0) {
                                mem = this->md->informationAI.objectToAttackByGroup(*players, cur, &this->attackStateValue, param_1);
                            }
                            if (this->attackStateValue.active == 1) {
                                this->nextActiveSoldierGroupToTaskValue = cur->id();
                                return;
                            }
                            if (mem == 0) {
                                cur->setAction(1);
                                this->attackStateValue.active = 0;
                            } else {
                                mem->attackAttempts = mem->attackAttempts + 1;
                                commanderObj = this->md->object(cur->commander());
                                if (commanderObj == 0) {
                                    cur->setAction(1);
                                } else {
                                    float dist;
                                    XYPoint point;
                                    dist = commanderObj->pathDistance2(mem->id, &point, 1, mem->owner, 0x1b, 0, 0);
                                    if (commanderObj->canMoveTo(mem->x, mem->y, mem->z, dist)) {
                                        this->lastGroupAttackTime = this->md->player->world->world_time;
                                        if (this->sn[0x47] == 1) {
                                            this->lastAttackResponseTime = this->md->player->world->world_time;
                                        }
                                        cur->setTarget(mem->id);
                                        cur->setTargetType((int)mem->type);
                                        cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                        cur->setInUse(1);
                                        this->checkForCoopAttack((unsigned int)mem->owner, (unsigned int)mem->x, (unsigned int)mem->y);
                                    } else {
                                        float gatherX2;
                                        char aux2[4];
                                        if (commanderObj->canPathTo(mem->x, mem->y, mem->z, dist, mem->id, &point, 1, 0x16, 1, mem->owner, 0x1b) &&
                                            commanderObj->pathPoint(2, &gatherX2, aux2) == 1) {
                                            cur->task(this, this->md, 0x0e, 1, 0);
                                            cur->setAction(0x0d);
                                            cur->setTarget(mem->id);
                                            cur->setTargetType((int)mem->type);
                                            cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                            cur->setInUse(1);
                                            cur->setWaitCode(200);
                                            cur->playNumberValue = -1;
                                        } else {
                                            cur->setAction(1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (mem != 0 && commanderObj != 0 && this->sn[0x67] == 1 && (cur->type() == 100 || cur->type() == 0x67)) {
                    XYPoint targetTile;
                    Path* avoidancePath;
                    this->md->informationAI.addEnemyInfluences((unsigned int)mem->owner, mem->id);
                    this->md->informationAI.addPriorAttackInfluences((unsigned int)mem->owner, mem->id);
                    targetTile.x = (int)mem->x;
                    targetTile.y = (int)mem->y;
                    avoidancePath = (Path*)(int)commanderObj->pathDistance(mem->id, &targetTile, 1, -1, -1);
                    if (avoidancePath != 0) {
                        stuffAvoidancePath(this, cur, avoidancePath);
                    }
                }
                if (allOutsideTransport == 0 && cur->action() == 2) {
                    cur->task(this, this->md, 0x15, 1, 0);
                }
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
                                        if (ai != 0 && ai->currentAction() == -1) {
                                            didTask = 1;
                                            this->taskToEnter(unit_id, assist->commander());
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
                } else if (t == 0x0f) {
                    TacticalAIGroup* assist;
                    RGE_Static_Object* transportObj;

                    assist = this->group(cur->assistGroupID(), -1, -1, -1);
                    if (assist != 0) {
                        transportObj = this->md->object(assist->commander());
                        if (transportObj != 0) {
                            int i;
                            int allInside;
                            int needTransporter;
                            unsigned char targetZone;

                            if (transportObj->objects->number_of_objects >= transportObj->master_obj->obj_max) {
                                cur->removeUnboardedUnits(this, this->md);
                            }
                            targetZone = 0xff;
                            needTransporter = 1;
                            allInside = 0;
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
                                        if (unit_id == cur->commander()) {
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
                                            allInside = allInside + 1;
                                        } else if (unitObj2->inside_obj == 0) {
                                            needTransporter = 0;
                                            if (unitObj2->unitAI()->currentOrder() != 700 && unitObj2->unitAI()->currentOrder() != 0x2cd) {
                                                this->taskToEnter(unit_id, assist->commander());
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
                                        int defender_id;
                                        defender_id = assist->unit(j);
                                        if (defender_id != assist->commander()) {
                                            RGE_Static_Object* defenderObj;
                                            defenderObj = this->md->object(defender_id);
                                            if (defenderObj != 0) {
                                                this->taskDefender(defender_id, assist->commander(), defenderObj->master_obj->los * 0.5f, 99);
                                            }
                                        }
                                        j++;
                                    }
                                }
                            }
                        } else {
                            cur->setTarget(-1);
                            cur->setTargetType(-1);
                            cur->setAction(1);
                            cur->setInUse(0);
                            this->attackStateValue.active = 0;
                        }
                    } else {
                        cur->setTarget(-1);
                        cur->setTargetType(-1);
                        cur->setAction(1);
                        cur->setInUse(0);
                        this->attackStateValue.active = 0;
                    }
                } else if (t == 0x10) {
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
                                        if (cur->type() == 100) {
                                            RGE_Static_Object* targetObj;
                                            targetObj = this->md->object(cur->target());
                                            if (targetObj != 0 && unitObj2->unitAI()->currentTarget() != cur->target()) {
                                                Waypoint* loc;
                                                loc = cur->targetLocation();
                                                this->taskAttacker(unit_id, loc->x, loc->y, cur->target(), -1, 0, 0, -1, 0);
                                            }
                                        } else {
                                            this->stopUnit(unit_id, 100);
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
                                    loc = assist->targetLocation();
                                    this->taskTransporter(assist->commander(), loc->x + 0.5f, loc->y + 0.5f);
                                    assist->setAction(0x0c);
                                }
                            } else if (needReset != 0) {
                                assist->setTarget(-1);
                                assist->setTargetType(-1);
                                assist->setAction(1);
                                assist->setInUse(0);
                                if (cur->type() != 100) {
                                    RGE_Static_Object* relicObj;
                                    relicObj = this->md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
                                    if (relicObj != 0) {
                                        this->moveUnit(assist->commander(), relicObj->world_x, relicObj->world_y, 50);
                                    }
                                    Waypoint* loc;
                                    loc = cur->targetLocation();
                                    cur->setGatherLocation(loc->x, loc->y, loc->z);
                                    cur->setInUse(0);
                                    cur->setAction(1);
                                    if (cur->type() == 0x65 || cur->type() == 0x6d) {
                                        Waypoint* tloc;
                                        tloc = cur->targetLocation();
                                        cur->setGatherLocation(tloc->x, tloc->y, tloc->z);
                                        cur->setTarget(-1);
                                        cur->numberObjectsToDestroyValue = 0;
                                        cur->setTargetType(-1);
                                        cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                    }
                                    cur->task(this, this->md, 1, 1, 1);
                                } else {
                                    RGE_Static_Object* commanderObjT;
                                    commanderObjT = this->md->object(cur->commander());
                                    if (commanderObjT == 0) {
                                        cur->setInUse(1);
                                        cur->setAction(7);
                                        cur->task(this, this->md, 7, 0, 1);
                                    } else {
                                        float distT;
                                        XYPoint ptT;
                                        distT = commanderObjT->pathDistance(cur->target(), &ptT, 1, -1, -1);
                                        if (commanderObjT->canPathTo((int)commanderObjT->world_x, (int)commanderObjT->world_y, (int)commanderObjT->world_z, distT, cur->target(), 0, 1, 0x16, 1, -1, -1) == 1) {
                                            this->lastGroupAttackTime = this->md->player->world->world_time;
                                            cur->setAction(2);
                                            cur->task(this, this->md, 2, 0, 1);
                                        } else {
                                            cur->setInUse(1);
                                            cur->setAction(7);
                                            cur->task(this, this->md, 7, 0, 1);
                                        }
                                    }
                                }
                            }
                        } else {
                            cur->setTarget(-1);
                            cur->setTargetType(-1);
                            cur->setAction(1);
                            cur->setInUse(0);
                            this->attackStateValue.active = 0;
                        }
                    } else {
                        cur->setTarget(-1);
                        cur->setTargetType(-1);
                        cur->setAction(1);
                        cur->setInUse(0);
                        this->attackStateValue.active = 0;
                    }
                } else if (t == 7) {
                    RGE_Static_Object* commanderObj3;
                    ObjectMemory* mem;
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
                        unsigned long idle;
                        idle = cur->consecutiveIdleUnitCount();
                        if ((unsigned int)(this->sn[0x58] << 2) < (this->md->player->world->world_time - idle) / 1000) {
                            cur->setAction(7);
                            cur->task(this, this->md, 7, 0, 1);
                        }
                    } else {
                        float dist;
                        XYPoint pathOut;
                        dist = commanderObj3->pathDistance2(mem->id, &pathOut, 1, mem->owner, 0x1b, 0, 0);
                        if (commanderObj3->canMoveTo(mem->x, mem->y, mem->z, dist) == 1) {
                            cur->setAction(2);
                            cur->setTarget(mem->id);
                            cur->setTargetType((int)mem->type);
                            cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                            cur->setInUse(1);
                            cur->task(this, this->md, 2, 0, 1);
                        } else {
                            char aux7[4];
                            float gather7;
                            if (commanderObj3->canPathTo(mem->x, mem->y, mem->z, dist, mem->id, &pathOut, 1, 0x16, 1, mem->owner, 0x1b) == 1 &&
                                commanderObj3->pathPoint(2, &gather7, aux7) == 1) {
                                cur->task(this, this->md, 0x0e, 1, 0);
                                cur->setAction(0x0d);
                                cur->setTarget(mem->id);
                                cur->setTargetType((int)mem->type);
                                cur->setTargetLocation((float)mem->x, (float)mem->y, (float)mem->z);
                                cur->setInUse(1);
                                cur->setWaitCode(200);
                                cur->playNumberValue = -1;
                            } else {
                                unsigned long idle2;
                                idle2 = cur->consecutiveIdleUnitCount();
                                if ((unsigned int)(this->sn[0x58] << 2) < (this->md->player->world->world_time - idle2) / 1000) {
                                    cur->setAction(7);
                                    cur->task(this, this->md, 7, 0, 1);
                                } else {
                                    cur->setAction(1);
                                }
                            }
                        }
                    }
                } else if (t == 2) {
                    RGE_Static_Object* targetObj2;
                    int targetType;
                    int i;

                    if (cur->playNumberValue == -1 && this->sn[0x5b] < 100) {
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
                                    retreat = cur->retreatLocation();
                                    this->moveUnit(unit_id, retreat->x, retreat->y, 100);
                                    cur->removeUnit(unit_id, this->md);
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
                    if (targetObj2 != 0 && targetObj2->object_state < 3) {
                        if (cur->subType() == -1) {
                            if (this->md->isEnemy(targetObj2->owner->id) == 0) {
                                if (cur->allUnitsIdle(this->md, 0) != 1) {
                                    cur->task(this, this->md, 0x14, 0, 1);
                                } else {
                                    RGE_Static_Object* commanderObj4;
                                    commanderObj4 = this->md->object(cur->commander());
                                    if (commanderObj4 == 0) {
                                        this->attackStateValue.active = 0;
                                    } else {
                                        float dist;
                                        dist = commanderObj4->pathDistance(cur->target(), &targetType, 1, -1, -1);
                                        if (commanderObj4->canPathTo((int)targetObj2->world_x, (int)targetObj2->world_y, (int)targetObj2->world_z, dist, cur->target(), 0, 1, 0x16, 1, -1, -1) == 1) {
                                            cur->task(this, this->md, 0x14, 0, 1);
                                        } else {
                                            cur->setGatherLocation(commanderObj4->world_x, commanderObj4->world_y, commanderObj4->world_z);
                                            cur->setInUse(0);
                                            cur->setAction(1);
                                            cur->setTarget(-1);
                                            cur->setTargetType(-1);
                                            cur->numberObjectsToDestroyValue = 0;
                                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                        }
                                    }
                                }
                            } else {
                                RGE_Static_Object* commanderObj8;
                                cur->setInUse(0);
                                cur->setAction(1);
                                cur->setTarget(-1);
                                cur->setTargetType(-1);
                                cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                cur->numberObjectsToDestroyValue = 0;
                                commanderObj8 = this->md->object(cur->commander());
                                if (commanderObj8 != 0) {
                                    cur->setGatherLocation(commanderObj8->world_x, commanderObj8->world_y, commanderObj8->world_z);
                                }
                            }
                        } else {
                            unsigned long idle;
                            if (cur->subType() == 4 && targetObj2->owner != 0 && targetObj2->owner->id == this->md->player->id && this->md->isMoveable(targetObj2->id)) {
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
                            if ((unsigned int)this->sn[0x4c] < (this->md->player->world->world_time - idle) / 1000) {
                                cur->setInUse(0);
                                cur->setAction(1);
                                cur->setTarget(-1);
                                cur->setTargetType(-1);
                                cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                                cur->numberObjectsToDestroyValue = 0;
                                this->attackStateValue.active = 0;
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
                    } else {
                        ObjectMemory* replacement;
                        int* players2;
                        if (this->sn[0x31] == 2) {
                            cur->setAction(1);
                            cur->setTarget(-1);
                            cur->numberObjectsToDestroyValue = 0;
                            cur->setTargetType(-1);
                            cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                            cur->task(this, this->md, cur->action(), 1, 0);
                        } else {
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
                        replacement = this->md->informationAI.objectToAttackByGroup(*players2, cur, &this->attackStateValue, param_1);
                        if (this->attackStateValue.active == 1) {
                            this->nextActiveSoldierGroupToTaskValue = cur->id();
                            return;
                        }
                        if (replacement != 0) {
                            RGE_Static_Object* commanderObj6;
                            commanderObj6 = this->md->object(cur->commander());
                            if (commanderObj6 != 0) {
                                float dist2;
                                XYPoint path2;
                                dist2 = commanderObj6->pathDistance2(replacement->id, &path2, 1, replacement->owner, 0x1b, 0, 0);
                                if (commanderObj6->canMoveTo(replacement->x, replacement->y, replacement->z, dist2) == 1) {
                                    cur->setTarget(replacement->id);
                                    cur->setTargetType((int)replacement->type);
                                    cur->setTargetLocation((float)replacement->x, (float)replacement->y, (float)replacement->z);
                                    cur->setInUse(1);
                                    cur->task(this, this->md, 2, 0, 0);
                                }
                            }
                        }
                        targetType = cur->targetType();
                        cur->setInUse(0);
                        cur->setAction(1);
                        cur->setTarget(-1);
                        cur->setTargetType(-1);
                        cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        if (this->sn[0x31] == 0) {
                            RGE_Static_Object* commanderObj5;
                            commanderObj5 = this->md->object(cur->commander());
                            if (commanderObj5 != 0) {
                                cur->setGatherLocation(commanderObj5->world_x, commanderObj5->world_y, commanderObj5->world_z);
                            }
                        } else if (this->sn[0x31] == 3 && targetType != 0x7e && targetType != 0x59) {
                            if (this->sn[0x87] == 1) {
                                RGE_Static_Object* commanderObj7;
                                commanderObj7 = this->md->object(cur->commander());
                                if (commanderObj7 != 0) {
                                    int cx;
                                    int cy;
                                    int radius;
                                    cx = (int)commanderObj7->world_x;
                                    cy = (int)commanderObj7->world_y;
                                    radius = this->sn[0x88];
                                    this->md->informationAI.blotExploredMap(cx - radius, cy - radius, cx + radius, cy + radius);
                                }
                            }
                            cur->setInUse(1);
                            cur->setAction(7);
                            cur->task(this, this->md, 7, 0, 1);
                        }
                        }
                    }
                } else if (t == 4) {
                    if (cur->allUnitsIdle(this->md, 1) != 1 || cur->isGathered(this, this->md) != 0) {
                        RGE_Static_Object* targetObj4;
                        targetObj4 = this->md->object(cur->target());
                        if (targetObj4 != 0) {
                            ObjectMemory* higher;
                            higher = this->md->informationAI.higherPriorityObjectToDefend(cur->commander(), cur->targetType(), (int)targetObj4->master_obj->object_group);
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
                    } else {
                        cur->task(this, this->md, 9, 1, 0);
                    }
                } else if (t == 0x0c || t == 0x13) {
                    unsigned long idle;
                    idle = cur->consecutiveIdleUnitCount();
                    if ((unsigned int)this->sn[0x4c] < (this->md->player->world->world_time - idle) / 1000) {
                        cur->setInUse(0);
                        cur->setAction(1);
                        cur->setTarget(-1);
                        cur->numberObjectsToDestroyValue = 0;
                        cur->setTargetType(-1);
                        cur->setTargetLocation(-1.0f, -1.0f, -1.0f);
                        this->attackStateValue.active = 0;
                    } else if (cur->isGathered(this, this->md) != 0) {
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
                    } else {
                        if (cur->allUnitsIdle(this->md, 1) == 1 && 5 < (this->md->player->world->world_time - idle) / 1000) {
                            cur->setConsecutiveIdleUnitCount(this->md->player->world->world_time);
                            cur->task(this, this->md, 9, 1, 0);
                        }
                    }
                } else if (t == 3) {
                } else {
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
                            cur->task(this, this->md, 9, 1, 0);
                        }
                    }
                    if (originalHP != 0 && originalUnits != 0 &&
                        (this->sn[0x1e] < ((originalHP - currentHP) * 100) / originalHP ||
                         this->sn[0x1f] < ((originalUnits - currentUnits) * 100) / originalUnits)) {
                        cur->setAction(3);
                        cur->task(this, this->md, 3, 1, 0);
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
                            Waypoint* loc;
                            loc = cur->targetLocation();
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
                                        if (ai2->currentTarget() != cur->target()) {
                                            this->taskAttacker(unit_id2, loc->x, loc->y, cur->target(), cur->subType(), 0, 0, -1, 0);
                                        } else if (ai2->currentAction() == -1) {
                                            this->taskAttacker(unit_id2, loc->x, loc->y, cur->target(), cur->subType(), 0, 0, -1, 0);
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
                }
            }

            if (this->attackStateValue.active != 0) {
                return;
            }
            cur = cur->next;
            if (cur == &this->groups || !cur) {
                this->nextActiveSoldierGroupToTaskValue = -1;
            } else {
                this->nextActiveSoldierGroupToTaskValue = cur->id();
            }
            if (param_2 <= debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c, 0x14fe) - param_1) {
                return;
            }
        } while (cur != sentinel);
    }
    this->nextActiveSoldierGroupToTaskValue = -1;
#undef RESET_GROUP
}
