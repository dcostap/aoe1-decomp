// RGE_Action::setup
// VA: 00407530
// PDB: action.cpp:73-121
// No EH framing

#include "../../include/game_globals.h"

class RGE_Action_List;
class RGE_Static_Object;

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
    void* obj;                     // +0x08
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
    void* task;                    // +0x30
    RGE_Action_List* sub_actions;  // +0x34
    void* sprite;                  // +0x38
    unsigned char subActionValue;  // +0x3C
    char gap_3D[3];

    int setup(int param_1, void* param_2);
};

class RGE_Action_List {
public:
    void load(int handle);
};

class RGE_Action_Object {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void* get_sprite_pointer(short id);  // slot 0xDC/4 = 55

    char gap_04[4];
    void* field_08;  // +0x08
};

void rge_read(int handle, void* buf, int size);

int RGE_Action::setup(int param_1, void* param_2)
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
        // Get task from: this->obj->field_08->field_0D8->task_list[short_val]
        void* field_08 = *(void**)((char*)this->obj + 8);
        void* tasks = *(void**)((char*)field_08 + 0xD8);
        this->task = *(void**)((char*)tasks + 4 + short_val * 4);
    }

    rge_read(param_1, &this->subActionValue, 1);

    this->sub_actions->load(param_1);

    rge_read(param_1, &short_val, 2);
    // call obj->get_sprite_pointer(short_val) — virtual at slot 55 (0xDC/4)
    this->sprite = ((RGE_Action_Object*)this->obj)->get_sprite_pointer(short_val);

    return 1;
}
