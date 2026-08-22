// VA: 005346F0 RGE_View::CreateBlitQueue
// Attempt log:
// v1 natural RECT/queue implementation with duplicated one-blit tail: compiled 780B but 94.49% positional, stack 0x14 not original 0x34.
// v2 single allocation/fill tail, top locals mirror packet names: undersized 736B under /O2, so tail sharing got closer structurally but not size.
// v3 /GX with v2: no change, still 736B; rolled back flag because no EH evidence.
// v4 /Od with v2: 780B same size but EBP-frame /Od family, 95.00% positional; rolled back flag.
// v5 kept v2 because it is cleaner and documents likely intended source, but it is not accepted-drift-safe.
// probe 6 structural/layout: restored the period TPanel render_rect at +8c/+90
// and the RGE_View queue-offset fields at +2ec/+2f0; the prior flat class put
// the panel rectangle at the wrong offsets and compiled the final assignments
// away.  The binary proves the final source is render_rect.left/top -> offsets.
// probe 7: a local yd initialized from param_4 was codegen-duplicate; retained
// only as the binary-supported vertical-delta naming clue.
// probe 8: a fixed-stride long* source-entry cursor moved to 0x2c frame / 783B
// and improved shape; direct byte-offset destination stores retained the
// original repeated queue-base reload schedule.
// probe 9: count=vBlits before off=0 reached 781B / 0x2c frame and improved
// resync; the loop counter stayed in the incoming dst-reference home.
// probe 10: hoisting count into an outer non-outside guard was one byte worse
// and lost an exact block; rolled back to probe 9.
// probe 12: removing the local yd copy and using the typed param_4 directly
// left the first hunk and all metrics unchanged; restored the clean source.
// probe 14: swapped loop counter initialization; output grew to 783B and was rolled back.
// probe 15: inlined boundary loads into the overlap predicate; VC5 emitted duplicate code.
// probe 16: used the binary's outside-marker slot directly; duplicate code.
// probe 18: boundary declaration order was duplicate; probe 19 sentinel order was worse and rolled back.
// probe 22: initialized the outside one-blit RECT from the already loaded boundary values;
// best current result is 780B, 0x24 frame, 671-byte positional diff, 61.44% shape.
// probe 23: a distinct outside marker was codegen-duplicate; retained for readable ownership.
// paused: calls, CFG counts, queue fields, clipping behavior, and output size align; frame and
// local/register topology remain structurally different. Next lead is expanded original locals.
// Reassessment pass sa-460299c2: 20 additional source hypotheses were compiled and checked.
// Decompiler-shaped locals and an explicit dword outside marker moved the frame to 0x2c but
// worsened size and shape. Aggregate RECT initialization, dead outside-arm assignments,
// scalar coordinate locals, typed queue cursors, explicit queue stores, queue ownership
// aliases, and declaration-order changes were duplicate or worse. Reversing the first two
// overlap predicates to source-left greater-than form improved shape only (62.29%). Writing
// vBlits greater-than allocated improved the best clean basin to 668 differing bytes and
// 62.71% shape, but the frame stayed 0x24. The pinned natural source remains the clean
// reconstruction. Calls are 2/2 aligned, size is 780, CFG counts are 23/23 conditions,
// 5/5 jumps, and 1/1 return; unresolved evidence is the original 0x34 local frame and
// register/stack topology. No policy-valid exact source was found.

// Follow-up sa-476ae437-r1: the original PDB locals show One_Blit as the
// outside marker, nBlits as the final count, and yd/nBlits sharing a home.
// Renaming roles alone was duplicate. Reusing nBlits for the absolute-y
// denominator before its count assignment reduced the mismatch to 664 bytes
// and raised shape to 68.94%; this is retained as the smallest supported
// lifetime model. Matching blt_deltaX/Y names and a PDB yd alias were
// duplicates. Reversing the first two overlap comparisons to source-bound
// greater-than form raised shape to 69.79% without changing the 664-byte
// mismatch. A local bounds RECT and SDK windows/tagRECT context were
// duplicates or worse. The capacity guard written as nBlits greater than
// allocated raised shape to 70.64%, exact-block coverage to 12.77%, and gave
// a 665-byte mismatch; this source form is retained because its cmp/jle
// direction matches the executable. Reversing allocation stores and adding a
// typed calloc result local were worse or codegen-duplicate. Final current
// result: 780 bytes, 0x24 frame versus original 0x34, 2/2 ordered calls,
// 23/23 conditions, 5/5 jumps, 1/1 return, 665 differing bytes. The blocker
// remains the original four boundary spill slots and prologue register/home
// topology. No accepted-drift residue is supported.

extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);

