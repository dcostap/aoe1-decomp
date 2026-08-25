// first pass: direct new-expression for the EH-framed factory helper
// if this is sticky, the only real follow-up is whether /GX is required to keep the ctor/new basin
#include "..\..\include\game_types.h"

RGE_Master_Static_Object* RGE_Master_Action_Object::make_new_master(void) {
    return new RGE_Master_Action_Object(this, 1);
}
