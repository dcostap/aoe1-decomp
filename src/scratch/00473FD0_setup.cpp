// VA: 00473FD0 TDropDownPanel::setup
// Pnl_drop.cpp
// FLAGS: /GX
// Attempt log:
// try 1: natural reconstruction from packet: stores dropdown dimensions, calls TPanel::setup, allocates child panels, calls their setup methods, sets mode.
// try 2: added /GX because original has EH registration and state stores around `new` child panel construction.
// try 3: modeled TDropDownPanel fields from matched ctor/dtor: val_panel +F4, btn +F8, list +FC, scbar +100, mode +104, val_num +108, dimension fields +10C..+12C, outline +138, font_hgt +134.
// try 4: modeled base TPanel::setup from matched 00464A80 and called it naturally with area,parent,left/top/width/height/value.
// try 5: modeled child constructors from observed sizes/calls: TTextPanel 0x188/0047BF40, TDropDownButtonPanel 0x2BC/00475470, TListPanel 0x1A0/004782A0, TScrollBarPanel 0x1C4/0047A700.
// try 6: modeled child setup call surfaces to match the long push trains for text/list/scrollbar and compact button setup.
// try 7: declared virtual set_active in TPanel so list/scbar active calls can generate vtable +0x14 dispatch where original uses it.
// try 8: fixed compile-surface issues in list/scrollbar setup prototypes by matching argument count/types loosely to call sites.
// try 9: current source compiles to original size 865B but broad mismatch: 84.16% positional, 110.17% edit, first mismatch at early EH/parameter-load scheduling.
// try 10: inspected first mismatch; original loads the short selection/index from `[esp+48]` before FS write and before register saves, while rebuilt hoists a 32-bit param load due incorrect/unnatural parameter surface. Correct original 29-argument signature/type order remains unresolved.
// left in scratch: behavior/call set mostly reconstructed, but parameter ordering/types and EH prologue scheduling are still wrong, cascading through all child setup push trains. No accepted_drift: broad drift from prologue/parameter loads.

struct TDrawArea;
class TPanel;
class TTextPanel;
class TDropDownButtonPanel;
class TListPanel;
class TScrollBarPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int set_active(int);
    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xCC];
    int setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, int value);
};

class TTextPanel : public TPanel {
public:
    TTextPanel();
    int setup(TDrawArea*, TPanel*, long, long, long, long, int, int, TPanel*, int, int, int, int, int, unsigned char, char*, int);
    void set_bevel_info(int, int);
};

class TDropDownButtonPanel : public TPanel {
public:
    TDropDownButtonPanel(void* drop);
    int setup(TDrawArea*, TPanel*, long, long, long, long, int, int, int, int);
};

class TListPanel : public TPanel {
public:
    TListPanel();
    int setup(TDrawArea*, TPanel*, long, long, long, long, int, int, int, int, int, int, int, int, int, int, char*, char*, int, int*);
    void set_bevel_info(int);
    int set_active(int);
    void setCurrentLineNumber(short);
    void connect_scroll_bar(TScrollBarPanel*, int);
};

class TScrollBarPanel : public TPanel {
public:
    TScrollBarPanel();
    int setup(TDrawArea*, TPanel*, long, long, TListPanel*, long, long, long, char*, char*, char*, char*, long, long, TListPanel*, short, int);
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

    int setup(TDrawArea* area, TPanel* parent, void* p3, long p4, long p5, long p6, long p7, long p8,
              unsigned char outline, long p10, long p11, long val_num, long val_hgt, long p14, long btn_wid,
              long btn_hgt, long list_wid, long list_hgt, long p19, long p20, int* vals, short current,
              long scbar_wid, long scbar_arrow_hgt, long scbar_tab_hgt, char* s1, char* s2, long p28, long p29);
    void set_mode(int mode);
};

int TDropDownPanel::setup(TDrawArea* area, TPanel* parent, void* p3, long p4, long p5, long p6, long p7, long p8,
              unsigned char outline, long p10, long p11, long val_num_param, long val_hgt_param, long p14, long btn_wid_param,
              long btn_hgt_param, long list_wid_param, long list_hgt_param, long p19, long p20, int* vals, short current,
              long scbar_wid_param, long scbar_arrow_hgt_param, long scbar_tab_hgt_param, char* s1, char* s2, long p28, long p29)
{
    this->val_num = (short)val_num_param;
    this->btn_wid = btn_wid_param;
    this->btn_hgt = btn_hgt_param;
    this->list_wid = list_wid_param;
    this->list_hgt = list_hgt_param;
    this->scbar_wid = scbar_wid_param;
    this->scbar_arrow_hgt = p28;
    this->scbar_tab_hgt = p29;
    this->val_wid = val_num_param - btn_wid_param - 1;
    this->val_hgt = val_hgt_param;
    this->outline_color = (unsigned char)outline;
    this->font_hgt = p4;

    TPanel::setup(area, parent, p5, p6, val_num_param, val_hgt_param, 0);

    this->val_panel = new TTextPanel;
    if (this->val_panel == 0) return 0;
    if (!this->val_panel->setup(area, this, 0, 0, this->val_wid, this->val_hgt, p7, p8, 0, p10, p11, p4, outline, p14, (unsigned char)current, (char*)vals[(short)this->val_num], p20)) return 0;
    this->val_panel->set_bevel_info(0, 1);

    this->btn_panel = new TDropDownButtonPanel(this);
    if (this->btn_panel == 0) return 0;
    if (!this->btn_panel->setup(area, this, this->btn_wid, this->btn_hgt, 6, 0, 0, 1, 0, 0)) return 0;

    this->list_panel = new TListPanel;
    if (this->list_panel == 0) return 0;
    if (!this->list_panel->setup(area, this, 0, 0, this->list_wid, this->list_hgt, p7, p8, 0, p10, p11, p4, outline, p14, (int)s1, (int)s1, (char*)s1, (char*)s1, scbar_wid_param, vals)) return 0;
    this->list_panel->set_bevel_info(1);
    this->list_panel->set_active(0);
    this->list_panel->setCurrentLineNumber(this->val_num);

    this->scbar_panel = new TScrollBarPanel;
    if (this->scbar_panel == 0) return 0;
    if (!this->scbar_panel->setup(area, this, 0, 0, this->list_panel, this->list_hgt, this->scbar_wid, this->scbar_arrow_hgt, (char*)0x592A40, (char*)0x592A40, (char*)0x592A40, (char*)0x592A40, this->list_hgt, this->scbar_tab_hgt, this->list_panel, current, 0)) return 0;
    this->list_panel->connect_scroll_bar(this->scbar_panel, 0);
    this->scbar_panel->set_active(0);
    this->set_mode(1);
    return 1;
}
