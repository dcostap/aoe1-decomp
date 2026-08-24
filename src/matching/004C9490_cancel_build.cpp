// VA: 004C9490 TRIBE_Building_Object::cancel_build
// PDB source: t_b_obj.cpp
// Baseline: named building/master ownership with the natural percent refund
// calculation and three-element Attribute_Cost scan.
// Attempt log:
// - Baseline natural inventory-element pointer alias matched frame/calls but
//   chose ESI for this, added a loop LEA, and emitted a double-to-float clamp.
// - Direct typed build_inventory[i] accesses plus a float 1.0f clamp matched
//   all 206 bytes; the array element stride produced the original ESI cursor.
// - Moved proven master/owner/hp/selected/state fields into the local
//   RGE_Static_Object base; code remained exact and ownership is canonical.

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::cancel_build()
{
    if ((this->selected & 1) != 0) {
        this->owner->unselect_one_object(this);
    }

    float percent;
    if (this->object_state >= 2 || this->hp <= DAT_005749f4) {
        percent = 0.0f;
    } else {
        percent = ((float)(int)this->master_obj->build_pts_required - this->build_pts) /
                  (float)(int)this->master_obj->build_pts_required * DAT_005749f8;
    }

    if (percent > DAT_00574a00) {
        percent = 1.0f;
    }

    for (int i = 0; i < 3; i++) {
        if (this->master_obj->build_inventory[i].type >= 0 &&
            this->master_obj->build_inventory[i].flag != 0) {
            int amount = this->master_obj->build_inventory[i].amount;
            this->owner->add_attribute_num(this->master_obj->build_inventory[i].type,
                                           (float)amount * percent, 0);
        }
    }

    this->hp = 0.0f;
}
