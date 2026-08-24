class RGE_Action_Object;
class RGE_Task;
class RGE_Static_Object;

#ifndef AOE1_TACT_ART_TU_CONTEXT
class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(RGE_Action_Object* object, int doSetup);

    unsigned short action_type;
    char gap_06[0x0A];
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    RGE_Static_Object* target;
    char gap_14[0x1C];
    RGE_Task* task;

    TRIBE_Action_Artifact(RGE_Action_Object* object, RGE_Task* task, RGE_Static_Object* target);
};
#endif

TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object* object, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(object, 1) {
    this->action_type = 0x6B;
    this->task = task;
    this->target = target;
}
