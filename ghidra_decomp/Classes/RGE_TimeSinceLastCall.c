// Class: RGE_TimeSinceLastCall
// Size:  0x2B4
//
// Member Layout:
// [0x000] char[255] TBuff (sz: 0xFF)
// [0x100] ulong lowTSLC
// [0x104] ulong highTSLC
// [0x108] ulong TSLC
// [0x10C] ulong[101] aTSLC (sz: 0x194)
// [0x2A0] int Offset
// [0x2A4] ulong LastCall
// [0x2A8] ulong FirstCall
// [0x2AC] ulong Now
// [0x2B0] ulong cps
// ----------------------------------------------------------------

// Function: RGE_TimeSinceLastCall
// Address: 00480390
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
/* public: __thiscall RGE_TimeSinceLastCall::RGE_TimeSinceLastCall(void) */

RGE_TimeSinceLastCall * __thiscall
RGE_TimeSinceLastCall::RGE_TimeSinceLastCall(RGE_TimeSinceLastCall *this)
{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  
  this->lowTSLC = 99999;
  this->highTSLC = 0;
  this->Offset = 0;
  this->cps = 0;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0xd);
  this->FirstCall = uVar1;
  this->Now = uVar1;
  this->LastCall = uVar1;
  puVar3 = this->aTSLC;
  for (iVar2 = 0x65; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_TimeSinceLastCall
// Address: 004803f0
/* public: __thiscall RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall(void) */

void __thiscall RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall(RGE_TimeSinceLastCall *this)
{
  return;
}

// --------------------------------------------------

// Function: GetAvg
// Address: 00480400
/* public: unsigned long __thiscall RGE_TimeSinceLastCall::GetAvg(int) */

ulong __thiscall RGE_TimeSinceLastCall::GetAvg(RGE_TimeSinceLastCall *this,int param_1)
{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  
  uVar1 = 0;
  if ((0 < param_1) && (param_1 < 0x65)) {
    iVar2 = this->Offset;
    uVar3 = 0;
    if (0 < param_1) {
      do {
        iVar2 = iVar2 + -1;
        if (iVar2 < 1) {
          iVar2 = 100;
        }
        uVar1 = uVar1 + this->aTSLC[iVar2];
        if (999 < uVar1) {
          this->cps = uVar3;
        }
        uVar3 = uVar3 + 1;
      } while ((int)uVar3 < param_1);
    }
    return uVar1 / (uint)param_1;
  }
  return 0;
}

// --------------------------------------------------

// Function: Get
// Address: 00480460
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
/* public: unsigned long __thiscall RGE_TimeSinceLastCall::Get(void) */

ulong __thiscall RGE_TimeSinceLastCall::Get(RGE_TimeSinceLastCall *this)
{
  ulong uVar1;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0x56);
  return uVar1 - this->LastCall;
}

// --------------------------------------------------

// Function: Set
// Address: 00480480
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
/* public: unsigned long __thiscall RGE_TimeSinceLastCall::Set(void) */

ulong __thiscall RGE_TimeSinceLastCall::Set(RGE_TimeSinceLastCall *this)
{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0x5d);
  uVar1 = this->LastCall;
  if (uVar1 == uVar3) {
    return 0;
  }
  this->LastCall = uVar3;
  iVar4 = this->Offset + 1;
  this->TSLC = uVar3 - uVar1;
  this->Offset = iVar4;
  if (100 < iVar4) {
    this->Offset = 0;
  }
  this->aTSLC[this->Offset] = this->TSLC;
  uVar2 = this->TSLC;
  uVar5 = this->lowTSLC;
  if (uVar2 < this->lowTSLC) {
    uVar5 = uVar2;
  }
  this->lowTSLC = uVar5;
  uVar5 = this->highTSLC;
  if (this->highTSLC < uVar2) {
    uVar5 = uVar2;
  }
  this->highTSLC = uVar5;
  return uVar2;
}

// --------------------------------------------------

// Function: Skip
// Address: 00480510
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
/* public: void __thiscall RGE_TimeSinceLastCall::Skip(void) */

void __thiscall RGE_TimeSinceLastCall::Skip(RGE_TimeSinceLastCall *this)
{
  ulong uVar1;
  
                    /* language.dll match for 0x78: "10" */
  debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0x78);
                    /* language.dll match for 0x79: "N" */
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0x79);
  this->LastCall = uVar1;
  return;
}

// --------------------------------------------------

// Function: GetAvgInfo
// Address: 00480540
// [HELPER] s_Avg__d____d: "Avg %d / %d"
/* public: char * __thiscall RGE_TimeSinceLastCall::GetAvgInfo(int) */

char * __thiscall RGE_TimeSinceLastCall::GetAvgInfo(RGE_TimeSinceLastCall *this,int param_1)
{
  ulong uVar1;
  
  uVar1 = GetAvg(this,param_1);
  sprintf(this,s_Avg__d____d,uVar1,param_1);
  return this->TBuff;
}

