#pragma once
#include "common.h"

class TPicture {
public:
    tagBITMAPINFOHEADER* Dib;                // 0x0
    BITMAPINFO256* BitmapInfo;               // 0x4
    uchar* Bits;                             // 0x8
    TRANSINFO* TransInfo;                    // 0xC
    int OwnMemory;                           // 0x10
    long Width;                              // 0x14
    long Height;                             // 0x18
    short Orien;                             // 0x1C

    TPicture(char* param_1, long param_2, int param_3, void* param_4, int param_5);
    TPicture(int param_1, int param_2);
    TPicture();
    ~TPicture();
    void Save(int param_1);
    void Load(char* param_1, long param_2, int param_3, void* param_4, int param_5);
    void Init(BITMAPINFO256* param_1, uchar* param_2, TRANSINFO* param_3);
    long AlignedWidth();
    void Draw(TDrawArea* param_1, long param_2, long param_3, int param_4, int param_5);
    long Tile(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11);
    uchar GetPixel(long param_1, long param_2, int param_3, int param_4);
};

static_assert(sizeof(TPicture) == 0x20, "TPicture Size Mismatch");

