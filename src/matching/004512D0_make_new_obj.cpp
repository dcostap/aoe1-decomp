#include "../../include/m_dg_obj_context.h"

RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(
    RGE_Player* param_1, float param_2, float param_3, float param_4,
    RGE_Static_Object* param_5) {
    if (this->recyclable != 0) {
        RGE_Doppleganger_Object* recycled =
            (RGE_Doppleganger_Object*)param_1->world->recycle_object_in_to_game(
                this->master_type);
        if (recycled != 0) {
            recycled->recycle_in_to_game(this, param_1, param_2, param_3,
                                         param_4, param_5);
            return recycled;
        }
    }
    return new RGE_Doppleganger_Object(this, param_1, param_2, param_3,
                                       param_4, 1, param_5);
}
