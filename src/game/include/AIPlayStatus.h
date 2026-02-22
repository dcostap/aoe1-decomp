#pragma once
#include "common.h"

// Minimal AIPlayStatus representation (fixed-size save/load blob).
// Used by UnitAIModule::load/save to keep saved-game streams aligned.
struct AIPlayStatus {
    unsigned char bytes[0x1C8];

    AIPlayStatus();
    void load(int fd);
    void save(int fd);
};
static_assert(sizeof(AIPlayStatus) == 0x1C8, "Size mismatch");

