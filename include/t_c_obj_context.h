#ifndef T_C_OBJ_CONTEXT_H
#define T_C_OBJ_CONTEXT_H

// Complete t_c_obj.cpp declaration surface for the grouped compile pass.
// The owner bodies remain the source of behavior.  This header only joins
// their period-style local class views into one compiling translation unit.
#define T_C_OBJ_HEAL_CONTEXT_H

typedef unsigned char uchar;

class RGE_Static_Object;
class RGE_Combat_Object;
class RGE_Action_Object;
class RGE_Action;
class RGE_Action_List;
class RGE_Task;
class RGE_Task_List;
class RGE_Player;
class RGE_Player_Info;
class RGE_Game_World;
class RGE_Map;
class RGE_Tile;
class RGE_Object_Node;
class RGE_Object_List;
class RGE_Sprite;
class RGE_Sound;
class RGE_Active_Sprite_List;
class TDrawArea;
class RGE_Color_Table;
class LOSTBL;
class RGE_Master_Action_Object;
struct RGE_Armor_Weapon_Info;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Master_Building_Object;
class TRIBE_Master_Combat_Object;
class TRIBE_Master_Building_Object;
class TRIBE_Master_Combat_Object;
class TribeStats;
class TribePlayerSub;
class UnitAIModule;
class RGE_Action_Object_Base;
class TRIBE_Action_Convert;
class TRIBE_Action_Heal;
class TRIBE_Action_Hunt;
class TRIBE_Action_Repair;
class TRIBE_Action_Build;
class TRIBE_Action_Trade;
class TRIBE_Combat_Object;
class AttackContext;
class TRIBE_Combat_Object_Type;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                             float x, float y, float z);
    virtual TRIBE_Master_Combat_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player* player,
                                           float x, float y,
                                           int* placement_info,
                                           unsigned char a,
                                           unsigned char b,
                                           unsigned char c,
                                           unsigned char d,
                                           unsigned char e,
                                           unsigned char f);

    unsigned char master_type;
    char gap_05[0x0B];
    short id;
    short copy_id;
    short object_group;
    char gap_16[0x10];
    short hp;
    unsigned char base_armor;
    short cost_type;
    short object_type;
    char gap_2C[0x0F0];
    short max_hit_points;
    char gap_11E[0x132];
    short heal_rate;
    short attack_modifier_kind;
    short entry_count;
    short* entry_table;
    short unit_count;
    short* pierce_table;
    short orig_armor;
    float radius_x;
    float radius_y;
    char gap_200[0x53];
    unsigned char area_effect_object_level;
    char gap_254[0x2C];
    short weapon_num;
    RGE_Armor_Weapon_Info* weapon;
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    char gap_281[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    RGE_Task_List* tasks;
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Combat_Object();
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();
    char gap_04[0x160];
    TRIBE_Master_Combat_Object(int handle, RGE_Sprite** sprites,
                               RGE_Sound** sounds, int do_setup);
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Building_Object();
    char gap_04[0x178];
    TRIBE_Master_Building_Object(int handle, RGE_Sprite** sprites,
                                 RGE_Sound** sounds, int do_setup);
};

class RGE_Master_Building_Object : public RGE_Master_Static_Object {
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x14];
    RGE_Player** players;
    RGE_Sound** sounds;
    RGE_Sprite** sprites;
    unsigned long world_time;
    unsigned char game_state;

    virtual unsigned char data_load_world(void* file);
    RGE_Static_Object* object(int id);
};


class RGE_Player_Info {
public:
    char gap_00[0x270];
    void* field_270;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
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
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*,
                               float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual void make_scenario_obj();
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short attribute, float amount,
                                   unsigned char flag);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual void* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(void*, float, float);
    virtual unsigned char command_make_work(void*, float, float);
    virtual unsigned char command_make_do(void*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void remake_visible_map();

    char gap_04[0x20];
    TRIBE_Master_Combat_Object** master_objects;
    char gap_28[0x14];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    float* attributes;
    RGE_Player_Info* info;

    void unselect_one_object(RGE_Static_Object* object);
    unsigned char check_obj_cost(short type, short* values,
                                 float amount, int flag);
    unsigned char pay_obj_cost(short type, float amount, int flag);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
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
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack() const;
    virtual void setUnderAttack(unsigned char);
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
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID() const;
    virtual float currentTargetX() const;
    virtual float currentTargetY() const;
    virtual float currentTargetZ() const;
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual void __cdecl logDebug(char*, ...);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();

    virtual void take_attribute_from_owner();
    virtual void give_attribute_to_owner();
    virtual void set_location(float x, float y, float z);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Static_Object* inside_obj;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float x;
    float y;
    float z;
    float attribute_amount_held;
    short attribute_type_held;
    unsigned char type;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    unsigned char worker_num;
    RGE_Object_Node* player_object_node;
    char gap_54[0x20];
};

