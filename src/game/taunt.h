#pragma once
#include "../common.h"
#include "Sounddrv.h"

class TTaunt {
public:
    TDigital* Audio[4];            // 0x0
    int LastAudioPlayed;                     // 0x10
    char TBuff[255];                         // 0x14
    char TauntDir[128];                      // 0x113
    int Mute;                                // 0x194

    TTaunt(TSound_Driver* param_1);
    ~TTaunt();
    int PlayTauntStr(char* param_1, uchar param_2);
    int PlayTauntNo(int param_1);
    int GetTauntNo(char* param_1);
    char* GetTauntText(int param_1);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* param_1);
};

static_assert(sizeof(TTaunt) == 0x198, "TTaunt Size Mismatch");
static_assert(offsetof(TTaunt, Mute) == 0x194, "TTaunt Offset Mismatch");

