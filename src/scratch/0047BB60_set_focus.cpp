// TScreenPanel::set_focus
// VA: 0047BB60
// PDB: Pnl_scr.cpp:106-145
//
// Attempt log:
// - draft 1: local vars focus, is_new, area, sys → 15 bytes too short (extra stack vars)
// - draft 2: inlined most values → 31 bytes short (pal_entry[256] allocated differently?)
// - draft 3: correct vtable slots for TEasy_Panel (5 virtuals), TScreenPanel dummies for slot 21
// Stuck on: function size (352 vs 383) — VC5 allocates pal_entry array differently or
// optimizes sub esp differently.
// Left in scratch.

#include "..\..\include\game_globals.h"

class TDrawArea;

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char ScreenMode;
    unsigned char DrawType;
    void Paint(void* rect);
};

class TDrawArea {
public:
    TDrawSystem* draw_system;
    void GetPalette(void* pal_entries);
    void Clear(void* rect, int zero1, int zero2);
};

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void set_focus(int param_1);
};

void RGE_fade_palette(TDrawArea* draw_area, int color, float fade_time, int mode, void* pal, int left, int right);
void GetPaletteEntries(void* palette, int start, int count, void* entries);

int last_screen;

class TScreenPanel : public TEasy_Panel {
public:
    char gap_04[0x1C];
    TDrawArea* draw_area;
    char gap_24[0x54];
    int save_focus;
    char gap_7C[0x190];
    void* palette_handle;

    virtual void set_focus(int param_1);
    virtual void v6();  virtual void v7();
    virtual void v8();  virtual void v9();
    virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void after_set_focus();
};

void TScreenPanel::set_focus(int param_1)
{
    int pal_entry[256];
    int is_new;
    TDrawArea* area;

    is_new = (this != (TScreenPanel*)last_screen) ? 1 : 0;
    area = this->draw_area;

    if (area && area->draw_system && param_1 && is_new) {
        TDrawSystem* sys = area->draw_system;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            if (this->palette_handle) {
                GetPaletteEntries(this->palette_handle, 0, 0x100, pal_entry + 1);
            } else {
                area->GetPalette(pal_entry + 1);
            }

            RGE_fade_palette(area, this->save_focus, 0.13f, 1, 0, -1, -1);
            area->Clear(0, 0, 0);
            area->draw_system->Paint(0);
        }
    }

    this->TEasy_Panel::set_focus(param_1);

    area = this->draw_area;
    if (area && area->draw_system && param_1 && is_new) {
        TDrawSystem* sys = area->draw_system;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            RGE_fade_palette(area, this->save_focus, 0.0f, 2, pal_entry + 1, -1, -1);
            this->after_set_focus();
            RGE_fade_palette(area, this->save_focus, 0.0f, 1, 0, -1, -1);
            area->draw_system->Paint(0);
            RGE_fade_palette(area, this->save_focus, 0.13f, 2, pal_entry + 1, -1, -1);
        }
    }

    if (param_1 != this->save_focus && this->save_focus)
        last_screen = (int)this;
}
