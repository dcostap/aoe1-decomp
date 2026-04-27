// m_ac_obj.cpp:169-175, 112 bytes
// attempt 1: 79.5%, no EH
// attempt 2: 58.0%, /GX added but vptr=0, no base dtor call
// attempt 3: 51.8%, base dtor present but still vptr=0, push edi missing
// attempt 4: 51.8%, added vf00 no help
// attempt 5: 51.8%, same
// BEST: 51.8%. BLOCKER: missing push edi (register pressure differs),
//   vptr set to 0 (not 570448h), register basin (eax vs edi for tasks).
//   /GX rsp needed. Core logic (task dtor, delete, base dtor) all correct.
class RGE_Task_List {
public:
    ~RGE_Task_List() {}
};

extern void __cdecl operator_delete(void*);

class RGE_Master_Moving_Object {
public:
    virtual void vf00() {}
    virtual ~RGE_Master_Moving_Object();
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_04[0xD8 - 4];
    RGE_Task_List* tasks;  // +0xD8

    ~RGE_Master_Action_Object();
};

RGE_Master_Action_Object::~RGE_Master_Action_Object() {
    if (tasks != 0) {
        tasks->~RGE_Task_List();
        operator_delete(tasks);
        tasks = 0;
    }
    RGE_Master_Moving_Object::~RGE_Master_Moving_Object();
}
