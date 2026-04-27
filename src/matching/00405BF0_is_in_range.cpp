// attempt 1: natural range check with direct object/position distance calls and the 0.25 fallback inRange path
// attempt 2: remove the local target temp; VC5 is loading the member into the wrong register before the FPU branch
#include "..\..\include\game_types.h"

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Master_Action_Object;
class RGE_Task;

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    unsigned char _pad_0[2];
    RGE_Action_Object* obj;
    unsigned char state;
    unsigned char _pad_1[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    unsigned char _pad_end[3];
};

class RGE_Action_Object {
public:
    float distance_to_object(RGE_Static_Object* param_1);
    float distance_to_position(float param_1, float param_2, float param_3);
    int inRange(RGE_Static_Object* param_1, float param_2);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;

    unsigned char is_in_range();
};

unsigned char RGE_Action_Move_To::is_in_range() {
    float distance;

    if (this->range > 0.0f) {
        if (this->target_obj != 0) {
            distance = this->obj->distance_to_object(this->target_obj);
        } else {
            distance = this->obj->distance_to_position(this->target_x, this->target_y, this->target_z);
        }
        if (distance <= this->range) {
            return 1;
        }
    } else {
        if (this->target_obj != 0 && this->obj->inRange(this->target_obj, 0.25f) != 0) {
            return 1;
        }
    }
    return 0;
}
