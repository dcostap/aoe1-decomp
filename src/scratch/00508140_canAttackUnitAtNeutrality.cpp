class TribeRangedUnitAIModule {
public:
    int canAttackUnitAtNeutrality(int);
};

int TribeRangedUnitAIModule::canAttackUnitAtNeutrality(int value) {
    if (value == 0x3 || value == 0x1B || value == 0x4 || value == 0x15 || value == 0x2)
        return 0;
    return 1;
}
