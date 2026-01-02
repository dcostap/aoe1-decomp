#pragma once
#include "../common.h"

class ostream : public ios {
public:
    char _pad_0x34[0x8];

    virtual int opfx();
    virtual void osfx();
    virtual ostream* operator<<(char* param_1);
    virtual ostream* flush();
    ostream();
    ostream(streambuf* param_1);
    ostream(ostream* param_1);
    virtual ~ostream();
    virtual ostream* operator=(streambuf* param_1);
    virtual ostream* writepad(char* param_1, char* param_2);
    virtual ostream* operator<<(int param_1);
    virtual ostream* operator<<(double param_1);
};

static_assert(sizeof(ostream) == 0x3C, "ostream Size Mismatch");

