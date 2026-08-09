// RGE_Victory_Conditions::RGE_Victory_Conditions
// VA: 00531750
// victory.cpp
// Attempt log:
// - Replaced the prior decompiler/raw-offset scaffold with typed player/world/object-list,
//   victory-entry, point-entry, and real add_point ownership. The while player scan removed
//   a duplicated find_by_id site and recovered the original 33-call set.
// - A diagnostic six-dword work aggregate for saved list/index/version/temp/point state
//   recovered the 0x1C frame and 920-byte size; delaying index zeroing until after list/player
//   setup recovered the prologue basin and 31.94% exact-block coverage.
// - Separate list_num pointer/register and declaration-order probes were neutral; the best
//   current typed reconstruction is 502 differing bytes with exact size/frame/call set.
// - Paused after 10 hypotheses: remaining drift is broad constructor local/register and
//   block scheduling (plus vtable relocation context), not an unresolved call or ownership
//   behavior defect. No explicit vptr or raw cross-member cursor is retained.
// - Main-agent audit removed the artificial local-window aggregate and pointer aliases.
//   Ordinary named locals and direct member ownership remain authoritative living source.

extern "C" void rge_read(int handle, void* data, int size);
extern "C" void* calloc(unsigned int count, unsigned int size);

class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_id(long id);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num; // +0x3C
    char gap_3E[2];
    RGE_Player** players; // +0x40
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects; // +0x28
    char gap_2C[0x10];
    RGE_Game_World* world; // +0x3C
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id; // +0x04
    void* master_obj; // +0x08
    RGE_Player* owner; // +0x0C
};

class RGE_Victory_Entry {
public:
    unsigned char command; // +0x00
    char gap_01[3];
    long obj_type; // +0x04
    RGE_Player* target_player; // +0x08
    float x0; // +0x0C
    float y0; // +0x10
    float x1; // +0x14
    float y1; // +0x18
    long number; // +0x1C
    long count; // +0x20
    RGE_Static_Object* this_obj; // +0x24
    RGE_Static_Object* target_obj; // +0x28
    unsigned char victory_group; // +0x2C
    unsigned char ally_flag; // +0x2D
    unsigned char state; // +0x2E
    char gap_2F;
    RGE_Victory_Entry* next; // +0x30
};

class RGE_Victory_Point_Entry {
public:
    unsigned char command; // +0x00
    unsigned char state; // +0x01
    unsigned char id; // +0x02
    unsigned char group; // +0x03
    long attribute; // +0x04
    long amount; // +0x08
    long points; // +0x0C
    long curr_points; // +0x10
    float curr_attribute_amount; // +0x14
    RGE_Victory_Point_Entry* next; // +0x18
};

class RGE_Victory_Conditions {
public:
    virtual void handle_point_condition(RGE_Victory_Point_Entry* entry);
    virtual void handle_condition(RGE_Victory_Entry* entry);
    virtual char* condition_description(RGE_Victory_Entry* entry);
    virtual void save(int handle);

    RGE_Victory_Entry* victory_list; // +0x04
    long list_num; // +0x08
    RGE_Player* player; // +0x0C
    unsigned char victory; // +0x10
    char gap_11[3];
    RGE_Victory_Point_Entry* victory_point_list; // +0x14
    long point_list_num; // +0x18
    long tot_victory_points; // +0x1C

    RGE_Victory_Point_Entry* add_point(unsigned char group, unsigned char id);
    RGE_Victory_Conditions(RGE_Player* player, int handle, long* version_map,
        unsigned char version_flag);
};

RGE_Victory_Conditions::RGE_Victory_Conditions(
    RGE_Player* player, int handle, long* version_map, unsigned char version_flag) {
    long index;
    long version;
    float save_version;
    long point_count;

    if (version_flag == 1) {
        rge_read(handle, &save_version, 4);
    } else {
        save_version = 0.0f;
    }

    rge_read(handle, &this->list_num, 4);
    rge_read(handle, &this->victory, 1);

    this->victory_list = 0;
    this->player = player;
    index = 0;

    while (index < this->list_num) {
        RGE_Victory_Entry* entry =
            (RGE_Victory_Entry*)calloc(1, sizeof(RGE_Victory_Entry));

        rge_read(handle, entry, 1);
        rge_read(handle, &entry->obj_type, 4);
        rge_read(handle, &version, 4);
        rge_read(handle, &entry->x0, 4);
        rge_read(handle, &entry->y0, 4);
        rge_read(handle, &entry->x1, 4);
        rge_read(handle, &entry->y1, 4);
        rge_read(handle, &entry->number, 4);
        rge_read(handle, &entry->count, 4);
        long target_player_id;
        rge_read(handle, &target_player_id, 4);
        long target_object_id;
        rge_read(handle, &target_object_id, 4);
        rge_read(handle, &entry->victory_group, 1);
        rge_read(handle, &entry->ally_flag, 1);
        rge_read(handle, &entry->state, 1);

        entry->target_obj = 0;
        entry->this_obj = 0;
        entry->target_player = 0;
        entry->next = this->victory_list;
        this->victory_list = entry;

        if (target_player_id >= 0) {
            int player_index = 0;
            RGE_Game_World* world = this->player->world;
            while (player_index < world->player_num) {
                entry->this_obj =
                    world->players[player_index]->objects->find_by_id(target_player_id);
                if (entry->this_obj != 0) {
                    break;
                }
                player_index++;
                world = this->player->world;
            }
            if (target_player_id >= 0 && entry->this_obj == 0) {
                entry->state = 3;
            }
        }

        if (target_object_id >= 0) {
            entry->target_obj = this->player->objects->find_by_id(target_object_id);
        }

        if (version < 0) {
            entry->target_player = 0;
        } else {
            if (version_map != 0) {
                version = version_map[version];
            }
            if (version < 0) {
                entry->state = 3;
            } else {
                RGE_Player* reference_player =
                    this->player->world->players[version];
                entry->target_player = reference_player;
                if (reference_player != 0 && entry->target_obj == 0 &&
                    target_object_id >= 0) {
                    entry->target_obj =
                        reference_player->objects->find_by_id(target_object_id);
                }
            }
        }

        if (target_object_id >= 0 && entry->target_obj == 0) {
            entry->state = 3;
        }

        index++;
    }

    this->victory_point_list = 0;
    this->point_list_num = 0;

    if (save_version < 1.0f) {
        this->tot_victory_points = 0;
    } else {
        rge_read(handle, &this->tot_victory_points, 4);
        rge_read(handle, &point_count, 4);

        int point_index = 0;
        while (point_index < point_count) {
            RGE_Victory_Point_Entry* point = this->add_point(0, 0);
            rge_read(handle, point, 1);
            rge_read(handle, &point->state, 1);
            rge_read(handle, &point->attribute, 4);
            rge_read(handle, &point->amount, 4);
            rge_read(handle, &point->points, 4);
            rge_read(handle, &point->curr_points, 4);
            rge_read(handle, &point->id, 1);
            rge_read(handle, &point->group, 1);
            rge_read(handle, &point->curr_attribute_amount, 4);

            if (this->tot_victory_points < 0) {
                point->points = 0;
            }
            point_index++;
        }

        if (this->tot_victory_points < 0) {
            this->tot_victory_points = 0;
        }
    }
}
