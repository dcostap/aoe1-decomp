// attempt log:
// first pass: straight new-expression wrapper with the EH/new prolog family in mind
// second pass: add a per-function /GX rsp because this helper is the same constructor/new family as create_sprite_list
// rsp used: config/flags/004CA510_create_action_list.rsp = /nologo /c /O2 /Oy /GX
// target shape: return new TRIBE_Action_List(this);

#include "../../include/t_c_obj_context.h"

RGE_Action_List* TRIBE_Combat_Object::create_action_list(void) {
    return new TRIBE_Action_List(this);
}
