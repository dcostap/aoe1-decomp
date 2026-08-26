// VA: 004CA3E0 TRIBE_Combat_Object::setup(int, RGE_Game_World*)
// PDB source: t_c_obj.cpp:152-180
//
// Binary-supported ownership uses the canonical t_c_obj class declarations.
// The body retains the original parameter-home reuse and load order.
// Main-agent audit restored canonical player/world/combat destructor ownership.

#include "../../include/t_c_obj_context.h"

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);

int TRIBE_Combat_Object::setup(int param_1, RGE_Game_World* param_2)
{
    int handle = param_1;

    RGE_Combat_Object::setup(handle, param_2);
    this->type = 0x46;
    rge_read(handle, &this->own_master, 1);

    if (this->own_master != 0) {
        rge_read(handle, &param_2, 1);
        if ((char)param_2 == 'F') {
            this->master_obj = new TRIBE_Master_Combat_Object(
                handle, this->owner->world->sprites,
                this->owner->world->sounds, 1);
        } else if ((char)param_2 == 'P') {
            this->master_obj = new TRIBE_Master_Building_Object(
                handle, this->owner->world->sprites,
                this->owner->world->sounds, 1);
        }
    }

    rge_read(handle, &param_1, 4);
    if (param_1 == 1) {
        this->initUnitAI();
        if (this->unit_ai != 0) {
            this->unit_ai->load(handle);
        }
    }
    return 1;
}
