// 0047BB60 TScreenPanel::set_focus
// Source: Pnl_scr.cpp lines 106-145
// Size: 383 bytes
// FLAGS: default (/nologo /c /O2 /Oy)
//
// Attempt log:
// - The initial typed reconstruction had the right calls but a 0x404 frame and
//   kept the focus field in EBP. It also passed one extra Clear argument.
// - A typed local aggregate stores the prior focus dword before 256 palette
//   entries. It restores the original EBP use and 0x408 frame.
// - Exact: the focus/palette aggregate and two-argument Clear produce 383/383
//   bytes with 11/11 calls and 100% block coverage.

#include "..\..\include\game_globals.h"

class TDrawArea;
class TDrawSystem;
class TEasy_Panel;

typedef struct { unsigned char r,g,b,a; } PE;
struct FocusPalette {
    int have_focus;
    PALETTEENTRY entries[256];
};

extern int DAT_0086b248;

extern void RGE_fade_palette(TDrawArea*, int, float, int, void*, int, int);

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
    unsigned char ScreenMode;
    void Paint(void*);
};
class TDrawArea {
public:
    TDrawSystem* draw_system;
    void GetPalette(void*);
    void Clear(void*, int);
};

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set_focus(int);
};

class TScreenPanel : public TEasy_Panel {
public:
    char gap_04[0x1C];
    TDrawArea* draw_area;
    char gap_24[0x54];
    int have_focus;
    char gap_7C[0x190];
    void* palette_handle;

    virtual void set_focus(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void after_set_focus();
};

void TScreenPanel::set_focus(int param_1)
{
    FocusPalette palette;
    PE pe;
    bool is_new;
    palette.have_focus = this->have_focus;
    is_new = (this != (TScreenPanel*)DAT_0086b248) ? 1 : 0;

    if (this->draw_area && this->draw_area->draw_system && param_1 && is_new) {
        TDrawSystem* sys = this->draw_area->draw_system;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            pe.r = 0;
            pe.g = 0;
            pe.b = 0;
            if (!this->palette_handle) {
                this->draw_area->GetPalette(palette.entries);
            } else {
                GetPaletteEntries(this->palette_handle, 0, 0x100, palette.entries);
            }

            RGE_fade_palette(this->draw_area, *(int*)&pe, 0.13f, 1, 0, -1, -1);
            this->draw_area->Clear(0, 0);
            this->draw_area->draw_system->Paint(0);
        }
    }

    this->TEasy_Panel::set_focus(param_1);

    if (this->draw_area && this->draw_area->draw_system && param_1 && is_new) {
        TDrawSystem* sys = this->draw_area->draw_system;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            RGE_fade_palette(this->draw_area, *(int*)&pe, 0.0f, 2, palette.entries, -1, -1);
            this->after_set_focus();
            RGE_fade_palette(this->draw_area, *(int*)&pe, 0.0f, 1, 0, -1, -1);
            this->draw_area->draw_system->Paint(0);
            RGE_fade_palette(this->draw_area, *(int*)&pe, 0.13f, 2, palette.entries, -1, -1);
        }
    }

    if (param_1 != palette.have_focus && this->have_focus)
        DAT_0086b248 = (int)this;
}
