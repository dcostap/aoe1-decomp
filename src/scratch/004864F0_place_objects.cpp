// 004864F0 RGE_RMM_Object_Generator::place_objects
// Attempt log:
// 1: initial natural implementation from packet/decompiler and rmm_obj neighbor stubs: exact size but 78% diff; compiler emitted counted byte loop and used edi=this.
// 2: use memset plus explicit self local to try original rep stosd clear and ebp=this register: first 74 bytes match; count kept in esi and player load scheduled later.
// 3: make count volatile to force stack local and memory test/dec: edit diff improved to 16.7%, but world/player load still scheduled after mask and stack arg LEAs shifted.
// 4: split world load to a separate local before player-id mask: no codegen change.
// 5: use <= -1 spelling for player-id mask to match cmp -1/setle: improved to 13.4%; remaining early mismatch is world load scheduled after mask and pop-argument order.
// 6: split players pointer load before mask: no codegen change.
// 7: store player id in a temp before indexing to probe load scheduling: no codegen change.
// 8: volatile world local to force load before mask: worsened to 27% edit diff with extra stack store; rolled back.
// 9: restored the proven Map_Stack/pop_stack ABI, long coordinate outputs, and
//    natural while(pop_stack && count > 0) tail; this reached exact size/CFG and
//    a 43-byte positional diff, with only the early setup hunk unresolved.
// 10: a focused 15-variant pre-loop lab (world/player declaration forms and
//     loop predicates) collapsed to duplicate codegen groups; reversing the
//     commutative mask operands was also a duplicate. The remaining drift is
//     VC5 world/mask/register and pop-argument scheduling, not behavior/calls.
// 11: ABI audit replaced the fake float cast at pop_stack with the proven
//     float cost output. Emitted bytes are unchanged; retain the safe typed form.
// 12: direct typed world local before the player-id mask plus swapped pop_stack
//     output order moved 10 bytes farther and lost aligned blocks; rolled back.
// 13: hoisted the typed master lookup before the placement loop to test the
//     original pre-pop lifetime; frame grew by 4 bytes and diff widened to 462,
//     so restored the clean loop-local lookup.
// 14: materialized the initial and bottom pop_stack result as next_stack to
//     mirror the decompiler's pMVar7 loop state; this widened the diff to 158
//     bytes and added one byte, so restored the direct natural while form.
// 15: tested the signed-negative conditional mask spelling; diff widened to
//     428 bytes, so restored the proven <= -1 form.
// 16: hoisted a typed world local to the function-local declarations; diff
//     widened to 88 bytes and moved the mismatch into the clear loop.
// 17: routed all record accesses through a natural info pointer alias; codegen
//     stayed at 43 bytes, so kept the simpler direct record accesses.
// 18: bound a typed world reference before the player lookup; codegen was an
//     unchanged 43-byte duplicate.
// 19: tested the exact decompiler mask idiom ((player_id < 0) - 1); diff widened
//     to 428 bytes, so restored the conditional mask.
// 20: modeled the high-confidence Random_Map_Module base layout; codegen stayed
//     at 43 bytes and confirmed the existing offsets.
// 21: added the virtual base declaration with a duplicate explicit vtable slot;
//     this produced a 46-byte diff and was rejected.
// 22: removed the duplicate vtable slot from the virtual base; diff was 45
//     bytes with changed operand scheduling, so restored the known stub shape.
// 23: tested the equivalent nonnegative mask idiom; diff widened to 428 bytes.
// 24: replaced the mask with an explicit negative-to-zero clamp; CFG and size
//     diverged and diff widened to 429 bytes.
// 25: combined a world local with a materialized masked index; codegen stayed
//     at 43 bytes.
// 26: added an explicit players-table local to that combination; codegen stayed
//     at 43 bytes.
// 27: moved count assignment before player lookup; diff improved from 43 to 31
//     bytes while size, frame, CFG, and calls stayed exact.
// 28: cached world before the improved count-before-player order; codegen stayed
//     at the 31-byte best.
// 29: restored the high-confidence base ownership with the 31-byte source; the
//     result stayed unchanged. Remaining drift is setup register scheduling.
// 30: direct this->world access with count-first setup was a 31-byte duplicate;
//     the simpler direct member form is now canonical.
// 31: long count, a named player index, the integer decompiler mask, and a
//     declaration-local count were all codegen duplicates or worse. The typed
//     while/pop loop and 31-byte clean source remain authoritative.
// Fresh bounded pass: explicit mask lifetimes with count-after-player widened
// the mismatch to 43 bytes. Players-slot, players-reference, and function-scope
// player locals reproduced the 31-byte basin. The remaining schedule changes
// world, info-field, player-table, and count read order. Keep this in scratch.
// Fresh claim pass: count-after-player with the direct mask widened to 43 bytes;
// top-scope player, world/table aliases, direct initialization, and reference
// Map_Stack helpers were 31-byte duplicates. A reference players alias, a
// loop-local count, an info alias, and reference helpers with count-after-player
// were 43-byte results. string.h changed the clear order and memory.h was the
// 31-byte basin. Restore the 31-byte direct-pointer clean source.
// Accepted-drift audit: do not promote. The executable reads this->world before
// info.number_of_groups. The rebuild reads number_of_groups first. It also
// moves the count store before the world and players-table reads. Concurrent
// record changes and invalid pointer storage can change results and fault order.
//
// Context audit: include/rmm_obj_context.h now supplies the period RGE_Random_Map_Module,
// object-info, player, master-object, and derived helper ownership. The real PDB prefix
// through this owner compiles in rmm_obj_full_prefix.cpp. Exact anchor results in that
// object are 00485C50 MATCH, 00485CB0 MATCH, 00485DC0 MATCH, 00486110 MATCH,
// 00486180 MATCH, and 00486210 MATCH. The nonexact owners remain behavior-valid
// context owners: 00485E50 is 8 bytes off, 00485F10 is 392 bytes off, and 004862B0
// is 42 bytes off. The target remains 515 bytes with a 31-byte positional diff.
// Full authentic prefix context did not move the first mismatch at +004A.

