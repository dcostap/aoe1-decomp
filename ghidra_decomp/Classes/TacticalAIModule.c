// Class: TacticalAIModule
// Size:  0xF0
//
// VTable Layout:
// [00] `vector_deleting_destructor'
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
// [15] `scalar_deleting_destructor'
// [16] `scalar_deleting_destructor'
// [17] loggingHistory
// [18] setLogHistory
// [19] toggleLogHistory
// [20] setHistoryFilename
// [21] loggingCommonHistory
// [22] setLogCommonHistory
// [23] toggleLogCommonHistory
// [24] loadState
// [25] saveState
// [26] gleanState
// [27] processMessage
// [28] update
// [29] setCallbackMessage
// [30] filterOutMessage
// [31] save
// [32] `scalar_deleting_destructor'
// [33] save
// [34] load
// [35] owner
// [36] order
// [37] notify
// [38] notifyCommander
// [39] notifyCommander
// [40] search
// [41] importantWhenDead
// [42] retryableOrder
// [43] actionRequiresLiveTarget
// [44] bestUnitToAttack
// [45] mostDangerousEnemy
// [46] weakestEnemy
// [47] closestAttacker
// [48] closestObject
// [49] closestResourceObject
// [50] closestUndiscoveredTile
// [51] logDebug
// [52] canAttackUnit
// [53] canAttackUnitAtNeutrality
// [54] stopObject
// [55] attackObject
// [56] attackRoundupObject
// [57] huntObject
// [58] gatherObject
// [59] convertObject
// [60] healObject
// [61] repairObject
// [62] buildObject
// [63] tradeWithObject
// [64] explore
// [65] enterObject
// [66] unload
// [67] transportObject
// [68] moveTo
// [69] moveTo
// [70] moveTo
// [71] evasiveMoveTo
// [72] intelligentEvasiveMoveTo
// [73] runAwayFromAttackers
// [74] followObject
// [75] defendObject
// [76] defendPosition
// [77] seekAndDestroy
// [78] exploreAndDestroy
// [79] importantObject
// [80] convertToLOSResourceType
// [81] canConvert
// [82] processOrder
// [83] processNotify
// [84] processGroupNotify
// [85] processIdle
// [86] processMisc
// [87] processRetryableOrder
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TacticalAIModule
// Address: 00412b50
// [HELPER] s_TacAI: "TacAI"
/* public: __thiscall TacticalAIModule::TacticalAIModule(void *,int) */

TacticalAIModule * __thiscall
TacticalAIModule::TacticalAIModule(TacticalAIModule *this,void *param_1,int param_2)
{
  AIModule::AIModule((AIModule *)this,s_TacAI,0x3f1,param_2,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00412b80
/* public: virtual void * __thiscall TacticalAIModule::`vector deleting destructor'(unsigned int) */

void * __thiscall
TacticalAIModule::_vector_deleting_destructor_(TacticalAIModule *this,uint param_1)
{
  ~TacticalAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TacticalAIModule
// Address: 00412ba0
/* public: virtual __thiscall TacticalAIModule::~TacticalAIModule(void) */

void __thiscall TacticalAIModule::~TacticalAIModule(TacticalAIModule *this)
{
  *(undefined ***)this = &_vftable_;
  AIModule::~AIModule((AIModule *)this);
  return;
}

// --------------------------------------------------

