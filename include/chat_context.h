#ifndef AOE1_CHAT_CONTEXT_H
#define AOE1_CHAT_CONTEXT_H

class SoundDriver;
class TDigital;
class TSound_Driver;

class TTaunt {
public:
    TDigital* Audio[4];
    int LastAudioPlayed;
    char TBuff[255];
    char TauntDir[128];
    unsigned char gap_193;
    int Mute;

    TTaunt(SoundDriver* sound_driver);
    ~TTaunt();
    int PlayTauntStr(char* text, unsigned char taunt_id);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* sound_driver);
};

class RGE_Base_Game {
public:
    unsigned char gap_00[0x60];
    SoundDriver* sound_system;
};

extern RGE_Base_Game* rge_base_game;

class TChat {
public:
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;

    TChat(void* host_wnd);
    ~TChat();
    int AddChatMsg(char* speaker, char* text, unsigned char taunt_id);
    char* GetChatMsg(int index);
    void ClearChat();
    int MaxArraySize();
    void setWindowHandle(void* v);
    void setInChatGroup(int index, int value);
    int inChatGroup(int index);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* sound_driver);
};

typedef char chat_context_size_check[(sizeof(TChat) == 0x100) ? 1 : -1];

#endif
