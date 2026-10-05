
#include "../include/taunt.h"
#include "../include/sounddrv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);
// These anonymous literals are the !MUTE and !NOMUTE command strings.

void __cdecl operator delete(void* ptr);

TTaunt::TTaunt(TSound_Driver* driver) {
    this->TauntDir[0] = 0;
    RestartSoundSystem(driver);
    this->Mute = 0;
}

TTaunt::~TTaunt() {
    StopSoundSystem();
}

int TTaunt::PlayTauntStr(char* Msg, unsigned char Local) {
    int taunt_no;

    if (_strnicmp(Msg, "!MUTE", strlen("!MUTE")) == 0 && Local) {
        this->Mute = 1;
    }

    if (_strnicmp(Msg, "!NOMUTE", strlen("!NOMUTE")) == 0 && Local) {
        this->Mute = 0;
    }

    if (this->Mute) {
        return 0;
    }

    taunt_no = this->GetTauntNo(Msg);
    if (taunt_no) {
        this->PlayTauntNo(taunt_no);
    }
    return taunt_no;
}

int TTaunt::PlayTauntNo(int TauntNo) {
    char FName[128];

    if (this->Mute == 0) {
        if (this->TauntDir != 0) {
            if (TauntNo != 0) {
                sprintf(FName, "%sTaunt%.3d.wav", this->TauntDir, TauntNo);

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

int TTaunt::GetTauntNo(char* Msg) {
    int value;

    if (*Msg == '!') {
        Msg++;
    }
    value = atoi(Msg);
    if (value == 0) {
        return 0;
    }
    return value & ((value > 999) - 1);
}

char* TTaunt::GetTauntText(int TauntNo) {
    strcpy(this->TBuff, (const char*) 0x588B88);
    return this->TBuff;
}

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

int TTaunt::RestartSoundSystem(TSound_Driver* driver) {
    for (int i = 0; i < 4; i++) {
        this->Audio[i] = new TDigital(driver, "Silence", -1);
    }
    return 1;
}
