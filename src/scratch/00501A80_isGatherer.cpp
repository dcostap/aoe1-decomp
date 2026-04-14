struct GathererEntry {
    int field_0;
    char data[20];
};

struct TribeTacticalAIModule {
    char gap_0[0x51C];
    GathererEntry gatherers[50];
    char gap_after[0x100];
    int numberGatherers;
};

int __fastcall isGatherer(TribeTacticalAIModule* self, int, int unitId) {
    for (int i = 0; i < self->numberGatherers; i++) {
        if (self->gatherers[i].field_0 == unitId)
            return 1;
    }
    return 0;
}
