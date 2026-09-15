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

    TTaunt(TSound_Driver* driver);
    ~TTaunt();
    int PlayTauntStr(char* Msg, unsigned char Local);
    int PlayTauntNo(int TauntNo);
    int GetTauntNo(char* Msg);
    char* GetTauntText(int TauntNo);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* driver);
};

typedef char taunt_size_check[(sizeof(TTaunt) == 0x198) ? 1 : -1];

#endif
