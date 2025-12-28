// Class: TTaunt
// Size:  0x198
//
// Member Layout:
// [0x000] TDigital *[4] Audio (sz: 0x10)
// [0x010] int LastAudioPlayed
// [0x014] char[255] TBuff (sz: 0xFF)
// [0x113] char[128] TauntDir (sz: 0x80)
// [0x194] int Mute
// ----------------------------------------------------------------

// Function: TTaunt
// Address: 00509450
/* public: __thiscall TTaunt::TTaunt(class TSound_Driver *) */

TTaunt * __thiscall TTaunt::TTaunt(TTaunt *this,TSound_Driver *param_1)
{
  this->TauntDir[0] = '\0';
  RestartSoundSystem(this,param_1);
  this->Mute = 0;
  return this;
}

// --------------------------------------------------

// Function: ~TTaunt
// Address: 00509480
/* public: __thiscall TTaunt::~TTaunt(void) */

void __thiscall TTaunt::~TTaunt(TTaunt *this)
{
  TDigital *this_00;
  int iVar1;
  
  iVar1 = 4;
  do {
    this_00 = this->Audio[0];
    if (this_00 != (TDigital *)0x0) {
      TDigital::~TDigital(this_00);
      operator_delete(this_00);
      this->Audio[0] = (TDigital *)0x0;
    }
    this = (TTaunt *)(this->Audio + 1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// --------------------------------------------------

// Function: PlayTauntStr
// Address: 00509490
/* public: int __thiscall TTaunt::PlayTauntStr(char *,unsigned char) */

int __thiscall TTaunt::PlayTauntStr(TTaunt *this,char *param_1,uchar param_2)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = "!MUTE";
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar2 = __strnicmp(param_1,&DAT_00576548,~uVar3 - 1);
  if ((iVar2 == 0) && (param_2 != '\0')) {
    this->Mute = 1;
  }
  uVar3 = 0xffffffff;
  pcVar4 = "!NOMUTE";
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar2 = __strnicmp(param_1,&DAT_00576550,~uVar3 - 1);
  if ((iVar2 == 0) && (param_2 != '\0')) {
    this->Mute = 0;
  }
  if (this->Mute != 0) {
    return 0;
  }
  iVar2 = GetTauntNo(this,param_1);
  if (iVar2 != 0) {
    PlayTauntNo(this,iVar2);
  }
  return iVar2;
}

// --------------------------------------------------

// Function: PlayTauntNo
// Address: 00509530
// [HELPER] s__sTaunt__3d_wav: "%sTaunt%.3d.wav"
/* WARNING: Variable defined which should be unmapped: FName */
/* public: int __thiscall TTaunt::PlayTauntNo(int) */

int __thiscall TTaunt::PlayTauntNo(TTaunt *this,int param_1)
{
  int iVar1;
  TTaunt *pTVar2;
  int iVar3;
  char FName [128];
  
  if (((this->Mute == 0) && (this->TauntDir != (char *)0x0)) && (param_1 != 0)) {
    sprintf(FName + 4,s__sTaunt__3d_wav,this->TauntDir,param_1);
    iVar3 = 4;
    pTVar2 = this;
    do {
      if ((pTVar2->Audio[0] != (TDigital *)0x0) &&
         (iVar1 = TDigital::is_playing(pTVar2->Audio[0]), iVar1 == 0)) {
        TDigital::unload(pTVar2->Audio[0]);
      }
      pTVar2 = (TTaunt *)(pTVar2->Audio + 1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 0;
    pTVar2 = this;
    while ((pTVar2->Audio[0] == (TDigital *)0x0 ||
           (iVar1 = TDigital::is_playing(pTVar2->Audio[0]), iVar1 != 0))) {
      iVar3 = iVar3 + 1;
      pTVar2 = (TTaunt *)(pTVar2->Audio + 1);
      if (3 < iVar3) {
        return 0;
      }
    }
    iVar1 = TDigital::load(this->Audio[iVar3],FName + 4,-1);
    if (iVar1 == 0) {
      TDigital::unload(this->Audio[iVar3]);
      return 0;
    }
    iVar3 = TDigital::play(this->Audio[iVar3]);
    return iVar3;
  }
  return 0;
}

// --------------------------------------------------

// Function: GetTauntNo
// Address: 00509610
/* public: int __thiscall TTaunt::GetTauntNo(char *) */

int __thiscall TTaunt::GetTauntNo(TTaunt *this,char *param_1)
{
  uint uVar1;
  
  if (*param_1 == '!') {
    param_1 = param_1 + 1;
  }
  uVar1 = atoi(param_1);
  if (uVar1 == 0) {
    return 0;
  }
  return uVar1 & (999 < (int)uVar1) - 1;
}

// --------------------------------------------------

// Function: GetTauntText
// Address: 00509640
// [HELPER] s_Taunts_you_: "Taunts you!"
/* public: char * __thiscall TTaunt::GetTauntText(int) */

char * __thiscall TTaunt::GetTauntText(TTaunt *this,int param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  pcVar4 = &s_Taunts_you_;
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
  pcVar5 = this->TBuff;
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
  return this->TBuff;
}

// --------------------------------------------------

// Function: StopSoundSystem
// Address: 00509670
/* public: void __thiscall TTaunt::StopSoundSystem(void) */

void __thiscall TTaunt::StopSoundSystem(TTaunt *this)
{
  TDigital *this_00;
  int iVar1;
  
  iVar1 = 4;
  do {
    this_00 = this->Audio[0];
    if (this_00 != (TDigital *)0x0) {
      TDigital::~TDigital(this_00);
      operator_delete(this_00);
      this->Audio[0] = (TDigital *)0x0;
    }
    this = (TTaunt *)(this->Audio + 1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// --------------------------------------------------

// Function: RestartSoundSystem
// Address: 005096a0
// [HELPER] s_Silence: "Silence"
/* public: int __thiscall TTaunt::RestartSoundSystem(class TSound_Driver *) */

int __thiscall TTaunt::RestartSoundSystem(TTaunt *this,TSound_Driver *param_1)
{
  TDigital *pTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_00560dab;
  *unaff_FS_OFFSET = &local_c;
  iVar2 = 4;
  do {
    local_4 = 0xffffffff;
    pTVar1 = (TDigital *)operator_new(0x3c);
    local_4 = 0;
    if (pTVar1 == (TDigital *)0x0) {
      pTVar1 = (TDigital *)0x0;
    }
    else {
      pTVar1 = (TDigital *)TDigital::TDigital(pTVar1,param_1,s_Silence,-1);
    }
    this->Audio[0] = pTVar1;
    this = (TTaunt *)(this->Audio + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

