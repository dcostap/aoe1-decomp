#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Action {
public:
    float targetY();
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

    virtual float currentTargetY() const;
};
#endif

float RGE_Combat_Object::currentTargetY() const {
    if (action_list->have_action() == 1) {
        return action_list->get_action()->targetY();
    }
    return -1.0f;
}
