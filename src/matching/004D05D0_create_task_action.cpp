// VA: 004D05D0 TRIBE_Action_List::create_task_action
// PDB source: tact_lst.cpp
// FLAGS: config\flags\004D05D0_create_task_action.rsp (/GX)
// Attempt log:
// - prior helper factory collapsed the repeated allocation and constructor arms.
// - baseline: explicit task-type switch with the original action classes and constructor overloads.

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);

    RGE_Action_Object* obj;
};

class RGE_Task {
public:
    char gap_00[6];
    short action_type;
};

class TRIBE_Action_Build : public RGE_Action {
public:
    virtual ~TRIBE_Action_Build();
    char gap_04[0x3C];
    TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    virtual ~TRIBE_Action_Convert();
    char gap_04[0x44];
    TRIBE_Action_Convert(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Convert(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Heal : public RGE_Action {
public:
    virtual ~TRIBE_Action_Heal();
    char gap_04[0x3C];
    TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    virtual ~TRIBE_Action_Artifact();
    char gap_04[0x3C];
    TRIBE_Action_Artifact(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Artifact(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Wonder : public RGE_Action {
public:
    virtual ~TRIBE_Action_Wonder();
    char gap_04[0x3C];
    TRIBE_Action_Wonder(RGE_Action_Object*);
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    virtual ~TRIBE_Action_Discovery_Artifact();
    char gap_04[0x40];
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Hunt : public RGE_Action {
public:
    virtual ~TRIBE_Action_Hunt();
    char gap_04[0x40];
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Repair : public RGE_Action {
public:
    virtual ~TRIBE_Action_Repair();
    char gap_04[0x40];
    TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Trade : public RGE_Action {
public:
    virtual ~TRIBE_Action_Trade();
    char gap_04[0x44];
    TRIBE_Action_Trade(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Trade(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
    char gap_04[0x3C];
    RGE_Action_Enter(RGE_Action_Object*, RGE_Task*, RGE_Action_Object*);
};

class RGE_Action_Transport : public RGE_Action {
public:
    virtual ~RGE_Action_Transport();
    char gap_04[0x3C];
    RGE_Action_Transport(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_List : public RGE_Action_List {
public:
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
};

RGE_Action* TRIBE_Action_List::create_task_action(
    RGE_Task* task,
    RGE_Static_Object* target,
    float x,
    float y,
    float z)
{
    switch (task->action_type) {
    case 0x65:
        if (target != 0)
            return new TRIBE_Action_Build(this->obj, task, target);
        return new TRIBE_Action_Build(this->obj, task, x, y, z);
    case 0x68:
        if (target != 0)
            return new TRIBE_Action_Convert(this->obj, task, target);
        return new TRIBE_Action_Convert(this->obj, task, x, y, z);
    case 0x69:
        if (target != 0)
            return new TRIBE_Action_Heal(this->obj, task, target);
        return new TRIBE_Action_Heal(this->obj, task, x, y, z);
    case 0x6B:
        if (target != 0)
            return new TRIBE_Action_Artifact(this->obj, task, target);
        return new TRIBE_Action_Artifact(this->obj, task, x, y, z);
    case 0x78:
        return new TRIBE_Action_Wonder(this->obj);
    case 0x6C:
        if (target != 0)
            return new TRIBE_Action_Discovery_Artifact(this->obj, task, target);
        return new TRIBE_Action_Discovery_Artifact(this->obj, task, x, y, z);
    case 0x6E:
        if (target != 0)
            return new TRIBE_Action_Hunt(this->obj, task, target);
        return new TRIBE_Action_Hunt(this->obj, task, x, y, z);
    case 0x6A:
        if (target != 0)
            return new TRIBE_Action_Repair(this->obj, task, target);
        return new TRIBE_Action_Repair(this->obj, task, x, y, z);
    case 0x6F:
        if (target != 0)
            return new TRIBE_Action_Trade(this->obj, task, target);
        return new TRIBE_Action_Trade(this->obj, task, x, y, z);
    case 3:
        return new RGE_Action_Enter(this->obj, task, (RGE_Action_Object*)target);
    case 0x0C:
        return new RGE_Action_Transport(this->obj, task, x, y, z);
    default:
        return RGE_Action_List::create_task_action(task, target, x, y, z);
    }
}
