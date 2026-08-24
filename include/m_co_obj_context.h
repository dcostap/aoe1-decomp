#ifndef AOE1_M_CO_OBJ_CONTEXT_H
#define AOE1_M_CO_OBJ_CONTEXT_H

// Canonical declarations for the PDB source module m_co_obj.cpp.
// The module wrapper defines RGE_MCO_OBJ_SHARED_CONTEXT before it includes
// the owner bodies. Standalone owners keep their local recovery declarations.

#ifdef RGE_MCO_OBJ_SHARED_CONTEXT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class RGE_Sprite {
public:
    char gap_00[0x72];
    short id;
};
class RGE_Sound;
class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Task_List;
class TDrawArea;
class RGE_Color_Table;

struct RGE_Damage_Sprite_Info {
    RGE_Sprite* sprite;
    unsigned char damage_percent;
    unsigned char flag;
    char pad[2];
};

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player* player, float x,
                                          float y, int* value,
                                          unsigned char a, unsigned char b,
                                          unsigned char c, unsigned char d,
                                          unsigned char e, unsigned char f);
    virtual unsigned char alignment(float* x, float* y, RGE_Game_World* world,
                                    unsigned char value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors, long clip_x, long clip_y,
                      int value, unsigned char flags);

    unsigned char master_type;
    char gap_005[0x9F];
    unsigned char recyclable;
    char gap_A5[0x13];
};

typedef char m_co_obj_master_size[(sizeof(RGE_Master_Static_Object) == 0xB8) ? 1 : -1];

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

typedef char m_co_obj_animated_size[(sizeof(RGE_Master_Animated_Object) == 0xBC) ? 1 : -1];

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x08];
    float turn_speed;
    char gap_C8[0x10];
};

typedef char m_co_obj_moving_size[(sizeof(RGE_Master_Moving_Object) == 0xD8) ? 1 : -1];

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Task_List* tasks;
    short default_task;
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    char gap_ED[3];
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    unsigned char run_pattern;
    char gap_F9[3];

    virtual ~RGE_Master_Action_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);

    RGE_Master_Action_Object(RGE_Master_Action_Object* source, int do_setup);
    RGE_Master_Action_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int flag);
    RGE_Master_Action_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short id, int flag);

protected:
    int setup(RGE_Master_Action_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short id);
};

typedef char m_co_obj_action_size[(sizeof(RGE_Master_Action_Object) == 0xFC) ? 1 : -1];

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    unsigned char gap_101[1];
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char gap_10A[2];
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    unsigned char gap_112[2];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    unsigned char gap_11D[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char gap_129[1];
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;

    virtual ~RGE_Master_Combat_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);

    RGE_Master_Combat_Object(RGE_Master_Combat_Object* source, int do_setup);
    RGE_Master_Combat_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int flag);
    RGE_Master_Combat_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short id, int flag);

protected:
    int setup(RGE_Master_Combat_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short id);

};

typedef char m_co_obj_combat_size[(sizeof(RGE_Master_Combat_Object) == 0x148) ? 1 : -1];

// The factory owner uses the real object hierarchy to select allocation size
// and the recycle call. Only the fields and methods touched by that owner are
// included here.
class RGE_Static_Object {
public:
    char gap_00[0x84];
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    char gap_04[0x190];
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    void* VUR_Ptrs[9];
    unsigned long map_value;
    float attack_timer;
    unsigned char capture_flag;
    unsigned char gap_end[3];

    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(RGE_Master_Combat_Object* master, RGE_Player* player,
                      float x, float y, float z, int do_setup);
};

class RGE_Map;
class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(unsigned char master_type);
};

extern float save_game_version;
extern float DAT_00570500;
extern float DAT_00570504;
extern float DAT_00570508;
extern float DAT_00570510;
extern float DAT_00570518;

extern "C" {
    void rge_read(int file, void* buffer, int size);
    void rge_write(int file, void* buffer, int size);
}

#endif  // RGE_MCO_OBJ_SHARED_CONTEXT
#endif  // AOE1_M_CO_OBJ_CONTEXT_H
