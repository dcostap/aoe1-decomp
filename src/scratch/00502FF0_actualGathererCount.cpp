struct TribeTacticalAIModule {
    char gap_0[0xD68];
    int actualGathererCounts[4]; // 0xD68
    int desiredGathererCounts[4]; // 0xD78
    int resourceMapping[4];       // 0xD88
    int resourceDifferences[4];   // 0xD98
};

int __fastcall actualGathererCount(TribeTacticalAIModule* self, int, int index) {
    if (index < 0 || index > 3)
        return -1;
    return self->actualGathererCounts[self->resourceMapping[index]];
}
