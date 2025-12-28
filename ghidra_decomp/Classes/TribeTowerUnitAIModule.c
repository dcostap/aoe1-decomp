// Class: TribeTowerUnitAIModule
// Size:  0x134
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] save
// [02] load
// [03] owner
// [04] order
// [05] notify
// [06] notifyCommander
// [07] notifyCommander
// [08] search
// [09] importantWhenDead
// [10] retryableOrder
// [11] actionRequiresLiveTarget
// [12] bestUnitToAttack
// [13] mostDangerousEnemy
// [14] weakestEnemy
// [15] closestAttacker
// [16] closestObject
// [17] closestResourceObject
// [18] closestUndiscoveredTile
// [19] logDebug
// [20] canAttackUnit
// [21] canAttackUnitAtNeutrality
// [22] stopObject
// [23] attackObject
// [24] attackRoundupObject
// [25] huntObject
// [26] gatherObject
// [27] convertObject
// [28] healObject
// [29] repairObject
// [30] buildObject
// [31] tradeWithObject
// [32] explore
// [33] enterObject
// [34] unload
// [35] transportObject
// [36] moveTo
// [37] moveTo
// [38] moveTo
// [39] evasiveMoveTo
// [40] intelligentEvasiveMoveTo
// [41] runAwayFromAttackers
// [42] followObject
// [43] defendObject
// [44] defendPosition
// [45] seekAndDestroy
// [46] exploreAndDestroy
// [47] importantObject
// [48] convertToLOSResourceType
// [49] canConvert
// [50] processOrder
// [51] processNotify
// [52] processGroupNotify
// [53] processIdle
// [54] processMisc
// [55] processRetryableOrder
// [56] `scalar_deleting_destructor'
// [57] save
// [58] load
// [59] owner
// [60] order
// [61] notify
// [62] notifyCommander
// [63] notifyCommander
// [64] search
// [65] importantWhenDead
// [66] retryableOrder
// [67] actionRequiresLiveTarget
// [68] bestUnitToAttack
// [69] mostDangerousEnemy
// [70] weakestEnemy
// [71] closestAttacker
// [72] closestObject
// [73] closestResourceObject
// [74] closestUndiscoveredTile
// [75] logDebug
// [76] canAttackUnit
// [77] canAttackUnitAtNeutrality
// [78] stopObject
// [79] attackObject
// [80] attackRoundupObject
// [81] huntObject
// [82] gatherObject
// [83] convertObject
// [84] healObject
// [85] repairObject
// [86] buildObject
// [87] tradeWithObject
// [88] explore
// [89] enterObject
// [90] unload
// [91] transportObject
// [92] moveTo
// [93] moveTo
// [94] moveTo
// [95] evasiveMoveTo
// [96] intelligentEvasiveMoveTo
// [97] runAwayFromAttackers
// [98] followObject
// [99] defendObject
// [100] defendPosition
// [101] seekAndDestroy
// [102] exploreAndDestroy
// [103] importantObject
// [104] convertToLOSResourceType
// [105] canConvert
// [106] processOrder
// [107] processNotify
// [108] processGroupNotify
// [109] processIdle
// [110] processMisc
// [111] processRetryableOrder
// [112] create_task
// [113] get_target_task
// [114] is_attack_task
// [115] check_task
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TribeTowerUnitAIModule
// Address: 00507f60
/* public: __thiscall TribeTowerUnitAIModule::TribeTowerUnitAIModule(class RGE_Static_Object *,int)
    */

TribeTowerUnitAIModule * __thiscall
TribeTowerUnitAIModule::TribeTowerUnitAIModule
          (TribeTowerUnitAIModule *this,RGE_Static_Object *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560d48;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  UnitAIModule::UnitAIModule((UnitAIModule *)this,param_1,param_2);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0x128 = 0x15;
  puVar1 = (undefined4 *)operator_new(0x54);
  *(undefined4 **)&this->field_0x124 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined4 *)(*(int *)&this->field_0x124 + 4) = 3;
    *(undefined4 *)(*(int *)&this->field_0x124 + 8) = 4;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0xc) = 0x1a;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x10) = 0x18;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x14) = 6;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x18) = 0x23;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x1c) = 0x19;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x20) = 0x11;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x24) = 0xc;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x28) = 0x17;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x2c) = 0x24;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x30) = 0x1c;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x34) = 0x12;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x38) = 0xd;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x3c) = 0x1b;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x40) = 0x16;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x44) = 0x14;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x48) = 2;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x4c) = 0x15;
    *(undefined4 *)(*(int *)&this->field_0x124 + 0x50) = 0x27;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 005080e0
/* public: virtual void * __thiscall TribeTowerUnitAIModule::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TribeTowerUnitAIModule::_scalar_deleting_destructor_(TribeTowerUnitAIModule *this,uint param_1)
{
  ~TribeTowerUnitAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeTowerUnitAIModule
// Address: 00508100
/* public: virtual __thiscall TribeTowerUnitAIModule::~TribeTowerUnitAIModule(void) */

void __thiscall TribeTowerUnitAIModule::~TribeTowerUnitAIModule(TribeTowerUnitAIModule *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055c8ab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)this = &UnitAIModule::_vftable_;
  uStack_4 = 0;
  if (*(void **)&this->field_0x18 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x18);
    *(undefined4 *)&this->field_0x18 = 0;
  }
  if (*(void **)&this->field_0x24 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x24);
    *(undefined4 *)&this->field_0x24 = 0;
  }
  if (*(void **)&this->field_0x124 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x124);
    *(undefined4 *)&this->field_0x124 = 0;
  }
  if (*(void **)&this->field_0x12c != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x12c);
    *(undefined4 *)&this->field_0x12c = 0;
  }
  uStack_4 = 0xffffffff;
  if (*(void **)&this->field_0x60 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x60);
    *(undefined4 *)&this->field_0x60 = 0;
  }
  *(undefined4 *)&this->field_0x64 = 0;
  *(undefined4 *)&this->field_0x68 = 0;
  *(undefined4 *)&this->field_0x6c = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: canAttackUnit
// Address: 00508110
/* public: virtual int __thiscall TribeTowerUnitAIModule::canAttackUnit(class RGE_Static_Object *)
    */

int __thiscall
TribeTowerUnitAIModule::canAttackUnit(TribeTowerUnitAIModule *this,RGE_Static_Object *param_1)
{
  if (param_1 == (RGE_Static_Object *)0x0) {
    return (int)param_1;
  }
  if (param_1->master_obj->object_group == 1) {
    return 0;
  }
  return (uint)(1 < *(byte *)(*(int *)&this->field_0x4 + 0x48));
}

// --------------------------------------------------

// Function: canAttackUnitAtNeutrality
// Address: 00508140
/* public: virtual int __thiscall TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int) */

int __thiscall
TribeTowerUnitAIModule::canAttackUnitAtNeutrality(TribeTowerUnitAIModule *this,int param_1)
{
  if ((((param_1 != 3) && (param_1 != 0x1b)) && (param_1 != 4)) &&
     ((param_1 != 0x15 && (param_1 != 2)))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

