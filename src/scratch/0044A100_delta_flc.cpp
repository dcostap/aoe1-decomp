// VA: 0044A100 RGE_Flic_Player::delta_flc
// flics.cpp lines 365-441
// Attempt log:
// 1: natural ushort* decoder: too short 400 B; compiler used EBP as constant 2 instead of chunk pointer.
// 2: byte-pointer decoder forced byte increments but used 0x10 frame/early EDI save, broad drift.
// 3: compact byte-pointer if-chain recovered 0x0c frame but still too short; EDX holds chunk, EBP constant 2.
// 4: register-qualified chunk pointer probe no change.
// 5: casted byte increments instead of +=2 to avoid constant-2 register; no change.
// 6: flags /O2(no /Oy), /O1, /Ox, /Ob0: /O1 much shorter, others same family.
// 7: volatile dummy forces comparable 412-byte output but broad drift (91.9903% pos, first mismatch 5).
// Left in scratch: behavior is modeled, but compiler insists on EDX chunk pointer + EBP constant 2 instead of original EBP chunk pointer, cascading through loop/register layout; not accepted_drift-safe.

#include <string.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

class RGE_Flic_Player {
public:
    char gap_00[0x90];
    long drawarea_width;
    long flic_width;
    uchar* window_buffer;
    uchar* save_buffer;
    uchar* chunk;
    void delta_flc();
};

void RGE_Flic_Player::delta_flc()
{
    volatile long dummy = 0;
    long cur_y = dummy;
    uchar* p = this->chunk;
    int lines = (int)*(short*)p;
    p = (uchar*)((int)p + 2);
    if (lines <= 0) return;

    do {
        unsigned char found = 0;
        short packets = 0;
        do {
            unsigned short code = *(unsigned short*)p;
            unsigned int top;
            p = (uchar*)((int)p + 2);
            top = ((unsigned int)code) >> 14;
            if (top == 0) {
                packets = (short)code;
                found = 1;
            } else if (top == 2) {
                this->window_buffer[this->flic_width - 1] = (uchar)code;
                code = *(unsigned short*)p;
                p = (uchar*)((int)p + 2);
                packets = (short)code;
                found = 1;
            } else if (top == 3) {
                int skip = -(int)(short)code;
                cur_y += skip;
                this->save_buffer += this->drawarea_width * skip;
                this->window_buffer = this->save_buffer;
            }
        } while (!found);

        if (packets > 0) {
            int packet_count = packets;
            do {
                signed char xskip = *(signed char*)p++;
                signed char size;
                this->window_buffer += xskip;
                size = *(signed char*)p++;
                if (size > 0) {
                    int bytes = (int)size << 1;
                    memcpy(this->window_buffer, p, bytes);
                    this->window_buffer += bytes;
                    p += bytes;
                } else {
                    int bytes = -(int)size << 1;
                    if (bytes > 1) {
                        int n = bytes >> 1;
                        do {
                            *(unsigned short*)this->window_buffer = *(unsigned short*)p;
                            this->window_buffer += 2;
                            n--;
                        } while (n != 0);
                    }
                    if (bytes == 1) {
                        *this->window_buffer = *p;
                        this->window_buffer++;
                    }
                    p = (uchar*)((int)p + 2);
                }
            } while (--packet_count != 0);
        }
        this->window_buffer = this->save_buffer + this->drawarea_width;
        cur_y++;
        this->save_buffer += this->drawarea_width;
    } while (--lines != 0);
}
