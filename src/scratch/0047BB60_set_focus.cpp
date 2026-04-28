// 0047BB60 TScreenPanel::set_focus
// Source: Pnl_scr.cpp lines 106-145
// Size: 383 bytes
// FLAGS: default (/nologo /c /O2 /Oy)
//
// Attempt log:
// - Original scratch: 352 bytes (31 short). No PALETTEENTRY→ missing 3 byte-stores
//   and sub esp=400h (should be 408h).
// - Added PALETTEENTRY pe local (3 zero-byte stores for peRed/peGreen/peBlue)
//   → sub esp=408h, correct size 383, local layout pe at [esp+0Ch]/is_new at [esp+10h]
//   /pal_entry at [esp+18h]. Focus_copy in register, param_1 on stack.
// - Tried axes: is_new as unsigned char/int/two-step, durable sys local,
//   various declaration orders, pointer-typed last_screen, param_1 local.
//   None produced original's `push ebx; xor ebx,ebx; setne bl` pattern.
// - Remaining mismatch: backend register-allocation basin.
//   Original: ebp=param_1, bl=is_new(push ebx), [esp+14h]=focus_copy, [esp+10h]=pe
//   Rebuilt:  ebx=focus_copy, eax/is_new on stack, no push ebx, pe shifted 4 bytes.
//   VC5 allocator picks eax/ecx over ebx for is_new given this TU context.
// Left in scratch — register-allocation shape issue, all semantics/calls correct.

#include "..\..\include\game_globals.h"

class TDrawArea;
class TDrawSystem;
class TEasy_Panel;

typedef struct { unsigned char r,g,b,a; } PE;

extern int last_screen;

extern void RGE_fade_palette(TDrawArea*, int, float, int, void*, int, int);
extern void GetPaletteEntries(void*, int, int, void*);

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
    int pal_entry[256];
    PE pe;
    int focus_copy;
    int is_new;

    pe.r = 0;
    pe.g = 0;
    pe.b = 0;
    focus_copy = this->save_focus;
    is_new = (this != (TScreenPanel*)last_screen) ? 1 : 0;
    TDrawArea* area = this->draw_area;

    if (area && area->draw_system && param_1 && is_new) {
        TDrawSystem* sys = area->draw_system;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            if (this->palette_handle) {
                GetPaletteEntries(this->palette_handle, 0, 0x100, pal_entry + 1);
            } else {
                area->GetPalette(pal_entry + 1);
            }

            RGE_fade_palette(area, *(int*)&pe, 0.13f, 1, 0, -1, -1);
            area->Clear(0, 0, 0);
            area->draw_system->Paint(0);
        }
    }

    this->TEasy_Panel::set_focus(param_1);

    area = this->draw_area;
    if (area && area->draw_system && param_1 && is_new) {
        TDrawSystem* sys = area->draw_system;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            RGE_fade_palette(area, focus_copy, 0.0f, 2, pal_entry + 1, -1, -1);
            this->after_set_focus();
            RGE_fade_palette(area, focus_copy, 0.0f, 1, 0, -1, -1);
            area->draw_system->Paint(0);
            RGE_fade_palette(area, focus_copy, 0.13f, 2, pal_entry + 1, -1, -1);
        }
    }

    if (param_1 != focus_copy && focus_copy)
        last_screen = (int)this;
}
