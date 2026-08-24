#ifndef AOE1_COM_OBJ_CONTEXT_H
#define AOE1_COM_OBJ_CONTEXT_H

// Canonical declaration surface for the com_obj.cpp translation unit.
// Included owner files keep their isolated declarations behind a guard.

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

class RGE_Action_Object;
class RGE_Combat_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Action_Object;
class RGE_Master_Combat_Object;
class InnerObj;
class InnerObj_00431490;
class RGE_Combat_Object_State;
struct VISIBLE_UNIT_REC;
class RGE_Action;
class RGE_Action_List;
class RGE_Task;
class RGE_Sprite;
class RGE_Sound;
class RGE_Armor_Weapon_Info;
class RGE_Tile;
class RGE_Map;
struct Link;
struct MapCell;
struct MapRow;
class RGE_Base_Object;
class UnitAIModule;
class Visible_Unit_Manager;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class TDrawArea;
class RGE_Color_Table;
class LOSTBL;
class Path;
struct XYPoint;
struct XYZPoint;
struct XYZBYTEPoint;
template<class T> class ManagedArray;

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);
extern "C" float save_game_version;
extern "C" float g_attack_modifier;
extern "C" float DAT_0056f49c;
extern "C" float DAT_0056f4ac;
extern "C" int __cdecl debug_rand(const char*, int);

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int index);
    RGE_Map* map;
    float frame_delta;
    int player_num;
    RGE_Player** players;
    void** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    void** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;
    short map_width;
    short map_height;
    float** terrains;
    int is_player_turn(int);
    float get_accum_time_delta(int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int id;
    char gap_04[0x38];
    RGE_Game_World* world;
    RGE_Master_Static_Object** master_objects;
    void** objects;
    int computerPlayer();
    void notify(int, int, int, long, long, long);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void pad04();
    virtual void pad08();
    virtual void pad0C();
    virtual void pad10();
    virtual void pad14();
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    char pad_004[0x22];
    short object_group;
    short hp_short;
    float hp;
    char pad_028[8];
    float radius_x;
    float radius_y;
    float radius_z;
    float area_effect_range;
    int area_effect_level;
    int area_effect_object_level;
    float base_hit_chance;
    int weapon_num;
    RGE_Armor_Weapon_Info* weapon;
    int base_armor;
    int armor_num;
    RGE_Armor_Weapon_Info* armor;
    int orig_armor;
    int orig_weapon;
    RGE_Sprite* fight_sprite;
    char pad_06C[0xA0];
    union {
        float weapon_range;
        float field_114;
    };
    char pad_118[8];
    float speed_of_attack;
    union {
        short missile_id;
        short field_124;
    };
    union {
        short base_hit_chance_combat;
        unsigned char defense_terrain_bonus;
    };
    unsigned char break_off_combat;
    unsigned char pad_129;
    union {
        short fire_missile_at_frame;
        short field_12A;
        short field_12a;
    };
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    union {
        float minimum_weapon_range;
        float field_138;
        float range_30;
    };
    short orig_armor_combat;
    short orig_weapon_combat;
    float orig_weapon_range;
    float orig_speed_of_attack;
    float range_34;
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};
class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char pad_D8[0x20];
};
class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char pad_F8[4];
};
class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    char pad_FC[0x18];
    RGE_Sound* fight_sprite;
    RGE_Sprite* moving_sprite;
    RGE_Sprite* sprite;
};

