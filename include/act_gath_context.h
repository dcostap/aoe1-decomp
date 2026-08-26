#ifndef ACT_GATH_CONTEXT_H
#define ACT_GATH_CONTEXT_H

// Authentic declaration context for C:\\msdev\\work\\age1_x1\\ACT_GATH.cpp.
// The class names and virtual members below follow the period game headers.
// The bodies in this module stay in PDB line and address order.

typedef unsigned char uchar;

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Static_Object;
class RGE_Object_Info;
class RGE_Object_List;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Active_Sprite_List;
class RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class RGE_Tile;
class TDrawArea;
class LOSTBL;
class RGE_Base_Game;

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
    char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    char gap_16[2];
    RGE_Sprite* sprite;
    char gap_1C[0xCC];
    short drop_site;
    short backup_drop_site;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;
};

class RGE_Object_Info {
public:
    char gap_00[0x7C];
    short attribute_type;
    char gap_7E[0x66];
    float gather_multiplier;
};

class RGE_Task {
public:
    short task_type;
    short id;
    uchar is_default;
    uchar gap_05;
    short action_type;
    short object_group;
    short object_id;
    uchar combat_level;
    uchar combat_level_flag;
    short terrain_id;
    uchar owner_type;
    uchar holding_attr;
    uchar state_building;
    uchar gap_13;
    union {
        short attribute_type;
        short facet;
    };
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float gather_amount;
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

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
    char gap_04[0x80];
    float world_time_delta_seconds;
};

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_ids(long, long, float, float,
                                          uchar, uchar, RGE_Static_Object*);
};

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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
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

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    short fallback_attribute;
    char gap_4E[2];
    float* attribute_table;
    RGE_Object_List* objects;

    int computerPlayer();
};

class RGE_Sound {
public:
    void play(int param);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
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
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(int, uchar);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(int);
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
    virtual void notify(int, int, int, int, int, int);

    long id;
    union {
        RGE_Master_Static_Object* master_obj;
        RGE_Master_Static_Object* master;
        RGE_Object_Info* object_data;
    };
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    char gap_1C[0x1C];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    uchar object_state;
    char gap_49[3];
    short attribute_type_held;

    float distance_to_object(RGE_Static_Object*);
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
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
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
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
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);

    char gap_88[0xF8];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    uchar waiting;
    char gap_181[3];
    RGE_Action_List* actions;
    uchar command_flag;
    char gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();
    virtual void get_action_name(char*);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual ~RGE_Action_List();

    void delete_list();
    void add_action(RGE_Action*);
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
    char gap_3D[3];

    RGE_Action(RGE_Action_Object*, int);
    RGE_Action(int, int);
    RGE_Action(int, RGE_Action_Object*, int);
    void setSubAction(uchar);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    float range;
};

class RGE_Action_Gather : public RGE_Action {
public:
    virtual ~RGE_Action_Gather();
    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual void set_state(uchar);

    RGE_Action_Gather(int, RGE_Action_Object*);
    RGE_Action_Gather(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    RGE_Action_Gather(RGE_Action_Object*, RGE_Task*, float, float, float);

protected:
    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();

    int targetType;
};

extern RGE_Base_Game* rge_base_game;
extern float DAT_0056e278;
extern double DAT_0056e280;
extern double DAT_0056e290;

class RGE_Base_Game {
public:
    char gap_00[0x9A8];
    int quick_build;
};

void rge_read(int, void*, int);
void rge_write(int, void*, int);

#endif
