// Class: RGE_Active_Animated_Sprite
// Size:  0x28
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] set_offset
// [02] save
// [03] update
// [04] draw
// [05] normal_draw
// [06] shadow_draw
// [07] what_frame
// [08] is_animating
// [09] set_frame
// [10] frame_passed
// [11] looped
// [12] get_facetindex
// [13] get_frame
// [14] setToFirstFrame
//
// Member Layout:
// [0x014] short frame
// [0x018] float animate_interval
// [0x01C] float animate_last
// [0x020] short last_frame
// [0x022] uchar frame_changed
// [0x023] uchar frame_looped
// [0x024] uchar animate_flag
// ----------------------------------------------------------------

// Function: RGE_Active_Animated_Sprite
// Address: 0041b010
// [HELPER] s_C__msdev_work_age1_x1_asprite_cp: "C:\msdev\work\age1_x1\asprite.cpp"
RGE_Active_Animated_Sprite * __thiscall
RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite
          (RGE_Active_Animated_Sprite *this,RGE_Sprite *param_1)
{
  float fVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  undefined4 *unaff_FS_OFFSET;
  float10 extraout_ST0;
  float tot_time;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c988;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Active_Sprite::RGE_Active_Sprite((RGE_Active_Sprite *)this,param_1);
  this->_padding_ = (int)&_vftable_;
  *(undefined1 *)&this->_padding_ = 2;
  this->last_frame = 0;
  local_4 = 0;
  fVar1 = *(float *)(this->_padding_ + 0x68);
  this->animate_interval = fVar1;
  if (fVar1 < (float)_DAT_0056ee78) {
    this->animate_interval = 0.001;
  }
  if ((*(byte *)(this->_padding_ + 0x70) & 4) == 0) {
    this->frame = 0;
  }
  else {
    debug_rand(s_C__msdev_work_age1_x1_asprite_cp,0xb7);
    iVar3 = this->_padding_;
    sVar4 = __ftol();
    this->frame = sVar4;
    sVar2 = *(short *)(iVar3 + 0x5e);
    if (sVar2 <= sVar4) {
      sVar2 = sVar2 + -1;
      this->frame = sVar2;
      this->animate_interval =
           (float)(extraout_ST0 - (float10)(int)sVar2 * (float10)*(float *)(iVar3 + 0x68));
    }
    this->last_frame = this->frame;
  }
  this->animate_last = 0.0;
  this->frame_changed = '\0';
  this->frame_looped = '\0';
  this->animate_flag = '\x01';
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0041b120
void * __thiscall
RGE_Active_Animated_Sprite::_vector_deleting_destructor_
          (RGE_Active_Animated_Sprite *this,uint param_1)
{
  ~RGE_Active_Animated_Sprite(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Active_Animated_Sprite
// Address: 0041b140
RGE_Active_Animated_Sprite * __thiscall
RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite
          (RGE_Active_Animated_Sprite *this,int param_1,RGE_Sprite **param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c9a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Active_Sprite::RGE_Active_Sprite((RGE_Active_Sprite *)this,param_1,param_2);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined1 *)&this->_padding_ = 2;
  rge_read(param_1,&this->frame,2);
  rge_read(param_1,&this->animate_interval,4);
  rge_read(param_1,&this->animate_last,4);
  rge_read(param_1,&this->last_frame,2);
  rge_read(param_1,&this->frame_changed,1);
  rge_read(param_1,&this->frame_looped,1);
  rge_read(param_1,&this->animate_flag,1);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Active_Animated_Sprite
// Address: 0041b200
void __thiscall
RGE_Active_Animated_Sprite::~RGE_Active_Animated_Sprite(RGE_Active_Animated_Sprite *this)
{
  this->_padding_ = (int)&_vftable_;
  RGE_Active_Sprite::~RGE_Active_Sprite((RGE_Active_Sprite *)this);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0041b210
void __thiscall RGE_Active_Animated_Sprite::save(RGE_Active_Animated_Sprite *this,int param_1)
{
  RGE_Active_Sprite::save((RGE_Active_Sprite *)this,param_1);
  rge_write(param_1,&this->frame,2);
  rge_write(param_1,&this->animate_interval,4);
  rge_write(param_1,&this->animate_last,4);
  rge_write(param_1,&this->last_frame,2);
  rge_write(param_1,&this->frame_changed,1);
  rge_write(param_1,&this->frame_looped,1);
  rge_write(param_1,&this->animate_flag,1);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 0041b290
void __thiscall
RGE_Active_Animated_Sprite::update(RGE_Active_Animated_Sprite *this,float param_1,float param_2)
{
  int iVar1;
  float fVar2;
  ushort uVar3;
  short sVar4;
  float10 extraout_ST0;
  
  iVar1 = this->_padding_;
  this->frame_changed = '\0';
  this->frame_looped = '\0';
  if ((iVar1 != 0) && (this->animate_flag != '\0')) {
    if (*(short *)(iVar1 + 0x5e) <= this->frame) {
      this->frame = *(short *)(iVar1 + 0x5e) + -1;
    }
    if (((*(byte *)(iVar1 + 0x70) & 1) != 0) &&
       (fVar2 = param_1 + this->animate_last, this->animate_last = fVar2,
       this->animate_interval <= fVar2)) {
      this->frame_changed = '\x01';
      this->last_frame = this->frame;
      uVar3 = __ftol();
      this->animate_last =
           (float)(extraout_ST0 - (float10)(int)(short)uVar3 * (float10)this->animate_interval);
      if ((((float)_DAT_0056ee88 < param_2) || (*(float *)(iVar1 + 100) == (float)_DAT_0056ee88)) &&
         (this->frame = this->frame + (uVar3 & 0xff), *(short *)(iVar1 + 0x5e) <= this->frame)) {
        this->frame_looped = '\x01';
      }
      if ((*(float *)(iVar1 + 100) == (float)_DAT_0056ee88) || (param_2 == (float)_DAT_0056ee88)) {
        this->animate_interval = *(float *)(iVar1 + 0x68);
      }
      else {
        this->animate_interval = (*(float *)(iVar1 + 0x68) * *(float *)(iVar1 + 100)) / param_2;
      }
      if (this->animate_interval < (float)_DAT_0056ee78) {
        this->animate_interval = 0.001;
      }
      if (this->frame_looped == '\0') {
        return;
      }
      if ((*(float *)(iVar1 + 0x6c) <= (float)_DAT_0056ee88) || (this->animate_flag == '\x02')) {
        this->animate_flag = '\x01';
        sVar4 = *(short *)(iVar1 + 0x5e);
        if (sVar4 <= this->frame) {
          do {
            this->frame = this->frame - sVar4;
            sVar4 = *(short *)(iVar1 + 0x5e);
          } while (sVar4 <= this->frame);
        }
      }
      else {
        this->animate_interval =
             *(float *)(iVar1 + 0x6c) -
             (float)((int)this->frame - (int)*(short *)(iVar1 + 0x5e)) * *(float *)(iVar1 + 0x68);
        sVar4 = *(short *)(iVar1 + 0x5e);
        this->animate_flag = '\x02';
        this->frame_looped = '\0';
        this->frame = sVar4 + -1;
      }
    }
  }
  if ((this->frame_looped != '\0') && ((*(byte *)(iVar1 + 0x70) & 8) != 0)) {
    this->animate_flag = '\0';
    this->frame = *(short *)(iVar1 + 0x5e) + -1;
  }
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0041b430
void __thiscall
RGE_Active_Animated_Sprite::draw
          (RGE_Active_Animated_Sprite *this,short param_1,long param_2,long param_3,long param_4,
          long param_5,RGE_Color_Table *param_6,TDrawArea *param_7)
{
  RGE_Sprite::draw((RGE_Sprite *)this->_padding_,(int)param_1,(int)this->frame,param_2,param_3,
                   param_4,param_5,param_6,param_7,'\0');
  if (this->frame_changed != '\0') {
    if (fog_next_shape == 0) {
      RGE_Sprite::play_sound((RGE_Sprite *)this->_padding_,this->last_frame,this->frame,param_1);
    }
    this->frame_changed = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: normal_draw
// Address: 0041b4a0
void __thiscall
RGE_Active_Animated_Sprite::normal_draw
          (RGE_Active_Animated_Sprite *this,short param_1,long param_2,long param_3,
          RGE_Color_Table *param_4,TDrawArea *param_5)
{
  RGE_Sprite::normal_draw
            ((RGE_Sprite *)this->_padding_,(int)param_1,(int)this->frame,param_2,param_3,param_4,
             param_5);
  if (this->frame_changed != '\0') {
    RGE_Sprite::play_sound((RGE_Sprite *)this->_padding_,this->last_frame,this->frame,param_1);
    this->frame_changed = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: shadow_draw
// Address: 0041b4f0
void __thiscall
RGE_Active_Animated_Sprite::shadow_draw
          (RGE_Active_Animated_Sprite *this,short param_1,long param_2,long param_3,
          RGE_Color_Table *param_4,TDrawArea *param_5,uchar param_6)
{
  RGE_Sprite::shadow_draw
            ((RGE_Sprite *)this->_padding_,(int)param_1,(int)this->frame,param_2,param_3,param_4,
             param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: what_frame
// Address: 0041b520
short __thiscall RGE_Active_Animated_Sprite::what_frame(RGE_Active_Animated_Sprite *this)
{
  return this->frame;
}

// --------------------------------------------------

// Function: is_animating
// Address: 0041b530
uchar __thiscall RGE_Active_Animated_Sprite::is_animating(RGE_Active_Animated_Sprite *this)
{
  uchar uVar1;
  
  if ((this->animate_flag == '\0') || (uVar1 = '\x01', (*(byte *)(this->_padding_ + 0x70) & 1) == 0)
     ) {
    uVar1 = '\0';
  }
  return uVar1;
}

// --------------------------------------------------

// Function: set_frame
// Address: 0041b550
void __thiscall
RGE_Active_Animated_Sprite::set_frame(RGE_Active_Animated_Sprite *this,short param_1)
{
  this->frame = param_1;
  return;
}

// --------------------------------------------------

// Function: frame_passed
// Address: 0041b560
uchar __thiscall
RGE_Active_Animated_Sprite::frame_passed(RGE_Active_Animated_Sprite *this,short param_1)
{
  if ((this->frame_changed != '\0') &&
     ((this->frame_looped != '\0' || ((param_1 <= this->frame && (this->last_frame < param_1)))))) {
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: looped
// Address: 0041b590
uchar __thiscall RGE_Active_Animated_Sprite::looped(RGE_Active_Animated_Sprite *this)
{
  return this->frame_looped;
}

// --------------------------------------------------

// Function: get_facetindex
// Address: 0041b5a0
short __thiscall
RGE_Active_Animated_Sprite::get_facetindex(RGE_Active_Animated_Sprite *this,short param_1)
{
  long facet_index;
  long local_4;
  
  local_4 = 0;
  RGE_Sprite::get_facetindex((RGE_Sprite *)this->_padding_,(int)param_1,(int)this->frame,&local_4);
  return (short)local_4;
}

// --------------------------------------------------

// Function: get_frame
// Address: 0041b5d0
uchar __thiscall
RGE_Active_Animated_Sprite::get_frame
          (RGE_Active_Animated_Sprite *this,short *param_1,short *param_2,short *param_3,
          short *param_4,long param_5)
{
  int iVar1;
  
  iVar1 = RGE_Sprite::get_frame
                    ((RGE_Sprite *)this->_padding_,param_1,param_2,param_3,param_4,param_5,
                     (int)this->frame);
  return (uchar)iVar1;
}

// --------------------------------------------------

// Function: setToFirstFrame
// Address: 0041b600
void __thiscall RGE_Active_Animated_Sprite::setToFirstFrame(RGE_Active_Animated_Sprite *this)
{
  this->frame_changed = '\x01';
  this->last_frame = this->frame;
  this->frame = 0;
  return;
}

// --------------------------------------------------

