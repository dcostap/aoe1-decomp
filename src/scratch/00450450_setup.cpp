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
//   pointer in the same natural phases as the executable.  Best check is
//   557/557 bytes, 194 positional-diff bytes, 92.90% shape, 100% calls;
//   remaining drift starts at the armor calloc store/compare scheduling and
//   register coloring in the final max scans.
// - Bounded follow-up: typed short declaration order/scope, byte-width output
//   probes, a contiguous local record, a natural FILE alias, and dead short
//   count-home reuse did not improve the clean typed source; the aggregate and
//   byte variants disturbed the prologue or stack topology.
// - Fresh follow-up reused the exact modify/save/copy combat hierarchy. Raw
//   FILE/sounds parameter-home outputs were diagnostic compiler steering;
//   main-agent audit restored ordinary named parser-output locals. Explicit
//   count-home sprite output was worse, while the natural local sprite form
//   retained the clean reconstruction.
// - Using the canonical armor_num member for the inner armor scan guard fixed
//   the allocator block and reached 181 bytes; moving the parser-output stores
//   to the observed break/area/fight/base/fire/count order reached 177 bytes.
// - A four-way natural max-scan lab (shared/separate/pointer-first/scoped
//   count/pointer locals) emitted one identical nonexact group; the remaining
//   drift is localized to assignment scheduling and max-scan register
//   coloring. The 177-byte parameter-home diagnostic is not retained; the
//   audited named-local source is 557/557 bytes, 182 diff bytes, 92.90% shape,
//   and preserves all six ordered calls under default /O2 /Oy.
// - Exact m_co_obj setup donor evidence supported one persistent count local,
//   scoped short value pointers, and inner remaining counters for both max
//   scans. This clean source shape reduced the current positional diff to 150
//   bytes and made both scan bodies instruction-identical; parser stack-home
//   scheduling remains the first mismatch. A duplicate scoped-pointer check
//   confirmed no further codegen change, so no blind variants were retained.

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

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
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
    char gap_005[0xB3];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short count);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];
    virtual void modify(float value, unsigned char attribute);

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
    FILE* input = file;
    short temp_base_armor;
    short temp_area_effect_level;
    short temp_break_off_combat;
    short temp_fire_missile_at_frame;
    short index;
    short* armor_count_value;
    int value_count;
    short sprite_index;
    RGE_Sprite* selected_sprite;

    RGE_Master_Action_Object::setup(input, sprites, sounds, count);
    master_type = 0x32;

    fscanf(input,
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
        if (0 < armor_num) {
            do {
                fscanf(input, "%hd %hd", &armor[index].type,
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
                fscanf(input, "%hd %hd", &weapon[index].type,
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
    break_off_combat = (unsigned char)temp_break_off_combat;
    area_effect_level = (unsigned char)temp_area_effect_level;
    fight_sprite = selected_sprite;
    base_armor = (unsigned char)temp_base_armor;
    fire_missile_at_frame = temp_fire_missile_at_frame;
    orig_armor = (unsigned char)base_armor;
    value_count = (int)armor_num;
    if (value_count > 0) {
        short* value = &armor->value;
        int left = value_count;
        do {
            if (*value > orig_armor)
                orig_armor = *value;
            value += 2;
            --left;
        } while (left != 0);
    }

    orig_weapon = 0;
    value_count = (int)weapon_num;
    if (value_count > 0) {
        short* value = &weapon->value;
        int left = value_count;
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
