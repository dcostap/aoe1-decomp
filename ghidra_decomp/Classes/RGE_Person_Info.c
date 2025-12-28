// Class: RGE_Person_Info
// Size:  0x114
//
// Member Layout:
// [0x000] char[255] name (sz: 0xFF)
// [0x100] long current_campaign
// [0x104] long campaign_info_num
// [0x108] RGE_Campaign_Info * * campaign_info
// [0x10C] long campaign_num
// [0x110] RGE_Campaign * * campaigns
// ----------------------------------------------------------------

// Function: RGE_Person_Info
// Address: 0044cc40
RGE_Person_Info * __thiscall
RGE_Person_Info::RGE_Person_Info
          (RGE_Person_Info *this,int param_1,RGE_Campaign **param_2,long param_3)
{
  long *plVar1;
  RGE_Campaign_Info **ppRVar2;
  RGE_Campaign_Info *pRVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d58b;
  *unaff_FS_OFFSET = &local_c;
  this->campaign_num = param_3;
  this->campaigns = param_2;
  rge_read(param_1,this,0xff);
  rge_read(param_1,&this->current_campaign,4);
  plVar1 = &this->campaign_info_num;
  rge_read(param_1,plVar1,4);
  if (*plVar1 < 1) {
    this->campaign_info = (RGE_Campaign_Info **)0x0;
  }
  else {
    ppRVar2 = (RGE_Campaign_Info **)calloc(*plVar1,4);
    this->campaign_info = ppRVar2;
    iVar4 = 0;
    if (0 < *plVar1) {
      do {
        pRVar3 = (RGE_Campaign_Info *)operator_new(0x114);
        local_4 = 0;
        if (pRVar3 == (RGE_Campaign_Info *)0x0) {
          pRVar3 = (RGE_Campaign_Info *)0x0;
        }
        else {
          pRVar3 = (RGE_Campaign_Info *)
                   RGE_Campaign_Info::RGE_Campaign_Info
                             (pRVar3,param_1,this->campaigns,this->campaign_num);
        }
        iVar5 = iVar4 + 1;
        local_4 = 0xffffffff;
        this->campaign_info[iVar4] = pRVar3;
        iVar4 = iVar5;
      } while (iVar5 < *plVar1);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Person_Info
// Address: 0044cd40
RGE_Person_Info * __thiscall
RGE_Person_Info::RGE_Person_Info
          (RGE_Person_Info *this,char *param_1,RGE_Campaign **param_2,long param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  RGE_Person_Info *pRVar5;
  
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_1;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pRVar5 = this;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pRVar5->name = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pRVar5 = (RGE_Person_Info *)(pRVar5->name + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    pRVar5->name[0] = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pRVar5 = (RGE_Person_Info *)(pRVar5->name + 1);
  }
  this->campaign_info_num = 0;
  this->campaign_info = (RGE_Campaign_Info **)0x0;
  this->campaigns = param_2;
  this->current_campaign = -1;
  this->campaign_num = param_3;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Person_Info
// Address: 0044cda0
void __thiscall RGE_Person_Info::~RGE_Person_Info(RGE_Person_Info *this)
{
  RGE_Campaign_Info *this_00;
  int iVar1;
  
  if (this->campaign_info != (RGE_Campaign_Info **)0x0) {
    iVar1 = 0;
    if (0 < this->campaign_info_num) {
      do {
        this_00 = this->campaign_info[iVar1];
        if (this_00 != (RGE_Campaign_Info *)0x0) {
          RGE_Campaign_Info::~RGE_Campaign_Info(this_00);
          operator_delete(this_00);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->campaign_info_num);
    }
    free(this->campaign_info);
    this->campaign_info = (RGE_Campaign_Info **)0x0;
    this->campaign_info_num = 0;
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0044ce10
// [HELPER] s__PIF_Saving_player____s: "(PIF)Saving player - %s"
void __thiscall RGE_Person_Info::save(RGE_Person_Info *this,int param_1)
{
  long *plVar1;
  int iVar2;
  
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s__PIF_Saving_player____s,this);
  rge_write(param_1,this,0xff);
  rge_write(param_1,&this->current_campaign,4);
  plVar1 = &this->campaign_info_num;
  rge_write(param_1,plVar1,4);
  iVar2 = 0;
  if (0 < *plVar1) {
    do {
      RGE_Campaign_Info::save(this->campaign_info[iVar2],param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *plVar1);
  }
  return;
}

// --------------------------------------------------

// Function: rehook_campaigns
// Address: 0044ce90
void __thiscall
RGE_Person_Info::rehook_campaigns(RGE_Person_Info *this,RGE_Campaign **param_1,long param_2)
{
  int iVar1;
  
  iVar1 = 0;
  this->campaign_num = param_2;
  this->campaigns = param_1;
  if (0 < this->campaign_info_num) {
    do {
      RGE_Campaign_Info::rehook_campaigns
                (this->campaign_info[iVar1],this->campaigns,this->campaign_num);
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->campaign_info_num);
  }
  return;
}

// --------------------------------------------------

// Function: get_name
// Address: 0044cee0
char * __thiscall RGE_Person_Info::get_name(RGE_Person_Info *this)
{
  return this->name;
}

// --------------------------------------------------

// Function: set_current_campaign
// Address: 0044cef0
uchar __thiscall RGE_Person_Info::set_current_campaign(RGE_Person_Info *this,long param_1)
{
  uchar uVar1;
  char *pcVar2;
  RGE_Campaign_Info **ppRVar3;
  RGE_Campaign_Info *pRVar4;
  uint uVar5;
  int iVar6;
  RGE_Campaign_Info **ppRVar7;
  RGE_Campaign_Info **ppRVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d5ab;
  *unaff_FS_OFFSET = &local_c;
  if (((param_1 < 0) || (this->campaign_num <= param_1)) ||
     (this->campaigns[param_1] == (RGE_Campaign *)0x0)) {
    uVar1 = '\0';
  }
  else {
    iVar6 = 0;
    if (0 < this->campaign_info_num) {
      do {
        pcVar2 = RGE_Campaign::get_name(this->campaigns[param_1]);
        uVar1 = RGE_Campaign_Info::verify_campaign_name(this->campaign_info[iVar6],pcVar2);
        if (uVar1 != '\0') {
          this->current_campaign = iVar6;
          uVar1 = '\x01';
          goto LAB_0044d022;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < this->campaign_info_num);
    }
    ppRVar3 = (RGE_Campaign_Info **)calloc(this->campaign_info_num + 1,4);
    if (this->campaign_info != (RGE_Campaign_Info **)0x0) {
      ppRVar7 = this->campaign_info;
      ppRVar8 = ppRVar3;
      for (uVar5 = this->campaign_info_num & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *ppRVar8 = *ppRVar7;
        ppRVar7 = ppRVar7 + 1;
        ppRVar8 = ppRVar8 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)ppRVar8 = *(undefined1 *)ppRVar7;
        ppRVar7 = (RGE_Campaign_Info **)((int)ppRVar7 + 1);
        ppRVar8 = (RGE_Campaign_Info **)((int)ppRVar8 + 1);
      }
    }
    free(this->campaign_info);
    this->campaign_info = ppRVar3;
    pRVar4 = (RGE_Campaign_Info *)operator_new(0x114);
    local_4 = 0;
    if (pRVar4 == (RGE_Campaign_Info *)0x0) {
      pRVar4 = (RGE_Campaign_Info *)0x0;
    }
    else {
      pRVar4 = (RGE_Campaign_Info *)
               RGE_Campaign_Info::RGE_Campaign_Info(pRVar4,this->campaigns[param_1]);
    }
    this->campaign_info[this->campaign_info_num] = pRVar4;
    this->current_campaign = this->campaign_info_num;
    this->campaign_info_num = this->campaign_info_num + 1;
    uVar1 = '\x01';
  }
LAB_0044d022:
  *unaff_FS_OFFSET = local_c;
  return uVar1;
}

// --------------------------------------------------

// Function: get_current_campaign
// Address: 0044d050
long __thiscall RGE_Person_Info::get_current_campaign(RGE_Person_Info *this)
{
  uchar uVar1;
  char *pcVar2;
  int iVar3;
  
  if (((-1 < this->current_campaign) && (this->current_campaign < this->campaign_info_num)) &&
     (iVar3 = 0, 0 < this->campaign_num)) {
    do {
      pcVar2 = RGE_Campaign::get_name(this->campaigns[iVar3]);
      uVar1 = RGE_Campaign_Info::verify_campaign_name
                        (this->campaign_info[this->current_campaign],pcVar2);
      if (uVar1 != '\0') {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->campaign_num);
    return -1;
  }
  return -1;
}

// --------------------------------------------------

// Function: get_current_scenario
// Address: 0044d0c0
long __thiscall RGE_Person_Info::get_current_scenario(RGE_Person_Info *this)
{
  int iVar1;
  long lVar2;
  
  iVar1 = this->current_campaign;
  if ((-1 < iVar1) && (this->campaigns[iVar1] != (RGE_Campaign *)0x0)) {
    lVar2 = RGE_Campaign_Info::get_current_scenario(this->campaign_info[iVar1]);
    return lVar2;
  }
  return -1;
}

// --------------------------------------------------

// Function: set_current_scenario
// Address: 0044d0f0
uchar __thiscall RGE_Person_Info::set_current_scenario(RGE_Person_Info *this,long param_1)
{
  int iVar1;
  uchar uVar2;
  
  iVar1 = this->current_campaign;
  if ((-1 < iVar1) && (this->campaigns[iVar1] != (RGE_Campaign *)0x0)) {
    uVar2 = RGE_Campaign_Info::set_current_scenario(this->campaign_info[iVar1],param_1);
    return uVar2;
  }
  return '\0';
}

// --------------------------------------------------

// Function: get_scenario_list
// Address: 0044d130
long __thiscall
RGE_Person_Info::get_scenario_list(RGE_Person_Info *this,char ***param_1,long *param_2)
{
  long lVar1;
  
  if (-1 < this->current_campaign) {
    lVar1 = RGE_Campaign_Info::get_scenario_list
                      (this->campaign_info[this->current_campaign],param_1,param_2);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: notify_of_scenario_complete
// Address: 0044d160
void __thiscall RGE_Person_Info::notify_of_scenario_complete(RGE_Person_Info *this)
{
  if (-1 < this->current_campaign) {
    RGE_Campaign_Info::notify_of_scenario_complete(this->campaign_info[this->current_campaign]);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: open_scenario
// Address: 0044d180
int __thiscall RGE_Person_Info::open_scenario(RGE_Person_Info *this)
{
  int iVar1;
  
  if (-1 < this->current_campaign) {
    iVar1 = RGE_Campaign_Info::open_scenario(this->campaign_info[this->current_campaign]);
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

