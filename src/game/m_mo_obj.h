#pragma once
#include "../common.h"

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;                 // 0xBC
    RGE_Sprite* run_sprite;                  // 0xC0
    float turn_speed;                        // 0xC4
    uchar size_class;                        // 0xC8
    short obj_trail_id;                      // 0xCA
    uchar obj_trail_options;                 // 0xCC
    float obj_trail_spacing;                 // 0xD0
    uchar move_algorithem;                   // 0xD4

    RGE_Master_Moving_Object(RGE_Master_Moving_Object* param_1, int param_2);
    RGE_Master_Moving_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Moving_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    virtual int setup(RGE_Master_Moving_Object* param_1);
    virtual int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    virtual int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    virtual ~RGE_Master_Moving_Object();
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual void copy_obj(RGE_Master_Static_Object* param_1);
    virtual void modify(float param_1, uchar param_2);
    virtual void modify_delta(float param_1, uchar param_2);
    virtual void modify_percent(float param_1, uchar param_2);
    virtual void save(int param_1);
};

static_assert(sizeof(RGE_Master_Moving_Object) == 0xD8, "RGE_Master_Moving_Object Size Mismatch");
static_assert(offsetof(RGE_Master_Moving_Object, move_algorithem) == 0xD4, "RGE_Master_Moving_Object Offset Mismatch");

