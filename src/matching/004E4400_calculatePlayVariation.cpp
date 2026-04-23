class TribeInformationAIModule {
public:
    char gap_0000[0x564];
    int playHistory[0x3E80];
    int unitHistory;

    int calculatePlayVariation(int param_1);
};

extern "C" long __cdecl __ftol(void);
extern float const DAT_00575584;

int TribeInformationAIModule::calculatePlayVariation(int param_1) {
    (void)param_1;
    int totalPlays = 0;
    for (int i = 0; i < 0x3E80; ++i) {
        totalPlays += this->playHistory[i];
    }

    return 100 - (int)((float)this->unitHistory / (float)totalPlays * DAT_00575584);
}
