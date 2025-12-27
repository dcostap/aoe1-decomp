// Class: TRIBE_Screen_Main_Error
// Function: TRIBE_Screen_Main_Error
// Address: 0049f0d0
// [HELPER] s_: ""
// [HELPER] s_Main_Error_Screen: "Main Error Screen"
// [HELPER] s_scr1: "scr1"
/* public: __thiscall TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error(void) */

TRIBE_Screen_Main_Error * __thiscall
TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error(TRIBE_Screen_Main_Error *this)
{
  TButtonPanel **ppTVar1;
  long lVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f0b8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Main_Error_Screen);
  this->_padding_ = (int)&_vftable_;
  this->message = (TTextPanel *)0x0;
  this->cancel_button = (TButtonPanel *)0x0;
  local_4 = 0;
  lVar2 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,s_scr1,0xc383,0);
  if (lVar2 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)this,(TPanel *)this,&this->message,s_,0x28,0x28,0x230,400,4,1,1,1);
                    /* language.dll match for 0xfa1: "OK" */
  TEasy_Panel::create_button
            ((TEasy_Panel *)this,(TPanel *)this,&this->cancel_button,0xfa1,0,200,0x1b8,0xf0,0x1e,0,0
             ,0);
  ppTVar1 = &this->close_button;
                    /* language.dll match for 0x3ea: "X" */
  iVar3 = TEasy_Panel::create_button
                    ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0x3ea,0,0,0,0,0,-1,-1,0);
  if (iVar3 != 0) {
    (**(code **)((*ppTVar1)->_padding_ + 0x14))(1);
    (**(code **)((*ppTVar1)->_padding_ + 0x18))(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0049f220
/* public: virtual void * __thiscall TRIBE_Screen_Main_Error::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Screen_Main_Error::_vector_deleting_destructor_(TRIBE_Screen_Main_Error *this,uint param_1)
{
  ~TRIBE_Screen_Main_Error(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Screen_Main_Error
// Address: 0049f240
/* public: virtual __thiscall TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error(void) */

void __thiscall TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error(TRIBE_Screen_Main_Error *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f0d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->message);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->cancel_button);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 0049f2b0
/* public: void __thiscall TRIBE_Screen_Main_Error::set_text(char *) */

void __thiscall TRIBE_Screen_Main_Error::set_text(TRIBE_Screen_Main_Error *this,char *param_1)
{
  (**(code **)(this->message->_padding_ + 0xe8))(param_1);
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 0049f2d0
/* public: void __thiscall TRIBE_Screen_Main_Error::set_text(long) */

void __thiscall TRIBE_Screen_Main_Error::set_text(TRIBE_Screen_Main_Error *this,long param_1)
{
  (**(code **)(this->message->_padding_ + 0xe4))(param_1);
  return;
}

// --------------------------------------------------

// Function: action
// Address: 0049f2f0
/* public: virtual long __thiscall TRIBE_Screen_Main_Error::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TRIBE_Screen_Main_Error::action
          (TRIBE_Screen_Main_Error *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  
  if ((param_1 != (TPanel *)0x0) &&
     ((((TButtonPanel *)param_1 == this->cancel_button && (param_2 == 1)) ||
      (((TButtonPanel *)param_1 == this->close_button && (param_2 == 1)))))) {
    RGE_Base_Game::close(rge_base_game);
    return 1;
  }
  lVar1 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0049f340
/* public: virtual long __thiscall TRIBE_Screen_Main_Error::handle_idle(void) */

long __thiscall TRIBE_Screen_Main_Error::handle_idle(TRIBE_Screen_Main_Error *this)
{
  long lVar1;
  
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  lVar1 = TPanel::handle_idle((TPanel *)this);
  return lVar1;
}

// --------------------------------------------------

