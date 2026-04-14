struct AIPlayPhaseCommand {
    char gap_0[0x49];
    unsigned char targetCharacteristics[5];
};

int __fastcall addTargetCharacteristic(AIPlayPhaseCommand* self, int, unsigned char characteristic) {
    for (int i = 0; i < 5; i++) {
        if (self->targetCharacteristics[i] == 0 || self->targetCharacteristics[i] == 5) {
            self->targetCharacteristics[i] = characteristic;
            return 1;
        }
    }
    return 0;
}
