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
// - Session follow-up: the size-left final-bound spelling and a late typed
//   surface local were rolled back (the former worsened CFG and the latter was
//   a codegen duplicate).  Keep this canonical COM/RECT source; remaining
//   drift is the isolated VC5 save/register and argument scheduling basin.
// FLAGS: none. Inline asm forbidden.
// Best retained source: canonical typed COM/RECT reconstruction, 219 bytes,
// frame 0x10, 2/2 calls aligned, diff=199.
// Main-agent audit confirmed canonical panel/draw-area/DirectDraw ownership;
// no dead-store or COM scheduling steering survives.
// Matching-worker continuation: an early typed surface cache worsened the
// resync basin (203 differing bytes), while restoring the full donor TPanel
// virtual surface was a codegen duplicate.  Retain the clean 219-byte source;
// the unresolved gap remains the isolated COM vtable/save-register and
// parameter-home scheduling basin, not call/ABI/layout uncertainty.
// fresh orch-view-02 pass: a late source-RECT pointer and named destination
//   coordinate locals were codegen duplicates; restored clean.
// fresh pass: 16 natural RECT/call-form variants produced four groups and no
//   exact result; all 12 size-eligible variants retained the extra EBX save.
// fresh pass: debug-context flag lab (64 variants, /Zd /Zi /Z7) produced no
//   distinct winning group or exact match; default flags remain authoritative.
// fresh pass: volatile force preserved a post-call home store and improved
//   resync by one byte but grew to 221 bytes; diagnostic only, restored.
// fresh pass: reordered RECT stores, function-scope RECT/entry locals, flat
//   long[8] queue access, and reference-parameter RECT ABI were duplicates or
//   worse; canonical typed COM/RECT source retained.
// wave21 probe: replaced gap-only panel/view declarations with the proven
//   TPanel/RGE_View field ownership, including Blt_Queue_Allocated and the
//   render rectangles; emitted code was unchanged (219B, diff=199).
// wave21 probe: added the proven RGE_View virtual dispatch declarations to
//   restore the view.h-shaped derived context; emitted code was unchanged.
// sa-f48fba19-r1 pass: the full inferred TPanel/RGE_View virtual slot surface
//   was a codegen duplicate; a late TDrawArea receiver local, address-taken
//   force-result pointer, and named source-left temporary were also duplicates.
// sa-f48fba19-r1 pass: windows.h/standard RECT context reached the prior
//   diagnostic 195-byte group but worsened shape and retained EBX; DWORD
//   BltFast signedness was duplicate. A narrow volatile force-home store
//   improved resync but grew to 221 bytes, and a late queue-size local plus
//   short-circuit early guard were duplicates; all were rolled back.
// orch-00534A00-L pass: baseline after claim remained 219B, diff=199, with
//   2/2 ordered calls and an extra EBX save from the first paired hunk.
// orch-00534A00-L pass: assigning the result to src.bottom, using an entry
//   reference, reversing destination add operands, restoring 51 RGE_View
//   slots, and using C-interface lpVtbl calls were codegen duplicates.
// orch-00534A00-L pass: windows.h RECT context reached diff=195 but reduced
//   shape and resync. Restored the canonical local RECT source; blocker is
//   TU-sensitive VC5 save/register and COM argument scheduling.
// follow-534A00-r1: exact view.cpp TPanel virtual surface and reduced RGE_View
//   surface were duplicate; positive status-gate topology was also duplicate.
// follow-534A00-r1: donor RGE_View destructor, opaque BltFast source pointer,
//   full TDrawArea extent, and IDirectDrawSurface:IUnknown inheritance were
//   each codegen duplicates; restored canonical typed ownership after each.
// Paused: the remaining mismatch is the extra EBX save and COM argument/source
//   scheduling basin; no canonical ownership or virtual-slot uncertainty remains.
// sa09-ProcessQueuedBlit reassessment: pointer arithmetic, RECT/entry declaration
//   order, aggregate and zero RECT initialization, late surface/entry aliases,
//   discarded BltFast result, explicit queued guard, reversed bound terms, and
//   SDK DWORD coordinate types were duplicates or worse. Restored this clean
//   typed source; the first mismatch remains the extra EBX save at +0003.
// sa-f2967bfc-r1 continuation: protected access matched the original IAEXH
//   symbol but did not change codegen. A named BltFast flags value was also a
//   duplicate. Restored the canonical source; the extra EBX save remains.
// sa-d5f42b52-r1 continuation: source-RECT declaration order and function scope,
//   queue-entry pointer scope, an address-taken force result, and the proven
//   TPanel virtual surface were all codegen duplicates (219B, diff=199).
//   A natural five-form source lab (surface alias, entry reference, aggregate
//   RECT, and direct queue indexing) produced only two nonexact groups; all
//   size-eligible variants retained the extra EBX save. A 128-sample neutral
//   ambient declaration sweep also produced no new group. Restore the pinned
//   source; the isolated save/register and COM scheduling basin remains.
// sa-900450cb reassessment: destination-coordinate locals, string.h and
// windows.h context, a polymorphic TDrawArea, a full DirectDraw method surface,
// a named BltFast result, and size-left final-bound spelling were each natural
// probes. They were duplicate or worse (the headers reached diff=195 with
// weaker shape). Restored the pinned 219-byte source; extra EBX save remains.

