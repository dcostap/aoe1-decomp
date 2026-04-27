// VA: 004463B0 TDrawArea::take_snapshot (540 B)
// PDB source: Drawarea.cpp
// Packet-grounded: build BMP header, convert pixel data to BGR, write to file

extern int RGE_write_file(const char* filename, void* data, int size);

extern void* operator_new(unsigned int size);
extern void operator_delete(void* p);
extern void* memset(void* s, int c, int n);
extern int strcpy(char* dst, const char* src);
extern int sprintf(char* buf, const char* fmt, ...);

struct Shim_take_snapshot_63B0 {
    char gap00[0x08];
    unsigned char* Bits;       // +0x08
    char gap0C[0x18 - 0x0C];
    int Width;                 // +0x18
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24
};

void TDrawArea_take_snapshot(Shim_take_snapshot_63B0* self, const char* filename)
{
    // Build 24-bit BMP from surface data
    int w = self->Width;
    int h = self->Height;
    
    // Row stride: aligned to 4 bytes, each pixel is 3 bytes (RGB)
    int rowSize = (w * 3 + 3) & ~3;
    int totalPixelData = rowSize * h;
    
    // BMP header: BITMAPFILEHEADER (14) + BITMAPINFOHEADER (40) + palette? + pixel data
    // Actually build full BMP with:
    // - BITMAPFILEHEADER: starts with 'BM', size including header, offset to pixel data
    // - BITMAPINFOHEADER: 40 bytes, width, height, 1 plane, 24 bpp, etc.
    // - Pixel data: BGR triplets, bottom-up rows
    
    int dataSize = 14 + 40 + totalPixelData;
    
    // Allocate buffer
    unsigned char* buf = (unsigned char*)operator_new(dataSize);
    if (!buf) return;
    
    memset(buf, 0, dataSize);
    
    // BITMAPFILEHEADER at offset 0
    buf[0] = 'B'; buf[1] = 'M';
    *(int*)(buf + 2) = dataSize;          // File size
    *(short*)(buf + 6) = 0;               // Reserved
    *(short*)(buf + 8) = 0;               // Reserved
    *(int*)(buf + 10) = 14 + 40;          // Offset to pixel data
    
    // BITMAPINFOHEADER at offset 14
    *(int*)(buf + 14) = 40;               // Header size
    *(int*)(buf + 18) = w;                // Width
    *(int*)(buf + 22) = h;                // Height (positive = bottom-up)
    *(short*)(buf + 26) = 1;              // Planes
    *(short*)(buf + 28) = 24;             // Bits per pixel
    *(int*)(buf + 30) = 0;                // Compression (BI_RGB)
    *(int*)(buf + 34) = totalPixelData;   // Image size
    *(int*)(buf + 38) = 0;                // X pixels per meter
    *(int*)(buf + 42) = 0;                // Y pixels per meter
    *(int*)(buf + 46) = 0;                // Colors used
    *(int*)(buf + 50) = 0;                // Important colors
    
    // Convert pixel data from surface format to BGR
    unsigned char* pixelDest = buf + 54;
    if (self->Orien == 1) {
        // Top-down surface: reverse row order for BMP (which is bottom-up)
        for (int y = 0; y < h; y++) {
            unsigned char* srcRow = self->Bits + (h - 1 - y) * self->Pitch;
            unsigned char* dstRow = pixelDest + y * rowSize;
            for (int x = 0; x < w; x++) {
                dstRow[x * 3 + 0] = srcRow[x * 3 + 2];  // B
                dstRow[x * 3 + 1] = srcRow[x * 3 + 1];  // G
                dstRow[x * 3 + 2] = srcRow[x * 3 + 0];  // R
            }
        }
    } else {
        // Bottom-up surface: copy directly
        for (int y = 0; y < h; y++) {
            unsigned char* srcRow = self->Bits + y * self->Pitch;
            unsigned char* dstRow = pixelDest + y * rowSize;
            for (int x = 0; x < w; x++) {
                dstRow[x * 3 + 0] = srcRow[x * 3 + 2];  // B
                dstRow[x * 3 + 1] = srcRow[x * 3 + 1];  // G
                dstRow[x * 3 + 2] = srcRow[x * 3 + 0];  // R
            }
        }
    }
    
    // Write to file
    RGE_write_file(filename, buf, dataSize);
    
    // Cleanup
    operator_delete(buf);
}
