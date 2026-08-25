#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_stop.h"
#endif

int RGE_Combat_Object::stopAction() {
    action_list->delete_list();
    new_sprite((RGE_Sprite*)state->value_18);
    return 1;
}
