#ifndef M_DG_OBJ_CONTEXT_H
#define M_DG_OBJ_CONTEXT_H

#include <stdio.h>
#include <stddef.h>

class RGE_Sprite;
class RGE_Sound;
class RGE_Player;
class RGE_Game_World;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Combat_Object;
class TDrawArea;
class RGE_Color_Table;

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

    unsigned char master_type;
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

typedef char m_dg_master_static_size[(sizeof(RGE_Master_Static_Object) == 0xB8) ? 1 : -1];

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

protected:
    int setup(RGE_Master_Animated_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);

public:
    float speed;
};

typedef char m_dg_master_animated_size[(sizeof(RGE_Master_Animated_Object) == 0xBC) ? 1 : -1];

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    RGE_Master_Doppleganger_Object();
    RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object*, int);
    RGE_Master_Doppleganger_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Doppleganger_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

    virtual ~RGE_Master_Doppleganger_Object();
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
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float,
                                            RGE_Static_Object*);

protected:
    int setup(RGE_Master_Doppleganger_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);
};

typedef char m_dg_master_doppleganger_size[(sizeof(RGE_Master_Doppleganger_Object) == 0xBC) ? 1 : -1];

// The factory dispatches to the six-argument virtual at RGE_Doppleganger_Object
// slot 0x1ec. Declaration-only padding preserves the real period slot order.
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
#define M_DG_STATIC_VIRTUAL(n) virtual void m_dg_static_v##n();
    M_DG_STATIC_VIRTUAL(02)  M_DG_STATIC_VIRTUAL(03)  M_DG_STATIC_VIRTUAL(04)
    M_DG_STATIC_VIRTUAL(05)  M_DG_STATIC_VIRTUAL(06)  M_DG_STATIC_VIRTUAL(07)
    M_DG_STATIC_VIRTUAL(08)  M_DG_STATIC_VIRTUAL(09)  M_DG_STATIC_VIRTUAL(10)
    M_DG_STATIC_VIRTUAL(11)  M_DG_STATIC_VIRTUAL(12)  M_DG_STATIC_VIRTUAL(13)
    M_DG_STATIC_VIRTUAL(14)  M_DG_STATIC_VIRTUAL(15)  M_DG_STATIC_VIRTUAL(16)
    M_DG_STATIC_VIRTUAL(17)  M_DG_STATIC_VIRTUAL(18)  M_DG_STATIC_VIRTUAL(19)
    M_DG_STATIC_VIRTUAL(20)  M_DG_STATIC_VIRTUAL(21)  M_DG_STATIC_VIRTUAL(22)
    M_DG_STATIC_VIRTUAL(23)  M_DG_STATIC_VIRTUAL(24)  M_DG_STATIC_VIRTUAL(25)
    M_DG_STATIC_VIRTUAL(26)  M_DG_STATIC_VIRTUAL(27)  M_DG_STATIC_VIRTUAL(28)
    M_DG_STATIC_VIRTUAL(29)  M_DG_STATIC_VIRTUAL(30)  M_DG_STATIC_VIRTUAL(31)
    M_DG_STATIC_VIRTUAL(32)  M_DG_STATIC_VIRTUAL(33)  M_DG_STATIC_VIRTUAL(34)
    M_DG_STATIC_VIRTUAL(35)  M_DG_STATIC_VIRTUAL(36)  M_DG_STATIC_VIRTUAL(37)
    M_DG_STATIC_VIRTUAL(38)  M_DG_STATIC_VIRTUAL(39)  M_DG_STATIC_VIRTUAL(40)
    M_DG_STATIC_VIRTUAL(41)  M_DG_STATIC_VIRTUAL(42)  M_DG_STATIC_VIRTUAL(43)
    M_DG_STATIC_VIRTUAL(44)  M_DG_STATIC_VIRTUAL(45)  M_DG_STATIC_VIRTUAL(46)
    M_DG_STATIC_VIRTUAL(47)  M_DG_STATIC_VIRTUAL(48)  M_DG_STATIC_VIRTUAL(49)
    M_DG_STATIC_VIRTUAL(50)  M_DG_STATIC_VIRTUAL(51)  M_DG_STATIC_VIRTUAL(52)
    M_DG_STATIC_VIRTUAL(53)  M_DG_STATIC_VIRTUAL(54)  M_DG_STATIC_VIRTUAL(55)
    M_DG_STATIC_VIRTUAL(56)  M_DG_STATIC_VIRTUAL(57)  M_DG_STATIC_VIRTUAL(58)
    M_DG_STATIC_VIRTUAL(59)  M_DG_STATIC_VIRTUAL(60)  M_DG_STATIC_VIRTUAL(61)
    M_DG_STATIC_VIRTUAL(62)  M_DG_STATIC_VIRTUAL(63)  M_DG_STATIC_VIRTUAL(64)
    M_DG_STATIC_VIRTUAL(65)  M_DG_STATIC_VIRTUAL(66)  M_DG_STATIC_VIRTUAL(67)
    M_DG_STATIC_VIRTUAL(68)  M_DG_STATIC_VIRTUAL(69)  M_DG_STATIC_VIRTUAL(70)
    M_DG_STATIC_VIRTUAL(71)  M_DG_STATIC_VIRTUAL(72)  M_DG_STATIC_VIRTUAL(73)
    M_DG_STATIC_VIRTUAL(74)  M_DG_STATIC_VIRTUAL(75)  M_DG_STATIC_VIRTUAL(76)
    M_DG_STATIC_VIRTUAL(77)  M_DG_STATIC_VIRTUAL(78)  M_DG_STATIC_VIRTUAL(79)
    M_DG_STATIC_VIRTUAL(80)  M_DG_STATIC_VIRTUAL(81)  M_DG_STATIC_VIRTUAL(82)
    M_DG_STATIC_VIRTUAL(83)  M_DG_STATIC_VIRTUAL(84)  M_DG_STATIC_VIRTUAL(85)
    M_DG_STATIC_VIRTUAL(86)  M_DG_STATIC_VIRTUAL(87)  M_DG_STATIC_VIRTUAL(88)
    M_DG_STATIC_VIRTUAL(89)  M_DG_STATIC_VIRTUAL(90)  M_DG_STATIC_VIRTUAL(91)
    M_DG_STATIC_VIRTUAL(92)  M_DG_STATIC_VIRTUAL(93)  M_DG_STATIC_VIRTUAL(94)
    M_DG_STATIC_VIRTUAL(95)  M_DG_STATIC_VIRTUAL(96)  M_DG_STATIC_VIRTUAL(97)
    M_DG_STATIC_VIRTUAL(98)  M_DG_STATIC_VIRTUAL(99)  M_DG_STATIC_VIRTUAL(100)
    M_DG_STATIC_VIRTUAL(101) M_DG_STATIC_VIRTUAL(102) M_DG_STATIC_VIRTUAL(103)
    M_DG_STATIC_VIRTUAL(104) M_DG_STATIC_VIRTUAL(105) M_DG_STATIC_VIRTUAL(106)
    M_DG_STATIC_VIRTUAL(107) M_DG_STATIC_VIRTUAL(108) M_DG_STATIC_VIRTUAL(109)
    M_DG_STATIC_VIRTUAL(110) M_DG_STATIC_VIRTUAL(111) M_DG_STATIC_VIRTUAL(112)
    M_DG_STATIC_VIRTUAL(113) M_DG_STATIC_VIRTUAL(114) M_DG_STATIC_VIRTUAL(115)
    M_DG_STATIC_VIRTUAL(116) M_DG_STATIC_VIRTUAL(117) M_DG_STATIC_VIRTUAL(118)
    M_DG_STATIC_VIRTUAL(119) M_DG_STATIC_VIRTUAL(120) M_DG_STATIC_VIRTUAL(121)
#undef M_DG_STATIC_VIRTUAL
    char gap_04[0x84];
};

typedef char m_dg_static_object_size[(sizeof(RGE_Static_Object) == 0x88) ? 1 : -1];

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    float speed;
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Doppleganger_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float, RGE_Static_Object*);
    RGE_Static_Object* doppled_object;
    RGE_Color_Table* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    unsigned long LastMapValue;
    unsigned long CantSeeBits;
    unsigned char map_draw_level;
    unsigned char map_color;
    char pad_AA[2];
    int doppledObjectID;
    RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object*, RGE_Player*,
                            float, float, float, int, RGE_Static_Object*);
};

typedef char m_dg_doppleganger_object_size[(sizeof(RGE_Doppleganger_Object) == 0xB0) ? 1 : -1];

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(unsigned char);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

typedef char m_dg_player_world_offset[(offsetof(RGE_Player, world) == 0x3C) ? 1 : -1];

#endif
