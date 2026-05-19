// VA: 0046E2D0 TPicture::Draw
// Picture.cpp lines 224-241
//
// attempt 1: old scratch had wrong signature/layout; size 144 vs 157.
// fresh 2026-05-19 try 2: local TPicture/TDrawArea layout from packet and natural DibBlt/TransDibBlt calls.

class TDrawArea {
public:
    char gap_00[8];
    void* Bits;          // +0x08
    void* BitmapInfo;    // +0x0C
    char gap_10[0x18];
    char ClipRect;       // +0x28
};

class TPicture {
public:
    char gap_00[4];
    void* BitmapInfo;    // +0x04
    void* Bits;          // +0x08
    void* TransInfo;     // +0x0C
    char gap_10[4];
    int Width;           // +0x14
    int Height;          // +0x18

    void Draw(TDrawArea* draw_area, long x, long y, int dst_x, int dst_y);
};

extern void __cdecl TransDibBlt(void* dst_info, void* dst_bits, void* clip, long x, long y,
    int width, int height, void* src_info, void* src_bits, void* trans_info,
    int sx, int sy, int sw, int sh, int flag, int dst_x, int dst_y, int zero);

extern void __cdecl DibBlt(void* dst_info, void* dst_bits, void* clip, long x, long y,
    int width, int height, void* src_info, void* src_bits,
    int sx, int sy, int sw, int sh, int flag, int dst_x, int dst_y);

void TPicture::Draw(TDrawArea* draw_area, long x, long y, int dst_x, int dst_y)
{
    if (this->TransInfo) {
        TransDibBlt(draw_area->BitmapInfo, draw_area->Bits, &draw_area->ClipRect,
            x, y, this->Width, this->Height, this->BitmapInfo, this->Bits,
            this->TransInfo, 0, 0, this->Width, this->Height, 1, dst_x, dst_y, 0);
    }
    else {
        DibBlt(draw_area->BitmapInfo, draw_area->Bits, &draw_area->ClipRect,
            x, y, this->Width, this->Height, this->BitmapInfo, this->Bits,
            0, 0, this->Width, this->Height, 1, dst_x, dst_y);
    }
}
