// VA: 0046E020 TPicture::Save
// Picture.cpp lines 112-123

// attempt 1: sequential fwrite of fields + pixel data
// 132 bytes

#include <stdio.h>

class TPicture {
public:
    char gap_00[0x10];
    int width;              // +0x10
    int height;             // +0x14
    int bpp;                // +0x18
    int palette_size;       // +0x1C
    char gap_20[8];         // +0x20 (palette data area)
    int data_size;          // +0x28
    void* data;             // +0x2C

    TPicture();
    void Save(void* file);
    void Load(void* file);
    void Draw(int x, int y, int w, int h, int sx, int sy, void* dst);
    int GetPixel(int x, int y);
};

// fwrite function (signature)
int __cdecl fwrite_compat(const void* ptr, int size, int count, void* stream);

void TPicture::Save(void* file) {
    fwrite_compat(&width, 4, 1, file);
    fwrite_compat(&height, 4, 1, file);
    fwrite_compat(&bpp, 4, 1, file);
    fwrite_compat(&palette_size, 4, 1, file);
    
    // Write palette data (palette_size bytes at +0x20)
    fwrite_compat((char*)this + 0x20, palette_size, 1, file);
    
    // Write data_size
    fwrite_compat(&data_size, 4, 1, file);
    
    // Write pixel data (data_size bytes)
    fwrite_compat(data, data_size, 1, file);
}
