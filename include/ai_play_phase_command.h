#ifndef AOE1_AI_PLAY_PHASE_COMMAND_H
#define AOE1_AI_PLAY_PHASE_COMMAND_H

class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    unsigned char _pad_02[2];
    int value1Value;
    int value2Value;
    int value3Value;
};

typedef char ai_play_phase_command_size_check[
    (sizeof(AIPlayPhaseCommand) == 0x10) ? 1 : -1];

#endif
