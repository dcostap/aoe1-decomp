// Grouped taiinfmd build differs by one SIB operand-order byte at +0x2E.
// Keep this Phase 4 owner unregistered until the grouped body matches.
#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

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
