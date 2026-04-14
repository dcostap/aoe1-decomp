struct TribeTacticalAIModule {
    char gap_0[0xD78];
    int desiredGathererCounts[4];
};

int __fastcall desiredGathererCount(TribeTacticalAIModule* self, int, int index) {
    if (index < 0 || index >= 4)
        return -1;
    return self->desiredGathererCounts[index];
}
