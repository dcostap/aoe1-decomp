#ifndef T_B_OBJ_CONTEXT_H
#define T_B_OBJ_CONTEXT_H

// Canonical local surface for the PDB module t_b_obj.cpp.
//
// The source owners in this module were recovered as separate function
// experiments.  This header provides one period-plausible class and object
// surface so the PDB-ordered owners can compile as one translation unit.
// Field names retain the proven offsets used by the owners.  The header does
// not add a synthetic function, vtable write, or register-control construct.

typedef unsigned char uchar;

class RGE_Player;
class RGE_Game_World;
class RGE_Static_Object;
class RGE_Map;
class RGE_Tile;
class RGE_Object_List;
class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Master_Static_Object;
class TRIBE_Master_Building_Object;
class TRIBE_Building_Object;
class TRIBE_Destructables;
class TRIBE_Doppleganger_Creator;
class TRIBE_Resource_Manager;
class TRIBE_Owner;
class TRIBE_Player_Tech;
// Original damage symbols use the struct tag.
struct RGE_Armor_Weapon_Info;
class RGE_Sound;
class RGE_Sprite;
class TDrawArea;
class RGE_Color_Table;

class Attribute_Cost {
public:
    short type;
    short amount;
    uchar flag;
    uchar pad;
};

class Production_Queue_Record {
public:
    short master_id;
    short unit_count;
    operator short() const { return master_id; }
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x10 - 0x04];
    short id;                                 // +0x10
    short task_id;
    char gap_12[0x26 - 0x12];
    short build_rate;                         // +0x26
    char gap_28[0x15A - 0x28];
    union {
        short build_points;                   // +0x15A
        short word_15A;
        short build_pts_required;
        short value_15A;
        short build_time;
    };
    char gap_15C[0x164 - 0x15C];
    RGE_Sound* completion_sound;              // +0x164
    union { int field_168; int action_value; };
    union { unsigned char field_16C; unsigned char connect_flag; unsigned char terrain_restriction; };
    union { unsigned char gather_flag_copy; unsigned char pad_16D; };
    unsigned char play_animation_flag;        // +0x16E
    unsigned char pad_16F;
    short terrain_1;                          // +0x170
    short terrain_2;                          // +0x172
    short building_facet;                     // +0x174
    char gap_176[2];
    short tech_id;                             // +0x178
    short passable_terrain;                   // +0x17A
    char gap_17C[0x08];
    float radius_x;                            // +0x184
    float radius_y;                            // +0x188
    char gap_18C[0x1C];
    short master_id;                           // +0x1A8 (alternate reviewed view)
    TRIBE_Doppleganger_Creator* creator;
    RGE_Sound* construction_sprite;
    short attrs[3];
    float amts[3];
    uchar modes[3];
    short value_60;
    short object_group;
    Attribute_Cost build_inventory[3];
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
};

class TRIBE_Master_Building_Object : public RGE_Master_Static_Object {
public:
    float footprint_x;                        // local view used by terrain code
    float footprint_y;
    char tail[0x20];
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
};

typedef TRIBE_Master_Building_Object BuildingMaster;
typedef TRIBE_Master_Building_Object Master;

class TRIBE_Doppleganger_Creator {
public:
    int add_doppleganger_check(RGE_Static_Object*, unsigned long*);
    int remove_doppleganger_check(TRIBE_Building_Object*);
};
typedef TRIBE_Doppleganger_Creator RGE_Doppleganger_Creator;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, uchar);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(int, int);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(int);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(
        RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);

    union {
        long id;                               // +0x04
        TRIBE_Resource_Manager* pManager;      // alternate attribute view
    };
    union {
        TRIBE_Master_Building_Object* master_obj; // +0x08
        TRIBE_Master_Building_Object* master;
        void* obj_info;
        void* object_info;
    };
    RGE_Player* owner;                          // +0x0C
    char gap_10[0x20];
    union {
        float hp;                               // +0x30
        float progress;
    };
    char gap_34[0x01];
    union {
        uchar facet;                            // +0x35
        uchar field_35;
        uchar terrain_restriction;
        uchar selected;
    };
    char gap_36[2];
    float world_x;                              // +0x38
    float world_y;                              // +0x3C
    float world_z;                              // +0x40
    char gap_44[4];
    union {
        uchar object_state;                     // +0x48
        uchar status;
        uchar field_48;
    };
    RGE_Game_World* world;
    char gap_4D[0x3B];

    void removeAllFromPathingGroup();
};

