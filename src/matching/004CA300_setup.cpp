// VA: 004CA300 TRIBE_Combat_Object::setup
// PDB source: t_c_obj.cpp:111-146
//
// Binary-supported ownership: RGE_Static_Object supplies master_obj (+0x08),
// owner (+0x0c), attribute_amount_held (+0x44), attribute_type_held (+0x4c),
// and type (+0x4e). RGE_Combat_Object supplies capture_flag, while
// TRIBE_Combat_Object owns own_master.

#include "../../include/t_c_obj_context.h"

extern float DAT_00574c7c;

int TRIBE_Combat_Object::setup(TRIBE_Master_Combat_Object* master_obj,
                               RGE_Player* player, float x, float y, float z)
{
    RGE_Combat_Object::setup(master_obj, player, x, y, z);

    if (this->owner->id == 0) {
        this->capture_flag = 1;
    }

    this->type = 0x46;
    this->initUnitAI();
    this->own_master = 0;

    if (this->master_obj->object_group == 4 ||
        this->master_obj->object_group == 0x15 ||
        this->master_obj->object_group == 2) {
        this->owner->attributes[0x25] -= DAT_00574c7c;
    } else if ((this->master_obj->object_group != 0x12 &&
                this->master_obj->master_type == 'F') ||
               this->master_obj->id == 0x4f ||
               this->master_obj->id == 0x45 ||
               this->master_obj->id == 0xc7) {
        this->owner->attributes[0x28] -= DAT_00574c7c;
    }

    if (this->master_obj->object_group == 0x12) {
        this->attribute_amount_held = 100.0f;
        this->attribute_type_held = 0x22;
    }

    return 1;
}
