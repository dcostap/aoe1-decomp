#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

void TribeInformationAIModule::setFullyExploredZone(int param_1, int param_2) {
    RGE_Static_Object* object = md->object(param_1);
    if (object != 0) {
        unsigned char zone = object->currentZone();
        fullyExploredZoneValue[zone] = (unsigned char)param_2;
    }
}
