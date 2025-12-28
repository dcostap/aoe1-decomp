// Class: RGE_Scenario_Header
// Size:  0x14
//
// VTable Layout:
// [00] get_size
// [01] save
// [02] get_object_pointer
// [03] `scalar_deleting_destructor'
// [04] rehook
// [05] save
//
// Member Layout:
// [0x004] int error_code
// [0x008] long version
// [0x00C] ulong checksum
// [0x010] char * description
// ----------------------------------------------------------------

// Function: RGE_Scenario_Header
// Address: 0048ab10
RGE_Scenario_Header * __thiscall
RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario_Header *this,RGE_Scenario *param_1)
{
  char cVar1;
  ulong uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  RGE_Scenario *pRVar6;
  char *pcVar7;
  
  this->_padding_ = (int)&_vftable_;
  this->error_code = 0;
  this->version = 2;
  uVar2 = time(0);
  this->checksum = uVar2;
  pcVar3 = RGE_Scenario::Get_description(param_1);
  if (pcVar3 == (char *)0x0) {
    this->description = (char *)0x0;
    pRVar6 = param_1;
  }
  else {
    pcVar3 = RGE_Scenario::Get_description(param_1);
    uVar4 = 0xffffffff;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = (char *)malloc((RGE_Scenario *)~uVar4);
    this->description = pcVar3;
    pRVar6 = (RGE_Scenario *)~uVar4;
  }
  if (this->description != (char *)0x0) {
    pcVar3 = RGE_Scenario::Get_description(param_1);
    uVar4 = 0xffffffff;
    do {
      pcVar7 = pcVar3;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar3 = pcVar7 + -uVar4;
    pcVar7 = this->description;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    }
    ((undefined1 *)((int)&pRVar6[-1].mission_picture + 3))[(int)this->description] = 0;
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Scenario_Header
// Address: 0048abb0
RGE_Scenario_Header * __thiscall
RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario_Header *this,int param_1)
{
  long *plVar1;
  int iVar2;
  char *pcVar3;
  long header_size;
  RGE_Scenario_Header *local_4;
  
  iVar2 = param_1;
  plVar1 = &this->version;
  this->error_code = 0;
  *plVar1 = 0;
  this->checksum = 0;
  this->description = (char *)0x0;
  this->_padding_ = (int)&_vftable_;
  local_4 = this;
  rge_read_uncompressed(param_1,&local_4,4);
  rge_read_uncompressed(iVar2,plVar1,4);
  if (1 < *plVar1) {
    rge_read_uncompressed(iVar2,&this->checksum,4);
  }
  rge_read_uncompressed(iVar2,&param_1,4);
  if (0 < param_1) {
    pcVar3 = (char *)malloc(param_1);
    this->description = pcVar3;
    if (pcVar3 == (char *)0x0) {
      this->error_code = 1;
      return this;
    }
    rge_read_uncompressed(iVar2,pcVar3,param_1);
    return this;
  }
  this->description = (char *)0x0;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Scenario_Header
// Address: 0048ac70
void __thiscall RGE_Scenario_Header::~RGE_Scenario_Header(RGE_Scenario_Header *this)
{
  this->_padding_ = (int)&_vftable_;
  if (this->description != (char *)0x0) {
    free(this->description);
    this->description = (char *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: get_size
// Address: 0048aca0
long __thiscall RGE_Scenario_Header::get_size(RGE_Scenario_Header *this)
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if (this->description == (char *)0x0) {
    return 0xc;
  }
  uVar2 = 0xffffffff;
  pcVar3 = this->description;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return ~uVar2 + 0xc;
}

// --------------------------------------------------

// Function: save
// Address: 0048acc0
void __thiscall RGE_Scenario_Header::save(RGE_Scenario_Header *this,int param_1)
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  long desc_size;
  long header_size;
  undefined4 uStack_4;
  
  uStack_4 = (**(code **)this->_padding_)();
  rge_write_uncompressed(param_1,&uStack_4,4);
  rge_write_uncompressed(param_1,&this->version,4);
  if (1 < this->version) {
    rge_write_uncompressed(param_1,&this->checksum,4);
  }
  if (this->description == (char *)0x0) {
    header_size = 0;
  }
  else {
    uVar2 = 0xffffffff;
    pcVar3 = this->description;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    header_size = ~uVar2;
  }
  rge_write_uncompressed(param_1,&header_size,4);
  if (this->description != (char *)0x0) {
    rge_write_uncompressed(param_1,this->description,header_size);
  }
  return;
}

// --------------------------------------------------

