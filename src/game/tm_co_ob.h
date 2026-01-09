#pragma once
#include "common.h"

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    Attribute_Cost build_inventory[3];       // 0x148
    short build_pts_required;                // 0x15A
    short id_of_building_obj;                // 0x15C
    uchar button_location;                   // 0x15E
    short orig_pierce_armor;                 // 0x160

    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[1]+0x4=0x50EE00
    virtual void modify(float param_1, uchar param_2);      // vt0[2]+0x8=0x50EE80
    virtual void modify_delta(float param_1, uchar param_2); // vt0[3]+0xC=0x50EF70
    virtual void modify_percent(float param_1, uchar param_2); // vt0[4]+0x10=0x50EFC0
    virtual void save(int param_1);                         // vt0[5]+0x14=0x50F010
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // vt0[6]+0x18=0x50F090
    virtual RGE_Master_Static_Object* make_new_master();    // vt0[7]+0x1C=0x50F110
    virtual RGE_Task_List* create_task_list();              // vt0[14]+0x38=0x50EDB0
    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* param_1, int param_2);
    TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    TRIBE_Master_Combat_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    int setup(TRIBE_Master_Combat_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    ~TRIBE_Master_Combat_Object();
};

static_assert(sizeof(TRIBE_Master_Combat_Object) == 0x164, "TRIBE_Master_Combat_Object Size Mismatch");

