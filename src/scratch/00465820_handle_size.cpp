// VA: 00465820 TPanel::handle_size
// Source: Panel.cpp lines 1558-1670
// Attempt log:
// baseline: natural geometry source had correct fields/calls but an explicit vptr
// shifted every TPanel member by four bytes and the raw child call used cdecl.
// removed explicit vptr in favor of the compiler-owned virtual layout; offsets align.
// typed child->handle_size(wid,hgt) at vtable slot 0x50 fixes the thiscall ABI and cleanup.
// removed durable calc_wid and retained only the height bound; frame became push-ecx
// family and size drift fell from 18 to 8 bytes with exact call/CFG counts.
// self alias and scalar/panel declaration-order probes were codegen duplicates.
// swapped fixed-arm bottom/right assignment to follow the original min_hgt load; positional drift improved locally.
// long coordinate types and canonical named TPanel fields preserve the proven layout but do not change codegen.
// tried one shared calc_hgt for fixed and centered bottom ownership; diff worsened 494->498, so restored.
// restored proven PanelNode::prev_node; original next_node load is at +8, not +4.
// direct typed edge-panel member tests improved exact-block coverage without changing size.
// modeled the vslot+8 set_rect call as a 16-byte Rect-by-value argument; original sub-esp call setup now matches and diff is 440/592 bytes.
// full TPanel virtual overload declarations shifted the call to vslot+0xC, so the minimal slot-preserving surface remains authoritative.
// a scoped active temporary for one edge panel was a codegen duplicate; restored the direct condition.
// left unresolved: residual prologue/register coloring and set_rect/centered scheduling drift; source is typed and period-plausible.
// Main-agent audit restored the canonical virtual destructor surface; typed
// panel geometry and recursive child ownership remain authoritative. Final
// audited check: 593/585 bytes, 2/2 ordered calls, 494-byte diff.
// this claim: local tagRECT plus PositionMode enum is period-plausible and
// reaches exact size with a 437-byte diff; keep it over the 592-byte int basin.
// this claim: reused the Ghidra-supported edge-panel cursor under the enum
// surface; codegen stayed at 437 bytes, so the typed cursor remains source.
// this claim: full trailing TPanel fields through +0xF3 are layout-canonical;
// VC5 output was unchanged.
// this claim: common calc_wid/calc_hgt and SDK windows.h context were tested;
// both returned larger or older basins, so direct width and local tagRECT stay.
// this claim: rechecked typed parent/edge-panel ownership and natural resize
// expressions. Self aliases, local declaration orders, and block-local height
// lifetimes were codegen duplicates. A binary-supported shared bottom tail
// improved block shape but reached 471/576 bytes, worse than the clean 437/585
// basin, so the natural source remains pinned.
// this claim: PDB symbols name win_wid, win_hgt, i, and calc_hgt. i and
// calc_hgt share the -4 home. Function-scope i and direct member forms were
// codegen duplicates. The full PDB virtual surface improved shape but gave
// 592/585 bytes. The minimal slot surface remains the smaller source model.
// context pass: include the recovered Panel.cpp TPanel layout and PanelNode
// ownership. The scalar set_rect overload occupies vslot +0x08; the RECT
// wrapper occupies +0x0C. The source now calls the scalar overload, matching
// the original four scalar pushes and direct virtual slot identity.

#include "../../include/panel_context.h"

long TPanel::handle_size(long wid, long hgt)
{
    TPanel* p = this->parent_panel;
    long left;
    long top;
    long right;
    long bottom;
    long calc_hgt;

    if (p != 0) {
        right = p->render_rect.right;
        left = p->render_rect.left;
        top = p->render_rect.top;
        bottom = p->render_rect.bottom;
        wid = right - left + 1;
        hgt = bottom - top + 1;
    } else {
        left = 0;
        top = 0;
        right = wid - 1;
        bottom = hgt - 1;
    }

    if (this->position_mode == PositionFixed) {
        left = this->left_border + left;
        top = this->top_border + top;
        bottom = this->min_hgt + top - 1;
        right = this->min_wid + left - 1;
    } else {
        p = this->left_panel;
        if (p != 0 && p->active != 0) {
            left = this->left_border + p->render_rect.right + 1;
        } else {
            left = this->left_border + left;
        }
        p = this->top_panel;
        if (p != 0 && p->active != 0) {
            top = this->top_border + p->render_rect.bottom + 1;
        } else {
            top = this->top_border + top;
        }
        p = this->right_panel;
        if (p != 0 && p->active != 0) {
            right = p->render_rect.left - this->right_border - 1;
        } else {
            right -= this->right_border;
        }
        p = this->bottom_panel;
        if (p != 0 && p->active != 0) {
            bottom = p->render_rect.top - this->bottom_border - 1;
        } else {
            bottom -= this->bottom_border;
        }

        calc_hgt = bottom - top + 1;
        long limit = this->min_wid;
        if (limit != 0 && right - left + 1 < limit) {
            right = left + limit - 1;
        } else {
            limit = this->max_wid;
            if (limit != 0 && right - left + 1 > limit) {
                if (this->position_mode == PositionLeft || this->position_mode == PositionLeftTop || this->position_mode == PositionLeftBottom) {
                    right = left + limit - 1;
                } else {
                    left = right - limit + 1;
                }
            }
        }
        limit = this->min_hgt;
        if (limit != 0 && calc_hgt < limit) {
            bottom = top + limit - 1;
        } else {
            limit = this->max_hgt;
            if (limit != 0 && calc_hgt > limit) {
                if (this->position_mode == PositionTop || this->position_mode == PositionLeftTop || this->position_mode == PositionRightTop) {
                    bottom = top + limit - 1;
                } else {
                    top = bottom - limit + 1;
                }
            }
        }

        if (this->position_mode == PositionCentered) {
            long real_w = right - left + 1;
            long real_h = bottom - top + 1;
            long xoff;
            if (real_w == wid) {
                xoff = 0;
            } else {
                xoff = wid / 2 - real_w / 2;
            }
            right = real_w + xoff - 1;
            if (real_h == hgt) {
                top = 0;
            } else {
                top = hgt / 2 - real_h / 2;
            }
            bottom = real_h + top - 1;
            left = xoff;
        }
    }

    this->set_rect(left, top, right, bottom);
    int pass = 0;
    do {
        for (PanelNode* node = this->first_child_node; node != 0; node = node->next_node) {
            TPanel* child = node->panel;
            long r = child->handle_size(wid, hgt);
            if (r != 0) {
                return r;
            }
        }
        ++pass;
    } while (pass < 2);
    return 0;
}
