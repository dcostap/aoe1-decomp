// Class: istream
// Function: get
// Address: 0055ae30
/* protected: class istream & __thiscall istream::get(char *,int,int) */

istream * __thiscall istream::get(istream *this,char *param_1,int param_2,int param_3)
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = ipfx(this,1);
  if ((iVar1 != 0) && (param_2 != 0)) {
    if (param_2 != 1) {
      do {
        iVar1 = streambuf::sgetc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
        if (iVar1 == -1) {
          *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
               *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 1;
          if (uVar2 == 0) {
            *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
                 *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 2;
          }
          break;
        }
        if (iVar1 == param_3) {
          if (this->_fGline != 0) {
            this->x_gcount = this->x_gcount + 1;
            streambuf::stossc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
          }
          break;
        }
        if (param_1 != (char *)0x0) {
          param_1[uVar2] = (char)iVar1;
        }
        streambuf::stossc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_2 - 1U);
    }
    this->x_gcount = this->x_gcount + uVar2;
  }
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    param_1[uVar2] = '\0';
  }
  this->_fGline = 0;
  return this;
}

// --------------------------------------------------

// Function: istream
// Address: 0055b450
/* protected: __thiscall istream::istream(void) */

istream * __thiscall istream::istream(istream *this)
{
  int in_stack_00000004;
  
  if (in_stack_00000004 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0xc);
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) =
       *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) | 1;
  this->x_gcount = 0;
  this->_fGline = 0;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0055b4b0
/* public: virtual void * __thiscall istream::`scalar deleting destructor'(unsigned int) */

void * __thiscall istream::_scalar_deleting_destructor_(istream *this,uint param_1)
{
  ~istream(this);
  ios::~ios((ios *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(&this[-1].field_0x34);
  }
  return &this[-1].field_0x34;
}

// --------------------------------------------------

// Function: istream
// Address: 0055b4e0
/* public: __thiscall istream::istream(class streambuf *) */

istream * __thiscall istream::istream(istream *this,streambuf *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561faa;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0xc);
    local_4 = 0;
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),param_1);
  *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) =
       *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) | 1;
  this->x_gcount = 0;
  this->_fGline = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: istream
// Address: 0055b580
/* protected: __thiscall istream::istream(class istream const &) */

istream * __thiscall istream::istream(istream *this,istream *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561fda;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0xc);
    local_4 = 0;
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),
            *(streambuf **)((int)&param_1->_fGline + *(int *)(*(int *)param_1 + 4)));
  *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) =
       *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) | 1;
  this->x_gcount = 0;
  this->_fGline = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~istream
// Address: 0055b620
/* public: virtual __thiscall istream::~istream(void) */

void __thiscall istream::~istream(istream *this)
{
  *(undefined ***)(*(int *)(*(int *)&this[-1].field_0x34 + 4) + -0xc + (int)this) = &_vftable_;
  return;
}

// --------------------------------------------------

// Function: operator=
// Address: 0055b630
/* protected: class istream & __thiscall istream::operator=(class streambuf *) */

istream * __thiscall istream::operator=(istream *this,streambuf *param_1)
{
  undefined4 *puVar1;
  ios *piVar2;
  undefined4 *unaff_FS_OFFSET;
  ios local_40;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561ff8;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(&this->field_0x1c + *(int *)(*(int *)this + 4)) != 0) &&
     (puVar1 = *(undefined4 **)((int)&this->_fGline + *(int *)(*(int *)this + 4)),
     puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)((int)&this->_fGline + *(int *)(*(int *)this + 4)) = 0;
  piVar2 = (ios *)ios::ios(&local_40);
  uStack_4 = 0;
  ios::operator=((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),piVar2);
  uStack_4 = 0xffffffff;
  ios::~ios(&local_40);
  *(undefined4 *)(&this->field_0x1c + *(int *)(*(int *)this + 4)) = 0;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),param_1);
  *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) =
       *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) | 1;
  this->x_gcount = 0;
  *unaff_FS_OFFSET = uStack_c;
  return this;
}

// --------------------------------------------------

// Function: ipfx
// Address: 0055b6f0
/* public: int __thiscall istream::ipfx(int) */

