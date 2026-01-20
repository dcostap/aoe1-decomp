#pragma once
#include "common.h"

struct FlicHead {
    long size;
    ushort type;
    short frames;
    short width;
    short height;
    short depth;
    short flags;
    long speed;
    short reserved1;
    long created;
    long creator;
    long updated;
    long updater;
    short aspect_dx;
    short aspect_dy;
    char reserved2[38];
    char* oframe1;
    char* oframe2;
    char reserved3[40];
};
static_assert(sizeof(FlicHead) == 0x84, "Size mismatch");
