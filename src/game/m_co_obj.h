#pragma once
#include "../common.h"
#include "Sound.h"
#include "m_ac_obj.h"
#include "sprite.h"

class RGE_Master_Combat_Object : public RGE_Master_Action_Object       {
public:
    char _pad_0x4[0xF8];
    RGE_Sprite* fight_sprite;                // 0xFC
    uchar base_armor;                        // 0x100
    short armor_num;                         // 0x102
    RGE_Armor_Weapon_Info* armor;            // 0x104
    short weapon_num;                        // 0x108
    RGE_Armor_Weapon_Info* weapon;           // 0x10C
    short defense_terrain_bonus;             // 0x110
    float weapon_range;                      // 0x114
    float area_effect_range;                 // 0x118
    uchar area_effect_level;                 // 0x11C
    float speed_of_attack;                   // 0x120
    short missile_id;                        // 0x124
    short base_hit_chance;                   // 0x126
    uchar break_off_combat;                  // 0x128
    short fire_missile_at_frame;             // 0x12A
    float weapon_offset_x;                   // 0x12C
    float weapon_offset_y;                   // 0x130
    float weapon_offset_z;                   // 0x134
    float minimum_weapon_range;              // 0x138
    short orig_armor;                        // 0x13C
    short orig_weapon;                       // 0x13E
    float orig_weapon_range;                 // 0x140
    float orig_speed_of_attack;              // 0x144

    RGE_Master_Combat_Object(RGE_Master_Combat_Object* param_1, int param_2);
    RGE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Combat_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Master_Combat_Object() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // Ghidra: copy_obj

    // [Slot 02] Offset 0x08 (Override)
    virtual void modify(float param_1, uchar param_2); // Ghidra: modify

    // [Slot 03] Offset 0x0C (Override)
    virtual void modify_delta(float param_1, uchar param_2); // Ghidra: modify_delta

    // [Slot 04] Offset 0x10 (Override)
    virtual void modify_percent(float param_1, uchar param_2); // Ghidra: modify_percent

    // [Slot 05] Offset 0x14 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 06] Offset 0x18 (Override)
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // Ghidra: make_new_obj

    // [Slot 07] Offset 0x1C (Override)
    virtual RGE_Master_Static_Object* make_new_master(); // Ghidra: make_new_master

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void check_placement();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void alignment();

    // [Slot 10] Offset 0x28 (Override)
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* param_1); // Ghidra: calc_base_damage_ability

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void play_command_sound();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void play_move_sound();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void create_task_list();

    // --- Non-Virtual Members ---
    int setup(RGE_Master_Combat_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
};

static_assert(sizeof(RGE_Master_Combat_Object) == 0x148, "RGE_Master_Combat_Object Size Mismatch");
static_assert(offsetof(RGE_Master_Combat_Object, orig_speed_of_attack) == 0x144, "RGE_Master_Combat_Object Offset Mismatch");

