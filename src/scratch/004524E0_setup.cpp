// 004524E0 RGE_Master_Static_Object::setup(int, RGE_Sprite**, RGE_Sound**)
// Attempt 1: direct binary-read reconstruction from m_s_obj.cpp packet.
// Attempt 2: preserved incoming handle in iVar2 and reused param_1 as the first 2-byte count; frame/first 307 bytes aligned.
// Attempt 3: used absolute save-version globals and inverted version gates to recover the 0xA8 fallback block; first mismatch moved to damage-sprite loop.
// Attempt 4: changed damage-sprite zero tests to >0, matching both jbe branches; remaining gap is sprite-loop branch/register shape and later tail.
// left in scratch: validated 161-byte strict drift, 10.3007%, first mismatch +0499;
// exact size/frame/call sequence but localized sprite-loop branch shape remains. No promotion.

#include "../../include/game_globals.h"

class RGE_Sprite;
class RGE_Sound;
struct RGE_Damage_Sprite_Info {
    RGE_Sprite* sprite;
    unsigned char damage_percent;
    unsigned char flag;
    unsigned char pad[2];
};

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl getstring(char** dest, char* src);
extern float save_game_version;
extern float DAT_00570610;
extern float DAT_00570614;

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    unsigned char master_type;
    unsigned char pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char pad_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    unsigned char pad_25;
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char pad_2d[3];
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
    unsigned char pad_4f;
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
    unsigned char pad_7e[2];
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
    unsigned char pad_aa[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;

    int setup(int handle, RGE_Sprite** sprites, RGE_Sound** sounds);
};

