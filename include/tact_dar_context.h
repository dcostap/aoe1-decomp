#ifndef AOE1_TACT_DAR_CONTEXT_H
#define AOE1_TACT_DAR_CONTEXT_H

// Canonical declaration surface for the original tact_dar.cpp module.
// The field offsets follow the action, map, player, and discovery accesses in
// the target functions.  Owner files provide the function bodies.

#include <stdlib.h>

typedef unsigned char uchar;

void rge_read(int file, void* data, int size);
void rge_write(int file, void* data, int size);

struct DiscoverySizeInfo {
    char gap_00[0x3C];
    short size;
    char gap_3E[0x44];
    float tile_width;
};

struct DiscoveryInfo {
    char gap_00[0x3C];
    DiscoverySizeInfo* size_info;
};

struct DiscoveryMaster {
    char gap_00[0x0C];
    DiscoveryInfo* info;
};

class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Tile;
class RGE_Object_Node;
class RGE_Object_List;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Master_Action_Object;
class RGE_Task;
class RGE_Sprite;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner,
                                             float x, float y, float z);

    uchar master_type;
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
    long id;
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
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(uchar);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual uchar attack_response(RGE_Static_Object*);
    virtual uchar relation_response(long, uchar);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    uchar state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    long target_id;
    long target2_id;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    uchar sub_action_value;
    char gap_3D[3];

    RGE_Action(int file_id, RGE_Action_Object* object, int do_setup);
    RGE_Action(RGE_Action_Object* object, int do_setup);
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    char* flags;

    TRIBE_Action_Discovery_Artifact(int file_id, RGE_Action_Object* object);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* object,
                                    RGE_Task* task,
                                    RGE_Static_Object* target);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* object,
                                    RGE_Task* task,
                                    float x, float y, float z);

    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual uchar update();

protected:
    virtual void set_state(uchar);
    void check_objects();
};

extern float DAT_00575078;
extern float DAT_0057507c;
extern double DAT_00575070;

typedef char tact_dar_action_abi[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_dar_discovery_abi[
    (sizeof(TRIBE_Action_Discovery_Artifact) == 0x44) ? 1 : -1];

#endif
