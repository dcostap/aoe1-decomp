// Class: AIPlay
// Size:  0x608
//
// Member Layout:
// [0x000] char[65] nameValue (sz: 0x41)
// [0x041] uchar minimumNumberUnitsValue
// [0x042] uchar maximumNumberUnitsValue
// [0x043] uchar typeValue
// [0x044] uchar[5] targetTypeValue (sz: 0x5)
// [0x049] uchar[5] targetCharacteristicValue (sz: 0x5)
// [0x04E] uchar powerValue
// [0x04F] uchar overflowValue
// [0x050] uchar intelligenceValue
// [0x051] uchar deathPercentageValue
// [0x052] uchar numberGroupsValue
// [0x053] AIPlayGroup[5] groups (sz: 0x3C)
// [0x090] AIPlayPhase[10] phases (sz: 0x578)
// ----------------------------------------------------------------

// Function: AIPlay
// Address: 0040f2e0
AIPlay * __thiscall AIPlay::AIPlay(AIPlay *this)
{
  uchar *puVar1;
  int iVar2;
  AIPlayGroup *this_00;
  AIPlayPhase *this_01;
  
  this->minimumNumberUnitsValue = '\x01';
  this->typeValue = '\x01';
  this->overflowValue = '\x01';
  this->maximumNumberUnitsValue = 0xff;
  this->powerValue = '\0';
  this->intelligenceValue = '2';
  this->deathPercentageValue = '2';
  this_00 = this->groups;
  iVar2 = 5;
  do {
    AIPlayGroup::AIPlayGroup(this_00);
    this_00 = this_00 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this_01 = this->phases;
  iVar2 = 10;
  do {
    AIPlayPhase::AIPlayPhase(this_01);
    this_01 = this_01 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = this->targetCharacteristicValue;
  do {
    puVar1[-5] = '\x05';
    *puVar1 = '\x05';
    puVar1 = puVar1 + 1;
  } while ((int)(puVar1 + (-0x49 - (int)this)) < 5);
  return this;
}

// --------------------------------------------------

// Function: setName
// Address: 0040f360
void __thiscall AIPlay::setName(AIPlay *this,char *param_1)
{
  if (param_1 != (char *)0x0) {
    strncpy(this,param_1,0x40);
  }
  return;
}

// --------------------------------------------------

// Function: humanPlay
// Address: 0040f380
int __thiscall AIPlay::humanPlay(AIPlay *this)
{
  if ((this->nameValue[0] == 'H') && (this->nameValue[1] == 'P')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: typeName
// Address: 0040f3a0
char * __thiscall AIPlay::typeName(AIPlay *this)
{
  char *pcVar1;
  
  pcVar1 = convertToNameType(this,this->typeValue);
  return pcVar1;
}

// --------------------------------------------------

// Function: targetType
// Address: 0040f3b0
uchar __thiscall AIPlay::targetType(AIPlay *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 5)) {
    return this->targetTypeValue[param_1];
  }
  return '\0';
}

// --------------------------------------------------

// Function: isTargetType
// Address: 0040f3d0
int __thiscall AIPlay::isTargetType(AIPlay *this,uchar param_1)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (this->targetTypeValue[iVar1] == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return 0;
}

// --------------------------------------------------

// Function: addTargetType
// Address: 0040f3f0
int __thiscall AIPlay::addTargetType(AIPlay *this,uchar param_1)
{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if ((this->targetTypeValue[iVar1] == '\0') || (this->targetTypeValue[iVar1] == '\x05')) break;
    iVar1 = iVar1 + 1;
    if (4 < iVar1) {
      return 0;
    }
  }
  this->targetTypeValue[iVar1] = param_1;
  return 1;
}

// --------------------------------------------------

// Function: targetCharacteristic
// Address: 0040f420
uchar __thiscall AIPlay::targetCharacteristic(AIPlay *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 5)) {
    return this->targetCharacteristicValue[param_1];
  }
  return '\0';
}

// --------------------------------------------------

// Function: isTargetCharacteristic
// Address: 0040f440
int __thiscall AIPlay::isTargetCharacteristic(AIPlay *this,uchar param_1)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (this->targetCharacteristicValue[iVar1] == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return 0;
}

// --------------------------------------------------

