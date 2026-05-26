// 00452B00 RGE_Master_Static_Object::setup(FILE*, RGE_Sprite**, RGE_Sound**, short)
// Attempt log:
// 1: source-level reconstruction from packet/PDB line map using typed fields and fscanf/calloc/getstring.
// 2: pulled exact fscanf format strings from original EXE and corrected the 51-field first fscanf argument order from Ghidra comments.
// 3: corrected temp_name+4, local_84/local_82 byte buffers, damage-sprite semantics, post-scan byte assignments, and zero-outline fallback checks.
// 4: adjusted temp_name to 128 bytes to recover original 0xC4 frame and exact 1183-byte size; first mismatch moved past prologue to first local LEA offset.
// 5: /Od probe produced EBP-frame debug-style code and was rolled back; not original basin.
// 6: left in scratch: remaining broad mismatch is local stack-slot packing/order around the huge fscanf argument list and later temp reuse; behavior model is close but not accepted_drift-safe.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class RGE_Sprite;
class RGE_Sound;
void __cdecl getstring(char** dest, char* src);

struct RGE_Damage_Sprite_Info { RGE_Sprite* sprite; unsigned char damage_percent; unsigned char flag; char pad[2]; };

class RGE_Master_Static_Object {
public:
    void* vtable_ptr; unsigned char master_type; char pad05[3]; char* name;
    short string_id; short string_id2; short id; short copy_id; short object_group; char pad16[2];
    RGE_Sprite* sprite; RGE_Sprite* death_sprite; RGE_Sprite* undead_sprite; unsigned char undead_flag; char pad25;
    short hp; float los; unsigned char obj_max; char pad2d[3]; float radius_x; float radius_y; float radius_z;
    RGE_Sound* selected_sound; RGE_Sound* created_sound; RGE_Sound* death_sound; short death_spawn_obj_id;
    unsigned char sort_number; unsigned char can_be_built_on; short button_pict; unsigned char hide_in_scenario_editor; char pad4f;
    short portrait_pict; unsigned char available; char pad53; short tile_req1; short tile_req2; short center_tile_req1; short center_tile_req2;
    float construction_radius_x; float construction_radius_y; unsigned char elevation_flag; unsigned char fog_flag; short terrain;
    unsigned char movement_type; char pad69; short attribute_type_held[3]; float attribute_amount_held[3];
    short attribute_max_amount; char pad7e[2]; float attribute_rot; float multiple_attribute_mod; unsigned char attribute_flag[3];
    unsigned char area_effect_object_level; unsigned char combat_level; unsigned char select_level; unsigned char map_draw_level;
    unsigned char unit_level; unsigned char map_color; unsigned char attack_reaction; unsigned char convert_terrain_flag;
    unsigned char damage_sprite_num; RGE_Damage_Sprite_Info* damage_sprites; int help_string_id; int help_page_id; int hotkey_id;
    unsigned char recyclable; unsigned char track_as_resource; unsigned char create_doppleganger_on_death; unsigned char resource_group;
    unsigned char draw_flag; unsigned char draw_color; char padaa[2]; float outline_radius_x; float outline_radius_y; float outline_radius_z;
    int setup(FILE* fp, RGE_Sprite** sprites, RGE_Sound** sounds, short object_id);
};

