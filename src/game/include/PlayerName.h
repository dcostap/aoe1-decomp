#pragma once
#include "common.h"

struct PlayerName {
    char Name[256];
};
static_assert(sizeof(PlayerName) == 0x100, "Size mismatch");
