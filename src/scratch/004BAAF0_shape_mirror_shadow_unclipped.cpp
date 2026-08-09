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
//
// sa-78979d2a-mshad probes (2026-08-09):
// - Normalized the living source away from the prior goto/parameter-alias
//   scaffold to a natural counted backward RLE decoder with separate height
//   and row-count locals. The clean source is 230B/203 strict bytes, with the
//   correct call/field behavior and no forbidden cursor or alias hacks.
// - Direct per-orientation destination formation, a persistent row/work pair,
//   a shared byte count, and table-plus-pixel operand spelling were tested;
//   none beat the normalized source. The old 188-byte metric winner depended
//   on decompiler-shaped control/parameter reuse and was not retained.

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

// Main-agent audit confirmed canonical non-polymorphic shape/draw-area ownership
// and retained the normalized typed RLE decoder; alias-heavy diagnostics remain
// history only.
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
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;

    Shape_Header* hdr = this->shape_header;
    byte* src = (byte*)(hdr + 1);
    long height = hdr->ymax - hdr->ymin + 1;

    long m;
    if (draw_area->Orien < 1)
        m = (y - draw_area->Height + 1) * pitch;
    else
        m = y * pitch;
    byte* dst = draw_area->Bits + m + x + 1;
    long rows;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte code = *src++;
                if ((code & 1) == 1) {
                    code >>= 1;
                    if (code == 0) {
                        dst -= *src++;
                    } else {
                        unsigned int count = code;
                        do {
                            --dst;
                            --count;
                            *dst = table[*dst];
                        } while (count != 0);
                        src += code;
                    }
                } else {
                    code >>= 1;
                    if (code == 0) {
                        done = 1;
                    } else {
                        unsigned int count = code;
                        do {
                            --dst;
                            --count;
                            *dst = table[*dst];
                        } while (count != 0);
                        src++;
                    }
                }
            } while (!done);
            dst += pitch;
        } while (--rows);
    }
    return 1;
}
