// t_tre_ob.cpp:44-47, 101 bytes
// The complete module context is in t_tre_ob_context.h.
#include "..\..\include\t_tre_ob_context.h"

TRIBE_Tree_Object::TRIBE_Tree_Object(int param_1, RGE_Game_World* world, int do_setup)
    : RGE_Static_Object(param_1, world, 0) {
    if (do_setup != 0) {
        setup(param_1, world);
    }
}
