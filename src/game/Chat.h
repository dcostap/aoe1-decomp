#pragma once
#include "../common.h"
#include "taunt.h"
#include "Sounddrv.h"

class TChat {
public:
    int chatGroupPlayers[10];                // 0x4
    char* Chat[51];                          // 0x2C
    int CurrentMsgNo;                        // 0xF8
    TTaunt* taunt;                           // 0xFC

    TChat(void* param_1);
    virtual ~TChat();
    virtual int AddChatMsg(char* param_1, char* param_2, uchar param_3);
    virtual char* GetChatMsg(int param_1);
    virtual void ClearChat();
    virtual int MaxArraySize();
    virtual void setWindowHandle(void* param_1);
    virtual void setInChatGroup(int param_1, int param_2);
    virtual int inChatGroup(int param_1);
    virtual void StopSoundSystem();
    virtual int RestartSoundSystem(TSound_Driver* param_1);
};

static_assert(sizeof(TChat) == 0x100, "TChat Size Mismatch");
static_assert(offsetof(TChat, taunt) == 0xFC, "TChat Offset Mismatch");

