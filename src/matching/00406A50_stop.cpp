#ifndef ACT_OBJ_CONTEXT_H
class RGE_Action_List {
public:
    int action_stop(void);
    void delete_list(void);
};

class RGE_Action_Object {
public:
    char gap_00[0x184];
    RGE_Action_List* actions;

    void stop(void);
};
#endif

void RGE_Action_Object::stop(void) {
    if (this->actions->action_stop() == 0) {
        this->actions->delete_list();
    }
}