// Function: addTargetCharacteristic
// Address: 0040f460
int __thiscall AIPlay::addTargetCharacteristic(AIPlay *this,uchar param_1)
{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if ((this->targetCharacteristicValue[iVar1] == '\0') ||
       (this->targetCharacteristicValue[iVar1] == '\x05')) break;
    iVar1 = iVar1 + 1;
    if (4 < iVar1) {
      return 0;
    }
  }
  this->targetCharacteristicValue[iVar1] = param_1;
  return 1;
}

// --------------------------------------------------

// Function: gatherTolerance
// Address: 0040f490
int __thiscall AIPlay::gatherTolerance(AIPlay *this,int param_1,int param_2)
{
  AIPlayPhase *this_00;
  AIPlayPhaseTrigger *pAVar1;
  int iVar2;
  
  this_00 = phase(this,param_2);
  if (this_00 == (AIPlayPhase *)0x0) {
    return 2;
  }
  iVar2 = 0;
  while( true ) {
    pAVar1 = AIPlayPhase::trigger(this_00,iVar2);
    if ((pAVar1 != (AIPlayPhaseTrigger *)0x0) && (pAVar1->typeValue == '\x01')) break;
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 2;
    }
  }
  return pAVar1->value1Value;
}

// --------------------------------------------------

// Function: group
// Address: 0040f4e0
AIPlayGroup * __thiscall AIPlay::group(AIPlay *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 5)) {
    return this->groups + param_1;
  }
  return (AIPlayGroup *)0x0;
}

// --------------------------------------------------

// Function: phase
// Address: 0040f500
AIPlayPhase * __thiscall AIPlay::phase(AIPlay *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 10)) {
    return this->phases + param_1;
  }
  return (AIPlayPhase *)0x0;
}

// --------------------------------------------------

