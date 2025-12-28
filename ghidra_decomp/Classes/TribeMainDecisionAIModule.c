// Class: TribeMainDecisionAIModule
// Size:  0x125C8
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] loggingHistory
// [02] setLogHistory
// [03] toggleLogHistory
// [04] setHistoryFilename
// [05] loggingCommonHistory
// [06] setLogCommonHistory
// [07] toggleLogCommonHistory
// [08] loadState
// [09] saveState
// [10] gleanState
// [11] processMessage
// [12] update
// [13] setCallbackMessage
// [14] filterOutMessage
// [15] save
// [16] addObject
// [17] removeObject
// [18] objectGroupThatCanPerformAction
// [19] canPerformAction
//
// Member Layout:
// [0x104] TribeBuildAIModule buildAI (sz: 0x5C0)
// [0x6C4] TribeConstructionAIModule constructionAI (sz: 0x318)
// [0x9DC] DiplomacyAIModule diplomacyAI (sz: 0x150)
// [0xB2C] EmotionalAIModule emotionalAI (sz: 0x1C0)
// [0xCEC] TribeInformationAIModule informationAI (sz: 0x10090)
// [0x10D7C] TribeResourceAIModule resourceAI (sz: 0xF8)
// [0x10E74] TribeStrategyAIModule strategyAI (sz: 0x5F8)
// [0x1146C] TribeTacticalAIModule tacticalAI (sz: 0x100C)
// [0x12478] TradeAIModule tradeAI (sz: 0xF4)
// [0x1256C] TRIBE_Player * aiPlayer
// [0x12570] int firstUpdate
// [0x12574] int veryFirstUpdate
// [0x12578] int updateDelay
// [0x1257C] ulong lastDiplomacyUpdateTime
// [0x12580] ulong lastTacticalUpdateTime
// [0x12584] ulong lastTributeChatTime
// [0x12588] ulong tributeChatTimeout
// [0x1258C] int waitingOnTribute
// [0x12590] int tributeExpirationTimeout
// [0x12594] int tributeAddressed
// [0x12598] int tributeAmount
// [0x1259C] int decidedInitialDiplomacy
// [0x125A0] int requiredDiplomacyTributeAmount
// [0x125A4] int[9] tributeGiven (sz: 0x24)
// ----------------------------------------------------------------

