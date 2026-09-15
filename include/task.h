#ifndef AOE1_TASK_H
#define AOE1_TASK_H

#include <stdio.h>

class RGE_Sprite;
class RGE_Sound;

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    unsigned char search_flag;
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;

    RGE_Task(short id_in);
    ~RGE_Task();
    void copy(RGE_Task* other_task);
    void load(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    void load(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    void save(int outfile);
};

typedef char rge_task_size_check[(sizeof(RGE_Task) == 0x4C) ? 1 : -1];

#endif
