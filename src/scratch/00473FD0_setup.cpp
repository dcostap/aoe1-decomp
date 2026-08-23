// VA: 00473FD0 TDropDownPanel::setup
// Pnl_drop.cpp
// FLAGS: /GX
// Attempt log:
// try 1-10: initial reconstruction had the wrong 29-argument surface and child
// sizes, so EH/prologue and every setup push train drifted broadly.
// try 11: corrected the period Pnl_drop signature/types, TPanel base size, and
// TTextPanel/TButtonPanel/TListPanel/TScrollBarPanel allocation sizes; restored
// the exact child setup/set_alignment/set_scrollbar call surfaces.
// try 12: widened the outline/selection parameter to short and removed its
// cast; this was binary-motivated by the original pre-EH word load but moved to
// 764-byte drift and wrong structural alignment, so the PDB/mangled uchar form
// was restored.
// try 13: added the missing TPanel dummy vtable slot; set_active now uses the
// observed +0x14 virtual slot and all 20 calls/targets align.
// try 14: reused one TButtonPanel child/result local to obtain one shared EH
// epilogue; it produced one return but a worse 353-byte drift, so the natural
// typed nested member source remains authoritative.
// try 15: reordered the initial field stores around the proven button-width
// derived value; current source is canonical and typed, with 20/20 calls,
// 88.55% shape and localized remaining drift dominated by the pre-EH word load,
// parameter scheduling, and final EH-tail topology.
// current pass: bound val_num to p15, the 15th stack parameter proven by the
// pre-EH word load and the vals index use; this improves the best diff to 272
// bytes and restores the canonical selection ownership. Direct button-width
// arithmetic is retained because it is source-plausible and codegen-equivalent.
// a typed outline local changed register allocation and broadened drift; rolled
// back. Remaining mismatch starts in VC5 prologue scheduling and EH tail.
// shardB3 pass: swapping font_hgt and outline field assignments maps outline to
// EBP and font_hgt to EBX, matching the donor's early register roles; diff moved
// to 266 bytes. A single result local was rejected because it caused 833 bytes
// of drift and a 31-byte oversize. The remaining first hunk loads panel width
// before button width, and the failure path still duplicates the EH epilogue.
// left in scratch: exact ABI/call/layout reconstruction is substantially
// improved but not exact; no accepted_drift for this broad prologue/CFG drift.
// shardB6 probe: binding val_num to p14 followed the first word-load reading
// the earlier short parameter, but it caused 816-byte drift and was rolled back.
// focused pass 2026-08-17: inventory owner evidence moved the char** list setup
// overload back to TTextPanel, added the proven +2B8 drop_down_panel tail, and
// made btn_panel a TButtonPanel owner. The original scrollbar call reads
// this->render_area (+20), not the area parameter; correcting that cut drift.
// The original shared EH tail requires one long result carrying each setup
// status and the final 1. This is a typed period-plausible reconstruction.
// The shared empty string is the exact-bank s_ symbol at 592A40.
// Probes 1-20 covered child size, result/tail forms, assignment order, pointer
// ownership, short/int casts, exact empty-string relocation, and header context.
// Follow-up claim 2026-08-22: eight measured probes kept the clean 162-byte
// mismatch as the best result. Deriving val_wid from the stored member, using
// a chained assignment, naming a button-width local, and isolating val_num in
// a block were codegen duplicates. Moving val_wid to the decompiler's late
// assignment order moved to 203 bytes and was rolled back. A canonical
// TPanel virtual declaration surface was also codegen-neutral. Naming the
// final scrollbar list and line arguments caused a 511-byte structural drift.
// The source is restored to the clean typed model. The original first hunk
// still loads btn_wid before panel_width, while this model loads them reversed;
// the final scrollbar setup also swaps the p22/list-panel register colors.
// Probes 21-28 combined corrected ownership with result and tested result type,
// declaration scope, width aliases, and supported register hints. Best current
// result is 865/865 bytes, 253/253 instructions, 20/20 ordered calls, one
// return, 94.86% shape, and 162 positional mismatch bytes. Remaining drift is
// a register map conflict in the prologue and the final scrollbar argument
// setup. No policy-valid exact match was found.
// Accepted-drift audit: all child calls, arguments, publications, failure
// branches, EH states, cleanup, and returns align. Promotion remains blocked
// because VC5 reorders the pre-call list_wid/list_hgt and
// scbar_wid/scbar_arrow_hgt member stores. A partial object or failing write can
// expose different state before TPanel::setup.
// Exact-finish audit 2026-08-23:
// - Replaced the local TPanel stub with include/panel_context.h. The canonical
//   0xF4 panel layout and virtual order are binary-supported. Output was
//   unchanged at 865 bytes and 162 mismatch bytes.
// - Added the proved TTextPanel override declarations. Output was unchanged.
// - Restored direct btn_wid arithmetic and the explicit int p22 conversion.
//   Member dependency, direct short passing, and base-pointer casts were
//   measured. Each emitted the same 162-byte mismatch.
// - A 20-variant /GX lab tested five early assignment forms and four scrollbar
//   argument forms. It produced two codegen groups. No exact result occurred.
// - Fresh exact checks passed for 00473ED0, 00473F50, 00474550, and 00474670.
//   These registered Pnl_drop anchors remain unchanged.
// - Fresh target validation still reports 865/865 bytes, 20 ordered calls,
//   one return, 94.86% shape, and 162 positional mismatch bytes.
// Remaining evidence: VC5 selects the opposite ECX/EAX map for the first
//   width loads and the opposite ECX/EDX map for scrollbar list and line.
// No natural source form tested in this claim resolves that register basin.

