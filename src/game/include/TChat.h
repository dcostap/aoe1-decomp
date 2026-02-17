#pragma once
#include "common.h"

class TTaunt;

#pragma pack(push, 1)
struct TChat {
    TChat(void* p1);
    void ClearChat();
    void setInChatGroup(int param_1, int param_2);
    int inChatGroup(int param_1);
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;
};
#pragma pack(pop)
static_assert(sizeof(TChat) == 0x100, "Size mismatch");
