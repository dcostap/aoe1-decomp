// Class: CCDAudio
// Size:  0x18
//
// Member Layout:
// [0x000] void * m_Wnd
// [0x004] int m_bOpened
// [0x008] uint m_nDeviceID
// [0x00C] tagMCI_PLAY_PARMS m_mciPlayParms (sz: 0xC)
// ----------------------------------------------------------------

// Function: CCDAudio
// Address: 004237c0
/* public: __thiscall CCDAudio::CCDAudio(void) */

void __thiscall CCDAudio::CCDAudio(CCDAudio *this)
{
  this->m_Wnd = (void *)0x0;
  this->m_bOpened = 0;
  return;
}

// --------------------------------------------------

// Function: ~CCDAudio
// Address: 004237d0
/* WARNING: Variable defined which should be unmapped: playing */
/* public: __thiscall CCDAudio::~CCDAudio(void) */

void __thiscall CCDAudio::~CCDAudio(CCDAudio *this)
{
  int playing;
  CCDAudio *local_4;
  
  local_4 = this;
  IsPlaying(this,(int *)&local_4);
  if (local_4 != (CCDAudio *)0x0) {
    Stop(this);
  }
  Close(this);
  return;
}

// --------------------------------------------------

// Function: Open
// Address: 00423800
/* WARNING: Variable defined which should be unmapped: mciSetInfo */
/* public: unsigned long __thiscall CCDAudio::Open(void *) */

