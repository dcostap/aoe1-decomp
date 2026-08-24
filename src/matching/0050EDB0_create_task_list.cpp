// probe 1: keep target first, let derived default ctor be compiler-synthesized, define base ctor after target
#ifndef TM_CO_OB_SHARED_CONTEXT
class RGE_Task_List {
public:
    virtual void destroy();
    int list;
    short list_num;

    RGE_Task_List();
};

class TRIBE_Task_List : public RGE_Task_List {
public:
    virtual void destroy();
};

class TRIBE_Master_Combat_Object {
public:
    virtual RGE_Task_List* create_task_list();
};
#endif

RGE_Task_List* TRIBE_Master_Combat_Object::create_task_list() {
    return new TRIBE_Task_List();
}

RGE_Task_List::RGE_Task_List() {
    list_num = 0;
    list = 0;
}
