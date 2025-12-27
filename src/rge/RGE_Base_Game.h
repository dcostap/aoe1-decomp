#pragma once
#include "RGE_Prog_Info.h"

// The base class occupies the first 0xA24 bytes of the TRIBE_Game structure
class RGE_Base_Game {
public:
    // Virtual table alignment
    virtual ~RGE_Base_Game() {}                                        // [0]
    virtual int get_error_code() { return 0; }                         // [1]
    virtual void stub_2() {}                                           // [2]
    virtual void stub_3() {}                                           // [3]
    virtual void stub_4() {}                                           // [4]
    virtual void stub_5() {}                                           // [5]
    virtual int run() { return 0; }                                    // [6]
    virtual void stub_7() {}                                           // [7]
    virtual void show_error(int id, char* buf, int s) {}               // [8]
    virtual void stub_9() {}                                           // [9]
    virtual void fatal_exit(int a, int b, int c, char* d, int e) {}    // [10]

    // Base engine members (Total size: 0xA20 excluding VTable)
    /* 0x0004 */ uchar _rge_data[0xA20];

    RGE_Base_Game(RGE_Prog_Info* info, int setup) {}
};