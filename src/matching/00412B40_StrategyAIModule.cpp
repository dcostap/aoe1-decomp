// VA: 00412B40 ~StrategyAIModule (11B)
// Translation unit: aistrmod.cpp, source line 29.
//
// BINARY NOTE: the target writes the StrategyAIModule vptr, then tail-jumps to
// AIModule::~AIModule.  The base owner and direct target are therefore part of
// this wrapper's ABI.  Do not use a synthetic base class or a local destructor.
//
// Context categories: source ownership, class ABI, TU order, compiler flags.
// Policy review: no inline assembly, dummy function, fake vtable, volatility,
// metric-only alias, or config change.
#ifndef AISTRMOD_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
};

class StrategyAIModule : public AIModule {
public:
    virtual ~StrategyAIModule();
};
#endif

StrategyAIModule::~StrategyAIModule() {
}
