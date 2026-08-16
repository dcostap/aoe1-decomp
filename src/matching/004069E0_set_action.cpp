class RGE_Action {
};

class RGE_Action_List {
public:
    void add_action(RGE_Action* action);
};

class RGE_Action_Object {
public:
    char gap_0[0x184];
    RGE_Action_List* actions;

    void set_action(RGE_Action* action);
};

void RGE_Action_Object::set_action(RGE_Action* action) {
    if (action != 0) {
        this->actions->add_action(action);
    }
}
