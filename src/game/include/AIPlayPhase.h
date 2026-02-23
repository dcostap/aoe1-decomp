#pragma once
#include "common.h"

#include "AIPlayPhaseCommand.h"
#include "AIPlayPhaseTrigger.h"

struct AIPlayPhase {
    AIPlayPhaseCommand commands[5];
    AIPlayPhaseTrigger triggers[3];
};
static_assert(sizeof(AIPlayPhase) == 0x8C, "Size mismatch");
