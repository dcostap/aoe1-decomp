#include "../com_obj_phase2_context.h"

int RGE_Combat_Object::pause() {
    new_sprite((RGE_Sprite*)state->value_18);
    return 1;
}
