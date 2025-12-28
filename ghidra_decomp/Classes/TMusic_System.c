// Class: TMusic_System
// Size:  0x3F8
//
// Member Layout:
// [0x000] char[260] path (sz: 0x104)
// [0x104] uchar music_type
// [0x108] TSound_Driver * sound_system
// [0x10C] void * instance
// [0x110] void * window
// [0x114] int device_open
// [0x118] uint device_id
// [0x11C] tagMCI_PLAY_PARMS play_info (sz: 0xC)
// [0x128] uchar playing_track
// [0x129] char[261] file_name (sz: 0x105)
// [0x230] int start_track
// [0x234] int end_track
// [0x238] int make_cur_track
// [0x23C] ulong set_pos
// [0x240] int loop
// [0x244] int current_track
// [0x248] int track_count
// [0x24C] int notify_waiting
// [0x250] long start_volume
// [0x254] long volume
// [0x258] int paused
// [0x25C] int auto_paused
// [0x260] int inactivated
// [0x264] int fade_out
// [0x268] ulong fade_time
// [0x26C] int fading_track
// [0x270] long fade_volume
// [0x274] ulong last_fade_time
// [0x278] int mixer_open
// [0x27C] void * mixer_handle
// [0x280] tagMIXERLINEA mixer_line_info (sz: 0xA8)
// [0x328] tagMIXERLINECONTROLSA mixer_line_controls (sz: 0x18)
// [0x340] tagMIXERCONTROLA mixer_volume_control (sz: 0x94)
// [0x3D4] tMIXERCONTROLDETAILS mixer_volume_details (sz: 0x18)
// [0x3EC] tMIXERCONTROLDETAILS_UNSIGNED mixer_volume_value
// [0x3F0] void * midi_window
// [0x3F4] ulong last_check_time
// ----------------------------------------------------------------

// Function: TMusic_System
// Address: 00461910
/* public: __thiscall TMusic_System::TMusic_System(unsigned char,void *,void *,class TSound_Driver
   *,char *) */

TMusic_System * __thiscall
TMusic_System::TMusic_System
          (TMusic_System *this,uchar param_1,void *param_2,void *param_3,TSound_Driver *param_4,
          char *param_5)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  TMusic_System *pTVar5;
  
  this->music_type = param_1;
  this->sound_system = param_4;
  this->window = param_3;
  this->instance = param_2;
  this->device_open = 0;
  this->device_id = 0;
  this->playing_track = '\0';
  this->start_track = 0;
  this->end_track = 0;
  this->make_cur_track = 0;
  this->set_pos = 0;
  this->loop = 0;
  this->current_track = 0;
  this->track_count = 0;
  this->notify_waiting = 0;
  this->start_volume = 1;
  this->volume = 0;
  this->paused = 0;
  this->auto_paused = 0;
  this->inactivated = 0;
  this->fade_out = 0;
  this->fade_time = 2000;
  this->fading_track = 0;
  this->last_fade_time = 0;
  this->mixer_open = 0;
  this->mixer_handle = (void *)0x0;
  this->midi_window = (void *)0x0;
  this->file_name[0] = '\0';
  if (param_5 == (char *)0x0) {
    this->path[0] = '\0';
    open_device(this);
    return this;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_5 + 1;
    cVar1 = *param_5;
    param_5 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pTVar5 = this;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pTVar5->path = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pTVar5 = (TMusic_System *)(pTVar5->path + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    pTVar5->path[0] = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pTVar5 = (TMusic_System *)(pTVar5->path + 1);
  }
  open_device(this);
  return this;
}

// --------------------------------------------------

