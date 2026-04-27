// VA: 00508700 RGE_Task::copy
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
    
    void copy(RGE_Task* src);
};

void RGE_Task::copy(RGE_Task* src)
{
    is_default = src->is_default;
    action_type = src->action_type;
    object_group = src->object_group;
    object_id = src->object_id;
    terrain_id = src->terrain_id;
    attribute_type = src->attribute_type;
    attribute_type2 = src->attribute_type2;
    attribute_type3 = src->attribute_type3;
    attribute_type4 = src->attribute_type4;
    work_val1 = src->work_val1;
    work_val2 = src->work_val2;
    work_range = src->work_range;
    search_flag = src->search_flag;
    search_wait_time = src->search_wait_time;
    combat_level = src->combat_level;
    combat_level_flag = src->combat_level_flag;
    work_flag = src->work_flag;
    work_flag2 = src->work_flag2;
    owner_type = src->owner_type;
    holding_attr = src->holding_attr;
    state_building = src->state_building;
    move_sprite = src->move_sprite;
    work_sprite = src->work_sprite;
    work_sprite2 = src->work_sprite2;
    carry_sprite = src->carry_sprite;
    work_sound = src->work_sound;
    work_sound2 = src->work_sound2;
}