class RGE_Object_Node {
public:
    RGE_Combat_Object* object;
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    char gap_0D[3];
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
    RGE_Object_Node* object_list;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
    unsigned char get_terrain(short col, short row);
};

struct OwnerData {
    char gap_00[0x3C];
    RGE_Game_World* world;
};

struct CombatDataA {
    char gap_00[0x8F];
    unsigned char value_8F;
};

struct CombatDataB {
    char gap_00[8];
    short value_08;
};

class TribeStats {
public:
    char gap_00[0x10];
    float f10;
    char gap_14[0x18];
    float f2c;
    char gap_30[0x1C];
    float f4c;
};

class TribePlayerSub {
public:
    char gap_00[0x50];
    TribeStats* stats;
};

class TRIBE_Combat_Object_Master {
public:
    char gap_00[0x14];
    short field_14;
};

class TRIBE_Combat_Object_Sub_3C {
public:
    char gap_00[0x84];
    float field_84;
};

class TRIBE_Combat_Object_Sub_50 {
public:
    char gap_00[0x8C];
    float field_8C;
};

class TRIBE_Combat_Object_Sub {
public:
    char gap_00[0x3C];
    TRIBE_Combat_Object_Sub_3C* field_3C;
    char gap_40[0x10];
    TRIBE_Combat_Object_Sub_50* field_50;
};

class OwnedMaster {
public:
    virtual void destroy(int value);
};

class Unit_Type_Data {
public:
    char gap_00[0x50];
    void* field_50;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Static_Object* object);
    virtual int setup(int type, RGE_Static_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Static_Object* object);
    virtual void rehook();
    virtual void save(int file);
    virtual short type();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* target, float x, float y, float z);
    virtual int work(RGE_Static_Object* target, float x, float y, float z);
    virtual void set_target(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* target);
    virtual void set_target_obj2(RGE_Static_Object* target);
    virtual void set_state(unsigned char state);

    short field_04;
    char gap_06[0x1A];
    int target_x;
    int target_y;
    int target_z;
    char gap_2C[4];
    void* task_ptr;
    char gap_34[0x0C];
    unsigned char was_same_owner;
    char gap_41[3];
    float required_range;
};

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    virtual RGE_Action* create_task_action(RGE_Task* task,
                                             RGE_Static_Object* target,
                                             float x, float y, float z);
    RGE_Static_Object* obj;
    void* list;
    unsigned char have_action();
    RGE_Action* get_action();
    RGE_Task* get_task();
    int action_work(RGE_Static_Object* target, float x, float y, float z);
    void delete_list();
};

class RGE_Task {
public:
    char gap_00[6];
    short action_id;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    unsigned char gap_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    unsigned char search_flag;
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, short object_id);
    virtual RGE_Task* get_target_task(RGE_Action_Object* action,
                                       RGE_Static_Object* target,
                                       float x, float y, float z);
    virtual int is_attack_task(RGE_Task* task);
    virtual int check_task(RGE_Task* task, RGE_Action_Object* action,
                           RGE_Static_Object* target);
    virtual ~RGE_Task_List();
    RGE_Task** list;
    short list_num;
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int file);
    virtual void load(int file);
    char pad[0x134];
    void purgeNotifyQueue(unsigned long time);
    void setCurrentOrder(int order);
    void setCurrentAction(int action);
    void setCurrentTarget(int id, int group, float x, float y, float z);
    void setTaskedByPlayer();
};