// sa-cd1ad2b3-r1 strict-span audit: the 14 spans total 199 bytes. The first
//   span is the extra EBX save. It shifts every later branch and stack home.
//   The first paired body hunk then shows early &src materialization before
//   push 16. This keeps the source-top value in EBX instead of EBP. It also
//   changes RECT stores, the receiver color, and COM push order. The final
//   hunk is separate: VC5 removes the dead BltFast result store, loads
//   Current_Blit before Blit_Queue_Size, and swaps CMP operands. The epilogue
//   has the matching EBX pop and two trailing NOPs.
// sa-cd1ad2b3-r1 H1-H20: long result, area/surface pointer and reference
//   aliases, named index and offset locals, period header contexts, combined
//   status guard, delayed RECT pointer, int/unsigned RECT fields, nested
//   failure guards, explicit casts, increment spellings, and a named final
//   index were duplicate, worse, or invalid-context probes. No probe changed
//   the 219-byte clean source basin.
// sa-cd1ad2b3-r1 conclusion: extra EBX save, COM argument/source scheduling,
//   and dead-result-store behavior remain isolated VC5/TU-context drift.
//   Restore and retain the pinned natural typed source.

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

    TPanel* previous_panel;            // +0x04
    TPanel* previous_modal_panel;      // +0x08
    long pnl_x;                        // +0x0C
    long pnl_y;                        // +0x10
    long pnl_wid;                      // +0x14
    long pnl_hgt;                      // +0x18
    char* panel_name;                  // +0x1C
    TDrawArea* render_area;            // +0x20
    tagRECT clip_rect;                 // +0x24
    char gap_34[0xF4 - 0x34];
};

class RGE_View : public TPanel {
public:
    // RGE_View's own virtual surface is part of the original view.h context;
    // these declarations are not used by ProcessQueuedBlit, but preserve the
    // derived type's real dispatch boundary for this TU.
    virtual int do_paint(long, long, long, long, int);
    virtual void draw_multi_object_outline();
    virtual void end_scroll_view();
    virtual int handle_scroll_view(long, long);
    virtual int pick_through_fog(void*);
    virtual int pick_weight(void*, int);
    virtual int start_scroll_view(unsigned char, long, long, int, int);

