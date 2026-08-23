// ResourceAIModule::~ResourceAIModule destructor
// VA: 00412480
// PDB: airesmod.cpp:49-58
// EH-framed, needs /GX

#include "../../include/game_globals.h"
#include "../../include/airesmod_context.h"
#include <stdlib.h>

void operator delete(void* ptr);

ResourceAIModule::~ResourceAIModule()
{
    operator delete(this->resourceValue);
    operator delete(this->minValue);
    operator delete(this->maxValue);

    if (this->numberResourcesValue > 0) {
        for (int i = 0; i < this->numberResourcesValue; i++) {
            operator delete(this->resourceTypesValue[i]);
        }
    }

    operator delete(this->resourceTypesValue);
    operator delete(this->numberResourceTypesValue);
}
