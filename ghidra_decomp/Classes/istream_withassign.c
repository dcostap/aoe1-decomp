// Class: istream_withassign
// Size:  0x1
//
// VTable Layout:
// [00] `vector_deleting_destructor'
//
// Member Layout:
// ----------------------------------------------------------------

// Function: istream_withassign
// Address: 0055b990
/* public: __thiscall istream_withassign::istream_withassign(void) */

istream_withassign * __thiscall istream_withassign::istream_withassign(istream_withassign *this)
{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000004;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00562026;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (in_stack_00000004 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)(this + 0xc));
    local_4 = 0;
  }
  istream::istream((istream *)this);
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) = &_vftable_;
  *unaff_FS_OFFSET = this;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0055ba10
/* public: virtual void * __thiscall istream_withassign::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
istream_withassign::_vector_deleting_destructor_(istream_withassign *this,uint param_1)
{
  ~istream_withassign(this);
  ios::~ios((ios *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this + -0xc);
  }
  return this + -0xc;
}

// --------------------------------------------------

// Function: istream_withassign
// Address: 0055ba40
/* public: __thiscall istream_withassign::istream_withassign(class streambuf *) */

istream_withassign * __thiscall
istream_withassign::istream_withassign(istream_withassign *this,streambuf *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00562046;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)(this + 0xc));
    local_4 = 0;
  }
  istream::istream((istream *)this,param_1);
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) = &_vftable_;
  *unaff_FS_OFFSET = this;
  return this;
}

// --------------------------------------------------

// Function: ~istream_withassign
// Address: 0055bac0
/* public: virtual __thiscall istream_withassign::~istream_withassign(void) */

void __thiscall istream_withassign::~istream_withassign(istream_withassign *this)
{
  *(undefined ***)(this + *(int *)(*(int *)(this + -0xc) + 4) + -0xc) = &_vftable_;
  istream::~istream((istream *)this);
  return;
}

// --------------------------------------------------

