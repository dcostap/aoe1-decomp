#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x5A4];
    int numberItemsIntoBuildListValue;
    int numberItemsIntoBuildList();
};
#endif

int BuildAIModule::numberItemsIntoBuildList() { return this->numberItemsIntoBuildListValue; }
