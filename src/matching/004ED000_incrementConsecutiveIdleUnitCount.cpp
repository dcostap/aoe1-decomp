#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    char gap_0[0x1CC];
    int field_1CC;

    void incrementConsecutiveIdleUnitCount(int value);
};
#endif

void TacticalAIGroup::incrementConsecutiveIdleUnitCount(int value) {
    this->field_1CC += value;
}
