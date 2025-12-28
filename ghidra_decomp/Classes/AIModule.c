// Class: AIModule
// Size:  0xF0
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
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
//
// Member Layout:
// [0x004] AIModuleID idValue (sz: 0x48)
// [0x04C] int playerNumberValue
// [0x050] char[64] playerNameValue (sz: 0x40)
// [0x090] int runningValue
// [0x094] int pausedValue
// [0x098] int logHistoryValue
// [0x09C] int logCommonHistoryValue
// [0x0A0] _iobuf * historyLogFile
// [0x0A4] char[64] historyLogFilename (sz: 0x40)
// [0x0E4] int intelligenceLevelValue
// [0x0E8] int priorityValue
// [0x0EC] int processFrameValue
// ----------------------------------------------------------------

// Function: loadState
// Address: 004087f0
int __thiscall AIModule::loadState(AIModule *this,char *param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: saveState
// Address: 00408800
int __thiscall AIModule::saveState(AIModule *this,char *param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: gleanState
// Address: 00408810
int __thiscall AIModule::gleanState(AIModule *this,int param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: AIModule
// Address: 0040e220
// [HELPER] s_: ""
// [HELPER] s_Unknown: "Unknown"
AIModule * __thiscall AIModule::AIModule(AIModule *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  AIModuleID::AIModuleID(&this->idValue,s_,-1);
  uVar2 = 0xffffffff;
  this->playerNumberValue = -1;
  this->runningValue = 0;
  this->pausedValue = 0;
  this->logHistoryValue = 0;
  this->logCommonHistoryValue = 0;
  this->historyLogFile = (_iobuf *)0x0;
  this->intelligenceLevelValue = 5;
  this->priorityValue = 0x32;
  this->processFrameValue = 0;
  this->_padding_ = (int)&_vftable_;
  pcVar4 = &s_Unknown;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = this->playerNameValue;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0040e2b0
void * __thiscall AIModule::_scalar_deleting_destructor_(AIModule *this,uint param_1)
{
  ~AIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: AIModule
// Address: 0040e2d0
// [HELPER] s_Unknown: "Unknown"
AIModule * __thiscall
AIModule::AIModule(AIModule *this,char *param_1,int param_2,int param_3,void *param_4)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  AIModuleID::AIModuleID(&this->idValue,param_1,param_2);
  uVar2 = 0xffffffff;
  this->playerNumberValue = param_3;
  this->runningValue = 0;
  this->pausedValue = 0;
  this->logHistoryValue = 0;
  this->logCommonHistoryValue = 0;
  this->historyLogFile = (_iobuf *)0x0;
  this->intelligenceLevelValue = 5;
  this->priorityValue = 0x32;
  this->processFrameValue = 0;
  this->_padding_ = (int)&_vftable_;
  pcVar4 = &s_Unknown;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = this->playerNameValue;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: ~AIModule
// Address: 0040e360
void __thiscall AIModule::~AIModule(AIModule *this)
{
  this->_padding_ = (int)&_vftable_;
  if ((this->logCommonHistoryValue != 0) && (commonHistoryLogFile != (_iobuf *)0x0)) {
    fclose(commonHistoryLogFile);
    commonHistoryLogFile = (_iobuf *)0x0;
  }
  AIModuleID::~AIModuleID(&this->idValue);
  return;
}

// --------------------------------------------------

// Function: id
// Address: 0040e3a0
AIModuleID * __thiscall AIModule::id(AIModule *this,AIModuleID *__return_storage_ptr__)
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  <NoType> ___ReturnUdt;
  
  __return_storage_ptr__->id = (this->idValue).id;
  pcVar2 = (this->idValue).name;
  pcVar3 = __return_storage_ptr__->name;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar3 = pcVar3 + 4;
  }
  __return_storage_ptr__->_padding_ = (int)&AIModuleID::_vftable_;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: idNumber
// Address: 0040e3d0
int __thiscall AIModule::idNumber(AIModule *this)
{
  return (this->idValue).id;
}

// --------------------------------------------------

// Function: playerNumber
// Address: 0040e3e0
int __thiscall AIModule::playerNumber(AIModule *this)
{
  return this->playerNumberValue;
}

// --------------------------------------------------

// Function: playerName
// Address: 0040e3f0
char * __thiscall AIModule::playerName(AIModule *this)
{
  return this->playerNameValue;
}

// --------------------------------------------------

// Function: setPlayer
// Address: 0040e400
// [HELPER] s_Unknown: "Unknown"
void __thiscall AIModule::setPlayer(AIModule *this,int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  this->playerNumberValue = param_1;
  if (param_2 != (char *)0x0) {
    strncpy(this->playerNameValue,param_2,0x3f);
    return;
  }
  uVar2 = 0xffffffff;
  pcVar4 = &s_Unknown;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = this->playerNameValue;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: start
// Address: 0040e450
void __thiscall AIModule::start(AIModule *this)
{
  this->runningValue = 1;
  return;
}

// --------------------------------------------------

// Function: stop
// Address: 0040e460
void __thiscall AIModule::stop(AIModule *this)
{
  this->runningValue = 0;
  return;
}

// --------------------------------------------------

// Function: toggleRun
// Address: 0040e470
void __thiscall AIModule::toggleRun(AIModule *this)
{
  this->runningValue = (uint)(this->runningValue == 0);
  return;
}

// --------------------------------------------------

// Function: togglePause
// Address: 0040e490
void __thiscall AIModule::togglePause(AIModule *this)
{
  this->pausedValue = (uint)(this->pausedValue == 0);
  return;
}

// --------------------------------------------------

// Function: step
// Address: 0040e4b0
void __thiscall AIModule::step(AIModule *this)
{
  return;
}

// --------------------------------------------------

// Function: running
// Address: 0040e4c0
int __thiscall AIModule::running(AIModule *this)
{
  return this->runningValue;
}

// --------------------------------------------------

// Function: paused
// Address: 0040e4d0
int __thiscall AIModule::paused(AIModule *this)
{
  return this->pausedValue;
}

// --------------------------------------------------

// Function: loggingHistory
// Address: 0040e4e0
int __thiscall AIModule::loggingHistory(AIModule *this)
{
  return this->logHistoryValue;
}

// --------------------------------------------------

// Function: setLogHistory
// Address: 0040e4f0
void __thiscall AIModule::setLogHistory(AIModule *this,int param_1)
{
  return;
}

// --------------------------------------------------

// Function: toggleLogHistory
// Address: 0040e500
void __thiscall AIModule::toggleLogHistory(AIModule *this)
{
  return;
}

// --------------------------------------------------

// Function: loggingCommonHistory
// Address: 0040e510
int __thiscall AIModule::loggingCommonHistory(AIModule *this)
{
  return this->logCommonHistoryValue;
}

// --------------------------------------------------

// Function: setLogCommonHistory
// Address: 0040e520
// [HELPER] s_: ""
// [HELPER] s_Common_AI_History_File_Started__: "Common AI History File Started %s"
// [HELPER] s_c__aoeai_txt: "c:\aoeai.txt"
// [HELPER] s_wa: "wa"
void __thiscall AIModule::setLogCommonHistory(AIModule *this,int param_1)
{
  undefined4 uVar1;
  AIModule *this_00;
  AIModule *this_01;
  
  this->logCommonHistoryValue = param_1;
  if ((param_1 != 0) && (commonHistoryLogFile == (_iobuf *)0x0)) {
    commonHistoryLogFile = (_iobuf *)fopen(s_c__aoeai_txt,s_wa);
    time(&param_1);
    uVar1 = localtime(&param_1);
    uVar1 = asctime(uVar1);
    logCommonHistory(this_00,(char *)this,s_Common_AI_History_File_Started__,uVar1);
    logCommonHistory(this_01,(char *)this,s_);
    return;
  }
  if ((param_1 == 0) && (commonHistoryLogFile != (_iobuf *)0x0)) {
    fclose(commonHistoryLogFile);
    commonHistoryLogFile = (_iobuf *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: toggleLogCommonHistory
// Address: 0040e5c0
void __thiscall AIModule::toggleLogCommonHistory(AIModule *this)
{
  return;
}

// --------------------------------------------------

// Function: setHistoryFilename
// Address: 0040e5d0
void __thiscall AIModule::setHistoryFilename(AIModule *this,char *param_1)
{
  return;
}

// --------------------------------------------------

// Function: intelligenceLevel
// Address: 0040e5e0
int __thiscall AIModule::intelligenceLevel(AIModule *this)
{
  return this->intelligenceLevelValue;
}

// --------------------------------------------------

// Function: setIntelligenceLevel
// Address: 0040e5f0
int __thiscall AIModule::setIntelligenceLevel(AIModule *this,int param_1)
{
  this->intelligenceLevelValue = param_1;
  if (param_1 < 1) {
    this->intelligenceLevelValue = 1;
    return 0;
  }
  if (10 < param_1) {
    this->intelligenceLevelValue = 10;
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: priority
// Address: 0040e630
int __thiscall AIModule::priority(AIModule *this)
{
  return this->priorityValue;
}

// --------------------------------------------------

// Function: setPriority
// Address: 0040e640
int __thiscall AIModule::setPriority(AIModule *this,int param_1)
{
  this->priorityValue = param_1;
  if (param_1 < 1) {
    this->priorityValue = 1;
    return 0;
  }
  if (100 < param_1) {
    this->priorityValue = 100;
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: incrementPriority
// Address: 0040e680
int __thiscall AIModule::incrementPriority(AIModule *this,int param_1)
{
  int iVar1;
  
  iVar1 = setPriority(this,this->priorityValue + param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: decrementPriority
// Address: 0040e6a0
int __thiscall AIModule::decrementPriority(AIModule *this,int param_1)
{
  int iVar1;
  
  iVar1 = setPriority(this,this->priorityValue - param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: sendMessage
// Address: 0040e6c0
int __thiscall AIModule::sendMessage(AIModule *this,AIModuleMessage *param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: receiveMessage
// Address: 0040e6d0
void __thiscall AIModule::receiveMessage(AIModule *this,AIModuleMessage *param_1)
{
  return;
}

// --------------------------------------------------

// Function: processMessage
// Address: 0040e6e0
int __thiscall AIModule::processMessage(AIModule *this,AIModuleMessage *param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: update
// Address: 0040e6f0
int __thiscall AIModule::update(AIModule *this,int param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: setCallbackMessage
// Address: 0040e700
void __thiscall AIModule::setCallbackMessage(AIModule *this,AIModuleMessage *param_1)
{
  return;
}

// --------------------------------------------------

// Function: messageLimit
// Address: 0040e710
int __thiscall AIModule::messageLimit(AIModule *this)
{
  return 0;
}

// --------------------------------------------------

// Function: setMessageLimit
// Address: 0040e720
void __thiscall AIModule::setMessageLimit(AIModule *this,int param_1)
{
  return;
}

// --------------------------------------------------

// Function: callbackLimit
// Address: 0040e730
int __thiscall AIModule::callbackLimit(AIModule *this)
{
  return 0;
}

// --------------------------------------------------

// Function: setCallbackLimit
// Address: 0040e740
void __thiscall AIModule::setCallbackLimit(AIModule *this,int param_1)
{
  return;
}

// --------------------------------------------------

// Function: messageTimeout
// Address: 0040e750
int __thiscall AIModule::messageTimeout(AIModule *this)
{
  return 0;
}

// --------------------------------------------------

// Function: setMessageTimeout
// Address: 0040e760
void __thiscall AIModule::setMessageTimeout(AIModule *this,int param_1)
{
  return;
}

// --------------------------------------------------

// Function: purgeMessages
// Address: 0040e770
int __thiscall AIModule::purgeMessages(AIModule *this,AIModuleID param_1)
{
  AIModuleID::~AIModuleID(&param_1);
  return 0;
}

// --------------------------------------------------

// Function: purgeMessagesWithID
// Address: 0040e780
int __thiscall AIModule::purgeMessagesWithID(AIModule *this,AIModuleID param_1,int param_2)
{
  AIModuleID::~AIModuleID(&param_1);
  return 0;
}

// --------------------------------------------------

// Function: purgeMessagesWithPriorityBelow
// Address: 0040e790
int __thiscall
AIModule::purgeMessagesWithPriorityBelow(AIModule *this,AIModuleID param_1,int param_2)
{
  AIModuleID::~AIModuleID(&param_1);
  return 0;
}

// --------------------------------------------------

// Function: purgeMessagesWithData
// Address: 0040e7a0
int __thiscall
AIModule::purgeMessagesWithData
          (AIModule *this,AIModuleID param_1,int param_2,int param_3,long param_4)
{
  AIModuleID::~AIModuleID(&param_1);
  return 0;
}

// --------------------------------------------------

// Function: purgeCallbacks
// Address: 0040e7b0
int __thiscall AIModule::purgeCallbacks(AIModule *this,AIModuleID param_1)
{
  AIModuleID::~AIModuleID(&param_1);
  return 0;
}

// --------------------------------------------------

// Function: purgeCallbacksWithID
// Address: 0040e7c0
int __thiscall AIModule::purgeCallbacksWithID(AIModule *this,AIModuleID param_1,int param_2)
{
  AIModuleID::~AIModuleID(&param_1);
  return 0;
}

// --------------------------------------------------

// Function: purgeCallbacksWithPriorityBelow
// Address: 0040e7d0
int __thiscall
AIModule::purgeCallbacksWithPriorityBelow(AIModule *this,AIModuleID param_1,int param_2)
{
  AIModuleID::~AIModuleID(&param_1);
  return 0;
}

// --------------------------------------------------

// Function: purgeCallbacksWithData
// Address: 0040e7e0
int __thiscall
AIModule::purgeCallbacksWithData
          (AIModule *this,AIModuleID param_1,int param_2,int param_3,long param_4)
{
  AIModuleID::~AIModuleID(&param_1);
  return 0;
}

// --------------------------------------------------

// Function: checkMessageLimit
// Address: 0040e7f0
void __thiscall AIModule::checkMessageLimit(AIModule *this)
{
  return;
}

// --------------------------------------------------

// Function: checkCallbackLimit
// Address: 0040e800
void __thiscall AIModule::checkCallbackLimit(AIModule *this)
{
  return;
}

// --------------------------------------------------

// Function: filterOutMessage
// Address: 0040e810
int __thiscall AIModule::filterOutMessage(AIModule *this,AIModuleMessage *param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: logHistory
// Address: 0040e820
void __thiscall AIModule::logHistory(AIModule *this,char *param_1,...)
{
  return;
}

// --------------------------------------------------

// Function: logCommonHistory
// Address: 0040e830
// [HELPER] s_P__d_: "P#%d\n"
// [HELPER] s_P__d__s___s_: "P#%d %s: %s\n"
void __thiscall AIModule::logCommonHistory(AIModule *this,char *param_1,...)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 in_stack_00000008;
  char textOut [1024];
  
  if (((specificAIPlayerToLog == -1) || (specificAIPlayerToLog == *(int *)(param_1 + 0x4c))) &&
     (commonHistoryLogFile != (_iobuf *)0x0)) {
    vsprintf(textOut + 4,in_stack_00000008,&stack0x0000000c);
    iVar2 = -1;
    pcVar3 = textOut + 4;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar2 == -2) {
      fprintf(commonHistoryLogFile,s_P__d_,*(undefined4 *)(param_1 + 0x4c));
    }
    else {
      fprintf(commonHistoryLogFile,s_P__d__s___s_,*(undefined4 *)(param_1 + 0x4c),param_1 + 0xc,
              textOut + 4);
    }
    fflush(commonHistoryLogFile);
  }
  return;
}

// --------------------------------------------------

// Function: logDebug
// Address: 0040e8e0
void __thiscall AIModule::logDebug(AIModule *this,char *param_1,...)
{
  return;
}

// --------------------------------------------------

// Function: processFrame
// Address: 0040e8f0
int __thiscall AIModule::processFrame(AIModule *this)
{
  return this->processFrameValue;
}

// --------------------------------------------------

// Function: incrementProcessFrame
// Address: 0040e900
void __thiscall AIModule::incrementProcessFrame(AIModule *this)
{
  int iVar1;
  
  iVar1 = this->processFrameValue + 1;
  this->processFrameValue = iVar1;
  if (iVar1 == 0x7fffffff) {
    this->processFrameValue = 0;
  }
  return;
}

// --------------------------------------------------

// Function: timeDifference
// Address: 0040e920
int __thiscall AIModule::timeDifference(AIModule *this,AIModuleMessage *param_1)
{
  return 0;
}

// --------------------------------------------------

