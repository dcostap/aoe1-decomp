#pragma once
#include "../common.h"

class streambuf       {
public:
    char _pad_0x0[0x4];
    int _fAlloc;                             // 0x4
    int _fUnbuf;                             // 0x8
    int x_lastc;                             // 0xC
    char* _base;                             // 0x10
    char* _ebuf;                             // 0x14
    char* _pbase;                            // 0x18
    char* _pptr;                             // 0x1C
    char* _epptr;                            // 0x20
    char* _eback;                            // 0x24
    char* _gptr;                             // 0x28
    char* _egptr;                            // 0x2C


    // --- Non-Virtual Members ---
    int snextc();
    int sbumpc();
    void stossc();
    int sgetc();
};

static_assert(sizeof(streambuf) == 0x30, "streambuf Size Mismatch");
static_assert(offsetof(streambuf, _egptr) == 0x2C, "streambuf Offset Mismatch");