int RGE_Master_Static_Object::setup(FILE* fp, RGE_Sprite** sprites, RGE_Sound** sounds, short object_id)
{
    char temp_name[128];
    short temp_undead_sprite, temp_obj_max, temp_fog_flag, temp_hide, temp_movement;
    short temp_available, temp_damage_percent, temp_attack_reaction, temp_attribute_flag;
    short temp_created_sound, temp_can_be_built_on, temp_undead_flag, temp_sort_number;
    short temp_damage_sprite, temp_select_level, temp_map_draw_level, temp_command_level;
    short temp_death_sound, temp_flag, temp_sprite, temp_death_sprite, temp_convert_terrain_flag, temp_map_color;
    short temp_terrain, temp_resource_group, temp_draw_flag, temp_draw_color, temp_selected_sound;
    short temp_track_as_resource, temp_create_doppleganger_on_death, temp_elevation_flag;
    unsigned char local_84[2]; unsigned char local_82[2];

    master_type = 10;
    id = object_id;

    fscanf(fp, (char*)0x584934, temp_name + 4, &string_id, &string_id2, &object_group, &temp_undead_sprite,
           &temp_obj_max, &temp_fog_flag, &temp_hide, &hp, &los, &temp_movement, &radius_x,
           &radius_y, &radius_z, &death_spawn_obj_id, &temp_available, &temp_damage_percent,
           &button_pict, &temp_attack_reaction, &portrait_pict, &temp_attribute_flag, &tile_req1,
           &tile_req2, &center_tile_req1, &center_tile_req2, &construction_radius_x,
           &construction_radius_y, local_84, &temp_sort_number, &temp_undead_flag,
           &temp_can_be_built_on, &temp_created_sound, &attribute_max_amount,
           &multiple_attribute_mod, &attribute_rot, &temp_damage_sprite, &temp_select_level,
           &temp_map_draw_level, &temp_command_level, &temp_terrain, &temp_track_as_resource,
           &help_string_id, &help_page_id, &hotkey_id, &temp_create_doppleganger_on_death,
           &temp_resource_group, &temp_draw_flag, &temp_draw_color, &temp_elevation_flag,
           &outline_radius_x, &outline_radius_y, &outline_radius_z);

    for (int i=0; i<3; i++) {
        fscanf(fp, (char*)0x584928, &attribute_type_held[i], &attribute_amount_held[i], &temp_selected_sound);
        attribute_flag[i] = (unsigned char)temp_selected_sound;
    }

    fscanf(fp, (char*)0x5804E8, temp_name);
    damage_sprite_num = (unsigned char)*(int*)temp_name;
    if (damage_sprite_num) {
        damage_sprites = (RGE_Damage_Sprite_Info*)calloc((int)damage_sprite_num, 8);
        short i=0;
        if (damage_sprite_num) {
            do {
                fscanf(fp, (char*)0x58491C, &temp_flag, local_82, &temp_death_sound);
                damage_sprites[i].sprite = temp_flag < 0 ? 0 : sprites[temp_flag];
                damage_sprites[i].damage_percent = local_82[0];
                damage_sprites[i].flag = (unsigned char)temp_death_sound;
                i++;
            } while (i < (short)damage_sprite_num);
        }
    } else {
        damage_sprites = 0;
    }

    fscanf(fp, (char*)0x58490C, &temp_death_sprite, &temp_sprite, &temp_convert_terrain_flag, &temp_map_color);
    selected_sound = temp_death_sprite < 0 ? 0 : sounds[temp_death_sprite];
    death_sound = temp_sprite < 0 ? 0 : sounds[temp_sprite];
    created_sound = temp_can_be_built_on < 0 ? 0 : sounds[temp_can_be_built_on];
    sprite = temp_undead_sprite < 0 ? 0 : sprites[temp_undead_sprite];
    death_sprite = temp_obj_max < 0 ? 0 : sprites[temp_obj_max];
    undead_sprite = temp_fog_flag < 0 ? 0 : sprites[temp_fog_flag];

    elevation_flag = local_84[0];
    sort_number = (unsigned char)temp_available;
    movement_type = (unsigned char)temp_created_sound;
    fog_flag = (unsigned char)temp_sort_number;
    select_level = (unsigned char)temp_map_draw_level;
    obj_max = (unsigned char)temp_movement;
    can_be_built_on = (unsigned char)temp_damage_percent;
    available = (unsigned char)temp_attribute_flag;
    area_effect_object_level = (unsigned char)temp_damage_sprite;
    terrain = (unsigned char)temp_undead_flag;
    combat_level = (unsigned char)temp_select_level;
    map_draw_level = (unsigned char)temp_command_level;
    attack_reaction = (unsigned char)temp_convert_terrain_flag;
    unit_level = (unsigned char)temp_terrain;
    undead_flag = (unsigned char)temp_hide;
    track_as_resource = (unsigned char)temp_create_doppleganger_on_death;
    hide_in_scenario_editor = (unsigned char)temp_attack_reaction;
    convert_terrain_flag = (unsigned char)temp_map_color;
    draw_flag = (unsigned char)temp_draw_color;
    map_color = (unsigned char)temp_track_as_resource;
    create_doppleganger_on_death = (unsigned char)temp_resource_group;
    resource_group = (unsigned char)temp_draw_flag;
    draw_color = (unsigned char)temp_elevation_flag;

    if (outline_radius_x == *(float*)0x570618) outline_radius_x = radius_x;
    if (outline_radius_y == *(float*)0x570618) outline_radius_y = radius_y;
    if (outline_radius_z == *(float*)0x570618) outline_radius_z = radius_z;

    copy_id = id;
    recyclable = 0;
    if (object_group == 11) recyclable = 1;

    if ((short)strlen(temp_name + 4) > 0) {
        name = 0;
        getstring(&name, temp_name + 4);
    }
    return 1;
}
