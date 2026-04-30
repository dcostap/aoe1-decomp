// RGE_Victory_Conditions::save
// VA: 00531B70
// victory.cpp

struct RGE_Player {
    char gap_00[0x4A];
    short id;                 // +0x4A
};

struct RGE_Master_Object {
    char gap_00[0x12];
    short copy_id;           // +0x12
};

struct RGE_Static_Object {
    char gap_00[4];
    long id;                  // +0x04
    RGE_Master_Object* master_obj; // +0x08
    RGE_Player* owner;        // +0x0C
};

struct RGE_Victory_Entry {
    unsigned char command;    // +0x00
    char gap_01[3];
    long obj_type;            // +0x04
    RGE_Player* target_player; // +0x08
    float x0;                 // +0x0C
    float y0;                 // +0x10
    float x1;                 // +0x14
    float y1;                 // +0x18
    long number;              // +0x1C
    long count;               // +0x20
    RGE_Static_Object* this_obj; // +0x24
    RGE_Static_Object* target_obj; // +0x28
    unsigned char victory_group; // +0x2C
    unsigned char ally_flag;  // +0x2D
    unsigned char state;      // +0x2E
    char gap_2F;
    RGE_Victory_Entry* next;  // +0x30
};

struct RGE_Victory_Point_Entry {
    unsigned char command;    // +0x00
    unsigned char state;      // +0x01
    unsigned char id;         // +0x02
    unsigned char group;      // +0x03
    long attribute;           // +0x04
    long amount;              // +0x08
    long points;              // +0x0C
    long curr_points;         // +0x10
    float curr_attribute_amount; // +0x14
    RGE_Victory_Point_Entry* next; // +0x18
};

class RGE_Victory_Conditions {
public:
    void* vftable;            // +0x00
    RGE_Victory_Entry* victory_list; // +0x04
    long list_num;            // +0x08
    RGE_Player* player;       // +0x0C
    unsigned char victory;    // +0x10
    char gap_11[3];
    RGE_Victory_Point_Entry* victory_point_list; // +0x14
    long point_list_num;      // +0x18
    long tot_victory_points;  // +0x1C

    void save(int param_1);
};

extern "C" void rge_write(int param_1, void* data, int size);

void RGE_Victory_Conditions::save(int param_1) {
    float version = 1.0f;

    rge_write(param_1, &version, 4);
    rge_write(param_1, &this->list_num, 4);
    rge_write(param_1, &this->victory, 1);

    for (RGE_Victory_Entry* entry = this->victory_list; entry != 0; entry = entry->next) {
        long target_player_id;
        long target_obj_id;
        float version_field;

        if (entry->target_player == 0) {
            target_player_id = -1;
        } else {
            target_player_id = entry->target_player->id;
        }

        if (entry->this_obj == 0) {
            target_obj_id = -1;
        } else {
            target_obj_id = entry->this_obj->id;
        }

        if (entry->target_obj == 0) {
            version_field = -1.0f;
        } else {
            version_field = (float)entry->target_obj->id;
            target_player_id = entry->target_obj->owner->id;
        }

        rge_write(param_1, entry, 1);
        rge_write(param_1, &entry->obj_type, 4);
        rge_write(param_1, &target_player_id, 4);
        rge_write(param_1, &entry->x0, 4);
        rge_write(param_1, &entry->y0, 4);
        rge_write(param_1, &entry->x1, 4);
        rge_write(param_1, &entry->y1, 4);
        rge_write(param_1, &entry->number, 4);
        rge_write(param_1, &entry->count, 4);
        rge_write(param_1, &target_obj_id, 4);
        rge_write(param_1, &version_field, 4);
        rge_write(param_1, &entry->victory_group, 1);
        rge_write(param_1, &entry->ally_flag, 1);
        rge_write(param_1, &entry->state, 1);
    }

    rge_write(param_1, &this->tot_victory_points, 4);
    rge_write(param_1, &this->point_list_num, 4);

    for (RGE_Victory_Point_Entry* point = this->victory_point_list; point != 0; point = point->next) {
        rge_write(param_1, point, 1);
        rge_write(param_1, &point->state, 1);
        rge_write(param_1, &point->attribute, 4);
        rge_write(param_1, &point->amount, 4);
        rge_write(param_1, &point->points, 4);
        rge_write(param_1, &point->curr_points, 4);
        rge_write(param_1, &point->id, 1);
        rge_write(param_1, &point->group, 1);
        rge_write(param_1, &point->curr_attribute_amount, 4);
    }
}
