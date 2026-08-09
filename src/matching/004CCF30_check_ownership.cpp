// VA: 004CCF30 TRIBE_Action_Artifact::check_ownership
// tact_art.cpp lines 168-224

// attempt 1: replaced the old raw decompiler cursor/absolute-address pass
// with named action-object, master-object, player/world/map, tile, and list
// ownership.  The binary proves four float-to-long coordinate conversions,
// a player-count byte array, clipped nested tile scans, and a unique-owner
// lookup; this is the clean natural baseline before codegen tuning.
// attempt 2: declared best_player before unique_owner so VC5 initializes the
// -1 ESI sentinel before the zero EBX counter, matching the scan prologue.
// attempt 3: used the binary-proven positive byte test (`> 0`) rather than
// `!= 0`, reproducing the oracle's unsigned jbe branch without changing the
// natural owner-count semantics.
// Status: exact under the default VC5 flags.

#include <stdlib.h>
#include <string.h>

extern float DAT_00574f10;
extern float DAT_00574f14;

class RGE_Action_Object;
class RGE_Action_List;
class RGE_Game_World;
class RGE_Map;
class RGE_Master_Static_Object;
class RGE_Object_Node;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Tile;

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    char gap_0A[2];
};

class RGE_Object_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    char gap_0D[3];
};

class RGE_Tile {
public:
    char gap_00[0x0C];
    RGE_Object_List objects;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x10];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    char gap_16[0x1A];
    float radius_x;
    float radius_y;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x20];
    float hit_points;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Task {
public:
    char gap_00[0x34];
    RGE_Sprite* move_sprite;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type;
    char gap_06[2];
    RGE_Action_Object* object;
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int target_id;
    int target2_id;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char sub_action_value;
    char gap_3D[3];
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    RGE_Player* check_ownership();
};

RGE_Player* TRIBE_Action_Artifact::check_ownership() {
    RGE_Action_Object* obj = this->object;
    RGE_Master_Static_Object* master = obj->master_obj;

    short map_x = (short)(obj->world_x - DAT_00574f10 - master->radius_x);
    short map_y = (short)(obj->world_y - DAT_00574f10 - master->radius_y);
    short x0 = (short)(master->radius_x + obj->world_x - DAT_00574f14);
    short y0 = (short)(master->radius_y + obj->world_y - DAT_00574f14);

    RGE_Map* map = obj->owner->world->map;
    short player_num = obj->owner->world->player_num;
    unsigned char* player_list = (unsigned char*)calloc(player_num, 1);

    if (player_num > 0) {
        memset(player_list, 0, player_num);
    }

    if (map_x < 0) {
        map_x = 0;
    }
    if (map_y < 0) {
        map_y = 0;
    }
    if (x0 >= map->map_width) {
        x0 = (short)map->map_width - 1;
    }
    if (y0 >= map->map_height) {
        y0 = (short)map->map_height - 1;
    }

    for (short y = map_y; y <= y0; ++y) {
        for (short x = map_x; x <= x0; ++x) {
            RGE_Object_Node* node = map->map_row_offset[y][x].objects.list;
            while (node != 0) {
                RGE_Static_Object* entity = node->object;
                short type = entity->master_obj->object_group;
                if (type != 1 && type != 0x0B && type != 0x1E && entity->object_state == 2) {
                    ++player_list[entity->owner->id];
                }
                node = node->next;
            }
        }
    }

    short best_player = -1;
    short unique_owner = 0;
    for (short player = 1; player < player_num; ++player) {
        if (player_list[player] > 0) {
            ++unique_owner;
            best_player = player;
        }
    }

    free(player_list);

    if (unique_owner == 1 && best_player > 0) {
        RGE_Player* owner = this->object->owner;
        if (best_player != owner->id) {
            return owner->world->players[best_player];
        }
    }
    return 0;
}
