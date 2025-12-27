// Class: RGE_Communications_Queue
// Function: RGE_Communications_Queue
// Address: 00431720
/* public: __thiscall RGE_Communications_Queue::RGE_Communications_Queue(int) */

RGE_Communications_Queue * __thiscall
RGE_Communications_Queue::RGE_Communications_Queue(RGE_Communications_Queue *this,int param_1)
{
  if (param_1 < 0x14) {
    param_1 = 0x14;
  }
  this->QueueDepth = 0;
  this->HighQueueDepth = 0;
  this->LastCurrentTurn = 0;
  this->Queue = (MsgQueue *)0x0;
  this->MaxQSize = param_1;
  this->Sequence = '\x01';
  AllocateQueue(this,param_1);
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Communications_Queue
// Address: 00431760
/* public: __thiscall RGE_Communications_Queue::~RGE_Communications_Queue(void) */

void __thiscall RGE_Communications_Queue::~RGE_Communications_Queue(RGE_Communications_Queue *this)
{
  MsgQueue *pMVar1;
  
  pMVar1 = this->Queue;
  if (pMVar1 != (MsgQueue *)0x0) {
    _eh_vector_destructor_iterator_(pMVar1,0x1c,pMVar1[-1].ControlCommand,MsgQueue::~MsgQueue);
    operator_delete(&pMVar1[-1].ControlCommand);
  }
  return;
}

// --------------------------------------------------

// Function: AllocateQueue
// Address: 00431810
/* protected: int __thiscall RGE_Communications_Queue::AllocateQueue(unsigned int) */

int __thiscall RGE_Communications_Queue::AllocateQueue(RGE_Communications_Queue *this,uint param_1)
{
  undefined1 *puVar1;
  MsgQueue *pMVar2;
  ulong *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined4 *unaff_FS_OFFSET;
  uint i;
  uint local_1c;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cedb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 < this->MaxQSize) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_1 + 1;
    piVar5 = (int *)operator_new(iVar4 * 0x1c + 4);
    local_4 = 0;
    if (piVar5 == (int *)0x0) {
      i = 0;
    }
    else {
      i = (uint)(piVar5 + 1);
      *piVar5 = iVar4;
      _eh_vector_constructor_iterator_((void *)i,0x1c,iVar4,MsgQueue::MsgQueue,MsgQueue::~MsgQueue);
    }
    local_4 = 0xffffffff;
    if (i == 0) {
      iVar4 = 0;
    }
    else {
      if (this->Queue != (MsgQueue *)0x0) {
        local_1c = 0;
        puVar9 = (undefined1 *)(i + 8);
        do {
          puVar1 = puVar9 + (-8 - i);
          if (*(int *)(puVar1 + 0x14 + (int)this->Queue) != 0) {
            *(undefined4 *)(puVar9 + -8) = 0;
            *(undefined4 *)(puVar9 + -4) = 0;
            *puVar9 = 0;
            *(undefined4 *)(puVar9 + 8) = 0;
            *(undefined4 *)(puVar9 + 0xc) = 0;
            *(undefined4 *)(puVar9 + 0x10) = 0;
            *(undefined4 *)(puVar9 + -8) = *(undefined4 *)(puVar1 + (int)this->Queue);
            *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(puVar1 + 4 + (int)this->Queue);
            *puVar9 = (puVar1 + 8)[(int)this->Queue];
            puVar3 = &this->Queue->Code;
            uVar8 = *(uint *)(puVar1 + (int)(puVar3 + 5));
            puVar10 = *(undefined4 **)(puVar1 + (int)(puVar3 + 3));
            puVar6 = (undefined4 *)operator_new(uVar8 + 1);
            *(undefined4 **)(puVar9 + 4) = puVar6;
            if (puVar6 != (undefined4 *)0x0) {
              for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar6 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar6 = puVar6 + 1;
              }
              for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined1 *)puVar6 = *(undefined1 *)puVar10;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
                puVar6 = (undefined4 *)((int)puVar6 + 1);
              }
            }
            *(undefined4 *)(puVar9 + 8) = *(undefined4 *)(puVar1 + 0x10 + (int)this->Queue);
            *(undefined4 *)(puVar9 + 0xc) = *(undefined4 *)(puVar1 + 0x14 + (int)this->Queue);
            *(undefined4 *)(puVar9 + 0x10) = *(undefined4 *)(puVar1 + 0x18 + (int)this->Queue);
          }
          local_1c = local_1c + 1;
          puVar9 = puVar9 + 0x1c;
        } while (local_1c <= this->MaxQSize);
        pMVar2 = this->Queue;
        if (pMVar2 != (MsgQueue *)0x0) {
          _eh_vector_destructor_iterator_(pMVar2,0x1c,pMVar2[-1].ControlCommand,MsgQueue::~MsgQueue)
          ;
          operator_delete(&pMVar2[-1].ControlCommand);
        }
      }
      this->MaxQSize = param_1;
      this->Queue = (MsgQueue *)i;
      iVar4 = 1;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return iVar4;
}

