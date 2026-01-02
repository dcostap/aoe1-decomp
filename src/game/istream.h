#pragma once
#include "../common.h"

class istream : public ios {
public:
    char _pad_0x34[0xC];

    virtual istream* get(char* param_1, int param_2, int param_3);
    istream();
    istream(streambuf* param_1);
    istream(istream* param_1);
    virtual ~istream();
    virtual istream* operator=(streambuf* param_1);
    virtual int ipfx(int param_1);
    virtual istream* operator>>(char* param_1);
    virtual int peek();
    virtual istream* putback(char param_1);
    virtual int sync();
    virtual void eatwhite();
};

static_assert(sizeof(istream) == 0x40, "istream Size Mismatch");

