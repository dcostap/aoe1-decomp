// 005096A0 TTaunt::RestartSoundSystem
// Source: taunt.cpp lines 173-179
// Size: 121 bytes, EH-framed
//
// Attempt log:
// Probe 1: loop creating 4 TDigital objects, /GX

#include "..\..\include\game_globals.h"

class TSound_Driver;

class TDigital {
public:
    char _gap_00[0x3C];  // padding to sizeof 0x3C
    TDigital(TSound_Driver* driver, const char* name, int flag);
};

class TTaunt {
public:
    TDigital* Audio[4];     // +0x00 to +0x0F
    char _gap_10[0x103];    // +0x10 to +0x112
    char* TauntDir;         // +0x113
    char _gap_117[0x7D];    // +0x117 to +0x193
    int Mute;               // +0x194

    int RestartSoundSystem(TSound_Driver* driver);
};

int TTaunt::RestartSoundSystem(TSound_Driver* driver)
{
    for (int i = 0; i < 4; i++) {
        this->Audio[i] = new TDigital(driver, "Silence", -1);
    }
    return 1;
}
