struct AttackMemory {
    char data[24];
};

struct TribeInformationAIModule {
    char gap_0[0x1FC];
    int numberAttackMemories;
    AttackMemory attackMemories[40];
};

AttackMemory* __fastcall attackMemory(TribeInformationAIModule* self, int, int index) {
    if (index < 0)
        return 0;
    if (index >= self->numberAttackMemories)
        return 0;
    return &self->attackMemories[index];
}
