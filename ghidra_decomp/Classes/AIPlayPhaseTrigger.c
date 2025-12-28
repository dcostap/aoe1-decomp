// Class: AIPlayPhaseTrigger
// Size:  0x14
//
// Member Layout:
// [0x000] uchar typeValue
// [0x004] int value1Value
// [0x008] int value2Value
// [0x00C] uchar phaseValue
// [0x00D] uchar nextPhaseValue
// [0x010] int randomnessValue
// ----------------------------------------------------------------

// Function: AIPlayPhaseTrigger
// Address: 0040ec70
/* public: __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(void) */

void __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(AIPlayPhaseTrigger *this)
{
  this->typeValue = '\0';
  this->value1Value = -1;
  this->value2Value = -1;
  this->phaseValue = '\0';
  this->nextPhaseValue = '\0';
  return;
}

// --------------------------------------------------

// Function: AIPlayPhaseTrigger
// Address: 0040ec90
/* public: __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(unsigned char,int,int,unsigned
   char,unsigned char,int) */

void __thiscall
AIPlayPhaseTrigger::AIPlayPhaseTrigger
          (AIPlayPhaseTrigger *this,uchar param_1,int param_2,int param_3,uchar param_4,
          uchar param_5,int param_6)
{
  this->typeValue = param_1;
  this->value1Value = param_2;
  this->value2Value = param_3;
  this->phaseValue = param_4;
  this->nextPhaseValue = param_5;
  this->randomnessValue = param_6;
  return;
}

// --------------------------------------------------

// Function: AIPlayPhaseTrigger
// Address: 0040ecc0
/* public: __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(char *,int,int,unsigned char,unsigned
   char,int) */

AIPlayPhaseTrigger * __thiscall
AIPlayPhaseTrigger::AIPlayPhaseTrigger
          (AIPlayPhaseTrigger *this,char *param_1,int param_2,int param_3,uchar param_4,
          uchar param_5,int param_6)
{
  uchar uVar1;
  
  uVar1 = convertToIntType(this,param_1);
  this->typeValue = uVar1;
  this->value1Value = param_2;
  this->value2Value = param_3;
  this->phaseValue = param_4;
  this->nextPhaseValue = param_5;
  this->randomnessValue = param_6;
  return this;
}

// --------------------------------------------------

// Function: nameType
// Address: 0040ed00
/* public: char * __thiscall AIPlayPhaseTrigger::nameType(void)const  */

char * __thiscall AIPlayPhaseTrigger::nameType(AIPlayPhaseTrigger *this)
{
  char *pcVar1;
  
  pcVar1 = convertToNameType(this,this->typeValue);
  return pcVar1;
}

// --------------------------------------------------

// Function: convertToIntType
// Address: 0040ed10
// [HELPER] s_DamageToAnyGroup: "DamageToAnyGroup"
// [HELPER] s_DamageToGroup: "DamageToGroup"
// [HELPER] s_Death: "Death"
// [HELPER] s_DeathOfGroup: "DeathOfGroup"
// [HELPER] s_Gather: "Gather"
// [HELPER] s_HealOfGroup: "HealOfGroup"
// [HELPER] s_HealthLost: "HealthLost"
// [HELPER] s_Immediate: "Immediate"
// [HELPER] s_Level1EnemySighted: "Level1EnemySighted"
// [HELPER] s_Level2EnemySighted: "Level2EnemySighted"
// [HELPER] s_Time: "Time"
/* protected: unsigned char __thiscall AIPlayPhaseTrigger::convertToIntType(char *)const  */

uchar __thiscall AIPlayPhaseTrigger::convertToIntType(AIPlayPhaseTrigger *this,char *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Gather;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ed46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ed4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ed46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ed4b:
  if (iVar3 == 0) {
    return '\x01';
  }
  pbVar4 = &s_Death;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ed86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ed8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ed86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ed8b:
  if (iVar3 == 0) {
    return '\x02';
  }
  pbVar4 = &s_HealthLost;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040edc6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040edcb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040edc6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040edcb:
  if (iVar3 == 0) {
    return '\x03';
  }
  pbVar4 = &s_DamageToGroup;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ee06:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ee0b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ee06;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ee0b:
  if (iVar3 == 0) {
    return '\x04';
  }
  pbVar4 = &s_DamageToAnyGroup;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ee46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ee4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ee46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ee4b:
  if (iVar3 == 0) {
    return '\x05';
  }
  pbVar4 = &s_Level1EnemySighted;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ee86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ee8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ee86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ee8b:
  if (iVar3 == 0) {
    return '\x06';
  }
  pbVar4 = &s_Level2EnemySighted;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040eec6:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040eecb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040eec6;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040eecb:
  if (iVar3 == 0) {
    return '\a';
  }
  pbVar4 = &s_DeathOfGroup;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ef06:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ef0b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ef06;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ef0b:
  if (iVar3 == 0) {
    return '\b';
  }
  pbVar4 = &s_HealOfGroup;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ef46:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ef4b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ef46;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ef4b:
  if (iVar3 == 0) {
    return '\t';
  }
  pbVar4 = &s_Immediate;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040ef86:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0040ef8b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040ef86;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040ef8b:
  if (iVar3 == 0) {
    return '\n';
  }
  pbVar2 = &s_Time;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return '\v';
    }
    bVar1 = ((byte *)param_1)[1];
    bVar5 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return '\v';
    }
  }
  return (1 - bVar5 != (uint)(bVar5 != 0)) - 1U & 0xb;
}

// --------------------------------------------------

// Function: convertToNameType
// Address: 0040eff0
// [HELPER] s_DamageToAnyGroup: "DamageToAnyGroup"
// [HELPER] s_DamageToGroup: "DamageToGroup"
// [HELPER] s_Death: "Death"
// [HELPER] s_DeathOfGroup: "DeathOfGroup"
// [HELPER] s_Gather: "Gather"
// [HELPER] s_HealOfGroup: "HealOfGroup"
// [HELPER] s_HealthLost: "HealthLost"
// [HELPER] s_Immediate: "Immediate"
// [HELPER] s_Invalid: "Invalid"
// [HELPER] s_Level1EnemySighted: "Level1EnemySighted"
// [HELPER] s_Level2EnemySighted: "Level2EnemySighted"
// [HELPER] s_Time: "Time"
/* protected: char * __thiscall AIPlayPhaseTrigger::convertToNameType(unsigned char)const  */

char * __thiscall AIPlayPhaseTrigger::convertToNameType(AIPlayPhaseTrigger *this,uchar param_1)
{
  switch(param_1) {
  case '\x01':
    return &s_Gather;
  case '\x02':
    return &s_Death;
  case '\x03':
    return &s_HealthLost;
  case '\x04':
    return &s_DamageToGroup;
  case '\x05':
    return &s_DamageToAnyGroup;
  case '\x06':
    return &s_Level1EnemySighted;
  case '\a':
    return &s_Level2EnemySighted;
  case '\b':
    return &s_DeathOfGroup;
  case '\t':
    return &s_HealOfGroup;
  case '\n':
    return &s_Immediate;
  case '\v':
    return &s_Time;
  default:
    return s_Invalid;
  }
}

// --------------------------------------------------

