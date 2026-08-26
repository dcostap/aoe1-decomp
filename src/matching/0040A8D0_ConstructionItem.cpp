#include "../../include/aiconitm_context.h"

// BINARY NOTE: The original copy constructor writes the derived vptr after
// all derived-field stores. Initializer-list form preserves that VC5 order;
// equivalent body assignments move the vptr before those stores.
ConstructionItem::ConstructionItem(ConstructionItem* other)
    : BaseItem(other),
      next(0),
      prev(0),
      inProgressValue(other->inProgressValue),
      builtValue(other->builtValue),
      buildAttemptsValue(other->buildAttemptsValue) {}
