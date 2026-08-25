// TribeInformationAIModule::addResourceType
// VA: 004E23A0
// PDB: taiinfmd.cpp:7119-7132
// Default flags: /nologo /c /O2 /Oy

#include <stdlib.h>

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    char gap_00[0x4C8];
    int** resourceTypesValue;        // +0x4C8
    int* numberResourceTypesValue;   // +0x4CC

    void addResourceType(int resource_idx, int type_value);
};
#endif

void* operator new(size_t size);
void operator delete(void* ptr);

#endif
void TribeInformationAIModule::addResourceType(int resource_idx, int type_value)
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
