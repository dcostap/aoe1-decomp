#pragma once
#include "common.h"

struct TRANSINFO;

class TPicture {
public:
    // Constructors/destructor used by `TPicturePanel::load_pic/free_pic`.
    TPicture(char* filename, long file_id, int use_trans, void* memory, int own_memory);
    TPicture(int handle, int use_trans);
    TPicture();
    ~TPicture();

    void Load(char* param_1, long param_2, int param_3, void* param_4, int param_5);
    void Init(BITMAPINFO256* param_1, uchar* param_2, TRANSINFO* param_3);
    void Save(int param_1);
    void Draw(TDrawArea* area, long x, long y, int p4, int p5);
    long Tile(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9,
              long param_10, long param_11);
    uchar GetPixel(long param_1, long param_2, int param_3, int param_4);
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
