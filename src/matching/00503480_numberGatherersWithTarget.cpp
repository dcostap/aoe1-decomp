struct GathererEntry {
    char gap_00[0x10];
    int target;
    char gap_14[0x04];
};

class TribeTacticalAIModule {
public:
    char gap_00[0x51C];
    GathererEntry gatherers[50];
    int numberGatherers;

    int numberGatherersWithTarget(int targetId);
};

int TribeTacticalAIModule::numberGatherersWithTarget(int targetId) {
    int count;
    int remaining;
    int* target;

    remaining = this->numberGatherers;
    count = 0;
    if (remaining > 0) {
        target = &this->gatherers[0].target;
        do {
            if (*target == targetId)
                count = count + 1;
            target = target + 6;
            remaining = remaining - 1;
        } while (remaining != 0);
    }
    return count;
}
