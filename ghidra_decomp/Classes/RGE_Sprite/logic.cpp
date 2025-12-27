// Class: RGE_Sprite
// Function: RGE_Sprite
// Address: 004bf720
/* public: __thiscall RGE_Sprite::RGE_Sprite(short) */

void __thiscall RGE_Sprite::RGE_Sprite(RGE_Sprite *this,short param_1)
{
  this->color_tables = (RGE_Color_Table **)0x0;
  this->id = param_1;
  this->last_time = 0;
  this->delta_time = 0;
  this->name[0] = '\0';
  this->pict_name[0] = '\0';
  this->resource_id = 0;
  this->frame_num = 0;
  this->facet_num = 0;
  this->color_table = 0;
  this->box_x1 = 0;
  this->box_y1 = 0;
  this->box_x2 = 0;
  this->box_y2 = 0;
  this->base_speed = 0.0;
  this->duration = 0.0;
  this->pause_between_loops = 0.0;
  this->draw_list_num = 0;
  this->loaded = '\0';
  this->shape = (TShape *)0x0;
  this->main_sound = (RGE_Sound *)0x0;
  this->mirror_flag = '\0';
  this->color_flag = '\0';
  this->draw_level = '\0';
  this->transparent_picking_flag = '\0';
  this->micro_man_sound = '\0';
  this->flag = '\0';
  this->draw_list = (RGE_Picture_List *)0x0;
  this->sound_list = (RGE_Sound_List *)0x0;
  return;
}

// --------------------------------------------------

// Function: RGE_Sprite
// Address: 004bf790
/* public: __thiscall RGE_Sprite::RGE_Sprite(int,class RGE_Sound * *,class RGE_Color_Table * *) */

