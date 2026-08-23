#include "../../include/information_dropsites_context.h"

int TribeInformationAIModule::closestDropsiteResID(int index) {
    if (index < 0 || index > 3) {
        return -1;
    }
    return this->closestDropsiteResourceID[index];
}
