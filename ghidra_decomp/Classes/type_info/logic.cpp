// Class: type_info
// Function: ~type_info
// Address: 0055bf20
/* public: virtual __thiscall type_info::~type_info(void) */

void __thiscall type_info::~type_info(type_info *this)
{
  *(undefined ***)this = &_vftable_;
  if (*(int *)(this + 4) != 0) {
    free(*(int *)(this + 4));
  }
  return;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0055bf40
/* public: virtual void * __thiscall type_info::`vector deleting destructor'(unsigned int) */

void * __thiscall type_info::_vector_deleting_destructor_(type_info *this,uint param_1)
{
  ~type_info(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: operator==
// Address: 0055bf60
/* public: int __thiscall type_info::operator==(class type_info const &)const  */

int __thiscall type_info::operator==(type_info *this,type_info *param_1)
{
  type_info tVar1;
  type_info *ptVar2;
  type_info *ptVar3;
  bool bVar4;
  
  ptVar3 = this + 9;
  ptVar2 = param_1 + 9;
  while( true ) {
    tVar1 = *ptVar2;
    bVar4 = (byte)tVar1 < (byte)*ptVar3;
    if (tVar1 != *ptVar3) break;
    if (tVar1 == (type_info)0x0) {
      return 1;
    }
    tVar1 = ptVar2[1];
    bVar4 = (byte)tVar1 < (byte)ptVar3[1];
    if (tVar1 != ptVar3[1]) break;
    ptVar2 = ptVar2 + 2;
    ptVar3 = ptVar3 + 2;
    if (tVar1 == (type_info)0x0) {
      return 1;
    }
  }
  return (uint)(1 - bVar4 == (uint)(bVar4 != 0));
}

// --------------------------------------------------

// Function: operator!=
// Address: 0055bfc0
/* public: int __thiscall type_info::operator!=(class type_info const &)const  */

int __thiscall type_info::operator!=(type_info *this,type_info *param_1)
{
  type_info tVar1;
  type_info *ptVar2;
  type_info *ptVar3;
  bool bVar4;
  
  ptVar3 = this + 9;
  ptVar2 = param_1 + 9;
  while( true ) {
    tVar1 = *ptVar2;
    bVar4 = (byte)tVar1 < (byte)*ptVar3;
    if (tVar1 != *ptVar3) break;
    if (tVar1 == (type_info)0x0) {
      return 0;
    }
    tVar1 = ptVar2[1];
    bVar4 = (byte)tVar1 < (byte)ptVar3[1];
    if (tVar1 != ptVar3[1]) break;
    ptVar2 = ptVar2 + 2;
    ptVar3 = ptVar3 + 2;
    if (tVar1 == (type_info)0x0) {
      return 0;
    }
  }
  return (uint)(1 - bVar4 != (uint)(bVar4 != 0));
}

// --------------------------------------------------

// Function: before
// Address: 0055c020
/* public: int __thiscall type_info::before(class type_info const &)const  */

int __thiscall type_info::before(type_info *this,type_info *param_1)
{
  type_info tVar1;
  uint uVar2;
  uint uVar3;
  type_info *ptVar4;
  type_info *ptVar5;
  bool bVar6;
  
  ptVar5 = this + 9;
  ptVar4 = param_1 + 9;
  while( true ) {
    tVar1 = *ptVar4;
    bVar6 = (byte)tVar1 < (byte)*ptVar5;
    if (tVar1 != *ptVar5) break;
    if (tVar1 == (type_info)0x0) {
      return 0;
    }
    tVar1 = ptVar4[1];
    bVar6 = (byte)tVar1 < (byte)ptVar5[1];
    if (tVar1 != ptVar5[1]) break;
    ptVar4 = ptVar4 + 2;
    ptVar5 = ptVar5 + 2;
    if (tVar1 == (type_info)0x0) {
      return 0;
    }
  }
  uVar2 = (uint)(bVar6 != 0);
  uVar3 = 1 - bVar6;
  return (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2));
}

// --------------------------------------------------

// Function: raw_name
// Address: 0055c080
/* public: char const * __thiscall type_info::raw_name(void)const  */

char * __thiscall type_info::raw_name(type_info *this)
{
  return (char *)(this + 8);
}

// --------------------------------------------------

// Function: type_info
// Address: 0055c090
/* private: __thiscall type_info::type_info(class type_info const &) */

void __thiscall type_info::type_info(type_info *this,type_info *param_1)
{
  *(undefined ***)this = &_vftable_;
  return;
}

// --------------------------------------------------

// Function: operator=
// Address: 0055c0a0
/* private: class type_info & __thiscall type_info::operator=(class type_info const &) */

type_info * __thiscall type_info::operator=(type_info *this,type_info *param_1)
{
  return this;
}

// --------------------------------------------------

