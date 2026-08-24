// first pass: walk the tech-tree list from head->next, call the node destructor, then reset head links and length
// if this misses, the remaining mismatch is likely only the prolog/epilog or the linked-list cursor register choice

#include "../../include/airchmod_context.h"

void ResearchAIModule::removeOldTechTree(void) {
    TechnologyItem* head = &this->techTree;
    TechnologyItem* node = this->techTree.next;

    while (node != head && node != 0) {
        TechnologyItem* next = node->next;
        delete node;
        node = next;
    }

    this->techTree.next = head;
    this->techTree.prev = head;
    this->techTreeLengthValue = 0;
}
