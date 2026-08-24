#ifndef AOE1_AISTRMOD_CONTEXT_H
#define AOE1_AISTRMOD_CONTEXT_H

// Authentic shared declarations for C:\\msdev\\work\\age1_x1\\aistrmod.cpp.
// PDB source order is StrategyAIModule::StrategyAIModule (lines 22-24),
// then StrategyAIModule::~StrategyAIModule (line 29).
//
// BINARY NOTE: the destructor stores the StrategyAIModule vptr and tail-jumps
// to AIModule::~AIModule.  The real base ownership and virtual surface preserve
// that direct target.  The vector-deleting destructor is compiler generated.
class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int param1, void* param2);
};

class StrategyAIModule : public AIModule {
public:
    StrategyAIModule(void* param1, int param2);
    virtual ~StrategyAIModule();
};

#endif
