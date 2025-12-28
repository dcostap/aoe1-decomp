// Class: ostream_withassign
// Size:  0x1
//
// VTable Layout:
// [00] `vector_deleting_destructor'
//
// Member Layout:
// ----------------------------------------------------------------

// Function: ostream_withassign
// Address: 0055aae0
/* public: __thiscall ostream_withassign::ostream_withassign(void) */

ostream_withassign * __thiscall ostream_withassign::ostream_withassign(ostream_withassign *this)
{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000004;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561f66;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (in_stack_00000004 != 0) {
    *(undefined8 **)this = &_vbtable_;
    ios::ios((ios *)(this + 8));
    local_4 = 0;
  }
  ostream::ostream((ostream *)this);
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) = &_vftable_;
  *unaff_FS_OFFSET = this;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0055ab60
/* public: virtual void * __thiscall ostream_withassign::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
ostream_withassign::_vector_deleting_destructor_(ostream_withassign *this,uint param_1)
{
  ~ostream_withassign(this);
  ios::~ios((ios *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this + -8);
  }
  return this + -8;
}

// --------------------------------------------------

// Function: ostream_withassign
// Address: 0055ab90
/* public: __thiscall ostream_withassign::ostream_withassign(class streambuf *) */

ostream_withassign * __thiscall
ostream_withassign::ostream_withassign(ostream_withassign *this,streambuf *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561f86;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (in_stack_00000008 != 0) {
    *(undefined8 **)this = &_vbtable_;
    ios::ios((ios *)(this + 8));
    local_4 = 0;
  }
  ostream::ostream((ostream *)this,param_1);
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) = &_vftable_;
  *unaff_FS_OFFSET = this;
  return this;
}

// --------------------------------------------------

// Function: ~ostream_withassign
// Address: 0055ac10
/* public: virtual __thiscall ostream_withassign::~ostream_withassign(void) */

void __thiscall ostream_withassign::~ostream_withassign(ostream_withassign *this)
{
  *(undefined ***)(this + *(int *)(*(int *)(this + -8) + 4) + -8) = &_vftable_;
  ostream::~ostream((ostream *)this);
  return;
}

// --------------------------------------------------

