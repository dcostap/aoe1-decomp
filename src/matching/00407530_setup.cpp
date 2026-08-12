// RGE_Action::setup
// VA: 00407530
// PDB: action.cpp:73-121
// No EH framing
// Attempt log:
// - Baseline rebuilt the serialized setup flow but used raw task lookup and a
//   virtual sprite lookup, leaving a 74-byte mismatch.
// - Modeled obj->master_obj (+0x08), master_obj->tasks (+0xD8), and the task
//   list field (+0x04) from the exact copy_obj donor.
// - Replaced the wrong virtual sprite call with the direct
//   RGE_Static_Object::get_sprite_pointer(short) donor surface; exact match.

#include "../../include/game_globals.h"

class RGE_Action_List;
class RGE_Action_Object;
class RGE_Master_Action_Object;
class RGE_Task_List;
class RGE_Task;
class RGE_Static_Object;
class RGE_Sprite;

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, short object_id);
    virtual RGE_Task* get_target_task(RGE_Action_Object* action_object,
                                      RGE_Static_Object* object,
                                      float x, float y, float z);
    virtual int is_attack_task(RGE_Task* task);
    virtual int check_task(RGE_Task* task, RGE_Action_Object* action_object,
                           RGE_Static_Object* object);
    virtual ~RGE_Task_List();

    RGE_Task** list;                // +0x04
    short list_num;
    char gap_0A[2];
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xD8];
    RGE_Task_List* tasks;          // +0xD8
};

class RGE_Action {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void* d3(void*);       // slot 3: create sub_actions list
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();

    short action_type;             // +0x04
    char gap_06[2];
    RGE_Action_Object* obj;         // +0x08
    unsigned char state;           // +0x0C
    char gap_0D[3];
    RGE_Static_Object* target_obj;    // +0x10
    RGE_Static_Object* target_obj2;   // +0x14
    int targetID;                  // +0x18
    int target2ID;                 // +0x1C
    float target_x;                // +0x20
    float target_y;                // +0x24
    float target_z;                // +0x28
    float timer;                   // +0x2C
    RGE_Task* task;                 // +0x30
    RGE_Action_List* sub_actions;  // +0x34
    void* sprite;                  // +0x38
    unsigned char subActionValue;  // +0x3C
    char gap_3D[3];

    int setup(int param_1, RGE_Action_Object* param_2);
};

class RGE_Action_List {
public:
    void load(int handle);
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();

    char gap_04[4];
    RGE_Master_Action_Object* master_obj; // +0x08
};

class RGE_Static_Object {
public:
    RGE_Sprite* get_sprite_pointer(short index);
};

void rge_read(int handle, void* buf, int size);

int RGE_Action::setup(int param_1, RGE_Action_Object* param_2)
{
    short short_val;
    int int_val;

    this->action_type = 0;
    this->obj = param_2;
    this->sub_actions = (RGE_Action_List*)this->d3(param_2);

    rge_read(param_1, &this->state, 1);

    rge_read(param_1, &int_val, 4);
    if (int_val == -1) {
        this->target_obj = 0;
    } else {
        this->target_obj = (RGE_Static_Object*)int_val;
    }

    rge_read(param_1, &int_val, 4);
    if (int_val == -1) {
        this->target_obj2 = 0;
    } else {
        this->target_obj2 = (RGE_Static_Object*)int_val;
    }

    rge_read(param_1, &this->targetID, 4);
    rge_read(param_1, &this->target2ID, 4);
    rge_read(param_1, &this->target_x, 4);
    rge_read(param_1, &this->target_y, 4);
    rge_read(param_1, &this->target_z, 4);
    rge_read(param_1, &this->timer, 4);

    rge_read(param_1, &short_val, 2);
    if (short_val == -1) {
        this->task = 0;
    } else {
        RGE_Task_List* task_list = this->obj->master_obj->tasks;
        this->task = task_list->list[short_val];
    }

    rge_read(param_1, &this->subActionValue, 1);

    this->sub_actions->load(param_1);

    rge_read(param_1, &short_val, 2);
    this->sprite = ((RGE_Static_Object*)this->obj)->get_sprite_pointer(short_val);

    return 1;
}
