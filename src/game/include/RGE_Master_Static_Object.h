#pragma once
#include "common.h"

class RGE_Master_Static_Object {
public:
    // Virtuals (best-effort)
    virtual ~RGE_Master_Static_Object(); // vt[0] (0x0)
    virtual void copy_obj(); // vt[1] (0x4)
    virtual void modify(float param_1, uchar param_2); // vt[2] (0x8)
    virtual void modify_delta(float param_1, uchar param_2); // vt[3] (0xC)
    virtual void modify_percent(float param_1, uchar param_2); // vt[4] (0x10)
    virtual void save(int param_1); // vt[5] (0x14)
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // vt[6] (0x18)
    virtual RGE_Master_Static_Object* make_new_master(); // vt[7] (0x1C)
    virtual uchar check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10); // vt[8] (0x20)
    virtual uchar alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4); // vt[9] (0x24)
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* param_1); // vt[10] (0x28)
    virtual void play_command_sound(); // vt[11] (0x2C)
    virtual void play_move_sound(); // vt[12] (0x30)
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8); // vt[13] (0x34)

    unsigned char master_type;
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    short hp;
    float los;
    unsigned char obj_max;
    float radius_x;
    float radius_y;
    float radius_z;
    RGE_Sound* selected_sound;
    RGE_Sound* created_sound;
    RGE_Sound* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    short portrait_pict;
    unsigned char available;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fog_flag;
    short terrain;
    unsigned char movement_type;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
    unsigned char area_effect_object_level;
    unsigned char combat_level;
    unsigned char select_level;
    unsigned char map_draw_level;
    unsigned char unit_level;
    unsigned char map_color;
    unsigned char attack_reaction;
    unsigned char convert_terrain_flag;
    unsigned char damage_sprite_num;
    RGE_Damage_Sprite_Info* damage_sprites;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
    unsigned char recyclable;
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
    unsigned char draw_flag;
    unsigned char draw_color;
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};
static_assert(sizeof(RGE_Master_Static_Object) == 0xB8, "Size mismatch");
