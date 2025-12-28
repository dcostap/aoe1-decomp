// Class: TRIBE_Scenario_Editor_Panel_Object
// Size:  0x21C
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] setup
// [02] set_rect
// [03] set_rect
// [04] set_color
// [05] set_active
// [06] set_positioning
// [07] set_fixed_position
// [08] set_redraw
// [09] set_overlapped_redraw
// [10] draw_setup
// [11] draw_finish
// [12] draw
// [13] draw_rect
// [14] draw_offset
// [15] draw_rect2
// [16] draw_offset2
// [17] paint
// [18] wnd_proc
// [19] handle_idle
// [20] handle_size
// [21] handle_paint
// [22] handle_key_down
// [23] handle_char
// [24] handle_command
// [25] handle_user_command
// [26] handle_timer_command
// [27] handle_scroll
// [28] handle_mouse_down
// [29] handle_mouse_move
// [30] handle_mouse_up
// [31] handle_mouse_dbl_click
// [32] mouse_move_action
// [33] mouse_left_down_action
// [34] mouse_left_hold_action
// [35] mouse_left_move_action
// [36] mouse_left_up_action
// [37] mouse_left_dbl_click_action
// [38] mouse_right_down_action
// [39] mouse_right_hold_action
// [40] mouse_right_move_action
// [41] mouse_right_up_action
// [42] mouse_right_dbl_click_action
// [43] key_down_action
// [44] char_action
// [45] action
// [46] get_true_render_rect
// [47] is_inside
// [48] set_focus
// [49] set_tab_order
// [50] set_tab_order
// [51] get_help_info
// [52] stop_sound_system
// [53] restart_sound_system
// [54] take_snapshot
// [55] handle_reactivate
// [56] draw_item
//
// Member Layout:
// [0x214] RGE_Master_Static_Object * master_game_obj
// [0x218] int master_culture_id
// ----------------------------------------------------------------

