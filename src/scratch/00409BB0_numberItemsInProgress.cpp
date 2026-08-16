struct BuildNode {
    int in_progress_flag(void);
    char gap_00[0x6C];
    BuildNode* next;
};

class BuildStatusHost {
public:
    int numberItemsInProgress(void);
    char gap_00[0xF0];
    char sentinel[0x6C];
    BuildNode* head;
};

int BuildStatusHost::numberItemsInProgress(void) {
    BuildNode* current = this->head;
    BuildNode* end = (BuildNode*)((char*)this + 0xF0);
    int count = 0;
    while (current != end && current != 0) {
        if (current->in_progress_flag() == 1) {
            count++;
        }
        current = current->next;
    }
    return count;
}
