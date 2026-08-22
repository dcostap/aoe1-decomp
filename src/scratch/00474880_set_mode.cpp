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
// - current best is 865 bytes (39.53%), shape 93.51%, size 2188 vs 2185, frame 0xC vs 0x10;
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

class TDrawArea {
public:
    char gap_00[0x18];
    int Width;    // +0x18
    int Height;   // +0x1C
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void set_active(int mode);                                            // 0x14
    virtual void set_positioning(int mode, long p2, long p3, long p4, long p5,
                                 long p6, long p7, long p8, long p9,
                                 TPanel* p10, TPanel* p11, TPanel* p12, TPanel* p13);  // 0x18
    virtual void set_fixed_position(long p1, long p2, long p3, long p4);          // 0x1C
    virtual void set_redraw(int mode);                                            // 0x20
    virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30();
    virtual void vf34(); virtual void vf38(); virtual void vf3C(); virtual void vf40();
    virtual void vf44(); virtual void vf48(); virtual void vf4C(); virtual void vf50();
    virtual void vf54(); virtual void vf58(); virtual void vf5C(); virtual void vf60();
    virtual void vf64(); virtual void vf68(); virtual void vf6C(); virtual void vf70();
    virtual void vf74(); virtual void vf78(); virtual void vf7C(); virtual void vf80();
    virtual void vf84(); virtual void vf88(); virtual void vf8C(); virtual void vf90();
    virtual void vf94(); virtual void vf98(); virtual void vf9C(); virtual void vfA0();
    virtual void vfA4(); virtual void vfA8(); virtual void vfAC(); virtual void vfB0();
    virtual long notify_action(TPanel* panel, long action, unsigned long param3,
                               unsigned long param4);                             // 0xB4

    TPanel* previousPanelValue;          // +0x04
    TPanel* previousModalPanelValue;     // +0x08
    long pnl_x;                          // +0x0C
    long pnl_y;                          // +0x10
    long pnl_wid;                        // +0x14
    long pnl_hgt;                        // +0x18
    char* panelNameValue;                // +0x1C
    TDrawArea* render_area;              // +0x20
    long clip_left;                      // +0x24
    long clip_top;                       // +0x28
    long clip_right;                     // +0x2C
    long clip_bottom;                    // +0x30
    int position_mode;                   // +0x34
    int need_redraw;                     // +0x38
    TPanel* curr_child;                  // +0x3C
    TPanel* parent_panel;                // +0x40
    TPanel* left_panel;                  // +0x44
    TPanel* top_panel;                   // +0x48
    TPanel* right_panel;                 // +0x4C
    TPanel* bottom_panel;                // +0x50
    char* node;                          // +0x54
    char* first_child_node;              // +0x58
    char* last_child_node;               // +0x5C
    TPanel* tab_prev_panel;              // +0x60
    TPanel* tab_next_panel;              // +0x64
    int mouse_captured;                  // +0x68
    int active;                          // +0x6C
    int visible;                         // +0x70
    int tab_stop;                        // +0x74
    int have_focus;                      // +0x78
    int overlapping_children;            // +0x7C
    int handle_mouse_input;              // +0x80
    int just_drawn;                      // +0x84
    void* clip_rgn;                      // +0x88
    char gap_8C[0x10];                   // +0x8C render_rect
    long left_border;                    // +0x9C
    long top_border;                     // +0xA0
    long right_border;                   // +0xA4
    long bottom_border;                  // +0xA8
    long min_wid;                        // +0xAC
    long max_wid;                        // +0xB0
    long min_hgt;                        // +0xB4
    long max_hgt;                        // +0xB8
    long mouse_hold_interval;            // +0xBC
    long mouse_move_tolerance;           // +0xC0
    long mouse_down_x;                   // +0xC4
    long mouse_down_y;                   // +0xC8
    int mouse_down_ctrl;                 // +0xCC
    int mouse_down_shift;                // +0xD0
    unsigned long mouse_down_time;       // +0xD4
    int error_code;                      // +0xD8
    int z_order;                         // +0xDC
    int display_changed_count;           // +0xE0
    long help_string_id;                 // +0xE4
    long help_page_id;                   // +0xE8
    unsigned char mouse_action;          // +0xEC
    unsigned char mouse_down_button;     // +0xED
    unsigned char panel_type;            // +0xEE
    unsigned char color;                 // +0xEF
    unsigned char fill_in_background;    // +0xF0
    unsigned char clip_to_parent;        // +0xF1
    unsigned char draw_rect2_flag;       // +0xF2
    unsigned char need_restore;          // +0xF3