// Function: TRIBE_Scenario_Editor_Panel_Object
// Address: 004bedc0
TRIBE_Scenario_Editor_Panel_Object * __thiscall
TRIBE_Scenario_Editor_Panel_Object::TRIBE_Scenario_Editor_Panel_Object
          (TRIBE_Scenario_Editor_Panel_Object *this,TDrawArea *param_1,TPanel *param_2,void *param_3
          ,long param_4,long param_5,TShape *param_6,TShape **param_7,TRIBE_Player *param_8)
{
  TRIBE_Panel_Object::TRIBE_Panel_Object
            ((TRIBE_Panel_Object *)this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,
             param_8);
  this->_padding_ = (int)&_vftable_;
  this->master_game_obj = (RGE_Master_Static_Object *)0x0;
  this->master_culture_id = 0;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004bee10
void * __thiscall
TRIBE_Scenario_Editor_Panel_Object::_scalar_deleting_destructor_
          (TRIBE_Scenario_Editor_Panel_Object *this,uint param_1)
{
  ~TRIBE_Scenario_Editor_Panel_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Scenario_Editor_Panel_Object
// Address: 004bee30
void __thiscall
TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Scenario_Editor_Panel_Object
          (TRIBE_Scenario_Editor_Panel_Object *this)
{
  this->_padding_ = (int)&_vftable_;
  TRIBE_Panel_Object::~TRIBE_Panel_Object((TRIBE_Panel_Object *)this);
  return;
}

// --------------------------------------------------

// Function: set_master_info
// Address: 004bee40
void __thiscall
TRIBE_Scenario_Editor_Panel_Object::set_master_info
          (TRIBE_Scenario_Editor_Panel_Object *this,RGE_Master_Static_Object *param_1,
          TRIBE_Player *param_2)
{
  this->master_game_obj = param_1;
  this->_padding_ = (int)param_2;
  if (param_2 == (TRIBE_Player *)0x0) {
    this->master_culture_id = 0;
    return;
  }
  this->master_culture_id = (uint)(byte)param_2->_padding_;
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 004bee70
// [HELPER] s_Gaia: "Gaia"
// [HELPER] s_Unknown: "Unknown"
// [HELPER] s__d__d: "%d+%d"
// [HELPER] s__s: "%s"
void __thiscall TRIBE_Scenario_Editor_Panel_Object::draw(TRIBE_Scenario_Editor_Panel_Object *this)
{
  char cVar1;
  byte bVar2;
  uchar uVar3;
  RGE_Master_Static_Object *pRVar4;
  code *pcVar5;
  short sVar6;
  uchar *puVar7;
  void *pvVar8;
  undefined4 uVar9;
  byte *pbVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  long lVar14;
  uint uVar15;
  uint uVar16;
  int unaff_EBX;
  byte *pbVar17;
  char *pcVar18;
  int iVar19;
  float *pfVar20;
  short sVar21;
  TShape *this_00;
  char *pcVar22;
  bool bVar23;
  int text_flag;
  int iStack_e4;
  void *old_font;
  long min_x;
  long min_y;
  long max_y;
  long max_x;
  char name [100];
  char str [100];
  
  if (((this->_padding_ == 0) || (this->_padding_ == 0)) || (this->_padding_ == 0)) {
LAB_004bf48b:
    this->_padding_ = 0;
    return;
  }
  if ((char)this->_padding_ == '\x02') {
    TRIBE_Panel_Object::draw_score((TRIBE_Panel_Object *)this);
    return;
  }
  if (this->master_game_obj == (RGE_Master_Static_Object *)0x0) {
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0x34))(&this->_padding_);
      this->_padding_ = 0;
      return;
    }
    goto LAB_004bf48b;
  }
  iVar11 = this->_padding_;
  (**(code **)(iVar11 + 0x28))(0);
  TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,0);
  puVar7 = TDrawArea::Lock((TDrawArea *)this->_padding_,(char *)0x0,1);
  text_flag = unaff_EBX;
  if (puVar7 != (uchar *)0x0) {
    pRVar4 = this->master_game_obj;
    text_flag = 1;
    sVar21 = pRVar4->button_pict;
    if (sVar21 == -1) {
      if (pRVar4->sprite != (RGE_Sprite *)0x0) {
        text_flag = 0;
        iVar19 = RGE_Sprite::get_size(pRVar4->sprite,&min_x,&min_y,&max_x,&max_y,0);
        if (iVar19 != 0) {
          RGE_Sprite::do_draw(this->master_game_obj->sprite,0,0,(this->_padding_ - min_x) + 10,
                              (this->_padding_ - min_y) + 0x28,
                              *(RGE_Color_Table **)(this->_padding_ + 0x108),
                              (TDrawArea *)this->_padding_,'\0');
        }
      }
    }
    else {
      if (pRVar4->unit_level == '\x02') {
        this_00 = *(TShape **)(this->_padding_ + this->master_culture_id * 4);
        sVar21 = sVar21 + *(short *)((int)&pRVar4[1].outline_radius_z + 2);
      }
      else {
        this_00 = (TShape *)this->_padding_;
      }
      if ((this->_padding_ == 0) || (iVar19 = *(int *)(this->_padding_ + 0x108), iVar19 == -0x28)) {
        TShape::shape_draw(this_00,(TDrawArea *)this->_padding_,this->_padding_ + 2,
                           this->_padding_ + 0x21,(int)sVar21,'\0',(uchar *)0x0);
      }
      else {
        _ASMSet_Color_Xform((*(short *)(iVar19 + 0x26) + 1) * 0x10);
        TShape::shape_draw(this_00,(TDrawArea *)this->_padding_,this->_padding_ + 2,
                           this->_padding_ + 0x21,(int)sVar21,'\x01',
                           (uchar *)(*(int *)(this->_padding_ + 0x108) + 0x28));
      }
    }
    TDrawArea::Unlock((TDrawArea *)this->_padding_,(char *)0x0);
  }
  pvVar8 = TDrawArea::GetDc((TDrawArea *)this->_padding_,(char *)0x0);
  if (pvVar8 != (void *)0x0) {
    SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
    SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
    SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_);
    uVar9 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_);
    if (this->_padding_ != 0) {
      (**(code **)(rge_base_game->_padding_ + 0x28))
                (0x69,(int)*(short *)(this->_padding_ + 0x4a),0,name,100);
      pbVar17 = &s_Unknown;
      pbVar10 = (byte *)name;
      do {
        bVar2 = *pbVar10;
        bVar23 = bVar2 < *pbVar17;
        if (bVar2 != *pbVar17) {
LAB_004bf0f9:
          iVar11 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);
          goto LAB_004bf0fe;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar10[1];
        bVar23 = bVar2 < pbVar17[1];
        if (bVar2 != pbVar17[1]) goto LAB_004bf0f9;
        pbVar10 = pbVar10 + 2;
        pbVar17 = pbVar17 + 2;
      } while (bVar2 != 0);
      iVar11 = 0;
LAB_004bf0fe:
      if (iVar11 == 0) {
        uVar15 = 0xffffffff;
        pcVar18 = &s_Gaia;
        do {
          pcVar22 = pcVar18;
          if (uVar15 == 0) break;
          uVar15 = uVar15 - 1;
          pcVar22 = pcVar18 + 1;
          cVar1 = *pcVar18;
          pcVar18 = pcVar22;
        } while (cVar1 != '\0');
        uVar15 = ~uVar15;
        pcVar18 = pcVar22 + -uVar15;
        pcVar22 = name;
        for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
          *(undefined4 *)pcVar22 = *(undefined4 *)pcVar18;
          pcVar18 = pcVar18 + 4;
          pcVar22 = pcVar22 + 4;
        }
        for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
          *pcVar22 = *pcVar18;
          pcVar18 = pcVar18 + 1;
          pcVar22 = pcVar22 + 1;
        }
      }
      uVar15 = 0xffffffff;
      pcVar18 = name;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        cVar1 = *pcVar18;
        pcVar18 = pcVar18 + 1;
      } while (cVar1 != '\0');
      TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_ + 2,this->_padding_,name,
               ~uVar15 - 1);
    }
    sVar21 = this->master_game_obj->string_id;
    if (sVar21 < 1) {
      str[0] = '\0';
    }
    else {
      (**(code **)(rge_base_game->_padding_ + 0x20))((int)sVar21,str,100);
    }
    if (str[0] == '\0') {
      uVar15 = 0xffffffff;
      pcVar18 = this->master_game_obj->name;
      do {
        pcVar22 = pcVar18;
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        pcVar22 = pcVar18 + 1;
        cVar1 = *pcVar18;
        pcVar18 = pcVar22;
      } while (cVar1 != '\0');
      uVar15 = ~uVar15;
      pcVar18 = pcVar22 + -uVar15;
      pcVar22 = str;
      for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
        *(undefined4 *)pcVar22 = *(undefined4 *)pcVar18;
        pcVar18 = pcVar18 + 4;
        pcVar22 = pcVar22 + 4;
      }
      for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
        *pcVar22 = *pcVar18;
        pcVar18 = pcVar18 + 1;
        pcVar22 = pcVar22 + 1;
      }
    }
    sprintf(name,s__s,str);
    uVar15 = 0xffffffff;
    pcVar18 = name;
    do {
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      cVar1 = *pcVar18;
      pcVar18 = pcVar18 + 1;
    } while (cVar1 != '\0');
    TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_ + 2,this->_padding_ + 0xf,name,
             ~uVar15 - 1);
    if (text_flag != 0) {
      iVar11 = (int)this->master_game_obj->hp;
      sprintf(str,s__d__d,iVar11,iVar11);
      uVar15 = 0xffffffff;
      pcVar18 = str;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        cVar1 = *pcVar18;
        pcVar18 = pcVar18 + 1;
      } while (cVar1 != '\0');
      TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_ + 5,this->_padding_ + 0x55,
               str,~uVar15 - 1);
      SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar9);
      SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),0);
    }
    TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,(char *)0x0);
    iVar11 = iStack_e4;
  }
  if (text_flag == 0) goto switchD_004bf313_caseD_4;
  pRVar4 = this->master_game_obj;
  iVar19 = 0;
  uVar3 = pRVar4->unit_level;
  if (uVar3 == '\x03') {
LAB_004bf3c9:
    iVar19 = (int)*(short *)((int)&pRVar4[1].multiple_attribute_mod + 2);
    (**(code **)(iVar11 + 0xe0))(0,7,1,iVar19,iVar19);
    iVar19 = 1;
  }
  else {
    if (((uVar3 != '\t') && (uVar3 != '\x04')) &&
       ((uVar3 != '\x05' && ((uVar3 != '\x06' && (uVar3 != '\a')))))) {
      if (uVar3 == '\x01') {
        sVar21 = -1;
        iVar19 = 0;
        pfVar20 = pRVar4->attribute_amount_held;
        do {
          if ((float)DAT_00574524 < *pfVar20) {
            sVar21 = pRVar4->attribute_type_held[iVar19];
            break;
          }
          iVar19 = iVar19 + 1;
          pfVar20 = pfVar20 + 1;
        } while (iVar19 < 3);
        switch(sVar21) {
        case 0:
        case 0xf:
        case 0x10:
        case 0x11:
          uVar9 = 2;
          break;
        case 1:
          uVar9 = 0;
          break;
        case 2:
          uVar9 = 1;
          break;
        case 3:
          uVar9 = 3;
          break;
        default:
          goto switchD_004bf313_caseD_4;
        }
        uVar12 = __ftol(0);
        (**(code **)(iVar11 + 0xe0))(0,uVar9,0,uVar12);
        (**(code **)(iVar11 + 0x2c))();
        return;
      }
      if (uVar3 == '\x02') {
        iVar19 = (int)*(short *)((int)&pRVar4[1].multiple_attribute_mod + 2);
        pcVar5 = *(code **)(iVar11 + 0xe0);
        (*pcVar5)(0,7,1,iVar19,iVar19);
        iVar19 = (int)*(short *)&this->master_game_obj[1].multiple_attribute_mod;
        (*pcVar5)(1,8,1,iVar19,iVar19);
        uVar9 = __ftol();
        (*pcVar5)(2,6,1,uVar9,uVar9);
        (**(code **)(iVar11 + 0x2c))();
        return;
      }
      goto switchD_004bf313_caseD_4;
    }
    if ((uVar3 == '\x03') || (uVar3 == '\x04')) goto LAB_004bf3c9;
  }
  uVar3 = this->master_game_obj->unit_level;
  if ((uVar3 == '\x04') || (uVar3 == '\x06')) {
    iVar13 = (int)*(short *)&this->master_game_obj[1].multiple_attribute_mod;
    (**(code **)(iVar11 + 0xe0))(iVar19,8,1,iVar13,iVar13);
    iVar19 = iVar19 + 1;
  }
  lVar14 = get_pierce_armor(this);
  uVar3 = this->master_game_obj->unit_level;
  sVar21 = (short)lVar14;
  if ((uVar3 == '\x04') || (uVar3 == '\x06')) {
    (**(code **)(iVar11 + 0xe0))(iVar19,10,1,(int)sVar21,(int)sVar21);
    iVar19 = iVar19 + 1;
  }
  uVar3 = this->master_game_obj->unit_level;
  if ((uVar3 == '\x04') || (uVar3 == '\x06')) {
    sVar6 = __ftol();
    (**(code **)(iVar11 + 0xe0))(iVar19,6,1,(int)sVar6,(int)sVar21);
  }
