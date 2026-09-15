#ifndef AOE1_AISTRMOD_H
#define AOE1_AISTRMOD_H

#include "aimodule.h"


class StrategyAIModule : public AIModule {
public:
    StrategyAIModule(void* pW, int playerID);
    virtual ~StrategyAIModule();
};

#endif
