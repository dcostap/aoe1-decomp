// Class: TChat
// Size:  0x100
//
// Member Layout:
// [0x000] void * HostWnd
// [0x004] int[10] chatGroupPlayers (sz: 0x28)
// [0x02C] char *[51] Chat (sz: 0xCC)
// [0x0F8] int CurrentMsgNo
// [0x0FC] TTaunt * taunt
// ----------------------------------------------------------------

// Function: TChat
// Address: 00423c30
TChat * __thiscall TChat::TChat(TChat *this,void *param_1)
{
  TTaunt *pTVar1;
  int iVar2;
  char **ppcVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cc3b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = (TTaunt *)operator_new(0x198);
  local_4 = 0;
  if (pTVar1 == (TTaunt *)0x0) {
    pTVar1 = (TTaunt *)0x0;
  }
  else {
    pTVar1 = (TTaunt *)TTaunt::TTaunt(pTVar1,rge_base_game->sound_system);
  }
  this->taunt = pTVar1;
  this->HostWnd = param_1;
  ppcVar3 = this->Chat;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppcVar3 = (char *)0x0;
    ppcVar3 = ppcVar3 + 1;
  }
  local_4 = 0xffffffff;
  this->CurrentMsgNo = 0;
  iVar2 = 0;
  do {
    setInChatGroup(this,iVar2,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TChat
// Address: 00423cd0
void __thiscall TChat::~TChat(TChat *this)
{
  TTaunt *this_00;
  
  ClearChat(this);
  this_00 = this->taunt;
  if (this_00 != (TTaunt *)0x0) {
    TTaunt::~TTaunt(this_00);
    operator_delete(this_00);
  }
  return;
}

// --------------------------------------------------

// Function: AddChatMsg
// Address: 00423d00
// [HELPER] s__s___s: "%s: %s"
int __thiscall TChat::AddChatMsg(TChat *this,char *param_1,char *param_2,uchar param_3)
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar3 = this->CurrentMsgNo + 1;
  this->CurrentMsgNo = iVar3;
  if (0x32 < iVar3) {
    this->CurrentMsgNo = 0;
  }
  if (this->Chat[this->CurrentMsgNo] != (char *)0x0) {
    free(this->Chat[this->CurrentMsgNo]);
  }
  uVar4 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar5 = 0xffffffff;
  pcVar2 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)calloc(~uVar4 + ~uVar5 + 1,1);
  this->Chat[this->CurrentMsgNo] = pcVar2;
  pcVar2 = this->Chat[this->CurrentMsgNo];
  if (pcVar2 == (char *)0x0) {
    return (int)pcVar2;
  }
  sprintf(pcVar2,s__s___s,param_1,param_2);
  PostMessageA(this->HostWnd,0x400,0x17d5,this->CurrentMsgNo);
  if (this->taunt != (TTaunt *)0x0) {
    TTaunt::PlayTauntStr(this->taunt,param_2,param_3);
  }
  return 1;
}

// --------------------------------------------------

// Function: GetChatMsg
// Address: 00423df0
char * __thiscall TChat::GetChatMsg(TChat *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x33)) {
    return this->Chat[param_1];
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: ClearChat
// Address: 00423e10
void __thiscall TChat::ClearChat(TChat *this)
{
  char **ppcVar1;
  int iVar2;
  
  ppcVar1 = this->Chat;
  iVar2 = 0x33;
  do {
    if (*ppcVar1 != (char *)0x0) {
      free(*ppcVar1);
    }
    *ppcVar1 = (char *)0x0;
    ppcVar1 = ppcVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->CurrentMsgNo = 0;
  return;
}

// --------------------------------------------------

// Function: MaxArraySize
// Address: 00423e50
int __thiscall TChat::MaxArraySize(TChat *this)
{
  return 0x32;
}

// --------------------------------------------------

// Function: setWindowHandle
// Address: 00423e60
void __thiscall TChat::setWindowHandle(TChat *this,void *param_1)
{
  this->HostWnd = param_1;
  return;
}

// --------------------------------------------------

// Function: setInChatGroup
// Address: 00423e70
void __thiscall TChat::setInChatGroup(TChat *this,int param_1,int param_2)
{
  if ((0 < param_1) && (param_1 < 10)) {
    this->chatGroupPlayers[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: inChatGroup
// Address: 00423e90
int __thiscall TChat::inChatGroup(TChat *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 10)) {
    return this->chatGroupPlayers[param_1];
  }
  return 0;
}

// --------------------------------------------------

// Function: StopSoundSystem
// Address: 00423eb0
void __thiscall TChat::StopSoundSystem(TChat *this)
{
  if (this->taunt != (TTaunt *)0x0) {
    TTaunt::StopSoundSystem(this->taunt);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: RestartSoundSystem
// Address: 00423ec0
int __thiscall TChat::RestartSoundSystem(TChat *this,TSound_Driver *param_1)
{
  int iVar1;
  
  if (this->taunt != (TTaunt *)0x0) {
    iVar1 = TTaunt::RestartSoundSystem(this->taunt,param_1);
    return iVar1;
  }
  return 1;
}

// --------------------------------------------------

