#ifndef AOE1_TM_CO_OB_CONTEXT_H
#define AOE1_TM_CO_OB_CONTEXT_H

#include <stdio.h>

// Canonical declarations for the PDB source module tm_co_ob.cpp.
// The fields and virtual slots below come from the generated class layout and
// the qualified symbols in the original executable.  Owner fragments keep
// their standalone declarations when this header is not included.

class RGE_Sprite;
class RGE_Sound;
class RGE_Player;
class RGE_Color_Table;
class TDrawArea;
class RGE_Game_World;
class RGE_Armor_Weapon_Info;
class RGE_Damage_Sprite_Info;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class TRIBE_Master_Combat_Object;

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

struct RGE_Master_Combat_Object_copy {
    char base[0x148];
    void copy_obj(void* source);
};

struct RGE_Master_Combat_Object_save {
    char base[0x148];
    void save(int file);
};

class RGE_Task_List {
public:
    virtual void destroy();
    int list;
    short list_num;

    RGE_Task_List();
};

class TRIBE_Task_List : public RGE_Task_List {
public:
    virtual void destroy();
};

class RGE_Static_Object {
};

class TRIBE_Combat_Object : public RGE_Static_Object {
public:
    char gap_000[0x1C8];

    TRIBE_Combat_Object(TRIBE_Master_Combat_Object* master,
                        RGE_Player* player, float x, float y, float z,
                        int flag);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    unsigned char master_type;
    unsigned char _pad_005[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char _pad_016[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    unsigned char _pad_025[1];
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char _pad_02D[3];
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
    unsigned char _pad_04F[1];
    short portrait_pict;
    unsigned char available;
    unsigned char _pad_053[1];
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
    unsigned char _pad_069[1];
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    unsigned char _pad_07E[2];
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
    unsigned char _pad_0AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

typedef char tm_co_ob_static_size[(sizeof(RGE_Master_Static_Object) == 0xB8) ? 1 : -1];

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

typedef char tm_co_ob_animated_size[(sizeof(RGE_Master_Animated_Object) == 0xBC) ? 1 : -1];

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    unsigned char size_class;
    unsigned char _pad_0C9[1];
    short obj_trail_id;
    unsigned char obj_trail_options;
    unsigned char _pad_0CD[3];
    float obj_trail_spacing;
    unsigned char move_algorithem;
    unsigned char _pad_0D5[3];
};

typedef char tm_co_ob_moving_size[(sizeof(RGE_Master_Moving_Object) == 0xD8) ? 1 : -1];

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Action_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);

    RGE_Task_List* tasks;
    short default_task;
    unsigned char _pad_0DE[2];
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    unsigned char _pad_0ED[3];
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    unsigned char run_pattern;
    unsigned char _pad_0F9[3];
};

typedef char tm_co_ob_action_size[(sizeof(RGE_Master_Action_Object) == 0xFC) ? 1 : -1];

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Combat_Object();

    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    unsigned char _pad_101[1];
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char _pad_10A[2];
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    unsigned char _pad_112[2];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    unsigned char _pad_11D[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char _pad_129[1];
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;

    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                             float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player* player, float x,
                                          float y, int* result,
                                          unsigned char a, unsigned char b,
                                          unsigned char c, unsigned char d,
                                          unsigned char e, unsigned char f);
    virtual unsigned char alignment(float* x, float* y, RGE_Game_World* world,
                                    unsigned char flag);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* source);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* color_table, long param_5,
                      long param_6, int param_7, unsigned char param_8);
    virtual RGE_Task_List* create_task_list();

    RGE_Master_Combat_Object(RGE_Master_Combat_Object* source, int do_setup);
    RGE_Master_Combat_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int flag);
    RGE_Master_Combat_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short id, int flag);

protected:
    int setup(RGE_Master_Combat_Object* source);
    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short id);
};

typedef char tm_co_ob_combat_size[(sizeof(RGE_Master_Combat_Object) == 0x148) ? 1 : -1];

class Attribute_Cost {
public:
    short type;
    short amount;
    unsigned char flag;
    unsigned char _pad_005;
};

typedef char tm_co_ob_attribute_cost_size[(sizeof(Attribute_Cost) == 6) ? 1 : -1];

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();

    Attribute_Cost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    unsigned char _pad_15F;
    short orig_pierce_armor;
    unsigned char _pad_162[2];

    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* source,
                               int do_setup);
    TRIBE_Master_Combat_Object(int id, RGE_Sprite** sprites,
                               RGE_Sound** sounds, int flag);
    TRIBE_Master_Combat_Object(FILE* file, RGE_Sprite** sprites,
                               RGE_Sound** sounds, short id, int flag);

protected:
    int setup(TRIBE_Master_Combat_Object* source);
    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short id);

public:
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                             float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual RGE_Task_List* create_task_list();
};

typedef char tm_co_ob_tribe_size[(sizeof(TRIBE_Master_Combat_Object) == 0x164) ? 1 : -1];

extern "C" {
    void rge_read(int fd, void* data, int size);
    void rge_write(int fd, void* data, int size);
}

extern float save_game_version;
extern float DAT_0057677c;

void* __cdecl operator new(unsigned int size);

#define TM_CO_OB_SHARED_CONTEXT 1

#endif  // AOE1_TM_CO_OB_CONTEXT_H
