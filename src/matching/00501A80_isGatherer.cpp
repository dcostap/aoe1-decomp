#ifndef TAITACMD_SHARED_CONTEXT
struct GathererEntry {
    int id;
    char data[20];
};

class TribeTacticalAIModule {
public:
    char gap_00[0x51C];
    GathererEntry gatherers[50];

    int isGatherer(int unitId);
};

#endif
int TribeTacticalAIModule::isGatherer(int unitId) {
    int i;

    for (i = 0; i < 0x32; i++) {
        if (this->gatherers[i].id == unitId)
            return 1;
    }
    return 0;
}
