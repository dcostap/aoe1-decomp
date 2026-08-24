// VA: 0047A910 TScrollBarPanel::set_rect(long, long, long, long)
// PDB source: Pnl_scbr.cpp lines 139-193 (368 bytes, 95 asm lines)
// Default flags
//
// __thiscall: this in ecx, 4 stack params, ret 10h. void return.
//
// Calls TPanel::set_rect then updates scrollbar rects based on orientation.
#include <new.h>

// Attempt log:
// 1: baseline natural field reconstruction; exact size/calls but calc_item_rects was a free cdecl helper,
//    missing EBP and emitted explicit this push/add-esp around both calls.
// 2: made calc_item_rects a member; call ABI became thiscall, but source still had the wrong register/liveness basin.
// 3: restored the proven TPanel base size/vptr; emitted code was unchanged.
// 4: replaced offset aliases with canonical tagRECT members; diff improved to 282 bytes and size/calls stayed exact.
// 5: compound-update liveness variant moved farther (328 bytes); rolled back to the clean tagRECT candidate.
// Paused: ordered calls/CFG and exact field offsets are established, but the remaining gap is early register/block
// topology (not a behavior or call-set uncertainty). Next lead is a natural Pnl_scbr donor/source-order comparison,
// especially the branch-local declaration order that makes EBP live from the prologue in both orientation arms.
// Fresh bounded pass (sa3cf31e29_r1, probes 034-043):
// - Shared function-scope geometry results and source-order/store-order variants moved the emitted basin to
//   275-276 strict bytes; the best natural form is exact size with 3/3 ordered calls and 68.42% shape similarity.
// - A shared range accumulator recovered the original-size basin without stack spill; initializing it was a
//   codegen duplicate.  Reordered rectangle stores improved edit/resync diagnostics but not positional bytes.
// - The proven virtual base/override surface with a qualified TPanel::set_rect call preserved the direct call;
//   an unqualified virtual call was rejected because it emitted an indirect target.  <new.h> TU context was a
//   donor-supported duplicate and is retained as period-plausible context.
// - Full Windows header context, direct-width spelling, declaration reordering, and virtual-only surfaces were
//   nonproductive or worse.  Final blocker remains the original early EBP save/register topology; no behavior,
//   layout, boundary, or call-set uncertainty remains.
// Bounded pass (sa-e2d0dd53-r1):
// - Tested function-scope top/bottom/left/right/range/tab locals with chained shared top assignments; this grew
//   the body to 374 bytes, diff 332, shape 63.16%, and was rolled back.
// - Reordered the horizontal range expression to perp plus margin, then subtract button; VC5 emitted the same
//   368-byte code as the clean source (diff 275, shape 68.42%), so it was rolled back.
// - Clean natural typed source retained.  The early EBP save remains the only structural lead.
// Current bounded pass (orch-47A910-a):
// - Branch-local range declarations and direct range expressions were codegen duplicates.
// - Direct vertical geometry reads improved the strict diff from 275 to 272 bytes and shape to 69.47%; retained.
// - Direct horizontal geometry reads added 5 bytes and worsened shape; rolled back.
// - Donor virtual method declarations and a shared down_right local were codegen duplicates; removed for source clarity.
// - Final blocker remains the prologue EBP save and associated register/block topology.
// Fresh bounded pass (sa-28199e0c):
// - The available Pnl_scbr donor reconstruction with direct geometry expressions and const long locals produced
//   the best natural basin: exact size, 3/3 ordered calls, early EBP save, 17.89% exact-block coverage, 138-byte
//   strict diff, and 76.84% shape similarity. It was not exact and was restored before final validation.
// - Widening the proven panel dimensions to long was a codegen duplicate. Shared range and function-scope local
//   variants were duplicates or returned to the 272-byte clean basin. Grouped store order made the result worse.
// - The clean typed source remains pinned. The blocker is still register assignment and source scheduling after
//   the base call; behavior, direct calls, boundary, and field ownership remain established.
// Fresh bounded pass (sa-03683be2):
// - Restored the donor-supported const-long geometry source and tested interleaved typed rectangle stores,
//   direct member dependencies, vertical declaration order, and explicit range/up-edge locals.
// - The best natural result stayed at 138 strict bytes, exact size, 3/3 ordered calls, and 76.84% shape.
// - The target's early EBP and post-base-call register map did not follow these source-level variants.
// - Restored the pinned clean source. No behavior, ABI, layout, boundary, or call-set uncertainty was found.
// Revisit pass (sa-79cd7e4d-r1, probes 038-048):
// - Revalidated the 138-byte const-long donor basin, then tested natural range, store-order, chained-store,
//   declaration-order, and decompiler-supported shared-local variants. None produced an exact result.
// - The best result remained 138 strict bytes with exact size, 3/3 ordered calls, early EBP save, and 76.84%
//   shape similarity. The shared six-local form reached 293 bytes; it was discarded.
// - Restored the pinned clean source. Final blocker remains register assignment and post-base-call scheduling;
//   behavior, ABI, layout, boundary, and call-set evidence remain established.
// - Accepted-drift audit: do not promote this candidate. The final geometry
//   values and three calls match, but both orientation branches publish the
//   rectangle and tab members in a different order before calc_item_rects.
//   Partial-object faults or observers can see a different intermediate state.
// Fresh bounded pass (sa-2d9b00bf-r1, probes 052-067):
// - A direct PDB/Ghidra publication-order reconstruction grew the body to 387 bytes and reached 311-byte diff;
//   it was rejected.  The donor-supported const-long source restored the best 138-byte diff and 76.84% shape.
// - Moving down-left declarations, sharing range locals across arms, mutable range updates, interleaved stores,
//   explicit up-edge locals, and narrow/wide field variants did not improve the 138-byte basin.  The best source
//   remains exact size with 3/3 ordered calls, an early EBP save, and 17.89% exact-block coverage.
// - Canonical local Pnl_scbr source confirms the rectangle ownership and const-long geometry form.  Adding its
//   early virtual overload surface, typed derived fields, and orientation enum was codegen-neutral.
// - Final blocker is the target EBP/range register map after the base call.  Behavior, ABI, layout, boundary,
//   direct calls, and field ownership remain established.  Accepted drift remains prohibited because publication
//   order differs before calc_item_rects on both orientation paths.

