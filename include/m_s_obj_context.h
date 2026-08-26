#ifndef MS_OBJ_TU_CONTEXT_H
#define MS_OBJ_TU_CONTEXT_H

#include <stdio.h>

class RGE_Sprite;
class RGE_Sound;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Master_Combat_Object;
class TDrawArea;
class RGE_Color_Table;
class DClipInfo_Node;

struct RGE_Damage_Sprite_Info {
    RGE_Sprite* sprite;
    unsigned char damage_percent;
    unsigned char flag;
    char pad[2];
};

struct RGE_Master_Static_Object_Setup_Locals {
    unsigned char pad_00[2];
    short temp_damage_sprite;
    short temp_select_level;
    short temp_flag;
    short temp_map_draw_level;
    short temp_death_sound;
    short temp_command_level;
    short temp_sprite;
    short temp_terrain;
    short temp_undead_sprite;
    short temp_undead_flag;
    short temp_fog_flag;
    short temp_hide;
    short temp_sort_number;
    short temp_attack_reaction;
    short temp_available;
    short temp_convert_terrain_flag;
    short temp_attribute_flag;
    short temp_map_color;
    short temp_selected_sound;
    short temp_track_as_resource;
    short temp_death_sprite;
    short temp_create_doppleganger_on_death;
    short temp_obj_max;
    short temp_resource_group;
    short temp_movement;
    short temp_draw_flag;
    short temp_created_sound;
    short temp_draw_color;
    short temp_can_be_built_on;
    short temp_elevation_flag;
    short temp_damage_percent;
    unsigned char local_84[2];
    unsigned char local_82[2];
    int count;
    char temp_name[120];
    unsigned char tail[4];
};

extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);
extern "C" void __cdecl getstring(char**, char*);

class RGE_Sprite {
public:
    char gap_00[0x72];
    short id;
    char gap_74[4];
    unsigned char draw(long, long, long, long, long, long,
                       RGE_Color_Table*, TDrawArea*, unsigned char);
};

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;
    char gap_0E[2];
};

class RGE_Object_Node;
class RGE_Object_List;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
    char gap_40[8];
    unsigned char object_state;
    char gap_49[0x3F];
    virtual void copy_obj(class RGE_Master_Static_Object*, RGE_Player*,
                          float, float, float);
    RGE_Static_Object(class RGE_Master_Static_Object*, RGE_Player*,
                      float, float, float, int);
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int, int) const;
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x28];
    float** terrains;
    RGE_Static_Object* recycle_object_in_to_game(unsigned char);
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short count;
    char pad_0A[2];
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x0A];
    short tile_half_height;
    short tile_half_width;
    void get_point(short*, short*, float, float, float, int, int);
};

class DClipInfo_List {
public:
    DClipInfo_Node* AddGDINode(int, int, short, short, short, short,
                               short, short, short, short,
                               int, int, int);
};

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
    char gap_1B4[0x240];
    RGE_Game_World* world;
};

class RGE_Master_Combat_Object {
public:
    char gap_00[0x108];
    short weapon_num;
    char pad_10A[2];
    char* weapon;
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
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    virtual unsigned char alignment(float&, float&, RGE_Game_World*,
                                    unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);

    RGE_Master_Static_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);
    RGE_Master_Static_Object(RGE_Master_Static_Object*, int);
    RGE_Master_Static_Object(int, RGE_Sprite**, RGE_Sound**, int);

protected:
    int setup(RGE_Master_Static_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(_iobuf*, RGE_Sprite**, RGE_Sound**, short);

public:
    void destroy();
    void* scalar_deleting_destructor(unsigned int);
    void make_available(unsigned char);
    unsigned char alignment_box(RGE_Game_World*, float, float,
                                short&, short&, short&, short&, short&, short&,
                                short&, short&);
    long get_help_message();
    long get_help_page();
    long get_hotkey();

    unsigned char master_type;
    char pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    char pad_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    char pad_25;
    short hp;
    float los;
    unsigned char obj_max;
    char pad_2D[3];
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
    char pad_4F;
    short portrait_pict;
    unsigned char available;
    char pad_53;
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
    char pad_69;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    char pad_7E[2];
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
    char pad_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

extern RGE_Base_Game* rge_base_game;
extern DClipInfo_List* SDI_List;
extern int SDI_Object_ID;

#endif
