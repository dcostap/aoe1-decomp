// Class: RGE_Main_View
// Function: RGE_Main_View
// Address: 0053dab0
/* public: __thiscall RGE_Main_View::RGE_Main_View(void) */

RGE_Main_View * __thiscall RGE_Main_View::RGE_Main_View(RGE_Main_View *this)
{
  RGE_View::RGE_View((RGE_View *)this);
  this->map_view = (TPanel *)0x0;
  this->last_mouse_scroll_time = 0;
  this->mouse_scrolling = 0;
  this->last_key_scroll_time = 0;
  this->key_scrolling = 0;
  this->save_player = (RGE_Player *)0x0;
  this->_padding_ = (int)&_vftable_;
  this->_padding_ = 10;
  this->mouse_last_x = -1;
  this->mouse_last_y = -1;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0053db10
/* public: virtual void * __thiscall RGE_Main_View::`vector deleting destructor'(unsigned int) */

void * __thiscall RGE_Main_View::_vector_deleting_destructor_(RGE_Main_View *this,uint param_1)
{
  ~RGE_Main_View(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Main_View
// Address: 0053db30
/* public: virtual __thiscall RGE_Main_View::~RGE_Main_View(void) */

void __thiscall RGE_Main_View::~RGE_Main_View(RGE_Main_View *this)
{
  TShape *this_00;
  TSpan_List_Manager *pTVar1;
  DClipInfo_List *pDVar2;
  int iVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561b28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&RGE_View::_vftable_;
  this_00 = (TShape *)this->_padding_;
  uStack_4 = 0;
  if (this_00 != (TShape *)0x0) {
    TShape::~TShape(this_00);
    operator_delete(this_00);
    this->_padding_ = 0;
  }
  RGE_View::delete_surfaces((RGE_View *)this);
  if (this->_padding_ != 0) {
    DeleteObject(this->_padding_);
    this->_padding_ = 0;
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  pTVar1 = (TSpan_List_Manager *)this->_padding_;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = (TSpan_List_Manager *)this->_padding_;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = (TSpan_List_Manager *)this->_padding_;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  pDVar2 = (DClipInfo_List *)this->_padding_;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  pDVar2 = (DClipInfo_List *)this->_padding_;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  piVar4 = &this->_padding_;
  iVar3 = 5;
  do {
    if (*piVar4 != 0) {
      free(*piVar4);
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::set_game_mode(MouseSystem,0);
    TMousePointer::set_game_enable(MouseSystem,0);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  RGE_View::reset_overlay_sprites((RGE_View *)this);
  TPanel::~TPanel((TPanel *)this);
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0053db40
/* public: virtual long __thiscall RGE_Main_View::handle_idle(void) */

long __thiscall RGE_Main_View::handle_idle(RGE_Main_View *this)
{
  long lVar1;
  
  color_log('E','E',5);
  do_auto_scroll(this);
  color_log('E','\x16',5);
  handle_keys(this);
  color_log('E','$',5);
  lVar1 = TPanel::handle_idle((TPanel *)this);
  color_log('E','_',5);
  return lVar1;
}

// --------------------------------------------------

// Function: do_auto_scroll
// Address: 0053dba0
// [HELPER] s_C__msdev_work_age1_x1_vw_main_cp: "C:\msdev\work\age1_x1\vw_main.cpp"
/* WARNING: Variable defined which should be unmapped: vert_scroll */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall RGE_Main_View::do_auto_scroll(void) */

int __thiscall RGE_Main_View::do_auto_scroll(RGE_Main_View *this)
{
  float fVar1;
  RGE_Prog_Info *pRVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  TPanel *pTVar7;
  RGE_Main_View *pRVar8;
  ulong uVar9;
  RGE_Player *pRVar10;
  short sVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float10 fVar13;
  short vert_scroll;
  float scroll_dist2;
  tagPOINT point;
  int iStack_1c;
  tagRECT rect;
  int iStack_4;
  
  iVar6 = rge_base_game->prog_mode;
  if ((((((iVar6 != 4) && (iVar6 != 6)) && (iVar6 != 7)) && (iVar6 != 5)) ||
      (((iVar6 = RGE_Base_Game::get_paused(rge_base_game), iVar6 != 0 ||
        (sVar11 = 0, rge_base_game->prog_info->auto_scroll == 0)) ||
       ((iVar6 = GetForegroundWindow(), iVar6 != *(int *)(this->_padding_ + 4) ||
        (pTVar7 = TPanelSystem::modalPanel(&panel_system), pTVar7 != (TPanel *)0x0)))))) ||
     (((pTVar7 = TPanelSystem::mouseOwner(&panel_system), pTVar7 != (TPanel *)0x0 &&
       (pRVar8 = (RGE_Main_View *)TPanelSystem::mouseOwner(&panel_system), pRVar8 != this)) ||
      (this->key_scrolling != 0)))) {
    this->mouse_scrolling = 0;
    return 0;
  }
  GetWindowRect(*(undefined4 *)(this->_padding_ + 4),&rect.top);
  GetCursorPos(&point.y);
  scroll_dist2._0_2_ = 0;
  sVar4 = scroll_dist2._0_2_;
  scroll_dist2._0_2_ = 0;
  pRVar2 = rge_base_game->prog_info;
  sVar5 = GetAsyncKeyState(1);
  if ((sVar5 < 0) || (sVar5 = GetAsyncKeyState(2), sVar5 < 0)) goto LAB_0053de6d;
  iVar6 = pRVar2->mouse_scroll_edge;
  if (point.y < rect.top + iVar6) {
    sVar11 = -1;
  }
  else if (rect.bottom - iVar6 < point.y) {
    sVar11 = 1;
  }
  if (iStack_1c < rect.right + iVar6) {
    scroll_dist2._0_2_ = -1;
  }
  else {
    scroll_dist2._0_2_ = sVar4;
    if (iStack_4 - iVar6 < iStack_1c) {
      scroll_dist2._0_2_ = 1;
    }
  }
  if ((sVar11 == 0) && (scroll_dist2._0_2_ == 0)) goto LAB_0053de6d;
  uVar9 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0xaa);
  if (this->mouse_scrolling == 0) {
    fVar12 = (float10)_DAT_00577900;
    this->mouse_scrolling = 1;
  }
  else {
    point.x = 0;
    rect.left = 0;
    iVar6 = __ftol();
    fVar1 = _DAT_00577904;
    if (extraout_ST0 - (float10)iVar6 < (float10)_DAT_00577904) {
      fVar1 = _DAT_00577908;
    }
    fVar12 = (float10)fVar1 + (float10)iVar6;
  }
  if ((float10)pRVar2->mouse_scroll_max_dist < fVar12) {
    fVar12 = (float10)pRVar2->mouse_scroll_max_dist;
  }
  if (fVar12 <= (float10)_DAT_00577908) goto LAB_0053de6d;
  fVar1 = (float)(fVar12 + fVar12);
  if (sVar11 == -1) {
    pRVar10 = (RGE_Player *)this->_padding_;
    fVar13 = (float10)pRVar10->view_y - fVar12;
    fVar12 = (float10)pRVar10->view_x - fVar12;
LAB_0053dddf:
    RGE_Player::set_view_loc(pRVar10,(float)fVar12,(float)fVar13);
  }
  else if (sVar11 == 1) {
    pRVar10 = (RGE_Player *)this->_padding_;
    fVar13 = (float10)pRVar10->view_y + fVar12;
    fVar12 = (float10)pRVar10->view_x + fVar12;
    goto LAB_0053dddf;
  }
  if (scroll_dist2._0_2_ == -1) {
    pRVar10 = (RGE_Player *)this->_padding_;
    fVar3 = pRVar10->view_y - fVar1;
    fVar1 = pRVar10->view_x + fVar1;
LAB_0053de3b:
    RGE_Player::set_view_loc(pRVar10,fVar1,fVar3);
  }
  else if (scroll_dist2._0_2_ == 1) {
    pRVar10 = (RGE_Player *)this->_padding_;
    fVar3 = pRVar10->view_y + fVar1;
    fVar1 = pRVar10->view_x - fVar1;
    goto LAB_0053de3b;
  }
  (**(code **)(this->_padding_ + 0x20))(1);
  if (this->map_view != (TPanel *)0x0) {
    (**(code **)(this->map_view->_padding_ + 0x20))(1);
  }
  this->last_mouse_scroll_time = uVar9;
LAB_0053de6d:
  if ((sVar11 == 0) && (scroll_dist2._0_2_ == 0)) {
    this->mouse_scrolling = 0;
  }
  return this->mouse_scrolling;
}

// --------------------------------------------------

// Function: handle_keys
// Address: 0053deb0
// [HELPER] s_C__msdev_work_age1_x1_vw_main_cp: "C:\msdev\work\age1_x1\vw_main.cpp"
/* WARNING: Variable defined which should be unmapped: horz_scroll */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall RGE_Main_View::handle_keys(void) */

int __thiscall RGE_Main_View::handle_keys(RGE_Main_View *this)
{
  float fVar1;
  RGE_Prog_Info *pRVar2;
  int *piVar3;
  float fVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  ulong uVar8;
  RGE_Player *pRVar9;
  uint uVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 fVar12;
  short horz_scroll;
  short vert_scroll;
  float scroll_dist2;
  uchar pbKeyState [256];
  
  iVar7 = RGE_Base_Game::get_paused(rge_base_game);
  if (((iVar7 != 0) ||
      ((((iVar7 = rge_base_game->prog_mode, iVar7 != 4 && (iVar7 != 6)) && (iVar7 != 7)) &&
       (iVar7 != 5)))) ||
     ((iVar7 = GetForegroundWindow(), iVar7 != *(int *)(this->_padding_ + 4) ||
      (uVar10 = 0, this->_padding_ == 0)))) {
    this->key_scrolling = 0;
    return 0;
  }
  GetKeyboardState(pbKeyState + 4);
  sVar5 = 0;
  sVar6 = 0;
  pRVar2 = rge_base_game->prog_info;
  if (((rge_base_game->game_mode == 0x12) && (this->_padding_ != 0)) &&
     (piVar3 = *(int **)(this->_padding_ + 0x130), piVar3 != (int *)0x0)) {
    if (1 < pbKeyState[0x26]) {
      (**(code **)(*piVar3 + 0x34))
                ((float)piVar3[0xe] + pRVar2->key_scroll_object_move,
                 (float)piVar3[0xf] - pRVar2->key_scroll_object_move,0);
    }
    uVar10 = (uint)(1 < pbKeyState[0x26]);
    if (1 < pbKeyState[0x28]) {
      (**(code **)(**(int **)(this->_padding_ + 0x130) + 0x34))
                ((float)piVar3[0xe] - pRVar2->key_scroll_object_move,
                 (float)piVar3[0xf] + pRVar2->key_scroll_object_move,0);
      uVar10 = 1;
    }
    if (1 < pbKeyState[0x25]) {
      (**(code **)(**(int **)(this->_padding_ + 0x130) + 0x34))
                ((float)piVar3[0xe] - pRVar2->key_scroll_object_move,
                 (float)piVar3[0xf] - pRVar2->key_scroll_object_move,0);
      uVar10 = 1;
    }
    if (1 < pbKeyState[0x27]) {
      (**(code **)(**(int **)(this->_padding_ + 0x130) + 0x34))
                ((float)piVar3[0xe] + pRVar2->key_scroll_object_move,
                 (float)piVar3[0xf] + pRVar2->key_scroll_object_move,0);
      uVar10 = 1;
    }
    goto LAB_0053e214;
  }
  if (this->_padding_ == 0) goto LAB_0053e214;
  if (pbKeyState[0x25] < 2) {
    if (1 < pbKeyState[0x27]) {
      sVar5 = 1;
    }
  }
  else {
    sVar5 = -1;
  }
  if (pbKeyState[0x26] < 2) {
    if (1 < pbKeyState[0x28]) {
      sVar6 = 1;
    }
  }
  else {
    sVar6 = -1;
  }
  if ((sVar5 == 0) && (sVar6 == 0)) goto LAB_0053e214;
  uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x153);
  if (this->key_scrolling == 0) {
    fVar11 = (float10)_DAT_00577900;
    this->key_scrolling = 1;
  }
  else {
    iVar7 = __ftol();
    fVar1 = _DAT_00577904;
    if (extraout_ST0 - (float10)iVar7 < (float10)_DAT_00577904) {
      fVar1 = _DAT_00577908;
    }
    fVar11 = (float10)fVar1 + (float10)iVar7;
  }
  if ((float10)pRVar2->key_scroll_max_dist < fVar11) {
    fVar11 = (float10)pRVar2->key_scroll_max_dist;
  }
  if (fVar11 <= (float10)_DAT_00577908) goto LAB_0053e214;
  fVar1 = (float)(fVar11 + fVar11);
  if (sVar5 == -1) {
    pRVar9 = (RGE_Player *)this->_padding_;
    fVar12 = (float10)pRVar9->view_y - fVar11;
    fVar11 = (float10)pRVar9->view_x - fVar11;
LAB_0053e19b:
    RGE_Player::set_view_loc(pRVar9,(float)fVar11,(float)fVar12);
  }
  else if (sVar5 == 1) {
    pRVar9 = (RGE_Player *)this->_padding_;
    fVar12 = (float10)pRVar9->view_y + fVar11;
    fVar11 = (float10)pRVar9->view_x + fVar11;
    goto LAB_0053e19b;
  }
  if (sVar6 == -1) {
    pRVar9 = (RGE_Player *)this->_padding_;
    fVar4 = pRVar9->view_y - fVar1;
    fVar1 = pRVar9->view_x + fVar1;
LAB_0053e1f7:
    RGE_Player::set_view_loc(pRVar9,fVar1,fVar4);
  }
  else if (sVar6 == 1) {
    pRVar9 = (RGE_Player *)this->_padding_;
    fVar4 = pRVar9->view_y + fVar1;
    fVar1 = pRVar9->view_x - fVar1;
    goto LAB_0053e1f7;
  }
  this->last_key_scroll_time = uVar8;
  uVar10 = 1;
LAB_0053e214:
  if ((sVar5 == 0) && (sVar6 == 0)) {
    this->key_scrolling = 0;
  }
  if (uVar10 != 0) {
    (**(code **)(this->_padding_ + 0x20))(1);
    if (this->map_view != (TPanel *)0x0) {
      (**(code **)(this->map_view->_padding_ + 0x20))(1);
    }
  }
  return uVar10;
}

// --------------------------------------------------

// Function: handle_mouse_up
// Address: 0053e280
// [HELPER] s_C__msdev_work_age1_x1_vw_main_cp: "C:\msdev\work\age1_x1\vw_main.cpp"
/* public: virtual long __thiscall RGE_Main_View::handle_mouse_up(unsigned char,long,long,int,int)
    */

long __thiscall
RGE_Main_View::handle_mouse_up
          (RGE_Main_View *this,uchar param_1,long param_2,long param_3,int param_4,int param_5)
{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x1ae);
  lVar2 = TPanel::handle_mouse_up((TPanel *)this,param_1,param_2,param_3,param_4,param_5);
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x1b0);
  RGE_Base_Game::add_to_timing(rge_base_game,0xd,uVar3 - uVar1);
  return lVar2;
}

// --------------------------------------------------

// Function: mouse_move_action
// Address: 0053e2f0
/* public: virtual long __thiscall RGE_Main_View::mouse_move_action(long,long,int,int) */

long __thiscall
RGE_Main_View::mouse_move_action
          (RGE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = rge_base_game->prog_mode;
  if ((((iVar1 != 4) && (iVar1 != 6)) && (iVar1 != 7)) && (iVar1 != 5)) {
    return 0;
  }
  iVar1 = rge_base_game->game_mode;
  if ((iVar1 == 1) || ((6 < iVar1 && (iVar1 < 9)))) {
    (**(code **)(this->_padding_ + 0x20))(1);
  }
  return 1;
}

// --------------------------------------------------

// Function: mouse_left_down_action
// Address: 0053e340
/* WARNING: Variable defined which should be unmapped: min_x */
/* public: virtual long __thiscall RGE_Main_View::mouse_left_down_action(long,long,int,int) */

long __thiscall
RGE_Main_View::mouse_left_down_action
          (RGE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  int *piVar1;
  RGE_Sprite *this_00;
  uchar uVar2;
  int iVar3;
  RGE_Player *pRVar4;
  int unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  short min_x;
  short min_y;
  short max_y;
  short max_x;
  tagPOINT point;
  RGE_Pick_Info pick_info;
  
  _min_x = unaff_EBX;
  iVar3 = RGE_Base_Game::get_paused(rge_base_game);
  if ((iVar3 == 0) &&
     ((((iVar3 = rge_base_game->prog_mode, iVar3 == 4 || (iVar3 == 6)) || (iVar3 == 7)) ||
      (iVar3 == 5)))) {
    iVar3 = rge_base_game->game_mode;
    color_log('L',0xba,1);
    switch(iVar3) {
    case 1:
      uVar2 = pick1(this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                    (RGE_Static_Object *)0x0,1);
      if (uVar2 == '3') {
        fixup_pick_info(this,(RGE_Pick_Info *)&pick_info.y);
        iVar3 = (int)rge_base_game->master_obj_id;
        if (iVar3 != -1) {
          piVar1 = *(int **)(*(int *)(this->_padding_ + 0x24) + iVar3 * 4);
          if (piVar1 == (int *)0x0) {
            if (iVar3 != -1) {
              piVar1 = *(int **)(*(int *)(**(int **)(this->_padding_ + 0x40) + 0x24) + iVar3 * 4);
              if (piVar1 != (int *)0x0) {
                (**(code **)(*piVar1 + 0x24))(&pick_info.y,&pick_info.scr_x,this->_padding_,0);
                (**(code **)(*(int *)**(undefined4 **)(this->_padding_ + 0x40) + 0xb0))
                          (iVar3,_max_y,point.x,0);
              }
            }
          }
          else {
            (**(code **)(*piVar1 + 0x24))(&pick_info.y,&pick_info.scr_x,this->_padding_,0);
            (**(code **)(*(int *)this->_padding_ + 0xb0))(iVar3,_max_y,point.x,0);
          }
        }
      }
      break;
    case 2:
    case 3:
    case 0x11:
      if (((RGE_Player *)this->_padding_)->selected_obj != (RGE_Static_Object *)0x0) {
        RGE_Player::unselect_object((RGE_Player *)this->_padding_);
        (**(code **)(this->_padding_ + 0x20))(1);
      }
    case 0x15:
      (**(code **)(this->_padding_ + 0xe8))(3,param_1,param_2,param_3,param_4);
      break;
    default:
      TPanel::capture_mouse((TPanel *)this);
      break;
    case 9:
    case 10:
    case 0x13:
      if (((RGE_Player *)this->_padding_)->selected_obj != (RGE_Static_Object *)0x0) {
        RGE_Player::unselect_object((RGE_Player *)this->_padding_);
        (**(code **)(this->_padding_ + 0x20))(1);
      }
      if (iVar3 == 0x13) {
        (**(code **)(rge_base_game->_padding_ + 0x10))(0x13,0);
      }
      (**(code **)(this->_padding_ + 0xe8))(9,param_1,param_2,param_3,param_4);
      break;
    case 0xf:
      uVar2 = pick1(this,')','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                    *(RGE_Static_Object **)(this->_padding_ + 0x130),1);
      if ((uVar2 == '4') && (*(short *)(*(int *)&(pick_info.tile)->last_drawn_shape + 0x14) != 0x22)
         ) {
        if (*(RGE_Active_Sprite_List **)(pick_info.tile + 1) == (RGE_Active_Sprite_List *)0x0) {
          this_00 = (RGE_Sprite *)((pick_info.tile)->objects).list;
          if (this_00 == (RGE_Sprite *)0x0) {
            uVar2 = '\x14';
          }
          else {
            uVar2 = RGE_Sprite::get_lowest_draw_level(this_00);
          }
        }
        else {
          uVar2 = RGE_Active_Sprite_List::get_lowest_draw_level
                            (*(RGE_Active_Sprite_List **)(pick_info.tile + 1));
        }
        pRVar4 = RGE_Base_Game::get_player(rge_base_game);
        this->save_player = pRVar4;
        iVar3 = ((pick_info.tile)->objects)._padding_;
        (**(code **)(rge_base_game->_padding_ + 0x14))
                  (CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(iVar3 + 0x4a)));
        rge_base_game->master_obj_id = (pick_info.object)->master_obj->id;
        this->_padding_ = (int)pick_info.object;
        (pick_info.object)->object_state = '\a';
        if (uVar2 == '\0') {
          (**(code **)(this->_padding_ + 0x20))(2);
        }
        (**(code **)(rge_base_game->_padding_ + 0x10))(8,1);
        if (((RGE_Static_Object *)this->_padding_)->sprite != (RGE_Sprite *)0x0) {
          RGE_Static_Object::get_frame
                    ((RGE_Static_Object *)this->_padding_,(short *)&stack0xffffffd0,
                     (short *)&stack0xffffffd2,(short *)&stack0xffffffd6,(short *)&stack0xffffffd4);
          _min_x = (int)pick_info.x._0_2_ - (int)(short)unaff_ESI;
          _max_y = (int)pick_info.x._2_2_ - (int)(short)((uint)unaff_ESI >> 0x10);
          if (*(char *)(*(int *)this->_padding_ + 0x479) == '\x01') {
            ClientToScreen(((int *)this->_padding_)[1],&min_x);
          }
        }
        (**(code **)(this->_padding_ + 0xe8))(9,param_1,param_2,unaff_retaddr,param_1);
      }
      break;
    case 0x12:
      uVar2 = pick1(this,')','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                    *(RGE_Static_Object **)(this->_padding_ + 0x130),1);
      if (uVar2 == '4') {
        RGE_Player::unselect_object((RGE_Player *)this->_padding_);
        RGE_Player::select_one_object
                  ((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.tile,1);
        iVar3 = this->_padding_;
        (**(code **)(iVar3 + 0x20))(1);
        if (((pick_info.tile)->objects).list != (RGE_Object_Node *)0x0) {
          RGE_Static_Object::get_frame
                    ((RGE_Static_Object *)pick_info.tile,&max_y,&max_x,(short *)((int)&point.x + 2),
                     (short *)&point);
          point.y = (int)(short)pick_info.object - (int)max_y;
          pick_info.x = (float)((int)pick_info.object._2_2_ - (int)max_x);
          if (*(char *)(*(int *)this->_padding_ + 0x479) == '\x01') {
            ClientToScreen(((int *)this->_padding_)[1],&point.y);
          }
          if (*(char *)(*(int *)this->_padding_ + 0x479) == '\x01') {
            ScreenToClient(((int *)this->_padding_)[1],&point.y);
          }
          (**(code **)(iVar3 + 0xe8))(4,point.y,pick_info.x,param_3,param_4);
        }
      }
    }
    color_log('L','_',1);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_move_action
// Address: 0053e7f0
/* public: virtual long __thiscall RGE_Main_View::mouse_left_move_action(long,long,int,int) */

long __thiscall
RGE_Main_View::mouse_left_move_action
          (RGE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  char cVar1;
  int iVar2;
  
  iVar2 = rge_base_game->prog_mode;
  if ((((iVar2 != 4) && (iVar2 != 6)) && (iVar2 != 7)) && (iVar2 != 5)) {
    return 0;
  }
  iVar2 = RGE_Base_Game::get_paused(rge_base_game);
  cVar1 = (char)this->_padding_;
  if (iVar2 == 0) {
    if (cVar1 != '\0') {
      (**(code **)(this->_padding_ + 0xec))(param_1,param_2);
      return 1;
    }
    switch(rge_base_game->game_mode) {
    case 0:
      TPanel::release_mouse((TPanel *)this);
      iVar2 = this->_padding_;
      (**(code **)(iVar2 + 0xe8))(2,this->_padding_,this->_padding_,param_3,param_4);
      (**(code **)(iVar2 + 0xec))(param_3,param_4);
      return 1;
    case 1:
    case 7:
    case 8:
      (**(code **)(this->_padding_ + 0x20))(1);
    }
    return 1;
  }
  if (cVar1 != '\0') {
    (**(code **)(this->_padding_ + 0xf0))();
    return 0;
  }
  TPanel::release_mouse((TPanel *)this);
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_up_action
// Address: 0053e910
/* WARNING: Variable defined which should be unmapped: pick_info */
/* public: virtual long __thiscall RGE_Main_View::mouse_left_up_action(long,long,int,int) */

long __thiscall
RGE_Main_View::mouse_left_up_action
          (RGE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  RGE_Player *pRVar1;
  RGE_Sprite *this_00;
  uchar uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  float unaff_EBX;
  RGE_Static_Object *pRVar6;
  RGE_Pick_Info pick_info;
  
  iVar4 = rge_base_game->prog_mode;
  if ((((iVar4 != 4) && (iVar4 != 6)) && (iVar4 != 7)) && (iVar4 != 5)) {
    return 0;
  }
  pick_info.x = unaff_EBX;
  color_log('L','\x16',1);
  if ((char)this->_padding_ != '\0') {
    iVar4 = this->_padding_;
    (**(code **)(iVar4 + 0xf0))();
    if (rge_base_game->game_mode == 0x15) {
      if ((param_3 == 0) && (param_4 == 0)) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
      (**(code **)(iVar4 + 0x10c))
                (this->_padding_,this->_padding_,this->_padding_,this->_padding_,uVar3);
    }
    if ((rge_base_game->game_mode == 8) &&
       ((**(code **)(iVar4 + 0xfc))(param_1,param_2,1), rge_base_game->sub_game_mode == 1)) {
      *(undefined1 *)(this->_padding_ + 0x48) = 2;
      this->_padding_ = 0;
      (**(code **)(rge_base_game->_padding_ + 0x10))(0xf,0);
      pRVar1 = this->save_player;
      if (pRVar1 != (RGE_Player *)0x0) {
        (**(code **)(rge_base_game->_padding_ + 0x14))
                  (CONCAT22((short)((uint)pRVar1 >> 0x10),pRVar1->id));
        this->save_player = (RGE_Player *)0x0;
      }
    }
    goto switchD_0053eb69_caseD_1;
  }
  TPanel::release_mouse((TPanel *)this);
  iVar4 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar4 != 0) {
    color_log('L','_',1);
    return 0;
  }
  iVar4 = rge_base_game->game_mode;
  if (((param_4 != 0) || (param_3 != 0)) && ((iVar4 != 7 && (iVar4 != 0x15)))) {
    uVar2 = pick1(this,')','\x02',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                  (RGE_Static_Object *)0x0,0);
    if (uVar2 == '4') {
      if ((pick_info.tile[2].field_0x6 & 1) == 0) {
        pRVar1 = (RGE_Player *)this->_padding_;
        if ((pRVar1->selected_obj != (RGE_Static_Object *)0x0) &&
           ((pRVar1->selected_obj->owner != pRVar1 ||
            (uVar2 = RGE_Player::get_select_level(pRVar1),
            uVar2 != *(uchar *)(*(int *)&(pick_info.tile)->last_drawn_shape + 0x8d))))) {
          RGE_Player::unselect_object((RGE_Player *)this->_padding_);
        }
        if (param_3 == 0) {
          RGE_Player::select_object
                    ((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.tile);
        }
        else {
          RGE_Player::select_one_object
                    ((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.tile,1);
        }
      }
      else {
        RGE_Player::unselect_one_object
                  ((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.tile);
      }
      (**(code **)(this->_padding_ + 0x20))(1);
    }
    if ((param_3 != 0) || (rge_base_game->prog_info->interface_style == 2))
    goto switchD_0053eb69_caseD_1;
  }
  switch(iVar4) {
  case 0:
  case 6:
    if (iVar4 == 6) {
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    }
    if (rge_base_game->prog_info->interface_style == 2) {
      if ((param_1 == this->mouse_last_x) && (param_2 == this->mouse_last_y)) {
        pRVar6 = *(RGE_Static_Object **)(this->_padding_ + 0x130);
      }
      else {
        pRVar6 = (RGE_Static_Object *)0x0;
      }
      uVar2 = pick1(this,')','\x02',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,pRVar6,0);
      this->mouse_last_x = -1;
      this->mouse_last_y = -1;
      if (uVar2 == '4') {
        pRVar1 = (RGE_Player *)this->_padding_;
        if ((pick_info.tile[2].field_0x6 & 1) == 0) {
          RGE_Player::unselect_object(pRVar1);
          RGE_Player::select_object
                    ((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.tile);
        }
        else {
          if (pRVar1->sel_count < 2) break;
          RGE_Player::unselect_object(pRVar1);
          RGE_Player::select_one_object
                    ((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.tile,1);
        }
        (**(code **)(this->_padding_ + 0x20))(1);
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        break;
      }
      RGE_Player::unselect_object((RGE_Player *)this->_padding_);
    }
    else {
      if ((param_1 == this->mouse_last_x) && (param_2 == this->mouse_last_y)) {
        pRVar6 = *(RGE_Static_Object **)(this->_padding_ + 0x130);
      }
      else {
        pRVar6 = (RGE_Static_Object *)0x0;
      }
      uVar2 = pick1(this,'*','\x01',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,pRVar6,1);
      param_3 = CONCAT31(param_3._1_3_,uVar2);
      if ((((uVar2 == '4') && (param_1 == this->mouse_last_x)) && (param_2 == this->mouse_last_y))
         && ((RGE_Static_Object *)pick_info.tile != ((RGE_Player *)this->_padding_)->selected_obj))
{
        RGE_Player::unselect_object((RGE_Player *)this->_padding_);
        (**(code **)(this->_padding_ + 0x20))(1);
      }
      this->mouse_last_x = -1;
      this->mouse_last_y = -1;
      if ((char)param_3 != '4') goto LAB_0053f0c7;
      if (((rge_base_game->prog_mode != 5) && (0 < *(short *)(this->_padding_ + 0x19c))) &&
         ((rge_base_game->prog_mode != 7 &&
          (iVar4 = (**(code **)(this->_padding_ + 0x100))(param_1,param_2,0,0xffffffff), iVar4 != 0)
          ))) {
        return 1;
      }
      if ((pick_info.tile[2].field_0x6 & 1) != 0) {
        if (((RGE_Player *)this->_padding_)->sel_count < 2) {
          return 1;
        }
        RGE_Player::unselect_object((RGE_Player *)this->_padding_);
        RGE_Player::select_one_object
                  ((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.tile,1);
        (**(code **)(this->_padding_ + 0x20))(1);
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        return 1;
      }
      if ((((pick_info.tile)->objects)._padding_ == this->_padding_) ||
         (*(short *)(this->_padding_ + 0x19c) == 0)) {
        if (1 < *(byte *)(*(int *)&(pick_info.tile)->last_drawn_shape + 0x8d)) {
          if (*(char *)(this->_padding_ + 0x8db8) == '\0') {
            iVar4 = __ftol();
            iVar5 = __ftol();
            uVar2 = RGE_Visible_Map::get_visible
                              (*(RGE_Visible_Map **)(this->_padding_ + 0x38),iVar5,iVar4);
            if (uVar2 != '\x0f') break;
          }
          RGE_Player::unselect_object((RGE_Player *)this->_padding_);
          RGE_Player::select_object
                    ((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.tile);
          (**(code **)(this->_padding_ + 0x20))(1);
          this->mouse_last_x = param_1;
          this->mouse_last_y = param_2;
        }
        break;
      }
      if (((rge_base_game->prog_mode != 5) && (rge_base_game->prog_mode != 7)) &&
         (iVar4 = (**(code **)(this->_padding_ + 0x100))(param_1,param_2,1,0xffffffff), iVar4 != 0))
      break;
      if (1 < *(byte *)(*(int *)&(pick_info.tile)->last_drawn_shape + 0x8d)) {
        if (*(char *)(this->_padding_ + 0x8db8) == '\0') {
          iVar4 = __ftol();
          iVar5 = __ftol();
          uVar2 = RGE_Visible_Map::get_visible
                            (*(RGE_Visible_Map **)(this->_padding_ + 0x38),iVar5,iVar4);
          if (uVar2 != '\x0f') goto LAB_0053f0c7;
        }
        RGE_Player::unselect_object((RGE_Player *)this->_padding_);
        RGE_Player::select_object((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.tile)
        ;
        (**(code **)(this->_padding_ + 0x20))(1);
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        break;
      }
LAB_0053f0c7:
      if ((((char)param_3 != '3') || (rge_base_game->prog_mode == 5)) ||
         (rge_base_game->prog_mode == 7)) break;
      if (param_4 == 0) {
        (**(code **)(this->_padding_ + 0x100))(param_1,param_2,1,0xffffffff);
        break;
      }
      uVar2 = RGE_Player::get_selected_objects_to_command
                        ((RGE_Player *)this->_padding_,(RGE_Static_Object ***)&param_4,
                         (short *)&param_3,-1,-1,-1,-1);
      if ((uVar2 == '\0') || (free(param_4), allow_user_commands == 0)) break;
      fixup_pick_info(this,(RGE_Pick_Info *)&pick_info.y);
      (**(code **)(*(int *)this->_padding_ + 0xd8))(pick_info.y,pick_info._8_4_,0x3f800000);
      reset_display_object_selection(this,2);
      RGE_View::add_overlay_sprite
                ((RGE_View *)this,rge_base_game->shapes[1],0,this->_padding_ + param_1,
                 this->_padding_ + param_2,0,0xf,(uchar *)0x0,1,0xfa);
    }
    iVar4 = this->_padding_;
    uVar3 = 1;
    goto LAB_0053f1ba;
  case 4:
    (**(code **)(this->_padding_ + 0x104))(param_1,param_2);
    break;
  case 5:
    (**(code **)(this->_padding_ + 0x108))(param_1,param_2);
    break;
  case 7:
    if ((param_3 == 0) && (param_4 == 0)) {
      (**(code **)(this->_padding_ + 0xfc))(param_1,param_2,1);
    }
    else {
      (**(code **)(this->_padding_ + 0xfc))(param_1,param_2,0);
    }
    break;
  case 8:
    (**(code **)(this->_padding_ + 0xfc))(param_1,param_2,1);
    if (rge_base_game->sub_game_mode == 1) {
      *(undefined1 *)(this->_padding_ + 0x48) = 2;
      this->_padding_ = 0;
      (**(code **)(rge_base_game->_padding_ + 0x10))(0xf,0);
      pRVar1 = this->save_player;
      if (pRVar1 != (RGE_Player *)0x0) {
        (**(code **)(rge_base_game->_padding_ + 0x14))
                  (CONCAT22((short)((uint)pRVar1 >> 0x10),pRVar1->id));
        this->save_player = (RGE_Player *)0x0;
      }
    }
    break;
  case 0xe:
    uVar2 = pick1(this,')','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                  *(RGE_Static_Object **)(this->_padding_ + 0x130),1);
    if (uVar2 != '4') break;
    if (*(RGE_Active_Sprite_List **)(pick_info.tile + 1) == (RGE_Active_Sprite_List *)0x0) {
      this_00 = (RGE_Sprite *)((pick_info.tile)->objects).list;
      if (this_00 == (RGE_Sprite *)0x0) {
        uVar2 = '\x14';
      }
      else {
        uVar2 = RGE_Sprite::get_lowest_draw_level(this_00);
      }
    }
    else {
      uVar2 = RGE_Active_Sprite_List::get_lowest_draw_level
                        (*(RGE_Active_Sprite_List **)(pick_info.tile + 1));
    }
    if (rge_base_game->prog_mode == 7) {
      if (pick_info.tile != (RGE_Tile *)0x0) {
        (*(code *)**(undefined4 **)pick_info.tile)(1);
      }
    }
    else {
      (**(code **)(*(int *)pick_info.tile + 0x68))();
    }
    if (uVar2 != '\0') break;
    iVar4 = this->_padding_;
    uVar3 = 2;
LAB_0053f1ba:
    (**(code **)(iVar4 + 0x20))(uVar3);
    break;
  case 0x10:
    uVar2 = pick1(this,')','\x01',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                  *(RGE_Static_Object **)(this->_padding_ + 0x130),1);
    if (uVar2 == '4') {
      if ((int *)this->_padding_ != (int *)0x0) {
        (**(code **)(*(int *)this->_padding_ + 0xb4))(this,0x10,pick_info.tile,0);
        RGE_Player::select_one_object
                  ((RGE_Player *)this->_padding_,(RGE_Static_Object *)pick_info.x,1);
        (**(code **)(this->_padding_ + 0x20))(1);
      }
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    }
    break;
  case 0x14:
    uVar2 = pick1(this,')','\x02',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                  *(RGE_Static_Object **)(this->_padding_ + 0x130),1);
    if (uVar2 == '4') {
      (**(code **)(*(int *)pick_info.tile + 0x78))(1);
    }
  }
switchD_0053eb69_caseD_1:
  color_log('L','_',1);
  return 1;
}

// --------------------------------------------------

// Function: mouse_right_down_action
// Address: 0053f220
/* public: virtual long __thiscall RGE_Main_View::mouse_right_down_action(long,long,int,int) */

long __thiscall
RGE_Main_View::mouse_right_down_action
          (RGE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if ((iVar1 == 0) &&
     ((((iVar1 = rge_base_game->prog_mode, iVar1 == 4 || (iVar1 == 6)) || (iVar1 == 7)) ||
      (iVar1 == 5)))) {
    color_log('L','$',1);
    if (rge_base_game->game_mode == 0x13) {
      if (((RGE_Player *)this->_padding_)->selected_obj != (RGE_Static_Object *)0x0) {
        RGE_Player::unselect_object((RGE_Player *)this->_padding_);
        (**(code **)(this->_padding_ + 0x20))(1);
      }
      (**(code **)(rge_base_game->_padding_ + 0x10))(0x13,1);
      (**(code **)(this->_padding_ + 0xe8))(9,unaff_ESI,unaff_retaddr,param_1,param_2);
    }
    else {
      TPanel::capture_mouse((TPanel *)this);
    }
    color_log('L','_',1);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_move_action
// Address: 0053f2f0
/* public: virtual long __thiscall RGE_Main_View::mouse_right_move_action(long,long,int,int) */

long __thiscall
RGE_Main_View::mouse_right_move_action
          (RGE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  char cVar1;
  int iVar2;
  
  iVar2 = rge_base_game->prog_mode;
  if ((((iVar2 == 4) || (iVar2 == 6)) || (iVar2 == 7)) || (iVar2 == 5)) {
    iVar2 = RGE_Base_Game::get_paused(rge_base_game);
    cVar1 = (char)this->_padding_;
    if (iVar2 != 0) {
      if (cVar1 != '\0') {
        (**(code **)(this->_padding_ + 0xf0))();
        return 0;
      }
      TPanel::release_mouse((TPanel *)this);
      return 0;
    }
    if (cVar1 != '\0') {
      (**(code **)(this->_padding_ + 0xec))(param_1,param_2);
      return 1;
    }
    if (*(short *)(this->_padding_ + 0x19c) == 0) {
      TPanel::release_mouse((TPanel *)this);
      iVar2 = this->_padding_;
      (**(code **)(iVar2 + 0xe8))(1,this->_padding_,this->_padding_,param_3,param_4);
      (**(code **)(iVar2 + 0xec))(param_3,param_4);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_up_action
// Address: 0053f3d0
/* WARNING: Variable defined which should be unmapped: list */
/* public: virtual long __thiscall RGE_Main_View::mouse_right_up_action(long,long,int,int) */

long __thiscall
RGE_Main_View::mouse_right_up_action
          (RGE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  RGE_Static_Object **list;
  RGE_Pick_Info pick_info;
  
  iVar3 = rge_base_game->prog_mode;
  if ((((iVar3 != 4) && (iVar3 != 6)) && (iVar3 != 7)) && (iVar3 != 5)) {
    return 0;
  }
  color_log('L','2',1);
  if ((char)this->_padding_ == '\0') {
    TPanel::release_mouse((TPanel *)this);
    if (rge_base_game->game_mode == 0x14) {
      uVar2 = pick1(this,')','\x02',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                    *(RGE_Static_Object **)(this->_padding_ + 0x130),1);
      if (uVar2 == '4') {
        (**(code **)(*(int *)pick_info.tile + 0x78))(0xffffffff);
      }
    }
    else {
      iVar3 = RGE_Base_Game::get_paused(rge_base_game);
      if ((iVar3 != 0) || ((cVar1 = (char)this->_padding_, cVar1 != '\x01' && (cVar1 != '\x02')))) {
        color_log('L','_',1);
        return 0;
      }
      iVar3 = rge_base_game->prog_mode;
      if (rge_base_game->prog_info->interface_style == 2) {
        if ((iVar3 == 5) || (iVar3 == 7)) goto LAB_0053f63b;
        if (rge_base_game->game_mode != 0) {
          if (rge_base_game->game_mode == 0x15) {
            RGE_View::set_selection_area((RGE_View *)this,-1,-1,-1,-1);
            (**(code **)(this->_padding_ + 0x20))(1);
          }
          (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
          goto LAB_0053f63b;
        }
        if (param_4 == 0) {
          (**(code **)(this->_padding_ + 0x100))(param_1,param_2,1,0xffffffff);
          goto LAB_0053f63b;
        }
        uVar2 = RGE_Player::get_selected_objects_to_command
                          ((RGE_Player *)this->_padding_,(RGE_Static_Object ***)&pick_info,
                           (short *)&param_4,-1,-1,-1,-1);
        if (uVar2 == '\0') goto LAB_0053f63b;
        free(pick_info.x);
        if (allow_user_commands == 0) goto LAB_0053f63b;
        uVar2 = pick1(this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                      (RGE_Static_Object *)0x0,1);
        if (uVar2 != '3') goto LAB_0053f63b;
        fixup_pick_info(this,(RGE_Pick_Info *)&pick_info.y);
        (**(code **)(*(int *)this->_padding_ + 0xd8))(pick_info.y,pick_info._8_4_,0x3f800000);
        reset_display_object_selection(this,2);
        RGE_View::add_overlay_sprite
                  ((RGE_View *)this,rge_base_game->shapes[1],0,this->_padding_ + param_1,
                   this->_padding_ + param_2,0,0xf,(uchar *)0x0,1,0xfa);
      }
      else {
        if (iVar3 == 7) goto LAB_0053f63b;
        if (rge_base_game->game_mode != 0) {
          (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
          goto LAB_0053f63b;
        }
        RGE_Player::unselect_object((RGE_Player *)this->_padding_);
      }
      (**(code **)(this->_padding_ + 0x20))(1);
    }
  }
  else {
    (**(code **)(this->_padding_ + 0xf0))();
  }
LAB_0053f63b:
  color_log('L','_',1);
  return 1;
}

// --------------------------------------------------

// Function: start_scroll_view
// Address: 0053f660
/* public: virtual int __thiscall RGE_Main_View::start_scroll_view(unsigned char,long,long,int,int)
    */

int __thiscall
RGE_Main_View::start_scroll_view
          (RGE_Main_View *this,uchar param_1,long param_2,long param_3,int param_4,int param_5)
{
  int iVar1;
  
  iVar1 = RGE_View::start_scroll_view((RGE_View *)this,param_1,param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    if (this->map_view != (TPanel *)0x0) {
      (**(code **)(this->map_view->_padding_ + 0x20))(1);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: handle_scroll_view
// Address: 0053f6b0
/* public: virtual int __thiscall RGE_Main_View::handle_scroll_view(long,long) */

int __thiscall RGE_Main_View::handle_scroll_view(RGE_Main_View *this,long param_1,long param_2)
{
  int iVar1;
  
  iVar1 = RGE_View::handle_scroll_view((RGE_View *)this,param_1,param_2);
  if (iVar1 != 0) {
    if (this->map_view != (TPanel *)0x0) {
      (**(code **)(this->map_view->_padding_ + 0x20))(1);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: draw
// Address: 0053f6f0
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_vw_main_cp: "C:\msdev\work\age1_x1\vw_main.cpp"
/* public: virtual void __thiscall RGE_Main_View::draw(void) */

void __thiscall RGE_Main_View::draw(RGE_Main_View *this)
{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x522);
  uVar3 = RGE_Base_Game::get_accum_time(rge_base_game,0xb);
  if ((this->_padding_ == 0) || (this->_padding_ == 0)) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,
                     (uint)*(byte *)((int)&this->_padding_ + 3));
    (**(code **)(iVar1 + 0x2c))();
  }
  else {
    if (do_draw_log != 0) {
      write_draw_log2(s_<vs>);
    }
    color_log('L','L',1);
    RGE_View::draw((RGE_View *)this);
    color_log('L','_',1);
    if (do_draw_log != 0) {
      write_draw_log2(s_<vf>_);
    }
  }
  uVar4 = RGE_Base_Game::get_accum_time(rge_base_game,0xb);
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x542);
  RGE_Base_Game::add_to_timing(rge_base_game,6,(uVar5 - uVar2) - (uVar4 - uVar3));
  RGE_Base_Game::increment_view_update_count(rge_base_game);
  RGE_Base_Game::add_to_timing(rge_base_game,0xc,uVar4 - uVar3);
  return;
}

// --------------------------------------------------

// Function: draw_multi_object_outline
// Address: 0053f800
/* public: virtual void __thiscall RGE_Main_View::draw_multi_object_outline(void) */

void __thiscall RGE_Main_View::draw_multi_object_outline(RGE_Main_View *this)
{
  return;
}

// --------------------------------------------------

// Function: command_place_object
// Address: 0053f810
/* WARNING: Variable defined which should be unmapped: pick_info */
/* public: virtual int __thiscall RGE_Main_View::command_place_object(long,long,int) */

int __thiscall
RGE_Main_View::command_place_object(RGE_Main_View *this,long param_1,long param_2,int param_3)
{
  RGE_Master_Static_Object *pRVar1;
  int iVar2;
  uchar uVar3;
  char cVar4;
  RGE_Player *pRVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  RGE_Pick_Info pick_info;
  
  if ((allow_user_commands != 0) &&
     (uVar3 = pick1(this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                    (RGE_Static_Object *)0x0,1), uVar3 == '3')) {
    fixup_pick_info(this,(RGE_Pick_Info *)&pick_info.y);
    iVar8 = (int)rge_base_game->master_obj_id;
    if ((iVar8 != -1) &&
       (pRVar5 = RGE_Base_Game::get_player(rge_base_game),
       pRVar5->master_objects[iVar8] != (RGE_Master_Static_Object *)0x0)) {
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      pRVar1 = pRVar5->master_objects[iVar8];
      iVar2 = pRVar1->_padding_;
      (**(code **)(iVar2 + 0x24))
                (&pick_info.y,&pick_info.scr_x,this->_padding_,rge_base_game->sub_game_mode != 3);
      uVar7 = (uint)pRVar1->elevation_flag;
      uVar14 = 1;
      iVar13 = 1;
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 1;
      uVar9 = 0;
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      cVar4 = (**(code **)(iVar2 + 0x20))
                        (pRVar5,unaff_EDI,unaff_ESI,uVar9,uVar10,uVar7,uVar11,uVar12,iVar13,uVar14);
      if (cVar4 == '\0') {
        if (rge_base_game->game_mode == 1) {
          pRVar5 = RGE_Base_Game::get_player(rge_base_game);
          cVar4 = (**(code **)(pRVar5->_padding_ + 0xb0))(iVar8,uVar10,uVar7,0);
          if (cVar4 != '\0') {
            if (iVar13 == 0) {
              return 1;
            }
            (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
            return 1;
          }
        }
        else if (rge_base_game->game_mode == 8) {
          if (rge_base_game->sub_game_mode == 1) {
            piVar6 = (int *)this->_padding_;
            (**(code **)(*piVar6 + 0x34))(uVar10,uVar7,0);
          }
          else {
            pRVar5 = RGE_Base_Game::get_player(rge_base_game);
            piVar6 = (int *)(**(code **)(pRVar5->_padding_ + 0x94))(iVar8,uVar10,uVar7,0,1);
          }
          if (piVar6 != (int *)0x0) {
            if ((RGE_Active_Sprite_List *)piVar6[6] == (RGE_Active_Sprite_List *)0x0) {
              if ((RGE_Sprite *)piVar6[4] == (RGE_Sprite *)0x0) {
                uVar3 = '\x14';
              }
              else {
                uVar3 = RGE_Sprite::get_lowest_draw_level((RGE_Sprite *)piVar6[4]);
              }
            }
            else {
              uVar3 = RGE_Active_Sprite_List::get_lowest_draw_level
                                ((RGE_Active_Sprite_List *)piVar6[6]);
            }
            if (uVar3 != '\0') {
              (**(code **)(this->_padding_ + 0x20))(1);
              return 1;
            }
            (**(code **)(this->_padding_ + 0x20))(2);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: command_make_do
// Address: 0053fa10
/* WARNING: Variable defined which should be unmapped: list_num */
/* public: virtual int __thiscall RGE_Main_View::command_make_do(long,long,int,short) */

int __thiscall
RGE_Main_View::command_make_do
          (RGE_Main_View *this,long param_1,long param_2,int param_3,short param_4)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  uint uVar3;
  short list_num;
  RGE_Static_Object **list;
  int attacking;
  RGE_Pick_Info pick_info;
  
  if (allow_user_commands != 0) {
    uVar1 = RGE_Player::get_selected_objects_to_command
                      ((RGE_Player *)this->_padding_,(RGE_Static_Object ***)&attacking,
                       (short *)((int)&list + 2),-1,-1,-1,-1);
    if (uVar1 != '\0') {
      free(attacking);
      color_log('L',0xba,2);
      pRVar2 = pick_best_target(this,param_1,param_2,(int *)&pick_info,param_4);
      if (pRVar2 != (RGE_Static_Object *)0x0) {
        uVar3 = (**(code **)(*(int *)this->_padding_ + 0xa8))
                          (pRVar2,pRVar2->world_x,pRVar2->world_y);
        if ((uVar3 & 0xff) != 0) {
          RGE_View::display_object_selection((RGE_View *)this,pRVar2->id,0x5dc,2,2);
        }
        RGE_View::reset_overlay_sprites((RGE_View *)this);
        (**(code **)(this->_padding_ + 0x20))(1);
        color_log('L','_',2);
        return uVar3 & 0xff;
      }
      if (param_3 != 0) {
        uVar1 = pick1(this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                      (RGE_Static_Object *)0x0,1);
        if (uVar1 == '3') {
          fixup_pick_info(this,(RGE_Pick_Info *)&pick_info.y);
          uVar3 = (**(code **)(*(int *)this->_padding_ + 0xa0))(0,pick_info.y,pick_info._8_4_);
          if ((uVar3 & 0xff) != 0) {
            reset_display_object_selection(this,2);
            RGE_View::add_overlay_sprite
                      ((RGE_View *)this,rge_base_game->shapes[2],0,this->_padding_ + param_1,
                       this->_padding_ + param_2,0,0xf,(uchar *)0x0,2,0x5a);
            (**(code **)(this->_padding_ + 0x20))(1);
          }
          color_log('L','_',2);
          return uVar3 & 0xff;
        }
      }
      RGE_View::reset_overlay_sprites((RGE_View *)this);
      (**(code **)(this->_padding_ + 0x20))(1);
      color_log('L','_',2);
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: pick1
// Address: 0053fbd0
/* WARNING: Variable defined which should be unmapped: target_count */
/* public: unsigned char __thiscall RGE_Main_View::pick1(unsigned char,unsigned
   char,long,long,struct RGE_Pick_Info *,class RGE_Static_Object *,int) */

uchar __thiscall
RGE_Main_View::pick1
          (RGE_Main_View *this,uchar param_1,uchar param_2,long param_3,long param_4,
          RGE_Pick_Info *param_5,RGE_Static_Object *param_6,int param_7)
{
  RGE_Static_Object *pRVar1;
  bool bVar2;
  uchar uVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  RGE_Pick_Obj_Info **ppRVar8;
  int iVar9;
  int iVar10;
  int target_count;
  int found_last;
  
  if (param_1 != ')') {
    if ((param_1 == '*') &&
       (uVar3 = pick1(this,')',param_2,param_3,param_4,param_5,param_6,1), uVar3 == '4')) {
      return '4';
    }
    uVar3 = RGE_View::pick((RGE_View *)this,'(',param_2,param_3,param_4,param_5,param_6);
    return uVar3;
  }
  param_5->x = 0.0;
  param_5->y = 0.0;
  param_5->scr_x = 0;
  param_5->scr_y = 0;
  param_5->object = (RGE_Static_Object *)0x0;
  param_5->tile = (RGE_Tile *)0x0;
  if (param_2 == '\0') {
    iVar10 = 0x28;
    iVar9 = 0;
  }
  else {
    iVar10 = 0x14;
    iVar9 = 10;
  }
  iVar9 = RGE_View::pick_objects((RGE_View *)this,param_3,param_4,iVar9,iVar10,0xf,4,1);
  if (iVar9 == 0) {
    return '2';
  }
  if (param_6 == (RGE_Static_Object *)0x0) {
    sVar6 = 0;
    _param_1 = (RGE_Static_Object *)0x0;
    param_6 = (RGE_Static_Object *)0x0;
    param_6._0_2_ = 0;
    param_3 = 0;
    pRVar4 = (RGE_Static_Object *)0x0;
    if (0 < iVar9) {
      ppRVar8 = &Picked_Objects;
      param_4 = iVar9;
      do {
        if ((((-1 < (int)*ppRVar8) &&
             (pRVar4 = *(RGE_Static_Object **)(*(int *)(this->_padding_ + 0x88) + (int)*ppRVar8 * 4)
             , pRVar4 != (RGE_Static_Object *)0x0)) && (pRVar4->object_state < 7)) &&
           (param_2 <= pRVar4->master_obj->select_level)) {
          if (((param_7 == 0) && (*(char *)(this->_padding_ + 0x8db8) == '\0')) &&
             (iVar9 = (**(code **)(this->_padding_ + 0xe0))(pRVar4), iVar9 == 0)) {
            iVar9 = __ftol();
            iVar10 = __ftol();
            uVar3 = RGE_Visible_Map::get_visible
                              (*(RGE_Visible_Map **)(this->_padding_ + 0x38),iVar10,iVar9);
            if (uVar3 != '\x0f') goto LAB_0053fd33;
          }
          iVar9 = (**(code **)(this->_padding_ + 0xe4))(pRVar4,(int)*(short *)(ppRVar8 + 1));
          if (param_3 < iVar9) {
            sVar6 = (short)this->_padding_ + *(short *)(ppRVar8 + 2);
            param_6 = (RGE_Static_Object *)
                      (uint)(ushort)((short)this->_padding_ + *(short *)((int)ppRVar8 + 10));
            _param_1 = pRVar4;
            param_3 = iVar9;
          }
        }
LAB_0053fd33:
        ppRVar8 = ppRVar8 + 3;
        param_4 = param_4 + -1;
        pRVar4 = _param_1;
      } while (param_4 != 0);
    }
    if (pRVar4 != (RGE_Static_Object *)0x0) {
      param_5->object = pRVar4;
      param_5->scr_x = sVar6;
      param_5->scr_y = (short)param_6;
      param_5->x = pRVar4->world_x;
      param_5->y = pRVar4->world_y;
      return '4';
    }
  }
  else {
    bVar2 = false;
    _param_1 = (RGE_Static_Object *)0x0;
    param_3 = 0;
    if (iVar9 < 1) {
      sVar6 = (short)param_6;
      sVar7 = 0;
    }
    else {
      sVar7 = 0;
      param_4 = (long)&Picked_Objects;
      pRVar4 = param_6;
      do {
        if ((((-1 < *(int *)param_4) &&
             (pRVar1 = *(RGE_Static_Object **)
                        (*(int *)(this->_padding_ + 0x88) + *(int *)param_4 * 4),
             pRVar1 != (RGE_Static_Object *)0x0)) && (pRVar1->object_state < 7)) &&
           ((param_2 <= pRVar1->master_obj->select_level &&
            (iVar10 = (**(code **)(this->_padding_ + 0xe4))(pRVar1,(int)*(short *)(param_4 + 4)),
            0 < iVar10)))) {
          if ((param_7 == 0) &&
             ((*(char *)(this->_padding_ + 0x8db8) == '\0' &&
              (iVar10 = (**(code **)(this->_padding_ + 0xe0))(pRVar1), iVar10 == 0)))) {
            iVar10 = __ftol();
            iVar5 = __ftol();
            uVar3 = RGE_Visible_Map::get_visible
                              (*(RGE_Visible_Map **)(this->_padding_ + 0x38),iVar5,iVar10);
            if (uVar3 != '\x0f') goto LAB_0053fe82;
          }
          if (pRVar1 == param_6) {
            bVar2 = true;
          }
          else {
            if (bVar2) {
              sVar7 = (&DAT_0087d4a8)[param_3 * 6] + (short)this->_padding_;
              sVar6 = (&DAT_0087d4aa)[param_3 * 6] + (short)this->_padding_;
              _param_1 = pRVar1;
              break;
            }
            if (_param_1 == (RGE_Static_Object *)0x0) {
              sVar7 = (short)this->_padding_ + *(short *)(param_4 + 8);
              pRVar4 = (RGE_Static_Object *)
                       (uint)(ushort)((short)this->_padding_ + *(short *)(param_4 + 10));
              _param_1 = pRVar1;
            }
          }
        }
LAB_0053fe82:
        sVar6 = (short)pRVar4;
        param_3 = param_3 + 1;
        param_4 = param_4 + 0xc;
      } while (param_3 < iVar9);
    }
    if ((bVar2) && (_param_1 == (RGE_Static_Object *)0x0)) {
      _param_1 = param_6;
      sVar7 = (&DAT_0087d4a8)[param_3 * 6] + (short)this->_padding_;
      sVar6 = (&DAT_0087d4aa)[param_3 * 6] + (short)this->_padding_;
    }
    if (_param_1 != (RGE_Static_Object *)0x0) {
      param_5->object = _param_1;
      param_5->scr_x = sVar7;
      param_5->scr_y = sVar6;
      param_5->x = _param_1->world_x;
      param_5->y = _param_1->world_y;
      return '4';
    }
  }
  return '2';
}

// --------------------------------------------------

// Function: pick_objects1
// Address: 0053ffb0
/* WARNING: Variable defined which should be unmapped: pick_info */
/* public: int __thiscall RGE_Main_View::pick_objects1(long,long,class RGE_Static_Object * *,int) */

int __thiscall
RGE_Main_View::pick_objects1
          (RGE_Main_View *this,long param_1,long param_2,RGE_Static_Object **param_3,int param_4)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  RGE_Static_Object **ppRVar4;
  RGE_Pick_Info pick_info;
  
  iVar3 = 0;
  pRVar2 = (RGE_Static_Object *)0x0;
  ppRVar4 = param_3;
  while( true ) {
    if (iVar3 == param_4) {
      return iVar3;
    }
    uVar1 = RGE_View::pick((RGE_View *)this,')','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                           pRVar2);
    if (uVar1 != '4') break;
    if ((0 < iVar3) && ((RGE_Static_Object *)pick_info.tile == *param_3)) {
      return iVar3;
    }
    *ppRVar4 = (RGE_Static_Object *)pick_info.tile;
    iVar3 = iVar3 + 1;
    ppRVar4 = ppRVar4 + 1;
    pRVar2 = (RGE_Static_Object *)pick_info.tile;
  }
  return iVar3;
}

// --------------------------------------------------

// Function: pick_best_target
// Address: 00540010
/* public: class RGE_Static_Object * __thiscall RGE_Main_View::pick_best_target(long,long,int
   *,short) */

RGE_Static_Object * __thiscall
RGE_Main_View::pick_best_target
          (RGE_Main_View *this,long param_1,long param_2,int *param_3,short param_4)
{
  int iVar1;
  uchar uVar2;
  RGE_Master_Action_Object *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  RGE_Static_Object *pRVar8;
  uint uVar9;
  int *piVar10;
  RGE_Pick_Obj_Info **ppRVar11;
  short *psStack_224;
  short selected_count;
  short local_21e;
  RGE_Static_Object **selected_objects;
  int i;
  int j;
  int target_count;
  RGE_Master_Action_Object *master_obj;
  int local_208;
  int valid_target_count [64];
  int attacking [64];
  
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  selected_objects = (RGE_Static_Object **)this;
  pRVar3 = (RGE_Master_Action_Object *)
           RGE_View::pick_objects((RGE_View *)this,param_1,param_2,10,0x14,0xf,4,1);
  if (pRVar3 == (RGE_Master_Action_Object *)0x0) {
    return (RGE_Static_Object *)0x0;
  }
  master_obj = pRVar3;
  uVar2 = RGE_Player::get_selected_objects_to_command
                    ((RGE_Player *)this->_padding_,(RGE_Static_Object ***)&i,&local_21e,-1,-1,-1,-1)
  ;
  if (uVar2 == '\0') {
    return (RGE_Static_Object *)0x0;
  }
  if (0 < (int)pRVar3) {
    piVar10 = attacking;
    for (uVar9 = (uint)pRVar3 & 0x3fffffff; piVar10 = piVar10 + 1, uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar10 = 0;
    }
    piVar10 = valid_target_count;
    for (uVar9 = (uint)pRVar3 & 0x3fffffff; piVar10 = piVar10 + 1, uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar10 = 0;
    }
  }
  j = 0;
  if (0 < local_21e) {
    do {
      target_count = 0;
      local_208 = *(int *)(*(int *)(i + j * 4) + 8);
      if (0 < (int)pRVar3) {
        psStack_224 = &DAT_0087d4a4;
        do {
          iVar6 = local_208;
          if (((-1 < *(int *)(psStack_224 + -2)) &&
              (iVar5 = *(int *)(*(int *)(this->_padding_ + 0x88) + *(int *)(psStack_224 + -2) * 4),
              iVar5 != 0)) && (*(byte *)(iVar5 + 0x48) < 7)) {
            iVar4 = (**(code **)(**(int **)(local_208 + 0xd8) + 4))
                              (*(undefined4 *)(i + j * 4),iVar5,0,0,0);
            if (iVar4 != 0) {
              if ((param_4 != -1) && (*(short *)(iVar4 + 6) != param_4)) {
                iVar4 = 0;
              }
              if (iVar4 != 0) {
                valid_target_count[0] = target_count * 4;
                iVar5 = (**(code **)(this->_padding_ + 0xe4))(iVar5,(int)*psStack_224);
                pRVar3 = master_obj;
                iVar6 = **(int **)(iVar6 + 0xd8);
                *(int *)((int)&local_208 + (int)master_obj) =
                     *(int *)((int)&local_208 + (int)master_obj) + iVar5;
                iVar6 = (**(code **)(iVar6 + 8))(iVar4);
joined_r0x005401ac:
                if (iVar6 != 0) {
                  *(undefined4 *)((int)(attacking + 1) + (int)pRVar3) = 1;
                }
                goto LAB_005402a9;
              }
            }
            if (*(char *)(iVar6 + 0xec) != '\0') {
              iVar6 = 0;
              pRVar8 = selected_objects[0x40];
              if (0 < *(short *)((int)&pRVar8->inside_obj + 2)) {
                do {
                  iVar4 = (&pRVar8->objects->_padding_)[iVar6];
                  if (((iVar4 != 0) && (*(short *)(iVar4 + 0x14) == *(short *)(local_208 + 0x14)))
                     && ((*(char *)(iVar4 + 4) == *(char *)(local_208 + 4) &&
                         ((*(char *)(iVar4 + 0xec) == *(char *)(local_208 + 0xec) &&
                          (iVar7 = (**(code **)(**(int **)(iVar4 + 0xd8) + 4))
                                             (*(undefined4 *)(i + j * 4),iVar5,0,0,0),
                          iVar1 = target_count, iVar7 != 0)))))) {
                    if ((param_4 != -1) && (*(short *)(iVar7 + 6) != param_4)) {
                      iVar7 = 0;
                    }
                    if (iVar7 != 0) {
                      pRVar3 = (RGE_Master_Action_Object *)(target_count * 4);
                      iVar5 = (*(code *)(*selected_objects)[1].pathingGroupMembers.
                                        desiredNumberValue)(iVar5,(int)*psStack_224);
                      iVar6 = **(int **)(iVar4 + 0xd8);
                      (&local_208)[iVar1] = (&local_208)[iVar1] + iVar5;
                      iVar6 = (**(code **)(iVar6 + 8))(iVar7);
                      goto joined_r0x005401ac;
                    }
                  }
                  iVar6 = iVar6 + 1;
                  pRVar8 = selected_objects[0x40];
                } while (iVar6 < *(short *)((int)&pRVar8->inside_obj + 2));
              }
            }
          }
LAB_005402a9:
          target_count = target_count + 1;
          psStack_224 = psStack_224 + 6;
          this = (RGE_Main_View *)selected_objects;
          pRVar3 = master_obj;
        } while (target_count < (int)master_obj);
      }
      j = j + 1;
    } while (j < local_21e);
  }
  free(i);
  iVar6 = 0;
  pRVar8 = (RGE_Static_Object *)0x0;
  iVar5 = 0;
  if (0 < (int)pRVar3) {
    ppRVar11 = &Picked_Objects;
    do {
      iVar4 = valid_target_count[iVar5 + 1];
      if ((iVar6 < iVar4) &&
         (pRVar8 = *(RGE_Static_Object **)(*(int *)(this->_padding_ + 0x88) + (int)*ppRVar11 * 4),
         iVar6 = iVar4, param_3 != (int *)0x0)) {
        *param_3 = attacking[iVar5 + 1];
        pRVar3 = master_obj;
      }
      iVar5 = iVar5 + 1;
      ppRVar11 = ppRVar11 + 3;
    } while (iVar5 < (int)pRVar3);
  }
  return pRVar8;
}

// --------------------------------------------------

// Function: command_make_move
// Address: 00540350
/* WARNING: Variable defined which should be unmapped: list_num */
/* public: virtual int __thiscall RGE_Main_View::command_make_move(long,long) */

int __thiscall RGE_Main_View::command_make_move(RGE_Main_View *this,long param_1,long param_2)
{
  uchar uVar1;
  uint uVar2;
  short list_num;
  RGE_Static_Object **list;
  RGE_Pick_Info pick_info;
  
  if (allow_user_commands != 0) {
    uVar1 = RGE_Player::get_selected_objects_to_command
                      ((RGE_Player *)this->_padding_,(RGE_Static_Object ***)&pick_info,
                       (short *)((int)&list + 2),-1,-1,-1,-1);
    if (uVar1 != '\0') {
      free(pick_info.x);
      uVar2 = 0;
      uVar1 = pick1(this,'*','\x01',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                    (RGE_Static_Object *)0x0,1);
      if (uVar1 != '2') {
        fixup_pick_info(this,(RGE_Pick_Info *)&pick_info.y);
        uVar2 = (**(code **)(*(int *)this->_padding_ + 0xa0))
                          (pick_info.tile,pick_info.y,pick_info._8_4_);
        uVar2 = uVar2 & 0xff;
        (**(code **)(this->_padding_ + 0x20))(1);
      }
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
      return uVar2;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: command_make_work
// Address: 00540420
/* WARNING: Variable defined which should be unmapped: list_num */
/* public: virtual int __thiscall RGE_Main_View::command_make_work(long,long) */

int __thiscall RGE_Main_View::command_make_work(RGE_Main_View *this,long param_1,long param_2)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  uint uVar3;
  short list_num;
  RGE_Static_Object **list;
  int attacking;
  RGE_Pick_Info pick_info;
  
  if (allow_user_commands != 0) {
    uVar1 = RGE_Player::get_selected_objects_to_command
                      ((RGE_Player *)this->_padding_,(RGE_Static_Object ***)&attacking,
                       (short *)((int)&list + 2),-1,-1,-1,-1);
    if (uVar1 != '\0') {
      free(attacking);
      pRVar2 = pick_best_target(this,param_1,param_2,(int *)&pick_info,-1);
      if (pRVar2 != (RGE_Static_Object *)0x0) {
        uVar3 = (**(code **)(*(int *)this->_padding_ + 0xa4))
                          (pRVar2,pRVar2->world_x,pRVar2->world_y);
        if ((uVar3 & 0xff) != 0) {
          RGE_View::display_object_selection((RGE_View *)this,pRVar2->id,0x5dc,2,2);
        }
        RGE_View::reset_overlay_sprites((RGE_View *)this);
        (**(code **)(this->_padding_ + 0x20))(1);
        (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
        return uVar3 & 0xff;
      }
      uVar1 = pick1(this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                    (RGE_Static_Object *)0x0,1);
      if (uVar1 == '3') {
        fixup_pick_info(this,(RGE_Pick_Info *)&pick_info.y);
        uVar3 = (**(code **)(*(int *)this->_padding_ + 0xa4))(0,pick_info.y,pick_info._8_4_);
        if ((uVar3 & 0xff) != 0) {
          reset_display_object_selection(this,2);
          RGE_View::add_overlay_sprite
                    ((RGE_View *)this,rge_base_game->shapes[2],0,this->_padding_ + param_1,
                     this->_padding_ + param_2,0,0xf,(uchar *)0x0,2,0x5a);
        }
        (**(code **)(this->_padding_ + 0x20))(1);
        (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
        return uVar3 & 0xff;
      }
      RGE_View::reset_overlay_sprites((RGE_View *)this);
      (**(code **)(this->_padding_ + 0x20))(1);
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: command_place_multi_object
// Address: 005405c0
/* public: virtual int __thiscall RGE_Main_View::command_place_multi_object(long,long,long,long,int)
    */

int __thiscall
RGE_Main_View::command_place_multi_object
          (RGE_Main_View *this,long param_1,long param_2,long param_3,long param_4,int param_5)
{
  RGE_View::set_selection_area((RGE_View *)this,-1,-1,-1,-1);
  (**(code **)(this->_padding_ + 0x20))(1);
  return 0;
}

// --------------------------------------------------

// Function: get_help_info
// Address: 005405e0
/* WARNING: Variable defined which should be unmapped: pick_info */
/* protected: virtual unsigned char __thiscall RGE_Main_View::get_help_info(char * &,long
   &,long,long) */

uchar __thiscall
RGE_Main_View::get_help_info
          (RGE_Main_View *this,char **param_1,long *param_2,long param_3,long param_4)
{
  char cVar1;
  uchar uVar2;
  long lVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  RGE_Pick_Info pick_info;
  
  uVar2 = pick1(this,')','\x02',param_3,param_4,(RGE_Pick_Info *)&pick_info.y,
                (RGE_Static_Object *)0x0,1);
  if (uVar2 != '4') {
    uVar2 = TPanel::get_help_info((TPanel *)this,param_1,param_2,param_3,param_4);
    return uVar2;
  }
  lVar3 = RGE_Master_Static_Object::get_help_message
                    (*(RGE_Master_Static_Object **)&(pick_info.tile)->last_drawn_shape);
  pcVar4 = TPanel::get_string((TPanel *)this,lVar3);
  uVar5 = 0xffffffff;
  do {
    pcVar7 = pcVar4;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar4 = pcVar7 + -uVar5;
  pcVar7 = *param_1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar7 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar7 = pcVar7 + 1;
  }
  lVar3 = RGE_Master_Static_Object::get_help_page
                    (*(RGE_Master_Static_Object **)&(pick_info.tile)->last_drawn_shape);
  *param_2 = lVar3;
  return '\x01';
}

// --------------------------------------------------

// Function: fixup_pick_info
// Address: 00540680
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: void __thiscall RGE_Main_View::fixup_pick_info(struct RGE_Pick_Info *) */

void __thiscall RGE_Main_View::fixup_pick_info(RGE_Main_View *this,RGE_Pick_Info *param_1)
{
  float fVar1;
  
  if (_DAT_00577908 <= param_1->x) {
    fVar1 = (float)*(int *)(this->_padding_ + 8);
    if (fVar1 <= param_1->x) {
      param_1->x = fVar1 - _DAT_00577900;
    }
  }
  else {
    param_1->x = 0.0;
  }
  if (_DAT_00577908 <= param_1->y) {
    fVar1 = (float)*(int *)(this->_padding_ + 0xc);
    if (param_1->y < fVar1) {
      return;
    }
    param_1->y = fVar1 - _DAT_00577900;
    return;
  }
  param_1->y = 0.0;
  return;
}

// --------------------------------------------------

// Function: reset_display_object_selection
// Address: 00540700
/* public: void __thiscall RGE_Main_View::reset_display_object_selection(int) */

void __thiscall RGE_Main_View::reset_display_object_selection(RGE_Main_View *this,int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < this->_padding_) {
    iVar2 = 0;
    do {
      piVar1 = (int *)(this->_padding_ + iVar2);
      if ((*piVar1 == 1) && (piVar1[4] == param_1)) {
        piVar1[2] = piVar1[2] - piVar1[3];
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x14;
    } while (iVar3 < this->_padding_);
  }
  return;
}

// --------------------------------------------------

