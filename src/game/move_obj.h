#pragma once
#include "../common.h"
#include "ani_obj.h"

enum PathResult : unsigned int {
    PathFound = 0,
    NoPathFound = 1,
    WaitingOnPathingCap = 2,
};

class RGE_Moving_Object : public RGE_Animated_Object       {
public:
    char _pad_0x4[0x88];
    float trail_remainder;                   // 0x8C
    float velocity_x;                        // 0x90
    float velocity_y;                        // 0x94
    float velocity_z;                        // 0x98
    float angle;                             // 0x9C
    float turn_towards_time;                 // 0xA0
    Path pathValue;                          // 0xA4
    Path exceptionPathValue;                 // 0xD8
    Waypoint startValue;                     // 0x10C
    Waypoint goalValue;                      // 0x11C
    float turnTimer;                         // 0x12C
    float collisionAvoidanceDistance;        // 0x130
    float actionRange;                       // 0x134
    int targetIDValue;                       // 0x138
    float targetRadiusX;                     // 0x13C
    float targetRadiusY;                     // 0x140
    int continueCounter;                     // 0x144
    int rangeStatusValue;                    // 0x148
    int currentTerrainException1;            // 0x14C
    int currentTerrainException2;            // 0x150
    uchar storePathInExceptionPath;          // 0x154
    uchar waitingToMoveValue;                // 0x155
    uchar numberWaitDelays;                  // 0x156
    XYPoint minInitialPointValue;            // 0x158
    XYPoint maxInitialPointValue;            // 0x160
    XYZBYTEPoint* userDefinedWaypoints;      // 0x168
    int numberUserDefinedWaypointsValue;     // 0x16C
    int maxUserDefinedWaypointsValue;        // 0x170
    uchar finalUserDefinedWaypoint;          // 0x174
    float closestDistanceToWaypoint;         // 0x178
    uchar lastFacet;                         // 0x17C
    uchar lastFacet2;                        // 0x17D

    RGE_Moving_Object(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Moving_Object(int param_1, RGE_Game_World* param_2, int param_3);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Moving_Object() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // Ghidra: recycle_in_to_game

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void recycle_out_of_game();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void shadow_draw();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void normal_draw();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void draw_front_frame();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void draw_back_frame();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void draw_frame();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void check_damage_sprites();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void rehook();

    // [Slot 12] Offset 0x30 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 13] Offset 0x34 (Override)
    virtual float teleport(float param_1, float param_2, float param_3); // Ghidra: teleport

    // [Slot 14] Offset 0x38 (Override)
    virtual void new_sprite(RGE_Sprite* param_1); // Ghidra: new_sprite

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void add_overlay_sprite();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void remove_overlay_sprite();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void change_ownership();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void modify();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void modify_delta();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void modify_percent();

    // [Slot 21] Offset 0x54 (Override)
    virtual void transform(RGE_Master_Static_Object* param_1); // Ghidra: transform

    // [Slot 22] Offset 0x58 (Override)
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // Ghidra: copy_obj

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void set_object_state();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void remove_visible_resource();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void create_doppleganger_when_dying();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void destroy_obj();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void die_die_die();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void damage();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void calculateDamage();

    // [Slot 30] Offset 0x78 (Override)
    virtual void rotate(long param_1); // Ghidra: rotate

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void can_attack();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void set_attribute();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void set_attribute_amount();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void heal();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void heal();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void canRepair();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void notify_of_relation();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void do_command();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void move_to();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void work();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void stop();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void set_attack();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void play_command_sound();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void play_move_sound();

    // [Slot 45] Offset 0xB4 (Override)
    virtual void new_angle(float param_1); // Ghidra: new_angle

    // [Slot 46] Offset 0xB8 (Override)
    virtual RGE_Static_Object* spawn_death_obj(); // Ghidra: spawn_death_obj

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void get_command_master();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void set_being_worked_on();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void release_being_worked_on();

    // [Slot 50] Offset 0xC8 (Override)
    virtual uchar is_moving(); // Ghidra: is_moving

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void get_target_obj();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void enter_obj();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void exit_obj();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void explore_terrain();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void unexplore_terrain();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void get_los_table();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void inAttackRange();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void underAttack();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void setUnderAttack();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void calc_attack_modifier();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void getSpeed();

    // [Slot 62] Offset 0xF8 (Override)
    virtual float getAngle(); // Ghidra: getAngle

    // [Slot 63] Offset 0xFC (Override)
    virtual float maximumSpeed(); // Ghidra: maximumSpeed

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void rateOfFire();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void damageCapability();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void damageCapability();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void weaponRange();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void minimumWeaponRange();

    // [Slot 69] Offset 0x114 (Override)
    virtual int passableTile(float param_1, float param_2, int param_3); // Ghidra: passableTile

    // [Slot 70] Offset 0x118 (Override)
    virtual uchar facetToNextWaypoint(); // Ghidra: facetToNextWaypoint

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void currentTargetID();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void currentTargetX();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void currentTargetY();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void currentTargetZ();

    // [Slot 75] Offset 0x12C (Override)
    virtual void setWaitingToMove(uchar param_1); // Ghidra: setWaitingToMove

    // [Slot 76] Offset 0x130 (Override)
    virtual uchar waitingToMove(); // Ghidra: waitingToMove

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void actionState();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void keepGatheringWhenObjectIsOut();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void produceWhenKilledBy();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void useSameZoneDropsite();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void attack();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void attack();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void moveAwayFrom();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void hunt();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void gather();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void convert();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void repair();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void build();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void trade();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void enter();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void transport();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void stopAction();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void pause();

    // [Slot 101] Offset 0x194 (Override)
    virtual int canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6); // Ghidra: canPath

