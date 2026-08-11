// VA: 005087C0 RGE_Task::load
// PDB source: task.cpp, lines 103-149
// Attempt log:
// - Baseline reconstruction: typed RGE_Task layout, sequential rge_read field
//   loads, and sprite/sound ID resolution from the supplied tables.
// - Probe 2: kept one selected pointer per sprite/sound table and stored the
//   selected value after each ID branch, matching the binary's common stores.

extern "C" void rge_read(int fd, void* buffer, int size);

class RGE_Sprite;
class RGE_Sound;

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    char gap_05[1];
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    char gap_13[1];
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    unsigned char search_flag;
    char gap_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;

    void load(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
};

void RGE_Task::load(int fd, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short id_value;
    RGE_Sprite* selected_sprite;
    RGE_Sound* selected_sound;

    rge_read(fd, &id, 2);
    rge_read(fd, &is_default, 1);
    rge_read(fd, &action_type, 2);
    rge_read(fd, &object_group, 2);
    rge_read(fd, &object_id, 2);
    rge_read(fd, &terrain_id, 2);
    rge_read(fd, &attribute_type, 2);
    rge_read(fd, &attribute_type2, 2);
    rge_read(fd, &attribute_type3, 2);
    rge_read(fd, &attribute_type4, 2);
    rge_read(fd, &work_val1, 4);
    rge_read(fd, &work_val2, 4);
    rge_read(fd, &work_range, 4);
    rge_read(fd, &search_flag, 1);
    rge_read(fd, &search_wait_time, 4);
    rge_read(fd, &combat_level, 1);
    rge_read(fd, &combat_level_flag, 1);
    rge_read(fd, &work_flag, 2);
    rge_read(fd, &work_flag2, 2);
    rge_read(fd, &owner_type, 1);
    rge_read(fd, &holding_attr, 1);
    rge_read(fd, &state_building, 1);

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[id_value];
    move_sprite = selected_sprite;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[id_value];
    work_sprite = selected_sprite;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[id_value];
    work_sprite2 = selected_sprite;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[id_value];
    carry_sprite = selected_sprite;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[id_value];
    work_sound = selected_sound;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[id_value];
    work_sound2 = selected_sound;
}
