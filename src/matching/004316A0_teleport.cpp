// BINARY NOTE: The shipped call is the inherited RGE_Moving_Object::teleport
// body at 0045D3D0.  A call through the local base_teleport helper keeps the
// bytes but changes the direct relocation target.
// Exact-finish walkback: base_teleport returned to a 2-byte mismatch and one
// wrong direct target.  The qualified inherited call is the reduced exact form.

#include "../com_obj_phase2_context.h"

float RGE_Combat_Object::teleport(float x, float y, float z) {
    VISIBLE_UNIT_REC** vur;
    VISIBLE_UNIT_REC* rec;
    float result;
    int old_x;
    int old_y;
    int new_x;
    int new_y;
    int i;

    old_x = (int)world_x;
    old_y = (int)world_y;
    result = RGE_Moving_Object::teleport(x, y, z);
    if (id >= 0) {
        new_x = (int)world_x;
        new_y = (int)world_y;
        if (new_x != old_x || new_y != old_y) {
            vur = VUR_Ptrs;
            for (i = 0; i < 9; ++i) {
                rec = *vur;
                if (rec != 0) {
                    rec->pos_x = (unsigned char)new_x;
                    rec->pos_y = (unsigned char)new_y;
                }
                ++vur;
            }
        }
    }
    return result;
}
