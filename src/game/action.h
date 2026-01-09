#pragma once
#include "common.h"

// ----------------------------------------------------------------
// RGE_Action_Node
// Size: 0x8
struct RGE_Action_Node {
    RGE_Action * action; // 0x0
    RGE_Action_Node * next; // 0x4
};

class RGE_Action {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    short action_type;                       // 0x4
    RGE_Action_Object* obj;                  // 0x8
    uchar state;                             // 0xC
    RGE_Static_Object* target_obj;           // 0x10
    RGE_Static_Object* target_obj2;          // 0x14
    int targetID;                            // 0x18
    int target2ID;                           // 0x1C
    float target_x;                          // 0x20
    float target_y;                          // 0x24
    float target_z;                          // 0x28
    float timer;                             // 0x2C
    RGE_Task* task;                          // 0x30
    RGE_Action_List* sub_actions;            // 0x34
    RGE_Sprite* sprite;                      // 0x38
    uchar subActionValue;                    // 0x3C

    virtual int setup(RGE_Action_Object* param_1);          // vt0[1]+0x4=0x407680
    virtual int setup(int param_1, RGE_Action_Object* param_2); // vt0[2]+0x8=0x407530
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1); // vt0[3]+0xC=0x4076D0
    virtual void rehook();                                  // vt0[4]+0x10=0x407740
    virtual void save(int param_1);                         // vt0[5]+0x14=0x407790
    virtual short type();                                   // vt0[6]+0x18=0x4078D0
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4078E0
    virtual uchar inside_obj_update();                      // vt0[8]+0x20=0x407950
    virtual uchar idle_update();                            // vt0[9]+0x24=0x407990
    virtual uchar update();                                 // vt0[10]+0x28=0x4079D0
    virtual int stop();                                     // vt0[11]+0x2C=0x4078F0
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[12]+0x30=0x407900
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x407910
    virtual uchar attack_response(RGE_Static_Object* param_1); // vt0[14]+0x38=0x407920
    virtual uchar relation_response(long param_1, uchar param_2); // vt0[15]+0x3C=0x407930
    virtual void copy_obj(RGE_Master_Action_Object* param_1); // vt0[16]+0x40=0x407B00
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3); // vt0[17]+0x44=0x407C00
    virtual void get_state_name(char* param_1);             // vt0[18]+0x48=0x407C10
    virtual RGE_Static_Object* get_target_obj();            // vt0[19]+0x4C=0x401130
    virtual RGE_Static_Object* get_target_obj2();           // vt0[20]+0x50=0x401140
    virtual void set_target_obj(RGE_Static_Object* param_1); // vt0[21]+0x54=0x407A20
    virtual void set_target_obj2(RGE_Static_Object* param_1); // vt0[22]+0x58=0x407A90
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x407940
    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
    RGE_Action(RGE_Action_Object* param_1, int param_2);
    ~RGE_Action();
    float targetX();
    float targetY();
    float targetZ();
    uchar subAction();
    void setSubAction(uchar param_1);
};

static_assert(sizeof(RGE_Action) == 0x40, "RGE_Action Size Mismatch");

