// Class: RGE_Sound
// Size:  0x10
//
// Member Layout:
// [0x000] short play_at_update_count
// [0x002] short sound_num
// [0x004] RGE_Sound_Info * sounds
// [0x008] ulong cache_time
// [0x00C] short id
// ----------------------------------------------------------------

// Function: RGE_Sound
// Address: 004bbe40
// [HELPER] s__d__s__hd: "%d %s %hd"
// [HELPER] s__hd: "%hd"
// [HELPER] s__wav: ".wav"
RGE_Sound * __thiscall RGE_Sound::RGE_Sound(RGE_Sound *this,_iobuf *param_1,short param_2)
{
  short *psVar1;
  char cVar2;
  RGE_Sound_Info *pRVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  psVar1 = &this->sound_num;
  this->id = param_2;
  this->play_at_update_count = 0;
  fscanf(param_1,s__hd,psVar1);
  if (*psVar1 < 1) {
    this->sounds = (RGE_Sound_Info *)0x0;
  }
  else {
    pRVar3 = (RGE_Sound_Info *)calloc((int)*psVar1,0x24);
    this->sounds = pRVar3;
    _param_2 = 0;
    iVar7 = 0;
    if (0 < *psVar1) {
      do {
        pcVar8 = this->sounds->name + iVar7;
        fscanf(param_1,s__d__s__hd,pcVar8 + 0x10,pcVar8,pcVar8 + 0x14);
        uVar4 = 0xffffffff;
        pcVar8 = &s__wav;
        do {
          pcVar10 = pcVar8;
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          pcVar10 = pcVar8 + 1;
          cVar2 = *pcVar8;
          pcVar8 = pcVar10;
        } while (cVar2 != '\0');
        uVar4 = ~uVar4;
        iVar5 = -1;
        pcVar8 = this->sounds->name + iVar7;
        do {
          pcVar9 = pcVar8;
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          pcVar9 = pcVar8 + 1;
          cVar2 = *pcVar8;
          pcVar8 = pcVar9;
        } while (cVar2 != '\0');
        pcVar8 = pcVar10 + -uVar4;
        pcVar10 = pcVar9 + -1;
        for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar10 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar10 = pcVar10 + 1;
        }
        pcVar8 = this->sounds->name + iVar7 + 0x18;
        pcVar8[0] = '\0';
        pcVar8[1] = '\0';
        pcVar8[2] = '\0';
        pcVar8[3] = '\0';
        _param_2 = _param_2 + 1;
        iVar7 = iVar7 + 0x24;
        if (this->sound_num <= _param_2) {
          this->cache_time = 300000;
          return this;
        }
      } while( true );
    }
  }
  this->cache_time = 300000;
  return this;
}

// --------------------------------------------------

