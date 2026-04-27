// attempt log:
// first pass: EH-framed factory helper returning a new 0x0C RGE_Action_List from this->obj
// target shape: allocate 0x0C, pass this->obj (offset 8) into the ctor, return new list or 0

class RGE_Action_Object;

class RGE_Action_List {
public:
    virtual void dummy();
    int field_4;
    int field_8;
    RGE_Action_List(RGE_Action_Object* param_1);
};

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    unsigned char pad_6[2];
    RGE_Action_Object* obj;
    unsigned char state;
    unsigned char pad_d[3];
    RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
};

RGE_Action_List* RGE_Action::create_action_list(RGE_Action_Object* param_1) {
    return new RGE_Action_List(this->obj);
}
