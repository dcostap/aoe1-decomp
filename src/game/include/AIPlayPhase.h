#pragma once
#include "common.h"

#include "AIPlayPhaseCommand.h"
#include "AIPlayPhaseTrigger.h"

struct AIPlayPhase {
    AIPlayPhaseCommand commands[5];
    AIPlayPhaseTrigger triggers[3];

    AIPlayPhase();
    AIPlayPhaseCommand* command(int index);
    AIPlayPhaseTrigger* trigger(int index);
    int addCommand(AIPlayPhaseCommand& commandValue);
    int addTrigger(AIPlayPhaseTrigger& triggerValue);

protected:
    void initialize();
};
static_assert(sizeof(AIPlayPhase) == 0x8C, "Size mismatch");
