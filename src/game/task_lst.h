#pragma once
#include "../common.h"

class RGE_Task_List {
public:
    RGE_Task** list;                         // 0x4
    short list_num;                          // 0x8

    RGE_Task_List();
    virtual ~RGE_Task_List();
    virtual void copy(RGE_Task_List* param_1);
    virtual void load(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    virtual void load(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    virtual void save(int param_1);
    virtual void delete_list();
    virtual RGE_Task* create_task(short param_1, short param_2);
    virtual RGE_Task* get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5);
    virtual int is_attack_task(RGE_Task* param_1);
    virtual int check_task(RGE_Task* param_1, RGE_Action_Object* param_2, RGE_Static_Object* param_3);
};

static_assert(sizeof(RGE_Task_List) == 0xC, "RGE_Task_List Size Mismatch");
static_assert(offsetof(RGE_Task_List, list_num) == 0x8, "RGE_Task_List Offset Mismatch");

