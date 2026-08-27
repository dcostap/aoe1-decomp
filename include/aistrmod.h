#ifndef AOE1_AISTRMOD_H
#define AOE1_AISTRMOD_H

#include "aimodule.h"

// Declarations for the authentic aistrmod.cpp source module.
// PDB source order is StrategyAIModule::StrategyAIModule (lines 22-24),
// then StrategyAIModule::~StrategyAIModule (line 29).

class StrategyAIModule : public AIModule {
public:
    StrategyAIModule(void* param1, int param2);
    virtual ~StrategyAIModule();
};

#endif
