// 005007F0 removeFromGroup: first pass follows the PDB shape directly.
// Likely mismatch axis, if any, is call ordering or the local temp/register basin.

class TribeMainDecisionAIModule;

class TacticalAIGroup {
public:
    int removeUnit(int unit, TribeMainDecisionAIModule* md);
    int numberUnits() const;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;

    TacticalAIGroup* group(int param_1, int param_2, int param_3, int param_4);
    void removeGroup(int id);
    int removeFromGroup(int param_1, int param_2);
};

int TribeTacticalAIModule::removeFromGroup(int param_1, int param_2) {
    TacticalAIGroup* group = this->group(param_2, -1, -1, -1);
    if (group == 0) {
        return 0;
    }

    int result = group->removeUnit(param_1, this->md);
    if (group->numberUnits() == 0) {
        this->removeGroup(param_2);
    }

    return result;
}
