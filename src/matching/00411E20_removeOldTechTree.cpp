// first pass: walk the tech-tree list from head->next, call the node destructor, then reset head links and length
// if this misses, the remaining mismatch is likely only the prolog/epilog or the linked-list cursor register choice

class TechnologyItem {
public:
    virtual void scalar_deleting_destructor(unsigned int param_1);
    TechnologyItem* next;
    TechnologyItem* prev;
    char gap_0C[0x48];
};

class ResearchAIModule {
public:
    char gap_00[0xF4];
    TechnologyItem techTree;
    int techTreeLengthValue;

    void removeOldTechTree(void);
};

void ResearchAIModule::removeOldTechTree(void) {
    TechnologyItem* head = &techTree;
    TechnologyItem* node = techTree.next;

    while (node != head && node != 0) {
        TechnologyItem* next = node->next;
        node->scalar_deleting_destructor(1);
        node = next;
    }

    techTree.next = head;
    techTree.prev = head;
    techTreeLengthValue = 0;
}
