#pragma once
#include "../common.h"
#include "asp_list.h"
#include "utmarray.h"
#include "aiuaimod.h"
#include "Path.h"
#include "act_obj.h"
#include "infmap.h"

class RGE_Check_List {
public:

    RGE_Check_List();
    virtual ~RGE_Check_List();
    virtual void add_node(RGE_Static_Object* param_1, float param_2, float param_3, uchar param_4);
};

static_assert(sizeof(RGE_Check_List) == 0x4, "RGE_Check_List Size Mismatch");

class RGE_Static_Object {
public:
    long id;                                 // 0x4
    RGE_Master_Static_Object* master_obj;    // 0x8
    RGE_Player* owner;                       // 0xC
    RGE_Sprite* sprite;                      // 0x10
    RGE_Sprite* old_sprite;                  // 0x14
    RGE_Active_Sprite_List* sprite_list;     // 0x18
    RGE_Tile* tile;                          // 0x1C
    RGE_Static_Object* inside_obj;           // 0x20
    RGE_Object_List* objects;                // 0x24
    short screen_x_offset;                   // 0x28
    short screen_y_offset;                   // 0x2A
    short shadow_x_offset;                   // 0x2C
    short shadow_y_offset;                   // 0x2E
    float hp;                                // 0x30
    uchar curr_damage_percent;               // 0x34
    uchar facet;                             // 0x35
    uchar selected;                          // 0x36
    uchar selected_group;                    // 0x37
    float world_x;                           // 0x38
    float world_y;                           // 0x3C
    float world_z;                           // 0x40
    float attribute_amount_held;             // 0x44
    uchar object_state;                      // 0x48
    uchar sleep_flag;                        // 0x49
    uchar dopple_flag;                       // 0x4A
    uchar goto_sleep_flag;                   // 0x4B
    short attribute_type_held;               // 0x4C
    uchar type;                              // 0x4E
    uchar worker_num;                        // 0x4F
    RGE_Object_Node* player_object_node;     // 0x50
    ManagedArray_int pathingGroupMembers;   // 0x54
    ManagedArray_int groupMembers;          // 0x64
    UnitAIModule* unitAIValue;               // 0x74
    int groupCommanderValue;                 // 0x78
    int zoneMapIndex;                        // 0x7C
    float groupRangeValue;                   // 0x80
    uchar inObstructionMapValue;             // 0x84
    uchar lastInObstructionMapValue;         // 0x85
    uchar underAttackValue;                  // 0x86