// Function: TribeMainDecisionAIModule
// Address: 004e4800
TribeMainDecisionAIModule * __thiscall
TribeMainDecisionAIModule::TribeMainDecisionAIModule
          (TribeMainDecisionAIModule *this,void *param_1,int param_2,char *param_3,
          TRIBE_Player *param_4,char *param_5,char *param_6,char *param_7)
{
  TribeInformationAIModule *this_00;
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560616;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  MainDecisionAIModule::MainDecisionAIModule
            ((MainDecisionAIModule *)this,param_1,param_2,(RGE_Player *)param_4);
  local_4 = 0;
  TribeBuildAIModule::TribeBuildAIModule(&this->buildAI,param_1,param_2);
  local_4._0_1_ = 1;
  TribeConstructionAIModule::TribeConstructionAIModule(&this->constructionAI,param_1,param_2);
  local_4._0_1_ = 2;
  DiplomacyAIModule::DiplomacyAIModule(&this->diplomacyAI,param_1,param_2);
  local_4._0_1_ = 3;
  EmotionalAIModule::EmotionalAIModule(&this->emotionalAI,param_1,param_2);
  this_00 = &this->informationAI;
  local_4._0_1_ = 4;
  TribeInformationAIModule::TribeInformationAIModule(this_00,param_1,param_2);
  local_4._0_1_ = 5;
  TribeResourceAIModule::TribeResourceAIModule(&this->resourceAI,param_1,param_2,4,500,0,1000);
  local_4._0_1_ = 6;
  TribeStrategyAIModule::TribeStrategyAIModule(&this->strategyAI,param_1,param_2);
  local_4._0_1_ = 7;
  TribeTacticalAIModule::TribeTacticalAIModule(&this->tacticalAI,param_1,param_2);
  local_4._0_1_ = 8;
  TradeAIModule::TradeAIModule(&this->tradeAI,param_1,param_2);
  this->firstUpdate = 1;
  this->veryFirstUpdate = 1;
  local_4 = CONCAT31(local_4._1_3_,9);
  this->aiPlayer = param_4;
  this->updateDelay = param_2;
  this->lastDiplomacyUpdateTime = 0;
  this->lastTacticalUpdateTime = 0;
  this->lastTributeChatTime = 0;
  this->tributeChatTimeout = 0;
  this->waitingOnTribute = 0;
  this->tributeExpirationTimeout = 0;
  this->tributeAddressed = 0;
  this->tributeAmount = 0;
  this->decidedInitialDiplomacy = 0;
  this->requiredDiplomacyTributeAmount = 0;
  this->_padding_ = (int)&_vftable_;
  AIModule::setPlayer((AIModule *)this,param_2,param_3);
  AIModule::setLogCommonHistory((AIModule *)this,(uint)(startLoggingAI != 0));
  TribeBuildAIModule::setMainDecisionAI(&this->buildAI,this);
  TribeConstructionAIModule::setMainDecisionAI(&this->constructionAI,this);
  DiplomacyAIModule::setMainDecisionAI(&this->diplomacyAI,(MainDecisionAIModule *)this);
  EmotionalAIModule::setMainDecisionAI(&this->emotionalAI,(MainDecisionAIModule *)this);
  TribeInformationAIModule::setMainDecisionAI(this_00,this);
  TribeResourceAIModule::setMainDecisionAI(&this->resourceAI,this);
  TribeStrategyAIModule::setMainDecisionAI(&this->strategyAI,this);
  TribeTacticalAIModule::setMainDecisionAI(&this->tacticalAI,this);
  TradeAIModule::setMainDecisionAI(&this->tradeAI,(MainDecisionAIModule *)this);
  AIModule::setPlayer((AIModule *)&this->buildAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&this->constructionAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&this->diplomacyAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&this->emotionalAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)this_00,param_2,param_3);
  AIModule::setPlayer((AIModule *)&this->resourceAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&this->strategyAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&this->tacticalAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&this->tradeAI,param_2,param_3);
  TribeInformationAIModule::addResourceType(this_00,0,0x30);
  TribeInformationAIModule::addResourceType(this_00,0,0x7e);
  TribeInformationAIModule::addResourceType(this_00,0,0x3b);
  TribeInformationAIModule::addResourceType(this_00,0,0x41);
  TribeInformationAIModule::addResourceType(this_00,0,0x34);
  TribeInformationAIModule::addResourceType(this_00,0,0x35);
  TribeInformationAIModule::addResourceType(this_00,0,0x104);
  TribeInformationAIModule::addResourceType(this_00,0,0x107);
  TribeInformationAIModule::addResourceType(this_00,0,0x32);
  iVar1 = 0x6f;
  do {
    TribeInformationAIModule::addResourceType(this_00,1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x73);
  iVar1 = 0x86;
  do {
    TribeInformationAIModule::addResourceType(this_00,1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x9a);
  iVar1 = 0xc0;
  do {
    TribeInformationAIModule::addResourceType(this_00,1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xc6);
  TribeInformationAIModule::addResourceType(this_00,2,0x66);
  TribeInformationAIModule::addResourceType(this_00,3,0x42);
  iVar1 = 0x150;
  do {
    TribeInformationAIModule::addResourceType(this_00,3,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x154);
  EmotionalAIModule::setOverallState(&this->emotionalAI,0);
  piVar2 = this->tributeGiven;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004e4b60
void * __thiscall
TribeMainDecisionAIModule::_scalar_deleting_destructor_
          (TribeMainDecisionAIModule *this,uint param_1)
{
  ~TribeMainDecisionAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TribeMainDecisionAIModule
// Address: 004e4b80
TribeMainDecisionAIModule * __thiscall
TribeMainDecisionAIModule::TribeMainDecisionAIModule
          (TribeMainDecisionAIModule *this,int param_1,char *param_2,TRIBE_Player *param_3,
          int param_4)
{
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005606a6;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  MainDecisionAIModule::MainDecisionAIModule
            ((MainDecisionAIModule *)this,param_1,(RGE_Player *)param_3,param_4);
  local_4 = 0;
  TribeBuildAIModule::TribeBuildAIModule(&this->buildAI,param_1,param_4);
  local_4._0_1_ = 1;
  TribeConstructionAIModule::TribeConstructionAIModule(&this->constructionAI,param_1,param_4);
  local_4._0_1_ = 2;
  DiplomacyAIModule::DiplomacyAIModule(&this->diplomacyAI,param_1,param_4);
  local_4._0_1_ = 3;
  EmotionalAIModule::EmotionalAIModule(&this->emotionalAI,param_1,param_4);
  local_4._0_1_ = 4;
  TribeInformationAIModule::TribeInformationAIModule(&this->informationAI,param_1,param_4);
  local_4._0_1_ = 5;
  TribeResourceAIModule::TribeResourceAIModule(&this->resourceAI,param_1,param_4);
  local_4._0_1_ = 6;
  TribeStrategyAIModule::TribeStrategyAIModule(&this->strategyAI,param_1,param_4);
  local_4._0_1_ = 7;
  TribeTacticalAIModule::TribeTacticalAIModule(&this->tacticalAI,param_1,param_4);
  local_4._0_1_ = 8;
  TradeAIModule::TradeAIModule(&this->tradeAI,param_1,param_4);
  this->aiPlayer = param_3;
  local_4 = CONCAT31(local_4._1_3_,9);
  this->firstUpdate = 0;
  this->veryFirstUpdate = 0;
  this->updateDelay = param_1;
  this->lastDiplomacyUpdateTime = 0;
  this->lastTacticalUpdateTime = 0;
  this->decidedInitialDiplomacy = 0;
  this->requiredDiplomacyTributeAmount = 0;
  this->_padding_ = (int)&_vftable_;
  AIModule::setPlayer((AIModule *)this,param_1,param_2);
  AIModule::setLogCommonHistory((AIModule *)this,(uint)(startLoggingAI != 0));
  TribeBuildAIModule::setMainDecisionAI(&this->buildAI,this);
  TribeConstructionAIModule::setMainDecisionAI(&this->constructionAI,this);
  DiplomacyAIModule::setMainDecisionAI(&this->diplomacyAI,(MainDecisionAIModule *)this);
  EmotionalAIModule::setMainDecisionAI(&this->emotionalAI,(MainDecisionAIModule *)this);
  TribeInformationAIModule::setMainDecisionAI(&this->informationAI,this);
  TribeResourceAIModule::setMainDecisionAI(&this->resourceAI,this);
  TribeStrategyAIModule::setMainDecisionAI(&this->strategyAI,this);
  TribeTacticalAIModule::setMainDecisionAI(&this->tacticalAI,this);
  TradeAIModule::setMainDecisionAI(&this->tradeAI,(MainDecisionAIModule *)this);
  AIModule::setPlayer((AIModule *)&this->buildAI,param_1,param_2);
  AIModule::setPlayer((AIModule *)&this->constructionAI,param_1,param_2);
  AIModule::setPlayer((AIModule *)&this->diplomacyAI,param_1,param_2);
  AIModule::setPlayer((AIModule *)&this->emotionalAI,param_1,param_2);
  AIModule::setPlayer((AIModule *)&this->informationAI,param_1,param_2);
  AIModule::setPlayer((AIModule *)&this->resourceAI,param_1,param_2);
  AIModule::setPlayer((AIModule *)&this->strategyAI,param_1,param_2);
  AIModule::setPlayer((AIModule *)&this->tacticalAI,param_1,param_2);
  AIModule::setPlayer((AIModule *)&this->tradeAI,param_1,param_2);
  rge_read(param_4,&this->updateDelay,4);
  rge_read(param_4,&this->lastDiplomacyUpdateTime,4);
  rge_read(param_4,&this->lastTacticalUpdateTime,4);
  if (_DAT_00575618 <= save_game_version) {
    rge_read(param_4,&this->lastTributeChatTime,4);
    rge_read(param_4,&this->tributeChatTimeout,4);
    rge_read(param_4,&this->waitingOnTribute,4);
    rge_read(param_4,&this->tributeExpirationTimeout,4);
    rge_read(param_4,&this->tributeAddressed,4);
    rge_read(param_4,&this->tributeAmount,4);
  }
  if (save_game_version < _DAT_0057561c) {
    piVar2 = this->tributeGiven;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  else {
    rge_read(param_4,&this->decidedInitialDiplomacy,4);
    rge_read(param_4,&this->requiredDiplomacyTributeAmount,4);
    rge_read(param_4,this->tributeGiven,0x24);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TribeMainDecisionAIModule
// Address: 004e4ec0
void __thiscall
TribeMainDecisionAIModule::~TribeMainDecisionAIModule(TribeMainDecisionAIModule *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00560728;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 8;
  TradeAIModule::~TradeAIModule(&this->tradeAI);
  local_4._0_1_ = 7;
  TribeTacticalAIModule::~TribeTacticalAIModule(&this->tacticalAI);
  local_4._0_1_ = 6;
  TribeStrategyAIModule::~TribeStrategyAIModule(&this->strategyAI);
  local_4._0_1_ = 5;
  TribeResourceAIModule::~TribeResourceAIModule(&this->resourceAI);
  local_4._0_1_ = 4;
  TribeInformationAIModule::~TribeInformationAIModule(&this->informationAI);
  local_4._0_1_ = 3;
  EmotionalAIModule::~EmotionalAIModule(&this->emotionalAI);
  local_4._0_1_ = 2;
  DiplomacyAIModule::~DiplomacyAIModule(&this->diplomacyAI);
  local_4._0_1_ = 1;
  TribeConstructionAIModule::~TribeConstructionAIModule(&this->constructionAI);
  local_4 = (uint)local_4._1_3_ << 8;
  TribeBuildAIModule::~TribeBuildAIModule(&this->buildAI);
  local_4 = 0xffffffff;
  MainDecisionAIModule::~MainDecisionAIModule((MainDecisionAIModule *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setLogHistory
// Address: 004e4fa0
void __thiscall
TribeMainDecisionAIModule::setLogHistory(TribeMainDecisionAIModule *this,int param_1)
{
  (**(code **)((this->buildAI)._padding_ + 8))(param_1);
  (**(code **)((this->constructionAI)._padding_ + 8))(param_1);
  (**(code **)((this->diplomacyAI)._padding_ + 8))(param_1);
  (**(code **)((this->emotionalAI)._padding_ + 8))(param_1);
  (**(code **)((this->informationAI)._padding_ + 8))(param_1);
  (**(code **)((this->resourceAI)._padding_ + 8))(param_1);
  (**(code **)((this->strategyAI)._padding_ + 8))(param_1);
  (**(code **)((this->tacticalAI)._padding_ + 8))(param_1);
  (**(code **)((this->tradeAI)._padding_ + 8))(param_1);
  MainDecisionAIModule::setLogHistory((MainDecisionAIModule *)this,param_1);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004e5050
// [HELPER] s_C__msdev_work_age1_x1_taimdmd_cp: "C:\msdev\work\age1_x1\taimdmd.cpp"
// [HELPER] s_Initial_Diplomacy_Settings_: "Initial Diplomacy Settings:"
// [HELPER] s___Player___d__Dislike__d__Like__: "  Player #%d: Dislike=%d, Like=%d, Ambivalence=%d."
int __thiscall TribeMainDecisionAIModule::update(TribeMainDecisionAIModule *this,int param_1)
{
  DiplomacyAIModule *this_00;
  TribeTacticalAIModule *pTVar1;
  AIModule *this_01;
  ulong uVar2;
  RGE_Player *pRVar3;
  RGE_Player *this_02;
  uchar uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  AIModule *this_03;
  RGE_Player *this_04;
  RGE_Player *this_05;
  undefined4 unaff_EBP;
  int iVar11;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar12;
  char *pcVar13;
  undefined4 uVar14;
  int newEnemy;
  TRIBE_World *world;
  int numberNeutralCPs;
  RGE_Player *temp2;
  ManagedArray<int> swayableCPs;
  int neutralList [9];
  char tempString [256];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056074b;
  *unaff_FS_OFFSET = &uStack_c;
  this_01 = *(AIModule **)(this->_padding_ + 0x3c);
  if (((this_01->idValue).name[0x11] == '\0') && (this->firstUpdate == 1)) {
    this->firstUpdate = 0;
    AIModule::logCommonHistory(this_01,(char *)this,s_Initial_Diplomacy_Settings_);
    iVar11 = 1;
    if (1 < *(short *)(*(int *)(this->_padding_ + 0x3c) + 0x3c)) {
      this_00 = &this->diplomacyAI;
      do {
        iVar5 = DiplomacyAIModule::stance(this_00,iVar11,1);
        iVar6 = DiplomacyAIModule::stance(this_00,iVar11,2);
        iVar7 = DiplomacyAIModule::stance(this_00,iVar11,0);
        AIModule::logCommonHistory
                  (this_03,(char *)this,s___Player___d__Dislike__d__Like__,iVar11,iVar7,iVar6,iVar5)
        ;
        iVar11 = iVar11 + 1;
      } while (iVar11 < *(short *)(*(int *)(this->_padding_ + 0x3c) + 0x3c));
    }
    (**(code **)((this->strategyAI)._padding_ + 0x30))(0);
    TribeBuildAIModule::initialize(&this->buildAI);
    TribeInformationAIModule::initialize(&this->informationAI);
    setTributeChat(this);
    pTVar1 = &this->tacticalAI;
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x81);
    if ((iVar11 == 1) && (iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7d), iVar11 == 0)
       ) {
      this->waitingOnTribute = 1;
      this->tributeAmount = 0;
    }
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x8a);
    if (iVar11 != 0) {
      (**(code **)(*(int *)this->_padding_ + 0xb4))(0,(float)iVar11);
    }
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x8b);
    if (iVar11 != 0) {
      (**(code **)(*(int *)this->_padding_ + 0xb4))(3,(float)iVar11);
    }
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x8c);
    if (iVar11 != 0) {
      (**(code **)(*(int *)this->_padding_ + 0xb4))(2,(float)iVar11);
    }
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x8d);
    if (iVar11 != 0) {
      (**(code **)(*(int *)this->_padding_ + 0xb4))(1,(float)iVar11);
    }
  }
  iVar11 = this->updateDelay + 1;
  this->updateDelay = iVar11;
  if (0x13 < iVar11) {
    (**(code **)((this->strategyAI)._padding_ + 0x30))(0);
    this->updateDelay = 0;
  }
  (**(code **)((this->informationAI)._padding_ + 0x30))(0);
  iVar11 = this->_padding_;
  if (0x3b < (*(int *)(*(int *)(iVar11 + 0x3c) + 4) - this->lastDiplomacyUpdateTime) / 1000) {
    (**(code **)((this->diplomacyAI)._padding_ + 0x30))(0);
    iVar11 = this->_padding_;
    this->lastDiplomacyUpdateTime = *(ulong *)(*(int *)(iVar11 + 0x3c) + 4);
  }
  uVar2 = this->lastTributeChatTime;
  pTVar1 = &this->tacticalAI;
  iVar11 = *(int *)(*(int *)(iVar11 + 0x3c) + 4);
  iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
  if ((iVar5 < 1) || (this->tributeAddressed != 0)) goto LAB_004e56fa;
  if (((iVar11 - uVar2) / 1000 < this->tributeChatTimeout) ||
     (iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7d), iVar11 < 1)) {
    if (this->waitingOnTribute != 1) goto LAB_004e56fa;
    iVar11 = this->tributeExpirationTimeout - *(int *)(*(int *)(this->_padding_ + 0x3c) + 0xc);
    this->tributeExpirationTimeout = iVar11;
    if (iVar11 < 1) {
      iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x82);
      if (iVar11 == 1) {
        iVar6 = 100;
        iVar5 = 0;
        iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        DiplomacyAIModule::setStance(&this->diplomacyAI,iVar11,iVar5,iVar6);
        iVar6 = 0;
        iVar5 = 2;
        iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        DiplomacyAIModule::setStance(&this->diplomacyAI,iVar11,iVar5,iVar6);
        uVar14 = 3;
        iVar11 = this->aiPlayer->_padding_;
        iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        (**(code **)(iVar11 + 0x28))(iVar5,uVar14);
        (**(code **)(rge_base_game->_padding_ + 0x20))(0x901,neutralList + 7,0x100);
        pcVar13 = tempString;
        pcVar12 = (char *)0x0;
        iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        RGE_Player::sendChatMessage
                  ((RGE_Player *)this->_padding_,this->_padding_,iVar11,pcVar12,pcVar13);
        this->waitingOnTribute = 0;
        uVar2 = *(ulong *)(*(int *)(this->_padding_ + 0x3c) + 4);
        this->tributeAddressed = 1;
        this->lastTributeChatTime = uVar2;
        goto LAB_004e56fa;
      }
      iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x81);
      if (iVar11 != 1) goto LAB_004e56fa;
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x900,tempString,0x100);
LAB_004e5646:
      pcVar13 = tempString;
      pcVar12 = (char *)0x0;
      iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
      RGE_Player::sendChatMessage(this_05,this->_padding_,iVar11,pcVar12,pcVar13);
      this->waitingOnTribute = 0;
      this->lastTributeChatTime = *(ulong *)(*(int *)(this->_padding_ + 0x3c) + 4);
    }
    else {
      iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
      if (this->tributeAmount < iVar11) goto LAB_004e56fa;
      iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x81);
      if (iVar11 == 1) {
        iVar6 = 0;
        iVar5 = 0;
        iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        DiplomacyAIModule::setStance(&this->diplomacyAI,iVar11,iVar5,iVar6);
        iVar6 = 100;
        iVar5 = 2;
        iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        DiplomacyAIModule::setStance(&this->diplomacyAI,iVar11,iVar5,iVar6);
        uVar14 = 0;
        iVar11 = this->aiPlayer->_padding_;
        iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        (**(code **)(iVar11 + 0x28))(iVar5,uVar14);
        (**(code **)(rge_base_game->_padding_ + 0x20))(0x8ff,neutralList + 7,0x100);
        goto LAB_004e5646;
      }
      iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x82);
      if (iVar11 != 1) goto LAB_004e56fa;
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x8fe,tempString,0x100);
      pcVar13 = tempString;
      pcVar12 = (char *)0x0;
      iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
      RGE_Player::sendChatMessage
                ((RGE_Player *)this->_padding_,this->_padding_,iVar11,pcVar12,pcVar13);
      this->waitingOnTribute = 0;
      this->lastTributeChatTime = *(ulong *)(*(int *)(this->_padding_ + 0x3c) + 4);
    }
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x84);
    this->tributeAddressed = (uint)(iVar11 == 0);
    goto LAB_004e56fa;
  }
  if (this->waitingOnTribute == 0) {
    this->waitingOnTribute = 1;
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7f);
    this->tributeAmount = 0;
    this->tributeExpirationTimeout = iVar11 * 1000;
  }
  this->lastTributeChatTime = *(ulong *)(*(int *)(this->_padding_ + 0x3c) + 4);
  iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x82);
  if (iVar11 == 1) {
    if (this->tributeAmount < 1) {
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x903,tempString,0x100);
      iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
LAB_004e5443:
      pcVar13 = tempString;
      pcVar12 = (char *)0x0;
      iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
      RGE_Player::sendChatMessage
                ((RGE_Player *)this->_padding_,this->_padding_,iVar5,pcVar12,pcVar13,iVar11);
LAB_004e5461:
      setTributeChat(this);
      goto LAB_004e56fa;
    }
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x902,tempString,0x100);
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
    iVar11 = iVar11 - this->tributeAmount;
  }
  else {
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x81);
    if (iVar11 != 1) goto LAB_004e5461;
    if (this->tributeAmount < 1) {
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x905,tempString,0x100);
      iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
      iVar11 = iVar11 - this->tributeAmount;
      goto LAB_004e5443;
    }
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x904,tempString,0x100);
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
  }
  pcVar13 = tempString;
  pcVar12 = (char *)0x0;
  iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
  RGE_Player::sendChatMessage(this_04,this->_padding_,iVar5,pcVar12,pcVar13,iVar11);
  setTributeChat(this);
