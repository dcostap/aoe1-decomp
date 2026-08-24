// attempt 1: natural ctor body with the base ctor call, vtable store, and optional setup helper
// result: default flags were too small; /GX is justified for this ctor/EH basin
// attempt 2: keep the body minimal and exact, with the byte+4 tree flag only on the setup path

#include "..\..\include\tm_tre_o_context.h"

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2)
    : RGE_Master_Static_Object((RGE_Master_Static_Object*)param_1, 0) {
    *(void**)this = (void*)0x576790;
    if (param_2 != 0) {
        setup(param_1);
        this->field_04 = 0x5A;
    }
}
