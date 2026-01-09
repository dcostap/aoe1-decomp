#pragma once
#include "common.h"

class TChat {
public:
    void* HostWnd;                           // 0x0
    int chatGroupPlayers[10];                // 0x4
    char* Chat[51];                          // 0x2C
    int CurrentMsgNo;                        // 0xF8
    TTaunt* taunt;                           // 0xFC

    TChat(void* param_1);
    ~TChat();
    int AddChatMsg(char* param_1, char* param_2, uchar param_3);
    char* GetChatMsg(int param_1);
    void ClearChat();
    int MaxArraySize();
    void setWindowHandle(void* param_1);
    void setInChatGroup(int param_1, int param_2);
    int inChatGroup(int param_1);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* param_1);
};

static_assert(sizeof(TChat) == 0x100, "TChat Size Mismatch");

