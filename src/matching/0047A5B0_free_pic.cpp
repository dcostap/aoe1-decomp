// VA: 0047A5B0 TPicturePanel::free_pic()
// PDB: Pnl_pic.cpp lines 153-169 (117 bytes, 35 asm lines)
// Default flags. No inline asm/hacks.
//
// EXACT MATCH — 117/117 bytes, 0% positional diff, 0% edit diff
// Result: MATCH on 2026-05-12 by SpruceGlow
//
// Key insight for matching: use a LOCAL alias (TPicture* p = this->pic) for the
// outer null check and the delete calls, but use MEMBER ACCESS (this->pic) in the
// inner `if (own_pic && this->pic)` condition. The mix of local-vs-member access
// tricks VC5 into keeping the redundant `test edi,edi` inside the short-circuit &&
// check, and into preserving `edi` as the saved-pointer register.
//
// This is the EXACT source that generates the original debug-adjacent/Vc5-baseline
// codegen: push edi + mov edi = pic, redundant test edi/edi inside &&, edi used for
// both the destructor this and the operator_delete arg.

extern void __cdecl operator_delete(void*);

#ifndef PNL_PIC_CANONICAL_TU
class TPicture {
public:
    ~TPicture();
};

class TShape {
public:
    ~TShape();
};

class TPicturePanel {
public:
    char gap_00[0x10C];
    int own_pic;               // +0x10C
    char gap_110[4];
    TPicture* pic;             // +0x114
    TShape* shape;             // +0x118

    void free_pic();
};
#endif

void TPicturePanel::free_pic() {
    TPicture* p = this->pic;
    if (p != 0) {
        if (this->own_pic != 0 && this->pic != 0) {
            p->~TPicture();
            operator_delete(p);
        }
        this->pic = 0;
    }
    TShape* s = this->shape;
    if (s != 0) {
        if (this->own_pic != 0 && this->shape != 0) {
            s->~TShape();
            operator_delete(s);
        }
        this->shape = 0;
    }
    this->own_pic = 0;
}
