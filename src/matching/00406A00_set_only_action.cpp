class RGE_Action;

class RGE_Action_List {
public:
    void delete_list(void);
    void add_action(RGE_Action* action);
};

class RGE_Action_Object {
public:
    char gap_00[0x184];
    RGE_Action_List* actions;

    void set_only_action(RGE_Action* action);
};

void RGE_Action_Object::set_only_action(RGE_Action* action) {
    this->actions->delete_list();
    if (action != 0) {
        this->actions->add_action(action);
    }
}
