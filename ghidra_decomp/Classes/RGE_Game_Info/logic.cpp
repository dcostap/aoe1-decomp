// Class: RGE_Game_Info
// Function: RGE_Game_Info
// Address: 0044d1a0
// [HELPER] s_1_00: "1.00"
/* WARNING: Variable defined which should be unmapped: version */
/* public: __thiscall RGE_Game_Info::RGE_Game_Info(char *) */

RGE_Game_Info * __thiscall RGE_Game_Info::RGE_Game_Info(RGE_Game_Info *this,char *param_1)
{
  long *plVar1;
  char cVar2;
  int iVar3;
  RGE_Person_Info **ppRVar4;
  RGE_Person_Info *pRVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  long version;
  RGE_Game_Info *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d5cb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  plVar1 = &this->people_num;
  this->people_info = (RGE_Person_Info **)0x0;
  *plVar1 = 0;
  this->campaign_num = 0;
  this->campaigns = (RGE_Campaign **)0x0;
  local_10 = this;
  find_campaigns(this);
  uVar6 = 0xffffffff;
  pcVar8 = param_1;
  do {
    pcVar11 = pcVar8;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar11 = pcVar8 + 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar11;
  } while (cVar2 != '\0');
  uVar6 = ~uVar6;
  pcVar8 = pcVar11 + -uVar6;
  pcVar11 = this->save_filename;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar11 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar11 = pcVar11 + 1;
  }
  iVar3 = rge_open(param_1,0x8000);
  if (-1 < iVar3) {
    rge_read(iVar3,&local_10,4);
    if (local_10 == (RGE_Game_Info *)s_1_00._0_4_) {
      rge_read(iVar3,this,4);
      rge_read(iVar3,plVar1,4);
      if (*plVar1 < 1) {
        this->people_info = (RGE_Person_Info **)0x0;
      }
      else {
        ppRVar4 = (RGE_Person_Info **)calloc(*plVar1,4);
        this->people_info = ppRVar4;
        iVar9 = 0;
        if (0 < *plVar1) {
          do {
            pRVar5 = (RGE_Person_Info *)operator_new(0x114);
            local_4 = 0;
            if (pRVar5 == (RGE_Person_Info *)0x0) {
              pRVar5 = (RGE_Person_Info *)0x0;
            }
            else {
              pRVar5 = (RGE_Person_Info *)
                       RGE_Person_Info::RGE_Person_Info
                                 (pRVar5,iVar3,this->campaigns,this->campaign_num);
            }
            iVar10 = iVar9 + 1;
            local_4 = 0xffffffff;
            this->people_info[iVar9] = pRVar5;
            iVar9 = iVar10;
          } while (iVar10 < *plVar1);
          rge_close(iVar3);
          goto LAB_0044d2e3;
        }
      }
      rge_close(iVar3);
      goto LAB_0044d2e3;
    }
  }
  this->current_person = -1;
  *plVar1 = 0;
  this->people_info = (RGE_Person_Info **)0x0;
LAB_0044d2e3:
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Game_Info
// Address: 0044d300
/* public: __thiscall RGE_Game_Info::~RGE_Game_Info(void) */

