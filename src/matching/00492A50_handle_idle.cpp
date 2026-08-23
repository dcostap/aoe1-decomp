// VA: 00492A50 TRIBE_Credits_Screen::handle_idle
// PDB donor: scr_cred.cpp lines 217-333
// Attempt log:
// - baseline reconstruction: model the real TPanel/TEasy_Panel base
//   sizes, named credits-screen fields, typed virtual dirty/draw calls, and
//   the period palette/timestamp state machine before codegen tuning.

#include "../../include/scr_cred_context.h"

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void* hpal, unsigned int start, unsigned int count,
    tagPALETTEENTRY* entries);

void RGE_fade_palette_start(TDrawArea* draw_area, tagPALETTEENTRY fade_color,
                            float fade_time, uchar fade_type,
                            tagPALETTEENTRY* palette, int first, int last);
int RGE_fade_palette_step();

long TRIBE_Credits_Screen::handle_idle()
{
    int current_mode = this->mode;

    if (current_mode == 1) {
        if (this->last_picture_time == 0) {
            goto set_time_f1;
        }

        if (debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0xF5)
                - this->last_picture_time < 10000) {
            goto tail;
        }

        if (this->render_area->DrawSystem->ScreenMode == 2 ||
            this->render_area->DrawSystem->DrawType == 1) {
            this->mode = 2;
            this->color.peRed = 0;
            this->color.peGreen = 0;
            this->color.peBlue = 0;

            if (this->palette_handle == 0) {
                this->render_area->GetPalette(this->color_table);
            } else {
                GetPaletteEntries(this->palette_handle, 0, 0x100,
                                  this->color_table);
            }

            RGE_fade_palette_start(this->render_area, this->color, 0.5f, 1,
                                   (tagPALETTEENTRY*)0, 0xFF, -1);
        } else {
            this->mode = 4;
        }
        goto tail;
    } else if (current_mode == 2) {
        if (RGE_fade_palette_step() != 0) {
            this->mode = 4;
            this->last_pause_time = 0;
            this->set_redraw(1);
            this->draw();
            this->render_area->DrawSystem->Paint((tagRECT*)0);
        }
        goto tail;
    } else if (current_mode == 4) {
        if (this->last_pause_time == 0) {
            this->last_pause_time = debug_timeGetTime(
                (char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x11A);
            goto tail;
        }

        debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x11E);
        this->mode = 5;
        ++this->picture_set;
        if (this->picture_set > 7) {
            this->picture_set = 1;
        }
        this->background_pic = this->back_pics[this->picture_set - 1];
        this->set_redraw(1);
        this->draw();
        this->render_area->DrawSystem->Paint((tagRECT*)0);

        if (this->render_area->DrawSystem->ScreenMode == 2 ||
            this->render_area->DrawSystem->DrawType == 1) {
            RGE_fade_palette_start(this->render_area, this->color, 0.5f, 2,
                                   this->color_table, 0xFF, -1);
            goto tail;
        }

        this->mode = 1;
        goto set_time_138;
    } else if (current_mode == 5) {
        if (RGE_fade_palette_step() != 0) {
            this->mode = 1;
            goto set_time_142;
        }
        goto tail;
    } else {
        goto tail;
    }

set_time_f1:
    this->last_picture_time = debug_timeGetTime(
        (char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0xF1);
    goto tail;

set_time_138:
    this->last_picture_time = debug_timeGetTime(
        (char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x138);
    goto tail;

set_time_142:
    this->last_picture_time = debug_timeGetTime(
        (char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x142);

tail:
    if (this->text_done != 0) {
        this->close_screen();
        return 1;
    }
    return TPanel::handle_idle();
}
