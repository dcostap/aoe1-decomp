// VA: 005131C0 TRIBE_Player::interface_item_avail
// Attempt log:
// v1 natural implementation with helper: compiled main 544B vs 804B, helper not inlined enough.
// v2 duplicate fill code inline like original: /O2 grew to 704B but still undersized vs 804B.
// v3 /GX: no change/benefit, still 704B; rolled back flag.
// v4 /Od: same-size 804B but EBP-frame debug family and 94.9005% positional, rolled back flag.
// v5 kept v2: it models count pass, special 0x76/0x6d extra item, free/calloc, item fill, obj_cost, help message/page.
// scratch give-up: remaining gap is broad source-shape/local-layout mismatch; likely needs exact original variable topology for obj_cost out-params and duplicated item-fill scheduling, not accepted-drift-safe.
// v6 canonicalized the inherited RGE_Player/RGE_Object_List/RGE_Static_Object
// ownership and corrected obj_cost to its six-short-output ABI.  The previous
// local list record skipped the static object's master_obj indirection and the
// previous declaration passed one extra output pointer.
// v7-v8 narrowed the special-item flag to short and tested declaration order;
// the width improved the emitted topology, while declaration order was a
// codegen duplicate.
// v9 restored the period RGE_Player field surface from exact tplayer.cpp donors;
// it was a codegen duplicate.  v10 tested a natural self-pointer lifetime and
// got closer diagnostically, but introduced a shifted direct-call pairing and
// less canonical base/index spelling; it was rolled back.
// final validated scratch: direct typed ownership with repeated indexed item
// stores is 789 rebuilt bytes versus 804, 91.63% shape, 571 positional diff.
// The remaining gap is a stable callee-save permutation (this/count/zero) plus
// a 15-byte late item-fill/block-layout difference; all eight calls and the
// corrected six-output obj_cost relocation are aligned.  Further blind probes
// are paused after the ten-hypothesis budget.
// shardB4 reconstruction: keep the exact tplayer.cpp direct indexed ownership
// in the extra item path, and model all six obj_cost outputs as typed shorts.
// v11 typed the Item_Avail gaps, restored virtual object/list ownership, used
// reference ABI outputs, and removed the cached extra master; 287 diff bytes.
// v12 ordered the typed obj_cost outputs as Item_Avail fields; shape reached
// 99.59% and the rebuilt size reached 806 bytes.
// v13 preincrement spelling was a codegen duplicate.  An int output cursor
// and a compound source-index increment were farther or duplicate; reverted.
// v14 a for-loop rewrite was farther; the natural do/while source is retained.
// orch-5131C0-a: a guarded while spelling was a codegen duplicate.
// Swapping the second-pass cursor declarations reduced the mismatch from 281
// bytes to 6 and matched the late counter schedule and exact function size.
// Split initialization, inner cursor scope, and a for-header index were
// farther or duplicate.  Retain the natural swapped declarations; the only
// remaining bytes are the zero-initialization order at the second-pass start.
// ACCEPTED_DRIFT: main-agent adjudication confirmed the six remaining bytes
// only reverse zero-register and distinct local-home stores. The following cmp
// overwrites flags. Both cursor values are zero before their first use. Size,
// frame, calls, CFG, and all later address calculations match.

#include <stdlib.h>

extern float DAT_00576828;

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char type;
    char gap_05[3];
    char* name;
    char gap_0c[4];
    short id;
    char gap_12[0x3a];
    short pict;
    char gap_4e[4];
    unsigned char available;
    char gap_53[0x109];
    short interface_group;
    long get_help_message(); long get_help_page();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long object_id;
    RGE_Master_Static_Object* master_obj;
};

struct RGE_Object_Node { RGE_Static_Object* object; RGE_Object_Node* next; };

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int computer_player_value;
    int pathing_attempt_cap;
    int pathing_delay_cap;
    int current_pathing_attempts;
    int checksum;
    int position_checksum;
    int action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap_21;
    short master_count;
    RGE_Master_Static_Object** masters;
    RGE_Object_List* object_list;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    void* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49;
    short id;
    short attribute_num;
    char gap_4e[2];
    float* attributes;
    unsigned char culture;
    char gap_55[3];
    unsigned char tile_list[0x14];
    unsigned char diam_tile_list[0x14];
    unsigned char game_status;
    unsigned char resigned;
    char gap_82[2];
    unsigned char* relations;
    int unit_diplomacy[9];
    int mutual_ally[9];
    unsigned int mutual_explored_mask;
    unsigned int mutual_visible_mask;
    unsigned int non_mutual_visible_mask;
    int remove_visible_bits[9];
    int allied_los_enable;
    unsigned char allied_victory;
    unsigned char master_player_id;
    char gap_106[2];
    void* color_table;
    int tribe_effect;
    void* vr_list;
};

