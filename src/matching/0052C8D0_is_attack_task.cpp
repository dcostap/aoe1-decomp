class RGE_Task {
public:
    char gap_00[0x06];
    short action_type;
};

class RGE_Task_List {
public:
    virtual int is_attack_task(RGE_Task* task);
};

class TRIBE_Task_List : public RGE_Task_List {
public:
    int is_attack_task(RGE_Task* task);
};

int TRIBE_Task_List::is_attack_task(RGE_Task* task) {
    if (task->action_type == 0x68) {
        return 1;
    }
    return RGE_Task_List::is_attack_task(task);
}
