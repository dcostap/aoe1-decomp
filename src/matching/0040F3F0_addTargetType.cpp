struct AIPlayPhaseCommand {
    char gap_0[0x44];
    unsigned char targetTypes[5];
};

int __fastcall addTargetType(AIPlayPhaseCommand* self, int, unsigned char type) {
    for (int i = 0; i < 5; i++) {
        if (self->targetTypes[i] == 0 || self->targetTypes[i] == 5) {
            self->targetTypes[i] = type;
            return 1;
        }
    }
    return 0;
}
