#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    if (this->field_10 == this->master_obj->field_168) {
        this->new_sprite((RGE_Sprite*)master_obj->field_168);
    }
    RGE_Action_Object::copy_obj(master_obj);
    if (this->master_obj->field_16C != 0) {
        this->connect();
    }
}
