#ifndef AOE1_AIINFMOD_H
#define AOE1_AIINFMOD_H

#include "aimodule.h"

class InformationAIModule : public AIModule {
public:
    InformationAIModule(void* param1, int param2);
    virtual ~InformationAIModule();
};

typedef char aiinfmod_information_ai_module_size[
    (sizeof(InformationAIModule) == 0xF0) ? 1 : -1];

#endif
