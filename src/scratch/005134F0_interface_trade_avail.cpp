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
// - Hoisting the owner pointer was tested for the original owner-before-store
//   order; the natural function-scope declaration is the best current basin.
// - Rolled back a saved-this array alias and a synthetic aggregate layout;
//   both worsened the prologue/block shape. Current remaining drift is two
//   one-slot dock-list LEA displacements plus late counter/owner coloring.
// - Main-agent audit restored canonical virtual ownership at unchanged offsets;
//   the validated six-byte codegen gap is unchanged.
// - New full-player/TU context probes tested dock_list[0] as the saved-player
//   overlay and moved the owner declaration; the overlay broadened drift to
//   225 bytes and the declaration move duplicated the six-byte result, so the
//   canonical function-scope owner source remains retained.
// - Reordering the counters before dock_list emitted the same six-byte result;
//   using dock_list[0] for every post-guard this access broadened drift to 246
//   bytes and was restored. Moving the transfer countdown declaration first
//   worsened the localized drift to ten bytes; the clean declaration order is
//   retained.

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
    RGE_Player* player;
    RGE_Static_Object* dock_list[96];
    int i = 1;
    int dock_count = 0;

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
                player = dock->owner;
                output[-1].dock = dock;
                output[-1].player = player;
                output[-1].inventory = dock->attribute_amount_held;
            } while (count != 0);
        }
    }
}