// Function: RGE_Sound
// Address: 004bbf30
RGE_Sound * __thiscall RGE_Sound::RGE_Sound(RGE_Sound *this,int param_1,TSound_Driver *param_2)
{
  short *psVar1;
  RGE_Sound_Info *pRVar2;
  TDigital *this_00;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f89b;
  *unaff_FS_OFFSET = &local_c;
  rge_read(param_1,&this->id,2);
  rge_read(param_1,this,2);
  psVar1 = &this->sound_num;
  rge_read(param_1,psVar1,2);
  rge_read(param_1,&this->cache_time,4);
  iVar4 = 0;
  if (*psVar1 < 1) {
    this->sounds = (RGE_Sound_Info *)0x0;
  }
  else {
    pRVar2 = (RGE_Sound_Info *)calloc((int)*psVar1,0x24);
    this->sounds = pRVar2;
    if (0 < *psVar1) {
      iVar5 = 0;
      do {
        rge_read(param_1,this->sounds->name + iVar5,0xd);
        rge_read(param_1,this->sounds->name + iVar5 + 0x10,4);
        rge_read(param_1,this->sounds->name + iVar5 + 0x14,2);
        this_00 = (TDigital *)operator_new(0x3c);
        local_4 = 0;
        if (this_00 == (TDigital *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = TDigital::TDigital(this_00,param_2,this->sounds->name + iVar5,
                                     *(long *)(this->sounds->name + iVar5 + 0x10));
        }
        iVar4 = iVar4 + 1;
        local_4 = 0xffffffff;
        *(undefined4 *)(this->sounds->name + iVar5 + 0x18) = uVar3;
        this->sounds->name[iVar5 + 0x1c] = '\x02';
        iVar5 = iVar5 + 0x24;
      } while (iVar4 < this->sound_num);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Sound
// Address: 004bc070
void __thiscall RGE_Sound::RGE_Sound(RGE_Sound *this)
{
  this->play_at_update_count = 0;
  this->sound_num = 0;
  this->sounds = (RGE_Sound_Info *)0x0;
  return;
}

// --------------------------------------------------

// Function: ~RGE_Sound
// Address: 004bc080
void __thiscall RGE_Sound::~RGE_Sound(RGE_Sound *this)
{
  char *pcVar1;
  TDigital *this_00;
  int iVar2;
  int iVar3;
  
  this->play_at_update_count = 0;
  if (this->sounds != (RGE_Sound_Info *)0x0) {
    iVar2 = 0;
    if (0 < this->sound_num) {
      iVar3 = 0;
      do {
        this->sounds->name[iVar3] = '\0';
        this_00 = *(TDigital **)(this->sounds->name + iVar3 + 0x18);
        if (this_00 != (TDigital *)0x0) {
          TDigital::~TDigital(this_00);
          operator_delete(this_00);
          pcVar1 = this->sounds->name + iVar3 + 0x18;
          pcVar1[0] = '\0';
          pcVar1[1] = '\0';
          pcVar1[2] = '\0';
          pcVar1[3] = '\0';
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x24;
      } while (iVar2 < this->sound_num);
    }
    free(this->sounds);
    this->sounds = (RGE_Sound_Info *)0x0;
    this->sound_num = 0;
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004bc0f0
void __thiscall RGE_Sound::save(RGE_Sound *this,int param_1)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  rge_write(param_1,&this->id,2);
  rge_write(param_1,this,2);
  rge_write(param_1,&this->sound_num,2);
  rge_write(param_1,&this->cache_time,4);
  sVar1 = this->sound_num;
  if ((0 < sVar1) && (iVar2 = 0, 0 < sVar1)) {
    iVar3 = 0;
    do {
      rge_write(param_1,this->sounds->name + iVar3,0xd);
      rge_write(param_1,this->sounds->name + iVar3 + 0x10,4);
      rge_write(param_1,this->sounds->name + iVar3 + 0x14,2);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < this->sound_num);
  }
  return;
}

// --------------------------------------------------

// Function: restart_sound
// Address: 004bc190
void __thiscall RGE_Sound::restart_sound(RGE_Sound *this,TSound_Driver *param_1)
{
  char *pcVar1;
  TDigital *pTVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f8bb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar4 = 0;
  if (0 < this->sound_num) {
    iVar5 = 0;
    do {
      pTVar2 = *(TDigital **)(this->sounds->name + iVar5 + 0x18);
      if (pTVar2 != (TDigital *)0x0) {
        TDigital::~TDigital(pTVar2);
        operator_delete(pTVar2);
      }
      if (param_1 == (TSound_Driver *)0x0) {
        pcVar1 = this->sounds->name + iVar5 + 0x18;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
      }
      else {
        pTVar2 = (TDigital *)operator_new(0x3c);
        local_4 = 0;
        if (pTVar2 == (TDigital *)0x0) {
          local_4 = 0xffffffff;
          pcVar1 = this->sounds->name + iVar5 + 0x18;
          pcVar1[0] = '\0';
          pcVar1[1] = '\0';
          pcVar1[2] = '\0';
          pcVar1[3] = '\0';
        }
        else {
          uVar3 = TDigital::TDigital(pTVar2,param_1,this->sounds->name + iVar5,
                                     *(long *)(this->sounds->name + iVar5 + 0x10));
          local_4 = 0xffffffff;
          *(undefined4 *)(this->sounds->name + iVar5 + 0x18) = uVar3;
        }
      }
      iVar4 = iVar4 + 1;
      this->sounds->name[iVar5 + 0x1c] = '\x02';
      iVar5 = iVar5 + 0x24;
    } while (iVar4 < this->sound_num);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004bc270
void __thiscall RGE_Sound::update(RGE_Sound *this,ulong param_1)
{
  RGE_Sound_Info *pRVar1;
  int iVar2;
  int iVar3;
  
  if (((0 < this->sound_num) && (this->cache_time != 0)) && (iVar2 = 0, 0 < this->sound_num)) {
    iVar3 = 0;
    do {
      pRVar1 = this->sounds;
      if ((pRVar1->name[iVar3 + 0x1c] == '\x01') &&
         (this->cache_time < param_1 - *(int *)(pRVar1->name + iVar3 + 0x20))) {
        TDigital::unload(*(TDigital **)(pRVar1->name + iVar3 + 0x18));
        this->sounds->name[iVar3 + 0x1c] = '\x02';
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < this->sound_num);
  }
  return;
}

// --------------------------------------------------

// Function: set_cache_time
// Address: 004bc2d0
void __thiscall RGE_Sound::set_cache_time(RGE_Sound *this,ulong param_1)
{
  this->cache_time = param_1;
  return;
}

// --------------------------------------------------

// Function: play_at_update
// Address: 004bc2e0
void __thiscall RGE_Sound::play_at_update(RGE_Sound *this)
{
  this->play_at_update_count = this->play_at_update_count + 1;
  return;
}

// --------------------------------------------------

// Function: update_play
// Address: 004bc2f0
void __thiscall RGE_Sound::update_play(RGE_Sound *this)
{
  if (0 < this->play_at_update_count) {
    play(this,1);
    this->play_at_update_count = 0;
  }
  return;
}

// --------------------------------------------------

// Function: play
// Address: 004bc310
// [HELPER] s_C__msdev_work_age1_x1_Sound_cpp: "C:\msdev\work\age1_x1\Sound.cpp"
// [HELPER] s__: "}"
// [HELPER] s___s: "{%s"
void __thiscall RGE_Sound::play(RGE_Sound *this,int param_1)
{
  RGE_Sound_Info *pRVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  short *psVar5;
  char s [256];
  
  if (0 < this->sound_num) {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_Sound_cpp,0xdd);
    iVar2 = (iVar2 * 100) / 0x7fff;
    iVar3 = 0;
    if (0 < this->sound_num) {
      pRVar1 = this->sounds;
      psVar5 = &pRVar1->percent;
      while (iVar2 = iVar2 - *psVar5, 0 < iVar2) {
        iVar3 = iVar3 + 1;
        psVar5 = psVar5 + 0x12;
        if (this->sound_num <= iVar3) {
          return;
        }
      }
      if (pRVar1[iVar3].digital_sound != (TDigital *)0x0) {
        if (do_draw_log != 0) {
          sprintf(s + 4,s___s,pRVar1 + iVar3);
          if (safe_draw_log == 0) {
            write_draw_log(s + 4);
          }
          else {
            write_draw_log2(s + 4);
          }
        }
        if (param_1 == 0) {
          TDigital::play(this->sounds[iVar3].digital_sound);
        }
        else {
          TDigital::add_to_play_list(this->sounds[iVar3].digital_sound);
        }
        if (do_draw_log != 0) {
          if (safe_draw_log == 0) {
            write_draw_log(s__);
          }
          else {
            write_draw_log2(s__);
          }
        }
        this->sounds[iVar3].loaded = '\x01';
        iVar2 = debug_timeGetTime_on;
        debug_timeGetTime_on = 0;
        uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Sound_cpp,0x108);
        this->sounds[iVar3].time = uVar4;
        debug_timeGetTime_on = iVar2;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: get_file_name
// Address: 004bc470
// [HELPER] s_C__msdev_work_age1_x1_Sound_cpp: "C:\msdev\work\age1_x1\Sound.cpp"
char * __thiscall RGE_Sound::get_file_name(RGE_Sound *this)
{
  TDigital *pTVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  
  if (0 < this->sound_num) {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_Sound_cpp,0x11c);
    iVar2 = (iVar2 * 100) / 0x7fff;
    iVar3 = 0;
    if (0 < this->sound_num) {
      psVar4 = &this->sounds->percent;
      while (iVar2 = iVar2 - *psVar4, 0 < iVar2) {
        iVar3 = iVar3 + 1;
        psVar4 = psVar4 + 0x12;
        if (this->sound_num <= iVar3) {
          return (char *)0x0;
        }
      }
      pTVar1 = this->sounds[iVar3].digital_sound;
      if (pTVar1 != (TDigital *)0x0) {
        return pTVar1->sound_file;
      }
    }
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: stop
// Address: 004bc4f0
void __thiscall RGE_Sound::stop(RGE_Sound *this)
{
  TDigital *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((0 < this->sound_num) && (iVar2 = 0, 0 < this->sound_num)) {
    iVar3 = 0;
    do {
      this_00 = *(TDigital **)(this->sounds->name + iVar3 + 0x18);
      if ((this_00 != (TDigital *)0x0) && (iVar1 = TDigital::is_playing(this_00), iVar1 != 0)) {
        TDigital::stop(*(TDigital **)(this->sounds->name + iVar3 + 0x18));
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < this->sound_num);
  }
  return;
}

// --------------------------------------------------

// Function: is_playing
// Address: 004bc540
int __thiscall RGE_Sound::is_playing(RGE_Sound *this)
{
  TDigital *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((0 < this->sound_num) && (iVar2 = 0, 0 < this->sound_num)) {
    iVar3 = 0;
    do {
      this_00 = *(TDigital **)(this->sounds->name + iVar3 + 0x18);
      if (this_00 != (TDigital *)0x0) {
        iVar1 = TDigital::is_playing(this_00);
        if (iVar1 != 0) {
          return 1;
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < this->sound_num);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

