// ResourceAIModule::addResourceType
// VA: 00412970
// PDB: airesmod.cpp:419-437
// No EH framing

#include "../../include/game_globals.h"
#include "../../include/airesmod_context.h"
#include <stdlib.h>

void* operator new(size_t size);
void operator delete(void* ptr);

void ResourceAIModule::addResourceType(int resource_idx, int type_value)
{
    int* new_types = (int*)operator new(
        this->numberResourceTypesValue[resource_idx] * 4 + 4);

    int count = 0;
    if (this->numberResourceTypesValue[resource_idx] > 0) {
        do {
            new_types[count] = this->resourceTypesValue[resource_idx][count];
            count++;
        } while (count < this->numberResourceTypesValue[resource_idx]);
    }

    new_types[count] = type_value;

    if (this->resourceTypesValue[resource_idx]) {
        operator delete(this->resourceTypesValue[resource_idx]);
    }

    this->resourceTypesValue[resource_idx] = new_types;
    this->numberResourceTypesValue[resource_idx]++;
}
