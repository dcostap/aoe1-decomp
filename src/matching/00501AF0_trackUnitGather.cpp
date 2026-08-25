#ifndef TAITACMD_SHARED_CONTEXT
// attempt 1: direct resource-delta check plus gatherer lookup/update in the same order as the asm
// exact match landed once the resource AI was modeled as a real nested subobject and the +0x0d98 delta array was placed correctly

#ifndef TAITACMD_SHARED_CONTEXT
class TribeResourceAIModule {
public:
    int resource(int resource_id);
};

class AIManager {
public:
    char gap_00[0x10D7C];
    TribeResourceAIModule resource_ai;
};

class UnitData {
public:
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    unsigned long lastTaskTime;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    AIManager* md;
    char gap_01[0xCA4];
    int resourceDifferenceValue[0x36];

    void updateNeededResources();
    UnitData* gatherer(int unit_id);
    void trackUnitGather(int unit_id, int resource_id, int amount);
};

#endif
void TribeTacticalAIModule::trackUnitGather(int unit_id, int resource_id, int amount) {
    UnitData* entry;

    if (this->resourceDifferenceValue[resource_id] < 0) {
        if (this->md->resource_ai.resource(resource_id) + this->resourceDifferenceValue[resource_id] > 0) {
            this->updateNeededResources();
        }
    }

    entry = this->gatherer(unit_id);
    if (entry != 0 && entry->data1 == resource_id) {
        entry->data3 += amount;
    }
}
#else
void TribeTacticalAIModule::trackUnitGather(int, int, int) {}
#endif
