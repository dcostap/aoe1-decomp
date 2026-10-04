#ifndef AOE1_M_S_OBJ_H
#define AOE1_M_S_OBJ_H

// Master-object groups, not master-object IDs or tactical-group types.
// Keep the short object_group field and existing integer parameter types.
#define OBJECT_GROUP_ARTIFACT        1
#define OBJECT_GROUP_TRADE_BOAT      2
#define OBJECT_GROUP_BUILDING        3
#define OBJECT_GROUP_CIVILIAN        4
#define OBJECT_GROUP_STONE_SOURCE    8
#define OBJECT_GROUP_HUNTED_ANIMAL   9
#define OBJECT_GROUP_PREDATOR        10
#define OBJECT_GROUP_TREE            0x0F
#define OBJECT_GROUP_PRIEST          0x12
#define OBJECT_GROUP_TRANSPORT_BOAT  0x14
#define OBJECT_GROUP_FISHING_BOAT    0x15
#define OBJECT_GROUP_WAR_BOAT        0x16
#define OBJECT_GROUP_WALL            0x1B
#define OBJECT_GROUP_GOLD_SOURCE     0x20
#define OBJECT_GROUP_CLIFF           0x22

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
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int outfile);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player* player, float col, float row, int* obstructionObject,
                                          unsigned char check_vis, unsigned char check_flat,
                                          unsigned char check_overlay, unsigned char construction_radius_flag,
                                          unsigned char can_be_built_on_flag, unsigned char check_objects);
    virtual unsigned char alignment(float& col, float& row, RGE_Game_World* world,
                                    unsigned char center_flag);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* attacker);
    virtual void play_command_sound() {}
    virtual void play_move_sound() {}
    virtual void draw(TDrawArea* render_area, short x, short y, RGE_Color_Table* player_color, long facet, long frame,
                      int draw_frame, unsigned char frame_color);

    RGE_Master_Static_Object(RGE_Master_Static_Object* other_object, int do_setup);
    RGE_Master_Static_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    RGE_Master_Static_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);

protected:
    int setup(RGE_Master_Static_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);

public:
    void make_available(unsigned char on_off_flag);
    unsigned char alignment_box(RGE_Game_World* world, float col, float row,
                                short& x1, short& y1, short& x2, short& y2,
                                short& x3, short& y3, short& x4, short& y4);
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
