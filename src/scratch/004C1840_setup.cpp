// 004C1840 RGE_Static_Object::setup(int, RGE_Game_World*)
// Attempt log:
// - Baseline used local raw array fields and incorrect renderer/object helper
//   surfaces; it had the right save-read prefix but wrong frame and final calls.
// - Reconstructing the canonical RGE_Static_Object/ManagedArray layout and
//   stat_obj.cpp save-load source is the current structural pass.
// - Canonical sprite-list load, world callback, object-list add, and vtable
//   slots aligned all 45 calls; period float literals restored the original
//   one-operand fcomp form and the bounded indexed loops improved CFG/size.
// - Remaining drift is the VC5 prologue/register/local-home basin and a few
//   loop block spans; direct parameter-home handle reuse was tested and made
//   the function 131 bytes larger, so it was rolled back.
// - Natural first-read handle split (incoming file for the first read, then a
//   local handle for later reads) moved the result farther to 1161 bytes, so
//   it was rolled back.
// - Corrected the proven world players offset to +0x40 and modeled the two
//   serialized member counts as int; the latter removed 12 bytes of mask code
//   and improved the strict diff to 883 bytes.
// - A do-while scan rewrite expanded the CFG and lost exact loop islands; it
//   was rolled back to the bounded for-loop form.
// - Donor-backed count-first scans and the inverted direct add_node tail
//   restore the original CFG islands, but register colors and local homes
//   still differ from the executable.
// - The original writes short indices into the incoming file/world homes;
//   keep the saved handle separate and preserve those parameter-home writes.
// - The reviewed DAT_00574724 and DAT_00574728 symbols recover the two rdata
//   comparison operands.  No source or context probe fixed the prologue basin.
// - Twenty-one hypotheses covered handle aliases, parameter-home reuse,
//   scalar scopes and order, array layout, loop forms, branch polarity, direct
//   calls, rdata symbols, and a local aggregate.  The current source is the
//   clearest donor-backed form.  Next lead: recover the original TU local
//   declaration context or register basin before further body rewrites.
// - Earlier direct-call tail work was superseded.  The current inverted branch
//   form restores the original tail block islands with the donor-backed scans.
// - A six-word local aggregate in binary stack order recovered the original
//   homes, but main review rejected it as local-home steering. A natural short
//   serialization index remains because it models the two-byte reads.
// - Tested register qualifiers, declaration order, aliases, narrow byte type,
//   header context, named zero, and nested scans; none changed the best basin.
// - Final unresolved residue is the callee-saved register permutation: the
//   build uses EBP for the file and EBX for zero, while the executable uses
//   EDI for file, EBX for world, and EBP for zero.
// BINARY NOTE: this loader entry is a protected virtual setup member.

#include "../../include/game_globals.h"
#include "../../include/stat_obj_context.h"

extern void rge_read(int file, void* buffer, int size);
extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);

extern float save_game_version;

