#ifndef AOE1_TPLAYER_CONTEXT_H
#define AOE1_TPLAYER_CONTEXT_H

// Canonical declarations for the tplayer.cpp PDB module.
//
// The source module starts at tplayer.cpp line 232.  The class members below
// use the reviewed offsets used by the grouped AI and civilization owners.
// Keep this header local to tplayer.cpp until the shared game ABI is complete.

typedef unsigned char uchar;

typedef unsigned long ulong;

class RGE_Player;
class RGE_Game_World;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Visible_Map;
class RGE_Master_Player;
class RGE_Object_List;
class RGE_Effects;
class TSound_Driver;
class AIPlayBook;
class RGE_Static_Object_Type;
class RGE_Action_Object;
class RGE_Active_Sprite_List;
class RGE_Color_Table;
class TDrawArea;
struct LOSTBL;
struct RGE_Armor_Weapon_Info;
class TRIBE_Building_Object;
class RGE_Sprite;
class RGE_Sound;
struct RGE_Object_Node;
class RGE_Progress_Info { public: char gap_00[0x6C]; float field_6c; float field_70; };
class TRIBE_Command {
public:
    void* command_obj;
    void command_build(RGE_Static_Object**, short, short, float, float);
    void command_build(int, int*, int, int, float, float, int);
    void command_build_wall(RGE_Static_Object**, short, short, long, long, long, long);
    void command_cancel_build(RGE_Static_Object*);
    void command_cancel_build(void*);
    void command_trade_attribute(RGE_Static_Object**, short, long);
    void command_attack_ground(RGE_Static_Object**, short, float, float);
    void command_work(int, int*, int, int, int, float, float);
    void command_relation(short, short, short);
    void command_repair(void*, int, int);
    unsigned char command_give_attribute(int, int, int, float, float);
};
class TRIBE_Command_Unload { public: void command_unload(RGE_Static_Object**, short, float, float); };
class PlayerCommandHolder { public: TRIBE_Command* command; };
class RGE_World { public: TRIBE_Command* commands; };
struct InnerType2 { char gap_00[4]; unsigned char field_04; };
struct InnerType1 { char gap_00[8]; InnerType2* field_08; };
struct Inner_00513D60 { void target(int, int); void target(int); };
struct Inner_005146E0 { void target(int); };
struct Inner_00514F90 { void target(int); };
struct TechIdSource { char gap_00[0x5C]; float tech_a; float tech_b; float tech_c; };
struct TechPlayerEntry { char gap_00[4]; short state; short gap_06; };
struct TechTree { TechPlayerEntry* tech_player_tree; };
struct QueueHost { void enqueue(InnerType1*, int); };
class CommandBuildingHost {
public:
    unsigned char command_building_make_tech(int);
    unsigned char command_building_make_obj(int);
    char gap_00[0x3C]; char* field_3C; char gap_40[0xF0]; InnerType1* field_130;
};
struct Trade_Avail { RGE_Player* player; RGE_Static_Object* dock; float inventory; };
struct ObjectCost { short type; short amount; unsigned char paid; unsigned char gap_05; };
struct CostInfo { short res_id; short amount; unsigned char flag; char pad; };
struct ObjInfo { char gap_00[4]; unsigned char kind; char gap_05[0x143]; CostInfo cost[3]; };
struct RightClickEntry { int key; int action_1; int var_1; int action_0; int var_0; int action_2; int var_2; int action_3; int var_3; int action_4; int var_4; };
class ObjectType {
public:
    virtual ~ObjectType();
    unsigned char status; char gap_005[0x143]; ObjectCost costs[3];
    unsigned char first_paid;
};
class ResourceItem { public: void incrementValue(int, int); };
class TRIBE_Master_Fish_Object { public: TRIBE_Master_Fish_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class TRIBE_Master_Projectile_Object { public: TRIBE_Master_Projectile_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class TRIBE_Master_Tree_Object { public: TRIBE_Master_Tree_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class TCommunications_Handler { public: int IsHost(); int checkSomething(); int ComputerPlayerGameStart(); };
class TMousePointer { public: void Poll(); };
class TChat { public: void setInChatGroup(int, int); };
class AI_Flags { public: char gap_00[0x1D]; unsigned char field_1D; };
class UnitAIModule {};
class TacticalAIGroup { public: int id(); int type(); };
struct _iobuf;
class AIModuleMessage;

extern "C" void __cdecl logCommonHistory(void* target, const char* message);

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
    virtual int filterOutMessage(AIModuleMessage*);
    char gap_04[0xEC];
    void logCommonHistory(char* format, ...);
};

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    virtual int load(char*, RGE_Player*);
    char* buildListName();
    int buildListLength();
    int numberItemsIntoBuildList();
    char* lastBuildItemRequested();
    char* currentBuildItemRequested();
    char* nextBuildItemRequested();
    int addItem(void*, int);
    void cancelBuildItem(int, int, int, float, float, int, int);
    char gap_04[0x5BC];
};

class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    virtual void load(char*, int, int, int, int, int);
    char* constructionPlanName();
    char gap_04[0x314];
};

