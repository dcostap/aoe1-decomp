// Class: TRIBE_Credits_Screen
// Function: TRIBE_Credits_Screen
// Address: 004926e0
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_credit_d: "credit%d"
// [HELPER] s_data2_list_cr: "data2\list.cr"
// [HELPER] s_scr_cred: "scr_cred"
/* WARNING: Variable defined which should be unmapped: size */
/* public: __thiscall TRIBE_Credits_Screen::TRIBE_Credits_Screen(void) */

TRIBE_Credits_Screen * __thiscall
TRIBE_Credits_Screen::TRIBE_Credits_Screen(TRIBE_Credits_Screen *this)
{
  TMusic_System *this_00;
  long lVar1;
  RGE_Font *pRVar2;
  int iVar3;
  TScrollTextPanel *pTVar4;
  TShape *pTVar5;
  int iVar6;
  TShape **ppTVar7;
  char *pcVar8;
  undefined4 *unaff_FS_OFFSET;
  long size;
  char temp_file_name [13];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055eace;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  temp_file_name._0_4_ = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Credits_Screen);
  this->_padding_ = (int)&_vftable_;
  this->text_panel = (TScrollTextPanel *)0x0;
  this->text_set = 1;
  this->picture_set = 1;
  this->last_picture_time = 0;
  this->last_pause_time = 0;
  this->mode = ModeNone;
  this->first_draw = 1;
  this->text_done = 0;
  ppTVar7 = this->back_pics;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppTVar7 = (TShape *)0x0;
    ppTVar7 = ppTVar7 + 1;
  }
  local_4 = 0;
  lVar1 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,s_scr_cred,0xc38b,1);
  if (lVar1 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
  pRVar2 = RGE_Base_Game::get_font(rge_base_game,4);
  pcVar8 = (char *)0x0;
  iVar6 = __open(s_data2_list_cr,0x8000);
  if (iVar6 != -1) {
    lseek(iVar6,0,2);
    iVar3 = __tell(iVar6);
    pcVar8 = (char *)calloc(iVar3 + 1,0x400);
    if (pcVar8 != (char *)0x0) {
      lseek(iVar6,0,0);
      read(iVar6,pcVar8,iVar3);
    }
    close(iVar6);
  }
  pTVar4 = (TScrollTextPanel *)operator_new(0x198);
  local_4._0_1_ = 1;
  if (pTVar4 == (TScrollTextPanel *)0x0) {
    pTVar4 = (TScrollTextPanel *)0x0;
  }
  else {
    pTVar4 = (TScrollTextPanel *)
             TScrollTextPanel::TScrollTextPanel
                       (pTVar4,(TPanel *)this,(TDrawArea *)this->_padding_,
                        this->_padding_ / 2 + -0xfa,this->_padding_ / 2 + -0x96,500,300,0x1e,
                        pRVar2->font,pRVar2->font_wid,pRVar2->font_hgt,pcVar8);
  }
  local_4._0_1_ = 0;
  this->text_panel = pTVar4;
  if (pcVar8 != (char *)0x0) {
    free(pcVar8);
  }
  this->back_pics[0] = (TShape *)this->_padding_;
  ppTVar7 = this->back_pics;
  iVar6 = 0xc3eb;
  do {
    ppTVar7 = ppTVar7 + 1;
    sprintf(temp_file_name + 4,s_credit_d,iVar6 + -0xc3e9);
    pTVar5 = (TShape *)operator_new(0x20);
    local_4._0_1_ = 2;
    if (pTVar5 == (TShape *)0x0) {
      pTVar5 = (TShape *)0x0;
    }
    else {
      pTVar5 = (TShape *)TShape::TShape(pTVar5,temp_file_name + 4,iVar6);
    }
    *ppTVar7 = pTVar5;
    local_4._0_1_ = 0;
    iVar3 = iVar6 + -0xc3e9;
    iVar6 = iVar6 + 1;
  } while (iVar3 < 7);
  this_00 = rge_base_game->music_system;
  if (((this_00 != (TMusic_System *)0x0) && (this_00->music_type == '\x01')) &&
     (this_00->track_count == 0xf)) {
    TMusic_System::play_tracks(this_00,0xf,0xf,1,0,0);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00492950
/* public: virtual void * __thiscall TRIBE_Credits_Screen::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Credits_Screen::_scalar_deleting_destructor_(TRIBE_Credits_Screen *this,uint param_1)
{
  ~TRIBE_Credits_Screen(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Credits_Screen
// Address: 00492970
/* public: virtual __thiscall TRIBE_Credits_Screen::~TRIBE_Credits_Screen(void) */

void __thiscall TRIBE_Credits_Screen::~TRIBE_Credits_Screen(TRIBE_Credits_Screen *this)
{
  TShape *this_00;
  TMusic_System *this_01;
  int iVar1;
  TShape **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055eae8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  ppTVar2 = this->back_pics;
  iVar1 = 7;
  do {
    this_00 = *ppTVar2;
    if (this_00 != (TShape *)0x0) {
      TShape::~TShape(this_00);
      operator_delete(this_00);
      *ppTVar2 = (TShape *)0x0;
    }
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this->_padding_ = 0;
  if (this->text_panel != (TScrollTextPanel *)0x0) {
    (**(code **)this->text_panel->_padding_)(1);
    this->text_panel = (TScrollTextPanel *)0x0;
  }
  this_01 = rge_base_game->music_system;
  if (((this_01 != (TMusic_System *)0x0) && (this_01->music_type == '\x01')) &&
     (this_01->track_count == 0xf)) {
    TMusic_System::play_tracks(this_01,5,0xe,1,0,0);
  }
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: handle_mouse_down
// Address: 00492a40
/* public: virtual long __thiscall TRIBE_Credits_Screen::handle_mouse_down(unsigned
   char,long,long,int,int) */

long __thiscall
TRIBE_Credits_Screen::handle_mouse_down
          (TRIBE_Credits_Screen *this,uchar param_1,long param_2,long param_3,int param_4,
          int param_5)
{
  close_screen(this);
  return 1;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 00492a50
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
/* public: virtual long __thiscall TRIBE_Credits_Screen::handle_idle(void) */

long __thiscall TRIBE_Credits_Screen::handle_idle(TRIBE_Credits_Screen *this)
{
  ScreenMode SVar1;
  TDrawArea *this_00;
  TDrawSystem *pTVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  
  SVar1 = this->mode;
  if (SVar1 == ModeNone) {
    if (this->last_picture_time != 0) {
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0xf5);
      if (9999 < uVar3 - this->last_picture_time) {
        this_00 = (TDrawArea *)this->_padding_;
        pTVar2 = this_00->DrawSystem;
        if ((pTVar2->ScreenMode == '\x02') || (pTVar2->DrawType == '\x01')) {
          iVar5 = this->_padding_;
          this->mode = ModeFadeOut;
          (this->color).peRed = '\0';
          (this->color).peGreen = '\0';
          (this->color).peBlue = '\0';
          if (iVar5 == 0) {
            TDrawArea::GetPalette(this_00,this->color_table);
          }
          else {
            GetPaletteEntries(iVar5,0,0x100,this->color_table);
          }
          RGE_fade_palette_start
                    ((TDrawArea *)this->_padding_,this->color,0.5,'\x01',(tagPALETTEENTRY *)0x0,0xff
                     ,-1);
        }
        else {
          this->mode = ModePause;
        }
      }
      goto LAB_00492c91;
    }
    iVar5 = 0xf1;
  }
  else {
    if (SVar1 == ModeFadeOut) {
      iVar5 = RGE_fade_palette_step();
      if (iVar5 != 0) {
        iVar5 = this->_padding_;
        this->mode = ModePause;
        this->last_pause_time = 0;
        (**(code **)(iVar5 + 0x20))(1);
        (**(code **)(iVar5 + 0x54))();
        TDrawSystem::Paint(*(TDrawSystem **)this->_padding_,(tagRECT *)0x0);
      }
      goto LAB_00492c91;
    }
    if (SVar1 == ModePause) {
      if (this->last_pause_time == 0) {
        uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x11a);
        this->last_pause_time = uVar3;
        goto LAB_00492c91;
      }
      debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x11e);
      iVar5 = this->picture_set + 1;
      this->mode = ModeFadeIn;
      this->picture_set = iVar5;
      if (7 < iVar5) {
        this->picture_set = 1;
      }
      iVar5 = this->_padding_;
      this->_padding_ = (int)this->back_pics[this->picture_set + -1];
      (**(code **)(iVar5 + 0x20))(1);
      (**(code **)(iVar5 + 0x54))();
      TDrawSystem::Paint(*(TDrawSystem **)this->_padding_,(tagRECT *)0x0);
      pTVar2 = ((TDrawArea *)this->_padding_)->DrawSystem;
      if ((pTVar2->ScreenMode == '\x02') || (pTVar2->DrawType == '\x01')) {
        RGE_fade_palette_start
                  ((TDrawArea *)this->_padding_,this->color,0.5,'\x02',this->color_table,0xff,-1);
        goto LAB_00492c91;
      }
      this->mode = ModeNone;
      iVar5 = 0x138;
    }
    else {
      if (SVar1 != ModeFadeIn) goto LAB_00492c91;
      iVar5 = RGE_fade_palette_step();
      if (iVar5 == 0) goto LAB_00492c91;
      this->mode = ModeNone;
      iVar5 = 0x142;
    }
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,iVar5);
  this->last_picture_time = uVar3;
LAB_00492c91:
  if (this->text_done != 0) {
    close_screen(this);
    return 1;
  }
  lVar4 = TPanel::handle_idle((TPanel *)this);
  return lVar4;
}

// --------------------------------------------------

// Function: draw
// Address: 00492cc0
/* public: virtual void __thiscall TRIBE_Credits_Screen::draw(void) */

void __thiscall TRIBE_Credits_Screen::draw(TRIBE_Credits_Screen *this)
{
  TDrawSystem *pTVar1;
  int iVar2;
  TShape **ppTVar3;
  
  if (this->mode == ModePause) {
    pTVar1 = ((TDrawArea *)this->_padding_)->DrawSystem;
    if ((pTVar1->ScreenMode == '\x02') || (pTVar1->DrawType == '\x01')) {
      TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,0);
      return;
    }
  }
  if (this->first_draw != 0) {
    iVar2 = 7;
    ppTVar3 = this->back_pics;
    do {
      this->_padding_ = (int)*ppTVar3;
      TScreenPanel::draw((TScreenPanel *)this);
      ppTVar3 = ppTVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    this->first_draw = 0;
    this->_padding_ = (int)this->back_pics[0];
  }
  TScreenPanel::draw((TScreenPanel *)this);
  return;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 00492d50
/* public: virtual long __thiscall TRIBE_Credits_Screen::key_down_action(long,short,int,int,int) */

long __thiscall
TRIBE_Credits_Screen::key_down_action
          (TRIBE_Credits_Screen *this,long param_1,short param_2,int param_3,int param_4,int param_5
          )
{
  if ((param_1 != 0xd) && (param_1 != 0x1b)) {
    return 0;
  }
  close_screen(this);
  return 1;
}

// --------------------------------------------------

// Function: action
// Address: 00492d70
/* public: virtual long __thiscall TRIBE_Credits_Screen::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TRIBE_Credits_Screen::action
          (TRIBE_Credits_Screen *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  
  if (((param_1 != (TPanel *)0x0) && ((TScrollTextPanel *)param_1 == this->text_panel)) &&
     (param_2 == 1)) {
    this->text_done = 1;
    return 1;
  }
  lVar1 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: close_screen
// Address: 00492db0
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Main_Menu: "Main Menu"
/* public: void __thiscall TRIBE_Credits_Screen::close_screen(void) */

void __thiscall TRIBE_Credits_Screen::close_screen(TRIBE_Credits_Screen *this)
{
  TPanel *pTVar1;
  int iVar2;
  TRIBE_Screen_Main_Menu *this_00;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055eb0b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = TPanelSystem::panel(&panel_system,s_Game_Screen);
  if (pTVar1 == (TPanel *)0x0) {
                    /* language.dll match for 0x4b0: "Ready" */
    this_00 = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
    local_4 = 0;
    if (this_00 != (TRIBE_Screen_Main_Menu *)0x0) {
      TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this_00);
    }
    local_4 = 0xffffffff;
    pcVar3 = s_Main_Menu;
  }
  else {
    iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
      RGE_Base_Game::set_paused(rge_base_game,0,0);
    }
    pcVar3 = s_Game_Screen;
  }
  TPanelSystem::setCurrentPanel(&panel_system,pcVar3,0);
  TPanelSystem::destroyPanel(&panel_system,s_Credits_Screen);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

