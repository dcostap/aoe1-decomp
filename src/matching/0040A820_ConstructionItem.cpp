#include "../../include/aiconitm_context.h"

ConstructionItem::ConstructionItem() : BaseItem() {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
}