LAB_004e56fa:
  if ((this->decidedInitialDiplomacy == 0) &&
     (10000 < *(uint *)(*(int *)(this->_padding_ + 0x3c) + 4))) {
    iVar5 = 1;
    this->decidedInitialDiplomacy = 1;
    iVar11 = *(int *)(this->_padding_ + 0x3c);
    newEnemy = 0;
    temp2 = (RGE_Player *)0x0;
    numberNeutralCPs = 0;
    if (1 < *(short *)(iVar11 + 0x3c)) {
      do {
        pRVar3 = *(RGE_Player **)(*(int *)(iVar11 + 0x40) + iVar5 * 4);
        iVar6 = RGE_Player::computerPlayer(pRVar3);
        if (iVar6 == 0) {
          temp2 = (RGE_Player *)((int)&temp2->_padding_ + 1);
        }
        else {
          newEnemy = newEnemy + 1;
          iVar6 = (**(code **)(pRVar3->_padding_ + 0x24))();
          if (iVar6 == 1) {
            neutralList[iVar5] = 1;
            numberNeutralCPs = numberNeutralCPs + 1;
          }
          else {
            neutralList[iVar5] = 0;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(iVar11 + 0x3c));
    }
    if (*(char *)(iVar11 + 0x11d) == -1) {
      if (newEnemy == 1) {
        *(undefined1 *)(iVar11 + 0x11d) = *(undefined1 *)(this->_padding_ + 0x4a);
      }
      else {
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x236);
        iVar6 = 1;
        iVar5 = iVar5 % newEnemy + 1;
        if (1 < *(short *)(iVar11 + 0x3c)) {
          do {
            pRVar3 = *(RGE_Player **)(*(int *)(iVar11 + 0x40) + iVar6 * 4);
            iVar7 = RGE_Player::computerPlayer(pRVar3);
            if ((iVar7 == 1) && (iVar5 = iVar5 + -1, iVar5 == 0)) {
              *(char *)(iVar11 + 0x11d) = (char)pRVar3->id;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(short *)(iVar11 + 0x3c));
        }
      }
    }
    if (*(char *)(iVar11 + 0x11d) == *(char *)(this->_padding_ + 0x4a)) {
      newEnemy = (newEnemy - (int)temp2) / 2;
      if (newEnemy < 0) {
        newEnemy = 0;
      }
      if (numberNeutralCPs < newEnemy) {
        newEnemy = numberNeutralCPs;
      }
      uVar4 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
      if (uVar4 == '\x01') {
        newEnemy = 0;
      }
      if ((newEnemy <= numberNeutralCPs) && (0 < numberNeutralCPs)) {
        iVar6 = 0;
        swayableCPs.value = (int *)0x0;
        swayableCPs.numberValue = 0;
        swayableCPs.maximumSizeValue = 0;
        pcStack_8 = (code *)0x0;
        numberNeutralCPs = 1;
        iVar5 = iVar6;
        if (1 < *(short *)(iVar11 + 0x3c)) {
          do {
            pRVar3 = *(RGE_Player **)(*(int *)(iVar11 + 0x40) + numberNeutralCPs * 4);
            iVar7 = RGE_Player::computerPlayer(pRVar3);
            iVar6 = iVar5;
            if ((((iVar7 != 0) && (neutralList[numberNeutralCPs] != 0)) &&
                ((ushort)*(byte *)(iVar11 + 0x11d) != pRVar3->id)) && (iVar5 < newEnemy)) {
              iVar7 = 0;
              piVar8 = swayableCPs.value;
              if (0 < iVar5) {
                do {
                  if (swayableCPs.maximumSizeValue <= iVar7) break;
                  if (*piVar8 == numberNeutralCPs) goto LAB_004e598c;
                  iVar7 = iVar7 + 1;
                  piVar8 = piVar8 + 1;
                } while (iVar7 < iVar5);
              }
              if (swayableCPs.maximumSizeValue + -1 < iVar5) {
                iVar6 = iVar5 + 1;
                piVar8 = (int *)operator_new(iVar6 * 4);
                if (piVar8 != (int *)0x0) {
                  iVar7 = 0;
                  if (0 < swayableCPs.maximumSizeValue) {
                    piVar9 = piVar8;
                    do {
                      if (iVar6 <= iVar7) break;
                      iVar7 = iVar7 + 1;
                      *piVar9 = *(int *)(((int)swayableCPs.value - (int)piVar8) + (int)piVar9);
                      piVar9 = piVar9 + 1;
                      iVar5 = swayableCPs.numberValue;
                    } while (iVar7 < swayableCPs.maximumSizeValue);
                  }
                  operator_delete(swayableCPs.value);
                  swayableCPs.value = piVar8;
                  swayableCPs.maximumSizeValue = iVar6;
                }
              }
              iVar6 = iVar5 + 1;
              swayableCPs.value[iVar5] = numberNeutralCPs;
              swayableCPs.numberValue = iVar6;
            }
LAB_004e598c:
            numberNeutralCPs = numberNeutralCPs + 1;
            iVar5 = iVar6;
          } while (numberNeutralCPs < *(short *)(iVar11 + 0x3c));
        }
        newEnemy = 2000;
        iVar5 = RGE_Base_Game::difficulty(rge_base_game);
        switch(iVar5) {
        case 0:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x26e);
          newEnemy = iVar5 % 500 + 0x578;
          break;
        case 1:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x26f);
          newEnemy = iVar5 % 400 + 1000;
          break;
        case 2:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x270);
          newEnemy = iVar5 % 300 + 700;
          break;
        case 3:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x271);
          newEnemy = iVar5 % 200 + 0x1c2;
          break;
        case 4:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x272);
          newEnemy = iVar5 % 100 + 300;
        }
        numberNeutralCPs = 1;
        if (1 < *(short *)(iVar11 + 0x3c)) {
          do {
            pRVar3 = *(RGE_Player **)(*(int *)(iVar11 + 0x40) + numberNeutralCPs * 4);
            iVar5 = RGE_Player::computerPlayer(pRVar3);
            if ((iVar5 != 0) && (neutralList[numberNeutralCPs] != 0)) {
              iVar5 = 0;
              piVar8 = swayableCPs.value;
              if (0 < iVar6) {
                do {
                  if (swayableCPs.maximumSizeValue <= iVar5) break;
                  if (*piVar8 == numberNeutralCPs) {
                    (**(code **)(pRVar3->_padding_ + 0x54))
                              ((int)*(short *)(this->_padding_ + 0x4a),7,newEnemy,0,0);
                    newEnemy = newEnemy * 2;
                    break;
                  }
                  iVar5 = iVar5 + 1;
                  piVar8 = piVar8 + 1;
                } while (iVar5 < iVar6);
              }
              iVar5 = 1;
              if (1 < *(short *)(iVar11 + 0x3c)) {
                do {
                  if (numberNeutralCPs != iVar5) {
                    this_02 = *(RGE_Player **)(*(int *)(iVar11 + 0x40) + iVar5 * 4);
                    iVar7 = RGE_Player::computerPlayer(this_02);
                    if (iVar7 == 0) {
                      if (0 < iVar6) {
                        iVar7 = 0;
                        piVar8 = swayableCPs.value;
                        do {
                          if (swayableCPs.maximumSizeValue <= iVar7) break;
                          if (*piVar8 == numberNeutralCPs) goto LAB_004e5b47;
                          iVar7 = iVar7 + 1;
                          piVar8 = piVar8 + 1;
                        } while (iVar7 < iVar6);
                      }
                      iVar7 = pRVar3->_padding_;
                      uVar14 = 0;
                    }
                    else {
LAB_004e5b47:
                      iVar7 = RGE_Player::computerPlayer(this_02);
                      if (iVar7 != 1) goto LAB_004e5b6f;
                      iVar7 = pRVar3->_padding_;
                      uVar14 = 2;
                    }
                    (**(code **)(iVar7 + 0x54))
                              ((int)*(short *)(this->_padding_ + 0x4a),6,iVar5,uVar14,0);
                  }
LAB_004e5b6f:
                  iVar5 = iVar5 + 1;
                } while (iVar5 < *(short *)(iVar11 + 0x3c));
              }
            }
            numberNeutralCPs = numberNeutralCPs + 1;
          } while (numberNeutralCPs < *(short *)(iVar11 + 0x3c));
        }
        pcStack_8 = (code *)0xffffffff;
        if (swayableCPs.value != (int *)0x0) {
          operator_delete(swayableCPs.value);
        }
      }
    }
  }
  pTVar1 = &this->tacticalAI;
  iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0xd9);
  if (iVar11 == 1) {
    iVar11 = TribeTacticalAIModule::strategicNumber(pTVar1,0x68);
    uVar10 = (iVar11 + -3) * 1000;
    if ((int)uVar10 < 0) {
      uVar10 = 0;
    }
    if (uVar10 < *(uint *)(*(int *)(this->_padding_ + 0x3c) + 4)) {
      TribeTacticalAIModule::setStrategicNumber(pTVar1,0xd9,0);
      iVar6 = 1;
      iVar11 = *(int *)(this->_padding_ + 0x3c);
      newEnemy = -1;
      iVar5 = newEnemy;
      if (1 < *(short *)(iVar11 + 0x3c)) {
        do {
          iVar11 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar11 + 0x40) + iVar6 * 4))
          ;
          iVar5 = iVar6;
          if (iVar11 != 1) break;
          iVar6 = iVar6 + 1;
          iVar11 = *(int *)(this->_padding_ + 0x3c);
          iVar5 = newEnemy;
        } while (iVar6 < *(short *)(iVar11 + 0x3c));
      }
      newEnemy = iVar5;
      if (newEnemy != -1) {
        iVar11 = (**(code **)(*(int *)this->_padding_ + 0x18))(newEnemy);
        if (iVar11 == 0) {
          (**(code **)(*(int *)this->_padding_ + 0x54))
                    ((int)*(short *)(this->_padding_ + 0x4a),6,newEnemy,0,0);
        }
        iVar11 = this->_padding_;
        iVar6 = 1;
        iVar5 = *(int *)(iVar11 + 0x3c);
        if (1 < *(short *)(iVar5 + 0x3c)) {
          do {
            if ((iVar6 != *(short *)(iVar11 + 0x4a)) && (iVar6 != newEnemy)) {
              pRVar3 = *(RGE_Player **)(*(int *)(iVar5 + 0x40) + iVar6 * 4);
              iVar11 = pRVar3->_padding_;
              iVar5 = (**(code **)(iVar11 + 0x18))(newEnemy);
              if (iVar5 == 1) {
                (**(code **)(*(int *)this->_padding_ + 0x54))
                          ((int)*(short *)(this->_padding_ + 0x4a),6,iVar6,2,0);
                iVar5 = RGE_Player::computerPlayer(pRVar3);
                if (iVar5 == 1) {
                  iVar5 = (int)*(short *)(this->_padding_ + 0x4a);
                  (**(code **)(iVar11 + 0x54))(iVar5,6,iVar5,2,0);
                }
              }
              else {
                iVar11 = (**(code **)(iVar11 + 0x1c))(unaff_EBP);
                if (iVar11 == 1) {
                  (**(code **)(*(int *)this->_padding_ + 0x54))
                            ((int)*(short *)(this->_padding_ + 0x4a),6,iVar6,0,0);
                }
              }
            }
            iVar11 = this->_padding_;
            iVar6 = iVar6 + 1;
            iVar5 = *(int *)(iVar11 + 0x3c);
          } while (iVar6 < *(short *)(iVar5 + 0x3c));
        }
      }
    }
  }
  iVar11 = *(int *)(this->_padding_ + 0x3c);
  if ((*(char *)(iVar11 + 0x1d) == '\0') &&
     (*(int *)(iVar11 + 0xfc) == (int)*(short *)(this->_padding_ + 0x4a))) {
    (**(code **)((this->tacticalAI)._padding_ + 0x30))(0);
    this->lastTacticalUpdateTime = *(ulong *)(*(int *)(this->_padding_ + 0x3c) + 4);
  }
  *unaff_FS_OFFSET = uStack_10;
  return 1;
}

