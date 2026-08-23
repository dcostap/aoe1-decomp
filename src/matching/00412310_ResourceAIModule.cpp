// ResourceAIModule::ResourceAIModule constructor
// VA: 00412310
// PDB: airesmod.cpp:26-44
// EH-framed, needs /GX
// BINARY NOTE: keep the explicit vtable store after `param_3 * 4` is formed.
// VC5 merges it with the normal derived-class store at the required position.

#include "../../include/game_globals.h"
#include "../../include/airesmod_context.h"
#include <stdlib.h>

void* operator new(size_t size);
void operator delete(void* ptr);

ResourceAIModule::ResourceAIModule(void* param_1, int param_2,
    int param_3, int param_4, int param_5, int param_6)
    : AIModule("Resource AI", 0x3EF, param_2, param_1)
{
    this->md = 0;
    this->numberResourcesValue = param_3;
    int bytes = param_3 * 4;
    *(void**)this = (void*)0x56E9D8;

    this->resourceValue = (int*)operator new(bytes);
    this->minValue = (int*)operator new(this->numberResourcesValue * 4);
    this->maxValue = (int*)operator new(this->numberResourcesValue * 4);
    this->resourceTypesValue = (int**)operator new(this->numberResourcesValue * 4);
    this->numberResourceTypesValue = (int*)operator new(this->numberResourcesValue * 4);

    for (int i = 0; i < this->numberResourcesValue; i++) {
        this->resourceValue[i] = param_4;
        this->minValue[i] = param_5;
        this->maxValue[i] = param_6;
        this->numberResourceTypesValue[i] = 0;
        this->resourceTypesValue[i] = 0;
    }
}
