// 00501920 TribeTacticalAIModule::addGatherer(int)
// Source: taitacmd.cpp lines 12119-12155
// Attempt log:
// - Replaced stub with full gatherer slot scan/add/duplicate-return logic.
// - Exact match with explicit `goto next` after recording the first free slot,
//   preserving the original duplicate-check fallthrough and return layout.

extern "C" void __cdecl logCommonHistory(void* module, const char* text);

struct UnitData {
    int id;
    char gap_04[0x10 - 0x04];
    int target;
    int lastTaskTime;
};

class TribeTacticalAIModule {
public:
    char gap_000[0x51C];
    UnitData gatherers[50];
    int numberGatherersValue;

    UnitData* addGatherer(int id);
};

UnitData* TribeTacticalAIModule::addGatherer(int id)
{
    int index;
    UnitData* item;
    int freeIndex;
    int value;

    if (id == -1) {
        logCommonHistory(this, (const char*)0x00588AA8);
        return 0;
    }
    freeIndex = -1;
    index = 0;
    item = this->gatherers;
    while (index < 50) {
        value = item->id;
        if (value == -1) {
            if (freeIndex == -1) {
                freeIndex = index;
                goto next;
            }
        }
        if (value == id) {
            return &this->gatherers[index];
        }
next:
        index = index + 1;
        item = item + 1;
    }
    if (freeIndex == -1) {
        return 0;
    }
    this->gatherers[freeIndex].id = id;
    this->gatherers[freeIndex].target = -1;
    this->gatherers[freeIndex].lastTaskTime = 0;
    this->numberGatherersValue = this->numberGatherersValue + 1;
    return &this->gatherers[freeIndex];
}
