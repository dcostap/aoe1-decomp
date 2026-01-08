#pragma once
#include "../common.h"

class ostream : public ios       {
public:
    int x_floatused;                         // 0x4
    char _pad_0x8[0x34];

    ostream();
    ostream(streambuf* param_1);
    ostream(ostream* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~ostream() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // --- Non-Virtual Members ---
    int opfx();
    void osfx();
    ostream* operator<<(char* param_1);
    ostream* flush();
    ostream* operator=(streambuf* param_1);
    ostream* writepad(char* param_1, char* param_2);
    ostream* operator<<(int param_1);
    ostream* operator<<(double param_1);
};

static_assert(sizeof(ostream) == 0x3C, "ostream Size Mismatch");

