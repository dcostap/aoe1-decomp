#include "../../include/taistrmd_context.h"

int VictoryConditionRuleSystem::rule(int index) {
    if (index < 0 || index >= 226) return -1;
    return this->sn[index];
}
