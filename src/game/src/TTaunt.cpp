#include "../include/TTaunt.h"
#include "../include/TDigital.h"
#include "../include/TSound_Driver.h"

#include <stdlib.h>
#include <string.h>
#include <new>

TTaunt::TTaunt(TSound_Driver* param_1) {
    // Fully verified. Source of truth: taunt.cpp.decomp @ 0x00509450
    this->TauntDir[0] = '\0';
    this->RestartSoundSystem(param_1);
    this->Mute = 0;
}

TTaunt::~TTaunt() {
    // Fully verified. Source of truth: taunt.cpp.decomp @ 0x00509480
    for (int i = 0; i < 4; ++i) {
        if (this->Audio[i] != nullptr) {
            delete this->Audio[i];
            this->Audio[i] = nullptr;
        }
    }
}

int TTaunt::PlayTauntStr(char* param_1, uchar param_2) {
    // Fully verified. Source of truth: taunt.cpp.decomp @ 0x00509490
    if (_strnicmp(param_1, "!MUTE", 5) == 0 && param_2 != '\0') {
        this->Mute = 1;
    }
    if (_strnicmp(param_1, "!NOMUTE", 7) == 0 && param_2 != '\0') {
        this->Mute = 0;
    }

    if (this->Mute != 0) {
        return 0;
    }

    int tauntNo = this->GetTauntNo(param_1);
    if (tauntNo != 0) {
        this->PlayTauntNo(tauntNo);
    }
    return tauntNo;
}

int TTaunt::PlayTauntNo(int param_1) {
    // Fully verified. Source of truth: taunt.cpp.decomp @ 0x00509530
    char FName[128];

    if (this->Mute != 0) {
        return 0;
    }
    if (param_1 == 0) {
        return 0;
    }

    sprintf(FName + 4, "%sTaunt%03d.wav", this->TauntDir, param_1);

    for (int i = 0; i < 4; ++i) {
        if (this->Audio[i] != nullptr && this->Audio[i]->is_playing() == 0) {
            this->Audio[i]->unload();
        }
    }

    int slot = 0;
    while (slot < 4) {
        if (this->Audio[slot] != nullptr && this->Audio[slot]->is_playing() == 0) {
            break;
        }
        ++slot;
    }
    if (slot > 3) {
        return 0;
    }

    if (this->Audio[slot]->load(FName + 4, -1) == 0) {
        this->Audio[slot]->unload();
        return 0;
    }

    return this->Audio[slot]->play();
}

int TTaunt::GetTauntNo(char* param_1) {
    // Fully verified. Source of truth: taunt.cpp.decomp @ 0x00509610
    if (*param_1 == '!') {
        param_1 += 1;
    }

    const uint taunt = (uint)atoi(param_1);
    if (taunt == 0) {
        return 0;
    }

    // Clamp to <= 999 (matches uVar1 & (999 < uVar1) - 1 idiom).
    if ((int)taunt > 999) {
        return 0;
    }
    return (int)taunt;
}

char* TTaunt::GetTauntText(int param_1) {
    // Fully verified. Source of truth: taunt.cpp.decomp @ 0x00509640
    (void)param_1;
    strcpy(this->TBuff, "Taunts you!");
    return this->TBuff;
}

void TTaunt::StopSoundSystem() {
    // Fully verified. Source of truth: taunt.cpp.decomp @ 0x00509670
    for (int i = 0; i < 4; ++i) {
        if (this->Audio[i] != nullptr) {
            delete this->Audio[i];
            this->Audio[i] = nullptr;
        }
    }
}

int TTaunt::RestartSoundSystem(TSound_Driver* param_1) {
    // Fully verified. Source of truth: taunt.cpp.decomp @ 0x005096A0
    for (int i = 0; i < 4; ++i) {
        this->Audio[i] = new (std::nothrow) TDigital(param_1, (char*)"Silence", -1);
    }
    return 1;
}

