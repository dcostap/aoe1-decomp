// 00449E90 RGE_Flic_Player::draw
// PDB context: C:\msdev\work\age1_x1\flics.cpp, lines 222-345.
// The address order is reset, draw, switch data, literal, and the decoders.
// RGE_Flic_Player is the 0xBC-byte PDB owner. Its decoder methods are private.
//
// Exact recovery notes:
// - The old clean source had 36 different bytes in the coordinate block.
// - Store y1 before the bound expressions, then read graphics through drawarea.
//   This recovers the shipped register lifetimes and all 461 bytes.
// - A late y1 assignment loses exactness. Parameter-owned graphics reads also
//   lose exactness, except for the AlignedWidth receiver alone.
// - Direct width and height reads stay exact. Width and height locals were not
//   required. Natural signed promotion also stays exact.
// - A product local and direct drawarea_width use both stay exact. Keep the
//   direct member form because it is smaller and matches the PDB line band.
// - Natural FlicHead padding, the reviewed TDrawArea layout, private helper
//   access, PDB parameter names, and char* temp_buffer are ABI-backed cleanup.
// - The PDB-backed FrameHead fields replace raw offsets without changing code.
//
// BINARY NOTE: The coordinate source order below emits the shipped stores in
// x1, drawarea, x2, y1, y2 order. Do not move y1 after the bound expressions.
#ifndef FLICS_SHARED_CONTEXT
extern "C" void* calloc(unsigned int count, unsigned int size);
extern "C" void free(void* ptr);
extern "C" long lseek(int handle, long offset, int origin);
extern "C" int read(int handle, void* buffer, unsigned int size);

class FlicHead {
public:
    long size;
    unsigned short type;
    short frames;
    short width;
    short height;
    short depth;
    short flags;
    long speed;
    short reserved1;
    long created;
    long creator;
    long updated;
    long updater;
    short aspect_dx;
    short aspect_dy;
    char reserved2[38];
    char* oframe1;
    char* oframe2;
    char reserved3[40];
};

class FrameHead {
public:
    long size;
    short type;
    short chunks;
    char reserved[8];
};

class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    long Width;
    long Height;
    long Pitch;
    long Orien;
    char gap_28[0xD8];

    long AlignedWidth();
};

class RGE_Flic_Player {
private:
    unsigned char* flic_buffer; // +0
    int flic_handle;           // +4
    FlicHead flichead;         // +8
    TDrawArea* drawarea;       // +8c
    long drawarea_width;       // +90
    long flic_width;           // +94
    unsigned char* window_buffer; // +98
    unsigned char* save_buffer;   // +9c
    char* chunk;               // +a0
    long x1;                   // +a4
    long y1;                   // +a8
    long x2;                   // +ac
    long y2;                   // +b0
    long flic_size_x;          // +b4
    long flic_size_y;          // +b8

    void literal();
    void delta_flc();
    void delta_fli();
    void black();
    void byte_run();

public:
    unsigned char draw(TDrawArea* drawarea_in, long flic_x, long flic_y);
};
#endif

unsigned char RGE_Flic_Player::draw(TDrawArea* drawarea_in, long flic_x,
                                    long flic_y)
{
    char* temp_buffer = 0;
    FrameHead* frame;
    char* chunk_base;

    if (this->flic_handle > -1) {
        frame = (FrameHead*)calloc(1, sizeof(FrameHead));
        lseek(this->flic_handle, (long)this->flichead.oframe2, 0);
        read(this->flic_handle, frame, sizeof(FrameHead));
        chunk_base = (char*)calloc(frame->size, 1);
        temp_buffer = chunk_base;
        read(this->flic_handle, chunk_base, frame->size);
    } else {
        frame = (FrameHead*)this->flichead.oframe2;
        chunk_base = (char*)frame + sizeof(FrameHead);
    }

    this->x1 = flic_x;
    this->drawarea = drawarea_in;
    this->y1 = flic_y;
    this->x2 = this->flichead.width + flic_x;
    this->y2 = this->flichead.height + flic_y;

    this->drawarea_width =
        this->drawarea->AlignedWidth() * this->drawarea->Orien;
    if (this->drawarea->Orien < 1) {
        this->window_buffer = this->drawarea->Bits + this->x1 +
            ((this->y1 - this->drawarea->Height) + 1) * this->drawarea_width;
    } else {
        this->window_buffer = this->drawarea->Bits + this->x1 +
            this->drawarea_width * this->y1;
    }
    this->save_buffer = this->window_buffer;

    int i = 0;
    if (frame->chunks > 0) {
        do {
            this->chunk = chunk_base + 6;
            switch (*(short*)(chunk_base + 4)) {
            case 4:
                // BINARY NOTE: This empty case keeps the shipped 4..16 range.
                break;
            case 0x10:
                this->literal();
                break;
            case 7:
                this->delta_flc();
                break;
            case 0x0c:
                this->delta_fli();
                break;
            case 0x0d:
                this->black();
                break;
            case 0x0f:
                this->byte_run();
                break;
            }
            chunk_base += *(int*)chunk_base;
            ++i;
        } while (i < frame->chunks);
    }

    this->flichead.oframe2 += frame->size;
    unsigned char result;
    if ((this->flichead.oframe2 - (char*)this->flic_buffer) >= this->flichead.size) {
        this->flichead.oframe2 = this->flichead.oframe1;
        if (this->flic_buffer != 0) {
            this->flichead.oframe2 = this->flichead.oframe1 + *(int*)this->flichead.oframe1;
        }
        result = 2;
    } else {
        result = 0;
    }

    if (this->flic_handle > -1) {
        if (frame != 0) {
            free(frame);
        }
        if (temp_buffer != 0) {
            free(temp_buffer);
        }
    }
    return result;
}
