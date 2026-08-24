#ifndef ACT_MAKE_CONTEXT_H
class RGE_Action_Object;
class RGE_Task;

class RGE_Action {
public:
    void* vtable_ptr;
    char gap_04[0x3C];

    RGE_Action(RGE_Action_Object* param_1, int param_2);
};

class RGE_Action_Make : public RGE_Action {
public:
    RGE_Action_Make(RGE_Action_Object* param_1, RGE_Task* param_2);
};
#endif

#ifdef ACT_MAKE_CONTEXT_H
RGE_Action_Make::RGE_Action_Make(RGE_Action_Object* param_1, RGE_Task* param_2)
    : RGE_Action(param_1, 1) {
    this->action_type = 0x15;
    this->task = param_2;
}
#else
RGE_Action_Make::RGE_Action_Make(RGE_Action_Object* param_1, RGE_Task* param_2)
    : RGE_Action(param_1, 1) {
    this->vtable_ptr = (void*)0x56E2B8;
    *(short*)((char*)this + 4) = 0x15;
    *(RGE_Task**)((char*)this + 0x30) = param_2;
}
#endif
