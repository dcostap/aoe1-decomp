#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x2A1];
    char lastBuildItemRequestedValue[1];
    char* lastBuildItemRequested();
};
#endif

char* BuildAIModule::lastBuildItemRequested() { return this->lastBuildItemRequestedValue; }