typedef RGE_Static_Object TRIBE_Static_Object;

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_88[0xF8];
    virtual ~RGE_Moving_Object();
    void set_angle();
    virtual void rotate(long);
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    char gap_180[0x14];
    uchar waiting;
    char pad_181[3];
    RGE_Action_List* actions;                   // +0x184
    virtual ~RGE_Action_Object();
    virtual void rehook();
    virtual void set_task(short);
    virtual void recycle_out_of_game();
    virtual void destroy_obj();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void save(int);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void transform(RGE_Master_Static_Object*);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    char gap_194[0x30];
    virtual ~RGE_Combat_Object();
    virtual uchar heal(float);
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void stop();
    virtual uchar update();
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    char gap_1C4[4];
    virtual ~TRIBE_Combat_Object();
    TRIBE_Combat_Object(TRIBE_Master_Building_Object*, RGE_Player*, float, float, float, int);
    TRIBE_Combat_Object(int, RGE_Game_World*, int);
    void change_ownership(RGE_Player*);
    void modify(float, uchar);
    void transform(RGE_Master_Static_Object*);
    int setup(int, RGE_Game_World*, int);
    int setup(int, RGE_Game_World*);
    int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    void save(int);
    uchar heal(float);
    uchar update();
    virtual void cancel_object();
    void empty_production_queue();
    void update_production_queue();
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    char gap_04[4];
    RGE_Static_Object* find_by_master_id(long, float, float, uchar, uchar, RGE_Static_Object*);
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    int width;
    int height;
    char gap_10[0x8D8C - 0x10];
    union {
        RGE_Tile** tile_data;
        RGE_Tile** row_lists;
    };
    void set_terrain(RGE_Player*, RGE_Game_World*, int, int, long, long, uchar, uchar, int);
    void request_redraw(int, int, int, int, uchar);
};
typedef RGE_Map GameMap;

class RGE_Tile {
public:
    char gap_00[5];
    uchar terrain;
    char gap_06[18];
    RGE_Object_List objects;
};

class TRIBE_Destructables {
public:
    void check_destructables(short, short, int, int, int);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;                               // +0x28
    char gap_2C[0x10];
    TRIBE_Destructables* destructables;         // +0x3C
    char gap_40[0x3C];
    RGE_Player** players;                       // +0x7C local view
    short map_id;
    short sound_player_id;
    TRIBE_Doppleganger_Creator* creator;
};
typedef RGE_Game_World TRIBE_World;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    union {
        RGE_Master_Static_Object** master_objects; // +0x24
        RGE_Master_Static_Object** object_infos;
    };
    RGE_Object_List* objects;                   // +0x28
    char gap_2C[0x10];
    RGE_Game_World* world;                      // +0x3C
    TRIBE_Doppleganger_Creator* doppleganger_creator; // +0x40
    char gap_44[6];
    union { short id; short player_id; };       // +0x4A
    float* attributes;                          // +0x4C local owner view
    TRIBE_Player_Tech* tech;                    // +0x50 local view
    uchar culture;
    char tail[0x1CC];
    virtual void add_attribute(short, float, int);
    virtual void give_resources(short, int, int);
    virtual uchar pay_obj_cost(short, float, int);
    virtual uchar check_obj_cost(short, short*, float, int);
    virtual void add_attribute_num(short, float, uchar);
    virtual void reimburse_obj_cost(short);
    virtual void play_sound(short, float, int);
    void unselect_one_object(RGE_Static_Object*);
    void notify_building(TRIBE_Building_Object*, int);
};

class TRIBE_Player_Tech {
public:
    uchar do_tech(short);
    uchar undo_tech(short);
};

class RGE_Master_Object : public RGE_Master_Static_Object {
public:
    void create_object(RGE_Player*, float, float, float);
};

class RGE_Sound {
public:
    void play(int);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type;                          // +0x04
    char gap_06[0x3A];
};

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    RGE_Action_Object* object;
    struct Node { RGE_Action* action; Node* next; };
    Node* list;
    virtual uchar status();
    RGE_Action* get_action();
    void delete_list();
    void action_stop();
    void add_action(RGE_Action*);
    void remove_action();
    void rehook();
    void load(int);
    void save(int);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    virtual ~TRIBE_Action_Make_Obj();
    unsigned short field_40;
    int work_done;
    int unique_id;
    uchar pre_paid;
    char gap_4D[3];
    TRIBE_Action_Make_Obj(RGE_Action_Object*, short, int, uchar);
    void get_info(short*, short*, char*, short);
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    void get_info(short*, short*, char*, short);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0xA30];
    int need_counts[256];
    long queue_is_waiting_on_pop_counter[9];
    int active_counts[16];
    void send(int, int, int, int, int);
    void notify(int, int, int, int, int);
    void notification(int, long, long, long, long);
    void v16(int, int, int, int, int);
};
extern RGE_Base_Game* rge_base_game;
extern unsigned long* unified_map_offsets[];
extern unsigned long world_update_counter;
extern int debug_random_on;
extern double DAT_005749E8;
extern float DAT_005749F4;
extern double DAT_005749F8;
extern double DAT_00574A00;
extern double DAT_00574A10;
extern float DAT_00574A08;
extern float DAT_00574A18;
extern float save_game_version;
extern float DAT_005749f4;
extern double DAT_005749f8;
extern double DAT_00574a00;
extern double DAT_00574a10;
extern float DAT_00574a08;
extern float DAT_00574a18;
extern "C" int debug_rand(char*, int);
extern "C" void debug_srand(char*, int, int);
extern "C" void rge_write(int, void*, int);
extern "C" void rge_read(int, void*, int);
extern "C" void free(void*);
extern "C" void* calloc(unsigned int, unsigned int);

