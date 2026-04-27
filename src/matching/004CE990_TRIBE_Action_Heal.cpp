// 004CE990 TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)
// Source: tact_hea.cpp lines 51-59
// Size: 120 bytes, EH-framed (FS:[0] registration)
//
// Attempt log:
// Probe 1: base ctor + member inits + vtable + set_target_obj + world coords, /GX flag

#include "..\..\include\game_globals.h"

class RGE_Action_Object;
class RGE_Task;
class RGE_Action_List;

class RGE_Static_Object {
public:
    char _gap_00[0x38];
    float world_x;        // +0x38
    float world_y;        // +0x3C
    float world_z;        // +0x40
};

class RGE_Action {
public:
    short field_04;                         // +0x04
    char _gap_06[0x02];                     // +0x06
    RGE_Action_Object* action_object;        // +0x08
    unsigned char state;                     // +0x0C
    char _gap_0D[0x03];                     // +0x0D
    RGE_Static_Object* target;               // +0x10
    char _gap_14[0x04];                     // +0x14
    int target_obj_id;                       // +0x18
    int completion_target_id;                // +0x1C
    float world_x;                           // +0x20
    float world_y;                           // +0x24
    float world_z;                           // +0x28
    char _gap_2C[0x04];                     // +0x2C
    RGE_Task* task;                          // +0x30
    RGE_Action_List* action_list;            // +0x34
    char _gap_38[0x08];                     // +0x38 to +0x3F (total = 0x40)

    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(class RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(class RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    RGE_Action(RGE_Action_Object* obj, int param2);
};

class TRIBE_Action_Heal : public RGE_Action {
public:
    virtual void set_state(unsigned char);
    virtual unsigned char update();

    TRIBE_Action_Heal(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
};

TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(obj, 1)
{
    this->task = task;
    field_04 = 0x69;
    set_target_obj(target);
    world_x = target->world_x;
    world_y = target->world_y;
    world_z = target->world_z;
}