struct tagRECT { long left; long top; long right; long bottom; };
struct Blit_Queue_Entry { tagRECT src; tagRECT dest; };

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual long vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw();
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    char gap_004[0x10];
    int pnl_wid;                         // +0x14
    int pnl_hgt;                         // +0x18
    char gap_01c[0x54];
    int visible;                         // +0x70
    char gap_074[0x18];
    tagRECT render_rect;                 // +0x8c
    char gap_09c[0x23c];                 // through +0x2d7
};

class RGE_View : public TPanel {
public:
    int Queued_Blits;
    Blit_Queue_Entry* Blit_Queue;
    int Blit_Queue_Size;
    int Blt_Queue_Allocated;
    int Current_Blit;
    int Blit_Offset_X;
    int Blit_Offset_Y;
    void CreateBlitQueue(tagRECT& src, tagRECT& dst, int xd, int yd);
};

void RGE_View::CreateBlitQueue(tagRECT& param_1, tagRECT& param_2, int param_3, int param_4)
{
    int nBlits;
    int yd;
    tagRECT blt_src;
    int local_4;
    int One_Blit = 0;
    int vBlits;
    int blt_deltaX;
    int blt_deltaY;
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar6;
    int xd;
    int off;
    int count;
    yd = param_4;
    if ((param_3 != 0) || (yd != 0)) {
        if (((iVar6 = param_1.top) > param_2.bottom) ||
            (((iVar1 = param_1.left, iVar1 > param_2.right ||
              (iVar2 = param_1.bottom, iVar2 < param_2.top)) ||
             (iVar3 = param_1.right, iVar3 < param_2.left)))) {
            One_Blit = 1;
            nBlits = 1;
            blt_src.left = iVar1;
            blt_src.top = iVar6;
            blt_src.right = iVar3;
            local_4 = iVar2;
        } else {
            nBlits = param_4;
            if (nBlits < 0) nBlits = -nBlits;
            xd = param_3;
            if (xd < 0) xd = -xd;
            vBlits = 9999;
            if (param_4 != 0) vBlits = (nBlits + (iVar2 - iVar6)) / nBlits;
            nBlits = 9999;
            if (param_3 != 0) nBlits = (xd + (iVar3 - iVar1)) / xd;
            blt_src.left = param_1.left;
            blt_src.top = param_1.top;
            blt_src.right = param_1.right;
            local_4 = param_1.bottom;
            blt_deltaX = 0;
            blt_deltaY = 0;
            if (vBlits < nBlits) {
                nBlits = vBlits;
                blt_deltaY = param_4;
                if (param_4 < 0) blt_src.top = param_4 + iVar2 + 1;
                else local_4 = param_4 + iVar6 - 1;
            } else {
                blt_deltaX = param_3;
                if (param_3 < 0) blt_src.left = param_3 + iVar3 + 1;
                else blt_src.right = param_3 + iVar1 - 1;
            }
        }

        if (nBlits > this->Blt_Queue_Allocated) {
            if (this->Blit_Queue != 0) free(this->Blit_Queue);
            this->Blit_Queue = 0;
        }
        if (this->Blit_Queue == 0) {
            this->Blit_Queue = (Blit_Queue_Entry*)calloc(nBlits, 0x20);
            this->Blt_Queue_Allocated = nBlits;
        }
        if (One_Blit) {
            this->Blit_Queue[0].src = param_1;
            this->Blit_Queue[0].dest = param_2;
        } else if (nBlits > 0) {
            count = nBlits;
            off = 0;
            do {
                long* plVar7 = (long*)((char*)this->Blit_Queue + off);
                plVar7[0] = blt_src.left;
                plVar7[1] = blt_src.top;
                plVar7[2] = blt_src.right;
                plVar7[3] = local_4;
                *(int*)((char*)this->Blit_Queue + off + 0x14) = blt_src.top - param_4;
                *(int*)((char*)this->Blit_Queue + off + 0x10) = blt_src.left - param_3;
                *(int*)((char*)this->Blit_Queue + off + 0x1c) = local_4 - param_4;
                *(int*)((char*)this->Blit_Queue + off + 0x18) = blt_src.right - param_3;
                blt_src.top += blt_deltaY;
                local_4 += blt_deltaY;
                blt_src.left += blt_deltaX;
                blt_src.right += blt_deltaX;
                if (blt_src.top < param_1.top) blt_src.top = param_1.top;
                if (blt_src.left < param_1.left) blt_src.left = param_1.left;
                if (blt_src.right > param_1.right) blt_src.right = param_1.right;
                if (local_4 > param_1.bottom) local_4 = param_1.bottom;
                off += 0x20;
                count--;
            } while (count != 0);
        }
        this->Queued_Blits = 1;
        this->Blit_Queue_Size = nBlits;
        this->Current_Blit = -1;
        this->Blit_Offset_X = this->render_rect.left;
        this->Blit_Offset_Y = this->render_rect.top;
    }
}
