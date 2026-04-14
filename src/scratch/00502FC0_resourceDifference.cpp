struct TribeTacticalAIModule {
    char gap_0[0xD98];
    int resourceDifferences[4];
};

int __fastcall resourceDifference(TribeTacticalAIModule* self, int, int index) {
    if (index < 0 || index >= 4)
        return -1;
    return self->resourceDifferences[index];
}
