// Class: RGE_Scenario
// Size:  0x1990
//
// VTable Layout:
// [00] get_object_pointer
// [01] `scalar_deleting_destructor'
// [02] rehook
// [03] save
//
// Member Layout:
// [0x004] RGE_Timeline * time_line
// [0x008] RGE_Game_World * world
// [0x00C] uchar victory_conquest
// [0x00D] PlayerName[16] player_name (sz: 0x1000)
// [0x1010] char * scenario_name
// [0x1014] char * description
// [0x1018] char * hints
// [0x101C] char * win_message
// [0x1020] char * loss_message
// [0x1024] char * historicle_notes
// [0x1028] char[224] TempText1 (sz: 0xE0)
// [0x1108] char[224] TempText2 (sz: 0xE0)
// [0x11E8] char[224] TempText3 (sz: 0xE0)
// [0x12C8] char *[16] BuildList (sz: 0x40)
// [0x1308] char *[16] CityPlan (sz: 0x40)
// [0x1348] char *[16] AiRules (sz: 0x40)
// [0x1388] uchar *[16] BuildListFile (sz: 0x40)
// [0x13C8] uchar *[16] CityPlanFile (sz: 0x40)
// [0x1408] uchar *[16] AiRulesFile (sz: 0x40)
// [0x1448] int[16] BuildListFileSize (sz: 0x40)
// [0x1488] int[16] CityPlanFileSize (sz: 0x40)
// [0x14C8] int[16] AiRulesFileSize (sz: 0x40)
// [0x1508] char[224] Cine_PreGame (sz: 0xE0)
// [0x15E8] char[224] Cine_Victory (sz: 0xE0)
// [0x16C8] char[224] Cine_Loss (sz: 0xE0)
// [0x17A8] char[224] Mission_Bmp (sz: 0xE0)
// [0x1888] float Version
// [0x188C] int[16] PlayerPosture (sz: 0x40)
// [0x18CC] int[16] PlType (sz: 0x40)
// [0x190C] int[16] PlCivilization (sz: 0x40)
// [0x194C] int[16] PlActive (sz: 0x40)
// [0x198C] TPicture * mission_picture
// ----------------------------------------------------------------

