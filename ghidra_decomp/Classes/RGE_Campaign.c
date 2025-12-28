// Class: RGE_Campaign
// Size:  0x20C
//
// Member Layout:
// [0x000] RGE_Campaign_Header campaign_header (sz: 0x108)
// [0x108] RGE_Scenario_Offset * scenario_offsets
// [0x10C] char[255] filename (sz: 0xFF)
// ----------------------------------------------------------------

// Function: RGE_Campaign
// Address: 00423230
// [HELPER] s_FILE_NOT_FOUND: "FILE NOT FOUND"
// [HELPER] s__s_s: "%s%s"
/* public: __thiscall RGE_Campaign::RGE_Campaign(char *) */

RGE_Campaign * __thiscall RGE_Campaign::RGE_Campaign(RGE_Campaign *this,char *param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  RGE_Scenario_Offset *pRVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  sprintf(this->filename,s__s_s,rge_base_game->prog_info->campaign_dir,param_1);
  iVar3 = __open(this->filename,0x8000);
  if (-1 < iVar3) {
    read(iVar3,this,0x108);
    iVar2 = (this->campaign_header).scenario_num;
    if (0 < iVar2) {
      pRVar4 = (RGE_Scenario_Offset *)calloc(iVar2,0x208);
      iVar2 = (this->campaign_header).scenario_num;
      this->scenario_offsets = pRVar4;
      read(iVar3,pRVar4,iVar2 * 0x208);
      close(iVar3);
      return this;
    }
    this->scenario_offsets = (RGE_Scenario_Offset *)0x0;
    close(iVar3);
    return this;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_FILE_NOT_FOUND;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = (this->campaign_header).name;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  (this->campaign_header).scenario_num = 0;
  (this->campaign_header).version = 0;
  this->scenario_offsets = (RGE_Scenario_Offset *)0x0;
  return this;
}

// --------------------------------------------------

// Function: RGE_Campaign
// Address: 00423330
// [HELPER] s_1_00: "1.00"
// [HELPER] s__s_s: "%s%s"
/* public: __thiscall RGE_Campaign::RGE_Campaign(char *,char *,long,char * *,char * *) */

RGE_Campaign * __thiscall
RGE_Campaign::RGE_Campaign
          (RGE_Campaign *this,char *param_1,char *param_2,long param_3,char **param_4,char **param_5
          )
{
  char cVar1;
  RGE_Scenario_Offset *pRVar2;
  uint uVar3;
  uint uVar4;
  char **ppcVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
  sprintf(this->filename,s__s_s,rge_base_game->prog_info->campaign_dir,param_1);
  (this->campaign_header).version = s_1_00._0_4_;
  uVar3 = 0xffffffff;
  do {
    pcVar7 = param_2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar6 = 0;
  pcVar7 = pcVar7 + -uVar3;
  pcVar8 = (this->campaign_header).name;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  (this->campaign_header).scenario_num = param_3;
  if (param_3 < 1) {
    this->scenario_offsets = (RGE_Scenario_Offset *)0x0;
  }
  else {
    pRVar2 = (RGE_Scenario_Offset *)calloc(param_3,0x208);
    this->scenario_offsets = pRVar2;
    if (0 < param_3) {
      param_1 = (char *)param_3;
      ppcVar5 = param_4;
      do {
        uVar3 = 0xffffffff;
        pcVar7 = *(char **)(((int)param_5 - (int)param_4) + (int)ppcVar5);
        do {
          pcVar8 = pcVar7;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          pcVar8 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar8;
        } while (cVar1 != '\0');
        uVar3 = ~uVar3;
        pcVar7 = pcVar8 + -uVar3;
        pcVar8 = this->scenario_offsets->name + iVar6;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar8 = pcVar8 + 4;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *pcVar8 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        }
        pcVar7 = this->scenario_offsets->file_name + iVar6;
        uVar3 = 0xffffffff;
        pcVar8 = *ppcVar5;
        do {
          pcVar9 = pcVar8;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          pcVar9 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar9;
        } while (cVar1 != '\0');
        uVar3 = ~uVar3;
        iVar6 = iVar6 + 0x208;
        pcVar8 = pcVar9 + -uVar3;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar7 = pcVar7 + 4;
        }
        param_1 = param_1 + -1;
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *pcVar7 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar7 = pcVar7 + 1;
        }
        ppcVar5 = ppcVar5 + 1;
        if (param_1 == (char *)0x0) {
          create_file(this);
          return this;
        }
      } while( true );
    }
  }
  create_file(this);
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Campaign
// Address: 00423480
/* public: __thiscall RGE_Campaign::~RGE_Campaign(void) */

