#pragma once
#include "../common.h"
#include "sprite.h"
#include "Sound.h"
#include "stat_obj.h"
#include "player.h"
#include "World.h"
#include "Drawarea.h"
#include "m_co_obj.h"

class RGE_Master_Static_Object       {
public:
    uchar master_type;                       // 0x4
    char* name;                              // 0x8
    short string_id;                         // 0xC
    short string_id2;                        // 0xE
    short id;                                // 0x10
    short copy_id;                           // 0x12
    short object_group;                      // 0x14
    RGE_Sprite* sprite;                      // 0x18
    RGE_Sprite* death_sprite;                // 0x1C
    RGE_Sprite* undead_sprite;               // 0x20
    uchar undead_flag;                       // 0x24
    short hp;                                // 0x26
    float los;                               // 0x28
    uchar obj_max;                           // 0x2C
    float radius_x;                          // 0x30
    float radius_y;                          // 0x34
    float radius_z;                          // 0x38
    RGE_Sound* selected_sound;               // 0x3C
    RGE_Sound* created_sound;                // 0x40
    RGE_Sound* death_sound;                  // 0x44
    short death_spawn_obj_id;                // 0x48
    uchar sort_number;                       // 0x4A
    uchar can_be_built_on;                   // 0x4B
    short button_pict;                       // 0x4C
    uchar hide_in_scenario_editor;           // 0x4E
    short portrait_pict;                     // 0x50
    uchar available;                         // 0x52
    short tile_req1;                         // 0x54
    short tile_req2;                         // 0x56
    short center_tile_req1;                  // 0x58
    short center_tile_req2;                  // 0x5A
    float construction_radius_x;             // 0x5C
    float construction_radius_y;             // 0x60
    uchar elevation_flag;                    // 0x64
    uchar fog_flag;                          // 0x65
    short terrain;                           // 0x66
    uchar movement_type;                     // 0x68
    short attribute_type_held[3];            // 0x6A
    float attribute_amount_held[3];          // 0x70
    short attribute_max_amount;              // 0x7C
    float attribute_rot;                     // 0x80
    float multiple_attribute_mod;            // 0x84
    uchar attribute_flag[3];                 // 0x88
    uchar area_effect_object_level;          // 0x8B
    uchar combat_level;                      // 0x8C
    uchar select_level;                      // 0x8D
    uchar map_draw_level;                    // 0x8E
    uchar unit_level;                        // 0x8F
    uchar map_color;                         // 0x90
    uchar attack_reaction;                   // 0x91
    uchar convert_terrain_flag;              // 0x92
    uchar damage_sprite_num;                 // 0x93
    RGE_Damage_Sprite_Info* damage_sprites;  // 0x94
    long help_string_id;                     // 0x98
    long help_page_id;                       // 0x9C
    long hotkey_id;                          // 0xA0
    uchar recyclable;                        // 0xA4
    uchar track_as_resource;                 // 0xA5
    uchar create_doppleganger_on_death;      // 0xA6
    uchar resource_group;                    // 0xA7
    uchar draw_flag;                         // 0xA8
    uchar draw_color;                        // 0xA9
    float outline_radius_x;                  // 0xAC
    float outline_radius_y;                  // 0xB0
    float outline_radius_z;                  // 0xB4

    RGE_Master_Static_Object(RGE_Master_Static_Object* param_1, int param_2);
    RGE_Master_Static_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Static_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Master_Static_Object() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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

    // [Slot 08] Offset 0x20 (Override)
    virtual uchar check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10); // Ghidra: check_placement

    // [Slot 09] Offset 0x24 (Override)
    virtual uchar alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4); // Ghidra: alignment

    // [Slot 10] Offset 0x28 (Override)
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* param_1); // Ghidra: calc_base_damage_ability

    // [Slot 11] Offset 0x2C (Override)
    virtual void play_command_sound(); // Ghidra: play_command_sound

    // [Slot 12] Offset 0x30 (Override)
    virtual void play_move_sound(); // Ghidra: play_move_sound

    // [Slot 13] Offset 0x34 (Override)
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8); // Ghidra: draw

    // --- Non-Virtual Members ---
    int setup(RGE_Master_Static_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    void make_available(uchar param_1);
    uchar alignment_box(RGE_Game_World* param_1, float param_2, float param_3, short* param_4, short* param_5, short* param_6, short* param_7, short* param_8, short* param_9, short* param_10, short* param_11);
    long get_help_message();
    long get_help_page();
    long get_hotkey();
};

static_assert(sizeof(RGE_Master_Static_Object) == 0xB8, "RGE_Master_Static_Object Size Mismatch");
static_assert(offsetof(RGE_Master_Static_Object, outline_radius_z) == 0xB4, "RGE_Master_Static_Object Offset Mismatch");

void RGE_Master_Static_Object::play_command_sound() {
    /* TODO: Stub */
//                              void __thiscall play_command_sound(RGE_Master_Static_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Master_Sta    ECX:4 (auto)   this
//                               ?play_command_sound@RGE_Master_Static_Object@@UAEXXZ         XREF[5]:     005704b4(*), 0057054c(*),
//                               RGE_Master_Static_Object::play_command_sound                              005705cc(*), 00570604(*),
//                                                                                                         005767bc(*)
//                              m_s_obj.h:210 (1)
//         0044fe20     RET
//         0044fe21     ??         90h
//         0044fe22     NOP
//         0044fe23     NOP
//         0044fe24     NOP
//         0044fe25     NOP
//         0044fe26     NOP
//         0044fe27     NOP
//         0044fe28     NOP
//         0044fe29     NOP
//         0044fe2a     NOP
//         0044fe2b     NOP
//         0044fe2c     NOP
//         0044fe2d     NOP
//         0044fe2e     NOP
//         0044fe2f     NOP
    return;
}

void RGE_Master_Static_Object::play_move_sound() {
    /* TODO: Stub */
//                              void __thiscall play_move_sound(RGE_Master_Static_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Master_Sta    ECX:4 (auto)   this
//                               ?play_move_sound@RGE_Master_Static_Object@@UAEXXZ            XREF[5]:     005704b8(*), 00570550(*),
//                               RGE_Master_Static_Object::play_move_sound                                 005705d0(*), 00570608(*),
//                                                                                                         005767c0(*)
//                              m_s_obj.h:211 (1)
//         0044fe30     RET
//         0044fe31     ??         90h
//         0044fe32     NOP
//         0044fe33     NOP
//         0044fe34     NOP
//         0044fe35     NOP
//         0044fe36     NOP
//         0044fe37     NOP
//         0044fe38     NOP
//         0044fe39     NOP
//         0044fe3a     NOP
//         0044fe3b     NOP
//         0044fe3c     NOP
//         0044fe3d     NOP
//         0044fe3e     NOP
//         0044fe3f     NOP
    return;
}

