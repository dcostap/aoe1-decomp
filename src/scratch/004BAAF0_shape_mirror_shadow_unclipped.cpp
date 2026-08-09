// 004BAAF0 TShape::shape_mirror_shadow_unclipped
// Shape.cpp:1943-2006
// Status: scratch / not exact.
// Attempt log:
// - Built natural mirror-shadow RLE decoder from packet/decompiler. Prologue/setup through header reads matches, behavior/call set/ret 10h are understood.
// - Plain natural source: 70.41% positional / 53.93% edit diff. First drift is VC5 storing row count [esp+18] before the orientation branch; original delays it until after dst calculation/table load and stores dst in [esp+1C].
// - Tried forcing parameter-slot reuse for x/y via raw casts and volatile writes; raw casts made .text 256B (too small for configured 267B) and volatile writes changed early row-count allocation EDX->ECX, cascading worse.
// - Tried pointer-typed x parameter to encourage [esp+1C] reuse; it perturbed LEA operand order and still did not match, reverted to real long signature.
// - Tried while vs do-while count loops and explicit byte temp reuse. Remaining mismatch is loop-count lowering: original uses [esp+20] byte temp with `mov esi,[esp+20]; test dl; ... mov edx,esi; and edx,0FFh` and no extra mid-loop test; rebuilt either hoists masks or inserts redundant tests.
// - Left in scratch after serious source-shape attempts; next lead is focused variant_lab around parameter-slot reuse and RLE loop spelling.
// - Sink-row declaration/assignment variants and direct x-home row-counter reuse changed the prologue basin to 264/267-byte structural drift; restored.
// - Signed-long odd/even counters improved instruction-shape similarity (81.98%) but worsened strict bytes (200); explicit nested packet guards were codegen-duplicate or worse; restored.
// - Focused variant lab (144 variants; count types/update spellings; size and call-set gated) found no exact. Best group was odd-long/even-uchar, 193 positional / 90 edit bytes, but it retained the same early row-home mismatch and was not adopted.
// - Direct mutation of y for the even shadow run improved shape to 83.49% with the same 188 strict bytes but changed register coloring and table-load order; restored clean source.
// - Final retained state: natural typed RLE decoder, 267-byte output, one aligned AlignedWidth call, 188 strict differing bytes (70.4120%), first mismatch at 004BAB1E. Paused: remaining gap is VC5 local-home/block scheduling, not unresolved behavior or call ABI.

typedef unsigned char byte;

struct Shape_Header { long bounds, origin, xmin, ymin, xmax, ymax; };

struct TDrawArea {
    char gap_00[8];
    byte* Bits;
    char gap_0C[0x10];
    long Height;
    char gap_20[4];
    long Orien;
    long AlignedWidth(void);
};

class TShape {
public:
    byte* shape;
    long load_type;
    long load_size;
    Shape_Header* shape_header;
    byte shape_mirror_shadow_unclipped(TDrawArea* draw_area, long x, long y, byte* table);
};

byte TShape::shape_mirror_shadow_unclipped(TDrawArea* draw_area, long x, long y, byte* table)
{
    long orien = draw_area->Orien;
    long pitch = draw_area->AlignedWidth() * orien;

    Shape_Header* hdr = this->shape_header;
    long rows = hdr->ymax - hdr->ymin + 1;
    byte* src = (byte*)(hdr + 1);

    byte* dst;
    if (orien < 1) {
        dst = draw_area->Bits + (y - draw_area->Height + 1) * pitch + x + 1;
    } else {
        dst = draw_area->Bits + pitch * y + x + 1;
    }

    if (rows > 0) {
        do {
            byte done = 0;
            do {
                byte code = *src++;
                byte low = (byte)(code & 1);
                if (low == 1) {
                    code >>= 1;
                    y = code;
                    if (code == 0) {
                        dst -= (unsigned char)*src;
                        goto bump_src;
                    }
                    {
                        unsigned int count = (unsigned char)y;
                        do {
                            --dst;
                            --count;
                            *dst = table[*dst];
                        } while (count != 0);
                    }
                    src += (unsigned char)y;
                    goto row_test;
                } else {
                    code >>= 1;
                    y = code;
                    if (code == 0) {
                        done = 1;
                        goto row_test;
                    }
                    if (code != 0) {
                        unsigned int count2 = (unsigned char)y;
                        do {
                            --dst;
                            --count2;
                            *dst = table[*dst];
                        } while (count2 != 0);
                    }
bump_src:
                    ++src;
                }
row_test:
                ;
            } while (!done);
            dst += pitch;
        } while (--rows != 0);
    }
    return 1;
}
