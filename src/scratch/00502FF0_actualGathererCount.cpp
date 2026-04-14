struct TribeTacticalAIModule {
    char gap_0[0xD68];
    int actualGathererCounts[4];
};

int __fastcall actualGathererCount(TribeTacticalAIModule* self, int, int index) {
    if (index < 0 || index >= 4)
        return -1;
    return self->actualGathererCounts[index];
}
