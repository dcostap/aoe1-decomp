// VA: 00474880 TDropDownPanel::set_mode
// Pnl_drop.cpp lines 408-627
// FLAGS: default
//
// Attempt log:
// baseline: natural reconstruction from packet + exact Pnl_drop.cpp donors.
//   - TDropDownPanel layout from matched ctor 00473ED0 / type dump: val_panel +F4, btn_panel +F8,
//     list_panel +FC, scbar_panel +100, mode +104, val_wid +10C, val_hgt +110, btn_wid +114,
//     btn_hgt +118, list_wid +11C, list_hgt +120, scbar_wid +124, list_is_above +130,
//     font_hgt +134, draw_style +13C.
//   - TPanel layout from type dump: pnl_x +0C, pnl_y +10, pnl_hgt +18, render_area +20,
//     clip_rect +24, parent_panel +40, active +6C, clip_to_parent +F1.
//   - TPanel virtuals: set_active 0x14, set_positioning 0x18 (13 args), set_fixed_position 0x1C,
//     set_redraw 0x20, notify_action 0xB4.
//   - TTextPanel: numberLines 0047DC30 / numberDrawLines 0047DC40, border_size +180, spacer_size +184.
//   - TPanelSystem: restorePreviousModalPanel 00464010, setModalPanel 00463F60; panel_system 62E870.
//
// probe history before this session (best = 1540 diff / 70.5%):
// 1 baseline: 1896 diff, frame 8 vs 16; old_mode stayed in a register, notify calls tail-merged.
// 2 else-path zero init + epilogue outside parent check: call prefix 31; frame still 8.
// 3 local declaration order (parent_y first): no change.
// 4 named pos_w/above locals for the 480-region: regressed (frame changed, worse scheduling).
// 5 register hint on parents: no change.
// 6 full real TPanel field list instead of gaps: no change.
// 7 KEY: mode-store + return INSIDE the `if (this->parent_panel)` notify block -> two separate
//   epilogues like the original; diff 1900 -> 1671; size gap -4.
// 8 zero initializers on parents: no change.
// 9 KEY: `long calc_wid = this->list_wid;` carried across the 536/583/609 position calls
//   (PDB/type evidence: original keeps a 4th local at frame E0-4). Flipped the whole register
//   allocation to the original basin: parent_x->ebp, parent_y->ebx, old_mode->stack [esp+18h],
//   zero->edx (register mode store), else-path reg zeros; diff 1671 -> 1540; frame 8 -> 0xC.
// 10 named pos_w/above again post-fix: regressed (1612); restored calc_wid state.
//
// Current session probes:
// - hoisted value_wid and value_hgt before the list_is_above branch: improved the prior
//   candidate to 1395 bytes (63.84%), shape 87.17%, and exact-block coverage 41.18%.
// - caching spacer_size before each line-count branch and border_size inside each arm
//   improved the candidate to 865 bytes (39.53%), shape 93.51%, and 52.19% exact blocks.
//   The final candidate is 2188 bytes versus 2185 original bytes, with all source calls
//   present but one vslot+1C versus indirect call encoding replacement.
// - Swapping parent_x before parent_y in this basin reduced the diff by two bytes; this is
//   retained as a codegen observation, not a proven declaration order.
// - pointer-to-member dispatch for this->set_fixed_position: regressed to 1944 bytes and
//   introduced direct compiler-generated PMF thunks; removed.
// - volatile calc_wid: regressed to 1959 bytes; removed.
// - local TPanel receiver and removal of register keywords: emitted-code duplicates; retained
//   ordinary local declarations and direct self calls for source plausibility.
// - reversed the initial equality operands: one byte farther with no structural change; restored
//   `mode == this->mode`.
// - nested `TDropDownPanel::DropdownMode` for the parameter and old_mode restored the PDB ABI;
//   the decorated owner now matches `?set_mode@TDropDownPanel@@QAEXW4DropdownMode@1@@Z`.
//   Emitted body shape stayed unchanged, so the L536 indirect/vslot+1C replacement remains
//   an encoding-local call-cache difference.
// - a positive outer mode guard, one duplicate calc_wid assignment, and a second width alias
//   were codegen duplicates. They are not retained.
// - a period TPanel virtual destructor declaration preserved the slot shape and emitted bytes.
//   Derived-panel destructor declarations changed numberLines/numberDrawLines call order and
//   were removed.
// - the reviewed long-returning notify_action declaration is also codegen-neutral when its
//   result is ignored.
//
// Left in scratch, remaining drift (all localized codegen):
// - prior local-context best was 865 bytes (39.53%), shape 93.51%, size 2188 vs 2185, frame 0xC vs 0x10;
// - that 865-byte result used a local panel ABI and is not retained after the
//   canonical context gate. The reduced canonical candidate is 2188 bytes,
//   881 differing bytes, 96.88% ordered-call alignment, and the same 0xC frame.
// - frame 0xC vs 0x10: original keeps a 4th slot [E0-4] caching list_wid for the above path;
//   rebuilt keeps calc_wid in ebp (register) and spills only the fn ptr to old_mode's home.
// - 480/484: original hoists arg3/arg4 (val_wid+btn_wid+1, val_hgt) and pushes them BEFORE the
//   list_is_above branch (L476 loads val_wid/btn_wid, L478 loads the flag). The retained named
//   value_wid/value_hgt locals recover this source shape.
// - epilogue A folds `this->mode = mode` to `mov dword [esi+104h],1`; original reloads param
//   from [esp+24h].
// - prologue: rebuilt pushes all 4 callee-saves eagerly before the early-return compare; original
//   pushes only esi and defers edi/ebp/ebx past the branch.
// - L536 fn ptr: original caches vtable[0x1C] into [E0-8] and list_wid into [E0-4]; rebuilt
//   keeps the fn ptr in ebp and spills it to old_mode's home, so the checker reports one
//   vslot+1C versus indirect call replacement.
// - Prologue: rebuilt pushes all four callee-saves before the early compare; original pushes
//   only esi and defers edi/ebp/ebx. The source probes did not recover this shrink-wrap basin.
// Current pass: packet and mangled-name evidence confirm the nested DropdownMode parameter ABI.
// Exact Pnl_drop.cpp donors use int declarations, but this target now uses the PDB-proven enum.
//
// Exact-finish context pass:
// - The PDB module is C:\\msdev\\work\\age1_x1\\Pnl_drop.cpp, lines 408-627.
// - The owning class is TDropDownPanel. The address sequence is the Pnl_drop.cpp
//   set_mode body between the exact constructor, destructor, set_rect, and
//   set_bevel_info anchors.
// - This owner now includes include/panel_context.h. That header supplies the
//   reviewed Panel.cpp vtable, 0xF4 layout, RECT storage, and Panel helpers.
// - Fresh checks keep exact anchors 00473ED0, 00473F50, 00474550, and 00474670.
// - Natural call order and panel rereads remain explicit. The shipped
//   numberLines result locals preserve the observed numberLines-before-
//   numberDrawLines order without reusing a panel result across checks.

