// VA: 0046E3E0 TPicture::GetPixel
// Picture.cpp lines 256-286

// attempt 1: get pixel at (x, y), return color
// 204 bytes

class TPicture {
public:
    char gap_00[4];
    int width;              // +0x04
    int height;             // +0x08
    char* pixel_data;       // +0x0C
    int field_10;
    int field_14;
    int field_18;
    int palette_size;       // +0x1C
    void* palette;          // +0x20 or similar
    int data_size;          // +0x28
    void* data;             // +0x2C

    TPicture();
    void Save(void* file);
    void Load(void* file);
    void Draw(int x, int y, int w, int h, int sx, int sy, void* dst);
    int GetPixel(int x, int y);
};

int TPicture::GetPixel(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) return 0;
    if (pixel_data == 0) return 0;
    
    // Calculate pixel offset based on bpp (bits per pixel)
    int bpp = field_18;
    int bytes_per_pixel = (bpp == 8) ? 1 : ((bpp == 16) ? 2 : 4);
    int offset = (y * field_14 + x) * bytes_per_pixel;
    
    // Read pixel value
    if (bpp == 8) {
        return (unsigned char)pixel_data[offset];
    } else if (bpp == 15 || bpp == 16) {
        return *(unsigned short*)(pixel_data + offset);
    } else {
        return *(unsigned int*)(pixel_data + offset);
    }
}
