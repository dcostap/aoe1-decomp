class TribeInformationAIModule {
public:
    int importantResource(int param_1);
};

int TribeInformationAIModule::importantResource(int param_1) {
    if (param_1 == 0x1F || param_1 == 5 || param_1 == 0x21 || param_1 == 7 ||
        param_1 == 9 || param_1 == 8 || param_1 == 0x20 || param_1 == 0xF) {
        return 1;
    }
    return 0;
}
