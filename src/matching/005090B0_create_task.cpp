// task_lst.cpp:148-154, 103 bytes
// attempt 1: compile error C2660 with placement new
// attempt 2: 64 bytes, explicit ctor call too compact
// attempt 3: 48 bytes, __fastcall too compact
// attempt 4: try class with virtuals for EH, new/delete
// FLAGS: /GX
class RGE_Task {
public:
    virtual void vf00();
    char gap_04[0x4C - 0x04];
    RGE_Task(short);
};

class RGE_Task_List {
public:
    RGE_Task* create_task(short param1, short param2);
};

RGE_Task* RGE_Task_List::create_task(short param1, short param2) {
    if (param1 != 1) {
        return 0;
    }
    RGE_Task* task = new RGE_Task(param2);
    return task;
}
