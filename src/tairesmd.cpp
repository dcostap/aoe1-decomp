
#include "../include/tairesmd.h"
#include "../include/taimdmd.h"
#include "../include/player.h"

extern const char s_Resource_AI[];
void rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int file_handle, void* data, int size);

TribeResourceAIModule::TribeResourceAIModule(void* param_1, int param_2,
                                             int param_3, int param_4,
                                             int param_5, int param_6)
    : AIModule((char*)s_Resource_AI, 0x3EF, param_2, param_1),
      md(0),
      numberResourcesValue(param_3) {
}

TribeResourceAIModule::TribeResourceAIModule(int param_1, int param_2)
    : AIModule("ResAI", 0x3EF, param_1, 0),
      md(0)
{
    rge_read(param_2, &this->numberResourcesValue, 4);
}

TribeResourceAIModule::~TribeResourceAIModule()
{
}

void TribeResourceAIModule::setMainDecisionAI(TribeMainDecisionAIModule* v)
{
    this->md = v;
}

int TribeResourceAIModule::save(int file_handle)
{
    rge_write(file_handle, &this->numberResourcesValue, 4);
    return 1;
}

int TribeResourceAIModule::numberResources() const
{
    return this->numberResourcesValue;
}

int TribeResourceAIModule::resource(int index) const
{
    if ((index >= 0) && (index < this->numberResourcesValue)) {
        return (int)this->md->player->attributes[index];
    }
    return -1;
}

// Canonical Main Decision and Player composition emits a 56-byte
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
