// Class: RGE_Communications_Speed
// Size:  0x240
//
// Member Layout:
// [0x000] char[255] TBuff (sz: 0xFF)
// [0x100] RGE_TimeSinceLastCall * TurnTSLC
// [0x104] RGE_TimeSinceLastCall * FrameTSLC
// [0x108] TCommunications_Handler * Comm
// [0x110] double AccumDiff (sz: 0x8)
// [0x118] int SpeedControlEnabled
// [0x11C] uint CurrentBufferFrames
// [0x120] uint FutureBufferFrames
// [0x124] uint TotalBufferFramesRemaining
// [0x128] uint TargetTurnLengthMsec
// [0x12C] uint CurrentBufferGranularity
// [0x130] uint FutureBufferGranularity
// [0x134] uint OverheadFactor
// [0x138] ulong TimeSinceLastBuffer
// [0x13C] ulong FutureSpeedChangeTurn
// [0x140] ulong NextLatencyChangeTurn
// [0x144] uint[10] ActualLatency (sz: 0x28)
// [0x16C] uint[10] AverageTSLC (sz: 0x28)
// [0x194] uchar[10] PlayerOptimalFrames (sz: 0xA)
// [0x19E] uchar[10] PlayerOptimalGranularity (sz: 0xA)
// [0x1A8] ushort[10] RequestFasterOrSlower (sz: 0x14)
// [0x1BC] ulong[10] PlayerAvgFramesMsec (sz: 0x28)
// [0x1E4] ulong[10] PlayerHighLatencyMsec (sz: 0x28)
// [0x20C] ulong HighestLatencyMsec
// [0x210] uint SkipFrames
// [0x214] uint OptimalBufferFrames
// [0x218] uint OptimalBufferGranularity
// [0x21C] uint DiffOffset
// [0x220] uint AllAcknowledgedBuffersRemaining
// [0x224] uint LastAdjusted
// [0x228] ulong RealTimePassed
// [0x22C] ulong BufferTimePassed
// [0x230] uint DroppedFrames
// [0x234] uint DroppedFramesTurn
// [0x238] ulong AdjustmentCount
// [0x23C] int LastFrameHadTime
// ----------------------------------------------------------------

// Function: RGE_Communications_Speed
// Address: 00432620
/* public: __thiscall RGE_Communications_Speed::RGE_Communications_Speed(class
   TCommunications_Handler *) */

