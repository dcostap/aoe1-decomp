#pragma once
#include "common.h"

struct streambuf {
    int padding;
    int fAlloc;
    int fUnbuf;
    int x_lastc;
    char* base;
    char* ebuf;
    char* pbase;
    char* pptr;
    char* epptr;
    char* eback;
    char* gptr;
    char* egptr;
};
static_assert(sizeof(streambuf) == 0x30, "Size mismatch");
