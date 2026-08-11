// 0047BB60 TScreenPanel::set_focus
// Source: Pnl_scr.cpp lines 106-145
// Size: 383 bytes
// FLAGS: default (/nologo /c /O2 /Oy)
//
// Attempt log:
// - Baseline had the correct 0x408 frame after adding a local PALETTEENTRY, but
//   used a direct GetPaletteEntries call and reversed the palette-handle arms.
// - Restored the Windows stdcall import, DAT_0086b248 relocation, null-handle
//   fall-through, and the binary-proven zeroed PALETTEENTRY dword as every fade's
//   color argument. Calls/CFG then aligned 11/11; no behavior gap remains known.
// - Direct draw_area rereads plus bool is_new recover the original saved EBX and
//   92.42% instruction-shape similarity, but VC5 keeps focus_copy in EBP and
//   allocates a 0x404 frame instead of the original EBP parameter/0x408 frame.
// - Tried declaration-order and parameter-local variants; emitted code duplicated.
// Left in scratch — remaining drift is the documented VC5 register/frame basin.

#include "..\..\include\game_globals.h"

class TDrawArea;
class TDrawSystem;
class TEasy_Panel;

typedef struct { unsigned char r,g,b,a; } PE;

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
    void Clear(void*, int, int);
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
    int save_focus;
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
    PALETTEENTRY pal_entry[256];
    PE pe;
    bool is_new;
    int focus_copy;

    focus_copy = this->save_focus;
    is_new = (this != (TScreenPanel*)DAT_0086b248) ? 1 : 0;

    if (this->draw_area && this->draw_area->draw_system && param_1 && is_new) {
        TDrawSystem* sys = this->draw_area->draw_system;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            pe.r = 0;
            pe.g = 0;
            pe.b = 0;
            if (!this->palette_handle) {
                this->draw_area->GetPalette(pal_entry + 1);
            } else {
                GetPaletteEntries(this->palette_handle, 0, 0x100, pal_entry + 1);
            }

            RGE_fade_palette(this->draw_area, *(int*)&pe, 0.13f, 1, 0, -1, -1);
            this->draw_area->Clear(0, 0, 0);
            this->draw_area->draw_system->Paint(0);
        }
    }

    this->TEasy_Panel::set_focus(param_1);

    if (this->draw_area && this->draw_area->draw_system && param_1 && is_new) {
        TDrawSystem* sys = this->draw_area->draw_system;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            RGE_fade_palette(this->draw_area, *(int*)&pe, 0.0f, 2, pal_entry + 1, -1, -1);
            this->after_set_focus();
            RGE_fade_palette(this->draw_area, *(int*)&pe, 0.0f, 1, 0, -1, -1);
            this->draw_area->draw_system->Paint(0);
            RGE_fade_palette(this->draw_area, *(int*)&pe, 0.13f, 2, pal_entry + 1, -1, -1);
        }
    }

    if (param_1 != focus_copy && focus_copy)
        DAT_0086b248 = (int)this;
}
