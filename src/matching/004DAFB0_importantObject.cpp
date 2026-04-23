class TribeInformationAIModule {
public:
    int importantUnit(int param_1);
    int importantResource(int param_1);
    int importantMisc(int param_1);

    int importantObject(int param_1);
};

int TribeInformationAIModule::importantObject(int param_1) {
    if (importantUnit(param_1) == 0) {
        if (importantResource(param_1) == 0) {
            if (importantMisc(param_1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
