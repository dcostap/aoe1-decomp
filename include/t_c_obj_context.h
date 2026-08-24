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
class RGE_World;
class RGE_Map;
class RGE_Tile;
class RGE_Object_Node;
class RGE_Object_List;
class RGE_Sprite;
class RGE_Sound;
class RGE_Armor_Weapon_Info;
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
class RGE_Action_Trade;
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

class RGE_World {
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

typedef RGE_World RGE_Game_World;

class RGE_Player_Info {
public:
    char gap_00[0x270];
    void* field_270;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18();
    virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void vf28(); virtual void vf2C(); virtual void vf30();
    virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48();
    virtual void vf4C(); virtual void vf50(); virtual void vf54();
    virtual void vf58(); virtual void vf5C(); virtual void vf60();
    virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78();
    virtual void vf7C(); virtual void vf80(); virtual void vf84();
    virtual void vf88(); virtual void vf8C(); virtual void vf90();
    virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8();
    virtual void vfAC(); virtual void vfB0(); virtual void vfB4();
    virtual void vfB8(); virtual void vfBC(); virtual void vfC0();
    virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
    virtual void vfD0(); virtual void vfD4(); virtual void vfD8();
    virtual void add_attribute_num(short attribute, float amount,
                                   unsigned char flag);
    virtual void vf94(int, float, float, float, int);
    virtual void vf94_action(int, float, float, float, int);
    virtual RGE_Object_Node* addObject(RGE_Static_Object* object,
                                        int sleep, int dopple);
    virtual void removeObject(RGE_Static_Object* object,
                              int sleep, int dopple, RGE_Object_Node* node);

    char gap_04[0x20];
    TRIBE_Master_Combat_Object** master_objects;
    char gap_28[0x14];
    RGE_World* world;
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
    virtual void vf000(); virtual void vf004(); virtual void vf008();
    virtual void vf00C(); virtual void vf010(); virtual void vf014();
    virtual void vf018(); virtual void vf01C(); virtual void vf020();
    virtual void vf024(); virtual void vf028(); virtual void vf02C();
    virtual void vf030(); virtual void vf034(); virtual void vf038();
    virtual void vf03C(); virtual void vf040(); virtual void vf044();
    virtual void vf048(); virtual void vf04C(); virtual void vf050();
    virtual void vf054(); virtual void vf058(); virtual void vf05C();
    virtual void vf060(); virtual void vf064();
    // BINARY NOTE: the shipped base slot at +0x6C is die_die_die.
    virtual void die_die_die();
    virtual void vf06C(); virtual void vf070(); virtual void vf074();
    virtual void vf070(int, int, float, int, RGE_Combat_Object*);
    virtual void vf078(); virtual void vf07C(); virtual void vf080();
    virtual void vf084(); virtual void vf088(); virtual void vf08C();
    virtual void vf090(); virtual void vf094(); virtual void vf098();
    virtual void modify(float value, unsigned char attribute);
    virtual void set_object_state(unsigned char state);
    virtual void transform(RGE_Master_Static_Object* master);
    virtual void change_ownership(RGE_Player* player);
    virtual void take_attribute_from_owner();
    virtual void give_attribute_to_owner();
    virtual void set_location(float x, float y, float z);
    virtual void exit_obj();
    virtual void move_to(RGE_Static_Object* object,
                         float x, float y, float z);
    virtual void teleport(float x, float y, float z);
    virtual void cancel_object();
    virtual void vf6C();
    virtual unsigned char heal(float amount);

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
    virtual short action_id();
    virtual short action_type();
    virtual short type();
    virtual short get_type();
    virtual short vf18();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* target, float x, float y, float z);
    virtual int work(RGE_Static_Object* target, float x, float y, float z);
    virtual int vf30(void* object, float x, float y, float z);
    virtual int vf34(void* object, float x, float y, float z);
    virtual void set_target(RGE_Static_Object* target, float x, float y, float z);
    virtual void set_target(RGE_Static_Object* target, float x, float y, int z);
    virtual RGE_Static_Object* target_obj();
    virtual RGE_Static_Object* get_target();
    virtual RGE_Static_Object* get_target_obj();
    virtual void* vf4C();
    virtual void set_target_obj(void* target);
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
    virtual void d21(void* object);

    char gap_44[0x140];
    RGE_Action_List* actions;
    UnitAIModule* unit_ai;
    RGE_World* world;
};

