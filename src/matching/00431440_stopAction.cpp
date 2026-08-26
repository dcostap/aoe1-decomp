#include "../com_obj_phase2_context.h"

int RGE_Combat_Object::stopAction() {
    action_list->delete_list();
    new_sprite((RGE_Sprite*)state->value_18);
    return 1;
}
