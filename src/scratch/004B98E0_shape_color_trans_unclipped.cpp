// VA: 004B98E0, TShape::shape_color_trans_unclipped, 268 bytes
// Source: Shape.cpp lines 841-905
// Status: SCRATCH — behavior and call set are reconstructed; remaining drift is
// the VC5 prologue/local-home/register basin and broad instruction placement.
//
// Known from the executable: TShape+0x0C is the Shape_Header, the payload starts
// at hdr+1, TDrawArea fields are Bits+0x08/Height+0x1C/Orien+0x24, and the RLE
// stream has literal, skip, solid, and end-of-row commands.  The repeat arm is
// a real memset call.  The pretested literal loop is retained because the binary
// has an initial destination/end compare before its copy body.
//
// Attempt log:
// - baseline: natural typed RLE reconstruction, but manual solid fill omitted
//   the binary memset call (193B, 259 differing bytes).
// - restored the external C memset surface with #pragma function(memset): calls
//   became 2/2 aligned and the candidate grew to 245B (254 differing bytes).
// - negative-first orientation dispatch improved setup/CFG (247B, 233 diff).
// - one shared byte count across command arms recovered parameter-slot reuse
//   (same size, 232 diff); typed Shape_Header and row-guard declaration were
//   canonical cleanup/duplicate basins.
// - changed the literal run to a pretested `while (dst < end)` as required by
//   the observed initial `cmp/jae`; current natural candidate is 251B, 234
//   differing bytes, 100% ordered calls, 9/9 conditional CFG signals.
// - setup declaration/order variants were codegen duplicates.  Remaining lead:
//   recover the original 8-byte local frame and early saved-register coloring;
//   do not replace this typed source with raw cursor/volatile scaffolding.
// sa508a60b0_shape3 probes (2026-08-09):
// - Rechecked the clean typed baseline: 251B/234 strict bytes with both calls
//   and the pretested literal loop aligned, but no local frame.
// - A natural separate `width` row counter assigned after destination setup
//   improved the strict metric to 230B without changing behavior or call set;
//   initializing it earlier instead moved header loads before the save prologue
//   and produced a worse 249B basin. Retained the after-destination form.
// - The remaining structural blocker is the oracle's 8-byte frame and its
//   delayed parameter-home allocation; no ABI or ownership uncertainty remains.
// sa-1a59a700-r1-004B98E0 probes (2026-08-11):
// - Collapsing header height and the post-destination counter into one natural
//   width local recovered the 8-byte frame, but stored width before the call and
//   remained a broad 254-byte mismatch; an area alias and orientation-first
//   spelling were emitted-code duplicates.
// - Split the binary-supported persistent row base from the per-row RLE cursor;
//   this reached exact effective size/frame (268B/8B) with both ordered calls,
//   while the standalone candidate remains 255 differing bytes.  Its remaining
//   mismatch is the setup/home basin: row and byte-count homes are swapped
//   relative to the oracle and literal/table index registers are oppositely
//   colored.  Moving count to setup scope and row declaration order were
//   duplicates.
// - A scoped literal index added 15 bytes and was rolled back; separate cursor
//   increment and period <string.h> context were duplicates/worse (261B).
// - Retained the readable one-width split-row reconstruction.  Calls, RLE CFG,
//   ownership, and effective size/frame are aligned; remaining lead is the
//   original Shape.cpp prologue/local-home/register basin, not behavior.
// orch2-4B98E0-home probes (2026-08-12):
// - Reused td as the persistent row home and p2 as the byte-count home after
//   setup, while capturing td before the delayed header load.  Size/frame and
//   calls stayed aligned, but strict diff stayed 255 and shape fell to 77.78%;
//   rolled back as a worse parameter-reuse basin.
// - A named td capture with delayed header load but natural row/count locals
//   was emitted-code identical to the clean source; rolled back.  The donor
//   home lead is exhausted without a source-quality improvement.
// shardE-4B98E0 probes (2026-08-13):
// - Applied the exact same-TU sibling cursor topology with a persistent typed
//   destination home and byte count.  It improved shape to 92.16% and exact
//   blocks to 73.27%, but remained 255 bytes different; the direct-address
//   variant was 269B/246 diff and retained no canonical source advantage.
// - Reordering pitch/header declarations, palette-index spelling, address
//   terms, and direct-formal aliases produced duplicates or a 283B/263 diff.
//   Restored the clean typed split-row reconstruction; calls and ownership
//   remain exact, while the setup/register basin is unresolved.
// sa7d813de0-r1-shape probes (2026-08-13):
// - Rechecked the paused source and exact Shape.cpp siblings.  Full proven
//   TShape/TDrawArea field surfaces were codegen duplicates; retained them.
// - The natural split statement `*dst = pal[*src]; src++;` and the matching
//   solid-arm cursor order reduce strict drift to 159 bytes at exact size and
//   frame.  Calls, RLE effects, and ownership stay aligned.
// - A diagnostic persistent-row cast through td reached 155 bytes and 91.18%
//   shape, but it is decompiler-shaped parameter-home steering.  The living
//   source keeps the ordinary row pointer instead.
// - Stride-first setup, p2 count reuse, index temporaries, pointer-add table
//   spelling, and redundant area aliases gave duplicates or worse basins.
// - Remaining drift is the original Shape.cpp prologue/register basin and
//   table index/value coloring.  No behavior or call uncertainty remains.
// sa-e6fe2895-r1 probes (2026-08-16):
// - The exact same-TU sibling cursor topology, with p2 carrying the row base
//   after setup, improved the clean natural candidate to 268B/137 diff and
//   89.32% shape.  Setup through the first row guard is exact.
// - A diagnostic reuse of the dead td home for the row pointer, plus explicit
//   shared source-advance labels, reached 268B/132 diff, 97.09% shape, and
//   94.06% exact blocks.  The binary supports the row home and shared tail,
//   but the cast is compiler-steering, so it was rolled back.
// - Literal bound spellings, typed palette views, scoped index/color locals,
//   register qualification, and explicit pointer increment order were
//   duplicates or worse.  Calls, size, frame, and behavior stayed aligned.
// - The pinned p2 row-home source was later rejected by main review as
//   compiler-steering.  The living source retains the ordinary row pointer.
// sa-899d6337-r1 probes (2026-08-17):
// - Restored the ordinary row-pointer source after the p2 pointer-carrier
//   checkpoint.  It builds at 268B/8B with both calls aligned and 159 strict
//   differing bytes; it is the retained natural source model.
// - Natural row/count order, a separate counted-row local, shared source
//   advance labels, literal post-increment, typed index/color locals, staged
//   orientation order, and typed palette payload access were duplicates or
//   worse.  Solid-arm statement order was also worse.  All were rolled back.
// - Do not retain p2 pointer casts, raw cursor forms, or metric-only control
//   flow.  Remaining drift is the VC5 prologue/local-home and register basin;
//   ABI, ownership, calls, and RLE behavior remain resolved.
// sa-eaa9dd7e-r1 probes (2026-08-17):
// - Re-read the complete local lessons, matching workflow, dossier, original
//   assembly, Ghidra listing, ABI evidence, and same-TU donors.  The original
//   uses td's incoming home for the persistent row, p2's home for the byte
//   count, and a separate 8-byte pitch/width frame.  Its two direct calls and
//   byte-stream ownership are already resolved.
// - A typed header increment, a typed payload-owner view, a natural area alias,
//   and a typed palette payload were duplicates or metric-only basins.  They
//   were rolled back.  Shared-tail and parameter-home steering remain rejected.
// - Initializing Orien at declaration and using the typed expression
//   `td->AlignedWidth() * Orien` is the best new natural basin: 268B/8B,
//   2/2 ordered calls, 152 strict differing bytes, and 85.29% shape.  It is
//   not exact.  The remaining mismatch starts in VC5 local-home/register
//   allocation and the literal table-index register basin.
// sa-08179dd2-r1 TU audit (2026-08-17):
// - Tested same-TU CRT header order, Windows/RECT context, <io.h>/<fcntl.h>,
//   a Windows-style min macro, the ground-truth class declaration kinds, the
//   full neighboring member declaration bank, and the exact preceding
//   shape_draw_unclipped donor body.  These contexts either reproduced the
//   clean 268B/152-diff output or moved to the harmful 271B/257-diff basin.
// - The exact preceding donor definition did not change the target output.
//   Function order is therefore not the controlling source context here.
// - The public TDrawArea/private TShape class spelling reproduced the PDB
//   AAEEPAV decorated ABI surface with unchanged bytes.  It did not recover
//   the oracle prologue or local homes, so it is ABI evidence only.
// - The clean source and default /O2 /Oy flags are restored.  No tested
//   translation-unit context naturally selects the oracle parameter-home
//   basin.  Remaining drift is source liveness/home allocation, not a proven
//   missing header, macro, declaration, function order, or flag.
// - Object audit confirms the 268-byte range, two local words, five parameters,
//   FPO/COFF shape, compiler, and no hidden inline cause. Oracle assigns row to
//   the td home and count to p2; the natural source reverses them. A row-home
//   cast remains rejected, and the extra skip-arm source increment stays open.
// sa-d8c4454d-r1:
// - Canonicalized the PDB class spellings and private decoder ABI. Added the
//   proven Shape_File_Header, Shape_Offsets, SLhape_File_Header, and Shape_Info
//   payload types. Calls stayed 2/2 and output stayed 268B with an 8B frame.
// - A full TDrawArea field layout added 3 bytes and was rejected. The narrow
//   typed overlay keeps only the proven decoder fields and class spelling.
// - A shared source increment after skip and solid arms reached 268B but 255
//   differing bytes. Restored the simple natural arm increments. It changed
//   control flow and did not preserve the best source basin.
// - Typed payload aliases, canonical Orien/width widths, a palette alias,
//   direct header reads, and folded destination arithmetic were duplicates or
//   worse. No parameter-home or row-home steering is retained.
// sa-697357dc-r1:
// - Completed a fresh 20-probe natural-source pass from the 268B/152-diff
//   frontier. Every probe preserved 268B/8B, two ordered calls, and behavior.
// - A one-byte Shape_Payload record models the proven packed stream without a
//   raw cursor. It is codegen-identical to the byte form and remains canonical.
// - Tested payload record ownership, decoder ABI spelling, row/count declaration
//   order, scoped locals, solid/skip order, row-pointer forms, and loop guards.
//   All natural variants were duplicates or worse.
// - The oracle still assigns the row pointer to td's home and count to p2's
//   home. Only rejected home casts or pointer carriers reach the 132-byte basin.
//   The retained source uses no casts, aliases, volatility, or compiler steering.
// - Accepted-drift audit: do not promote this candidate. RLE cursor effects,
//   palette reads, memset arguments, row movement, and returns align. However,
//   the rebuild reads td->Orien before a shape-header field that the original
//   reads first. Invalid header or draw-area pointers therefore fault in a
//   different order.
// sa-575307d7-r1 fresh pass (2026-08-22):
// - Baseline rebuilt at 268B/8B with both ordered calls and 152 strict diff.
// - Tested a shared source-increment goto tail, int count, integer row address,
//   outer while form, direct Orien reads, short-lived width scope, literal index
//   local, scoped count, const header/payload, orientation-first declarations,
//   int command, and a raw uchar payload cursor. These were worse or emitted
//   duplicates. Memory reads, RLE writes, row movement, calls, and cleanup were
//   kept unchanged in each test.
// - Moving the payload cursor declaration after stride is a natural declaration
//   order variant. It improved the clean candidate to 268B/8B and 150 strict
//   differing bytes. It is retained; no exact result was found.
// - Reusing td as a byte-address row cursor recovered the oracle td home and
//   92.16% shape/56.44% exact blocks, but is compiler-steering type punning. An
//   explicit shared-tail variant reached 73.27% exact blocks but 255 diff.
//   Both were rolled back. The oracle row/count homes are now proven, but the
//   natural source does not select them.
// - Strict accepted-drift review remains negative: the residue is broad setup,
//   register, and cursor-tail drift, not a small localized equivalent. The
//   natural rebuild also reads td->Orien before header fields, unlike the
//   executable. This changes invalid-input fault order, so do not promote.
// sa-575307d7-r1 continued shape pass (2026-08-22):
// - The 576-case structured source lab found no exact variant. Its natural
//   baseline family kept size, frame, calls, and 85.29% shape. Table, cursor,
//   loop, declaration, and update axes did not improve the pinned source.
//   Reported lower positional values in lab output masked object relocations;
//   they did not survive authoritative checking as a source gain.
// - A narrow-member/direct-byte/long-orientation/separate-row group reached
//   86.41% shape but 251 diff and 270 bytes. A private-ABI replay of the old
//   compiler-steering basin reached 94.12% shape and 75.25% exact blocks but
//   246 diff. Both were rolled back because strict drift grew and the source
//   needed td pointer casts or shared labels.
// - Single destination cursor, p3 parameter reuse, reversed solid updates,
//   orientation-first declarations, long Orien, register td, unqualified
//   shape_header, area alias, and typed palette were duplicates or worse.
//   The solid update probe reached 86.27% shape and 40.59% exact blocks but
//   246 diff; it was not retained as metric-only scaffolding.
// - A 12-case VC5-small flag lab emitted one group with no flag movement. A
//   32-case ambient declaration lab produced 11 eligible 268-byte variants,
//   all at the same first divergence; other variants were 271 bytes. Neither
//   context axis is a useful lead.
// sa-b67e446d-r1 exact-codegen pass (2026-08-23):
// - Replayed the binary-proven td row home, p2 byte-count home, guarded row
//   count, and shared source-advance tails from exact same-TU decoders. This
//   diagnostic source matched setup through +0x87 and reached 268B/132 diff,
//   but retained rejected td pointer punning and goto-based tail steering.
// - Adding the period <string.h> context changed that diagnostic to 268B with
//   all 101 instruction shapes and both calls aligned. Only two SIB bytes
//   remained: original palette reads use [edx+ebx], while VC5 emitted the
//   equivalent [ebx+edx]. Palette structs, references, pointer addition,
//   reversed subscripting, pointer typedefs, and array-parameter spelling did
//   not change those bytes. Narrow index locals changed the frame or prologue.
// - The two-byte frontier is not retained because its td cast and labels are
//   compiler-steering forms, not the simplest supported source. The natural
//   typed row reconstruction remains authoritative. Its known fault-order
//   difference also blocks semantic acceptance: it reads td->Orien before the
//   original header-field reads on invalid input.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void* __cdecl memset(void*, int, unsigned int);