RGE_Communications_Speed * __thiscall
RGE_Communications_Speed::RGE_Communications_Speed
          (RGE_Communications_Speed *this,TCommunications_Handler *param_1)
{
  uint *puVar1;
  RGE_TimeSinceLastCall *pRVar2;
  ushort *puVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cf06;
  *unaff_FS_OFFSET = &local_c;
  iVar4 = 10;
  this->Comm = param_1;
  this->CurrentBufferGranularity = 0x5a;
  this->OptimalBufferGranularity = 0x5a;
  this->CurrentBufferFrames = 10;
  this->OptimalBufferFrames = 10;
  this->SpeedControlEnabled = 1;
  this->OverheadFactor = 0;
  this->LastAdjusted = 0;
  this->AdjustmentCount = 0;
  this->LastFrameHadTime = 0;
  this->TotalBufferFramesRemaining = 0;
  this->TimeSinceLastBuffer = 0;
  this->TargetTurnLengthMsec = 500;
  this->RealTimePassed = 0;
  this->BufferTimePassed = 0;
  this->DroppedFrames = 0;
  this->DroppedFramesTurn = 0;
  this->NextLatencyChangeTurn = 0;
  this->FutureBufferFrames = 0;
  this->FutureBufferGranularity = 0;
  puVar3 = this->RequestFasterOrSlower;
  puVar1 = this->AverageTSLC;
  do {
    puVar1[-10] = 0x1e;
    *puVar1 = 0;
    *puVar3 = 0;
    puVar1[0x14] = 0;
    puVar1[0x1e] = 0;
    puVar3 = puVar3 + 1;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  this->HighestLatencyMsec = 500;
  pRVar2 = (RGE_TimeSinceLastCall *)operator_new(0x2b4);
  local_4 = 0;
  if (pRVar2 == (RGE_TimeSinceLastCall *)0x0) {
    pRVar2 = (RGE_TimeSinceLastCall *)0x0;
  }
  else {
    pRVar2 = (RGE_TimeSinceLastCall *)RGE_TimeSinceLastCall::RGE_TimeSinceLastCall(pRVar2);
  }
  local_4 = 0xffffffff;
  this->FrameTSLC = pRVar2;
  pRVar2 = (RGE_TimeSinceLastCall *)operator_new(0x2b4);
  local_4 = 1;
  if (pRVar2 == (RGE_TimeSinceLastCall *)0x0) {
    pRVar2 = (RGE_TimeSinceLastCall *)0x0;
  }
  else {
    pRVar2 = (RGE_TimeSinceLastCall *)RGE_TimeSinceLastCall::RGE_TimeSinceLastCall(pRVar2);
  }
  this->TurnTSLC = pRVar2;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Communications_Speed
// Address: 00432780
/* public: __thiscall RGE_Communications_Speed::~RGE_Communications_Speed(void) */

void __thiscall RGE_Communications_Speed::~RGE_Communications_Speed(RGE_Communications_Speed *this)
{
  RGE_TimeSinceLastCall *pRVar1;
  
  pRVar1 = this->FrameTSLC;
  if (pRVar1 != (RGE_TimeSinceLastCall *)0x0) {
    RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = this->TurnTSLC;
  if (pRVar1 != (RGE_TimeSinceLastCall *)0x0) {
    RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall(pRVar1);
    operator_delete(pRVar1);
  }
  return;
}

// --------------------------------------------------

// Function: SetPlayerTurnSpeed
// Address: 004327c0
/* public: void __thiscall RGE_Communications_Speed::SetPlayerTurnSpeed(unsigned int,unsigned
   char,unsigned char) */

void __thiscall
RGE_Communications_Speed::SetPlayerTurnSpeed
          (RGE_Communications_Speed *this,uint param_1,uchar param_2,uchar param_3)
{
  if ((param_1 != 0) && (param_1 < 10)) {
    this->PlayerAvgFramesMsec[param_1] = (uint)param_2;
    this->PlayerHighLatencyMsec[param_1] = (uint)param_3 * 10;
  }
  return;
}

// --------------------------------------------------

// Function: SetActualLatency
// Address: 00432800
/* public: void __thiscall RGE_Communications_Speed::SetActualLatency(unsigned int,unsigned long) */

void __thiscall
RGE_Communications_Speed::SetActualLatency
          (RGE_Communications_Speed *this,uint param_1,ulong param_2)
{
  if ((param_1 != 0) && (param_1 < 10)) {
    if (param_2 < 0x1e) {
      param_2 = 0x1e;
    }
    if (6000 < param_2) {
      param_2 = 6000;
    }
    this->ActualLatency[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: SetFutureSpeedChange
// Address: 00432840
/* public: void __thiscall RGE_Communications_Speed::SetFutureSpeedChange(unsigned int,unsigned
   int,unsigned long) */

void __thiscall
RGE_Communications_Speed::SetFutureSpeedChange
          (RGE_Communications_Speed *this,uint param_1,uint param_2,ulong param_3)
{
  if (this->NextLatencyChangeTurn == 0) {
    this->FutureBufferFrames = param_1;
    this->FutureBufferGranularity = param_2;
    this->NextLatencyChangeTurn = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: EnableSpeedControl
// Address: 00432870
/* public: void __thiscall RGE_Communications_Speed::EnableSpeedControl(int) */

void __thiscall
RGE_Communications_Speed::EnableSpeedControl(RGE_Communications_Speed *this,int param_1)
{
  this->SpeedControlEnabled = param_1;
  return;
}

// --------------------------------------------------

// Function: GetBufferGranularity
// Address: 00432880
/* public: unsigned int __thiscall RGE_Communications_Speed::GetBufferGranularity(void) */

uint __thiscall RGE_Communications_Speed::GetBufferGranularity(RGE_Communications_Speed *this)
{
  return this->CurrentBufferGranularity;
}

// --------------------------------------------------

// Function: GetAdjustmentCount
// Address: 00432890
/* public: unsigned long __thiscall RGE_Communications_Speed::GetAdjustmentCount(void) */

ulong __thiscall RGE_Communications_Speed::GetAdjustmentCount(RGE_Communications_Speed *this)
{
  return this->AdjustmentCount;
}

// --------------------------------------------------

// Function: GetBufferGranularityAdjusted
// Address: 004328a0
/* public: unsigned int __thiscall RGE_Communications_Speed::GetBufferGranularityAdjusted(void) */

uint __thiscall
RGE_Communications_Speed::GetBufferGranularityAdjusted(RGE_Communications_Speed *this)
{
  this->LastFrameHadTime = 1;
  return this->CurrentBufferGranularity;
}

// --------------------------------------------------

// Function: BufferFramesRemaining
// Address: 004328c0
/* public: unsigned int __thiscall RGE_Communications_Speed::BufferFramesRemaining(void) */

uint __thiscall RGE_Communications_Speed::BufferFramesRemaining(RGE_Communications_Speed *this)
{
  return this->TotalBufferFramesRemaining;
}

// --------------------------------------------------

// Function: WaitingOnAcknowledgement
// Address: 004328d0
/* public: unsigned int __thiscall RGE_Communications_Speed::WaitingOnAcknowledgement(void) */

uint __thiscall RGE_Communications_Speed::WaitingOnAcknowledgement(RGE_Communications_Speed *this)
{
  uint uVar1;
  
  uVar1 = this->SkipFrames + 1;
  this->SkipFrames = uVar1;
  return uVar1;
}

// --------------------------------------------------

// Function: AdjustLocalSpeed
// Address: 004328e0
/* protected: void __thiscall RGE_Communications_Speed::AdjustLocalSpeed(void) */

void __thiscall RGE_Communications_Speed::AdjustLocalSpeed(RGE_Communications_Speed *this)
{
  if ((this->NextLatencyChangeTurn != 0) &&
     (this->LastAdjusted = 0, this->NextLatencyChangeTurn <= this->Comm->current_turn)) {
    this->NextLatencyChangeTurn = 0;
    this->AdjustmentCount = this->AdjustmentCount + 1;
    this->CurrentBufferFrames = this->FutureBufferFrames;
    this->CurrentBufferGranularity = this->FutureBufferGranularity;
    this->FutureBufferFrames = 0;
    this->FutureBufferGranularity = 0;
  }
  return;
}

// --------------------------------------------------

// Function: ReloadBufferFrames
// Address: 00432940
/* public: void __thiscall RGE_Communications_Speed::ReloadBufferFrames(void) */

void __thiscall RGE_Communications_Speed::ReloadBufferFrames(RGE_Communications_Speed *this)
{
  RGE_TimeSinceLastCall::Set(this->TurnTSLC);
  this->DroppedFramesTurn = 0;
  AdjustLocalSpeed(this);
  this->TotalBufferFramesRemaining = this->CurrentBufferFrames;
  return;
}

// --------------------------------------------------

// Function: BufferTimeToUse
// Address: 00432970
/* public: unsigned int __thiscall RGE_Communications_Speed::BufferTimeToUse(unsigned long) */

uint __thiscall
RGE_Communications_Speed::BufferTimeToUse(RGE_Communications_Speed *this,ulong param_1)
{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  
  if (this->LastFrameHadTime == 0) {
    RGE_TimeSinceLastCall::Skip(this->FrameTSLC);
  }
  else {
    RGE_TimeSinceLastCall::Set(this->FrameTSLC);
  }
  this->LastFrameHadTime = 0;
  if (this->TotalBufferFramesRemaining == 0) {
    this->LastFrameHadTime = 0;
    return 0;
  }
  uVar1 = RGE_TimeSinceLastCall::Get(this->TurnTSLC);
  this->RealTimePassed = uVar1;
  iVar2 = TCommunications_Handler::AllPlayersAcknowledged(this->Comm);
  if (iVar2 != 0) {
    this->AllAcknowledgedBuffersRemaining =
         this->AllAcknowledgedBuffersRemaining + this->TotalBufferFramesRemaining;
  }
  uVar3 = (this->CurrentBufferFrames - this->TotalBufferFramesRemaining) *
          this->CurrentBufferGranularity;
  this->BufferTimePassed = uVar3;
  if (this->OverheadFactor + this->RealTimePassed < uVar3) {
    if (6 < param_1) {
      this->DroppedFrames = this->DroppedFrames + 1;
      this->DroppedFramesTurn = this->DroppedFramesTurn + 1;
    }
    this->LastFrameHadTime = 0;
    return 0;
  }
  this->LastFrameHadTime = 1;
  this->TotalBufferFramesRemaining = this->TotalBufferFramesRemaining - 1;
  return this->CurrentBufferGranularity;
}

// --------------------------------------------------

// Function: Skip
// Address: 00432a70
/* public: void __thiscall RGE_Communications_Speed::Skip(void) */

void __thiscall RGE_Communications_Speed::Skip(RGE_Communications_Speed *this)
{
  RGE_TimeSinceLastCall::Skip(this->FrameTSLC);
  this->LastFrameHadTime = 0;
  return;
}

// --------------------------------------------------

// Function: GetHighLatencyCenti
// Address: 00432a90
/* public: unsigned char __thiscall RGE_Communications_Speed::GetHighLatencyCenti(void) */

uchar __thiscall RGE_Communications_Speed::GetHighLatencyCenti(RGE_Communications_Speed *this)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar2 = 0;
  uVar3 = 1;
  puVar4 = this->ActualLatency;
  do {
    puVar4 = puVar4 + 1;
    iVar1 = TCommunications_Handler::IsPlayerHuman(this->Comm,uVar3);
    if ((iVar1 != 0) && (uVar2 <= *puVar4)) {
      uVar2 = *puVar4;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 10);
  this->HighestLatencyMsec = uVar2;
  uVar2 = (uVar2 + 5) / 10;
  if (uVar2 < 2) {
    uVar2 = 1;
  }
  if (0xfe < uVar2) {
    uVar2 = 0xff;
  }
  return (uchar)uVar2;
}

// --------------------------------------------------

// Function: GetPlayerLatency
// Address: 00432b00
/* public: unsigned long __thiscall RGE_Communications_Speed::GetPlayerLatency(unsigned int) */

ulong __thiscall
RGE_Communications_Speed::GetPlayerLatency(RGE_Communications_Speed *this,uint param_1)
{
  if ((param_1 != 0) && (param_1 < 10)) {
    return this->ActualLatency[param_1];
  }
  return 0;
}

// --------------------------------------------------

// Function: GetLatencyInfo
// Address: 00432b20
// [HELPER] s_P_d__d_: "P%d=%d "
/* public: char * __thiscall RGE_Communications_Speed::GetLatencyInfo(void) */

char * __thiscall RGE_Communications_Speed::GetLatencyInfo(RGE_Communications_Speed *this)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  char *pcVar7;
  RGE_Communications_Speed *pRVar8;
  char *pcVar9;
  char *pcVar10;
  char buf [24];
  
  uVar3 = 0xffffffff;
  pcVar7 = &s_Latency>_;
  do {
    pcVar10 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar10 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar10;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  uVar5 = 1;
  pcVar7 = pcVar10 + -uVar3;
  pRVar8 = this;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pRVar8->TBuff = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pRVar8 = (RGE_Communications_Speed *)(pRVar8->TBuff + 4);
  }
  puVar6 = this->ActualLatency;
  for (uVar3 = uVar3 & 3; buf._0_4_ = this, uVar3 != 0; uVar3 = uVar3 - 1) {
    pRVar8->TBuff[0] = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pRVar8 = (RGE_Communications_Speed *)(pRVar8->TBuff + 1);
  }
  do {
    puVar6 = puVar6 + 1;
    iVar2 = TCommunications_Handler::IsPlayerHuman
                      (*(TCommunications_Handler **)(buf._0_4_ + 0x108),uVar5);
    if (iVar2 != 0) {
      sprintf(buf + 4,s_P_d__d_,uVar5,*puVar6);
      uVar3 = 0xffffffff;
      pcVar7 = buf + 4;
      do {
        pcVar10 = pcVar7;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar10 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar10;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar2 = -1;
      pcVar7 = (char *)buf._0_4_;
      do {
        pcVar9 = pcVar7;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      pcVar7 = pcVar10 + -uVar3;
      pcVar10 = pcVar9 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar10 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    uVar5 = uVar5 + 1;
    if (9 < uVar5) {
      return (char *)buf._0_4_;
    }
  } while( true );
}

// --------------------------------------------------

// Function: GetSelfPlayerOptimalSpeedStr
// Address: 00432bd0
// [HELPER] s_MeOptimal__Buf__3d_Gran__3d__Tar: "MeOptimal: Buf=%3d Gran=%3d  Target FPS=%3d  My expect turn=%4dms"
/* public: char * __thiscall RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr(void) */

char * __thiscall
RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr(RGE_Communications_Speed *this)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = GetRecommendedBufferFrames(this);
  uVar2 = GetRecommendedBufferGranularity(this);
  sprintf(0x62d170,s_MeOptimal__Buf__3d_Gran__3d__Tar,uVar1,uVar2,(int)(1000 / (longlong)(int)uVar2)
          ,uVar2 * uVar1);
  return &UNK_0062d078.field_0xf8;
}

// --------------------------------------------------

// Function: GetPlayerSpeedStatusStr
// Address: 00432c10
// [HELPER] s_Buf__3d____3d___Gran__3dms___tur: "Buf=%3d / %3d * Gran=%3dms = turn %4dms   %s"
/* public: char * __thiscall RGE_Communications_Speed::GetPlayerSpeedStatusStr(int) */

char * __thiscall
RGE_Communications_Speed::GetPlayerSpeedStatusStr(RGE_Communications_Speed *this,int param_1)
{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  if ((-1 < param_1) && (param_1 < 10)) {
    uVar1 = this->CurrentBufferGranularity;
    uVar2 = this->CurrentBufferFrames;
    pcVar3 = RGE_TimeSinceLastCall::GetHiLoInfo(this->FrameTSLC,0x32);
    sprintf(&DAT_0062cf70,s_Buf__3d____3d___Gran__3dms___tur,this->TotalBufferFramesRemaining,uVar2,
            uVar1,uVar2 * uVar1,pcVar3);
    return (char *)&DAT_0062cf70;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: GetMachineSpeedInfo
// Address: 00432c70
// [HELPER] s_P__1d_fr_d_lat_d__: "P#%1d(fr%d lat%d) "
/* public: char * __thiscall RGE_Communications_Speed::GetMachineSpeedInfo(void) */

char * __thiscall RGE_Communications_Speed::GetMachineSpeedInfo(RGE_Communications_Speed *this)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulong *puVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char buf [24];
  
  uVar3 = 0xffffffff;
  pcVar7 = &s_PlrSpeed>_;
  do {
    pcVar9 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  uVar5 = 1;
  pcVar7 = pcVar9 + -uVar3;
  pcVar9 = (char *)&DAT_0062d070;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  puVar6 = this->PlayerAvgFramesMsec;
  for (uVar3 = uVar3 & 3; buf._0_4_ = this, uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  do {
    puVar6 = puVar6 + 1;
    iVar2 = TCommunications_Handler::IsPlayerHuman
                      (*(TCommunications_Handler **)(buf._0_4_ + 0x108),uVar5);
    if (iVar2 != 0) {
      sprintf(buf + 4,s_P__1d_fr_d_lat_d__,uVar5,*puVar6,puVar6[10]);
      uVar3 = 0xffffffff;
      pcVar7 = buf + 4;
      do {
        pcVar9 = pcVar7;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar2 = -1;
      pcVar7 = (char *)&DAT_0062d070;
      do {
        pcVar8 = pcVar7;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar3;
      pcVar9 = pcVar8 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
    }
    uVar5 = uVar5 + 1;
    if (9 < (int)uVar5) {
      return (char *)&DAT_0062d070;
    }
  } while( true );
}

// --------------------------------------------------

// Function: GetRecommendedBufferFrames
// Address: 00432d20
/* public: unsigned int __thiscall RGE_Communications_Speed::GetRecommendedBufferFrames(void) */

uint __thiscall RGE_Communications_Speed::GetRecommendedBufferFrames(RGE_Communications_Speed *this)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar2 = 0;
  uVar3 = 1;
  puVar4 = this->ActualLatency;
  do {
    puVar4 = puVar4 + 1;
    iVar1 = TCommunications_Handler::IsPlayerHuman(this->Comm,uVar3);
    if ((iVar1 != 0) && (uVar2 <= *puVar4)) {
      uVar2 = *puVar4;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 10);
  uVar2 = uVar2 / this->CurrentBufferGranularity;
  this->OptimalBufferFrames = uVar2;
  if (0x13 < uVar2) {
    uVar2 = 0x14;
  }
  this->OptimalBufferFrames = uVar2;
  if (uVar2 < 5) {
    uVar2 = 4;
  }
  this->OptimalBufferFrames = uVar2 + 1;
  return uVar2 + 1;
}

// --------------------------------------------------

// Function: GetAvgFrameRate
// Address: 00432d90
/* public: unsigned int __thiscall RGE_Communications_Speed::GetAvgFrameRate(void) */

uint __thiscall RGE_Communications_Speed::GetAvgFrameRate(RGE_Communications_Speed *this)
{
  ulong uVar1;
  
  uVar1 = RGE_TimeSinceLastCall::GetAvg(this->FrameTSLC,0x32);
  return uVar1;
}

// --------------------------------------------------

// Function: GetRecommendedBufferGranularity
// Address: 00432da0
/* public: unsigned int __thiscall RGE_Communications_Speed::GetRecommendedBufferGranularity(void)
    */

uint __thiscall
RGE_Communications_Speed::GetRecommendedBufferGranularity(RGE_Communications_Speed *this)
{
  uint uVar1;
  
  uVar1 = RGE_TimeSinceLastCall::GetAvg(this->FrameTSLC,0x32);
  this->OptimalBufferGranularity = uVar1;
  if (0x96 < uVar1) {
    uVar1 = 0x96;
  }
  this->OptimalBufferGranularity = uVar1;
  if (uVar1 < 10) {
    uVar1 = 10;
  }
  this->OptimalBufferGranularity = uVar1;
  return uVar1;
}

// --------------------------------------------------

// Function: AnalyzeGameSpeed
// Address: 00432de0
/* public: int __thiscall RGE_Communications_Speed::AnalyzeGameSpeed(unsigned int *,unsigned int
   *,int) */

int __thiscall
RGE_Communications_Speed::AnalyzeGameSpeed
          (RGE_Communications_Speed *this,uint *param_1,uint *param_2,int param_3)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong *puVar8;
  uint uVar9;
  ulong SyncTurn;
  
  iVar1 = TCommunications_Handler::IsHost(this->Comm);
  if (iVar1 == 0) {
    return 0;
  }
  if (this->NextLatencyChangeTurn != 0) {
    return 0;
  }
  uVar2 = this->Comm->current_turn + (uint)(this->Comm->PlayerOptions).CommandTurnIncrement;
  if (uVar2 < 0x14) {
    return 0;
  }
  uVar4 = this->LastAdjusted + 1;
  this->LastAdjusted = uVar4;
  if (uVar4 < 5) {
    return 0;
  }
  uVar4 = 10;
  uVar7 = 0x1e;
  uVar9 = 1;
  puVar8 = this->PlayerHighLatencyMsec;
  do {
    puVar8 = puVar8 + 1;
    iVar1 = TCommunications_Handler::IsPlayerHuman(this->Comm,uVar9);
    if (iVar1 != 0) {
      if (uVar4 <= puVar8[-10]) {
        uVar4 = puVar8[-10];
      }
      if (uVar7 <= *puVar8) {
        uVar7 = *puVar8;
      }
    }
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 10);
  uVar4 = ((uVar4 + 5) / 10) * 10;
  if (0x96 < uVar4) {
    uVar4 = 0x96;
  }
  uVar9 = this->CurrentBufferGranularity;
  uVar5 = (int)(uVar4 - uVar9) >> 0x1f;
  if ((uVar4 - uVar9 ^ uVar5) - uVar5 < 10) {
    uVar4 = uVar9;
  }
  uVar7 = uVar7 / uVar4 + 2;
  if (0x13 < uVar7) {
    uVar7 = 0x14;
  }
  if (uVar7 < 5) {
    uVar7 = 4;
  }
  if (uVar4 * uVar7 < 0xfa) {
    uVar7 = (int)(0xfa / (ulonglong)uVar4) + 1;
  }
  uVar5 = this->CurrentBufferFrames;
  uVar3 = uVar4 * uVar7 - uVar5 * uVar9;
  uVar6 = (int)uVar3 >> 0x1f;
  uVar6 = (uVar3 ^ uVar6) - uVar6;
  if (uVar6 < 0xb) {
    return 0;
  }
  if (((uVar4 * uVar7 < uVar5 * uVar9) && (100 < uVar6)) && (4 < uVar5)) {
    uVar7 = uVar5 - 1;
  }
  *param_1 = uVar4;
  *param_2 = uVar7;
  if ((param_3 != 0) && (this->SpeedControlEnabled != 0)) {
    SetFutureSpeedChange(this,uVar7,uVar4,uVar2);
    TCommunications_Handler::SendSpeedChange(this->Comm,uVar7,uVar4);
  }
  return 1;
}

// --------------------------------------------------

// Function: SetV1
// Address: 00432fb0
// [HELPER] s_Speed_set_V1__d: "Speed set V1=%d"
/* public: void __thiscall RGE_Communications_Speed::SetV1(unsigned long) */

void __thiscall RGE_Communications_Speed::SetV1(RGE_Communications_Speed *this,ulong param_1)
{
  TDebuggingLog::Log(L,(char *)L,s_Speed_set_V1__d,param_1);
  return;
}

// --------------------------------------------------

// Function: SetV2
// Address: 00432fd0
// [HELPER] s_Speed_set_V2__d: "Speed set V2=%d"
/* public: void __thiscall RGE_Communications_Speed::SetV2(unsigned long) */

void __thiscall RGE_Communications_Speed::SetV2(RGE_Communications_Speed *this,ulong param_1)
{
  TDebuggingLog::Log(L,(char *)L,s_Speed_set_V2__d,param_1);
  return;
}

// --------------------------------------------------

