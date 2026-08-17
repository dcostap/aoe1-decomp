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
// - This claim: a positive-run-first branch restored the oracle's late
//   negative-run topology and improved the clean candidate to 397 bytes / 367
//   diff / 71.32% shape. Explicit packet cursor increments, per-scan packet
//   zeroing, and a sparse switch were regressed; retain the positive-first
//   natural source. Remaining blocker is the original EBP cursor/prologue
//   allocation and associated stack packet-count schedule.
// - This claim: char* stream cursor plus sparse switch improved size to 400 B
//   and shape to 72.09%, but worsened positional diff to 383 B and frame to
//   0x10; restored the clean ushort-cursor source.
// Matching-worker pass (sa-9c74babf-r1):
// - Rechecked the pinned natural ushort/two-cursor source: 397 emitted bytes,
//   367 differing bytes, 0xC frame, and no calls.  The first structural gap
//   remains the missing early EBP save and packet-cursor coloring.
// - Tested byte cursors, one-cursor forms, explicit byte increments, signed
//   packet counts, split cur_y initialization, full class context, payload
//   aliases, and register qualification.  None improved the clean result.
// - An ambient declaration lab with 64 variants produced two codegen groups;
//   all remained 397 bytes with no size/frame-valid improvement.
// Matching-worker pass (sa-47d20a98-r1):
// - Revalidated the pinned source at 397 bytes / 367 differing bytes / 0xC
//   frame.  The original still requires an early EBP save for the stream
//   cursor; the clean source assigns EBP to a packet value instead.
// - Tested packet zeroing and classifier operands, one-cursor ushort loops,
//   byte-stream cursors, declaration order, and typed byte views.  The best
//   source-model variant reached 394 bytes / 377 differing bytes; none beat
//   the pinned natural two-cursor source.
// - Restored the pinned clean source.  The remaining blocker is the EBP
//   stream-cursor allocation basin without compiler-steering source forms.
// Matching-worker pass (sa-82ebd704-r1):
// - Moving scalar declarations to function scope produced duplicate codegen.
// - One advancing ushort classifier cursor, including the inverted scan-owner
//   form, produced the 399-byte / 373-diff basin and was rejected.
// - Restored the pinned natural two-cursor decoder.  The unresolved blocker is
//   still the original EBP stream-cursor allocation and prologue basin.

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
                    uchar* dst = this->window_buffer;
                    memcpy(dst, payload, bytes);
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
