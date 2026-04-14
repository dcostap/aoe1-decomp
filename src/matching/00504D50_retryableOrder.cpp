class TribeCivilianUnitAIModule {
public:
    int retryableOrder(int);
};

int TribeCivilianUnitAIModule::retryableOrder(int value) {
    if (value == 0x2C1 || value == 0x2C5 || value == 0x2C9)
        return 1;
    return 0;
}
