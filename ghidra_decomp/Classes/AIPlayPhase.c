// Class: AIPlayPhase
// Size:  0x8C
//
// Member Layout:
// [0x000] AIPlayPhaseCommand[5] commands (sz: 0x50)
// [0x050] AIPlayPhaseTrigger[3] triggers (sz: 0x3C)
// ----------------------------------------------------------------

// Function: AIPlayPhase
// Address: 0040f0a0
AIPlayPhase * __thiscall AIPlayPhase::AIPlayPhase(AIPlayPhase *this)
{
  AIPlayPhase *this_00;
  AIPlayPhaseTrigger *this_01;
  int iVar1;
  
  iVar1 = 5;
  this_00 = this;
  do {
    AIPlayPhaseCommand::AIPlayPhaseCommand(this_00->commands);
    this_00 = (AIPlayPhase *)(this_00->commands + 1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this_01 = this->triggers;
  iVar1 = 3;
  do {
    AIPlayPhaseTrigger::AIPlayPhaseTrigger(this_01);
    this_01 = this_01 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  initialize(this);
  return this;
}

// --------------------------------------------------

// Function: command
// Address: 0040f110
AIPlayPhaseCommand * __thiscall AIPlayPhase::command(AIPlayPhase *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 5)) {
    return this->commands + param_1;
  }
  return (AIPlayPhaseCommand *)0x0;
}

// --------------------------------------------------

// Function: trigger
// Address: 0040f130
AIPlayPhaseTrigger * __thiscall AIPlayPhase::trigger(AIPlayPhase *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 3)) {
    return this->triggers + param_1;
  }
  return (AIPlayPhaseTrigger *)0x0;
}

// --------------------------------------------------

// Function: addCommand
// Address: 0040f150
int __thiscall AIPlayPhase::addCommand(AIPlayPhase *this,AIPlayPhaseCommand *param_1)
{
  int iVar1;
  AIPlayPhaseCommand *pAVar2;
  uchar *puVar3;
  
  iVar1 = 0;
  puVar3 = &this->commands[0].typeValue;
  do {
    if (*puVar3 == '\0') {
      pAVar2 = this->commands + iVar1;
      pAVar2->groupValue = param_1->groupValue;
      pAVar2->typeValue = param_1->typeValue;
      pAVar2->value1Value = param_1->value1Value;
      pAVar2->value2Value = param_1->value2Value;
      pAVar2->value3Value = param_1->value3Value;
      return 1;
    }
    iVar1 = iVar1 + 1;
    puVar3 = puVar3 + 0x10;
  } while (iVar1 < 5);
  return 0;
}

// --------------------------------------------------

// Function: addTrigger
// Address: 0040f1a0
int __thiscall AIPlayPhase::addTrigger(AIPlayPhase *this,AIPlayPhaseTrigger *param_1)
{
  int iVar1;
  AIPlayPhaseTrigger *pAVar2;
  
  iVar1 = 0;
  pAVar2 = this->triggers;
  do {
    if (pAVar2->typeValue == '\0') {
      this->triggers[iVar1].typeValue = param_1->typeValue;
      this->triggers[iVar1].value1Value = param_1->value1Value;
      this->triggers[iVar1].value2Value = param_1->value2Value;
      this->triggers[iVar1].phaseValue = param_1->phaseValue;
      this->triggers[iVar1].nextPhaseValue = param_1->nextPhaseValue;
      this->triggers[iVar1].randomnessValue = param_1->randomnessValue;
      return 1;
    }
    iVar1 = iVar1 + 1;
    pAVar2 = pAVar2 + 1;
  } while (iVar1 < 3);
  return 0;
}

// --------------------------------------------------

// Function: initialize
// Address: 0040f200
void __thiscall AIPlayPhase::initialize(AIPlayPhase *this)
{
  uchar *puVar1;
  AIPlayPhaseTrigger *pAVar2;
  int iVar3;
  
  puVar1 = &this->commands[0].typeValue;
  iVar3 = 5;
  do {
    *puVar1 = '\0';
    puVar1 = puVar1 + 0x10;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pAVar2 = this->triggers;
  iVar3 = 3;
  do {
    pAVar2->typeValue = '\0';
    pAVar2 = pAVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// --------------------------------------------------

