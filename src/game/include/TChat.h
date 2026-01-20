#pragma once
#include "common.h"

struct TChat {
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;
};
static_assert(sizeof(TChat) == 0x100, "Size mismatch");
