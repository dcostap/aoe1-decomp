#pragma once
#include "common.h"

struct TTaunt {
    TDigital* Audio[4];
    int LastAudioPlayed;
    char TBuff[255];
    char TauntDir[128];
    int Mute;
};
static_assert(sizeof(TTaunt) == 0x198, "Size mismatch");
