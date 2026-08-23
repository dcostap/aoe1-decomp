#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x19C];
    int buildListLengthValue;
    int buildListLength();
};
#endif

int BuildAIModule::buildListLength() { return this->buildListLengthValue; }