// --------------------------------------------------

// Function: save
// Address: 004e5db0
int __thiscall TribeMainDecisionAIModule::save(TribeMainDecisionAIModule *this,int param_1)
{
  MainDecisionAIModule::save((MainDecisionAIModule *)this,param_1);
  (**(code **)((this->buildAI)._padding_ + 0x3c))(param_1);
  (**(code **)((this->constructionAI)._padding_ + 0x3c))(param_1);
  (**(code **)((this->diplomacyAI)._padding_ + 0x3c))(param_1);
  (**(code **)((this->emotionalAI)._padding_ + 0x3c))(param_1);
  TribeInformationAIModule::save(&this->informationAI,param_1);
  (**(code **)((this->resourceAI)._padding_ + 0x3c))(param_1);
  (**(code **)((this->strategyAI)._padding_ + 0x3c))(param_1);
  (**(code **)((this->tacticalAI)._padding_ + 0x3c))(param_1);
  (**(code **)((this->tradeAI)._padding_ + 0x3c))(param_1);
  rge_write(param_1,&this->updateDelay,4);
  rge_write(param_1,&this->lastDiplomacyUpdateTime,4);
  rge_write(param_1,&this->lastTacticalUpdateTime,4);
  rge_write(param_1,&this->lastTributeChatTime,4);
  rge_write(param_1,&this->tributeChatTimeout,4);
  rge_write(param_1,&this->waitingOnTribute,4);
  rge_write(param_1,&this->tributeExpirationTimeout,4);
  rge_write(param_1,&this->tributeAddressed,4);
  rge_write(param_1,&this->tributeAmount,4);
  rge_write(param_1,&this->decidedInitialDiplomacy,4);
  rge_write(param_1,&this->requiredDiplomacyTributeAmount,4);
  rge_write(param_1,this->tributeGiven,0x24);
  return 1;
}

