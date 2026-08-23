class RGE_Action_Object {
public:
    char gap_0[8];
    int *action_ptr;
    int get_action();
};

int RGE_Action_Object::get_action() {
    if (this->action_ptr) return *this->action_ptr;
    return 0;
}
