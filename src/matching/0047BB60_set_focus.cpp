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

#include "..\..\include\pnl_scr_context.h"

struct FocusPalette {
    int have_focus;
    PALETTEENTRY entries[256];
};

void TScreenPanel::set_focus(int param_1)
{
    FocusPalette palette;
    PALETTEENTRY pe;
    bool is_new;
    palette.have_focus = this->have_focus;
    is_new = (this != last_screen) ? 1 : 0;

    if (this->draw_area && this->draw_area->DrawSystem && param_1 && is_new) {
        TDrawSystem* sys = this->draw_area->DrawSystem;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            pe.peRed = 0;
            pe.peGreen = 0;
            pe.peBlue = 0;
            if (!this->palette_handle) {
                this->draw_area->GetPalette(palette.entries);
            } else {
                GetPaletteEntries(this->palette_handle, 0, 0x100, palette.entries);
            }

            RGE_fade_palette(this->draw_area, pe, 0.13f, 1, 0, -1, -1);
            this->draw_area->Clear(0, 0);
            this->draw_area->DrawSystem->Paint(0);
        }
    }

    this->TEasy_Panel::set_focus(param_1);

    if (this->draw_area && this->draw_area->DrawSystem && param_1 && is_new) {
        TDrawSystem* sys = this->draw_area->DrawSystem;
        if (sys->ScreenMode == 2 || sys->DrawType == 1) {
            RGE_fade_palette(this->draw_area, pe, 0.0f, 2, palette.entries, -1, -1);
            this->handle_paint();
            RGE_fade_palette(this->draw_area, pe, 0.0f, 1, 0, -1, -1);
            this->draw_area->DrawSystem->Paint(0);
            RGE_fade_palette(this->draw_area, pe, 0.13f, 2, palette.entries, -1, -1);
        }
    }

    if (param_1 != palette.have_focus && this->have_focus)
        last_screen = this;
}
