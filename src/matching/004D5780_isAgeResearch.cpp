#ifndef TAIBLDMD_SHARED_CONTEXT
class TribeBuildAIModule {
public:
    int isAgeResearch(int);
};
#endif

int TribeBuildAIModule::isAgeResearch(int value) {
    if (value == 0x65 || value == 0x66 || value == 0x67)
        return 1;
    return 0;
}
