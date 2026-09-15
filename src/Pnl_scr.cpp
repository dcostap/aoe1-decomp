
#include "../include/Pnl_scr.h"

extern void __cdecl RGE_fade_palette(TDrawArea*, PALETTEENTRY, float,
                                     unsigned char, PALETTEENTRY*, int, int);

static TScreenPanel* last_screen;

TScreenPanel::TScreenPanel() : TEasy_Panel() {
}

TScreenPanel::TScreenPanel(char* name) : TEasy_Panel(name) {
}

TScreenPanel::~TScreenPanel() {
}

long TScreenPanel::setup(TDrawArea* render_area_in, char* info_file_name,
                         long resource_file_id, int allow_shadow_area_in) {
    return TEasy_Panel::setup(render_area_in, 0, info_file_name, resource_file_id, 1, 0, 0, 0, 0,
                              allow_shadow_area_in) != 0;
}

long TScreenPanel::setup(TDrawArea* render_area_in, char* palette_file,
                         long pal_res_id, unsigned char color_in,
                         int allow_shadow_area_in) {
    return TEasy_Panel::setup(render_area_in, 0, 0, -1, 1, 0, 0, 0, 0,
                              allow_shadow_area_in) != 0;
}

void TScreenPanel::draw() {
    TEasy_Panel::draw();
}

long TScreenPanel::handle_paint() {
    TPanel::handle_paint();
    return 0;
}

void TScreenPanel::set_focus(int have_focus_in) {
    PALETTEENTRY color;
    struct {
        int save_focus;
        PALETTEENTRY color_table[256];
    } local;
    bool is_new;

    local.save_focus = this->have_focus;
    is_new = (this != last_screen) ? 1 : 0;

    if (this->render_area && this->render_area->DrawSystem && have_focus_in && is_new) {
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

    this->TEasy_Panel::set_focus(have_focus_in);

    if (this->render_area && this->render_area->DrawSystem && have_focus_in && is_new) {
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

    if (have_focus_in != local.save_focus && this->have_focus)
        last_screen = this;
}
