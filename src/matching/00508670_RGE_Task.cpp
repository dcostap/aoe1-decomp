// VA: 00508670 RGE_Task::RGE_Task (short ctor)
// PDB source: task.cpp

struct RGE_Task {
    short task_type;        // +0x00
    short id;               // +0x02
    char is_default;        // +0x04
    short action_type;      // +0x06
    short object_group;     // +0x08
    short object_id;        // +0x0A
    char combat_level;      // +0x0C
    char combat_level_flag; // +0x0D
    short terrain_id;       // +0x0E
    char owner_type;        // +0x10
    char holding_attr;      // +0x11
    char state_building;    // +0x12
    short attribute_type;   // +0x14
    short attribute_type2;  // +0x16
    short attribute_type3;  // +0x18
    short attribute_type4;  // +0x1A
    float work_val1;        // +0x1C
    float work_val2;        // +0x20
    float work_range;       // +0x24
    char search_flag;       // +0x28
    float search_wait_time; // +0x2C
    short work_flag;        // +0x30
    short work_flag2;       // +0x32
    void* move_sprite;      // +0x34
    void* work_sprite;      // +0x38
    void* work_sprite2;     // +0x3C
    void* carry_sprite;     // +0x40
    void* work_sound;       // +0x44
    void* work_sound2;      // +0x48
    RGE_Task(short param_1);
};

RGE_Task::RGE_Task(short param_1)
{
    id = param_1;
    task_type = 1;
    is_default = 0;
    action_type = 0;
    object_group = 0;
    object_id = 0;
    terrain_id = -1;
    attribute_type = -1;
    attribute_type2 = -1;
    attribute_type3 = -1;
    attribute_type4 = -1;
    work_val1 = 0.0f;
    work_val2 = 0.0f;
    work_range = 0.0f;
    search_flag = 0;
    search_wait_time = 0.0f;
    combat_level = 0;
    combat_level_flag = 0;
    work_flag = 0;
    work_flag2 = 0;
    owner_type = 0;
    holding_attr = 0;
    state_building = 0;
    move_sprite = 0;
    work_sprite = 0;
    work_sprite2 = 0;
    carry_sprite = 0;
    work_sound = 0;
    work_sound2 = 0;
}
