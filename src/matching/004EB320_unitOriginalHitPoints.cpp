// VA: 004EB320 TacticalAIGroup::unitOriginalHitPoints (72 B)
// Scans unitsValue array for the unit_index-th valid entry, returns corresponding HP
// Note: uses single i=-1 counter matching original asm topology

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];              // +0x1C
    int unitsOriginalHitPointsValue[40]; // +0xBC

    int unitOriginalHitPoints(int unit_index);
};
#endif

int TacticalAIGroup::unitOriginalHitPoints(int unit_index) {
    int idx = 0;
    int i = -1;
    int limit = unit_index + 1;

    for (; idx < 40; idx++) {
        if (i >= limit)
            return -1;
        if (this->unitsValue[idx] != -1)
            i++;
        if (i == unit_index)
            return this->unitsOriginalHitPointsValue[idx];
    }
    return -1;
}
