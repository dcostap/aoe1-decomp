#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIModule {
public:
    char gap_00[0xF0];
};

class ResourceItem {
public:
    char gap_0[0xC];
    int arr[24];
    int count;

    int value(int index);
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    void* md;
    char civilians[0x10];
    char civilianExplorers[0x10];
    char soldiers[0x10];
    char ungroupedSoldiers[0x10];
    char boats[0x10];
    char warBoats[0x10];
    char fishingBoats[0x10];
    char tradeBoats[0x10];
    char transportBoats[0x10];
    char artifacts[0x10];
    int sn[226];
    char gap_01[0x85C];
    int desiredGathererDistribution[4];
    char gap_02[0x20];
    ResourceItem neededResources;

    int requiredGatherAmount(int index);
};

#endif
int TribeTacticalAIModule::requiredGatherAmount(int index) {
    if (this->desiredGathererDistribution[index] == 0) {
        return this->sn[0x94];
    }
    int value = this->neededResources.value(index);
    return value / this->desiredGathererDistribution[index];
}
