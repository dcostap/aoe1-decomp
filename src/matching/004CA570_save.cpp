// VA: 004CA570 TRIBE_Combat_Object::save
// Canonical ownership is the t_c_obj class surface. The two optional object
// records use their real inherited save member instead of local ABI classes.

#include "../../include/t_c_obj_context.h"

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

void TRIBE_Combat_Object::save(int fd)
{
    int flag;

    RGE_Combat_Object::save(fd);
    rge_write(fd, &own_master, 1);

    if (own_master) {
        this->master_obj->save(fd);
    }

    RGE_Static_Object* child =
        *(RGE_Static_Object**)((char*)this + 0x74);
    if (child != 0) {
        flag = 1;
        rge_write(fd, &flag, 4);
        child->save(fd);
    } else {
        flag = 0;
        rge_write(fd, &flag, 4);
    }
}
