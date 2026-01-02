#pragma once
#include "../common.h"

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    Attribute_Cost build_inventory[3];       // 0x148
    short build_pts_required;                // 0x15A
    short id_of_building_obj;                // 0x15C
    uchar button_location;                   // 0x15E
    short orig_pierce_armor;                 // 0x160

    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* param_1, int param_2);
    TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    TRIBE_Master_Combat_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    virtual int setup(TRIBE_Master_Combat_Object* param_1);
    virtual int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    virtual int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    virtual ~TRIBE_Master_Combat_Object();
    virtual RGE_Task_List* create_task_list();
    virtual void copy_obj(RGE_Master_Static_Object* param_1);
    virtual void modify(float param_1, uchar param_2);
    virtual void modify_delta(float param_1, uchar param_2);
    virtual void modify_percent(float param_1, uchar param_2);
    virtual void save(int param_1);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4);
    virtual RGE_Master_Static_Object* make_new_master();
};

static_assert(sizeof(TRIBE_Master_Combat_Object) == 0x164, "TRIBE_Master_Combat_Object Size Mismatch");
static_assert(offsetof(TRIBE_Master_Combat_Object, orig_pierce_armor) == 0x160, "TRIBE_Master_Combat_Object Offset Mismatch");