#define T_C_OBJ_AI_CLASS(name) \
class name : public UnitAIModule { \
public: name(RGE_Static_Object*, int); \
};
T_C_OBJ_AI_CLASS(TribeArtifactUnitAIModule)
T_C_OBJ_AI_CLASS(TribeCivilianUnitAIModule)
T_C_OBJ_AI_CLASS(TribePriestUnitAIModule)
T_C_OBJ_AI_CLASS(TribeHuntedAnimalUnitAIModule)
T_C_OBJ_AI_CLASS(TribeElephantUnitAIModule)
T_C_OBJ_AI_CLASS(TribeLionUnitAIModule)
T_C_OBJ_AI_CLASS(TribePreditorUnitAIModule)
T_C_OBJ_AI_CLASS(TribeFishingShipUnitAIModule)
T_C_OBJ_AI_CLASS(TribeTradeShipUnitAIModule)
T_C_OBJ_AI_CLASS(TribeTransportShipUnitAIModule)
T_C_OBJ_AI_CLASS(TribeBuildingUnitAIModule)
T_C_OBJ_AI_CLASS(TribeTowerUnitAIModule)
T_C_OBJ_AI_CLASS(TribeSoldierUnitAIModule)
#undef T_C_OBJ_AI_CLASS

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void transform(RGE_Master_Static_Object* master);
    virtual void change_ownership(RGE_Player* player);
    virtual void move_to(RGE_Static_Object* target, float x, float y, float z);
    virtual void work2();
    virtual void set_action(RGE_Action* action);
    virtual void add_action(RGE_Action* action);
    virtual RGE_Action_List* create_action_list();
    virtual void set_only_action(RGE_Action* action);
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);

    char gap_44[0x140];
    RGE_Action_List* actions;
    UnitAIModule* unit_ai;
    RGE_Game_World* world;
};

class RGE_Action_Object_Base : public RGE_Action_Object {
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(RGE_Master_Combat_Object* master, RGE_Player* player,
                      float x, float y, float z, int flag);
    RGE_Combat_Object(int mode, RGE_Game_World* world, int doSetup);

protected:
    virtual int setup(void* master, void* player, float x, float y, float z);
    virtual int setup(RGE_Master_Combat_Object* master, RGE_Player* player,
                      float x, float y, float z);
    virtual int setup(int handle, RGE_Game_World* world);

public:
    virtual unsigned char update();
    virtual void save(int file);
    virtual void modify(float value, unsigned char attribute);
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* armor,
                        float value, RGE_Player* player,
                        RGE_Static_Object* target);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
    virtual unsigned char attack(RGE_Static_Object* target,
                                 RGE_Combat_Object* other);
    virtual unsigned char do_attack(RGE_Static_Object* target,
                                    RGE_Combat_Object* attacker,
                                    float p3, float p4, float p5);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    // Binary note: the combat event callback occupies the shipped +0x148
    // slot.  The PDB names the same member notify at its other call sites.
    virtual void notify(int, int, int, long, long, long);
    virtual unsigned char area_attack(float, float, float,
                                      RGE_Combat_Object*, RGE_Static_Object*);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual RGE_Task* make_action(RGE_Static_Object*, float, float, float);
    virtual unsigned char produceWhenKilledBy(int) const;
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int hunt(int, int);
    virtual int convert(int, int);
    virtual int canRepair();
    virtual void change_ownership(RGE_Player* player);

    int field_04;
    void* object_info;
    int field_0C;
    int field_0C_value;
    float field_38;
    float field_3C;
    float field_40;
    float hp;
    unsigned char capture_flag;
};

class RGE_Action_Object;

class TRIBE_Action_List : public RGE_Action_List {
public:
    TRIBE_Action_List(RGE_Action_Object* object);
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    TRIBE_Action_Convert(TRIBE_Combat_Object* object, RGE_Task* task,
                         RGE_Static_Object* target);
    void martyrdom();
};
class TRIBE_Action_Heal : public RGE_Action {
public:
    TRIBE_Action_Heal(RGE_Action_Object* object, RGE_Task* task,
                      RGE_Static_Object* target);
};
class TRIBE_Action_Hunt : public RGE_Action {
public:
    int target_type;
    TRIBE_Action_Hunt(TRIBE_Combat_Object* object, RGE_Task* task,
                      RGE_Static_Object* target);
};
class TRIBE_Action_Repair : public RGE_Action {
public:
    char padding[0x40];
    TRIBE_Action_Repair(RGE_Action_Object* object, RGE_Task* task,
                        RGE_Static_Object* target);
};
class TRIBE_Action_Build : public RGE_Action {
public:
    char padding[0x3C];
    TRIBE_Action_Build(RGE_Action_Object* object, RGE_Task* task,
                       RGE_Static_Object* target);
};
class TRIBE_Action_Trade : public RGE_Action {
public:
    char gap_40[8];
    TRIBE_Action_Trade(RGE_Action_Object* object, RGE_Task* task, RGE_Static_Object* target);
};

