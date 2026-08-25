#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

extern "C" long __cdecl __ftol(void);

int TribeInformationAIModule::calculatePlayVariation(int param_1) {
    (void)param_1;
    int totalPlays = 0;
    for (int i = 0; i < 0x3E80; ++i) {
        totalPlays += this->playHistory[i];
    }

    return 100 - (int)((float)this->unitHistory[0] / (float)totalPlays * DAT_00575584);
}
