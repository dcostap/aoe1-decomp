
#include "../include/t_tre_ob.h"

TRIBE_Tree_Object::TRIBE_Tree_Object(
    TRIBE_Master_Tree_Object* tobj, RGE_Player* obj_owner,
    float x, float y, float z, int do_setup)
    : RGE_Static_Object(tobj, obj_owner, x, y, z, 0) {
    if (do_setup != 0) {
        setup(tobj, obj_owner, x, y, z);
    }
}

TRIBE_Tree_Object::TRIBE_Tree_Object(
    int infile, RGE_Game_World* gworld, int do_setup)
    : RGE_Static_Object(infile, gworld, 0) {
    if (do_setup != 0) {
        setup(infile, gworld);
    }
}

void TRIBE_Tree_Object::set_object_state(unsigned char new_object_state) {
    RGE_Static_Object::set_object_state(new_object_state);
}
