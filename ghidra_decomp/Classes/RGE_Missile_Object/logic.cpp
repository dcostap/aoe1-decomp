// Class: RGE_Missile_Object
// Function: RGE_Missile_Object
// Address: 0045a740
/* public: __thiscall RGE_Missile_Object::RGE_Missile_Object(class RGE_Master_Combat_Object *,class
   RGE_Player *,float,float,float,int) */

RGE_Missile_Object * __thiscall
RGE_Missile_Object::RGE_Missile_Object
          (RGE_Missile_Object *this,RGE_Master_Combat_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055db68;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Combat_Object::RGE_Combat_Object
            ((RGE_Combat_Object *)this,param_1,param_2,param_3,param_4,param_5,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_6 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x3c;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0045a7d0
/* public: virtual void * __thiscall RGE_Missile_Object::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
RGE_Missile_Object::_scalar_deleting_destructor_(RGE_Missile_Object *this,uint param_1)
{
  ~RGE_Missile_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Missile_Object
// Address: 0045a7f0
/* public: virtual __thiscall RGE_Missile_Object::~RGE_Missile_Object(void) */

void __thiscall RGE_Missile_Object::~RGE_Missile_Object(RGE_Missile_Object *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  ulong uVar5;
  ulong uVar6;
  int *piVar7;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055cd98;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&RGE_Combat_Object::_vftable_;
  iVar1 = this->_padding_;
  uStack_4 = 0;
  if (-1 < iVar1) {
    uVar5 = this->_padding_;
    piVar7 = &this->_padding_;
    uVar6 = 0;
    iVar2 = (int)*(short *)(this->_padding_ + 0x14);
    iVar3 = __ftol();
    iVar4 = __ftol();
    Visible_Unit_Manager::Update_Unit_Info
              (VisibleUnitManager,iVar1,(int)*(short *)(this->_padding_ + 0x4a),iVar4,iVar3,iVar2,
               uVar5,uVar6,(VISIBLE_UNIT_REC **)piVar7);
  }
  uStack_4 = 0xffffffff;
  RGE_Action_Object::~RGE_Action_Object((RGE_Action_Object *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: RGE_Missile_Object
// Address: 0045a800
/* public: __thiscall RGE_Missile_Object::RGE_Missile_Object(int,class RGE_Game_World *,int) */

RGE_Missile_Object * __thiscall
RGE_Missile_Object::RGE_Missile_Object
          (RGE_Missile_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055db88;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Combat_Object::RGE_Combat_Object((RGE_Combat_Object *)this,param_1,param_2,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x3c;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 0045a870
/* protected: virtual int __thiscall RGE_Missile_Object::setup(class RGE_Master_Combat_Object
   *,class RGE_Player *,float,float,float) */

int __thiscall
RGE_Missile_Object::setup
          (RGE_Missile_Object *this,RGE_Master_Combat_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  RGE_Combat_Object::setup((RGE_Combat_Object *)this,param_1,param_2,param_3,param_4,param_5);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x3c;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0045a8a0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall RGE_Missile_Object::setup(int,class RGE_Game_World *) */

int __thiscall
RGE_Missile_Object::setup(RGE_Missile_Object *this,int param_1,RGE_Game_World *param_2)
{
  RGE_Combat_Object::setup((RGE_Combat_Object *)this,param_1,param_2);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x3c;
  if (_DAT_00570930 < save_game_version) {
    rge_read(param_1,&this->max_range,4);
    return 1;
  }
  this->max_range = *(float *)(this->_padding_ + 0x114);
  return 1;
}

// --------------------------------------------------

// Function: rehook
// Address: 0045a900
/* public: virtual void __thiscall RGE_Missile_Object::rehook(void) */

void __thiscall RGE_Missile_Object::rehook(RGE_Missile_Object *this)
{
  RGE_Static_Object::rehook((RGE_Static_Object *)this);
  RGE_Action_List::rehook((RGE_Action_List *)this->_padding_);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0045a910
/* public: virtual void __thiscall RGE_Missile_Object::save(int) */

void __thiscall RGE_Missile_Object::save(RGE_Missile_Object *this,int param_1)
{
  RGE_Combat_Object::save((RGE_Combat_Object *)this,param_1);
  rge_write(param_1,&this->max_range,4);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 0045a940
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Missile_Object::update(void) */

uchar __thiscall RGE_Missile_Object::update(RGE_Missile_Object *this)
{
  ulong *puVar1;
  ulong *puVar2;
  bool bVar3;
  float fVar4;
  uchar uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  
  if ((_DAT_0056f4a8 < (float)this->_padding_) &&
     (fVar4 = (float)this->_padding_ - *(float *)(*(int *)(this->_padding_ + 0x3c) + 0x84),
     bVar3 = fVar4 < _DAT_0056f4a8, this->_padding_ = (int)fVar4, bVar3)) {
    this->_padding_ = 0;
  }
  uVar5 = RGE_Action_Object::update((RGE_Action_Object *)this);
  iVar8 = this->_padding_;
  if ((-1 < iVar8) && (this->_padding_ == 0)) {
    iVar6 = __ftol();
    iVar7 = __ftol();
    puVar1 = (ulong *)this->_padding_;
    puVar2 = (&unified_map_offsets)[iVar7][iVar6];
    this->_padding_ = (int)puVar2;
    if (puVar2 != puVar1) {
      Visible_Unit_Manager::Update_Unit_Info
                (VisibleUnitManager,iVar8,(int)*(short *)(this->_padding_ + 0x4a),iVar6,iVar7,
                 (int)*(short *)(this->_padding_ + 0x14),(ulong)puVar1,(ulong)puVar2,
                 (VISIBLE_UNIT_REC **)&this->_padding_);
      if ((char)this->_padding_ != '\0') {
        iVar6 = 1;
        iVar8 = *(int *)(this->_padding_ + 0x3c);
        iVar7 = (int)*(short *)(iVar8 + 0x3c);
        if (1 < iVar7) {
          do {
            if ((iVar6 != *(short *)(this->_padding_ + 0x4a)) &&
               (((uint)puVar2 & 1 << ((byte)iVar6 & 0x1f)) != 0)) goto LAB_00430784;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar7);
        }
        iVar6 = -1;
LAB_00430784:
        if (-1 < iVar6) {
          iVar8 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar8 + 0x40) + iVar6 * 4));
          if (iVar8 == 0) {
            (**(code **)(this->_padding_ + 0x44))
                      (*(undefined4 *)
                        (*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x40) + iVar6 * 4));
            if ((char)this->_padding_ == '\x01') {
              *(undefined1 *)&this->_padding_ = 0;
            }
          }
        }
      }
    }
  }
  if (this->_padding_ != 0) {
    iVar8 = RGE_Game_World::is_player_turn
                      (*(RGE_Game_World **)(this->_padding_ + 0x3c),
                       (int)*(short *)(this->_padding_ + 0x4a));
    if (iVar8 != 0) {
      uVar9 = RGE_Game_World::get_accum_time_delta
                        (*(RGE_Game_World **)(this->_padding_ + 0x3c),
                         (int)*(short *)(this->_padding_ + 0x4a));
      UnitAIModule::update((UnitAIModule *)this->_padding_,uVar9);
    }
  }
  return uVar5;
}

// --------------------------------------------------

// Function: init_missile
// Address: 0045a950
/* public: void __thiscall RGE_Missile_Object::init_missile(class RGE_Combat_Object *,class
   RGE_Static_Object *,float) */

void __thiscall
RGE_Missile_Object::init_missile
          (RGE_Missile_Object *this,RGE_Combat_Object *param_1,RGE_Static_Object *param_2,
          float param_3)
{
  RGE_Action_Missile *this_00;
  RGE_Action *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dbab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Action_Missile *)operator_new(0x54);
  local_4 = 0;
  if (this_00 == (RGE_Action_Missile *)0x0) {
    pRVar1 = (RGE_Action *)0x0;
  }
  else {
    pRVar1 = (RGE_Action *)
             RGE_Action_Missile::RGE_Action_Missile
                       (this_00,(RGE_Action_Object *)this,(RGE_Static_Object *)param_1,param_2,
                        param_2->world_x,param_2->world_y,param_2->world_z);
  }
  local_4 = 0xffffffff;
  if (pRVar1 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar1);
  }
  this->max_range = param_3;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: init_missile
// Address: 0045a9e0
/* public: void __thiscall RGE_Missile_Object::init_missile(class RGE_Combat_Object
   *,float,float,float,float) */

void __thiscall
RGE_Missile_Object::init_missile
          (RGE_Missile_Object *this,RGE_Combat_Object *param_1,float param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action_Missile *this_00;
  RGE_Action *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dbcb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Action_Missile *)operator_new(0x54);
  local_4 = 0;
  if (this_00 == (RGE_Action_Missile *)0x0) {
    pRVar1 = (RGE_Action *)0x0;
  }
  else {
    pRVar1 = (RGE_Action *)
             RGE_Action_Missile::RGE_Action_Missile
                       (this_00,(RGE_Action_Object *)this,(RGE_Static_Object *)param_1,
                        (RGE_Static_Object *)0x0,param_2,param_3,param_4);
  }
  local_4 = 0xffffffff;
  if (pRVar1 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar1);
  }
  this->max_range = param_5;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: missile_move
// Address: 0045aa70
/* WARNING: Variable defined which should be unmapped: new_y */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: unsigned char __thiscall RGE_Missile_Object::missile_move(void) */

uchar __thiscall RGE_Missile_Object::missile_move(RGE_Missile_Object *this)
{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float new_y;
  float new_x;
  float new_z;
  
  fVar5 = (float)this->_padding_ + (float)this->_padding_;
  fVar1 = (float)this->_padding_;
  fVar4 = (float)this->_padding_ + (float)this->_padding_;
  fVar2 = (float)this->_padding_;
  if ((((fVar5 < _DAT_00570934) ||
       (iVar3 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28),
       (float)*(int *)(iVar3 + 8) <= fVar5)) || (fVar4 < _DAT_00570934)) ||
     ((float)*(int *)(iVar3 + 0xc) <= fVar4)) {
    (**(code **)(this->_padding_ + 0x6c))();
  }
  fVar6 = (float10)(**(code **)(this->_padding_ + 0x34))(fVar5,fVar4,fVar1 + fVar2);
  if (fVar6 == (float10)(float)this->_padding_) {
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: make_object_collision_list
// Address: 0045ab20
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class RGE_Check_List * __thiscall RGE_Missile_Object::make_object_collision_list(float)
    */

RGE_Check_List * __thiscall
RGE_Missile_Object::make_object_collision_list(RGE_Missile_Object *this,float param_1)
{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  RGE_Missile_Object *pRVar5;
  RGE_Master_Static_Object *pRVar6;
  float fVar7;
  float fVar8;
  short sVar9;
  short sVar10;
  RGE_Check_List *this_00;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *unaff_FS_OFFSET;
  short x2;
  short x1;
  short local_40;
  float rx2;
  float ry2;
  float ry;
  float dy;
  RGE_Map *map;
  RGE_Check_List *check_list;
  RGE_Check_List *local_20;
  float rx;
  float dx;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dbeb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  fVar1 = *(float *)(this->_padding_ + 0x30);
  fVar2 = *(float *)(this->_padding_ + 0x34);
  if ((fVar1 <= _DAT_00570934) || (fVar2 <= _DAT_00570934)) {
    _x2 = (RGE_Check_List *)0x0;
  }
  else {
    local_40 = __ftol();
    sVar9 = __ftol();
    x1 = __ftol();
    sVar10 = __ftol();
    iVar3 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28);
    this_00 = (RGE_Check_List *)operator_new(4);
    local_4 = 0;
    if (this_00 == (RGE_Check_List *)0x0) {
      _x2 = (RGE_Check_List *)0x0;
    }
    else {
      _x2 = (RGE_Check_List *)RGE_Check_List::RGE_Check_List(this_00);
    }
    local_4 = 0xffffffff;
    if (local_40 < 0) {
      local_40 = 0;
    }
    if (*(int *)(iVar3 + 8) <= (int)x1) {
      x1 = *(short *)(iVar3 + 8) + -1;
    }
    if (sVar9 < 0) {
      sVar9 = 0;
    }
    if (*(int *)(iVar3 + 0xc) <= (int)sVar10) {
      sVar10 = *(short *)(iVar3 + 0xc) + -1;
    }
    if (sVar9 <= sVar10) {
      rx2 = (float)(sVar9 * 4);
      check_list = (RGE_Check_List *)(((int)sVar10 - (int)sVar9) + 1);
      do {
        if (local_40 <= x1) {
          puVar12 = (undefined4 *)
                    (*(int *)((int)rx2 + *(int *)(iVar3 + 0x8d8c)) + local_40 * 0x18 + 0x10);
          iVar11 = ((int)x1 - (int)local_40) + 1;
          do {
            for (puVar4 = (undefined4 *)*puVar12; puVar4 != (undefined4 *)0x0;
                puVar4 = (undefined4 *)puVar4[1]) {
              pRVar5 = (RGE_Missile_Object *)*puVar4;
              if (pRVar5 != this) {
                pRVar6 = (RGE_Master_Static_Object *)pRVar5->_padding_;
                if ((((_DAT_00570934 < pRVar6->radius_y) && (_DAT_00570934 < pRVar6->radius_x)) &&
                    (fVar7 = (float)pRVar5->_padding_ - (float)this->_padding_,
                    -(pRVar6->radius_z - _DAT_00570940) <= fVar7)) &&
                   (fVar7 <= *(float *)(this->_padding_ + 0x38) - _DAT_00570940)) {
                  fVar7 = (float)pRVar5->_padding_ - (float)this->_padding_;
                  fVar8 = (float)pRVar5->_padding_ - (float)this->_padding_;
                  if (fVar7 < _DAT_00570934) {
                    fVar7 = -fVar7;
                  }
                  if (fVar8 < _DAT_00570934) {
                    fVar8 = -fVar8;
                  }
                  fVar7 = fVar7 - (pRVar6->radius_x + fVar1 + param_1);
                  fVar8 = fVar8 - (pRVar6->radius_y + fVar2 + param_1);
                  if ((fVar7 <= _DAT_00570934) && (fVar8 <= _DAT_00570934)) {
                    RGE_Check_List::add_node(_x2,(RGE_Static_Object *)pRVar5,fVar7,fVar8,'\0');
                  }
                }
              }
            }
            puVar12 = puVar12 + 6;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
        rx2 = (float)((int)rx2 + 4);
        check_list = (RGE_Check_List *)((int)&check_list[-1].list + 3);
      } while (check_list != (RGE_Check_List *)0x0);
    }
    if (_x2->list == (RGE_Check_Node *)0x0) {
      if (_x2 != (RGE_Check_List *)0x0) {
        RGE_Check_List::~RGE_Check_List(_x2);
        operator_delete(_x2);
      }
      local_20 = (RGE_Check_List *)0x0;
      _x2 = local_20;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return _x2;
}

// --------------------------------------------------

