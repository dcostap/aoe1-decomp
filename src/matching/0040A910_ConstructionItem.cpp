#include "../../include/aiconitm_context.h"

ConstructionItem::ConstructionItem(const ConstructionItem& other)
    : BaseItem(other) {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = other.inProgressValue;
    this->builtValue = other.builtValue;
    this->buildAttemptsValue = other.buildAttemptsValue;
}
