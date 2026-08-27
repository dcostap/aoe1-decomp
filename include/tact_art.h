#ifndef AOE1_TACT_ART_H
#define AOE1_TACT_ART_H

// Declaration surface for C:\\msdev\\work\\age1_x1\\tact_art.cpp.

class RGE_Action_Object;
class RGE_Action_List;
class RGE_Color_Table;
class RGE_Game_World;
class RGE_Map;
class RGE_Master_Static_Object;
class RGE_Object_Node;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class TDrawArea;
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
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
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
public:
    virtual ~RGE_Action_Object();
    virtual void work2(RGE_Static_Object*, float, float, float,
                       unsigned char);
    virtual void set_task(short);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x10];
    short player_num;
    char gap_3E[2];
    union {
        RGE_Player** master_players;
        RGE_Player** players;
    };
    char gap_44[0x40];
    float world_time_delta_seconds;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Task {
public:
    char gap_00[0x34];
    RGE_Sprite* move_sprite;
};

class RGE_Action_List {
public:
    virtual void create_action();
    virtual void create_task_action();
    virtual unsigned char inside_obj_update();
    virtual unsigned char update();
    virtual void get_action_name();
    virtual void copy_obj();
    virtual void copy_obj_sprites();
    virtual ~RGE_Action_List();
    void delete_list();
    void add_action(class RGE_Action* action);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int file, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int file);
    virtual short type();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual unsigned char attack_response(RGE_Static_Object* object);
    virtual unsigned char relation_response(long player, unsigned char relation);
    virtual void copy_obj(void* master_action);
    virtual void copy_obj_sprites(void* master_action, RGE_Task* task1, RGE_Task* task2);
    virtual void get_state_name(char* name);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char state);

    union {
        short action_type;
        short field_04;
    };
    char gap_06[2];
    RGE_Action_Object* object;
    unsigned char state;
    char gap_0D[3];
    union {
        RGE_Static_Object* target_obj;
        RGE_Static_Object* target;
        RGE_Static_Object* field_10;
    };
    RGE_Static_Object* target_obj2;
    int target_id;
    int target2_id;
    union {
        float target_x;
        float move_x;
        float field_20;
    };
    union {
        float target_y;
        float move_y;
        float field_24;
    };
    union {
        float target_z;
        float move_z;
        float field_28;
    };
    float timer;
    RGE_Task* task;
    union {
        RGE_Action_List* sub_actions;
        RGE_Action_List* action_list;
    };
    RGE_Sprite* sprite;
    unsigned char sub_action_value;
    char gap_3D[3];

    RGE_Action(int id, RGE_Action_Object* object, int flag);
    RGE_Action(RGE_Action_Object* object, int do_setup);
    RGE_Action(int file, int flag);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;
    RGE_Action_Move_To(RGE_Action_Object* object, float x, float y, float z,
        float speed, RGE_Sprite* sprite);
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    virtual ~TRIBE_Action_Artifact();
    TRIBE_Action_Artifact(int id, RGE_Action_Object* object);
    TRIBE_Action_Artifact(RGE_Action_Object* object, RGE_Task* task,
        RGE_Static_Object* target);
    TRIBE_Action_Artifact(RGE_Action_Object* file, RGE_Task* task,
        float x, float y, float z);
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char update();
    void reset_owner();

protected:
    virtual void set_state(unsigned char state);
    virtual int stop();
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    RGE_Player* check_ownership();
};

#endif