// Function: fillGroups
// Address: 0040f530
int __thiscall
AIPlay::fillGroups(AIPlay *this,AIPlayStatus *param_1,int *param_2,int param_3,
                  RGE_Game_World *param_4)
{
  uchar uVar1;
  byte bVar2;
  uchar uVar3;
  byte bVar4;
  AIPlay *this_00;
  RGE_Static_Object *pRVar5;
  AIPlayGroup *pAVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  AIPlay *play;
  int deviation;
  int j;
  int i;
  int local_4e8;
  int rVal;
  int minUnits;
  int smallestGroupSize;
  int a;
  int iStack_4d4;
  AIPlayGroup *group;
  int unitsByTypeCount [6];
  int unitsByType [6] [50];
  
  unitsByTypeCount[0] = (int)this;
  this_00 = AIPlayBook::play(param_4->playbook,param_1->playNumberValue);
  if (this_00 == (AIPlay *)0x0) {
    return 0;
  }
  piVar10 = unitsByTypeCount;
  minUnits = 1;
  for (iVar8 = 6; piVar10 = piVar10 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar10 = 0;
  }
  if (0 < param_3) {
    j = param_3;
    do {
      pRVar5 = RGE_Game_World::object(param_4,*param_2);
      if (((pRVar5 == (RGE_Static_Object *)0x0) ||
          (iVar8 = (**(code **)(param_4->playbook->_padding_ + 0x10))(pRVar5), iVar8 < 0)) ||
         (5 < iVar8)) {
        minUnits = 0;
      }
      else {
        iVar9 = unitsByTypeCount[iVar8 + 1];
        iVar11 = *param_2;
        unitsByTypeCount[iVar8 + 1] = iVar9 + 1;
        unitsByType[iVar8][iVar9 + 1] = iVar11;
      }
      param_2 = param_2 + 1;
      j = j + -1;
    } while (j != 0);
  }
  local_4e8 = 0;
  if (this_00->numberGroupsValue != '\0') {
    do {
      pAVar6 = AIPlay::group(this_00,local_4e8);
      if (pAVar6 == (AIPlayGroup *)0x0) {
        return 0;
      }
      j = (int)unitsByTypeCount;
      i = 0;
      rVal = 0;
      do {
        j = j + 4;
        bVar2 = AIPlayGroup::minimum(pAVar6,i);
        if (bVar2 != 0) {
          iVar9 = 0;
          iVar11 = 0;
          iVar8 = *(int *)j;
          if (0 < iVar8) {
            do {
              if ((int)(uint)bVar2 <= iVar9) break;
              if (unitsByType[0][iVar11 + rVal + 1] != -1) {
                iVar7 = AIPlayStatus::addGrouping
                                  (param_1,unitsByType[0][iVar11 + rVal + 1],(uchar)local_4e8,
                                   (uchar)i);
                if (iVar7 == 1) {
                  iVar9 = iVar9 + 1;
                  uVar1 = this_00->maximumNumberUnitsValue;
                  unitsByType[0][iVar11 + rVal + 1] = -1;
                  uVar3 = AIPlayStatus::numberInPlay(param_1);
                  if (uVar3 == uVar1) goto LAB_0040f918;
                }
                else {
                  minUnits = 0;
                }
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 < iVar8);
          }
        }
        rVal = rVal + 0x32;
        i = i + 1;
      } while (rVal < 300);
      local_4e8 = local_4e8 + 1;
    } while (local_4e8 < (int)(uint)this_00->numberGroupsValue);
  }
  rVal = (int)unitsByTypeCount;
  j = (int)(unitsByType[0] + 1);
  local_4e8 = 0;
  do {
    rVal = rVal + 4;
    iStack_4d4 = 0;
    iVar8 = *(int *)rVal;
    if (0 < iVar8) {
      i = j;
      do {
        iVar9 = *(int *)i;
        if (iVar9 != -1) {
          if (*(char *)(unitsByTypeCount[0] + 0x4f) == '\x01') {
            iVar11 = -1;
            iVar7 = 0;
            a = 0;
            if (this_00->numberGroupsValue != '\0') {
              do {
                pAVar6 = AIPlay::group(this_00,iVar7);
                if (pAVar6 != (AIPlayGroup *)0x0) {
                  bVar2 = AIPlayStatus::numberOfTypeInGroup(param_1,iVar7,local_4e8);
                  bVar4 = AIPlayGroup::maximum(pAVar6,local_4e8);
                  if ((bVar2 < bVar4) &&
                     ((iVar11 == -1 ||
                      (bVar2 = AIPlayStatus::numberInGroup(param_1,iVar7), (uint)bVar2 < (uint)a))))
{
                    bVar2 = AIPlayStatus::numberInGroup(param_1,iVar7);
                    a = (int)bVar2;
                    iVar11 = iVar7;
                  }
                }
                iVar7 = iVar7 + 1;
              } while (iVar7 < (int)(uint)this_00->numberGroupsValue);
            }
            if (iVar11 != -1) {
              iVar9 = AIPlayStatus::addGrouping(param_1,iVar9,(uchar)iVar11,(uchar)local_4e8);
              if (iVar9 == 1) {
                uVar1 = this_00->maximumNumberUnitsValue;
                *(undefined4 *)i = 0xffffffff;
                uVar3 = AIPlayStatus::numberInPlay(param_1);
                if (uVar3 == uVar1) goto LAB_0040f918;
              }
              else {
                minUnits = 0;
              }
            }
          }
          else if ((*(char *)(unitsByTypeCount[0] + 0x4f) == '\x02') &&
                  (iVar11 = 0, this_00->numberGroupsValue != '\0')) {
            do {
              pAVar6 = AIPlay::group(this_00,iVar11);
              if (pAVar6 != (AIPlayGroup *)0x0) {
                bVar2 = AIPlayStatus::numberOfTypeInGroup(param_1,iVar11,local_4e8);
                bVar4 = AIPlayGroup::maximum(pAVar6,local_4e8);
                if (bVar2 < bVar4) {
                  iVar7 = AIPlayStatus::addGrouping(param_1,iVar9,(uchar)iVar11,(uchar)local_4e8);
                  if (iVar7 == 1) {
                    uVar1 = this_00->maximumNumberUnitsValue;
                    *(undefined4 *)i = 0xffffffff;
                    uVar3 = AIPlayStatus::numberInPlay(param_1);
                    if (uVar3 == uVar1) goto LAB_0040f918;
                    break;
                  }
                  minUnits = 0;
                }
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 < (int)(uint)this_00->numberGroupsValue);
          }
        }
        iStack_4d4 = iStack_4d4 + 1;
        i = i + 4;
      } while (iStack_4d4 < iVar8);
    }
    local_4e8 = local_4e8 + 1;
    j = j + 200;
  } while (local_4e8 < 6);
LAB_0040f918:
  iVar8 = 0;
  j = 0;
  j._0_1_ = '\0';
  if (this_00->numberGroupsValue != '\0') {
    do {
      unitsByTypeCount[0] = (int)AIPlay::group(this_00,iVar8);
      if ((AIPlayGroup *)unitsByTypeCount[0] != (AIPlayGroup *)0x0) {
        iVar9 = 0;
        do {
          bVar2 = AIPlayGroup::minimum((AIPlayGroup *)unitsByTypeCount[0],iVar9);
          bVar4 = AIPlayStatus::numberOfTypeInGroup(param_1,iVar8,iVar9);
          if ((uint)bVar4 < (uint)bVar2) {
            j = j + ((uint)bVar2 - (uint)bVar4);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < 6);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(uint)this_00->numberGroupsValue);
  }
  param_1->deviationValue = (uchar)j;
  return minUnits;
}

// --------------------------------------------------

// Function: groupGivenCommandOnPhase
// Address: 0040f9b0
int __thiscall AIPlay::groupGivenCommandOnPhase(AIPlay *this,int param_1,int param_2,int param_3)
{
  AIPlayPhaseCommand *pAVar1;
  int iVar2;
  
  if ((((-1 < param_1) && (param_1 < 5)) && (-1 < param_3)) && (param_3 < 10)) {
    iVar2 = 0;
    do {
      pAVar1 = AIPlayPhase::command(this->phases + param_3,iVar2);
      if ((uint)pAVar1->groupValue == param_1) {
        pAVar1 = AIPlayPhase::command(this->phases + param_3,iVar2);
        if ((uint)pAVar1->typeValue == param_2) {
          return iVar2;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
    return -1;
  }
  return -1;
}

// --------------------------------------------------

// Function: convertToIntType
// Address: 0040fa40
// [HELPER] s_Annoy: "Annoy"
// [HELPER] s_Attack: "Attack"
// [HELPER] s_Flank: "Flank"
// [HELPER] s_Recon: "Recon"
uchar __thiscall AIPlay::convertToIntType(AIPlay *this,char *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Attack;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040fa76:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040fa7b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040fa76;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040fa7b:
  if (iVar3 == 0) {
    return '\x01';
  }
  pbVar4 = &s_Annoy;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040fab6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040fabb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040fab6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040fabb:
  if (iVar3 == 0) {
    return '\x02';
  }
  pbVar4 = &s_Flank;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040faf6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040fafb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040faf6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040fafb:
  if (iVar3 == 0) {
    return '\x03';
  }
  pbVar2 = &s_Recon;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return '\x04';
    }
    bVar1 = ((byte *)param_1)[1];
    bVar5 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return '\x04';
    }
  }
  return (1 - bVar5 != (uint)(bVar5 != 0)) - 1U & 4;
}

// --------------------------------------------------

// Function: convertToNameType
// Address: 0040fb60
// [HELPER] s_Annoy: "Annoy"
// [HELPER] s_Attack: "Attack"
// [HELPER] s_Flank: "Flank"
// [HELPER] s_Invalid: "Invalid"
// [HELPER] s_Recon: "Recon"
char * __thiscall AIPlay::convertToNameType(AIPlay *this,uchar param_1)
{
  switch(param_1) {
  case '\x01':
    return &s_Attack;
  case '\x02':
    return &s_Annoy;
  case '\x03':
    return &s_Flank;
  case '\x04':
    return &s_Recon;
  default:
    return s_Invalid;
  }
}

// --------------------------------------------------

// Function: locationsOnMap
// Address: 0040fbb0
int __thiscall AIPlay::locationsOnMap(AIPlay *this,int param_1,int param_2,int param_3,int param_4)
{
  AIPlayPhaseCommand *pAVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  AIPlayPhase *this_00;
  int p;
  int local_4;
  
  local_4 = 0;
  this_00 = this->phases;
  do {
    iVar4 = 0;
    do {
      pAVar1 = AIPlayPhase::command(this_00,iVar4);
      if (pAVar1->typeValue == '\x01') {
        iVar3 = pAVar1->value1Value + param_1;
        iVar2 = pAVar1->value2Value + param_2;
        if ((((iVar3 < 0) || (iVar2 < 0)) || (param_3 <= iVar3)) || (param_4 <= iVar2)) {
          return 0;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    this_00 = this_00 + 1;
    local_4 = local_4 + 1;
    if (9 < local_4) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

