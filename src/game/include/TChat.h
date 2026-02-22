#pragma once
#include "common.h"

class TTaunt;

#pragma pack(push, 1)
struct TChat {
    TChat(void* p1);
    ~TChat();
    int AddChatMsg(char* param_1, char* param_2, uchar param_3);
    char* GetChatMsg(int param_1);
    void ClearChat();
    int MaxArraySize();
    void setWindowHandle(void* p1);
    void setInChatGroup(int param_1, int param_2);
    int inChatGroup(int param_1);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* param_1);
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;
};
#pragma pack(pop)
static_assert(sizeof(TChat) == 0x100, "Size mismatch");
