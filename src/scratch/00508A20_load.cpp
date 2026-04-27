// VA: 00508A20 RGE_Task::load (rge_read, version-check variant)
// PDB source: task.cpp
// Attempt log:
// - 389B, rge_read + version check + sound ID lookups
// - Left in scratch after shallow pass

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

struct RGE_Task_load2 {
    short task_type;        
    short id;               
    char is_default;        
    short action_type;      
    short object_group;     
    short object_id;        
    char combat_level;      
    char combat_level_flag; 
    short terrain_id;       
    char owner_type;        
    char holding_attr;      
    char state_building;    
    short attribute_type;   
    short attribute_type2;  
    short attribute_type3;  
    short attribute_type4;  
    float work_val1;        
    float work_val2;        
    float work_range;       
    char search_flag;       
    float search_wait_time; 
    short work_flag;        
    short work_flag2;       
    void* move_sprite;      
    void* work_sprite;      
    void* work_sprite2;     
    void* carry_sprite;     
    void* work_sound;       
    void* work_sound2;      
    
    void load(int fd, void** sprites, void** sounds);
};

void RGE_Task_load2::load(int fd, void** sprites, void** sounds)
{
    short temp;
    
    // Read sound IDs
    rge_read(fd, &temp, 2);
    work_sound = (temp == -1) ? 0 : sounds[temp];
    
    rge_read(fd, &temp, 2);
    work_sound2 = (temp == -1) ? 0 : sounds[temp];
    
    // Force task_type to 1
    task_type = 1;
}
