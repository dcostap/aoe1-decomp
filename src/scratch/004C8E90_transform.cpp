#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::transform(TRIBE_Master_Building_Object* master) {
    RGE_Master_Static_Object* master_obj;

    ((TRIBE_Combat_Object*)this)->transform((RGE_Master_Static_Object*)master);
    this->built = 0;
    master_obj = this->master_obj;
    if (master_obj->building_facet > 0) {
        this->new_sprite((RGE_Sprite*)master->construction_sprite);
    }
    this->build_pts = 0.0f;
}
