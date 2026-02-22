#include "../include/TRIBE_Object_List.h"

#include "../include/TRIBE_Building_Object.h"
#include "../include/TRIBE_Combat_Object.h"

#include <new>

void TRIBE_Object_List::load(uchar param_1, int param_2, RGE_Game_World* param_3) {
    // Fully verified. Source of truth: tobj_lst.cpp.decomp @ 0x00511B00
    if (param_1 == 'F') {
        TRIBE_Combat_Object* object =
            (TRIBE_Combat_Object*)::operator new(sizeof(TRIBE_Combat_Object), std::nothrow);
        if (object != nullptr) {
            new (object) TRIBE_Combat_Object(param_2, param_3, 1);
        }
        return;
    }

    if (param_1 == 'P') {
        TRIBE_Building_Object* object =
            (TRIBE_Building_Object*)::operator new(sizeof(TRIBE_Building_Object), std::nothrow);
        if (object != nullptr) {
            new (object) TRIBE_Building_Object(param_2, param_3, 1);
        }
        return;
    }

    RGE_Object_List::load(param_1, param_2, param_3);
}
