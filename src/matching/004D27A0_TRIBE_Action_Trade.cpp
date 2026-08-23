#ifndef TACT_TRD_SHARED_CONTEXT
class RGE_Action_Object;
class RGE_Task;

class RGE_Action {
public:
    unsigned short action_type;
    char gap_06[0x1A];

    virtual ~RGE_Action();
    RGE_Action(RGE_Action_Object* obj, int value);
};

class TRIBE_Action_Trade : public RGE_Action {
public:
    float field_20;
    float field_24;
    float field_28;
    char gap_2C[0x04];
    RGE_Task* task;
    char gap_34[0x0C];
    float pick_up_x;
    float pick_up_y;

    virtual ~TRIBE_Action_Trade();
    TRIBE_Action_Trade(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z);
};
#endif

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z)
#ifdef TACT_TRD_SHARED_CONTEXT
    : RGE_Action(obj, 1)
#else
    : RGE_Action(obj, 1), task(task)
#endif
{
#ifdef TACT_TRD_SHARED_CONTEXT
    this->task = task;
#endif
    this->action_type = 0x6F;
#ifdef TACT_TRD_SHARED_CONTEXT
    *(int*)&this->target_x = *(int*)&x;
    *(int*)&this->target_y = *(int*)&y;
#else
    *(int*)&this->field_20 = *(int*)&x;
    *(int*)&this->field_24 = *(int*)&y;
#endif
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
#ifdef TACT_TRD_SHARED_CONTEXT
    *(int*)&this->target_z = *(int*)&z;
#else
    *(int*)&this->field_28 = *(int*)&z;
#endif
}
