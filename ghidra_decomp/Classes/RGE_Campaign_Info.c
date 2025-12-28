// Class: RGE_Campaign_Info
// Size:  0x114
//
// Member Layout:
// [0x000] char[255] campaign_name (sz: 0xFF)
// [0x100] long current_scenario
// [0x104] long scenario_num
// [0x108] RGE_Scenario_Info * scenario_info
// [0x10C] long last_scenario
// [0x110] RGE_Campaign * campaign
// ----------------------------------------------------------------

// Function: RGE_Campaign_Info
// Address: 0044c5a0
RGE_Campaign_Info * __thiscall
RGE_Campaign_Info::RGE_Campaign_Info
          (RGE_Campaign_Info *this,int param_1,RGE_Campaign **param_2,long param_3)
{
  long *plVar1;
  byte bVar2;
  RGE_Campaign *this_00;
  RGE_Scenario_Info *pRVar3;
  byte *pbVar4;
  int iVar5;
  long lVar6;
  RGE_Scenario_Info *pRVar7;
  uint uVar8;
  uint uVar9;
  RGE_Campaign_Info *pRVar10;
  RGE_Scenario_Info *pRVar11;
  bool bVar12;
  undefined4 uVar13;
  
  rge_read(param_1,this,0xff);
  rge_read(param_1,&this->current_scenario,4);
  plVar1 = &this->scenario_num;
  rge_read(param_1,plVar1,4);
  rge_read(param_1,&this->last_scenario,4);
  if (*plVar1 < 1) {
    this->scenario_info = (RGE_Scenario_Info *)0x0;
  }
  else {
    pRVar3 = (RGE_Scenario_Info *)calloc(*plVar1,1);
    this->scenario_info = pRVar3;
    rge_read(param_1,pRVar3,*plVar1);
  }
  this->campaign = (RGE_Campaign *)0x0;
  if (0 < param_3) {
    param_1 = (int)param_2;
    do {
      pbVar4 = (byte *)RGE_Campaign::get_name(*(RGE_Campaign **)param_1);
      pRVar10 = this;
      do {
        bVar2 = *pbVar4;
        bVar12 = bVar2 < (byte)pRVar10->campaign_name[0];
        if (bVar2 != pRVar10->campaign_name[0]) {
LAB_0044c66c:
          iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_0044c671;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar12 = bVar2 < (byte)pRVar10->campaign_name[1];
        if (bVar2 != pRVar10->campaign_name[1]) goto LAB_0044c66c;
        pbVar4 = pbVar4 + 2;
        pRVar10 = (RGE_Campaign_Info *)(pRVar10->campaign_name + 2);
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_0044c671:
      if (iVar5 == 0) {
        this_00 = *(RGE_Campaign **)param_1;
        this->campaign = this_00;
        lVar6 = RGE_Campaign::scenario_number(this_00);
        if (this->scenario_num != lVar6) {
          lVar6 = RGE_Campaign::scenario_number(this->campaign);
          if (lVar6 < this->scenario_num) {
            uVar13 = 1;
            lVar6 = RGE_Campaign::scenario_number(this->campaign);
            pRVar7 = (RGE_Scenario_Info *)calloc(lVar6,uVar13);
            uVar9 = this->scenario_num;
            lVar6 = RGE_Campaign::scenario_number(this->campaign);
            pRVar3 = pRVar7;
            if ((int)uVar9 < lVar6) {
              pRVar11 = this->scenario_info;
              for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined4 *)pRVar3 = *(undefined4 *)pRVar11;
                pRVar11 = pRVar11 + 4;
                pRVar3 = pRVar3 + 4;
              }
            }
            else {
              uVar9 = RGE_Campaign::scenario_number(this->campaign);
              pRVar11 = this->scenario_info;
              for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined4 *)pRVar3 = *(undefined4 *)pRVar11;
                pRVar11 = pRVar11 + 4;
                pRVar3 = pRVar3 + 4;
              }
            }
            for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
              pRVar3->scenario_status = pRVar11->scenario_status;
              pRVar11 = pRVar11 + 1;
              pRVar3 = pRVar3 + 1;
            }
            free(this->scenario_info);
            this->scenario_info = pRVar7;
          }
          lVar6 = RGE_Campaign::scenario_number(this->campaign);
          this->scenario_num = lVar6;
          if (lVar6 <= this->last_scenario) {
            this->last_scenario = lVar6 + -1;
          }
          if (this->last_scenario < this->current_scenario) {
            this->current_scenario = this->last_scenario;
          }
        }
      }
      param_1 = param_1 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Campaign_Info
