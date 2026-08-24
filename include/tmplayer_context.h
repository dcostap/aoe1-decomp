#ifndef TMPLAYER_CONTEXT_H
#define TMPLAYER_CONTEXT_H

// Authentic tmplayer.cpp declaration context.
// Layout and virtual slots follow the reviewed class inventory.

struct _iobuf;
class RGE_Sprite;
class RGE_Sound;
class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Combat_Object;
class RGE_Master_Static_Object;
class RGE_Task_List;
class RGE_Damage_Sprite_Info;
class RGE_Armor_Weapon_Info;
class TDrawArea;
class RGE_Color_Table;

class Attribute_Cost {
public:
    short type;
    short amount;
    unsigned char flag;
    unsigned char pad_end;
};

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    virtual void finish_init(int, RGE_Sprite**, RGE_Sound**);
    virtual void load_master_object(int, unsigned char, RGE_Sprite**, RGE_Sound**, short);
    virtual void create_master_object_space(short);
    virtual void load_object(_iobuf*, unsigned char, RGE_Sprite**, RGE_Sound**, short);
    virtual void save(int);

    RGE_Master_Player(_iobuf*);
    RGE_Master_Player(int);

    char name[20];
    short master_object_num;
    unsigned char pad_1A[2];
    RGE_Master_Static_Object** master_objects;
    short attribute_num;
    unsigned char pad_22[2];
    float* attributes;
    unsigned char culture;
    unsigned char type;
    short tribe_effect;
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
    virtual unsigned char check_placement(RGE_Player*, float, float, int*, unsigned char,
                                          unsigned char, unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long, int,
                      unsigned char);

    RGE_Master_Static_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Static_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);

    unsigned char master_type;
    unsigned char pad_05[0x03];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char pad_16[0x02];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    unsigned char pad_25;
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char pad_2D[0x03];
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
    unsigned char pad_4F;
    short portrait_pict;
    unsigned char available;
    unsigned char pad_53;
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
    unsigned char pad_69;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    unsigned char pad_7E[0x02];
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
    unsigned char pad_AA[0x02];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Moving_Object();
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    unsigned char size_class;
    unsigned char pad_C9;
    short obj_trail_id;
    unsigned char obj_trail_options;
    unsigned char pad_CD[0x03];
    float obj_trail_spacing;
    unsigned char move_algorithem;
    unsigned char pad_D5[0x03];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Action_Object();
    RGE_Task_List* tasks;
    short default_task;
    unsigned char pad_DE[0x02];
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    unsigned char pad_ED[0x03];
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    unsigned char run_pattern;
    unsigned char pad_F9[0x03];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    unsigned char pad_101;
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char pad_10A[0x02];
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    unsigned char pad_112[0x02];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    unsigned char pad_11D[0x03];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char pad_129;
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();
    TRIBE_Master_Combat_Object(int, RGE_Sprite**, RGE_Sound**, int);
    TRIBE_Master_Combat_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);
    Attribute_Cost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    unsigned char pad_15F;
    short orig_pierce_armor;
    unsigned char pad_162[0x02];
};

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:
    virtual ~TRIBE_Master_Tree_Object();
    TRIBE_Master_Tree_Object(int, RGE_Sprite**, RGE_Sound**, int);
    TRIBE_Master_Tree_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Building_Object();
    TRIBE_Master_Building_Object(int, RGE_Sprite**, RGE_Sound**, int);
    TRIBE_Master_Building_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);
    RGE_Sound* construction_sound;
    RGE_Sprite* construction_sprite;
    unsigned char building_connect_flag;
    unsigned char pad_16D;
    short building_facet;
    unsigned char build_and_go_away;
    unsigned char pad_171;
    short on_build_make_obj;
    short on_build_make_tile;
    short on_build_make_overlay;
    short on_build_make_tech;
    unsigned char pad_17A[0x02];
};

class TRIBE_Master_Player : public RGE_Master_Player {
public:
    virtual ~TRIBE_Master_Player();
    virtual void load_master_object(int, unsigned char, RGE_Sprite**, RGE_Sound**, short);
    virtual void load_object(_iobuf*, unsigned char, RGE_Sprite**, RGE_Sound**, short);

    TRIBE_Master_Player(_iobuf*);
    TRIBE_Master_Player(int);
};

#endif
