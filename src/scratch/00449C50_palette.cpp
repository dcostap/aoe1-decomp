// VA: 00449C50 RGE_Flic_Player::palette(tagRGBQUAD* palette)
// flics.cpp lines 81-171
// Palette chunks are decoded from either the in-memory frame stream or a
// temporary file-backed frame.  Keep the FLIC and frame headers typed so the
// 0x60 oframe2 field and 0x10 frame-header size are owned by their records.
// Attempt log:
// - Completed the skeleton with the canonical typed FlicHead/FrameHead and
//   tagRGBQUAD surfaces; calls, frame, and size then matched, but the first
//   guard/loop basin remained 368 differing bytes.
// - Reversed to the positive file-backed guard and assigned the payload owner
//   before read; this recovered the original 407-byte frame and call topology.
// - Matched the decoder's pointer progression by advancing once after the
//   skip byte and once after count normalization; best source is 407 bytes /
//   262 differing bytes with all seven direct calls aligned.
// - Function-scope counter/register and raw index1 variants were neutral; the
//   remaining structural gap is the original framehead stack reload/zero-home
//   order and EDX/ESI packet-count coloring.
// - Replaced the raw index1 cursor with the typed FrameHead pointer; emitted
//   code stayed identical, so the living source now keeps proven header
//   ownership without decompiler-only offset plumbing.
// - Added a typed two-byte PalettePacket for the packed skip/count header; this
//   preserved the natural +6 header anchor and +2 payload step and improved the
//   emitted result to 243 differing bytes.
// - Added a natural packet countdown local after each positive packet guard;
//   this recovered the original movsx/test/copy countdown topology and reached
//   the best 212-byte result with all seven relocated call sites aligned.
// - Scoped count/color/skip declaration variants were codegen duplicates; keep
//   the typed packet plus countdown as the clean source.  Remaining drift is
//   the FrameHead stack reload and payload count/palette-base register coloring.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);
extern "C" int __cdecl lseek(int handle, int offset, int origin);
extern "C" int __cdecl read(int handle, void* buffer, unsigned int size);

struct FlicHead {
    long size;
    unsigned short type;
    short frames;
    short width;
    short height;
    short depth;
    short flags;
    long speed;
    short reserved1;
    unsigned char pad_16[2];
    long created;
    long creator;
    long updated;
    long updater;
    short aspect_dx;
    short aspect_dy;
    char reserved2[38];
    unsigned char pad_52[2];
    char* oframe1;
    char* oframe2;
    char reserved3[40];
};

struct FrameHead {
    long size;
    short type;
    short chunks;
    char reserved[8];
};

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

class RGE_Flic_Player {
public:
    unsigned char* flic_buffer;
    int flic_handle;
    FlicHead flichead;
    void* drawarea;
    long drawarea_width;
    long flic_width;
    unsigned char* window_buffer;
    unsigned char* save_buffer;
    char* chunk;
    long x1;
    long y1;
    long x2;
    long y2;
    long flic_size_x;
    long flic_size_y;

    void palette(tagRGBQUAD* palette);
};

// Main-agent audit confirmed the typed file/frame/palette surfaces; byte cursors
// are retained only where the packed FLIC chunk format requires them.
void RGE_Flic_Player::palette(tagRGBQUAD* palette)
{
    FrameHead* framehead;
    int* chunk;
    int* frame_buffer = 0;
    int packets;
    int color_index;

    if (this->flic_handle > -1) {
        framehead = (FrameHead*)calloc(1, 0x10);
        lseek(this->flic_handle, (int)this->flichead.oframe2, 0);
        read(this->flic_handle, framehead, 0x10);
        chunk = (int*)calloc(framehead->size, 1);
        frame_buffer = chunk;
        read(this->flic_handle, chunk, framehead->size);
    } else {
        framehead = (FrameHead*)this->flichead.oframe2;
        chunk = (int*)((char*)framehead + 0x10);
    }

    char* temp_buffer = 0;
    if (0 < framehead->chunks) {
        do {
            if ((short)chunk[1] == 4) {
                packets = *(short*)((char*)chunk + 6);
                color_index = 0;
                unsigned char* packet = (unsigned char*)chunk + 6;
                if (0 < packets) {
                    int packet_count = packets;
                    do {
                        PalettePacket* packet_header = (PalettePacket*)packet;
                        int count = packet_header->count;
                        color_index += packet_header->skip;
                        packet = (unsigned char*)(packet_header + 1);
                        if (count == 0) {
                            count = 0x100;
                        }
                        if (0 < count) {
                            unsigned char* green = &palette[color_index].rgbGreen;
                            color_index += count;
                            unsigned char* input = packet;
                            do {
                                unsigned char* next = input + 3;
                                green[1] = input[0];
                                green[0] = input[1];
                                ((tagRGBQUAD*)(green - 1))->rgbBlue = input[2];
                                green += 4;
                                count--;
                                input = next;
                            } while (count != 0);
                            packet = input;
                        }
                        packet_count--;
                    } while (packet_count != 0);
                }
            }

            if ((short)chunk[1] == 0x0B) {
                packets = *(short*)((char*)chunk + 6);
                color_index = 0;
                unsigned char* packet = (unsigned char*)chunk + 6;
                if (0 < packets) {
                    int packet_count = packets;
                    do {
                        PalettePacket* packet_header = (PalettePacket*)packet;
                        int count = packet_header->count;
                        color_index += packet_header->skip;
                        packet = (unsigned char*)(packet_header + 1);
                        if (count == 0) {
                            count = 0x100;
                        }
                        if (0 < count) {
                            tagRGBQUAD* color = palette + color_index;
                            color_index += count;
                            unsigned char* green = &color->rgbGreen;
                            do {
                                green[1] = (unsigned char)(packet[0] << 2);
                                green[0] = (unsigned char)(packet[1] << 2);
                                ((tagRGBQUAD*)(green - 1))->rgbBlue =
                                    (unsigned char)(packet[2] << 2);
                                packet += 3;
                                count--;
                                green += 4;
                            } while (count != 0);
                        }
                        packet_count--;
                    } while (packet_count != 0);
                }
            }

            chunk = (int*)((char*)chunk + *chunk);
            temp_buffer++;
        } while ((int)temp_buffer < (int)framehead->chunks);
    }

    if (this->flic_handle >= 0) {
        if (framehead != 0) {
            free(framehead);
        }
        if (frame_buffer != 0) {
            free(frame_buffer);
        }
    }
}