extern "C" void* __cdecl memset(void*, int, unsigned int);
#include "..\..\include\rmm_obj_context.h"

void RGE_RMM_Object_Generator::place_objects(RGE_Object_Info_Line& info)
{
    long x;
    long col;
    float cost;
    int count;
    float fx;
    float fy;
    int zone;
    Map_Stack obj_stack;

    // clear occupancy byte map to 1
    memset(this->byte_map, 1, this->width * this->height);

    this->init_stack(obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    count = info.number_of_groups;
    RGE_Player* player;
    player = this->world->players[
        info.player_id & (info.player_id <= -1 ? 0 : -1)];

    while (pop_stack(obj_stack, col, x, cost) && count > 0) {
            if (info.terrain < 0 || ((this->map_row_offset[x][col].terrain & 0x1f) == (unsigned int)info.terrain)) {
                fx = (float)col;
                fy = (float)x;
                RGE_Master_Static_Object* master = player->master_objects[info.obj_id];
                zone = (short)(int)master->radius_x;
                if (0.0f < master->radius_x - (float)zone) {
                    fx = fx - -0.5f;
                }
                zone = (short)(int)master->radius_y;
                if (0.0f < master->radius_y - (float)zone) {
                    fy = fy - -0.5f;
                }
                if (!master->can_place(player, fx, fy, 0, 0, 1, 1, 1, 0, 1)) {
                    remove_area_from_lists(col, x, info.object_exclusion_zone);
                    switch (info.group_flag) {
                    case 0:
                        player->place_object(info.obj_id, fx, fy, 0, 1);
                        break;
                    case 1:
                        place_group(info, col, x, player);
                        break;
                    case 2:
                        place_cluster(info, col, x, player);
                        break;
                    }
                    count--;
                }
            }
        }
    this->deinit_stack(obj_stack);
}
