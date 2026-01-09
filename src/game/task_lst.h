#pragma once
#include "common.h"

class RGE_Task_List {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    RGE_Task** list;                         // 0x4
    short list_num;                          // 0x8

    virtual RGE_Task* create_task(short param_1, short param_2); // vt0[0]+0x0=0x5090B0
    virtual RGE_Task* get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5); // vt0[1]+0x4=0x509120
    virtual int is_attack_task(RGE_Task* param_1);          // vt0[2]+0x8=0x5092D0
    virtual int check_task(RGE_Task* param_1, RGE_Action_Object* param_2, RGE_Static_Object* param_3); // vt0[3]+0xC=0x5092F0
    RGE_Task_List();
    ~RGE_Task_List();
    void copy(RGE_Task_List* param_1);
    void load(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    void load(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    void save(int param_1);
    void delete_list();
};

static_assert(sizeof(RGE_Task_List) == 0xC, "RGE_Task_List Size Mismatch");

