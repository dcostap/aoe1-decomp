// Authentic task.cpp translation-unit context.
//
// The PDB source order is the order of the member definitions included by
// src/task_tu.cpp.  The fields below are the one RGE_Task object layout used by
// all six task.cpp owners.  Ordinary compiler alignment supplies the
// unaddressed bytes between narrow fields and aligned members.

#ifndef AOE1_TASK_CONTEXT_H
#define AOE1_TASK_CONTEXT_H

struct _iobuf;
typedef struct _iobuf FILE;
class RGE_Sprite;
class RGE_Sound;

extern "C" void rge_read(int fd, void* buffer, int size);
extern "C" void rge_write(int fd, void* buffer, int size);

class RGE_Task {
public:
    short task_type;             // +0x00
    short id;                    // +0x02
    unsigned char is_default;    // +0x04
    short action_type;           // +0x06
    short object_group;          // +0x08
    short object_id;             // +0x0A
    unsigned char combat_level;  // +0x0C
    unsigned char combat_level_flag; // +0x0D
    short terrain_id;            // +0x0E
    unsigned char owner_type;    // +0x10
    unsigned char holding_attr;  // +0x11
    unsigned char state_building; // +0x12
    short attribute_type;        // +0x14
    short attribute_type2;       // +0x16
    short attribute_type3;       // +0x18
    short attribute_type4;       // +0x1A
    float work_val1;             // +0x1C
    float work_val2;             // +0x20
    float work_range;            // +0x24
    unsigned char search_flag;   // +0x28
    float search_wait_time;      // +0x2C
    short work_flag;             // +0x30
    short work_flag2;            // +0x32
    RGE_Sprite* move_sprite;     // +0x34
    RGE_Sprite* work_sprite;     // +0x38
    RGE_Sprite* work_sprite2;    // +0x3C
    RGE_Sprite* carry_sprite;    // +0x40
    RGE_Sound* work_sound;       // +0x44
    RGE_Sound* work_sound2;      // +0x48

    RGE_Task(short param_1);
    ~RGE_Task();
    void copy(RGE_Task* src);
    void load(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
    void save(int fd);
};

#endif
