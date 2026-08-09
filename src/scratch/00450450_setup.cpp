// VA: 00450450 RGE_Master_Combat_Object::setup (557B)
// m_co_obj.cpp
// Attempt log:
// - Baseline used typed armor/weapon records, the natural FILE setup call, and
//   the fscanf parameter-home destinations; it matched size but not block shape.
// - Saving the input FILE* and using positive-count allocation arms recovered
//   the original no-frame prologue and both allocation/scan CFGs.
// - A selected-sprite temporary with a positive nonnegative arm recovered the
//   original word selector reload and late null arm.
// - Scoped calloc-result temporaries were rolled back because they introduced
//   an EBP frame and displaced the exact prologue.
// - The retained source reuses the short scan index, value-count, and value
//   pointer in the same natural phases as the executable.  The final audit
//   replaced decompiler-style writes into pointer parameter homes with real
//   short parser outputs.  Current check is 557/557 bytes, 194 positional-diff
//   bytes, 92.90% shape, 100% calls;
//   remaining drift starts at the armor calloc store/compare scheduling and
//   register coloring in the final max scans.

#include <stdio.h>
#include <stdlib.h>

class RGE_Sprite;
class RGE_Sound;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Task_List;
class RGE_Player;
class RGE_Game_World;
class TDrawArea;
class RGE_Color_Table;

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
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
    char gap_005[0xB7];

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short count);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short count);
};

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

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short count);
};

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

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short count);
};

int RGE_Master_Combat_Object::setup(FILE* file, RGE_Sprite** sprites,
                                    RGE_Sound** sounds, short count) {
    short temp_base_armor;
    short temp_area_effect_level;
    short temp_break_off_combat;
    short temp_fire_missile_at_frame;
    short index;
    short* armor_count_value;
    int value_count;
    short* value_ptr;
    short sprite_index;
    RGE_Sprite* selected_sprite;

    RGE_Master_Action_Object::setup(file, sprites, sounds, count);
    master_type = 0x32;

    fscanf(file,
           "%hd %hd %hd %hd %hd %f %f %f %hd %hd %hd %hd %f %f %f %hd %f",
           &sprite_index, &temp_base_armor, &armor_num, &weapon_num,
           &defense_terrain_bonus,
           &weapon_range, &area_effect_range, &speed_of_attack, &missile_id,
           &base_hit_chance, &temp_break_off_combat,
           &temp_fire_missile_at_frame, &weapon_offset_x, &weapon_offset_y,
           &weapon_offset_z, &temp_area_effect_level, &minimum_weapon_range);

    armor_count_value = &armor_num;
    index = 0;
    if (*armor_count_value > 0) {
        armor = (RGE_Armor_Weapon_Info*)calloc((int)*armor_count_value, 4);
        if (0 < *armor_count_value) {
            do {
                fscanf(file, "%hd %hd", &armor[index].type,
                       &armor[index].value);
                ++index;
            } while (index < *armor_count_value);
        }
    } else {
        armor = (RGE_Armor_Weapon_Info*)0;
    }

    index = 0;
    if (weapon_num > 0) {
        weapon = (RGE_Armor_Weapon_Info*)calloc((int)weapon_num, 4);
        if (0 < weapon_num) {
            do {
                fscanf(file, "%hd %hd", &weapon[index].type,
                       &weapon[index].value);
                ++index;
            } while (index < weapon_num);
        }
    } else {
        weapon = (RGE_Armor_Weapon_Info*)0;
    }

    if (sprite_index >= 0)
        selected_sprite = sprites[sprite_index];
    else
        selected_sprite = (RGE_Sprite*)0;
    fight_sprite = selected_sprite;
    break_off_combat = (unsigned char)temp_break_off_combat;
    area_effect_level = (unsigned char)temp_area_effect_level;
    value_count = (int)*armor_count_value;
    base_armor = (unsigned char)temp_base_armor;
    fire_missile_at_frame = temp_fire_missile_at_frame;

    orig_armor = (unsigned char)base_armor;
    if (value_count > 0) {
        value_ptr = &armor->value;
        do {
            if (*value_ptr > orig_armor)
                orig_armor = *value_ptr;
            value_ptr += 2;
            --value_count;
        } while (value_count != 0);
    }

    value_count = (int)weapon_num;
    orig_weapon = 0;
    if (value_count > 0) {
        value_ptr = &weapon->value;
        do {
            if (*value_ptr > orig_weapon)
                orig_weapon = *value_ptr;
            value_ptr += 2;
            --value_count;
        } while (value_count != 0);
    }

    orig_weapon_range = weapon_range;
    orig_speed_of_attack = speed_of_attack;
    return 1;
}
