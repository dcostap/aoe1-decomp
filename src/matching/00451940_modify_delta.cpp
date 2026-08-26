#include "../../include/m_mi_obj_context.h"

#ifndef M_MI_OBJ_SHARED_CONTEXT
class RGE_Master_Missile_Object {
public:
    void parent_modify_delta(float param_1, unsigned char param_2);
    void modify_delta(float param_1, unsigned char param_2);
    char pad[0x149];
    unsigned char field_149;
};
#endif
void RGE_Master_Missile_Object::modify_delta(float param_1, unsigned char param_2) {
    if (param_2 == 0x13) {
        this->field_149 = (unsigned char)(int)param_1;
    }
#ifdef M_MI_OBJ_SHARED_CONTEXT
    RGE_Master_Combat_Object::modify_delta(param_1, param_2);
#else
    this->parent_modify_delta(param_1, param_2);
#endif
}
