#ifndef TAITACMD_SHARED_CONTEXT
#ifndef TAITACMD_SHARED_CONTEXT
struct TribeTacticalAIModule {
    char gap_0[0xD78];
    int desiredGathererCounts[4]; // 0xD78 - ends at 0xD88
    int resourceMapping[4];       // 0xD88
};

#endif
int TribeTacticalAIModule::desiredGathererCount(int) {
    if (index < 0 || index > 3)
        return -1;
    return self->desiredGathererCounts[self->resourceMapping[index]];
}
#else
int TribeTacticalAIModule::desiredGathererCount(int) { return 0; }
#endif
