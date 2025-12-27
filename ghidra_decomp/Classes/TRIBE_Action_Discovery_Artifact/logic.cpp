// Class: TRIBE_Action_Discovery_Artifact
// Function: TRIBE_Action_Discovery_Artifact
// Address: 004ce530
/* public: __thiscall TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(int,class
   RGE_Action_Object *) */

TRIBE_Action_Discovery_Artifact * __thiscall
TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact
          (TRIBE_Action_Discovery_Artifact *this,int param_1,RGE_Action_Object *param_2)
{
  uchar *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe28;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x6c;
  local_4 = 0;
  puVar1 = (uchar *)calloc((int)*(short *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x3c),
                           1);
  this->flags = puVar1;
  rge_read(param_1,puVar1,(int)*(short *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x3c));
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004ce5c0
/* public: virtual void * __thiscall TRIBE_Action_Discovery_Artifact::`vector deleting
   destructor'(unsigned int) */

void * __thiscall
TRIBE_Action_Discovery_Artifact::_vector_deleting_destructor_
          (TRIBE_Action_Discovery_Artifact *this,uint param_1)
{
  ~TRIBE_Action_Discovery_Artifact(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Discovery_Artifact
// Address: 004ce5e0
/* public: virtual __thiscall
   TRIBE_Action_Discovery_Artifact::~TRIBE_Action_Discovery_Artifact(void) */

void __thiscall
TRIBE_Action_Discovery_Artifact::~TRIBE_Action_Discovery_Artifact
          (TRIBE_Action_Discovery_Artifact *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&RGE_Action::_vftable_;
  RGE_Action::set_target_obj((RGE_Action *)this,(RGE_Static_Object *)0x0);
  RGE_Action::set_target_obj2((RGE_Action *)this,(RGE_Static_Object *)0x0);
  this_00 = (RGE_Action_List *)this->_padding_;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->_padding_ = 0;
  }
  return;
}

// --------------------------------------------------

// Function: TRIBE_Action_Discovery_Artifact
// Address: 004ce5f0
/* public: __thiscall TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(class
   RGE_Action_Object *,class RGE_Task *,class RGE_Static_Object *) */

TRIBE_Action_Discovery_Artifact * __thiscall
TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact
          (TRIBE_Action_Discovery_Artifact *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          RGE_Static_Object *param_3)
{
  uchar *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe48;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x6c;
  RGE_Action::set_target_obj((RGE_Action *)this,param_3);
  puVar1 = (uchar *)calloc((int)*(short *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x3c),
                           1);
  this->flags = puVar1;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Discovery_Artifact
// Address: 004ce670
/* public: __thiscall TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(class
   RGE_Action_Object *,class RGE_Task *,float,float,float) */

TRIBE_Action_Discovery_Artifact * __thiscall
TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact
          (TRIBE_Action_Discovery_Artifact *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          float param_3,float param_4,float param_5)
{
  uchar *puVar1;
  
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  this->_padding_ = (int)param_3;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x6c;
  this->_padding_ = (int)param_4;
  this->_padding_ = (int)param_5;
  puVar1 = (uchar *)calloc((int)*(short *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x3c),
                           1);
  this->flags = puVar1;
  return this;
}

// --------------------------------------------------

// Function: save
// Address: 004ce6d0
/* public: virtual void __thiscall TRIBE_Action_Discovery_Artifact::save(int) */

void __thiscall
TRIBE_Action_Discovery_Artifact::save(TRIBE_Action_Discovery_Artifact *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,this->flags,
            (int)*(short *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x3c));
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004ce700
/* public: virtual void __thiscall TRIBE_Action_Discovery_Artifact::first_in_stack(unsigned char) */

void __thiscall
TRIBE_Action_Discovery_Artifact::first_in_stack(TRIBE_Action_Discovery_Artifact *this,uchar param_1)
{
  if (param_1 != '\0') {
    (**(code **)(this->_padding_ + 0x5c))(6);
  }
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004ce720
/* protected: virtual void __thiscall TRIBE_Action_Discovery_Artifact::set_state(unsigned char) */

void __thiscall
TRIBE_Action_Discovery_Artifact::set_state(TRIBE_Action_Discovery_Artifact *this,uchar param_1)
{
  *(uchar *)&this->_padding_ = param_1;
  if (param_1 == '\n') {
    this->_padding_ = 0x40400000;
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004ce740
/* public: virtual unsigned char __thiscall TRIBE_Action_Discovery_Artifact::update(void) */

uchar __thiscall TRIBE_Action_Discovery_Artifact::update(TRIBE_Action_Discovery_Artifact *this)
{
  char cVar1;
  float fVar2;
  float fVar3;
  
  cVar1 = (char)this->_padding_;
  if (cVar1 == '\x01') {
    return '\x01';
  }
  if (cVar1 == '\x06') {
    check_objects(this);
    (**(code **)(this->_padding_ + 0x5c))(10);
  }
  else if ((cVar1 == '\n') &&
          (fVar2 = (float)this->_padding_ -
                   *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84),
          fVar3 = (float)(double)DAT_00575070, this->_padding_ = (int)fVar2, fVar2 <= fVar3)) {
    (**(code **)(this->_padding_ + 0x5c))(6);
    return '\0';
  }
  return '\0';
}

// --------------------------------------------------

// Function: check_objects
// Address: 004ce7a0
/* WARNING: Variable defined which should be unmapped: x0 */
/* protected: void __thiscall TRIBE_Action_Discovery_Artifact::check_objects(void) */

void __thiscall
TRIBE_Action_Discovery_Artifact::check_objects(TRIBE_Action_Discovery_Artifact *this)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  short x0;
  short x1;
  short local_18;
  int local_14;
  int local_c;
  RGE_Map *map;
  
  iVar1 = this->_padding_;
  x1 = __ftol();
  sVar4 = __ftol();
  local_18 = __ftol();
  sVar5 = __ftol();
  iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0xc) + 0x3c) + 0x28);
  if (x1 < 0) {
    x1 = 0;
  }
  if (sVar4 < 0) {
    sVar4 = 0;
  }
  if (*(int *)(iVar1 + 8) <= (int)local_18) {
    local_18 = *(short *)(iVar1 + 8) + -1;
  }
  if (*(int *)(iVar1 + 0xc) <= (int)sVar5) {
    sVar5 = *(short *)(iVar1 + 0xc) + -1;
  }
  if (sVar4 <= sVar5) {
    local_14 = sVar4 * 4;
    local_c = ((int)sVar5 - (int)sVar4) + 1;
    do {
      if (x1 <= local_18) {
        iVar7 = x1 * 0x18;
        iVar6 = ((int)local_18 - (int)x1) + 1;
        do {
          for (piVar2 = *(int **)(*(int *)(local_14 + *(int *)(iVar1 + 0x8d8c)) + 0x10 + iVar7);
              piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
            if ((*(int *)(*piVar2 + 0xc) != *(int *)(this->_padding_ + 0xc)) &&
               (this->flags[*(short *)(*(int *)(*piVar2 + 0xc) + 0x4a)] == '\0')) {
              this->flags[*(short *)(*(int *)(*piVar2 + 0xc) + 0x4a)] = '\x01';
              iVar3 = *piVar2;
              (**(code **)(**(int **)(*(int *)(*(int *)(iVar3 + 0xc) + 0x24) + 0x288) + 0x18))
                        (*(int *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x38),
                         *(undefined4 *)(iVar3 + 0x3c),*(undefined4 *)(iVar3 + 0x40));
            }
          }
          iVar7 = iVar7 + 0x18;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      local_14 = local_14 + 4;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  return;
}

// --------------------------------------------------

