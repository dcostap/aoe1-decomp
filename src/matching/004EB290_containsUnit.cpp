#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    int containsUnit(int unitId);
    char gap_00[0x1C];
    int unitsValue[40];
};
#endif

int TacticalAIGroup::containsUnit(int unitId) {
    for (int i = 0; i < 0x28; ++i) {
        if (this->unitsValue[i] == unitId) {
            return 1;
        }
    }
    return 0;
}
