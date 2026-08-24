// VA: 0044F710 RGE_Master_Action_Object::getTaskByTaskID (76 B)
// PDB source: m_ac_obj.cpp lines 223-237

#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
struct RGE_Task {
    char gap_00[6];
    short action_type;  // +0x06, signed word
};

struct TaskList {
    char gap_00[4];
    RGE_Task** list;  // +0x04
    short list_num;   // +0x08, signed word
};

typedef TaskList RGE_Task_List;

class RGE_Master_Action_Object {
public:
    char gap_00[0xD8];
    TaskList* tasks;  // +0xD8

    RGE_Task* getTaskByTaskID(int task_id) const;
};
#endif

RGE_Task* RGE_Master_Action_Object::getTaskByTaskID(int task_id) const {
    if (task_id == -1) {
        return 0;
    }

    RGE_Task_List* tl = this->tasks;
    int i;
    for (i = 0; i < tl->list_num; i++) {
        if (task_id == tl->list[i]->action_type) {
            return tl->list[i];
        }
    }
    return 0;
}
