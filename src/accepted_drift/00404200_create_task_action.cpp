// STATUS: PAUSED
// FLAGS: /GX is required for the binary-observed new-expression EH frame.
// NOTE: Natural typed factory reconstruction. Keep action ownership and
// constructor calls in the source; do not replace them with helper bridges.
// ATTEMPT LOG:
// - Replaced the former naked inline-assembly body with a typed action switch,
//   direct global allocation, direct constructors, and typed UnitAI calls.
// - The current source preserves all 19 direct call sites, the EH prologue,
//   allocation sizes, task and master offsets, and the original branch labels.
// - The best natural build is still nonexact. VC5 retains an extra shared
//   result test and emits the switch table outside the original boundary.
// - Behavior correction: RGE_Static_Object world_x/world_y/world_z are at
//   +0x38/+0x3C/+0x40. The prior +0x3C/+0x40/+0x44 layout passed the wrong
//   target coordinates to UnitAIModule::setCurrentTarget.
// - Accepted drift: all 19 calls, constructor arguments, UnitAI effects,
//   allocation failures, EH states, faulting reads, and action results match.
//   VC5 adds redundant tests of constructor results and a duplicate SEH return
//   tail. Each constructor returns its allocated this pointer. Switch-table
//   placement also differs outside the owning function boundary.
// - Exact-finish pass: `fail: return 0; done: return action;` removes the
//   duplicate SEH tail and reaches 73 differing bytes, but leaves one shared
//   result test and a shifted switch table. Explicit placement new removes EH
//   state and broadens the mismatch. Restore the pinned source after each test.
// - Full PDB surfaces from 00404610 and positive guards are codegen duplicates.
//   The remaining 73-byte basin is not an exact source model.
// NEXT: Revisit only with evidence for the original common return-tail source
//   form or a linker-bound switch-table ownership context.

#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action;
class RGE_Action_Object;
class RGE_Master_Combat_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class UnitAIModule;

void* __cdecl operator new(unsigned int size);

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual RGE_Action* create_action(int param_1, short param_2);

    char gap_04[0x3C];
};

class RGE_Action_Attack : public RGE_Action {
public:
    virtual ~RGE_Action_Attack();
    char gap_40[0x1C];

    RGE_Action_Attack(
        RGE_Action_Object* obj,
        RGE_Static_Object* target,
        RGE_Sprite* move_sprite,
        RGE_Sprite* work_sprite,
        RGE_Sprite* wait_sprite,
        float work_range,
        float minimum_weapon_range,
        short base_hit_chance,
        short fire_missile_at_frame);

    RGE_Action_Attack(
        RGE_Action_Object* obj,
        float x,
        float y,
        float z,
        RGE_Sprite* move_sprite,
        RGE_Sprite* work_sprite,
        RGE_Sprite* wait_sprite,
        float work_range,
        float minimum_weapon_range,
        short base_hit_chance,
        short fire_missile_at_frame);
};

class RGE_Action_Bird : public RGE_Action {
public:
    virtual ~RGE_Action_Bird();
    RGE_Action_Bird(
        RGE_Action_Object* obj,
        RGE_Task* task,
        float x,
        float y,
        float z);
};

class RGE_Action_Explore : public RGE_Action {
public:
    virtual ~RGE_Action_Explore();
    RGE_Action_Explore(
        RGE_Action_Object* obj,
        RGE_Task* task,
        float x,
        float y,
        float z);
};

class RGE_Action_Gather : public RGE_Action {
public:
    virtual ~RGE_Action_Gather();
    char gap_40[0x04];

    RGE_Action_Gather(
        RGE_Action_Object* obj,
        RGE_Task* task,
        RGE_Static_Object* target);
    RGE_Action_Gather(
        RGE_Action_Object* obj,
        RGE_Task* task,
        float x,
        float y,
        float z);
};

class RGE_Action_Make : public RGE_Action {
public:
    virtual ~RGE_Action_Make();
    RGE_Action_Make(RGE_Action_Object* obj, RGE_Task* task);
};

class RGE_Master_Combat_Object {
public:
    char gap_00[0x124];
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char gap_129;
    short fire_missile_at_frame;
    char gap_12C[0x0C];
    float minimum_weapon_range;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;
    RGE_Master_Combat_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
    float world_z;

    UnitAIModule* unitAI();
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Task {
public:
    char gap_00[0x06];
    short action_type;
    char gap_08[0x1C];
    float work_range;
    char gap_28[0x0C];
    RGE_Sprite* work_sprite;
    RGE_Sprite* move_sprite;
};

class UnitAIModule {
public:
    void setCurrentAction(int value);
    void setCurrentTarget(int id, float x, float y, float z);
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int param_1, short param_2);
    virtual RGE_Action* create_task_action(
        RGE_Task* task,
        RGE_Static_Object* target,
        float x,
        float y,
        float z);

    RGE_Action_Object* obj;
};
#endif

RGE_Action* RGE_Action_List::create_task_action(
    RGE_Task* task,
    RGE_Static_Object* target,
    float x,
    float y,
    float z)
{
    RGE_Action* action;
    RGE_Action_Bird* bird_action;
    RGE_Action_Attack* attack_action;
    RGE_Action_Explore* explore_action;
    RGE_Action_Gather* gather_action;
    RGE_Action_Make* make_action;

    switch (task->action_type) {
    case 10:
        bird_action = new RGE_Action_Bird(this->obj, task, x, y, z);
        if (bird_action == 0) {
            goto fail;
        }
        action = bird_action;
        goto done;

    case 7:
        if (this->obj->unitAI() != 0) {
            this->obj->unitAI()->setCurrentAction(600);
            if (target != 0) {
                this->obj->unitAI()->setCurrentTarget(
                    target->id,
                    target->world_x,
                    target->world_y,
                    target->world_z);
            }
            else {
                this->obj->unitAI()->setCurrentTarget(-1, x, y, z);
            }
        }
        if (target != 0) {
            attack_action = new RGE_Action_Attack(
                this->obj,
                target,
                task->work_sprite,
                task->move_sprite,
                0,
                task->work_range,
                this->obj->master_obj->minimum_weapon_range,
                this->obj->master_obj->missile_id,
                this->obj->master_obj->fire_missile_at_frame);
        } else {
            attack_action = new RGE_Action_Attack(
                this->obj,
                x,
                y,
                z,
                task->work_sprite,
                task->move_sprite,
                0,
                task->work_range,
                this->obj->master_obj->minimum_weapon_range,
                this->obj->master_obj->missile_id,
                this->obj->master_obj->fire_missile_at_frame);
        }
        if (attack_action == 0) {
            goto fail;
        }
        action = attack_action;
        goto done;

    case 4:
        explore_action = new RGE_Action_Explore(this->obj, task, x, y, z);
        if (explore_action == 0) {
            goto fail;
        }
        action = explore_action;
        goto done;

    case 5:
        if (target != 0) {
            gather_action = new RGE_Action_Gather(this->obj, task, target);
        } else {
            gather_action = new RGE_Action_Gather(this->obj, task, x, y, z);
        }
        if (gather_action == 0) {
            goto fail;
        }
        action = gather_action;
        goto done;

    case 21:
        make_action = new RGE_Action_Make(this->obj, task);
        if (make_action == 0) {
            goto fail;
        }
        action = make_action;
        goto done;

    default:
        goto fail;
    }

fail:
    action = 0;
done:
    return action;
}

// This source replaces the former inline-assembly attempt.
