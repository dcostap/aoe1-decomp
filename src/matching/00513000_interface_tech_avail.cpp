// VA: 00513000, TRIBE_Player::interface_tech_avail, 446 bytes
// Source: tplayer.cpp lines 930-975
// Attempt log:
// - v1: natural decompiler-shaped implementation with local TRIBE_Player/TRIBE_Player_Tech/Item_Avail structs.
// - v2: modeled master tech array stride 0x3c, type at +0x28, pict at +0x24; tech player entry stride 8 state at +4.
// - v3: used calloc/free declarations and direct TRIBE_Player_Tech member calls.
// - v4: fixed tech_source master pointer at +0x104 and made count int to encourage EBX counter / EBP this.
// - v5: moved count initialization after initial member loads, probing original source-line order/register split.
// - v6: introduced explicit self local and used it for member reloads to try to force EBP=this / EBX=count; no prologue change.
// - v7: reverted self and count back to short after +0x104 layout fix.
// - v8: tried register short count to probe EBX allocation.
// - v9: tried reusing out_count parameter slot as output index; worse (frame shrank to 0x10), rolled back.
// - v10: tried reusing out_items parameter slot as inv1 temp for tech_cost; worse (frame shrank to 0x10), rolled back.
// - v11: paused in scratch. Best check: 446/446 bytes, positional diff 70.4036%, edit diff 30.0448%, first mismatch +0x04.
//   Blocker: broad register-allocation/source-context basin. Original uses EBP=this and EBX=count in the prologue,
//   while rebuilt insists on EBX=this and EBP=count, causing early register drift. Later body is behaviorally close
//   (correct +0x104 master table, count/free/calloc, tech_cost/help calls), but local/parameter temp placement for
//   tech_cost cost shorts also differs. Likely needs donor TU/source declaration context or a more exact stack-slot model.
// - v12: removed the cached tech_tree local and the explicit master reload after
//   each item; direct tech_tree reloads plus one saved master pointer recover the
//   original EBP=this/EBX=count prologue, exact frame/size/call/relocation parity,
//   and reduce the mismatch to 30 bytes.
// - v13-v14: declaration and master-table staging variants did not improve the
//   remaining initial load order. The original loads tech count in DX before
//   dereferencing the saved master pointer; rebuilt still loads the master into
//   ESI before the count in CX. Final validated source keeps the canonical direct
//   ownership and the narrow count register clue; paused at that localized basin.
// - v15: moved the natural tech-count declaration before the master dereference;
//   VC5 scheduled the tech-tree load before the master load and widened the diff
//   to 45 bytes. Rolled back; the 30-byte clean source remains best.
// - v16: adopted the exact tplayer tech_cost output order and typed call surface
//   from researchCost; emitted code was unchanged (30-byte diff), so restored.
// - v17-v18: staged the master-table pointer, including an explicit source alias;
//   both moved the field load after the tech-tree load and widened the diff to 45.
// - v19-v21: volatile count/master access probes either added a stack store or
//   duplicated the 30-byte output; all were rolled back.
// - v22: separate master declaration and assignment after the count; duplicate
//   45-byte output. v23: canonical world->tech->tech_tree ownership widened to 56.
// - v24-v25: address/reference aliases for the master pointer widened to 427/45.
// - v26: reused the decompiler's tech index across both scans; emitted code was
//   unchanged. Final lead remains the initial DX-before-ESI VC5 scheduling gap.
// - Prior pass: parameter-home reuse was tested but rejected by policy. The
//   then-clean source kept a named output index. Register hints, declaration
//   scope, and direct guard spellings did not change codegen. Staged master
//   pointers, count-before-master order, guarded master assignment, and a
//   hoisted countdown widened the result and were restored. The clean source
//   reached a 30-byte mismatch, led by initial DX-before-ESI scheduling.
// - Revisit: function-scope tech_cost short outputs, supported by the Ghidra
//   local evidence, reduced the natural source to a 16-byte mismatch and made
//   the whole body exact. This uses no explicit parameter-home assignment.
// - Revisit probes for function-scope countdown/cursors, one shared scan cursor,
//   declaration order, and the donor-supported stdlib.h context were duplicate.
//   Typed master-table aliasing and guarded master assignment widened the code.
//   Retain the natural function-scope output model; the initial DX-before-ESI
//   scheduling basin remains unresolved.
// - v27: replaced offset-only entry views with the period-supported
//   Tech_Player_Tree and Tech_Entry layouts used by exact same-TU tech
//   functions; the canonical typed source is codegen-duplicate at 16 bytes.
// - v28: a persistent tech-tree alias changed the prologue and helper target
//   (426-byte diff); restored direct this->tech_tree ownership.
// - v29: canonical RGE_Player::world -> TRIBE_World::tech -> TRIBE_Tech::tech_tree
//   ownership was codegen-duplicate at 16 bytes. A separate master-table alias
//   reached the original load order but widened the result to 31 bytes.
// - v30: exact Tech_Entry mapping briefly selected +22 for the pict output;
//   mapping the proven +24 access to full_tech_mode restored 16 bytes.
//   The full RGE_Player base fields and RGE_Game_World vptr were also duplicate.
// - v31: moving n before the master assignment, even with canonical types,
//   reached the original local load order but widened the result to 31 bytes;
//   restored master-first source order and the 16-byte clean reconstruction.
// - Prior accepted-drift audit: the executable reads
//   tech_tree->tech_player_tree_num before it dereferences world->tech->tech_tree.
//   The rebuild dereferences world->tech->tech_tree first. This changes pointer-fault order
//   and behavior under concurrent table replacement before any output writes.
//   The exact indexed loop below resolves this fault-order difference.
// - Exact finish: restored the PDB line-941 short indexed for-loop over both typed arrays.
//   VC5 snapshots the short bound and converts both indexes to moving cursors.
//   This loop preserves the original load order and all 446 bytes.
// - Walkback: a named bound also stayed exact, but the direct member bound is smaller.
//   Removing the dead first-scan n assignment stayed exact.
//   Narrowing n and out_index to the second scan also stayed exact.
//   Pointer loops and an int loop did not match.
// - Canonical type review restored Tech_Tree, icon at +0x24, and build_obj_id at +0x28.
//   The PDB type dump proves this 0x3C record.

