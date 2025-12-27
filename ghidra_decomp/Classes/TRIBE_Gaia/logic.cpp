// Class: TRIBE_Gaia
// Function: TRIBE_Gaia
// Address: 00519af0
/* public: __thiscall TRIBE_Gaia::TRIBE_Gaia(int,class TRIBE_World *,unsigned char) */

TRIBE_Gaia * __thiscall
TRIBE_Gaia::TRIBE_Gaia(TRIBE_Gaia *this,int param_1,TRIBE_World *param_2,uchar param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005612d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TRIBE_Player::TRIBE_Player((TRIBE_Player *)this,param_1,param_2,param_3);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined1 *)&this->_padding_ = 2;
  rge_read(param_1,&this->update_time,4);
  rge_read(param_1,&this->update_nature,4);
  rge_read(param_1,&this->animal_max,4);
  rge_read(param_1,&this->last_count,4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00519ba0
/* public: virtual void * __thiscall TRIBE_Gaia::`vector deleting destructor'(unsigned int) */

void * __thiscall TRIBE_Gaia::_vector_deleting_destructor_(TRIBE_Gaia *this,uint param_1)
{
  ~TRIBE_Gaia(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Gaia
// Address: 00519bc0
/* public: virtual __thiscall TRIBE_Gaia::~TRIBE_Gaia(void) */

void __thiscall TRIBE_Gaia::~TRIBE_Gaia(TRIBE_Gaia *this)
{
  TRIBE_Player_Tech *this_00;
  TRIBE_History_Info *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_005611d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&TRIBE_Player::_vftable_;
  this_00 = (TRIBE_Player_Tech *)this->_padding_;
  uStack_4 = 0;
  if (this_00 != (TRIBE_Player_Tech *)0x0) {
    TRIBE_Player_Tech::~TRIBE_Player_Tech(this_00);
    operator_delete(this_00);
    this->_padding_ = 0;
  }
  if ((undefined4 *)this->_padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->_padding_)(1);
    this->_padding_ = 0;
  }
  this_01 = (TRIBE_History_Info *)this->_padding_;
  if (this_01 != (TRIBE_History_Info *)0x0) {
    TRIBE_History_Info::~TRIBE_History_Info(this_01);
    operator_delete(this_01);
    this->_padding_ = 0;
  }
  uStack_4 = 0xffffffff;
  RGE_Player::~RGE_Player((RGE_Player *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: TRIBE_Gaia
// Address: 00519bd0
/* public: __thiscall TRIBE_Gaia::TRIBE_Gaia(class TRIBE_World *,class RGE_Master_Player *,unsigned
   char,char *,unsigned char) */

TRIBE_Gaia * __thiscall
TRIBE_Gaia::TRIBE_Gaia
          (TRIBE_Gaia *this,TRIBE_World *param_1,RGE_Master_Player *param_2,uchar param_3,
          char *param_4,uchar param_5)
{
  TRIBE_Player::TRIBE_Player
            ((TRIBE_Player *)this,param_1,param_2,param_3,param_4,param_5,'\0','\x01',(char *)0x0,
             (char *)0x0,(char *)0x0);
  this->_padding_ = (int)&_vftable_;
  *(undefined1 *)&this->_padding_ = 2;
  this->update_time = 0.0;
  this->update_nature = 0x1d;
  this->animal_max = 0;
  this->last_count = 0;
  return this;
}

// --------------------------------------------------

// Function: save
// Address: 00519c40
/* public: virtual void __thiscall TRIBE_Gaia::save(int) */

void __thiscall TRIBE_Gaia::save(TRIBE_Gaia *this,int param_1)
{
  TRIBE_Player::save((TRIBE_Player *)this,param_1);
  rge_write(param_1,&this->update_time,4);
  rge_write(param_1,&this->update_nature,4);
  rge_write(param_1,&this->animal_max,4);
  rge_write(param_1,&this->last_count,4);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00519ca0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Gaia::update(void) */

void __thiscall TRIBE_Gaia::update(TRIBE_Gaia *this)
{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = _DAT_00576824;
  fVar1 = *(float *)(this->_padding_ + 0x84) + this->update_time;
  this->update_time = fVar1;
  if (fVar2 < fVar1) {
    do {
      fVar1 = this->update_time - _DAT_00576824;
      iVar3 = this->update_nature + 1;
      this->update_nature = iVar3;
      this->update_time = fVar1;
      if (iVar3 == 0x1e) {
        this->update_nature = 0;
      }
    } while (_DAT_00576824 < this->update_time);
  }
  RGE_Player::update((RGE_Player *)this);
  return;
}

// --------------------------------------------------

// Function: load_master_object
// Address: 00519d10
/* public: void __thiscall TRIBE_Gaia::load_master_object(int,short,unsigned char,class RGE_Sprite *
   *,class RGE_Sound * *) */

void __thiscall
TRIBE_Gaia::load_master_object
          (TRIBE_Gaia *this,int param_1,short param_2,uchar param_3,RGE_Sprite **param_4,
          RGE_Sound **param_5)
{
  TRIBE_Player::load_master_object((TRIBE_Player *)this,param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: random_start
// Address: 00519d40
/* public: virtual void __thiscall TRIBE_Gaia::random_start(void) */

void __thiscall TRIBE_Gaia::random_start(TRIBE_Gaia *this)
{
  return;
}

// --------------------------------------------------

