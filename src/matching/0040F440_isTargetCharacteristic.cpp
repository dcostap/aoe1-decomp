// AIPlayPhaseCommand::isTargetCharacteristic
// Searches 5 bytes at offset +0x49 for matching value
// ret 4 = 1 param

struct AIPlayPhaseCommand {
    char gap_0[0x49];
    unsigned char targetCharacteristics[5];
};

int __fastcall isTargetCharacteristic(AIPlayPhaseCommand* self, int, unsigned char characteristic) {
    for (int i = 0; i < 5; i++) {
        if (self->targetCharacteristics[i] == characteristic)
            return 1;
    }
    return 0;
}
