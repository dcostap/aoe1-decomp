#pragma once
#include "../common.h"

typedef enum io_state : unsigned int {
    goodbit = 0,
    eofbit = 1,
    failbit = 2,
    badbit = 4,
};

typedef enum open_mode : unsigned int {
    in = 1,
    out = 2,
    ate = 4,
    app = 8,
    trunc = 16,
    nocreate = 32,
    noreplace = 64,
    binary = 128,
};

typedef enum seek_dir : unsigned int {
    beg = 0,
    cur = 1,
    end = 2,
};

class ios {
public:
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
    virtual ~ios();
    virtual void init(streambuf* param_1);
    virtual ios* operator=(ios* param_1);
    virtual int xalloc();
    virtual long bitalloc();
};

static_assert(sizeof(ios) == 0x34, "ios Size Mismatch");
static_assert(offsetof(ios, x_width) == 0x30, "ios Offset Mismatch");

