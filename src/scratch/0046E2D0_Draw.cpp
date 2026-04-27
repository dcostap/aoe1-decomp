// VA: 0046E2D0 TPicture::Draw
// Picture.cpp lines 224-241

// attempt 1: draw with pixel data (blit) or solid fill
// 157 bytes, ret 14h

#include <string.h>

class TPicture {
public:
    char gap_00[4];
    int width;              // +0x04
    int height;             // +0x08
    int bpp;                // +0x0C  (actually pixel_data ptr?)
    char gap_10[0x10];
    // re-evaluate layout based on the original
    
    char gap_00x[4];
    int var_04;             // +0x04
    int var_08;             // +0x08
    void* pixel_data;       // +0x0C
    int field_10;           // +0x10 (width2?)
    int field_14;           // +0x14 (height2?)
    int field_18;           // +0x18 (bpp2?)
    int palette_size;       // +0x1C
    char gap_20[8];         // +0x20 palette
    int data_size;          // +0x28
    void* data;             // +0x2C

    TPicture();
    void Save(void* file);
    void Load(void* file);
    void Draw(int x, int y, int w, int h, int sx, int sy, void* dst);
    int GetPixel(int x, int y);
};

void __cdecl draw_blit_or_fill(int x, int y, int w, int h, int sx, int sy,
    void* data, int bpp, int width, int height, void* palette,
    void* dst, void* dst_info);

void TPicture::Draw(int x, int y, int w, int h, int sx, int sy, void* dst) {
    if (pixel_data != 0) {
        // Blit from pixel data
        draw_blit_or_fill(x, y, w, h, sx, sy, 
            pixel_data, bpp, width, height,
            0, dst, (char*)dst + 0x28);
    } else {
        // Solid fill
        draw_blit_or_fill(x, y, w, h, sx, sy,
            data, field_14, field_18, field_10,
            0, dst, (char*)dst + 0x28);
    }
}
