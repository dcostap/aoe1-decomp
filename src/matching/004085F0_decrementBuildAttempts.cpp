#include "../../include/aiblditm_context.h"

void BuildItem::decrementBuildAttempts() {
    --buildAttemptsValue;
    if (buildAttemptsValue < 0) {
        buildAttemptsValue = 0;
    }
}