class RGE_Action_Object_Base : public RGE_Action_Object {
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(void* master, void* player, float x, float y, float z, int flag);
    RGE_Combat_Object(int mode, RGE_Game_World* world, int doSetup);
    virtual int setup(void* master, void* player, float x, float y, float z);
    virtual int setup(RGE_Master_Combat_Object* master, RGE_Player* player,
                      float x, float y, float z);
    virtual int setup(int handle, RGE_Game_World* world);
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
    virtual unsigned char area_attack(float, float, float,
                                      RGE_Combat_Object*, RGE_Static_Object*);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int vf148(int, int, int, int, int, int);
    virtual unsigned char vf21C(float, float, float,
                                RGE_Combat_Object*, RGE_Static_Object*);
    virtual float vf0F0(RGE_Static_Object*);
    virtual void vf070(int, int, float, int, RGE_Combat_Object*);
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual RGE_Task* make_action(RGE_Static_Object*, float, float, float);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual unsigned char produceWhenKilledBy(int) const;
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int hunt(int, int);
    virtual int convert(int, int);
    virtual int canRepair();
    virtual void change_ownership(RGE_Player* player);
    virtual void notify(int, int, int, long, long, long);

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
class RGE_Action_Trade : public RGE_Action {
public:
    char gap_40[8];
    RGE_Action_Trade(void* object, RGE_Task* task, RGE_Static_Object* target);
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
    TRIBE_Combat_Object(void* master, void* player, float x, float y,
                        float z, int flag);
    TRIBE_Combat_Object(int mode, RGE_Game_World* world, int doSetup);
    virtual ~TRIBE_Combat_Object();
    virtual int setup(void* master, void* player, float x, float y, float z);
    virtual int setup(TRIBE_Master_Combat_Object* master, RGE_Player* player,
                      float x, float y, float z);
    virtual int setup(int handle, RGE_Game_World* world);
    RGE_Action_List* create_action_list();
    void save(int file);
    unsigned char update();
    void modify(float value, unsigned char attribute);
    void transform(RGE_Master_Static_Object* master);
    void set_object_state(unsigned char state);
    void die_die_die();
    void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    void change_ownership(RGE_Player* player);
    unsigned char attack(RGE_Static_Object*, RGE_Combat_Object*);
    unsigned char do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float);
    void get_armor(short&, short&);
    void get_pierce_armor(short&, short&);
    void reposition_artifact();
    int can_debark();
    int hunt(int, int);
    int convert(int, int);
    int heal(int, int);
    int repair(int, int);
    int build(int, int);
    void initUnitAI();
    unsigned char produceWhenKilledBy(int) const;
    virtual void cancel_object();
    virtual unsigned char keepGatheringWhenObjectIsOut(int) const;
    virtual unsigned char useSameZoneDropsite() const;
    unsigned char heal(float);
    int higher_check_for_cliff(RGE_Static_Object*, int, int,
                               float, float, float, float,
                               RGE_Map*, RGE_Static_Object*, float&, int&);
    int higher_than_target(RGE_Static_Object*);
    unsigned char area_attack(float, float, float,
                              RGE_Combat_Object*, RGE_Static_Object*);
    int canRepair();
    void do_repair(RGE_Static_Object* target);
    void vf208(void* action);
    RGE_Task* vf210(void* object, float x, float y, float z);

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

class RGE_Combat_Object_base {
public:
    char base[0x1C4];
    void save(int file);
};

class MasterObj {
public:
    char base[4];
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void save(int file);
};

class ChildObj {
public:
    char base[4];
    virtual void f0(); virtual void save(int file);
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

class TRIBE_Building_Object {
public:
    char gap_00[4];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x34];
    float world_z;
    virtual int higher_than_target(RGE_Static_Object* object);
    float calc_attack_modifier(RGE_Static_Object* object);
};

class SomeClass {
public:
    unsigned char keepGatheringWhenObjectIsOut(int param);
    unsigned char useSameZoneDropsite();
    char pad[8];
    class InnerObj* field_08;
};

class InnerObj {
public:
    char pad[0x14];
    short field_14;
};

class VTableProxy {
public:
    virtual void call208(void* arg);
    virtual RGE_Task* call210(RGE_Static_Object* object,
                              float x, float y, float z);
};

class CombatObject {
public:
    void* vtable_ptr;
    int id;
    void* master_obj;
    void* owner_player;
    char gap_10[0x174];
    RGE_Action_List* actions;
    RGE_Action_List* action_list;
    int trade(int param_1, int param_2);
};

extern "C" int __cdecl lines_intersect(int, int, int, int,
                                        int, int, int, int);
extern "C" double __cdecl atan2(double, double);
extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern float DAT_00574c98;
extern float DAT_00574ca4;

extern float DAT_0058725c;
extern float DAT_00587268;
#define CLIFF_VALUE(offset) (*(float*)((char*)&DAT_00587268 + (offset)))
#define CLIFF_ANGLE(offset) (*(float*)((char*)&DAT_0058725c + (offset)))

#endif
