// VA: 0046E4B0 RGE_Player::RGE_Player(int, RGE_Game_World *, unsigned char)
// PDB source: player.cpp, lines 91-167
//
// Attempt log:
// - Baseline was the pre-existing partial tile-list scaffold (structural
//   mismatch; 19 rge_read calls and all allocation/lifetime work were absent).
// - Restored the binary-backed constructor ownership: embedded tile lists,
//   doppelganger creator, relation/name/attribute allocations, serialized
//   fields, and the final checksum reset.  The source follows the natural
//   player.cpp load/constructor family rather than raw offset plumbing.
// - The exact RGE_Tile_List destructor declaration is required: it restores
//   the original 0xC EH frame, saved-this home, EBX pathing pointer, and full
//   661-byte constructor shape.  A named pathing-cap value plus persistent
//   pointer also reproduces the accumulator global load and final read ABI.
// - Positive save-version guard reproduces the oracle's jne-to-zero,
//   fallthrough-read topology.  Current best is same size/frame/instructions,
//   all 28 ordered calls and 36/36 relocation identities, with 12 bytes left
//   in one prologue scheduling hunk: original `mov ecx,esi; state=1; store
//   pathing; store world`, rebuilt `store world; mov ecx,esi; state=1; store
//   pathing`.  Leave this readable candidate in scratch for the next worker.
// - Reordered the natural pathing-cap and world assignments to match the
//   decompiler-supported source order.  This moved the rebuilt pathing store
//   before the call setup and reduced strict drift from 12 to 9 bytes; VC5
//   still schedules `mov ecx,esi; state=1` after that store.

#include <stdlib.h>

void rge_read(int file, void* buffer, int size);

extern int pathingCapValue;
extern float save_game_version;
extern float DAT_00570e90;

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;

    RGE_Tile_List(int max_tiles);
    ~RGE_Tile_List();
};

class RGE_Player;

class RGE_Doppleganger_Creator {
public:
    RGE_Player* owner;
    int allocated_size;
    int active_size;
    void* Objects;
    void* Map_Addresses;
    void* Last_Map_Value;
    void* Object_ids;

    RGE_Doppleganger_Creator(RGE_Player* player, int max_count);
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap_21[1];
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49[1];
    short id;
    short attribute_num;
    unsigned char gap_4E[2];
    float* attributes;
    unsigned char culture;
    unsigned char gap_55[3];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    unsigned char game_status;
    unsigned char resigned;
    unsigned char gap_82[2];
    unsigned char* relations;
    int unitDiplomacy[9];
    char gap_AC[0x54];
    int allied_LOS_Enable;
    unsigned char allied_victory;
    unsigned char master_player_id;
    unsigned char gap_106[2];
    void* color_table;
    char gap_10C[4];
    void* VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;

    RGE_Player(int file, RGE_Game_World* world_arg, unsigned char player_id);
    void reset_selected();
    void set_color_table(unsigned char table);
};

RGE_Player::RGE_Player(int file, RGE_Game_World* world_arg,
                       unsigned char player_id)
    : computerPlayerValue(0), pathingAttemptCapValue(5),
      pathingDelayCapValue(10), tile_list(400), diam_tile_list(400) {
    register int* pathing = &this->pathingAttemptCapValue;
    int pathing_cap = pathingCapValue;

    this->id = player_id;
    *pathing = pathing_cap;
    this->world = world_arg;
    this->reset_selected();

    this->doppleganger_creator =
        new RGE_Doppleganger_Creator(this, 100);

    this->relations = (unsigned char*)calloc(
        1, (int)this->world->player_num);
    rge_read(file, this->relations, (int)this->world->player_num);
    rge_read(file, this->unitDiplomacy, 0x24);

    if (save_game_version >= DAT_00570e90) {
        rge_read(file, &this->allied_LOS_Enable, 4);
    } else {
        this->allied_LOS_Enable = 0;
    }

    rge_read(file, &this->allied_victory, 1);

    short name_length;
    rge_read(file, &name_length, 2);
    if (name_length > 0) {
        this->name = (char*)calloc((int)name_length, 1);
        rge_read(file, this->name, (int)name_length);
    } else {
        this->name = 0;
    }

    rge_read(file, &this->attribute_num, 2);
    if (this->attribute_num > 0) {
        this->attributes = (float*)calloc((int)this->attribute_num, 4);
        rge_read(file, this->attributes, (int)this->attribute_num << 2);
    } else {
        this->attributes = 0;
    }

    rge_read(file, &this->view_x, 4);
    rge_read(file, &this->view_y, 4);
    rge_read(file, &this->map_x, 2);
    rge_read(file, &this->map_y, 2);
    rge_read(file, &this->culture, 1);
    rge_read(file, &this->master_player_id, 1);
    rge_read(file, &this->game_status, 1);
    rge_read(file, &this->resigned, 1);

    unsigned char table;
    rge_read(file, &table, 1);
    this->set_color_table(table);

    rge_read(file, pathing, 4);
    rge_read(file, &this->pathingDelayCapValue, 4);

    this->checksum_created_this_update = 0;
    this->checksum = 0;
}
