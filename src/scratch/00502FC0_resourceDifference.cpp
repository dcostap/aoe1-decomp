#ifndef TAITACMD_SHARED_CONTEXT
#ifndef TAITACMD_SHARED_CONTEXT
struct TribeTacticalAIModule {
    char gap_0[0xD88];
    int resourceMapping[4];    // 0xD88
    int resourceDifferences[4]; // 0xD98
};

#endif
int TribeTacticalAIModule::resourceDifference(int) {
    if (index < 0 || index > 3)
        return -1;
    return self->resourceDifferences[self->resourceMapping[index]];
}
#else
int TribeTacticalAIModule::resourceDifference(int) { return 0; }
#endif
