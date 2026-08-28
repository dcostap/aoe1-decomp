#ifndef AOE1_PICTURE_H
#define AOE1_PICTURE_H

#include "drawarea.h"

struct LINEINFO {
    int AllTrans;
    int MidSolid;
    long StartX;
    long EndX;
};

typedef char picture_line_info_size_check[(sizeof(LINEINFO) == 0x10) ? 1 : -1];

struct TRANSINFO {
    int AnyTrans;
    long x;
    long y;
    long w;
    long h;
    LINEINFO* LineInfo;
};

typedef char picture_trans_info_size_check[(sizeof(TRANSINFO) == 0x18) ? 1 : -1];

class TPicture {
public:
    tagBITMAPINFOHEADER* Dib;
    BITMAPINFO256* BitmapInfo;
    unsigned char* Bits;
    TRANSINFO* TransInfo;
    int OwnMemory;
    int Width;
    int Height;
    short Orien;

    TPicture(char* file_name, long resource_id, int palette_id,
        void* palette, int palette_flags);
    TPicture(int file_handle, int param_2);
    TPicture();
    ~TPicture();

    void Save(int fd);
    void Load(char* file_name, long resource_id, int palette_id,
        void* palette, int palette_flags);
    void Init(BITMAPINFO256* info, unsigned char* bits, TRANSINFO* trans);
    long AlignedWidth();
    void Draw(TDrawArea* draw_area, long x, long y, int dst_x, int dst_y);
    long Tile(TDrawArea* draw_area, long param_2, long param_3, long param_4,
        long param_5, long param_6, long param_7, long param_8, long param_9,
        long param_10, long param_11);
    unsigned char GetPixel(long x, long y, int param_3, int param_4);
};

typedef char picture_size_check[(sizeof(TPicture) == 0x20) ? 1 : -1];

#endif