class TRIBE_Resource_Manager { public: char gap_00[0x88]; };
class TRIBE_Owner : public RGE_Player { };
typedef RGE_Base_Game TRIBE_Game;
typedef TRIBE_Combat_Object TRIBE_Combat_Object_Base;

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    union {
        Production_Queue_Record* production_queue; // +0x1C8
        Production_Queue_Record* production_queue_1c8;
    };
    union { short production_queue_size; short production_queue_size_1cc; };
    union { short production_queue_count; short production_queue_count_1ce; short field_1CE; };
    union { uchar production_queue_enabled; uchar field_1D0; };
    char gap_1D1[3];
    union {
        RGE_Action_List* production_queue_actions; // +0x1D4
        RGE_Action_List* action_list_1d4;
        RGE_Action_List* member_1D4;
    };
    uchar production_queue_change_flag;          // +0x1D8
    uchar production_queue_enabled_1d0;
    uchar production_queue_change_flag_1d8;
    uchar production_queue_auto_paused;          // +0x1D9
    uchar production_queue_auto_paused_1d9;
    union { short production_queue_need_attr; short production_queue_need_attr_1da; short need_attr; };
    float build_pts;                             // +0x1DC
    int unique_build_id;                         // +0x1E0
    uchar culture;                               // +0x1E4
    uchar built;                                 // +0x1E5
    char gap_1E6[2];
    union { int DoppleInstalled; int dopple_installed; };
    unsigned long PriorMap1;
    unsigned long PriorMap2;
    unsigned long PriorMap3;
    long PriorTurn1;
    long PriorTurn2;
    long PriorTurn3;
    union { RGE_Player* owner_player; void* some_ptr; };
    RGE_Action_List* action_list;
    int field_10;
    int object_type;
    uchar type;
    int tile_y;
    int tile_x;
    float field_30;
    float x;
    float y;
    RGE_Master_Static_Object* ptr_08;
    RGE_Master_Static_Object* ptr_10;
    uchar status_field;
    unsigned long prior_map_val;

    virtual ~TRIBE_Building_Object();
    TRIBE_Building_Object(TRIBE_Master_Building_Object*, RGE_Player*, float, float, float, int, int);
    TRIBE_Building_Object(TRIBE_Master_Building_Object*, RGE_Player*, float, float, float, int);
    TRIBE_Building_Object(int, RGE_Game_World*, int);

// Original symbols define both overloads as protected virtual methods.
protected:
    virtual int setup(TRIBE_Master_Building_Object*, RGE_Player*, float, float, float);
    virtual int setup(int, RGE_Game_World*);

public:
    void recycle_out_of_game();
    virtual void take_building_attribute_from_owner();
    virtual void give_building_attribute_to_owner();
    void destroy_obj();
    uchar heal(float);
    void set_object_state(uchar);
    void rehook();
    uchar update();
    int explore_terrain(RGE_Player*, uchar, int);
    void save(int);
    void change_ownership(RGE_Player*);
    void modify(float, uchar);
    void transform(TRIBE_Master_Building_Object*);
    long check(TRIBE_Building_Object**);
    void connect();
    void connect2();
    void lay_down_impassable_terrain();
    void lay_down_passable_terrain();
    void cancel_object();
    void cancel_build();
    uchar build(float);
    int work_status(short&, short&, short&, char*, short);
    short get_construction_progress();
    void copy_obj(RGE_Master_Static_Object*);
    virtual void rotate(long);
    void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    void add_to_production_queue(short, short);
    void remove_from_production_queue(short, short);
    void advance_production_queue();
    void empty_production_queue();
    void enable_production_queue(int);
    void update_production_queue();
    int production_queue_status(short&, short&);
    void stop();
    void set_status(int);
    RGE_Action_List* create_action_list();
};

#endif
