
#include "../include/taipbook.h"
#include "../include/m_s_obj.h"
#include "../include/stat_obj.h"
#include <string.h>

// Compiler-emitted destructor body at 004E68F0.
TribeAIPlayBook::~TribeAIPlayBook() {
}

TribeAIPlayBook::TribeAIPlayBook() : AIPlayBook() {
}

int TribeAIPlayBook::convertTargetNameToIntType(char* t) const {
    return AIPlayBook::convertTargetNameToIntType(t);
}

int TribeAIPlayBook::convertTargetCharacteristicNameToIntType(char* t) const {
    return AIPlayBook::convertTargetCharacteristicNameToIntType(t);
}

int TribeAIPlayBook::convertUnitNameToIntType(char* t) const {
    if (strcmp(t, "Hand") == 0)
        return 0;
    if (strcmp(t, "Ranged") == 0)
        return 1;
    if (strcmp(t, "Priest") == 0)
        return 4;
    if (strcmp(t, "Siege") == 0)
        return 5;
    if (strcmp(t, "Cavalry") == 0)
        return 2;
    if (strcmp(t, "Legion") == 0)
        return 3;

    return AIPlayBook::convertUnitNameToIntType(t);
}

int TribeAIPlayBook::convertUnitToIntType(RGE_Static_Object* obj) const {
    short group = obj->master_obj->object_group;
    if (group == OBJECT_GROUP_PRIEST) return 4;
    if (group == 0x1C) return 3;
    if (group == 0x0D) return 5;
    if (group == 0x0C || group == 0x23) return 2;

    float result = obj->weaponRange();
    if (result > 1.0f) return 1;
    return 0;
}
