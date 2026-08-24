#include "../../include/task_context.h"

// VA: 00508A20 RGE_Task::load (FILE* overload)
// PDB source: task.cpp, lines 154-218
// Attempt log:
// - Replaced the unrelated rge_read candidate with the period-plausible fscanf
//   reconstruction. The binary reads all scalar fields as text, then resolves
//   four sprite and two sound IDs through the supplied tables.
// - Baseline: 391B, frame 0x18, 31 differing bytes. All calls, fields, and
//   control flow aligned; only the final null store used a direct immediate.
// - Tried a branch-local selected-sound assignment; VC5 emitted the same code.
// - Kept the natural common selected-sound assignment after the final ID test.
//   This produced 389B and an exact positional match.
// - Replaced the parameter-home alias with a scanned short local. This keeps
//   the file parameter a FILE* while preserving the original field order.
// - Removed two unused decompiler-only combat temporaries. The natural source
//   still emits the same exact code.

extern int __cdecl fscanf(FILE* file, const char* format, ...);

void RGE_Task::load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short temp_is_default;
    short temp_combat_level;
    short temp_combat_level_flag;
    short temp_search_flag;
    short temp_owner_type;
    short temp_holding_attr;
    short temp_state_building;
    short move_sprite_id;
    short work_sprite_id;
    short work_sprite2_id;
    short carry_sprite_id;
    short work_sound_id;
    short work_sound2_id;
    RGE_Sprite* selected_sprite;
    RGE_Sound* selected_sound;

    fscanf(file, "%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f %f %f %hd %f %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd",
        &id, &temp_is_default, &action_type,
        &object_group, &object_id, &terrain_id,
        &attribute_type, &attribute_type2, &attribute_type3, &attribute_type4,
        &work_val1, &work_val2, &work_range,
        &temp_search_flag, &search_wait_time,
        &temp_combat_level, &temp_combat_level_flag,
        &work_flag, &work_flag2, &temp_owner_type,
        &temp_holding_attr, &temp_state_building,
        &move_sprite_id, &work_sprite_id, &work_sprite2_id, &carry_sprite_id,
        &work_sound_id, &work_sound2_id);

    is_default = (unsigned char)temp_is_default;
    combat_level = (unsigned char)temp_combat_level;
    combat_level_flag = (unsigned char)temp_combat_level_flag;
    search_flag = (unsigned char)temp_search_flag;
    owner_type = (unsigned char)temp_owner_type;
    holding_attr = (unsigned char)temp_holding_attr;
    state_building = (unsigned char)temp_state_building;

    if (move_sprite_id == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[move_sprite_id];
    move_sprite = selected_sprite;

    if (work_sprite_id == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[work_sprite_id];
    work_sprite = selected_sprite;

    if (work_sprite2_id == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[work_sprite2_id];
    work_sprite2 = selected_sprite;

    if (carry_sprite_id == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[carry_sprite_id];
    carry_sprite = selected_sprite;

    if (work_sound_id == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[work_sound_id];
    work_sound = selected_sound;

    if (work_sound2_id == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[work_sound2_id];
    work_sound2 = selected_sound;
}
