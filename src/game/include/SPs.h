#pragma once
#include "common.h"

struct SPs {
    char Name[80];
    _GUID* GUID;
    ulong MajVersion;
    ulong MinVersion;
    int Active;
};
static_assert(sizeof(SPs) == 0x60, "Size mismatch");
