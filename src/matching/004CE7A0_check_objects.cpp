// check_objects: 004CE7A0, tact_dar.cpp:125-165
// Baseline: scan the clipped map area and create each foreign owner's discovery object.
// The source uses the canonical action-object, player, world, map, tile, and node ownership.
// Attempt log:
// 1: Natural typed reconstruction reached 389 bytes with a 0x20 frame; calls and CFG matched.
// 2: Restored RGE_Object_List's 0x0C layout, giving the map tile stride 0x18 and a 0x1C frame.
// 3: Kept the action-object temp only through map setup; this was a duplicate codegen basin.
// 4: Removed the entity temp and repeated node->object expressions; this reproduced the original reload and matched.
// MATCH: exact bytes under the default VC5 flags; promotion is intentionally deferred by this assignment.

extern float DAT_00575078;
extern float DAT_0057507c;

class RGE_Action_Object;
class RGE_Game_World;
class RGE_Map;
class RGE_Master_Static_Object;
class RGE_Object_Node;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Tile;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void pad04();
    virtual void pad08();
    virtual void pad0C();
    virtual void pad10();
    virtual void pad14();
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);

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

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x14];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
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

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    char gap_0A[2];
};

class RGE_Tile {
public:
    char gap_00[0x0C];
    RGE_Object_List objects;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_Node* next;
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
    void* task;
    void* sub_actions;
    RGE_Sprite* sprite;
    unsigned char sub_action_value;
    char gap_3D[3];
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    char* flags;

    void check_objects();
};

void TRIBE_Action_Discovery_Artifact::check_objects() {
    RGE_Action_Object* obj = this->object;
    RGE_Master_Static_Object* master = obj->master_obj;

    short map_x = (short)(obj->world_x - DAT_00575078 - master->radius_x);
    short map_y = (short)(obj->world_y - DAT_00575078 - master->radius_y);
    short x0 = (short)(master->radius_x + obj->world_x - DAT_0057507c);
    short y0 = (short)(master->radius_y + obj->world_y - DAT_0057507c);

    RGE_Map* map = obj->owner->world->map;

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
                if (node->object->owner != this->object->owner &&
                    this->flags[node->object->owner->id] == 0) {
                    this->flags[node->object->owner->id] = 1;
                    node->object->owner->master_objects[162]->make_new_obj(
                        node->object->owner,
                        node->object->world_x,
                        node->object->world_y,
                        node->object->world_z);
                }
                node = node->next;
            }
        }
    }
}