#ifndef PNL_DROP_CONTEXT
#include "../../include/panel_context.h"

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char*);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    int numberLines();
    int numberDrawLines();
    char gap_F4[0x8C];                   // +0xF4
    int border_size;                     // +0x180
    int spacer_size;                     // +0x184
};

class TScrollBarPanel : public TPanel {
};

class TDropDownPanel : public TPanel {
public:
    enum DropdownMode {
        ModeNone = 0,
        ModeValue = 1,
        ModeList = 2
    };

    TTextPanel* val_panel;               // +0xF4
    TPanel* btn_panel;                   // +0xF8
    TTextPanel* list_panel;              // +0xFC
    TScrollBarPanel* scbar_panel;        // +0x100
    DropdownMode mode;                   // +0x104
    short val_num;                       // +0x108
    char gap_10A[2];
    long val_wid;                        // +0x10C
    long val_hgt;                        // +0x110
    long btn_wid;                        // +0x114
    long btn_hgt;                        // +0x118
    long list_wid;                       // +0x11C
    long list_hgt;                       // +0x120
    long scbar_wid;                      // +0x124
    long scbar_arrow_hgt;                // +0x128
    long scbar_tab_hgt;                  // +0x12C
    unsigned char list_is_above;         // +0x130
    char gap_131[3];
    long font_hgt;                       // +0x134
    int outline_color;                   // +0x138
    int draw_style;                      // +0x13C
    int draw_val_rect;                   // +0x140

