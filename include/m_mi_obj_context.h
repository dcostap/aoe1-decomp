#ifndef M_MI_OBJ_CONTEXT_H
#define M_MI_OBJ_CONTEXT_H

#include <stdio.h>

class RGE_Sprite;
class RGE_Sound;
class RGE_Player;
class RGE_Game_World;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Master_Action_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Animated_Object;
class RGE_Missile_Object;
class TDrawArea;
class RGE_Color_Table;
class RGE_Task_List;
class RGE_Armor_Weapon_Info;

struct RGE_Damage_Sprite_Info {
    RGE_Sprite* sprite;
    unsigned char damage_percent;
    unsigned char flag;
    char pad[2];
};

class RGE_Master_Static_Object {
public:
    RGE_Master_Static_Object();
    RGE_Master_Static_Object(RGE_Master_Static_Object*, int);
    RGE_Master_Static_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Static_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

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
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);

    int setup(RGE_Master_Static_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);
    long get_help_message();
    long get_help_page();
    long get_hotkey();
    void make_available(unsigned char);

    union {
        unsigned char master_type;
        unsigned char field_4;
    };
    char pad_05[3];
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
    union {
        unsigned char recyclable;
        unsigned char field_a4;
    };
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
    unsigned char draw_flag;
    unsigned char draw_color;
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

typedef char m_mi_master_static_size[(sizeof(RGE_Master_Static_Object) == 0xB8) ? 1 : -1];

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Animated_Object();
    RGE_Master_Animated_Object(RGE_Master_Animated_Object*, int);
    RGE_Master_Animated_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Animated_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

    virtual ~RGE_Master_Animated_Object();
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
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);

    float speed;
};

typedef char m_mi_master_animated_size[(sizeof(RGE_Master_Animated_Object) == 0xBC) ? 1 : -1];

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Master_Moving_Object();
    RGE_Master_Moving_Object(RGE_Master_Moving_Object*, int);
    RGE_Master_Moving_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Moving_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

    virtual ~RGE_Master_Moving_Object();
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
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);

    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    unsigned char size_class;
    short obj_trail_id;
    unsigned char obj_trail_options;
    char pad_0CD[3];
    float obj_trail_spacing;
    unsigned char move_algorithem;
};

typedef char m_mi_master_moving_size[(sizeof(RGE_Master_Moving_Object) == 0xD8) ? 1 : -1];

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Master_Action_Object();
    RGE_Master_Action_Object(RGE_Master_Action_Object*, int);
    RGE_Master_Action_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Action_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

    virtual ~RGE_Master_Action_Object();
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
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);
    virtual RGE_Task_List* create_task_list();

    RGE_Task_List* tasks;
    short default_task;
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    unsigned char run_pattern;
};

typedef char m_mi_master_action_size[(sizeof(RGE_Master_Action_Object) == 0xFC) ? 1 : -1];

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Master_Combat_Object();
    RGE_Master_Combat_Object(RGE_Master_Combat_Object*, int);
    RGE_Master_Combat_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Combat_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

    virtual ~RGE_Master_Combat_Object();
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
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);
    virtual RGE_Task_List* create_task_list();

    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;

    int setup(RGE_Master_Combat_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(int, void**, void**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);
    int setup(FILE*, void**, void**, short);
};

typedef char m_mi_master_combat_size[(sizeof(RGE_Master_Combat_Object) == 0x148) ? 1 : -1];

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    RGE_Master_Missile_Object();
    RGE_Master_Missile_Object(RGE_Master_Missile_Object*, int);
    RGE_Master_Missile_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Missile_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

    virtual ~RGE_Master_Missile_Object();
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
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);
    virtual RGE_Task_List* create_task_list();

    unsigned char missile_type;
    union {
        unsigned char targetting_type;
        unsigned char field_149;
    };
    unsigned char missile_hit_info;
    unsigned char missile_die_info;
    unsigned char area_effect_specials;
    char pad_14D[3];
    float ballistics_ratio;

protected:
    int setup(RGE_Master_Missile_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(int, void**, void**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);
    int setup(FILE*, void**, void**, short);
};

typedef char m_mi_master_missile_size[(sizeof(RGE_Master_Missile_Object) == 0x154) ? 1 : -1];

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    char gap_04[0x84];
};

typedef char m_mi_static_object_size[(sizeof(RGE_Static_Object) == 0x88) ? 1 : -1];

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(unsigned char);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Combat_Object : public RGE_Static_Object {
public:
    char gap_88[0x13C];
};

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    float max_range;
    RGE_Missile_Object(RGE_Master_Missile_Object*, RGE_Player*,
                       float, float, float, int);
};

typedef char m_mi_missile_object_size[(sizeof(RGE_Missile_Object) == 0x1C8) ? 1 : -1];

#endif
