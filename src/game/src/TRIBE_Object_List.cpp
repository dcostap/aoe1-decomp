#include "../include/TRIBE_Object_List.h"

#include "../include/RGE_Combat_Object.h"

#include <new>

class TRIBE_Combat_Object_Load_Compat : public RGE_Combat_Object {
public:
    TRIBE_Combat_Object_Load_Compat(int param_1, RGE_Game_World* param_2, int param_3)
        : RGE_Combat_Object(param_1, param_2, param_3) {
    }

    unsigned char extra_tribe_storage[4];
};
static_assert(sizeof(TRIBE_Combat_Object_Load_Compat) == 0x1C8, "Size mismatch");

class TRIBE_Building_Object_Load_Compat : public TRIBE_Combat_Object_Load_Compat {
public:
    TRIBE_Building_Object_Load_Compat(int param_1, RGE_Game_World* param_2, int param_3)
        : TRIBE_Combat_Object_Load_Compat(param_1, param_2, param_3) {
    }

    unsigned char extra_building_storage[0x3C];
};
static_assert(sizeof(TRIBE_Building_Object_Load_Compat) == 0x204, "Size mismatch");

void TRIBE_Object_List::load(uchar param_1, int param_2, RGE_Game_World* param_3) {
    // Source of truth: tobj_lst.cpp.decomp @ 0x00511B00.
    // Compatibility note: the exact TRIBE object load constructors are still not transliterated,
    // so this keeps the branch structure and allocation sizes while using available combat-object setup.
    if (param_1 == 'F') {
        TRIBE_Combat_Object_Load_Compat* object =
            (TRIBE_Combat_Object_Load_Compat*)::operator new(sizeof(TRIBE_Combat_Object_Load_Compat), std::nothrow);
        if (object != nullptr) {
            new (object) TRIBE_Combat_Object_Load_Compat(param_2, param_3, 1);
        }
        return;
    }

    if (param_1 == 'P') {
        TRIBE_Building_Object_Load_Compat* object =
            (TRIBE_Building_Object_Load_Compat*)::operator new(sizeof(TRIBE_Building_Object_Load_Compat), std::nothrow);
        if (object != nullptr) {
            new (object) TRIBE_Building_Object_Load_Compat(param_2, param_3, 1);
        }
        return;
    }

    RGE_Object_List::load(param_1, param_2, param_3);
}
