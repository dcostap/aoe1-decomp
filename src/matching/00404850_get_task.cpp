class RGE_Task;

class RGE_Action {
public:
    char gap_00[0x30];
    RGE_Task* task;
};

class RGE_Action_Node {
public:
    RGE_Action* action;
};

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node* list;

    RGE_Task* get_task(void);
};

RGE_Task* RGE_Action_List::get_task(void) {
    if (this->list != 0) {
        return this->list->action->task;
    }
    return 0;
}
