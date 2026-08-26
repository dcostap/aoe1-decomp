class RGE_Player;
class RGE_Static_Object;

#include "../../include/stat_obj_context.h"
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
#define RGE_STAT_OBJ_SHARED_CONTEXT 1
#endif

RGE_Static_Object* RGE_Static_Object::spawn_death_obj(void) {
    short id = this->master_obj->death_spawn_obj_id;
    if (id >= 0) {
        RGE_Master_Static_Object* master = this->owner->master_objects[id];
        if (master != 0) {
            return master->make_new_obj(this->owner, this->world_x, this->world_y, this->world_z);
        }
    }
    return 0;
}
