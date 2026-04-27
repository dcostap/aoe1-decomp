// VA: 0046E0B0 TPicture::Load
// Picture.cpp lines 126-197

// attempt 1: load picture from file
// 438 bytes

#include <stdio.h>

class TRANSINFO;

class TPicture {
public:
    void* Dib;              // +0x00
    void* BitmapInfo;       // +0x04
    unsigned char* Bits;    // +0x08
    TRANSINFO* TransInfo;   // +0x0C
    int OwnMemory;          // +0x10
    int width;              // +0x14
    int height;             // +0x18
    short bpp;              // +0x1C

    TPicture();
    void Save(void* file);
    void Load(void* file);
    void Draw(int x, int y, int w, int h, int sx, int sy, void* dst);
    int GetPixel(int x, int y);
};

int __cdecl fread_compat(void* ptr, int size, int count, void* stream);
void* __cdecl operator_new(unsigned int size);

int pixel_size(int bpp);

void TPicture::Load(void* file) {
    fread_compat(&OwnMemory, 4, 1, file);
    fread_compat(&width, 4, 1, file);
    fread_compat(&height, 4, 1, file);
    fread_compat(&bpp, 2, 1, file);
    
    if (OwnMemory == 0) {
        OwnMemory = 2;
    }
    
    if (width > 0 && height > 0) {
        int dib_size = pixel_size(bpp) * height + 0x428;
        Dib = operator_new(dib_size);
        fread_compat(Dib, dib_size, 1, file);
        BitmapInfo = Dib;
        Bits = (unsigned char*)Dib + 0x428;
    } else {
        Dib = 0;
        BitmapInfo = 0;
        Bits = 0;
    }
    TransInfo = 0;
}
