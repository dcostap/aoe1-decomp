// VA: 004CE740 TRIBE_Action_Discovery_Artifact::update
// PDB source: tact_dar.cpp, lines 96-121
// ACCEPTED_DRIFT: the rebuilt scheduler orders the timer store and x87 compare
// differently.  The function size and behavior remain stable.

#ifndef TACT_DAR_SHARED_CONTEXT
#include "../../include/tact_dar_context.h"
#endif

uchar TRIBE_Action_Discovery_Artifact::update() {
    switch (this->state) {
    case 1:
        return 1;
    case 6:
        check_objects();
        this->set_state(10);
        break;
    case 10:
        this->timer -= ((DiscoveryMaster*)this->obj)->info->size_info->tile_width;
        if (this->timer <= DAT_00575070) {
            this->set_state(6);
        }
        break;
    }
    return 0;
}