// --------------------------------------------------

// Function: ExpectedNextSequence
// Address: 004319e0
/* public: unsigned char __thiscall RGE_Communications_Queue::ExpectedNextSequence(unsigned
   long,unsigned int) */

uchar __thiscall
RGE_Communications_Queue::ExpectedNextSequence
          (RGE_Communications_Queue *this,ulong param_1,uint param_2)
{
  MsgQueue *pMVar1;
  int iVar2;
  uchar uVar3;
  uint uVar4;
  
  uVar3 = '\x01';
  uVar4 = 0;
  DAT_0062cf40._0_1_ = '\x01';
  iVar2 = 0;
  do {
    pMVar1 = this->Queue;
    if (((*(ulong *)((int)&pMVar1->ExecTurn + iVar2) == param_1) &&
        (*(uint *)((int)&pMVar1->From + iVar2) == param_2)) &&
       (*(int *)((int)&pMVar1->Size + iVar2) != 0)) {
      uVar3 = uVar3 + '\x01';
      DAT_0062cf40._0_1_ = uVar3;
    }
    uVar4 = uVar4 + 1;
    iVar2 = iVar2 + 0x1c;
  } while (uVar4 <= this->HighQueueDepth);
  return (uchar)DAT_0062cf40;
}

// --------------------------------------------------

// Function: QueuedForTurn
// Address: 00431a40
/* protected: unsigned int __thiscall RGE_Communications_Queue::QueuedForTurn(unsigned long) */

uint __thiscall
RGE_Communications_Queue::QueuedForTurn(RGE_Communications_Queue *this,ulong param_1)
{
  uint uVar1;
  int iVar2;
  ulong *puVar3;
  
  uVar1 = 0;
  puVar3 = &this->Queue->ExecTurn;
  iVar2 = this->HighQueueDepth + 1;
  do {
    if (*puVar3 == param_1) {
      uVar1 = uVar1 + 1;
    }
    puVar3 = puVar3 + 7;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}

// --------------------------------------------------

// Function: FlushAll
// Address: 00431a70
/* public: void __thiscall RGE_Communications_Queue::FlushAll(void) */

void __thiscall RGE_Communications_Queue::FlushAll(RGE_Communications_Queue *this)
{
  FlushTurnRange(this,0,0);
  return;
}

// --------------------------------------------------

// Function: FlushTurnRange
// Address: 00431a80
/* WARNING: Variable defined which should be unmapped: Count */
/* public: unsigned int __thiscall RGE_Communications_Queue::FlushTurnRange(unsigned long,unsigned
   long) */

uint __thiscall
RGE_Communications_Queue::FlushTurnRange(RGE_Communications_Queue *this,ulong param_1,ulong param_2)
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint Count;
  uint i;
  uint local_4;
  
  i = 0;
  local_4 = 0;
  iVar3 = 0;
  do {
    puVar1 = (undefined4 *)((int)&this->Queue->Code + iVar3);
    uVar2 = *(uint *)((int)&this->Queue->ExecTurn + iVar3);
    if ((((param_1 <= uVar2) && (uVar2 <= param_2)) || ((param_1 == 0 && (param_2 == 0)))) &&
       (i = i + 1, puVar1[5] != 0)) {
      *puVar1 = 0;
      puVar1[1] = 0;
      *(undefined1 *)(puVar1 + 2) = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      if ((void *)puVar1[3] != (void *)0x0) {
        operator_delete((void *)puVar1[3]);
      }
      puVar1[3] = 0;
    }
    local_4 = local_4 + 1;
    iVar3 = iVar3 + 0x1c;
  } while (local_4 <= this->HighQueueDepth);
  return i;
}

