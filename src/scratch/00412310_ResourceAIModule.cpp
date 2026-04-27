// ResourceAIModule::ResourceAIModule constructor
// VA: 00412310
// PDB: airesmod.cpp:26-44
// EH-framed, needs /GX

#include "../../include/game_globals.h"
#include <stdlib.h>

class AIModule {
public:
    AIModule(char* name, int id, int param_2, void* param_1);
    virtual ~AIModule();
    char gap_04[0xEC];
};

class ResourceAIModule : public AIModule {
public:
    void* md;                   // +0xF0
    int numberResourcesValue;   // +0xF4
    int* resourceValue;         // +0xF8
    int* minValue;              // +0xFC
    int* maxValue;              // +0x100
    int** resourceTypesValue;   // +0x104
    int* numberResourceTypesValue; // +0x108

    ResourceAIModule(void* param_1, int param_2, int param_3,
        int param_4, int param_5, int param_6);
    virtual ~ResourceAIModule();
};

void* operator new(size_t size);
void operator delete(void* ptr);

ResourceAIModule::ResourceAIModule(void* param_1, int param_2,
    int param_3, int param_4, int param_5, int param_6)
    : AIModule("Resource AI", 0x3EF, param_2, param_1)
{
    this->md = 0;
    this->numberResourcesValue = param_3;

    this->resourceValue = (int*)operator new(param_3 * 4);
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
