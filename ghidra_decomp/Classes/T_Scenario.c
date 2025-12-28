// Class: T_Scenario
// Size:  0x514C
//
// VTable Layout:
// [00] get_object_pointer
// [01] `vector_deleting_destructor'
// [02] rehook
// [03] save
//
// Member Layout:
// [0x1990] Player_Start_Info[16] player_info (sz: 0x100)
// [0x1A90] Victory_StartInfo victory (sz: 0x18)
// [0x1AA8] SP_Victory_Info[16][12] sp_victory (sz: 0x2D00)
// [0x47A8] Friendliness[16] Opponent (sz: 0x400)
// [0x4BA8] int[16] AlliedVictory (sz: 0x40)
// [0x4BE8] int victory_all_flag
// [0x4BEC] int is_multi_player_flag
// [0x4BF0] int which_player
// [0x4BF4] int[16][20] DisabledTechnology (sz: 0x500)
// [0x50F4] int[3] ScenarioOptions (sz: 0xC)
// [0x5100] int[16] PlayerAge (sz: 0x40)
// [0x5140] int mp_victory_type
// [0x5144] int victory_score
// [0x5148] int victory_time
// ----------------------------------------------------------------

// Function: T_Scenario
// Address: 0052aac0
/* public: __thiscall T_Scenario::T_Scenario(class RGE_Game_World *) */

