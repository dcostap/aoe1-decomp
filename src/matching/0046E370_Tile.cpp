// first pass: wrapper around TileDibBlt; the main basin is the push order and cdecl cleanup
// trans flag is the this->TransInfo non-null test, with two trailing zero args preserved
#ifndef PICTURE_CONTEXT_H
class TDrawArea;
class BITMAPINFO256;
#endif

extern "C" long __cdecl TileDibBlt(
    BITMAPINFO256* bitmapInfo,
    unsigned char* bits,
    void* clipRect,
    long param_2,
    long param_3,
    long param_4,
    long param_5,
    long param_6,
    long param_7,
    BITMAPINFO256* thisBitmapInfo,
    unsigned char* thisBits,
    void* transInfo,
    long param_8,
    long param_9,
    long param_10,
    long param_11,
    int hasTrans,
    int zero1,
    int zero2);

#ifndef PICTURE_CONTEXT_H
class TPicture {
public:
    void* Dib;
    BITMAPINFO256* BitmapInfo;
    unsigned char* Bits;
    void* TransInfo;

    long Tile(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11);
};
#endif

#ifndef PICTURE_CONTEXT_H
class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    BITMAPINFO256* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    char ClipRect[0x10];
};
#endif

long TPicture::Tile(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TileDibBlt(param_1->BitmapInfo, param_1->Bits, &param_1->ClipRect, param_2, param_3, param_4, param_5, param_6, param_7, (BITMAPINFO256*)this->BitmapInfo, this->Bits, this->TransInfo, param_8, param_9, param_10, param_11, (this->TransInfo != 0), 0, 0);
}