#include "../../include/panel_context.h"

class TTextPanel;
class TDropDownPanel;
class TDropDownButtonPanel;
class TListPanel;
class TScrollBarPanel;
class TDigital;

extern char s_[];

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
    char gap_F4[0x8C];
    int border_size;
    int spacer_size;
    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long, char*, int, unsigned char, int, unsigned char, short, char*);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long, char*, int, unsigned char, int, unsigned char, short, char**, short);
    void set_alignment(int, int);
    void set_scrollbar(TScrollBarPanel*, int);
    void setCurrentLineNumber(int);
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1C4];
    enum DrawType { DrawBevelPicture = 6 };
    enum NotifyType { NotifyAction = 1 };
    long setup(TDrawArea*, TPanel*, long, long, long, long, DrawType, TDigital*, NotifyType, long);
};

class TDropDownButtonPanel : public TButtonPanel {
public:
    TDropDownPanel* drop_down_panel; // proven by handle_mouse_move at +2B8
    TDropDownButtonPanel(TDropDownPanel* drop);
};

class TListPanel : public TTextPanel {
public:
    char gap_188[0x18];
    TListPanel();
    void set_auto_track(int);
};

class TScrollBarPanel : public TPanel {
public:
    char gap_F4[0xD0];
    enum Orientation { Vertical = 0, Horizontal = 1 };
    TScrollBarPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, char*, char*, char*, char*, long, long, TPanel*, long, Orientation);
};

class TDropDownPanel : public TPanel {
public:
    TTextPanel* val_panel;          // +F4
    TButtonPanel* btn_panel;         // +F8; base owner used by setup/action code
    TListPanel* list_panel;         // +FC
    TScrollBarPanel* scbar_panel;   // +100
    int mode;                       // +104
    short val_num;                  // +108
    long val_wid;                   // +10C
    long val_hgt;                   // +110
    long btn_wid;                   // +114
    long btn_hgt;                   // +118
    long list_wid;                  // +11C
    long list_hgt;                  // +120
    long scbar_wid;                 // +124
    long scbar_arrow_hgt;           // +128
    long scbar_tab_hgt;             // +12C
    unsigned char list_is_above;    // +130
    char gap_131[3];
    long font_hgt;                  // +134
    int outline_color;              // +138
    int draw_style;                 // +13C
    int draw_val_rect;              // +140

