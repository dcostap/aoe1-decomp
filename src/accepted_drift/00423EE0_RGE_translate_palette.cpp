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
// Matching-worker pass: modeling the four contiguous scratch slots as long intense[4] made the
// body align with the original after a seven-byte prologue shift: 456 bytes, 93.38% shape,
// 33.11% exact-block coverage, and 51 edit-diff bytes. The fourth array slot explains the
// decompiler's local4 and frees ESI for the inner two-step sort counter. Reversed
// (intense[2] + intense[3]) operands recover the original mid/max load order. The remaining
// mismatch is the destination/source cursor prologue and the late diff-load scheduling.
// Windows and shared game_globals header contexts, pointer/delta declaration orders, explicit
// byte offsets, and int/long width variants did not change this codegen basin. Keep this
// ordinary four-slot array reconstruction as the clean unresolved source.
// Revisit: matching the Ghidra declaration order by initializing intense[0] before s was a
// codegen duplicate. Final validation remains 437 differing bytes and a 456-byte rebuild.
// Context pass: src/color_tu.cpp is an unregistered PDB-ordered wrapper for color.cpp. A fresh
// drawarea_context.h plus string.h build kept the C++ owner symbol, zero calls, 0x10 frame, and
// palette body, but emitted 456 bytes with reachable code beyond the 449-byte boundary.
// Accepted-drift review: the prologue computes identical source cursor,
// destination cursor, and destination-minus-source delta values with different
// registers. Body arithmetic and source reads match. Each iteration stores red,
// green, blue, then flags in the same order. The late delta reload moves only a
// private stack read, and the function makes no calls.
// Exact-finish pass: fresh prologue, width, declaration, pointer, type, header,
// and comma-expression tests did not remove the seven-byte prologue shift.
// A seven-variant prologue lab also found no size/frame-eligible or exact form.
// The four-slot scratch array remains the smallest body model with stable blocks.
// TU captain pass: the context gate proves color.cpp as the PDB module, source
// order 23 -> 32 -> 34 -> 43-45 -> 67 with fallback 36-39, and one free
// __cdecl owner at 00423EE0-004240A0. Exact color.cpp anchors 00424350,
// 00424440, 004244F0, 004245F0, 004247A0, and 004247B0 all remain MATCH in
// the authentic wrapper. The class owner for this function is unknown.
// TU captain probes: declaration initializers, register-qualified destination,
// int delta, reordered delta assignment, separate intense/local4 storage, and
// entry-base byte cursors did not repair the standalone boundary. The separate
// storage and entry-base forms worsened frame or body shape and were restored.
// Grouped validation is authoritative: the six exact anchors remain MATCH with
// zero relocation or boundary errors. The two accepted-drift functions remain
// observed; this function emits 461 bytes versus 449 with 417 differing bytes
// and two boundary escapes in the full color.cpp wrapper. No source-backed
// repair removes this structural overflow without losing the stable body model.

#ifndef COLOR_TU_CONTEXT
struct tagPALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };
#endif

void __cdecl RGE_translate_palette(tagPALETTEENTRY* src, tagPALETTEENTRY* dst, tagPALETTEENTRY color, long pct, int keep1, int keep2)
{
    unsigned char* d;
    unsigned char* s;
    long diff;
    long index1;
    long intense[4];
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
            intense[1] = t.peRed;
            intense[2] = *s;
            intense[3] = s[1];

            index1 = 2;
            do {
                long* p = &intense[2];
                for (long n = 2; n != 0; n--) {
                    long a = p[-1];
                    long b = p[0];
                    if (a < b) { p[-1] = b; p[0] = a; }
                    p++;
                }
                index1--;
            } while (index1 != 0);

            long minv = intense[1];
            long inten = (((intense[2] + intense[3]) * (0xff - minv)) / 512) + minv;
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