// --------------------------------------------------

// Function: FlushForPlayer
// Address: 00431b10
// [HELPER] s_Flushing_queue_for_player__d: "Flushing queue for player %d"
// [HELPER] s_Remove_Q___d_Seq__d_ToExecute__l: "Remove Q #%d Seq=%d ToExecute %ld From P#%d Size=%d Code=%d Ctrl=%d "
/* WARNING: Variable defined which should be unmapped: i */
/* public: void __thiscall RGE_Communications_Queue::FlushForPlayer(unsigned int) */

void __thiscall
RGE_Communications_Queue::FlushForPlayer(RGE_Communications_Queue *this,uint param_1)
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint i;
  uint local_4;
  
  TDebuggingLog::Log(L,(char *)L,s_Flushing_queue_for_player__d,param_1);
  local_4 = 0;
  iVar3 = 0;
  do {
    uVar1 = *(uint *)((int)&this->Queue->From + iVar3);
    puVar2 = (undefined4 *)((int)&this->Queue->Code + iVar3);
    if ((uVar1 == param_1) && (puVar2[5] != 0)) {
      TDebuggingLog::Log(L,(char *)L,s_Remove_Q___d_Seq__d_ToExecute__l,local_4,
                         (uint)*(byte *)(puVar2 + 2),puVar2[1],uVar1,puVar2[5],puVar2[6],*puVar2);
      puVar2 = (undefined4 *)((int)&this->Queue->Code + iVar3);
      *puVar2 = 0;
      puVar2[1] = 0;
      *(undefined1 *)(puVar2 + 2) = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      if ((void *)puVar2[3] != (void *)0x0) {
        operator_delete((void *)puVar2[3]);
      }
      puVar2[3] = 0;
    }
    local_4 = local_4 + 1;
    iVar3 = iVar3 + 0x1c;
  } while (local_4 <= this->HighQueueDepth);
  return;
}

// --------------------------------------------------

// Function: FlushForTurn
// Address: 00431bd0
/* public: unsigned int __thiscall RGE_Communications_Queue::FlushForTurn(unsigned long) */

uint __thiscall RGE_Communications_Queue::FlushForTurn(RGE_Communications_Queue *this,ulong param_1)
{
  uint uVar1;
  
  uVar1 = FlushTurnRange(this,param_1,param_1);
  return uVar1;
}

// --------------------------------------------------

// Function: FlushThruTurn
// Address: 00431be0
/* public: unsigned int __thiscall RGE_Communications_Queue::FlushThruTurn(unsigned long) */

uint __thiscall
RGE_Communications_Queue::FlushThruTurn(RGE_Communications_Queue *this,ulong param_1)
{
  uint uVar1;
  
  uVar1 = FlushTurnRange(this,0,param_1);
  return uVar1;
}

// --------------------------------------------------

// Function: AddItem
// Address: 00431bf0
/* WARNING: Variable defined which should be unmapped: i */
/* public: int __thiscall RGE_Communications_Queue::AddItem(unsigned long,void *,unsigned
   long,unsigned int,unsigned char,int) */

