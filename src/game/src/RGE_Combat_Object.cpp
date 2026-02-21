#include "../include/RGE_Combat_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

#include <string.h>

// Default constructor
RGE_Combat_Object::RGE_Combat_Object()
    : RGE_Action_Object()
{
    for (int i = 0; i < 9; i++) {
        this->VUR_Ptrs[i] = nullptr;
    }
    this->Unified_Map_Value = 0;
    this->attack_timer = 0.0f;
    this->capture_flag = '\0';
}

// Fully verified. Source of truth: com_obj.cpp.decomp @ 0x0042F9E0
RGE_Combat_Object::RGE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Action_Object(param_1, param_2, 0)
{
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: com_obj.cpp.decomp @ 0x0042FBA0
int RGE_Combat_Object::setup(int param_1, RGE_Game_World* param_2) {
    // Zero VUR_Ptrs and Unified_Map_Value before base setup
    for (int i = 0; i < 9; i++) {
        this->VUR_Ptrs[i] = nullptr;
    }
    this->Unified_Map_Value = 0;

    RGE_Action_Object::setup(param_1, param_2);
    this->type = 0x32;

    rge_read(param_1, &this->attack_timer, 4);

    if (save_game_version >= 2.01f) {
        rge_read(param_1, &this->capture_flag, 1);
    }

    return 1;
}
