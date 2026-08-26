#include "../com_obj_phase2_context.h"

float RGE_Combat_Object::damageCapability() {
    float total;
    short* value;
    int count;

    total = 0.0f;
    count = master_obj->weapon_num;
    if (count > 0) {
        value = &master_obj->weapon[0].value;
        do {
            if ((float)(int)*value > 0.0f) {
                total = total + (float)(int)*value;
            }
            value = value + 2;
            count = count - 1;
        } while (count != 0);
    }
    return total;
}
