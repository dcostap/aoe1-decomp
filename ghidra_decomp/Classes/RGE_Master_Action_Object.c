// Class: RGE_Master_Action_Object
// Size:  0xFC
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] copy_obj
// [02] modify
// [03] modify_delta
// [04] modify_percent
// [05] save
// [06] make_new_obj
// [07] make_new_master
// [08] check_placement
// [09] alignment
// [10] calc_base_damage_ability
// [11] play_command_sound
// [12] play_move_sound
// [13] draw
// [14] create_task_list
//
// Member Layout:
// [0x0D8] RGE_Task_List * tasks
// [0x0DC] short default_task
// [0x0E0] float search_radius
// [0x0E4] float work_rate
// [0x0E8] short drop_site
// [0x0EA] short backup_drop_site
// [0x0EC] uchar task_by_group
// [0x0F0] RGE_Sound * command_sound
// [0x0F4] RGE_Sound * move_sound
// [0x0F8] uchar run_pattern
// ----------------------------------------------------------------

// Function: RGE_Master_Action_Object
// Address: 0044f070
/* public: __thiscall RGE_Master_Action_Object::RGE_Master_Action_Object(class
   RGE_Master_Action_Object *,int) */

RGE_Master_Action_Object * __thiscall
RGE_Master_Action_Object::RGE_Master_Action_Object
          (RGE_Master_Action_Object *this,RGE_Master_Action_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d638;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Moving_Object::RGE_Master_Moving_Object
            ((RGE_Master_Moving_Object *)this,(RGE_Master_Moving_Object *)param_1,0);
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
// Address: 0044f0d0
/* public: virtual void * __thiscall RGE_Master_Action_Object::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
RGE_Master_Action_Object::_vector_deleting_destructor_(RGE_Master_Action_Object *this,uint param_1)
{
  ~RGE_Master_Action_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Action_Object
// Address: 0044f0f0
/* public: __thiscall RGE_Master_Action_Object::RGE_Master_Action_Object(int,class RGE_Sprite *
   *,class RGE_Sound * *,int) */

RGE_Master_Action_Object * __thiscall
RGE_Master_Action_Object::RGE_Master_Action_Object
          (RGE_Master_Action_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d658;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Moving_Object::RGE_Master_Moving_Object
            ((RGE_Master_Moving_Object *)this,param_1,param_2,param_3,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_4 != 0) {
    setup(this,param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Action_Object
// Address: 0044f160
/* public: __thiscall RGE_Master_Action_Object::RGE_Master_Action_Object(struct _iobuf *,class
   RGE_Sprite * *,class RGE_Sound * *,short,int) */

RGE_Master_Action_Object * __thiscall
RGE_Master_Action_Object::RGE_Master_Action_Object
          (RGE_Master_Action_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d678;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Moving_Object::RGE_Master_Moving_Object
            ((RGE_Master_Moving_Object *)this,param_1,param_2,param_3,param_4,0);
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
// Address: 0044f1e0
/* protected: int __thiscall RGE_Master_Action_Object::setup(class RGE_Master_Action_Object *) */

int __thiscall
RGE_Master_Action_Object::setup(RGE_Master_Action_Object *this,RGE_Master_Action_Object *param_1)
{
  RGE_Task_List *this_00;
  
  RGE_Master_Moving_Object::setup
            ((RGE_Master_Moving_Object *)this,(RGE_Master_Moving_Object *)param_1);
  *(undefined1 *)&this->_padding_ = 0x28;
  this->default_task = param_1->default_task;
  this->search_radius = param_1->search_radius;
  this->work_rate = param_1->work_rate;
  this->drop_site = param_1->drop_site;
  this->backup_drop_site = param_1->backup_drop_site;
  this->task_by_group = param_1->task_by_group;
  this->command_sound = param_1->command_sound;
  this->move_sound = param_1->move_sound;
  this->run_pattern = param_1->run_pattern;
  this_00 = (RGE_Task_List *)(**(code **)(this->_padding_ + 0x38))();
  this->tasks = this_00;
  RGE_Task_List::copy(this_00,param_1->tasks);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0044f290
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: int __thiscall RGE_Master_Action_Object::setup(int,class RGE_Sprite * *,class
   RGE_Sound * *) */

int __thiscall
RGE_Master_Action_Object::setup
          (RGE_Master_Action_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  RGE_Sprite **ppRVar1;
  RGE_Sound **ppRVar2;
  RGE_Sound *pRVar3;
  RGE_Task_List *this_00;
  
  ppRVar2 = param_3;
  ppRVar1 = param_2;
  RGE_Master_Moving_Object::setup((RGE_Master_Moving_Object *)this,param_1,param_2,param_3);
  *(undefined1 *)&this->_padding_ = 0x28;
  rge_read(param_1,&this->default_task,2);
  rge_read(param_1,&this->search_radius,4);
  rge_read(param_1,&this->work_rate,4);
  rge_read(param_1,&this->drop_site,2);
  rge_read(param_1,&this->backup_drop_site,2);
  rge_read(param_1,&this->task_by_group,1);
  rge_read(param_1,&param_3,2);
  if (save_game_version < _DAT_00570484) {
    param_2 = (RGE_Sprite **)param_3;
  }
  else {
    rge_read(param_1,&param_2,2);
  }
  rge_read(param_1,&this->run_pattern,1);
  if ((short)param_3 < 0) {
    pRVar3 = (RGE_Sound *)0x0;
  }
  else {
    pRVar3 = ppRVar2[(short)param_3];
  }
  this->command_sound = pRVar3;
  if ((short)param_2 < 0) {
    pRVar3 = (RGE_Sound *)0x0;
  }
  else {
    pRVar3 = ppRVar2[(short)param_2];
  }
  this->move_sound = pRVar3;
  this_00 = (RGE_Task_List *)(**(code **)(this->_padding_ + 0x38))();
  this->tasks = this_00;
  RGE_Task_List::load(this_00,param_1,ppRVar1,ppRVar2);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0044f3c0
// [HELPER] s__f__f__hd__hd__hd__hd__hd__hd: "%f %f %hd %hd %hd %hd %hd %hd"
/* protected: int __thiscall RGE_Master_Action_Object::setup(struct _iobuf *,class RGE_Sprite *
   *,class RGE_Sound * *,short) */

int __thiscall
RGE_Master_Action_Object::setup
          (RGE_Master_Action_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4)
{
  _iobuf *p_Var1;
  RGE_Sprite **ppRVar2;
  RGE_Sound **ppRVar3;
  RGE_Sound *pRVar4;
  RGE_Task_List *this_00;
  int iVar5;
  int iVar6;
  RGE_Task **ppRVar7;
  undefined2 in_stack_00000012;
  
  ppRVar3 = param_3;
  ppRVar2 = param_2;
  p_Var1 = param_1;
  RGE_Master_Moving_Object::setup((RGE_Master_Moving_Object *)this,param_1,param_2,param_3,param_4);
  *(undefined1 *)&this->_padding_ = 0x28;
  fscanf(p_Var1,s__f__f__hd__hd__hd__hd__hd__hd,&this->search_radius,&this->work_rate,
         &this->drop_site,&this->backup_drop_site,&param_4,&param_2,&param_1,&param_3);
  this->task_by_group = (uchar)param_4;
  this->run_pattern = (uchar)param_3;
  if ((short)param_2 < 0) {
    pRVar4 = (RGE_Sound *)0x0;
  }
  else {
    pRVar4 = ppRVar3[(short)param_2];
  }
  this->command_sound = pRVar4;
  if ((short)param_1 < 0) {
    pRVar4 = (RGE_Sound *)0x0;
  }
  else {
    pRVar4 = ppRVar3[(short)param_1];
  }
  this->move_sound = pRVar4;
  this_00 = (RGE_Task_List *)(**(code **)(this->_padding_ + 0x38))();
  this->tasks = this_00;
  RGE_Task_List::load(this_00,p_Var1,ppRVar2,ppRVar3);
  this->default_task = -1;
  iVar5 = 0;
  iVar6 = (int)this->tasks->list_num;
  if (0 < iVar6) {
    ppRVar7 = this->tasks->list;
    while ((*ppRVar7)->is_default == '\0') {
      iVar5 = iVar5 + 1;
      ppRVar7 = ppRVar7 + 1;
      if (iVar6 <= iVar5) {
        return 1;
      }
    }
    this->default_task = (short)iVar5;
  }
  return 1;
}

// --------------------------------------------------

// Function: ~RGE_Master_Action_Object
// Address: 0044f4d0
/* public: virtual __thiscall RGE_Master_Action_Object::~RGE_Master_Action_Object(void) */

void __thiscall RGE_Master_Action_Object::~RGE_Master_Action_Object(RGE_Master_Action_Object *this)
{
  RGE_Task_List *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055d698;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  this_00 = this->tasks;
  local_4 = 0;
  if (this_00 != (RGE_Task_List *)0x0) {
    RGE_Task_List::~RGE_Task_List(this_00);
    operator_delete(this_00);
    this->tasks = (RGE_Task_List *)0x0;
  }
  local_4 = 0xffffffff;
  RGE_Master_Moving_Object::~RGE_Master_Moving_Object((RGE_Master_Moving_Object *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: create_task_list
// Address: 0044f540
/* public: virtual class RGE_Task_List * __thiscall RGE_Master_Action_Object::create_task_list(void)
    */

RGE_Task_List * __thiscall
RGE_Master_Action_Object::create_task_list(RGE_Master_Action_Object *this)
{
  RGE_Task_List *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d6bb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Task_List *)operator_new(0xc);
  local_4 = 0;
  if (pRVar1 != (RGE_Task_List *)0x0) {
    pRVar1 = (RGE_Task_List *)RGE_Task_List::RGE_Task_List(pRVar1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Task_List *)0x0;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 0044f5a0
/* public: virtual class RGE_Static_Object * __thiscall RGE_Master_Action_Object::make_new_obj(class
   RGE_Player *,float,float,float) */

RGE_Static_Object * __thiscall
RGE_Master_Action_Object::make_new_obj
          (RGE_Master_Action_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4)
{
  RGE_Static_Object *pRVar1;
  RGE_Action_Object *this_00;
  float *unaff_FS_OFFSET;
  float local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d6db;
  *unaff_FS_OFFSET = (float)&local_c;
  if ((char)this->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_1->world,(uchar)this->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(this,param_1,param_2,param_3,param_4);
      *unaff_FS_OFFSET = param_3;
      return pRVar1;
    }
  }
  this_00 = (RGE_Action_Object *)operator_new(0x194);
  local_4 = 0;
  if (this_00 != (RGE_Action_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Action_Object::RGE_Action_Object(this_00,this,param_1,param_2,param_3,param_4,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 0044f670
/* public: virtual class RGE_Master_Static_Object * __thiscall
   RGE_Master_Action_Object::make_new_master(void) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Action_Object::make_new_master(RGE_Master_Action_Object *this)
{
  RGE_Master_Action_Object *this_00;
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d6fb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Master_Action_Object *)operator_new(0xfc);
  local_4 = 0;
  if (this_00 != (RGE_Master_Action_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)RGE_Master_Action_Object(this_00,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: get_task
// Address: 0044f6e0
/* public: class RGE_Task * __thiscall RGE_Master_Action_Object::get_task(short) */

RGE_Task * __thiscall
RGE_Master_Action_Object::get_task(RGE_Master_Action_Object *this,short param_1)
{
  if ((param_1 != -1) && (param_1 < this->tasks->list_num)) {
    return this->tasks->list[param_1];
  }
  return (RGE_Task *)0x0;
}

// --------------------------------------------------

// Function: getTaskByTaskID
// Address: 0044f710
/* public: class RGE_Task * __thiscall RGE_Master_Action_Object::getTaskByTaskID(int)const  */

RGE_Task * __thiscall
RGE_Master_Action_Object::getTaskByTaskID(RGE_Master_Action_Object *this,int param_1)
{
  RGE_Task **ppRVar1;
  int iVar2;
  RGE_Task **ppRVar3;
  int iVar4;
  
  if (param_1 != -1) {
    iVar2 = 0;
    iVar4 = (int)this->tasks->list_num;
    if (0 < iVar4) {
      ppRVar1 = this->tasks->list;
      ppRVar3 = ppRVar1;
      do {
        if (param_1 == (*ppRVar3)->action_type) {
          return ppRVar1[iVar2];
        }
        iVar2 = iVar2 + 1;
        ppRVar3 = ppRVar3 + 1;
      } while (iVar2 < iVar4);
      return (RGE_Task *)0x0;
    }
  }
  return (RGE_Task *)0x0;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 0044f760
/* public: virtual void __thiscall RGE_Master_Action_Object::copy_obj(class RGE_Master_Static_Object
   *) */

void __thiscall
RGE_Master_Action_Object::copy_obj(RGE_Master_Action_Object *this,RGE_Master_Static_Object *param_1)
{
  RGE_Master_Moving_Object::copy_obj((RGE_Master_Moving_Object *)this,param_1);
  this->default_task = *(short *)&param_1[1].undead_flag;
  this->search_radius = param_1[1].los;
  this->work_rate = *(float *)&param_1[1].obj_max;
  this->drop_site = *(short *)&param_1[1].radius_x;
  this->backup_drop_site = *(short *)((int)&param_1[1].radius_x + 2);
  this->task_by_group = *(uchar *)&param_1[1].radius_y;
  this->command_sound = (RGE_Sound *)param_1[1].radius_z;
  this->move_sound = param_1[1].selected_sound;
  RGE_Task_List::copy(this->tasks,(RGE_Task_List *)param_1[1].undead_sprite);
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 0044f7f0
/* public: virtual void __thiscall RGE_Master_Action_Object::modify(float,unsigned char) */

void __thiscall
RGE_Master_Action_Object::modify(RGE_Master_Action_Object *this,float param_1,uchar param_2)
{
  if (param_2 != '\r') {
    RGE_Master_Moving_Object::modify((RGE_Master_Moving_Object *)this,param_1,param_2);
    return;
  }
  this->work_rate = param_1;
  return;
}

// --------------------------------------------------

// Function: modify_delta
// Address: 0044f820
/* public: virtual void __thiscall RGE_Master_Action_Object::modify_delta(float,unsigned char) */

void __thiscall
RGE_Master_Action_Object::modify_delta(RGE_Master_Action_Object *this,float param_1,uchar param_2)
{
  if (param_2 != '\r') {
    RGE_Master_Moving_Object::modify_delta((RGE_Master_Moving_Object *)this,param_1,param_2);
    return;
  }
  this->work_rate = param_1 + this->work_rate;
  return;
}

// --------------------------------------------------

// Function: modify_percent
// Address: 0044f850
/* public: virtual void __thiscall RGE_Master_Action_Object::modify_percent(float,unsigned char) */

void __thiscall
RGE_Master_Action_Object::modify_percent(RGE_Master_Action_Object *this,float param_1,uchar param_2)
{
  if (param_2 != '\r') {
    RGE_Master_Moving_Object::modify_percent((RGE_Master_Moving_Object *)this,param_1,param_2);
    return;
  }
  this->work_rate = param_1 * this->work_rate;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0044f880
/* WARNING: Variable defined which should be unmapped: command_sound_num */
/* public: virtual void __thiscall RGE_Master_Action_Object::save(int) */

void __thiscall RGE_Master_Action_Object::save(RGE_Master_Action_Object *this,int param_1)
{
  RGE_Sound *pRVar1;
  undefined2 extraout_var;
  short command_sound_num;
  short move_sound_num;
  undefined4 local_4;
  
  _move_sound_num = 0xffffffff;
  local_4 = 0xffffffff;
  RGE_Master_Moving_Object::save((RGE_Master_Moving_Object *)this,param_1);
  pRVar1 = this->command_sound;
  if (pRVar1 != (RGE_Sound *)0x0) {
    _move_sound_num = CONCAT22((short)((uint)pRVar1 >> 0x10),pRVar1->id);
  }
  if (this->move_sound != (RGE_Sound *)0x0) {
    local_4 = CONCAT22(extraout_var,this->move_sound->id);
  }
  rge_write(param_1,&this->default_task,2);
  rge_write(param_1,&this->search_radius,4);
  rge_write(param_1,&this->work_rate,4);
  rge_write(param_1,&this->drop_site,2);
  rge_write(param_1,&this->backup_drop_site,2);
  rge_write(param_1,&this->task_by_group,1);
  rge_write(param_1,&move_sound_num,2);
  rge_write(param_1,&local_4,2);
  rge_write(param_1,&this->run_pattern,1);
  RGE_Task_List::save(this->tasks,param_1);
  return;
}

// --------------------------------------------------

// Function: play_command_sound
// Address: 0044f980
/* public: virtual void __thiscall RGE_Master_Action_Object::play_command_sound(void) */

void __thiscall RGE_Master_Action_Object::play_command_sound(RGE_Master_Action_Object *this)
{
  if (this->command_sound != (RGE_Sound *)0x0) {
    RGE_Sound::play(this->command_sound,1);
  }
  return;
}

// --------------------------------------------------

// Function: play_move_sound
// Address: 0044f9a0
/* public: virtual void __thiscall RGE_Master_Action_Object::play_move_sound(void) */

void __thiscall RGE_Master_Action_Object::play_move_sound(RGE_Master_Action_Object *this)
{
  if (this->move_sound != (RGE_Sound *)0x0) {
    RGE_Sound::play(this->move_sound,1);
  }
  return;
}

// --------------------------------------------------

