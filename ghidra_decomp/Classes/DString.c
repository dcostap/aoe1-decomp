// Class: DString
// Size:  0x14
//
// Member Layout:
// [0x000] char * stringValue
// [0x004] int lengthValue
// [0x008] int numWordsValue
// [0x00C] int indexValue
// [0x010] int currentWordValue
// ----------------------------------------------------------------

// Function: DString
// Address: 004465d0
// [HELPER] s_: ""
DString * __thiscall DString::DString(DString *this)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  this->stringValue = (char *)0x0;
  this->lengthValue = 0;
  this->numWordsValue = -1;
  this->indexValue = 0;
  this->currentWordValue = 0;
  pcVar2 = (char *)malloc(1);
  uVar3 = 0xffffffff;
  this->stringValue = pcVar2;
  pcVar5 = s_;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: DString
// Address: 00446620
DString * __thiscall DString::DString(DString *this,DString *param_1)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  this->lengthValue = param_1->lengthValue;
  this->numWordsValue = param_1->numWordsValue;
  this->indexValue = param_1->indexValue;
  this->currentWordValue = param_1->currentWordValue;
  if (this->lengthValue < 1) {
    this->stringValue = (char *)0x0;
    return this;
  }
  pcVar2 = (char *)malloc(this->lengthValue + 1);
  uVar3 = 0xffffffff;
  this->stringValue = pcVar2;
  pcVar5 = param_1->stringValue;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: DString
