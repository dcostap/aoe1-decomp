// t_tre_ob.cpp:36-39, 131 bytes
// The complete module context is in t_tre_ob_context.h.
#include "..\..\include\t_tre_ob_context.h"

TRIBE_Tree_Object::TRIBE_Tree_Object(TRIBE_Master_Tree_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6)
    : RGE_Static_Object(param_1, param_2, param_3, param_4, param_5, 0) {
    if (param_6 != 0) {
        setup(param_1, param_2, param_3, param_4, param_5);
    }
}
