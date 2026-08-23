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
// Current context pass: the PDB-ordered base surface fixes the clear-size load
// order and proves pointer-qualified stack helper symbols. PDB local order also
// restores y, x, tile_y, tile_x, count, obj_stack, and float zone ownership.
// The result is 568 bytes with an exact frame, 13 aligned calls, and 40 changed
// bytes. The mismatch starts after make_placement_stack and ends at the first
// pop_stack call. The bottom call and all later blocks are exact.
// ACCEPTED DRIFT: The residual only recolors and schedules the player lookup,
// count store, and private output addresses. It keeps the same memory-read and
// fault order, arguments, calls, FPU work, state changes, and return.
// Count-before-player lowers the residual to 25 bytes but reads count before
// world. Keep player-before-count to preserve executable fault order.
// A complete-world continuation tested typed world/table aliases, a sequenced
// comma expression, first-pop loop forms, const player storage, and explicit
// output or stack pointers. All safe forms emit this same 40-byte basin.
// Completing the PDB player/master suffixes also moved the exact clear block
// and increased the residual to 42 bytes, so that broad context was removed.

extern "C" void* __cdecl memset(void*, int, unsigned int);
#include "..\..\include\rmm_obj_context.h"

void RGE_RMM_Object_Generator::place_avoid_objects(RGE_Object_Info_Line& info, long unused)
{
    long y;
    long x;
    float tile_y;
    float tile_x;
    long count;
    Map_Stack obj_stack;
    float zone;
    RGE_Master_Static_Object* master;
    short radius;
    int i;

    memset(this->search_map, 1, this->map_width * this->map_height);

    for (i = 0; i < this->info.land_num; i++) {
        this->set_search_area(this->info.lands[i].x, this->info.lands[i].y,
                              info.land_inner_radius, 0);
    }

    this->init_stack(&obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    RGE_Player* player = this->world->players[
        info.player_id & ((info.player_id <= -1) - 1)];
    count = info.number_of_groups;

    while (this->pop_stack(&obj_stack, &x, &y, &zone) && count > 0) {
            if (info.terrain >= 0) {
                if ((this->map_row_offset[y][x].terrain & 0x1f) !=
                    (unsigned int)info.terrain) {
                    goto next;
                }
            }

            tile_x = (float)x;
            tile_y = (float)y;
            master = player->master_objects[info.obj_id];
            radius = (short)(int)master->radius_x;
            if (master->radius_x - (float)radius > 0.0f) {
                tile_x = tile_x - -0.5f;
            }
            radius = (short)(int)master->radius_y;
            if (master->radius_y - (float)radius > 0.0f) {
                tile_y = tile_y - -0.5f;
            }

            if (!master->can_place(player, tile_x, tile_y, 0, 0, 1, 1, 1, 0, 1)) {
                this->remove_area_from_lists(x, y, info.object_exclusion_zone);
                switch (info.group_flag) {
                case 0:
                    player->place_object(info.obj_id, tile_x, tile_y, 0, 1);
                    break;
                case 1:
                    this->place_group(info, x, y, player);
                    break;
                case 2:
                    this->place_cluster(info, x, y, player);
                    break;
                }
                count--;
            }
    next:
        ;
    }
    this->deinit_stack(&obj_stack);
}
