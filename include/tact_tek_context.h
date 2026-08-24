#ifndef AOE1_TACT_TEK_CONTEXT_H
#define AOE1_TACT_TEK_CONTEXT_H

// Authentic declaration surface for C:\\msdev\\work\\age1_x1\\tact_tek.cpp.
// The source and address order is 004D21B0, 004D2250, 004D2290,
// 004D2370, 004D23B0, 004D2440, 004D2450, 004D2550, 004D25E0.
//
// The class names, fields, virtual slots, and helper ABIs below use the
// reviewed class inventory.  The aliases retain the historical member names
// used by the recovered owner bodies without changing their offsets.

#include "game_globals.h"
#include <stdio.h>

typedef unsigned char uchar;

class RGE_Action_Object;
class RGE_Action_List;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Player_Info;
class RGE_Scenario;
class RGE_Static_Object;
class RGE_Task;
class RGE_Game_World;
class RGE_Player;
class TRIBE_Player;
class TRIBE_Player_Tech;

void rge_read(int handle, void* buffer, int count);
void rge_write(int handle, void* buffer, int count);
extern "C" char* __cdecl strncpy(char* dest, const char* src, unsigned int count);

// RGE_Action_Object's inherited virtual surface through notify (slot 82).
// These are the reviewed RGE_Static_Object/RGE_Moving_Object method names in
// their original slot order.  Only notify is called by this module.
class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, uchar);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
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
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual uchar facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(uchar);
    virtual uchar waitingToMove();
    virtual uchar actionState();
    virtual uchar keepGatheringWhenObjectIsOut(int);
    virtual uchar produceWhenKilledBy(int);
    virtual uchar useSameZoneDropsite();
    virtual void __cdecl logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);

    union {
        int id;
        int player_id;
    };
    union {
        void* master_obj;
        void* field_08;
    };
    union {
        RGE_Player* owner;
        void* obj_ptr;
    };
    char gap_10[0x28];
    float world_x;
    float world_y;
    char gap_40[0x0A];
    short field_4A;
    char gap_4C[0x148];
};

// RGE_Player owns the first 62 TRIBE_Player slots.  Its reviewed data
// boundary is 0x220; the compact field view keeps the proven player id and
// the derived tech-tree offset available to this TU.
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, uchar);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual uchar command_make_move(RGE_Static_Object*, float, float);
    virtual uchar command_make_work(RGE_Static_Object*, float, float);
    virtual uchar command_make_do(RGE_Static_Object*, float, float);
    virtual uchar command_stop();
    virtual uchar command_place_object(short, float, float, float);
    virtual uchar command_add_attribute(int, float);
    virtual uchar command_give_attribute(int, int, float);
    virtual uchar command_formation(int);
    virtual uchar command_stand_ground();
    virtual uchar command_create_group(int, int*, int, float);
    virtual uchar command_add_to_group(int, int, float);
    virtual uchar command_remove_from_group(int, int);
    virtual uchar command_destroy_group(int);
    virtual uchar command_resign(int, int);
    virtual uchar command_add_waypoint(float, float, float);
    virtual void* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, void*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(FILE*, int);
    virtual void load_victory(int, long*, uchar);
    virtual void new_victory();

    char gap_04[0x46];
    short id;
    char gap_4C[0x1D0];
    char gap_21C[4];
};

class TRIBE_Player : public RGE_Player {
public:
    virtual void command_give_attribute(int, int, float, float);
    virtual void buildObject(int, int, float, float, int);
    virtual void cancelBuild(int, int, int, float, float, int, int);
    virtual void registerBuild(RGE_Static_Object*, int);
    virtual void trainUnit(int, int, int);
    virtual void cancelTrain(int, int, int, int);
    virtual void registerTrain(int, int, int, int);
    virtual void research(int, int, int);
    virtual void cancelResearch(int, int, int, int);
    virtual void registerResearch(int, int, int);
    virtual void taskTrader(int, int, int, float, float);
    virtual void taskResourceGatherer(int, int, int, float, float);
    virtual void notifyAI(int, int, int, long, long, long);

    TRIBE_Player_Tech* tech_tree;
    char gap_224[0x624];
};

class TRIBE_Player_Tech {
public:
    unsigned char start_research(short, int, unsigned char*);
    unsigned char research(short, float);
    unsigned char cancel_research(short, int);
    short get_progress(short);
    char* get_name(short);
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
    union {
        RGE_Action_Object* obj;
        RGE_Action_Object* action_obj;
    };
    union {
        uchar state;
        uchar status;
    };
    char gap_0D[3];
    char gap_10[0x30];

    RGE_Action(int, RGE_Action_Object*, int);
    RGE_Action(RGE_Action_Object*, int);
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    virtual ~TRIBE_Action_Make_Tech();
    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual uchar update();
    virtual int stop();

    short tech_id;
    char gap_42[2];
    int unique_id;

    TRIBE_Action_Make_Tech(int, RGE_Action_Object*);
    TRIBE_Action_Make_Tech(RGE_Action_Object*, short, int);
    void get_info(short&, short&, char*, short);

protected:
    virtual void set_state(uchar);
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
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(RGE_Scenario*);
    virtual void* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);

    char gap_04[0x3F0];
    RGE_Game_World* world;
    char gap_3F8[0x5B0];
    int quick_build;
};

extern RGE_Base_Game* rge_base_game;

#endif
