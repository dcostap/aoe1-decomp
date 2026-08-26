#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

int TribeInformationAIModule::closestDropsiteResID(int index) const {
    if (index < 0 || index > 3) {
        return -1;
    }
    return this->closestDropsiteResourceID[index];
}
