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

struct TDrawArea;
class TPanel;
class TTextPanel;
class TDropDownPanel;
class TDropDownButtonPanel;
class TListPanel;
class TScrollBarPanel;
class TDigital;

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual int set_active(int);
    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xD0];
    long setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, unsigned char value);
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x8C];
    int border_size;
    int spacer_size;
    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long, char*, int, unsigned char, int, unsigned char, short, char*);
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
    TDropDownButtonPanel(TDropDownPanel* drop);
};

class TListPanel : public TTextPanel {
public:
    char gap_188[0x18];
    TListPanel();
    void set_auto_track(int);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long, char*, int, unsigned char, int, unsigned char, short, char**, short);
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
    TDropDownButtonPanel* btn_panel;// +F8
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
    if (this->val_panel != 0 &&
        this->val_panel->setup(area, this, 0, 0, this->val_wid, this->val_hgt,
                               p3, p4, p5, (char*)0, p6, p7, p8, outline, p14,
                               vals[(short)this->val_num]) != 0) {
        this->val_panel->set_alignment(0, 1);

        this->btn_panel = new TDropDownButtonPanel(this);
        if (this->btn_panel != 0 &&
            this->btn_panel->setup(area, this, 0, 0, this->btn_wid, this->btn_hgt,
                                   TButtonPanel::DrawBevelPicture, (TDigital*)0,
                                   TButtonPanel::NotifyAction, 0) != 0) {
            this->list_panel = new TListPanel;
            if (this->list_panel != 0 &&
                this->list_panel->setup(area, this, 0, 0, this->list_wid, this->list_hgt,
                                        p3, p4, p5, (char*)0, p6, p7, p8, outline, p14,
                                        vals, p22) != 0) {
                this->list_panel->set_auto_track(1);
                this->list_panel->set_active(0);
                this->list_panel->setCurrentLineNumber((int)this->val_num);

                this->scbar_panel = new TScrollBarPanel;
                if (this->scbar_panel != 0 &&
                    this->scbar_panel->setup(area, this, 0, 0, this->scbar_wid, this->list_hgt,
                                             "", "", "", "",
                                             this->scbar_arrow_hgt, this->scbar_tab_hgt,
                                             this->list_panel, (long)p22,
                                             TScrollBarPanel::Vertical) != 0) {
                    this->list_panel->set_scrollbar(this->scbar_panel, 0);
                    this->scbar_panel->set_active(0);
                    this->set_mode(1);
                    return 1;
                }
            }
        }
    }
    return 0;
}