int __thiscall istream::ipfx(istream *this,int param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 != 0) {
    this->x_gcount = 0;
  }
  iVar1 = *(int *)(*(int *)this + 4);
  uVar2 = *(uint *)((int)&this->x_gcount + iVar1);
  if (uVar2 != 0) {
    *(uint *)((int)&this->x_gcount + iVar1) = uVar2 | 2;
    return 0;
  }
  if (*(ostream **)(&this->field_0x20 + iVar1) != (ostream *)0x0) {
    if (param_1 != 0) {
      iVar4 = *(int *)((int)&this->_fGline + iVar1);
      uVar2 = *(uint *)(iVar4 + 0x2c);
      uVar3 = *(uint *)(iVar4 + 0x28);
      if (uVar3 < uVar2) {
        iVar4 = uVar2 - uVar3;
      }
      else {
        iVar4 = 0;
      }
      if (param_1 <= iVar4) goto LAB_0055b747;
    }
    ostream::flush(*(ostream **)(&this->field_0x20 + iVar1));
  }
LAB_0055b747:
  if ((param_1 == 0) && (((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 1) != 0)) {
    eatwhite(this);
    uVar2 = *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4));
    if (uVar2 != 0) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) = uVar2 | 2;
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: operator>>
// Address: 0055b790
/* public: class istream & __thiscall istream::operator>>(char *) */

istream * __thiscall istream::operator>>(istream *this,char *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = ipfx(this,0);
  if (iVar1 != 0) {
    iVar1 = *(int *)(&this->field_0x30 + *(int *)(*(int *)this + 4));
    *(undefined4 *)(&this->field_0x30 + *(int *)(*(int *)this + 4)) = 0;
    if (param_1 == (char *)0x0) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
           *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 2;
      return this;
    }
    uVar4 = 0;
    if (iVar1 != 1) {
      do {
        iVar2 = streambuf::sgetc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
        if (iVar2 == -1) {
          *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
               *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 1;
          if (uVar4 != 0) goto LAB_0055b867;
          *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
               *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 6;
          break;
        }
        iVar3 = isspace(iVar2);
        if (iVar3 != 0) break;
        param_1[uVar4] = (char)iVar2;
        streambuf::stossc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
        uVar4 = uVar4 + 1;
      } while (uVar4 < iVar1 - 1U);
    }
    if (uVar4 == 0) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
           *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 2;
      return this;
    }
LAB_0055b867:
    param_1[uVar4] = '\0';
  }
  return this;
}

// --------------------------------------------------

// Function: peek
// Address: 0055b880
/* public: int __thiscall istream::peek(void) */

int __thiscall istream::peek(istream *this)
{
  int iVar1;
  
  iVar1 = ipfx(this,1);
  if (iVar1 != 0) {
    iVar1 = streambuf::sgetc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: putback
// Address: 0055b8b0
/* public: class istream & __thiscall istream::putback(char) */

istream * __thiscall istream::putback(istream *this,char param_1)
{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  
  if (*(int *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) == 0) {
    piVar1 = *(int **)((int)&this->_fGline + *(int *)(*(int *)this + 4));
    if ((uint)piVar1[9] < (uint)piVar1[10]) {
      pcVar2 = (char *)(piVar1[10] - 1);
      piVar1[10] = (int)pcVar2;
      *pcVar2 = param_1;
      iVar3 = (int)param_1;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x24))((int)param_1);
    }
    if (iVar3 == -1) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
           *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 2;
    }
  }
  return this;
}

// --------------------------------------------------

// Function: sync
// Address: 0055b910
/* public: int __thiscall istream::sync(void) */

int __thiscall istream::sync(istream *this)
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)((int)&this->_fGline + *(int *)(*(int *)this + 4)) + 4))();
  if (iVar1 == -1) {
    *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
         *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 6;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: eatwhite
// Address: 0055b940
/* public: void __thiscall istream::eatwhite(void) */

void __thiscall istream::eatwhite(istream *this)
{
  int iVar1;
  
  iVar1 = streambuf::sgetc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
  while( true ) {
    if (iVar1 == -1) {
      *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) =
           *(uint *)((int)&this->x_gcount + *(int *)(*(int *)this + 4)) | 1;
      return;
    }
    iVar1 = isspace(iVar1);
    if (iVar1 == 0) break;
    iVar1 = streambuf::snextc(*(streambuf **)((int)&this->_fGline + *(int *)(*(int *)this + 4)));
  }
  return;
}

// --------------------------------------------------

