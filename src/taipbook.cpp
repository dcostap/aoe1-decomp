// taipbook.cpp
// The vector-deleting destructor at 004E68D0 is compiler generated.

#include "../include/taipbook.h"
#include "../include/m_s_obj.h"
#include "../include/stat_obj.h"
#include <string.h>

// Compiler-emitted destructor body at 004E68F0.
TribeAIPlayBook::~TribeAIPlayBook() {
}

TribeAIPlayBook::TribeAIPlayBook() : AIPlayBook() {
}

int TribeAIPlayBook::convertTargetNameToIntType(char* name) const {
    return AIPlayBook::convertTargetNameToIntType(name);
}

int TribeAIPlayBook::convertTargetCharacteristicNameToIntType(char* name) const {
    return AIPlayBook::convertTargetCharacteristicNameToIntType(name);
}

int TribeAIPlayBook::convertUnitNameToIntType(char* name) const
{
    if (strcmp(name, "Hand") == 0)
        return 0;
    if (strcmp(name, "Ranged") == 0)
        return 1;
    if (strcmp(name, "Priest") == 0)
        return 4;
    if (strcmp(name, "Siege") == 0)
        return 5;
    if (strcmp(name, "Cavalry") == 0)
        return 2;
    if (strcmp(name, "Legion") == 0)
        return 3;

    return AIPlayBook::convertUnitNameToIntType(name);
}

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
