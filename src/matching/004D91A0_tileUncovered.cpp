#include "../../include/information_dropsites_context.h"

int TribeInformationAIModule::tileUncovered(int x, int y) {
    int rv;

    if (x < 0 || y < 0 || x >= this->mapXSizeValue || y >= this->mapYSizeValue) {
        goto not_found;
    }
    if (this->pathMap.lookupValue(x, y) != 0xFF) {
        rv = 1;
        return rv;
    }
not_found:
    return 0;
}
