// 00452B00 RGE_Master_Static_Object::setup(FILE*, RGE_Sprite**, RGE_Sound**, short)
// Attempt log:
// 1: source-level reconstruction from packet/PDB line map using typed fields and fscanf/calloc/getstring.
// 2: pulled exact fscanf format strings from original EXE and corrected the 51-field first fscanf argument order from Ghidra comments.
// 3: corrected temp_name+4, local_84/local_82 byte buffers, damage-sprite semantics, post-scan byte assignments, and zero-outline fallback checks.
// 4: adjusted temp_name to 128 bytes to recover the original 0xC4 frame and exact 1183-byte size; first mismatch moved past the first local LEA.
// 5-8: restored the pointer-based attribute loop, >0 damage guards, and original temporary declaration/lifetime evidence; stack packing remained broad.
// Attempt 9: typed local aggregate follows the proven C4 frame offsets; reduced the strict drift from 835 to 205 bytes and made the first 574 bytes exact.
// Attempt 10: scoping the final sprite result was codegen-duplicate; no further productive hypotheses remain in this assignment.
// Attempt 11: direct member stores for the three sprite lookups moved the first hunk earlier, enlarged the drift to 493, and were rolled back.
// Attempt 12: pointer-member and commuted damage-record address spellings were codegen-duplicate; rolled back as diagnostic forms.
// Attempt 13: a ternary final sprite assignment was codegen-duplicate; retained the named-result form.
// Attempt 14: named DAT_00570618 and period-likely fscanf literals moved the first hunk to 00452E24 and reduced drift to 199 bytes; kept.
// Attempt 15: function-scope sprite result and explicit terrain width were codegen-duplicate; kept the period-plausible scope.
// Attempt 16: a 24-case scalar store-order lab found edit diff 92 and positional diff 196, but every case kept the first mismatch and reversed PDB order; diagnostic only.
// Worker pass: 20 additional probes covered statement order, result lifetimes, declaration order, headers, class surface,
// register hints, flags, and damage-pointer ownership. None improved the pinned source; all are recorded in target history.
// Revisit pass: ten focused probes covered natural local declarations, typed widths, lexical grouping, member qualification,
// and isolated sound/sprite result lifetimes. Natural locals changed the frame to 0xC0 and 982 bytes. The other forms were worse
// or codegen-duplicate. The clean aggregate-backed source remains the smallest validated frontier.
// TU pass: 20 new probes tested period headers, API declarations, same-file class surfaces, type aliases, local declaration order,
// and decompiler-listed string locals. None changed the 199-byte frontier. Natural declarations still produced a C0 frame.
// BINARY NOTE: the original stores undead_sprite at 00452E24 before the scalar-byte block. The natural source below preserves
// that behavior, but VC5 schedules two later byte loads before the store. Do not add volatility or address tricks without proof.
// left in scratch: 199-byte strict drift begins at 00452E24 in scalar-store scheduling after the final lookup; calls, size, frame, and CFG match.
// BLOCKER: the scalar block changes member publication order. The executable
// stores movement_type before fog_flag, while the rebuild stores fog_flag first;
// other byte fields also swap. The executable performs the first outline-radius
// x87 comparison before many of these stores, but the rebuild performs it after
// them. Member visibility, fault order, and FP-exception timing differ.
// Context probe: an authentic owner-order wrapper with offset-equivalent,
// gap-only RGE_Game_World and RGE_Map declarations kept the 199-byte diff,
// 1183-byte body, and C4 frame. Shared world/map vptr context is not the
// publication-order cause. The diagnostic variant was not retained.
// PDB-home audit: CodeView proves 33 short parser locals from -C2 through -82.
// It also proves temp_damage_sprite_num at -7C and char temp_name[120] at -78.
// The aggregate below preserves those addresses. Its shifted names are not
// canonical ownership claims.
// Follow-up: natural PDB-named locals kept the C4 frame but produced 1186 bytes.
// They moved the first mismatch to +38 and were not retained.
// Literal-zero, scalar-order, byte-local, CPU, and cursor labs found no exact result.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class RGE_Sprite;
class RGE_Sound;
void __cdecl getstring(char** dest, char* src);

