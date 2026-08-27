#ifndef AOE1_TACT_CNV_H
#define AOE1_TACT_CNV_H

// Declarations owned by tact_cnv.cpp.  The layouts follow the period action,
// object, master-object, task, and player surfaces used by this module.

typedef unsigned char uchar;

class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Action;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Task;
class RGE_Sprite;
class RGE_Sound;
class RGE_Armor_Weapon_Info;
class TDrawArea;
class XYZBYTEPoint;
class LOSTBL;

extern "C" int __cdecl debug_rand(char* file, int line);
extern float DAT_00574ff8;
extern float DAT_00574ffc;
extern float DAT_00575000;
extern float DAT_00575004;

void __cdecl rge_read(int file, void* data, unsigned int size);
void __cdecl rge_write(int file, void* data, int size);

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
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
    virtual void notification(int message, long first, long second,
                              long zero1, long zero2);
    virtual void notify(int, int, int, int, int);
};

extern RGE_Base_Game* rge_base_game;

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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float,
                                 float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                               float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                 uchar, float);
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

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0xB9];
    uchar master_player_id;
    float* attributes;

    int computerPlayer();
};

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds;

    RGE_Static_Object* object(int id);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar,
                                  uchar, uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(void*, short, short, void*, long, long, int, uchar);

    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
    void* sprite;
    char gap_1C[0x0A];
    short hp;
    char gap_28[0xBC];
    float work_rate;
    char gap_E8[4];
    float action_weapon_range;
    char gap_F0[0x24];
    float weapon_range;
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Action_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar,
                                  uchar, uchar, uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(void*, short, short, void*, long, long, int, uchar);
    virtual void* create_task_list();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
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
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
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
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*,
                                                         float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);
    virtual LOSTBL* get_los_table();
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
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int,
                                                 int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual void* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(void*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual void* findAvoidancePath(void*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void* create_object_list();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x20];
    float hp;
    char gap_34[4];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    uchar object_state;
};

class RGE_Animated_Object : public RGE_Static_Object {
};

class RGE_Moving_Object : public RGE_Animated_Object {
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float,
                      float);
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float,
                      float);
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float,
                                           float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();
    void delete_list();
    void add_action(RGE_Action*);
};

class RGE_Sound {
public:
    void play(int);
};

class RGE_Task {
public:
    short task_type;
    short id;
    uchar is_default;
    char gap_05;
    short action_type;
    short object_group;
    short object_id;
    uchar combat_level;
    uchar combat_level_flag;
    short terrain_id;
    uchar owner_type;
    uchar holding_attr;
    uchar state_building;
    char gap_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    uchar search_flag;
    char gap_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;
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

protected:
    virtual void set_state(uchar);

public:
    RGE_Action(int, RGE_Action_Object*, int);
    RGE_Action(RGE_Action_Object*, int);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    uchar state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int target_id;
    int target2_id;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    uchar subActionValue;
    char gap_3D[3];

    void setSubAction(uchar);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, void*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, void*);
    float range;
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    virtual ~TRIBE_Action_Convert();
    TRIBE_Action_Convert(int, RGE_Action_Object*);
    TRIBE_Action_Convert(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Convert(RGE_Action_Object*, RGE_Task*, float, float, float);
    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(uchar);

public:
    uchar was_same_owner;
    char gap_41[3];
    float requiredRange;

    void martyrdom();
};

typedef char tact_cnv_size_check[(sizeof(TRIBE_Action_Convert) == 0x48) ? 1 : -1];

#endif
