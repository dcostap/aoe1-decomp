#ifndef TACT_WND_CONTEXT_H
#define TACT_WND_CONTEXT_H

// Canonical declaration surface for the original tact_wnd.cpp module.
//
// The target action uses the period RGE_Action virtual order.  The object
// calls at slots +D8 and +DC are the inherited explore/unexplore methods.
// Fields use the addresses proved by tact_wnd.cpp: action object +08, state
// +0C, timer +2C, player id +4A, world player data +3C/+40, and the base-game
// world pointer +3F4.

typedef unsigned char uchar;

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Node;
class RGE_Action_Object;
class RGE_Game_World;
class RGE_Master_Object;
class RGE_Player;
class RGE_Static_Object;
class RGE_Scenario;
class RGE_Scenario_Header;
class TPanel;

class RGE_Master_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Action_Node {
public:
    RGE_Action_Object* object;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    char gap_00[4];
    RGE_Action_Node* head;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, uchar);
    virtual void normal_draw(short, short, short);
    virtual void draw_front_frame(short, short, short);
    virtual void draw_back_frame(short, short, short);
    virtual void draw_frame(short, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, uchar);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, uchar);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);

    long id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    uchar object_state;
};

// RGE_Action_Object inherits the static object's slot order.  The Wonder
// module only needs the inherited receiver fields and terrain relation calls.
class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Action_Object();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Action_List* action_list;
    char gap_2C[0x10];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;

    void win_game_now();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x19];
    uchar game_state;
    uchar wonder_state;
    char gap_1F[0x1D];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x40];
    float world_time_delta_seconds;
    char gap_88[0x80];
    int countdown_active;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int command, long player_id, long x, long y,
                              long zero);

    char gap_04[0x3F0];
    RGE_Game_World* world;

    void reset_countdown_timer(long player_id);
    void set_countdown_timer(long player_id, long timeout);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Action {
public:
    virtual ~RGE_Action();
    // The period vtable has the two setup overloads in this order.
    virtual int setup(int, RGE_Action_Object*);
    virtual int setup(RGE_Action_Object*);
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
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, void*, void*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short field_04;
    uchar gap_06[2];
    RGE_Action_Object* object;
    uchar state;
    uchar gap_0D[3];
    void* target_obj;
    void* target_obj2;
    long target_id;
    long target2_id;
    float target_x;
    float target_y;
    float target_z;
    float field_2C;
    void* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    uchar sub_action;
    uchar gap_3D[3];

    RGE_Action(int id, RGE_Action_Object* object, int flag);
    RGE_Action(RGE_Action_Object* object, int flag);
};

class TRIBE_Action_Wonder : public RGE_Action {
public:
    TRIBE_Action_Wonder(int id, RGE_Action_Object* object);
    TRIBE_Action_Wonder(RGE_Action_Object* object);
    virtual ~TRIBE_Action_Wonder();
    virtual void first_in_stack(uchar);
    virtual void set_state(uchar);
    virtual uchar update();
};

typedef char tact_wnd_action_size[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_wnd_wonder_size[(sizeof(TRIBE_Action_Wonder) == 0x40) ? 1 : -1];
typedef char tact_wnd_object_size[(sizeof(RGE_Action_Object) == 0x4C) ? 1 : -1];
typedef char tact_wnd_game_size[(sizeof(RGE_Game_World) == 0x10C) ? 1 : -1];

#endif