// --------------------------------------------------

// Function: kick
// Address: 004e5f30
// [HELPER] s_Current_Build_list_is_: "Current Build list is:"
// [HELPER] s_Got_a_kick__d_: "Got a kick=%d."
void __thiscall TribeMainDecisionAIModule::kick(TribeMainDecisionAIModule *this,int param_1)
{
  AIModule *extraout_ECX;
  AIModule *extraout_ECX_00;
  AIModule *extraout_ECX_01;
  AIModule *this_00;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this,s_Got_a_kick__d_,param_1);
  this_00 = extraout_ECX;
  if (param_1 == 1) {
    TribeBuildAIModule::skipNextBuildListItem(&this->buildAI);
    this_00 = extraout_ECX_00;
  }
  if (param_1 == 2) {
    TribeBuildAIModule::insert(&this->buildAI,0x53,1,-1);
    this_00 = extraout_ECX_01;
  }
  if (param_1 == 3) {
    AIModule::logCommonHistory(this_00,(char *)this,s_Current_Build_list_is_);
    (**(code **)((this->buildAI)._padding_ + 0x40))();
  }
  return;
}

// --------------------------------------------------

// Function: addObject
// Address: 004e5fa0
int __thiscall
TribeMainDecisionAIModule::addObject(TribeMainDecisionAIModule *this,RGE_Static_Object *param_1)
{
  int iVar1;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  TribeTacticalAIModule::addObject(&this->tacticalAI,param_1);
  TribeInformationAIModule::addObject(&this->informationAI,param_1);
  iVar1 = MainDecisionAIModule::addObject((MainDecisionAIModule *)this,param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: removeObject
// Address: 004e5fe0
int __thiscall TribeMainDecisionAIModule::removeObject(TribeMainDecisionAIModule *this,int param_1)
{
  int iVar1;
  
  TribeTacticalAIModule::removeObject(&this->tacticalAI,param_1);
  TribeBuildAIModule::removeBuiltItem(&this->buildAI,param_1);
  TribeInformationAIModule::removeObject(&this->informationAI,param_1);
  iVar1 = MainDecisionAIModule::removeObject((MainDecisionAIModule *)this,param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: objectGroupThatCanPerformAction
// Address: 004e6020
int __thiscall
TribeMainDecisionAIModule::objectGroupThatCanPerformAction
          (TribeMainDecisionAIModule *this,int param_1)
{
  int iVar1;
  
  switch(param_1) {
  case 0x25a:
  case 0x25d:
  case 0x261:
  case 0x265:
    return 4;
  default:
    iVar1 = MainDecisionAIModule::objectGroupThatCanPerformAction
                      ((MainDecisionAIModule *)this,param_1);
    return iVar1;
  case 0x26b:
  case 0x26c:
    return 3;
  }
}

// --------------------------------------------------

// Function: canPerformAction
// Address: 004e6090
int __thiscall
TribeMainDecisionAIModule::canPerformAction(TribeMainDecisionAIModule *this,int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)this,param_1);
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    iVar2 = (**(code **)(this->_padding_ + 0x48))(param_2);
    if (pRVar1->master_obj->object_group == iVar2) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: detask
// Address: 004e60d0
void __thiscall TribeMainDecisionAIModule::detask(TribeMainDecisionAIModule *this,int param_1)
{
  TribeTacticalAIModule::detask(&this->tacticalAI,param_1);
  return;
}

// --------------------------------------------------

// Function: isMoveable
// Address: 004e60f0
int __thiscall TribeMainDecisionAIModule::isMoveable(TribeMainDecisionAIModule *this,int param_1)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)this,param_1);
  if (((((pRVar2 != (RGE_Static_Object *)0x0) &&
        (sVar1 = pRVar2->master_obj->object_group, sVar1 != 3)) && (sVar1 != 0x1b)) &&
      (((sVar1 != 0x1e && (sVar1 != 0x1f)) && ((sVar1 != 5 && ((sVar1 != 0x21 && (sVar1 != 7))))))))
     && ((sVar1 != 8 && ((((sVar1 != 0x20 && (sVar1 != 0x10)) && (sVar1 != 0xe)) && (sVar1 != 0xf)))
         ))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: updateBuildAIWithObjects
// Address: 004e6160
void __thiscall TribeMainDecisionAIModule::updateBuildAIWithObjects(TribeMainDecisionAIModule *this)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < this->_padding_) {
    do {
      if (this->_padding_ + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < this->_padding_) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(this->_padding_ + -4 + iVar2 * 4);
            } while (iVar2 < this->_padding_);
          }
          operator_delete((void *)this->_padding_);
          this->_padding_ = (int)pvVar1;
          this->_padding_ = iVar4 + 1;
        }
      }
      pRVar3 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)this,*(int *)(this->_padding_ + iVar4 * 4));
      if ((pRVar3 != (RGE_Static_Object *)0x0) &&
         (TribeBuildAIModule::addItem(&this->buildAI,pRVar3,0), pRVar3->master_obj->id == 0x6d)) {
        iVar2 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28);
        ConstructionAIModule::setReferencePoint
                  ((ConstructionAIModule *)&this->constructionAI,*(int *)(iVar2 + 8),
                   *(int *)(iVar2 + 0xc),pRVar3->world_x,pRVar3->world_y,pRVar3->world_z);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: tributeNotify
