// RGE_Victory_Conditions::RGE_Victory_Conditions
// VA: 00531750
// victory.cpp
// Attempt log:
// - Replaced raw-offset scaffolding with typed player, world, object-list, entry, and point
//   ownership. The 33-call set and direct helper identities now match the executable.
// - Pointer locals for list count and list tail recover the original 0x1C frame and 920-byte
//   boundary. Saving the file handle and reusing its dead parameter home as target-player ID
//   is required for the best natural source shape.
// - BINARY NOTE: The original writes the target-player ID through the incoming handle home.
//   ESI still carries the file handle for every later read.
// - BINARY NOTE: A dword loop counter reuses the incoming version-flag home. A raw typed alias
//   recovered this stack shape, but it was not retained in the clean source.
// - Twenty tracked meaningful probes were tested. The best retained clean source has exact
//   size, frame, owner symbol, 33 ordered calls, and 506 differing bytes.
// - Remaining drift is register color, redundant guard layout, and branch scheduling. The
//   H11 diagnostic reached 500 bytes but used a non-canonical raw parameter alias.

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
    long* list_num_ptr;
    RGE_Victory_Entry** tail;
    int file_handle = handle;

    if (version_flag == 1) {
        rge_read(file_handle, &save_version, 4);
    } else {
        save_version = 0.0f;
    }

    list_num_ptr = &this->list_num;
    rge_read(file_handle, list_num_ptr, 4);
    rge_read(file_handle, &this->victory, 1);

    tail = &this->victory_list;
    *tail = 0;
    this->player = player;
    index = 0;

    while (index < *list_num_ptr) {
        RGE_Victory_Entry* entry =
            (RGE_Victory_Entry*)calloc(1, sizeof(RGE_Victory_Entry));

        rge_read(file_handle, entry, 1);
        rge_read(file_handle, &entry->obj_type, 4);
        rge_read(file_handle, &version, 4);
        rge_read(file_handle, &entry->x0, 4);
        rge_read(file_handle, &entry->y0, 4);
        rge_read(file_handle, &entry->x1, 4);
        rge_read(file_handle, &entry->y1, 4);
        rge_read(file_handle, &entry->number, 4);
        rge_read(file_handle, &entry->count, 4);
        rge_read(file_handle, &handle, 4);
        long target_object_id;
        rge_read(file_handle, &target_object_id, 4);
        rge_read(file_handle, &entry->victory_group, 1);
        rge_read(file_handle, &entry->ally_flag, 1);
        rge_read(file_handle, &entry->state, 1);

        entry->target_obj = 0;
        entry->this_obj = 0;
        entry->target_player = 0;
        *tail = entry;
        tail = &entry->next;

        if (handle >= 0) {
            int player_index = 0;
            RGE_Game_World* world = this->player->world;
            while (player_index < world->player_num) {
                entry->this_obj =
                    world->players[player_index]->objects->find_by_id(handle);
                if (entry->this_obj != 0) {
                    break;
                }
                player_index++;
                world = this->player->world;
            }
            if (handle >= 0 && entry->this_obj == 0) {
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
        long* total_points = &this->tot_victory_points;
        rge_read(file_handle, total_points, 4);
        rge_read(file_handle, &point_count, 4);

        int point_index = 0;
        while (point_index < point_count) {
            RGE_Victory_Point_Entry* point = this->add_point(0, 0);
            rge_read(file_handle, point, 1);
            rge_read(file_handle, &point->state, 1);
            rge_read(file_handle, &point->attribute, 4);
            rge_read(file_handle, &point->amount, 4);
            rge_read(file_handle, &point->points, 4);
            rge_read(file_handle, &point->curr_points, 4);
            rge_read(file_handle, &point->id, 1);
            rge_read(file_handle, &point->group, 1);
            rge_read(file_handle, &point->curr_attribute_amount, 4);

            if (*total_points < 0) {
                point->points = 0;
            }
            point_index++;
        }

        if (*total_points < 0) {
            *total_points = 0;
        }
    }
}
