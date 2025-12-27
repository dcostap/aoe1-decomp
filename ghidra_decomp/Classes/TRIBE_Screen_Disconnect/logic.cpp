// Class: TRIBE_Screen_Disconnect
// Function: TRIBE_Screen_Disconnect
// Address: 004a61a0
// [HELPER] s_Multiplayer_Disconnect_Screen: "Multiplayer Disconnect Screen"
// [HELPER] s_scr3: "scr3"
/* public: __thiscall TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(int) */

TRIBE_Screen_Disconnect * __thiscall
TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(TRIBE_Screen_Disconnect *this,int param_1)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f298;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Multiplayer_Disconnect_Screen);
  this->_padding_ = (int)&_vftable_;
  this->mode = param_1;
  this->message = (TTextPanel *)0x0;
  this->cancel_button = (TButtonPanel *)0x0;
  this->close_button = (TButtonPanel *)0x0;
  local_4 = 0;
  lVar1 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,&s_scr3,0xc385,0);
  if (lVar1 == 0) {
    this->_padding_ = 1;
  }
  else {
    TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
                    /* language.dll match for 0x4c0: "Disconnecting from multiplayer
                       game...\\n\\n\\n\\nPlease press ESC if the game does not\\ndisconnect within
                       15 seconds." */
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->message,0x4c0,0x28,0x28,0x230,400,4,1,1,1);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004a6270
/* public: virtual void * __thiscall TRIBE_Screen_Disconnect::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Screen_Disconnect::_vector_deleting_destructor_(TRIBE_Screen_Disconnect *this,uint param_1)
{
  ~TRIBE_Screen_Disconnect(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Screen_Disconnect
// Address: 004a6290
/* public: virtual __thiscall TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect(void) */

void __thiscall TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect(TRIBE_Screen_Disconnect *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f2b8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->message);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 004a62f0
/* public: void __thiscall TRIBE_Screen_Disconnect::set_text(char *) */

void __thiscall TRIBE_Screen_Disconnect::set_text(TRIBE_Screen_Disconnect *this,char *param_1)
{
  (**(code **)(this->message->_padding_ + 0xe8))(param_1);
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 004a6310
/* public: void __thiscall TRIBE_Screen_Disconnect::set_text(long) */

void __thiscall TRIBE_Screen_Disconnect::set_text(TRIBE_Screen_Disconnect *this,long param_1)
{
  (**(code **)(this->message->_padding_ + 0xe4))(param_1);
  return;
}

// --------------------------------------------------

// Function: action
// Address: 004a6330
// [HELPER] s_Multiplayer_Disconnect_Screen: "Multiplayer Disconnect Screen"
// [HELPER] s_Status_Screen: "Status Screen"
/* public: virtual long __thiscall TRIBE_Screen_Disconnect::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TRIBE_Screen_Disconnect::action
          (TRIBE_Screen_Disconnect *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  
  if (param_1 != (TPanel *)0x0) {
    if (((TButtonPanel *)param_1 == this->cancel_button) && (param_2 == 1)) {
      TRIBE_Game::quit_game((TRIBE_Game *)rge_base_game);
      TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Disconnect_Screen);
      TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
      return 1;
    }
    if (((TButtonPanel *)param_1 == this->close_button) && (param_2 == 1)) {
      RGE_Base_Game::close(rge_base_game);
      return 1;
    }
  }
  lVar1 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 004a63c0
// [HELPER] s_C__msdev_work_age1_x1_Panel_cpp: "C:\msdev\work\age1_x1\Panel.cpp"
/* public: virtual long __thiscall TRIBE_Screen_Disconnect::handle_idle(void) */

long __thiscall TRIBE_Screen_Disconnect::handle_idle(TRIBE_Screen_Disconnect *this)
{
  char cVar1;
  undefined4 *puVar2;
  ulong uVar3;
  int iVar4;
  
  if (((this->_padding_ != 0) && ((char)this->_padding_ == '\x01')) &&
     (uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Panel_cpp,0x5fd),
     this->_padding_ <= (int)(uVar3 - this->_padding_))) {
    cVar1 = *(char *)((int)&this->_padding_ + 1);
    *(undefined1 *)&this->_padding_ = 2;
    if (cVar1 == '\x01') {
      (**(code **)(this->_padding_ + 0x88))();
    }
    else {
      (**(code **)(this->_padding_ + 0x9c))
                (this->_padding_,this->_padding_,this->_padding_,this->_padding_);
    }
  }
  puVar2 = (undefined4 *)this->_padding_;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    iVar4 = (**(code **)(*(int *)*puVar2 + 0x4c))();
    if (iVar4 != 0) break;
    puVar2 = (undefined4 *)puVar2[1];
  }
  return iVar4;
}

// --------------------------------------------------

