#pragma once
#include "common.h"

class RGE_Action_Object : public RGE_Moving_Object {
public:
    uchar waiting;                           // 0x180
    RGE_Action_List* actions;                // 0x184
    uchar command_flag;                      // 0x188
    int lastActionValue;                     // 0x18C
    int lastActionStateValue;                // 0x190

    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[1]+0x4=0x4060A0
    virtual void recycle_out_of_game();                     // vt0[2]+0x8=0x406080
    virtual uchar update();                                 // vt0[9]+0x24=0x406A70
    virtual void rehook();                                  // vt0[11]+0x2C=0x406200
    virtual void save(int param_1);                         // vt0[12]+0x30=0x406220
    virtual void change_ownership(RGE_Player* param_1);     // vt0[17]+0x44=0x406B90
    virtual void transform(RGE_Master_Static_Object* param_1); // vt0[21]+0x54=0x406270
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[22]+0x58=0x406BC0
    virtual void destroy_obj();                             // vt0[26]+0x68=0x406290
    virtual void notify_of_relation(long param_1, uchar param_2); // vt0[37]+0x94=0x4062B0
    virtual void do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[38]+0x98=0x4062C0
    virtual void move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[39]+0x9C=0x406300
    virtual void work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[40]+0xA0=0x406430
    virtual void stop();                                    // vt0[41]+0xA4=0x406A50
    virtual void set_attack(RGE_Static_Object* param_1);    // vt0[42]+0xA8=0x406830
    virtual void play_command_sound();                      // vt0[43]+0xAC=0x406840
    virtual void play_move_sound();                         // vt0[44]+0xB0=0x406850
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[47]+0xBC=0x406860
    virtual RGE_Static_Object* get_target_obj();            // vt0[51]+0xCC=0x406C10
    virtual uchar actionState();                            // vt0[77]+0x134=0x406D00
    virtual long get_action_checksum();                     // vt0[116]+0x1D0=0x406D30
    virtual int setup(int param_1, RGE_Game_World* param_2); // vt0[118]+0x1D8=0x406120
    virtual void work2(RGE_Static_Object* param_1, float param_2, float param_3, float param_4, uchar param_5); // vt0[126]+0x1F8=0x406470
    virtual void set_task(short param_1);                   // vt0[127]+0x1FC=0x406940
    virtual void setTaskByTaskID(int param_1);              // vt0[128]+0x200=0x406990
    virtual void set_action(RGE_Action* param_1);           // vt0[129]+0x204=0x4069E0
    virtual void set_only_action(RGE_Action* param_1);      // vt0[130]+0x208=0x406A00
    virtual void set_end_action(RGE_Action* param_1);       // vt0[131]+0x20C=0x406A30
    virtual RGE_Task* getTask(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[132]+0x210=0x406C30
    virtual int setup(RGE_Master_Action_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[133]+0x214=0x4060D0
    virtual RGE_Action_List* create_action_list();          // vt0[134]+0x218=0x4061A0
    RGE_Action_Object(RGE_Master_Action_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Action_Object(int param_1, RGE_Game_World* param_2, int param_3);
    ~RGE_Action_Object();
    uchar have_action();
    void rehook();
};

static_assert(sizeof(RGE_Action_Object) == 0x194, "RGE_Action_Object Size Mismatch");

