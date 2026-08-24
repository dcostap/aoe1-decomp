#include "../../include/taction_context.h"

TRIBE_Action::TRIBE_Action(RGE_Action_Object* object, int doSetup)
    : RGE_Action(object, 0) {
    if (doSetup != 0) {
        setup(object);
    }
}
