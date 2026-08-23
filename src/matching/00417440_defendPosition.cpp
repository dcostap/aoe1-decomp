// defendPosition: aiuaimod.cpp lines 3733-3747
// __thiscall, virtual (but we don't rely on virtual here)
// Direct transcription of original asm.
// Attempt 1: straightforward implementation with minimal stubs.

#include "../../include/aiuaimod_context.h"

int UnitAIModule::defendPosition(float x, float y, float distance, int flag) {
    // Guard: if (flag == 0 && currentActionValue != -1) return 0;
    if (flag == 0 && this->currentActionValue != -1) {
        return 0;
    }

    // setCurrentAction(0x259)
    this->setCurrentAction(0x259);

    // setCurrentTarget(-1, x, y, this->objectValue->world_z)
    this->setCurrentTarget(-1, x, y, this->objectValue->world_z);

    // this->defendTargetValue = -1;
    this->defendTargetValue = -1;

    // this->desiredTargetDistanceValue = distance;
    this->desiredTargetDistanceValue = distance;

    return 1;
}