#include "../../include/tplayer_context.h"
#include <stdlib.h>

void TRIBE_Player::interface_tech_avail(Item_Avail** out_items, short* out_count, short button_location)
{
    short count = 0;
    short inv1, amt1, inv2, amt2, inv3, amt3;
    Tech_Tree* master = ((TRIBE_World*)this->world)->tech->tech_tree;

    for (short i = 0; i < this->tech_tree->tech_player_tree_num; i++) {
        if (this->tech_tree->tech_player_tree[i].state == 1 &&
            master[i].build_obj_id == button_location) {
            count++;
        }
    }

    if (*out_items != 0) {
        free(*out_items);
        *out_items = 0;
    }

    *out_count = count;
    if (count == 0) {
        return;
    }

    *out_items = (Item_Avail*)calloc((int)count, 0x28);

    short n = 0;
    short out_index = 0;
    if (this->tech_tree->tech_player_tree_num <= 0) {
        return;
    }

    do {
        int idx = (int)n;
        if (this->tech_tree->tech_player_tree[idx].state == 1) {
            Tech_Tree* entry = &master[idx];
            if (entry->build_obj_id == button_location) {
                int avail_index = (int)out_index;
                Item_Avail* item = *out_items;
                item[avail_index].id = n;
                (*out_items)[avail_index].pict = entry->icon;
                (*out_items)[avail_index].name = entry->name;

                this->tech_tree->tech_cost(n, &inv1, &amt1, &inv2, &amt2, &inv3, &amt3);

                (*out_items)[avail_index].inv1 = inv1;
                (*out_items)[avail_index].cost1 = (float)(int)amt1;
                (*out_items)[avail_index].inv2 = inv2;
                (*out_items)[avail_index].cost2 = (float)(int)amt2;
                (*out_items)[avail_index].inv3 = inv3;
                (*out_items)[avail_index].cost3 = (float)(int)amt3;
                (*out_items)[avail_index].help_msg = this->tech_tree->get_help_message(n);
                (*out_items)[avail_index].help_page = this->tech_tree->get_help_page(n);

                out_index++;
            }
        }
        n++;
    } while (n < this->tech_tree->tech_player_tree_num);
}
