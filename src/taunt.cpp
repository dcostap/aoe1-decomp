// Authentic source module for C:\\msdev\\work\\age1_x1\\taunt.cpp.
// Normal owners follow the PDB source-line order.

#include "../include/taunt.h"
#include "../include/sounddrv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);
// BINARY NOTE: These are the anonymous MuteOn and MuteOff literals at
// 0x00576548 and 0x00576550. No canonical providers expose either literal.
extern const char DAT_00576548[];
extern const char DAT_00576550[];

void __cdecl operator delete(void* ptr);

// VA: 00509450 TTaunt::TTaunt
// PDB source: taunt.cpp lines 16-22.
TTaunt::TTaunt(TSound_Driver* sound_driver) {
    this->TauntDir[0] = 0;
    RestartSoundSystem(sound_driver);
    this->Mute = 0;
}

// VA: 00509480 TTaunt::~TTaunt
// PDB source: taunt.cpp line 25.
TTaunt::~TTaunt() {
    StopSoundSystem();
}

// VA: 00509490 TTaunt::PlayTauntStr
// PDB source: taunt.cpp lines 30-56.
int TTaunt::PlayTauntStr(char* str, unsigned char allow_mute) {
    int taunt_no;

    if (_strnicmp(str, DAT_00576548, strlen(DAT_00576548)) == 0 && allow_mute) {
        this->Mute = 1;
    }

    if (_strnicmp(str, DAT_00576550, strlen(DAT_00576550)) == 0 && allow_mute) {
        this->Mute = 0;
    }

    if (this->Mute) {
        return 0;
    }

    taunt_no = this->GetTauntNo(str);
    if (taunt_no) {
        this->PlayTauntNo(taunt_no);
    }
    return taunt_no;
}

// VA: 00509530 TTaunt::PlayTauntNo
// PDB source: taunt.cpp lines 59-116.
int TTaunt::PlayTauntNo(int num) {
    char FName[128];

    if (this->Mute == 0) {
        if (this->TauntDir != 0) {
            if (num != 0) {
                sprintf(FName, "%sTaunt%.3d.wav", this->TauntDir, num);

                int i;
                for (i = 0; i < 4; i++) {
                    if (this->Audio[i] != 0 && this->Audio[i]->is_playing() == 0) {
                        this->Audio[i]->unload();
                    }
                }

                for (i = 0; i < 4; i++) {
                    if (this->Audio[i] == 0 || this->Audio[i]->is_playing() != 0) {
                        continue;
                    }
                    if (this->Audio[i]->load(FName, -1) != 0)
                        return this->Audio[i]->play();
                    this->Audio[i]->unload();
                    return 0;
                }
                return 0;
            }
        }
    }
    return 0;
}

// VA: 00509610 TTaunt::GetTauntNo
// PDB source: taunt.cpp lines 119-143.
int TTaunt::GetTauntNo(char* text) {
    int value;

    if (*text == '!') {
        text++;
    }
    value = atoi(text);
    if (value == 0) {
        return 0;
    }
    return value & ((value > 999) - 1);
}

// VA: 00509640 TTaunt::GetTauntText
// PDB source: taunt.cpp lines 146-157.
char* TTaunt::GetTauntText(int id) {
    // BINARY NOTE: The executable copies the unnamed "Taunts you!" literal
    // at 0x00588B88. No reviewed shared provider exposes this literal.
    strcpy(this->TBuff, (const char*)0x588B88);
    return this->TBuff;
}

// VA: 00509670 TTaunt::StopSoundSystem
// PDB source: taunt.cpp lines 160-170.
void TTaunt::StopSoundSystem() {
    int i = 4;
    TDigital** audio = this->Audio;

    do {
        TDigital* digital = *audio;
        if (digital != 0) {
            digital->~TDigital();
            operator delete(digital);
            *audio = 0;
        }
        audio = audio + 1;
        i = i - 1;
    } while (i != 0);
}

// VA: 005096A0 TTaunt::RestartSoundSystem
// PDB source: taunt.cpp lines 173-179.
// FLAGS: config/flags/005096A0_RestartSoundSystem.rsp (/GX)
int TTaunt::RestartSoundSystem(TSound_Driver* driver) {
    for (int i = 0; i < 4; i++) {
        this->Audio[i] = new TDigital(driver, "Silence", -1);
    }
    return 1;
}
