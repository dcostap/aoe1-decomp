// VA: 00450170 setup (730B)
// m_co_obj.cpp
// Attempt log:
// - Baseline reconstruction: period serialized combat-master setup with
//   typed armor/weapon records, version-gated saved maxima, and named fields.
// - Positive allocation guards recovered the full serialized prefix and CFG.
// - Exact breakthrough: retain one shared count, but use separate short
//   value-field cursors and inner remaining counters for the two legacy maxima
//   scans.  This natural value-field ownership reproduces the original
//   movzx/store-before-count reload and ECX/EAX pointer coloring exactly.

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buffer, int size);
}

extern float save_game_version;
extern float DAT_00570500;

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

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int fd);
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
    char gap_005[0xB3];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x04];

    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];

    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
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

    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
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

    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
};

int RGE_Master_Combat_Object::setup(int fd, RGE_Sprite** sprites,
                                    RGE_Sound** sounds) {
    int count;

    RGE_Master_Action_Object::setup(fd, sprites, sounds);
    master_type = 0x32;

    rge_read(fd, &base_armor, 1);
    rge_read(fd, &weapon_num, 2);
    if (weapon_num > 0) {
        weapon = (RGE_Armor_Weapon_Info*)calloc((int)weapon_num, 4);
        rge_read(fd, weapon, (int)weapon_num << 2);
    } else {
        weapon = (RGE_Armor_Weapon_Info*)0;
    }

    rge_read(fd, &armor_num, 2);
    if (armor_num > 0) {
        armor = (RGE_Armor_Weapon_Info*)calloc((int)armor_num, 4);
        rge_read(fd, armor, (int)armor_num << 2);
    } else {
        armor = (RGE_Armor_Weapon_Info*)0;
    }

    rge_read(fd, &defense_terrain_bonus, 2);
    rge_read(fd, &weapon_range, 4);
    rge_read(fd, &area_effect_range, 4);
    rge_read(fd, &speed_of_attack, 4);
    rge_read(fd, &missile_id, 2);
    rge_read(fd, &base_hit_chance, 2);
    rge_read(fd, &break_off_combat, 1);
    rge_read(fd, &fire_missile_at_frame, 2);
    rge_read(fd, &weapon_offset_x, 4);
    rge_read(fd, &weapon_offset_y, 4);
    rge_read(fd, &weapon_offset_z, 4);
    rge_read(fd, &area_effect_level, 1);
    rge_read(fd, &minimum_weapon_range, 4);

    short sprite_id;
    RGE_Sprite* selected_sprite;
    rge_read(fd, &sprite_id, 2);
    if (sprite_id >= 0)
        selected_sprite = sprites[sprite_id];
    else
        selected_sprite = (RGE_Sprite*)0;
    fight_sprite = selected_sprite;

    if (save_game_version >= DAT_00570500) {
        rge_read(fd, &orig_armor, 2);
        rge_read(fd, &orig_weapon, 2);
        rge_read(fd, &orig_weapon_range, 4);
        rge_read(fd, &orig_speed_of_attack, 4);
        return 1;
    }

    orig_armor = (unsigned char)base_armor;
    count = (int)armor_num;
    if (count > 0) {
        short* value = &armor->value;
        int left = count;
        do {
            if (*value > orig_armor)
                orig_armor = *value;
            value += 2;
            --left;
        } while (left != 0);
    }

    orig_weapon = 0;
    count = (int)weapon_num;
    if (count > 0) {
        short* value = &weapon->value;
        int left = count;
        do {
            if (*value > orig_weapon)
                orig_weapon = *value;
            value += 2;
            --left;
        } while (left != 0);
    }

    orig_weapon_range = weapon_range;
    orig_speed_of_attack = speed_of_attack;
    return 1;
}
