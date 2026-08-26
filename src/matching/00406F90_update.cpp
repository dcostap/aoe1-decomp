// RGE_Action_Transport::update
// VA: 00406F90
// PDB: act_tran.cpp:139-300
//
// Attempt log:
// - Reconstructed the action-list, static-object, player/world/map, and
//   transport virtual/member surfaces from exact act_tran.cpp/action donors.
// - Natural switch and typed call surfaces reached exact size/frame/CFG/call
//   parity; correcting action field ownership and keeping zero-count cleanup
//   outside the owner notification reduced the diagnostic diff to 28 bytes.
// - The natural target-x `-1.0f` sentinel preserves the target dword compare
//   and map/x87 order. Preloading the drop pointer or swapping fallback
//   declarations was rolled back: each added 63 bytes and two virtual calls.
// - Tried the proven drop-result/object-local order with corrected long notify
//   trailing parameters; the direct form was unchanged, while the stored-result
//   form added 63 bytes and two calls. Restored the clean direct-call form.
// - Spelled sub-action success as `result > 0`; this recovered the original
//   unsigned-byte branch and reduced the live mismatch to the drop block.
// - Made a zero drop result notify 0x207 and break before the 0x206 success
//   check. VC5 then hoisted the object reload and tail-merged the notify block.
//   Removing a redundant scope kept the exact bytes in ordinary source form.
// - The source now matches all function bytes. The standalone extraction still
//   reports local switch-table relocations, but they do not affect exact bytes.

#ifndef ACT_TRAN_SHARED_CONTEXT
#include "../../include/act_tran_context.h"
#endif

unsigned char RGE_Action_Transport::update(void)
{
    switch (this->state) {
    case 4: {
        unsigned char result = this->sub_actions->update();
        if (result > 0 && result <= 5) {
            this->set_state(2);
            return 0;
        }
        return 0;
    }

    case 0x0B: {
        unsigned char result = this->sub_actions->update();
        if (result > 0 && result <= 5) {
            this->set_state(6);
            return 0;
        }
        return 0;
    }

    case 6: {
        int zone = this->targetZone();
        if (zone != -1 && this->obj->withinRangeOfZone((unsigned char)zone, 2.0f) == 0) {
            RGE_Action_Object* object = this->obj;
            RGE_Player* owner = object->owner;
            int id = object->id;
            owner->notify(id, id, 0x207, 0x266, 0, 0);
            break;
        }

        if (this->obj->objects->number_of_objects > 0) {
            if (this->next_to_drop_off_terrain() != 0) {
                zone = this->targetZone();
                if (this->obj->drop_held_objects(zone) == 0) {
                    this->obj->owner->notify(
                        this->obj->id, this->obj->id, 0x207, 0x266, 0, 0
                    );
                    break;
                }
                if (this->obj->objects->number_of_objects > 0) {
                    this->obj->owner->notify(
                        this->obj->id, this->obj->id, 0x206, 0x266, 0, 0
                    );
                }
                break;
            } else {
                RGE_Action_Object* object = this->obj;
                RGE_Player* owner = object->owner;
                RGE_Map* map = owner->world->map;
                if (this->target_x != -1.0f) {
                    if (map->get_terrain((short)this->target_x,
                                         (short)this->target_y) == 1 ||
                        map->get_terrain((short)this->target_x,
                                         (short)this->target_y) == 0x16) {
                        break;
                    }
                }
            }
            RGE_Player* owner = this->obj->owner;
            int id = this->obj->id;
            owner->notify(id, id, 0x207, 0x266, 0, 0);
        }
        break;
    }

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x266, 0, 0);
        this->set_state(2);
        return 3;

    default:
        return 0;
    }

    this->set_state(2);
    return 0;
}