class RGE_Armor_Weapon_Info {
public:
    short armor;
    short original_armor;
    short weapon;
    short original_weapon;
    short type;
    short value;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual uchar update();
    virtual float teleport(float, float, float);
    virtual void notify(int, int, int, long, long, long);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual int enter(int, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int gather(int, int);
    virtual int explore(int, int, int);
    virtual int transport(float, float, float, int);
    virtual int unload(int, float, float, float);
    virtual int stopAction();
    virtual int pause();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual int currentTargetID() const;
    virtual float currentTargetX() const;
    virtual float currentTargetY() const;
    virtual float currentTargetZ() const;
    virtual float rateOfFire();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual void vf070(int, int, float, int, RGE_Combat_Object*);
    virtual float vf0F0(RGE_Static_Object*);
    virtual void vf074();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void save(int);
    virtual void stop();
    virtual void copy_obj(RGE_Master_Combat_Object*);

    union {
        int id;
        int object_id;
    };
    RGE_Master_Combat_Object* master_obj;
    RGE_Master_Combat_Object* master;
    RGE_Player* owner;
    char gap_10[0x20];
    float hp;
    float x;
    float y;
    float z;
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x44];
    VISIBLE_UNIT_REC* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    RGE_Tile* tile;
    InnerObj_00431490* ptr;
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};
class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float angle;
    char gap_0A0[0xE0];
};

