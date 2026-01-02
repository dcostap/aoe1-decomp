#pragma once
#include "../common.h"

class RGE_Action_Object : public RGE_Moving_Object {
public:
    uchar waiting;                           // 0x180
    RGE_Action_List* actions;                // 0x184
    uchar command_flag;                      // 0x188
    int lastActionValue;                     // 0x18C
    int lastActionStateValue;                // 0x190

    RGE_Action_Object(RGE_Master_Action_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Action_Object(int param_1, RGE_Game_World* param_2, int param_3);
    virtual ~RGE_Action_Object();
    virtual void recycle_out_of_game();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(RGE_Master_Action_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual RGE_Action_List* create_action_list();
    virtual void rehook();
    virtual void save(int param_1);
    virtual void transform(RGE_Master_Static_Object* param_1);
    virtual void destroy_obj();
    virtual void notify_of_relation(long param_1, uchar param_2);
    virtual void do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void work2(RGE_Static_Object* param_1, float param_2, float param_3, float param_4, uchar param_5);
    virtual void set_attack(RGE_Static_Object* param_1);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void set_task(short param_1);
    virtual void setTaskByTaskID(int param_1);
    virtual void set_action(RGE_Action* param_1);
    virtual void set_only_action(RGE_Action* param_1);
    virtual void set_end_action(RGE_Action* param_1);
    virtual void stop();
    virtual uchar update();
    virtual void change_ownership(RGE_Player* param_1);
    virtual void copy_obj(RGE_Master_Static_Object* param_1);
    virtual uchar have_action();
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Task* getTask(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual uchar actionState();
    virtual long get_action_checksum();
};

static_assert(sizeof(RGE_Action_Object) == 0x194, "RGE_Action_Object Size Mismatch");
static_assert(offsetof(RGE_Action_Object, lastActionStateValue) == 0x190, "RGE_Action_Object Offset Mismatch");

