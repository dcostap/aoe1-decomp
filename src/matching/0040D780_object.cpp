// VA: 0040D780 MainDecisionAIModule::object
// Source: aimdmod.cpp lines 194-213
// Attempt log:
// 1-10: earlier decompiler-shaped reconstruction reached the target size but
// used the wrong filter mapping and did not match the register/branch basin.
// 11: fresh typed ownership pass: the unused eighth parameter is real, the
// ninth filter is object state, and the tenth is attribute_amount_held.
// 12: typed RGE_Player::world at +3C replaced pointer arithmetic and improved
// the world call to the canonical field load.
// 13: modeled objects as ManagedArray<int>; operator[] naturally emits both
// observed capacity-growth blocks.
// 14: an ordinary for loop, rather than do/while, reproduces the original
// preheader, stack-backed index reload, backedge, and complete 578-byte body.
// 15: exact match; source remains in scratch because this worker does not
// promote targets.

#include <stddef.h>

extern void* __cdecl operator new(unsigned int size);
extern void __cdecl operator delete(void* p);

class UnitAIModule;

class UnitAIModule {
public:
    int currentAction();
    int currentTarget();
    int currentTargetType();
};

class RGE_Master_Object {
public:
    char gap_00[0x10];
    short id;                // +10
    short copy_id;           // +12
    short object_group;      // +14
};

class RGE_Static_Object {
public:
    void* vfptr;
    int id;                       // +04
    RGE_Master_Object* master;    // +08
    char gap_0C[0x38];
    float attribute_amount_held;  // +44
    unsigned char object_state;   // +48
    char gap_49[3];
    UnitAIModule* unitAI();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class AIModule {
public:
    virtual void v00();
    virtual int vf04();
    virtual int vf08();
    virtual int vf0C();
    virtual int vf10();
    virtual int vf14();
    virtual int vf18();
    virtual int vf1C();
    virtual int vf20();
    virtual int vf24();
    virtual int vf28();
    virtual int vf2C();
    virtual int vf30();
    virtual int vf34();
    virtual int vf38();
    virtual int vf3C();
    virtual int vf40();
    virtual int vf44();
    virtual int vf48();
    virtual int canPerformAction(int obj_id, int filter);
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_data = (T*)operator new(new_size * 4);
            if (new_data != 0) {
                for (int j = 0;
                     j < this->maximumSizeValue && j < new_size;
                     ++j) {
                    new_data[j] = this->value[j];
                }
                operator delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class MainDecisionAIModule : public AIModule {
public:
    char gap_04[0xF0 - 0x04];
    RGE_Player* player;       // +F0
    ManagedArray<int> objects; // +F4

    RGE_Static_Object* object(int object_id, int type, int class_id, int action,
                              int can_perform_action, int current_target,
                              int current_target_type, int unused, int state,
                              int attribute_amount);
};

RGE_Static_Object* MainDecisionAIModule::object(int object_id, int type, int class_id, int action,
                                                int can_perform_action, int current_target,
                                                int current_target_type, int unused, int state,
                                                int attribute_amount)
{
    int i = 0;
    for (; i < this->objects.numberValue; ++i) {
        RGE_Static_Object* obj = this->player->world->object(this->objects[i]);
        if (obj != 0 && obj->unitAI() != 0) {
            if (object_id != -1 && obj->id != object_id) {
                goto next_object;
            }
            if (type != -1 && obj->master->id != type) {
                goto next_object;
            }
            if (class_id != -1 && obj->master->object_group != class_id) {
                goto next_object;
            }
            if (action != -1 && obj->unitAI()->currentAction() != action) {
                goto next_object;
            }
            if (can_perform_action != -1) {
                if (!this->canPerformAction(this->objects[i], can_perform_action)) {
                    goto next_object;
                }
            }
            if (current_target != -1 && obj->unitAI()->currentTarget() != current_target) {
                goto next_object;
            }
            if (current_target_type != -1 &&
                obj->unitAI()->currentTargetType() != current_target_type) {
                goto next_object;
            }
            if ((state == -1 || (int)obj->object_state == state) &&
                (attribute_amount == -1 ||
                 obj->attribute_amount_held <= (float)attribute_amount)) {
                return obj;
            }
        }

    next_object:
        ;
    }

    return 0;
}
