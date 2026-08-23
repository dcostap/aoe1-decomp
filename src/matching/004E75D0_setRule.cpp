#include "../../include/taistrmd_context.h"

void VictoryConditionRuleSystem::setRule(int index, int val) {
    if (index < 0 || index >= 226) return;
    this->sn[index] = val;
}
