#pragma once
#include "common.h"

class RGE_Action_List {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    RGE_Action_Object* obj;                  // 0x4
    RGE_Action_Node* list;                   // 0x8

    virtual RGE_Action* create_action(int param_1, short param_2); // vt0[0]+0x0=0x403FC0
    virtual RGE_Action* create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5); // vt0[1]+0x4=0x404200
    virtual uchar inside_obj_update();                      // vt0[2]+0x8=0x4044A0
    virtual uchar update();                                 // vt0[3]+0xC=0x4044F0
    virtual void get_action_name(char* param_1);            // vt0[4]+0x10=0x4048C0
    virtual void copy_obj(RGE_Master_Action_Object* param_1); // vt0[5]+0x14=0x404860
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3); // vt0[6]+0x18=0x404890
    RGE_Action_List(RGE_Action_Object* param_1);
    ~RGE_Action_List();
    void load(int param_1);
    void rehook();
    void save(int param_1);
    void delete_list();
    void add_action(RGE_Action* param_1);
    void add_action_at_end(RGE_Action* param_1);
    void add_action_at_end_of_action_queue(RGE_Action* param_1);
    void remove_action();
    uchar have_action();
    int action_stop();
    int action_move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    int action_work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    int attack_response(RGE_Static_Object* param_1);
    int relation_response(long param_1, uchar param_2);
    RGE_Action* get_action();
    RGE_Task* get_task();
};

static_assert(sizeof(RGE_Action_List) == 0xC, "RGE_Action_List Size Mismatch");