struct VISIBLE_UNIT_REC {
    int object_id;
    unsigned char distance;
    unsigned char player;
    unsigned char pos_x;
    unsigned char pos_y;
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    TRIBE_Combat_Object(TRIBE_Master_Combat_Object* master, RGE_Player* player,
                        float x, float y, float z, int flag);
    TRIBE_Combat_Object(int mode, RGE_Game_World* world, int doSetup);
    virtual ~TRIBE_Combat_Object();

protected:
    virtual int setup(void* master, void* player, float x, float y, float z);
    virtual int setup(TRIBE_Master_Combat_Object* master, RGE_Player* player,
                      float x, float y, float z);
    virtual int setup(int handle, RGE_Game_World* world);

public:
    RGE_Action_List* create_action_list();
    void save(int file);
    unsigned char update();
    void modify(float value, unsigned char attribute);
    void transform(RGE_Master_Static_Object* master);
    void set_object_state(unsigned char state);
    void die_die_die();
    void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);

protected:
    void change_ownership(RGE_Player* player);

public:
    unsigned char attack(RGE_Static_Object*, RGE_Combat_Object*);
    unsigned char do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual void get_armor(short&, short&);
    virtual void get_pierce_armor(short&, short&);
    void reposition_artifact();
    int can_debark();
    int hunt(int, int);
    int convert(int, int);
    int heal(int, int);
    int repair(int, int);
    int build(int, int);
    virtual int trade(int, int);
    virtual RGE_Task* make_action(RGE_Static_Object*, float, float, float);
protected:
    virtual void initUnitAI();

public:
    unsigned char produceWhenKilledBy(int) const;
    virtual void cancel_object();
    virtual unsigned char keepGatheringWhenObjectIsOut(int) const;
    virtual unsigned char useSameZoneDropsite() const;

protected:
    virtual unsigned char heal(float);

public:
    virtual int higher_check_for_cliff(RGE_Static_Object*, int, int,
                                       float, float, float, float,
                                       RGE_Map*, RGE_Static_Object*, float&, int&);
    virtual int higher_than_target(RGE_Static_Object*);

protected:
    virtual unsigned char area_attack(float, float, float,
                                      RGE_Combat_Object*, RGE_Static_Object*);
    virtual int canRepair();

public:
    void do_repair(RGE_Static_Object* target);

    char gap_08[0x200];
    TRIBE_Master_Combat_Object* master_obj;
    TRIBE_Combat_Object_Master* field_08;
    TRIBE_Combat_Object_Sub* field_0C;
    char* master;
    TribePlayerSub* sub;
    RGE_Action_Object* game;
    RGE_Action_List* action_list;
    OwnerData* owner_data;
    CombatDataA* can_debark_master;
    CombatDataB* can_debark_state;
    UnitAIModule* unit_ai_value;
    OwnedMaster* owned_master_ptr;
    unsigned char own_master;
    unsigned char field_48;
    unsigned short field_4C;
    float field_44;
    VISIBLE_UNIT_REC* VUR_Ptrs[9];
    RGE_Object_Node* player_object_node_value;
    UnitAIModule* unitAIValue;
    AttackContext* context;
    TRIBE_Combat_Object_Type* type_info;
    Unit_Type_Data* unit_type;
};

class AttackContext {
public:
    char pad_00[0x124];
    short field_124;
};

class RGE_Base_Game {
public:
    char gap_000[0x9A8];
    int quick_build;
};

class TRIBE_Combat_Object_Type {
public:
    char gap_00[0x14];
    short object_class;
};

int __cdecl lines_intersect(float, float, float, float,
                            float, float, float, float);
extern "C" double __cdecl atan2(double, double);
extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern float DAT_00574c98;
extern float DAT_00574ca4;

extern float DAT_0058725c;
extern float DAT_00587268;
#define CLIFF_VALUE(offset) (*(float*)((char*)&DAT_00587268 + (offset)))
#define CLIFF_ANGLE(offset) (*(float*)((char*)&DAT_0058725c + (offset)))

#endif