// Address: 004e6250
void __thiscall
TribeMainDecisionAIModule::tributeNotify
          (TribeMainDecisionAIModule *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  TribeTacticalAIModule *unaff_EBX;
  int iVar4;
  undefined4 uVar5;
  TribeTacticalAIModule *this_00;
  int *piVar6;
  RGE_Player *newAlly;
  char tempString [256];
  if (((this->waitingOnTribute == 1) &&
      (iVar1 = TribeTacticalAIModule::strategicNumber(&this->tacticalAI,0x80), param_1 == iVar1)) &&
     (param_2 == 3)) {
    this->tributeAmount = this->tributeAmount + param_3;
    return;
  }
  newAlly = (RGE_Player *)&this->tacticalAI;
  iVar1 = TribeTacticalAIModule::strategicNumber((TribeTacticalAIModule *)newAlly,0x80);
  if (param_1 != iVar1) {
    DiplomacyAIModule::changeStance(&this->diplomacyAI,param_1,2,param_3 / 100);
    DiplomacyAIModule::changeStance(&this->diplomacyAI,param_1,0,-(param_3 / 100));
    this->tributeGiven[param_1] = this->tributeGiven[param_1] + param_3;
    iVar1 = (**(code **)(*(int *)this->_padding_ + 0x20))();
    iVar4 = 1;
    if (((iVar1 == 1) &&
        (iVar1 = TribeTacticalAIModule::strategicNumber(unaff_EBX,0xd9), iVar1 == 1)) &&
       (this->requiredDiplomacyTributeAmount <= this->tributeGiven[param_1])) {
      this_00 = (TribeTacticalAIModule *)0x6;
      (**(code **)(*(int *)this->_padding_ + 0x54))
                ((int)*(short *)(this->_padding_ + 0x4a),6,param_1);
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x907,&stack0xfffffee8,0x100);
      RGE_Player::sendChatMessage
                ((RGE_Player *)&stack0xfffffedc,this->_padding_,param_1,(char *)0x0,
                 (RGE_Player *)&stack0xfffffedc);
      iVar1 = this->_padding_;
      piVar6 = *(int **)(*(int *)(*(int *)(iVar1 + 0x3c) + 0x40) + param_1 * 4);
      if (1 < *(short *)(*(int *)(iVar1 + 0x3c) + 0x3c)) {
        do {
          if ((iVar4 != *(short *)(iVar1 + 0x4a)) && (iVar4 != param_1)) {
            iVar1 = *piVar6;
            iVar2 = (**(code **)(iVar1 + 0x1c))(iVar4);
            if (iVar2 == 1) {
              piVar3 = (int *)this->_padding_;
              uVar5 = 2;
              iVar1 = *piVar3;
            }
            else {
              iVar1 = (**(code **)(iVar1 + 0x18))(iVar4);
              if (iVar1 != 1) goto LAB_004e640b;
              piVar3 = (int *)this->_padding_;
              uVar5 = 0;
              iVar1 = *piVar3;
            }
            (**(code **)(iVar1 + 0x54))((int)*(short *)((int)piVar3 + 0x4a),6,iVar4,uVar5,0);
          }
LAB_004e640b:
          iVar1 = this->_padding_;
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(short *)(*(int *)(iVar1 + 0x3c) + 0x3c));
      }
      TribeTacticalAIModule::setStrategicNumber(this_00,0xd9,0);
      return;
    }
    iVar1 = (**(code **)(*(int *)this->_padding_ + 0x18))();
    if (iVar1 == 1) {
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x906,&newAlly);
      RGE_Player::sendChatMessage
                ((RGE_Player *)&stack0xfffffeec,this->_padding_,param_1,(char *)0x0,
                 (RGE_Player *)&stack0xfffffeec);
    }
  }
  return;
}

