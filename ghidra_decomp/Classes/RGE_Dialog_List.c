// Class: RGE_Dialog_List
// Size:  0x4BC
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
// [56] draw_background
// [57] set_ideal_size
// [58] create_button
// [59] create_button
// [60] create_check_box
// [61] create_radio_button
// [62] create_text
// [63] create_text
// [64] create_text
// [65] create_input
// [66] create_edit
// [67] create_drop_down
// [68] create_list
// [69] create_scrollbar
// [70] create_auto_scrollbar
// [71] create_vert_slider
// [72] create_horz_slider
// [73] position_panel
// [74] setup
// [75] setup
// [76] get_list_id
// [77] get_list_name
// [78] create_list
// [79] get_cur_id
// [80] generate
//
// Member Layout:
// [0x4AC] int list_type
// [0x4B0] short list_size
// [0x4B2] short list_line
// [0x4B4] rdlg_list_info * list_info
// [0x4B8] char * * list_text
// ----------------------------------------------------------------

// Function: RGE_Dialog_List
// Address: 0047e670
/* public: __thiscall RGE_Dialog_List::RGE_Dialog_List(char *) */

RGE_Dialog_List * __thiscall RGE_Dialog_List::RGE_Dialog_List(RGE_Dialog_List *this,char *param_1)
{
  TListDialog::TListDialog((TListDialog *)this,param_1);
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0047e690
/* public: virtual void * __thiscall RGE_Dialog_List::`scalar deleting destructor'(unsigned int) */

void * __thiscall RGE_Dialog_List::_scalar_deleting_destructor_(RGE_Dialog_List *this,uint param_1)
{
  ~RGE_Dialog_List(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 0047e6b0
/* public: int __thiscall RGE_Dialog_List::setup(class TScreenPanel *,char *,long,int,char *) */

int __thiscall
RGE_Dialog_List::setup
          (RGE_Dialog_List *this,TScreenPanel *param_1,char *param_2,long param_3,int param_4,
          char *param_5)
{
  char cVar1;
  int iVar2;
  char **ppcVar3;
  char *pcVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  
  this->list_type = param_4;
  this->list_info = (rdlg_list_info *)0x0;
  this->list_text = (char **)0x0;
  if (this->_padding_ != 0) {
    return 0;
  }
  iVar2 = (**(code **)(this->_padding_ + 0x138))();
  if (iVar2 == 0) {
    return 0;
  }
  sort_list(this);
  calc_list_line(this);
  ppcVar3 = (char **)calloc((int)this->list_size,4);
  this->list_text = ppcVar3;
  if (ppcVar3 == (char **)0x0) {
    return 0;
  }
  iVar2 = 0;
  if (0 < this->list_size) {
    param_4 = 0;
    do {
      uVar6 = 0xffffffff;
      pcVar4 = this->list_info->text + param_4;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar4 = (char *)calloc(~uVar6,1);
      this->list_text[iVar2] = pcVar4;
      if (this->list_text[iVar2] == (char *)0x0) {
        return 0;
      }
      uVar6 = 0xffffffff;
      pcVar4 = this->list_info->text + param_4;
      do {
        pcVar8 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar8 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar8;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar4 = pcVar8 + -uVar6;
      pcVar8 = this->list_text[iVar2];
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar8 = pcVar8 + 4;
      }
      iVar2 = iVar2 + 1;
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar8 = pcVar8 + 1;
      }
      param_4 = param_4 + 0x66;
    } while (iVar2 < this->list_size);
  }
  lVar5 = TListDialog::setup((TListDialog *)this,(TPanel *)param_1,param_2,param_3,0x136,400,10,10,
                             0x122,0x19,param_5,10,0x2d,0x122,0x131,this->list_text,this->list_size,
                             this->list_line,10,0xa0,0x168,0x8c,0x1e);
  return (uint)(lVar5 != 0);
}

// --------------------------------------------------

// Function: ~RGE_Dialog_List
// Address: 0047e830
/* public: virtual __thiscall RGE_Dialog_List::~RGE_Dialog_List(void) */

void __thiscall RGE_Dialog_List::~RGE_Dialog_List(RGE_Dialog_List *this)
{
  int iVar1;
  
  this->_padding_ = (int)&_vftable_;
  if (this->list_text != (char **)0x0) {
    iVar1 = 0;
    if (0 < this->list_size) {
      do {
        if (this->list_text[iVar1] != (char *)0x0) {
          free(this->list_text[iVar1]);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->list_size);
    }
    free(this->list_text);
    this->list_text = (char **)0x0;
  }
  if (this->list_info != (rdlg_list_info *)0x0) {
    free(this->list_info);
    this->list_info = (rdlg_list_info *)0x0;
  }
  TListDialog::~TListDialog((TListDialog *)this);
  return;
}

// --------------------------------------------------

// Function: get_list_id
// Address: 0047e8c0
/* public: virtual short __thiscall RGE_Dialog_List::get_list_id(void) */

short __thiscall RGE_Dialog_List::get_list_id(RGE_Dialog_List *this)
{
  short sVar1;
  
  sVar1 = (short)this->_padding_;
  if (sVar1 == -1) {
    return -1;
  }
  return this->list_info[sVar1].id;
}

// --------------------------------------------------

// Function: create_list
// Address: 0047e8f0
/* protected: virtual int __thiscall RGE_Dialog_List::create_list(void) */

int __thiscall RGE_Dialog_List::create_list(RGE_Dialog_List *this)
{
  int iVar1;
  
  if (this->list_type != 1) {
    return 0;
  }
  iVar1 = create_object_list(this);
  return iVar1;
}

// --------------------------------------------------

// Function: create_object_list
// Address: 0047e910
// [HELPER] s__: "}"
/* WARNING: Variable defined which should be unmapped: j */
/* protected: int __thiscall RGE_Dialog_List::create_object_list(void) */

int __thiscall RGE_Dialog_List::create_object_list(RGE_Dialog_List *this)
{
  char cVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  RGE_Player *pRVar6;
  rdlg_list_info *prVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  short j;
  short i;
  RGE_Player *player;
  short end_i;
  
  pRVar6 = RGE_Base_Game::get_player(rge_base_game);
  if (pRVar6 == (RGE_Player *)0x0) {
    return 0;
  }
  this->list_size = 1;
  sVar2 = pRVar6->master_object_num;
  if (0 < sVar2) {
    iVar10 = 0;
    iVar11 = (int)sVar2;
    do {
      iVar4 = *(int *)((int)pRVar6->master_objects + iVar10);
      if ((iVar4 != 0) && (*(char *)(iVar4 + 0x4e) == '\0')) {
        this->list_size = this->list_size + 1;
      }
      iVar10 = iVar10 + 4;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  if (this->list_size == 0) {
    return 0;
  }
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
  prVar7 = (rdlg_list_info *)calloc((int)this->list_size,0x66);
  this->list_info = prVar7;
  if (prVar7 == (rdlg_list_info *)0x0) {
    return 0;
  }
  uVar8 = 0xffffffff;
  prVar7->id = -1;
  pcVar12 = &s__<None>_;
  do {
    pcVar13 = pcVar12;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar13 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar13;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8;
  sVar5 = 1;
  pcVar12 = pcVar13 + -uVar8;
  prVar7 = this->list_info;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)prVar7->text = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    prVar7 = (rdlg_list_info *)(prVar7->text + 4);
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    prVar7->text[0] = *pcVar12;
    pcVar12 = pcVar12 + 1;
    prVar7 = (rdlg_list_info *)(prVar7->text + 1);
  }
  player = (RGE_Player *)0x0;
  if (0 < sVar2) {
    iVar10 = 0;
    do {
      iVar11 = *(int *)((int)pRVar6->master_objects + iVar10);
      if ((iVar11 != 0) && (*(char *)(iVar11 + 0x4e) == '\0')) {
        this->list_info[sVar5].id = (short)player;
        iVar11 = *(int *)((int)pRVar6->master_objects + iVar10);
        sVar3 = *(short *)(iVar11 + 0xc);
        if (sVar3 < 1) {
          uVar8 = 0xffffffff;
          pcVar12 = *(char **)(iVar11 + 8);
          do {
            pcVar13 = pcVar12;
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            pcVar13 = pcVar12 + 1;
            cVar1 = *pcVar12;
            pcVar12 = pcVar13;
          } while (cVar1 != '\0');
          uVar8 = ~uVar8;
          pcVar12 = pcVar13 + -uVar8;
          prVar7 = this->list_info + sVar5;
          for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined4 *)prVar7->text = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            prVar7 = (rdlg_list_info *)(prVar7->text + 4);
          }
          for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            prVar7->text[0] = *pcVar12;
            pcVar12 = pcVar12 + 1;
            prVar7 = (rdlg_list_info *)(prVar7->text + 1);
          }
        }
        else {
          (**(code **)(rge_base_game->_padding_ + 0x1c))(2,(int)sVar3,this->list_info + sVar5,100);
        }
        sVar5 = sVar5 + 1;
      }
      player = (RGE_Player *)((int)&player->_padding_ + 1);
      iVar10 = iVar10 + 4;
    } while ((short)player < sVar2);
  }
  return 1;
}

// --------------------------------------------------

// Function: sort_list
// Address: 0047ead0
/* protected: void __thiscall RGE_Dialog_List::sort_list(void) */

void __thiscall RGE_Dialog_List::sort_list(RGE_Dialog_List *this)
{
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
  qsort(this->list_info,(int)this->list_size,0x66,rdlg_list_compare);
  return;
}

// --------------------------------------------------

// Function: calc_list_line
// Address: 0047eaf0
/* protected: void __thiscall RGE_Dialog_List::calc_list_line(void) */

void __thiscall RGE_Dialog_List::calc_list_line(RGE_Dialog_List *this)
{
  short sVar1;
  short sVar2;
  
  this->list_line = -1;
  sVar1 = (**(code **)(this->_padding_ + 0x13c))();
  if (sVar1 != -1) {
    sVar2 = 0;
    if (0 < this->list_size) {
      do {
        if (this->list_info[sVar2].id == sVar1) {
          this->list_line = sVar2;
          break;
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < this->list_size);
    }
  }
  if (this->list_line == -1) {
    this->list_line = 0;
  }
  return;
}

// --------------------------------------------------

// Function: get_cur_id
// Address: 0047eb60
/* protected: virtual short __thiscall RGE_Dialog_List::get_cur_id(void) */

short __thiscall RGE_Dialog_List::get_cur_id(RGE_Dialog_List *this)
{
  if (this->list_type != 1) {
    return -1;
  }
  return rge_base_game->master_obj_id;
}

// --------------------------------------------------

