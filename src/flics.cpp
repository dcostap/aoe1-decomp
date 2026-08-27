// PDB source module: C:\\msdev\\work\\age1_x1\\flics.cpp.
// The definitions below follow the original source order.

#include "../include/flics.h"
#include <string.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

// 00449B30, flics.cpp lines 21-50.
RGE_Flic_Player::RGE_Flic_Player(char* path)
{
    register int size;
    register int fd = open(path, 0x8000);

    if (fd > -1) {
        lseek(fd, 0, 2);
        size = tell(fd);
        flic_buffer = (unsigned char*)calloc(size, 1);
        lseek(fd, 0, 0);
        read(fd, flic_buffer, size);
        // BINARY NOTE: The shipped constructor copies the complete 0x84-byte
        // FLIC header before it reads the width field.
        flichead = *(FlicHead*)flic_buffer;
        flic_width = (int)*(short*)((char*)&flichead + 0x08);
        start();
        close(fd);
    } else {
        flic_buffer = 0;
        flic_handle = -1;
    }
}

// 00449BE0, flics.cpp lines 54-70.
RGE_Flic_Player::RGE_Flic_Player(int file_handle)
{
    if (file_handle > -1) {
        read(file_handle, &this->flichead, 0x84);
        this->flic_width = (int)(short)this->flichead.width;
        this->flic_handle = file_handle;
        this->flic_buffer = 0;
        this->start();
    } else {
        this->flic_buffer = 0;
        this->flic_handle = -1;
    }
}

// 00449C40, flics.cpp lines 74-77.
RGE_Flic_Player::~RGE_Flic_Player()
{
    if (this->flic_buffer) {
        free(this->flic_buffer);
    }
}

