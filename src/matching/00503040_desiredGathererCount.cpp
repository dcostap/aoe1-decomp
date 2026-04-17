struct TribeTacticalAIModule {
    char gap_0[0xD78];
    int desiredGathererCounts[4]; // 0xD78 - ends at 0xD88
    int resourceMapping[4];       // 0xD88
};

int __fastcall desiredGathererCount(TribeTacticalAIModule* self, int, int index) {
    if (index < 0 || index > 3)
        return -1;
    return self->desiredGathererCounts[self->resourceMapping[index]];
}
