#ifndef AOE1_AITACMOD_H
#define AOE1_AITACMOD_H

// Declarations recovered for the original aitacmod.cpp source module.
#include "aimodule.h"

class TacticalAIModule : public AIModule {
public:
    TacticalAIModule(void* param1, int param2);
    virtual ~TacticalAIModule();
};

typedef char aitacmod_tactical_ai_module_size[
    (sizeof(TacticalAIModule) == 0xF0) ? 1 : -1];

#endif
