// Class: CombatRuleSystem
// Size:  0x9C8
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] `scalar_deleting_destructor'
// [02] loggingHistory
// [03] setLogHistory
// [04] toggleLogHistory
// [05] setHistoryFilename
// [06] loggingCommonHistory
// [07] setLogCommonHistory
// [08] toggleLogCommonHistory
// [09] loadState
// [10] saveState
// [11] gleanState
// [12] processMessage
// [13] update
// [14] setCallbackMessage
// [15] filterOutMessage
//
// Member Layout:
// [0x004] uchar[2500] ratingValue (sz: 0x9C4)
// ----------------------------------------------------------------

// Function: CombatRuleSystem
// Address: 004d68d0
void __thiscall CombatRuleSystem::CombatRuleSystem(CombatRuleSystem *this)
{
  this->_padding_ = (int)&_vftable_;
  return;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004d68e0
void * __thiscall
CombatRuleSystem::_scalar_deleting_destructor_(CombatRuleSystem *this,uint param_1)
{
  ~CombatRuleSystem(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~CombatRuleSystem
// Address: 004d6900
void __thiscall CombatRuleSystem::~CombatRuleSystem(CombatRuleSystem *this)
{
  this->_padding_ = (int)&_vftable_;
  return;
}

// --------------------------------------------------

// Function: loadRules
// Address: 004d6910
// [HELPER] s_NONE: "NONE"
// [HELPER] s__c_c: "%c%c"
// [HELPER] s__d__d__d_: "%d %d %d "
// [HELPER] s__s: "%s"
// [HELPER] s__tmp: ".tmp"
// [HELPER] s_r: "r"
int __thiscall CombatRuleSystem::loadRules(CombatRuleSystem *this,char *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uchar *puVar6;
  bool bVar7;
  char commentTemp1;
  char commentTemp2;
  int unitIndex;
  int rating;
  int targetUnitType;
  char temp [256];
  
  pbVar5 = &s_NONE;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar7 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_004d694e:
      iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_004d6953;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar7 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_004d694e;
    pbVar2 = pbVar2 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004d6953:
  if ((iVar3 != 0) && (param_1 != (char *)0x0)) {
    sprintf(temp + 4,s__s,param_1);
    iVar3 = fopen(temp + 4,s_r);
    if (iVar3 != 0) {
      iVar4 = 0x271;
      puVar6 = this->ratingValue;
      while (iVar4 != 0) {
        iVar4 = iVar4 + -1;
        builtin_memcpy(puVar6,"2222",4);
        puVar6 = puVar6 + 4;
      }
      iVar4 = fgets(temp + 4,0x100,iVar3);
      while (iVar4 != 0) {
        sscanf(temp + 4,s__c_c,(int)&unitIndex + 2,(int)&unitIndex + 3);
        if ((((unitIndex._2_1_ != '/') || (unitIndex._3_1_ != '/')) &&
            (sscanf(temp + 4,s__d__d__d_,&rating,temp,&targetUnitType), -1 < rating)) &&
           (rating < 0x32)) {
          this->ratingValue[temp._0_4_ + rating * 0x32] = (uchar)targetUnitType;
        }
        iVar4 = fgets(temp + 4,0x100,iVar3);
      }
      fclose(iVar3);
      iVar3 = strstr(param_1,s__tmp);
      if (iVar3 != 0) {
        __unlink(param_1);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: bestUnitTypeToAttack
// Address: 004d6aa0
int __thiscall CombatRuleSystem::bestUnitTypeToAttack(CombatRuleSystem *this,int param_1)
{
  return -1;
}

// --------------------------------------------------

// Function: bestUnitTypeToDefendAgainst
// Address: 004d6ab0
int __thiscall CombatRuleSystem::bestUnitTypeToDefendAgainst(CombatRuleSystem *this,int param_1)
{
  return -1;
}

// --------------------------------------------------

