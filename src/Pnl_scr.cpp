
#include "../include/Pnl_scr.h"

extern void __cdecl RGE_fade_palette(TDrawArea*, PALETTEENTRY, float,
                                     unsigned char, PALETTEENTRY*, int, int);

static TScreenPanel* last_screen;

TScreenPanel::TScreenPanel() : TEasy_Panel()
{
}

TScreenPanel::TScreenPanel(char* name) : TEasy_Panel(name)
{
}

TScreenPanel::~TScreenPanel()
{
}

long TScreenPanel::setup(TDrawArea* draw_area, char* text, long id, int value)
{
    return TEasy_Panel::setup(draw_area, 0, text, id, 1, 0, 0, 0, 0, value) != 0;
}

long TScreenPanel::setup(TDrawArea* draw_area, char*, long, unsigned char,
                         int value)
{
    return TEasy_Panel::setup(draw_area, 0, 0, -1, 1, 0, 0, 0, 0, value) != 0;
}

void TScreenPanel::draw()
{
    TEasy_Panel::draw();
}

long TScreenPanel::handle_paint()
{
    TPanel::handle_paint();
    return 0;
}

void TScreenPanel::set_focus(int focus)
{
    PALETTEENTRY color;
    struct {
        int save_focus;
        PALETTEENTRY color_table[256];
    } local;
    bool is_new;

    local.save_focus = this->have_focus;
    is_new = (this != last_screen) ? 1 : 0;

    if (this->render_area && this->render_area->DrawSystem && focus && is_new) {
        TDrawSystem* system = this->render_area->DrawSystem;
        if (system->ScreenMode == 2 || system->DrawType == 1) {
            color.peRed = 0;
            color.peGreen = 0;
            color.peBlue = 0;
            if (!this->palette) {
                this->render_area->GetPalette(local.color_table);
            } else {
                GetPaletteEntries(this->palette, 0, 0x100, local.color_table);
            }

            RGE_fade_palette(this->render_area, color, 0.13f, 1, 0, -1, -1);
            this->render_area->Clear(0, 0);
            this->render_area->DrawSystem->Paint(0);
        }
    }

    this->TEasy_Panel::set_focus(focus);

    if (this->render_area && this->render_area->DrawSystem && focus && is_new) {
        TDrawSystem* system = this->render_area->DrawSystem;
        if (system->ScreenMode == 2 || system->DrawType == 1) {
            RGE_fade_palette(this->render_area, color, 0.0f, 2,
                             local.color_table, -1, -1);
            this->handle_paint();
            RGE_fade_palette(this->render_area, color, 0.0f, 1, 0, -1, -1);
            this->render_area->DrawSystem->Paint(0);
            RGE_fade_palette(this->render_area, color, 0.13f, 2,
                             local.color_table, -1, -1);
        }
    }

    if (focus != local.save_focus && this->have_focus)
        last_screen = this;
}
