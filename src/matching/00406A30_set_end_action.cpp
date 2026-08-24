#ifndef ACT_OBJ_CONTEXT_H
class RGE_Action;

class RGE_Action_List {
public:
    void add_action_at_end(RGE_Action* action);
};

class RGE_Action_Object {
public:
    char gap_0[0x184];
    RGE_Action_List* actions;

    void set_end_action(RGE_Action* action);
};
#endif

void RGE_Action_Object::set_end_action(RGE_Action* action) {
    if (action) {
        this->actions->add_action_at_end(action);
    }
}
