#pragma once
#include "../common.h"

class TRIBE_Building_Object : public TRIBE_Combat_Object       {
public:
    char _pad_0x4[0x1C4];
    Production_Queue_Record* production_queue; // 0x1C8
    short production_queue_size;             // 0x1CC
    short production_queue_count;            // 0x1CE
    uchar production_queue_enabled;          // 0x1D0
    RGE_Action_List* production_queue_actions; // 0x1D4
    uchar production_queue_change_flag;      // 0x1D8
    uchar production_queue_auto_paused;      // 0x1D9
    short production_queue_need_attr;        // 0x1DA
    float build_pts;                         // 0x1DC
    int unique_build_id;                     // 0x1E0
    uchar culture;                           // 0x1E4
    uchar built;                             // 0x1E5
    int DoppleInstalled;                     // 0x1E8
    ulong PriorMap1;                         // 0x1EC
    ulong PriorMap2;                         // 0x1F0
    ulong PriorMap3;                         // 0x1F4
    long PriorTurn1;                         // 0x1F8
    long PriorTurn2;                         // 0x1FC
    long PriorTurn3;                         // 0x200

    TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6, int param_7);
    TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    TRIBE_Building_Object(int param_1, RGE_Game_World* param_2, int param_3);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Building_Object() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void recycle_in_to_game();

    // [Slot 02] Offset 0x08 (Override)
    virtual void recycle_out_of_game(); // Ghidra: recycle_out_of_game

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

    // [Slot 17] Offset 0x44 (Override)
    virtual void change_ownership(RGE_Player* param_1); // Ghidra: change_ownership

    // [Slot 18] Offset 0x48 (Override)
    virtual void modify(float param_1, uchar param_2); // Ghidra: modify

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void modify_delta();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void modify_percent();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void transform();

    // [Slot 22] Offset 0x58 (Override)
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // Ghidra: copy_obj

    // [Slot 23] Offset 0x5C (Override)
    virtual void set_object_state(uchar param_1); // Ghidra: set_object_state

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void remove_visible_resource();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void create_doppleganger_when_dying();

    // [Slot 26] Offset 0x68 (Override)
    virtual void destroy_obj(); // Ghidra: destroy_obj

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void die_die_die();

    // [Slot 28] Offset 0x70 (Override)
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5); // Ghidra: damage

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

    // [Slot 35] Offset 0x8C (Override)
    virtual uchar heal(float param_1); // Ghidra: heal

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

    // [Slot 41] Offset 0xA4 (Override)
    virtual void stop(); // Ghidra: stop

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

    // [Slot 54] Offset 0xD8 (Override)
    virtual int explore_terrain(RGE_Player* param_1, uchar param_2, int param_3); // Ghidra: explore_terrain

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

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 144] Offset 0x240 (Override)
    virtual void cancel_object(); // Ghidra: cancel_object

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void get_pierce_armor();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void higher_check_for_cliff();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void higher_than_target();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void initUnitAI();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 150] Offset 0x258 (Override)
    virtual void take_building_attribute_from_owner(); // Ghidra: take_building_attribute_from_owner

    // [Slot 151] Offset 0x25C (Override)
    virtual void give_building_attribute_to_owner(); // Ghidra: give_building_attribute_to_owner

    // [Slot 152] Offset 0x260 (Override)
    virtual int setup(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // Ghidra: setup

    // --- Non-Virtual Members ---
    void transform(TRIBE_Master_Building_Object* param_1);
    long check(TRIBE_Building_Object** param_1);
    void connect();
    void connect2();
    void lay_down_impassable_terrain();
    void lay_down_passable_terrain();
    void cancel_build();
    uchar build(float param_1);
    int work_status(short* param_1, short* param_2, short* param_3, char* param_4, short param_5);
    short get_construction_progress();
    void add_to_production_queue(short param_1, short param_2);
    void remove_from_production_queue(short param_1, short param_2);
    void advance_production_queue();
    void empty_production_queue();
    void enable_production_queue(int param_1);
    void update_production_queue();
    int production_queue_status(short* param_1, short* param_2);
};

static_assert(sizeof(TRIBE_Building_Object) == 0x204, "TRIBE_Building_Object Size Mismatch");
static_assert(offsetof(TRIBE_Building_Object, PriorTurn3) == 0x200, "TRIBE_Building_Object Offset Mismatch");

