// VA: 005087C0 RGE_Task::load (rge_read, version-safe)
// PDB source: task.cpp
// Attempt log:
// - 600B, rge_read all fields + sprite/sound table ID lookups
// - Left in scratch after shallow pass

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

struct RGE_Task_load {
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
    
    void load(int fd, void** sprites, void** sounds, short a);
};

void RGE_Task_load::load(int fd, void** sprites, void** sounds, short a)
{
    short temp;
    
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
    
    // Sprite/sound ID lookups
    rge_read(fd, &temp, 2);
    move_sprite = (temp == -1) ? 0 : sprites[temp];
    
    rge_read(fd, &temp, 2);
    work_sprite = (temp == -1) ? 0 : sprites[temp];
    
    rge_read(fd, &temp, 2);
    work_sprite2 = (temp == -1) ? 0 : sprites[temp];
    
    rge_read(fd, &temp, 2);
    carry_sprite = (temp == -1) ? 0 : sprites[temp];
}
