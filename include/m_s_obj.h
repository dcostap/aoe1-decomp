#ifndef AOE1_M_S_OBJ_H
#define AOE1_M_S_OBJ_H

#include <stdio.h>
#include "rge_damage_sprite_info.h"

class DClipInfo_List;
class RGE_Color_Table;
class RGE_Game_World;
class RGE_Master_Combat_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class TDrawArea;

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
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    virtual unsigned char alignment(float&, float&, RGE_Game_World*,
                                    unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound() {}
    virtual void play_move_sound() {}
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);

    RGE_Master_Static_Object(RGE_Master_Static_Object*, int);
    RGE_Master_Static_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Static_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

protected:
    int setup(RGE_Master_Static_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);

public:
    void make_available(unsigned char);
    unsigned char alignment_box(RGE_Game_World*, float, float,
                                short&, short&, short&, short&,
                                short&, short&, short&, short&);
    long get_help_message();
    long get_help_page();
    long get_hotkey();

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
    int help_string_id;
    int help_page_id;
    int hotkey_id;
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

typedef char m_s_obj_master_size_check[
    (sizeof(RGE_Master_Static_Object) == 0xB8) ? 1 : -1];

#endif
