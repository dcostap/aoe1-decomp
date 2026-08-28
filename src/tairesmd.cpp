// Authentic PDB-ordered source module for C:\\msdev\\work\\age1_x1\\tairesmd.cpp.
// The ten normal owners below follow the original source-line and address order.
// The nearby 004E6B80 scalar deleting destructor is compiler-generated.

#include "../include/tairesmd.h"
#include "../include/taimdmd.h"
#include "../include/player.h"

extern const char s_Resource_AI[];
void rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int file_handle, void* data, int size);

// 004E6B40 TribeResourceAIModule::TribeResourceAIModule(void*, int, int, int, int, int)
// PDB: tairesmd.cpp lines 30-31. Status: matching.
// BINARY NOTE: Both members are initialized in the initializer list. VC5 then
// emits the derived vtable store after the member stores, matching the binary.
TribeResourceAIModule::TribeResourceAIModule(void* param_1, int param_2,
                                             int param_3, int param_4,
                                             int param_5, int param_6)
    : AIModule((char*)s_Resource_AI, 0x3EF, param_2, param_1),
      md(0),
      numberResourcesValue(param_3) {
}

// 004E6BA0 TribeResourceAIModule::TribeResourceAIModule(int, int)
// PDB: tairesmd.cpp lines 38-40. Status: matching.
TribeResourceAIModule::TribeResourceAIModule(int param_1, int param_2)
    : AIModule("ResAI", 0x3EF, param_1, 0),
      md(0)
{
    rge_read(param_2, &this->numberResourcesValue, 4);
}

// 004E6C20 TribeResourceAIModule::~TribeResourceAIModule()
// PDB: tairesmd.cpp line 45. Status: matching.
TribeResourceAIModule::~TribeResourceAIModule()
{
}

// 004E6C30 TribeResourceAIModule::setMainDecisionAI
// PDB: tairesmd.cpp lines 51-53. Status: matching.
void TribeResourceAIModule::setMainDecisionAI(TribeMainDecisionAIModule* v)
{
    this->md = v;
}

// 004E6C40 TribeResourceAIModule::save
// PDB: tairesmd.cpp lines 58-61. Status: matching.
int TribeResourceAIModule::save(int file_handle)
{
    rge_write(file_handle, &this->numberResourcesValue, 4);
    return 1;
}

// 004E6C60 TribeResourceAIModule::numberResources
// PDB: tairesmd.cpp lines 66-68. Status: matching.
int TribeResourceAIModule::numberResources() const
{
    return this->numberResourcesValue;
}

// 004E6C70 TribeResourceAIModule::resource
// PDB: tairesmd.cpp lines 73-77. Status: matching.
int TribeResourceAIModule::resource(int index) const
{
    if ((index >= 0) && (index < this->numberResourcesValue)) {
        return (int)this->md->player->attributes[index];
    }
    return -1;
}

// 004E6CA0 TribeResourceAIModule::resourcesAvailable
// PDB: tairesmd.cpp lines 82-110. Status: scratch.
// BINARY NOTE: Canonical Main Decision and Player composition emits a 56-byte
// mismatch. The direct targets and boundary match, but no current drift claim
// is valid.
int TribeResourceAIModule::resourcesAvailable(ResourceItem* item)
{
    if (item == 0)
        return 0;
    if (numberResourcesValue != item->number())
        return 0;

    int i = 0;
    int n = item->number();
    while (i < n) {
        float* available = this->md->player->attributes;
        int needed = item->value(i);
        if ((float)needed > available[i])
            return 0;
        ++i;
        n = item->number();
    }

    return 1;
}

// 004E6D40 TribeResourceAIModule::unavailableResource
// PDB: tairesmd.cpp lines 115-128. Status: matching.
int TribeResourceAIModule::unavailableResource(ResourceItem* item)
{
    if (item == 0)
        return 0;

    if (this->numberResourcesValue == item->number()) {
        int i = 0;
        while (i < item->number()) {
            float* amounts = this->md->player->attributes;
            if (amounts[i] < (float)item->value(i)) {
                return i;
            }
            ++i;
        }
        return -1;
    }
    return -1;
}

// 004E6DD0 TribeResourceAIModule::resourceName
// PDB: tairesmd.cpp lines 133-143. Status: matching.
char* TribeResourceAIModule::resourceName(int param_1)
{
    if (param_1 == 0) {
        return (char*)"Food";
    }
    if (param_1 == 1) {
        return (char*)"Wood";
    }
    if (param_1 == 2) {
        return (char*)"Stone";
    }
    if (param_1 == 3) {
        return (char*)"Gold";
    }
    return (char*)"Unknown";
}
