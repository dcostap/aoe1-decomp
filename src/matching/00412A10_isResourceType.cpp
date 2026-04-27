// ResourceAIModule::isResourceType
// VA: 00412A10
// PDB: airesmod.cpp:442-455
// No EH framing

#include "../../include/game_globals.h"
#include <stdlib.h>

class AIModule {
public:
    AIModule(char* name, int id, int param_2, void* param_1);
    virtual ~AIModule();
    void logCommonHistory(char* format, ...);
    char gap_04[0xEC];
};

class ResourceAIModule : public AIModule {
public:
    void* md;                      // +0xF0
    int numberResourcesValue;      // +0xF4
    int* resourceValue;            // +0xF8
    int* minValue;                 // +0xFC
    int* maxValue;                 // +0x100
    int** resourceTypesValue;      // +0x104
    int* numberResourceTypesValue; // +0x108

    int isResourceType(int resource_idx, int type_to_check);
};

int ResourceAIModule::isResourceType(int resource_idx, int type_to_check)
{
    this->logCommonHistory("Entering isResourceType: r=%d, t=%d.",
        resource_idx, type_to_check);
    this->logCommonHistory("  There are %d resource types for resource %d.",
        this->numberResourceTypesValue[resource_idx], resource_idx);

    for (int i = 0; i < this->numberResourceTypesValue[resource_idx]; i++) {
            this->logCommonHistory("    Checking against type %d.",
                this->resourceTypesValue[resource_idx][i]);
            if (this->resourceTypesValue[resource_idx][i] == type_to_check) {
                this->logCommonHistory("      Match!  Returning TRUE.");
                return 1;
            }
    }

    this->logCommonHistory("  No match!  Returning FALSE.");
    return 0;
}
