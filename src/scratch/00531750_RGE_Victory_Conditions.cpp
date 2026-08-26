// RGE_Victory_Conditions::RGE_Victory_Conditions
// VA: 00531750
// victory.cpp
// Attempt log:
// - Replaced raw-offset scaffolding with typed player, world, object-list, entry, and point
//   ownership. The 33-call set and direct helper identities now match the executable.
// - Pointer locals for list count and list tail recover the original 0x1C frame and 920-byte
//   boundary. Saving the file handle and reusing its dead parameter home as target-player ID
//   is required for the best natural source shape.
// - BINARY NOTE: The original writes the target-player ID through the incoming handle home.
//   ESI still carries the file handle for every later read.
// - BINARY NOTE: A dword loop counter reuses the incoming version-flag home. One natural
//   counter now serves both serialized loops. The serialized target-object ID has function
//   scope. This recovers the original local basin without a raw parameter-home alias.
// - Positive-first version predicates recover the late negative-version blocks. A double
//   1.0 threshold recovers the original qword FPU compare. The canonical point record uses
//   id at +2 and group at +3, as shown by the exact add_point and save donors.
// - Probe 46: the best natural source has exact size, frame, owner symbol, and 33 ordered
//   calls. It has 493 differing bytes, 97.03% shape, and 87.46% exact-block coverage.
// - Remaining drift is the early player-store order, player-scan register color, point-read
//   register color, and vtable relocation context.
// - BINARY NOTE: PDB assigns this body to victory.cpp lines 28-145. The same module's
//   exact constructor and destructor anchors are 00531AF0 (lines 150-158) and 00531B20
//   (lines 163-172). The shared declarations in victory_context.h preserve the proven
//   0x20 conditions, 0x34 entry, and 0x1C point-entry layouts.
// - Current prefix pass: binding the second serialized area coordinate to the proven y2
//   +0x18 alias reduced the natural candidate from 712 to 493 differing bytes and removed
//   the boundary escapes. The remaining mismatch is the logged early-store and register
//   allocation basin. Initialization-order reordering was codegen-neutral and was restored.

#include "../../include/victory_context.h"

RGE_Victory_Conditions::RGE_Victory_Conditions(
    RGE_Player* player, int handle, long* version_map, unsigned char version_flag) {
    long index;
    long version;
    float save_version;
    long point_count;
    long* list_num_ptr;
    RGE_Victory_Entry** tail;
    int file_handle = handle;
    long target_object_id;

    if (version_flag == 1) {
        rge_read(file_handle, &save_version, 4);
    } else {
        save_version = 0.0f;
    }

    list_num_ptr = &this->list_num;
    rge_read(file_handle, list_num_ptr, 4);
    rge_read(file_handle, &this->victory, 1);

    tail = &this->victory_list;
    *tail = 0;
    this->player = player;
    index = 0;

    while (index < *list_num_ptr) {
        RGE_Victory_Entry* entry =
            (RGE_Victory_Entry*)calloc(1, sizeof(RGE_Victory_Entry));

        rge_read(file_handle, entry, 1);
        rge_read(file_handle, &entry->obj_type, 4);
        rge_read(file_handle, &version, 4);
        rge_read(file_handle, &entry->x0, 4);
        rge_read(file_handle, &entry->y0, 4);
        rge_read(file_handle, &entry->x1, 4);
        rge_read(file_handle, &entry->y2, 4);
        rge_read(file_handle, &entry->number, 4);
        rge_read(file_handle, &entry->count, 4);
        rge_read(file_handle, &handle, 4);
        rge_read(file_handle, &target_object_id, 4);
        rge_read(file_handle, &entry->victory_group, 1);
        rge_read(file_handle, &entry->ally_flag, 1);
        rge_read(file_handle, &entry->state, 1);

        entry->target_obj = 0;
        entry->this_obj = 0;
        entry->target_player = 0;
        *tail = entry;
        tail = &entry->next;

        if (handle >= 0) {
            int player_index = 0;
            RGE_Game_World* world = this->player->world;
            while (player_index < world->player_num) {
                entry->this_obj =
                    world->players[player_index]->objects->find_by_id(handle);
                if (entry->this_obj != 0) {
                    break;
                }
                player_index++;
                world = this->player->world;
            }
            if (handle >= 0 && entry->this_obj == 0) {
                entry->state = 3;
            }
        }

        if (target_object_id >= 0) {
            entry->target_obj = this->player->objects->find_by_id(target_object_id);
        }

        if (version >= 0) {
            if (version_map != 0) {
                version = version_map[version];
            }
            if (version >= 0) {
                RGE_Player* reference_player =
                    this->player->world->players[version];
                entry->target_player = reference_player;
                if (reference_player != 0 && entry->target_obj == 0 &&
                    target_object_id >= 0) {
                    entry->target_obj =
                        reference_player->objects->find_by_id(target_object_id);
                }
            } else {
                entry->state = 3;
            }
        } else {
            entry->target_player = 0;
        }

        if (target_object_id >= 0 && entry->target_obj == 0) {
            entry->state = 3;
        }

        index++;
    }

    this->victory_point_list = 0;
    this->point_list_num = 0;

    if (save_version >= 1.0) {
        long* total_points = &this->tot_victory_points;
        rge_read(file_handle, total_points, 4);
        rge_read(file_handle, &point_count, 4);

        index = 0;
        while (index < point_count) {
            RGE_Victory_Point_Entry* point = this->add_point(0, 0);
            rge_read(file_handle, point, 1);
            rge_read(file_handle, &point->state, 1);
            rge_read(file_handle, &point->attribute, 4);
            rge_read(file_handle, &point->amount, 4);
            rge_read(file_handle, &point->points, 4);
            rge_read(file_handle, &point->curr_points, 4);
            rge_read(file_handle, &point->id, 1);
            rge_read(file_handle, &point->group, 1);
            rge_read(file_handle, &point->curr_attribute_amount, 4);

            if (*total_points < 0) {
                point->points = 0;
            }
            index++;
        }

        if (*total_points < 0) {
            *total_points = 0;
        }
    } else {
        this->tot_victory_points = 0;
    }
}
