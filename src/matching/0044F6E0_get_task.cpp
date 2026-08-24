#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Task;

class TaskArray {
public:
    char gap_00[0x4];
    RGE_Task** list;
    short list_num;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xD8];
    TaskArray* tasks;

    RGE_Task* get_task(short task_id);
};
#endif

RGE_Task* RGE_Master_Action_Object::get_task(short task_id) {
    if ((task_id != -1) && (task_id < this->tasks->list_num)) {
        return this->tasks->list[task_id];
    }
    return 0;
}
