// attempt 1: EH-framed factory helper returning a new 0x0C TRIBE_Action_List from this->obj
// result: the first compile needed the local RGE_Action surface to expose obj at +8
// attempt 2: keep the helper natural and let the ctor/new shape do the work

class RGE_Action_Object;
class TRIBE_Action_List;

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    char pad_06[2];
    RGE_Action_Object* obj;
    char pad_0C[0x40 - 0x0C];
};

class RGE_Action_List {
public:
    void* vtable_ptr;
    char pad_04[0xC - 0x4];

    RGE_Action_List(RGE_Action_Object* param_1);
};

class TRIBE_Action : public RGE_Action {
public:
    RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
};

class TRIBE_Action_List : public RGE_Action_List {
public:
    TRIBE_Action_List(RGE_Action_Object* param_1);
};

RGE_Action_List* TRIBE_Action::create_action_list(RGE_Action_Object* param_1) {
    TRIBE_Action_List* list = new TRIBE_Action_List(this->obj);
    return (RGE_Action_List*)list;
}
