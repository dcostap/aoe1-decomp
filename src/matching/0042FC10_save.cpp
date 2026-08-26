extern "C" void rge_write(int handle, void* buffer, int size);

#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::save(int handle) {
    RGE_Action_Object::save(handle);
    rge_write(handle, &attack_timer, 4);
    rge_write(handle, &capture_flag, 1);
}
