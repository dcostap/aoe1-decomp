// Class: StrategyAIModule
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
//
// Member Layout:
// ----------------------------------------------------------------

// Function: StrategyAIModule
// Address: 00412af0
// [HELPER] s_Strategy_AI: "Strategy AI"
StrategyAIModule * __thiscall
StrategyAIModule::StrategyAIModule(StrategyAIModule *this,void *param_1,int param_2)
{
  AIModule::AIModule((AIModule *)this,s_Strategy_AI,0x3f0,param_2,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00412b20
void * __thiscall
StrategyAIModule::_vector_deleting_destructor_(StrategyAIModule *this,uint param_1)
{
  ~StrategyAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~StrategyAIModule
// Address: 00412b40
void __thiscall StrategyAIModule::~StrategyAIModule(StrategyAIModule *this)
{
  *(undefined ***)this = &_vftable_;
  AIModule::~AIModule((AIModule *)this);
  return;
}

// --------------------------------------------------

