#ifndef AOE1_CHAT_H
#define AOE1_CHAT_H

#include "taunt.h"

#define CHAT_RECEIVED 0x17D5

class TChat {
  public:
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;

    TChat(void* HostWndIn);
    ~TChat();
    int AddChatMsg(char* PlayerName, char* Text, unsigned char Local);
    char* GetChatMsg(int lineno);
    void ClearChat();
    int MaxArraySize();
    void setWindowHandle(void* newHandle);
    void setInChatGroup(int playerNum, int status);
    int inChatGroup(int playerNum);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* driver);
};

typedef char chat_size_check[(sizeof(TChat) == 0x100) ? 1 : -1];

#endif