class RGE_Action_List {
public:
    uchar have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual short func18();
    virtual short type();
    virtual short action_type();
    virtual void set_target(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual int func30(RGE_Action_Object*, float, float, float);
    virtual RGE_Static_Object* func4C();
    virtual RGE_Static_Object* get_target();
    virtual RGE_Static_Object* target_obj();
    virtual RGE_Static_Object* get_target_obj();
    virtual int func34(RGE_Static_Object*, float, float, float);
    virtual void call34(float, float, int);
    virtual void set_target_pos(RGE_Static_Object*, int, int, int);
    float target_x;
    float target_y;
    float target_z;
    char gap_04[4];
    RGE_Action_Object* obj;
    uchar state;
    char gap_0D[3];
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    uchar subActionValue;
    char gap_3D[3];
    float targetX();
    float targetY();
    float targetZ();
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    RGE_Action_Object(RGE_Master_Combat_Object*, RGE_Player*, float, float, float, int);
    RGE_Action_Object(int, RGE_Game_World*, int);
    virtual void recycle_in_to_game(RGE_Master_Combat_Object*, RGE_Player*, float, float, float);
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Combat_Object*, RGE_Player*, float, float, float);
    virtual void save(int);
    virtual void stop();
    virtual void copy_obj(RGE_Master_Combat_Object*);
    virtual uchar update();
    virtual void add_action(RGE_Action*);
    virtual void set_action(RGE_Action*);
    virtual void set_only_action(RGE_Action*);
    virtual void set_end_action(RGE_Action*);
    virtual void vf38(RGE_Sound*);
    virtual RGE_Task* make_enter_task(RGE_Static_Object*, int, int, int);
    virtual RGE_Task* create_gather_task(RGE_Static_Object*, int, int, int);
    RGE_Player* player;
    uchar waiting;
    char gap_181[3];
    RGE_Action_List* actions;
    uchar command_flag;
    char gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    RGE_Combat_Object(RGE_Master_Combat_Object*, RGE_Player*, float, float, float, int);
    RGE_Combat_Object(int, RGE_Game_World*, int);
    virtual ~RGE_Combat_Object();
    virtual int setup(RGE_Master_Combat_Object*, RGE_Player*, float, float, float);
    virtual int setup(int, RGE_Game_World*);
    virtual void recycle_in_to_game(RGE_Master_Combat_Object*, RGE_Player*, float, float, float);
    virtual void save(int);
    virtual void stop();
    virtual uchar area_attack(float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
    virtual uchar attack(RGE_Static_Object*, float, RGE_Combat_Object*, float, float);
    uchar attack(RGE_Static_Object*, RGE_Combat_Object*);
    uchar attack(float, float, float, RGE_Combat_Object*);
    virtual uchar do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float);
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual uchar can_attack();
    virtual void get_armor(short*, short*);
    virtual void get_weapon(short*, short*);
    virtual void get_weapon_range(int*, int*);
    virtual void get_speed_of_attack(int*, int*);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual void enter_obj(RGE_Static_Object*);
    virtual uchar update();
    virtual void copy_obj(RGE_Master_Combat_Object*);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(int, int);
    virtual int attack(float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int gather(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int transport(float, float, float, int);
    virtual int unload(int, float, float, float);
    virtual int stopAction();
    virtual int pause();
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float rateOfFire();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual int currentTargetID() const;
    virtual float currentTargetX() const;
    virtual float currentTargetY() const;
    virtual float currentTargetZ() const;
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual float teleport(float, float, float);
    virtual float base_teleport(float, float, float);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    void reset_attack_timer();
    void get_armor(short&, short&);
    void get_weapon(short&, short&);
    void get_weapon_range(short&, short&);
    void calc_attack_modifier();
    virtual void vf44(RGE_Player*);
    virtual float vf0F0(RGE_Static_Object*);
    virtual void vf148(int, int, int, int, int, int);
    virtual uchar vf21C(float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
    void set_something(int);
    virtual void vf38(int);
    virtual void vf38(RGE_Sound*);
    virtual float vf10C();
    virtual float vf074(int, RGE_Armor_Weapon_Info*, float, void*, RGE_Static_Object*);
    float distance_to_object(RGE_Static_Object*);
    void get_target_obj();
    float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    RGE_Action_List* action_list;
    void* object_info;
    int field_04;
    int field_0C;
    void* field_08;
    RGE_Action_List* action_list_2;
    RGE_Action* inside_action;
    RGE_Static_Object* inside_obj;
    UnitAIModule* aiModule;
    int object_state;
    int vf21C_value;
    int value_4;
    RGE_Sound* sprite;
    RGE_Sprite* sprite_ptr;
    InnerObj* field_8;
    RGE_Master_Static_Object* master_object;
    int fight_state;
    float field_40;
    RGE_Combat_Object_State* state;
    float attack_timer;
    uchar capture_flag;
    uchar type;
    float area_effect_range;
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
    RGE_Action_Enter(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
};
class RGE_Action_Gather : public RGE_Action {
public:
    RGE_Action_Gather(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
};
class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(void*, void*, float, float, float);
};
class RGE_Action_Transport : public RGE_Action {
public:
    RGE_Action_Transport(RGE_Action_Object*, RGE_Task*, float, float, float);
    int func34(RGE_Static_Object*, float, float, float);
};
class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    RGE_Action_Move_To(void*, RGE_Static_Object*, float, void*);
};
class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(void*, RGE_Static_Object*, int, int, int, float, float, short, short);
    RGE_Action_Attack(void*, float, float, float, void*, void*, void*, float, float, short, short);
};

class RGE_Task {
};
class InnerObj {
public:
    int field_114;
    int field_120;
    int field_140;
    int field_144;
};
class RGE_Missile_Object {
public:
    void init_missile(RGE_Combat_Object*, RGE_Static_Object*, float);
    void init_missile(RGE_Combat_Object*, float, float, float, float);
};
class RGE_Base_Object : public RGE_Combat_Object {
public:
    static void enter_obj(RGE_Static_Object*);
};
struct MapCell {
    char gap[0x10];
    Link* objects;
    char gap_end[4];
};
struct MapRow {
    MapCell cell[1];
};
class RGE_Base_Game {
public:
    float calc_attack_modifier(int);
};
class RGE_Map {
public:
    short width;
    short height;
    MapRow** rows;
};
class RGE_Tile {
public:
    int field_00;
    int field_04;
    int field_08;
    unsigned char terrain_type;
};
class UnitAIModule {
public:
    void stop(int);
    int notify(int, int, int, long, long, long);
    void update(float);
};
class Visible_Unit_Manager {
public:
    void Update_Unit_Info(int, int, int, int, int, unsigned long, int, void*);
    void remove_object(RGE_Static_Object*);
};
class RGE_Object_List {
};
class RGE_Active_Sprite_List {
};
class RGE_Combat_Object_State {
public:
    int state;
    int value_18;
};
struct VISIBLE_UNIT_REC {
    unsigned char gap_00[6];
    unsigned char pos_x;
    unsigned char pos_y;
};
class InnerObj_00431490 {
public:
    float rateOfFire;
    float weaponRange;
    float minimumWeaponRange;
};

extern UnitAIModule* unitAIValue;
extern Visible_Unit_Manager* VisibleUnitManager;

#endif
