struct TribeTacticalAIModule {
    char gap_0[0xD88];
    int resourceTypes[4];
};

int __fastcall neededResourceAmount(TribeTacticalAIModule* self, int, int resourceType) {
    for (int i = 0; i < 4; i++) {
        if (self->resourceTypes[i] == resourceType)
            return 1;
    }
    return 0;
}