class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char gap_04[0x14C];
    void setStance(int, int, int);
    void setChangeable(int, uchar);
    int stance(int, int);
    void changeStance(int, int, int);
};

class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    char gap_04[0x1BC];
    void setOverallState(int);
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0x1008C];
    void loadLearnInfo(char*);
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int*, int*);
    int fullyExploredZone(int);
    int closestUnexploredTile(int,long,long,long*,long*);
    int addImportantObject(long);
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char gap_04[0xF4];
    char* resourceName(int);
};

class TribeStrategyAIModule {
public:
    virtual ~TribeStrategyAIModule();
    char gap_04[0x5F4];
    int loadRules(char*);
    void setDifficultyLevel(int);
    int rule(int);
    void setRule(int, int);
    char* ruleSetName();
};

class TribeTacticalAIModule {
public:
    int attackEnabledValue;
    int lastUpdateAreaTimeValue;
    int averageUpdateAreaTimeValue;
    int neededResource(int) const;
    int desiredNumberGatherers() const;
    int numberGatherers() const;
    int desiredNumberCivilianExplorers() const;
    int numberCivilianExplorers() const;
    int numberCivilians() const;
    int numberSoldiers() const;
    void trackUnitGather(int, int, int);
    char* updateAreaName(); int strategicNumber(int); int resourceDifference(int);
    int neededResourceAmount(int); int numberBoats(); int numberSoldiers(); int numberCivilians();
    int desiredGathererCount(int); int actualGathererCount(int);
    TacticalAIGroup* groupUnitIsIn(int); int removeGroup(int); int taskExplorer(int,long,long); void detask(int);
    void notify(int,int,int,long,long,long);
};

class MainDecisionAIModule : public AIModule {
public:
    char gap_base[0x14];
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    TribeMainDecisionAIModule(int, char*, void*, int);
    TribeMainDecisionAIModule(void*, int, char*, void*, char*, char*, char*);
    virtual void setLogHistory(int);
    virtual int update(int);
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
    virtual int canPerformAction(int, int);
    void tributeNotify(int,long,long);
    void updateBuildAIWithObjects();
    TribeTacticalAIModule tacticalAI;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* tiles;
    int map_width;
    int map_height;
};

class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_04[0x100C];
    char* learn_info;
};

