#ifndef AOE1_CHAT_CONTEXT_H
class SoundDriver;
class TDigital;

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
    void setInChatGroup(int player, int enabled);
};
#endif

TChat::TChat(void* host_wnd) {
    int i;

    taunt = new TTaunt(rge_base_game->sound_system);
    HostWnd = host_wnd;

    for (i = 0; i < 0x33; ++i) {
        Chat[i] = 0;
    }

    CurrentMsgNo = 0;

    for (i = 0; i <= 9; ++i) {
        setInChatGroup(i, 0);
    }
}
