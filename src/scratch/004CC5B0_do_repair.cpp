// VA: 004CC5B0 TRIBE_Combat_Object::do_repair
// PDB: t_c_obj.cpp:1678-1777
// Attempt log:
// baseline: replace the prior raw-vtable/inline-asm scaffold with the natural
// typed action-list/task lookup and UnitAI dispatch supported by the same-TU
// RGE_Action_Object::work2 donor.
// probe: an explicit for-loop and a separate task local worsened the prologue;
// the donor-shaped guarded do/while with the selected task loaded directly
// recovered exact size/CFG and left only the no-task-list candidate reload.
// Promotion audit rejected the prior exact diagnostic: it used a volatile,
// type-punning reload of the target parameter as an RGE_Task*.  The oracle
// instead supports a typed target-as-task fallback when the list is empty.
// Same-TU action declarations now retain the proven object and task offsets.
// probe: direct typed target fallback improved the mismatch from 249 to 248
// bytes; non-volatile address, memcpy, and reference aliases stayed at 248 or
// worsened the prologue.  Keep the direct cast as the binary-supported source.
// probe: same-TU virtual base and task-list declarations initially shifted
// offsets; removing compensating gaps restored the 248-byte codegen basin.
// probe: a focused seven-way lab of non-volatile target casts, address aliases,
// and local pointer copies collapsed to one 383-byte codegen group; none
// reproduced the oracle's +0x83 parameter-home reload.
// probe: using this as the empty-list task candidate improved positional diff
// by four bytes but lost the shared jump block and worsened shape; restored the
// typed target fallback because the candidate is not behavior-plausible.
// fresh pass: dossier, same-TU donors, and stack-home lessons confirm the
// remaining +0x83 reload as the only natural-source blocker; no new lead.

class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Task;
class RGE_Action;
class RGE_Action_List;
class RGE_Task_List;
class UnitAIModule;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    char gap_05[0x0B];
    short id;
    char gap_12[2];
    short object_group;
    char gap_16[0xC2];
    RGE_Task_List* tasks;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1E];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Task {
public:
    char gap_00[6];
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    unsigned char gap_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    unsigned char search_flag;
    char gap_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    void* move_sprite;
    void* work_sprite;
    void* work_sprite2;
    void* carry_sprite;
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, short object_id);
    virtual RGE_Task* get_target_task(RGE_Action_Object* action,
                                      RGE_Static_Object* target,
                                      float x, float y, float z);
    virtual int is_attack_task(RGE_Task* task);
    virtual int check_task(RGE_Task* task, RGE_Action_Object* action,
                           RGE_Static_Object* target);
    virtual ~RGE_Task_List();
    RGE_Task** list;
    short list_num;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Static_Object* object);
    virtual int setup(int type, RGE_Static_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Static_Object* object);
    virtual void rehook();
    virtual void save(int file);
    virtual short action_id();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* target, float x, float y, float z);
    virtual int work(RGE_Static_Object* target, float x, float y, float z);
};

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    virtual RGE_Action* create_task_action(RGE_Task* task,
                                             RGE_Static_Object* target,
                                             float x, float y, float z);

    int action_work(RGE_Static_Object* target, float x, float y, float z);
    RGE_Action* get_action();
    RGE_Task* get_task();
};

class UnitAIModule {
public:
    void setCurrentOrder(int order);
    void setCurrentAction(int action);
    void setCurrentTarget(int id, int group, float x, float y, float z);
    void setTaskedByPlayer();
};

#define VPAD1(n) virtual void vpad_##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)
#define VPAD15(n) VPAD8(n) VPAD4(n##_8) VPAD2(n##_12) VPAD1(n##_14)

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    VPAD15(1)
    VPAD4(16)
    VPAD1(20)
    virtual void transform(RGE_Master_Static_Object* master);
    VPAD16(22)
    VPAD1(38)
    virtual void move_to(RGE_Static_Object* target, float x, float y, float z);
    VPAD64(40)
    VPAD16(104)
    VPAD8(120)
    VPAD2(128)
    virtual void set_action(RGE_Action* action);

    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x64];
    UnitAIModule* unit_ai;
    char gap_78[0x10C];
    RGE_Action_List* actions;
};

class TRIBE_Combat_Object : public RGE_Action_Object {
public:
    void do_repair(RGE_Static_Object* target);
};

void TRIBE_Combat_Object::do_repair(RGE_Static_Object* target)
{
    RGE_Task* repair_task;
    RGE_Task_List* repair_list;
    int i;
    int task_count;
    RGE_Task** task_list;
    RGE_Task* current_task;
    short action_id;
    int action_worked;
    RGE_Action* action;
    int order;
    int current_action;

    if ((RGE_Action_Object*)target != this) {
        if (this->master_obj->id != 0x9c) {
            this->transform(this->owner->master_objects[0x9c]);
        }

        repair_list = this->master_obj->tasks;
        i = 0;
        task_count = (int)repair_list->list_num;
        if (task_count > 0) {
            repair_task = 0;
            task_list = repair_list->list;
            do {
                repair_task = *task_list;
                if (repair_task->action_type == 0x6a) {
                    RGE_Master_Static_Object* target_master = target->master_obj;
                    if (target_master->master_type == 'P') {
                        if (repair_task->object_group == -1 ||
                            repair_task->object_group == 0) {
                            break;
                        }
                    }
                    if (repair_task->object_group == target_master->object_group) {
                        break;
                    }
                }
                repair_task = 0;
                ++i;
                ++task_list;
            } while (i < task_count);
        } else {
            repair_task = (RGE_Task*)target;
        }

        current_task = this->actions->get_task();
        action_id = 0;
        action_worked = 0;
        if (current_task != 0 && repair_task == current_task &&
            this->actions->action_work(target,
                                       target->world_x,
                                       target->world_y,
                                       target->world_z) != 0) {
            action_id = this->actions->get_action()->action_id();
            action_worked = 1;
        }

        if (action_worked == 0) {
            if (repair_task != 0) {
                action = this->actions->create_task_action(
                    repair_task, target,
                    target->world_x, target->world_y, target->world_z);
            } else {
                action = 0;
            }

            if (action != 0) {
                action_id = action->action_id();
                this->set_action(action);
            } else {
                action_id = 0;
            }
        }

        if (this->unit_ai != 0) {
            order = -1;
            current_action = -1;
            if (action_id == 0x6a) {
                current_action = 0x26a;
                order = 0x2ce;
            }
            this->unit_ai->setCurrentOrder(order);
            this->unit_ai->setCurrentAction(current_action);
            this->unit_ai->setCurrentTarget(
                target->id,
                target->master_obj->object_group,
                target->world_x,
                target->world_y,
                target->world_z);
            this->unit_ai->setTaskedByPlayer();
        }
    }
}

#undef VPAD15
#undef VPAD64
#undef VPAD32
#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1