// 00449C50, flics.cpp lines 81-171.
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

    int chunk_index = 0;
    if (0 < framehead->chunks) {
        do {
            if ((short)chunk[1] == 4) {
                packets = *(short*)((char*)chunk + 6);
                color_index = 0;
                unsigned char* packet = (unsigned char*)chunk + 6;
                packet += 2;
                if (0 < packets) {
                    int packet_count = packets;
                    do {
                        PalettePacket* packet_header =
                            (PalettePacket*)packet;
                        int count = packet_header->count;
                        color_index += packet_header->skip;
                        packet = (unsigned char*)(packet_header + 1);
                        if (count == 0) {
                            count = 0x100;
                        }
                        if (0 < count) {
                            tagRGBQUAD* color = palette + color_index;
                            color_index += count;
                            int color_count = count;
                            unsigned char* green = &color->rgbGreen;
                            unsigned char* input = packet;
                            do {
                                unsigned char* next = input + 3;
                                green[1] = input[0];
                                green[0] = input[1];
                                ((tagRGBQUAD*)(green - 1))->rgbBlue =
                                    input[2];
                                green += 4;
                                input = next;
                            } while (--color_count != 0);
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
                packet += 2;
                if (0 < packets) {
                    int packet_count = packets;
                    do {
                        PalettePacket* packet_header =
                            (PalettePacket*)packet;
                        int count = packet_header->count;
                        color_index += packet_header->skip;
                        packet = (unsigned char*)(packet_header + 1);
                        if (count == 0) {
                            count = 0x100;
                        }
                        if (0 < count) {
                            unsigned char* green =
                                &palette[color_index].rgbGreen;
                            color_index += count;
                            int color_count = count;
                            do {
                                green += 4;
                                green[-3] = (unsigned char)(packet[0] << 2);
                                green[-4] = (unsigned char)(packet[1] << 2);
                                green[-5] = (unsigned char)(packet[2] << 2);
                                packet += 3;
                            } while (--color_count != 0);
                        }
                        packet_count--;
                    } while (packet_count != 0);
                }
            }

            chunk = (int*)((char*)chunk + *chunk);
            chunk_index++;
        } while (chunk_index < (int)framehead->chunks);
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

// 00449DF0, flics.cpp lines 175-180.
long RGE_Flic_Player::resolution()
{
    return ((long)this->flichead.width << 16) |
           (short)this->flichead.height;
}

// 00449E00, flics.cpp lines 184-186.
long RGE_Flic_Player::time_delay()
{
    return this->flichead.speed;
}

// 00449E10, flics.cpp lines 190-192.
short RGE_Flic_Player::frames()
{
    return this->flichead.frames;
}

// 00449E20, flics.cpp lines 196-212.
void RGE_Flic_Player::start()
{
    switch (this->flichead.type) {
    case 0xAF12:
        this->flichead.oframe1 += (long)this->flic_buffer;
        break;
    case 0xAF11: {
        int s = this->flichead.speed;
        char* tmp = (char*)this->flic_buffer + 0x84;
        s = s * 5;
        this->flichead.oframe1 = tmp;
        s = s * 5;
        s = s * 5;
        this->flichead.speed = (s * 8) / 70;
        break;
    }
    }
    this->flichead.oframe2 = this->flichead.oframe1;
}

// 00449E80, flics.cpp lines 216-218.
void RGE_Flic_Player::reset()
{
    this->flichead.oframe2 = this->flichead.oframe1;
}

// 00449E90, flics.cpp lines 222-345.
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

    // BINARY NOTE: The original stores x1, drawarea, y1, x2, and y2 in
    // this order. The y1 store comes before the bound expressions.
    this->x1 = flic_x;
    this->drawarea = drawarea_in;
    this->y1 = flic_y;
    this->x2 = this->flichead.width + flic_x;
    this->y2 = this->flichead.height + flic_y;

    this->drawarea_width =
        this->drawarea->AlignedWidth() * this->drawarea->Orien;
    if (this->drawarea->Orien < 1) {
        this->window_buffer = this->drawarea->Bits + this->x1 +
            ((this->y1 - this->drawarea->Height) + 1) *
                this->drawarea_width;
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
                // Palette chunks are handled by palette().
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
    if ((this->flichead.oframe2 - (char*)this->flic_buffer) >=
        this->flichead.size) {
        this->flichead.oframe2 = this->flichead.oframe1;
        if (this->flic_buffer != 0) {
            this->flichead.oframe2 =
                this->flichead.oframe1 +
                *(int*)this->flichead.oframe1;
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

// 0044A090, flics.cpp lines 349-361.
void RGE_Flic_Player::literal()
{
    int i = 0;
    if (this->flic_size_y <= 0) {
        return;
    }
    do {
        memcpy(this->window_buffer, this->chunk, this->flic_size_x);
        this->window_buffer += this->drawarea_width;
        this->chunk += this->flic_width;
        i++;
    } while (i < this->flic_size_y);
}

// 0044A100, flics.cpp lines 365-441.
void RGE_Flic_Player::delta_flc()
{
    ushort* p;
    long cur_y = 0;
    int lines = (int)*(short*)this->chunk;
    p = (ushort*)(this->chunk + 2);
    if (lines <= 0) {
        return;
    }
    int remaining = lines;

    do {
        unsigned char found = 0;
        ushort packets = 0;
        ushort* scan = p;
        do {
            ushort code = *scan;
            p = scan + 1;
            unsigned int top = ((unsigned int)code) >> 14;
            if (top == 0) {
                packets = code;
                found = 1;
            } else if (top == 2) {
                this->window_buffer[this->flic_width - 1] = (uchar)code;
                packets = *p;
                p = scan + 2;
                found = 1;
            } else if (top == 3) {
                int skip = -(int)(short)code;
                cur_y += skip;
                this->save_buffer += this->drawarea_width * skip;
                this->window_buffer = this->save_buffer;
            }
            scan = p;
        } while (found == 0);

        if ((short)packets > 0) {
            int packet_count = (short)packets;
            do {
                ushort pair = *p;
                this->window_buffer += (signed char)pair;
                signed char size = *((signed char*)p + 1);
                ushort* payload = p + 1;
                if (size > 0) {
                    int bytes = (int)size << 1;
                    memcpy(this->window_buffer, payload, bytes);
                    this->window_buffer += bytes;
                    p = payload + size;
                } else {
                    int bytes = -(int)size << 1;
                    if (bytes > 1) {
                        int n = bytes >> 1;
                        do {
                            *(ushort*)this->window_buffer = *payload;
                            this->window_buffer += 2;
                            n--;
                        } while (n != 0);
                    }
                    if (bytes == 1) {
                        *this->window_buffer = (uchar)*payload;
                        this->window_buffer++;
                    }
                    p = payload + 1;
                }
            } while (--packet_count != 0);
        }
        this->window_buffer = this->save_buffer + this->drawarea_width;
        cur_y++;
        this->save_buffer += this->drawarea_width;
    } while (--remaining != 0);
}

// 0044A2A0, flics.cpp lines 445-488.
void RGE_Flic_Player::delta_fli()
{
    char* chunk = this->chunk;
    int count = *(int*)chunk;
    chunk += 8;
    if (count <= 0) {
        return;
    }
    int remaining = count;

    do {
        int lines = (signed char)*chunk;
        int x = 0;
        chunk++;
        if (lines > 0) {
            int line_remaining = lines;
            do {
                x += (signed char)*chunk;
                char cnt = *++chunk;
                chunk++;
                if (cnt < 0) {
                    cnt = -cnt;
                    memset(this->window_buffer + x, *chunk, cnt);
                    chunk++;
                } else {
                    memcpy(this->window_buffer + x, chunk, cnt);
                    chunk += cnt;
                }
                x += cnt;
            } while (--line_remaining != 0);
        }
        this->window_buffer += this->drawarea_width;
        remaining--;
    } while (remaining != 0);
}

// 0044A390, flics.cpp lines 492-500.
void RGE_Flic_Player::black()
{
    long i;
    unsigned char* p;

    i = 0;
    if (this->flic_size_y > 0) {
        do {
            p = this->window_buffer;
            memset(p, 0, this->flic_size_x);
            this->window_buffer =
                this->window_buffer + this->drawarea_width;
            i = i + 1;
        } while (i < this->flic_size_y);
    }
}

// 0044A3E0, flics.cpp lines 504-541.
void RGE_Flic_Player::byte_run()
{
    char* chunk = this->chunk;
    int count = this->y1;
    count += this->flic_size_y;
    count--;
    if (count < 0) {
        return;
    }
    count++;

    int line_offset;
    unsigned char* dst;

    do {
        line_offset = 0;
        chunk++;
        do {
            unsigned char opcode = (unsigned char)*chunk;
            chunk++;
            signed char copy_count;

            if ((signed char)opcode >= 0) {
                copy_count = (signed char)opcode;
                dst = this->window_buffer + line_offset;
                memset(dst, *chunk, copy_count);
                chunk++;
            } else {
                copy_count = (signed char)opcode;
                copy_count = -copy_count;
                dst = this->window_buffer + line_offset;
                memcpy(dst, chunk, copy_count);
                chunk += copy_count;
            }
            line_offset += copy_count;
        } while (line_offset < this->flic_width);

        this->window_buffer += this->drawarea_width;
        count--;
    } while (count != 0);
}

// 0044A05D is a reviewed padding-only boundary between draw and literal.
