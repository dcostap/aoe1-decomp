// PDB source module: C:\\msdev\\work\\age1_x1\\t_tre_ob.cpp.
// Definitions follow the original source-line and address order.

#include "../include/t_tre_ob.h"

// BINARY NOTE: The tree master is owned by tm_tre_o.cpp. The canonical static
// object declarations expose the base receiver but not that derived class.
// These casts preserve the proven single-inheritance receiver without copying
// the tree-master or static-object layout into this module.
// t_tre_ob.cpp:36-39, 004CCA60.
TRIBE_Tree_Object::TRIBE_Tree_Object(
    TRIBE_Master_Tree_Object* param_1, RGE_Player* param_2,
    float param_3, float param_4, float param_5, int param_6)
    : RGE_Static_Object((RGE_Master_Static_Object*)param_1,
                        param_2, param_3, param_4, param_5, 0) {
    if (param_6 != 0) {
        setup((RGE_Master_Static_Object*)param_1,
              param_2, param_3, param_4, param_5);
    }
}

// t_tre_ob.cpp:44-47, 004CCB20.
TRIBE_Tree_Object::TRIBE_Tree_Object(
    int param_1, RGE_Game_World* world, int do_setup)
    : RGE_Static_Object(param_1, world, 0) {
    if (do_setup != 0) {
        setup(param_1, world);
    }
}

// t_tre_ob.cpp:51-62, 004CCB90.
void TRIBE_Tree_Object::set_object_state(unsigned char value) {
    RGE_Static_Object::set_object_state(value);
}
