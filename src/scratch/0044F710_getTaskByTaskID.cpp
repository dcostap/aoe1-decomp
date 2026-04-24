// first pass: reject -1, then scan the task list for a matching action_type and return the corresponding task pointer
// tried direct/local task-list shapes, pointer-vs-index loop variants, and a decompiler-shaped do/while; the remaining mismatch is now the early prolog/loop-branch basin (push order / branch displacement)

class RGE_Task {
public:
    char gap_00[0x6];
    short action_type;
};

class RGE_Task_List {
public:
    char gap_00[0x4];
    RGE_Task** list;
    short list_num;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xD8];
    RGE_Task_List* tasks;

    RGE_Task* getTaskByTaskID(int taskID) const;
};

RGE_Task* RGE_Master_Action_Object::getTaskByTaskID(int taskID) const {
    RGE_Task** ppRVar1;
    RGE_Task** ppRVar3;
    int iVar2;
    int iVar4;

    if (taskID == -1) {
        return 0;
    }

    iVar2 = 0;
    iVar4 = this->tasks->list_num;
    if (0 < iVar4) {
        ppRVar1 = this->tasks->list;
        ppRVar3 = ppRVar1;
        do {
            if (taskID == (*ppRVar3)->action_type) {
                return ppRVar1[iVar2];
            }
            iVar2 = iVar2 + 1;
            ppRVar3 = ppRVar3 + 1;
        } while (iVar2 < iVar4);
    }
    return 0;
}
