// VA: 0046E770 RGE_Player::RGE_Player
// PDB source: player.cpp, lines 177-274
//
// Attempt log:
// - Baseline was the partial tile-list scaffold; it omitted the constructor's
//   object ownership, master/attribute copies, map setup, and effect dispatch.
// - Restored the period-plausible RGE_Player constructor family using the
//   proven field ownership and helper ABIs from the adjacent player.cpp
//   constructors/destructor.  Full ownership reconstruction reached the
//   original 897-byte size, 22 ordered calls, CFG, frame, and relocation set.
// - Reversed the positive/zero object-allocation source arms to reproduce the
//   oracle's forward `je` to the late zero-store block.
// - Used the incoming `world` parameter for the visible-map constructor; the
//   oracle reloads `[esp+24]` there rather than `this->world`.
// - Initializer-list reordering, cast/long constants, a register pathing
//   pointer, a named pathing-cap local, and `<memory.h>` context were either
//   codegen duplicates or worse.  A 15-variant /GX lab over initializer and
//   early-field order also found no closer basin.
// - Tested a natural EH-aware alternative that assigned the scalar pathing
//   defaults in the body after embedded tile-list construction; VC5 moved the
//   prologue and worsened the positional diff from 18 to 64 bytes.  Restored
//   the member-initializer source.
// - Best validated source is 897 bytes with all 22 calls/CFG/frame exact and
//   18 positional bytes remaining.  The only localized drift is the first
//   tile-list setup: the oracle emits `push 190h; lea; save this; store +8`,
//   while VC5 emits `store +8` before that setup.  The rest of the function
//   is byte-identical after resynchronization; leave this readable candidate
//   in scratch for a later worker.
// - This claim tested initializer side effects, volatile pathing fields, an
//   empty base, and reversed scalar initializer spelling.  The side-effect
//   form worsened the drift to 50 bytes; the other forms reproduced the same
//   18-byte hunk.  The localized gap remains compiler scheduling, not ABI or
//   ownership uncertainty.
// - Follow-up claim probes: 20 distinct source, liveness, context, and flag
//   hypotheses were compiled and checked.  Scoped pathing aliases, named
//   globals, header changes, inline-depth and optimization pragmas, literal
//   types, initializer-side dependencies, and scalar body stores did not beat
//   the clean source.  All experiments were restored before final validation.
// - Revisit probes 1-13 tested the reviewed full virtual surface, canonical
//   typed Player/World/Master/Tile layouts, same-TU donor declarations, enum
//   defaults, narrow tile-count conversion, and method/data declaration order.
//   Every valid probe remained an 18-byte mismatch with the same two spans.
//   These results support a compiler scheduling or historical-TU-context
//   blocker, not an unresolved field or helper ABI.
// - Exact-finish context audit compiled the existing unregistered
//   `src/player_tu.cpp` wrapper with the reviewed full player.cpp surface and
//   /GX.  Its target body had the same 897-byte size, 22 ordered calls, EH
//   coverage, and 26 relocation sites.  After masking those relocation fields,
//   it reproduced the same 18-byte hunk.  The grouped context is therefore a
//   codegen duplicate, not a required owner; leave the wrapper unregistered.
// ACCEPTED DRIFT: The 18-byte edit moves the independent `[this+8] = 5` store
// across one tile-list argument push, LEA, and caller stack spill. No call or
// branch occurs inside the hunk, and the store completes before the same first
// tile-list constructor call in both builds. Constructor state, arguments,
// exception coverage, writes, cleanup, and all later bytes match.

#include <stdlib.h>
#include <string.h>
#include <memory.h>
#ifdef PLAYER_GROUPED_TU
#include "../../include/player_context.h"
#endif

extern "C" void __cdecl getstring(char** destination, char* source);
extern int pathingCapValue;

#ifndef PLAYER_GROUPED_TU
class RGE_Player;
class RGE_Sprite;
class RGE_Sound;

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map;
    int map_width;
    int map_height;
};

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    virtual void save(int file);
    virtual void do_effect(short effect, RGE_Player* player);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x10];
    short player_num;
    char gap_3E[0x0E];
    RGE_Effects* effects;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual RGE_Master_Static_Object* copy_obj();
};

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    char gap_04[0x14];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    short attribute_num;
    float* attributes;
    unsigned char culture;
    unsigned char gap_29;
    short tribe_effect;
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

class RGE_Object_List {
public:
    virtual void destroy();
    int list;
    short number_of_objects;

    RGE_Object_List();
    ~RGE_Object_List();
};

class RGE_Victory_Conditions {
public:
    void* vtable_ptr;
    char gap_04[0x1C];

