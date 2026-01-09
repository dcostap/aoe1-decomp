#pragma once
#include "common.h"

enum io_state : unsigned int {
    goodbit = 0,
    eofbit = 1,
    failbit = 2,
    badbit = 4,
};

enum open_mode : unsigned int {
    in = 1,
    out = 2,
    ate = 4,
    app = 8,
    trunc = 16,
    nocreate = 32,
    noreplace = 64,
    binary = 128,
};

enum seek_dir : unsigned int {
    beg = 0,
    cur = 1,
    end = 2,
};

class ios {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    streambuf* bp;                           // 0x4
    int state;                               // 0x8
    int ispecial;                            // 0xC
    int ospecial;                            // 0x10
    int isfx_special;                        // 0x14
    int osfx_special;                        // 0x18
    int x_delbuf;                            // 0x1C
    ostream* x_tie;                          // 0x20
    long x_flags;                            // 0x24
    int x_precision;                         // 0x28
    char x_fill;                             // 0x2C
    int x_width;                             // 0x30

    ios();
    ios(streambuf* param_1);
    ios(ios* param_1);
    ~ios();
    void init(streambuf* param_1);
    ios* operator=(ios* param_1);
    int xalloc();
    long bitalloc();
};

static_assert(sizeof(ios) == 0x34, "ios Size Mismatch");

class istream : public ios {
public:
    char _pad_0x34[0xC];

    istream* get(char* param_1, int param_2, int param_3);
    istream();
    istream(streambuf* param_1);
    istream(istream* param_1);
    ~istream();
    istream* operator=(streambuf* param_1);
    int ipfx(int param_1);
    istream* operator>>(char* param_1);
    int peek();
    istream* putback(char param_1);
    int sync();
    void eatwhite();
};

static_assert(sizeof(istream) == 0x40, "istream Size Mismatch");

class istream_withassign {
public:

    istream_withassign();
    istream_withassign(streambuf* param_1);
    ~istream_withassign();
};

static_assert(sizeof(istream_withassign) == 0x1, "istream_withassign Size Mismatch");

class ostream : public ios {
public:
    char _pad_0x34[0x8];

    int opfx();
    void osfx();
    ostream* operator<<(char* param_1);
    ostream* flush();
    ostream();
    ostream(streambuf* param_1);
    ostream(ostream* param_1);
    ~ostream();
    ostream* operator=(streambuf* param_1);
    ostream* writepad(char* param_1, char* param_2);
    ostream* operator<<(int param_1);
    ostream* operator<<(double param_1);
};

static_assert(sizeof(ostream) == 0x3C, "ostream Size Mismatch");

class ostream_withassign {
public:

    ostream_withassign();
    ostream_withassign(streambuf* param_1);
    ~ostream_withassign();
};

static_assert(sizeof(ostream_withassign) == 0x1, "ostream_withassign Size Mismatch");

class streambuf {
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

    int snextc();
    int sbumpc();
    void stossc();
    int sgetc();
};

static_assert(sizeof(streambuf) == 0x30, "streambuf Size Mismatch");

class type_info {
public:

    ~type_info();
    int operator==(type_info* param_1);
    int operator!=(type_info* param_1);
    int before(type_info* param_1);
    char* raw_name();
    type_info(type_info* param_1);
    type_info* operator=(type_info* param_1);
};

static_assert(sizeof(type_info) == 0x1, "type_info Size Mismatch");

