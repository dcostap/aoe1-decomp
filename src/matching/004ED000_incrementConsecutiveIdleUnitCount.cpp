#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    char gap_0[0x1CC];
    int field_1CC;

    void incrementConsecutiveIdleUnitCount(unsigned long value);
};
#endif

void TacticalAIGroup::incrementConsecutiveIdleUnitCount(unsigned long value) {
    this->field_1CC += value;
}
