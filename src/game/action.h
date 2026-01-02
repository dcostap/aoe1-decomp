#pragma once
#include "../common.h"

class RGE_Action {
public:
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

    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
    RGE_Action(RGE_Action_Object* param_1, int param_2);
    virtual ~RGE_Action();
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual int setup(RGE_Action_Object* param_1);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(uchar param_1);
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual uchar attack_response(RGE_Static_Object* param_1);
    virtual uchar relation_response(long param_1, uchar param_2);
    virtual void set_state(uchar param_1);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void copy_obj(RGE_Master_Action_Object* param_1);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void get_state_name(char* param_1);
    virtual float targetX();
    virtual float targetY();
    virtual float targetZ();
    virtual uchar subAction();
    virtual void setSubAction(uchar param_1);
};

static_assert(sizeof(RGE_Action) == 0x40, "RGE_Action Size Mismatch");
static_assert(offsetof(RGE_Action, subActionValue) == 0x3C, "RGE_Action Offset Mismatch");

RGE_Static_Object* RGE_Action::get_target_obj() {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall get_target_obj(RGE_Action * this)
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?get_target_obj@RGE_Action@@UAEPAVRGE_Static_Object@@XZ      XREF[22]:    0056e0a4(*), 0056e124(*),
//                               RGE_Action::get_target_obj                                                0056e18c(*), 0056e1fc(*),
//                                                                                                         0056e264(*), 0056e304(*),
//                                                                                                         0056e36c(*), 0056e3ec(*),
//                                                                                                         0056e69c(*), 0056e71c(*),
//                                                                                                         00574ef4(*), 00574f64(*),
//                                                                                                         00574fdc(*), 0057505c(*),
//                                                                                                         005750cc(*), 0057513c(*),
//                                                                                                         005751f4(*), 00575254(*),
//                                                                                                         005752cc(*), 00575334(*), [more]
//                              action.h:85 (4)
//         00401130     MOV        EAX,dword ptr [ECX + this->target_obj]
//         00401133     RET
//         00401134     ??         90h
//         00401135     NOP
//         00401136     NOP
//         00401137     NOP
//         00401138     NOP
//         00401139     NOP
//         0040113a     NOP
//         0040113b     NOP
//         0040113c     NOP
//         0040113d     NOP
//         0040113e     NOP
//         0040113f     NOP
    return 0;
}

RGE_Static_Object* RGE_Action::get_target_obj2() {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall get_target_obj2(RGE_Action * this)
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Action *      ECX:4 (auto)   this
//                               ?get_target_obj2@RGE_Action@@UAEPAVRGE_Static_Object@@XZ     XREF[22]:    0056e0a8(*), 0056e128(*),
//                               RGE_Action::get_target_obj2                                               0056e190(*), 0056e200(*),
//                                                                                                         0056e268(*), 0056e308(*),
//                                                                                                         0056e370(*), 0056e3f0(*),
//                                                                                                         0056e6a0(*), 0056e720(*),
//                                                                                                         00574ef8(*), 00574f68(*),
//                                                                                                         00574fe0(*), 00575060(*),
//                                                                                                         005750d0(*), 00575140(*),
//                                                                                                         005751f8(*), 00575258(*),
//                                                                                                         005752d0(*), 00575338(*), [more]
//                              action.h:86 (4)
//         00401140     MOV        EAX,dword ptr [ECX + this->target_obj2]
//         00401143     RET
//         00401144     ??         90h
//         00401145     NOP
//         00401146     NOP
//         00401147     NOP
//         00401148     NOP
//         00401149     NOP
//         0040114a     NOP
//         0040114b     NOP
//         0040114c     NOP
//         0040114d     NOP
//         0040114e     NOP
//         0040114f     NOP
    return 0;
}

