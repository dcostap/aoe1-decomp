// Class: AIModuleMessage
// Size:  0x138
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
// [0x004] int id
// [0x008] char[128] text (sz: 0x80)
// [0x088] int priority
// [0x08C] AIModuleID sender (sz: 0x48)
// [0x0D4] AIModuleID recipient (sz: 0x48)
// [0x11C] long data1
// [0x120] long data2
// [0x124] long data3
// [0x128] AIModuleMessage * callbackMessage
// [0x12C] int timeStamp
// [0x130] AIModuleMessage * next
// [0x134] AIModuleMessage * prev
// ----------------------------------------------------------------

// Function: AIModuleMessage
// Address: 0040de70
// [HELPER] s_: ""
// [HELPER] s_Recipient: "Recipient"
// [HELPER] s_Sender: "Sender"
AIModuleMessage * __thiscall AIModuleMessage::AIModuleMessage(AIModuleMessage *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c69e;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->id = 0;
  this->priority = 0;
  AIModuleID::AIModuleID(&this->sender,s_Sender,0);
  local_4 = 0;
  AIModuleID::AIModuleID(&this->recipient,s_Recipient,0);
  uVar2 = 0xffffffff;
  this->data1 = 0;
  this->data2 = 0;
  this->data3 = 0;
  this->callbackMessage = (AIModuleMessage *)0x0;
  this->timeStamp = 0;
  this->next = (AIModuleMessage *)0x0;
  this->prev = (AIModuleMessage *)0x0;
  this->_padding_ = (int)&_vftable_;
  pcVar4 = s_;
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
  pcVar5 = this->text;
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
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0040df30
void * __thiscall AIModuleMessage::_scalar_deleting_destructor_(AIModuleMessage *this,uint param_1)
{
  ~AIModuleMessage(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: AIModuleMessage
// Address: 0040df50
// [HELPER] s_: ""
AIModuleMessage * __thiscall
AIModuleMessage::AIModuleMessage
          (AIModuleMessage *this,int param_1,int param_2,int param_3,int param_4,long param_5,
          long param_6,long param_7,AIModuleMessage *param_8,int param_9)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c6be;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->priority = param_4;
  this->id = param_3;
  AIModuleID::AIModuleID(&this->sender,s_,param_1);
  local_4 = 0;
  AIModuleID::AIModuleID(&this->recipient,s_,param_2);
  this->data1 = param_5;
  this->data2 = param_6;
  this->data3 = param_7;
  this->callbackMessage = param_8;
  uVar2 = 0xffffffff;
  this->timeStamp = param_9;
  this->_padding_ = (int)&_vftable_;
  pcVar4 = s_;
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
  pcVar5 = this->text;
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
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: AIModuleMessage
// Address: 0040e030
AIModuleMessage * __thiscall
AIModuleMessage::AIModuleMessage(AIModuleMessage *this,AIModuleMessage *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c6ec;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->id = param_1->id;
  this->priority = param_1->priority;
  AIModuleID::AIModuleID(&this->sender,(param_1->sender).name,(param_1->sender).id);
  local_4 = 0;
  AIModuleID::AIModuleID(&this->recipient,(param_1->recipient).name,(param_1->recipient).id);
  this->data1 = param_1->data1;
  this->data2 = param_1->data2;
  this->data3 = param_1->data3;
  this->callbackMessage = param_1->callbackMessage;
  this->timeStamp = param_1->timeStamp;
  local_4 = CONCAT31(local_4._1_3_,1);
  this->next = (AIModuleMessage *)0x0;
  this->prev = (AIModuleMessage *)0x0;
  this->_padding_ = (int)&_vftable_;
  setText(this,param_1->text);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~AIModuleMessage
// Address: 0040e120
void __thiscall AIModuleMessage::~AIModuleMessage(AIModuleMessage *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_0055c71c;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 1;
  if (this->callbackMessage != (AIModuleMessage *)0x0) {
    (**(code **)this->callbackMessage->_padding_)(1);
  }
  local_4 = local_4 & 0xffffff00;
  AIModuleID::~AIModuleID(&this->recipient);
  local_4 = 0xffffffff;
  AIModuleID::~AIModuleID(&this->sender);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: setText
// Address: 0040e190
// [HELPER] s_: ""
void __thiscall AIModuleMessage::setText(AIModuleMessage *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 != (char *)0x0) {
    strncpy(this->text,param_1,0x7f);
    return;
  }
  uVar2 = 0xffffffff;
  pcVar4 = s_;
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
  pcVar5 = this->text;
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

// Function: setSender
// Address: 0040e1e0
void __thiscall AIModuleMessage::setSender(AIModuleMessage *this,int param_1,char *param_2)
{
  AIModuleID::setID(&this->sender,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: setRecipient
// Address: 0040e200
void __thiscall AIModuleMessage::setRecipient(AIModuleMessage *this,int param_1,char *param_2)
{
  AIModuleID::setID(&this->recipient,param_1,param_2);
  return;
}

// --------------------------------------------------

