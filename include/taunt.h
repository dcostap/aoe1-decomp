#ifndef AOE1_TAUNT_H
#define AOE1_TAUNT_H

class TSound_Driver;
class TDigital;

class TTaunt {
public:
    TDigital* Audio[4];
    int LastAudioPlayed;
    char TBuff[255];
    char TauntDir[128];
    unsigned char _pad_193;
    int Mute;

    TTaunt(TSound_Driver* sound_driver);
    ~TTaunt();
    int PlayTauntStr(char* str, unsigned char allow_mute);
    int PlayTauntNo(int num);
    int GetTauntNo(char* text);
    char* GetTauntText(int id);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* driver);
};

typedef char taunt_size_check[(sizeof(TTaunt) == 0x198) ? 1 : -1];

#endif
