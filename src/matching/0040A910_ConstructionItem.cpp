#include "../../include/aiconitm_context.h"

// BINARY NOTE: PDB line 63 calls BaseItem::BaseItem(const BaseItem&) at
// 0040A919. The shared declaration must expose that const-reference overload.
// Initializers preserve the original derived-vptr placement after the stores.
ConstructionItem::ConstructionItem(const ConstructionItem& other)
    : BaseItem(other),
      next(0),
      prev(0),
      inProgressValue(other.inProgressValue),
      builtValue(other.builtValue),
      buildAttemptsValue(other.buildAttemptsValue) {}
