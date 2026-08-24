#ifndef TAIUAIMD_COMPLETE_TU
class TribeFishingShipUnitAIModule {
public:
    virtual int importantWhenDead(int value);
};
#endif

int TribeFishingShipUnitAIModule::importantWhenDead(int value) {
    if (value != 0x1F && value != 5) {
        return 0;
    }
    return 1;
}