// Function: close_device
// Address: 00461a19
void __thiscall TMusic_System::close_device(TMusic_System *this)
{
  uchar uVar1;
  
  if (this->device_open != 0) {
    stop_track(this);
    uVar1 = this->music_type;
    if (uVar1 == '\x01') {
      if (this->start_volume != 1) {
        set_volume(this,this->start_volume,0);
        this->start_volume = 1;
      }
      close_mixer(this);
      mciSendCommandA(this->device_id,0x804,2,0);
      this->device_id = 0;
      this->device_open = 0;
      this->track_count = 0;
    }
    else {
      if (uVar1 == '\x02') {
        if (this->start_volume != 1) {
          set_volume(this,this->start_volume,0);
          this->start_volume = 1;
        }
        close_mixer(this);
        this->device_open = 0;
        this->track_count = 0;
        return;
      }
      if (uVar1 == '\x03') {
        this->track_count = 0;
        this->device_open = 0;
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: ~TMusic_System
// Address: 00461a20
/* public: __thiscall TMusic_System::~TMusic_System(void) */

void __thiscall TMusic_System::~TMusic_System(TMusic_System *this)
{
  uchar uVar1;
  
  if (this->device_open != 0) {
    stop_track(this);
    uVar1 = this->music_type;
    if (uVar1 == '\x01') {
      if (this->start_volume != 1) {
        set_volume(this,this->start_volume,0);
        this->start_volume = 1;
      }
      close_mixer(this);
      mciSendCommandA(this->device_id,0x804,2,0);
      this->device_id = 0;
      this->device_open = 0;
      this->track_count = 0;
    }
    else {
      if (uVar1 == '\x02') {
        if (this->start_volume != 1) {
          set_volume(this,this->start_volume,0);
          this->start_volume = 1;
        }
        close_mixer(this);
        this->device_open = 0;
        this->track_count = 0;
        return;
      }
      if (uVar1 == '\x03') {
        this->track_count = 0;
        this->device_open = 0;
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: open_device
// Address: 00461a30
// [HELPER] s__smusic_d_mid: "%smusic%d.mid"
// [HELPER] s__smusic_d_wav: "%smusic%d.wav"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: status_info */
/* public: int __thiscall TMusic_System::open_device(void) */

int __thiscall TMusic_System::open_device(TMusic_System *this)
{
  uchar uVar1;
  int iVar2;
  tagMCI_STATUS_PARMS status_info;
  tagMCI_SET_PARMS set_info;
  tagMCI_OPEN_PARMSA open_info;
  char file_name [261];
  
  uVar1 = this->music_type;
  if (uVar1 == '\x01') {
    open_info.lpstrElementName = (char *)0x204;
    iVar2 = mciSendCommandA(0,0x803,0x3102,&open_info.wDeviceID);
    if (iVar2 == 0) {
      this->device_open = 1;
      this->device_id = (uint)open_info.lpstrDeviceType;
      set_info.dwAudio = 10;
      mciSendCommandA(open_info.lpstrDeviceType,0x80d,0x402,&set_info.dwTimeFormat);
      status_info.dwTrack = 3;
      iVar2 = mciSendCommandA(this->device_id,0x814,0x102,&status_info.dwReturn);
      if (iVar2 == 0) {
        this->track_count = status_info.dwItem;
      }
      iVar2 = open_mixer(this);
      if (iVar2 != 0) {
        iVar2 = ((this->mixer_volume_value).dwValue * 10000) /
                (uint)((this->mixer_volume_control).Bounds._s_0.lMaximum -
                      (this->mixer_volume_control).Bounds._s_0.lMinimum) - 10000;
        this->start_volume = iVar2;
        this->volume = iVar2;
      }
      return 1;
    }
  }
  else {
    if (uVar1 == '\x02') {
      iVar2 = open_mixer(this);
      if (iVar2 != 0) {
        iVar2 = ((this->mixer_volume_value).dwValue * 10000) /
                (uint)((this->mixer_volume_control).Bounds._s_0.lMaximum -
                      (this->mixer_volume_control).Bounds._s_0.lMinimum) - 10000;
        this->start_volume = iVar2;
        this->volume = iVar2;
      }
      this->track_count = 0;
      while( true ) {
        sprintf(file_name + 4,s__smusic_d_mid,this,this->track_count + 1);
        iVar2 = fopen(file_name + 4,s_r);
        if (iVar2 == 0) break;
        fclose(iVar2);
        this->track_count = this->track_count + 1;
      }
      this->device_open = 1;
      return 1;
    }
    if (uVar1 == '\x03') {
      this->track_count = 0;
      while( true ) {
        sprintf(file_name + 4,s__smusic_d_wav,this,this->track_count + 1);
        iVar2 = fopen(file_name + 4,s_r);
        if (iVar2 == 0) break;
        fclose(iVar2);
        this->track_count = this->track_count + 1;
      }
      this->volume = 0;
      this->device_open = 1;
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: close_device
// Address: 00461c60
/* public: void __thiscall TMusic_System::close_device(void) */

void __thiscall TMusic_System::close_device(TMusic_System *this)
{
  uchar uVar1;
  
  if (this->device_open != 0) {
    stop_track(this);
    uVar1 = this->music_type;
    if (uVar1 == '\x01') {
      if (this->start_volume != 1) {
        set_volume(this,this->start_volume,0);
        this->start_volume = 1;
      }
      close_mixer(this);
      mciSendCommandA(this->device_id,0x804,2,0);
      this->device_id = 0;
      this->device_open = 0;
      this->track_count = 0;
    }
    else {
      if (uVar1 == '\x02') {
        if (this->start_volume != 1) {
          set_volume(this,this->start_volume,0);
          this->start_volume = 1;
        }
        close_mixer(this);
        this->device_open = 0;
        this->track_count = 0;
        return;
      }
      if (uVar1 == '\x03') {
        this->track_count = 0;
        this->device_open = 0;
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: open_mixer
// Address: 00461d20
/* WARNING: Variable defined which should be unmapped: mixer_id */
/* protected: int __thiscall TMusic_System::open_mixer(void) */

int __thiscall TMusic_System::open_mixer(TMusic_System *this)
{
  void **ppvVar1;
  tagMIXERLINEA *ptVar2;
  tagMIXERLINECONTROLSA *ptVar3;
  tMIXERCONTROLDETAILS *ptVar4;
  uchar uVar5;
  ulong uVar6;
  void *pvVar7;
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
      uVar5 = this->music_type;
      ptVar2->cbStruct = 0xa8;
      if (uVar5 == '\x01') {
                    /* language.dll match for 0x1005: "Work (W)" */
        (this->mixer_line_info).dwComponentType = 0x1005;
      }
      else {
        (this->mixer_line_info).dwComponentType = 0x1004;
      }
      iVar9 = mixerGetLineInfoA(*ppvVar1,ptVar2,3);
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
        pvVar7 = *ppvVar1;
        (this->mixer_line_controls).dwLineID = uVar6;
        (this->mixer_line_controls).field2_0x8.dwControlID = 0x50030001;
        (this->mixer_line_controls).cControls = 1;
        (this->mixer_line_controls).cbmxctrl = 0x94;
        (this->mixer_line_controls).pamxctrl = &this->mixer_volume_control;
        iVar9 = mixerGetLineControlsA(pvVar7,ptVar3,2);
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
          pvVar7 = *ppvVar1;
          (this->mixer_volume_details).dwControlID = uVar6;
          (this->mixer_volume_details).cChannels = 1;
          (this->mixer_volume_details).cbDetails = 4;
          (this->mixer_volume_details).paDetails = &this->mixer_volume_value;
          iVar9 = mixerGetControlDetailsA(pvVar7,ptVar4,0);
          if (iVar9 == 0) {
            this->mixer_open = 1;
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
// Address: 00461ec0
/* protected: void __thiscall TMusic_System::close_mixer(void) */

void __thiscall TMusic_System::close_mixer(TMusic_System *this)
{
  if (this->mixer_open != 0) {
    if (this->mixer_handle != (void *)0x0) {
      mixerClose(this->mixer_handle);
      this->mixer_handle = (void *)0x0;
    }
    this->mixer_open = 0;
  }
  return;
}

// --------------------------------------------------

// Function: set_music_type
// Address: 00461f00
/* public: int __thiscall TMusic_System::set_music_type(unsigned char) */

int __thiscall TMusic_System::set_music_type(TMusic_System *this,uchar param_1)
{
  int iVar1;
  
  if (param_1 == this->music_type) {
    return this->device_open;
  }
  close_device(this);
  this->music_type = param_1;
  iVar1 = open_device(this);
  return iVar1;
}

// --------------------------------------------------

// Function: set_fade_out
// Address: 00461f40
/* public: void __thiscall TMusic_System::set_fade_out(int,unsigned long) */

void __thiscall TMusic_System::set_fade_out(TMusic_System *this,int param_1,ulong param_2)
{
  this->fade_out = param_1;
  this->fade_time = param_2;
  return;
}

// --------------------------------------------------

// Function: set_volume
// Address: 00461f60
/* public: void __thiscall TMusic_System::set_volume(long,int) */

void __thiscall TMusic_System::set_volume(TMusic_System *this,long param_1,int param_2)
{
  uchar uVar1;
  int iVar2;
  
  if (param_1 < -10000) {
    param_1 = -10000;
  }
  else if (0 < param_1) {
    param_1 = 0;
  }
  if (param_2 != 0) {
    this->volume = param_1;
  }
  if (this->device_open != 0) {
    uVar1 = this->music_type;
    if (uVar1 == '\x01') {
      iVar2 = this->mixer_open;
    }
    else {
      if (uVar1 != '\x02') {
        if (uVar1 != '\x03') {
          return;
        }
        if (this->sound_system == (TSound_Driver *)0x0) {
          return;
        }
        TSound_Driver::set_stream_volume(this->sound_system,param_1);
        return;
      }
      iVar2 = this->mixer_open;
    }
    if (iVar2 != 0) {
      (this->mixer_volume_value).dwValue =
           (uint)(((this->mixer_volume_control).Bounds._s_0.lMaximum -
                  (this->mixer_volume_control).Bounds._s_0.lMinimum) * (param_1 + 10000)) / 10000;
      mixerSetControlDetails(this->mixer_handle,&this->mixer_volume_details,0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: play_track
// Address: 00462010
/* public: int __thiscall TMusic_System::play_track(int,int,unsigned long) */

int __thiscall TMusic_System::play_track(TMusic_System *this,int param_1,int param_2,ulong param_3)
{
  int iVar1;
  
  this->file_name[0] = '\0';
  this->start_track = param_1;
  this->end_track = param_1;
  this->make_cur_track = 0;
  this->set_pos = param_3;
  this->loop = param_2;
  if (((this->playing_track != '\0') && (this->fade_out != 0)) && (this->fade_time != 0)) {
    start_fade(this);
    return 1;
  }
  iVar1 = play(this,param_1,param_1,(char *)0x0,0,param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: play_file
// Address: 00462090
/* public: int __thiscall TMusic_System::play_file(char *,int,unsigned long) */

int __thiscall TMusic_System::play_file(TMusic_System *this,char *param_1,int param_2,ulong param_3)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (this->music_type == '\x01') {
    return 0;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar5 = param_1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  pcVar6 = this->file_name;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  this->start_track = 0;
  this->end_track = 0;
  this->make_cur_track = 0;
  this->set_pos = param_3;
  this->loop = param_2;
  if (((this->playing_track != '\0') && (this->fade_out != 0)) && (this->fade_time != 0)) {
    start_fade(this);
    return 1;
  }
  iVar2 = play(this,0,0,this->file_name,0,param_3);
  return iVar2;
}

// --------------------------------------------------

// Function: play_tracks
// Address: 00462140
/* public: int __thiscall TMusic_System::play_tracks(int,int,int,int,unsigned long) */

int __thiscall
TMusic_System::play_tracks
          (TMusic_System *this,int param_1,int param_2,int param_3,int param_4,ulong param_5)
{
  int iVar1;
  int iVar2;
  
  this->loop = param_3;
  iVar2 = this->track_count;
  this->file_name[0] = '\0';
  this->start_track = param_1;
  this->end_track = param_2;
  this->make_cur_track = param_4;
  this->set_pos = param_5;
  if (iVar2 == 0) {
    return iVar2;
  }
  if (iVar2 < param_1) {
    this->start_track = iVar2;
  }
  iVar1 = this->start_track;
  if (param_2 < iVar1) {
    this->end_track = iVar1;
  }
  else if (iVar2 < param_2) {
    this->end_track = iVar2;
  }
  if (((this->playing_track != '\0') && (this->fade_out != 0)) && (this->fade_time != 0)) {
    start_fade(this);
    return 1;
  }
  iVar2 = play(this,iVar1,this->end_track,(char *)0x0,param_4,param_5);
  return iVar2;
}

// --------------------------------------------------

// Function: play
// Address: 00462200
// [HELPER] s_Unknow_Error: "Unknow Error"
// [HELPER] s__mid: ".mid"
// [HELPER] s__s_s: "%s%s"
// [HELPER] s__smusic_d_mid: "%smusic%d.mid"
// [HELPER] s__smusic_d_wav: "%smusic%d.wav"
/* WARNING: Variable defined which should be unmapped: seek_info */
/* protected: int __thiscall TMusic_System::play(int,int,char *,int,unsigned long) */

int __thiscall
TMusic_System::play(TMusic_System *this,int param_1,int param_2,char *param_3,int param_4,
                   ulong param_5)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  code *pcVar8;
  char *pcVar9;
  char *pcVar10;
  tagMCI_SEEK_PARMS seek_info;
  tagMCI_OPEN_PARMSA open_info;
  char track_name [261];
  char szErrorMsg [256];
  
  if (this->device_open == 0) {
    return 0;
  }
  if (this->playing_track != '\0') {
    stop_playing(this);
  }
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    if (this->track_count == 0) {
      return 0;
    }
    if (this->track_count < param_1) {
      return 0;
    }
    if (param_1 == 0) {
      return 0;
    }
    if (param_4 == 0) {
      this->current_track = param_1;
    }
    else {
      this->current_track = param_4;
    }
  }
  uVar2 = this->music_type;
  if (uVar2 == '\x01') {
    (this->play_info).dwCallback = (ulong)this->window;
    uVar5 = 1;
    if (param_5 == 0) {
      uVar5 = 5;
      (this->play_info).dwFrom = (uint)(byte)this->current_track;
    }
    else {
      open_info.dwCallback = param_5;
      seek_info.dwTo = 0;
      mciSendCommandA(this->device_id,0x807,10,&seek_info.dwTo);
    }
    if ((param_1 < this->track_count) && (param_2 < this->track_count)) {
      uVar5 = uVar5 | 8;
      (this->play_info).dwTo = (uint)(byte)((char)param_2 + 1);
    }
    iVar3 = mciSendCommandA(this->device_id,0x806,uVar5,&this->play_info);
    if (iVar3 == 0) {
      this->playing_track = '\x01';
      this->notify_waiting = this->notify_waiting + 1;
    }
    else {
      iVar3 = mciGetErrorStringA(iVar3,szErrorMsg + 4,0x100);
      if (iVar3 == 0) {
        uVar5 = 0xffffffff;
        pcVar10 = &s_Unknow_Error;
        do {
          pcVar7 = pcVar10;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar7 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar7;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        pcVar10 = szErrorMsg;
        pcVar7 = pcVar7 + -uVar5;
        for (uVar6 = uVar5 >> 2; pcVar10 = pcVar10 + 4, uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar10 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar10 = pcVar10 + 1;
        }
      }
    }
  }
  else if (uVar2 == '\x02') {
    if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
      sprintf(track_name + 4,s__smusic_d_mid,this,this->current_track);
    }
    else {
      sprintf(track_name + 4,s__s_s,this,param_3);
      iVar3 = strchr(track_name + 4,0x2e);
      if (iVar3 == 0) {
        uVar5 = 0xffffffff;
        pcVar10 = &s__mid;
        do {
          pcVar7 = pcVar10;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar7 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar7;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        iVar3 = -1;
        pcVar10 = track_name + 4;
        do {
          pcVar9 = pcVar10;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        pcVar10 = pcVar7 + -uVar5;
        pcVar7 = pcVar9 + -1;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar7 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
    }
    iVar3 = __open(track_name + 4,0);
    if (iVar3 != -1) {
      close(iVar3);
      pcVar8 = mciSendCommandA_exref;
      open_info.lpstrAlias = track_name + 4;
      open_info.lpstrElementName = (char *)0x20b;
      iVar3 = mciSendCommandA(0,0x803,0x3200,&open_info.wDeviceID);
      if (iVar3 != 0) {
        iVar4 = mciGetErrorStringA(iVar3,szErrorMsg + 4,0x100);
        if (iVar4 == 0) {
          uVar5 = 0xffffffff;
          pcVar10 = &s_Unknow_Error;
          do {
            pcVar7 = pcVar10;
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            pcVar7 = pcVar10 + 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar7;
          } while (cVar1 != '\0');
          uVar5 = ~uVar5;
          pcVar10 = szErrorMsg;
          pcVar7 = pcVar7 + -uVar5;
          for (uVar6 = uVar5 >> 2; pcVar10 = pcVar10 + 4, uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
          }
          for (uVar5 = uVar5 & 3; pcVar8 = mciSendCommandA_exref, uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar10 = *pcVar7;
            pcVar7 = pcVar7 + 1;
            pcVar10 = pcVar10 + 1;
          }
        }
        if (iVar3 != 0) goto LAB_00462579;
      }
      this->device_id = (uint)open_info.lpstrDeviceType;
      if (param_5 != 0) {
        open_info.dwCallback = param_5;
        seek_info.dwTo = 0;
        (*pcVar8)(open_info.lpstrDeviceType,0x807,8,&seek_info.dwTo);
      }
      (this->play_info).dwCallback = (ulong)this->window;
      iVar3 = (*pcVar8)(this->device_id,0x806,1,&this->play_info);
      if (iVar3 == 0) {
        this->playing_track = '\x01';
        this->notify_waiting = this->notify_waiting + 1;
      }
    }
  }
  else if ((uVar2 == '\x03') && (this->sound_system != (TSound_Driver *)0x0)) {
    if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
      param_3 = (char *)this->current_track;
      pcVar10 = s__smusic_d_wav;
    }
    else {
      pcVar10 = s__s_s;
    }
    sprintf(track_name + 4,pcVar10,this,param_3);
    iVar3 = TSound_Driver::stream_file(this->sound_system,track_name + 4,0,this->volume);
    if (iVar3 == 0) {
      return 0;
    }
    this->playing_track = '\x01';
  }
LAB_00462579:
  if (this->playing_track == '\0') {
    return 0;
  }
  this->paused = 0;
  this->auto_paused = 0;
  this->inactivated = 0;
  return 1;
}

// --------------------------------------------------

// Function: pause_play
// Address: 004625c0
/* public: int __thiscall TMusic_System::pause_play(void) */

int __thiscall TMusic_System::pause_play(TMusic_System *this)
{
  uchar uVar1;
  
  if ((this->device_open == 0) || (this->playing_track == '\0')) {
    return 0;
  }
  if (this->paused != 0) {
    this->auto_paused = 0;
    return 1;
  }
  this->paused = 1;
  if (this->auto_paused != 0) {
    this->auto_paused = 0;
    return 1;
  }
  uVar1 = this->music_type;
  if (uVar1 == '\x01') {
    mciSendCommandA(this->device_id,0x809,2,0);
  }
  else {
    if (uVar1 == '\x02') {
      mciSendCommandA(this->device_id,0x809,2,0);
      return 1;
    }
    if ((uVar1 == '\x03') && (this->sound_system != (TSound_Driver *)0x0)) {
      TSound_Driver::pause_stream(this->sound_system);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: resume_play
// Address: 00462670
/* public: int __thiscall TMusic_System::resume_play(void) */

int __thiscall TMusic_System::resume_play(TMusic_System *this)
{
  uchar uVar1;
  int iVar2;
  
  if (((this->device_open == 0) || (this->playing_track == '\0')) || (this->paused == 0)) {
    return 0;
  }
  this->paused = 0;
  this->auto_paused = 0;
  if (this->fading_track != 0) {
    end_fade(this);
    return 1;
  }
  uVar1 = this->music_type;
  if (uVar1 == '\x01') {
    iVar2 = mciSendCommandA(this->device_id,0x806,0,&this->play_info);
  }
  else {
    if (uVar1 != '\x02') {
      if (uVar1 != '\x03') {
        return 1;
      }
      if (this->sound_system == (TSound_Driver *)0x0) {
        return 1;
      }
      TSound_Driver::resume_stream(this->sound_system);
      return 1;
    }
    iVar2 = mciSendCommandA(this->device_id,0x806,0,&this->play_info);
  }
  if (iVar2 == 0) {
    this->notify_waiting = this->notify_waiting + 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: stop_track
// Address: 00462740
/* public: int __thiscall TMusic_System::stop_track(void) */

int __thiscall TMusic_System::stop_track(TMusic_System *this)
{
  int iVar1;
  
  this->loop = 0;
  this->start_track = 0;
  this->end_track = 0;
  this->file_name[0] = '\0';
  this->fading_track = 0;
  iVar1 = stop_playing(this);
  return iVar1;
}

// --------------------------------------------------

// Function: stop_playing
// Address: 00462770
/* protected: int __thiscall TMusic_System::stop_playing(void) */

int __thiscall TMusic_System::stop_playing(TMusic_System *this)
{
  uchar uVar1;
  
  if (this->playing_track == '\0') {
    return 1;
  }
  uVar1 = this->music_type;
  if (uVar1 == '\x01') {
    mciSendCommandA(this->device_id,0x808,2,0);
    this->playing_track = '\0';
  }
  else if (uVar1 == '\x02') {
    mciSendCommandA(this->device_id,0x808,2,0);
    this->playing_track = '\0';
    mciSendCommandA(this->device_id,0x804,2,0);
    this->device_id = 0;
  }
  else if ((uVar1 == '\x03') && (this->sound_system != (TSound_Driver *)0x0)) {
    TSound_Driver::stop_stream(this->sound_system);
  }
  this->playing_track = '\0';
  this->paused = 0;
  this->auto_paused = 0;
  return 1;
}

// --------------------------------------------------

// Function: fade_track
// Address: 00462820
/* public: int __thiscall TMusic_System::fade_track(void) */

int __thiscall TMusic_System::fade_track(TMusic_System *this)
{
  this->loop = 0;
  this->start_track = 0;
  this->end_track = 0;
  this->file_name[0] = '\0';
  this->fading_track = 0;
  if (this->playing_track != '\0') {
    start_fade(this);
  }
  return 1;
}

// --------------------------------------------------

// Function: start_fade
// Address: 00462860
// [HELPER] s_C__msdev_work_age1_x1_music_cpp: "C:\msdev\work\age1_x1\music.cpp"
/* protected: void __thiscall TMusic_System::start_fade(void) */

void __thiscall TMusic_System::start_fade(TMusic_System *this)
{
  ulong uVar1;
  
  if (this->fading_track == 0) {
    this->fade_volume = this->volume;
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_music_cpp,0x38c);
    this->last_fade_time = uVar1;
    this->fading_track = 1;
  }
  return;
}

// --------------------------------------------------

// Function: do_fade
// Address: 004628a0
// [HELPER] s_C__msdev_work_age1_x1_music_cpp: "C:\msdev\work\age1_x1\music.cpp"
/* WARNING: Variable defined which should be unmapped: time */
/* protected: void __thiscall TMusic_System::do_fade(void) */

void __thiscall TMusic_System::do_fade(TMusic_System *this)
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  float time;
  
  if (this->paused == 0) {
    debug_timeGetTime(s_C__msdev_work_age1_x1_music_cpp,0x39e);
    if ((this->fade_volume < -9999) && (this->playing_track != '\0')) {
      stop_playing(this);
    }
    iVar1 = __ftol();
    iVar1 = this->fade_volume + iVar1;
    this->fade_volume = iVar1;
    iVar2 = __ftol();
    if (-10000 - iVar2 < iVar1) {
      set_volume(this,iVar1,0);
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_music_cpp,0x3b8);
      this->last_fade_time = uVar3;
    }
    else {
      if (this->playing_track != '\0') {
        stop_playing(this);
      }
      if (this->fading_track != 0) {
        end_fade(this);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: end_fade
// Address: 004629b0
/* protected: void __thiscall TMusic_System::end_fade(void) */

void __thiscall TMusic_System::end_fade(TMusic_System *this)
{
  this->fading_track = 0;
  set_volume(this,this->volume,0);
  if (((0 < this->start_track) && (0 < this->end_track)) || (this->file_name[0] != '\0')) {
    play(this,this->start_track,this->end_track,this->file_name,this->make_cur_track,this->set_pos);
  }
  return;
}

// --------------------------------------------------

// Function: handle_messages
// Address: 00462a10
/* public: unsigned int __thiscall TMusic_System::handle_messages(void *,unsigned int,unsigned
   int,long) */

uint __thiscall
TMusic_System::handle_messages
          (TMusic_System *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  uchar uVar1;
  
  if (param_2 < 0x114) {
    if (param_2 == 0x113) {
      if (this->fading_track != 0) {
        do_fade(this);
        return 0;
      }
    }
    else if (param_2 == 0x1c) {
      if (param_3 == 0) {
        if (this->inactivated == 0) {
          pause_play(this);
          this->auto_paused = 1;
          this->inactivated = 1;
          return 0;
        }
      }
      else if ((this->inactivated != 0) && (this->auto_paused != 0)) {
        resume_play(this);
        this->auto_paused = 0;
        this->inactivated = 0;
        return 0;
      }
    }
  }
  else if (param_2 == 0x3b9) {
    uVar1 = this->music_type;
    if ((uVar1 == '\x01') || (uVar1 == '\x02')) {
      if (0 < this->notify_waiting) {
        this->notify_waiting = this->notify_waiting + -1;
      }
      if ((this->notify_waiting == 0) && (this->paused == 0)) {
        if (uVar1 == '\x01') {
          this->playing_track = '\0';
        }
        after_end_track(this);
      }
    }
  }
  else if (((param_2 == 0x500) && (this->music_type == '\x03')) && (this->paused == 0)) {
    this->playing_track = '\0';
    after_end_track(this);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: after_end_track
// Address: 00462b40
/* protected: void __thiscall TMusic_System::after_end_track(void) */

void __thiscall TMusic_System::after_end_track(TMusic_System *this)
{
  uchar uVar1;
  int iVar2;
  char cVar3;
  
  uVar1 = this->music_type;
  if (uVar1 == '\x01') {
    if (this->fading_track != 0) {
      return;
    }
    if (this->loop == 0) {
      return;
    }
  }
  else {
    if (uVar1 == '\x02') {
      if (this->fading_track != 0) {
        return;
      }
      cVar3 = this->file_name[0];
      if ((cVar3 == '\0') && (this->current_track < this->end_track)) {
        iVar2 = this->current_track + 1;
        play(this,iVar2,iVar2,(char *)0x0,0,0);
        return;
      }
    }
    else {
      if (uVar1 != '\x03') {
        return;
      }
      if (this->fading_track != 0) {
        return;
      }
      cVar3 = this->file_name[0];
      if ((cVar3 == '\0') && (this->current_track < this->end_track)) {
        iVar2 = this->current_track + 1;
        play(this,iVar2,iVar2,(char *)0x0,0,0);
        return;
      }
    }
    if (this->loop == 0) {
      return;
    }
    if (cVar3 != '\0') {
      play(this,0,0,this->file_name,0,0);
      return;
    }
  }
  play(this,this->start_track,this->end_track,(char *)0x0,0,0);
  return;
}

// --------------------------------------------------

// Function: get_play_info
// Address: 00462c30
/* WARNING: Variable defined which should be unmapped: status_info */
/* public: int __thiscall TMusic_System::get_play_info(unsigned char *,int *,int *,int *,char *,int
   *,unsigned long *) */

int __thiscall
TMusic_System::get_play_info
          (TMusic_System *this,uchar *param_1,int *param_2,int *param_3,int *param_4,char *param_5,
          int *param_6,ulong *param_7)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  tagMCI_STATUS_PARMS status_info;
  
  *param_1 = this->music_type;
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = '\0';
  *param_6 = 0;
  *param_7 = 0;
  if (this->device_open == 0) {
    return 0;
  }
  if (this->playing_track != '\0') {
    *param_2 = this->start_track;
    *param_3 = this->end_track;
    *param_4 = this->current_track;
    uVar3 = 0xffffffff;
    pcVar5 = this->file_name;
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
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)param_5 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      param_5 = param_5 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_5 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      param_5 = param_5 + 1;
    }
    *param_6 = this->loop;
    *param_7 = 0;
    if (this->music_type == '\x01') {
      status_info.dwTrack = 2;
      iVar2 = mciSendCommandA(this->device_id,0x814,0x102,&status_info.dwReturn);
    }
    else {
      if (this->music_type != '\x02') {
        return 1;
      }
      status_info.dwTrack = 2;
      iVar2 = mciSendCommandA(this->device_id,0x814,0x102,&status_info.dwReturn);
    }
    if (iVar2 == 0) {
      *param_7 = status_info.dwItem;
    }
  }
  return 1;
}

// --------------------------------------------------

