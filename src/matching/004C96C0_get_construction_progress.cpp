#include "../../include/t_b_obj_context.h"

short TRIBE_Building_Object::get_construction_progress() {
    short points;
    RGE_Static_Object* obj;

    if (built != 0) {
        return 100;
    }
    obj = *(RGE_Static_Object**)((char*)this + 8);
    points = *(short*)((char*)obj + 0x15A);
    if (points == 0) {
        return 100;
    }
    return (short)(build_pts / (float)points * 100.0f);
}
