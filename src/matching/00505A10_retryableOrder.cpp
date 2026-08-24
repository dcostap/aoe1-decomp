#ifndef TAIUAIMD_COMPLETE_TU
class TribePriestUnitAIModule {
public:
    int retryableOrder(int);
};
#endif

int TribePriestUnitAIModule::retryableOrder(int value) {
    if (value == 0x2C0 || value == 0x2BF)
        return 1;
    return 0;
}
