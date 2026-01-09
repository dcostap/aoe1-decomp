#pragma once
#include "common.h"

class RGE_Master_Player {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    char name[20];                           // 0x4
    short master_object_num;                 // 0x18
    RGE_Master_Static_Object** master_objects; // 0x1C
    short attribute_num;                     // 0x20
    float* attributes;                       // 0x24
    uchar culture;                           // 0x28
    uchar type;                              // 0x29
    short tribe_effect;                      // 0x2A

    virtual void finish_init(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3); // vt0[1]+0x4=0x4611D0
    virtual void load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // vt0[2]+0x8=0x461270
    virtual void create_master_object_space(short param_1); // vt0[3]+0xC=0x461530
    virtual void load_object(_iobuf* param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // vt0[4]+0x10=0x461560
    virtual void save(int param_1);                         // vt0[5]+0x14=0x461840
    RGE_Master_Player(_iobuf* param_1);
    RGE_Master_Player(int param_1);
    ~RGE_Master_Player();
};

static_assert(sizeof(RGE_Master_Player) == 0x2C, "RGE_Master_Player Size Mismatch");

