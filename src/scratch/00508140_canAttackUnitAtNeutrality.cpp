#ifndef TAIUAIMD_COMPLETE_TU
class TribeTowerUnitAIModule {
public:
    int canAttackUnitAtNeutrality(int);
};
#endif

int TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int value) {
    if (value == 0x3 || value == 0x1B || value == 0x4 || value == 0x15 || value == 0x2)
        return 0;
    return 1;
}
