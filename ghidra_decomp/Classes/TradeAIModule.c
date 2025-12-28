// Class: TradeAIModule
// Size:  0xF4
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
// [16] `scalar_deleting_destructor'
// [17] save
// [18] load
// [19] owner
// [20] order
// [21] notify
// [22] notifyCommander
// [23] notifyCommander
// [24] search
// [25] importantWhenDead
// [26] retryableOrder
// [27] actionRequiresLiveTarget
// [28] bestUnitToAttack
// [29] mostDangerousEnemy
// [30] weakestEnemy
// [31] closestAttacker
// [32] closestObject
// [33] closestResourceObject
// [34] closestUndiscoveredTile
// [35] logDebug
// [36] canAttackUnit
// [37] canAttackUnitAtNeutrality
// [38] stopObject
// [39] attackObject
// [40] attackRoundupObject
// [41] huntObject
// [42] gatherObject
// [43] convertObject
// [44] healObject
// [45] repairObject
// [46] buildObject
// [47] tradeWithObject
// [48] explore
// [49] enterObject
// [50] unload
// [51] transportObject
// [52] moveTo
// [53] moveTo
// [54] moveTo
// [55] evasiveMoveTo
// [56] intelligentEvasiveMoveTo
// [57] runAwayFromAttackers
// [58] followObject
// [59] defendObject
// [60] defendPosition
// [61] seekAndDestroy
// [62] exploreAndDestroy
// [63] importantObject
// [64] convertToLOSResourceType
// [65] canConvert
// [66] processOrder
// [67] processNotify
// [68] processGroupNotify
// [69] processIdle
// [70] processMisc
// [71] processRetryableOrder
//
// Member Layout:
// [0x0F0] MainDecisionAIModule * md
// ----------------------------------------------------------------

// Function: TradeAIModule
// Address: 00412e40
// [HELPER] s_Trade_AI: "Trade AI"
TradeAIModule * __thiscall
TradeAIModule::TradeAIModule(TradeAIModule *this,void *param_1,int param_2)
{
  AIModule::AIModule((AIModule *)this,s_Trade_AI,0x3f2,param_2,param_1);
  this->md = (MainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00412e80
void * __thiscall TradeAIModule::_scalar_deleting_destructor_(TradeAIModule *this,uint param_1)
{
  ~TradeAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TradeAIModule
// Address: 00412ea0
// [HELPER] s_Trade_AI: "Trade AI"
TradeAIModule * __thiscall TradeAIModule::TradeAIModule(TradeAIModule *this,int param_1,int param_2)
{
  AIModule::AIModule((AIModule *)this,s_Trade_AI,0x3f2,param_1,(void *)0x0);
  this->md = (MainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: ~TradeAIModule
// Address: 00412ed0
void __thiscall TradeAIModule::~TradeAIModule(TradeAIModule *this)
{
  this->_padding_ = (int)&_vftable_;
  AIModule::~AIModule((AIModule *)this);
  return;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 00412ee0
void __thiscall TradeAIModule::setMainDecisionAI(TradeAIModule *this,MainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00412ef0
int __thiscall TradeAIModule::save(TradeAIModule *this,int param_1)
{
  return 1;
}

// --------------------------------------------------