    long xPosition();
    long yPosition();
    long width();
    long height();
    void set_curr_child(TPanel* panel);
    void set_z_order(unsigned char mode, short order);
};

class TTextPanel : public TPanel {
public:
    int numberLines();
    int numberDrawLines();
    char gap_F4[0x8C];                   // +0xF4
    int border_size;                     // +0x180
    int spacer_size;                     // +0x184
};

class TScrollBarPanel : public TPanel {
};

class TPanelSystem {
public:
    void setModalPanel(TPanel* panel);
    int restorePreviousModalPanel();
};

extern TPanelSystem panel_system;

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

    old_mode = this->mode;
    this->mode = ModeNone;

    if (mode == ModeValue) {
        if (old_mode == ModeList && this->parent_panel != 0 && this->parent_panel->parent_panel != 0) {
            if (this->clip_left < parent_x || this->clip_top < parent_y ||
                this->clip_right > parent_w + parent_x - 1 ||
                this->clip_bottom > parent_h + parent_y - 1) {
                this->parent_panel->parent_panel->set_redraw(2);
            }
        }
        this->list_panel->set_active(0);
        this->scbar_panel->set_active(0);
        if (this->draw_style == 1) {
            this->btn_panel->set_positioning(7, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
            this->val_panel->set_positioning(7, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
        } else {
            this->val_panel->set_positioning(7, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, 0, 0, 0, 0);
            this->btn_panel->set_positioning(7, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
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
                this->parent_panel->notify_action(this, 2, 0, 0);
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
        if (this->list_panel->numberLines() > this->list_panel->numberDrawLines()) {
            this->scbar_panel->set_active(1);
        } else {
            this->scbar_panel->set_active(0);
        }
        if (this->draw_style == 1) {
            this->btn_panel->set_positioning(7, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
            this->val_panel->set_positioning(7, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
        } else {
            this->val_panel->set_positioning(7, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                             this->val_hgt, this->val_hgt, 0, 0, 0, 0);
            this->btn_panel->set_positioning(7, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
                                             this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
        }
        this->scbar_panel->set_positioning(10, 1, 1, 0, 0, this->scbar_wid, this->scbar_wid,
                                           0, 0, 0, this->val_panel, 0, 0);
        this->list_panel->set_positioning(8, 0, 1, 1, 0, 0, 0, 0, 0, 0,
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
                        if (this->list_panel->numberLines() > this->list_panel->numberDrawLines()) {
                            this->scbar_panel->set_active(1);
                        }
                    }
                }
                if (this->draw_style == 1) {
                    this->btn_panel->set_positioning(7, 0, 0, 1, 0, this->btn_wid, this->btn_wid,
                                                     this->btn_hgt, this->btn_hgt, 0, 0, 0, 0);
                    this->val_panel->set_positioning(7, 1, 0, 0, 0, this->val_wid, this->val_wid,
                                                     this->val_hgt, this->val_hgt, this->btn_panel, 0, 0, 0);
                } else {
                    this->val_panel->set_positioning(7, 0, 0, 1, 0, this->val_wid, this->val_wid,
                                                     this->val_hgt, this->val_hgt, 0, 0, 0, 0);
                    this->btn_panel->set_positioning(7, 1, 0, 0, 0, this->btn_wid, this->btn_wid,
                                                     this->btn_hgt, this->btn_hgt, this->val_panel, 0, 0, 0);
                }
                this->scbar_panel->set_positioning(9, 1, 1, 0, 0, this->scbar_wid, this->scbar_wid,
                                                   0, 0, 0, 0, 0, this->val_panel);
                this->list_panel->set_positioning(7, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
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
                    if (this->list_panel->numberLines() > this->list_panel->numberDrawLines()) {
                        this->scbar_panel->set_active(1);
                    }
                    this->list_panel->set_positioning(8, 0, 1, 1, 0, 0, 0, 0, 0, 0,
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
            this->parent_panel->notify_action(this, 1, 0, 0);
        }
    }

    this->mode = mode;
}