void __thiscall RGE_Campaign::~RGE_Campaign(RGE_Campaign *this)
{
  if (this->scenario_offsets != (RGE_Scenario_Offset *)0x0) {
    free(this->scenario_offsets);
    this->scenario_offsets = (RGE_Scenario_Offset *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: create_file
// Address: 004234b0
// [HELPER] s__s_s: "%s%s"
/* public: void __thiscall RGE_Campaign::create_file(void) */

void __thiscall RGE_Campaign::create_file(RGE_Campaign *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int handle;
  long index;
  long current_offset;
  char tempname [300];
  
  iVar1 = __open(this->filename,0x8301,0x180);
  if (-1 < iVar1) {
    write(iVar1,this,0x108);
    iVar2 = (this->campaign_header).scenario_num;
    if (0 < iVar2) {
      write(iVar1,this->scenario_offsets,iVar2 * 0x208);
      iVar2 = (this->campaign_header).scenario_num;
      current_offset = 0;
      tempname._0_4_ = iVar2 * 0x208 + 0x108;
      if (0 < iVar2) {
        handle = 0;
        do {
          sprintf(tempname + 4,s__s_s,rge_base_game->prog_info->scenario_dir,
                  this->scenario_offsets->file_name + handle);
          iVar2 = __open(tempname + 4,0x8000);
          if (-1 < iVar2) {
            lseek(iVar2,0,2);
            iVar3 = __tell(iVar2);
            uVar4 = calloc(iVar3,1);
            lseek(iVar2,0,0);
            read(iVar2,uVar4,iVar3);
            write(iVar1,uVar4,iVar3);
            *(undefined4 *)(this->scenario_offsets->name + handle + -4) = tempname._0_4_;
            tempname._0_4_ = tempname._0_4_ + iVar3;
            *(int *)(this->scenario_offsets->name + handle + -8) = iVar3;
            free(uVar4);
            close(iVar2);
          }
          current_offset = current_offset + 1;
          handle = handle + 0x208;
        } while (current_offset < (this->campaign_header).scenario_num);
      }
      lseek(iVar1,0x108,0);
      write(iVar1,this->scenario_offsets,(this->campaign_header).scenario_num * 0x208);
    }
    close(iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: open_scenario
// Address: 00423690
/* public: int __thiscall RGE_Campaign::open_scenario(long) */

int __thiscall RGE_Campaign::open_scenario(RGE_Campaign *this,long param_1)
{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < (this->campaign_header).scenario_num)) {
    iVar1 = __open(this->filename,0x8000);
    if (-1 < iVar1) {
      lseek(iVar1,this->scenario_offsets[param_1].offset,0);
      rge_fake_open(iVar1,this->scenario_offsets[param_1].size);
      return iVar1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: get_name
// Address: 00423710
/* public: char * __thiscall RGE_Campaign::get_name(void) */

char * __thiscall RGE_Campaign::get_name(RGE_Campaign *this)
{
  return (this->campaign_header).name;
}

// --------------------------------------------------

// Function: scenario_number
// Address: 00423720
/* public: long __thiscall RGE_Campaign::scenario_number(void) */

long __thiscall RGE_Campaign::scenario_number(RGE_Campaign *this)
{
  return (this->campaign_header).scenario_num;
}

// --------------------------------------------------

// Function: scenario_info
// Address: 00423730
/* public: long __thiscall RGE_Campaign::scenario_info(char * * *) */

long __thiscall RGE_Campaign::scenario_info(RGE_Campaign *this,char ***param_1)
{
  char **ppcVar1;
  int iVar2;
  int iVar3;
  
  ppcVar1 = (char **)calloc((this->campaign_header).scenario_num,4);
  iVar3 = 0;
  *param_1 = ppcVar1;
  if (0 < (this->campaign_header).scenario_num) {
    iVar2 = 0;
    do {
      getstring(*param_1 + iVar3,this->scenario_offsets->name + iVar2);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x208;
    } while (iVar3 < (this->campaign_header).scenario_num);
  }
  return (this->campaign_header).scenario_num;
}

// --------------------------------------------------

// Function: get_scenario_name
// Address: 004237a0
/* public: char * __thiscall RGE_Campaign::get_scenario_name(long) */

char * __thiscall RGE_Campaign::get_scenario_name(RGE_Campaign *this,long param_1)
{
  return this->scenario_offsets[param_1].name;
}

// --------------------------------------------------

