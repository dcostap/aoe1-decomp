class TacticalAIGroup;
class TribeStrategyAIModule;
class TribeMainDecisionAIModule {
public:
    char gap_00[0x10E74];
};

class TribeStrategyAIModule {
public:
    int currentVictoryCondition();
    int secondTargetID();
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;

    TacticalAIGroup* group(int a1, int a2, int a3, int a4);
    int itemToBringToArea();
};

class TacticalAIGroup {
public:
    char gap_00[0x330];
};

int TribeTacticalAIModule::itemToBringToArea()
{
    int target;

    if (((TribeStrategyAIModule*)((char*)this->md + 0x10E74))->currentVictoryCondition() == 4) {
        target = ((TribeStrategyAIModule*)((char*)this->md + 0x10E74))->secondTargetID();
        if (this->group(-1, -1, -1, target) == 0)
            return target;
    }
    return -1;
}

TacticalAIGroup* TribeTacticalAIModule::group(int a1, int a2, int a3, int a4)
{
    return 0;
}