class TRIBE_World;
class TRIBE_Player;
class TRIBE_Effects { public: void do_tech_effect(short, TRIBE_Player*); };
class T_Scenario {
public:
    char* learn_info;
    int GetScenarioOption(int);
    void set_player_tech(TRIBE_Player*);
};
class TRIBE_Player_Other { public: void save(int); };
class ScenarioObject { public: virtual void save(int); };

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void*);
    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char gap_1F;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    char gap_2E[2];
    RGE_Sound** sounds;
    short sprite_num;
    char gap_36[2];
    RGE_Sprite** sprites;
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    short master_player_num;
    char gap_46[2];
    RGE_Master_Player** master_players;
    RGE_Effects* effects;
    short terrain_num;
    short terrain_size;
    float** terrains;
    TRIBE_Command* commands;
    RGE_Scenario* scenario;
    short color_table_num;
    char gap_62[2];
    RGE_Color_Table** color_tables;
    long next_object_id;
    long next_reusable_object_id;
    long scenario_object_id;
    unsigned char scenario_object_flag;
    char gap_75[3];
    unsigned int random_seed;
    short curr_player;
    char gap_7E[2];
    TSound_Driver* sound_driver;
    float world_time_delta_seconds;
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;
    AIPlayBook* playbook;
    long campaign;
    long campaign_player;
    long campaign_scenario;
    int player_turn;
    unsigned long player_time_delta[9];
    RGE_Object_List* reusable_static_objects;
    RGE_Object_List* reusable_animated_objects;
    RGE_Object_List* reusable_moving_objects;
    RGE_Object_List* reusable_action_objects;
    RGE_Object_List* reusable_combat_objects;
    RGE_Object_List* reusable_missile_objects;
    RGE_Object_List* reusable_doppleganger_objects;
    unsigned long maximumComputerPlayerUpdateTime;
    unsigned long availableComputerPlayerUpdateTime;
    int currentUpdateComputerPlayer;
    int difficultyLevelValue;
    void update_mutual_allies(void);
    void selectNextComputerPlayer(int);
    RGE_Static_Object* object(int);
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Static_Object* object;
    RGE_Object_Node* head;
    RGE_Object_Node* list;
    RGE_Object_List();
    void* operator[](int);
    void load_list(int, RGE_Game_World*);
    RGE_Static_Object* find_by_master_id(long, float, float, uchar, uchar, RGE_Static_Object*);
};

class TRIBE_Object_List : public RGE_Object_List {
public:
    virtual void load(unsigned char, int, RGE_Game_World*);
};

class Visible_Resource_Manager {
public:
    Visible_Resource_Manager(RGE_Player*, int);
    Visible_Resource_Manager(int, void*);
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
    int difficulty();
    uchar deathMatch();
    int fullVisibility();
    int fullTechTree();
    int game_mode;
    int prog_mode;
    int multiplayerGame();
    int randomGame();
    int playerID(int);
};

struct NodeObj2 { char pad[0x14]; short id; };
struct NodeObj { char pad0[8]; NodeObj2* type; char pad1[0x3C]; char state; };
struct Node { NodeObj* obj; Node* next; };
struct RGE_Object_Node { RGE_Static_Object* obj; RGE_Static_Object* object; RGE_Static_Object* node; RGE_Object_Node* next; };
struct List { int count; Node* head; };
struct Stats {
    float cur; char pad04[0x20]; float progress; float add; float visible;
    char pad30[0x1C]; float a4c; float a50; char pad54[4]; float explored;
    char pad5c[0x28]; float mult; char pad88[0x28]; float diff; float b4;
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int mapSize();
    int mapType();
    int victoryType();
    uchar deathMatch();
    RGE_Static_Object** selected_table; int selected_count;
    RGE_Static_Object** normal_table; int normal_count;
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite*);
    virtual void update(float, float);
    virtual void draw(short, short, short, short, short, RGE_Color_Table*, TDrawArea*);
    virtual void normal_draw(short, short, short, RGE_Color_Table*, TDrawArea*);
    virtual void shadow_draw(short, short, short, RGE_Color_Table*, TDrawArea*, unsigned char);
    virtual unsigned char is_animating(RGE_Sprite*);
    virtual void set_frame(RGE_Sprite*, short);
    virtual unsigned char frame_passed(RGE_Sprite*, short);
    virtual unsigned char looped(RGE_Sprite*);
    virtual short get_facetindex(RGE_Sprite*, short);
    virtual unsigned char load_node(int, unsigned char, RGE_Sprite**);
};

// Use the reviewed process-wide game pointer declaration.
#include "rge_base_game_global.h"

class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    RGE_Victory_Conditions(RGE_Player*, int, long*, unsigned char);
    char gap_04[0x1C];
    int get_victory_points_group(unsigned char);
    int get_victory_points_id(unsigned char);
    int get_victory_points();
    int get_attribute_id(unsigned char);
};

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:
    TRIBE_Victory_Conditions(RGE_Player*, int, long*, unsigned char);
    TRIBE_Victory_Conditions(RGE_Player*);
};

class RGE_Resource {
public:
    float food;
    float wood;
    float stone;
    float gold;
    char gap_10[0x1C];
    float pop;
};

