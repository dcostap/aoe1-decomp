#ifndef PICTURE_CONTEXT_H
#define PICTURE_CONTEXT_H

// Authentic Picture.cpp type surface shared by the owner bodies.  The
// individual recovery files keep their stand-alone declarations when this
// header is not present.
class TRANSINFO;
class LINEINFO;
class TPicture;
struct BITMAPINFO256;

void __cdecl rge_read(int file_handle, void* buffer, int size);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __cdecl DibFree(void* dib);
void __cdecl DibCheckTrans(BITMAPINFO256* dib, TRANSINFO* info,
    unsigned char* bits);

struct tagBITMAPINFOHEADER {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
};

struct tagRGBQUAD {
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

struct BITMAPINFO256 {
    tagBITMAPINFOHEADER bmiHeader;
    tagRGBQUAD bmiColors[256];
};

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

class TPicture {
public:
    void* Dib;
    void* BitmapInfo;
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
    int AlignedWidth();
    void Draw(TDrawArea* draw_area, long x, long y, int dst_x, int dst_y);
    long Tile(TDrawArea* draw_area, long param_2, long param_3, long param_4,
        long param_5, long param_6, long param_7, long param_8, long param_9,
        long param_10, long param_11);
    unsigned char GetPixel(long x, long y, int param_3, int param_4);
};

#endif