    RGE_Victory_Conditions(RGE_Player* player);
};

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    unsigned long PlayerVisibleMaskValue;
    unsigned long PlayerVisibleMaskInvertValue;
    unsigned long PlayerExploredMaskValue;
    unsigned long PlayerExploredMaskInvertValue;
    unsigned long input_csum;

    RGE_Visible_Map(RGE_Map* map, RGE_Player* player);
};

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
    unsigned char gap_21;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49;
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
    char gap_AC[0x24];
    int mutualExploredMask;
    int mutualVisibleMask;
    int nonMutualVisibleMask;
    char gap_DC[0x24];
    int allied_LOS_Enable;
    unsigned char allied_victory;
    unsigned char master_player_id;
    unsigned char gap_106[2];
    void* color_table;
    int tribe_effect;
    void* VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    char gap_120[0x100];

    RGE_Player(RGE_Game_World* world, RGE_Master_Player* master,
               unsigned char player_id, char* player_name,
               unsigned char master_id, unsigned char is_computer);
    void reset_selected();
    void new_victory();
    void set_view_loc(float x, float y);
    void set_map_loc(short x, short y);
};
#endif

RGE_Player::RGE_Player(RGE_Game_World* world, RGE_Master_Player* master,
                       unsigned char player_id, char* player_name,
                       unsigned char master_id, unsigned char is_computer)
    : computerPlayerValue(0), pathingAttemptCapValue(5),
      pathingDelayCapValue(10), tile_list(400), diam_tile_list(400)
{
    this->pathingAttemptCapValue = pathingCapValue;
    this->master_player_id = master_id;
    this->type = 0;
    this->world = world;
    this->id = (short)player_id;
    this->reset_selected();

    this->name = 0;
    if (player_name != 0) {
        getstring(&this->name, player_name);
    }

    this->relations = (unsigned char*)calloc(1, (int)this->world->player_num);
    for (int i = 0; i < 9; ++i) {
        this->unitDiplomacy[i] = -1;
    }

    short relation_index = 0;
    if (this->world->player_num > 0) {
        do {
            this->relations[relation_index] = 1;
            if (relation_index == this->id) {
                this->unitDiplomacy[relation_index] = 1;
            } else if (relation_index == 0) {
                this->unitDiplomacy[0] = 0;
            } else {
                this->unitDiplomacy[relation_index] = 3;
            }
            ++relation_index;
        } while (relation_index < this->world->player_num);
    }

    this->mutualExploredMask = 0;
    this->mutualVisibleMask = 0;
    this->nonMutualVisibleMask = 0;
    this->allied_LOS_Enable = 0;
    this->allied_victory = 0;

    this->master_object_num = master->master_object_num;
    if (this->master_object_num > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc(
            (int)this->master_object_num, 4);
        short master_index = 0;
        if (this->master_object_num > 0) {
            do {
                if (master->master_objects[master_index] != 0) {
                    this->master_objects[master_index] =
                        master->master_objects[master_index]->copy_obj();
                }
                ++master_index;
            } while (master_index < this->master_object_num);
        }
    }

    if (is_computer != 0) {
        this->objects = new RGE_Object_List;
        this->sleeping_objects = new RGE_Object_List;
        this->doppleganger_objects = new RGE_Object_List;
        this->new_victory();
        this->visible = new RGE_Visible_Map(world->map, this);
    } else {
        this->objects = 0;
        this->sleeping_objects = 0;
        this->doppleganger_objects = 0;
        this->victory_conditions = 0;
        this->visible = 0;
    }

    this->doppleganger_creator = new RGE_Doppleganger_Creator(this, 100);

    this->attribute_num = master->attribute_num;
    if (this->attribute_num > 0) {
        this->attributes = (float*)calloc((int)this->attribute_num, 4);
        memcpy(this->attributes, master->attributes,
               (int)this->attribute_num * 4);
    } else {
        this->attributes = 0;
    }

    this->culture = master->culture;
    this->set_view_loc(
        (float)(this->world->map->map_width / 2),
        (float)(this->world->map->map_height / 2));
    this->set_map_loc(
        (short)(this->world->map->map_width / 2),
        (short)(this->world->map->map_height / 2));

    this->game_status = 0;
    this->resigned = 0;
    this->color_table = 0;
    this->tribe_effect = master->tribe_effect;
    if (is_computer != 0 && this->tribe_effect >= 0) {
        this->world->effects->do_effect((short)this->tribe_effect, this);
    }

    this->checksum = 0;
    this->checksum_created_this_update = 0;
}