T_Scenario * __thiscall T_Scenario::T_Scenario(T_Scenario *this,RGE_Game_World *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561888;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Scenario::RGE_Scenario((RGE_Scenario *)this,param_1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  InitializePlayerValues(this);
  InitializeVictoryValues(this);
  InitializeFriendlinessValues(this);
  this->mp_victory_type = 0;
  this->victory_score = 900;
  this->victory_time = 9000;
  this->victory_all_flag = 0;
  this->which_player = 0;
  this->ScenarioOptions[0] = 0;
  this->ScenarioOptions[1] = 0;
  this->ScenarioOptions[2] = 0;
  ClearDisabledTechnologies(this);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0052ab60
/* public: virtual void * __thiscall T_Scenario::`vector deleting destructor'(unsigned int) */

void * __thiscall T_Scenario::_vector_deleting_destructor_(T_Scenario *this,uint param_1)
{
  ~T_Scenario(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~T_Scenario
// Address: 0052ab80
/* public: virtual __thiscall T_Scenario::~T_Scenario(void) */

void __thiscall T_Scenario::~T_Scenario(T_Scenario *this)
{
  TPicture *this_00;
  int *piVar1;
  int iVar2;
  
  this->_padding_ = (int)&RGE_Scenario::_vftable_;
  if ((undefined4 *)this->_padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->_padding_)(1);
    this->_padding_ = 0;
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  operator_delete((void *)this->_padding_);
  this_00 = (TPicture *)this->_padding_;
  if (this_00 != (TPicture *)0x0) {
    TPicture::~TPicture(this_00);
    operator_delete(this_00);
    this->_padding_ = 0;
  }
  piVar1 = &this->_padding_;
  iVar2 = 0x10;
  do {
    operator_delete((void *)piVar1[-0x10]);
    operator_delete((void *)*piVar1);
    operator_delete((void *)piVar1[0x10]);
    if (piVar1[0x20] != 0) {
      free(piVar1[0x20]);
    }
    if (piVar1[0x30] != 0) {
      free(piVar1[0x30]);
    }
    if (piVar1[0x40] != 0) {
      free(piVar1[0x40]);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: T_Scenario
// Address: 0052ab90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall T_Scenario::T_Scenario(int,class RGE_Game_World *) */

T_Scenario * __thiscall T_Scenario::T_Scenario(T_Scenario *this,int param_1,RGE_Game_World *param_2)
{
  float fVar1;
  int iVar2;
  void *pvVar3;
  Player_Start_Info *pPVar4;
  int *piVar5;
  SP_Victory_Info (*paSVar6) [12];
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar2 = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005618a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Scenario::RGE_Scenario((RGE_Scenario *)this,param_1,param_2);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  param_2 = (RGE_Game_World *)0x0;
  InitializeVictoryValues(this);
  InitializeFriendlinessValues(this);
  ClearDisabledTechnologies(this);
  fVar1 = _DAT_00577318;
  this->mp_victory_type = 0;
  this->victory_score = 900;
  this->victory_time = 9000;
  this->victory_all_flag = 0;
  this->which_player = 0;
  if ((float)this->_padding_ <= fVar1) {
    pvVar3 = (void *)((int)&this->_padding_ + 1);
    iVar7 = 0x10;
    do {
      rge_read(param_1,pvVar3,0x100);
      pvVar3 = (void *)((int)pvVar3 + 0x100);
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if ((float)this->_padding_ <= _DAT_00577318) {
    piVar5 = &this->_padding_;
    pPVar4 = this->player_info;
    param_1 = 0x10;
    do {
      rge_read(iVar2,piVar5 + 0x20,4);
      rge_read(iVar2,pPVar4,0x10);
      rge_read(iVar2,piVar5,4);
      rge_read(iVar2,piVar5 + 0x10,4);
      rge_read(iVar2,piVar5 + -0x10,4);
      pPVar4 = pPVar4 + 1;
      piVar5 = piVar5 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  else {
    pPVar4 = this->player_info;
    iVar7 = 0x10;
    do {
      rge_read(param_1,pPVar4,0x10);
      pPVar4 = pPVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (_DAT_0057731c < (float)this->_padding_) {
    rge_read(iVar2,&param_2,4);
  }
  rge_read(iVar2,&this->victory,0x18);
  rge_read(iVar2,&this->victory_all_flag,4);
  if ((float)this->_padding_ < _DAT_00577318) {
    this->mp_victory_type = 4;
    this->victory_score = 900;
    this->victory_time = 9000;
  }
  else {
    rge_read(iVar2,&this->mp_victory_type,4);
    rge_read(iVar2,&this->victory_score,4);
    rge_read(iVar2,&this->victory_time,4);
  }
  rge_read(iVar2,this->Opponent,0x400);
  paSVar6 = this->sp_victory;
  iVar7 = 0x10;
  do {
    rge_read(iVar2,paSVar6,0x2d0);
    paSVar6 = paSVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (_DAT_0057731c < (float)this->_padding_) {
    rge_read(iVar2,&param_2,4);
  }
  if (this->_padding_ == 0x3f8147ae) {
    iVar7 = 0x10;
    do {
      rge_read(iVar2,this->AlliedVictory,0x40);
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (_DAT_0057731c <= (float)this->_padding_) {
    rge_read(iVar2,this->AlliedVictory,0x40);
  }
  if (_DAT_00577320 < (float)this->_padding_) {
    rge_read(iVar2,this->DisabledTechnology,0x500);
  }
  if (_DAT_00577324 < (float)this->_padding_) {
    if (_DAT_00577328 <= (float)this->_padding_) {
      rge_read(iVar2,this->ScenarioOptions,0xc);
    }
    else {
      rge_read(iVar2,this->ScenarioOptions,4);
      this->ScenarioOptions[1] = 0;
      this->ScenarioOptions[2] = 0;
    }
  }
  if (_DAT_0057732c < (float)this->_padding_) {
    rge_read(iVar2,this->PlayerAge,0x40);
  }
  if (_DAT_0057731c < (float)this->_padding_) {
    rge_read(iVar2,&param_2,4);
  }
  (this->victory).MP_Conquest = (uint)(byte)this->_padding_;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: save
// Address: 0052af20
/* WARNING: Variable defined which should be unmapped: checksum */
/* public: virtual void __thiscall T_Scenario::save(int) */

void __thiscall T_Scenario::save(T_Scenario *this,int param_1)
{
  Player_Start_Info *pPVar1;
  SP_Victory_Info (*paSVar2) [12];
  int iVar3;
  int checksum;
  undefined4 local_4;
  
  local_4 = 0xffffff9d;
  WriteDisabledTechnologiesToMainSystem(this);
  RGE_Scenario::save((RGE_Scenario *)this,param_1);
  pPVar1 = this->player_info;
  iVar3 = 0x10;
  do {
    rge_write(param_1,pPVar1,0x10);
    pPVar1 = pPVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  rge_write(param_1,&local_4,4);
  rge_write(param_1,&this->victory,0x18);
  rge_write(param_1,&this->victory_all_flag,4);
  rge_write(param_1,&this->mp_victory_type,4);
  rge_write(param_1,&this->victory_score,4);
  rge_write(param_1,&this->victory_time,4);
  rge_write(param_1,this->Opponent,0x400);
  paSVar2 = this->sp_victory;
  iVar3 = 0x10;
  do {
    rge_write(param_1,paSVar2,0x2d0);
    paSVar2 = paSVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  rge_write(param_1,&local_4,4);
  rge_write(param_1,this->AlliedVictory,0x40);
  rge_write(param_1,this->DisabledTechnology,0x500);
  rge_write(param_1,this->ScenarioOptions,0xc);
  rge_write(param_1,this->PlayerAge,0x40);
  rge_write(param_1,&local_4,4);
  return;
}

// --------------------------------------------------

// Function: InitializePlayerValues
// Address: 0052b080
/* public: void __thiscall T_Scenario::InitializePlayerValues(void) */

void __thiscall T_Scenario::InitializePlayerValues(T_Scenario *this)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = &this->_padding_;
  piVar2 = &this->player_info[0].Food;
  do {
    iVar3 = iVar3 + 1;
    ((Player_Start_Info *)(piVar2 + -2))->Gold = 0;
    piVar2[-1] = 0;
    *piVar2 = 0;
    piVar2[1] = 0;
    piVar1[0x20] = 0;
    ((Player_Start_Info *)(piVar2 + -2))->Gold = 0;
    piVar2[-1] = 200;
    *piVar2 = 200;
    piVar2[1] = 0x96;
    *piVar1 = 0;
    piVar1[0x10] = iVar3;
    piVar1[-0x10] = 4;
    piVar1[0xcb7] = 0;
    piVar1[0xe0d] = 0;
    piVar1 = piVar1 + 1;
    piVar2 = piVar2 + 4;
  } while (iVar3 < 0x10);
  this->_padding_ = 1;
  return;
}

// --------------------------------------------------

// Function: ClearDisabledTechnologies
// Address: 0052b100
/* private: void __thiscall T_Scenario::ClearDisabledTechnologies(void) */

void __thiscall T_Scenario::ClearDisabledTechnologies(T_Scenario *this)
{
  int iVar1;
  int (*paiVar2) [20];
  
  paiVar2 = this->DisabledTechnology;
  for (iVar1 = 0x140; iVar1 != 0; iVar1 = iVar1 + -1) {
    (*paiVar2)[0] = 1;
    paiVar2 = (int (*) [20])(*paiVar2 + 1);
  }
  return;
}

// --------------------------------------------------

// Function: InitializeAIInformation
// Address: 0052b120
/* public: void __thiscall T_Scenario::InitializeAIInformation(void) */

void __thiscall T_Scenario::InitializeAIInformation(T_Scenario *this)
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar5 = 0;
  do {
    uVar7 = 0xffffffff;
    uVar6 = 4;
    iVar1 = **(int **)(*(int *)(this->_padding_ + 0x40) + iVar5 * 4);
    pcVar2 = RGE_Scenario::Get_player_AI((RGE_Scenario *)this,iVar5,1);
    pcVar3 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)this,iVar5,1);
    pcVar4 = RGE_Scenario::Get_BuildList((RGE_Scenario *)this,iVar5,1);
    (**(code **)(iVar1 + 0x2c))(pcVar4,pcVar3,pcVar2,uVar6,uVar7);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  return;
}

// --------------------------------------------------

// Function: Set_victory_all_flag
// Address: 0052b170
/* public: void __thiscall T_Scenario::Set_victory_all_flag(int) */

void __thiscall T_Scenario::Set_victory_all_flag(T_Scenario *this,int param_1)
{
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (1 < param_1) {
    param_1 = 1;
  }
  this->victory_all_flag = param_1;
  return;
}

// --------------------------------------------------

// Function: Get_victory_all_flag
// Address: 0052b190
/* public: int __thiscall T_Scenario::Get_victory_all_flag(void) */

int __thiscall T_Scenario::Get_victory_all_flag(T_Scenario *this)
{
  return this->victory_all_flag;
}

// --------------------------------------------------

// Function: SetMPVictory
// Address: 0052b1a0
/* public: void __thiscall T_Scenario::SetMPVictory(int) */

void __thiscall T_Scenario::SetMPVictory(T_Scenario *this,int param_1)
{
  this->mp_victory_type = param_1;
  if (param_1 != 4) {
    *(undefined1 *)&this->_padding_ = 1;
  }
  return;
}

// --------------------------------------------------

// Function: GetMPVictory
// Address: 0052b1c0
/* public: int __thiscall T_Scenario::GetMPVictory(void) */

int __thiscall T_Scenario::GetMPVictory(T_Scenario *this)
{
  return this->mp_victory_type;
}

// --------------------------------------------------

// Function: SetVictoryScore
// Address: 0052b1d0
/* public: void __thiscall T_Scenario::SetVictoryScore(int) */

void __thiscall T_Scenario::SetVictoryScore(T_Scenario *this,int param_1)
{
  this->victory_score = param_1;
  return;
}

// --------------------------------------------------

// Function: GetVictoryScore
// Address: 0052b1e0
/* public: int __thiscall T_Scenario::GetVictoryScore(void) */

int __thiscall T_Scenario::GetVictoryScore(T_Scenario *this)
{
  return this->victory_score;
}

// --------------------------------------------------

// Function: SetVictoryTime
// Address: 0052b1f0
/* public: void __thiscall T_Scenario::SetVictoryTime(int) */

void __thiscall T_Scenario::SetVictoryTime(T_Scenario *this,int param_1)
{
  this->victory_time = param_1;
  return;
}

// --------------------------------------------------

// Function: GetVictoryTime
// Address: 0052b200
/* public: int __thiscall T_Scenario::GetVictoryTime(void) */

int __thiscall T_Scenario::GetVictoryTime(T_Scenario *this)
{
  return this->victory_time;
}

// --------------------------------------------------

// Function: SetSPWhich
// Address: 0052b210
/* public: void __thiscall T_Scenario::SetSPWhich(int) */

void __thiscall T_Scenario::SetSPWhich(T_Scenario *this,int param_1)
{
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (0x10 < param_1) {
    param_1 = 0xf;
  }
  this->which_player = param_1;
  return;
}

// --------------------------------------------------

// Function: GetSPWhich
// Address: 0052b230
/* public: int __thiscall T_Scenario::GetSPWhich(void) */

int __thiscall T_Scenario::GetSPWhich(T_Scenario *this)
{
  return this->which_player;
}

// --------------------------------------------------

// Function: InitializeVictoryValues
// Address: 0052b240
/* public: void __thiscall T_Scenario::InitializeVictoryValues(void) */

void __thiscall T_Scenario::InitializeVictoryValues(T_Scenario *this)
{
  int iVar1;
  SP_Victory_Info (*paSVar2) [12];
  
  (this->victory).MP_Conquest = 1;
  (this->victory).MP_Ruins = 0;
  (this->victory).MP_Artifacts = 0;
  (this->victory).MP_Discoveries = 0;
  (this->victory).MP_Exploration = 0;
  (this->victory).MP_Gold = 0;
  paSVar2 = this->sp_victory;
  for (iVar1 = 0xb40; iVar1 != 0; iVar1 = iVar1 + -1) {
    (*paSVar2)[0].ObjType = 0;
    paSVar2 = (SP_Victory_Info (*) [12])&(*paSVar2)[0].AllFlag;
  }
  return;
}

// --------------------------------------------------

// Function: ClearSPVictoryCondition
// Address: 0052b280
/* public: void __thiscall T_Scenario::ClearSPVictoryCondition(int) */

void __thiscall T_Scenario::ClearSPVictoryCondition(T_Scenario *this,int param_1)
{
  int iVar1;
  SP_Victory_Info *pSVar2;
  
  pSVar2 = this->sp_victory[this->which_player] + param_1;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    pSVar2->ObjType = 0;
    pSVar2 = (SP_Victory_Info *)&pSVar2->AllFlag;
  }
  return;
}

// --------------------------------------------------

// Function: InitializeFriendlinessValues
// Address: 0052b2b0
/* public: void __thiscall T_Scenario::InitializeFriendlinessValues(void) */

void __thiscall T_Scenario::InitializeFriendlinessValues(T_Scenario *this)
{
  int iVar1;
  Friendliness *pFVar2;
  
  pFVar2 = this->Opponent;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    pFVar2->Attitude[0] = 3;
    pFVar2 = (Friendliness *)(pFVar2->Attitude + 1);
  }
  return;
}

// --------------------------------------------------

// Function: Set_player_attitude
// Address: 0052b2d0
/* public: void __thiscall T_Scenario::Set_player_attitude(int,int,int) */

void __thiscall
T_Scenario::Set_player_attitude(T_Scenario *this,int param_1,int param_2,int param_3)
{
  if ((((param_3 == 1) || (param_3 == 3)) || (param_3 == 0)) &&
     (((-1 < param_1 && (param_1 < 0x10)) && ((-1 < param_2 && (param_2 < 0x10)))))) {
    this->Opponent[param_1].Attitude[param_2] = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: Get_player_attitude
// Address: 0052b310
/* public: int __thiscall T_Scenario::Get_player_attitude(int,int) */

int __thiscall T_Scenario::Get_player_attitude(T_Scenario *this,int param_1,int param_2)
{
  if ((((-1 < param_1) && (param_1 < 0x10)) && (-1 < param_2)) && (param_2 < 0x10)) {
    return this->Opponent[param_1].Attitude[param_2];
  }
  return -1;
}

// --------------------------------------------------

// Function: Set_player_Gold
// Address: 0052b340
/* public: void __thiscall T_Scenario::Set_player_Gold(int,int) */

void __thiscall T_Scenario::Set_player_Gold(T_Scenario *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    this->player_info[param_1].Gold = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: Set_player_Wood
// Address: 0052b360
/* public: void __thiscall T_Scenario::Set_player_Wood(int,int) */

void __thiscall T_Scenario::Set_player_Wood(T_Scenario *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    this->player_info[param_1].Wood = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: Set_player_Food
// Address: 0052b380
/* public: void __thiscall T_Scenario::Set_player_Food(int,int) */

void __thiscall T_Scenario::Set_player_Food(T_Scenario *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    this->player_info[param_1].Food = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: Set_player_Stone
// Address: 0052b3a0
/* public: void __thiscall T_Scenario::Set_player_Stone(int,int) */

void __thiscall T_Scenario::Set_player_Stone(T_Scenario *this,int param_1,int param_2)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    this->player_info[param_1].Stone = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: Set_player_Info
// Address: 0052b3c0
/* public: void __thiscall T_Scenario::Set_player_Info(int,struct Player_Start_Info *) */

void __thiscall T_Scenario::Set_player_Info(T_Scenario *this,int param_1,Player_Start_Info *param_2)
{
  Player_Start_Info *pPVar1;
  
  if ((-1 < param_1) && (param_1 < 0x10)) {
    pPVar1 = this->player_info + param_1;
    pPVar1->Gold = param_2->Gold;
    pPVar1->Wood = param_2->Wood;
    pPVar1->Food = param_2->Food;
    pPVar1->Stone = param_2->Stone;
  }
  return;
}

// --------------------------------------------------

// Function: Set_Multi_Conquest
// Address: 0052b400
/* public: void __thiscall T_Scenario::Set_Multi_Conquest(int) */

void __thiscall T_Scenario::Set_Multi_Conquest(T_Scenario *this,int param_1)
{
  if (param_1 != 0) {
    (this->victory).MP_Conquest = 1;
    RGE_Scenario::Set_conquest_victory((RGE_Scenario *)this,'\x01');
    return;
  }
  (this->victory).MP_Conquest = 0;
  RGE_Scenario::Set_conquest_victory((RGE_Scenario *)this,'\0');
  return;
}

// --------------------------------------------------

// Function: Set_Multi_Ruins
// Address: 0052b430
/* public: void __thiscall T_Scenario::Set_Multi_Ruins(int) */

void __thiscall T_Scenario::Set_Multi_Ruins(T_Scenario *this,int param_1)
{
  (this->victory).MP_Ruins = param_1;
  return;
}

// --------------------------------------------------

// Function: Set_Multi_Artifacts
// Address: 0052b440
/* public: void __thiscall T_Scenario::Set_Multi_Artifacts(int) */

void __thiscall T_Scenario::Set_Multi_Artifacts(T_Scenario *this,int param_1)
{
  (this->victory).MP_Artifacts = param_1;
  return;
}

// --------------------------------------------------

// Function: Set_Multi_Discoveries
// Address: 0052b450
/* public: void __thiscall T_Scenario::Set_Multi_Discoveries(int) */

void __thiscall T_Scenario::Set_Multi_Discoveries(T_Scenario *this,int param_1)
{
  (this->victory).MP_Discoveries = param_1;
  return;
}

// --------------------------------------------------

// Function: Set_Multi_Exploration
// Address: 0052b460
/* public: void __thiscall T_Scenario::Set_Multi_Exploration(int) */

void __thiscall T_Scenario::Set_Multi_Exploration(T_Scenario *this,int param_1)
{
  (this->victory).MP_Exploration = param_1;
  return;
}

// --------------------------------------------------

// Function: Set_Multi_Gold
// Address: 0052b470
/* public: void __thiscall T_Scenario::Set_Multi_Gold(int) */

void __thiscall T_Scenario::Set_Multi_Gold(T_Scenario *this,int param_1)
{
  (this->victory).MP_Gold = param_1;
  return;
}

// --------------------------------------------------

// Function: SetSPRectangle
// Address: 0052b480
/* public: void __thiscall T_Scenario::SetSPRectangle(int,float,float,float,float) */

void __thiscall
T_Scenario::SetSPRectangle
          (T_Scenario *this,int param_1,float param_2,float param_3,float param_4,float param_5)
{
  this->sp_victory[this->which_player][param_1].x1 = param_2;
  this->sp_victory[this->which_player][param_1].y1 = param_3;
  this->sp_victory[this->which_player][param_1].x2 = param_4;
  this->sp_victory[this->which_player][param_1].y2 = param_5;
  return;
}

// --------------------------------------------------

// Function: SetSPObjectType
// Address: 0052b500
/* public: void __thiscall T_Scenario::SetSPObjectType(int,int) */

void __thiscall T_Scenario::SetSPObjectType(T_Scenario *this,int param_1,int param_2)
{
  this->sp_victory[this->which_player][param_1].ObjType = param_2;
  return;
}

// --------------------------------------------------

// Function: SetSPPlayerID
// Address: 0052b530
/* public: void __thiscall T_Scenario::SetSPPlayerID(int,int) */

void __thiscall T_Scenario::SetSPPlayerID(T_Scenario *this,int param_1,int param_2)
{
  this->sp_victory[this->which_player][param_1].PlayerID = param_2;
  return;
}

// --------------------------------------------------

// Function: SetSPAllFlag
// Address: 0052b560
/* public: void __thiscall T_Scenario::SetSPAllFlag(int,int) */

void __thiscall T_Scenario::SetSPAllFlag(T_Scenario *this,int param_1,int param_2)
{
  this->sp_victory[this->which_player][param_1].AllFlag = param_2;
  return;
}

// --------------------------------------------------

// Function: SetSPAttribType
// Address: 0052b590
/* public: void __thiscall T_Scenario::SetSPAttribType(int,int) */

void __thiscall T_Scenario::SetSPAttribType(T_Scenario *this,int param_1,int param_2)
{
  this->sp_victory[this->which_player][param_1].AttribType = param_2;
  return;
}

// --------------------------------------------------

// Function: SetSPVictoryType
// Address: 0052b5c0
/* public: void __thiscall T_Scenario::SetSPVictoryType(int,int) */

void __thiscall T_Scenario::SetSPVictoryType(T_Scenario *this,int param_1,int param_2)
{
  this->sp_victory[this->which_player][param_1].VictoryType = param_2;
  return;
}

// --------------------------------------------------

// Function: SetSPObject
// Address: 0052b5f0
/* public: void __thiscall T_Scenario::SetSPObject(int,class RGE_Static_Object *) */

void __thiscall T_Scenario::SetSPObject(T_Scenario *this,int param_1,RGE_Static_Object *param_2)
{
  int iVar1;
  
  if (param_2 != (RGE_Static_Object *)0x0) {
    iVar1 = get_object_ID(this,param_2);
    this->sp_victory[this->which_player][param_1].obj_ID = iVar1 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: SetSPDestObjectID
// Address: 0052b630
/* public: void __thiscall T_Scenario::SetSPDestObjectID(int,class RGE_Static_Object *) */

void __thiscall
T_Scenario::SetSPDestObjectID(T_Scenario *this,int param_1,RGE_Static_Object *param_2)
{
  int iVar1;
  
  if (param_2 != (RGE_Static_Object *)0x0) {
    iVar1 = get_object_ID(this,param_2);
    this->sp_victory[this->which_player][param_1].dest_obj_ID = iVar1 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: SetSPAmount
// Address: 0052b670
/* public: void __thiscall T_Scenario::SetSPAmount(int,int) */

void __thiscall T_Scenario::SetSPAmount(T_Scenario *this,int param_1,int param_2)
{
  this->sp_victory[this->which_player][param_1].Amount = param_2;
  return;
}

// --------------------------------------------------

// Function: SetPlayerAlliedVictory
// Address: 0052b6a0
/* public: void __thiscall T_Scenario::SetPlayerAlliedVictory(int,int) */

void __thiscall T_Scenario::SetPlayerAlliedVictory(T_Scenario *this,int param_1,int param_2)
{
  this->AlliedVictory[param_1] = param_2;
  return;
}

// --------------------------------------------------

// Function: SetDisabledTechnology
// Address: 0052b6c0
/* public: void __thiscall T_Scenario::SetDisabledTechnology(int,int,int) */

void __thiscall
T_Scenario::SetDisabledTechnology(T_Scenario *this,int param_1,int param_2,int param_3)
{
  this->DisabledTechnology[param_1][param_2] = param_3;
  return;
}

// --------------------------------------------------

// Function: SetScenarioOption
// Address: 0052b6e0
/* public: void __thiscall T_Scenario::SetScenarioOption(int,int) */

void __thiscall T_Scenario::SetScenarioOption(T_Scenario *this,int param_1,int param_2)
{
  this->ScenarioOptions[param_1] = param_2;
  return;
}

// --------------------------------------------------

// Function: SetPlayerAge
// Address: 0052b700
/* public: void __thiscall T_Scenario::SetPlayerAge(int,int) */

void __thiscall T_Scenario::SetPlayerAge(T_Scenario *this,int param_1,int param_2)
{
  this->PlayerAge[param_1] = param_2;
  return;
}

// --------------------------------------------------

// Function: Get_player_Gold
// Address: 0052b720
/* public: int __thiscall T_Scenario::Get_player_Gold(int) */

int __thiscall T_Scenario::Get_player_Gold(T_Scenario *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    return this->player_info[param_1].Gold;
  }
  return 0;
}

// --------------------------------------------------

// Function: Get_player_Wood
// Address: 0052b740
/* public: int __thiscall T_Scenario::Get_player_Wood(int) */

int __thiscall T_Scenario::Get_player_Wood(T_Scenario *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    return this->player_info[param_1].Wood;
  }
  return 0;
}

// --------------------------------------------------

// Function: Get_player_Food
// Address: 0052b760
/* public: int __thiscall T_Scenario::Get_player_Food(int) */

int __thiscall T_Scenario::Get_player_Food(T_Scenario *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    return this->player_info[param_1].Food;
  }
  return 0;
}

// --------------------------------------------------

// Function: Get_player_Stone
// Address: 0052b780
/* public: int __thiscall T_Scenario::Get_player_Stone(int) */

int __thiscall T_Scenario::Get_player_Stone(T_Scenario *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    return this->player_info[param_1].Stone;
  }
  return 0;
}

// --------------------------------------------------

// Function: Get_player_Info
// Address: 0052b7a0
/* public: struct Player_Start_Info * __thiscall T_Scenario::Get_player_Info(int) */

Player_Start_Info * __thiscall T_Scenario::Get_player_Info(T_Scenario *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < 0x10)) {
    return this->player_info + param_1;
  }
  return (Player_Start_Info *)0x0;
}

// --------------------------------------------------

// Function: Get_Multi_Conquest
// Address: 0052b7c0
/* public: int __thiscall T_Scenario::Get_Multi_Conquest(void) */

int __thiscall T_Scenario::Get_Multi_Conquest(T_Scenario *this)
{
  return (this->victory).MP_Conquest;
}

// --------------------------------------------------

// Function: Get_Multi_Ruins
// Address: 0052b7d0
/* public: int __thiscall T_Scenario::Get_Multi_Ruins(void) */

int __thiscall T_Scenario::Get_Multi_Ruins(T_Scenario *this)
{
  return (this->victory).MP_Ruins;
}

// --------------------------------------------------

// Function: Get_Multi_Artifacts
// Address: 0052b7e0
/* public: int __thiscall T_Scenario::Get_Multi_Artifacts(void) */

int __thiscall T_Scenario::Get_Multi_Artifacts(T_Scenario *this)
{
  return (this->victory).MP_Artifacts;
}

// --------------------------------------------------

// Function: Get_Multi_Discoveries
// Address: 0052b7f0
/* public: int __thiscall T_Scenario::Get_Multi_Discoveries(void) */

int __thiscall T_Scenario::Get_Multi_Discoveries(T_Scenario *this)
{
  return (this->victory).MP_Discoveries;
}

// --------------------------------------------------

// Function: Get_Multi_Exploration
// Address: 0052b800
/* public: int __thiscall T_Scenario::Get_Multi_Exploration(void) */

int __thiscall T_Scenario::Get_Multi_Exploration(T_Scenario *this)
{
  return (this->victory).MP_Exploration;
}

// --------------------------------------------------

// Function: Get_Multi_Gold
// Address: 0052b810
/* public: int __thiscall T_Scenario::Get_Multi_Gold(void) */

int __thiscall T_Scenario::Get_Multi_Gold(T_Scenario *this)
{
  return (this->victory).MP_Gold;
}

// --------------------------------------------------

// Function: GetSPRectangle
// Address: 0052b820
/* public: void __thiscall T_Scenario::GetSPRectangle(int,float *,float *,float *,float *) */

void __thiscall
T_Scenario::GetSPRectangle
          (T_Scenario *this,int param_1,float *param_2,float *param_3,float *param_4,float *param_5)
{
  *param_2 = this->sp_victory[this->which_player][param_1].x1;
  *param_3 = this->sp_victory[this->which_player][param_1].y1;
  *param_4 = this->sp_victory[this->which_player][param_1].x2;
  *param_5 = this->sp_victory[this->which_player][param_1].y2;
  return;
}

// --------------------------------------------------

// Function: GetSPObjectType
// Address: 0052b8b0
/* public: int __thiscall T_Scenario::GetSPObjectType(int) */

int __thiscall T_Scenario::GetSPObjectType(T_Scenario *this,int param_1)
{
  return this->sp_victory[this->which_player][param_1].ObjType;
}

// --------------------------------------------------

// Function: GetSPPlayerID
// Address: 0052b8e0
/* public: int __thiscall T_Scenario::GetSPPlayerID(int) */

int __thiscall T_Scenario::GetSPPlayerID(T_Scenario *this,int param_1)
{
  return this->sp_victory[this->which_player][param_1].PlayerID;
}

// --------------------------------------------------

// Function: GetSPAllFlag
// Address: 0052b910
/* public: int __thiscall T_Scenario::GetSPAllFlag(int) */

int __thiscall T_Scenario::GetSPAllFlag(T_Scenario *this,int param_1)
{
  return this->sp_victory[this->which_player][param_1].AllFlag;
}

// --------------------------------------------------

// Function: GetSPAttribType
// Address: 0052b940
/* public: int __thiscall T_Scenario::GetSPAttribType(int) */

int __thiscall T_Scenario::GetSPAttribType(T_Scenario *this,int param_1)
{
  return this->sp_victory[this->which_player][param_1].AttribType;
}

// --------------------------------------------------

// Function: GetSPAmount
// Address: 0052b970
/* public: int __thiscall T_Scenario::GetSPAmount(int) */

int __thiscall T_Scenario::GetSPAmount(T_Scenario *this,int param_1)
{
  return this->sp_victory[this->which_player][param_1].Amount;
}

// --------------------------------------------------

// Function: GetSPVictoryType
// Address: 0052b9a0
/* public: int __thiscall T_Scenario::GetSPVictoryType(int) */

int __thiscall T_Scenario::GetSPVictoryType(T_Scenario *this,int param_1)
{
  return this->sp_victory[this->which_player][param_1].VictoryType;
}

// --------------------------------------------------

// Function: GetSPDestObjectID
// Address: 0052b9d0
/* public: class RGE_Static_Object * __thiscall T_Scenario::GetSPDestObjectID(int) */

RGE_Static_Object * __thiscall T_Scenario::GetSPDestObjectID(T_Scenario *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = (RGE_Static_Object *)
           (**(code **)this->_padding_)(this->sp_victory[this->which_player][param_1].dest_obj_ID);
  return pRVar1;
}

// --------------------------------------------------

// Function: GetSPObject
// Address: 0052ba00
/* public: class RGE_Static_Object * __thiscall T_Scenario::GetSPObject(int) */

RGE_Static_Object * __thiscall T_Scenario::GetSPObject(T_Scenario *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = (RGE_Static_Object *)
           (**(code **)this->_padding_)(this->sp_victory[this->which_player][param_1].obj_ID);
  return pRVar1;
}

// --------------------------------------------------

// Function: GetPlayerAlliedVictory
// Address: 0052ba30
/* public: int __thiscall T_Scenario::GetPlayerAlliedVictory(int) */

int __thiscall T_Scenario::GetPlayerAlliedVictory(T_Scenario *this,int param_1)
{
  return this->AlliedVictory[param_1];
}

// --------------------------------------------------

// Function: GetDisabledTechnology
// Address: 0052ba40
/* public: int __thiscall T_Scenario::GetDisabledTechnology(int,int) */

int __thiscall T_Scenario::GetDisabledTechnology(T_Scenario *this,int param_1,int param_2)
{
  return this->DisabledTechnology[param_1][param_2];
}

// --------------------------------------------------

// Function: GetScenarioOption
// Address: 0052ba60
/* public: int __thiscall T_Scenario::GetScenarioOption(int) */

int __thiscall T_Scenario::GetScenarioOption(T_Scenario *this,int param_1)
{
  return this->ScenarioOptions[param_1];
}

// --------------------------------------------------

// Function: GetPlayerAge
// Address: 0052ba70
/* public: int __thiscall T_Scenario::GetPlayerAge(int) */

int __thiscall T_Scenario::GetPlayerAge(T_Scenario *this,int param_1)
{
  return this->PlayerAge[param_1];
}

// --------------------------------------------------

// Function: update
// Address: 0052ba80
/* public: void __thiscall T_Scenario::update(void) */

void __thiscall T_Scenario::update(T_Scenario *this)
{
  RGE_Timeline::update((RGE_Timeline *)this->_padding_);
  return;
}

// --------------------------------------------------

// Function: SaveAttributesIntoPlayers
// Address: 0052ba90
/* private: void __thiscall T_Scenario::SaveAttributesIntoPlayers(void) */

void __thiscall T_Scenario::SaveAttributesIntoPlayers(T_Scenario *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *local_8;
  
  iVar3 = 1;
  if (1 < *(short *)(this->_padding_ + 0x3c)) {
    local_8 = this->AlliedVictory;
    iVar4 = 0x11e9;
    do {
      iVar2 = iVar3 + -1;
      iVar1 = Get_player_Food(this,iVar2);
      RGE_Player::new_attribute_num
                (*(RGE_Player **)(*(int *)(this->_padding_ + 0x40) + iVar3 * 4),0,(float)iVar1);
      iVar1 = Get_player_Stone(this,iVar2);
      RGE_Player::new_attribute_num
                (*(RGE_Player **)(*(int *)(this->_padding_ + 0x40) + iVar3 * 4),2,(float)iVar1);
      iVar1 = Get_player_Gold(this,iVar2);
      RGE_Player::new_attribute_num
                (*(RGE_Player **)(*(int *)(this->_padding_ + 0x40) + iVar3 * 4),3,(float)iVar1);
      iVar2 = Get_player_Wood(this,iVar2);
      RGE_Player::new_attribute_num
                (*(RGE_Player **)(*(int *)(this->_padding_ + 0x40) + iVar3 * 4),1,(float)iVar2);
      iVar2 = this->_padding_;
      iVar1 = 1;
      if (1 < *(short *)(iVar2 + 0x3c)) {
        do {
          if (iVar1 != iVar3) {
            RGE_Player::set_relation
                      (*(RGE_Player **)(*(int *)(iVar2 + 0x40) + iVar3 * 4),iVar1,
                       (uchar)(&this->_padding_)[iVar1 + iVar4]);
          }
          iVar2 = this->_padding_;
          iVar1 = iVar1 + 1;
        } while (iVar1 < *(short *)(iVar2 + 0x3c));
      }
      RGE_Player::set_allied_victory
                (*(RGE_Player **)(*(int *)(this->_padding_ + 0x40) + iVar3 * 4),(uchar)*local_8);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x10;
      local_8 = local_8 + 1;
    } while (iVar3 < *(short *)(this->_padding_ + 0x3c));
  }
  return;
}

// --------------------------------------------------

// Function: Save_victory_conditions_into_players
// Address: 0052bbc0
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall T_Scenario::Save_victory_conditions_into_players(int) */

void __thiscall T_Scenario::Save_victory_conditions_into_players(T_Scenario *this,int param_1)
{
  int iVar1;
  RGE_Victory_Conditions *pRVar2;
  code *pcVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  undefined4 uVar6;
  RGE_Static_Object *pRVar7;
  int unaff_EBX;
  int iVar8;
  int *piVar9;
  int unaff_retaddr;
  float fVar10;
  float fVar11;
  float fVar12;
  uchar uVar13;
  int i;
  int local_10;
  int j;
  int local_8;
  
  if (param_1 != 0) {
    SaveAttributesIntoPlayers(this);
  }
  iVar5 = this->_padding_;
  iVar8 = 1;
  if (1 < *(short *)(iVar5 + 0x3c)) {
    do {
      RGE_Victory_Conditions::destroy_all
                (*(RGE_Victory_Conditions **)(*(int *)(*(int *)(iVar5 + 0x40) + iVar8 * 4) + 0x34));
      iVar5 = this->_padding_;
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(short *)(iVar5 + 0x3c));
  }
  if (this->mp_victory_type == 4) {
    if (this->victory_all_flag != 0) {
      iVar5 = this->_padding_;
      iVar8 = 1;
      if (1 < *(short *)(iVar5 + 0x3c)) {
        do {
          iVar1 = (this->victory).MP_Exploration;
          pRVar2 = *(RGE_Victory_Conditions **)(*(int *)(*(int *)(iVar5 + 0x40) + iVar8 * 4) + 0x34)
          ;
          if (iVar1 != 0) {
            RGE_Victory_Conditions::add_explore(pRVar2,'\b',iVar1,'\x01');
          }
          iVar5 = (this->victory).MP_Ruins;
          if (iVar5 != 0) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\b',0xe,iVar5,'\x01');
          }
          iVar5 = (this->victory).MP_Artifacts;
          if (iVar5 != 0) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\b',7,iVar5,'\x01');
          }
          iVar5 = (this->victory).MP_Discoveries;
          if (iVar5 != 0) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\b',0xd,iVar5,'\0');
          }
          iVar5 = (this->victory).MP_Gold;
          if (iVar5 != 0) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\b',3,iVar5,'\x01');
          }
          iVar5 = this->_padding_;
          iVar8 = iVar8 + 1;
        } while (iVar8 < *(short *)(iVar5 + 0x3c));
      }
      if (this->victory_all_flag != 0) goto LAB_0052bd5d;
    }
    iVar5 = this->_padding_;
    iVar8 = 1;
    if (1 < *(short *)(iVar5 + 0x3c)) {
      do {
        iVar1 = (this->victory).MP_Exploration;
        pRVar2 = *(RGE_Victory_Conditions **)(*(int *)(*(int *)(iVar5 + 0x40) + iVar8 * 4) + 0x34);
        if (iVar1 != 0) {
          RGE_Victory_Conditions::add_explore(pRVar2,'\b',iVar1,'\x01');
        }
        iVar5 = (this->victory).MP_Ruins;
        if (iVar5 != 0) {
          RGE_Victory_Conditions::add_attributes(pRVar2,'\t',0xe,iVar5,'\x01');
        }
        iVar5 = (this->victory).MP_Artifacts;
        if (iVar5 != 0) {
          RGE_Victory_Conditions::add_attributes(pRVar2,'\n',7,iVar5,'\x01');
        }
        iVar5 = (this->victory).MP_Discoveries;
        if (iVar5 != 0) {
          RGE_Victory_Conditions::add_attributes(pRVar2,'\v',0xd,iVar5,'\0');
        }
        iVar5 = (this->victory).MP_Gold;
        if (iVar5 != 0) {
          RGE_Victory_Conditions::add_attributes(pRVar2,'\f',3,iVar5,'\x01');
        }
        iVar5 = this->_padding_;
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(short *)(iVar5 + 0x3c));
    }
  }
LAB_0052bd5d:
  iVar5 = this->_padding_;
  local_8 = 0;
  if (*(short *)(iVar5 + 0x3c) != 1 && -1 < *(short *)(iVar5 + 0x3c) + -1) {
    param_1 = 0x72;
    j = 4;
    piVar9 = &this->sp_victory[0][0].AttribType;
    do {
      pRVar2 = *(RGE_Victory_Conditions **)(*(int *)(*(int *)(iVar5 + 0x40) + j) + 0x34);
      local_10 = 0;
      do {
        iVar5 = piVar9[-2];
        if (iVar5 != 0) {
          if (iVar5 == 4) {
            iVar5 = *piVar9;
            if (iVar5 == 6) {
              RGE_Victory_Conditions::add_explore(pRVar2,'\x01',piVar9[-1],'\x01');
            }
            else if (iVar5 == 4) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',0xb,piVar9[-1],'\0');
            }
            else if (iVar5 == 3) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',0,piVar9[-1],'\0');
            }
            else if (iVar5 == 2) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',2,piVar9[-1],'\0');
            }
            else if (iVar5 == 1) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',1,piVar9[-1],'\0');
            }
            else if (iVar5 == 0) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',3,piVar9[-1],'\0');
            }
            else if (iVar5 == 5) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',6,piVar9[-1],'\0');
            }
          }
          else if (iVar5 == 6) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',*piVar9,piVar9[-1],'\0');
          }
          else if (iVar5 == 5) {
            uVar13 = '\x01';
            pRVar4 = (RGE_Static_Object *)(**(code **)this->_padding_)(piVar9[1]);
            RGE_Victory_Conditions::add_capture(pRVar2,'\x01',pRVar4,uVar13);
          }
          else if (iVar5 == 3) {
            pRVar4 = (RGE_Static_Object *)piVar9[2];
            pcVar3 = *(code **)this->_padding_;
            iVar5 = (*pcVar3)();
            if (iVar5 == 0) {
              fVar12 = (float)piVar9[-3];
              fVar11 = (float)piVar9[-4];
              fVar10 = (float)piVar9[-5];
              pRVar7 = (RGE_Static_Object *)
                       (*pcVar3)(piVar9[1],(&this->_padding_)[(unaff_retaddr + unaff_EBX) * 0xf]);
              RGE_Victory_Conditions::add_bring
                        (pRVar2,'\x01',pRVar7,fVar10,fVar11,fVar12,(float)pRVar4);
            }
            else {
              uVar6 = (*pcVar3)(piVar9[2]);
              pRVar7 = (RGE_Static_Object *)(*pcVar3)(piVar9[1],uVar6);
              RGE_Victory_Conditions::add_bring(pRVar2,'\x01',pRVar7,pRVar4);
            }
          }
          else if (iVar5 == 2) {
            if ((float)piVar9[-4] <= (float)_DAT_00577330) {
              RGE_Victory_Conditions::add_create
                        (pRVar2,'\x01',((SP_Victory_Info *)(piVar9 + -10))->ObjType,piVar9[-1],'\0')
              ;
            }
            else {
              RGE_Victory_Conditions::add_create
                        (pRVar2,'\x01',((SP_Victory_Info *)(piVar9 + -10))->ObjType,piVar9[-1],
                         (float)(&this->_padding_)[(param_1 + local_10) * 0xf],(float)piVar9[-5],
                         (float)piVar9[-4],(float)piVar9[-3],'\0');
            }
          }
          else if (iVar5 == 7) {
            TRIBE_Victory_Conditions::add_tech((TRIBE_Victory_Conditions *)pRVar2,'\x01',*piVar9);
          }
          else if (iVar5 == 1) {
            iVar5 = ((SP_Victory_Info *)(piVar9 + -10))->ObjType;
            if ((iVar5 == 0) || (piVar9[-9] == 0)) {
              iVar8 = piVar9[-8];
              if (iVar8 == 0) {
LAB_0052bff1:
                pcVar3 = *(code **)this->_padding_;
                iVar5 = (*pcVar3)(piVar9[1]);
                if (iVar5 != 0) {
                  pRVar4 = (RGE_Static_Object *)(*pcVar3)(piVar9[1]);
                  RGE_Victory_Conditions::add_destroy(pRVar2,'\x01',pRVar4);
                }
              }
              else if (iVar5 == 0) {
                if (iVar8 == 0) goto LAB_0052bff1;
                RGE_Victory_Conditions::add_destroy
                          (pRVar2,'\x01',
                           *(RGE_Player **)(*(int *)(this->_padding_ + 0x40) + iVar8 * 4));
              }
              else {
                RGE_Victory_Conditions::add_destroy
                          (pRVar2,'\x01',iVar5,piVar9[-1],
                           *(RGE_Player **)(*(int *)(this->_padding_ + 0x40) + iVar8 * 4));
              }
            }
            else {
              RGE_Victory_Conditions::add_destroy(pRVar2,'\x01',iVar5,(RGE_Player *)0x0);
            }
          }
        }
        piVar9 = piVar9 + 0xf;
        local_10 = local_10 + 1;
      } while (local_10 < 0xc);
      param_1 = param_1 + 0xc;
      iVar5 = this->_padding_;
      j = j + 4;
      local_8 = local_8 + 1;
    } while (local_8 < *(short *)(iVar5 + 0x3c) + -1);
  }
  return;
}

// --------------------------------------------------

// Function: rehook
// Address: 0052c070
/* public: virtual void __thiscall T_Scenario::rehook(void) */

void __thiscall T_Scenario::rehook(T_Scenario *this)
{
  return;
}

// --------------------------------------------------

// Function: get_object_pointer
// Address: 0052c080
/* private: virtual class RGE_Static_Object * __thiscall T_Scenario::get_object_pointer(int) */

RGE_Static_Object * __thiscall T_Scenario::get_object_pointer(T_Scenario *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = (RGE_Static_Object *)0x0;
  if (0 < param_1) {
    pRVar1 = RGE_Game_World::object((RGE_Game_World *)this->_padding_,param_1 + -1);
  }
  return pRVar1;
}

// --------------------------------------------------

// Function: get_object_ID
// Address: 0052c0a0
/* private: int __thiscall T_Scenario::get_object_ID(class RGE_Static_Object *) */

int __thiscall T_Scenario::get_object_ID(T_Scenario *this,RGE_Static_Object *param_1)
{
  return param_1->id;
}

// --------------------------------------------------

// Function: WriteDisabledTechnologiesToMainSystem
// Address: 0052c0b0
/* private: void __thiscall T_Scenario::WriteDisabledTechnologiesToMainSystem(void) */

void __thiscall T_Scenario::WriteDisabledTechnologiesToMainSystem(T_Scenario *this)
{
  TRIBE_Player *this_00;
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = this->_padding_;
  if ((iVar1 != 0) && (iVar2 = 1, 1 < *(short *)(iVar1 + 0x3c))) {
    piVar3 = this->DisabledTechnology[0] + 1;
    do {
      this_00 = *(TRIBE_Player **)(*(int *)(iVar1 + 0x40) + iVar2 * 4);
      if (this->ScenarioOptions[0] != 0) {
        (**(code **)(**(int **)(iVar1 + 0x4c) + 8))(100,this_00);
      }
      TRIBE_Player::tech_abling(this_00,0x58,(uchar)(*(int (*) [20])(piVar3 + -1))[0]);
      TRIBE_Player::tech_abling(this_00,0x59,(uchar)*piVar3);
      TRIBE_Player::tech_abling(this_00,0x5a,(uchar)piVar3[1]);
      TRIBE_Player::tech_abling(this_00,0x5b,(uchar)piVar3[2]);
      TRIBE_Player::tech_abling(this_00,0x5e,(uchar)piVar3[3]);
      TRIBE_Player::tech_abling(this_00,0x5f,(uchar)piVar3[4]);
      TRIBE_Player::tech_abling(this_00,0x61,(uchar)piVar3[5]);
      TRIBE_Player::tech_abling(this_00,0x62,(uchar)piVar3[6]);
      TRIBE_Player::tech_abling(this_00,0x5d,(uchar)piVar3[7]);
      TRIBE_Player::tech_abling(this_00,0x60,(uchar)piVar3[8]);
      TRIBE_Player::tech_abling(this_00,0x5c,(uchar)piVar3[9]);
                    /* language.dll match for 0x65: "1" */
      TRIBE_Player::tech_abling(this_00,0x65,(uchar)piVar3[10]);
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
      TRIBE_Player::tech_abling(this_00,0x66,(uchar)piVar3[0xb]);
                    /* language.dll match for 0x67: "Comic Sans MS" */
      TRIBE_Player::tech_abling(this_00,0x67,(uchar)piVar3[0xc]);
                    /* language.dll match for 0x73: "B" */
      TRIBE_Player::tech_abling(this_00,0x73,(uchar)piVar3[0xd]);
                    /* language.dll match for 0x74: "Copperplate Gothic Light" */
      TRIBE_Player::tech_abling(this_00,0x74,(uchar)piVar3[0xe]);
      iVar2 = iVar2 + 1;
      iVar1 = this->_padding_;
      piVar3 = piVar3 + 0x14;
    } while (iVar2 < *(short *)(iVar1 + 0x3c));
  }
  return;
}

// --------------------------------------------------

// Function: any_sp_victory
// Address: 0052c1e0
/* public: int __thiscall T_Scenario::any_sp_victory(void) */

int __thiscall T_Scenario::any_sp_victory(T_Scenario *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = RGE_Scenario::Get_player_Active((RGE_Scenario *)this,iVar3);
    if (iVar1 != 0) {
      SetSPWhich(this,iVar3);
      iVar1 = 0;
      do {
        iVar2 = GetSPVictoryType(this,iVar1);
        if (iVar2 != 0) {
          return 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0xc);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return 0;
}

// --------------------------------------------------

// Function: set_player_tech
// Address: 0052c230
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall T_Scenario::set_player_tech(class TRIBE_Player *) */

void __thiscall T_Scenario::set_player_tech(T_Scenario *this,TRIBE_Player *param_1)
{
  int iVar1;
  long lVar2;
  
  iVar1 = (int)*(short *)((int)&param_1->_padding_ + 2);
  if (iVar1 + -1 < 0) {
    return;
  }
  TRIBE_Player::tech_abling(param_1,0x58,(uchar)this->AlliedVictory[iVar1 * 0x14 + -1]);
  TRIBE_Player::tech_abling(param_1,0x59,(uchar)this->AlliedVictory[iVar1 * 0x14]);
  TRIBE_Player::tech_abling(param_1,0x5a,(uchar)this->DisabledTechnology[iVar1 + -1][2]);
  TRIBE_Player::tech_abling(param_1,0x5b,(uchar)this->DisabledTechnology[iVar1 + -1][3]);
  TRIBE_Player::tech_abling(param_1,0x5e,(uchar)this->DisabledTechnology[iVar1 + -1][4]);
  TRIBE_Player::tech_abling(param_1,0x5f,(uchar)this->DisabledTechnology[iVar1 + -1][5]);
  TRIBE_Player::tech_abling(param_1,0x61,(uchar)this->DisabledTechnology[iVar1 + -1][6]);
  TRIBE_Player::tech_abling(param_1,0x62,(uchar)this->DisabledTechnology[iVar1 + -1][7]);
  TRIBE_Player::tech_abling(param_1,0x5d,(uchar)this->DisabledTechnology[iVar1 + -1][8]);
  TRIBE_Player::tech_abling(param_1,0x60,(uchar)this->DisabledTechnology[iVar1 + -1][9]);
  TRIBE_Player::tech_abling(param_1,0x5c,(uchar)this->DisabledTechnology[iVar1 + -1][10]);
                    /* language.dll match for 0x65: "1" */
  TRIBE_Player::tech_abling(param_1,0x65,(uchar)this->DisabledTechnology[iVar1 + -1][0xb]);
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
  TRIBE_Player::tech_abling(param_1,0x66,(uchar)this->DisabledTechnology[iVar1 + -1][0xc]);
                    /* language.dll match for 0x67: "Comic Sans MS" */
  TRIBE_Player::tech_abling(param_1,0x67,(uchar)this->DisabledTechnology[iVar1 + -1][0xd]);
                    /* language.dll match for 0x73: "B" */
  TRIBE_Player::tech_abling(param_1,0x73,(uchar)this->DisabledTechnology[iVar1 + -1][0xe]);
                    /* language.dll match for 0x74: "Copperplate Gothic Light" */
  TRIBE_Player::tech_abling(param_1,0x74,(uchar)this->DisabledTechnology[iVar1 + -1][0xf]);
  TRIBE_Player_Tech::check_for_new_tech(param_1->tech_tree);
  if (this->ScenarioOptions[0] != 0) {
    (**(code **)(**(int **)(this->_padding_ + 0x4c) + 8))(100,param_1);
  }
  if (rge_base_game->prog_mode != 7) {
    switch(this->ScenarioOptions[iVar1 + 2]) {
    case 1:
      lVar2 = 0x19;
      break;
    case 2:
      lVar2 = 0x17;
      break;
    case 3:
      lVar2 = 0x18;
      break;
    case 4:
      lVar2 = 1;
      break;
    default:
      goto switchD_0052c390_default;
    }
    TRIBE_Player::rev_tech(param_1,lVar2);
  }
switchD_0052c390_default:
  if ((float)this->DisabledTechnology[iVar1 + -1][0xe] == _DAT_00577338) {
    *(undefined4 *)(param_1->_padding_ + 0xc0) = 0x3f800000;
  }
  return;
}

// --------------------------------------------------

