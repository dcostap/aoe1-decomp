#include "../include/TRIBE_Combat_Object.h"

#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Master_Combat_Object.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

#include <new>

TRIBE_Combat_Object::TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Combat_Object(param_1, param_2, 0) {
    // Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA1A0
    this->type = 0x46;
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

int TRIBE_Combat_Object::setup(int param_1, RGE_Game_World* param_2) {
    // Source of truth: t_c_obj.cpp.decomp @ 0x004CA3E0
    RGE_Combat_Object::setup(param_1, param_2);
    this->type = 0x46;

    rge_read(param_1, &this->own_master, 1);
    if (this->own_master != 0) {
        char master_type = 0;
        rge_read(param_1, &master_type, 1);

        if (master_type == 'F') {
            TRIBE_Master_Combat_Object* master =
                (TRIBE_Master_Combat_Object*)::operator new(sizeof(TRIBE_Master_Combat_Object), std::nothrow);
            if (master != nullptr) {
                this->master_obj =
                    new (master) TRIBE_Master_Combat_Object(param_1, param_2->sprites, param_2->sounds, 1);
            } else {
                this->master_obj = nullptr;
            }
        } else if (master_type == 'P') {
            TRIBE_Master_Building_Object* master =
                (TRIBE_Master_Building_Object*)::operator new(sizeof(TRIBE_Master_Building_Object), std::nothrow);
            if (master != nullptr) {
                this->master_obj =
                    new (master) TRIBE_Master_Building_Object(param_1, param_2->sprites, param_2->sounds, 1);
            } else {
                this->master_obj = nullptr;
            }
        }
    }

    int has_actions = 0;
    rge_read(param_1, &has_actions, 4);
    if (has_actions == 1) {
        this->actions = RGE_Action_Object::create_action_list();
        if (this->actions != nullptr) {
            this->actions->load(param_1);
        }
    }

    return 1;
}
