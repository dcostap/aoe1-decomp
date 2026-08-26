#ifndef AOE1_DPL_OBJ_CONTEXT_H
#define AOE1_DPL_OBJ_CONTEXT_H

// Canonical declaration surface for the original dpl_obj.cpp module.
//
// The PDB places the fifteen ordinary owners in one source module, in the
// address and line order recorded by the module packet.  The wrapper defines
// DPL_OBJ_SHARED_CONTEXT before including the owner bodies.  The same named
// surface is available when an owner is checked in isolation.

#include <stdio.h>
#include <stdlib.h>

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Animated_Object;
class RGE_Sprite;
class TDrawArea;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Doppleganger_Object;
class RGE_Master_Combat_Object;
class RGE_Doppleganger_Object;
class RGE_Doppleganger_Creator;
class RGE_Color_Table;
class RGE_Active_Sprite_Node;
class RGE_Active_Sprite_List;
class RGE_Armor_Weapon_Info;
class RGE_Action_Object;
class RGE_Object_List;
class LOSTBL;
class Path;
struct XYZBYTEPoint;

extern "C" int __cdecl __ftol();
extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);
extern unsigned long* unified_map_offsets[];
extern float save_game_version;
extern float DAT_00570418;
extern FILE* DDlogf;

class RGE_Color_Table {
public:
    char gap_00[0x25];
    unsigned char map_color;
};

class RGE_Active_Sprite_List {
public:
    RGE_Active_Sprite_Node* copy_sprite_list();
    void use_sprite_list(RGE_Active_Sprite_Node* node);
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
    virtual unsigned char check_placement(RGE_Player*, float, float, int*, unsigned char,
                                          unsigned char, unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long, int,
                      unsigned char);
    char gap_04[0x0C];
    short string_id;
    char gap_12[0x7C];
    unsigned char map_draw_level;
    unsigned char gap_8F;
    unsigned char map_color;

};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float,
                                             RGE_Static_Object*);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    union {
        unsigned long world_time;
        unsigned long someField;
    };
    char gap_08[0x38];
    RGE_Player** players;

    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1E];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x14];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x88];
    unsigned long mutualVisibleMask;
    unsigned long nonMutualVisibleMask;
    unsigned long RemoveVisibleBits[9];
    char gap_100[8];
    RGE_Color_Table* color_table;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
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
    virtual void save(int file);
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
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
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
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(void*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();

    long id;
    RGE_Master_Static_Object* master_obj;
    union {
        RGE_Player* owner;
        void* world;
    };
    void* sprite;
    char gap_14[4];
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x19];
    unsigned char facet;
    char gap_36[2];
    union {
        float world_x;
        float x;
        float field_38;
    };
    union {
        float world_y;
        float y;
        float field_3C;
        float field_3c;
    };
    float world_z;
    char gap_44[4];
    unsigned char object_state;
    char gap_49[5];
    union {
        unsigned char type;
        unsigned char field_4E;
        unsigned char field_4e;
    };
    char gap_4F[0x39];

    RGE_Static_Object* get_object_pointer(long id);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;

    RGE_Animated_Object(RGE_Master_Animated_Object* master, RGE_Player* player,
                        float x, float y, float z, int do_setup);
    RGE_Animated_Object(int file, RGE_Game_World* world, int do_setup);
    virtual unsigned char update();
    virtual int setup(RGE_Master_Animated_Object* master, RGE_Player* player,
                      float x, float y, float z);
    virtual int setup(int file, RGE_Game_World* world);
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
    virtual void save(int file);
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Doppleganger_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z, RGE_Static_Object* doppled);
    virtual unsigned char update();
    virtual void rehook();
    virtual void save(int file);
    virtual void destroy_obj();

    RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object* master,
                            RGE_Player* player, float x, float y, float z,
                            int do_setup, RGE_Static_Object* doppled);
    RGE_Doppleganger_Object(int file, RGE_Game_World* world, int do_setup);
    virtual void validate();
protected:
    virtual int setup(RGE_Master_Doppleganger_Object* master, RGE_Player* player,
                      float x, float y, float z);
    virtual int setup(int file, RGE_Game_World* world);

public:
    RGE_Static_Object* doppled_object;
    RGE_Color_Table* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    union {
        unsigned long LastMapValue;
        int lastMapValue;
    };
    union {
        unsigned long CantSeeBits;
        int cantSeeBits;
    };
    unsigned char map_draw_level;
    unsigned char map_color;
    unsigned char gap_AA[2];
    union {
        int doppledObjectID;
        int doppledObjID;
    };
};

class RGE_Doppleganger_Creator {
public:
    union {
        RGE_Player* owner;
        void* player;
    };
    union {
        int allocated_size;
        int maxCount;
    };
    union {
        int active_size;
        int activeCount;
    };
    union {
        RGE_Static_Object** Objects;
        int* objects;
    };
    union {
        unsigned long** Map_Addresses;
        int* mapAddresses;
    };
    union {
        unsigned long* Last_Map_Value;
        int* lastMapValue;
    };
    union {
        int* Object_ids;
        int* objectIds;
    };

    RGE_Doppleganger_Creator(RGE_Player* player, int count);
    ~RGE_Doppleganger_Creator();
    int add_doppleganger_check(RGE_Static_Object* object,
                               unsigned long* map_address);
    int remove_doppleganger_check(RGE_Static_Object* object);
    void perform_doppleganger_checks();

// BINARY NOTE: dpl_obj.cpp emits expand_allocations with protected access.
protected:
    void expand_allocations(int grow_size);
};

#endif