#ifndef RGE_MS_OBJ_SHARED_CONTEXT
struct RGE_Damage_Sprite_Info {
    RGE_Sprite* sprite;
    unsigned char damage_percent;
    unsigned char flag;
    char pad[2];
};

struct RGE_Master_Static_Object_Setup_Locals {
    unsigned char pad_00[2];
    short temp_damage_sprite;          // +0x02
    short temp_select_level;           // +0x04
    short temp_flag;                   // +0x06
    short temp_map_draw_level;         // +0x08
    short temp_death_sound;            // +0x0A
    short temp_command_level;          // +0x0C
    short temp_sprite;                 // +0x0E
    short temp_terrain;                // +0x10
    short temp_undead_sprite;          // +0x12
    short temp_undead_flag;            // +0x14
    short temp_fog_flag;               // +0x16
    short temp_hide;                   // +0x18
    short temp_sort_number;            // +0x1A
    short temp_attack_reaction;        // +0x1C
    short temp_available;              // +0x1E
    short temp_convert_terrain_flag;   // +0x20
    short temp_attribute_flag;         // +0x22
    short temp_map_color;              // +0x24
    short temp_selected_sound;         // +0x26
    short temp_track_as_resource;      // +0x28
    short temp_death_sprite;           // +0x2A
    short temp_create_doppleganger_on_death; // +0x2C
    short temp_obj_max;                // +0x2E
    short temp_resource_group;         // +0x30
    short temp_movement;               // +0x32
    short temp_draw_flag;              // +0x34
    short temp_created_sound;          // +0x36
    short temp_draw_color;             // +0x38
    short temp_can_be_built_on;        // +0x3A
    short temp_elevation_flag;         // +0x3C
    short temp_damage_percent;         // +0x3E
    unsigned char local_84[2];         // +0x40
    unsigned char local_82[2];         // +0x42
    int count;                         // +0x44
    char temp_name[120];               // +0x48
    unsigned char tail[4];             // +0xC0
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type; char pad05[3]; char* name;
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
#endif

int RGE_Master_Static_Object::setup(FILE* fp, RGE_Sprite** sprites, RGE_Sound** sounds, short object_id)
{
    RGE_Master_Static_Object_Setup_Locals local;
    unsigned char* attribute_flags;
    float* attribute_amounts;
    short* attribute_types;
    RGE_Sound* sound_value;
    RGE_Sprite* sprite_value;

    master_type = 10;
    id = object_id;

    fscanf(fp, "%s %hd %hd %hd %hd %hd %hd %hd %hd %f %hd %f %f %f %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd %hd %hd %hd %d %d %d %hd %hd %hd %hd %hd %f %f %f", local.temp_name + 4, &string_id, &string_id2, &object_group, &local.temp_undead_sprite,
           &local.temp_obj_max, &local.temp_fog_flag, &local.temp_hide, &hp, &los, &local.temp_movement, &radius_x,
           &radius_y, &radius_z, &death_spawn_obj_id, &local.temp_available, &local.temp_damage_percent,
           &button_pict, &local.temp_attack_reaction, &portrait_pict, &local.temp_attribute_flag, &tile_req1,
           &tile_req2, &center_tile_req1, &center_tile_req2, &construction_radius_x,
           &construction_radius_y, local.local_84, &local.temp_sort_number, &local.temp_undead_flag,
           &local.temp_can_be_built_on, &local.temp_created_sound, &attribute_max_amount,
           &multiple_attribute_mod, &attribute_rot, &local.temp_damage_sprite, &local.temp_select_level,
           &local.temp_map_draw_level, &local.temp_command_level, &local.temp_terrain, &local.temp_track_as_resource,
           &help_string_id, &help_page_id, &hotkey_id, &local.temp_create_doppleganger_on_death,
           &local.temp_resource_group, &local.temp_draw_flag, &local.temp_draw_color, &local.temp_elevation_flag,
           &outline_radius_x, &outline_radius_y, &outline_radius_z);

    attribute_flags = this->attribute_flag;
    attribute_types = this->attribute_type_held;
    attribute_amounts = this->attribute_amount_held;
    local.count = 3;
    do {
        fscanf(fp, "%hd %f %hd", attribute_types, attribute_amounts, &local.temp_selected_sound);
        *attribute_flags = (unsigned char)local.temp_selected_sound;
        attribute_amounts++;
        attribute_types++;
        attribute_flags++;
        local.count--;
    } while (local.count != 0);

    fscanf(fp, "%hd", local.temp_name);
    damage_sprite_num = (unsigned char)*(int*)local.temp_name;
    if (damage_sprite_num > 0) {
        damage_sprites = (RGE_Damage_Sprite_Info*)calloc((int)damage_sprite_num, 8);
        short i = 0;
        if (damage_sprite_num > 0) {
            do {
                fscanf(fp, "%hd %hd %hd", &local.temp_flag, local.local_82, &local.temp_death_sound);
                RGE_Sprite* damage_sprite;
                if (local.temp_flag >= 0) damage_sprite = sprites[local.temp_flag];
                else damage_sprite = 0;
                damage_sprites[i].sprite = damage_sprite;
                damage_sprites[i].damage_percent = local.local_82[0];
                damage_sprites[i].flag = (unsigned char)local.temp_death_sound;
                i++;
            } while (i < (short)damage_sprite_num);
        }
    } else {
        damage_sprites = 0;
    }

    fscanf(fp, "%hd %hd %hd %hd", &local.temp_death_sprite, &local.temp_sprite,
           &local.temp_convert_terrain_flag, &local.temp_map_color);

    if (local.temp_death_sprite >= 0) sound_value = sounds[local.temp_death_sprite];
    else sound_value = 0;
    selected_sound = sound_value;
    if (local.temp_sprite >= 0) sound_value = sounds[local.temp_sprite];
    else sound_value = 0;
    death_sound = sound_value;
    if (local.temp_can_be_built_on >= 0) sound_value = sounds[local.temp_can_be_built_on];
    else sound_value = 0;
    created_sound = sound_value;
    {
        if (local.temp_undead_sprite >= 0) sprite_value = sprites[local.temp_undead_sprite];
        else sprite_value = 0;
        sprite = sprite_value;
        if (local.temp_obj_max >= 0) sprite_value = sprites[local.temp_obj_max];
        else sprite_value = 0;
        death_sprite = sprite_value;
        if (local.temp_fog_flag >= 0) sprite_value = sprites[local.temp_fog_flag];
        else sprite_value = 0;
        undead_sprite = sprite_value;
    }

    elevation_flag = local.local_84[0];
    sort_number = (unsigned char)local.temp_available;
    movement_type = (unsigned char)local.temp_created_sound;
    fog_flag = (unsigned char)local.temp_sort_number;
    select_level = (unsigned char)local.temp_map_draw_level;
    obj_max = (unsigned char)local.temp_movement;
    can_be_built_on = (unsigned char)local.temp_damage_percent;
    available = (unsigned char)local.temp_attribute_flag;
    area_effect_object_level = (unsigned char)local.temp_damage_sprite;
    terrain = (unsigned char)local.temp_undead_flag;
    combat_level = (unsigned char)local.temp_select_level;
    map_draw_level = (unsigned char)local.temp_command_level;
    attack_reaction = (unsigned char)local.temp_convert_terrain_flag;
    unit_level = (unsigned char)local.temp_terrain;
    undead_flag = (unsigned char)local.temp_hide;
    track_as_resource = (unsigned char)local.temp_create_doppleganger_on_death;
    hide_in_scenario_editor = (unsigned char)local.temp_attack_reaction;
    convert_terrain_flag = (unsigned char)local.temp_map_color;
    draw_flag = (unsigned char)local.temp_draw_color;
    map_color = (unsigned char)local.temp_track_as_resource;
    create_doppleganger_on_death = (unsigned char)local.temp_resource_group;
    resource_group = (unsigned char)local.temp_draw_flag;
    draw_color = (unsigned char)local.temp_elevation_flag;

    extern float DAT_00570618;
    if (outline_radius_x == DAT_00570618) outline_radius_x = radius_x;
    if (outline_radius_y == DAT_00570618) outline_radius_y = radius_y;
    if (outline_radius_z == DAT_00570618) outline_radius_z = radius_z;

    recyclable = 0;
    copy_id = id;
    if (object_group == 11) recyclable = 1;

    if ((short)strlen(local.temp_name + 4) > 0) {
        name = 0;
        getstring(&name, local.temp_name + 4);
    }
    return 1;
}
