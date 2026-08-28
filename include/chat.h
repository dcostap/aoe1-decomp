#ifndef AOE1_CHAT_H
#define AOE1_CHAT_H

#include "taunt.h"

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
    void setWindowHandle(void* value);
    void setInChatGroup(int index, int value);
    int inChatGroup(int index);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* sound_driver);
};

typedef char chat_size_check[(sizeof(TChat) == 0x100) ? 1 : -1];

#endif
