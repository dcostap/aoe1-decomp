// RGE_Action_Transport::next_to_drop_off_terrain
// VA: 004072B0
// PDB: act_tran.cpp:392-462
//
// Attempt log:
// - Replaced the decompiler cursor/absolute-offset scaffold with the typed
//   action-object, master-object, player/world/map, task, and terrain surfaces
//   established by the act_tran.cpp siblings and generated layout evidence.
// - Corrected the inherited action gap to keep target_x/task at 0x20/0x30;
//   source then differed only in the two upper-bound compare operand orders.
// - Spelled both clamps as `upper >= limit`, matching the original cmp/jl and
//   producing exact bytes; natural virtual class surfaces preserve the match.

extern float DAT_0056e6c8;
extern float DAT_0056e6cc;

class RGE_Sprite;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x2C];
    float radius_x;
    float radius_y;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    long map_width;
    long map_height;

    unsigned char get_terrain(short x, short y);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    unsigned char lookupZone(int x, int y);
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    unsigned char gap_05;
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char gap_10[0x24];
    RGE_Sprite* move_sprite;
};

class RGE_Action {
public:
    virtual ~RGE_Action();

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x13];
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    void* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    char gap_3D[3];
};

class RGE_Action_Transport : public RGE_Action {
public:
    int targetZone(void);
    virtual int next_to_drop_off_terrain(void);
};

int RGE_Action_Transport::next_to_drop_off_terrain(void)
{
    if (this->task != 0 && this->task->terrain_id == -1) {
        return 1;
    }

    int x1 = (int)(this->obj->world_x - this->obj->master_obj->radius_x - DAT_0056e6c8);
    int y1 = (int)(this->obj->world_y - this->obj->master_obj->radius_y - DAT_0056e6c8);
    int x2 = (int)(this->obj->master_obj->radius_x + this->obj->world_x - DAT_0056e6cc);
    int y2 = (int)(this->obj->master_obj->radius_y + this->obj->world_y - DAT_0056e6cc);

    RGE_Map* map = this->obj->owner->world->map;

    if (x1 < 0) {
        x1 = 0;
    }
    if (x2 >= map->map_width) {
        x2 = map->map_width - 1;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (y2 >= map->map_height) {
        y2 = map->map_height - 1;
    }

    int target_zone = this->targetZone();
    // The transport sentinel is tested as its stored dword in the original
    // source; keep the proven bitwise -1.0f test rather than an x87 compare.
    if (*(int*)&this->target_x != 0xBF800000) {
        target_zone = (int)this->obj->lookupZone(
            (int)this->target_x,
            (int)this->target_y
        );
    }

    for (int y = y1; y <= y2; ++y) {
        for (int x = x1; x <= x2; ++x) {
            if (target_zone == -1 || this->obj->lookupZone(x, y) == target_zone) {
                if (map->get_terrain((short)x, (short)y) == 2 ||
                    map->get_terrain((short)x, (short)y) == 4) {
                    return 1;
                }
            }
        }
    }

    return 0;
}
