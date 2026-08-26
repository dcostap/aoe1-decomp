// VA: 004CCDF0 TRIBE_Action_Artifact::update
// tact_art.cpp lines 120-164

// Attempt log:
// 1-4: established the 199-byte layout and vtable slots, but the initial
//      source had broad switch/order, call, and FPU mismatches.
// 5: reordered cases to the PDB/source order (10, 6, 100, 1), used the real
//    DAT_00574f08 double, and recovered the jbe/cmp3/ja list-value guard.
// 6: added the binary-proven extra dereference in the state-100 argument.
// 7: a local speed plus duplicate timer stores in the two arms preserves the
//    original fcom/fstp order; exact match under the default VC5 flags.
// 8: restored and revalidated the exact source after a compound-timer probe.
// 9: named the proven owner/world/master-player fields; codegen stayed exact.
// 10-11: replaced dummy virtual labels with the generated ABI names/surfaces;
//        codegen and relocation identity remained exact.
// The duplicate stores are intentional: the executable proves compare-before-
// store ordering, and the ordinary single-store spelling emits fst/fcomp.
// Status: exact validated match.

#ifndef AOE1_TACT_ART_TU_CONTEXT
#include "../../include/tact_art_context.h"
#endif

extern double DAT_00574f08;

unsigned char TRIBE_Action_Artifact::update() {
    unsigned char val = action_list->update();
    if (val > 0 && val <= 3) {
        action_list->delete_list();
    }
    switch (state) {
    case 10: {
        RGE_Action_Object* obj = this->object;
        float speed = this->timer - obj->owner->world->world_time_delta_seconds;
        if (speed > DAT_00574f08) {
            this->timer = speed;
            return 0;
        }
        this->timer = speed;
        this->set_state(6);
        return 0;
    }

    case 6: {
        RGE_Player* owner = (RGE_Player*)check_ownership();
        if (owner != 0) {
            action_list->delete_list();
            object->change_ownership(owner);
            return 0;
        }
        this->set_state(10);
        return 0;
    }

    case 100:
        object->change_ownership(object->owner->world->master_players[0]);
        this->set_state(6);
        return 0;

    case 1:
        return 1;

    default:
        return 0;
    }
}
