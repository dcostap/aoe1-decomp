#ifndef MISL_OBJ_MODULE_CONTEXT_H
#define MISL_OBJ_MODULE_CONTEXT_H

class RGE_Master_Static_Object {
public:
    char gap_00[0x30];
    float radius_x;
    float radius_y;
    float radius_z;
};

class RGE_Game_World;
class RGE_Map;
class RGE_Player;
class RGE_Static_Object;
class RGE_Tile;
struct RGE_Object_Node;
class RGE_Action_List;

class RGE_Map_Info {
public:
    char gap_00[8];
    int width;
    int height;
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void rehook();
};

class RGE_Static_Object : public RGE_Action_Object {
public:
    virtual void static_pad_01();
    virtual void static_pad_02();
    virtual void static_pad_03();
    virtual void static_pad_04();
    virtual void static_pad_05();
    virtual void static_pad_06();
    virtual void static_pad_07();
    virtual void static_pad_08();
    virtual void static_pad_09();
    virtual void static_pad_10();
    virtual void static_pad_11();

    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    union {
        float world_x;
        float x;
    };
    union {
        float world_y;
        float y;
    };
    union {
        float world_z;
        float z;
    };
};

class RGE_Combat_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(void*, void*, float, float, float, int);
    RGE_Combat_Object(int, RGE_Game_World*, int);
    void save(int);
    unsigned char update();
};

class RGE_Check_List;

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    virtual float move_to(float, float, float);
    virtual void missile_pad_14();
    virtual void missile_pad_15();
    virtual void missile_pad_16();
    virtual void missile_pad_17();
    virtual void missile_pad_18();
    virtual void missile_pad_19();
    virtual void missile_pad_20();
    virtual void missile_pad_21();
    virtual void missile_pad_22();
    virtual void missile_pad_23();
    virtual void missile_pad_24();
    virtual void missile_pad_25();
    virtual void missile_pad_26();
    virtual void destroy();

    char gap_44[0x4C];
    float dx;
    float dy;
    float dz;
    char gap_9C[0xE8];
    RGE_Action_List* action_list;
    char gap_188[0x3C];
    float max_range;

    RGE_Missile_Object(void*, void*, float, float, float, int);
    RGE_Missile_Object(int, RGE_Game_World*, int);
    int setup(void*, void*, float, float, float);
    int setup(int, void*);
    int setup(int, RGE_Game_World*);
    void rehook();
    void save(int);
    unsigned char update();
    void init_missile(RGE_Combat_Object*, float, float, float, float);
    void init_missile(RGE_Combat_Object*, RGE_Static_Object*, float);
    int missile_move();
    void* scalar_deleting_destructor(unsigned int);
    void parent_destroy();
    RGE_Check_List* make_object_collision_list(float);
};

struct RGE_Check_Node {
    RGE_Static_Object* object;
    float dx;
    float dy;
    unsigned char flag;
    unsigned char gap_0D[3];
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;
    RGE_Check_List();
    ~RGE_Check_List();
    void add_node(RGE_Static_Object*, float, float, unsigned char);
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
};

struct RGE_Object_Node {
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Tile {
public:
    char gap_00[0x0C];
    RGE_Object_List objects;
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
    char gap_10[0x8D8C - 0x10];
    RGE_Tile** map_row_offset;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    union {
        RGE_Map* map;
        RGE_Map_Info* map_info;
    };
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Action_Missile : public RGE_Action_Object {
public:
    char pad[0x50];
    ~RGE_Action_Missile();
    RGE_Action_Missile(RGE_Action_Object*, RGE_Combat_Object*, int,
                       float, float, float);
    RGE_Action_Missile(RGE_Action_Object*, RGE_Combat_Object*,
                       RGE_Static_Object*, float, float, float);
};

class RGE_Action_List {
public:
    int some_field;
    void add_action(RGE_Action_Object*);
};

#endif
