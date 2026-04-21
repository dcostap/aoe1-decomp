class RGE_Action_Object;

class RGE_Action {
public:
    void* vtable_ptr;
    char gap_04[0x3C];

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
};

class RGE_Action_Make : public RGE_Action {
public:
    RGE_Action_Make(int param_1, RGE_Action_Object* param_2);
};

RGE_Action_Make::RGE_Action_Make(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    this->vtable_ptr = (void*)0x56E2B8;
    *(short*)((char*)this + 4) = 0x15;
}
