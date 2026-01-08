#pragma once
#include "../common.h"

class RGE_Missile_Object : public RGE_Combat_Object       {
public:
    char _pad_0x4[0x1C0];
    float max_range;                         // 0x1C4

    RGE_Missile_Object(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Missile_Object(int param_1, RGE_Game_World* param_2, int param_3);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Missile_Object() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void recycle_in_to_game();

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

    // [Slot 09] Offset 0x24 (Override)
    virtual uchar update(); // Ghidra: update

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void check_damage_sprites();

    // [Slot 11] Offset 0x2C (Override)
    virtual void rehook(); // Ghidra: rehook

    // [Slot 12] Offset 0x30 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void teleport();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void new_sprite();

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

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void transform();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void copy_obj();

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

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void rotate();

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

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void new_angle();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void spawn_death_obj();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void get_command_master();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void set_being_worked_on();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void release_being_worked_on();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void is_moving();

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

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void getAngle();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void maximumSpeed();

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

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void passableTile();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void facetToNextWaypoint();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void currentTargetID();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void currentTargetX();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void currentTargetY();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void currentTargetZ();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void setWaitingToMove();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void waitingToMove();

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

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void canPath();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void canPath();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void canBidirectionPath();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void canPathWithObstructions();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canPathWithAdditionalPassability();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void findFirstTerrainAlongExceptionPath();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void canLinePath();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void canLinePath();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void firstTileAlongLine();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void userDefinedWaypoint();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void addUserDefinedWaypoint();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void removeAllUserDefinedWaypoints();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void removeUserDefinedWaypoint();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void numberUserDefinedWaypoints();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void findAvoidancePath();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void get_action_checksum();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void get_waypoint_checksum();

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

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void stop_moving();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void turn_towards();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void work2();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void set_task();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void setTaskByTaskID();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void set_action();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void set_only_action();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void set_end_action();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void getTask();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void create_action_list();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void area_attack();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attack();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void attack();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void do_attack();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void get_armor();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void get_weapon();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void get_weapon_range();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void get_speed_of_attack();

    // [Slot 143] Offset 0x23C (Override)
    virtual int setup(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // Ghidra: setup

    // --- Non-Virtual Members ---
    void init_missile(RGE_Combat_Object* param_1, RGE_Static_Object* param_2, float param_3);
    void init_missile(RGE_Combat_Object* param_1, float param_2, float param_3, float param_4, float param_5);
    uchar missile_move();
    RGE_Check_List* make_object_collision_list(float param_1);
};

static_assert(sizeof(RGE_Missile_Object) == 0x1C8, "RGE_Missile_Object Size Mismatch");
static_assert(offsetof(RGE_Missile_Object, max_range) == 0x1C4, "RGE_Missile_Object Offset Mismatch");

