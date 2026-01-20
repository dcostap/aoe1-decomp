#pragma once
#include "common.h"

struct AIPlayPhase {
    AIPlayPhaseCommand commands[5];
    AIPlayPhaseTrigger triggers[3];
};
static_assert(sizeof(AIPlayPhase) == 0x8C, "Size mismatch");