// --------------------------------------------------

// Function: revokeTributeAlliance
// Address: 004e6490
void __thiscall TribeMainDecisionAIModule::revokeTributeAlliance(TribeMainDecisionAIModule *this)
{
  TribeTacticalAIModule *this_00;
  int iVar1;
  int iVar2;
  RGE_Player *this_01;
  char *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  char tempString [256];
  this_00 = &this->tacticalAI;
  iVar1 = *(int *)this->_padding_;
  TribeTacticalAIModule::strategicNumber(this_00,0x80);
  iVar1 = (**(code **)(iVar1 + 0x18))();
  if (iVar1 == 0) {
    iVar5 = iVar1;
    iVar2 = TribeTacticalAIModule::strategicNumber(this_00,0x80);
    DiplomacyAIModule::setStance(&this->diplomacyAI,iVar2,iVar1,iVar5);
    iVar2 = 100;
    iVar5 = 2;
    iVar1 = TribeTacticalAIModule::strategicNumber(this_00,0x80);
    DiplomacyAIModule::setStance(&this->diplomacyAI,iVar1,iVar5,iVar2);
    iVar1 = this->aiPlayer->_padding_;
    TribeTacticalAIModule::strategicNumber(this_00,0x80);
    (**(code **)(iVar1 + 0x28))();
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x8fd,&stack0xfffffef4,0x100);
    puVar4 = &stack0xfffffee8;
    pcVar3 = (char *)0x0;
    iVar1 = TribeTacticalAIModule::strategicNumber(this_00,0x80);
    RGE_Player::sendChatMessage(this_01,this->_padding_,iVar1,pcVar3,puVar4);
    this->waitingOnTribute = 0;
    this->tributeAddressed = 1;
  }
  return;
}