class RGE_Visible_Map {
public:
    RGE_Visible_Map(RGE_Map*, RGE_Player*);
    RGE_Visible_Map(int, RGE_Game_World*);
    float percentExplored();
    unsigned char get_visible(int, int);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
    unsigned char master_type;
    void make_available(char);
    unsigned char type;
    char* name;
    short pict;
    unsigned char available;
    unsigned char flag52;
    short hp;
    short right_click_table;
    short interface_group;
    long get_help_message();
    long get_help_page();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
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
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
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
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
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
    UnitAIModule* unitAI();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    char gap_30[4];
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    RGE_Object_Node* player_object_node;
    char gap_54[0x20];
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    char gap_87;
    RGE_Master_Static_Object* special_master;
    int special_owner;
};

class RGE_Static_Object_Type {
public:
    virtual void load(int);
    virtual void save(int);
    virtual void setup();
    virtual void clear();
    virtual void reset();
    virtual void initialize();
    virtual RGE_Static_Object* make_scenario_obj(RGE_Player*, float, float, float);
    unsigned char object_group;
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    unsigned char build(float);
};

class Tech_Player_Tree {
public:
    float research_done;
    short state;
    char gap_06[2];
};

class Tech_Tree {
public:
    char* name;
    short pre_reqs[4];
    short pre_reqs_required;
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    char gap_1D;
    short research;
    short effect;
    short track;
    short icon;
    unsigned char button_location;
    char gap_27;
    short build_obj_id;
    short string_id;
    short string_id2;
    char gap_2E[2];
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

class TRIBE_Tech {
public:
    void save(int);
    Tech_Tree* tech_tree;
    short tech_tree_num;
    char gap_06[2];
    TRIBE_World* world;
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;
    TRIBE_Effects* effects;
    T_Scenario* scenario;
    void check_destructables(short, long, float, float, int);
    int controllingComputerPlayer;
};

struct Item_Avail {
public:
    char* name;
    short id;
    short pict;
    short inv1;
    short pad_0A;
    float cost1;
    short inv2;
    short pad_12;
    float cost2;
    short inv3;
    short pad_1A;
    float cost3;
    long help_msg;
    long help_page;
    short inventory_item_1;
    float inventory_cost_1;
    short inventory_item_2;
    float inventory_cost_2;
    short inventory_item_3;
    float inventory_cost_3;
    long help_string_id;
    long help_page_id;
};

class ObjectInfo {
public:
    char pad0[4]; unsigned char type; char pad5[3]; char* name;
    char pad0c[0x13C];
    short cost1_type; short cost1_amount; unsigned char cost1_used;
    char pad14d; short cost2_type; short cost2_amount; unsigned char cost2_used;
    char pad153; short cost3_type; short cost3_amount; unsigned char cost3_used;
    unsigned char flag52;
};

class TRIBE_Player_Tech {
public:
    virtual ~TRIBE_Player_Tech();
    TRIBE_Player_Tech(TRIBE_Tech*, RGE_Player*, unsigned char);
    unsigned char check_for_new_tech();
    TRIBE_Player_Tech(int, void*, RGE_Player*, int);
    Tech_Player_Tree* tech_player_tree;
    TechPlayerEntry* tech_player_tree_entries;
    short tech_player_tree_num;
    char gap_06[2];
    TRIBE_Tech* base_tech;
    RGE_Player* owner;