void __thiscall RGE_Game_Info::~RGE_Game_Info(RGE_Game_Info *this)
{
  RGE_Campaign *this_00;
  RGE_Person_Info *this_01;
  int iVar1;
  
  if (this->save_filename[0] != '\0') {
    save(this,this->save_filename);
  }
  if (this->campaigns != (RGE_Campaign **)0x0) {
    iVar1 = 0;
    if (0 < this->campaign_num) {
      do {
        this_00 = this->campaigns[iVar1];
        if (this_00 != (RGE_Campaign *)0x0) {
          RGE_Campaign::~RGE_Campaign(this_00);
          operator_delete(this_00);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->campaign_num);
    }
    free(this->campaigns);
    this->campaigns = (RGE_Campaign **)0x0;
  }
  if (this->people_info != (RGE_Person_Info **)0x0) {
    iVar1 = 0;
    if (0 < this->people_num) {
      do {
        this_01 = this->people_info[iVar1];
        if (this_01 != (RGE_Person_Info *)0x0) {
          RGE_Person_Info::~RGE_Person_Info(this_01);
          operator_delete(this_01);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->people_num);
    }
    free(this->people_info);
    this->people_info = (RGE_Person_Info **)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0044d3b0
// [HELPER] s_1_00: "1.00"
// [HELPER] s__PIF_Creating_Player_Info_File: "(PIF)Creating Player Info File"
/* public: void __thiscall RGE_Game_Info::save(char *) */

void __thiscall RGE_Game_Info::save(RGE_Game_Info *this,char *param_1)
{
  long *plVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s__PIF_Creating_Player_Info_File);
  uVar4 = 0xffffffff;
  pcVar6 = param_1;
  do {
    pcVar8 = pcVar6;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar6 + 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar8 + -uVar4;
  pcVar8 = this->save_filename;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  }
  iVar3 = rge_open(param_1,0x8309,0x180);
  if (iVar3 != -1) {
    rge_write(iVar3,s_1_00,4);
    rge_write(iVar3,this,4);
    plVar1 = &this->people_num;
    rge_write(iVar3,plVar1,4);
    if ((0 < *plVar1) && (iVar7 = 0, 0 < *plVar1)) {
      do {
        RGE_Person_Info::save(this->people_info[iVar7],iVar3);
        iVar7 = iVar7 + 1;
      } while (iVar7 < *plVar1);
    }
    rge_close(iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: find_campaigns
// Address: 0044d470
// [HELPER] s__s__cpn: "%s*.cpn"
// [HELPER] s__s__cpx: "%s*.cpx"
/* public: void __thiscall RGE_Game_Info::find_campaigns(void) */

void __thiscall RGE_Game_Info::find_campaigns(RGE_Game_Info *this)
{
  int iVar1;
  RGE_Campaign **ppRVar2;
  int iVar3;
  RGE_Campaign *pRVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  _finddata_t file_info;
  char file_name [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d5fc;
  *unaff_FS_OFFSET = &local_c;
  if (this->campaigns != (RGE_Campaign **)0x0) {
    iVar6 = 0;
    if (0 < this->campaign_num) {
      do {
        pRVar4 = this->campaigns[iVar6];
        if (pRVar4 != (RGE_Campaign *)0x0) {
          RGE_Campaign::~RGE_Campaign(pRVar4);
          operator_delete(pRVar4);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < this->campaign_num);
    }
    free(this->campaigns);
    this->campaigns = (RGE_Campaign **)0x0;
  }
  sprintf(file_name + 4,s__s__cpn,rge_base_game->prog_info->campaign_dir);
  iVar1 = __findfirst(file_name + 4,&file_info.time_create);
  this->campaign_num = 0;
  iVar6 = iVar1;
  while (iVar6 != -1) {
    this->campaign_num = this->campaign_num + 1;
    iVar6 = __findnext(iVar1,&file_info.time_create);
  }
  sprintf(file_name + 4,s__s__cpx,rge_base_game->prog_info->campaign_dir);
  iVar1 = __findfirst(file_name + 4,&file_info.time_create);
  iVar6 = iVar1;
  while (iVar6 != -1) {
    this->campaign_num = this->campaign_num + 1;
    iVar6 = __findnext(iVar1,&file_info.time_create);
  }
  iVar6 = 0;
  if (this->campaign_num < 1) {
    this->campaigns = (RGE_Campaign **)0x0;
  }
  else {
    ppRVar2 = (RGE_Campaign **)calloc(this->campaign_num,4);
    this->campaigns = ppRVar2;
    sprintf(file_name + 4,s__s__cpn,rge_base_game->prog_info->campaign_dir);
    iVar3 = __findfirst(file_name + 4,&file_info.time_create);
    iVar1 = iVar3;
    while (iVar1 != -1) {
      file_info.attrib = (uint)operator_new(0x20c);
      local_4 = 0;
      if ((RGE_Campaign *)file_info.attrib == (RGE_Campaign *)0x0) {
        pRVar4 = (RGE_Campaign *)0x0;
      }
      else {
        pRVar4 = (RGE_Campaign *)
                 RGE_Campaign::RGE_Campaign((RGE_Campaign *)file_info.attrib,file_info.name + 4);
      }
      local_4 = 0xffffffff;
      this->campaigns[iVar6] = pRVar4;
      iVar6 = iVar6 + 1;
      iVar1 = __findnext(iVar3,&file_info.time_create);
    }
    sprintf(file_name + 4,s__s__cpx,rge_base_game->prog_info->campaign_dir);
    iVar1 = __findfirst(file_name + 4,&file_info.time_create);
    if (iVar1 != -1) {
      iVar6 = iVar6 << 2;
      while( true ) {
        file_info.attrib = (uint)operator_new(0x20c);
        local_4 = 1;
        if ((RGE_Campaign *)file_info.attrib == (RGE_Campaign *)0x0) {
          uVar5 = 0;
        }
        else {
          uVar5 = RGE_Campaign::RGE_Campaign((RGE_Campaign *)file_info.attrib,file_info.name + 4);
        }
        local_4 = 0xffffffff;
        *(undefined4 *)(iVar6 + (int)this->campaigns) = uVar5;
        iVar3 = __findnext(iVar1,&file_info.time_create);
        if (iVar3 == -1) break;
        iVar6 = iVar6 + 4;
      }
    }
  }
  iVar6 = 0;
  if (0 < this->people_num) {
    do {
      RGE_Person_Info::rehook_campaigns(this->people_info[iVar6],this->campaigns,this->campaign_num)
      ;
      iVar6 = iVar6 + 1;
    } while (iVar6 < this->people_num);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: add_new_person
// Address: 0044d710
/* public: unsigned char __thiscall RGE_Game_Info::add_new_person(char *) */

uchar __thiscall RGE_Game_Info::add_new_person(RGE_Game_Info *this,char *param_1)
{
  RGE_Person_Info **ppRVar1;
  RGE_Person_Info *pRVar2;
  uint uVar3;
  int iVar4;
  RGE_Person_Info **ppRVar5;
  RGE_Person_Info **ppRVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d61b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  ppRVar1 = (RGE_Person_Info **)calloc(this->people_num + 1,4);
  ppRVar5 = this->people_info;
  ppRVar6 = ppRVar1;
  for (uVar3 = this->people_num & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *ppRVar6 = *ppRVar5;
    ppRVar5 = ppRVar5 + 1;
    ppRVar6 = ppRVar6 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)ppRVar6 = *(undefined1 *)ppRVar5;
    ppRVar5 = (RGE_Person_Info **)((int)ppRVar5 + 1);
    ppRVar6 = (RGE_Person_Info **)((int)ppRVar6 + 1);
  }
  free(this->people_info);
  this->people_info = ppRVar1;
  pRVar2 = (RGE_Person_Info *)operator_new(0x114);
  local_4 = 0;
  if (pRVar2 == (RGE_Person_Info *)0x0) {
    pRVar2 = (RGE_Person_Info *)0x0;
  }
  else {
    pRVar2 = (RGE_Person_Info *)
             RGE_Person_Info::RGE_Person_Info(pRVar2,param_1,this->campaigns,this->campaign_num);
  }
  this->people_info[this->people_num] = pRVar2;
  this->current_person = this->people_num;
  this->people_num = this->people_num + 1;
  *unaff_FS_OFFSET = local_c;
  return '\x01';
}

// --------------------------------------------------

// Function: set_current_person
// Address: 0044d7d0
/* public: unsigned char __thiscall RGE_Game_Info::set_current_person(long) */

uchar __thiscall RGE_Game_Info::set_current_person(RGE_Game_Info *this,long param_1)
{
  if (param_1 < this->people_num) {
    this->current_person = param_1;
    return '\x01';
  }
  this->current_person = -1;
  return '\0';
}

// --------------------------------------------------

// Function: set_current_campaign
// Address: 0044d7f0
/* public: unsigned char __thiscall RGE_Game_Info::set_current_campaign(long) */

uchar __thiscall RGE_Game_Info::set_current_campaign(RGE_Game_Info *this,long param_1)
{
  int iVar1;
  uchar uVar2;
  
  iVar1 = this->current_person;
  if ((iVar1 < this->people_num) && (-1 < iVar1)) {
    uVar2 = RGE_Person_Info::set_current_campaign(this->people_info[iVar1],param_1);
    return uVar2;
  }
  return '\0';
}

// --------------------------------------------------

// Function: set_current_scenario
// Address: 0044d820
/* public: unsigned char __thiscall RGE_Game_Info::set_current_scenario(long) */

uchar __thiscall RGE_Game_Info::set_current_scenario(RGE_Game_Info *this,long param_1)
{
  int iVar1;
  uchar uVar2;
  
  iVar1 = this->current_person;
  if ((-1 < iVar1) && (iVar1 < this->people_num)) {
    uVar2 = RGE_Person_Info::set_current_scenario(this->people_info[iVar1],param_1);
    return uVar2;
  }
  return '\0';
}

// --------------------------------------------------

// Function: get_people_list
// Address: 0044d850
/* public: long __thiscall RGE_Game_Info::get_people_list(char * * *,long &) */

long __thiscall RGE_Game_Info::get_people_list(RGE_Game_Info *this,char ***param_1,long *param_2)
{
  char **ppcVar1;
  char *pcVar2;
  int iVar3;
  
  if (0 < this->people_num) {
    ppcVar1 = (char **)calloc(this->people_num,4);
    iVar3 = 0;
    *param_1 = ppcVar1;
    if (0 < this->people_num) {
      do {
        pcVar2 = RGE_Person_Info::get_name(this->people_info[iVar3]);
        getstring(*param_1 + iVar3,pcVar2);
        iVar3 = iVar3 + 1;
      } while (iVar3 < this->people_num);
    }
    *param_2 = this->current_person;
  }
  return this->people_num;
}

// --------------------------------------------------

// Function: get_campaign_list
// Address: 0044d8c0
/* public: long __thiscall RGE_Game_Info::get_campaign_list(char * * *,long &) */

long __thiscall RGE_Game_Info::get_campaign_list(RGE_Game_Info *this,char ***param_1,long *param_2)
{
  char **ppcVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  
  if (0 < this->campaign_num) {
    ppcVar1 = (char **)calloc(this->campaign_num,4);
    iVar4 = 0;
    *param_1 = ppcVar1;
    if (0 < this->campaign_num) {
      do {
        pcVar2 = RGE_Campaign::get_name(this->campaigns[iVar4]);
        getstring(*param_1 + iVar4,pcVar2);
        iVar4 = iVar4 + 1;
      } while (iVar4 < this->campaign_num);
    }
    iVar4 = this->current_person;
    if ((iVar4 < this->people_num) && (-1 < iVar4)) {
      lVar3 = RGE_Person_Info::get_current_campaign(this->people_info[iVar4]);
      *param_2 = lVar3;
    }
  }
  return this->campaign_num;
}

// --------------------------------------------------

// Function: get_scenario_list
// Address: 0044d940
/* public: long __thiscall RGE_Game_Info::get_scenario_list(char * * *,long &) */

long __thiscall RGE_Game_Info::get_scenario_list(RGE_Game_Info *this,char ***param_1,long *param_2)
{
  int iVar1;
  long lVar2;
  
  iVar1 = this->current_person;
  if ((iVar1 < this->people_num) && (-1 < iVar1)) {
    lVar2 = RGE_Person_Info::get_current_scenario(this->people_info[iVar1]);
    *param_2 = lVar2;
    lVar2 = RGE_Person_Info::get_scenario_list
                      (this->people_info[this->current_person],param_1,param_2);
    return lVar2;
  }
  *param_2 = -1;
  return -1;
}

// --------------------------------------------------

// Function: get_current_scenario
// Address: 0044d990
/* public: long __thiscall RGE_Game_Info::get_current_scenario(void) */

long __thiscall RGE_Game_Info::get_current_scenario(RGE_Game_Info *this)
{
  int iVar1;
  long lVar2;
  
  iVar1 = this->current_person;
  if ((iVar1 < this->people_num) && (-1 < iVar1)) {
    lVar2 = RGE_Person_Info::get_current_scenario(this->people_info[iVar1]);
    return lVar2;
  }
  return -1;
}

// --------------------------------------------------

// Function: get_current_campaign
// Address: 0044d9b0
/* public: long __thiscall RGE_Game_Info::get_current_campaign(void) */

long __thiscall RGE_Game_Info::get_current_campaign(RGE_Game_Info *this)
{
  int iVar1;
  long lVar2;
  
  iVar1 = this->current_person;
  if ((iVar1 < this->people_num) && (-1 < iVar1)) {
    lVar2 = RGE_Person_Info::get_current_campaign(this->people_info[iVar1]);
    return lVar2;
  }
  return -1;
}

// --------------------------------------------------

// Function: get_current_player
// Address: 0044d9d0
/* public: long __thiscall RGE_Game_Info::get_current_player(void) */

long __thiscall RGE_Game_Info::get_current_player(RGE_Game_Info *this)
{
  return this->current_person;
}

// --------------------------------------------------

// Function: get_current_player_name
// Address: 0044d9e0
/* public: char * __thiscall RGE_Game_Info::get_current_player_name(void) */

char * __thiscall RGE_Game_Info::get_current_player_name(RGE_Game_Info *this)
{
  char *pcVar1;
  
  if (this->current_person < 0) {
    return (char *)0x0;
  }
  pcVar1 = RGE_Person_Info::get_name(this->people_info[this->current_person]);
  return pcVar1;
}

// --------------------------------------------------

// Function: notify_of_scenario_complete
// Address: 0044da00
/* public: void __thiscall RGE_Game_Info::notify_of_scenario_complete(void) */

void __thiscall RGE_Game_Info::notify_of_scenario_complete(RGE_Game_Info *this)
{
  int iVar1;
  
  iVar1 = this->current_person;
  if ((iVar1 < this->people_num) && (-1 < iVar1)) {
    RGE_Person_Info::notify_of_scenario_complete(this->people_info[iVar1]);
  }
  save(this,this->save_filename);
  return;
}

// --------------------------------------------------

// Function: open_scenario
// Address: 0044da30
/* public: int __thiscall RGE_Game_Info::open_scenario(void) */

int __thiscall RGE_Game_Info::open_scenario(RGE_Game_Info *this)
{
  int iVar1;
  
  iVar1 = this->current_person;
  if ((iVar1 < this->people_num) && (-1 < iVar1)) {
    iVar1 = RGE_Person_Info::open_scenario(this->people_info[iVar1]);
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: remove_player
// Address: 0044da50
/* public: void __thiscall RGE_Game_Info::remove_player(long) */

void __thiscall RGE_Game_Info::remove_player(RGE_Game_Info *this,long param_1)
{
  RGE_Person_Info *this_00;
  int iVar1;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < this->people_num)) {
    this_00 = this->people_info[param_1];
    if (this_00 != (RGE_Person_Info *)0x0) {
      RGE_Person_Info::~RGE_Person_Info(this_00);
      operator_delete(this_00);
    }
    if (param_1 < this->people_num + -1) {
      do {
        iVar1 = param_1 + 1;
        this->people_info[param_1] = this->people_info[iVar1];
        param_1 = iVar1;
      } while (iVar1 < this->people_num + -1);
    }
    iVar1 = this->people_num;
    iVar2 = iVar1 + -1;
    this->people_num = iVar2;
    if (this->current_person == iVar2) {
      this->current_person = iVar1 + -2;
    }
  }
  return;
}

// --------------------------------------------------