RGE_Sprite * __thiscall
RGE_Sprite::RGE_Sprite(RGE_Sprite *this,int param_1,RGE_Sound **param_2,RGE_Color_Table **param_3)
{
  short *psVar1;
  short *psVar2;
  int iVar3;
  RGE_Picture_List *pRVar4;
  RGE_Sound_List *pRVar5;
  RGE_Sound *pRVar6;
  int iVar7;
  int iVar8;
  int local_c;
  long index1;
  int local_4;
  
  iVar3 = param_1;
  this->color_tables = param_3;
  this->last_time = 0;
  this->delta_time = 0;
  rge_read(param_1,this->name,0x15);
  rge_read(iVar3,this,0xd);
  rge_read(iVar3,&this->resource_id,4);
  rge_read(iVar3,&this->loaded,1);
  rge_read(iVar3,&this->color_flag,1);
  rge_read(iVar3,&this->draw_level,1);
  rge_read(iVar3,&this->color_table,2);
  rge_read(iVar3,&this->transparent_picking_flag,1);
  rge_read(iVar3,&this->box_x1,2);
  rge_read(iVar3,&this->box_y1,2);
  rge_read(iVar3,&this->box_x2,2);
  rge_read(iVar3,&this->box_y2,2);
  psVar1 = &this->draw_list_num;
  rge_read(iVar3,psVar1,2);
  rge_read(iVar3,&param_3,2);
  rge_read(iVar3,&this->micro_man_sound,1);
  rge_read(iVar3,&this->frame_num,2);
  psVar2 = &this->facet_num;
  rge_read(iVar3,psVar2,2);
  rge_read(iVar3,&this->base_speed,4);
  rge_read(iVar3,&this->duration,4);
  rge_read(iVar3,&this->pause_between_loops,4);
  rge_read(iVar3,&this->flag,1);
  rge_read(iVar3,&this->id,2);
  rge_read(iVar3,&this->mirror_flag,1);
  if ((short)param_3 < 0) {
    pRVar6 = (RGE_Sound *)0x0;
  }
  else {
    pRVar6 = param_2[(short)param_3];
  }
  this->main_sound = pRVar6;
  if (*psVar1 < 1) {
    this->draw_list = (RGE_Picture_List *)0x0;
  }
  else {
    pRVar4 = (RGE_Picture_List *)calloc((int)*psVar1,0x10);
    this->draw_list = pRVar4;
    rge_read(iVar3,pRVar4,(int)*psVar1 << 4);
  }
  if (this->micro_man_sound == '\0') {
    this->sound_list = (RGE_Sound_List *)0x0;
  }
  else {
    pRVar5 = (RGE_Sound_List *)calloc((int)*psVar2,0x14);
    this->sound_list = pRVar5;
    local_4 = 0;
    if (0 < *psVar2) {
      local_c = 0;
      do {
        iVar8 = local_c + 0xc;
        index1 = 3;
        iVar7 = local_c;
        do {
          rge_read(iVar3,(void *)((int)this->sound_list->sound + iVar8),2);
          rge_read(iVar3,&param_1,2);
          if ((short)param_1 < 0) {
            pRVar6 = (RGE_Sound *)0x0;
          }
          else {
            pRVar6 = param_2[(short)param_1];
          }
          iVar8 = iVar8 + 2;
          *(RGE_Sound **)((int)this->sound_list->sound + iVar7) = pRVar6;
          iVar7 = iVar7 + 4;
          index1 = index1 + -1;
        } while (index1 != 0);
        local_4 = local_4 + 1;
        local_c = local_c + 0x14;
      } while (local_4 < this->facet_num);
      return this;
    }
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Sprite
// Address: 004bfa20
// [HELPER] s___hd__hd__hd__hd: " %hd %hd %hd %hd"
// [HELPER] s___s__s__d__hd__hd__hd__hd__hd__h: " %s %s %d %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f %f %..."
// [HELPER] s__hd__hd__hd: "%hd %hd %hd"
/* WARNING: Variable defined which should be unmapped: temp_main_sound */
/* public: __thiscall RGE_Sprite::RGE_Sprite(struct _iobuf *,short,class RGE_Sound * *) */

RGE_Sprite * __thiscall
RGE_Sprite::RGE_Sprite(RGE_Sprite *this,_iobuf *param_1,short param_2,RGE_Sound **param_3)
{
  short *psVar1;
  short *psVar2;
  short sVar3;
  int iVar4;
  RGE_Sound *pRVar5;
  RGE_Picture_List *pRVar6;
  RGE_Sound_List *pRVar7;
  int iVar8;
  short sVar9;
  undefined2 in_stack_0000000a;
  short temp_main_sound;
  short temp_mirror_flag;
  short temp_color_flag;
  short temp_draw_level;
  short temp_transparent_picking_flag;
  short temp_animated;
  short temp_directional;
  short temp_randomize_on_start;
  short temp_loop_once;
  short sound_id;
  short sound_frame;
  short last_facet;
  short local_e;
  short sound_facet;
  short index1;
  int local_4;
  
  this->color_tables = (RGE_Color_Table **)0x0;
  this->last_time = 0;
  this->delta_time = 0;
  this->id = param_2;
  psVar1 = &this->draw_list_num;
  psVar2 = &this->facet_num;
  _sound_facet = 0xffffffff;
  iVar4 = fscanf(param_1,s___s__s__d__hd__hd__hd__hd__hd__h,this->name,this,&this->resource_id,
                 &this->frame_num,psVar2,&temp_draw_level,&temp_transparent_picking_flag,
                 &temp_animated,&this->color_table,&sound_id,&temp_directional,
                 &temp_randomize_on_start,&temp_loop_once,&sound_frame,&this->box_x1,&this->box_y1,
                 &this->box_x2,&this->box_y2,&this->base_speed,&this->duration,
                 &this->pause_between_loops,psVar1,&temp_color_flag,&param_2);
  if (iVar4 != -1) {
    this->loaded = '\0';
    this->shape = (TShape *)0x0;
    convert_us(this->name);
    sVar3 = 0;
    if (temp_color_flag < 0) {
      pRVar5 = (RGE_Sound *)0x0;
    }
    else {
      pRVar5 = param_3[temp_color_flag];
    }
    this->main_sound = pRVar5;
    if (temp_draw_level < 1) {
      this->mirror_flag = '\0';
    }
    else {
      iVar4 = CONCAT22((short)((uint)psVar2 >> 0x10),*psVar2);
      this->mirror_flag = (char)(iVar4 >> 1) + (char)(iVar4 >> 2);
    }
    this->color_flag = (uchar)temp_transparent_picking_flag;
    this->draw_level = (uchar)temp_animated;
    this->transparent_picking_flag = (uchar)temp_directional;
    this->micro_man_sound = 0 < param_2;
    this->flag = 0 < temp_randomize_on_start;
    if (temp_loop_once != 0) {
      this->flag = (0 < temp_randomize_on_start) + '\x02';
    }
    if (sound_id != 0) {
      this->flag = this->flag + '\x04';
    }
    if (sound_frame != 0) {
      this->flag = this->flag + '\b';
    }
    if (*psVar1 < 1) {
      this->draw_list = (RGE_Picture_List *)0x0;
    }
    else {
      pRVar6 = (RGE_Picture_List *)calloc((int)*psVar1,0x10);
      this->draw_list = pRVar6;
      if (0 < *psVar1) {
        do {
          pRVar6 = this->draw_list + sVar3;
          fscanf(param_1,s___hd__hd__hd__hd,pRVar6,&pRVar6->offset_x,&pRVar6->offset_y,
                 &pRVar6->facet);
          sVar3 = sVar3 + 1;
        } while (sVar3 < *psVar1);
      }
    }
    if (this->micro_man_sound == '\0') {
      this->sound_list = (RGE_Sound_List *)0x0;
    }
    else {
      pRVar7 = (RGE_Sound_List *)calloc((int)this->facet_num,0x14);
      sVar3 = 0;
      this->sound_list = pRVar7;
      if (0 < this->facet_num) {
        do {
          iVar8 = 3;
          iVar4 = sVar3 * 0x14 + 0xc;
          do {
            iVar8 = iVar8 + -1;
            *(undefined2 *)((int)this->sound_list->sound + iVar4) = 0xffff;
            iVar4 = iVar4 + 2;
          } while (iVar8 != 0);
          sVar3 = sVar3 + 1;
        } while (sVar3 < this->facet_num);
      }
      local_4 = 0;
      iVar4 = _param_2;
      if (0 < param_2) {
        do {
          iVar8 = fscanf(param_1,s__hd__hd__hd,&index1,&local_e,&last_facet);
          if (iVar8 != -1) {
            sVar3 = (short)_index1;
            if (sound_facet == sVar3) {
              iVar4 = iVar4 + 1;
            }
            else {
              iVar4 = 0;
              _sound_facet = _index1;
            }
            if (((-1 < sVar3) && (sVar3 < this->facet_num)) && (sVar9 = (short)iVar4, sVar9 < 3)) {
              this->sound_list[sVar3].sound[sVar9] = param_3[last_facet];
              this->sound_list[sVar3].frame[sVar9] = local_e;
            }
          }
          local_4 = local_4 + 1;
        } while ((short)local_4 < param_2);
        return this;
      }
    }
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Sprite
// Address: 004bfce0
/* public: __thiscall RGE_Sprite::~RGE_Sprite(void) */

void __thiscall RGE_Sprite::~RGE_Sprite(RGE_Sprite *this)
{
  TShape *this_00;
  
  this_00 = this->shape;
  if ((this_00 != (TShape *)0x0) && (this->loaded != '\0')) {
    if (this_00 != (TShape *)0x0) {
      TShape::~TShape(this_00);
      operator_delete(this_00);
    }
    this->loaded = '\0';
  }
  this->shape = (TShape *)0x0;
  if (this->sound_list != (RGE_Sound_List *)0x0) {
    free(this->sound_list);
    this->sound_list = (RGE_Sound_List *)0x0;
  }
  if (this->draw_list != (RGE_Picture_List *)0x0) {
    free(this->draw_list);
    this->draw_list = (RGE_Picture_List *)0x0;
  }
  this->color_tables = (RGE_Color_Table **)0x0;
  return;
}

// --------------------------------------------------

// Function: rehook
// Address: 004bfd40
/* public: void __thiscall RGE_Sprite::rehook(class RGE_Sprite * *) */

void __thiscall RGE_Sprite::rehook(RGE_Sprite *this,RGE_Sprite **param_1)
{
  RGE_Picture_List *pRVar1;
  short sVar2;
  
  if ((0 < this->draw_list_num) && (this->draw_list != (RGE_Picture_List *)0x0)) {
    sVar2 = 0;
    if (0 < this->draw_list_num) {
      do {
        pRVar1 = this->draw_list + sVar2;
        if (pRVar1->picture_num == -1) {
          pRVar1->sprite = this;
        }
        else {
          pRVar1->sprite = param_1[pRVar1->picture_num];
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < this->draw_list_num);
    }
  }
  load_facets(this,param_1);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004bfda0
/* WARNING: Variable defined which should be unmapped: lock1 */
/* public: void __thiscall RGE_Sprite::save(int) */

void __thiscall RGE_Sprite::save(RGE_Sprite *this,int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lock1;
  long info;
  int local_c;
  long index1;
  int local_4;
  
  iVar2 = param_1;
  info = -1;
  if (this->main_sound != (RGE_Sound *)0x0) {
    info = (long)this->main_sound->id;
  }
  rge_write(param_1,this->name,0x15);
  rge_write(param_1,this,0xd);
  rge_write(param_1,&this->resource_id,4);
  rge_write(param_1,&this->loaded,1);
  rge_write(param_1,&this->color_flag,1);
  rge_write(param_1,&this->draw_level,1);
  rge_write(param_1,&this->color_table,2);
  rge_write(param_1,&this->transparent_picking_flag,1);
  rge_write(param_1,&this->box_x1,2);
  rge_write(param_1,&this->box_y1,2);
  rge_write(param_1,&this->box_x2,2);
  rge_write(param_1,&this->box_y2,2);
  rge_write(param_1,&this->draw_list_num,2);
  rge_write(param_1,&info,2);
  rge_write(param_1,&this->micro_man_sound,1);
  rge_write(param_1,&this->frame_num,2);
  rge_write(param_1,&this->facet_num,2);
  rge_write(param_1,&this->base_speed,4);
  rge_write(param_1,&this->duration,4);
  rge_write(param_1,&this->pause_between_loops,4);
  rge_write(param_1,&this->flag,1);
  rge_write(param_1,&this->id,2);
  rge_write(param_1,&this->mirror_flag,1);
  if (this->draw_list != (RGE_Picture_List *)0x0) {
    rge_write(param_1,this->draw_list,(int)this->draw_list_num << 4);
  }
  if ((this->micro_man_sound != '\0') && (local_4 = 0, 0 < this->facet_num)) {
    param_1 = 0;
    do {
      iVar4 = param_1 + 0xc;
      index1 = 3;
      iVar3 = param_1;
      do {
        iVar1 = *(int *)((int)this->sound_list->sound + iVar3);
        if (iVar1 == 0) {
          local_c = -1;
        }
        else {
          local_c = (int)*(short *)(iVar1 + 0xc);
        }
        rge_write(iVar2,(void *)((int)this->sound_list->sound + iVar4),2);
        rge_write(iVar2,&local_c,2);
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 2;
        index1 = index1 + -1;
      } while (index1 != 0);
      local_4 = local_4 + 1;
      param_1 = param_1 + 0x14;
    } while (local_4 < this->facet_num);
  }
  return;
}

// --------------------------------------------------

// Function: load_facets
// Address: 004bffe0
/* public: void __thiscall RGE_Sprite::load_facets(class RGE_Sprite * *) */

void __thiscall RGE_Sprite::load_facets(RGE_Sprite *this,RGE_Sprite **param_1)
{
  this->shape = (TShape *)0x0;
  this->loaded = '\x01';
  return;
}

// --------------------------------------------------

// Function: play_sound
// Address: 004bfff0
/* public: void __thiscall RGE_Sprite::play_sound(short,short,short) */

void __thiscall RGE_Sprite::play_sound(RGE_Sprite *this,short param_1,short param_2,short param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (this->facet_num <= param_3) {
    param_3 = 0;
  }
  if (param_1 != param_2) {
    if ((this->main_sound != (RGE_Sound *)0x0) &&
       ((param_1 == 0 || ((param_2 < param_1 && (param_2 != 0)))))) {
      RGE_Sound::play(this->main_sound,1);
    }
    if (this->micro_man_sound != '\0') {
      if (param_1 < param_2) {
        iVar2 = 0;
        iVar3 = param_3 * 0x14 + 0xc;
        while( true ) {
          sVar1 = *(short *)((int)this->sound_list->sound + iVar3);
          if (sVar1 < 0) break;
          if ((param_1 <= sVar1) && (sVar1 < param_2)) {
            RGE_Sound::play(this->sound_list[param_3].sound[iVar2],1);
          }
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 2;
          if (2 < iVar2) {
            return;
          }
        }
      }
      else {
        iVar2 = 0;
        iVar3 = param_3 * 0x14 + 0xc;
        do {
          sVar1 = *(short *)((int)this->sound_list->sound + iVar3);
          if (sVar1 < 0) {
            return;
          }
          if ((param_1 <= sVar1) || (sVar1 < param_2)) {
            RGE_Sound::play(this->sound_list[param_3].sound[iVar2],1);
          }
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 2;
        } while (iVar2 < 3);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: get_facetindex
// Address: 004c00e0
/* public: unsigned char __thiscall RGE_Sprite::get_facetindex(long,long,long &) */

uchar __thiscall
RGE_Sprite::get_facetindex(RGE_Sprite *this,long param_1,long param_2,long *param_3)
{
  byte bVar1;
  int iVar2;
  
  bVar1 = this->mirror_flag;
  if ((bVar1 != 0) && (this->facet_num == 2)) {
    *param_3 = param_2;
    return (uchar)param_1;
  }
  if ((bVar1 != 0) && (((int)(uint)bVar1 < param_1 || (param_1 < (int)this->facet_num >> 2)))) {
    iVar2 = (int)this->facet_num >> 1;
    if (iVar2 < param_1) {
      iVar2 = (iVar2 - param_1) + (int)this->facet_num;
    }
    else {
      iVar2 = iVar2 - param_1;
    }
    *param_3 = iVar2;
    *param_3 = (*param_3 - ((int)this->facet_num >> 2)) * (int)this->frame_num + param_2;
    return '\x01';
  }
  if (bVar1 == 0) {
    *param_3 = this->frame_num * param_1 + param_2;
    return '\0';
  }
  *param_3 = (param_1 - ((int)this->facet_num >> 2)) * (int)this->frame_num + param_2;
  return '\0';
}

// --------------------------------------------------

// Function: do_draw
// Address: 004c01a0
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_sprite_cpp: "C:\msdev\work\age1_x1\sprite.cpp"
// [HELPER] s__shp: ".shp"
/* WARNING: Variable defined which should be unmapped: facetindex */
/* public: void __thiscall RGE_Sprite::do_draw(long,long,long,long,class RGE_Color_Table *,class
   TDrawArea *,unsigned char) */

void __thiscall
RGE_Sprite::do_draw(RGE_Sprite *this,long param_1,long param_2,long param_3,long param_4,
                   RGE_Color_Table *param_5,TDrawArea *param_6,uchar param_7)
{
  short sVar1;
  uchar uVar2;
  ulong uVar3;
  TShape *pTVar4;
  ulong uVar5;
  undefined4 *unaff_FS_OFFSET;
  uchar *puVar6;
  long facetindex;
  char *fname;
  char *local_114;
  char s [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f8fe;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_114 = (char *)0x0;
  if (this->frame_num <= param_2) {
    param_2 = 0;
  }
  if (this->shape == (TShape *)0x0) {
    if (this->loaded == '\0') goto LAB_004c04ca;
    addstring(&local_114,this->pict_name,s__shp);
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x1e8);
    s._0_4_ = operator_new(0x20);
    local_4 = 0;
    if ((TShape *)s._0_4_ == (TShape *)0x0) {
      pTVar4 = (TShape *)0x0;
    }
    else {
      pTVar4 = (TShape *)TShape::TShape((TShape *)s._0_4_,local_114,this->resource_id);
    }
    local_4 = 0xffffffff;
    this->shape = pTVar4;
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x1ea);
    RGE_Base_Game::add_to_timing(rge_base_game,0xb,uVar5 - uVar3);
    free(local_114);
  }
  this->delta_time = 0;
  SDI_Draw_Level = (uint)this->draw_level;
  if ((uint)this->draw_level < (uint)param_7) {
    SDI_Draw_Level = (uint)param_7;
  }
  SDI_List->Select_Box = (short *)0x0;
  if (this->box_x1 != 0) {
    SDI_List->Select_Box = &this->box_x1;
  }
  uVar2 = get_facetindex(this,param_1,param_2,(long *)&fname);
  if (uVar2 == '\0') {
    if (do_draw_log != 0) {
      sprintf(s + 4,s_<_s,_d,_d,_d,_d,u,this,param_3,param_4,fname,this->color_flag);
      if (safe_draw_log == 0) {
        write_draw_log(s + 4);
      }
      else {
        write_draw_log2(s + 4);
      }
    }
    sVar1 = this->color_table;
    if (sVar1 < 0) {
      if (param_5 == (RGE_Color_Table *)0x0) {
        puVar6 = (uchar *)0x0;
      }
      else {
        _ASMSet_Color_Xform((param_5->id + 1) * 0x10);
        puVar6 = param_5->table;
      }
      uVar2 = this->color_flag;
    }
    else {
      if (this->color_tables[sVar1] == (RGE_Color_Table *)0x0) {
        puVar6 = (uchar *)0x0;
      }
      else {
        _ASMSet_Color_Xform((sVar1 + 1) * 0x10);
        puVar6 = this->color_tables[this->color_table]->table;
      }
      uVar2 = this->color_flag;
    }
    TShape::shape_draw(this->shape,param_6,param_3,param_4,(long)fname,uVar2,puVar6);
  }
  else {
    if (do_draw_log != 0) {
      sprintf(s + 4,s_<_s,_d,_d,_d,_d,m,this,param_3,param_4,fname,this->color_flag);
      if (safe_draw_log == 0) {
        write_draw_log(s + 4);
      }
      else {
        write_draw_log2(s + 4);
      }
    }
    sVar1 = this->color_table;
    if (sVar1 < 0) {
      if (param_5 == (RGE_Color_Table *)0x0) {
        puVar6 = (uchar *)0x0;
      }
      else {
        _ASMSet_Color_Xform((param_5->id + 1) * 0x10);
        puVar6 = param_5->table;
      }
      TShape::shape_mirror(this->shape,param_6,param_3,param_4,(long)fname,this->color_flag,puVar6);
    }
    else {
      if (this->color_tables[sVar1] == (RGE_Color_Table *)0x0) {
        puVar6 = (uchar *)0x0;
      }
      else {
        _ASMSet_Color_Xform((sVar1 + 1) * 0x10);
        puVar6 = this->color_tables[this->color_table]->table;
      }
      TShape::shape_mirror(this->shape,param_6,param_3,param_4,(long)fname,this->color_flag,puVar6);
    }
  }
  if (do_draw_log != 0) {
    if (safe_draw_log == 0) {
      write_draw_log(&s_>);
    }
    else {
      write_draw_log2(&s_>);
    }
  }
LAB_004c04ca:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 004c04f0
/* public: unsigned char __thiscall RGE_Sprite::draw(long,long,long,long,long,long,class
   RGE_Color_Table *,class TDrawArea *,unsigned char) */

uchar __thiscall
RGE_Sprite::draw(RGE_Sprite *this,long param_1,long param_2,long param_3,long param_4,long param_5,
                long param_6,RGE_Color_Table *param_7,TDrawArea *param_8,uchar param_9)
{
  short sVar1;
  RGE_Picture_List *pRVar2;
  RGE_Sprite *this_00;
  uchar uVar3;
  int iVar4;
  long lVar5;
  long index;
  int local_8;
  int local_4;
  
  if (this->facet_num <= param_1) {
    param_1 = 0;
  }
  if ((this->draw_list_num < 1) || (this->draw_list == (RGE_Picture_List *)0x0)) {
    if (this->draw_level < 0xb) {
      param_3 = param_5;
      param_4 = param_6;
    }
    do_draw(this,param_1,param_2,param_3,param_4,param_7,param_8,param_9);
    uVar3 = '\x01';
  }
  else {
    uVar3 = '\0';
    local_8 = 0;
    if (0 < this->draw_list_num) {
      local_4 = 0;
      do {
        pRVar2 = this->draw_list;
        sVar1 = *(short *)((int)&pRVar2->facet + local_4);
        if ((sVar1 < 0) || (sVar1 == param_1)) {
          this_00 = *(RGE_Sprite **)((int)&pRVar2->sprite + local_4);
          iVar4 = (int)*(short *)((int)&pRVar2->offset_y + local_4);
          if (this_00->draw_level < 0xb) {
            iVar4 = iVar4 + param_6;
            sVar1 = *(short *)((int)&pRVar2->offset_x + local_4);
            lVar5 = param_5;
          }
          else {
            iVar4 = iVar4 + param_4;
            sVar1 = *(short *)((int)&pRVar2->offset_x + local_4);
            lVar5 = param_3;
          }
          do_draw(this_00,(this_00->facet_num * param_1) / (int)this->facet_num,param_2,
                  sVar1 + lVar5,iVar4,param_7,param_8,param_9);
        }
        local_8 = local_8 + 1;
        local_4 = local_4 + 0x10;
      } while (local_8 < this->draw_list_num);
      return (uchar)local_8;
    }
  }
  return uVar3;
}

// --------------------------------------------------

// Function: normal_draw
// Address: 004c0620
/* WARNING: Variable defined which should be unmapped: index */
/* public: unsigned char __thiscall RGE_Sprite::normal_draw(long,long,long,long,class
   RGE_Color_Table *,class TDrawArea *) */

uchar __thiscall
RGE_Sprite::normal_draw
          (RGE_Sprite *this,long param_1,long param_2,long param_3,long param_4,
          RGE_Color_Table *param_5,TDrawArea *param_6)
{
  short sVar1;
  RGE_Picture_List *pRVar2;
  RGE_Sprite *this_00;
  uchar uVar3;
  long lVar4;
  long index;
  int local_4;
  
  lVar4 = param_1;
  if (this->facet_num <= param_1) {
    lVar4 = 0;
  }
  uVar3 = '\0';
  if ((this->draw_list_num < 1) || (this->draw_list == (RGE_Picture_List *)0x0)) {
    if (this->draw_level == '\x14') {
      do_draw(this,lVar4,param_2,param_3,param_4,param_5,param_6,'\0');
    }
    uVar3 = '\x01';
  }
  else {
    local_4 = 0;
    if (0 < this->draw_list_num) {
      param_1 = 0;
      do {
        pRVar2 = this->draw_list;
        this_00 = *(RGE_Sprite **)((int)&pRVar2->sprite + param_1);
        if ((this_00->draw_level == '\x14') &&
           ((sVar1 = *(short *)((int)&pRVar2->facet + param_1), sVar1 < 0 || (sVar1 == lVar4)))) {
          do_draw(this_00,(this_00->facet_num * lVar4) / (int)this->facet_num,param_2,
                  *(short *)((int)&pRVar2->offset_x + param_1) + param_3,
                  *(short *)((int)&pRVar2->offset_y + param_1) + param_4,param_5,param_6,'\0');
        }
        local_4 = local_4 + 1;
        param_1 = param_1 + 0x10;
      } while (local_4 < this->draw_list_num);
      return (uchar)local_4;
    }
  }
  return uVar3;
}

// --------------------------------------------------

// Function: shadow_draw
// Address: 004c0720
/* public: unsigned char __thiscall RGE_Sprite::shadow_draw(long,long,long,long,class
   RGE_Color_Table *,class TDrawArea *,unsigned char) */

uchar __thiscall
RGE_Sprite::shadow_draw
          (RGE_Sprite *this,long param_1,long param_2,long param_3,long param_4,
          RGE_Color_Table *param_5,TDrawArea *param_6,uchar param_7)
{
  short sVar1;
  RGE_Picture_List *pRVar2;
  RGE_Sprite *this_00;
  long lVar3;
  int local_4;
  
  lVar3 = param_1;
  if (this->facet_num <= param_1) {
    lVar3 = 0;
  }
  if ((this->draw_list_num < 1) || (this->draw_list == (RGE_Picture_List *)0x0)) {
    if ((this->draw_level != param_7) && (this->draw_level < 0x14)) {
      do_draw(this,lVar3,param_2,param_3,param_4,param_5,param_6,'\0');
    }
    param_1 = 1;
  }
  else {
    param_1 = 0;
    if (0 < this->draw_list_num) {
      local_4 = 0;
      do {
        pRVar2 = this->draw_list;
        this_00 = *(RGE_Sprite **)((int)&pRVar2->sprite + local_4);
        if (((this_00->draw_level != param_7) && (this_00->draw_level < 0x14)) &&
           ((sVar1 = *(short *)((int)&pRVar2->facet + local_4), sVar1 < 0 || (sVar1 == lVar3)))) {
          do_draw(this_00,(this_00->facet_num * lVar3) / (int)this->facet_num,param_2,
                  *(short *)((int)&pRVar2->offset_x + local_4) + param_3,
                  *(short *)((int)&pRVar2->offset_y + local_4) + param_4,param_5,param_6,'\0');
        }
        local_4 = local_4 + 0x10;
        param_1 = param_1 + 1;
      } while (param_1 < this->draw_list_num);
      return (uchar)param_1;
    }
  }
  return (uchar)param_1;
}

// --------------------------------------------------

// Function: get_size
// Address: 004c0840
// [HELPER] s_C__msdev_work_age1_x1_sprite_cpp: "C:\msdev\work\age1_x1\sprite.cpp"
// [HELPER] s__shp: ".shp"
/* WARNING: Variable defined which should be unmapped: fname */
/* public: int __thiscall RGE_Sprite::get_size(long &,long &,long &,long &,long) */

int __thiscall
RGE_Sprite::get_size
          (RGE_Sprite *this,long *param_1,long *param_2,long *param_3,long *param_4,long param_5)
{
  byte bVar1;
  ulong uVar2;
  TShape *pTVar3;
  ulong uVar4;
  undefined4 *unaff_FS_OFFSET;
  char *fname;
  char *local_14;
  TShape *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f91b;
  *unaff_FS_OFFSET = &local_c;
  if (this->shape == (TShape *)0x0) {
    if (this->loaded == '\0') {
      *unaff_FS_OFFSET = local_c;
      return 0;
    }
    local_14 = (char *)0x0;
    addstring(&local_14,this->pict_name,s__shp);
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x2b9);
    local_10 = (TShape *)operator_new(0x20);
    local_4 = 0;
    if (local_10 == (TShape *)0x0) {
      pTVar3 = (TShape *)0x0;
    }
    else {
      pTVar3 = (TShape *)TShape::TShape(local_10,local_14,this->resource_id);
    }
    local_4 = 0xffffffff;
    this->shape = pTVar3;
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,699);
    RGE_Base_Game::add_to_timing(rge_base_game,0xb,uVar4 - uVar2);
    free(local_14);
  }
  bVar1 = TShape::shape_minmax(this->shape,param_1,param_2,param_3,param_4,param_5);
  *unaff_FS_OFFSET = local_c;
  return (uint)bVar1;
}

// --------------------------------------------------

// Function: get_frame
// Address: 004c0960
// [HELPER] s_C__msdev_work_age1_x1_sprite_cpp: "C:\msdev\work\age1_x1\sprite.cpp"
// [HELPER] s__shp: ".shp"
/* WARNING: Variable defined which should be unmapped: fname */
/* public: int __thiscall RGE_Sprite::get_frame(short &,short &,short &,short &,long,long) */

int __thiscall
RGE_Sprite::get_frame
          (RGE_Sprite *this,short *param_1,short *param_2,short *param_3,short *param_4,long param_5
          ,long param_6)
{
  RGE_Picture_List *pRVar1;
  RGE_Sprite *this_00;
  short *psVar2;
  ulong uVar3;
  TShape *pTVar4;
  ulong uVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  char *fname;
  char *local_14;
  TShape *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  psVar2 = param_1;
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f93b;
  *unaff_FS_OFFSET = &local_c;
  if (this->shape == (TShape *)0x0) {
    if (this->loaded != '\0') {
      local_14 = (char *)0x0;
      addstring(&local_14,this->pict_name,s__shp);
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x2d2);
      local_10 = (TShape *)operator_new(0x20);
      local_4 = 0;
      if (local_10 == (TShape *)0x0) {
        pTVar4 = (TShape *)0x0;
      }
      else {
        pTVar4 = (TShape *)TShape::TShape(local_10,local_14,this->resource_id);
      }
      local_4 = 0xffffffff;
      this->shape = pTVar4;
      uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x2d4);
      RGE_Base_Game::add_to_timing(rge_base_game,0xb,uVar5 - uVar3);
      free(local_14);
      goto LAB_004c0a23;
    }
LAB_004c0b1c:
    iVar6 = 0;
  }
  else {
LAB_004c0a23:
    if (((this->box_x1 == 0) && (this->box_x2 == 0)) || ((this->box_y1 == 0 && (this->box_y2 == 0)))
       ) {
      *param_1 = 0;
      *param_2 = 0;
      *param_3 = 0;
      *param_4 = 0;
      if ((this->draw_list_num < 1) || (this->draw_list == (RGE_Picture_List *)0x0)) {
        get_frame_min_max(this,param_1,param_2,param_3,param_4,param_5,param_6,0,0);
      }
      else {
        param_1 = (short *)0x0;
        if (0 < this->draw_list_num) {
          iVar6 = 0;
          do {
            if (this->transparent_picking_flag != '\0') {
              pRVar1 = this->draw_list;
              this_00 = *(RGE_Sprite **)((int)&pRVar1->sprite + iVar6);
              get_frame_min_max(this_00,psVar2,param_2,param_3,param_4,
                                (this_00->facet_num * param_5) / (int)this->facet_num,param_6,
                                *(short *)((int)&pRVar1->offset_x + iVar6),
                                *(short *)((int)&pRVar1->offset_y + iVar6));
            }
            iVar6 = iVar6 + 0x10;
            param_1 = (short *)((int)param_1 + 1);
          } while ((int)param_1 < (int)this->draw_list_num);
        }
      }
      if (((*psVar2 == 0) && (*param_3 == 0)) || ((*param_2 == 0 && (*param_4 == 0))))
      goto LAB_004c0b1c;
    }
    else {
      *param_1 = this->box_x1;
      *param_2 = this->box_y1;
      *param_3 = this->box_x2;
      *param_4 = this->box_y2;
    }
    iVar6 = 1;
  }
  *unaff_FS_OFFSET = local_c;
  return iVar6;
}

// --------------------------------------------------

// Function: get_frame_min_max
// Address: 004c0b70
/* WARNING: Variable defined which should be unmapped: facetindex */
/* public: int __thiscall RGE_Sprite::get_frame_min_max(short &,short &,short &,short
   &,long,long,short,short) */

int __thiscall
RGE_Sprite::get_frame_min_max
          (RGE_Sprite *this,short *param_1,short *param_2,short *param_3,short *param_4,long param_5
          ,long param_6,short param_7,short param_8)
{
  uchar uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long facetindex;
  long calc_min_y;
  long calc_max_y;
  int local_4;
  
  lVar2 = param_6;
  if (this->frame_num <= param_6) {
    lVar2 = 0;
  }
  uVar1 = get_facetindex(this,param_5,lVar2,&calc_min_y);
  iVar3 = get_size(this,&param_5,&calc_max_y,&param_6,&local_4,calc_min_y);
  if (iVar3 != 0) {
    if (uVar1 != '\0') {
      iVar3 = -param_5;
      param_5 = -param_6;
      param_6 = iVar3;
    }
    iVar3 = param_5 + param_7;
    iVar4 = param_6 + param_7;
    iVar5 = calc_max_y + param_8;
    local_4 = local_4 + param_8;
    if (iVar3 < *param_1) {
      *param_1 = (short)iVar3;
    }
    if (iVar5 < *param_2) {
      *param_2 = (short)iVar5;
    }
    if (*param_3 < iVar4) {
      *param_3 = (short)iVar4;
    }
    if (*param_4 < local_4) {
      *param_4 = (short)local_4;
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: get_lowest_draw_level
// Address: 004c0c50
/* public: unsigned char __thiscall RGE_Sprite::get_lowest_draw_level(void) */

uchar __thiscall RGE_Sprite::get_lowest_draw_level(RGE_Sprite *this)
{
  short sVar1;
  byte bVar2;
  RGE_Sprite **ppRVar3;
  int iVar4;
  
  sVar1 = this->draw_list_num;
  if (sVar1 == 0) {
    return this->draw_level;
  }
  bVar2 = 0x14;
  if (0 < sVar1) {
    ppRVar3 = &this->draw_list->sprite;
    iVar4 = (int)sVar1;
    do {
      if ((*ppRVar3)->draw_level < bVar2) {
        bVar2 = (*ppRVar3)->draw_level;
      }
      ppRVar3 = ppRVar3 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return bVar2;
}

// --------------------------------------------------

// Function: hit_test
// Address: 004c0c90
/* WARNING: Variable defined which should be unmapped: index */
/* public: unsigned char __thiscall RGE_Sprite::hit_test(short,short,long,long) */

uchar __thiscall
RGE_Sprite::hit_test(RGE_Sprite *this,short param_1,short param_2,long param_3,long param_4)
{
  RGE_Picture_List *pRVar1;
  RGE_Sprite *this_00;
  uchar uVar2;
  int iVar3;
  long index;
  int local_4;
  
  iVar3 = 0;
  if ((((this->box_x1 != 0) || (this->box_x2 != 0)) && ((this->box_y1 != 0 || (this->box_y2 != 0))))
     && ((((this->box_x1 <= param_1 && (param_1 <= this->box_x2)) && (this->box_y1 <= param_2)) &&
         (param_2 <= this->box_y2)))) {
    return '\x01';
  }
  if ((0 < this->draw_list_num) && (this->draw_list != (RGE_Picture_List *)0x0)) {
    local_4 = 0;
    if (0 < this->draw_list_num) {
      do {
        pRVar1 = this->draw_list;
        this_00 = *(RGE_Sprite **)((int)&pRVar1->sprite + iVar3);
        uVar2 = shape_hit_test(this_00,param_1 - *(short *)((int)&pRVar1->offset_x + iVar3),
                               param_2 - *(short *)((int)&pRVar1->offset_y + iVar3),
                               (this_00->facet_num * param_3) / (int)this->facet_num,param_4);
        if (uVar2 != '\0') {
          return '\x01';
        }
        iVar3 = iVar3 + 0x10;
        local_4 = local_4 + 1;
      } while (local_4 < this->draw_list_num);
    }
    return '\0';
  }
  uVar2 = shape_hit_test(this,param_1,param_2,param_3,param_4);
  return uVar2;
}

// --------------------------------------------------

// Function: shape_hit_test
// Address: 004c0d80
// [HELPER] s_C__msdev_work_age1_x1_sprite_cpp: "C:\msdev\work\age1_x1\sprite.cpp"
// [HELPER] s__shp: ".shp"
/* WARNING: Variable defined which should be unmapped: fname */
/* public: unsigned char __thiscall RGE_Sprite::shape_hit_test(short,short,long,long) */

uchar __thiscall
RGE_Sprite::shape_hit_test(RGE_Sprite *this,short param_1,short param_2,long param_3,long param_4)
{
  uchar uVar1;
  uchar uVar2;
  ulong uVar3;
  TShape *pTVar4;
  ulong uVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  char *fname;
  long shape_num;
  long xmin;
  long xmax;
  long ymin;
  long ymax;
  int local_14;
  TShape *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f95b;
  *unaff_FS_OFFSET = &local_c;
  if (this->shape == (TShape *)0x0) {
    if (this->loaded == '\0') goto LAB_004c0f6e;
    shape_num = 0;
    addstring((char **)&shape_num,this->pict_name,s__shp);
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x366);
    local_10 = (TShape *)operator_new(0x20);
    local_4 = 0;
    if (local_10 == (TShape *)0x0) {
      pTVar4 = (TShape *)0x0;
    }
    else {
      pTVar4 = (TShape *)TShape::TShape(local_10,(char *)shape_num,this->resource_id);
    }
    local_4 = 0xffffffff;
    this->shape = pTVar4;
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_sprite_cpp,0x368);
    RGE_Base_Game::add_to_timing(rge_base_game,0xb,uVar5 - uVar3);
    free(shape_num);
  }
  if (this->frame_num < param_4) {
    param_4 = 0;
  }
  uVar1 = get_facetindex(this,param_3,param_4,&xmin);
  uVar2 = this->transparent_picking_flag;
  if (uVar2 != '\0') {
    if (uVar2 == '\x01') {
      pTVar4 = this->shape;
      if (pTVar4 != (TShape *)0x0) {
        if (uVar1 == '\0') {
          uVar2 = TShape::shape_check(pTVar4,(int)param_1,(int)param_2,xmin);
          *unaff_FS_OFFSET = local_c;
          return uVar2;
        }
        uVar2 = TShape::shape_check(pTVar4,-(int)param_1,(int)param_2,xmin);
        *unaff_FS_OFFSET = local_c;
        return uVar2;
      }
    }
    else if ((uVar2 == '\x02') && (this->shape != (TShape *)0x0)) {
      TShape::shape_minmax(this->shape,&xmax,&ymax,&ymin,&local_14,xmin);
      iVar6 = (int)param_1;
      if (uVar1 == '\0') {
        if (iVar6 < xmax) goto LAB_004c0f6e;
      }
      else {
        if (iVar6 < -ymin) goto LAB_004c0f6e;
        ymin = -xmax;
      }
      if (((iVar6 <= ymin) && (ymax <= param_2)) && (param_2 <= local_14)) {
        *unaff_FS_OFFSET = local_c;
        return '\x01';
      }
    }
  }
LAB_004c0f6e:
  *unaff_FS_OFFSET = local_c;
  return '\0';
}

// --------------------------------------------------

// Function: make_active_sprite
// Address: 004c0f90
/* public: class RGE_Active_Sprite * __thiscall RGE_Sprite::make_active_sprite(void) */

RGE_Active_Sprite * __thiscall RGE_Sprite::make_active_sprite(RGE_Sprite *this)
{
  RGE_Active_Animated_Sprite *this_00;
  RGE_Active_Sprite *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f986;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if ((this->flag & 1) == 0) {
    pRVar1 = (RGE_Active_Sprite *)operator_new(0x14);
    local_4 = 1;
    if (pRVar1 != (RGE_Active_Sprite *)0x0) {
      pRVar1 = (RGE_Active_Sprite *)RGE_Active_Sprite::RGE_Active_Sprite(pRVar1,this);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
  }
  else {
    this_00 = (RGE_Active_Animated_Sprite *)operator_new(0x28);
    local_4 = 0;
    if (this_00 != (RGE_Active_Animated_Sprite *)0x0) {
      pRVar1 = (RGE_Active_Sprite *)
               RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(this_00,this);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Active_Sprite *)0x0;
}

// --------------------------------------------------

// Function: check_for_shadows
// Address: 004c1030
/* public: int __thiscall RGE_Sprite::check_for_shadows(void) */

int __thiscall RGE_Sprite::check_for_shadows(RGE_Sprite *this)
{
  short sVar1;
  int iVar2;
  RGE_Sprite **ppRVar3;
  
  sVar1 = this->draw_list_num;
  if ((sVar1 < 1) || (this->draw_list == (RGE_Picture_List *)0x0)) {
    if (this->draw_level != '\0') {
      return 0;
    }
  }
  else {
    iVar2 = 0;
    if (sVar1 < 1) {
      return 0;
    }
    ppRVar3 = &this->draw_list->sprite;
    while ((*ppRVar3)->draw_level != '\0') {
      iVar2 = iVar2 + 1;
      ppRVar3 = ppRVar3 + 4;
      if (sVar1 <= iVar2) {
        return 0;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: update
// Address: 004c1080
/* public: void __thiscall RGE_Sprite::update(unsigned long) */

void __thiscall RGE_Sprite::update(RGE_Sprite *this,ulong param_1)
{
  TShape *this_00;
  int iVar1;
  
  if ((this->loaded != '\0') && (this_00 = this->shape, this_00 != (TShape *)0x0)) {
    if ((double)this->delta_time == DAT_00574524._4_8_) {
      this->last_time = param_1;
      this->delta_time = 1;
      return;
    }
    iVar1 = this->last_time;
    this->last_time = param_1;
    iVar1 = (param_1 - iVar1) + this->delta_time;
    this->delta_time = iVar1;
    if (179999 < iVar1) {
      if (this_00 != (TShape *)0x0) {
        TShape::~TShape(this_00);
        operator_delete(this_00);
      }
      this->shape = (TShape *)0x0;
    }
  }
  return;
}

// --------------------------------------------------

