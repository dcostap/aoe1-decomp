// BINARY NOTE: The PDB destructor owns the task-list cleanup. The reviewed
// context proves a direct nonvirtual RGE_Task_List destructor call.

RGE_Master_Action_Object::~RGE_Master_Action_Object() {
    RGE_Task_List* task_list = this->tasks;
    if (task_list == 0) {
    } else {
        task_list->~RGE_Task_List();
        operator_delete(task_list);
        this->tasks = 0;
    }
}
