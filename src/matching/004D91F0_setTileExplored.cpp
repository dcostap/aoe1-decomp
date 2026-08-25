#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

void TribeInformationAIModule::setTileExplored(int x, int y) {
    if (x >= 0 && y >= 0 && x < this->mapXSizeValue && y < this->mapYSizeValue)
        this->pathMap.setValue(x, y, 0);
}