#ifndef PNL_SCBR_CANONICAL_TU
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct TPanel {
    virtual ~TPanel();
    char gap_04[0x0C - 0x04];
    int margin;                // +0x0C (panel edge offset)
    int track_size;            // +0x10 (track dimension in scroll direction)
    int perp_size;             // +0x14 (track dimension perpendicular to scroll)
    int button_size;           // +0x18 (arrow/button dimension)
    char gap_1C[0xF4 - 0x1C];
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
};

struct TScrollBarPanel : public TPanel {
    char gap_F4[0x124 - 0xF4];
    int tab_y;                 // +0x124
    int tab_min_y;             // +0x128
    int tab_max_y;             // +0x12C
    char gap_130[0x134 - 0x130];
    int tab_x;                 // +0x134
    int tab_min_x;             // +0x138
    int tab_max_x;             // +0x13C
    char gap_140[0x164 - 0x140];
    tagRECT up_rect;            // +0x164
    tagRECT down_rect;          // +0x174
    tagRECT tab_rect;           // +0x184
    tagRECT top_rect;           // +0x194
    tagRECT bottom_rect;        // +0x1A4
    int orientation;           // +0x1B4 (1 = horizontal)

    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    void calc_item_rects();
};
#endif

void TScrollBarPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TPanel::set_rect(param_1, param_2, param_3, param_4);

    if (this->orientation == 1) {
        const long base_top = this->track_size + 2;
        const long track_bottom = this->track_size + this->button_size - 5;

        this->up_rect.left = this->margin + 2;
        this->up_rect.top = base_top;
        this->up_rect.right = (this->margin + 2) + this->button_size - 5;
        this->up_rect.bottom = track_bottom;

        const long down_left = (this->margin + this->perp_size - this->button_size) + 2;
        this->down_rect.left = down_left;
        this->down_rect.top = base_top;
        this->down_rect.right = down_left + this->button_size - 5;
        this->down_rect.bottom = track_bottom;

        this->tab_rect.top = base_top;
        this->tab_rect.bottom = track_bottom;
        this->top_rect.top = base_top;
        this->top_rect.bottom = track_bottom;
        this->bottom_rect.top = base_top;
        this->bottom_rect.bottom = track_bottom;

        this->tab_min_x = this->up_rect.right + 1;
        this->tab_max_x = (down_left - this->button_size) + 4;
        this->tab_x = this->tab_min_x;
    } else {
        const long base_left = this->margin + 2;
        const long track_right = this->margin + this->perp_size - 5;

        this->up_rect.left = base_left;
        this->up_rect.top = this->track_size + 2;
        this->up_rect.right = track_right;
        this->up_rect.bottom = (this->track_size + 2) + this->perp_size - 5;

        const long down_top = (this->track_size + this->button_size - this->perp_size) + 2;
        this->down_rect.left = base_left;
        this->down_rect.top = down_top;
        this->down_rect.right = track_right;
        this->down_rect.bottom = down_top + this->perp_size - 5;

        this->tab_rect.left = base_left;
        this->top_rect.left = base_left;
        this->bottom_rect.left = base_left;
        this->tab_rect.right = track_right;
        this->top_rect.right = track_right;
        this->bottom_rect.right = track_right;

        this->tab_max_y = (down_top - this->perp_size) + 4;
        this->tab_min_y = this->up_rect.bottom + 1;
        this->tab_y = this->tab_min_y;
    }

    this->calc_item_rects();
}
