// Class: AIPlayPhaseCommand
// Size:  0x10
//
// Member Layout:
// [0x000] uchar groupValue
// [0x001] uchar typeValue
// [0x004] int value1Value
// [0x008] int value2Value
// [0x00C] int value3Value
// ----------------------------------------------------------------

// Function: AIPlayPhaseCommand
// Address: 0040e930
/* public: __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(void) */

void __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(AIPlayPhaseCommand *this)
{
  this->groupValue = '\0';
  this->typeValue = '\0';
  this->value1Value = 0;
  this->value2Value = 0;
  this->value3Value = 0;
  return;
}

// --------------------------------------------------

// Function: AIPlayPhaseCommand
// Address: 0040e950
/* public: __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char,unsigned
   char,int,int,int) */

void __thiscall
AIPlayPhaseCommand::AIPlayPhaseCommand
          (AIPlayPhaseCommand *this,uchar param_1,uchar param_2,int param_3,int param_4,int param_5)
{
  this->groupValue = param_1;
  this->typeValue = param_2;
  this->value1Value = param_3;
  this->value2Value = param_4;
  this->value3Value = param_5;
  return;
}

// --------------------------------------------------

// Function: AIPlayPhaseCommand
// Address: 0040e980
/* public: __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char,char *,int,int,int) */

AIPlayPhaseCommand * __thiscall
AIPlayPhaseCommand::AIPlayPhaseCommand
          (AIPlayPhaseCommand *this,uchar param_1,char *param_2,int param_3,int param_4,int param_5)
{
  uchar uVar1;
  
  this->groupValue = param_1;
  uVar1 = convertToIntType(this,param_2);
  this->typeValue = uVar1;
  this->value2Value = param_4;
  this->value1Value = param_3;
  this->value3Value = param_5;
  return this;
}

// --------------------------------------------------

// Function: nameType
// Address: 0040e9c0
/* public: char * __thiscall AIPlayPhaseCommand::nameType(void)const  */

char * __thiscall AIPlayPhaseCommand::nameType(AIPlayPhaseCommand *this)
{
  char *pcVar1;
  
  pcVar1 = convertToNameType(this,this->typeValue);
  return pcVar1;
}

// --------------------------------------------------

// Function: convertToIntType
// Address: 0040e9d0
// [HELPER] s_Attack: "Attack"
// [HELPER] s_AttackSavedTarget: "AttackSavedTarget"
// [HELPER] s_Heal: "Heal"
// [HELPER] s_Move: "Move"
// [HELPER] s_ResetAliveCount: "ResetAliveCount"
// [HELPER] s_ResetHitPoints: "ResetHitPoints"
// [HELPER] s_Retreat: "Retreat"
// [HELPER] s_Wait: "Wait"
/* protected: unsigned char __thiscall AIPlayPhaseCommand::convertToIntType(char *)const  */

uchar __thiscall AIPlayPhaseCommand::convertToIntType(AIPlayPhaseCommand *this,char *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Move;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ea06:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ea0b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ea06;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ea0b:
  if (iVar3 == 0) {
    return '\x01';
  }
  pbVar4 = &s_Attack;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ea46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ea4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ea46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ea4b:
  if (iVar3 == 0) {
    return '\x02';
  }
  pbVar4 = &s_AttackSavedTarget;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ea86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ea8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ea86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ea8b:
  if (iVar3 == 0) {
    return '\x03';
  }
  pbVar4 = &s_Retreat;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eac6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eacb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eac6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eacb:
  if (iVar3 == 0) {
    return '\x04';
  }
  pbVar4 = &s_Heal;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eb06:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eb0b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eb06;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eb0b:
  if (iVar3 == 0) {
    return '\x05';
  }
  pbVar4 = &s_ResetHitPoints;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eb46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eb4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eb46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eb4b:
  if (iVar3 == 0) {
    return '\x06';
  }
  pbVar4 = &s_ResetAliveCount;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eb86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eb8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eb86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eb8b:
  if (iVar3 == 0) {
    return '\a';
  }
  pbVar2 = &s_Wait;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return '\b';
    }
    bVar1 = ((byte *)param_1)[1];
    bVar5 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return '\b';
    }
  }
  return (1 - bVar5 != (uint)(bVar5 != 0)) - 1U & 8;
}

// --------------------------------------------------

// Function: convertToNameType
// Address: 0040ebf0
// [HELPER] s_Attack: "Attack"
// [HELPER] s_AttackSavedTarget: "AttackSavedTarget"
// [HELPER] s_Heal: "Heal"
// [HELPER] s_Invalid: "Invalid"
// [HELPER] s_Move: "Move"
// [HELPER] s_ResetAliveCount: "ResetAliveCount"
// [HELPER] s_ResetHitPoints: "ResetHitPoints"
// [HELPER] s_Retreat: "Retreat"
// [HELPER] s_Wait: "Wait"
/* protected: char * __thiscall AIPlayPhaseCommand::convertToNameType(unsigned char)const  */

char * __thiscall AIPlayPhaseCommand::convertToNameType(AIPlayPhaseCommand *this,uchar param_1)
{
  switch(param_1) {
  case '\x01':
    return &s_Move;
  case '\x02':
    return &s_Attack;
  case '\x03':
    return &s_AttackSavedTarget;
  case '\x04':
    return &s_Retreat;
  case '\x05':
    return &s_Heal;
  case '\x06':
    return &s_ResetHitPoints;
  case '\a':
    return &s_ResetAliveCount;
  case '\b':
    return &s_Wait;
  default:
    return s_Invalid;
  }
}

// --------------------------------------------------

