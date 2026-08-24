// VA: 004C8CB0 TRIBE_Building_Object::change_ownership
// t_b_obj.cpp lines 494-546
// Attempt log:
// 1: natural raw-offset source: too short 384 B; base modeled non-polymorphic causing +4 this-adjust and virtual slots shifted.
// 2: move virtual surface to TRIBE_Combat_Object base and fix +1DA field layout: virtual offsets fixed but still 384 B/no local slot.
// 3: volatile sound_off loop variables force stack slot and 416 B, but VC5 chose EBX=4.
// 4: introduce `two` local for state/step: no improvement, EBX still 4.
// 5: move play_sound surface to RGE_Player; size matched but remaining broad drift; before/after owner slots shifted and loop init order off.
// 6: add one combat vtable pad and declare loop index first: exact to loop addressing; first mismatch 0x25 from [eax+ebp] vs original [ebp+eax].
// 7: integer address expressions did not alter base/index order.
// 8: expanded active_counts decrement matched original length and lowered diff to 4.86%; remaining first drift is equivalent base/index encoding in sound loops.
// 9: cast loop offsets to char* before adding info: no change.
// 10: flags /O2 no-/Oy, /Ox unchanged; /O1 too short.
// Accepted-drift suggestion: final mismatch is 21/432 positional, 20/432 edit. Remaining drift is localized equivalent addressing/register allocation: commuted base+index encodings in the two sound loops, a few ecx/edx/eax choices in the queue-count and master-object blocks, and paired branch displacement shifts. Calls, vtable slots, field offsets, predicates, stores, stack cleanup, and side effects match.

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::change_ownership(RGE_Player* player)
{
    register int two = 2;
    if (this->object_state == two) {
        int i = 0;
        volatile int sound_off = 0x6a;
        int sound_step = two;
        int amount_off = 0x70;
        do {
            int info = (int)this->obj_info;
            if (*(unsigned char*)((char*)i + info + 0x88) >= 4) {
                short id = *(short*)((char*)sound_off + info);
                if (id >= 0) {
                    this->owner->play_sound(id, -*(float*)((char*)amount_off + info), 0);
                }
            }
            amount_off += 4;
            ++i;
            sound_off += sound_step;
        } while (amount_off < 0x7c);
    }

    if (this->object_state == 0) {
        this->unexplore_terrain(this->owner, 1, -1);
    }

    if (this->field_1CE > 0) {
        if (this->need_attr == 4) {
            this->need_attr = -1;
            RGE_Player* old_owner = this->owner;
            RGE_Base_Game* game = rge_base_game;
            int id = old_owner->id;
            int* count_ptr = &game->active_counts[id];
            int count_val = *count_ptr;
            count_val--;
            *count_ptr = count_val;
        }
        this->field_1CE = 1;
        *(short*)((char*)this->production_queue + 2) = 1;
    }

    this->action_list->delete_list();
    TRIBE_Combat_Object::change_ownership(player);

    if (this->object_state == 0) {
        this->explore_terrain(this->owner, 1, -1);
    }

    if (this->object_state == two) {
        short master_id = *(short*)((char*)this->obj_info + 0x172);
        if (master_id > -1) {
            RGE_Player* owner = this->owner;
            RGE_Master_Object* master = (RGE_Master_Object*)owner->master_objects[master_id];
            master->create_object(owner, this->world_x, this->world_y, this->world_z);
        }
        short tech_id = *(short*)((char*)this->obj_info + 0x178);
        if (tech_id > -1) {
            ((TRIBE_Player_Tech*)this->owner->tech)->do_tech(tech_id);
        }
        if (this->object_state == two) {
            int i = 0;
            volatile int sound_off = 0x6a;
            int sound_step = two;
            int amount_off = 0x70;
            do {
                int info = (int)this->obj_info;
                if (*(unsigned char*)((char*)i + info + 0x88) >= 4) {
                    short id = *(short*)((char*)sound_off + info);
                    if (id >= 0) {
                        this->owner->play_sound(id, *(float*)((char*)amount_off + info), 0);
                    }
                }
                amount_off += 4;
                ++i;
                sound_off += sound_step;
            } while (amount_off < 0x7c);
        }
    }
}
