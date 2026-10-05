#ifndef AOE1_AI_PLAY_PHASE_H
#define AOE1_AI_PLAY_PHASE_H

#include "ai_play_phase_command.h"
#include "ai_play_phase_trigger.h"

class AIPlayPhase {
  public:
    enum { MaxCommands = 5, MaxTriggers = 3 };

  protected:
    AIPlayPhaseCommand commands[MaxCommands]; // +0x00
    AIPlayPhaseTrigger triggers[MaxTriggers]; // +0x50

  public:
    AIPlayPhase();
    AIPlayPhaseCommand* command(int v);
    AIPlayPhaseTrigger* trigger(int v);
    int addCommand(AIPlayPhaseCommand& c);
    int addTrigger(AIPlayPhaseTrigger& t);

  protected:
    void initialize();
};

typedef char ai_play_phase_size_check[(sizeof(AIPlayPhase) == 0x8C) ? 1 : -1];

#endif