switchD_004bf313_caseD_4:
  (**(code **)(iVar11 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: draw_item
// Address: 004bf4d0
// [HELPER] s__d: "%d"
// [HELPER] s__d__: "%d%%"
// [HELPER] s__d__d: "%d+%d"
void __thiscall
TRIBE_Scenario_Editor_Panel_Object::draw_item
          (TRIBE_Scenario_Editor_Panel_Object *this,int param_1,int param_2,ValueType param_3,
          int param_4,int param_5)
{
  char cVar1;
  uchar *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  char val_str [20];
  
  if (((this->_padding_ != 0) && (param_2 != -1)) &&
     (puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,(char *)0x0,1), puVar2 != (uchar *)0x0))
{
    TShape::shape_draw((TShape *)this->_padding_,(TDrawArea *)this->_padding_,this->_padding_ + 0x3c
                       ,this->_padding_ + 0x1e + param_1 * 0x12,param_2,'\0',(uchar *)0x0);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,(char *)0x0);
  }
  switch(param_3) {
  case ValueTypeNumber:
    sprintf(val_str + 4,&s__d,param_4);
    break;
  case ValueTypeBonus:
    if (param_4 < param_5) {
      sprintf(val_str + 4,s__d__d,param_4,param_5 - param_4);
    }
    else {
      sprintf(val_str + 4,&s__d,param_4);
    }
    break;
  case ValueTypeCompare:
    sprintf(val_str + 4,s__d__d,param_4,param_5);
    break;
  case ValueTypePercent:
    sprintf(val_str + 4,s__d__,param_4);
    break;
  default:
    val_str[4] = '\0';
  }
  if ((val_str[4] != '\0') &&
     (pvVar3 = TDrawArea::GetDc((TDrawArea *)this->_padding_,(char *)0x0), pvVar3 != (void *)0x0)) {
    SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
    SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
    SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_);
    uVar4 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_);
    uVar5 = 0xffffffff;
    pcVar6 = val_str + 4;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_ + 100,
             this->_padding_ + 0x20 + param_1 * 0x12,val_str + 4,~uVar5 - 1);
    SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar4);
    SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),0);
    TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,(char *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: mouse_left_up_action
// Address: 004bf6c0
long __thiscall
TRIBE_Scenario_Editor_Panel_Object::mouse_left_up_action
          (TRIBE_Scenario_Editor_Panel_Object *this,long param_1,long param_2,int param_3,
          int param_4)
{
  TPanel::release_mouse((TPanel *)this);
  return 1;
}

// --------------------------------------------------

// Function: get_pierce_armor
// Address: 004bf6e0
long __thiscall
TRIBE_Scenario_Editor_Panel_Object::get_pierce_armor(TRIBE_Scenario_Editor_Panel_Object *this)
{
  short sVar1;
  RGE_Master_Static_Object *pRVar2;
  long lVar3;
  short *psVar4;
  int iVar5;
  
  pRVar2 = this->master_game_obj;
  if (pRVar2 == (RGE_Master_Static_Object *)0x0) {
    return 0;
  }
  if (pRVar2->master_type != 'F') {
    return 0;
  }
  sVar1._0_1_ = pRVar2[1].sort_number;
  sVar1._1_1_ = pRVar2[1].can_be_built_on;
  iVar5 = (int)sVar1;
  lVar3 = 0;
  if (0 < iVar5) {
    psVar4 = *(short **)&pRVar2[1].button_pict;
    do {
      if (*psVar4 == 3) {
        lVar3 = (long)psVar4[1];
      }
      psVar4 = psVar4 + 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return lVar3;
}

// --------------------------------------------------

