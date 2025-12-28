// Class: EmotionalAIModule
// Size:  0x1C0
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] loggingHistory
// [02] setLogHistory
// [03] toggleLogHistory
// [04] setHistoryFilename
// [05] loggingCommonHistory
// [06] setLogCommonHistory
// [07] toggleLogCommonHistory
// [08] loadState
// [09] saveState
// [10] gleanState
// [11] processMessage
// [12] update
// [13] setCallbackMessage
// [14] filterOutMessage
// [15] save
// [16] `vector_deleting_destructor'
// [17] loggingHistory
// [18] setLogHistory
// [19] toggleLogHistory
// [20] setHistoryFilename
// [21] loggingCommonHistory
// [22] setLogCommonHistory
// [23] toggleLogCommonHistory
// [24] loadState
// [25] saveState
// [26] gleanState
// [27] processMessage
// [28] update
// [29] setCallbackMessage
// [30] filterOutMessage
//
// Member Layout:
// [0x0F0] MainDecisionAIModule * md
// [0x0F4] int[6] stateValue (sz: 0x18)
// [0x10C] char[6][30] stateNameValue (sz: 0xB4)
// ----------------------------------------------------------------

// Function: EmotionalAIModule
// Address: 0040c7c0
// [HELPER] s_Aggressive: "Aggressive"
// [HELPER] s_Compassionate: "Compassionate"
// [HELPER] s_Defensive: "Defensive"
// [HELPER] s_Emotional_AI: "Emotional AI"
// [HELPER] s_Friendly: "Friendly"
// [HELPER] s_Passive: "Passive"
// [HELPER] s_Vengeful: "Vengeful"
EmotionalAIModule * __thiscall
EmotionalAIModule::EmotionalAIModule(EmotionalAIModule *this,void *param_1,int param_2)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  char *pcVar7;
  char (*pacVar8) [30];
  
  AIModule::AIModule((AIModule *)this,s_Emotional_AI,0x3ec,param_2,param_1);
  this->md = (MainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  piVar6 = this->stateValue;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar6 = 0x31;
    piVar6 = piVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s_Aggressive;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar7 + -uVar3;
  pacVar8 = this->stateNameValue;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s_Compassionate;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar7 + -uVar3;
  pacVar8 = this->stateNameValue + 1;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s_Defensive;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar7 + -uVar3;
  pacVar8 = this->stateNameValue + 2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s_Friendly;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar7 + -uVar3;
  pacVar8 = this->stateNameValue + 3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s_Passive;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar7 + -uVar3;
  pacVar8 = this->stateNameValue + 4;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s_Vengeful;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar7 + -uVar3;
  pacVar8 = this->stateNameValue + 5;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0040c900
void * __thiscall
EmotionalAIModule::_vector_deleting_destructor_(EmotionalAIModule *this,uint param_1)
{
  ~EmotionalAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: EmotionalAIModule
// Address: 0040c920
// [HELPER] s_Aggressive: "Aggressive"
// [HELPER] s_Compassionate: "Compassionate"
// [HELPER] s_Defensive: "Defensive"
// [HELPER] s_Emotional_AI: "Emotional AI"
// [HELPER] s_Friendly: "Friendly"
// [HELPER] s_Passive: "Passive"
// [HELPER] s_Vengeful: "Vengeful"
EmotionalAIModule * __thiscall
EmotionalAIModule::EmotionalAIModule(EmotionalAIModule *this,int param_1,int param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  char (*pacVar8) [30];
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c618;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  AIModule::AIModule((AIModule *)this,s_Emotional_AI,0x3ec,param_1,(void *)0x0);
  local_4 = 0;
  this->md = (MainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  piVar4 = this->stateValue;
  iVar6 = 6;
  do {
    rge_read(param_2,piVar4,4);
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  uVar2 = 0xffffffff;
  pcVar5 = &s_Aggressive;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar7 + -uVar2;
  pacVar8 = this->stateNameValue;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar2 = 0xffffffff;
  pcVar5 = &s_Compassionate;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar7 + -uVar2;
  pacVar8 = this->stateNameValue + 1;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar2 = 0xffffffff;
  pcVar5 = &s_Defensive;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar7 + -uVar2;
  pacVar8 = this->stateNameValue + 2;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar2 = 0xffffffff;
  pcVar5 = &s_Friendly;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar7 + -uVar2;
  pacVar8 = this->stateNameValue + 3;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar2 = 0xffffffff;
  pcVar5 = &s_Passive;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar7 + -uVar2;
  pacVar8 = this->stateNameValue + 4;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  uVar2 = 0xffffffff;
  pcVar5 = &s_Vengeful;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar7 + -uVar2;
  pacVar8 = this->stateNameValue + 5;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)*pacVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pacVar8 = (char (*) [30])(*pacVar8 + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    (*pacVar8)[0] = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pacVar8 = (char (*) [30])(*pacVar8 + 1);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~EmotionalAIModule
// Address: 0040ca90
void __thiscall EmotionalAIModule::~EmotionalAIModule(EmotionalAIModule *this)
{
  this->_padding_ = (int)&_vftable_;
  AIModule::~AIModule((AIModule *)this);
  return;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 0040caa0
void __thiscall
EmotionalAIModule::setMainDecisionAI(EmotionalAIModule *this,MainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0040cab0
int __thiscall EmotionalAIModule::save(EmotionalAIModule *this,int param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = this->stateValue;
  iVar2 = 6;
  do {
    rge_write(param_1,piVar1,4);
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 1;
}

// --------------------------------------------------

// Function: stateName
// Address: 0040cae0
char * __thiscall EmotionalAIModule::stateName(EmotionalAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 6)) {
    return this->stateNameValue[param_1];
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: state
// Address: 0040cb10
int __thiscall EmotionalAIModule::state(EmotionalAIModule *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 6)) {
    return this->stateValue[param_1];
  }
  return -1;
}

// --------------------------------------------------

// Function: setState
// Address: 0040cb30
void __thiscall EmotionalAIModule::setState(EmotionalAIModule *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 6)) {
    this->stateValue[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: incrementState
// Address: 0040cb50
void __thiscall EmotionalAIModule::incrementState(EmotionalAIModule *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 6)) {
    this->stateValue[param_1] = this->stateValue[param_1] + param_2;
  }
  return;
}

// --------------------------------------------------

// Function: decrementState
// Address: 0040cb80
void __thiscall EmotionalAIModule::decrementState(EmotionalAIModule *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 6)) {
    this->stateValue[param_1] = this->stateValue[param_1] - param_2;
  }
  return;
}

// --------------------------------------------------

// Function: overallState
// Address: 0040cbb0
int __thiscall EmotionalAIModule::overallState(EmotionalAIModule *this)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = this->stateValue[0];
  iVar1 = 0;
  iVar2 = 1;
  piVar3 = this->stateValue;
  do {
    piVar3 = piVar3 + 1;
    if (iVar4 < *piVar3) {
      iVar1 = iVar2;
      iVar4 = *piVar3;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  return iVar1;
}

// --------------------------------------------------

// Function: setOverallState
// Address: 0040cbe0
void __thiscall EmotionalAIModule::setOverallState(EmotionalAIModule *this,int param_1)
{
  switch(param_1) {
  case 0:
    this->stateValue[0] = 100;
    this->stateValue[4] = 10;
    this->stateValue[1] = 10;
    this->stateValue[3] = 10;
    this->stateValue[2] = 0;
    this->stateValue[5] = 0x46;
    return;
  case 1:
    this->stateValue[0] = 10;
    this->stateValue[4] = 0x32;
    this->stateValue[1] = 100;
    this->stateValue[3] = 0x50;
    this->stateValue[2] = 0x32;
    this->stateValue[5] = 0;
    return;
  case 2:
    this->stateValue[0] = 0x14;
    this->stateValue[4] = 0x3c;
    this->stateValue[1] = 0x32;
    this->stateValue[3] = 0x32;
    this->stateValue[2] = 100;
    this->stateValue[5] = 10;
    return;
  case 3:
    this->stateValue[0] = 10;
    this->stateValue[4] = 0x32;
    this->stateValue[1] = 0x46;
    this->stateValue[3] = 100;
    this->stateValue[2] = 0x32;
    this->stateValue[5] = 0x14;
    return;
  case 4:
    this->stateValue[0] = 0x14;
    this->stateValue[4] = 100;
    this->stateValue[1] = 0x46;
    this->stateValue[3] = 0x32;
    this->stateValue[2] = 0x3c;
    this->stateValue[5] = 0;
    return;
  case 5:
    this->stateValue[0] = 0x5a;
    this->stateValue[4] = 10;
    this->stateValue[1] = 0;
    this->stateValue[3] = 0x1e;
    this->stateValue[2] = 0x32;
    this->stateValue[5] = 100;
  }
  return;
}

// --------------------------------------------------

// Function: defaultState
// Address: 0040cd80
int __thiscall EmotionalAIModule::defaultState(EmotionalAIModule *this)
{
  return 4;
}

// --------------------------------------------------