    void tech_cost(short, short*, short*, short*, short*, short*, short*);
    long get_help_message(short);
    long get_help_page(short);
    void do_tech(short); unsigned char rev_tech(short); void disable(short); void enable(short);
};

class TRIBE_History_Info {
public:
    TRIBE_History_Info(int);
    virtual ~TRIBE_History_Info();
    void add_history_entry(int, int);
    void add_history_entry(unsigned char, int);
};
class TRIBE_Population_Source { public: char gap_00[0x2C]; float population_value; };

class RGE_Player {
public:
    virtual ~RGE_Player();
    RGE_Player(int, RGE_Game_World*, unsigned char);
    RGE_Player(RGE_Game_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char);
    virtual void set_game_status(uchar);
    virtual void update();
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void update_dopplegangers();
    virtual void scenario_save(int);
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
    virtual void add_attribute_num(short, float, unsigned char);
    void save(int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void load_master_object(int, short, unsigned char, RGE_Sprite**, RGE_Sound**);
    virtual void load(int);
    uchar get_selected_objects_to_command(void**, short*, int, int, int, int);
    uchar get_selected_objects_to_command(RGE_Static_Object***, short*, int, int, int, int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postload(int, long*, float);
    RGE_Static_Object* make_new_object(long, float, float, float, int);
    void set_relation(int, char);
    void set_map_loc(short, short);
    void set_view_loc(float, float);

    char gap_04[0x1E];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Static_Object_Type** object_types;
    RGE_Object_List* objects;
    RGE_Object_List* object_list;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    union {
        RGE_Victory_Conditions* victory_conditions;
        RGE_Victory_Conditions* victory;
    };
    union {
        RGE_Visible_Map* visible;
        RGE_Visible_Map* visible_map;
    };
    RGE_Game_World* world;
    void* doppleganger_creator;
    void* VR_List;
    TRIBE_Command* tribe_command;
    char* name;
    uchar type;
    int computerPlayerValue;
    short objectCount;
    short master_count;
    RGE_Master_Static_Object** masters;
    char* playerData;
    int startTech;
    uchar gap_49;
    short id;
    char gap_4C[4];
    union {
        RGE_Resource* res;
        float* attributes;
    };
    char gap_54[0xAC];
    int allied_LOS_Enable;
    char gap_104[1];
    uchar civ_id;
    char gap_106[0x2A];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned int sel_object_properties;
    short sel_count;
    char gap_19E[0x82];
};

class TRIBE_Player : public RGE_Player {
public:
    virtual ~TRIBE_Player();
    char* aiStatus(int);
    virtual void __cdecl logMessage(char*, ...);
    char aiStatusInformationValue5[0x100];
    char aiStatusInformationValue6[0x100];
    char aiStatusInformationValue[0x100];
    char aiStatusInformationValue2[0x100];
    char aiStatusInformationValue3[0x100];
    char aiStatusInformationValue4[0x100];
    TRIBE_Player(int, TRIBE_World*, unsigned char);
    TRIBE_Player(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char,
                 unsigned char, unsigned char, char*, char*, char*);
    TRIBE_Player(RGE_Game_World*, RGE_Master_Player*, unsigned char, char*, unsigned char,
                 unsigned char, unsigned char, char*, char*, char*);
    char player_type;
    short civ;
    int fog_update;
    int update_count;
    int update_history_count;
    int updateCountNeedHelp;
    int update_time;
    short count;
    char* field_50;
    TRIBE_Player_Tech* tech_tree;
    TRIBE_Player_Tech* techTree;
    char gap_224[0x14];
    union {
        TribeMainDecisionAIModule* playerAI;
        void* ai;
    };
    TRIBE_History_Info* history;
    List* list;
    RGE_Visible_Map* visibleMap;
    Stats* stats;
    unsigned char byte_48;
    TRIBE_Tech* tech;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    ScenarioObject* scenario_object;
    TRIBE_Player_Other* other;
    short master_object_count;
    TRIBE_Object_List* list_28;
    TRIBE_Object_List* list_2c;
    RGE_Object_List* list_30;
    RGE_Visible_Map* visible_map;
    Visible_Resource_Manager* visible_resources;
    int field_840;
    int field_844;
    float ruin_held_time;
    float artifact_held_time;
    float* resources;
    RGE_Progress_Info* progress_info;
    void* info;
    int mutual_allies_loaded;
    int mouse_actions[68];
    int current_action_flags;
    short current_target;
    AI_Flags* field_3C;
    float view_x;
    float view_y;
    void* obj_table;
    float* resource_cost_table;
    RGE_Player* rge_player;
    short diplomacy_value;
    TRIBE_Command* command;
    TRIBE_World* world;
    short destructable_type;

    void interface_tech_avail(Item_Avail**, short*, short);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
    uchar check_obj_cost(short, short*, float, int);
    void obj_cost(short, char**, short*, short*, short*, short*, short*, short*, float);
    void obj_cost(short, char**, short&, short&, short&, short&, short&, short&, float);
    RGE_Static_Object* find_obj(short, RGE_Static_Object*);
    void interface_trade_avail(Trade_Avail**, short*);
    ObjectInfo** objectInfo;
    unsigned char get_selected_objects_to_command(RGE_Static_Object***, short*, int, int, int, int);
    unsigned char command_make_building(short, float, float);
    unsigned char command_make_wall(short, long, long, long, long);
    unsigned char command_building_cancel(void);
    PlayerCommandHolder* holder;
    unsigned char command_delete_object(RGE_Static_Object*);
    unsigned char command_trade_attribute(long);
    unsigned char command_attack_ground(float, float);
    uchar command_make_repair(RGE_Static_Object*);
    unsigned char command_make_unload(float, float);
    unsigned char pay_obj_cost(short, float, int);
    void objectCost(int, int, ResourceItem*, int);
    virtual int objectCostByType(int);
    int researchAvailable(int);
    void researchState(int);
    Inner_00514F90* inner_;
    void kickAI(int);
    void researchCost(int, int, ResourceItem*, int);
    void reimburse_obj_cost(short);
    Inner_00513D60* ptr_;
    void check_tech_cost(int, int);
    TRIBE_Population_Source* population_source;
    void add_population_entry(void);
    TechIdSource* source;
    void rev_tech(long);
    virtual void notifyAI(int,int,int,long,long,long);
    int intelligentCivSelection(int, int, int);
    int get_mouse_pointer_action_vars(int, int&, int&);
    virtual unsigned char command_give_attribute(int, int, float, float);
    void interface_item_avail(Item_Avail**, short*, short);
    RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void random_start();
    void loadAIInformation(char*, char*, char*, int, int);
    void intelligentBuildListAndRulesSelection(char*, char*, int, int, int);
    virtual void logStatus(_iobuf*, int);
    virtual void trackUnitGather(int, int, int);
    void get_achievement(unsigned char, char*);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void analyize_selected_objects();
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void update();
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void buildObject(int, int, float, float, int);
    virtual void cancelBuild(int, int, int, float, float, int, int);
    virtual void taskTrader(int, int, int, float, float);
    virtual void taskResourceGatherer(int, int, int, float, float);
    void setDiplomaticStance(int, int);
    virtual void update_dopplegangers();
    virtual void scenario_save(int);
    void save(int);
    virtual void load_master_object(int, short, unsigned char, RGE_Sprite**, RGE_Sound**);
    virtual void load(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postload(int, long*, float);

    void setupEgyptian(int*, int, int, int);
    void setupGreek(int*, int, int, int);
    void setupBabylonian(int*, int, int, int);
    void setupAssyrian(int*, int, int, int);
    void setupMinoan(int*, int, int, int);
    void setupHittite(int*, int, int, int);
    void setupPhoenician(int*, int, int, int);
    void setupSumerian(int*, int, int, int);
    void setupPersian(int*, int, int, int);
    void setupShang(int*, int, int, int);
    void setupYamato(int*, int, int, int);
    void setupChoson(int*, int, int, int);
    void setupRoman(int*, int, int, int);
    void setupCarthaginian(int*, int, int, int);
    void setupPalmyran(int*, int, int, int);
    void setupMacedonian(int*, int, int, int);
};

class TRIBE_Gaia : public TRIBE_Player {
public:
    unsigned char field_48;
    int update_time; int update_nature; int last_count; int animal_max;
    int field_848; int field_84C; int field_850; int field_854;
    TRIBE_Gaia(int, TRIBE_World*, unsigned char);
    TRIBE_Gaia(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char, unsigned char, char*, char*, char*);
    TRIBE_Gaia(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char);
    virtual ~TRIBE_Gaia();
    void random_start();
    virtual void save(int);
    void update();
    void load_master_object(int, short, unsigned char, RGE_Sprite**, RGE_Sound**);
    void scenario_postload(int, long*, float);
};

extern "C" int __cdecl debug_rand(char*, int);
extern "C" void __cdecl debug_srand(char*, int, int);

#define S_TPLAYER_CPP ((char*)0x0058AC44)
#define S_RANDOM_GAME_SPECIALIZED ((char*)0x0058AF78)
#define S_SETTING_AI_PERSONALITY ((char*)0x0058B130)
#define S_SELECTED_BEST_BUILD_LIST ((char*)0x0058B148)
#define S_I_AM_THE_CIV ((char*)0x0058B16C)

#define debug_random_on (*(int*)0x0062C4D4)
#define saved_debug2 (*(int*)0x0086BC94)
#define base_game rge_base_game
#define tribe_game ((TRIBE_Game*)rge_base_game)

extern int computerPlayerSetup;
extern int allowAIToCheat;


#endif
