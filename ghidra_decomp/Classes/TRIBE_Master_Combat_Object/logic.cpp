// Class: TRIBE_Master_Combat_Object
// Function: TRIBE_Master_Combat_Object
// Address: 0050e970
/* public: __thiscall TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(class
   TRIBE_Master_Combat_Object *,int) */

TRIBE_Master_Combat_Object * __thiscall
TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
          (TRIBE_Master_Combat_Object *this,TRIBE_Master_Combat_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560ee8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)this,(RGE_Master_Combat_Object *)param_1,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_2 != 0) {
    setup(this,param_1);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0050e9d0
/* public: virtual void * __thiscall TRIBE_Master_Combat_Object::`vector deleting
   destructor'(unsigned int) */

void * __thiscall
TRIBE_Master_Combat_Object::_vector_deleting_destructor_
          (TRIBE_Master_Combat_Object *this,uint param_1)
{
  ~TRIBE_Master_Combat_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Master_Combat_Object
// Address: 0050e9f0
/* public: __thiscall TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(int,class RGE_Sprite *
   *,class RGE_Sound * *,int) */

TRIBE_Master_Combat_Object * __thiscall
TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
          (TRIBE_Master_Combat_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560f08;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)this,param_1,param_2,param_3,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_4 != 0) {
    setup(this,param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Master_Combat_Object
// Address: 0050ea60
/* public: __thiscall TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(struct _iobuf *,class
   RGE_Sprite * *,class RGE_Sound * *,short,int) */

TRIBE_Master_Combat_Object * __thiscall
TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
          (TRIBE_Master_Combat_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3
          ,short param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560f28;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)this,param_1,param_2,param_3,param_4,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_5 != 0) {
    setup(this,param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 0050eae0
/* protected: int __thiscall TRIBE_Master_Combat_Object::setup(class TRIBE_Master_Combat_Object *)
    */

int __thiscall
TRIBE_Master_Combat_Object::setup
          (TRIBE_Master_Combat_Object *this,TRIBE_Master_Combat_Object *param_1)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  Attribute_Cost *pAVar3;
  int iVar4;
  
  RGE_Master_Combat_Object::setup
            ((RGE_Master_Combat_Object *)this,(RGE_Master_Combat_Object *)param_1);
  *(undefined1 *)&this->_padding_ = 0x46;
  iVar4 = 3;
  pAVar3 = this->build_inventory;
  do {
    puVar1 = (undefined4 *)(((int)param_1 - (int)this) + (int)pAVar3);
    iVar4 = iVar4 + -1;
    uVar2 = *puVar1;
    pAVar3->type = (short)uVar2;
    pAVar3->amount = (short)((uint)uVar2 >> 0x10);
    *(undefined2 *)&pAVar3->flag = *(undefined2 *)(puVar1 + 1);
    pAVar3 = pAVar3 + 1;
  } while (iVar4 != 0);
  this->build_pts_required = param_1->build_pts_required;
  this->id_of_building_obj = param_1->id_of_building_obj;
  this->button_location = param_1->button_location;
  this->orig_pierce_armor = param_1->orig_pierce_armor;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0050eb60
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: int __thiscall TRIBE_Master_Combat_Object::setup(int,class RGE_Sprite * *,class
   RGE_Sound * *) */

int __thiscall
TRIBE_Master_Combat_Object::setup
          (TRIBE_Master_Combat_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  short *psVar1;
  int iVar2;
  Attribute_Cost *pAVar3;
  int iVar4;
  
  RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object *)this,param_1,param_2,param_3);
  *(undefined1 *)&this->_padding_ = 0x46;
  pAVar3 = this->build_inventory;
  iVar2 = 3;
  do {
    rge_read(param_1,pAVar3,6);
    pAVar3 = pAVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  rge_read(param_1,&this->build_pts_required,2);
  rge_read(param_1,&this->id_of_building_obj,2);
  rge_read(param_1,&this->button_location,1);
  if (_DAT_0057677c <= save_game_version) {
    rge_read(param_1,&this->orig_pierce_armor,2);
    return 1;
  }
  iVar2 = (int)*(short *)((int)&this->_padding_ + 2);
  this->orig_pierce_armor = 0;
  if (0 < iVar2) {
    psVar1 = (short *)this->_padding_;
    iVar4 = iVar2;
    do {
      if ((*psVar1 == 3) && (this->orig_pierce_armor < psVar1[1])) {
        this->orig_pierce_armor = psVar1[1];
      }
      psVar1 = psVar1 + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *(ushort *)&this->_padding_ = (ushort)(byte)this->_padding_;
  if (0 < iVar2) {
    psVar1 = (short *)this->_padding_;
    do {
      if ((*psVar1 != 3) && ((short)this->_padding_ < psVar1[1])) {
        *(short *)&this->_padding_ = psVar1[1];
      }
      psVar1 = psVar1 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0050ec90
// [HELPER] s__hd__hd__hd: "%hd %hd %hd"
/* protected: int __thiscall TRIBE_Master_Combat_Object::setup(struct _iobuf *,class RGE_Sprite *
   *,class RGE_Sound * *,short) */

int __thiscall
TRIBE_Master_Combat_Object::setup
          (TRIBE_Master_Combat_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3
          ,short param_4)
{
  short *psVar1;
  int iVar2;
  Attribute_Cost *pAVar3;
  int iVar4;
  undefined2 in_stack_00000012;
  
  RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object *)this,param_1,param_2,param_3,param_4);
  *(undefined1 *)&this->_padding_ = 0x46;
  pAVar3 = this->build_inventory;
  iVar2 = 3;
  do {
    fscanf(param_1,s__hd__hd__hd,pAVar3,&pAVar3->amount,&param_4);
    pAVar3->flag = (uchar)param_4;
    pAVar3 = pAVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  fscanf(param_1,s__hd__hd__hd,&this->build_pts_required,&this->id_of_building_obj,&param_3);
  iVar2 = (int)*(short *)((int)&this->_padding_ + 2);
  this->button_location = (uchar)param_3;
  this->orig_pierce_armor = 0;
  if (0 < iVar2) {
    psVar1 = (short *)this->_padding_;
    iVar4 = iVar2;
    do {
      if ((*psVar1 == 3) && (this->orig_pierce_armor < psVar1[1])) {
        this->orig_pierce_armor = psVar1[1];
      }
      psVar1 = psVar1 + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *(ushort *)&this->_padding_ = (ushort)(byte)this->_padding_;
  if (0 < iVar2) {
    psVar1 = (short *)this->_padding_;
    do {
      if ((*psVar1 != 3) && ((short)this->_padding_ < psVar1[1])) {
        *(short *)&this->_padding_ = psVar1[1];
      }
      psVar1 = psVar1 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: ~TRIBE_Master_Combat_Object
// Address: 0050eda0
/* public: virtual __thiscall TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object(void) */

void __thiscall
TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object *this)
{
  this->_padding_ = (int)&_vftable_;
  RGE_Master_Combat_Object::~RGE_Master_Combat_Object((RGE_Master_Combat_Object *)this);
  return;
}

// --------------------------------------------------

// Function: create_task_list
// Address: 0050edb0
/* public: virtual class RGE_Task_List * __thiscall
   TRIBE_Master_Combat_Object::create_task_list(void) */

RGE_Task_List * __thiscall
TRIBE_Master_Combat_Object::create_task_list(TRIBE_Master_Combat_Object *this)
{
  RGE_Task_List *this_00;
  RGE_Task_List *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560f4b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Task_List *)operator_new(0xc);
  local_4 = 0;
  pRVar1 = (RGE_Task_List *)0x0;
  if (this_00 != (RGE_Task_List *)0x0) {
    RGE_Task_List::RGE_Task_List(this_00);
    this_00->_padding_ = (int)&TRIBE_Task_List::_vftable_;
    pRVar1 = this_00;
  }
  *unaff_FS_OFFSET = local_c;
  return pRVar1;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 0050ee00
/* public: virtual void __thiscall TRIBE_Master_Combat_Object::copy_obj(class
   RGE_Master_Static_Object *) */

void __thiscall
TRIBE_Master_Combat_Object::copy_obj
          (TRIBE_Master_Combat_Object *this,RGE_Master_Static_Object *param_1)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  Attribute_Cost *pAVar3;
  int iVar4;
  
  RGE_Master_Combat_Object::copy_obj((RGE_Master_Combat_Object *)this,param_1);
  iVar4 = 3;
  pAVar3 = this->build_inventory;
  do {
    puVar1 = (undefined4 *)(((int)param_1 - (int)this) + (int)pAVar3);
    iVar4 = iVar4 + -1;
    uVar2 = *puVar1;
    pAVar3->type = (short)uVar2;
    pAVar3->amount = (short)((uint)uVar2 >> 0x10);
    *(undefined2 *)&pAVar3->flag = *(undefined2 *)(puVar1 + 1);
    pAVar3 = pAVar3 + 1;
  } while (iVar4 != 0);
  this->build_pts_required = *(short *)((int)&param_1[1].hotkey_id + 2);
  this->id_of_building_obj = *(short *)&param_1[1].recyclable;
  this->button_location = param_1[1].create_doppleganger_on_death;
  this->orig_pierce_armor = *(short *)&param_1[1].draw_flag;
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 0050ee80
/* public: virtual void __thiscall TRIBE_Master_Combat_Object::modify(float,unsigned char) */

void __thiscall
TRIBE_Master_Combat_Object::modify(TRIBE_Master_Combat_Object *this,float param_1,uchar param_2)
{
  short sVar1;
  short *psVar2;
  short *psVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  if (param_2 == 'd') {
    psVar2 = &this->build_inventory[0].amount;
    iVar6 = 3;
    do {
      if (*(uchar *)(psVar2 + 1) != '\0') {
        sVar1 = __ftol();
        *psVar2 = sVar1;
      }
      psVar2 = psVar2 + 3;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    return;
  }
  if (param_2 != 'e') {
    RGE_Master_Combat_Object::modify((RGE_Master_Combat_Object *)this,param_1,param_2);
    return;
  }
  psVar2 = &this->build_inventory[0].amount;
  iVar6 = 3;
  do {
    if (*(uchar *)(psVar2 + 1) == '\0') {
      sVar1 = __ftol();
      *psVar2 = sVar1;
    }
    psVar2 = psVar2 + 3;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  piVar5 = &this->_padding_;
  psVar3 = (short *)((int)&this->_padding_ + 2);
  iVar6 = 3;
  psVar2 = psVar3;
  piVar4 = piVar5;
  do {
    if (*psVar2 == 4) {
      *piVar4 = (int)param_1;
    }
    psVar2 = psVar2 + 1;
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 3;
  psVar2 = psVar3;
  piVar4 = piVar5;
  do {
    if (*psVar2 == 0xb) {
      *piVar4 = (int)-param_1;
    }
    psVar2 = psVar2 + 1;
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 3;
  do {
    if (*psVar3 == 0x13) {
      *piVar5 = (int)-param_1;
    }
    psVar3 = psVar3 + 1;
    piVar5 = piVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}

// --------------------------------------------------

// Function: modify_delta
// Address: 0050ef70
/* public: virtual void __thiscall TRIBE_Master_Combat_Object::modify_delta(float,unsigned char) */

void __thiscall
TRIBE_Master_Combat_Object::modify_delta
          (TRIBE_Master_Combat_Object *this,float param_1,uchar param_2)
{
  short sVar1;
  short *psVar2;
  int iVar3;
  
  if (param_2 != 'd') {
    RGE_Master_Combat_Object::modify_delta((RGE_Master_Combat_Object *)this,param_1,param_2);
    return;
  }
  psVar2 = &this->build_inventory[0].amount;
  iVar3 = 3;
  do {
    if (*(uchar *)(psVar2 + 1) != '\0') {
      sVar1 = __ftol();
      *psVar2 = *psVar2 + sVar1;
    }
    psVar2 = psVar2 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// --------------------------------------------------

// Function: modify_percent
// Address: 0050efc0
/* public: virtual void __thiscall TRIBE_Master_Combat_Object::modify_percent(float,unsigned char)
    */

void __thiscall
TRIBE_Master_Combat_Object::modify_percent
          (TRIBE_Master_Combat_Object *this,float param_1,uchar param_2)
{
  short sVar1;
  short *psVar2;
  int iVar3;
  
  if (param_2 != 'd') {
    RGE_Master_Combat_Object::modify_percent((RGE_Master_Combat_Object *)this,param_1,param_2);
    return;
  }
  psVar2 = &this->build_inventory[0].amount;
  iVar3 = 3;
  do {
    if (*(uchar *)(psVar2 + 1) != '\0') {
      sVar1 = __ftol();
      *psVar2 = sVar1;
    }
    psVar2 = psVar2 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0050f010
/* public: virtual void __thiscall TRIBE_Master_Combat_Object::save(int) */

void __thiscall TRIBE_Master_Combat_Object::save(TRIBE_Master_Combat_Object *this,int param_1)
{
  int iVar1;
  Attribute_Cost *pAVar2;
  
  RGE_Master_Combat_Object::save((RGE_Master_Combat_Object *)this,param_1);
  pAVar2 = this->build_inventory;
  iVar1 = 3;
  do {
    rge_write(param_1,pAVar2,6);
    pAVar2 = pAVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  rge_write(param_1,&this->build_pts_required,2);
  rge_write(param_1,&this->id_of_building_obj,2);
  rge_write(param_1,&this->button_location,1);
  rge_write(param_1,&this->orig_pierce_armor,2);
  return;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 0050f090
/* public: virtual class RGE_Static_Object * __thiscall
   TRIBE_Master_Combat_Object::make_new_obj(class RGE_Player *,float,float,float) */

RGE_Static_Object * __thiscall
TRIBE_Master_Combat_Object::make_new_obj
          (TRIBE_Master_Combat_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4)
{
  TRIBE_Combat_Object *this_00;
  RGE_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560f6b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Combat_Object *)operator_new(0x1c8);
  local_4 = 0;
  if (this_00 != (TRIBE_Combat_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             TRIBE_Combat_Object::TRIBE_Combat_Object
                       (this_00,this,param_1,param_2,param_3,param_4,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 0050f110
/* public: virtual class RGE_Master_Static_Object * __thiscall
   TRIBE_Master_Combat_Object::make_new_master(void) */

RGE_Master_Static_Object * __thiscall
TRIBE_Master_Combat_Object::make_new_master(TRIBE_Master_Combat_Object *this)
{
  TRIBE_Master_Combat_Object *this_00;
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560f8b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Master_Combat_Object *)operator_new(0x164);
  local_4 = 0;
  if (this_00 != (TRIBE_Master_Combat_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)TRIBE_Master_Combat_Object(this_00,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

