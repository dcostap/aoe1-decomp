#include "../../include/aiconitm_context.h"

void ConstructionItem::decrementBuildAttempts() {
    this->buildAttemptsValue--;
    if (this->buildAttemptsValue < 0) {
        this->buildAttemptsValue = 0;
    }
}
