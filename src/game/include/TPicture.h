#pragma once
#include "common.h"

struct TRANSINFO;

struct TPicture {
    // Constructors/destructor used by `TPicturePanel::load_pic/free_pic`.
    TPicture(char* filename, long file_id, int use_trans, void* memory, int own_memory);
    TPicture(int width, int height);
    TPicture();
    ~TPicture();

    void Save(int param_1);
    void Draw(TDrawArea* area, long x, long y, int p4, int p5);
    long AlignedWidth();

    tagBITMAPINFOHEADER* Dib;
    BITMAPINFO256* BitmapInfo;
    uchar* Bits;
    TRANSINFO* TransInfo;
    int OwnMemory;
    long Width;
    long Height;
    short Orien;
};
static_assert(sizeof(TPicture) == 0x20, "Size mismatch");
