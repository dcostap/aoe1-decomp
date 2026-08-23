#include "../../include/information_dropsites_context.h"

void TribeInformationAIModule::setTileExplored(int x, int y) {
    if (x >= 0 && y >= 0 && x < this->mapXSizeValue && y < this->mapYSizeValue)
        this->pathMap.setValue(x, y, 0);
}
