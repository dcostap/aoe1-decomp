#include "../com_obj_phase2_context.h"

unsigned char RGE_Combat_Object::can_attack() {
    if (attack_timer > 0.0f) {
        return 0;
    }
    return 1;
}
