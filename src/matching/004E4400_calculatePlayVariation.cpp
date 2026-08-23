#include "../../include/information_dropsites_context.h"

extern "C" long __cdecl __ftol(void);
extern float const DAT_00575584;

int TribeInformationAIModule::calculatePlayVariation(int param_1) {
    (void)param_1;
    int totalPlays = 0;
    for (int i = 0; i < 0x3E80; ++i) {
        totalPlays += this->playHistory[i];
    }

    return 100 - (int)((float)this->unitHistory[0] / (float)totalPlays * DAT_00575584);
}
