struct GathererEntry {
    int objectId;
    int targetId;
    char data[16];
};

struct TribeTacticalAIModule {
    char gap_0[0x51C];
    GathererEntry gatherers[50];
    char gap_after[0x100];
    int numberGatherers;
};

int __fastcall numberGatherersWithTarget(TribeTacticalAIModule* self, int, int targetId) {
    int count = 0;
    for (int i = 0; i < self->numberGatherers; i++) {
        if (self->gatherers[i].targetId == targetId)
            count++;
    }
    return count;
}