int __thiscall
RGE_Communications_Queue::AddItem
          (RGE_Communications_Queue *this,ulong param_1,void *param_2,ulong param_3,uint param_4,
          uchar param_5,int param_6)
{
  int *piVar1;
  MsgQueue *pMVar2;
  uint *puVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint i;
  uint local_4;
  
  uVar6 = 0;
  local_4 = 0;
  puVar3 = &this->Queue->Size;
  if (*puVar3 != 0) {
    do {
      local_4 = uVar6;
      if (this->MaxQSize <= uVar6) break;
      piVar1 = (int *)(puVar3 + 7);
      puVar3 = puVar3 + 7;
      uVar6 = uVar6 + 1;
      local_4 = uVar6;
    } while (*piVar1 != 0);
  }
  if (this->MaxQSize <= local_4) {
    iVar4 = AllocateQueue(this,this->MaxQSize + 0x14);
    if (iVar4 == 0) {
      return 0;
    }
    local_4 = local_4 + 1;
  }
  uVar6 = this->HighQueueDepth;
  if (this->HighQueueDepth < local_4) {
    uVar6 = local_4;
  }
  pMVar2 = this->Queue;
  this->HighQueueDepth = uVar6;
  pcVar5 = (char *)operator_new(param_3 + 1);
  pMVar2[local_4].msgptr = pcVar5;
  if (pcVar5 != (char *)0x0) {
                    /* WARNING: Load size is inaccurate */
    for (uVar6 = param_3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar5 = *param_2;
      param_2 = (char *)((int)param_2 + 4);
      pcVar5 = pcVar5 + 4;
    }
                    /* WARNING: Load size is inaccurate */
    for (uVar6 = param_3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *param_2;
      param_2 = (char *)((int)param_2 + 1);
      pcVar5 = pcVar5 + 1;
    }
  }
  this->Queue[local_4].Size = param_3;
  this->Queue[local_4].SeqNo = param_5;
  this->Queue[local_4].ExecTurn = param_1;
  this->Queue[local_4].From = param_4;
  this->Queue[local_4].Code = (uint)param_5 + param_4 * 1000;
  this->Queue[local_4].ControlCommand = param_6;
  this->QueueDepth = local_4;
  return 1;
}

// --------------------------------------------------

// Function: GetQueueDepth
// Address: 00431d10
/* public: unsigned int __thiscall RGE_Communications_Queue::GetQueueDepth(void) */

uint __thiscall RGE_Communications_Queue::GetQueueDepth(RGE_Communications_Queue *this)
{
  return this->QueueDepth;
}

// --------------------------------------------------

// Function: GetHighQueueDepth
// Address: 00431d20
/* public: unsigned int __thiscall RGE_Communications_Queue::GetHighQueueDepth(void) */

uint __thiscall RGE_Communications_Queue::GetHighQueueDepth(RGE_Communications_Queue *this)
{
  return this->HighQueueDepth;
}

// --------------------------------------------------

// Function: GetSpecificItem
// Address: 00431d30
/* public: void * __thiscall RGE_Communications_Queue::GetSpecificItem(unsigned int,unsigned
   long,unsigned char,unsigned int *) */

void * __thiscall
RGE_Communications_Queue::GetSpecificItem
          (RGE_Communications_Queue *this,uint param_1,ulong param_2,uchar param_3,uint *param_4)
{
  MsgQueue *pMVar1;
  uint uVar2;
  
  uVar2 = 0;
  pMVar1 = this->Queue;
  while ((pMVar1->Code != (uint)param_3 + param_1 * 1000 || (pMVar1->ExecTurn != param_2))) {
    uVar2 = uVar2 + 1;
    pMVar1 = pMVar1 + 1;
    if (this->HighQueueDepth < uVar2) {
      return (void *)0x0;
    }
  }
  *param_4 = this->Queue[uVar2].Size;
  DAT_0062cf3c = this->Queue[uVar2].msgptr;
  this->Queue[uVar2].msgptr = (char *)0x0;
  pMVar1 = this->Queue + uVar2;
  pMVar1->Code = 0;
  pMVar1->ExecTurn = 0;
  pMVar1->SeqNo = '\0';
  pMVar1->From = 0;
  pMVar1->Size = 0;
  pMVar1->ControlCommand = 0;
  return DAT_0062cf3c;
}

