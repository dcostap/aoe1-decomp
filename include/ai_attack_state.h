#ifndef AOE1_AI_ATTACK_STATE_H
#define AOE1_AI_ATTACK_STATE_H

struct AttackState {
    int bestTargetID;
    float bestTargetValue;
    int bestTargetMemoryIndex;
    int iterationIndex;
    int attackGroupID;
    int playID;
    unsigned char phase;
    int bestNonWallTargetID;
    float bestNonWallTargetValue;
    int bestNonWallTargetMemoryIndex;
    int active;
};

typedef char ai_attack_state_size_check[
    (sizeof(AttackState) == 0x2C) ? 1 : -1];

#endif
