// 004E6AD0 TribeAIPlayBook::convertUnitToIntType
// Source: taipbook.cpp lines 62-81
// public: virtual int __thiscall TribeAIPlayBook::convertUnitToIntType(RGE_Static_Object*) const
//
// Attempt log:
// Probe 1: natural if-else chain + virtual weaponRange() call, default flags
// SOURCE NOTE: The reviewed class surface replaces the old fake slot list.
// The reduced grouped source remains exact.

#include "../../include/taipbook_context.h"

int TribeAIPlayBook::convertUnitToIntType(RGE_Static_Object* obj) const
{
    short group = obj->master_obj->object_group;
    if (group == 0x12) return 4;
    if (group == 0x1C) return 3;
    if (group == 0x0D) return 5;
    if (group == 0x0C || group == 0x23) return 2;

    float result = obj->weaponRange();
    if (result > 1.0f) return 1;
    return 0;
}