int RGE_Master_Static_Object::setup(int param_1, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short temp_damage_sprite;
    short selected_sound_num;
    short death_sound_num;
    short created_sound_num;
    short sprite_num;
    short death_sprite_num;
    short undead_sprite_num;
    short local_c;
    short local_a;
    unsigned char* attribute_flags;
    float* attribute_amounts;
    short* attribute_types;
    int count;
    int iVar2 = param_1;

    this->master_type = 10;
    rge_read(iVar2, &param_1, 2);
    rge_read(iVar2, &this->id, 2);
    rge_read(iVar2, &this->string_id, 2);
    rge_read(iVar2, &this->string_id2, 2);
    rge_read(iVar2, &this->object_group, 2);
    rge_read(iVar2, &undead_sprite_num, 2);
    rge_read(iVar2, &local_c, 2);
    rge_read(iVar2, &local_a, 2);
    rge_read(iVar2, &this->undead_flag, 1);
    rge_read(iVar2, &this->hp, 2);
    rge_read(iVar2, &this->los, 4);
    rge_read(iVar2, &this->obj_max, 1);
    rge_read(iVar2, &this->radius_x, 4);
    rge_read(iVar2, &this->radius_y, 4);
    rge_read(iVar2, &this->radius_z, 4);
    rge_read(iVar2, &death_sprite_num, 2);
    rge_read(iVar2, &this->death_spawn_obj_id, 2);
    rge_read(iVar2, &this->sort_number, 1);
    rge_read(iVar2, &this->can_be_built_on, 1);
    rge_read(iVar2, &this->button_pict, 2);
    rge_read(iVar2, &this->hide_in_scenario_editor, 1);
    rge_read(iVar2, &this->portrait_pict, 2);
    rge_read(iVar2, &this->available, 1);
    rge_read(iVar2, &this->tile_req1, 2);
    rge_read(iVar2, &this->tile_req2, 2);
    rge_read(iVar2, &this->center_tile_req1, 2);
    rge_read(iVar2, &this->center_tile_req2, 2);
    rge_read(iVar2, &this->construction_radius_x, 4);
    rge_read(iVar2, &this->construction_radius_y, 4);
    rge_read(iVar2, &this->elevation_flag, 1);
    rge_read(iVar2, &this->fog_flag, 1);
    rge_read(iVar2, &this->terrain, 2);
    rge_read(iVar2, &this->movement_type, 1);
    rge_read(iVar2, &this->attribute_max_amount, 2);
    rge_read(iVar2, &this->attribute_rot, 4);
    rge_read(iVar2, &this->area_effect_object_level, 1);
    rge_read(iVar2, &this->combat_level, 1);
    rge_read(iVar2, &this->select_level, 1);
    rge_read(iVar2, &this->map_draw_level, 1);
    rge_read(iVar2, &this->unit_level, 1);
    rge_read(iVar2, &this->multiple_attribute_mod, 4);
    rge_read(iVar2, &this->map_color, 1);
    rge_read(iVar2, &this->help_string_id, 4);
    rge_read(iVar2, &this->help_page_id, 4);
    rge_read(iVar2, &this->hotkey_id, 4);
    rge_read(iVar2, &this->recyclable, 1);
    rge_read(iVar2, &this->track_as_resource, 1);
    rge_read(iVar2, &this->create_doppleganger_on_death, 1);
    rge_read(iVar2, &this->resource_group, 1);

    if (!(save_game_version < DAT_00570610)) {
        rge_read(iVar2, &this->draw_flag, 1);
        rge_read(iVar2, &this->draw_color, 1);
        rge_read(iVar2, &this->outline_radius_x, 4);
        rge_read(iVar2, &this->outline_radius_y, 4);
        rge_read(iVar2, &this->outline_radius_z, 4);
    } else {
        this->draw_flag = 0;
        this->draw_color = 0;
        this->outline_radius_x = this->radius_x;
        this->outline_radius_y = this->radius_y;
        this->outline_radius_z = this->radius_z;
    }

    attribute_flags = this->attribute_flag;
    attribute_amounts = this->attribute_amount_held;
    attribute_types = this->attribute_type_held;
    count = 3;
    do {
        rge_read(iVar2, attribute_types, 2);
        rge_read(iVar2, attribute_amounts, 4);
        rge_read(iVar2, attribute_flags, 1);
        attribute_types++;
        attribute_amounts++;
        attribute_flags++;
        count--;
    } while (count != 0);

    rge_read(iVar2, &this->damage_sprite_num, 1);
    if (this->damage_sprite_num > 0) {
        this->damage_sprites = (RGE_Damage_Sprite_Info*)calloc(this->damage_sprite_num, 8);
        short i = 0;
        if (this->damage_sprite_num > 0) {
            do {
                rge_read(iVar2, &death_sound_num, 2);
                rge_read(iVar2, &this->damage_sprites[i].damage_percent, 2);
                rge_read(iVar2, &this->damage_sprites[i].flag, 1);
                this->damage_sprites[i].sprite = death_sound_num < 0 ? 0 : sprites[death_sound_num];
                i++;
            } while (i < (short)this->damage_sprite_num);
        }
    } else {
        this->damage_sprites = 0;
    }

    rge_read(iVar2, &created_sound_num, 2);
    rge_read(iVar2, &sprite_num, 2);
    rge_read(iVar2, &this->attack_reaction, 1);
    rge_read(iVar2, &this->convert_terrain_flag, 1);

    if ((short)param_1 < 1) {
        this->name = 0;
    } else {
        this->name = (char*)calloc((short)param_1, 1);
        rge_read(iVar2, this->name, (short)param_1);
    }

    if (!(save_game_version < DAT_00570614)) {
        rge_read(iVar2, &this->copy_id, 2);
    }

    this->selected_sound = created_sound_num < 0 ? 0 : sounds[created_sound_num];
    this->death_sound = sprite_num < 0 ? 0 : sounds[sprite_num];
    this->created_sound = death_sprite_num < 0 ? 0 : sounds[death_sprite_num];
    this->sprite = undead_sprite_num < 0 ? 0 : sprites[undead_sprite_num];
    this->death_sprite = local_c < 0 ? 0 : sprites[local_c];
    this->undead_sprite = local_a < 0 ? 0 : sprites[local_a];

    return 1;
}
