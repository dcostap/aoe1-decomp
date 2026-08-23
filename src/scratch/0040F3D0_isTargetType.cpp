struct AIPlayPhaseCommand {
    char gap_0[0x44];
    unsigned char targetTypes[5];
};

int __fastcall isTargetType(AIPlayPhaseCommand* self, int, unsigned char type) {
    for (int i = 0; i < 5; i++) {
        if (self->targetTypes[i] == type)
            return 1;
    }
    return 0;
}
