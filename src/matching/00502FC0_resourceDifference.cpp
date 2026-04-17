struct TribeTacticalAIModule {
    char gap_0[0xD88];
    int resourceMapping[4];    // 0xD88
    int resourceDifferences[4]; // 0xD98
};

int __fastcall resourceDifference(TribeTacticalAIModule* self, int, int index) {
    if (index < 0 || index > 3)
        return -1;
    return self->resourceDifferences[self->resourceMapping[index]];
}
