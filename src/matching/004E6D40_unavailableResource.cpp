// 004E6D40 TribeResourceAIModule::unavailableResource
// Source: tairesmd.cpp lines 115-128
// Size: 134 bytes, no EH
// Attempt log:
// - Previous file had only notes, producing no .text section.
// - 2026-05-10 StarryZephyr pass: implemented natural typed source matching packet behavior.

class ResourceItem {
public:
    int number();
    int value(int index);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    void* player;
};

class TribeResourceAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;
    int numberResourcesValue;

    int unavailableResource(ResourceItem* item);
};

int TribeResourceAIModule::unavailableResource(ResourceItem* item)
{
    if (item == 0)
        return 0;

    if (this->numberResourcesValue == item->number()) {
        int i = 0;
        while (i < item->number()) {
            float* amounts = *(float**)((char*)this->md->player + 0x50);
            if (amounts[i] < (float)item->value(i)) {
                return i;
            }
            ++i;
        }
        return -1;
    }
    return -1;
}
