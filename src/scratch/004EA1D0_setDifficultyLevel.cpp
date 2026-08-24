#include "../../include/taistrmd_context.h"

void TribeStrategyAIModule::setDifficultyLevel(int param) {
    this->vcRules.modifyForDifficultyLevel(param);
}
