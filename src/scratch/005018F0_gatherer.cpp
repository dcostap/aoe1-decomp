struct GathererEntry {
    char data[24];
};

struct TribeTacticalAIModule {
    char gap_0[0x51C];
    GathererEntry gatherers[50];
    char gap_after[0x100];
    int numberGatherers;
};

GathererEntry* __fastcall gatherer(TribeTacticalAIModule* self, int, int index) {
    if (index < 0)
        return 0;
    if (index >= self->numberGatherers)
        return 0;
    return &self->gatherers[index];
}
