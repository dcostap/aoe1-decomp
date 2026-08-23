#include "../../include/information_dropsites_context.h"

int TribeInformationAIModule::fullyExploredZone(int param_1) {
    RGE_Static_Object* object = md->object(param_1);
    if (object != 0) {
        unsigned char zone = object->currentZone();
        if (fullyExploredZoneValue[zone] == 0) {
            return 1;
        }
    }
    return 0;
}
