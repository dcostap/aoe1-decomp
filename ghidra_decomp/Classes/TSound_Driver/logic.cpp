// Class: TSound_Driver
// Function: TSound_Driver
// Address: 004bc590
/* public: __thiscall TSound_Driver::TSound_Driver(void) */

TSound_Driver * __thiscall TSound_Driver::TSound_Driver(TSound_Driver *this)
{
  init_vars(this);
  return this;
}

// --------------------------------------------------

// Function: TSound_Driver
// Address: 004bc5a0
/* public: __thiscall TSound_Driver::TSound_Driver(void *,char *) */

TSound_Driver * __thiscall
TSound_Driver::TSound_Driver(TSound_Driver *this,void *param_1,char *param_2)
{
  init_vars(this);
  init(this,param_1,param_2);
  return this;
}

// --------------------------------------------------

// Function: exit
// Address: 004bc5bf
void __thiscall TSound_Driver::exit(TSound_Driver *this)
{
  IDirectSoundBuffer *pIVar1;
  IDirectSound *pIVar2;
  
  close_mixer(this);
  if (this->ready != '\0') {
    ds_stream_exit();
    pIVar1 = this->primary_buffer;
    if (pIVar1 != (IDirectSoundBuffer *)0x0) {
      (**(code **)((int)*pIVar1 + 0x48))(pIVar1);
      (**(code **)((int)*this->primary_buffer + 8))(this->primary_buffer);
      this->primary_buffer = (IDirectSoundBuffer *)0x0;
    }
    pIVar2 = this->direct_sound;
    if (pIVar2 != (IDirectSound *)0x0) {
      (**(code **)((int)*pIVar2 + 8))(pIVar2);
      this->direct_sound = (IDirectSound *)0x0;
    }
    this->ready = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: ~TSound_Driver
// Address: 004bc5c0
/* public: __thiscall TSound_Driver::~TSound_Driver(void) */

void __thiscall TSound_Driver::~TSound_Driver(TSound_Driver *this)
{
  IDirectSoundBuffer *pIVar1;
  IDirectSound *pIVar2;
  
  close_mixer(this);
  if (this->ready != '\0') {
    ds_stream_exit();
    pIVar1 = this->primary_buffer;
    if (pIVar1 != (IDirectSoundBuffer *)0x0) {
      (**(code **)((int)*pIVar1 + 0x48))(pIVar1);
      (**(code **)((int)*this->primary_buffer + 8))(this->primary_buffer);
      this->primary_buffer = (IDirectSoundBuffer *)0x0;
    }
    pIVar2 = this->direct_sound;
    if (pIVar2 != (IDirectSound *)0x0) {
      (**(code **)((int)*pIVar2 + 8))(pIVar2);
      this->direct_sound = (IDirectSound *)0x0;
    }
    this->ready = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: init_vars
// Address: 004bc5d0
/* public: void __thiscall TSound_Driver::init_vars(void) */

void __thiscall TSound_Driver::init_vars(TSound_Driver *this)
{
  this->start_volume = 1;
  this->ready = '\0';
  this->main_wnd = (void *)0x0;
  this->direct_sound = (IDirectSound *)0x0;
  this->primary_buffer = (IDirectSoundBuffer *)0x0;
  this->dsrval = 0;
  this->mute = '\0';
  this->play_list_count = 0;
  this->volume = 0;
  this->mixer_open = 0;
  this->mixer_handle = (void *)0x0;
  this->path[0] = '\0';
  return;
}

// --------------------------------------------------

// Function: init
// Address: 004bc610
/* WARNING: Variable defined which should be unmapped: fmt */
/* public: int __thiscall TSound_Driver::init(void *,char *) */

int __thiscall TSound_Driver::init(TSound_Driver *this,void *param_1,char *param_2)
{
  IDirectSound **ppIVar1;
  IDirectSoundBuffer **ppIVar2;
  bool bVar3;
  int iVar4;
  IDirectSound *pIVar5;
  long lVar6;
  IDirectSound IVar7;
  IDirectSound *pIStack_a0;
  tWAVEFORMATEX fmt;
  _DSBUFFERDESC dsBD;
  _DSCAPS dscaps;
  
  pIStack_a0 = (IDirectSound *)0x4bc626;
  set_path(this,param_2);
  ppIVar1 = &this->direct_sound;
  this->main_wnd = param_1;
  this->ready = '\0';
  pIStack_a0 = (IDirectSound *)ppIVar1;
  iVar4 = _DirectSoundCreate_12(0);
  this->dsrval = iVar4;
  if (iVar4 != 0) {
    return 0;
  }
  pIStack_a0 = *ppIVar1;
  (**(code **)((int)*pIStack_a0 + 0x10))();
  bVar3 = false;
  pIVar5 = *ppIVar1;
  IVar7 = *pIVar5;
  if (((byte)dscaps.dwSize & 8) != 0) {
    iVar4 = (**(code **)((int)IVar7 + 0x18))(pIVar5,this->main_wnd,2);
    this->dsrval = iVar4;
    if (iVar4 == 0) {
      bVar3 = true;
      goto LAB_004bc69f;
    }
    pIVar5 = *ppIVar1;
    IVar7 = *pIVar5;
  }
  lVar6 = (**(code **)((int)IVar7 + 0x18))(pIVar5,this->main_wnd,1);
  this->dsrval = lVar6;
LAB_004bc69f:
  if (this->dsrval != 0) {
    (**(code **)((int)**ppIVar1 + 8))(*ppIVar1);
    *ppIVar1 = (IDirectSound *)0x0;
    return 0;
  }
  ppIVar2 = &this->primary_buffer;
  stack0xffffff84 = 0x14;
  iVar4 = (**(code **)((int)**ppIVar1 + 0xc))(*ppIVar1,&fmt.cbSize,ppIVar2,0);
  this->dsrval = iVar4;
  if (iVar4 == 0) {
    if (bVar3) {
      pIStack_a0 = (IDirectSound *)0x10001;
      lVar6 = (**(code **)((int)**ppIVar2 + 0x38))(*ppIVar2,&pIStack_a0);
      this->dsrval = lVar6;
    }
    iVar4 = (**(code **)((int)**ppIVar2 + 0x30))(*ppIVar2,0,0,1);
    this->dsrval = iVar4;
    if (iVar4 == 0) {
      this->ready = '\x01';
      ds_stream_init(this->main_wnd,*ppIVar1,*ppIVar2);
      open_mixer(this);
      return (uint)this->ready;
    }
  }
  (**(code **)((int)**ppIVar1 + 8))(*ppIVar1);
  *ppIVar1 = (IDirectSound *)0x0;
  return 0;
}

// --------------------------------------------------

// Function: exit
// Address: 004bc7c0
/* public: void __thiscall TSound_Driver::exit(void) */

void __thiscall TSound_Driver::exit(TSound_Driver *this)
{
  IDirectSoundBuffer *pIVar1;
  IDirectSound *pIVar2;
  
  close_mixer(this);
  if (this->ready != '\0') {
    ds_stream_exit();
    pIVar1 = this->primary_buffer;
    if (pIVar1 != (IDirectSoundBuffer *)0x0) {
      (**(code **)((int)*pIVar1 + 0x48))(pIVar1);
      (**(code **)((int)*this->primary_buffer + 8))(this->primary_buffer);
      this->primary_buffer = (IDirectSoundBuffer *)0x0;
    }
    pIVar2 = this->direct_sound;
    if (pIVar2 != (IDirectSound *)0x0) {
      (**(code **)((int)*pIVar2 + 8))(pIVar2);
      this->direct_sound = (IDirectSound *)0x0;
    }
    this->ready = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: set_path
// Address: 004bc810
/* public: void __thiscall TSound_Driver::set_path(char *) */

void __thiscall TSound_Driver::set_path(TSound_Driver *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    this->path[0] = '\0';
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_1;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = this->path;
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

// Function: driver_active
// Address: 004bc850
/* public: int __thiscall TSound_Driver::driver_active(void) */

int __thiscall TSound_Driver::driver_active(TSound_Driver *this)
{
  return (uint)this->ready;
}

// --------------------------------------------------

// Function: get_volume
// Address: 004bc860
/* public: long __thiscall TSound_Driver::get_volume(void) */

long __thiscall TSound_Driver::get_volume(TSound_Driver *this)
{
  return this->volume;
}

// --------------------------------------------------

// Function: set_volume
// Address: 004bc870
/* public: void __thiscall TSound_Driver::set_volume(long,int) */

void __thiscall TSound_Driver::set_volume(TSound_Driver *this,long param_1,int param_2)
{
  void *pvVar1;
  long lVar2;
  
  if (param_2 != 0) {
    this->volume = param_1;
  }
  if (this->mixer_open != 0) {
    pvVar1 = this->mixer_handle;
    (this->mixer_volume_value).dwValue =
         (uint)(((this->mixer_volume_control).Bounds._s_0.lMaximum -
                (this->mixer_volume_control).Bounds._s_0.lMinimum) * (param_1 + 10000)) / 10000;
    lVar2 = mixerSetControlDetails(pvVar1,&this->mixer_volume_details,0);
    this->dsrval = lVar2;
  }
  return;
}

// --------------------------------------------------

// Function: stream_file
// Address: 004bc8d0
// [HELPER] s__s_s: "%s%s"
/* WARNING: Variable defined which should be unmapped: file_name2 */
/* public: int __thiscall TSound_Driver::stream_file(char *,int,long) */

int __thiscall
TSound_Driver::stream_file(TSound_Driver *this,char *param_1,int param_2,long param_3)
{
  int iVar1;
  char file_name2 [260];
  
  if (this->ready == '\0') {
    return 0;
  }
  file_name2._0_4_ = param_1;
  sprintf(file_name2 + 4,s__s_s,this->path,param_1);
  file_name2._0_4_ = param_3;
  iVar1 = ds_stream_file(file_name2 + 4,param_2,param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: set_stream_volume
// Address: 004bc930
/* public: int __thiscall TSound_Driver::set_stream_volume(long) */

int __thiscall TSound_Driver::set_stream_volume(TSound_Driver *this,long param_1)
{
  int iVar1;
  
  if (this->ready == '\0') {
    return 0;
  }
  iVar1 = ds_stream_volume(param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: pause_stream
// Address: 004bc950
/* public: int __thiscall TSound_Driver::pause_stream(void) */

int __thiscall TSound_Driver::pause_stream(TSound_Driver *this)
{
  int iVar1;
  
  if (this->ready == '\0') {
    return 0;
  }
  iVar1 = ds_stream_pause();
  return iVar1;
}

// --------------------------------------------------

// Function: resume_stream
// Address: 004bc960
/* public: int __thiscall TSound_Driver::resume_stream(void) */

int __thiscall TSound_Driver::resume_stream(TSound_Driver *this)
{
  int iVar1;
  
  if (this->ready == '\0') {
    return 0;
  }
  iVar1 = ds_stream_resume();
  return iVar1;
}

// --------------------------------------------------

// Function: stop_stream
// Address: 004bc970
/* public: int __thiscall TSound_Driver::stop_stream(void) */

int __thiscall TSound_Driver::stop_stream(TSound_Driver *this)
{
  int iVar1;
  
  if (this->ready == '\0') {
    return 0;
  }
  iVar1 = ds_stream_stop();
  return iVar1;
}

// --------------------------------------------------

// Function: handle_messages
// Address: 004bc980
/* public: unsigned int __thiscall TSound_Driver::handle_messages(void *,unsigned int,unsigned
   int,long) */

uint __thiscall
TSound_Driver::handle_messages
          (TSound_Driver *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  uint uVar1;
  
  if (this->ready == '\0') {
    return 0;
  }
  uVar1 = ds_stream_messages(param_1,param_2,param_3,param_4);
  return uVar1;
}

// --------------------------------------------------

// Function: add_to_play_list
// Address: 004bc9b0
/* public: int __thiscall TSound_Driver::add_to_play_list(class TDigital *) */

int __thiscall TSound_Driver::add_to_play_list(TSound_Driver *this,TDigital *param_1)
{
  if ((this->play_list_count != 0xff) && (this->mute == '\0')) {
    this->sound_play_list[this->play_list_count] = param_1;
    this->play_list_count = this->play_list_count + 1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: play_list
// Address: 004bc9f0
/* public: void __thiscall TSound_Driver::play_list(void) */

void __thiscall TSound_Driver::play_list(TSound_Driver *this)
{
  int iVar1;
  TDigital **ppTVar2;
  
  iVar1 = 0;
  if (0 < this->play_list_count) {
    ppTVar2 = this->sound_play_list;
    do {
      TDigital::play(*ppTVar2);
      iVar1 = iVar1 + 1;
      ppTVar2 = ppTVar2 + 1;
    } while (iVar1 < this->play_list_count);
  }
  return;
}

// --------------------------------------------------

// Function: reset_play_list
// Address: 004bca20
/* public: void __thiscall TSound_Driver::reset_play_list(void) */

void __thiscall TSound_Driver::reset_play_list(TSound_Driver *this)
{
  this->play_list_count = 0;
  return;
}

// --------------------------------------------------

// Function: open_mixer
// Address: 004bca30
/* WARNING: Variable defined which should be unmapped: mixer_id */
/* public: int __thiscall TSound_Driver::open_mixer(void) */

int __thiscall TSound_Driver::open_mixer(TSound_Driver *this)
{
  void **ppvVar1;
  tagMIXERLINEA *ptVar2;
  tagMIXERLINECONTROLSA *ptVar3;
  tMIXERCONTROLDETAILS *ptVar4;
  void *pvVar5;
  ulong uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint unaff_ESI;
  tagMIXERLINEA *ptVar11;
  tagMIXERLINECONTROLSA *ptVar12;
  tagMIXERCONTROLA *ptVar13;
  tMIXERCONTROLDETAILS *ptVar14;
  uint mixer_id;
  uint num_dev;
  
  uVar8 = mixerGetNumDevs();
  if ((uVar8 == 0) || (uVar10 = 0, uVar8 == 0)) {
    return 0;
  }
  ppvVar1 = &this->mixer_handle;
  do {
    iVar9 = mixerOpen(ppvVar1,uVar10,0,0,0);
    if (iVar9 == 0) {
      ptVar2 = &this->mixer_line_info;
      ptVar11 = ptVar2;
      for (iVar9 = 0x2a; iVar9 != 0; iVar9 = iVar9 + -1) {
        ptVar11->cbStruct = 0;
        ptVar11 = (tagMIXERLINEA *)&ptVar11->dwDestination;
      }
      pvVar5 = *ppvVar1;
      ptVar2->cbStruct = 0xa8;
                    /* language.dll match for 0x1008: "Trade" */
      (this->mixer_line_info).dwComponentType = 0x1008;
      iVar9 = mixerGetLineInfoA(pvVar5,ptVar2,3);
      if (iVar9 == 0) {
        ptVar3 = &this->mixer_line_controls;
        ptVar12 = ptVar3;
        for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
          ptVar12->cbStruct = 0;
          ptVar12 = (tagMIXERLINECONTROLSA *)&ptVar12->dwLineID;
        }
        ptVar13 = &this->mixer_volume_control;
        for (iVar9 = 0x25; iVar9 != 0; iVar9 = iVar9 + -1) {
          ptVar13->cbStruct = 0;
          ptVar13 = (tagMIXERCONTROLA *)&ptVar13->dwControlID;
        }
        uVar6 = (this->mixer_line_info).dwLineID;
        ptVar3->cbStruct = 0x18;
        pvVar5 = *ppvVar1;
        (this->mixer_line_controls).dwLineID = uVar6;
        (this->mixer_line_controls).field2_0x8.dwControlID = 0x50030001;
        (this->mixer_line_controls).cControls = 1;
        (this->mixer_line_controls).cbmxctrl = 0x94;
        (this->mixer_line_controls).pamxctrl = &this->mixer_volume_control;
        iVar9 = mixerGetLineControlsA(pvVar5,ptVar3,2);
        uVar10 = unaff_ESI;
        if (iVar9 == 0) {
          ptVar4 = &this->mixer_volume_details;
          ptVar14 = ptVar4;
          for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
            ptVar14->cbStruct = 0;
            ptVar14 = (tMIXERCONTROLDETAILS *)&ptVar14->dwControlID;
          }
          (this->mixer_volume_value).dwValue = 0;
          uVar6 = (this->mixer_volume_control).dwControlID;
          ptVar4->cbStruct = 0x18;
          pvVar5 = *ppvVar1;
          (this->mixer_volume_details).dwControlID = uVar6;
          (this->mixer_volume_details).cChannels = 1;
          (this->mixer_volume_details).cbDetails = 4;
          (this->mixer_volume_details).paDetails = &this->mixer_volume_value;
          iVar9 = mixerGetControlDetailsA(pvVar5,ptVar4,0);
          if (iVar9 == 0) {
            uVar6 = (this->mixer_volume_value).dwValue;
            iVar9 = (this->mixer_volume_control).Bounds._s_0.lMaximum;
            iVar7 = (this->mixer_volume_control).Bounds._s_0.lMinimum;
            this->mixer_open = 1;
            iVar9 = (uVar6 * 10000) / (uint)(iVar9 - iVar7) - 10000;
            this->start_volume = iVar9;
            this->volume = iVar9;
            return 1;
          }
        }
      }
      mixerClose(*ppvVar1);
      *ppvVar1 = (void *)0x0;
    }
    uVar10 = uVar10 + 1;
    if (uVar8 <= uVar10) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: close_mixer
// Address: 004bcbf0
/* public: void __thiscall TSound_Driver::close_mixer(void) */

void __thiscall TSound_Driver::close_mixer(TSound_Driver *this)
{
  if (this->mixer_open != 0) {
    if (this->start_volume != 1) {
      set_volume(this,this->start_volume,0);
      this->start_volume = 1;
    }
    if (this->mixer_handle != (void *)0x0) {
      mixerClose(this->mixer_handle);
      this->mixer_handle = (void *)0x0;
    }
    this->mixer_open = 0;
  }
  return;
}

// --------------------------------------------------

