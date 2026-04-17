class RGE_Action {
public:
    float targetZ();
};

class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
};

class RGE_Combat_Object {
public:
    unsigned char gap_00[0x180];
    RGE_Action_List* action_list;

    virtual float currentTargetZ() const;
};

float RGE_Combat_Object::currentTargetZ() const {
    if (action_list->have_action() == 1) {
        return action_list->get_action()->targetZ();
    }
    return -1.0f;
}
