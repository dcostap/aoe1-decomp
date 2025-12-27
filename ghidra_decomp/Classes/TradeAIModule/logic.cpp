// Class: TradeAIModule
// Function: TradeAIModule
// Address: 00412e40
// [HELPER] s_Trade_AI: "Trade AI"
/* public: __thiscall TradeAIModule::TradeAIModule(void *,int) */

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
/* public: virtual void * __thiscall TradeAIModule::`scalar deleting destructor'(unsigned int) */

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
/* public: __thiscall TradeAIModule::TradeAIModule(int,int) */

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
/* public: virtual __thiscall TradeAIModule::~TradeAIModule(void) */

void __thiscall TradeAIModule::~TradeAIModule(TradeAIModule *this)
{
  this->_padding_ = (int)&_vftable_;
  AIModule::~AIModule((AIModule *)this);
  return;
}

// --------------------------------------------------

// Function: setMainDecisionAI
// Address: 00412ee0
/* public: void __thiscall TradeAIModule::setMainDecisionAI(class MainDecisionAIModule *) */

void __thiscall TradeAIModule::setMainDecisionAI(TradeAIModule *this,MainDecisionAIModule *param_1)
{
  this->md = param_1;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00412ef0
/* public: virtual int __thiscall TradeAIModule::save(int) */

int __thiscall TradeAIModule::save(TradeAIModule *this,int param_1)
{
  return 1;
}

// --------------------------------------------------

