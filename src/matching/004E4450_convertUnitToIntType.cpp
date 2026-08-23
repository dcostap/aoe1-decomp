#include "../../include/information_dropsites_context.h"

int TribeInformationAIModule::convertUnitToIntType(RGE_Static_Object* obj) const {
    int og = obj->master_obj->object_group;
    int id = obj->master_obj->id;

    if (og == 0x12) return 5;
    if (og == 0x1C) return 3;
    if (og == 0x0D) return 4;
    if (og == 0x0C) return 2;
    if (og == 0x23) return 7;

    if (id == 0x49) return 0;
    if (id == 0x4B) return 1;

    if (id == 4 || id == 5 || id == 0x27) return 6;

    if (id == 0x29) return 10;

    if (id == 0x2E || id == 0x19) return 9;

    // Fallback: returns 8 if object_group == 0x16, otherwise -1
    return (og == 0x16) ? 8 : -1;
}
