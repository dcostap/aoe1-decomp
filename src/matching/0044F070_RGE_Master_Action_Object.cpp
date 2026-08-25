// first pass: call the moving-object base ctor with 0, then conditionally run the copy/helper setup
// /GX was needed to land the exact EH ctor/body basin for this constructor overload
#include "..\..\include\game_types.h"

RGE_Master_Action_Object::RGE_Master_Action_Object(RGE_Master_Action_Object* source, int do_setup)
    : RGE_Master_Moving_Object(source, 0) {
    if (do_setup != 0) {
        setup(source);
    }
}