// Address: 0044c780
// [HELPER] s_: ""
RGE_Campaign_Info * __thiscall
RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign_Info *this,RGE_Campaign *param_1)
{
  char cVar1;
  char *pcVar2;
  long lVar3;
  RGE_Scenario_Info *pRVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  RGE_Campaign_Info *pRVar8;
  
  if (param_1 == (RGE_Campaign *)0x0) {
    uVar5 = 0xffffffff;
    this->campaign = (RGE_Campaign *)0x0;
    pcVar2 = s_;
    do {
      pcVar7 = pcVar2;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar2 = pcVar7 + -uVar5;
    pRVar8 = this;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pRVar8->campaign_name = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pRVar8 = (RGE_Campaign_Info *)(pRVar8->campaign_name + 4);
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      pRVar8->campaign_name[0] = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pRVar8 = (RGE_Campaign_Info *)(pRVar8->campaign_name + 1);
    }
    this->current_scenario = 0;
    this->last_scenario = 0;
    this->scenario_num = 0;
    this->scenario_info = (RGE_Scenario_Info *)0x0;
    return this;
  }
  this->campaign = param_1;
  pcVar2 = RGE_Campaign::get_name(param_1);
  uVar5 = 0xffffffff;
  do {
    pcVar7 = pcVar2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar2 = pcVar7 + -uVar5;
  pRVar8 = this;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pRVar8->campaign_name = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pRVar8 = (RGE_Campaign_Info *)(pRVar8->campaign_name + 4);
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    pRVar8->campaign_name[0] = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pRVar8 = (RGE_Campaign_Info *)(pRVar8->campaign_name + 1);
  }
  lVar3 = RGE_Campaign::scenario_number(this->campaign);
  this->scenario_num = lVar3;
  if (0 < lVar3) {
    this->current_scenario = 0;
    this->last_scenario = 0;
    pRVar4 = (RGE_Scenario_Info *)calloc(lVar3,1);
    this->scenario_info = pRVar4;
    pRVar4->scenario_status = '\x02';
    return this;
  }
  this->scenario_info = (RGE_Scenario_Info *)0x0;
  this->current_scenario = -1;
  this->last_scenario = -1;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Campaign_Info
// Address: 0044c870
void __thiscall RGE_Campaign_Info::~RGE_Campaign_Info(RGE_Campaign_Info *this)
{
  if (this->scenario_info != (RGE_Scenario_Info *)0x0) {
    free(this->scenario_info);
    this->scenario_info = (RGE_Scenario_Info *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0044c8a0
// [HELPER] s____PIF_Saving_campaign_____d___s: "  (PIF)Saving campaign - (%d) %s"
void __thiscall RGE_Campaign_Info::save(RGE_Campaign_Info *this,int param_1)
{
  int iVar1;
  
  TDebuggingLog::Log(L,(char *)L,s____PIF_Saving_campaign_____d___s,this->last_scenario,this);
  rge_write(param_1,this,0xff);
  rge_write(param_1,&this->current_scenario,4);
  rge_write(param_1,&this->scenario_num,4);
  rge_write(param_1,&this->last_scenario,4);
  iVar1 = this->scenario_num;
  if (0 < iVar1) {
    rge_write(param_1,this->scenario_info,iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: rehook_campaigns
// Address: 0044c930
void __thiscall
RGE_Campaign_Info::rehook_campaigns(RGE_Campaign_Info *this,RGE_Campaign **param_1,long param_2)
{
  byte bVar1;
  RGE_Campaign *this_00;
  byte *pbVar2;
  int iVar3;
  long lVar4;
  RGE_Scenario_Info *pRVar5;
  uint uVar6;
  uint uVar7;
  RGE_Scenario_Info *pRVar8;
  RGE_Campaign_Info *pRVar9;
  RGE_Scenario_Info *pRVar10;
  bool bVar11;
  undefined4 uVar12;
  
  lVar4 = param_2;
  this->campaign = (RGE_Campaign *)0x0;
  if (0 < param_2) {
    param_2 = (long)param_1;
    param_1 = (RGE_Campaign **)lVar4;
    do {
      pbVar2 = (byte *)RGE_Campaign::get_name(*(RGE_Campaign **)param_2);
      pRVar9 = this;
      do {
        bVar1 = *pbVar2;
        bVar11 = bVar1 < (byte)pRVar9->campaign_name[0];
        if (bVar1 != pRVar9->campaign_name[0]) {
LAB_0044c98c:
          iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0044c991;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar11 = bVar1 < (byte)pRVar9->campaign_name[1];
        if (bVar1 != pRVar9->campaign_name[1]) goto LAB_0044c98c;
        pbVar2 = pbVar2 + 2;
        pRVar9 = (RGE_Campaign_Info *)(pRVar9->campaign_name + 2);
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0044c991:
      if (iVar3 == 0) {
        this_00 = *(RGE_Campaign **)param_2;
        this->campaign = this_00;
        lVar4 = RGE_Campaign::scenario_number(this_00);
        if (this->scenario_num != lVar4) {
          uVar12 = 1;
          lVar4 = RGE_Campaign::scenario_number(this->campaign);
          pRVar5 = (RGE_Scenario_Info *)calloc(lVar4,uVar12);
          uVar7 = this->scenario_num;
          lVar4 = RGE_Campaign::scenario_number(this->campaign);
          pRVar10 = pRVar5;
          if ((int)uVar7 < lVar4) {
            pRVar8 = this->scenario_info;
            for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined4 *)pRVar10 = *(undefined4 *)pRVar8;
              pRVar8 = pRVar8 + 4;
              pRVar10 = pRVar10 + 4;
            }
          }
          else {
            uVar7 = RGE_Campaign::scenario_number(this->campaign);
            pRVar8 = this->scenario_info;
            for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined4 *)pRVar10 = *(undefined4 *)pRVar8;
              pRVar8 = pRVar8 + 4;
              pRVar10 = pRVar10 + 4;
            }
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            pRVar10->scenario_status = pRVar8->scenario_status;
            pRVar8 = pRVar8 + 1;
            pRVar10 = pRVar10 + 1;
          }
          free(this->scenario_info);
          this->scenario_info = pRVar5;
        }
        lVar4 = RGE_Campaign::scenario_number(this->campaign);
        this->scenario_num = lVar4;
        if (lVar4 <= this->last_scenario) {
          this->last_scenario = lVar4 + -1;
        }
        if (this->last_scenario < this->current_scenario) {
          this->current_scenario = this->last_scenario;
        }
      }
      param_2 = param_2 + 4;
      param_1 = (RGE_Campaign **)((int)param_1 + -1);
    } while (param_1 != (RGE_Campaign **)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: set_current_scenario
// Address: 0044ca90
uchar __thiscall RGE_Campaign_Info::set_current_scenario(RGE_Campaign_Info *this,long param_1)
{
  if ((param_1 < this->scenario_num) && (this->scenario_info[param_1].scenario_status != '\0')) {
    if (this->last_scenario < param_1) {
      this->current_scenario = this->last_scenario;
      return '\x01';
    }
    this->current_scenario = param_1;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: verify_campaign_name
// Address: 0044cad0
uchar __thiscall RGE_Campaign_Info::verify_campaign_name(RGE_Campaign_Info *this,char *param_1)
{
  byte bVar1;
  bool bVar2;
  
  while( true ) {
    bVar1 = this->campaign_name[0];
    bVar2 = bVar1 < (byte)*param_1;
    if (bVar1 != *param_1) break;
    if (bVar1 == 0) {
      return '\x01';
    }
    bVar1 = this->campaign_name[1];
    bVar2 = bVar1 < ((byte *)param_1)[1];
    if (bVar1 != ((byte *)param_1)[1]) break;
    this = (RGE_Campaign_Info *)(this->campaign_name + 2);
    param_1 = (char *)((byte *)param_1 + 2);
    if (bVar1 == 0) {
      return '\x01';
    }
  }
  return 1 - bVar2 == (uint)(bVar2 != 0);
}

// --------------------------------------------------

// Function: get_scenario_list
// Address: 0044cb20
long __thiscall
RGE_Campaign_Info::get_scenario_list(RGE_Campaign_Info *this,char ***param_1,long *param_2)
{
  char **ppcVar1;
  char *pcVar2;
  int iVar3;
  
  if (this->campaign != (RGE_Campaign *)0x0) {
    ppcVar1 = (char **)calloc(this->last_scenario + 1,4);
    iVar3 = 0;
    *param_1 = ppcVar1;
    if (-1 < this->last_scenario) {
      do {
        pcVar2 = RGE_Campaign::get_scenario_name(this->campaign,iVar3);
        getstring(*param_1 + iVar3,pcVar2);
        iVar3 = iVar3 + 1;
      } while (iVar3 <= this->last_scenario);
    }
    *param_2 = this->current_scenario;
    return this->last_scenario + 1;
  }
  *param_2 = -1;
  return -1;
}

// --------------------------------------------------

// Function: get_current_scenario
// Address: 0044cbb0
long __thiscall RGE_Campaign_Info::get_current_scenario(RGE_Campaign_Info *this)
{
  return this->current_scenario;
}

// --------------------------------------------------

// Function: notify_of_scenario_complete
// Address: 0044cbc0
void __thiscall RGE_Campaign_Info::notify_of_scenario_complete(RGE_Campaign_Info *this)
{
  int iVar1;
  
  if (-1 < this->current_scenario) {
    this->scenario_info[this->current_scenario].scenario_status = '\x01';
    if (this->last_scenario <= this->current_scenario) {
      iVar1 = this->current_scenario + 1;
      this->last_scenario = iVar1;
      set_current_scenario(this,iVar1);
    }
    if (this->scenario_num <= this->last_scenario) {
      this->last_scenario = this->scenario_num + -1;
    }
    this->scenario_info[this->last_scenario].scenario_status = '\x02';
  }
  return;
}

// --------------------------------------------------

// Function: open_scenario
// Address: 0044cc20
int __thiscall RGE_Campaign_Info::open_scenario(RGE_Campaign_Info *this)
{
  int iVar1;
  
  if (-1 < this->current_scenario) {
    iVar1 = RGE_Campaign::open_scenario(this->campaign,this->current_scenario);
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

