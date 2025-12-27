// Class: TacticalAIModule
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