    void set_mode(DropdownMode mode);
};
#endif

void TDropDownPanel::set_mode(DropdownMode mode) {
    if (mode == this->mode) {
        return;
    }

    long parent_x = 0;
    long parent_y = 0;
    long parent_w = 0;
    long parent_h = 0;
    DropdownMode old_mode;
    if (this->parent_panel) {
        parent_x = this->parent_panel->xPosition();
        parent_y = this->parent_panel->yPosition();
        parent_w = this->parent_panel->width();
        parent_h = this->parent_panel->height();
    } else {
        parent_x = 0;
        parent_y = 0;
        parent_w = this->render_area->Width;
        parent_h = this->render_area->Height;
    }

    old_mode = (DropdownMode)this->mode;
    this->mode = (DropdownMode)ModeNone;

    if (mode == ModeValue) {
        if (old_mode == ModeList && this->parent_panel != 0 && this->parent_panel->parent_panel != 0) {
            if (this->clip_rect.left < parent_x || this->clip_rect.top < parent_y ||
                this->clip_rect.right > parent_w + parent_x - 1 ||
                this->clip_rect.bottom > parent_h + parent_y - 1) {
                this->parent_panel->parent_panel->set_redraw(2);
            }
        }
        this->list_panel->set_active(0);
        this->scbar_panel->set_active(0);
        if (this->draw_style == 1) {
            this->btn_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
            this->val_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
        } else {
            this->val_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, 0, 0, 0, 0);
            this->btn_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
        }
        this->clip_to_parent = 1;
        long value_wid = this->val_wid + this->btn_wid + 1;
        long value_hgt = this->val_hgt;
        if (this->list_is_above) {
            this->set_fixed_position(this->pnl_x - parent_x,
                                     this->pnl_y + this->pnl_hgt - this->val_hgt - old_mode,
                                     value_wid, value_hgt);
            this->list_is_above = 0;
        } else {
            this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - old_mode,
                                     value_wid, value_hgt);
        }
        if (this->parent_panel) {
            this->parent_panel->set_redraw(1);
        } else {
            this->set_redraw(1);
        }
        this->set_curr_child(this->val_panel);
        if (old_mode == ModeList) {
            if (panel_system.restorePreviousModalPanel() == 0) {
                panel_system.setModalPanel(0);
            }
            if (this->parent_panel) {
                this->parent_panel->action(this, 2, 0, 0);
                this->mode = mode;
                return;
            }
        }
    } else if (mode == ModeList) {
        this->list_panel->set_active(1);
        // BINARY NOTE: the shipped code reads spacer and border sizes before each count call.
        int spacer_size = this->list_panel->spacer_size;
        if (spacer_size == 0) {
            int border_size = this->list_panel->border_size;
            this->list_hgt = this->list_panel->numberLines() * (this->font_hgt + 2) +
                             border_size * 2;
        } else {
            int border_size = this->list_panel->border_size;
            this->list_hgt = this->list_panel->numberLines() * (this->font_hgt + 1 +
                             spacer_size * 2) + border_size * 2;
        }
        this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
        int number_lines = this->list_panel->numberLines();
        if (number_lines > this->list_panel->numberDrawLines()) {
            this->scbar_panel->set_active(1);
        } else {
            this->scbar_panel->set_active(0);
        }
        if (this->draw_style == 1) {
            this->btn_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
            this->val_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
        } else {
            this->val_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, 0, 0, 0, 0);
            this->btn_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
        }
        this->scbar_panel->set_positioning(PositionRightBottom, 1, 1, 0, 0, this->scbar_wid, this->scbar_wid,
                                           0, 0, 0, this->val_panel, 0, 0);
        this->list_panel->set_positioning(PositionLeftBottom, 0, 1, 1, 0, 0, 0, 0, 0, 0,
                                          this->val_panel, this->scbar_panel, 0);
        this->clip_to_parent = 0;
        long calc_wid = this->list_wid;
        this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y,
                                 calc_wid, this->list_hgt + this->val_hgt + 1);
        if (this->list_panel->yPosition() + this->list_panel->height() >
            this->render_area->Height - 4) {
            long overflow = this->list_panel->yPosition() + this->list_panel->height() +
                            4 - this->render_area->Height;
            long above = this->list_panel->height() + 4 - this->pnl_y;
            if (above < overflow) {
                if (above > 0) {
                    this->list_hgt -= above;
                    this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                    int spacer_size = this->list_panel->spacer_size;
                    if (spacer_size == 0) {
                        int border_size = this->list_panel->border_size;
                        this->list_hgt = this->list_panel->numberDrawLines() * (this->font_hgt + 2) +
                                         border_size * 2;
                    } else {
                        int border_size = this->list_panel->border_size;
                        this->list_hgt = this->list_panel->numberDrawLines() *
                                         (this->font_hgt + 1 + spacer_size * 2) +
                                         border_size * 2;
                    }
                    if (this->scbar_panel->active == 0) {
                        this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                        int number_lines = this->list_panel->numberLines();
                        if (number_lines > this->list_panel->numberDrawLines()) {
                            this->scbar_panel->set_active(1);
                        }
                    }
                }
                if (this->draw_style == 1) {
                    this->btn_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                                     this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
                    this->val_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                                     this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
                } else {
                    this->val_panel->set_positioning(PositionLeftTop, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                                     this->val_hgt, this->val_hgt, 0, 0, 0, 0);
                    this->btn_panel->set_positioning(PositionLeftTop, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
                                                     this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
                }
                this->scbar_panel->set_positioning(PositionRightTop, 1, 1, 0, 0, this->scbar_wid, this->scbar_wid,
                                                   0, 0, 0, 0, 0, this->val_panel);
                this->list_panel->set_positioning(PositionLeftTop, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
                                                  this->scbar_panel, this->val_panel);
                this->set_fixed_position(this->pnl_x - parent_x,
                                         this->pnl_y - parent_y - this->list_hgt - 1,
                                         calc_wid, this->list_hgt + this->val_hgt + 1);
                this->list_is_above = 1;
            } else {
                this->list_hgt -= overflow;
                this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                int spacer_size = this->list_panel->spacer_size;
                if (spacer_size == 0) {
                    int border_size = this->list_panel->border_size;
                    this->list_hgt = this->list_panel->numberDrawLines() * (this->font_hgt + 2) +
                                     border_size * 2;
                } else {
                    int border_size = this->list_panel->border_size;
                    this->list_hgt = this->list_panel->numberDrawLines() *
                                     (this->font_hgt + 1 + spacer_size * 2) +
                                     border_size * 2;
                }
                if (this->scbar_panel->active == 0) {
                    this->list_panel->set_fixed_position(0, 0, this->list_wid, this->list_hgt);
                    int number_lines = this->list_panel->numberLines();
                    if (number_lines > this->list_panel->numberDrawLines()) {
                        this->scbar_panel->set_active(1);
                    }
                    this->list_panel->set_positioning(PositionLeftBottom, 0, 1, 1, 0, 0, 0, 0, 0, 0,
                                                      this->val_panel, this->scbar_panel, 0);
                }
                this->set_fixed_position(this->pnl_x - parent_x, this->pnl_y - parent_y,
                                         calc_wid, this->list_hgt + this->val_hgt + 1);
            }
        }
        this->set_redraw(1);
        this->set_z_order(1, 0);
        this->set_curr_child(this->list_panel);
        panel_system.setModalPanel(this);
        if (this->parent_panel) {
            this->parent_panel->action(this, 1, 0, 0);
        }
    }

    this->mode = mode;
}
