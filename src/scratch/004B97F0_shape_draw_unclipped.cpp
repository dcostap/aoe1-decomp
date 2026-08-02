// 004B97F0 TShape::shape_draw_unclipped
// Shape.cpp:777-836, 232 bytes
//
// Attempt log:
// (prior worker) parked claiming VC5 always inlines memcpy/memset with /O2 and
// no pragma prevents it — contradicted by DibWriteClipped (00439BE0, exact)
// which uses #pragma function(memcpy), and by shape_mirror_unclipped
// (004BA900) which emits a real memset call via a plain extern declaration.
//
// sa-8a05ceeb rewrite: forward RLE draw, modeled on the mirror sibling plus
// the observed memcpy(0054DAC0)/memset(0054DA60) call surface. No CRT headers
// are included so the /Oi intrinsic pragma never activates; manual extern
// declarations keep memcpy/memset as real calls with matching relocations.
//
// baseline (kind=baseline): two-pointer reconstruction (outer d + inner w
//   cursor), (b&1)==1 idiom, TShape_Caller local class. 239B rebuilt vs 232
//   orig, shape 68.09%, prologue has sub esp,8 (extra c slot) and
//   da->ebp/height->edi coloring vs orig da->ebx/height->ebp.
// probe (context): real TShape/TDrawArea class surfaces from matched donors
//   -> byte-identical code (class surface irrelevant here).
// probe (layout): single shared `unsigned char c` declared before the two
//   branches -> extra slot gone (frame none, push ecx), shape 76.60%,
//   diff 215/232, exact-blocks 37%. Inner loop matches (and cl,1 / cmp cl,1,
//   c home [esp+20h], w/d row-end reload). REMAINING (localized): prologue
//   register coloring (da->ebp/Orien->ebx/height->edi/p->esi vs orig
//   da->ebx/height->ebp/Orien->esi/p->edi) and rows/d stack-home swap
//   (rebuilt rows->param_2,d->param_1 vs orig rows->param_1,d->param_2).
//   Calls 3/3 aligned (alignedwidth/memcpy/memset). Next lead: probe source
//   declaration order rows-before-d and single height counter to flip the
//   allocator basin; consider variant_lab on the prologue scheduling.
// Left in scratch: exact matching genuinely close but register-coloring
//   basin not yet flipped; all call/stack/behavior evidence aligned.

#pragma function(memcpy)
#pragma function(memset)

void* __cdecl memcpy(void* dest, const void* src, unsigned int count);
void* __cdecl memset(void* dest, int c, unsigned int count);

struct Shape_Header {
    long bounds;    // +0x00
    long origin;    // +0x04
    long xmin;      // +0x08
    long ymin;      // +0x0C
    long xmax;      // +0x10
    long ymax;      // +0x14
};

class TDrawArea {
public:
    char gap_00[8];
    unsigned char* Bits;    // +0x08
    char gap_0C[0x10];
    int Height;             // +0x1C
    int Pitch;              // +0x20
    int Orien;              // +0x24
    long AlignedWidth();
};

class TShape {
public:
    unsigned char* shape;       // +0x00
    int load_type;              // +0x04
    int load_size;              // +0x08
    Shape_Header* shape_header; // +0x0C
    void* head;                 // +0x10
    void* offsets;              // +0x14
    void* FShape;               // +0x18
    void* shape_info;           // +0x1C

    unsigned char shape_draw_unclipped(TDrawArea*, long, long, long);
};

unsigned char TShape::shape_draw_unclipped(TDrawArea* da, long y, long x, long table)
{
    Shape_Header* sh = this->shape_header;
    long height = sh->ymax - sh->ymin + 1;
    unsigned char* p = (unsigned char*)(sh + 1);
    long pitch = da->AlignedWidth() * da->Orien;
    long m;
    if (da->Orien < 1)
        m = (x - da->Height + 1) * pitch;
    else
        m = x * pitch;
    unsigned char* d = da->Bits + m + y;
    long rows = height;

    if (height > 0) {
        do {
            unsigned char done = 0;
            unsigned char* w = d;
            do {
                unsigned char b = *p++;
                unsigned char c;
                if ((b & 1) == 1) {
                    c = b >> 1;
                    if (c) {
                        memcpy(w, p, c);
                        w += c;
                        p += c;
                    } else {
                        w += *p;
                        p++;
                    }
                } else {
                    c = b >> 1;
                    if (c) {
                        unsigned char t = *p;
                        memset(w, t, c);
                        w += c;
                        p++;
                    } else {
                        done = 1;
                    }
                }
            } while (!done);
            d += pitch;
        } while (--rows);
    }

    return 1;
}
