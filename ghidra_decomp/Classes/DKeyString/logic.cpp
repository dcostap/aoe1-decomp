// Class: DKeyString
// Function: DKeyString
// Address: 004475d0
// [HELPER] s_: ""
/* public: __thiscall DKeyString::DKeyString(void) */

DKeyString * __thiscall DKeyString::DKeyString(DKeyString *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d4d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  DString::DString(&this->keyValue,s_);
  local_4 = 0;
  DString::DString(&this->valueValue,s_);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: DKeyString
// Address: 00447620
/* public: __thiscall DKeyString::DKeyString(class DString,class DString) */

DKeyString * __thiscall DKeyString::DKeyString(DKeyString *this,DString param_1,DString param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_0055d508;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_4 = 1;
  DString::DString(&this->keyValue,&param_1);
  local_4._0_1_ = 2;
  DString::DString(&this->valueValue,&param_2);
  local_4 = (uint)local_4._1_3_ << 8;
  DString::~DString(&param_1);
  local_4 = 0xffffffff;
  DString::~DString(&param_2);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~DKeyString
// Address: 004476a0
/* public: __thiscall DKeyString::~DKeyString(void) */

void __thiscall DKeyString::~DKeyString(DKeyString *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055d528;
  *unaff_FS_OFFSET = &local_c;
  local_4 = 0;
  DString::~DString(&this->valueValue);
  local_4 = 0xffffffff;
  DString::~DString(&this->keyValue);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: key
// Address: 004476f0
/* public: class DString __thiscall DKeyString::key(void)const  */

DString * __thiscall DKeyString::key(DKeyString *this,DString *__return_storage_ptr__)
{
  <NoType> ___ReturnUdt;
  
  DString::DString(__return_storage_ptr__,&this->keyValue);
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: setKey
// Address: 00447710
/* public: void __thiscall DKeyString::setKey(class DString) */

void __thiscall DKeyString::setKey(DKeyString *this,DString param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055d548;
  *unaff_FS_OFFSET = &local_c;
  local_4 = 0;
  DString::operator=(&this->keyValue,&param_1);
  local_4 = 0xffffffff;
  DString::~DString(&param_1);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: value
// Address: 00447760
/* public: class DString __thiscall DKeyString::value(void)const  */

DString * __thiscall DKeyString::value(DKeyString *this,DString *__return_storage_ptr__)
{
  <NoType> ___ReturnUdt;
  
  DString::DString(__return_storage_ptr__,&this->valueValue);
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: setValue
// Address: 00447780
/* public: void __thiscall DKeyString::setValue(class DString) */

void __thiscall DKeyString::setValue(DKeyString *this,DString param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055d568;
  *unaff_FS_OFFSET = &local_c;
  local_4 = 0;
  DString::operator=(&this->valueValue,&param_1);
  local_4 = 0xffffffff;
  DString::~DString(&param_1);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

