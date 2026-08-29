
#include "../include/t_tre_ob.h"

TRIBE_Tree_Object::TRIBE_Tree_Object(
    TRIBE_Master_Tree_Object* param_1, RGE_Player* param_2,
    float param_3, float param_4, float param_5, int param_6)
    : RGE_Static_Object(param_1, param_2, param_3, param_4, param_5, 0) {
    if (param_6 != 0) {
        setup(param_1, param_2, param_3, param_4, param_5);
    }
}

TRIBE_Tree_Object::TRIBE_Tree_Object(
    int param_1, RGE_Game_World* world, int do_setup)
    : RGE_Static_Object(param_1, world, 0) {
    if (do_setup != 0) {
        setup(param_1, world);
    }
}

void TRIBE_Tree_Object::set_object_state(unsigned char value) {
    RGE_Static_Object::set_object_state(value);
}
