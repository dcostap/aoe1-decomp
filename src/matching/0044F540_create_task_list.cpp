// quick-win attempt log:
// first probe that kept create_task_list first in the TU compiled too small and lost
// the EH/new-expression basin; next probe will keep the target lexically first and
// move the helper ctor/dtor definitions after it so the extractor still sees the right body

class RGE_Task_List {
public:
    int list;
    short list_num;
    RGE_Task_List();
    virtual ~RGE_Task_List();
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xD8];
    RGE_Task_List* tasks;

    virtual RGE_Task_List* create_task_list(void);
};

RGE_Task_List* RGE_Master_Action_Object::create_task_list(void) {
    return new RGE_Task_List();
}

RGE_Task_List::RGE_Task_List() {
    list_num = 0;
    list = 0;
}

RGE_Task_List::~RGE_Task_List() {
}
