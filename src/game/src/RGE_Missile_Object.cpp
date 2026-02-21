#include "../include/RGE_Missile_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

// Default constructor
RGE_Missile_Object::RGE_Missile_Object()
    : RGE_Combat_Object()
{
    this->max_range = 0.0f;
}

// Fully verified. Source of truth: misl_obj.cpp.decomp @ 0x0045A800
RGE_Missile_Object::RGE_Missile_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Combat_Object(param_1, param_2, 0)
{
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
    this->type = 0x3C;
}

// Fully verified. Source of truth: misl_obj.cpp.decomp @ 0x0045A8A0, misl_obj.cpp.asm @ 0x0045A8A0
int RGE_Missile_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Combat_Object::setup(param_1, param_2);
    this->type = 0x3C;

    if (save_game_version > 7.09f) {
        rge_read(param_1, &this->max_range, 4);
        return 1;
    }

    // Older save versions: get max_range from master_obj->weapon_range (offset 0x114)
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    if (master != nullptr) {
        this->max_range = master->weapon_range;
    }

    return 1;
}
