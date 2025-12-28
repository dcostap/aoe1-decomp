// Class: InformationAIModule
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

// Function: InformationAIModule
// Address: 0040cd90
// [HELPER] s_InfAI: "InfAI"
/* public: __thiscall InformationAIModule::InformationAIModule(void *,int) */

InformationAIModule * __thiscall
InformationAIModule::InformationAIModule(InformationAIModule *this,void *param_1,int param_2)
{
  AIModule::AIModule((AIModule *)this,s_InfAI,0x3ed,param_2,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0040cdc0
/* public: virtual void * __thiscall InformationAIModule::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
InformationAIModule::_vector_deleting_destructor_(InformationAIModule *this,uint param_1)
{
  ~InformationAIModule(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~InformationAIModule
// Address: 0040cde0
/* public: virtual __thiscall InformationAIModule::~InformationAIModule(void) */

void __thiscall InformationAIModule::~InformationAIModule(InformationAIModule *this)
{
  *(undefined ***)this = &_vftable_;
  AIModule::~AIModule((AIModule *)this);
  return;
}

// --------------------------------------------------

