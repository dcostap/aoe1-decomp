// Class: StrategyAIModule
// Function: StrategyAIModule
// Address: 00412af0
// [HELPER] s_Strategy_AI: "Strategy AI"
/* public: __thiscall StrategyAIModule::StrategyAIModule(void *,int) */

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
/* public: virtual void * __thiscall StrategyAIModule::`vector deleting destructor'(unsigned int) */

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
/* public: virtual __thiscall StrategyAIModule::~StrategyAIModule(void) */

void __thiscall StrategyAIModule::~StrategyAIModule(StrategyAIModule *this)
{
  *(undefined ***)this = &_vftable_;
  AIModule::~AIModule((AIModule *)this);
  return;
}

// --------------------------------------------------

