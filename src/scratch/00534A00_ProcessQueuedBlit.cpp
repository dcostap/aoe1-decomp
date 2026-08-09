// RGE_View::ProcessQueuedBlit (00534A00)
// PDB source: view.cpp:1218-1318
// Size: 219 bytes
//
// Attempt log:
// - Old parked state: wrong ss slot mapping (src.right written to index 3),
//   missing src.bottom entry, ss[5]-induced sub esp,14h frame. Rewrote from scratch.
// - Canonical ownership (ground truth): render_area(TDrawArea*)@+0x20,
//   DrawSurface(IDirectDrawSurface*)@TDrawArea+0x3C; Queued_Blits@+0x2D8,
//   Blit_Queue@+0x2DC, Blit_Queue_Size@+0x2E0, Current_Blit@+0x2E8,
//   Blit_Offset_X@+0x2EC, Blit_Offset_Y@+0x2F0. Blit_Queue_Entry = 32B
//   { tagRECT src; tagRECT dest; }.
// - Vtable evidence: [vtable+0x34] = GetBltStatus(this,1) (2 args __stdcall),
//   [vtable+0x1C] = BltFast(this, dest.left+OX, dest.top+OY, DrawSurface,
//   &src, 16) (6 args __stdcall) — DirectDraw surface COM calls.
// - RECT math (binary-observed field processing order top,left,bottom,right):
//   src.top = st+OY, src.left = sl+OX, src.bottom = sb+OY+1, src.right = sr+OX+1;
//   dest coords = dl+OX, dt+OY. Final check loads Blit_Queue_Size first then
//   Current_Blit+1 (size on the left of the comparison).
// - Post-call dead store of the BltFast result into the force parameter home
//   ([esp+20h] = E+4) implies the original source reused the dead force param
//   as the call-result scratch (force = BltFast(...)).
// - Probe 1 (baseline): src.bottom=BltFast + left,top,right,bottom field order:
//   diff=197, shape=67.95%; store eliminated; field order left,top,right,bottom
//   (rebuilt preserved source order -> original wrote top,left,bottom,right).
// - Probe 2 (layout, current): top,left,bottom,right field order + force=BltFast:
//   diff=195, shape=73.08%; RECT region now matches; remaining drift is the
//   extra push ebx (vtable lands in ebx instead of edx -> one extra saved reg),
//   the &src lea/push interleave (rebuilt hoists &src before push 16), dest
//   register roles, the eliminated post-call param-slot store, and final-check
//   load order (size-first vs CB-first).
// - Left in scratch: pure VC5 register/scheduling/encoding drift inside the
//   isolated scratch TU; the post-call dead store is eliminated by VC5 here but
//   was kept in the original view.cpp TU (TU-context-sensitive DSE/scheduling).
// - Continuation: reversing the final bound comparison made the branch shape
//   worse without changing the byte diff; restored the clean source.
// - Continuation: adding the proven TPanel base improved shape but worsened the
//   byte diff; the SDK ddraw.h surface, four-dword RECT buffer, narrow surface
//   local, volatile RECT, CINTERFACE/lpVtbl calls, and unused-call-result forms
//   were duplicates or worse.
// - Main-agent normalization retained the proven TPanel inheritance and base
//   render-area ownership despite the slightly worse positional metric; the
//   shape improves and canonical source remains authoritative over register
//   steering in this unresolved function.
// FLAGS: none. Inline asm forbidden.
// Best variant: probe 2 (current source), 219 bytes, frame 0x10, 2/2 calls aligned.

struct tagRECT { long left; long top; long right; long bottom; };

struct Blit_Queue_Entry {
    tagRECT src;   // +0x0
    tagRECT dest;  // +0x10
};

// DirectDraw surface vtable (IDirectDrawSurface), slots 0..13 used:
// BltFast = slot 7 (0x1C), GetBltStatus = slot 13 (0x34).
struct IDirectDrawSurface {
    virtual long __stdcall QueryInterface(void*, void*);
    virtual long __stdcall AddRef();
    virtual long __stdcall Release();
    virtual long __stdcall AddAttachedSurface(void*);
    virtual long __stdcall AddOverlayDirtyRect(void*);
    virtual long __stdcall Blt(void*, void*, void*, unsigned long, void*);
    virtual long __stdcall BltBatch(void*, void*, unsigned long, unsigned long);
    virtual long __stdcall BltFast(long, long, IDirectDrawSurface*, tagRECT*, unsigned long);
    virtual long __stdcall DeleteAttachedSurface(unsigned long, void*);
    virtual long __stdcall EnumAttachedSurfaces(void*, void*);
    virtual long __stdcall EnumOverlayZOrders(unsigned long, void*, void*);
    virtual long __stdcall Flip(void*, unsigned long);
    virtual long __stdcall GetAttachedSurface(void*, void*);
    virtual long __stdcall GetBltStatus(unsigned long);
};

class TDrawArea {
public:
    char gap_00[0x3C];
    IDirectDrawSurface* DrawSurface;   // +0x3C
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x1C];
    TDrawArea* render_area;            // +0x20
    char gap_24[0xF4 - 0x24];
};

class RGE_View : public TPanel {
public:
    char gap_F4[0x2D8 - 0xF4];
    int Queued_Blits;                  // +0x2D8
    Blit_Queue_Entry* Blit_Queue;      // +0x2DC
    int Blit_Queue_Size;               // +0x2E0
    char gap_2E4[4];
    int Current_Blit;                  // +0x2E8
    int Blit_Offset_X;                 // +0x2EC
    int Blit_Offset_Y;                 // +0x2F0

    void ProcessQueuedBlit(int force);
};

void RGE_View::ProcessQueuedBlit(int force)
{
    if (!this->Queued_Blits)
        return;

    if (force == 0) {
        if (this->render_area->DrawSurface->GetBltStatus(1))
            return;
    }

    this->Current_Blit++;
    if (this->Blit_Queue && this->Current_Blit >= 0 && this->Current_Blit < this->Blit_Queue_Size) {
        Blit_Queue_Entry* entry = &this->Blit_Queue[this->Current_Blit];
        tagRECT src;
        src.top = entry->src.top + this->Blit_Offset_Y;
        src.left = entry->src.left + this->Blit_Offset_X;
        src.bottom = entry->src.bottom + this->Blit_Offset_Y + 1;
        src.right = entry->src.right + this->Blit_Offset_X + 1;
        force = this->render_area->DrawSurface->BltFast(
            entry->dest.left + this->Blit_Offset_X,
            entry->dest.top + this->Blit_Offset_Y,
            this->render_area->DrawSurface, &src, 16);
        if (this->Current_Blit + 1 < this->Blit_Queue_Size)
            return;
    }
    this->Queued_Blits = 0;
}
