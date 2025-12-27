// Class: RGE_Action_Make
// Function: RGE_Action_Make
// Address: 004049b0
/* public: __thiscall RGE_Action_Make::RGE_Action_Make(int,class RGE_Action_Object *) */

RGE_Action_Make * __thiscall
RGE_Action_Make::RGE_Action_Make(RGE_Action_Make *this,int param_1,RGE_Action_Object *param_2)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 0x15;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004049e0
/* public: virtual void * __thiscall RGE_Action_Make::`vector deleting destructor'(unsigned int) */

void * __thiscall RGE_Action_Make::_vector_deleting_destructor_(RGE_Action_Make *this,uint param_1)
{
  ~RGE_Action_Make(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action_Make
// Address: 00404a00
/* public: virtual __thiscall RGE_Action_Make::~RGE_Action_Make(void) */

void __thiscall RGE_Action_Make::~RGE_Action_Make(RGE_Action_Make *this)
{
  RGE_Action_List *this_00;
  
  *(undefined ***)this = &RGE_Action::_vftable_;
  RGE_Action::set_target_obj((RGE_Action *)this,(RGE_Static_Object *)0x0);
  RGE_Action::set_target_obj2((RGE_Action *)this,(RGE_Static_Object *)0x0);
  this_00 = *(RGE_Action_List **)&this->field_0x34;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    *(undefined4 *)&this->field_0x34 = 0;
  }
  return;
}

// --------------------------------------------------

// Function: RGE_Action_Make
// Address: 00404a10
/* public: __thiscall RGE_Action_Make::RGE_Action_Make(class RGE_Action_Object *,class RGE_Task *)
    */

RGE_Action_Make * __thiscall
RGE_Action_Make::RGE_Action_Make(RGE_Action_Make *this,RGE_Action_Object *param_1,RGE_Task *param_2)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 0x15;
  *(RGE_Task **)&this->field_0x30 = param_2;
  return this;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 00404a40
/* public: virtual void __thiscall RGE_Action_Make::first_in_stack(unsigned char) */

void __thiscall RGE_Action_Make::first_in_stack(RGE_Action_Make *this,uchar param_1)
{
  short sVar1;
  undefined2 extraout_var;
  
  (**(code **)(*(int *)this + 0x5c))(6);
  sVar1 = *(short *)(*(int *)&this->field_0x30 + 0x14);
  if ((-1 < sVar1) && ((short)(*(int **)&this->field_0x8)[0x13] != sVar1)) {
    (**(code **)(**(int **)&this->field_0x8 + 0x80))(CONCAT22(extraout_var,sVar1),0);
  }
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 00404a70
/* protected: virtual void __thiscall RGE_Action_Make::set_state(unsigned char) */

void __thiscall RGE_Action_Make::set_state(RGE_Action_Make *this,uchar param_1)
{
  this->field_0xc = param_1;
  *(undefined4 *)&this->field_0x2c =
       *(undefined4 *)(*(int *)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x50) + 0x90);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00404a90
/* WARNING: Variable defined which should be unmapped: work */
/* public: virtual unsigned char __thiscall RGE_Action_Make::update(void) */

uchar __thiscall RGE_Action_Make::update(RGE_Action_Make *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  float fVar5;
  undefined4 uVar6;
  float unaff_EDI;
  float work;
  float pre_attribute;
  
  if (this->field_0xc == '\x01') {
    return '\x01';
  }
  if (this->field_0xc == '\x06') {
    if (*(float *)&this->field_0x2c <= (float)DAT_0056e318) {
      iVar1 = *(int *)&this->field_0x8;
      iVar2 = *(int *)(iVar1 + 0xc);
      if ((float)DAT_0056e318 < *(float *)(*(int *)(iVar2 + 0x50) + 0x90)) {
        if ((float)DAT_0056e318 < *(float *)(iVar1 + 0x44)) {
          return '\0';
        }
        iVar3 = rge_base_game->_padding_;
        uVar6 = __ftol();
        uVar6 = __ftol(uVar6);
                    /* language.dll match for 0x7e: "10" */
        (**(code **)(iVar3 + 0x40))
                  (0x7e,(int)*(short *)(iVar2 + 0x4a),*(undefined4 *)(iVar1 + 4),uVar6);
        (**(code **)(**(int **)&this->field_0x8 + 0x6c))();
        return '\0';
      }
    }
    piVar4 = *(int **)&this->field_0x8;
    iVar1 = *(int *)&this->field_0x30;
    fVar5 = *(float *)(piVar4[2] + 0xe4) * *(float *)(((int *)piVar4[3])[0xf] + 0x84) *
            *(float *)(iVar1 + 0x1c);
    if (*(short *)(iVar1 + 0x30) == 0) {
      (**(code **)(*piVar4 + 0x84))(fVar5,1,1);
    }
    else {
      (**(code **)(*(int *)piVar4[3] + 0x78))
                (CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x14)),fVar5,0);
    }
    *(float *)&this->field_0x2c =
         *(float *)&this->field_0x2c - (*(float *)(*(int *)&this->field_0x8 + 0x44) - unaff_EDI);
  }
  return '\0';
}

// --------------------------------------------------