// Address: 00446690
DString * __thiscall DString::DString(DString *this,char *param_1)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  this->numWordsValue = -1;
  this->lengthValue = iVar4;
  this->indexValue = 0;
  this->currentWordValue = 0;
  if (iVar4 < 1) {
    this->stringValue = (char *)0x0;
    return this;
  }
  pcVar2 = (char *)malloc(~uVar3);
  uVar3 = 0xffffffff;
  this->stringValue = pcVar2;
  do {
    pcVar6 = param_1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar6 + -uVar3;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: ~DString
// Address: 00446700
void __thiscall DString::~DString(DString *this)
{
  if (this->stringValue != (char *)0x0) {
    free(this->stringValue);
  }
  return;
}

// --------------------------------------------------

// Function: operator=
// Address: 00446780
DString * __thiscall DString::operator=(DString *this,char *param_1)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  if (this->stringValue != (char *)0x0) {
    free(this->stringValue);
  }
  uVar3 = 0xffffffff;
  this->numWordsValue = -1;
  this->indexValue = 0;
  this->currentWordValue = 0;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  this->lengthValue = iVar4;
  if (iVar4 < 1) {
    this->stringValue = (char *)0x0;
    return this;
  }
  pcVar2 = (char *)malloc(~uVar3);
  uVar3 = 0xffffffff;
  this->stringValue = pcVar2;
  do {
    pcVar6 = param_1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar6 + -uVar3;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: operator=
// Address: 00446800
DString * __thiscall DString::operator=(DString *this,DString *param_1)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  if (this->stringValue != (char *)0x0) {
    free(this->stringValue);
  }
  this->numWordsValue = param_1->numWordsValue;
  this->indexValue = param_1->indexValue;
  this->currentWordValue = param_1->currentWordValue;
  iVar2 = param_1->lengthValue;
  this->lengthValue = iVar2;
  if (iVar2 < 1) {
    this->stringValue = (char *)0x0;
    return this;
  }
  pcVar3 = (char *)malloc(iVar2 + 1);
  uVar4 = 0xffffffff;
  this->stringValue = pcVar3;
  pcVar6 = param_1->stringValue;
  do {
    pcVar7 = pcVar6;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar7 + -uVar4;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar3 = pcVar3 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: operator+
// Address: 00446c80
DString * __thiscall
DString::operator+(DString *this,DString *__return_storage_ptr__,DString *param_1)
{
  DString DVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 in_stack_ffffffc0 [12];
  int iVar2;
  DString newStr;
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d35f;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar2 = 0x446cab;
  DString((DString *)&newStr.lengthValue,this);
  newStr.stringValue = &stack0xffffffc0;
  local_4 = 1;
  DString((DString *)&stack0xffffffc0,param_1);
  DVar1.indexValue = iVar2;
  DVar1.stringValue = (char *)in_stack_ffffffc0._0_4_;
  DVar1.lengthValue = in_stack_ffffffc0._4_4_;
  DVar1.numWordsValue = in_stack_ffffffc0._8_4_;
  DVar1.currentWordValue = (int)this;
  append((DString *)&newStr.lengthValue,DVar1);
  DString(__return_storage_ptr__,(DString *)&newStr.lengthValue);
  local_4 = local_4 & 0xffffff00;
  ~DString((DString *)&newStr.lengthValue);
  *unaff_FS_OFFSET = local_c;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: operator[]
// Address: 00446d10
char * __thiscall DString::operator[](DString *this,int param_1)
{
  if ((-1 < param_1) && (param_1 + 1 <= this->lengthValue)) {
    return this->stringValue + param_1;
  }
  return this->stringValue;
}

// --------------------------------------------------

// Function: operator_char*
// Address: 00446d30
char * __thiscall DString::operator_char_(DString *this)
{
  return this->stringValue;
}

// --------------------------------------------------

// Function: length
// Address: 00446d40
int __thiscall DString::length(DString *this)
{
  return this->lengthValue;
}

// --------------------------------------------------

// Function: index
// Address: 00446d50
int __thiscall DString::index(DString *this)
{
  return this->indexValue;
}

// --------------------------------------------------

// Function: contains
// Address: 00446d60
int __thiscall DString::contains(DString *this,DString param_1)
{
  char *pcVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055d378;
  *unaff_FS_OFFSET = &local_c;
  local_4 = 0;
  pcVar1 = operator_char_(&param_1);
  iVar2 = strstr(this->stringValue,pcVar1);
  local_4 = 0xffffffff;
  if (iVar2 != 0) {
    ~DString(&param_1);
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
  ~DString(&param_1);
  *unaff_FS_OFFSET = local_c;
  return 0;
}

// --------------------------------------------------

// Function: contains
// Address: 00446de0
int __thiscall DString::contains(DString *this,char *param_1)
{
  int iVar1;
  
  iVar1 = strstr(this->stringValue,param_1);
  return (uint)(iVar1 != 0);
}

// --------------------------------------------------

// Function: numWords
// Address: 00446e00
int __thiscall DString::numWords(DString *this)
{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = this->numWordsValue;
  if (iVar1 == -1) {
    iVar1 = this->lengthValue;
    if (iVar1 == 0) {
      return iVar1;
    }
    bVar3 = *this->stringValue != ' ';
    if (bVar3) {
      this->numWordsValue = 1;
    }
    else {
      this->numWordsValue = 0;
    }
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (bVar3) {
LAB_00446e61:
          iVar1 = isspace((int)this->stringValue[iVar2]);
          if (iVar1 != 0) {
            bVar3 = false;
          }
        }
        else {
          iVar1 = isspace((int)this->stringValue[iVar2]);
          if (iVar1 != 0) goto LAB_00446e61;
          bVar3 = true;
          this->numWordsValue = this->numWordsValue + 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->lengthValue);
    }
    iVar1 = this->numWordsValue;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: word
// Address: 00446e90
// [HELPER] s_: ""
DString * __thiscall DString::word(DString *this,DString *__return_storage_ptr__,int param_1)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  DString rStr;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d398;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar4 = 0;
  rStr.stringValue = (char *)0x0;
  iVar2 = numWords(this);
  if ((param_1 <= iVar2) && (0 < param_1)) {
    iVar2 = this->currentWordValue + 1;
    if (param_1 == iVar2) {
      this->currentWordValue = iVar2;
      nextWord(this,__return_storage_ptr__,1);
      goto LAB_00446fb6;
    }
    iVar2 = 0;
    bVar1 = false;
    if (param_1 != 0) {
      do {
        if (this->lengthValue <= iVar2) break;
        if ((bVar1) || (iVar3 = isspace((int)this->stringValue[iVar2]), iVar3 != 0)) {
          iVar3 = isspace((int)this->stringValue[iVar2]);
          if (iVar3 != 0) {
            bVar1 = false;
          }
        }
        else {
          iVar4 = iVar4 + 1;
          bVar1 = true;
        }
        iVar2 = iVar2 + 1;
      } while (iVar4 != param_1);
    }
    if (iVar4 == param_1) {
      iVar4 = iVar2 + -1;
      iVar3 = isspace((int)this->stringValue[iVar2]);
      while ((iVar3 == 0 && (iVar2 < this->lengthValue))) {
        iVar2 = iVar2 + 1;
        iVar3 = isspace((int)this->stringValue[iVar2]);
      }
      subString(this,(DString *)&rStr.lengthValue,iVar4,iVar2 - iVar4);
      local_4 = 0;
      DString(__return_storage_ptr__,(DString *)&rStr.lengthValue);
      local_4 = 0xffffffff;
      ~DString((DString *)&rStr.lengthValue);
      goto LAB_00446fb6;
    }
  }
  DString(__return_storage_ptr__,s_);
LAB_00446fb6:
  *unaff_FS_OFFSET = local_c;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: nextWord
// Address: 00446fd0
DString * __thiscall DString::nextWord(DString *this,DString *__return_storage_ptr__,int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  DString rStr;
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d3cf;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  rStr.stringValue = (char *)0x0;
  iVar3 = this->indexValue;
  iVar1 = isspace((int)this->stringValue[iVar3]);
  while ((iVar1 != 0 && (iVar3 < this->lengthValue))) {
    iVar3 = iVar3 + 1;
    iVar1 = isspace((int)this->stringValue[iVar3]);
  }
  iVar2 = isspace((int)this->stringValue[iVar3]);
  iVar1 = iVar3;
  while ((iVar2 == 0 && (iVar1 < this->lengthValue))) {
    iVar1 = iVar1 + 1;
    iVar2 = isspace((int)this->stringValue[iVar1]);
  }
  if (param_1 != 0) {
    this->indexValue = iVar1;
  }
  subString(this,(DString *)&rStr.lengthValue,iVar3,iVar1 - iVar3);
  local_4 = 1;
  DString(__return_storage_ptr__,(DString *)&rStr.lengthValue);
  rStr.stringValue = (char *)0x1;
  local_4 = local_4 & 0xffffff00;
  ~DString((DString *)&rStr.lengthValue);
  *unaff_FS_OFFSET = local_c;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: moveToFirstWord
// Address: 004470b0
void __thiscall DString::moveToFirstWord(DString *this)
{
  this->indexValue = 0;
  this->currentWordValue = 0;
  return;
}

// --------------------------------------------------

// Function: moveToNextWord
// Address: 004470c0
void __thiscall DString::moveToNextWord(DString *this)
{
  int iVar1;
  
  iVar1 = isspace((int)this->stringValue[this->indexValue]);
  while ((iVar1 != 0 && (this->indexValue < this->lengthValue))) {
    iVar1 = this->indexValue + 1;
    this->indexValue = iVar1;
    iVar1 = isspace((int)this->stringValue[iVar1]);
  }
  iVar1 = isspace((int)this->stringValue[this->indexValue]);
  while ((iVar1 == 0 && (this->indexValue < this->lengthValue))) {
    iVar1 = this->indexValue + 1;
    this->indexValue = iVar1;
    iVar1 = isspace((int)this->stringValue[iVar1]);
  }
  return;
}

// --------------------------------------------------

// Function: subString
// Address: 00447140
DString * __thiscall
DString::subString(DString *this,DString *__return_storage_ptr__,int param_1,int param_2)
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  DString rStr;
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d3ff;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  rStr.stringValue = (char *)0x0;
  pcVar2 = (char *)malloc(param_2 + 1);
  iVar3 = 0;
  iVar4 = 0;
  if (param_1 < this->lengthValue) {
    do {
      iVar4 = iVar3;
      if (param_2 <= iVar3) break;
      iVar4 = iVar3 + 1;
      pcVar1 = this->stringValue + param_1;
      param_1 = param_1 + 1;
      pcVar2[iVar3] = *pcVar1;
      iVar3 = iVar4;
    } while (param_1 < this->lengthValue);
  }
  pcVar2[iVar4] = '\0';
  DString((DString *)&rStr.lengthValue,pcVar2);
  local_4 = 1;
  DString(__return_storage_ptr__,(DString *)&rStr.lengthValue);
  rStr.stringValue = (char *)0x1;
  local_4 = local_4 & 0xffffff00;
  ~DString((DString *)&rStr.lengthValue);
  *unaff_FS_OFFSET = local_c;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: append
// Address: 004471f0
void __thiscall DString::append(DString *this,DString param_1)
{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055d418;
  *unaff_FS_OFFSET = &local_c;
  iVar5 = 0;
  local_4 = 0;
  iVar1 = length(&param_1);
  pcVar2 = (char *)malloc(iVar1 + 1 + this->lengthValue);
  iVar1 = iVar5;
  if (0 < this->lengthValue) {
    do {
      iVar5 = iVar1 + 1;
      pcVar2[iVar1] = this->stringValue[iVar1];
      iVar1 = iVar5;
    } while (iVar5 < this->lengthValue);
  }
  iVar1 = this->lengthValue;
  iVar3 = length(&param_1);
  if (iVar5 < iVar3 + iVar1) {
    do {
      pcVar4 = operator[](&param_1,iVar5 - iVar1);
      pcVar2[iVar5] = *pcVar4;
      iVar1 = this->lengthValue;
      iVar5 = iVar5 + 1;
      iVar3 = length(&param_1);
    } while (iVar5 < iVar3 + iVar1);
  }
  pcVar2[iVar5] = '\0';
  free(this->stringValue);
  this->stringValue = pcVar2;
  iVar1 = length(&param_1);
  this->lengthValue = this->lengthValue + iVar1;
  this->numWordsValue = -1;
  local_4 = 0xffffffff;
  this->indexValue = 0;
  this->currentWordValue = 0;
  ~DString(&param_1);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: stripTrailing
// Address: 004472d0
DString * __thiscall
DString::stripTrailing(DString *this,DString *__return_storage_ptr__,char param_1)
{
  char cVar1;
  int iVar2;
  DString *pDVar3;
  char *pcVar4;
  undefined4 *unaff_FS_OFFSET;
  DString local_20;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d438;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar2 = this->lengthValue;
  pcVar4 = this->stringValue + iVar2;
  cVar1 = pcVar4[-1];
  for (; (cVar1 == param_1 && (0 < iVar2)); iVar2 = iVar2 + -1) {
    cVar1 = pcVar4[-2];
    pcVar4 = pcVar4 + -1;
  }
  pDVar3 = subString(this,&local_20,0,iVar2);
  local_4 = 0;
  operator=(this,pDVar3);
  local_4 = 0xffffffff;
  ~DString(&local_20);
  DString(__return_storage_ptr__,this);
  *unaff_FS_OFFSET = local_c;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: stripLeading
// Address: 00447370
DString * __thiscall
DString::stripLeading(DString *this,DString *__return_storage_ptr__,char param_1)
{
  int iVar1;
  DString *pDVar2;
  undefined4 *unaff_FS_OFFSET;
  DString local_20;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d458;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar1 = 0;
  if (*this->stringValue == param_1) {
    do {
      if (this->lengthValue <= iVar1) break;
      iVar1 = iVar1 + 1;
    } while (this->stringValue[iVar1] == param_1);
  }
  pDVar2 = subString(this,&local_20,iVar1,this->lengthValue);
  local_4 = 0;
  operator=(this,pDVar2);
  local_4 = 0xffffffff;
  ~DString(&local_20);
  DString(__return_storage_ptr__,this);
  *unaff_FS_OFFSET = local_c;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: asInt
// Address: 00447400
int __thiscall DString::asInt(DString *this)
{
  int iVar1;
  
  iVar1 = atoi(this->stringValue);
  return iVar1;
}

// --------------------------------------------------

// Function: asDouble
// Address: 00447410
double __thiscall DString::asDouble(DString *this)
{
  float10 fVar1;
  
  fVar1 = (float10)atof(this->stringValue);
  return (double)fVar1;
}

// --------------------------------------------------

// Function: uppercase
// Address: 00447420
void __thiscall DString::uppercase(DString *this)
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = length(this);
  if (0 < iVar2) {
    do {
      cVar1 = toupper((int)this->stringValue[iVar3]);
      this->stringValue[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
      iVar2 = length(this);
    } while (iVar3 < iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: asUppercase
// Address: 00447460
DString * __thiscall DString::asUppercase(DString *this,DString *__return_storage_ptr__)
{
  undefined4 *unaff_FS_OFFSET;
  <NoType> ___ReturnUdt;
  DString rStr;
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d48b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  rStr.stringValue = (char *)0x0;
  DString((DString *)&rStr.lengthValue,this->stringValue);
  local_4 = 1;
  uppercase((DString *)&rStr.lengthValue);
  DString(__return_storage_ptr__,(DString *)&rStr.lengthValue);
  rStr.stringValue = (char *)0x1;
  local_4 = local_4 & 0xffffff00;
  ~DString((DString *)&rStr.lengthValue);
  *unaff_FS_OFFSET = local_c;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: lowercase
// Address: 004474e0
void __thiscall DString::lowercase(DString *this)
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = length(this);
  if (0 < iVar2) {
    do {
      cVar1 = tolower((int)this->stringValue[iVar3]);
      this->stringValue[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
      iVar2 = length(this);
    } while (iVar3 < iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: asLowercase
// Address: 00447520
DString * __thiscall DString::asLowercase(DString *this,DString *__return_storage_ptr__)
{
  undefined4 *unaff_FS_OFFSET;
  <NoType> ___ReturnUdt;
  DString rStr;
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d4bb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  rStr.stringValue = (char *)0x0;
  DString((DString *)&rStr.lengthValue,this->stringValue);
  local_4 = 1;
  lowercase((DString *)&rStr.lengthValue);
  DString(__return_storage_ptr__,(DString *)&rStr.lengthValue);
  rStr.stringValue = (char *)0x1;
  local_4 = local_4 & 0xffffff00;
  ~DString((DString *)&rStr.lengthValue);
  *unaff_FS_OFFSET = local_c;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: change
// Address: 004475a0
void __thiscall DString::change(DString *this,char param_1,char param_2)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < this->lengthValue) {
    do {
      if (this->stringValue[iVar1] == param_1) {
        this->stringValue[iVar1] = param_2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->lengthValue);
  }
  return;
}

// --------------------------------------------------