// Function: RGE_Scenario
// Address: 0048ad60
RGE_Scenario * __thiscall RGE_Scenario::RGE_Scenario(RGE_Scenario *this,RGE_Game_World *param_1)
{
  RGE_Timeline *pRVar1;
  int iVar2;
  PlayerName *pPVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e7bb;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  this->world = param_1;
  pRVar1 = (RGE_Timeline *)operator_new(0x14);
  local_4 = 0;
  if (pRVar1 == (RGE_Timeline *)0x0) {
    pRVar1 = (RGE_Timeline *)0x0;
  }
  else {
    pRVar1 = (RGE_Timeline *)RGE_Timeline::RGE_Timeline(pRVar1,this->world);
  }
  local_4 = 0xffffffff;
  this->time_line = pRVar1;
  InitializeTextValues(this);
  this->mission_picture = (TPicture *)0x0;
  this->victory_conquest = '\x01';
  pPVar3 = this->player_name;
  for (iVar2 = 0x400; iVar2 != 0; iVar2 = iVar2 + -1) {
    pPVar3->Name[0] = '\0';
    pPVar3->Name[1] = '\0';
    pPVar3->Name[2] = '\0';
    pPVar3->Name[3] = '\0';
    pPVar3 = (PlayerName *)(pPVar3->Name + 4);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0048adf0
void * __thiscall RGE_Scenario::_scalar_deleting_destructor_(RGE_Scenario *this,uint param_1)
{
  ~RGE_Scenario(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Scenario
// Address: 0048ae10
RGE_Scenario * __thiscall
RGE_Scenario::RGE_Scenario(RGE_Scenario *this,int param_1,RGE_Game_World *param_2)
{
  int *piVar1;
  RGE_Timeline *pRVar2;
  char *pcVar3;
  TPicture *pTVar4;
  uchar *puVar5;
  int iVar6;
  PlayerName *pPVar7;
  char **ppcVar8;
  int *piVar9;
  undefined4 *unaff_FS_OFFSET;
  short length;
  short local_f6;
  int val;
  char text [224];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e7ec;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  this->world = param_2;
  InitializeTextValues(this);
  rge_read(param_1,&this->Version,4);
  if (_DAT_00572138 < this->Version) {
    pPVar7 = this->player_name;
    iVar6 = 0x10;
    do {
      rge_read(param_1,pPVar7,0x100);
      pPVar7 = pPVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if ((float)_DAT_00572140 < this->Version) {
    piVar9 = this->PlType;
    iVar6 = 0x10;
    do {
      rge_read(param_1,piVar9 + 0x20,4);
      rge_read(param_1,piVar9,4);
      rge_read(param_1,piVar9 + 0x10,4);
      rge_read(param_1,piVar9 + -0x10,4);
      piVar9 = piVar9 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (this->Version < (float)_DAT_00572148) {
    this->victory_conquest = '\x01';
  }
  else {
    rge_read(param_1,&this->victory_conquest,1);
  }
  val = (int)operator_new(0x14);
  local_4 = 0;
  if ((RGE_Timeline *)val == (RGE_Timeline *)0x0) {
    pRVar2 = (RGE_Timeline *)0x0;
  }
  else {
    pRVar2 = (RGE_Timeline *)RGE_Timeline::RGE_Timeline((RGE_Timeline *)val,param_1,this->world);
  }
  this->time_line = pRVar2;
  local_4 = 0xffffffff;
  rge_read(param_1,&local_f6,2);
  if (0 < local_f6) {
    rge_read(param_1,this->scenario_name,(int)local_f6);
  }
  this->scenario_name[local_f6] = '\0';
  rge_read(param_1,&local_f6,2);
  if (local_f6 < 1) {
    this->description = (char *)0x0;
  }
  else {
    pcVar3 = (char *)calloc((int)local_f6,1);
    this->description = pcVar3;
    rge_read(param_1,pcVar3,(int)local_f6);
    this->description[local_f6 + -1] = '\0';
  }
  if (this->Version < (float)_DAT_00572150) {
    this->hints = (char *)0x0;
    this->win_message = (char *)0x0;
    this->loss_message = (char *)0x0;
  }
  else {
    rge_read(param_1,&local_f6,2);
    if (local_f6 < 1) {
      this->hints = (char *)0x0;
    }
    else {
      pcVar3 = (char *)calloc((int)local_f6,1);
      this->hints = pcVar3;
      rge_read(param_1,pcVar3,(int)local_f6);
      this->hints[local_f6 + -1] = '\0';
    }
    rge_read(param_1,&local_f6,2);
    if (local_f6 < 1) {
      this->win_message = (char *)0x0;
    }
    else {
      pcVar3 = (char *)calloc((int)local_f6,1);
      this->win_message = pcVar3;
      rge_read(param_1,pcVar3,(int)local_f6);
      this->win_message[local_f6 + -1] = '\0';
    }
    rge_read(param_1,&local_f6,2);
    if (local_f6 < 1) {
      this->loss_message = (char *)0x0;
    }
    else {
      pcVar3 = (char *)calloc((int)local_f6,1);
      this->loss_message = pcVar3;
      rge_read(param_1,pcVar3,(int)local_f6);
      this->loss_message[local_f6 + -1] = '\0';
    }
    rge_read(param_1,&local_f6,2);
    if (0 < local_f6) {
      pcVar3 = (char *)calloc((int)local_f6,1);
      this->historicle_notes = pcVar3;
      rge_read(param_1,pcVar3,(int)local_f6);
      goto LAB_0048b152;
    }
  }
  this->historicle_notes = (char *)0x0;
LAB_0048b152:
  if (this->Version < _DAT_00572158) {
    rge_read(param_1,&local_f6,2);
    if (0 < local_f6) {
      rge_read(param_1,text + 4,(int)local_f6);
    }
    rge_read(param_1,&local_f6,2);
    if (0 < local_f6) {
      rge_read(param_1,text + 4,(int)local_f6);
    }
    rge_read(param_1,&local_f6,2);
    if (0 < local_f6) {
      rge_read(param_1,text + 4,(int)local_f6);
    }
  }
  rge_read(param_1,&local_f6,2);
  if (0 < local_f6) {
    rge_read(param_1,this->Cine_PreGame,(int)local_f6);
  }
  this->Cine_PreGame[local_f6] = '\0';
  rge_read(param_1,&local_f6,2);
  if (0 < local_f6) {
    rge_read(param_1,this->Cine_Victory,(int)local_f6);
  }
  this->Cine_Victory[local_f6] = '\0';
  rge_read(param_1,&local_f6,2);
  if (0 < local_f6) {
    rge_read(param_1,this->Cine_Loss,(int)local_f6);
  }
  this->Cine_Loss[local_f6] = '\0';
  if ((float)_DAT_00572160 <= this->Version) {
    rge_read(param_1,&local_f6,2);
    if (0 < local_f6) {
      rge_read(param_1,this->Mission_Bmp,(int)local_f6);
    }
    this->Mission_Bmp[local_f6] = '\0';
  }
  if (this->Version < (float)_DAT_00572168) {
    this->mission_picture = (TPicture *)0x0;
  }
  else {
    val = (int)operator_new(0x20);
    local_4 = 1;
    if ((TPicture *)val == (TPicture *)0x0) {
      local_4 = 0xffffffff;
      this->mission_picture = (TPicture *)0x0;
    }
    else {
      pTVar4 = (TPicture *)TPicture::TPicture((TPicture *)val,param_1,1);
      local_4 = 0xffffffff;
      this->mission_picture = pTVar4;
    }
  }
  ppcVar8 = this->BuildList;
  iVar6 = 0x10;
  do {
    rge_read(param_1,&local_f6,2);
    if (0 < local_f6) {
      rge_read(param_1,*ppcVar8,(int)local_f6);
    }
    pcVar3 = *ppcVar8;
    ppcVar8 = ppcVar8 + 1;
    iVar6 = iVar6 + -1;
    pcVar3[local_f6] = '\0';
  } while (iVar6 != 0);
  ppcVar8 = this->CityPlan;
  iVar6 = 0x10;
  do {
    rge_read(param_1,&local_f6,2);
    if (0 < local_f6) {
      rge_read(param_1,*ppcVar8,(int)local_f6);
    }
    pcVar3 = *ppcVar8;
    ppcVar8 = ppcVar8 + 1;
    iVar6 = iVar6 + -1;
    pcVar3[local_f6] = '\0';
  } while (iVar6 != 0);
  if ((float)_DAT_00572170 <= this->Version) {
    ppcVar8 = this->AiRules;
    iVar6 = 0x10;
    do {
      rge_read(param_1,&local_f6,2);
      if (0 < local_f6) {
        rge_read(param_1,*ppcVar8,(int)local_f6);
      }
      pcVar3 = *ppcVar8;
      ppcVar8 = ppcVar8 + 1;
      iVar6 = iVar6 + -1;
      pcVar3[local_f6] = '\0';
    } while (iVar6 != 0);
  }
  piVar9 = this->BuildListFileSize;
  val = 0x10;
  do {
    rge_read(param_1,piVar9,4);
    piVar1 = piVar9 + 0x10;
    rge_read(param_1,piVar1,4);
    if ((float)_DAT_00572170 <= this->Version) {
      rge_read(param_1,piVar9 + 0x20,4);
    }
    piVar9[-0x30] = 0;
    piVar9[-0x20] = 0;
    piVar9[-0x10] = 0;
    if (_DAT_00572178 <= this->Version) {
      if (0 < *piVar9) {
        puVar5 = (uchar *)calloc(*piVar9,1);
        piVar9[-0x30] = (int)puVar5;
        rge_read(param_1,puVar5,*piVar9);
      }
      if (0 < *piVar1) {
        puVar5 = (uchar *)calloc(*piVar1,1);
        piVar9[-0x20] = (int)puVar5;
        rge_read(param_1,puVar5,*piVar1);
      }
      if (0 < piVar9[0x20]) {
        puVar5 = (uchar *)calloc(piVar9[0x20],1);
        piVar9[-0x10] = (int)puVar5;
        rge_read(param_1,puVar5,piVar9[0x20]);
      }
    }
    piVar9 = piVar9 + 1;
    val = val + -1;
  } while (val != 0);
  text[0] = '\0';
  text[1] = '\0';
  text[2] = '\0';
  text[3] = '\0';
  if (_DAT_0057217c < this->Version) {
    rge_read(param_1,text,4);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: get_object_pointer
// Address: 0048b580
RGE_Static_Object * __thiscall RGE_Scenario::get_object_pointer(RGE_Scenario *this,int param_1)
{
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: rehook
// Address: 0048b590
void __thiscall RGE_Scenario::rehook(RGE_Scenario *this)
{
  return;
}

// --------------------------------------------------

// Function: ~RGE_Scenario
// Address: 0048b5a0
void __thiscall RGE_Scenario::~RGE_Scenario(RGE_Scenario *this)
{
  TPicture *this_00;
  char **ppcVar1;
  int iVar2;
  
  this->_padding_ = (int)&_vftable_;
  if (this->time_line != (RGE_Timeline *)0x0) {
    (**(code **)this->time_line->_padding_)(1);
    this->time_line = (RGE_Timeline *)0x0;
  }
  if (this->description != (char *)0x0) {
    free(this->description);
  }
  if (this->hints != (char *)0x0) {
    free(this->hints);
  }
  if (this->win_message != (char *)0x0) {
    free(this->win_message);
  }
  if (this->loss_message != (char *)0x0) {
    free(this->loss_message);
  }
  if (this->historicle_notes != (char *)0x0) {
    free(this->historicle_notes);
  }
  operator_delete(this->scenario_name);
  this_00 = this->mission_picture;
  if (this_00 != (TPicture *)0x0) {
    TPicture::~TPicture(this_00);
    operator_delete(this_00);
    this->mission_picture = (TPicture *)0x0;
  }
  ppcVar1 = this->CityPlan;
  iVar2 = 0x10;
  do {
    operator_delete(ppcVar1[-0x10]);
    operator_delete(*ppcVar1);
    operator_delete(ppcVar1[0x10]);
    if ((uchar *)ppcVar1[0x20] != (uchar *)0x0) {
      free(ppcVar1[0x20]);
    }
    if ((uchar *)ppcVar1[0x30] != (uchar *)0x0) {
      free(ppcVar1[0x30]);
    }
    if ((uchar *)ppcVar1[0x40] != (uchar *)0x0) {
      free(ppcVar1[0x40]);
    }
    ppcVar1 = ppcVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: InitializeTextValues
// Address: 0048b6c0
void __thiscall RGE_Scenario::InitializeTextValues(RGE_Scenario *this)
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  PlayerName *pPVar9;
  char none_string [30];
  char default_string [30];
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x2775,none_string + 4,0x1e);
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x277b,none_string + 0x18,0x1e);
  this->description = (char *)0x0;
  this->hints = (char *)0x0;
  this->win_message = (char *)0x0;
  this->loss_message = (char *)0x0;
  this->historicle_notes = (char *)0x0;
  pcVar2 = (char *)operator_new(0xe0);
  this->scenario_name = pcVar2;
  for (iVar3 = 0x38; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + 4;
  }
  uVar4 = 0xffffffff;
  pcVar2 = &stack0xffffffa8;
  do {
    pcVar8 = pcVar2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar2 = pcVar8 + -uVar4;
  pcVar8 = this->Cine_PreGame;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar2 = &stack0xffffffa8;
  do {
    pcVar8 = pcVar2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar2 = pcVar8 + -uVar4;
  pcVar8 = this->Cine_Victory;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar2 = &stack0xffffffa8;
  do {
    pcVar8 = pcVar2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar2 = pcVar8 + -uVar4;
  pcVar8 = this->Cine_Loss;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar2 = &stack0xffffffa8;
  do {
    pcVar8 = pcVar2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar3 = 0x10;
  pcVar2 = pcVar8 + -uVar4;
  pcVar8 = this->Mission_Bmp;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar8 = pcVar8 + 1;
  }
  pPVar9 = this->player_name;
  piVar7 = this->PlType;
  do {
    piVar7[-0x10] = 0;
    *piVar7 = 0;
    piVar7[0x10] = 0;
    piVar7[0x20] = 0;
    pPVar9->Name[0] = '\0';
    pcVar2 = (char *)operator_new(0xe0);
    piVar7[-0x181] = (int)pcVar2;
    for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2 = pcVar2 + 4;
    }
    uVar4 = 0xffffffff;
    pcVar2 = none_string + 0xc;
    do {
      pcVar8 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar8 + -uVar4;
    pcVar8 = (char *)piVar7[-0x181];
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcVar2 = (char *)operator_new(0xe0);
    piVar7[-0x171] = (int)pcVar2;
    for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2 = pcVar2 + 4;
    }
    uVar4 = 0xffffffff;
    pcVar2 = &stack0xffffffa8;
    do {
      pcVar8 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar8 + -uVar4;
    pcVar8 = (char *)piVar7[-0x171];
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcVar2 = (char *)operator_new(0xe0);
    piVar7[-0x161] = (int)pcVar2;
    for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2 = pcVar2 + 4;
    }
    uVar4 = 0xffffffff;
    pcVar2 = none_string + 0xc;
    do {
      pcVar8 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar8 + -uVar4;
    pcVar8 = (char *)piVar7[-0x161];
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar8 = pcVar8 + 1;
    }
    piVar7[-0x151] = 0;
    piVar7[-0x141] = 0;
    piVar7[-0x131] = 0;
    piVar7[-0x121] = 0;
    piVar7[-0x111] = 0;
    piVar7[-0x101] = 0;
    pPVar9 = pPVar9 + 1;
    iVar3 = iVar3 + -1;
    piVar7 = piVar7 + 1;
    if (iVar3 == 0) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: Set_scenario_name
// Address: 0048b910
void __thiscall RGE_Scenario::Set_scenario_name(RGE_Scenario *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    *this->scenario_name = '\0';
    return;
  }
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
  pcVar5 = this->scenario_name;
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

// Function: Set_description
// Address: 0048b950
void __thiscall RGE_Scenario::Set_description(RGE_Scenario *this,char *param_1)
{
  Set_message(this,param_1,0);
  return;
}

// --------------------------------------------------

// Function: Set_Cine_PreGame
// Address: 0048b960
void __thiscall RGE_Scenario::Set_Cine_PreGame(RGE_Scenario *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    this->Cine_PreGame[0] = '\0';
    return;
  }
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
  pcVar5 = this->Cine_PreGame;
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

// Function: Set_Cine_Victory
// Address: 0048b9a0
void __thiscall RGE_Scenario::Set_Cine_Victory(RGE_Scenario *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    this->Cine_Victory[0] = '\0';
    return;
  }
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
  pcVar5 = this->Cine_Victory;
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

// Function: Set_Cine_Loss
// Address: 0048b9e0
void __thiscall RGE_Scenario::Set_Cine_Loss(RGE_Scenario *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    this->Cine_Loss[0] = '\0';
    return;
  }
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
  pcVar5 = this->Cine_Loss;
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

// Function: Set_Mission_Bmp
// Address: 0048ba20
void __thiscall RGE_Scenario::Set_Mission_Bmp(RGE_Scenario *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    this->Mission_Bmp[0] = '\0';
    return;
  }
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
  pcVar5 = this->Mission_Bmp;
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

// Function: Set_BuildList
// Address: 0048ba60
void __thiscall
RGE_Scenario::Set_BuildList(RGE_Scenario *this,int param_1,char *param_2,int param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char **ppcVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_2 == (char *)0x0) {
    ppcVar4 = this->BuildList + param_1;
    *this->BuildList[param_1] = '\0';
  }
  else {
    ppcVar4 = this->BuildList + param_1;
    uVar2 = 0xffffffff;
    pcVar5 = param_2;
    do {
      pcVar6 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar6 + -uVar2;
    pcVar6 = *ppcVar4;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  if (param_3 == 1) {
    uVar2 = 0xffffffff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *param_2;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    (*ppcVar4)[~uVar2 - 5] = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: Set_CityPlan
// Address: 0048bad0
void __thiscall RGE_Scenario::Set_CityPlan(RGE_Scenario *this,int param_1,char *param_2,int param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char **ppcVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_2 == (char *)0x0) {
    ppcVar4 = this->CityPlan + param_1;
    *this->CityPlan[param_1] = '\0';
  }
  else {
    ppcVar4 = this->CityPlan + param_1;
    uVar2 = 0xffffffff;
    pcVar5 = param_2;
    do {
      pcVar6 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar6 + -uVar2;
    pcVar6 = *ppcVar4;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  if (param_3 == 1) {
    uVar2 = 0xffffffff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *param_2;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    (*ppcVar4)[~uVar2 - 5] = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: Set_player_AI
// Address: 0048bb40
void __thiscall
RGE_Scenario::Set_player_AI(RGE_Scenario *this,int param_1,char *param_2,int param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char **ppcVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_2 == (char *)0x0) {
    ppcVar4 = this->AiRules + param_1;
    *this->AiRules[param_1] = '\0';
  }
  else {
    ppcVar4 = this->AiRules + param_1;
    uVar2 = 0xffffffff;
    pcVar5 = param_2;
    do {
      pcVar6 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar6 + -uVar2;
    pcVar6 = *ppcVar4;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  if (param_3 == 1) {
    uVar2 = 0xffffffff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *param_2;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    (*ppcVar4)[~uVar2 - 5] = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: Set_Version
// Address: 0048bbb0
void __thiscall RGE_Scenario::Set_Version(RGE_Scenario *this,float param_1)
{
  this->Version = param_1;
  return;
}

// --------------------------------------------------

// Function: Set_player_Type
// Address: 0048bbc0
void __thiscall RGE_Scenario::Set_player_Type(RGE_Scenario *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    this->PlType[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: Set_player_Civ
// Address: 0048bbe0
void __thiscall RGE_Scenario::Set_player_Civ(RGE_Scenario *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    this->PlCivilization[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: Set_player_Active
// Address: 0048bc00
void __thiscall RGE_Scenario::Set_player_Active(RGE_Scenario *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    this->PlActive[param_1] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: SetPlayerName
// Address: 0048bc20
void __thiscall RGE_Scenario::SetPlayerName(RGE_Scenario *this,int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  PlayerName *pPVar5;
  
  uVar2 = 0xffffffff;
  pcVar4 = param_2;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pPVar5 = this->player_name + param_1;
  for (uVar3 = ~uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pPVar5->Name = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pPVar5 = (PlayerName *)(pPVar5->Name + 4);
  }
  for (uVar2 = ~uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    pPVar5->Name[0] = *param_2;
    param_2 = param_2 + 1;
    pPVar5 = (PlayerName *)(pPVar5->Name + 1);
  }
  return;
}

// --------------------------------------------------

// Function: Get_scenario_name
// Address: 0048bc60
char * __thiscall RGE_Scenario::Get_scenario_name(RGE_Scenario *this)
{
  return this->scenario_name;
}

// --------------------------------------------------

// Function: Get_description
// Address: 0048bc70
char * __thiscall RGE_Scenario::Get_description(RGE_Scenario *this)
{
  return this->description;
}

// --------------------------------------------------

// Function: Get_Cine_PreGame
// Address: 0048bc80
char * __thiscall RGE_Scenario::Get_Cine_PreGame(RGE_Scenario *this)
{
  return this->Cine_PreGame;
}

// --------------------------------------------------

// Function: Get_Cine_Victory
// Address: 0048bc90
char * __thiscall RGE_Scenario::Get_Cine_Victory(RGE_Scenario *this)
{
  return this->Cine_Victory;
}

// --------------------------------------------------

// Function: Get_Cine_Loss
// Address: 0048bca0
char * __thiscall RGE_Scenario::Get_Cine_Loss(RGE_Scenario *this)
{
  return this->Cine_Loss;
}

// --------------------------------------------------

// Function: Get_Mission_Bmp
// Address: 0048bcb0
char * __thiscall RGE_Scenario::Get_Mission_Bmp(RGE_Scenario *this)
{
  return this->Mission_Bmp;
}

// --------------------------------------------------

// Function: Get_BuildList
// Address: 0048bcc0
// [HELPER] s__: "}"
// [HELPER] s__s: "%s"
// [HELPER] s__s_s_ai: "%s%s.ai"
// [HELPER] s__stemp_buildlist_d_tmp: "%stemp_buildlist%d.tmp"
char * __thiscall RGE_Scenario::Get_BuildList(RGE_Scenario *this,int param_1,int param_2)
{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  bool bVar12;
  byte abStack_18c [8];
  undefined1 *puStack_184;
  undefined4 uStack_180;
  char random_str [50];
  char none_str [50];
  char temp_path [260];
  
  puStack_184 = random_str + 4;
  uStack_180 = 0x32;
  abStack_18c[4] = 0x7b;
  abStack_18c[5] = 0x27;
  abStack_18c[6] = 0;
  abStack_18c[7] = 0;
  iVar8 = -1;
  abStack_18c[0] = 0xe6;
  abStack_18c[1] = 0xbc;
  abStack_18c[2] = 0x48;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  abStack_18c[0] = 0x32;
  abStack_18c[1] = 0;
  abStack_18c[2] = 0;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x2775,random_str + 0x2c);
  iVar4 = GetTempPathA(0x104,none_str + 0x20);
  if (iVar4 == 0) {
    uVar6 = 0xffffffff;
    pcVar9 = &s__;
    do {
      pcVar11 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar11 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar11;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar11 + -uVar6;
    pcVar11 = none_str + 0x18;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar11 = pcVar11 + 1;
    }
  }
  if (((temp_path._240_4_ == 1) && (0 < this->BuildListFileSize[temp_path._236_4_])) &&
     (this->BuildListFile[temp_path._236_4_] != (uchar *)0x0)) {
    sprintf(this->TempText1,s__stemp_buildlist_d_tmp,none_str + 0x18,temp_path._236_4_);
    iVar8 = __open(this->TempText1,0x8301,0x180);
  }
  if (iVar8 != -1) {
    write(iVar8,this->BuildListFile[temp_path._236_4_],this->BuildListFileSize[temp_path._236_4_]);
    close(iVar8);
    return this->TempText1;
  }
  if (temp_path._240_4_ == 1) {
    pbVar3 = (byte *)this->BuildList[temp_path._236_4_];
    pbVar10 = (byte *)(random_str + 0x18);
    pbVar5 = pbVar3;
    do {
      bVar2 = *pbVar5;
      bVar12 = bVar2 < *pbVar10;
      if (bVar2 != *pbVar10) {
LAB_0048be0e:
        iVar4 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_0048be13;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar12 = bVar2 < pbVar10[1];
      if (bVar2 != pbVar10[1]) goto LAB_0048be0e;
      pbVar5 = pbVar5 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_0048be13:
    if (iVar4 != 0) {
      pbVar10 = abStack_18c;
      pbVar5 = pbVar3;
      do {
        bVar2 = *pbVar5;
        bVar12 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0048be45:
          iVar4 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_0048be4a;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar12 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0048be45;
        pbVar5 = pbVar5 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_0048be4a:
      if (iVar4 != 0) {
        sprintf(this->TempText1,s__s_s_ai,rge_base_game->prog_info->ai_dir,pbVar3);
        return this->TempText1;
      }
    }
  }
  sprintf(this->TempText1,s__s,this->BuildList[temp_path._236_4_]);
  return this->TempText1;
}

// --------------------------------------------------

// Function: Get_CityPlan
// Address: 0048bec0
// [HELPER] s__: "}"
// [HELPER] s__s: "%s"
// [HELPER] s__s_s_cty: "%s%s.cty"
// [HELPER] s__stemp_CityPlan_d_tmp: "%stemp_CityPlan%d.tmp"
char * __thiscall RGE_Scenario::Get_CityPlan(RGE_Scenario *this,int param_1,int param_2)
{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  bool bVar12;
  byte abStack_18c [8];
  undefined1 *puStack_184;
  undefined4 uStack_180;
  char random_str [50];
  char none_str [50];
  char temp_path [260];
  
  puStack_184 = random_str + 4;
  uStack_180 = 0x32;
  abStack_18c[4] = 0x7b;
  abStack_18c[5] = 0x27;
  abStack_18c[6] = 0;
  abStack_18c[7] = 0;
  iVar8 = -1;
  abStack_18c[0] = 0xe6;
  abStack_18c[1] = 0xbe;
  abStack_18c[2] = 0x48;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  abStack_18c[0] = 0x32;
  abStack_18c[1] = 0;
  abStack_18c[2] = 0;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x2775,random_str + 0x2c);
  iVar3 = GetTempPathA(0x104,none_str + 0x20);
  if (iVar3 == 0) {
    uVar6 = 0xffffffff;
    pcVar9 = &s__;
    do {
      pcVar11 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar11 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar11;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar11 + -uVar6;
    pcVar11 = none_str + 0x18;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar11 = pcVar11 + 1;
    }
  }
  if (((temp_path._240_4_ == 1) && (0 < this->CityPlanFileSize[temp_path._236_4_])) &&
     (this->CityPlanFile[temp_path._236_4_] != (uchar *)0x0)) {
    sprintf(this->TempText2,s__stemp_CityPlan_d_tmp,none_str + 0x18,temp_path._236_4_);
    iVar8 = __open(this->TempText2,0x8301,0x180);
  }
  if (iVar8 != -1) {
    write(iVar8,this->CityPlanFile[temp_path._236_4_],this->CityPlanFileSize[temp_path._236_4_]);
    close(iVar8);
    return this->TempText2;
  }
  if (temp_path._240_4_ == 1) {
    pbVar5 = (byte *)this->BuildList[temp_path._236_4_];
    pbVar10 = (byte *)(random_str + 0x18);
    pbVar4 = pbVar5;
    do {
      bVar2 = *pbVar4;
      bVar12 = bVar2 < *pbVar10;
      if (bVar2 != *pbVar10) {
LAB_0048c00e:
        iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_0048c013;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar12 = bVar2 < pbVar10[1];
      if (bVar2 != pbVar10[1]) goto LAB_0048c00e;
      pbVar4 = pbVar4 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_0048c013:
    if (iVar3 != 0) {
      pbVar10 = abStack_18c;
      do {
        bVar2 = *pbVar5;
        bVar12 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0048c045:
          iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_0048c04a;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar12 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0048c045;
        pbVar5 = pbVar5 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar3 = 0;
LAB_0048c04a:
      if (iVar3 != 0) {
        sprintf(this->TempText2,s__s_s_cty,rge_base_game->prog_info->ai_dir,
                this->CityPlan[temp_path._236_4_]);
        return this->TempText2;
      }
    }
  }
  sprintf(this->TempText2,s__s,this->CityPlan[temp_path._236_4_]);
  return this->TempText2;
}

// --------------------------------------------------

// Function: Get_Version
// Address: 0048c0d0
float __thiscall RGE_Scenario::Get_Version(RGE_Scenario *this)
{
  return _DAT_00572178;
}

// --------------------------------------------------

// Function: Get_player_AI
// Address: 0048c0e0
// [HELPER] s__: "}"
// [HELPER] s__s: "%s"
// [HELPER] s__s_s_per: "%s%s.per"
// [HELPER] s__stemp_AiRules_d_tmp: "%stemp_AiRules%d.tmp"
char * __thiscall RGE_Scenario::Get_player_AI(RGE_Scenario *this,int param_1,int param_2)
{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  bool bVar12;
  byte abStack_18c [8];
  undefined1 *puStack_184;
  undefined4 uStack_180;
  char random_str [50];
  char none_str [50];
  char temp_path [260];
  
  puStack_184 = random_str + 4;
  uStack_180 = 0x32;
  abStack_18c[4] = 0x7b;
  abStack_18c[5] = 0x27;
  abStack_18c[6] = 0;
  abStack_18c[7] = 0;
  iVar8 = -1;
  abStack_18c[0] = 6;
  abStack_18c[1] = 0xc1;
  abStack_18c[2] = 0x48;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  abStack_18c[0] = 0x32;
  abStack_18c[1] = 0;
  abStack_18c[2] = 0;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x2775,random_str + 0x2c);
  iVar3 = GetTempPathA(0x104,none_str + 0x20);
  if (iVar3 == 0) {
    uVar6 = 0xffffffff;
    pcVar9 = &s__;
    do {
      pcVar11 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar11 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar11;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar11 + -uVar6;
    pcVar11 = none_str + 0x18;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar11 = pcVar11 + 1;
    }
  }
  if (((temp_path._240_4_ == 1) && (0 < this->AiRulesFileSize[temp_path._236_4_])) &&
     (this->AiRulesFile[temp_path._236_4_] != (uchar *)0x0)) {
    sprintf(this->TempText3,s__stemp_AiRules_d_tmp,none_str + 0x18,temp_path._236_4_);
    iVar8 = __open(this->TempText3,0x8301,0x180);
  }
  if (iVar8 != -1) {
    write(iVar8,this->AiRulesFile[temp_path._236_4_],this->AiRulesFileSize[temp_path._236_4_]);
    close(iVar8);
    return this->TempText3;
  }
  if (temp_path._240_4_ == 1) {
    pbVar5 = (byte *)this->BuildList[temp_path._236_4_];
    pbVar10 = (byte *)(random_str + 0x18);
    pbVar4 = pbVar5;
    do {
      bVar2 = *pbVar4;
      bVar12 = bVar2 < *pbVar10;
      if (bVar2 != *pbVar10) {
LAB_0048c22e:
        iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_0048c233;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar12 = bVar2 < pbVar10[1];
      if (bVar2 != pbVar10[1]) goto LAB_0048c22e;
      pbVar4 = pbVar4 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_0048c233:
    if (iVar3 != 0) {
      pbVar10 = abStack_18c;
      do {
        bVar2 = *pbVar5;
        bVar12 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0048c265:
          iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_0048c26a;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar12 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0048c265;
        pbVar5 = pbVar5 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar3 = 0;
LAB_0048c26a:
      if (iVar3 != 0) {
        sprintf(this->TempText3,s__s_s_per,rge_base_game->prog_info->ai_dir,
                this->AiRules[temp_path._236_4_]);
        return this->TempText3;
      }
    }
  }
  sprintf(this->TempText3,s__s,this->AiRules[temp_path._236_4_]);
  return this->TempText3;
}

// --------------------------------------------------

// Function: GetPlayerPosture
// Address: 0048c2f0
int __thiscall RGE_Scenario::GetPlayerPosture(RGE_Scenario *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 9)) {
    switch(this->PlayerPosture[param_1]) {
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      return 3;
    case 4:
      return 4;
    case 5:
      return 5;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: GetPlayerName
// Address: 0048c360
char * __thiscall RGE_Scenario::GetPlayerName(RGE_Scenario *this,int param_1)
{
  return this->player_name[param_1].Name;
}

// --------------------------------------------------

// Function: Get_player_Type
// Address: 0048c370
int __thiscall RGE_Scenario::Get_player_Type(RGE_Scenario *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    return this->PlType[param_1];
  }
  return 0;
}

// --------------------------------------------------

// Function: Get_player_Civ
// Address: 0048c390
int __thiscall RGE_Scenario::Get_player_Civ(RGE_Scenario *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    return this->PlCivilization[param_1];
  }
  return 0;
}

// --------------------------------------------------

// Function: Get_player_Active
// Address: 0048c3b0
int __thiscall RGE_Scenario::Get_player_Active(RGE_Scenario *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    return this->PlActive[param_1];
  }
  return 0;
}

// --------------------------------------------------

// Function: update
// Address: 0048c3d0
void __thiscall RGE_Scenario::update(RGE_Scenario *this)
{
  if (this->time_line != (RGE_Timeline *)0x0) {
    RGE_Timeline::update(this->time_line);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0048c3e0
// [HELPER] s__s_bmp: "%s.bmp"
// [HELPER] s__s_s_ai: "%s%s.ai"
// [HELPER] s__s_s_cty: "%s%s.cty"
// [HELPER] s__s_s_per: "%s%s.per"
void __thiscall RGE_Scenario::save(RGE_Scenario *this,int param_1)
{
  float *pfVar1;
  char cVar2;
  TPicture *this_00;
  int iVar3;
  uchar *puVar4;
  uint uVar5;
  PlayerName *pPVar6;
  int *piVar7;
  char **ppcVar8;
  int iVar9;
  char *pcVar10;
  TPicture *pTVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  float fVar13;
  short length;
  uint local_1e0;
  int local_1dc;
  TPicture *local_1d8;
  int val;
  char temp_file_name [224];
  char file_name [224];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e80e;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pfVar1 = &this->Version;
  val = (int)pfVar1;
  fVar13 = Get_Version(this);
  *pfVar1 = fVar13;
  rge_write(param_1,pfVar1,4);
  pPVar6 = this->player_name;
  iVar9 = 0x10;
  do {
    rge_write(param_1,pPVar6,0x100);
    pPVar6 = pPVar6 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  piVar7 = this->PlType;
  iVar9 = 0x10;
  do {
    rge_write(param_1,piVar7 + 0x20,4);
    rge_write(param_1,piVar7,4);
    rge_write(param_1,piVar7 + 0x10,4);
    rge_write(param_1,piVar7 + -0x10,4);
    piVar7 = piVar7 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  rge_write(param_1,&this->victory_conquest,1);
  if (this->time_line != (RGE_Timeline *)0x0) {
    RGE_Timeline::save(this->time_line,param_1);
  }
  if (this->scenario_name == (char *)0x0) {
    local_1e0 = 0;
  }
  else {
    uVar5 = 0xffffffff;
    pcVar12 = this->scenario_name;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_1e0 = ~uVar5 - 1;
  }
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,this->scenario_name,(int)(short)local_1e0);
  }
  if (this->description == (char *)0x0) {
    local_1e0 = 0;
  }
  else {
    local_1e0 = 0xffffffff;
    pcVar12 = this->description;
    do {
      if (local_1e0 == 0) break;
      local_1e0 = local_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_1e0 = ~local_1e0;
  }
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,this->description,(int)(short)local_1e0);
  }
  if (this->hints == (char *)0x0) {
    local_1e0 = 0;
  }
  else {
    local_1e0 = 0xffffffff;
    pcVar12 = this->hints;
    do {
      if (local_1e0 == 0) break;
      local_1e0 = local_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_1e0 = ~local_1e0;
  }
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,this->hints,(int)(short)local_1e0);
  }
  if (this->win_message == (char *)0x0) {
    local_1e0 = 0;
  }
  else {
    local_1e0 = 0xffffffff;
    pcVar12 = this->win_message;
    do {
      if (local_1e0 == 0) break;
      local_1e0 = local_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_1e0 = ~local_1e0;
  }
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,this->win_message,(int)(short)local_1e0);
  }
  if (this->loss_message == (char *)0x0) {
    local_1e0 = 0;
  }
  else {
    local_1e0 = 0xffffffff;
    pcVar12 = this->loss_message;
    do {
      if (local_1e0 == 0) break;
      local_1e0 = local_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_1e0 = ~local_1e0;
  }
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,this->loss_message,(int)(short)local_1e0);
  }
  if (this->historicle_notes == (char *)0x0) {
    local_1e0 = 0;
  }
  else {
    local_1e0 = 0xffffffff;
    pcVar12 = this->historicle_notes;
    do {
      if (local_1e0 == 0) break;
      local_1e0 = local_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_1e0 = ~local_1e0;
  }
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,this->historicle_notes,(int)(short)local_1e0);
  }
  uVar5 = 0xffffffff;
  pcVar12 = this->Cine_PreGame;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar2 != '\0');
  local_1e0 = ~uVar5 - 1;
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,this->Cine_PreGame,(int)(short)local_1e0);
  }
  uVar5 = 0xffffffff;
  pcVar12 = this->Cine_Victory;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar2 != '\0');
  local_1e0 = ~uVar5 - 1;
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,this->Cine_Victory,(int)(short)local_1e0);
  }
  uVar5 = 0xffffffff;
  pcVar12 = this->Cine_Loss;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar2 != '\0');
  local_1e0 = ~uVar5 - 1;
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,this->Cine_Loss,(int)(short)local_1e0);
  }
  pcVar12 = this->Mission_Bmp;
  uVar5 = 0xffffffff;
  pcVar10 = pcVar12;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar2 != '\0');
  local_1e0 = ~uVar5 - 1;
  rge_write(param_1,&local_1e0,2);
  if (0 < (short)local_1e0) {
    rge_write(param_1,pcVar12,(int)(short)local_1e0);
  }
  sprintf(file_name + 4,s__s_bmp,pcVar12);
  local_1d8 = (TPicture *)operator_new(0x20);
  pTVar11 = (TPicture *)0x0;
  local_4 = 0;
  if (local_1d8 != (TPicture *)0x0) {
    pTVar11 = (TPicture *)TPicture::TPicture(local_1d8,file_name + 4,-1,0,(void *)0x0,0);
  }
  this_00 = this->mission_picture;
  local_4 = 0xffffffff;
  if (this_00 != (TPicture *)0x0) {
    if (pTVar11->Dib == (tagBITMAPINFOHEADER *)0x0) {
      if (pTVar11 != (TPicture *)0x0) {
        TPicture::~TPicture(pTVar11);
        operator_delete(pTVar11);
      }
      goto LAB_0048c7f6;
    }
    if (this_00 != (TPicture *)0x0) {
      TPicture::~TPicture(this_00);
      operator_delete(this_00);
    }
  }
  this->mission_picture = pTVar11;
LAB_0048c7f6:
  TPicture::Save(this->mission_picture,param_1);
  ppcVar8 = this->BuildList;
  local_1dc = 0x10;
  do {
    uVar5 = 0xffffffff;
    pcVar12 = *ppcVar8;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_1e0 = ~uVar5 - 1;
    rge_write(param_1,&local_1e0,2);
    if (0 < (short)local_1e0) {
      rge_write(param_1,*ppcVar8,(int)(short)local_1e0);
    }
    ppcVar8 = ppcVar8 + 1;
    local_1dc = local_1dc + -1;
  } while (local_1dc != 0);
  ppcVar8 = this->CityPlan;
  local_1dc = 0x10;
  local_1d8 = (TPicture *)ppcVar8;
  do {
    uVar5 = 0xffffffff;
    pcVar12 = *ppcVar8;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_1e0 = ~uVar5 - 1;
    rge_write(param_1,&local_1e0,2);
    if (0 < (short)local_1e0) {
      rge_write(param_1,*ppcVar8,(int)(short)local_1e0);
    }
    ppcVar8 = ppcVar8 + 1;
    local_1dc = local_1dc + -1;
  } while (local_1dc != 0);
  if ((float)_DAT_00572170 <= *(float *)val) {
    ppcVar8 = this->AiRules;
    iVar9 = 0x10;
    local_1dc = 0;
    do {
      uVar5 = 0xffffffff;
      pcVar12 = *ppcVar8;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar2 = *pcVar12;
        pcVar12 = pcVar12 + 1;
      } while (cVar2 != '\0');
      local_1e0 = ~uVar5 - 1;
      rge_write(param_1,&local_1e0,2);
      if (0 < (short)local_1e0) {
        rge_write(param_1,*ppcVar8,(int)(short)local_1e0);
      }
      ppcVar8 = ppcVar8 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  local_1dc = 0x10;
  pTVar11 = local_1d8;
  do {
    if (*(char **)((int)pTVar11 + -0x40) != (char *)0x0) {
      sprintf(temp_file_name + 4,s__s_s_ai,rge_base_game->prog_info->ai_dir,
              *(char **)((int)pTVar11 + -0x40));
      iVar9 = __open(temp_file_name + 4,0x8000);
      if (-1 < iVar9) {
        lseek(iVar9,0,2);
        iVar3 = __tell(iVar9);
        *(int *)((int)pTVar11 + 0x140) = iVar3;
        if (*(uchar **)((int)pTVar11 + 0x80) != (uchar *)0x0) {
          free(*(uchar **)((int)pTVar11 + 0x80));
        }
        puVar4 = (uchar *)calloc(*(int *)((int)pTVar11 + 0x140),1);
        *(uchar **)((int)pTVar11 + 0x80) = puVar4;
        lseek(iVar9,0,0);
        read(iVar9,*(uchar **)((int)pTVar11 + 0x80),*(int *)((int)pTVar11 + 0x140));
        close(iVar9);
      }
    }
    if (*(char **)pTVar11 != (char *)0x0) {
      sprintf(temp_file_name + 4,s__s_s_cty,rge_base_game->prog_info->ai_dir,*(char **)pTVar11);
      iVar9 = __open(temp_file_name + 4,0x8000);
      if (-1 < iVar9) {
        lseek(iVar9,0,2);
        iVar3 = __tell(iVar9);
        *(int *)((int)pTVar11 + 0x180) = iVar3;
        if (*(uchar **)((int)pTVar11 + 0xc0) != (uchar *)0x0) {
          free(*(uchar **)((int)pTVar11 + 0xc0));
        }
        puVar4 = (uchar *)calloc(*(int *)((int)pTVar11 + 0x180),1);
        *(uchar **)((int)pTVar11 + 0xc0) = puVar4;
        lseek(iVar9,0,0);
        read(iVar9,*(uchar **)((int)pTVar11 + 0xc0),*(int *)((int)pTVar11 + 0x180));
        close(iVar9);
      }
    }
    if (*(char **)((int)pTVar11 + 0x40) != (char *)0x0) {
      sprintf(temp_file_name + 4,s__s_s_per,rge_base_game->prog_info->ai_dir,
              *(char **)((int)pTVar11 + 0x40));
      iVar9 = __open(temp_file_name + 4,0x8000);
      if (-1 < iVar9) {
        lseek(iVar9,0,2);
        iVar3 = __tell(iVar9);
        *(int *)((int)pTVar11 + 0x1c0) = iVar3;
        if (*(uchar **)((int)pTVar11 + 0x100) != (uchar *)0x0) {
          free(*(uchar **)((int)pTVar11 + 0x100));
        }
        puVar4 = (uchar *)calloc(*(int *)((int)pTVar11 + 0x1c0),1);
        *(uchar **)((int)pTVar11 + 0x100) = puVar4;
        lseek(iVar9,0,0);
        read(iVar9,*(uchar **)((int)pTVar11 + 0x100),*(int *)((int)pTVar11 + 0x1c0));
        close(iVar9);
      }
    }
    rge_write(param_1,(int *)((int)pTVar11 + 0x140),4);
    rge_write(param_1,(int *)((int)pTVar11 + 0x180),4);
    if ((float)_DAT_00572170 <= *(float *)val) {
      rge_write(param_1,(int *)((int)pTVar11 + 0x1c0),4);
    }
    if (*(uchar **)((int)pTVar11 + 0x80) != (uchar *)0x0) {
      rge_write(param_1,*(uchar **)((int)pTVar11 + 0x80),*(int *)((int)pTVar11 + 0x140));
    }
    if (*(uchar **)((int)pTVar11 + 0xc0) != (uchar *)0x0) {
      rge_write(param_1,*(uchar **)((int)pTVar11 + 0xc0),*(int *)((int)pTVar11 + 0x180));
    }
    if (*(uchar **)((int)pTVar11 + 0x100) != (uchar *)0x0) {
      rge_write(param_1,*(uchar **)((int)pTVar11 + 0x100),*(int *)((int)pTVar11 + 0x1c0));
    }
    pTVar11 = (TPicture *)((int)pTVar11 + 4);
    local_1dc = local_1dc + -1;
  } while (local_1dc != 0);
  temp_file_name[0] = -99;
  temp_file_name[1] = -1;
  temp_file_name[2] = -1;
  temp_file_name[3] = -1;
  rge_write(param_1,temp_file_name,4);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: active_player_count
// Address: 0048cc20
int __thiscall RGE_Scenario::active_player_count(RGE_Scenario *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar1 = Get_player_Active(this,iVar3);
    if (iVar1 != 0) {
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return iVar2;
}

// --------------------------------------------------

// Function: any_player_count
// Address: 0048cc50
int __thiscall RGE_Scenario::any_player_count(RGE_Scenario *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar1 = Get_player_Active(this,iVar3);
    if (iVar1 != 0) {
      iVar1 = Get_player_Type(this,iVar3);
      if (iVar1 == 1) {
        iVar2 = iVar2 + 1;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return iVar2;
}

// --------------------------------------------------

// Function: computer_player_count
// Address: 0048cc80
int __thiscall RGE_Scenario::computer_player_count(RGE_Scenario *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar1 = Get_player_Active(this,iVar3);
    if (iVar1 != 0) {
      iVar1 = Get_player_Type(this,iVar3);
      if (iVar1 == 0) {
        iVar2 = iVar2 + 1;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return iVar2;
}

// --------------------------------------------------

// Function: Set_conquest_victory
// Address: 0048ccb0
void __thiscall RGE_Scenario::Set_conquest_victory(RGE_Scenario *this,uchar param_1)
{
  this->victory_conquest = param_1;
  return;
}

// --------------------------------------------------

// Function: Get_conquest_victory
// Address: 0048ccc0
uchar __thiscall RGE_Scenario::Get_conquest_victory(RGE_Scenario *this)
{
  return this->victory_conquest;
}

// --------------------------------------------------

// Function: add_description
// Address: 0048ccd0
void __thiscall RGE_Scenario::add_description(RGE_Scenario *this,char *param_1)
{
  if (this->description == (char *)0x0) {
    getstring(&this->description,param_1);
    return;
  }
  addstring(&this->description,this->description,param_1);
  return;
}

// --------------------------------------------------

// Function: Set_message
// Address: 0048cd10
void __thiscall RGE_Scenario::Set_message(RGE_Scenario *this,char *param_1,long param_2)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff;
    pcVar2 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
  }
  if ((int)uVar4 < 1) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = (char *)calloc(uVar4,1);
  }
  pcVar5 = pcVar2;
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar5 = *param_1;
    param_1 = param_1 + 1;
    pcVar5 = pcVar5 + 1;
  }
  switch(param_2) {
  case 0:
    if (this->description != (char *)0x0) {
      free(this->description);
    }
    break;
  case 1:
    if (this->hints != (char *)0x0) {
      free(this->hints);
    }
    this->hints = pcVar2;
    return;
  case 2:
    if (this->win_message == (char *)0x0) {
      free(0);
    }
    this->win_message = pcVar2;
    return;
  case 3:
    if (this->loss_message != (char *)0x0) {
      free(this->loss_message);
    }
    this->loss_message = pcVar2;
    return;
  case 4:
    if (this->historicle_notes != (char *)0x0) {
      free(this->historicle_notes);
    }
    this->historicle_notes = pcVar2;
    return;
  default:
    if (pcVar2 != (char *)0x0) {
      free(pcVar2);
    }
    return;
  }
  this->description = pcVar2;
  return;
}

// --------------------------------------------------

// Function: Get_message
// Address: 0048ce40
char * __thiscall RGE_Scenario::Get_message(RGE_Scenario *this,long param_1)
{
  switch(param_1) {
  case 0:
    return this->description;
  case 1:
    return this->hints;
  case 2:
    return this->win_message;
  case 3:
    return this->loss_message;
  case 4:
    return this->historicle_notes;
  default:
    return (char *)0x0;
  }
}

// --------------------------------------------------

