class RGE_Action {
public:
    char gap_00[0x0C];
    unsigned char state;
};

class RGE_Action_List {
public:
    unsigned char have_action(void);
    RGE_Action* get_action(void);
};

class RGE_Action_Object {
public:
    char gap_00[0x184];
    RGE_Action_List* actions;

    unsigned char actionState(void) const;
};

unsigned char RGE_Action_Object::actionState(void) const {
    if (this->actions->have_action() == 1) {
        return this->actions->get_action()->state;
    }
    return 0;
}