    TDrawArea* cur_render_area;        // +0xF4
    int calc_draw_count;               // +0xF8
    void* world;                        // +0xFC
    void* player;                       // +0x100
    void* map;                          // +0x104
    short tile_wid;                     // +0x108
    short tile_hgt;                     // +0x10A
    short tile_half_wid;               // +0x10C
    short tile_half_hgt;               // +0x10E
    short elev_hgt;                     // +0x110
    short render_rect_wid;             // +0x112
    short render_rect_hgt;             // +0x114
    short max_col_num;                  // +0x116
    short max_row_num;                  // +0x118
    short center_scr_col;               // +0x11A
    short center_scr_row;               // +0x11C
    short center_scr_col_offset;        // +0x11E
    short center_scr_row_offset;        // +0x120
    short center_map_col;               // +0x122
    short center_map_row;               // +0x124
    short start_scr_col;                // +0x126
    short start_scr_row;                // +0x128
    short start_map_col;                // +0x12A
    short start_map_row;                // +0x12C
    char gap_12E[2];
    int map_scr_x_offset;               // +0x130
    int map_scr_y_offset;               // +0x134
    float last_view_x;                  // +0x138
    float last_view_y;                  // +0x13C
    unsigned char function_mode;        // +0x140
    unsigned char function_parm;        // +0x141
    unsigned char render_terrain_mode;  // +0x142
    char gap_143[1];
    long sel_col1;                      // +0x144
    long sel_row1;                      // +0x148
    long sel_col2;                      // +0x14C
    long sel_row2;                      // +0x150
    short save_paint_terrain;           // +0x154
    char gap_156[2];
    void* white_pen;                    // +0x158
    void* red_pen;                      // +0x15C
    void* hollow_brush;                 // +0x160
    void* border_line_shape;            // +0x164
    unsigned char scroll_action;        // +0x168
    char gap_169[3];
    long mouse_last_x;                  // +0x16C
    long mouse_last_y;                  // +0x170
    void* movable_object;               // +0x174
    void* terrain_clip_mask;            // +0x178
    void* terrain_fog_clip_mask;        // +0x17C
    void* master_clip_mask;             // +0x180
    void* tile_edge_tables;             // +0x184
    void* black_edge_tables;            // +0x188
    tagRECT overlaid_panel;              // +0x18C
    int overlaid_panel_active;           // +0x19C
    unsigned char edge_number[0x100];   // +0x1A0
    int limited_render_rect;            // +0x2A0
    int use_rect2;                      // +0x2A4
    tagRECT render_rect1;               // +0x2A8
    tagRECT render_rect2;               // +0x2B8
    void** float_scroll_offsets;        // +0x2C8
    int float_scroll_offsets_sz;        // +0x2CC
    int Float_X_Delta;                  // +0x2D0
    int Float_Y_Delta;                  // +0x2D4
    int Queued_Blits;                  // +0x2D8
    Blit_Queue_Entry* Blit_Queue;      // +0x2DC
    int Blit_Queue_Size;               // +0x2E0
    int Blt_Queue_Allocated;            // +0x2E4
    int Current_Blit;                  // +0x2E8
    int Blit_Offset_X;                 // +0x2EC
    int Blit_Offset_Y;                 // +0x2F0
    long real_old_map_col;              // +0x2F4
    long real_old_map_row;              // +0x2F8
    void* pick_lists[5];                // +0x2FC
    int pick_list_size[5];              // +0x310
    TDrawArea* save_area1;              // +0x324
    unsigned char* LastRenderBits;      // +0x328
    void** RenderOffsets;               // +0x32C
    int LastRenderSize;                 // +0x330
    void* prior_objs;                   // +0x334
    void* futur_objs;                   // +0x338
    int UC_ObjectTouched;               // +0x33C
    int UC_TouchedObj;                  // +0x340
    unsigned long UC_StartTime;         // +0x344
    unsigned long UC_ElapsedTime;       // +0x348
    void* message_panel;                // +0x34C
    void* extra_sprites;                // +0x350
    void* DispSel_List;                 // +0x354
    int DispSel_List_Size;              // +0x358
    int DispSel_List_Max;               // +0x35C

protected:
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
