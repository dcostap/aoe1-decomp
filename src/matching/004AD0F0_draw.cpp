// VA: 004AD0F0 TRIBE_Screen_Sed::draw (scr_sed.cpp:3239-3263, 322B)
// Attempt log:
// baseline: typed field/virtual-call reconstruction; initial free draw shim and
// wrong zero-argument vslot were corrected from ordered call/ABI evidence.
// probe: raw/typed scalar rectangle access used the wrong main-view register;
// a tagRECT pointer plus aggregate assignment reproduces the proven stack window.
// diagnostic volatile scalar stores reached a nearby basin but were not retained;
// the ordinary aggregate copy is both exact and period-plausible.
// probe: the direct TEasy_Panel::draw member and one-int vslot 0x28 surface
// aligned all seven calls; the original frame and size then matched.
// probe: typed main-view field expressions alone changed the basin; a natural
// tagRECT* plus aggregate assignment (`rect_local = *mrect`) matched exactly.
// FLAGS: /nologo /c /O2 /Oy

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct TDrawArea {
    unsigned char* Lock(char* name, int flags);
    void Unlock(char* name);
    void DrawBevel3(int x, int y, int w, int h,
        unsigned char c1, unsigned char c2, unsigned char c3,
        unsigned char c4, unsigned char c5, unsigned char c6);
};

struct TEasy_Panel {
    virtual ~TEasy_Panel();
    void draw();
};

struct TRIBE_Main_View {
    char gap_00[0x8C];
    tagRECT rect;
};

struct TRIBE_Screen_Sed : TEasy_Panel {
    char _pad_04[0x14 - 4];
    int pnl_wid;                   // +0x14
    int pnl_hgt;                   // +0x18
    char _pad_1C[0x20 - 0x1C];
    TDrawArea* render_area;        // +0x20
    tagRECT clip_rect;             // +0x24
    char _pad_34[0x8C - 0x34];
    tagRECT stored_rect;           // +0x8C
    char _pad_9C[0x31C - 0x9C];
    int use_bevels;                // +0x31C
    unsigned char bevel_c1;        // +0x320
    unsigned char bevel_c2;        // +0x321
    unsigned char bevel_c3;        // +0x322
    unsigned char bevel_c4;        // +0x323
    unsigned char bevel_c5;        // +0x324
    unsigned char bevel_c6;        // +0x325
    char _pad_326[0x4C8 - 0x326];
    TRIBE_Main_View* main_view;    // +0x4C8

    virtual ~TRIBE_Screen_Sed();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10(int param); // slot 10, vtable offset 0x28
    virtual void v11();           // slot 11, vtable offset 0x2C

    virtual void draw();
};

void TRIBE_Screen_Sed::draw()
{
    tagRECT rect_local;

    this->TEasy_Panel::draw();

    if (use_bevels != 0 && main_view != 0) {
        if (stored_rect.left == clip_rect.left &&
            stored_rect.top == clip_rect.top &&
            stored_rect.right == clip_rect.right &&
            stored_rect.bottom == clip_rect.bottom)
        {
            v10(0);

            unsigned char* locked = render_area->Lock("scr_sed::draw", 1);
            if (locked) {
                tagRECT* mrect = &main_view->rect;
                rect_local = *mrect;

                render_area->DrawBevel3(0, 0, pnl_wid - 1, rect_local.top - 1,
                    bevel_c1, bevel_c2, bevel_c3, bevel_c4,
                    bevel_c5, bevel_c6);

                render_area->DrawBevel3(0, rect_local.bottom + 1,
                    pnl_wid - 1, pnl_hgt - 1,
                    bevel_c1, bevel_c2, bevel_c3, bevel_c4,
                    bevel_c5, bevel_c6);

                render_area->Unlock("scr_sed::draw");
            }

            v11();
        }
    }
}