#pragma function(memset)

typedef unsigned char uchar;

class Shape_Header {
public:
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

class TDrawArea {
public:
    char gap_00[0x08];
    uchar* Bits;           // +0x08
    void* BitmapInfo;      // +0x0C
    void* Bitmap;          // +0x10
    void* OldBitmap;       // +0x14
    int Width;             // +0x18
    int Height;            // +0x1C
    int Pitch;             // +0x20
    int Orien;             // +0x24
    char ClipRect[0x10];   // +0x28
    char _tail_38[0xC8];

    long AlignedWidth();
};

class Shape_File_Header {
public:
    long version;
    long shape_num;
};

class Shape_Offsets {
public:
    long shape;
    long palette;
};

class SLhape_File_Header {
public:
    char Version[4];
    long Num_Shapes;
    char Comment[24];
};

class Shape_Info {
public:
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

struct Shape_Payload {
    uchar value;
};


class TShape {
public:
    uchar* shape;                   // +0x00
    int load_type;                  // +0x04
    int load_size;                  // +0x08
    Shape_Header* shape_header;     // +0x0C
    Shape_File_Header* head;        // +0x10
    Shape_Offsets* offsets;         // +0x14
    SLhape_File_Header* FShape;     // +0x18
    Shape_Info* shape_info;         // +0x1C

private:
    uchar shape_color_trans_unclipped(TDrawArea* td, long p2, long p3, long p4, uchar* pal);
};

uchar TShape::shape_color_trans_unclipped(TDrawArea* td, long p2, long p3, long p4, uchar* pal)
{
    Shape_Header* hdr = this->shape_header;
    long width = (hdr->ymax - hdr->ymin) + 1;

    int Orien = td->Orien;
    long stride = td->AlignedWidth() * Orien;
    Shape_Payload* src = (Shape_Payload*)(hdr + 1);
    uchar count;
    uchar* row;
    long dest_off;
    if (Orien < 1) {
        dest_off = (p3 - td->Height + 1) * stride;
    } else {
        dest_off = p3 * stride;
    }
    row = td->Bits + p2 + dest_off;

    if (width > 0) {
        do {
            uchar done = 0;
            uchar* dst = row;
            do {
                uchar b = src++->value;
                if ((b & 1) == 1) {
                    count = b >> 1;
                    if (count == 0) {
                        dst += src->value;
                        src++;
                    } else {
                        uchar* end = dst + count;
                        while (dst < end) {
                            *dst = pal[src->value];
                            src++;
                            dst++;
                        }
                    }
                } else {
                    count = b >> 1;
                    if (count == 0) {
                        done = 1;
                    } else {
                        memset(dst, pal[src->value], count);
                        src++;
                        dst += count;
                    }
                }
            } while (!done);

            row += stride;
        } while (--width);
    }

    return 1;
}
