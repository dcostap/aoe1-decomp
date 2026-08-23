#include "../../include/information_dropsites_context.h"

void TribeInformationAIModule::setFullyExploredZone(int param_1, int param_2) {
    RGE_Static_Object* object = md->object(param_1);
    if (object != 0) {
        unsigned char zone = object->currentZone();
        fullyExploredZoneValue[zone] = (unsigned char)param_2;
    }
}
