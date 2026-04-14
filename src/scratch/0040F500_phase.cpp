struct AIPlayPhase {
    char data[0x8C];
};

struct AIPlayBook {
    int vfptr;
    int numberPlays;
    char gap_8[0x88];
    AIPlayPhase phases[10];
};

AIPlayPhase* __fastcall phase(AIPlayBook* self, int, int index) {
    if (index < 0)
        return 0;
    if (index >= 10)
        return 0;
    return &self->phases[index];
}
