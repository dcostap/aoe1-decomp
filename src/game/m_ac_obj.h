#pragma once
#include "common.h"

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Task_List* tasks;                    // 0xD8
    short default_task;                      // 0xDC
    float search_radius;                     // 0xE0
    float work_rate;                         // 0xE4
    short drop_site;                         // 0xE8
    short backup_drop_site;                  // 0xEA
    uchar task_by_group;                     // 0xEC
    RGE_Sound* command_sound;                // 0xF0
    RGE_Sound* move_sound;                   // 0xF4
    uchar run_pattern;                       // 0xF8

    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[1]+0x4=0x44F760
    virtual void modify(float param_1, uchar param_2);      // vt0[2]+0x8=0x44F7F0
    virtual void modify_delta(float param_1, uchar param_2); // vt0[3]+0xC=0x44F820
    virtual void modify_percent(float param_1, uchar param_2); // vt0[4]+0x10=0x44F850
    virtual void save(int param_1);                         // vt0[5]+0x14=0x44F880
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // vt0[6]+0x18=0x44F5A0
    virtual RGE_Master_Static_Object* make_new_master();    // vt0[7]+0x1C=0x44F670
    virtual void play_command_sound();                      // vt0[11]+0x2C=0x44F980 | vt0[40]+0xA0=0x44F980
    virtual void play_move_sound();                         // vt0[12]+0x30=0x44F9A0 | vt0[41]+0xA4=0x44F9A0
    virtual RGE_Task_List* create_task_list();              // vt0[14]+0x38=0x44F540 | vt0[43]+0xAC=0x44F540
    RGE_Master_Action_Object(RGE_Master_Action_Object* param_1, int param_2);
    RGE_Master_Action_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Action_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    int setup(RGE_Master_Action_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    ~RGE_Master_Action_Object();
    RGE_Task* get_task(short param_1);
    RGE_Task* getTaskByTaskID(int param_1);
};

static_assert(sizeof(RGE_Master_Action_Object) == 0xFC, "RGE_Master_Action_Object Size Mismatch");

