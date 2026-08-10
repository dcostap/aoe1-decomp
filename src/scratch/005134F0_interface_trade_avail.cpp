// VA: 005134F0 TRIBE_Player::interface_trade_avail
// PDB source: tplayer.cpp lines 1063-1114
// Baseline: named game objects/lists and the natural dock scan followed by
// rebuilding the Trade_Avail array.
// Attempt log:
// - Baseline matched size/frame/call set (257 bytes, 0x188, five calls) but
//   retained a broad source-shape mismatch.
// - Narrow short coordinate conversions and one-based dock/result cursors
//   reduced the drift to the late transfer loop and stack cursor LEAs.
// - A one-past Trade_Avail cursor with output[-1] stores reproduced the
//   original negative result offsets and transfer ordering.
// - A local owner temporary reproduced the load-before-dock-store schedule but
//   colored the transfer countdown/owner as EDI/ESI; following the canonical
//   Trade_Avail field order with direct owner assignment restores ESI/EDI and
//   reduces the remaining drift to two bytes.
// - Rolled back a saved-this array alias and a synthetic aggregate layout;
//   both worsened the prologue/block shape. Current remaining drift is two
//   one-slot dock-list LEA displacements plus late counter/owner coloring.
// - Main-agent audit restored canonical virtual ownership at unchanged offsets;
//   the direct-owner source remains exact-size with only the two one-slot LEAs.
// - New full-player/TU context probes tested dock_list[0] as the saved-player
//   overlay and moved the owner declaration; the overlay broadened drift to
//   225 bytes and the declaration move duplicated the six-byte result, so the
//   canonical function-scope owner source remains retained.
// - Reordering counters before dock_list emitted the same two-byte result.
//   A 95-slot array changed the frame, explicit dock_list[0]=this broadened
//   drift to 225 bytes, and aggregate/union local surfaces were duplicate
//   codegen. A split input cursor left seven bytes; restored this direct
//   one-past cursor form. Final gap: rebuilt LEAs use +1C where the oracle uses
//   +18 at the early dock write and late transfer setup; all other 255 bytes,
//   calls, frame, and typed ownership are aligned.
// - Fresh declaration-order and first-element initialization probes were
//   duplicate or structurally worse; explicit saved-player aliases broadened
//   drift rather than making the overlay usable.
// - A natural self pointer plus 95-entry dock array (using dock_list as the
//   actual list, no synthetic padding) matched all body/LEA bytes but chose a
//   0x184 frame, leaving four frame/argument displacement bytes; owner/result/
//   dock lifetime variants did not change that basin. A union overlay returned
//   to the broad alias basin. Restored the direct canonical 96-entry source.

#include <stdlib.h>

class RGE_Player;
class RGE_Game_World;
class RGE_Visible_Map {
public:
    unsigned char get_visible(int x, int y);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
};

class RGE_Static_Object;
class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long object_id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    void* master_objects;
    RGE_Object_List* objects;
    char gap_2C[0x0C];
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x38];
    short player_num;
    short gap_3E;
    RGE_Player** players;
};

class Trade_Avail {
public:
    RGE_Player* player;
    RGE_Static_Object* dock;
    float inventory;
};

class TRIBE_Player : public RGE_Player {
public:
    void interface_trade_avail(Trade_Avail** out_trade, short* out_count);
};

void TRIBE_Player::interface_trade_avail(Trade_Avail** out_trade,
                                          short* out_count)
{
    int i = 1;
    int dock_count = 0;
    RGE_Static_Object* dock_list[96];

    if (i < this->world->player_num) {
        do {
            if (i != this->id) {
                RGE_Object_Node* node = this->world->players[i]->objects->list;
                if (node != 0) {
                    RGE_Static_Object** output = dock_list + dock_count + 1;
                    do {
                        if (node->node->master_obj->id == 0x2D) {
                            if (this->visible->get_visible(
                                    (short)node->node->world_x,
                                    (short)node->node->world_y)) {
                                ++dock_count;
                                *output = node->node;
                                ++output;
                            }
                        }
                        node = node->next;
                    } while (node != 0);
                }
            }
            ++i;
        } while (i < this->world->player_num);
    }

    if (*out_trade != 0) {
        free(*out_trade);
        *out_trade = 0;
    }

    *out_count = (short)dock_count;
    if (dock_count != 0) {
        *out_trade = (Trade_Avail*)calloc(dock_count, 0x0C);
        if (dock_count > 0) {
            RGE_Static_Object** input = dock_list + 1;
            Trade_Avail* output = *out_trade;
            int count = dock_count;
            do {
                ++output;
                RGE_Static_Object* dock = *input;
                ++input;
                --count;
                output[-1].player = dock->owner;
                output[-1].dock = dock;
                output[-1].inventory = dock->attribute_amount_held;
            } while (count != 0);
        }
    }
}
