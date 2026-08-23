#ifndef TACT_BLD_CONTEXT_H
#define TACT_BLD_CONTEXT_H

// Canonical local declarations for the original tact_bld.cpp source module.
// The action hierarchy and virtual slots follow the period tactical-action
// headers.  The source-line order is kept by src/tact_bld_tu.cpp.

typedef unsigned char uchar;

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class TRIBE_Building_Object;
class RGE_Base_Game;

void* operator new(unsigned int size);
extern RGE_Base_Game* rge_base_game;

class RGE_Sprite {
public:
    char gap_00[0x5E];
    short frame;
    char gap_60[0x10];
    uchar flags;
    char gap_71;
    short id;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    uchar master_type;
    uchar pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    uchar pad_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    uchar undead_flag;
    uchar pad_25;
    short hp;
    float los;
    uchar pad_2C[4];
    float radius_x;
    float radius_y;
    float radius_z;
    RGE_Sound* selected_sound;
    RGE_Sound* created_sound;
    RGE_Sound* death_sound;
    short death_spawn_obj_id;
    uchar sort_number;
    uchar can_be_built_on;
    short button_pict;
    uchar hide_in_scenario_editor;
    uchar pad_4F;
    short portrait_pict;
    uchar available;
    uchar pad_53;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    uchar elevation_flag;
    uchar fog_flag;
    short terrain;
    uchar movement_type;
    uchar pad_69;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    uchar pad_7E[2];
    float attribute_rot;
    float multiple_attribute_mod;
    uchar attribute_flag[3];
    uchar area_effect_object_level;
    uchar combat_level;
    uchar select_level;
    uchar map_draw_level;
    uchar unit_level;
    uchar map_color;
    uchar attack_reaction;
    uchar convert_terrain_flag;
    uchar damage_sprite_num;
    void* damage_sprites;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
    uchar recyclable;
    uchar track_as_resource;
    uchar create_doppleganger_on_death;
    uchar resource_group;
    uchar draw_flag;
    uchar draw_color;
    uchar pad_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    uchar size_class;
    uchar pad_C9;
    short obj_trail_id;
    uchar obj_trail_options;
    uchar pad_CD[3];
    float obj_trail_spacing;
    uchar move_algorithem;
    uchar pad_D5[3];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    void* tasks;
    short default_task;
    uchar pad_DE[2];
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    uchar task_by_group;
    uchar pad_ED[3];
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    uchar run_pattern;
    uchar pad_F9[3];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
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
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual void vpad100();
    virtual void vpad104();
    virtual void vpad108();
    virtual void vpad10C();
    virtual void vpad110();
    virtual void vpad114();
    virtual void vpad118();
    virtual void vpad11C();
    virtual void vpad120();
    virtual void vpad124();
    virtual void vpad128();
    virtual void setWaitingToMove(uchar);
    virtual void vpad130();
    virtual void vpad134();
    virtual void vpad138();
    virtual void vpad13C();
    virtual void vpad140();
    virtual void vpad144();
    virtual void notify(int, int, int, long, long, long);
    virtual void vpad14C();
    virtual void vpad150();
    virtual void vpad154();
    virtual void vpad158();
    virtual void vpad15C();
    virtual void vpad160();
    virtual void vpad164();
    virtual void vpad168();
    virtual void vpad16C();
    virtual void vpad170();
    virtual void vpad174();
    virtual void vpad178();
    virtual void vpad17C();
    virtual void vpad180();
    virtual void vpad184();
    virtual void vpad188();
    virtual void vpad18C();
    virtual void vpad190();
    virtual void vpad194();
    virtual void vpad198();
    virtual void vpad19C();
    virtual void vpad1A0();
    virtual void vpad1A4();
    virtual void vpad1A8();
    virtual void vpad1AC();
    virtual void vpad1B0();
    virtual void vpad1B4();
    virtual void vpad1B8();
    virtual void vpad1BC();
    virtual void vpad1C0();
    virtual void vpad1C4();
    virtual void vpad1C8();
    virtual void vpad1CC();
    virtual void vpad1D0();
    virtual void vpad1D4();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void* create_object_list();
    virtual void* create_sprite_list();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    uchar object_state;
    uchar sleep_flag;
    uchar dopple_flag;
    uchar goto_sleep_flag;
    short attribute_type_held;
    uchar type;
    uchar worker_num;
    void* player_object_node;
    char pathingGroupMembers[0x10];
    char groupMembers[0x10];
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    uchar inObstructionMapValue;
    uchar lastInObstructionMapValue;
    uchar underAttackValue;
    uchar pad_87;

    void removeAllFromPathingGroup();
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Action_Object();
    virtual int setup_animated(void*, RGE_Player*, float, float, float);
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup_moving(void*, RGE_Player*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds;
    RGE_Static_Object* object(int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual int isAlly(int);
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void command(int, int, int, int, int, float, float, float, float, int, int, int);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;

    int computerPlayer();
};

class RGE_Task {
public:
    char gap_00[0x1C];
    float work_val1;
    char gap_20[4];
    float work_range;
    char gap_28[0x0C];
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;
};

class RGE_Action_List {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual uchar update();

    void delete_list();
    void add_action(RGE_Action*);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    // VC5 reverses adjacent overload entries in the original action vtable.
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
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, void*, void*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    union {
        short action_type;
        short field_04;
    };
    uchar pad_06[2];
    RGE_Action_Object* obj;
    uchar state;
    uchar pad_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    uchar subActionValue;
    uchar pad_3D[3];

    RGE_Action(RGE_Action_Object*, int);
    RGE_Action(int, RGE_Action_Object*, int);
    void setSubAction(uchar);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    float range;
};

class RGE_Sound {
public:
    void play(int);
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    uchar build(float);
};

class RGE_Base_Game {
public:
    char gap_00[0x9A8];
    int quick_build;
};

class TRIBE_Action_Build : public RGE_Action {
public:
    TRIBE_Action_Build(int, RGE_Action_Object*);
    TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void first_in_stack(uchar);
    virtual void set_state(uchar);
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
};

typedef char tact_bld_action_size[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_bld_build_size[(sizeof(TRIBE_Action_Build) == 0x40) ? 1 : -1];

#endif
