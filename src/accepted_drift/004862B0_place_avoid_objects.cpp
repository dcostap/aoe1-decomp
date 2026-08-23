// 004862B0 RGE_RMM_Object_Generator::place_avoid_objects
// Source: rmm_obj.cpp lines 255-324.
// Attempt log:
// - Reconstructed the function from the typed random-map and object surfaces.
// - The input record is RGE_Object_Info_Line; player_id selects a world player,
//   and that player's master object supplies radius and placement methods.
// - The original virtual calls are master_object +0x20 and player +0x94.
//   The old local stubs used the wrong object ownership and virtual slots.
// - Restored the inherited random-map layout and the exact RGE_Object_Info
//   field ownership. This fixed all direct-call and virtual-call identities.
// - A volatile count home reproduced the observed stack count and gave a
//   568-byte build with 53 differing bytes. It was diagnostic compiler
//   steering, so the final source restores the natural plain count.
// - Pointer stack helpers match the exact random-map ABI donor. Operand and
//   player-index scheduling variants were codegen duplicates.
// - Final natural source is 556 bytes with a 0x2C frame and 426 differing
//   bytes. The closer volatile form remains diagnostic evidence only.
// - Changed the placement scan from an initial-pop do/while to a typed
//   while(pop_stack && count > 0). The original reloads count after each
//   pop, so this is the natural source form for the observed loop topology.
// - This session tested height-first memset operands, explicit world/player
//   temporaries, signed-mask spellings, and reference-based stack helpers.
//   All natural variants were codegen duplicates at the 52-byte residual.
// - A signed-mask expression copied from the decompiler widened the drift to
//   428 bytes. A volatile map-size home widened it to 571 bytes and 16 extra
//   bytes. Restored the clean typed source; the remaining lead is compiler
//   scheduling of the initial clear and player-table block.
// - Batch worker probes restored the original terrain/FPU coordinate roles by
//   using tile_x as the map row and x as the map column. Helper calls also use
//   the original x,tile_x argument order. This gives 568 bytes, exact frame,
//   204 instructions, 13 calls, and a 42-byte (7.3944%) positional diff.
// - The remaining drift is confined to the initial dimension-load order and
//   the first pop_stack setup. The bottom pop_stack call and all later blocks
//   are positionally exact. World/player aliases, count scope, stack pointer
//   aliases, and reference-form stack ABI were codegen duplicates or worse.
// ACCEPTED DRIFT: The initial clear multiplies the same width and height in the
// opposite load order. The next hunk recolors the player index and schedules
// valid world/player loads and private output addresses around the first
// pop_stack call. Both builds pass identical addresses and values. All 13 calls,
// used flags, memory effects, FPU operations, returns, and fault order match.
// Context pass: the shared rmm_obj declaration surface is used by the full owner
// prefix. The prefix keeps the 568-byte body and 42-byte drift.

extern "C" void* __cdecl memset(void*, int, unsigned int);
#include "..\..\include\rmm_obj_context.h"

void RGE_RMM_Object_Generator::place_avoid_objects(RGE_Object_Info_Line& info, long unused)
{
    Map_Stack stack;
    long x;
    long tile_x;
    long y;
    long count;
    float fx;
    float fy;
    short zone;
    RGE_Player* player;
    RGE_Master_Static_Object* master;
    int i;

    memset(this->search_map, 1, this->map_width * this->map_height);

    for (i = 0; i < this->info.land_num; i++) {
        this->set_search_area(this->info.lands[i].x, this->info.lands[i].y,
                              info.land_inner_radius, 0);
    }

    this->init_stack(stack);
    this->make_placement_stack(stack, -1, -1, -1, -1);

    player = this->world->players[
        info.player_id & (info.player_id <= -1 ? 0 : -1)];
    count = info.number_of_groups;

    while (this->pop_stack(stack, x, tile_x, *(float*)&y) && count > 0) {
            if (info.terrain >= 0) {
                if ((((RGE_Tile**)this->map_row_offset)[tile_x][x].terrain & 0x1f) !=
                    (unsigned int)info.terrain) {
                    goto next;
                }
            }

            fx = (float)x;
            fy = (float)tile_x;
            master = player->master_objects[info.obj_id];
            zone = (short)(int)master->radius_x;
            if (master->radius_x - (float)zone > 0.0f) {
                fx = fx - -0.5f;
            }
            zone = (short)(int)master->radius_y;
            if (master->radius_y - (float)zone > 0.0f) {
                fy = fy - -0.5f;
            }

            if (!master->can_place(player, fx, fy, 0, 0, 1, 1, 1, 0, 1)) {
                this->remove_area_from_lists(x, tile_x, info.object_exclusion_zone);
                switch (info.group_flag) {
                case 0:
                    player->place_object(info.obj_id, fx, fy, 0, 1);
                    break;
                case 1:
                    this->place_group(info, x, tile_x, player);
                    break;
                case 2:
                    this->place_cluster(info, x, tile_x, player);
                    break;
                }
                count--;
            }
    next:
        ;
    }
    this->deinit_stack(stack);
}
