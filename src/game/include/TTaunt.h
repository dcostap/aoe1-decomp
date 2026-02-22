#pragma once
#include "common.h"

struct TTaunt {
    TTaunt(TSound_Driver* param_1);
    ~TTaunt();

    int PlayTauntStr(char* param_1, uchar param_2);
    int PlayTauntNo(int param_1);
    int GetTauntNo(char* param_1);
    char* GetTauntText(int param_1);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* param_1);

    TDigital* Audio[4];
    int LastAudioPlayed;
    char TBuff[255];
    char TauntDir[128];
    int Mute;
};
static_assert(sizeof(TTaunt) == 0x198, "Size mismatch");