    long setup(TDrawArea* area, TPanel* parent, void* p3, long p4, long p5, int p6, unsigned char p7,
              int p8, unsigned char outline, long left, long top, long panel_width, long panel_height,
              short p14, short p15, long btn_wid, long btn_hgt, char* p18, long list_wid, long list_hgt,
              char** vals, short p22, long scbar_wid, char* p24, char* p25, char* p26, char* p27,
              long scbar_arrow_hgt, long scbar_tab_hgt);
    void set_mode(int mode);
};

long TDropDownPanel::setup(TDrawArea* area, TPanel* parent, void* p3, long p4, long p5, int p6, unsigned char p7,
              int p8, unsigned char outline, long left, long top, long panel_width, long panel_height,
              short p14, short p15, long btn_wid_param, long btn_hgt_param, char* p18, long list_wid_param,
              long list_hgt_param, char** vals, short p22, long scbar_wid_param, char* p24, char* p25,
              char* p26, char* p27, long scbar_arrow_hgt_param, long scbar_tab_hgt_param)
{
    long result;

    this->val_num = p15;
    this->btn_wid = btn_wid_param;
    this->val_wid = panel_width - btn_wid_param - 1;
    this->btn_hgt = btn_hgt_param;
    this->list_wid = list_wid_param;
    this->list_hgt = list_hgt_param;
    this->scbar_wid = scbar_wid_param;
    this->scbar_arrow_hgt = scbar_arrow_hgt_param;
    this->scbar_tab_hgt = scbar_tab_hgt_param;
    this->val_hgt = panel_height;
    this->font_hgt = p5;
    this->outline_color = outline;

    TPanel::setup(area, parent, left, top, panel_width, panel_height, 0);

    this->val_panel = new TTextPanel;
    result = (long)this->val_panel;
    if (result != 0 &&
        (result = this->val_panel->setup(area, this, 0, 0, this->val_wid, this->val_hgt,
                               p3, p4, p5, (char*)0, p6, p7, p8, outline, p14,
                               vals[(short)this->val_num])) != 0) {
        this->val_panel->set_alignment(0, 1);

        this->btn_panel = new TDropDownButtonPanel(this);
        result = (long)this->btn_panel;
        if (result != 0 &&
            (result = this->btn_panel->setup(area, this, 0, 0, this->btn_wid, this->btn_hgt,
                                   TButtonPanel::DrawBevelPicture, (TDigital*)0,
                                   TButtonPanel::NotifyAction, 0)) != 0) {
            this->list_panel = new TListPanel;
            result = (long)this->list_panel;
            if (result != 0 &&
                (result = this->list_panel->setup(area, this, 0, 0, this->list_wid, this->list_hgt,
                                        p3, p4, p5, (char*)0, p6, p7, p8, outline, p14,
                                        vals, p22)) != 0) {
                this->list_panel->set_auto_track(1);
                this->list_panel->set_active(0);
                ((TTextPanel*)this->list_panel)->setCurrentLineNumber(this->val_num);

                this->scbar_panel = new TScrollBarPanel;
                result = (long)this->scbar_panel;
                if (result != 0 &&
                    (result = this->scbar_panel->setup(this->render_area, this, 0, 0, this->scbar_wid, this->list_hgt,
                                             s_, s_, s_, s_,
                                             this->scbar_arrow_hgt, this->scbar_tab_hgt,
                                             this->list_panel, (int)p22,
                                             TScrollBarPanel::Vertical)) != 0) {
                    this->list_panel->set_scrollbar(this->scbar_panel, 0);
                    this->scbar_panel->set_active(0);
                    this->set_mode(1);
                    result = 1;
                }
            }
        }
    }
    return result;
}
