#include "../../include/stat_obj_context.h"
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
#define RGE_STAT_OBJ_SHARED_CONTEXT 1
#endif

void RGE_Static_Object::rehook(void) {
    RGE_Static_Object* obj;

    this->teleport((float)this->world_x, (float)this->world_y, (float)this->world_z);
    obj = this->inside_obj;
    if (obj != 0) {
        this->inside_obj = 0;
        obj = this->get_object_pointer((long)obj);
        if (obj != 0) {
            this->enter_obj(obj);
        }
    }
}
