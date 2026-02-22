#include "../include/TribeAIPlayBook.h"

#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Static_Object.h"

#include <string.h>

// Fully verified. Source of truth: taipbook.cpp.decomp @ 0x004E68B0
TribeAIPlayBook::TribeAIPlayBook() : AIPlayBook() {}

// Fully verified. Source of truth: bucket_04E6.decomp @ 0x004E68F0
TribeAIPlayBook::~TribeAIPlayBook() {}

// Fully verified. Source of truth: taipbook.cpp.decomp @ 0x004E6900
int TribeAIPlayBook::convertTargetNameToIntType(char* param_1) {
    return AIPlayBook::convertTargetNameToIntType(param_1);
}

// Fully verified. Source of truth: taipbook.cpp.decomp @ 0x004E6910
int TribeAIPlayBook::convertTargetCharacteristicNameToIntType(char* param_1) {
    return AIPlayBook::convertTargetCharacteristicNameToIntType(param_1);
}

// Fully verified. Source of truth: taipbook.cpp.decomp @ 0x004E6920
int TribeAIPlayBook::convertUnitNameToIntType(char* param_1) {
    if (strcmp(param_1, "Hand") == 0) {
        return 0;
    }
    if (strcmp(param_1, "Ranged") == 0) {
        return 1;
    }
    if (strcmp(param_1, "Priest") == 0) {
        return 4;
    }
    if (strcmp(param_1, "Siege") == 0) {
        return 5;
    }
    if (strcmp(param_1, "Cavalry") == 0) {
        return 2;
    }
    if (strcmp(param_1, "Legion") == 0) {
        return 3;
    }
    return AIPlayBook::convertUnitNameToIntType(param_1);
}

// Fully verified. Source of truth: taipbook.cpp.decomp @ 0x004E6AD0
int TribeAIPlayBook::convertUnitToIntType(RGE_Static_Object* param_1) {
    short object_group = param_1->master_obj->object_group;
    if (object_group == 0x12) {
        return 4;
    }
    if (object_group == 0x1C) {
        return 3;
    }
    if (object_group == 0x0D) {
        return 5;
    }
    if (object_group != 0x0C && object_group != 0x23) {
        if (param_1->weaponRange() > 1.0f) {
            return 1;
        }
        return 0;
    }
    return 2;
}
