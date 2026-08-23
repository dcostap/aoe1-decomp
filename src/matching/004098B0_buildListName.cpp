#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x1A0];
    char buildListNameValue[1];
    char* buildListName();
};
#endif

char* BuildAIModule::buildListName() { return this->buildListNameValue; }