// --------------------------------------------------

// Function: setTributeChat
// Address: 004e6580
// [HELPER] s_C__msdev_work_age1_x1_taimdmd_cp: "C:\msdev\work\age1_x1\taimdmd.cpp"
void __thiscall TribeMainDecisionAIModule::setTributeChat(TribeMainDecisionAIModule *this)
{
  TribeTacticalAIModule *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  this_00 = &this->tacticalAI;
  iVar1 = TribeTacticalAIModule::strategicNumber(this_00,0x7e);
  if (0 < iVar1) {
    iVar1 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x41d);
    iVar2 = TribeTacticalAIModule::strategicNumber(this_00,0x7e);
    iVar3 = TribeTacticalAIModule::strategicNumber(this_00,0x7e);
    iVar4 = TribeTacticalAIModule::strategicNumber(this_00,0x7d);
    this->tributeChatTimeout = (iVar1 % iVar2 - iVar3 / 2) + iVar4;
    return;
  }
  uVar5 = TribeTacticalAIModule::strategicNumber(this_00,0x7d);
  this->tributeChatTimeout = uVar5;
  return;
}

// --------------------------------------------------

// Function: processAICommand
// Address: 004e6600
int __thiscall
TribeMainDecisionAIModule::processAICommand
          (TribeMainDecisionAIModule *this,int param_1,int param_2,int param_3,int param_4,
          int param_5)
{
  DiplomacyAIModule *this_00;
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  
  switch(param_2) {
  case 0:
    TribeInformationAIModule::lookAtMap(&this->informationAI);
    return 1;
  case 1:
    if ((param_1 != *(short *)(this->_padding_ + 0x4a)) &&
       (pRVar1 = RGE_Object_List::find_by_master_id
                           ((RGE_Object_List *)this->aiPlayer->_padding_,0x54,-1.0,-1.0,'\0','\x02',
                            (RGE_Static_Object *)0x0), pRVar1 != (RGE_Static_Object *)0x0)) {
      (**(code **)(this->aiPlayer->_padding_ + 0xf8))
                (param_1,param_3,(float)param_4,*(undefined4 *)(this->aiPlayer->_padding_ + 0xb8));
      return 1;
    }
    break;
  case 2:
  case 3:
    if (param_1 != *(short *)(this->_padding_ + 0x4a)) {
      TribeTacticalAIModule::processCoopAttack(&this->tacticalAI,param_1,param_3,param_4,param_5);
      return 1;
    }
    break;
  default:
    return 0;
  case 6:
    this_00 = &this->diplomacyAI;
    DiplomacyAIModule::setChangeable(this_00,param_3,'\x01');
    if (param_4 == 0) {
      DiplomacyAIModule::setStance(this_00,param_3,0,100);
      iVar2 = 3;
LAB_004e681c:
      DiplomacyAIModule::setRelation(this_00,param_3,iVar2);
    }
    else {
      if (param_4 == 1) {
        DiplomacyAIModule::setStance(this_00,param_3,0,0x31);
        DiplomacyAIModule::setStance(this_00,param_3,2,0x31);
        iVar2 = 1;
        goto LAB_004e681c;
      }
      if (param_4 == 2) {
        DiplomacyAIModule::setStance(this_00,param_3,2,100);
        DiplomacyAIModule::setRelation(this_00,param_3,0);
        iVar2 = RGE_Base_Game::difficulty(rge_base_game);
        if (iVar2 != 4) {
          TRIBE_Command::command_allied_victory
                    (*(TRIBE_Command **)(*(int *)(this->_padding_ + 0x3c) + 0x58),
                     *(short *)(this->_padding_ + 0x4a),'\x01');
          DiplomacyAIModule::setChangeable(this_00,param_3,'\0');
          return 1;
        }
        iVar3 = RGE_Player::computerPlayer
                          (*(RGE_Player **)
                            (*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x40) + param_3 * 4));
        iVar2 = this->_padding_;
        if (iVar3 == 0) {
          TRIBE_Command::command_allied_victory
                    (*(TRIBE_Command **)(*(int *)(iVar2 + 0x3c) + 0x58),*(short *)(iVar2 + 0x4a),
                     '\x01');
          DiplomacyAIModule::setChangeable(this_00,param_3,'\0');
          return 1;
        }
        TRIBE_Command::command_allied_victory
                  (*(TRIBE_Command **)(*(int *)(iVar2 + 0x3c) + 0x58),*(short *)(iVar2 + 0x4a),'\0')
        ;
        DiplomacyAIModule::setChangeable(this_00,param_3,'\0');
        return 1;
      }
    }
    DiplomacyAIModule::setChangeable(this_00,param_3,'\0');
    break;
  case 7:
    this->requiredDiplomacyTributeAmount = param_3;
    TribeTacticalAIModule::setStrategicNumber(&this->tacticalAI,0xd9,1);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: currentScore
// Address: 004e6870
int __thiscall TribeMainDecisionAIModule::currentScore(TribeMainDecisionAIModule *this,int param_1)
{
  int iVar1;
  long lVar2;
  
  if ((0 < param_1) &&
     (iVar1 = *(int *)(this->_padding_ + 0x3c), param_1 <= *(short *)(iVar1 + 0x3c))) {
    lVar2 = RGE_Victory_Conditions::get_victory_points
                      (*(RGE_Victory_Conditions **)
                        (*(int *)(*(int *)(iVar1 + 0x40) + param_1 * 4) + 0x34));
    return lVar2;
  }
  return -1;
}

// --------------------------------------------------

