#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x4A3];
    char nextBuildItemRequestedValue[1];
    char* nextBuildItemRequested();
};
#endif

char* BuildAIModule::nextBuildItemRequested() { return this->nextBuildItemRequestedValue; }
