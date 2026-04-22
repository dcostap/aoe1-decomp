class TribeInformationAIModule {
public:
    int importantMisc(int value);
};

int TribeInformationAIModule::importantMisc(int value) {
    if (value != 1 && value != 0x1E) {
        return 0;
    }
    return 1;
}
