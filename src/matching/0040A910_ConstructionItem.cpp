#include "../../include/aiconitm_context.h"

// BINARY NOTE: The original copy constructor writes the derived vptr after
// the body stores. Natural VC5 virtual-class code writes it before them.
// The old exact source used a raw vtable field. Policy does not allow it.
ConstructionItem::ConstructionItem(const ConstructionItem& other)
    : BaseItem(other) {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = other.inProgressValue;
    this->builtValue = other.builtValue;
    this->buildAttemptsValue = other.buildAttemptsValue;
}
