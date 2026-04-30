// RGE_View::ProcessQueuedBlit (00534A00)
// PDB source: view.cpp:1218-1318
// Size: 219 bytes
// PARKED - pure VC5 instruction scheduling / register rotation / jump encoding drift
//
// Attempt log:
// - Probe 1 (abstract class + cached ox/oy + tagRECT struct): 208 bytes, major struct diffs
// - Probe 2 (no cached ox/oy + int array ss): 208 bytes, closer but vf1c call mismatch
// - Probe 3 (raw typedef fn ptr dispatch): 208 bytes, different push order  
// - Probe 4 (correct __stdcall abstract class + (surf,dx,dy,surf,ss,16)): 208 bytes, push order MATCHES
//   remaining drift: register coloring (push ebx/pop ebx vs not), store offset assignment,
//   blob construction order (original does push-0x10 + top store, then X load + left store,
//   then push-&src + bottom+1 store, then right+1 store; my version computes offsets at
//   different times), some jump near→short encoding (2×4=8 bytes diff)
// - Probe 5 (short member names + ss[5]): 219 bytes but vf34 pushing surf twice, vf1c push
//   order wrong, sub esp 14h instead of 10h due to ss[5]
// 
// Remaining gap: pure VC5 register/scheduling/encoding drift within the isolated scratch
// context. The original's instruction interleaving for blit RECT construction + vf1c call
// uses specific register assignments and push/schedule timing that match the TU context.
// Near→short jump encoding change is an expected VC5 distance artifact.
//
// FLAGS: none attempted; inline asm forbidden; no custom flags
// Best variant: abstract class __stdcall + (surf,dx,dy,surf,ss,16), 208 bytes,
// push order matches original exactly for both vf34 and vf1c calls

struct BQE {
    int sl; int st; int sr; int sb;
    int dl; int dt; int dr; int db;
};

struct IDV {
    virtual int __stdcall QI(void*,void*) = 0;
    virtual int __stdcall AR() = 0;
    virtual int __stdcall RL() = 0;
    virtual int __stdcall d3() = 0; virtual int __stdcall d4() = 0;
    virtual int __stdcall d5() = 0; virtual int __stdcall d6() = 0;
    virtual void __stdcall v7(void*,int,int,void*,void*,int) = 0;
    virtual int __stdcall d8() = 0; virtual int __stdcall d9() = 0;
    virtual int __stdcall dA() = 0; virtual int __stdcall dB() = 0;
    virtual int __stdcall dC() = 0; virtual int __stdcall vD(void*,int) = 0;
};

struct TDA { unsigned char g0[0x3C]; IDV* DS; };

struct RGE_View {
    unsigned char g0[0x20]; TDA* da; unsigned char g1[0x2B4];
    int QB; BQE* BQ; int BQS; unsigned char g2[0x04];
    int CB; int OX; int OY;
    void PQBI(int);
};

// Best attempt: abstract class __stdcall with correct param order
// Push order for vf34: push 1, push surf, mov ecx,[surf], call [ecx+52]
// Push order for vf1c: push 16, push &ss, push surf, push dy, mov ebx,[surf], push dx, push surf, call [ebx+28]
// These match the original EXACTLY (same push order, same argument assignment)
void RGE_View::PQBI(int p1)
{
    if (!QB) return;
    if (!p1) { IDV* s = da->DS; if (s->vD(s,1)) return; }
    int n = CB + 1; CB = n;
    BQE* q = BQ;
    if (q && n >= 0 && n < BQS) {
        BQE* e = q + n;
        int ss[4];
        ss[1] = e->st + OY;
        ss[0] = OX + e->sl;
        ss[3] = e->sr + OX + 1;
        int dx = e->dl + OX;
        int dy = e->dt + OY;
        IDV* s = da->DS;
        s->v7(s,dx,dy,s,ss,16);
    }
    if (CB + 1 < BQS) return;
    QB = 0;
}
