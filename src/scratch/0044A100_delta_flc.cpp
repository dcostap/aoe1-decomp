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
// Fresh pass: replace the compiler-steering dummy with the binary-supported
// cur_y stack local and the natural ushort packet cursor from the sibling FLIC
// decoder.  This is the clean baseline for the remaining register/layout work.
// - A short/long outer-count, single-cursor, signed packet-count, and positive
//   payload-cursor pass were neutral or lower-shape; retain the two-cursor
//   natural decoder.  The remaining gap is EBP packet-cursor allocation and
//   the cur_y/line-count stack-home schedule.
// - Widening the outer line count to int changed the body to 400 bytes; rolled
//   back because the original boundary is 412 bytes.
// - Typed char* cursor and base-plus-one pointer spellings were neutral or
//   lower-shape; retain the natural ushort cursor.
// - Removing the redundant found-scan value temporary improved the best result
//   to 376 differing bytes without changing size or calls; this is the clean
//   source retained for the remaining EBP/prologue basin.
// - This claim: the binary-proven dword outer count plus a separate
//   success-path remaining counter improved the clean source to 374 differing
//   bytes / 61.24% shape / 398 emitted bytes, while register qualification and
//   pointer declaration/initialization order were codegen duplicates or a
//   one-byte regression. Retain the natural dword-count candidate below; the
//   unresolved structural blocker is EBP packet-cursor coloring and the
//   missing original 14-byte prologue/body basin.

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
    char* chunk;
    void delta_flc();
};

// Main-agent audit confirmed canonical FLIC player/frame ownership and retained
// the natural packed ushort delta decoder.
void RGE_Flic_Player::delta_flc()
{
    long cur_y = 0;
    int lines = (int)*(short*)this->chunk;
    ushort* p = (ushort*)(this->chunk + 2);
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
                if (size < 1) {
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
                } else {
                    int bytes = (int)size << 1;
                    uchar* dst = this->window_buffer;
                    memcpy(dst, payload, bytes);
                    this->window_buffer += bytes;
                    p = payload + size;
                }
            } while (--packet_count != 0);
        }
        this->window_buffer = this->save_buffer + this->drawarea_width;
        cur_y++;
        this->save_buffer += this->drawarea_width;
    } while (--remaining != 0);
}