    // [Slot 102] Offset 0x198 (Override)
    virtual int canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7); // Ghidra: canPath

    // [Slot 103] Offset 0x19C (Override)
    virtual int canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7); // Ghidra: canBidirectionPath

    // [Slot 104] Offset 0x1A0 (Override)
    virtual int canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7); // Ghidra: canPathWithObstructions

    // [Slot 105] Offset 0x1A4 (Override)
    virtual int canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9); // Ghidra: canPathWithAdditionalPassability

    // [Slot 106] Offset 0x1A8 (Override)
    virtual int findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3); // Ghidra: findFirstTerrainAlongExceptionPath

    // [Slot 107] Offset 0x1AC (Override)
    virtual int canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6); // Ghidra: canLinePath

    // [Slot 108] Offset 0x1B0 (Override)
    virtual int canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5); // Ghidra: canLinePath

    // [Slot 109] Offset 0x1B4 (Override)
    virtual int firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6); // Ghidra: firstTileAlongLine

    // [Slot 110] Offset 0x1B8 (Override)
    virtual XYZBYTEPoint* userDefinedWaypoint(int param_1); // Ghidra: userDefinedWaypoint

    // [Slot 111] Offset 0x1BC (Override)
    virtual int addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2); // Ghidra: addUserDefinedWaypoint

    // [Slot 112] Offset 0x1C0 (Override)
    virtual void removeAllUserDefinedWaypoints(int param_1); // Ghidra: removeAllUserDefinedWaypoints

    // [Slot 113] Offset 0x1C4 (Override)
    virtual void removeUserDefinedWaypoint(int param_1); // Ghidra: removeUserDefinedWaypoint

    // [Slot 114] Offset 0x1C8 (Override)
    virtual int numberUserDefinedWaypoints(); // Ghidra: numberUserDefinedWaypoints

    // [Slot 115] Offset 0x1CC (Override)
    virtual Path* findAvoidancePath(XYZPoint* param_1, float param_2, int param_3); // Ghidra: findAvoidancePath

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void get_action_checksum();

    // [Slot 117] Offset 0x1D4 (Override)
    virtual long get_waypoint_checksum(); // Ghidra: get_waypoint_checksum

    // [Slot 118] Offset 0x1D8 (Override)
    virtual int setup(int param_1, RGE_Game_World* param_2); // Ghidra: setup

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void create_object_list();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void create_sprite_list();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 123] Offset 0x1EC (Override)
    virtual void stop_moving(); // Ghidra: stop_moving

    // [Slot 124] Offset 0x1F0 (Override)
    virtual uchar turn_towards(RGE_Static_Object* param_1, float param_2, float param_3); // Ghidra: turn_towards

    // [Slot 125] Offset 0x1F4 (Override)
    virtual int setup(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // Ghidra: setup

    // --- Non-Virtual Members ---
    float angle_to_object(RGE_Static_Object* param_1, float param_2, float param_3);
    void set_angle();
    void set_velocity(float param_1, float param_2, float param_3);
    Path* getPath();
    void setGoal(float param_1, float param_2, float param_3);
    void setActionRange(float param_1);
    void setTargetID(int param_1);
    void setTargetRadius(float param_1, float param_2);
    PathResult findPath();
    int doMove();
    int doTrivialMove(float param_1, float param_2);
    void setFinalUserDefinedWaypoint();
    void setInitialPoints(XYPoint* param_1, XYPoint* param_2);
    void boundAngle(float* param_1, int param_2);
};

static_assert(sizeof(RGE_Moving_Object) == 0x180, "RGE_Moving_Object Size Mismatch");
static_assert(offsetof(RGE_Moving_Object, lastFacet2) == 0x17D, "RGE_Moving_Object Offset Mismatch");

float RGE_Moving_Object::getAngle() {
    /* TODO: Stub */
//                              float __thiscall getAngle(RGE_Moving_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?getAngle@RGE_Moving_Object@@UBEMXZ                          XREF[6]:     0056e518(*), 0056f350(*),
//                               RGE_Moving_Object::getAngle                                               005707e8(*), 00570a40(*),
//                                                                                                         00574870(*), 00574b18(*)
//                              move_obj.h:122 (7)
//         00405f50     FLD        float ptr [ECX + this->angle]
//         00405f56     RET
//         00405f57     ??         90h
//         00405f58     NOP
//         00405f59     NOP
//         00405f5a     NOP
//         00405f5b     NOP
//         00405f5c     NOP
//         00405f5d     NOP
//         00405f5e     NOP
//         00405f5f     NOP
    return 0;
}

int RGE_Moving_Object::numberUserDefinedWaypoints() {
    /* TODO: Stub */
//                              int __thiscall numberUserDefinedWaypoints(RGE_Moving_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?numberUserDefinedWaypoints@RGE_Moving_Object@@UBEHXZ        XREF[6]:     0056e5e8(*), 0056f420(*),
//                               RGE_Moving_Object::numberUserDefinedWaypoints                             005708b8(*), 00570b10(*),
//                                                                                                         00574940(*), 00574be8(*)
//                              move_obj.h:131 (7)
//         00405f60     MOV        EAX,dword ptr [ECX + this->numberUserDefinedWa
//         00405f66     RET
//         00405f67     ??         90h
//         00405f68     NOP
//         00405f69     NOP
//         00405f6a     NOP
//         00405f6b     NOP
//         00405f6c     NOP
//         00405f6d     NOP
//         00405f6e     NOP
//         00405f6f     NOP
    return 0;
}

