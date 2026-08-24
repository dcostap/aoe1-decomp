#ifndef ACT_OBJ_CONTEXT_H
class RGE_Action_List {
public:
    unsigned char have_action(void);
};

class RGE_Action_Object {
public:
    char gap_0[0x184];
    RGE_Action_List* actions;

    unsigned char have_action(void);
};
#endif

unsigned char RGE_Action_Object::have_action(void) {
    if (this->actions->have_action()) {
        return 1;
    }
    return 0;
}
