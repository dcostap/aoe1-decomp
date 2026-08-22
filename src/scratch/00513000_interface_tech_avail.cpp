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
// - Accepted-drift audit: do not promote. The executable reads
//   tech_tree->tech_player_tree_num before it dereferences master_techs. The
//   rebuild dereferences master_techs first. This changes pointer-fault order
//   and behavior under concurrent table replacement before any output writes.

#include <stdlib.h>

typedef unsigned char uchar;

struct Item_Avail {
    int name;              // +00
    short id;              // +04
    short pict;            // +06
    short inv1;            // +08
    short pad0a;           // +0a
    float cost1;           // +0c
    short inv2;            // +10
    short pad12;           // +12
    float cost2;           // +14
    short inv3;            // +18
    short pad1a;           // +1a
    float cost3;           // +1c
    int help_msg;          // +20
    int help_page;         // +24
};

struct TechPlayerEntry {
    int field_00;
    short state;
    short field_06;
};

struct MasterTechEntry {
    int name;
    char gap_04[0x20];
    short pict;
    short gap_26;
    short button_location;
    char gap_2a[0x12];
};

struct TechSource {
    char gap_00[0x104];
    MasterTechEntry** master_techs;
};

class TRIBE_Player_Tech {
public:
    TechPlayerEntry* tech_player_tree; // +0
    short tech_player_tree_num;        // +4
    short pad_06;
    void* field_08;

    void tech_cost(short tech_id, short* inv_1, short* amt_1, short* inv_2, short* amt_2, short* inv_3, short* amt_3);
    long get_help_message(short tech_id);
    long get_help_page(short tech_id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
};

class TRIBE_Player : public RGE_Player {
public:
    TechSource* tech_source;       // +3c
    char gap_40[0x1e0];
    TRIBE_Player_Tech* tech_tree;  // +220

    void interface_tech_avail(Item_Avail** out_items, short* out_count, short button_location);
};

void TRIBE_Player::interface_tech_avail(Item_Avail** out_items, short* out_count, short button_location)
{
    short count = 0;
    short inv1, amt1, inv2, amt2, inv3, amt3;
    short out_index;
    short n;
    MasterTechEntry* master = *this->tech_source->master_techs;
    n = this->tech_tree->tech_player_tree_num;
    if (n > 0) {
        TechPlayerEntry* t = this->tech_tree->tech_player_tree;
        MasterTechEntry* m = master;
        int i = (int)n;
        do {
            if (t->state == 1 && m->button_location == button_location) {
                count++;
            }
            t++;
            m++;
            i--;
        } while (i != 0);
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

    n = 0;
    out_index = 0;
    if (this->tech_tree->tech_player_tree_num <= 0) {
        return;
    }

    do {
        int idx = (int)n;
        if (this->tech_tree->tech_player_tree[idx].state == 1) {
            MasterTechEntry* entry = &master[idx];
            if (entry->button_location == button_location) {
                int avail_index = (int)out_index;
                Item_Avail* item = *out_items;
                int off = avail_index * 0x28;
                item[avail_index].id = n;
                (*out_items)[avail_index].pict = entry->pict;
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