struct Item_Avail {
    char* name;
    short id;
    short pict;
    short inventory_item_1;
    unsigned char gap_0A[2];
    float inventory_cost_1;
    short inventory_item_2;
    unsigned char gap_12[2];
    float inventory_cost_2;
    short inventory_item_3;
    unsigned char gap_1A[2];
    float inventory_cost_3;
    long help_string_id;
    long help_page_id;
};

class TRIBE_Player : public RGE_Player {
public:
    void obj_cost(short, char**, short&, short&, short&, short&, short&, short&, float);
    void interface_item_avail(Item_Avail**, short*, short);
};
#endif

void TRIBE_Player::interface_item_avail(Item_Avail** out, short* count_out, short group)
{
    short add_extra = 0;
    short count = 0;
    short inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3;

    if (this->master_count > 0) {
        RGE_Master_Static_Object** pp = this->masters;
        int n = this->master_count;
        do {
            RGE_Master_Static_Object* m = *pp;
            if (m != 0 && m->type >= 0x46 && m->available != 0 && m->interface_group == group) count++;
            pp++;
            n--;
        } while (n != 0);
    }

    if (group == 0x76 && this->attributes[0x30] == DAT_00576828 && this->masters[0x6d]->available == 0) {
        add_extra = 1;
        RGE_Object_Node* node = this->object_list->list;
        while (node != 0) {
            if (node->object->master_obj->id == 0x6d) add_extra = 0;
            node = node->next;
        }
    }
    if (add_extra != 0) count++;

    Item_Avail** item_list = out;
    if (*item_list != 0) { free(*item_list); *item_list = 0; }
    *count_out = count;
    if (count == 0) return;
    *item_list = (Item_Avail*)calloc((int)count, 0x28);

    short idx = 0;
    short out_i = 0;
    while (idx < this->master_count) {
            if (this->masters[idx] != 0 && this->masters[idx]->type >= 0x46 &&
                this->masters[idx]->available != 0 && this->masters[idx]->interface_group == group) {
                (*item_list)[out_i].id = idx;
                (*item_list)[out_i].pict = this->masters[idx]->pict;
                (*item_list)[out_i].name = this->masters[idx]->name;
                this->obj_cost((short)idx, 0, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3, 1.0f);
                (*item_list)[out_i].inventory_item_1 = inv_1;
                (*item_list)[out_i].inventory_cost_1 = (float)(int)inv_amt_1;
                (*item_list)[out_i].inventory_item_2 = inv_2;
                (*item_list)[out_i].inventory_cost_2 = (float)(int)inv_amt_2;
                (*item_list)[out_i].inventory_item_3 = inv_3;
                (*item_list)[out_i].inventory_cost_3 = (float)(int)inv_amt_3;
                (*item_list)[out_i].help_string_id = this->masters[idx]->get_help_message();
                (*item_list)[out_i].help_page_id = this->masters[idx]->get_help_page();
                ++out_i;
            }
            idx++;
    }

    if (add_extra != 0) {
        (*item_list)[out_i].id = 0x6d;
        (*item_list)[out_i].pict = this->masters[0x6d]->pict;
        (*item_list)[out_i].name = this->masters[0x6d]->name;
        this->obj_cost(0x6d, 0, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3, 1.0f);
        (*item_list)[out_i].inventory_item_1 = inv_1;
        (*item_list)[out_i].inventory_cost_1 = (float)(int)inv_amt_1;
        (*item_list)[out_i].inventory_item_2 = inv_2;
        (*item_list)[out_i].inventory_cost_2 = (float)(int)inv_amt_2;
        (*item_list)[out_i].inventory_item_3 = inv_3;
        (*item_list)[out_i].inventory_cost_3 = (float)(int)inv_amt_3;
        (*item_list)[out_i].help_string_id = this->masters[0x6d]->get_help_message();
        (*item_list)[out_i].help_page_id = this->masters[0x6d]->get_help_page();
    }
}
