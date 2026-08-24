#include "../../include/taction_context.h"

TRIBE_Action::TRIBE_Action(int mode, RGE_Action_Object* object, int doSetup)
    : RGE_Action(mode, object, 0) {
    if (doSetup != 0) {
        setup(mode, object);
    }
}
