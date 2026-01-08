#pragma once
#include "../common.h"

class istream : public ios       {
public:
    int _fGline;                             // 0x4
    int x_gcount;                            // 0x8
    char _pad_0xC[0x34];

    istream();
    istream(streambuf* param_1);
    istream(istream* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~istream() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // --- Non-Virtual Members ---
    istream* get(char* param_1, int param_2, int param_3);
    istream* operator=(streambuf* param_1);
    int ipfx(int param_1);
    istream* operator>>(char* param_1);
    int peek();
    istream* putback(char param_1);
    int sync();
    void eatwhite();
};

static_assert(sizeof(istream) == 0x40, "istream Size Mismatch");

