// m_ac_obj.cpp:169-175, 112 bytes
// attempt 7: no-inheritance explicit base call kept store sunk and introduced extra cleanup call.
// attempt 8: restore real inheritance/auto base dtor, manual volatile vftable store before task cleanup.

class RGE_Task_List {
public:
    ~RGE_Task_List();
};

extern void __cdecl operator_delete(void*);

class RGE_Master_Moving_Object {
public:
    virtual void vf00();
    virtual ~RGE_Master_Moving_Object();
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_04[0xD8 - 4];
    RGE_Task_List* tasks;  // +0xD8

    ~RGE_Master_Action_Object();
};

RGE_Master_Action_Object::~RGE_Master_Action_Object() {
    *(void* volatile*)this = (void*)0x00570448;
    RGE_Task_List* task_list = *(RGE_Task_List* volatile*)((char*)this + 0xD8);
    if (task_list == 0) {
    } else {
        task_list->~RGE_Task_List();
        operator_delete(task_list);
        this->tasks = 0;
    }
}
