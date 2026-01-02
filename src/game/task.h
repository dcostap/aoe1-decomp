#pragma once
#include "../common.h"

class RGE_Task {
public:
    uchar is_default;                        // 0x4
    short action_type;                       // 0x6
    short object_group;                      // 0x8
    short object_id;                         // 0xA
    uchar combat_level;                      // 0xC
    uchar combat_level_flag;                 // 0xD
    short terrain_id;                        // 0xE
    uchar owner_type;                        // 0x10
    uchar holding_attr;                      // 0x11
    uchar state_building;                    // 0x12
    short attribute_type;                    // 0x14
    short attribute_type2;                   // 0x16
    short attribute_type3;                   // 0x18
    short attribute_type4;                   // 0x1A
    float work_val1;                         // 0x1C
    float work_val2;                         // 0x20
    float work_range;                        // 0x24
    uchar search_flag;                       // 0x28
    float search_wait_time;                  // 0x2C
    short work_flag;                         // 0x30
    short work_flag2;                        // 0x32
    RGE_Sprite* move_sprite;                 // 0x34
    RGE_Sprite* work_sprite;                 // 0x38
    RGE_Sprite* work_sprite2;                // 0x3C
    RGE_Sprite* carry_sprite;                // 0x40
    RGE_Sound* work_sound;                   // 0x44
    RGE_Sound* work_sound2;                  // 0x48

    RGE_Task(short param_1);
    virtual ~RGE_Task();
    virtual void copy(RGE_Task* param_1);
    virtual void load(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    virtual void load(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    virtual void save(int param_1);
};

static_assert(sizeof(RGE_Task) == 0x4C, "RGE_Task Size Mismatch");
static_assert(offsetof(RGE_Task, work_sound2) == 0x48, "RGE_Task Offset Mismatch");