// --------------------------------------------------

// Function: GetNextItemSingle
// Address: 00431dd0
/* public: void * __thiscall RGE_Communications_Queue::GetNextItemSingle(void) */

void * __thiscall RGE_Communications_Queue::GetNextItemSingle(RGE_Communications_Queue *this)
{
  uint uVar1;
  MsgQueue *pMVar2;
  uint *puVar3;
  
  uVar1 = 0;
  puVar3 = &this->Queue->Size;
  do {
    if (*puVar3 != 0) {
      DAT_0062cf34 = this->Queue[uVar1].msgptr;
      pMVar2 = this->Queue + uVar1;
      pMVar2->Code = 0;
      pMVar2->ExecTurn = 0;
      pMVar2->SeqNo = '\0';
      pMVar2->From = 0;
      pMVar2->Size = 0;
      pMVar2->ControlCommand = 0;
      this->Queue[uVar1].msgptr = (char *)0x0;
      return DAT_0062cf34;
    }
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 7;
  } while (uVar1 <= this->HighQueueDepth);
  return (void *)0x0;
}

// --------------------------------------------------

// Function: GetNextItemOrdered
// Address: 00431e40
/* WARNING: Variable defined which should be unmapped: SendMsg */
/* public: void * __thiscall RGE_Communications_Queue::GetNextItemOrdered(unsigned long) */

void * __thiscall
RGE_Communications_Queue::GetNextItemOrdered(RGE_Communications_Queue *this,ulong param_1)
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  MsgQueue *pMVar5;
  int iVar6;
  int SendMsg;
  uint local_4;
  
  uVar3 = 0xffffffff;
  uVar4 = 0;
  local_4 = 0xffffffff;
  iVar6 = 0;
  do {
    piVar2 = (int *)((int)&this->Queue->Code + iVar6);
    if ((*piVar2 != 0) && (piVar2[5] != 0)) {
      if ((uint)piVar2[1] < param_1) {
        TestShowQueue(this);
      }
      uVar1 = *(uint *)((int)&this->Queue->Code + iVar6);
      if ((uVar1 < uVar3) && (*(ulong *)((int)&this->Queue->ExecTurn + iVar6) == param_1)) {
        uVar3 = uVar1;
        local_4 = uVar4;
      }
    }
    uVar4 = uVar4 + 1;
    iVar6 = iVar6 + 0x1c;
  } while (uVar4 <= this->HighQueueDepth);
  if (local_4 == 0xffffffff) {
    return (void *)0x0;
  }
  DAT_0062cf38 = this->Queue[local_4].msgptr;
  this->Queue[local_4].msgptr = (char *)0x0;
  pMVar5 = this->Queue + local_4;
  pMVar5->Code = 0;
  pMVar5->ExecTurn = 0;
  pMVar5->SeqNo = '\0';
  pMVar5->From = 0;
  pMVar5->Size = 0;
  pMVar5->ControlCommand = 0;
  return DAT_0062cf38;
}

// --------------------------------------------------

// Function: GetNextSequence
// Address: 00431f10
/* public: unsigned char __thiscall RGE_Communications_Queue::GetNextSequence(unsigned long) */

uchar __thiscall
RGE_Communications_Queue::GetNextSequence(RGE_Communications_Queue *this,ulong param_1)
{
  byte bVar1;
  
  if (param_1 != this->LastCurrentTurn) {
    this->LastCurrentTurn = param_1;
    this->Sequence = '\x01';
    return '\x01';
  }
  bVar1 = this->Sequence + 1;
  this->Sequence = bVar1;
  return -(bVar1 != 0xff) & bVar1;
}

// --------------------------------------------------

// Function: TestShowQueue
// Address: 00431f50
/* public: void __thiscall RGE_Communications_Queue::TestShowQueue(void) */

void __thiscall RGE_Communications_Queue::TestShowQueue(RGE_Communications_Queue *this)
{
  return;
}

// --------------------------------------------------

