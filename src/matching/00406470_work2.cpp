// VA: 00406470 RGE_Action_Object::work2
// PDB source: act_obj.cpp lines 266-462
// Attempt log:
// - Reconstructed the task lookup, action-list checks, fallback move, and UnitAI
//   dispatch from the original call/slot map. The parameter byte is not consumed
//   by the observed body; the final UnitAI target call uses the three float
//   coordinates, matching the neighboring move_to surface.
// - Natural for-loop fallback scan reproduced the oracle's jl backedge and
//   exhaustion jump where do/while/explicit continue emitted the opposite tail.
// - Per-case action assignment before order assignment reproduced the switch
//   handler store order; current exact result is 789 bytes / 24 calls.

#define VPAD1(n) virtual void vf##n(void);
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)
#define VPAD15(n) VPAD8(n) VPAD4(n##_8) VPAD2(n##_12) VPAD1(n##_14)

#ifndef ACT_OBJ_CONTEXT_H
class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Player;
class RGE_Task;
class RGE_Action;
class RGE_Action_List;
class RGE_Task_List;
class UnitAIModule;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;                                      // +0x04
    RGE_Master_Static_Object* master_obj;       // +0x08
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    unsigned char master_type;                   // +0x04
    char gap_05[0x0F];
    short object_group;                          // +0x14
    char gap_16[0xA2];
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, short id);
    virtual RGE_Task* get_target_task(RGE_Action_Object* action,
                                      RGE_Static_Object* target,
                                      float x, float y, float z);
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x20];                           // +0xB8..+0xD7
    RGE_Task_List* tasks;                        // +0xD8
    char gap_DC[0x10];
    unsigned char task_by_group;                 // +0xEC
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1E];
    short master_object_num;                     // +0x22
    RGE_Master_Static_Object** master_objects;   // +0x24
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int type, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int file);
    virtual short action_id(void);               // +0x18
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* target, float x, float y, float z);
    virtual int can_work(RGE_Static_Object* target,
                         float x, float y, float z); // +0x34
    virtual unsigned char attack_response(RGE_Static_Object* target);
    virtual unsigned char relation_response(long player, unsigned char relation);
    virtual void copy_obj(RGE_Master_Action_Object* master);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* master,
                                  RGE_Task* first, RGE_Task* second);
    virtual void get_state_name(char* name);
    virtual RGE_Static_Object* get_target_obj(void); // +0x4C
};

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    virtual RGE_Action* create_task_action(RGE_Task* task,
                                           RGE_Static_Object* target,
                                           float x, float y, float z);

    int action_work(RGE_Static_Object* target, float x, float y, float z);
    RGE_Action* get_action(void);
    RGE_Task* get_task(void);
    unsigned char have_action(void);
};

class UnitAIModule {
public:
    void setCurrentOrder(int order);
    void setCurrentAction(int action);
    void setCurrentTarget(int id, int group, float x, float y, float z);
    void setTaskedByPlayer(void);
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    VPAD15(1)
    VPAD4(16)
    VPAD1(20)
    virtual void transform(RGE_Master_Static_Object* master); // +0x54
    VPAD16(22)
    VPAD1(38)
    virtual void move_to(RGE_Static_Object* target, float x, float y, float z); // +0x9C
    VPAD64(40)
    VPAD16(104)
    VPAD8(120)
    VPAD2(128)
    virtual void set_action(RGE_Action* action); // +0x208

    char gap_04[4];                              // +0x04..+0x07
    RGE_Master_Action_Object* master_obj;        // +0x08
    RGE_Player* owner;                           // +0x0C
    char gap_10[0x64];                           // +0x10..+0x73
    UnitAIModule* unit_ai;                       // +0x74
    char gap_78[0x10C];                          // +0x78..+0x183
    RGE_Action_List* actions;                    // +0x184

    void work2(RGE_Static_Object* target, float x, float y, float z,
               unsigned char flag);
};
#endif

void RGE_Action_Object::work2(RGE_Static_Object* target,
                              float x, float y, float z,
                              unsigned char flag)
{
    int skip;
    RGE_Task* task;
    RGE_Action* action;
    RGE_Task* current_task;
    short action_id;
    RGE_Master_Static_Object* other;
    int i;
    int order;
    int current_action;

    if ((RGE_Action_Object*)target != this) {
        task = ((RGE_Master_Action_Object*)this->master_obj)->tasks->get_target_task(
            this, target, x, y, z);
        if (task == 0 && ((RGE_Master_Action_Object*)this->master_obj)->task_by_group != 0) {
            i = 0;
            for (; i < this->owner->master_object_num; i++) {
                other = this->owner->master_objects[i];
                if (other != 0 &&
                    other->object_group == this->master_obj->object_group &&
                    other->master_type == this->master_obj->master_type &&
                    ((RGE_Master_Action_Object*)other)->task_by_group ==
                        ((RGE_Master_Action_Object*)this->master_obj)->task_by_group) {
                    task = ((RGE_Master_Action_Object*)other)->tasks->get_target_task(
                        this, target, x, y, z);
                    if (task != 0) {
                        this->transform(other);
                        break;
                    }
                }
            }
        }

        current_task = this->actions->get_task();
        skip = 0;
        action_id = -1;
        if (current_task != 0 && task == current_task &&
            this->actions->action_work(target, x, y, z) != 0) {
            action_id = this->actions->get_action()->type();
            skip = 1;
        }

        if (this->actions->have_action() == 1) {
            if (this->actions->get_action()->get_target_obj() == target &&
                this->actions->get_action()->type() == 9) {
                if (this->actions->get_action()->work(target, x, y, z) != 0) {
                    action_id = this->actions->get_action()->type();
                    skip = 1;
                }
            }
        }

        if (skip == 0) {
            if (task != 0) {
                action = this->actions->create_task_action(task, target, x, y, z);
            } else {
                action = 0;
            }
            if (action != 0) {
                action_id = action->action_id();
                this->set_action(action);
            } else {
                action_id = 1;
                this->move_to(target, x, y, z);
            }
        }

        if (this->unitAIValue != 0) {
            order = -1;
            current_action = -1;
            switch (action_id) {
            case 9:
                current_action = 0x258;
                order = 0x2BC;
                break;
            case 0x65:
                current_action = 0x25A;
                order = 0x2BE;
                break;
            case 3:
                current_action = 0x269;
                order = 0x2CD;
                break;
            case 4:
                current_action = 0x25D;
                order = 0x2C1;
                break;
            case 5:
                current_action = 0x261;
                order = 0x2C5;
                break;
            case 1:
                current_action = 0x262;
                order = 0x2C6;
                break;
            case 0x6E:
                current_action = 0x265;
                order = 0x2C9;
                break;
            case 0x0C:
                current_action = 0x266;
                order = 0x2CA;
                break;
            case 0x6F:
                current_action = 0x267;
                order = 0x2CB;
                break;
            case 0x68:
                current_action = 0x25C;
                order = 0x2C0;
                break;
            case 0x69:
                current_action = 0x25B;
                order = 0x2BF;
                break;
            case 0x6A:
                current_action = 0x26A;
                order = 0x2CE;
                break;
            }

            this->unitAIValue->setCurrentOrder(order);
            this->unitAIValue->setCurrentAction(current_action);
            if (target != 0) {
                this->unitAIValue->setCurrentTarget(
                    target->id,
                    target->master_obj->object_group,
                    x, y, z);
            } else {
                this->unitAIValue->setCurrentTarget(-1, -1, x, y, z);
            }
            this->unitAIValue->setTaskedByPlayer();
        }
    }
}

#undef VPAD64
#undef VPAD15
#undef VPAD32
#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1
