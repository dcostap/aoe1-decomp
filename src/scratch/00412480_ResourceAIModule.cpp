// ResourceAIModule::~ResourceAIModule destructor
// VA: 00412480
// PDB: airesmod.cpp:49-58
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
