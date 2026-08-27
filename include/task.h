#ifndef AOE1_TASK_H
#define AOE1_TASK_H

struct _iobuf;
typedef struct _iobuf FILE;

class RGE_Sprite;
class RGE_Sound;

extern "C" void __cdecl rge_read(int fd, void* buffer, int size);
extern "C" void __cdecl rge_write(int fd, void* buffer, int size);

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    unsigned char pad_05;
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    unsigned char pad_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    unsigned char search_flag;
    unsigned char pad_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;

    RGE_Task(short param_1);
    ~RGE_Task();
    void copy(RGE_Task* src);
    void load(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
    void save(int fd);
};

typedef char rge_task_size_check[(sizeof(RGE_Task) == 0x4C) ? 1 : -1];

#endif
