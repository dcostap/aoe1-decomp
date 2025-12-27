// Class: AIModuleID
// Function: AIModuleID
// Address: 0040dd90
// [HELPER] s_: ""
/* public: __thiscall AIModuleID::AIModuleID(char *,int) */

AIModuleID * __thiscall AIModuleID::AIModuleID(AIModuleID *this,char *param_1,int param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  this->id = param_2;
  this->_padding_ = (int)&_vftable_;
  if (param_1 != (char *)0x0) {
    strncpy(this->name,param_1,0x3f);
    return this;
  }
  uVar2 = 0xffffffff;
  pcVar4 = s_;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = this->name;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0040ddf0
/* public: virtual void * __thiscall AIModuleID::`vector deleting destructor'(unsigned int) */

void * __thiscall AIModuleID::_vector_deleting_destructor_(AIModuleID *this,uint param_1)
{
  ~AIModuleID(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~AIModuleID
// Address: 0040de10
/* public: virtual __thiscall AIModuleID::~AIModuleID(void) */

void __thiscall AIModuleID::~AIModuleID(AIModuleID *this)
{
  this->_padding_ = (int)&_vftable_;
  return;
}

// --------------------------------------------------

// Function: setID
// Address: 0040de20
// [HELPER] s_: ""
/* public: void __thiscall AIModuleID::setID(int,char *) */

void __thiscall AIModuleID::setID(AIModuleID *this,int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  this->id = param_1;
  if (param_2 != (char *)0x0) {
    strncpy(this->name,param_2,0x3f);
    return;
  }
  uVar2 = 0xffffffff;
  pcVar4 = s_;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = this->name;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return;
}

// --------------------------------------------------

