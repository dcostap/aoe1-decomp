#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x3A2];
    char currentBuildItemRequestedValue[1];
    char* currentBuildItemRequested();
};
#endif

char* BuildAIModule::currentBuildItemRequested() { return this->currentBuildItemRequestedValue; }