// --------------------------------------------------

// Function: GetHiLoMaxInfo
// Address: 00480570
/* public: char * __thiscall RGE_TimeSinceLastCall::GetHiLoMaxInfo(int) */

char * __thiscall RGE_TimeSinceLastCall::GetHiLoMaxInfo(RGE_TimeSinceLastCall *this,int param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = param_1;
  uVar2 = 0;
  uVar5 = 0;
  uVar6 = 999999;
  uVar3 = param_1;
  uVar7 = param_1;
  if ((0 < param_1) && (param_1 < 0x65)) {
    iVar4 = this->Offset;
    if (0 < param_1) {
      do {
        iVar4 = iVar4 + -1;
        if (iVar4 < 1) {
          iVar4 = 100;
        }
        uVar3 = this->aTSLC[iVar4];
        uVar2 = uVar2 + uVar3;
        if (uVar3 < uVar6) {
          uVar6 = uVar3;
        }
        if (uVar5 < uVar3) {
          uVar5 = uVar3;
        }
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
    param_1 = uVar2 / (uint)iVar1;
    uVar3 = uVar5;
    uVar7 = uVar6;
  }
  sprintf(this,s__LoLo__d__Lo__d_<_Avg__d____d_>_,this->lowTSLC,uVar7,param_1,iVar1,uVar3,
          this->highTSLC);
  return this->TBuff;
}

// --------------------------------------------------

// Function: GetHiLoInfo
// Address: 00480610
/* public: char * __thiscall RGE_TimeSinceLastCall::GetHiLoInfo(int) */

char * __thiscall RGE_TimeSinceLastCall::GetHiLoInfo(RGE_TimeSinceLastCall *this,int param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = param_1;
  uVar2 = 0;
  uVar5 = 0;
  uVar6 = 999999;
  uVar3 = param_1;
  uVar7 = param_1;
  if ((0 < param_1) && (param_1 < 0x65)) {
    iVar4 = this->Offset;
    if (0 < param_1) {
      do {
        iVar4 = iVar4 + -1;
        if (iVar4 < 1) {
          iVar4 = 100;
        }
        uVar3 = this->aTSLC[iVar4];
        uVar2 = uVar2 + uVar3;
        if (uVar3 < uVar6) {
          uVar6 = uVar3;
        }
        if (uVar5 < uVar3) {
          uVar5 = uVar3;
        }
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
    param_1 = uVar2 / (uint)iVar1;
    uVar3 = uVar5;
    uVar7 = uVar6;
  }
  sprintf(this,s_Lo__d_<_Avg__d_>_Hi__d_of__d,uVar7,param_1,uVar3,iVar1);
  return this->TBuff;
}

// --------------------------------------------------

// Function: CPS
// Address: 004806a0
/* public: unsigned long __thiscall RGE_TimeSinceLastCall::CPS(void) */

ulong __thiscall RGE_TimeSinceLastCall::CPS(RGE_TimeSinceLastCall *this)
{
  this->cps = 0;
  GetAvg(this,100);
  return this->cps;
}

// --------------------------------------------------

// Function: GetFirstCall
// Address: 004806c0
/* public: unsigned long __thiscall RGE_TimeSinceLastCall::GetFirstCall(void) */

ulong __thiscall RGE_TimeSinceLastCall::GetFirstCall(RGE_TimeSinceLastCall *this)
{
  return this->FirstCall;
}

// --------------------------------------------------

// Function: GetElapsedFirstCall
// Address: 004806d0
// [HELPER] s_C__msdev_work_age1_x1_RGE_TSLC_c: "C:\msdev\work\age1_x1\RGE_TSLC.cpp"
// [HELPER] s__02ld__02ld__02ld: "%02ld:%02ld:%02ld"
/* public: char * __thiscall RGE_TimeSinceLastCall::GetElapsedFirstCall(void) */

char * __thiscall RGE_TimeSinceLastCall::GetElapsedFirstCall(RGE_TimeSinceLastCall *this)
{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_RGE_TSLC_c,0xb5);
  this->Now = uVar1;
  uVar2 = (uVar1 - this->FirstCall) / 1000;
  if (0x3b < uVar2) {
    uVar4 = uVar2 / 0x3c;
    uVar2 = uVar2 % 0x3c;
    if (0x3b < uVar4) {
      uVar3 = uVar4 / 0x3c;
      uVar4 = uVar4 % 0x3c;
    }
  }
  sprintf(this,s__02ld__02ld__02ld,uVar3,uVar4,uVar2);
  return this->TBuff;
}

// --------------------------------------------------

// Function: Test
// Address: 00480770
/* public: void __thiscall RGE_TimeSinceLastCall::Test(void) */

void __thiscall RGE_TimeSinceLastCall::Test(RGE_TimeSinceLastCall *this)
{
  int iVar1;
  ulong *puVar2;
  
  puVar2 = this->aTSLC;
  for (iVar1 = 100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 10;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

