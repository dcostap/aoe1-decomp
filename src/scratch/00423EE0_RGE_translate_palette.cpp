// 00423EE0 RGE_translate_palette (color.cpp:23-67)
// Attempt log:
// 1: Pointer implementation with s/d locals: size 448, broad diff; compiler kept pct in EBP and used different pointer basis.
// 2: d-before-s and d[-3] stores: no material improvement.
// 3: Natural indexed PALETTEENTRY loop: worse (95.3% diff), rolled back.
// 4: Pointer form with register d/s hints: no material change, still 448 bytes.
// 5: Use unsigned int color parameter: worsened padded diff to 96.2%; rolled back to struct color.
// 6: Fresh typed PALETTEENTRY array reconstruction: 476 bytes and a 0x24 frame; rolled back.
// 7: Removed unsigned channel casts in the typed pointer form; signed VC5 divisions improved resync similarity.
// 8: Separated the palette index from the three intensity values; 0x14 frame and no positional gain.
// 9: Reordered locals, counted loops, and pointer declarations; emitted code stayed unchanged.
// 10: Restored the binary-backed long index1/intense[3] lifetime shape. The outer loop counter shares
// intense[0], while the inner counter stays a block local; this tests the original 0x10-frame reuse.
// 11: Use typed source/target entry pointers and direct member ownership instead of channel cursors;
// this expanded the frame to 0x24 and broke the exact branch islands, so it was rolled back.
// 12: Declare the destination cursor, byte delta, and source cursor in the original evidence order.
// 13: Separate the pointer/delta initializers from their declarations to test source-line scheduling.
// 14: Split the local4 declaration from its source-channel assignment to test stack home reuse.
// 15: Keep the two-step sort counter in a register, matching the observed ESI inner-loop lifetime.
// 16: Widen the inner sort counter to long, matching the long index variables in the source packet.
// 17: Restore local4 to int; the binary lists it as a 4-byte scratch separate from long intense[].
// 18: Form the channel cursors from explicit byte offsets; emitted code was unchanged, so the
// named PALETTEENTRY member addresses remain the living source.
// Final pass: the long index/intense lifetime reaches the 0x10 frame and 85.53% shape basin;
// pointer-order, local declaration, counter-width, and cursor-offset variants were duplicates.
// Left in scratch: the best period-plausible typed reconstruction. The original uses a 0x10 frame,
// reuses a parameter home for the byte delta, and starts the channel loop seven bytes earlier.
// Follow-up TU pass: declaration initializers and split delta subtraction were duplicates.
// The historical typed entry-pointer form reached 420 bytes but used a 0x24 frame and
// 42.67% shape; named channel locals reached 431 bytes with a 0x14 frame. Both were restored.
// New pass: the original writes the destination-minus-source delta into the incoming source
// parameter home. Reusing the saved source cursor and mutating that parameter reached 384 bytes,
// 86.58% shape, and 455 bytes, but the parameter-as-integer form is not a clean source baseline.
// Scoping the sort counter, moving local4, and widening local4 were codegen duplicates. Restored
// the clean typed channel-cursor source; remaining blocker is structural VC5 stack/register
// allocation around the proven parameter-home reuse and local4/inner-counter overlap.

struct tagPALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };

void __cdecl RGE_translate_palette(tagPALETTEENTRY* src, tagPALETTEENTRY* dst, tagPALETTEENTRY color, long pct, int keep1, int keep2)
{
    long index1;
    long intense[3];
    unsigned char* d;
    int diff;
    unsigned char* s;
    d = &dst->peFlags;
    diff = (int)dst - (int)src;
    s = &src->peGreen;
    intense[0] = 0;

    do {
        if (intense[0] == keep1 || intense[0] == keep2) {
            d[-3] = s[-1];
            s[diff] = *s;
            d[-1] = s[1];
            d[0] = s[2];
        } else {
            tagPALETTEENTRY t = *(tagPALETTEENTRY*)(s - 1);
            int local4;
            intense[1] = t.peRed;
            intense[2] = *s;
            local4 = s[1];

            index1 = 2;
            do {
                long* p = &intense[2];
                for (int n = 2; n != 0; n--) {
                    long a = p[-1];
                    long b = p[0];
                    if (a < b) { p[-1] = b; p[0] = a; }
                    p++;
                }
                index1--;
            } while (index1 != 0);

            long minv = intense[1];
            long midv = intense[2];
            long maxv = local4;
            long inten = (((maxv + midv) * (0xff - minv)) / 512) + minv;
            long v;
            v = ((color.peRed * inten) / 255 - t.peRed) * pct;
            d[-3] = (unsigned char)(t.peRed + (v / 100));
            v = ((color.peGreen * inten) / 255 - *s) * pct;
            s[diff] = (unsigned char)(*s + (v / 100));
            v = ((color.peBlue * inten) / 255 - s[1]) * pct;
            d[-1] = (unsigned char)(s[1] + (v / 100));
            d[0] = s[2];
        }
        intense[0]++;
        s += 4;
        d += 4;
    } while (intense[0] < 0x100);
}
