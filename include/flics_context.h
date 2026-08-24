#ifndef AOE1_FLICS_CONTEXT_H
#define AOE1_FLICS_CONTEXT_H

// Canonical compiler-facing context for C:\\msdev\\work\\age1_x1\\flics.cpp.
// Owner files keep narrow standalone declarations for focused checks.  The
// authentic module wrapper defines FLICS_SHARED_CONTEXT before including them.

extern "C" int __cdecl open(const char* path, int access);
extern "C" int __cdecl lseek(int handle, long offset, int origin);
extern "C" int __cdecl tell(int handle);
extern "C" int __cdecl read(int handle, void* buffer, unsigned int size);
extern "C" int __cdecl close(int handle);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);

struct FlicHead {
    long size;                  // +0x00
    unsigned short type;        // +0x04
    short frames;               // +0x06
    short width;                // +0x08
    short height;               // +0x0A
    short depth;                // +0x0C
    short flags;                // +0x0E
    long speed;                 // +0x10
    short reserved1;            // +0x14
    unsigned char pad_16[2];    // +0x16
    long created;               // +0x18
    long creator;               // +0x1C
    long updated;               // +0x20
    long updater;               // +0x24
    short aspect_dx;            // +0x28
    short aspect_dy;            // +0x2A
    char reserved2[38];         // +0x2C
    unsigned char pad_52[2];    // +0x52
    char* oframe1;              // +0x54
    char* oframe2;              // +0x58
    char reserved3[40];         // +0x5C, through +0x83
};

typedef char flic_head_size_check[(sizeof(FlicHead) == 0x84) ? 1 : -1];

struct FrameHead {
    long size;                  // +0x00
    short type;                 // +0x04
    short chunks;               // +0x06
    char reserved[8];           // +0x08
};

typedef char frame_head_size_check[(sizeof(FrameHead) == 0x10) ? 1 : -1];

struct tagRGBQUAD {
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

struct PalettePacket {
    signed char skip;
    signed char count;
};

class TDrawArea {
public:
    void* DrawSystem;            // +0x00
    void* Wnd;                   // +0x04
    unsigned char* Bits;         // +0x08
    void* BitmapInfo;            // +0x0C
    void* Bitmap;                // +0x10
    void* OldBitmap;             // +0x14
    long Width;                  // +0x18
    long Height;                 // +0x1C
    long Pitch;                  // +0x20
    long Orien;                  // +0x24
    char gap_28[0xD8];           // +0x28

    long AlignedWidth();
};

typedef char draw_area_size_check[(sizeof(TDrawArea) == 0x100) ? 1 : -1];

class RGE_Flic_Player {
private:
    unsigned char* flic_buffer;  // +0x00
    int flic_handle;             // +0x04
    FlicHead flichead;           // +0x08
    TDrawArea* drawarea;          // +0x8C
    long drawarea_width;          // +0x90
    long flic_width;              // +0x94
    unsigned char* window_buffer; // +0x98
    unsigned char* save_buffer;  // +0x9C
    char* chunk;                  // +0xA0
    long x1;                      // +0xA4
    long y1;                      // +0xA8
    long x2;                      // +0xAC
    long y2;                      // +0xB0
    long flic_size_x;             // +0xB4
    long flic_size_y;             // +0xB8

    void literal();
    void delta_flc();
    void delta_fli();
    void black();
    void byte_run();

public:
    RGE_Flic_Player(char* path);
    RGE_Flic_Player(int file_handle);
    ~RGE_Flic_Player();

    void palette(tagRGBQUAD* palette);
    long resolution();
    long time_delay();
    short frames();
    void start();
    void reset();
    unsigned char draw(TDrawArea* drawarea_in, long flic_x, long flic_y);
};

typedef char flic_player_size_check[(sizeof(RGE_Flic_Player) == 0xBC) ? 1 : -1];

#endif  // AOE1_FLICS_CONTEXT_H
