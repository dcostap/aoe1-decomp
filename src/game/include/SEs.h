#pragma once
#include "common.h"

struct SEs {
    char Name[255];
    char Password[255];
    _GUID AppGUID;
    _GUID SessGUID;
    ulong CurrentPlayers;
    ulong MaxPlayers;
    ulong User1;
    ulong User2;
    ulong User3;
    ulong User4;
};
static_assert(sizeof(SEs) == 0x238, "Size mismatch");