ulong __thiscall CCDAudio::Open(CCDAudio *this,void *param_1)
{
  ulong uVar1;
  tagMCI_SET_PARMS mciSetInfo;
  tagMCI_OPEN_PARMSA mciOpenParms;
  
  this->m_Wnd = param_1;
  if (this->m_bOpened != 0) {
    Close(this);
  }
  mciOpenParms.lpstrElementName = (char *)0x204;
  uVar1 = mciSendCommandA(0,0x803,0x3102,&mciOpenParms.wDeviceID);
  if (uVar1 == 0) {
    this->m_bOpened = 1;
    this->m_nDeviceID = (uint)mciOpenParms.lpstrDeviceType;
    mciSetInfo.dwAudio = 10;
    uVar1 = mciSendCommandA(mciOpenParms.lpstrDeviceType,0x80d,0x402,&mciSetInfo.dwTimeFormat);
  }
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: Close
// Address: 00423880
/* public: unsigned long __thiscall CCDAudio::Close(void) */

ulong __thiscall CCDAudio::Close(CCDAudio *this)
{
  ulong uVar1;
  
  uVar1 = 0;
  if (this->m_bOpened != 0) {
    uVar1 = mciSendCommandA(this->m_nDeviceID,0x804,2,0);
    DisplayErrorMsg(this,uVar1);
    if (uVar1 == 0) {
      this->m_bOpened = 0;
    }
  }
  return uVar1;
}

// --------------------------------------------------

// Function: Stop
// Address: 004238c0
/* public: unsigned long __thiscall CCDAudio::Stop(void) */

ulong __thiscall CCDAudio::Stop(CCDAudio *this)
{
  ulong uVar1;
  
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x808,2,0);
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: Play
// Address: 004238e0
/* public: unsigned long __thiscall CCDAudio::Play(unsigned char) */

ulong __thiscall CCDAudio::Play(CCDAudio *this,uchar param_1)
{
  ulong uVar1;
  
  (this->m_mciPlayParms).dwCallback = (ulong)this->m_Wnd;
  (this->m_mciPlayParms).dwFrom = (uint)param_1;
  (this->m_mciPlayParms).dwTo = (uint)(byte)(param_1 + 1);
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x806,0xd,&this->m_mciPlayParms);
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: Pause
// Address: 00423930
/* public: unsigned long __thiscall CCDAudio::Pause(void) */

ulong __thiscall CCDAudio::Pause(CCDAudio *this)
{
  ulong uVar1;
  
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x809,2,0);
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: ResumePlay
// Address: 00423950
/* public: unsigned long __thiscall CCDAudio::ResumePlay(void) */

ulong __thiscall CCDAudio::ResumePlay(CCDAudio *this)
{
  ulong uVar1;
  
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x806,0,&this->m_mciPlayParms);
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: Eject
// Address: 00423980
/* public: unsigned long __thiscall CCDAudio::Eject(void) */

ulong __thiscall CCDAudio::Eject(CCDAudio *this)
{
  ulong uVar1;
  
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x80d,0x100,0);
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: GetNumberOfTracks
// Address: 004239b0
/* WARNING: Variable defined which should be unmapped: mciStatusInfo */
/* public: unsigned long __thiscall CCDAudio::GetNumberOfTracks(unsigned char &) */

ulong __thiscall CCDAudio::GetNumberOfTracks(CCDAudio *this,uchar *param_1)
{
  ulong uVar1;
  tagMCI_STATUS_PARMS mciStatusInfo;
  
  mciStatusInfo.dwTrack = 3;
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x814,0x102,&mciStatusInfo.dwReturn);
  *param_1 = (uchar)mciStatusInfo.dwItem;
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: IsMediaPresent
// Address: 004239f0
/* WARNING: Variable defined which should be unmapped: mciStatusParms */
/* public: unsigned long __thiscall CCDAudio::IsMediaPresent(int &) */

ulong __thiscall CCDAudio::IsMediaPresent(CCDAudio *this,int *param_1)
{
  ulong uVar1;
  tagMCI_STATUS_PARMS mciStatusParms;
  
  mciStatusParms.dwTrack = 5;
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x814,0x102,&mciStatusParms.dwReturn);
  *param_1 = (uint)(mciStatusParms.dwItem != 0);
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: IsPlaying
// Address: 00423a40
/* WARNING: Variable defined which should be unmapped: mciStatusParms */
/* public: unsigned long __thiscall CCDAudio::IsPlaying(int &) */

ulong __thiscall CCDAudio::IsPlaying(CCDAudio *this,int *param_1)
{
  ulong uVar1;
  tagMCI_STATUS_PARMS mciStatusParms;
  
  mciStatusParms.dwTrack = 4;
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x814,0x102,&mciStatusParms.dwReturn);
  *param_1 = (uint)(mciStatusParms.dwItem == 0x20e);
  if ((mciStatusParms.dwItem == 0x20e) != 0) {
    mciStatusParms.dwTrack = 8;
    uVar1 = mciSendCommandA(this->m_nDeviceID,0x814,0x102,&mciStatusParms.dwReturn);
    *param_1 = mciStatusParms.dwItem;
  }
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: GetLength
// Address: 00423ac0
/* WARNING: Variable defined which should be unmapped: mciStatusParms */
/* public: unsigned long __thiscall CCDAudio::GetLength(unsigned char &,unsigned char &) */

ulong __thiscall CCDAudio::GetLength(CCDAudio *this,uchar *param_1,uchar *param_2)
{
  ulong uVar1;
  tagMCI_STATUS_PARMS mciStatusParms;
  
  mciStatusParms.dwTrack = 1;
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x814,0x102,&mciStatusParms.dwReturn);
  *param_1 = (uchar)(undefined2)mciStatusParms.dwItem;
  *param_2 = (uchar)((ushort)(undefined2)mciStatusParms.dwItem >> 8);
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: GetTrackLength
// Address: 00423b10
/* WARNING: Variable defined which should be unmapped: mciStatusParms */
/* public: unsigned long __thiscall CCDAudio::GetTrackLength(unsigned char,unsigned char &,unsigned
   char &) */

ulong __thiscall
CCDAudio::GetTrackLength(CCDAudio *this,uchar param_1,uchar *param_2,uchar *param_3)
{
  ulong uVar1;
  tagMCI_STATUS_PARMS mciStatusParms;
  
  mciStatusParms.dwTrack = 1;
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x814,0x112,&mciStatusParms.dwReturn);
  *param_2 = (uchar)(undefined2)mciStatusParms.dwItem;
  *param_3 = (uchar)((ushort)(undefined2)mciStatusParms.dwItem >> 8);
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: GetPosition
// Address: 00423b70
/* WARNING: Variable defined which should be unmapped: mciStatusParms */
/* public: unsigned long __thiscall CCDAudio::GetPosition(unsigned char &,unsigned char &,unsigned
   char &) */

ulong __thiscall CCDAudio::GetPosition(CCDAudio *this,uchar *param_1,uchar *param_2,uchar *param_3)
{
  ulong uVar1;
  tagMCI_STATUS_PARMS mciStatusParms;
  
  mciStatusParms.dwTrack = 2;
  uVar1 = mciSendCommandA(this->m_nDeviceID,0x814,0x102,&mciStatusParms.dwReturn);
  *param_1 = (uchar)mciStatusParms.dwItem;
  *param_2 = (uchar)(mciStatusParms.dwItem >> 8);
  *param_3 = (uchar)(mciStatusParms.dwItem >> 0x10);
  uVar1 = DisplayErrorMsg(this,uVar1);
  return uVar1;
}

// --------------------------------------------------

// Function: DisplayErrorMsg
// Address: 00423bd0
// [HELPER] s_Unknow_Error: "Unknow Error"
/* WARNING: Variable defined which should be unmapped: szErrorMsg */
/* private: unsigned long __thiscall CCDAudio::DisplayErrorMsg(unsigned long) */

ulong __thiscall CCDAudio::DisplayErrorMsg(CCDAudio *this,ulong param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char szErrorMsg [256];
  
  if (param_1 != 0) {
    pcVar7 = szErrorMsg;
    iVar2 = mciGetErrorStringA(param_1,szErrorMsg + 4,0x100);
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
      pcVar5 = &s_Unknow_Error;
      do {
        pcVar6 = pcVar5;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar5 = pcVar6 + -uVar3;
      for (uVar4 = uVar3 >> 2; pcVar7 = pcVar7 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar7 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
      }
    }
  }
  return param_1;
}

// --------------------------------------------------

