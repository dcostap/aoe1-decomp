class RGE_Action {
public:
    char gap_00[0x04];
    short action_type;
    char gap_06[0x06];
    unsigned char state;
};

class RGE_Action_List {
public:
    RGE_Action* get_action(void);
};

class RGE_Action_Object {
public:
    char gap_00[0x184];
    RGE_Action_List* actions;

    long get_action_checksum(void);
};

long RGE_Action_Object::get_action_checksum(void) {
    RGE_Action* action;
    long checksum;

    checksum = 0;
    if (this->actions != 0) {
        action = this->actions->get_action();
        if (action != 0) {
            checksum = (int)action->action_type + (unsigned int)action->state;
        }
    }
    return checksum;
}