    virtual uchar can_attack();
    virtual int canRepair();
    virtual int inAttackRange(RGE_Static_Object* param_1);
    virtual float calc_attack_modifier(RGE_Static_Object* param_1);
    virtual float rateOfFire();
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object* param_1);
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual uchar keepGatheringWhenObjectIsOut(int param_1);
    virtual uchar produceWhenKilledBy(int param_1);
    virtual uchar useSameZoneDropsite();
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual int attack(int param_1, int param_2);
    virtual int attack(float param_1, float param_2, float param_3, int param_4);
    virtual int moveTo(int param_1, int param_2);
    virtual int moveTo(int param_1, float param_2, int param_3);
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
    virtual int moveAwayFrom(int param_1, int param_2);
    virtual int hunt(int param_1, int param_2);
    virtual int gather(int param_1, int param_2);
    virtual int convert(int param_1, int param_2);
    virtual int heal(int param_1, int param_2);
    virtual int repair(int param_1, int param_2);
    virtual int build(int param_1, int param_2);
    virtual int trade(int param_1, int param_2);
    virtual int explore(int param_1, int param_2, int param_3);
    virtual int enter(int param_1, int param_2);
    virtual int unload(int param_1, float param_2, float param_3, float param_4);
    virtual int transport(float param_1, float param_2, float param_3, int param_4);
    virtual int stopAction();
    virtual int pause();
    virtual void do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object* param_1);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual RGE_Static_Object* get_target_obj();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual int passableTile(float param_1, float param_2, int param_3);
    virtual uchar facetToNextWaypoint();
    virtual void setWaitingToMove(uchar param_1);
    virtual uchar waitingToMove();
    virtual uchar actionState();
    virtual int canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7);
    virtual int canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6);
    virtual int canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7);
    virtual int canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray_int* param_7);
    virtual int canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9);
    virtual int findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3);
    virtual int canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5);
    virtual int canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6);
    virtual int firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6);
    virtual XYZBYTEPoint* userDefinedWaypoint(int param_1);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2);
    virtual void removeAllUserDefinedWaypoints(int param_1);
    virtual void removeUserDefinedWaypoint(int param_1);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(XYZPoint* param_1, float param_2, int param_3);
    RGE_Static_Object(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Static_Object(int param_1, RGE_Game_World* param_2, int param_3);
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual void recycle_out_of_game();
    virtual int setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual float getSpeed();
    virtual void change_unique_id();
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();
    virtual void get_starting_attribute();
    virtual void give_attribute_to_owner();
    virtual void take_attribute_from_owner();
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4);
    virtual void shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4);
    virtual void normal_draw(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_front_frame(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_back_frame(TDrawArea* param_1, short param_2, short param_3);
    virtual void capture_frame(TDrawArea* param_1, short param_2, short param_3);
    virtual void capture_square_frame(TDrawArea* param_1, short param_2, short param_3);
    virtual void capture_frame_3d_cube(TDrawArea* param_1, short param_2, short param_3);
    virtual void capture_frame_3d_square(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_frame_3d_square_back(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_frame_3d_square_front(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_frame_3d_cube_back(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_frame_3d_cube_front(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_frame(TDrawArea* param_1, short param_2, short param_3);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void rehook();
    virtual RGE_Static_Object* get_object_pointer(long param_1);
    virtual RGE_Sprite* get_sprite_pointer(short param_1);
    virtual void save(int param_1);
    virtual float teleport(float param_1, float param_2, float param_3);
    virtual void new_sprite(RGE_Sprite* param_1);
    virtual void add_overlay_sprite(RGE_Sprite* param_1, uchar param_2);
    virtual void remove_overlay_sprite(RGE_Sprite* param_1);
    virtual void change_ownership(RGE_Player* param_1);
    virtual void modify(float param_1, uchar param_2);
    virtual void modify_delta(float param_1, uchar param_2);
    virtual void modify_percent(float param_1, uchar param_2);
    virtual void transform(RGE_Master_Static_Object* param_1);
    virtual void copy_obj(RGE_Master_Static_Object* param_1);
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void set_object_state(uchar param_1);
    virtual RGE_Static_Object* check_object_bounds();
    virtual float get_terrain_speed(uchar param_1);
    virtual uchar is_moving();
    virtual uchar is_dying();
    virtual int get_frame(short* param_1, short* param_2, short* param_3, short* param_4);
    virtual uchar more_room();
    virtual void enter_obj(RGE_Static_Object* param_1);
    virtual void exit_obj();
    virtual LOSTBL* get_los_table();
    virtual int explore_terrain(RGE_Player* param_1, uchar param_2, int param_3);
    virtual void unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3);
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
    virtual float calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
    virtual void rotate(long param_1);
    virtual void set_attribute(short param_1, float param_2);
    virtual void set_attribute_amount(float param_1, uchar param_2, uchar param_3);
    virtual uchar heal(float param_1);
    virtual void notify_of_relation(long param_1, uchar param_2);
    virtual void set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3);
    virtual void release_being_worked_on(RGE_Static_Object* param_1);
    virtual int inRange(RGE_Static_Object* param_1, float param_2);
    virtual float distance_to_object(RGE_Static_Object* param_1);
    virtual float distance_to_position(float param_1, float param_2, float param_3);
    virtual uchar hit_test(short param_1, short param_2, short param_3, short param_4, short param_5);
    virtual uchar box_hit_test(short param_1, short param_2, short param_3, short param_4, short param_5, short param_6);
    virtual void set_location(float param_1, float param_2, float param_3);
    virtual void new_angle(float param_1);
    virtual uchar drop_held_objects(int param_1);
    virtual uchar find_drop_location(int param_1, float* param_2, float* param_3, RGE_Master_Static_Object* param_4, RGE_Static_Object* param_5, float param_6, float param_7, float param_8, float param_9);
    virtual RGE_Check_List* make_object_bounds_list(float param_1);
    virtual int boundToFacet(float param_1, float param_2, int param_3);
    virtual int numberFacets();
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar param_1);
    virtual int addToObstructionMap(int param_1);
    virtual int removeFromObstructionMap(int param_1);
    virtual void changeInfluenceMap(InfluenceMap* param_1, int param_2, int param_3, int param_4);
    virtual RGE_Check_List* objectCollisionList(float param_1);
    virtual void logDebug(char* param_1);
    virtual UnitAIModule* unitAI();
    virtual uchar lookupZone(XYPoint param_1);
    virtual uchar lookupZone(int param_1, int param_2);
    virtual uchar currentZone();
    virtual int withinRangeOfZoneAtPoint(uchar param_1, float param_2, XYPoint* param_3);
    virtual int withinRangeOfZone(uchar param_1, float param_2);
    virtual int findClosestPointInTerrainType(XYPoint param_1, XYPoint* param_2, int param_3, int param_4, int param_5);
    virtual int isGroupCommander();
    virtual int inGroup();
    virtual int unitIsInGroup(int param_1);
    virtual int createGroup(int* param_1, int param_2, int param_3, float param_4);
    virtual int commanderCreateGroup(int* param_1, int param_2, int param_3, float param_4);
    virtual int addToGroup(int param_1, float param_2);
    virtual int commanderAddToGroup(int param_1, float param_2);
    virtual int removeFromGroup(int param_1);
    virtual int commanderRemoveFromGroup(int param_1);
    virtual int destroyGroup();
    virtual int commanderDestroyGroup();
    virtual void addToPathingGroup(int param_1);
    virtual void removeAllFromPathingGroup();
    virtual void remove_shadows();
    virtual void set_sleep_flag(uchar param_1);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
};

static_assert(sizeof(RGE_Static_Object) == 0x88, "RGE_Static_Object Size Mismatch");
static_assert(offsetof(RGE_Static_Object, underAttackValue) == 0x86, "RGE_Static_Object Offset Mismatch");

uchar RGE_Static_Object::can_attack() {
    /* TODO: Stub */
//                              uchar __thiscall can_attack(RGE_Static_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?can_attack@RGE_Static_Object@@UAEEXZ                        XREF[6]:     0056e49c(*), 0056ec8c(*),
//                               RGE_Static_Object::can_attack                                             0057029c(*), 005709c4(*),
//                                                                                                         005745ac(*), 00574d2c(*)
//                              stat_obj.h:144 (3)
//         00405d00     XOR        AL,AL
//         00405d02     RET
//         00405d03     ??         90h
//         00405d04     NOP
//         00405d05     NOP
//         00405d06     NOP
//         00405d07     NOP
//         00405d08     NOP
//         00405d09     NOP
//         00405d0a     NOP
//         00405d0b     NOP
//         00405d0c     NOP
//         00405d0d     NOP
//         00405d0e     NOP
//         00405d0f     NOP
    return 0;
}

int RGE_Static_Object::canRepair() {
    /* TODO: Stub */
//                              int __thiscall canRepair(RGE_Static_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?canRepair@RGE_Static_Object@@UAEHXZ                         XREF[8]:     0056e4b0(*), 0056eca0(*),
//                               RGE_Static_Object::canRepair                                              0056f2e8(*), 005702b0(*),
//                                                                                                         00570780(*), 005709d8(*),
//                                                                                                         005745c0(*), 00574d40(*)
//                              stat_obj.h:149 (3)
//         00405d10     XOR        EAX,EAX
//         00405d12     RET
//         00405d13     ??         90h
//         00405d14     NOP
//         00405d15     NOP
//         00405d16     NOP
//         00405d17     NOP
//         00405d18     NOP
//         00405d19     NOP
//         00405d1a     NOP
//         00405d1b     NOP
//         00405d1c     NOP
//         00405d1d     NOP
//         00405d1e     NOP
//         00405d1f     NOP
    return 0;
}

void RGE_Static_Object::do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              void __thiscall do_command(RGE_Static_Object * this, RGE_Static_Obje
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?do_command@RGE_Static_Object@@UAEXPAV1@MMM@Z                XREF[5]:     0056eca8(*), 005702b8(*),
//                               RGE_Static_Object::do_command                                             005709e0(*), 005745c8(*),
//                                                                                                         00574d48(*)
//                              stat_obj.h:158 (3)
//         0041a450     RET        0x10
//         0041a453     ??         90h
//         0041a454     NOP
//         0041a455     NOP
//         0041a456     NOP
//         0041a457     NOP
//         0041a458     NOP
//         0041a459     NOP
//         0041a45a     NOP
//         0041a45b     NOP
//         0041a45c     NOP
//         0041a45d     NOP
//         0041a45e     NOP
//         0041a45f     NOP
    return;
}

void RGE_Static_Object::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              void __thiscall move_to(RGE_Static_Object * this, RGE_Static_Object
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?move_to@RGE_Static_Object@@UAEXPAV1@MMM@Z                   XREF[5]:     0056ecac(*), 005702bc(*),
//                               RGE_Static_Object::move_to                                                005709e4(*), 005745cc(*),
//                                                                                                         00574d4c(*)
//                              stat_obj.h:159 (3)
//         0041a460     RET        0x10
//         0041a463     ??         90h
//         0041a464     NOP
//         0041a465     NOP
//         0041a466     NOP
//         0041a467     NOP
//         0041a468     NOP
//         0041a469     NOP
//         0041a46a     NOP
//         0041a46b     NOP
//         0041a46c     NOP
//         0041a46d     NOP
//         0041a46e     NOP
//         0041a46f     NOP
    return;
}

void RGE_Static_Object::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              void __thiscall work(RGE_Static_Object * this, RGE_Static_Object * p
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?work@RGE_Static_Object@@UAEXPAV1@MMM@Z                      XREF[5]:     0056ecb0(*), 005702c0(*),
//                               RGE_Static_Object::work                                                   005709e8(*), 005745d0(*),
//                                                                                                         00574d50(*)
//                              stat_obj.h:160 (3)
//         0041a470     RET        0x10
//         0041a473     ??         90h
//         0041a474     NOP
//         0041a475     NOP
//         0041a476     NOP
//         0041a477     NOP
//         0041a478     NOP
//         0041a479     NOP
//         0041a47a     NOP
//         0041a47b     NOP
//         0041a47c     NOP
//         0041a47d     NOP
//         0041a47e     NOP
//         0041a47f     NOP
    return;
}

void RGE_Static_Object::stop() {
    /* TODO: Stub */
//                              void __thiscall stop(RGE_Static_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?stop@RGE_Static_Object@@UAEXXZ                              XREF[5]:     0056ecb4(*), 005702c4(*),
//                               RGE_Static_Object::stop                                                   005709ec(*), 005745d4(*),
//                                                                                                         00574d54(*)
//                              stat_obj.h:161 (1)
//         0041a480     RET
//         0041a481     ??         90h
//         0041a482     NOP
//         0041a483     NOP
//         0041a484     NOP
//         0041a485     NOP
//         0041a486     NOP
//         0041a487     NOP
//         0041a488     NOP
//         0041a489     NOP
//         0041a48a     NOP
//         0041a48b     NOP
//         0041a48c     NOP
//         0041a48d     NOP
//         0041a48e     NOP
//         0041a48f     NOP
    return;
}

void RGE_Static_Object::set_attack(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_attack(RGE_Static_Object * this, RGE_Static_Obje
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//                               ?set_attack@RGE_Static_Object@@UAEXPAV1@@Z                   XREF[5]:     0056ecb8(*), 005702c8(*),
//                               RGE_Static_Object::set_attack                                             005709f0(*), 005745d8(*),
//                                                                                                         00574d58(*)
//                              stat_obj.h:162 (3)
//         0041a490     RET        0x4
//         0041a493     ??         90h
//         0041a494     NOP
//         0041a495     NOP
//         0041a496     NOP
//         0041a497     NOP
//         0041a498     NOP
//         0041a499     NOP
//         0041a49a     NOP
//         0041a49b     NOP
//         0041a49c     NOP
//         0041a49d     NOP
//         0041a49e     NOP
//         0041a49f     NOP
    return;
}

void RGE_Static_Object::play_command_sound() {
    /* TODO: Stub */
//                              void __thiscall play_command_sound(RGE_Static_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?play_command_sound@RGE_Static_Object@@UAEXXZ                XREF[5]:     0056ecbc(*), 005702cc(*),
//                               RGE_Static_Object::play_command_sound                                     005709f4(*), 005745dc(*),
//                                                                                                         00574d5c(*)
//                              stat_obj.h:163 (1)
//         0041a4a0     RET
//         0041a4a1     ??         90h
//         0041a4a2     NOP
//         0041a4a3     NOP
//         0041a4a4     NOP
//         0041a4a5     NOP
//         0041a4a6     NOP
//         0041a4a7     NOP
//         0041a4a8     NOP
//         0041a4a9     NOP
//         0041a4aa     NOP
//         0041a4ab     NOP
//         0041a4ac     NOP
//         0041a4ad     NOP
//         0041a4ae     NOP
//         0041a4af     NOP
    return;
}

void RGE_Static_Object::play_move_sound() {
    /* TODO: Stub */
//                              void __thiscall play_move_sound(RGE_Static_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?play_move_sound@RGE_Static_Object@@UAEXXZ                   XREF[5]:     0056ecc0(*), 005702d0(*),
//                               RGE_Static_Object::play_move_sound                                        005709f8(*), 005745e0(*),
//                                                                                                         00574d60(*)
//                              stat_obj.h:164 (1)
//         0041a4b0     RET
//         0041a4b1     ??         90h
//         0041a4b2     NOP
//         0041a4b3     NOP
//         0041a4b4     NOP
//         0041a4b5     NOP
//         0041a4b6     NOP
//         0041a4b7     NOP
//         0041a4b8     NOP
//         0041a4b9     NOP
//         0041a4ba     NOP
//         0041a4bb     NOP
//         0041a4bc     NOP
//         0041a4bd     NOP
//         0041a4be     NOP
//         0041a4bf     NOP
    return;
}

RGE_Master_Static_Object* RGE_Static_Object::get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              RGE_Master_Static_Object * __thiscall get_command_master(RGE_Static_
//              RGE_Master_Sta    EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?get_command_master@RGE_Static_Object@@UAEPAVRGE_Master_Sta  XREF[5]:     0056eccc(*), 005702dc(*),
//                               RGE_Static_Object::get_command_master                                     00570a04(*), 005745ec(*),
//                                                                                                         00574d6c(*)
//                              stat_obj.h:170 (6)
//         0041a4c0     MOV        EAX,dword ptr [ECX + this->master_obj]
//         0041a4c3     RET        0x10
//         0041a4c6     ??         90h
//         0041a4c7     NOP
//         0041a4c8     NOP
//         0041a4c9     NOP
//         0041a4ca     NOP
//         0041a4cb     NOP
//         0041a4cc     NOP
//         0041a4cd     NOP
//         0041a4ce     NOP
//         0041a4cf     NOP
    return 0;
}

RGE_Static_Object* RGE_Static_Object::get_target_obj() {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall get_target_obj(RGE_Static_Object * th
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?get_target_obj@RGE_Static_Object@@UAEPAV1@XZ                XREF[5]:     0056ecdc(*), 005702ec(*),
//                               RGE_Static_Object::get_target_obj                                         00570a14(*), 005745fc(*),
//                                                                                                         00574d7c(*)
//                              stat_obj.h:184 (3)
//         0041a4d0     XOR        EAX,EAX
//         0041a4d2     RET
//         0041a4d3     ??         90h
//         0041a4d4     NOP
//         0041a4d5     NOP
//         0041a4d6     NOP
//         0041a4d7     NOP
//         0041a4d8     NOP
//         0041a4d9     NOP
//         0041a4da     NOP
//         0041a4db     NOP
//         0041a4dc     NOP
//         0041a4dd     NOP
//         0041a4de     NOP
//         0041a4df     NOP
    return 0;
}

int RGE_Static_Object::inAttackRange(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall inAttackRange(RGE_Static_Object * this, RGE_Static_Ob
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//                               ?inAttackRange@RGE_Static_Object@@UAEHPAV1@@Z                XREF[6]:     0056e504(*), 0056ecf4(*),
//                               RGE_Static_Object::inAttackRange                                          00570304(*), 00570a2c(*),
//                                                                                                         00574614(*), 00574d94(*)
//                              stat_obj.h:208 (5)
//         00405d20     XOR        EAX,EAX
//         00405d22     RET        0x4
//         00405d25     ??         90h
//         00405d26     NOP
//         00405d27     NOP
//         00405d28     NOP
//         00405d29     NOP
//         00405d2a     NOP
//         00405d2b     NOP
//         00405d2c     NOP
//         00405d2d     NOP
//         00405d2e     NOP
//         00405d2f     NOP
    return 0;
}

float RGE_Static_Object::calc_attack_modifier(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              float __thiscall calc_attack_modifier(RGE_Static_Object * this, RGE_
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//                               ?calc_attack_modifier@RGE_Static_Object@@UAEMPAV1@@Z         XREF[6]:     0056e510(*), 0056ed00(*),
//                               RGE_Static_Object::calc_attack_modifier                                   00570310(*), 00570a38(*),
//                                                                                                         00574620(*), 00574da0(*)
//                              stat_obj.h:219 (9)
//         00405d30     FLD        float ptr [DAT_0056e63c]                         = align(2)
//         00405d36     RET        0x4
//         00405d39     ??         90h
//         00405d3a     NOP
//         00405d3b     NOP
//         00405d3c     NOP
//         00405d3d     NOP
//         00405d3e     NOP
//         00405d3f     NOP
    return 0;
}

float RGE_Static_Object::getSpeed() {
    /* TODO: Stub */
//                              float __thiscall getSpeed(RGE_Static_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?getSpeed@RGE_Static_Object@@UBEMXZ                          XREF[2]:     00574624(*), 00574da4(*)
//                               RGE_Static_Object::getSpeed
//                              stat_obj.h:220 (7)
//         004c1ce0     FLD        float ptr [null_00574720]                        = align(4)
//         004c1ce6     RET
//         004c1ce7     ??         90h
//         004c1ce8     NOP
//         004c1ce9     NOP
//         004c1cea     NOP
//         004c1ceb     NOP
//         004c1cec     NOP
//         004c1ced     NOP
//         004c1cee     NOP
//         004c1cef     NOP
    return 0;
}

float RGE_Static_Object::getAngle() {
    /* TODO: Stub */
//                              float __thiscall getAngle(RGE_Static_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?getAngle@RGE_Static_Object@@UBEMXZ                          XREF[4]:     0056ed08(*), 00570318(*),
//                               RGE_Static_Object::getAngle                                               00574628(*), 00574da8(*)
//                              stat_obj.h:221 (7)
//         0041a4e0     FLD        float ptr [DAT_0056ee00]
//         0041a4e6     RET
//         0041a4e7     ??         90h
//         0041a4e8     NOP
//         0041a4e9     NOP
//         0041a4ea     NOP
//         0041a4eb     NOP
//         0041a4ec     NOP
//         0041a4ed     NOP
//         0041a4ee     NOP
//         0041a4ef     NOP
    return 0;
}

float RGE_Static_Object::maximumSpeed() {
    /* TODO: Stub */
//                              float __thiscall maximumSpeed(RGE_Static_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?maximumSpeed@RGE_Static_Object@@UAEMXZ                      XREF[4]:     0056ed0c(*), 0057031c(*),
//                               RGE_Static_Object::maximumSpeed                                           0057462c(*), 00574dac(*)
//                              stat_obj.h:222 (7)
//         0041a4f0     FLD        float ptr [DAT_0056ee00]
//         0041a4f6     RET
//         0041a4f7     ??         90h
//         0041a4f8     NOP
//         0041a4f9     NOP
//         0041a4fa     NOP
//         0041a4fb     NOP
//         0041a4fc     NOP
//         0041a4fd     NOP
//         0041a4fe     NOP
//         0041a4ff     NOP
    return 0;
}

float RGE_Static_Object::rateOfFire() {
    /* TODO: Stub */
//                              float __thiscall rateOfFire(RGE_Static_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?rateOfFire@RGE_Static_Object@@UAEMXZ                        XREF[6]:     0056e520(*), 0056ed10(*),
//                               RGE_Static_Object::rateOfFire                                             00570320(*), 00570a48(*),
//                                                                                                         00574630(*), 00574db0(*)
//                              stat_obj.h:223 (7)
//         00405d40     FLD        float ptr [DAT_0056e640]
//         00405d46     RET
//         00405d47     ??         90h
//         00405d48     NOP
//         00405d49     NOP
//         00405d4a     NOP
//         00405d4b     NOP
//         00405d4c     NOP
//         00405d4d     NOP
//         00405d4e     NOP
//         00405d4f     NOP
    return 0;
}

float RGE_Static_Object::damageCapability() {
    /* TODO: Stub */
//                              float __thiscall damageCapability(RGE_Static_Object * this, RGE_Stat
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//                               ?damageCapability@RGE_Static_Object@@UAEMPAV1@@Z             XREF[6]:     0056e524(*), 0056ed14(*),
//                               RGE_Static_Object::damageCapability                                       00570324(*), 00570a4c(*),
//                                                                                                         00574634(*), 00574db4(*)
//                              stat_obj.h:225 (9)
//         00405d60     FLD        float ptr [DAT_0056e640]
//         00405d66     RET        0x4
//         00405d69     ??         90h
//         00405d6a     NOP
//         00405d6b     NOP
//         00405d6c     NOP
//         00405d6d     NOP
//         00405d6e     NOP
//         00405d6f     NOP
    return 0;
}

float RGE_Static_Object::damageCapability(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              float __thiscall damageCapability(RGE_Static_Object * this, RGE_Stat
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//                               ?damageCapability@RGE_Static_Object@@UAEMPAV1@@Z             XREF[6]:     0056e524(*), 0056ed14(*),
//                               RGE_Static_Object::damageCapability                                       00570324(*), 00570a4c(*),
//                                                                                                         00574634(*), 00574db4(*)
//                              stat_obj.h:225 (9)
//         00405d60     FLD        float ptr [DAT_0056e640]
//         00405d66     RET        0x4
//         00405d69     ??         90h
//         00405d6a     NOP
//         00405d6b     NOP
//         00405d6c     NOP
//         00405d6d     NOP
//         00405d6e     NOP
//         00405d6f     NOP
    return 0;
}

float RGE_Static_Object::weaponRange() {
    /* TODO: Stub */
//                              float __thiscall weaponRange(RGE_Static_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?weaponRange@RGE_Static_Object@@UAEMXZ                       XREF[6]:     0056e52c(*), 0056ed1c(*),
//                               RGE_Static_Object::weaponRange                                            0057032c(*), 00570a54(*),
//                                                                                                         0057463c(*), 00574dbc(*)
//                              stat_obj.h:226 (7)
//         00405d70     FLD        float ptr [DAT_0056e640]
//         00405d76     RET
//         00405d77     ??         90h
//         00405d78     NOP
//         00405d79     NOP
//         00405d7a     NOP
//         00405d7b     NOP
//         00405d7c     NOP
//         00405d7d     NOP
//         00405d7e     NOP
//         00405d7f     NOP
    return 0;
}

float RGE_Static_Object::minimumWeaponRange() {
    /* TODO: Stub */
//                              float __thiscall minimumWeaponRange(RGE_Static_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?minimumWeaponRange@RGE_Static_Object@@UAEMXZ                XREF[6]:     0056e530(*), 0056ed20(*),
//                               RGE_Static_Object::minimumWeaponRange                                     00570330(*), 00570a58(*),
//                                                                                                         00574640(*), 00574dc0(*)
//                              stat_obj.h:227 (7)
//         00405d80     FLD        float ptr [DAT_0056e640]
//         00405d86     RET
//         00405d87     ??         90h
//         00405d88     NOP
//         00405d89     NOP
//         00405d8a     NOP
//         00405d8b     NOP
//         00405d8c     NOP
//         00405d8d     NOP
//         00405d8e     NOP
//         00405d8f     NOP
    return 0;
}

int RGE_Static_Object::passableTile(float param_1, float param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall passableTile(RGE_Static_Object * this, float param_1,
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//                               ?passableTile@RGE_Static_Object@@UAEHMMH@Z                   XREF[4]:     0056ed24(*), 00570334(*),
//                               RGE_Static_Object::passableTile                                           00574644(*), 00574dc4(*)
//                              stat_obj.h:228 (5)
//         0041a500     XOR        EAX,EAX
//         0041a502     RET        0xc
//         0041a505     ??         90h
//         0041a506     NOP
//         0041a507     NOP
//         0041a508     NOP
//         0041a509     NOP
//         0041a50a     NOP
//         0041a50b     NOP
//         0041a50c     NOP
//         0041a50d     NOP
//         0041a50e     NOP
//         0041a50f     NOP
    return 0;
}

uchar RGE_Static_Object::facetToNextWaypoint() {
    /* TODO: Stub */
//                              uchar __thiscall facetToNextWaypoint(RGE_Static_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?facetToNextWaypoint@RGE_Static_Object@@UBEEXZ               XREF[4]:     0056ed28(*), 00570338(*),
//                               RGE_Static_Object::facetToNextWaypoint                                    00574648(*), 00574dc8(*)
//                              stat_obj.h:231 (3)
//         0041a510     OR         AL,0xff
//         0041a512     RET
//         0041a513     ??         90h
//         0041a514     NOP
//         0041a515     NOP
//         0041a516     NOP
//         0041a517     NOP
//         0041a518     NOP
//         0041a519     NOP
//         0041a51a     NOP
//         0041a51b     NOP
//         0041a51c     NOP
//         0041a51d     NOP
//         0041a51e     NOP
//         0041a51f     NOP
    return 0;
}

int RGE_Static_Object::currentTargetID() {
    /* TODO: Stub */
//                              int __thiscall currentTargetID(RGE_Static_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?currentTargetID@RGE_Static_Object@@UBEHXZ                   XREF[6]:     0056e53c(*), 0056ed2c(*),
//                               RGE_Static_Object::currentTargetID                                        0057033c(*), 00570a64(*),
//                                                                                                         0057464c(*), 00574dcc(*)
//                              stat_obj.h:232 (4)
//         00405d90     OR         EAX,0xffffffff
//         00405d93     RET
//         00405d94     ??         90h
//         00405d95     NOP
//         00405d96     NOP
//         00405d97     NOP
//         00405d98     NOP
//         00405d99     NOP
//         00405d9a     NOP
//         00405d9b     NOP
//         00405d9c     NOP
//         00405d9d     NOP
//         00405d9e     NOP
//         00405d9f     NOP
    return 0;
}

float RGE_Static_Object::currentTargetX() {
    /* TODO: Stub */
//                              float __thiscall currentTargetX(RGE_Static_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?currentTargetX@RGE_Static_Object@@UBEMXZ                    XREF[6]:     0056e540(*), 0056ed30(*),
//                               RGE_Static_Object::currentTargetX                                         00570340(*), 00570a68(*),
//                                                                                                         00574650(*), 00574dd0(*)
//                              stat_obj.h:233 (7)
//         00405da0     FLD        float ptr [DAT_0056e644]
//         00405da6     RET
//         00405da7     ??         90h
//         00405da8     NOP
//         00405da9     NOP
//         00405daa     NOP
//         00405dab     NOP
//         00405dac     NOP
//         00405dad     NOP
//         00405dae     NOP
//         00405daf     NOP
    return 0;
}

float RGE_Static_Object::currentTargetY() {
    /* TODO: Stub */
//                              float __thiscall currentTargetY(RGE_Static_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?currentTargetY@RGE_Static_Object@@UBEMXZ                    XREF[6]:     0056e544(*), 0056ed34(*),
//                               RGE_Static_Object::currentTargetY                                         00570344(*), 00570a6c(*),
//                                                                                                         00574654(*), 00574dd4(*)
//                              stat_obj.h:234 (7)
//         00405db0     FLD        float ptr [DAT_0056e644]
//         00405db6     RET
//         00405db7     ??         90h
//         00405db8     NOP
//         00405db9     NOP
//         00405dba     NOP
//         00405dbb     NOP
//         00405dbc     NOP
//         00405dbd     NOP
//         00405dbe     NOP
//         00405dbf     NOP
    return 0;
}

float RGE_Static_Object::currentTargetZ() {
    /* TODO: Stub */
//                              float __thiscall currentTargetZ(RGE_Static_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?currentTargetZ@RGE_Static_Object@@UBEMXZ                    XREF[6]:     0056e548(*), 0056ed38(*),
//                               RGE_Static_Object::currentTargetZ                                         00570348(*), 00570a70(*),
//                                                                                                         00574658(*), 00574dd8(*)
//                              stat_obj.h:235 (7)
//         00405dc0     FLD        float ptr [DAT_0056e644]
//         00405dc6     RET
//         00405dc7     ??         90h
//         00405dc8     NOP
//         00405dc9     NOP
//         00405dca     NOP
//         00405dcb     NOP
//         00405dcc     NOP
//         00405dcd     NOP
//         00405dce     NOP
//         00405dcf     NOP
    return 0;
}

void RGE_Static_Object::setWaitingToMove(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall setWaitingToMove(RGE_Static_Object * this, uchar par
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//                               ?setWaitingToMove@RGE_Static_Object@@UAEXE@Z                 XREF[4]:     0056ed3c(*), 0057034c(*),
//                               RGE_Static_Object::setWaitingToMove                                       0057465c(*), 00574ddc(*)
//                              stat_obj.h:236 (3)
//         0041a520     RET        0x4
//         0041a523     ??         90h
//         0041a524     NOP
//         0041a525     NOP
//         0041a526     NOP
//         0041a527     NOP
//         0041a528     NOP
//         0041a529     NOP
//         0041a52a     NOP
//         0041a52b     NOP
//         0041a52c     NOP
//         0041a52d     NOP
//         0041a52e     NOP
//         0041a52f     NOP
    return;
}

uchar RGE_Static_Object::waitingToMove() {
    /* TODO: Stub */
//                              uchar __thiscall waitingToMove(RGE_Static_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?waitingToMove@RGE_Static_Object@@UBEEXZ                     XREF[4]:     0056ed40(*), 00570350(*),
//                               RGE_Static_Object::waitingToMove                                          00574660(*), 00574de0(*)
//                              stat_obj.h:237 (3)
//         0041a530     XOR        AL,AL
//         0041a532     RET
//         0041a533     ??         90h
//         0041a534     NOP
//         0041a535     NOP
//         0041a536     NOP
//         0041a537     NOP
//         0041a538     NOP
//         0041a539     NOP
//         0041a53a     NOP
//         0041a53b     NOP
//         0041a53c     NOP
//         0041a53d     NOP
//         0041a53e     NOP
//         0041a53f     NOP
    return 0;
}

uchar RGE_Static_Object::actionState() {
    /* TODO: Stub */
//                              uchar __thiscall actionState(RGE_Static_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?actionState@RGE_Static_Object@@UBEEXZ                       XREF[5]:     0056ed44(*), 00570354(*),
//                               RGE_Static_Object::actionState                                            00570a7c(*), 00574664(*),
//                                                                                                         00574de4(*)
//                              stat_obj.h:238 (3)
//         0041a540     XOR        AL,AL
//         0041a542     RET
//         0041a543     ??         90h
//         0041a544     NOP
//         0041a545     NOP
//         0041a546     NOP
//         0041a547     NOP
//         0041a548     NOP
//         0041a549     NOP
//         0041a54a     NOP
//         0041a54b     NOP
//         0041a54c     NOP
//         0041a54d     NOP
//         0041a54e     NOP
//         0041a54f     NOP
    return 0;
}

uchar RGE_Static_Object::keepGatheringWhenObjectIsOut(int param_1) {
    /* TODO: Stub */
//                              uchar __thiscall keepGatheringWhenObjectIsOut(RGE_Static_Object * th
//              uchar             AL:1           <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?keepGatheringWhenObjectIsOut@RGE_Static_Object@@UBEEH@Z     XREF[8]:     0056e558(*), 0056ed48(*),
//                               RGE_Static_Object::keepGatheringWhenObjectIsOut                           0056f390(*), 00570358(*),
//                                                                                                         00570828(*), 00570a80(*),
//                                                                                                         00574668(*), 00574de8(*)
//                              stat_obj.h:239 (5)
//         00405dd0     XOR        AL,AL
//         00405dd2     RET        0x4
//         00405dd5     ??         90h
//         00405dd6     NOP
//         00405dd7     NOP
//         00405dd8     NOP
//         00405dd9     NOP
//         00405dda     NOP
//         00405ddb     NOP
//         00405ddc     NOP
//         00405ddd     NOP
//         00405dde     NOP
//         00405ddf     NOP
    return 0;
}

uchar RGE_Static_Object::produceWhenKilledBy(int param_1) {
    /* TODO: Stub */
//                              uchar __thiscall produceWhenKilledBy(RGE_Static_Object * this, int p
//              uchar             AL:1           <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?produceWhenKilledBy@RGE_Static_Object@@UBEEH@Z              XREF[8]:     0056e55c(*), 0056ed4c(*),
//                               RGE_Static_Object::produceWhenKilledBy                                    0056f394(*), 0057035c(*),
//                                                                                                         0057082c(*), 00570a84(*),
//                                                                                                         0057466c(*), 00574dec(*)
//                              stat_obj.h:240 (5)
//         00405de0     MOV        AL,0x1
//         00405de2     RET        0x4
//         00405de5     ??         90h
//         00405de6     NOP
//         00405de7     NOP
//         00405de8     NOP
//         00405de9     NOP
//         00405dea     NOP
//         00405deb     NOP
//         00405dec     NOP
//         00405ded     NOP
//         00405dee     NOP
//         00405def     NOP
    return 0;
}

uchar RGE_Static_Object::useSameZoneDropsite() {
    /* TODO: Stub */
//                              uchar __thiscall useSameZoneDropsite(RGE_Static_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?useSameZoneDropsite@RGE_Static_Object@@UBEEXZ               XREF[8]:     0056e560(*), 0056ed50(*),
//                               RGE_Static_Object::useSameZoneDropsite                                    0056f398(*), 00570360(*),
//                                                                                                         00570830(*), 00570a88(*),
//                                                                                                         00574670(*), 00574df0(*)
//                              stat_obj.h:241 (3)
//         00405df0     MOV        AL,0x1
//         00405df2     RET
//         00405df3     ??         90h
//         00405df4     NOP
//         00405df5     NOP
//         00405df6     NOP
//         00405df7     NOP
//         00405df8     NOP
//         00405df9     NOP
//         00405dfa     NOP
//         00405dfb     NOP
//         00405dfc     NOP
//         00405dfd     NOP
//         00405dfe     NOP
//         00405dff     NOP
    return 0;
}

void RGE_Static_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
//                              void __thiscall notify(RGE_Static_Object * this, int param_1, int pa
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//              long              Stack[0x14]:4  param_5
//              long              Stack[0x18]:4  param_6
//                               ?notify@RGE_Static_Object@@UAEXHHHJJJ@Z                      XREF[6]:     0056e568(*), 0056ed58(*),
//                               RGE_Static_Object::notify                                                 00570368(*), 00570a90(*),
//                                                                                                         00574678(*), 00574df8(*)
//                              stat_obj.h:253 (3)
//         00405e00     RET        0x18
//         00405e03     ??         90h
//         00405e04     NOP
//         00405e05     NOP
//         00405e06     NOP
//         00405e07     NOP
//         00405e08     NOP
//         00405e09     NOP
//         00405e0a     NOP
//         00405e0b     NOP
//         00405e0c     NOP
//         00405e0d     NOP
//         00405e0e     NOP
//         00405e0f     NOP
    return;
}

int RGE_Static_Object::attack(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall attack(RGE_Static_Object * this, float param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?attack@RGE_Static_Object@@UAEHMMMH@Z                        XREF[6]:     0056e56c(*), 0056ed5c(*),
//                               RGE_Static_Object::attack                                                 0057036c(*), 00570a94(*),
//                                                                                                         0057467c(*), 00574dfc(*)
//                              stat_obj.h:256 (5)
//         00405e20     XOR        EAX,EAX
//         00405e22     RET        0x10
//         00405e25     ??         90h
//         00405e26     NOP
//         00405e27     NOP
//         00405e28     NOP
//         00405e29     NOP
//         00405e2a     NOP
//         00405e2b     NOP
//         00405e2c     NOP
//         00405e2d     NOP
//         00405e2e     NOP
//         00405e2f     NOP
    return 0;
}

int RGE_Static_Object::attack(float param_1, float param_2, float param_3, int param_4) {
    /* TODO: Stub */
//                              int __thiscall attack(RGE_Static_Object * this, float param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?attack@RGE_Static_Object@@UAEHMMMH@Z                        XREF[6]:     0056e56c(*), 0056ed5c(*),
//                               RGE_Static_Object::attack                                                 0057036c(*), 00570a94(*),
//                                                                                                         0057467c(*), 00574dfc(*)
//                              stat_obj.h:256 (5)
//         00405e20     XOR        EAX,EAX
//         00405e22     RET        0x10
//         00405e25     ??         90h
//         00405e26     NOP
//         00405e27     NOP
//         00405e28     NOP
//         00405e29     NOP
//         00405e2a     NOP
//         00405e2b     NOP
//         00405e2c     NOP
//         00405e2d     NOP
//         00405e2e     NOP
//         00405e2f     NOP
    return 0;
}

int RGE_Static_Object::moveTo(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall moveTo(RGE_Static_Object * this, float param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?moveTo@RGE_Static_Object@@UAEHMMMMH@Z                       XREF[6]:     0056e574(*), 0056ed64(*),
//                               RGE_Static_Object::moveTo                                                 00570374(*), 00570a9c(*),
//                                                                                                         00574684(*), 00574e04(*)
//                              stat_obj.h:259 (5)
//         00405e50     XOR        EAX,EAX
//         00405e52     RET        0x14
//         00405e55     ??         90h
//         00405e56     NOP
//         00405e57     NOP
//         00405e58     NOP
//         00405e59     NOP
//         00405e5a     NOP
//         00405e5b     NOP
//         00405e5c     NOP
//         00405e5d     NOP
//         00405e5e     NOP
//         00405e5f     NOP
    return 0;
}

int RGE_Static_Object::moveTo(int param_1, float param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall moveTo(RGE_Static_Object * this, float param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?moveTo@RGE_Static_Object@@UAEHMMMMH@Z                       XREF[6]:     0056e574(*), 0056ed64(*),
//                               RGE_Static_Object::moveTo                                                 00570374(*), 00570a9c(*),
//                                                                                                         00574684(*), 00574e04(*)
//                              stat_obj.h:259 (5)
//         00405e50     XOR        EAX,EAX
//         00405e52     RET        0x14
//         00405e55     ??         90h
//         00405e56     NOP
//         00405e57     NOP
//         00405e58     NOP
//         00405e59     NOP
//         00405e5a     NOP
//         00405e5b     NOP
//         00405e5c     NOP
//         00405e5d     NOP
//         00405e5e     NOP
//         00405e5f     NOP
    return 0;
}

int RGE_Static_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall moveTo(RGE_Static_Object * this, float param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?moveTo@RGE_Static_Object@@UAEHMMMMH@Z                       XREF[6]:     0056e574(*), 0056ed64(*),
//                               RGE_Static_Object::moveTo                                                 00570374(*), 00570a9c(*),
//                                                                                                         00574684(*), 00574e04(*)
//                              stat_obj.h:259 (5)
//         00405e50     XOR        EAX,EAX
//         00405e52     RET        0x14
//         00405e55     ??         90h
//         00405e56     NOP
//         00405e57     NOP
//         00405e58     NOP
//         00405e59     NOP
//         00405e5a     NOP
//         00405e5b     NOP
//         00405e5c     NOP
//         00405e5d     NOP
//         00405e5e     NOP
//         00405e5f     NOP
    return 0;
}

int RGE_Static_Object::moveAwayFrom(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall moveAwayFrom(RGE_Static_Object * this, int param_1, i
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?moveAwayFrom@RGE_Static_Object@@UAEHHH@Z                    XREF[6]:     0056e580(*), 0056ed70(*),
//                               RGE_Static_Object::moveAwayFrom                                           00570380(*), 00570aa8(*),
//                                                                                                         00574690(*), 00574e10(*)
//                              stat_obj.h:260 (5)
//         00405e60     XOR        EAX,EAX
//         00405e62     RET        0x8
//         00405e65     ??         90h
//         00405e66     NOP
//         00405e67     NOP
//         00405e68     NOP
//         00405e69     NOP
//         00405e6a     NOP
//         00405e6b     NOP
//         00405e6c     NOP
//         00405e6d     NOP
//         00405e6e     NOP
//         00405e6f     NOP
    return 0;
}

int RGE_Static_Object::hunt(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall hunt(RGE_Static_Object * this, int param_1, int param
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?hunt@RGE_Static_Object@@UAEHHH@Z                            XREF[8]:     0056e584(*), 0056ed74(*),
//                               RGE_Static_Object::hunt                                                   0056f3bc(*), 00570384(*),
//                                                                                                         00570854(*), 00570aac(*),
//                                                                                                         00574694(*), 00574e14(*)
//                              stat_obj.h:261 (5)
//         00405e70     XOR        EAX,EAX
//         00405e72     RET        0x8
//         00405e75     ??         90h
//         00405e76     NOP
//         00405e77     NOP
//         00405e78     NOP
//         00405e79     NOP
//         00405e7a     NOP
//         00405e7b     NOP
//         00405e7c     NOP
//         00405e7d     NOP
//         00405e7e     NOP
//         00405e7f     NOP
    return 0;
}

int RGE_Static_Object::gather(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall gather(RGE_Static_Object * this, int param_1, int par
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?gather@RGE_Static_Object@@UAEHHH@Z                          XREF[6]:     0056e588(*), 0056ed78(*),
//                               RGE_Static_Object::gather                                                 00570388(*), 00570ab0(*),
//                                                                                                         00574698(*), 00574e18(*)
//                              stat_obj.h:262 (5)
//         00405e80     XOR        EAX,EAX
//         00405e82     RET        0x8
//         00405e85     ??         90h
//         00405e86     NOP
//         00405e87     NOP
//         00405e88     NOP
//         00405e89     NOP
//         00405e8a     NOP
//         00405e8b     NOP
//         00405e8c     NOP
//         00405e8d     NOP
//         00405e8e     NOP
//         00405e8f     NOP
    return 0;
}

int RGE_Static_Object::convert(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall convert(RGE_Static_Object * this, int param_1, int pa
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?convert@RGE_Static_Object@@UAEHHH@Z                         XREF[8]:     0056e58c(*), 0056ed7c(*),
//                               RGE_Static_Object::convert                                                0056f3c4(*), 0057038c(*),
//                                                                                                         0057085c(*), 00570ab4(*),
//                                                                                                         0057469c(*), 00574e1c(*)
//                              stat_obj.h:263 (5)
//         00405e90     XOR        EAX,EAX
//         00405e92     RET        0x8
//         00405e95     ??         90h
//         00405e96     NOP
//         00405e97     NOP
//         00405e98     NOP
//         00405e99     NOP
//         00405e9a     NOP
//         00405e9b     NOP
//         00405e9c     NOP
//         00405e9d     NOP
//         00405e9e     NOP
//         00405e9f     NOP
    return 0;
}

int RGE_Static_Object::repair(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall repair(RGE_Static_Object * this, int param_1, int par
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?repair@RGE_Static_Object@@UAEHHH@Z                          XREF[8]:     0056e590(*), 0056ed80(*),
//                               RGE_Static_Object::repair                                                 0056f3c8(*), 00570390(*),
//                                                                                                         00570860(*), 00570ab8(*),
//                                                                                                         005746a0(*), 00574e20(*)
//                              stat_obj.h:265 (5)
//         00405eb0     XOR        EAX,EAX
//         00405eb2     RET        0x8
//         00405eb5     ??         90h
//         00405eb6     NOP
//         00405eb7     NOP
//         00405eb8     NOP
//         00405eb9     NOP
//         00405eba     NOP
//         00405ebb     NOP
//         00405ebc     NOP
//         00405ebd     NOP
//         00405ebe     NOP
//         00405ebf     NOP
    return 0;
}

int RGE_Static_Object::build(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall build(RGE_Static_Object * this, int param_1, int para
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?build@RGE_Static_Object@@UAEHHH@Z                           XREF[8]:     0056e594(*), 0056ed84(*),
//                               RGE_Static_Object::build                                                  0056f3cc(*), 00570394(*),
//                                                                                                         00570864(*), 00570abc(*),
//                                                                                                         005746a4(*), 00574e24(*)
//                              stat_obj.h:266 (5)
//         00405ec0     XOR        EAX,EAX
//         00405ec2     RET        0x8
//         00405ec5     ??         90h
//         00405ec6     NOP
//         00405ec7     NOP
//         00405ec8     NOP
//         00405ec9     NOP
//         00405eca     NOP
//         00405ecb     NOP
//         00405ecc     NOP
//         00405ecd     NOP
//         00405ece     NOP
//         00405ecf     NOP
    return 0;
}

int RGE_Static_Object::trade(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall trade(RGE_Static_Object * this, int param_1, int para
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?trade@RGE_Static_Object@@UAEHHH@Z                           XREF[8]:     0056e598(*), 0056ed88(*),
//                               RGE_Static_Object::trade                                                  0056f3d0(*), 00570398(*),
//                                                                                                         00570868(*), 00570ac0(*),
//                                                                                                         005746a8(*), 00574e28(*)
//                              stat_obj.h:267 (5)
//         00405ed0     XOR        EAX,EAX
//         00405ed2     RET        0x8
//         00405ed5     ??         90h
//         00405ed6     NOP
//         00405ed7     NOP
//         00405ed8     NOP
//         00405ed9     NOP
//         00405eda     NOP
//         00405edb     NOP
//         00405edc     NOP
//         00405edd     NOP
//         00405ede     NOP
//         00405edf     NOP
    return 0;
}

int RGE_Static_Object::explore(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall explore(RGE_Static_Object * this, int param_1, int pa
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//                               ?explore@RGE_Static_Object@@UAEHHHH@Z                        XREF[6]:     0056e59c(*), 0056ed8c(*),
//                               RGE_Static_Object::explore                                                0057039c(*), 00570ac4(*),
//                                                                                                         005746ac(*), 00574e2c(*)
//                              stat_obj.h:268 (5)
//         00405ee0     XOR        EAX,EAX
//         00405ee2     RET        0xc
//         00405ee5     ??         90h
//         00405ee6     NOP
//         00405ee7     NOP
//         00405ee8     NOP
//         00405ee9     NOP
//         00405eea     NOP
//         00405eeb     NOP
//         00405eec     NOP
//         00405eed     NOP
//         00405eee     NOP
//         00405eef     NOP
    return 0;
}

int RGE_Static_Object::enter(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall enter(RGE_Static_Object * this, int param_1, int para
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?enter@RGE_Static_Object@@UAEHHH@Z                           XREF[6]:     0056e5a0(*), 0056ed90(*),
//                               RGE_Static_Object::enter                                                  005703a0(*), 00570ac8(*),
//                                                                                                         005746b0(*), 00574e30(*)
//                              stat_obj.h:269 (5)
//         00405ef0     XOR        EAX,EAX
//         00405ef2     RET        0x8
//         00405ef5     ??         90h
//         00405ef6     NOP
//         00405ef7     NOP
//         00405ef8     NOP
//         00405ef9     NOP
//         00405efa     NOP
//         00405efb     NOP
//         00405efc     NOP
//         00405efd     NOP
//         00405efe     NOP
//         00405eff     NOP
    return 0;
}

int RGE_Static_Object::unload(int param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall unload(RGE_Static_Object * this, int param_1, float p
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?unload@RGE_Static_Object@@UAEHHMMM@Z                        XREF[6]:     0056e5a4(*), 0056ed94(*),
//                               RGE_Static_Object::unload                                                 005703a4(*), 00570acc(*),
//                                                                                                         005746b4(*), 00574e34(*)
//                              stat_obj.h:270 (5)
//         00405f00     XOR        EAX,EAX
//         00405f02     RET        0x10
//         00405f05     ??         90h
//         00405f06     NOP
//         00405f07     NOP
//         00405f08     NOP
//         00405f09     NOP
//         00405f0a     NOP
//         00405f0b     NOP
//         00405f0c     NOP
//         00405f0d     NOP
//         00405f0e     NOP
//         00405f0f     NOP
    return 0;
}

int RGE_Static_Object::transport(float param_1, float param_2, float param_3, int param_4) {
    /* TODO: Stub */
//                              int __thiscall transport(RGE_Static_Object * this, float param_1, fl
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?transport@RGE_Static_Object@@UAEHMMMH@Z                     XREF[6]:     0056e5a8(*), 0056ed98(*),
//                               RGE_Static_Object::transport                                              005703a8(*), 00570ad0(*),
//                                                                                                         005746b8(*), 00574e38(*)
//                              stat_obj.h:271 (5)
//         00405f10     XOR        EAX,EAX
//         00405f12     RET        0x10
//         00405f15     ??         90h
//         00405f16     NOP
//         00405f17     NOP
//         00405f18     NOP
//         00405f19     NOP
//         00405f1a     NOP
//         00405f1b     NOP
//         00405f1c     NOP
//         00405f1d     NOP
//         00405f1e     NOP
//         00405f1f     NOP
    return 0;
}

int RGE_Static_Object::stopAction() {
    /* TODO: Stub */
//                              int __thiscall stopAction(RGE_Static_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?stopAction@RGE_Static_Object@@UAEHXZ                        XREF[6]:     0056e5ac(*), 0056ed9c(*),
//                               RGE_Static_Object::stopAction                                             005703ac(*), 00570ad4(*),
//                                                                                                         005746bc(*), 00574e3c(*)
//                              stat_obj.h:272 (3)
//         00405f20     XOR        EAX,EAX
//         00405f22     RET
//         00405f23     ??         90h
//         00405f24     NOP
//         00405f25     NOP
//         00405f26     NOP
//         00405f27     NOP
//         00405f28     NOP
//         00405f29     NOP
//         00405f2a     NOP
//         00405f2b     NOP
//         00405f2c     NOP
//         00405f2d     NOP
//         00405f2e     NOP
//         00405f2f     NOP
    return 0;
}

int RGE_Static_Object::pause() {
    /* TODO: Stub */
//                              int __thiscall pause(RGE_Static_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?pause@RGE_Static_Object@@UAEHXZ                             XREF[6]:     0056e5b0(*), 0056eda0(*),
//                               RGE_Static_Object::pause                                                  005703b0(*), 00570ad8(*),
//                                                                                                         005746c0(*), 00574e40(*)
//                              stat_obj.h:273 (3)
//         00405f30     XOR        EAX,EAX
//         00405f32     RET
//         00405f33     ??         90h
//         00405f34     NOP
//         00405f35     NOP
//         00405f36     NOP
//         00405f37     NOP
//         00405f38     NOP
//         00405f39     NOP
//         00405f3a     NOP
//         00405f3b     NOP
//         00405f3c     NOP
//         00405f3d     NOP
//         00405f3e     NOP
//         00405f3f     NOP
    return 0;
}

int RGE_Static_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              int __thiscall canPath(RGE_Static_Object * this, int param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float *           Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//              int               Stack[0x18]:4  param_6
//                               ?canPath@RGE_Static_Object@@UAEHHMPAMHHH@Z                   XREF[4]:     0056eda4(*), 005703b4(*),
//                               RGE_Static_Object::canPath                                                005746c4(*), 00574e44(*)
//                              stat_obj.h:283 (5)
//         0041a560     XOR        EAX,EAX
//         0041a562     RET        0x18
//         0041a565     ??         90h
//         0041a566     NOP
//         0041a567     NOP
//         0041a568     NOP
//         0041a569     NOP
//         0041a56a     NOP
//         0041a56b     NOP
//         0041a56c     NOP
//         0041a56d     NOP
//         0041a56e     NOP
//         0041a56f     NOP
    return 0;
}

int RGE_Static_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
//                              int __thiscall canPath(RGE_Static_Object * this, int param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float *           Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//              int               Stack[0x18]:4  param_6
//                               ?canPath@RGE_Static_Object@@UAEHHMPAMHHH@Z                   XREF[4]:     0056eda4(*), 005703b4(*),
//                               RGE_Static_Object::canPath                                                005746c4(*), 00574e44(*)
//                              stat_obj.h:283 (5)
//         0041a560     XOR        EAX,EAX
//         0041a562     RET        0x18
//         0041a565     ??         90h
//         0041a566     NOP
//         0041a567     NOP
//         0041a568     NOP
//         0041a569     NOP
//         0041a56a     NOP
//         0041a56b     NOP
//         0041a56c     NOP
//         0041a56d     NOP
//         0041a56e     NOP
//         0041a56f     NOP
    return 0;
}

int RGE_Static_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              int __thiscall canBidirectionPath(RGE_Static_Object * this, int para
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float *           Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//              int               Stack[0x18]:4  param_6
//              int               Stack[0x1c]:4  param_7
//                               ?canBidirectionPath@RGE_Static_Object@@UAEHHHMPAMHHH@Z       XREF[4]:     0056edac(*), 005703bc(*),
//                               RGE_Static_Object::canBidirectionPath                                     005746cc(*), 00574e4c(*)
//                              stat_obj.h:284 (5)
//         0041a570     XOR        EAX,EAX
//         0041a572     RET        0x1c
//         0041a575     ??         90h
//         0041a576     NOP
//         0041a577     NOP
//         0041a578     NOP
//         0041a579     NOP
//         0041a57a     NOP
//         0041a57b     NOP
//         0041a57c     NOP
//         0041a57d     NOP
//         0041a57e     NOP
//         0041a57f     NOP
    return 0;
}

int RGE_Static_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray_int* param_7) {
    /* TODO: Stub */
//                              int __thiscall canPathWithObstructions(RGE_Static_Object * this, int
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float *           Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//              int               Stack[0x18]:4  param_6
//              ManagedArray<i    Stack[0x1c]:4  param_7
//                               ?canPathWithObstructions@RGE_Static_Object@@UAEHHMPAMHHHAAV  XREF[4]:     0056edb0(*), 005703c0(*),
//                               RGE_Static_Object::canPathWithObstructions                                005746d0(*), 00574e50(*)
//                              stat_obj.h:285 (5)
//         0041a580     XOR        EAX,EAX
//         0041a582     RET        0x1c
//         0041a585     ??         90h
//         0041a586     NOP
//         0041a587     NOP
//         0041a588     NOP
//         0041a589     NOP
//         0041a58a     NOP
//         0041a58b     NOP
//         0041a58c     NOP
//         0041a58d     NOP
//         0041a58e     NOP
//         0041a58f     NOP
    return 0;
}

int RGE_Static_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) {
    /* TODO: Stub */
//                              int __thiscall canPathWithAdditionalPassability(RGE_Static_Object *
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              XYZPoint          Stack[0x4]:12  param_1
//              float             Stack[0x10]:4  param_2
//              int               Stack[0x14]:4  param_3
//              float *           Stack[0x18]:4  param_4
//              int               Stack[0x1c]:4  param_5
//              int               Stack[0x20]:4  param_6
//              int               Stack[0x24]:4  param_7
//              int               Stack[0x28]:4  param_8
//              int               Stack[0x2c]:4  param_9
//                               ?canPathWithAdditionalPassability@RGE_Static_Object@@UAEHUX  XREF[4]:     0056edb4(*), 005703c4(*),
//                               RGE_Static_Object::canPathWithAdditionalPassability                       005746d4(*), 00574e54(*)
//                              stat_obj.h:286 (5)
//         0041a590     XOR        EAX,EAX
//         0041a592     RET        0x2c
//         0041a595     ??         90h
//         0041a596     NOP
//         0041a597     NOP
//         0041a598     NOP
//         0041a599     NOP
//         0041a59a     NOP
//         0041a59b     NOP
//         0041a59c     NOP
//         0041a59d     NOP
//         0041a59e     NOP
//         0041a59f     NOP
    return 0;
}

int RGE_Static_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) {
    /* TODO: Stub */
//                              int __thiscall findFirstTerrainAlongExceptionPath(RGE_Static_Object
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              float *           Stack[0x8]:4   param_2
//              float *           Stack[0xc]:4   param_3
//                               ?findFirstTerrainAlongExceptionPath@RGE_Static_Object@@UAEH  XREF[4]:     0056edb8(*), 005703c8(*),
//                               RGE_Static_Object::findFirstTerrainAlongExceptionPath                     005746d8(*), 00574e58(*)
//                              stat_obj.h:287 (5)
//         0041a5a0     XOR        EAX,EAX
//         0041a5a2     RET        0xc
//         0041a5a5     ??         90h
//         0041a5a6     NOP
//         0041a5a7     NOP
//         0041a5a8     NOP
//         0041a5a9     NOP
//         0041a5aa     NOP
//         0041a5ab     NOP
//         0041a5ac     NOP
//         0041a5ad     NOP
//         0041a5ae     NOP
//         0041a5af     NOP
    return 0;
}

int RGE_Static_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall canLinePath(RGE_Static_Object * this, int param_1, in
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              float             Stack[0x14]:4  param_5
//              int               Stack[0x18]:4  param_6
//                               ?canLinePath@RGE_Static_Object@@UAEHHHHHMH@Z                 XREF[4]:     0056edbc(*), 005703cc(*),
//                               RGE_Static_Object::canLinePath                                            005746dc(*), 00574e5c(*)
//                              stat_obj.h:289 (5)
//         0041a5c0     XOR        EAX,EAX
//         0041a5c2     RET        0x18
//         0041a5c5     ??         90h
//         0041a5c6     NOP
//         0041a5c7     NOP
//         0041a5c8     NOP
//         0041a5c9     NOP
//         0041a5ca     NOP
//         0041a5cb     NOP
//         0041a5cc     NOP
//         0041a5cd     NOP
//         0041a5ce     NOP
//         0041a5cf     NOP
    return 0;
}

int RGE_Static_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) {
    /* TODO: Stub */
//                              int __thiscall canLinePath(RGE_Static_Object * this, int param_1, in
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              float             Stack[0x14]:4  param_5
//              int               Stack[0x18]:4  param_6
//                               ?canLinePath@RGE_Static_Object@@UAEHHHHHMH@Z                 XREF[4]:     0056edbc(*), 005703cc(*),
//                               RGE_Static_Object::canLinePath                                            005746dc(*), 00574e5c(*)
//                              stat_obj.h:289 (5)
//         0041a5c0     XOR        EAX,EAX
//         0041a5c2     RET        0x18
//         0041a5c5     ??         90h
//         0041a5c6     NOP
//         0041a5c7     NOP
//         0041a5c8     NOP
//         0041a5c9     NOP
//         0041a5ca     NOP
//         0041a5cb     NOP
//         0041a5cc     NOP
//         0041a5cd     NOP
//         0041a5ce     NOP
//         0041a5cf     NOP
    return 0;
}

int RGE_Static_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
//                              int __thiscall firstTileAlongLine(RGE_Static_Object * this, XYPoint
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              XYPoint *         Stack[0x4]:4   param_1
//              XYPoint *         Stack[0x8]:4   param_2
//              XYPoint *         Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//              int               Stack[0x18]:4  param_6
//                               ?firstTileAlongLine@RGE_Static_Object@@UAEHABUXYPoint@@0AAU  XREF[4]:     0056edc4(*), 005703d4(*),
//                               RGE_Static_Object::firstTileAlongLine                                     005746e4(*), 00574e64(*)
//                              stat_obj.h:290 (5)
//         0041a5d0     XOR        EAX,EAX
//         0041a5d2     RET        0x18
//         0041a5d5     ??         90h
//         0041a5d6     NOP
//         0041a5d7     NOP
//         0041a5d8     NOP
//         0041a5d9     NOP
//         0041a5da     NOP
//         0041a5db     NOP
//         0041a5dc     NOP
//         0041a5dd     NOP
//         0041a5de     NOP
//         0041a5df     NOP
    return 0;
}

XYZBYTEPoint* RGE_Static_Object::userDefinedWaypoint(int param_1) {
    /* TODO: Stub */
//                              XYZBYTEPoint * __thiscall userDefinedWaypoint(RGE_Static_Object * th
//              XYZBYTEPoint *    EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?userDefinedWaypoint@RGE_Static_Object@@UAEPAUXYZBYTEPoint@  XREF[4]:     0056edc8(*), 005703d8(*),
//                               RGE_Static_Object::userDefinedWaypoint                                    005746e8(*), 00574e68(*)
//                              stat_obj.h:316 (5)
//         0041a5e0     XOR        EAX,EAX
//         0041a5e2     RET        0x4
//         0041a5e5     ??         90h
//         0041a5e6     NOP
//         0041a5e7     NOP
//         0041a5e8     NOP
//         0041a5e9     NOP
//         0041a5ea     NOP
//         0041a5eb     NOP
//         0041a5ec     NOP
//         0041a5ed     NOP
//         0041a5ee     NOP
//         0041a5ef     NOP
    return 0;
}

int RGE_Static_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall addUserDefinedWaypoint(RGE_Static_Object * this, XYZB
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              XYZBYTEPoint *    Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?addUserDefinedWaypoint@RGE_Static_Object@@UAEHPAUXYZBYTEPo  XREF[4]:     0056edcc(*), 005703dc(*),
//                               RGE_Static_Object::addUserDefinedWaypoint                                 005746ec(*), 00574e6c(*)
//                              stat_obj.h:317 (5)
//         0041a5f0     XOR        EAX,EAX
//         0041a5f2     RET        0x8
//         0041a5f5     ??         90h
//         0041a5f6     NOP
//         0041a5f7     NOP
//         0041a5f8     NOP
//         0041a5f9     NOP
//         0041a5fa     NOP
//         0041a5fb     NOP
//         0041a5fc     NOP
//         0041a5fd     NOP
//         0041a5fe     NOP
//         0041a5ff     NOP
    return 0;
}

void RGE_Static_Object::removeAllUserDefinedWaypoints(int param_1) {
    /* TODO: Stub */
//                              void __thiscall removeAllUserDefinedWaypoints(RGE_Static_Object * th
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?removeAllUserDefinedWaypoints@RGE_Static_Object@@UAEXH@Z    XREF[4]:     0056edd0(*), 005703e0(*),
//                               RGE_Static_Object::removeAllUserDefinedWaypoints                          005746f0(*), 00574e70(*)
//                              stat_obj.h:318 (3)
//         0041a600     RET        0x4
//         0041a603     ??         90h
//         0041a604     NOP
//         0041a605     NOP
//         0041a606     NOP
//         0041a607     NOP
//         0041a608     NOP
//         0041a609     NOP
//         0041a60a     NOP
//         0041a60b     NOP
//         0041a60c     NOP
//         0041a60d     NOP
//         0041a60e     NOP
//         0041a60f     NOP
    return;
}

void RGE_Static_Object::removeUserDefinedWaypoint(int param_1) {
    /* TODO: Stub */
//                              void __thiscall removeUserDefinedWaypoint(RGE_Static_Object * this,
//              void              <VOID>         <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?removeUserDefinedWaypoint@RGE_Static_Object@@UAEXH@Z        XREF[4]:     0056edd4(*), 005703e4(*),
//                               RGE_Static_Object::removeUserDefinedWaypoint                              005746f4(*), 00574e74(*)
//                              stat_obj.h:319 (3)
//         0041a610     RET        0x4
//         0041a613     ??         90h
//         0041a614     NOP
//         0041a615     NOP
//         0041a616     NOP
//         0041a617     NOP
//         0041a618     NOP
//         0041a619     NOP
//         0041a61a     NOP
//         0041a61b     NOP
//         0041a61c     NOP
//         0041a61d     NOP
//         0041a61e     NOP
//         0041a61f     NOP
    return;
}

int RGE_Static_Object::numberUserDefinedWaypoints() {
    /* TODO: Stub */
//                              int __thiscall numberUserDefinedWaypoints(RGE_Static_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//                               ?numberUserDefinedWaypoints@RGE_Static_Object@@UBEHXZ        XREF[4]:     0056edd8(*), 005703e8(*),
//                               RGE_Static_Object::numberUserDefinedWaypoints                             005746f8(*), 00574e78(*)
//                              stat_obj.h:320 (3)
//         0041a620     XOR        EAX,EAX
//         0041a622     RET
//         0041a623     ??         90h
//         0041a624     NOP
//         0041a625     NOP
//         0041a626     NOP
//         0041a627     NOP
//         0041a628     NOP
//         0041a629     NOP
//         0041a62a     NOP
//         0041a62b     NOP
//         0041a62c     NOP
//         0041a62d     NOP
//         0041a62e     NOP
//         0041a62f     NOP
    return 0;
}

Path* RGE_Static_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) {
    /* TODO: Stub */
//                              Path * __thiscall findAvoidancePath(RGE_Static_Object * this, XYZPoi
//              Path *            EAX:4          <RETURN>
//              RGE_Static_Obj    ECX:4 (auto)   this
//              XYZPoint *        Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//                               ?findAvoidancePath@RGE_Static_Object@@UAEPAVPath@@AAUXYZPoi  XREF[4]:     0056eddc(*), 005703ec(*),
//                               RGE_Static_Object::findAvoidancePath                                      005746fc(*), 00574e7c(*)
//                              stat_obj.h:324 (5)
//         0041a630     XOR        EAX,EAX
//         0041a632     RET        0xc
//         0041a635     ??         90h
//         0041a636     NOP
//         0041a637     NOP
//         0041a638     NOP
//         0041a639     NOP
//         0041a63a     NOP
//         0041a63b     NOP
//         0041a63c     NOP
//         0041a63d     NOP
//         0041a63e     NOP
//         0041a63f     NOP
    return 0;
}

