// Class: TRIBE_Diamond_Map_View
// Function: TRIBE_Diamond_Map_View
// Address: 0052c9e0
/* public: __thiscall TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View(void) */

TRIBE_Diamond_Map_View * __thiscall
TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View(TRIBE_Diamond_Map_View *this)
{
  RGE_Diamond_Map_View::RGE_Diamond_Map_View((RGE_Diamond_Map_View *)this);
  this->_padding_ = (int)&_vftable_;
  this->last_attack_time = 0;
  this->flash_on = 0;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0052ca00
/* public: virtual void * __thiscall TRIBE_Diamond_Map_View::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Diamond_Map_View::_scalar_deleting_destructor_(TRIBE_Diamond_Map_View *this,uint param_1)
{
  ~TRIBE_Diamond_Map_View(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Diamond_Map_View
// Address: 0052ca20
/* public: virtual __thiscall TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View(void) */

void __thiscall TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View(TRIBE_Diamond_Map_View *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055cf18;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&RGE_Diamond_Map::_vftable_;
  uStack_4 = 0;
  RGE_Diamond_Map::delete_surfaces((RGE_Diamond_Map *)this);
  if (this->_padding_ != 0) {
    free(this->_padding_);
    this->_padding_ = 0;
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
    this->_padding_ = 0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: set_redraw
// Address: 0052ca30
/* public: virtual void __thiscall TRIBE_Diamond_Map_View::set_redraw(enum TPanel::RedrawMode) */

void __thiscall TRIBE_Diamond_Map_View::set_redraw(TRIBE_Diamond_Map_View *this,RedrawMode param_1)
{
  RGE_Diamond_Map::set_redraw((RGE_Diamond_Map *)this,param_1);
  if (((param_1 != RedrawNone) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    TRIBE_Screen_Game::set_map_buttons_redraw((TRIBE_Screen_Game *)this->_padding_,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: draw_objects
// Address: 0052ca60
// [HELPER] s_C__msdev_work_age1_x1_tvw_dmap_c: "C:\msdev\work\age1_x1\tvw_dmap.cpp"
/* protected: virtual void __thiscall TRIBE_Diamond_Map_View::draw_objects(void) */

void __thiscall TRIBE_Diamond_Map_View::draw_objects(TRIBE_Diamond_Map_View *this)
{
  ulong uVar1;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_tvw_dmap_c,0x40);
  if (0x14c < uVar1 - this->last_attack_time) {
    this->flash_on = (uint)(this->flash_on == 0);
    this->last_attack_time = uVar1;
  }
  RGE_Diamond_Map::draw_objects((RGE_Diamond_Map *)this);
  return;
}

// --------------------------------------------------

// Function: draw_object
// Address: 0052cab0
/* protected: virtual void __thiscall TRIBE_Diamond_Map_View::draw_object(short,short,unsigned
   char,short,class RGE_Static_Object *) */

void __thiscall
TRIBE_Diamond_Map_View::draw_object
          (TRIBE_Diamond_Map_View *this,short param_1,short param_2,uchar param_3,short param_4,
          RGE_Static_Object *param_5)
{
  if (this->_padding_ == 4) {
    param_3 = (-(this->flash_on != 0) & 0x57U) - 1;
  }
  RGE_Diamond_Map::draw_object((RGE_Diamond_Map *)this,param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