int RGE_Static_Object::setup(int file, RGE_Game_World* world) {
    int save_file = file;
    int long_val;
    int byte_val;
    int numberUnits;
    int tempInt;
    int tempInt_fffffff8;
    int local_4;
    short index;

    this->type = 10;
    rge_read(save_file, &long_val, 1);
    this->owner = world->players[long_val & 0xff];

    // BINARY NOTE: The shipped loader reuses the incoming file home for this index.
    rge_read(save_file, &index, 2);
    this->master_obj = this->owner->master_objects[index];

    rge_read(save_file, &index, 2);
    if (index >= 0) {
        this->sprite = world->sprites[index];
    } else {
        this->sprite = 0;
    }

    this->old_sprite = 0;
    rge_read(save_file, &tempInt, 4);
    if (tempInt == -1) {
        this->inside_obj = 0;
    } else {
        this->inside_obj = (RGE_Static_Object*)tempInt;
    }

    rge_read(save_file, &this->hp, 4);
    rge_read(save_file, &this->object_state, 1);
    rge_read(save_file, &this->sleep_flag, 1);
    if (save_game_version >= DAT_00574724) {
        rge_read(save_file, &this->dopple_flag, 1);
    }
    rge_read(save_file, &this->goto_sleep_flag, 1);
    rge_read(save_file, &this->id, 4);
    rge_read(save_file, &this->facet, 1);
    rge_read(save_file, &this->world_x, 4);
    rge_read(save_file, &this->world_y, 4);
    rge_read(save_file, &this->world_z, 4);
    rge_read(save_file, &this->screen_x_offset, 2);
    rge_read(save_file, &this->screen_y_offset, 2);
    rge_read(save_file, &this->shadow_x_offset, 2);
    rge_read(save_file, &this->shadow_y_offset, 2);
    rge_read(save_file, &this->selected_group, 1);
    rge_read(save_file, &this->attribute_type_held, 2);
    rge_read(save_file, &this->attribute_amount_held, 4);
    rge_read(save_file, &this->worker_num, 1);
    rge_read(save_file, &this->curr_damage_percent, 1);
    rge_read(save_file, &this->underAttackValue, 1);
    this->tile = 0;
    rge_read(save_file, &this->groupCommanderValue, 4);
    rge_read(save_file, &this->groupRangeValue, 4);

    if (save_game_version == DAT_00574728) {
        rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &local_4, 4);
        rge_read(save_file, &tempInt_fffffff8, 4);
        rge_read(save_file, &tempInt_fffffff8, 4);
    }

    rge_read(save_file, &byte_val, 4);
    numberUnits = 0;
    if (0 < byte_val) {
        do {
            rge_read(save_file, &tempInt_fffffff8, 4);
            // BINARY NOTE: The duplicate scan checks count before capacity.
            int number = this->groupMembers.numberValue;
            int index = 0;
            local_4 = tempInt_fffffff8;
            for (; index < number && index < this->groupMembers.maximumSizeValue;
                 index = index + 1) {
                if (this->groupMembers.value[index] == tempInt_fffffff8) {
                    goto group_member_found;
                }
            }
            if (number > this->groupMembers.maximumSizeValue - 1) {
                int newNumber = number + 1;
                int* values = (int*)operator new(newNumber * 4);
                if (values != 0) {
                    index = 0;
                    for (; index < this->groupMembers.maximumSizeValue && index < newNumber;
                         index = index + 1) {
                        values[index] = this->groupMembers.value[index];
                    }
                    operator delete(this->groupMembers.value);
                    this->groupMembers.value = values;
                    this->groupMembers.maximumSizeValue = newNumber;
                }
            }
            this->groupMembers.value[this->groupMembers.numberValue] = local_4;
            this->groupMembers.numberValue = this->groupMembers.numberValue + 1;
        group_member_found:
            numberUnits = numberUnits + 1;
        } while (numberUnits < byte_val);
    }

    rge_read(save_file, &byte_val, 4);
    numberUnits = 0;
    if (0 < byte_val) {
        do {
            rge_read(save_file, &local_4, 4);
            int number = this->pathingGroupMembers.numberValue;
            int index = 0;
            tempInt_fffffff8 = local_4;
            for (; index < number && index < this->pathingGroupMembers.maximumSizeValue;
                 index = index + 1) {
                if (this->pathingGroupMembers.value[index] == local_4) {
                    goto pathing_member_found;
                }
            }
            if (number > this->pathingGroupMembers.maximumSizeValue - 1) {
                int newNumber = number + 1;
                int* values = (int*)operator new(newNumber * 4);
                if (values != 0) {
                    index = 0;
                    for (; index < this->pathingGroupMembers.maximumSizeValue && index < newNumber;
                         index = index + 1) {
                        values[index] = this->pathingGroupMembers.value[index];
                    }
                    operator delete(this->pathingGroupMembers.value);
                    this->pathingGroupMembers.value = values;
                    this->pathingGroupMembers.maximumSizeValue = newNumber;
                }
            }
            this->pathingGroupMembers.value[this->pathingGroupMembers.numberValue] = tempInt_fffffff8;
            this->pathingGroupMembers.numberValue = this->pathingGroupMembers.numberValue + 1;
        pathing_member_found:
            numberUnits = numberUnits + 1;
        } while (numberUnits < byte_val);
    }

    this->sprite_list = this->create_sprite_list();
    this->sprite_list->load(save_file, world->sprites);
    this->owner->world->add_object(this);

    if (this->sleep_flag != 0) {
        this->owner->sleeping_objects->add_node(this);
    } else if (this->dopple_flag != 0) {
        this->owner->doppleganger_objects->add_node(this);
    } else {
        this->owner->objects->add_node(this);
    }

    this->objects = this->create_object_list();
    this->selected = 0;
    return 1;
}
