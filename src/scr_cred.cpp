// scr_cred.cpp
// PDB source order: lines 46-753.
// The source owns all sixteen normal functions in this compiland.
// The deleting destructors at 00492950 and 00492F50 are compiler generated.

#include "../include/scr_cred.h"
#include "../include/music.h"
#include "../include/scr_main.h"
#include <fcntl.h>
#include <io.h>
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void* hpal, unsigned int start, unsigned int count,
    tagPALETTEENTRY* entries);

extern "C" unsigned long __cdecl debug_timeGetTime(char*, int);

extern const char s_scr_cred_draw_005862e0[];

extern float DAT_00572968;
extern float DAT_0057297c;

extern float DAT_0086b290;
extern unsigned int DAT_0086b294;
extern int DAT_0086b298;
extern int DAT_0086b29c;
extern int DAT_0086b2a0;
extern unsigned char DAT_0086b2a4;
extern tagPALETTEENTRY DAT_0086b2a8;
extern float DAT_0086b2ac;
extern tagPALETTEENTRY DAT_0086b2b0[];
extern tagPALETTEENTRY DAT_0086b6b0[256];
extern TDrawArea* DAT_0086bab0;

void RGE_translate_palette(tagPALETTEENTRY*, tagPALETTEENTRY*,
                           tagPALETTEENTRY, long, int, int);
void RGE_fade_palette_start(TDrawArea*, tagPALETTEENTRY, float,
                            unsigned char, tagPALETTEENTRY*, int, int);
int RGE_fade_palette_step();

TRIBE_Credits_Screen::TRIBE_Credits_Screen()
    : TScreenPanel("Credits Screen")
{
    int zero = 0;
    int one = 1;

    this->text_panel = 0;
    this->text_set = one;
    this->picture_set = one;
    this->last_picture_time = zero;
    this->last_pause_time = zero;
    this->mode = one;
    this->first_draw = one;
    this->text_done = zero;

    for (int i = 0; i < 7; ++i) {
        this->back_pics[i] = 0;
    }

    if (this->setup(rge_base_game->draw_area, "scr_cred", 0xC38B, one) == 0) {
        this->error_code = one;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);

    RGE_Font* font = rge_base_game->get_font(4);
    char* file_buf = 0;
    int fd = _open("data2\\list.cr", _O_BINARY);
    int size = 0;
    if (fd != -1) {
        _lseek(fd, 0, SEEK_END);
        size = _tell(fd);
        file_buf = (char*)calloc(size + 1, 0x400);
        if (file_buf != 0) {
            _lseek(fd, 0, SEEK_SET);
            _read(fd, file_buf, size);
        }
        _close(fd);
    }

    TScrollTextPanel* scroll_panel = new TScrollTextPanel(
        this, this->render_area,
        (this->pnl_wid / 2) - 0xFA, (this->pnl_hgt / 2) - 0x96,
        0x1F4, 0x12C, 0x1E,
        font->font, font->font_wid, font->font_hgt, file_buf);
    this->text_panel = scroll_panel;

    if (file_buf != 0) {
        free(file_buf);
    }

    int id = 0xC3EB;
    this->back_pics[0] = (TShape*)this->background_pic;
    TShape** shape_slot = &this->back_pics[1];
    for (; id - 0xC3EA < 7; ++id) {
        char temp_file_name[13];
        sprintf(temp_file_name, "credit%d", id - 0xC3E9);
        *shape_slot = new TShape(temp_file_name, id);
        ++shape_slot;
    }

    TMusic_System* music = rge_base_game->music_system;
    if (music != 0 && music->music_type == 1 && music->track_count == 0x0F) {
        music->play_tracks(0x0F, 0x0F, 1, 0, 0);
    }
}

TRIBE_Credits_Screen::~TRIBE_Credits_Screen()
{
    for (int i = 0; i < 7; i++) {
        if (this->back_pics[i] != 0) {
            delete this->back_pics[i];
            this->back_pics[i] = 0;
        }
    }

    this->background_pic = 0;

    if (this->text_panel != 0) {
        delete this->text_panel;
        this->text_panel = 0;
    }

    TMusic_System* music = rge_base_game->music_system;
    if (music != 0 && music->music_type == 1 && music->track_count == 0xF) {
        music->play_tracks(5, 0xE, 1, 0, 0);
    }
}

long TRIBE_Credits_Screen::handle_mouse_down(unsigned char, long, long, int, int)
{
    this->close_screen();
    return 1;
}

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

            if (this->palette == 0) {
                this->render_area->GetPalette(this->color_table);
            } else {
                GetPaletteEntries(this->palette, 0, 0x100,
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
            this->set_redraw(TPanel::RedrawNormal);
            this->handle_paint();
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
        this->set_redraw(TPanel::RedrawNormal);
        this->handle_paint();
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

void TRIBE_Credits_Screen::draw() {
    if (this->mode == 4) {
        TDrawSystem* draw_system = this->render_area->DrawSystem;
        if (draw_system->ScreenMode == 2 || draw_system->DrawType == 1) {
            this->render_area->Clear(&this->clip_rect, 0);
            return;
        }
    }

    if (this->first_draw != 0) {
        for (int i = 0; i < 7; i++) {
            this->background_pic = this->back_pics[i];
            TScreenPanel::draw();
        }
        this->first_draw = 0;
        this->background_pic = this->back_pics[0];
    }

    TScreenPanel::draw();
}

long TRIBE_Credits_Screen::key_down_action(long key, short, int, int, int)
{
    if (key == 0xD || key == 0x1B) {
        this->close_screen();
        return 1;
    }
    return 0;
}

long TRIBE_Credits_Screen::action(TPanel* param_1, long param_2,
                                  unsigned long param_3,
                                  unsigned long param_4) {
    long lVar1;

    if (((param_1 != (TPanel*)0x0) &&
         ((TScrollTextPanel*)param_1 == this->text_panel)) &&
        (param_2 == 1)) {
        this->text_done = 1;
        return 1;
    }
    lVar1 = this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
    return lVar1;
}

void TRIBE_Credits_Screen::close_screen()
{
    if (panel_system.panel("Game Screen")) {
        if (rge_base_game->singlePlayerGame() == 1 &&
            rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system.setCurrentPanel("Game Screen", 0);
    } else {
        new TRIBE_Screen_Main_Menu();
        panel_system.setCurrentPanel("Main Menu", 0);
    }
    panel_system.destroyPanel("Credits Screen");
}

TScrollTextPanel::TScrollTextPanel(TPanel* parent, TDrawArea* draw_area,
                                   long x, long y, long width, long height,
                                   int speed_value, void* font, long font_wid,
                                   long font_hgt, char* text)
    : TTextPanel()
{
    this->speed = speed_value;
    this->scroll = 0;
    this->last_time = 0;
    this->done = 0;

    char* no_text = 0;
    if (this->setup(draw_area, parent, x, y, width, height, font, font_wid,
                    font_hgt, 0, 0, 0, 0, 0, 0, no_text) != 0) {
        this->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignCenter);
        this->set_word_wrap(1);
        this->set_text(text);
        this->set_text_color(this->text_color1, this->text_color2);
    }
}

TScrollTextPanel::~TScrollTextPanel()
{
}

void TScrollTextPanel::set_text(char* text) {
    TTextPanel::set_text(text);
    this->last_time = 0;
    this->scroll = 0;
    this->done = 0;
}

// ACCEPTED_DRIFT: equivalent x87 multiply encoding differs by two bytes.
long TScrollTextPanel::handle_idle()
{
    if (this->last_time == 0) {
        this->last_time = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x1DC);
    } else {
        unsigned long now = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x1DF);
        __int64 elapsed = (unsigned long)(now - this->last_time);
        int amount = (long)(((double)elapsed * DAT_00572968) * this->speed);
        if (amount > 0) {
            this->scroll += amount;
            this->set_redraw(TPanel::RedrawNormal);
            this->last_time = now;
        }
    }
    if (this->done != 0) {
        if (this->curr_child != 0) {
            this->curr_child->action(this, 1, 0, 0);
        }
    }
    return this->TPanel::handle_idle();
}

void TScrollTextPanel::draw()
{
    this->need_redraw = 0;
    if (this->render_area != 0 && this->visible != 0 && this->active != 0)
    {
        this->draw_background();
        this->draw_setup(0);
        void* dc = this->render_area->GetDc((char*)s_scr_cred_draw_005862e0);
        if (dc != 0)
        {
            SelectClipRgn(dc, this->clip_rgn);
            void* old_font = SelectObject(dc, this->font);
            SetBkMode(dc, 1);
            for (short i = 0; i < this->num_lines; i++)
            {
                this->draw_scrolled_line(dc, i, i,
                                         this->text_color1, this->text_color2);
            }
            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc((char*)s_scr_cred_draw_005862e0);
        }
        this->draw_border();
        this->draw_finish();
    }
}

void TScrollTextPanel::draw_scrolled_line(void* hdc, short draw_index,
                                          short line_index,
                                          unsigned long color1,
                                          unsigned long color2) {
    char* text;
    short text_len;
    char* temp_text2;
    short text2_length;
    RECT line_rect;
    long text_x;
    long text_y;
    temp_text2 = 0;
    text2_length = 0;
    text = this->get_text((long)line_index);
    temp_text2 = this->get_text2((long)line_index);
    if (text == 0) {
        if (temp_text2 == 0) return;
    }
    if (text != 0) {
        text_len = (short)strlen(text);
    }
    if (temp_text2 != 0) {
        text2_length = (short)strlen(temp_text2);
    }

    this->calc_line_pos(hdc, draw_index, line_index, &line_rect, 0);

    text_x = line_rect.left;
    if ((this->horz_align != 0) && (this->horz_align != 6)) {
        text_x += 5;
    }
    text_x = this->second_column_pos + text_x;
    text_y = this->pnl_hgt - this->scroll + line_rect.top;
    if ((line_index == (short)this->num_lines - 1) &&
        (this->font_hgt + text_y < this->pnl_y)) {
        this->done = 1;
    }

    if (this->clip_rgn2 != 0) {
        SelectClipRgn(hdc, this->clip_rgn2);
    }

    switch (this->text_style) {
    case 0:
        SetTextColor(hdc, color1);
        if (text != 0) {
            TextOutA(hdc, text_x, text_y, text, (int)text_len);
        }
        break;
    case 1:
        SetTextColor(hdc, color1);
        if (text != 0) {
            TextOutA(hdc, text_x - 1, text_y + 1, text, (int)text_len);
        }
        SetTextColor(hdc, color2);
        if (text != 0) {
            TextOutA(hdc, text_x, text_y, text, (int)text_len);
        }
        break;
    case 2:
        SetTextColor(hdc, color2);
        if (text != 0) {
            TextOutA(hdc, text_x - 1, text_y + 1, text, (int)text_len);
        }
        SetTextColor(hdc, color1);
        if (text != 0) {
            TextOutA(hdc, text_x, text_y, text, (int)text_len);
        }
        break;
    default:
        break;
    }

    if (temp_text2 == 0) return;

    if (this->clip_rgn2 != 0) {
        SelectClipRgn(hdc, this->clip_rgn);
    }

    switch (this->text_style) {
    case 0:
        SetTextColor(hdc, color1);
        TextOutA(hdc, text_x, text_y, temp_text2, (int)text2_length);
        return;
    case 1:
        SetTextColor(hdc, color1);
        TextOutA(hdc, text_x - 1, text_y + 1, temp_text2, (int)text2_length);
        SetTextColor(hdc, color2);
        TextOutA(hdc, text_x, text_y, temp_text2, (int)text2_length);
        return;
    case 2:
        SetTextColor(hdc, color2);
        TextOutA(hdc, text_x - 1, text_y + 1, temp_text2, (int)text2_length);
        SetTextColor(hdc, color1);
        TextOutA(hdc, text_x, text_y, temp_text2, (int)text2_length);
        return;
    default:
        return;
    }
}

void RGE_fade_palette_start(TDrawArea* draw_area, tagPALETTEENTRY fade_color,
                            float fade_time, unsigned char fade_type,
                            tagPALETTEENTRY* palette, int first, int last)
{
    DAT_0086bab0 = draw_area;
    DAT_0086b2a8 = fade_color;
    DAT_0086b290 = fade_time;
    DAT_0086b2a4 = fade_type;
    DAT_0086b298 = first;
    DAT_0086b29c = last;

    for (int i = 0; i < 256; i++) {
        DAT_0086b2b0[i].peRed = 0;
        DAT_0086b6b0[i].peRed = 0;
        DAT_0086b2b0[i].peBlue = 0;
        DAT_0086b6b0[i].peBlue = 0;
        DAT_0086b2b0[i].peGreen = 0;
        DAT_0086b6b0[i].peGreen = 0;
        DAT_0086b2b0[i].peFlags = 0;
        DAT_0086b6b0[i].peFlags = 0;
    }

    if (palette == 0) {
        draw_area->GetPalette(DAT_0086b2b0);
    } else {
        tagPALETTEENTRY* target = DAT_0086b2b0;
        tagPALETTEENTRY* source = palette;
        do {
            target->peRed = source->peRed;
            target->peBlue = source->peBlue;
            target->peGreen = source->peGreen;
            target->peFlags = source->peFlags;
            ++target;
            ++source;
        } while ((int)target < (int)DAT_0086b6b0);
    }

    DAT_0086b294 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x2B5);
    DAT_0086b2ac = DAT_0086b290 * DAT_0086b290;

    if (DAT_0086b2a4 == 1) {
        DAT_0086b2a0 = 0;
    } else {
        DAT_0086b2a0 = 100;
    }
}

int RGE_fade_palette_step()
{
    float delta;
    int amount;
    unsigned char done = 0;

    if (DAT_0086b2a4 == 1) {
        unsigned int cur = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x2C8);
        int ticks = cur - DAT_0086b294;
        delta = (float)ticks * 0.001f;

        if (DAT_0086b290 <= 0.0 || delta > DAT_0086b290 || delta < 0.0f) {
            amount = 100;
        } else {
            float v = delta * delta / DAT_0086b2ac * DAT_0057297c;
            amount = (long)v;
        }
        DAT_0086b2a0 = amount;
        if (amount >= 100) {
            DAT_0086b2a0 = 100;
            done = 1;
        }
    } else {
        unsigned int cur = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x2DC);
        int ticks = cur - DAT_0086b294;
        delta = DAT_0086b290 - (float)ticks * 0.001f;

        if (DAT_0086b290 <= 0.0 || delta > DAT_0086b290 || delta < 0.0f) {
            amount = 0;
        } else {
            float v = delta * delta / DAT_0086b2ac * DAT_0057297c;
            amount = (long)v;
        }
        DAT_0086b2a0 = amount;
        if (amount <= 0) {
            DAT_0086b2a0 = 0;
            done = 1;
        }
    }

    RGE_translate_palette(DAT_0086b2b0, DAT_0086b6b0, DAT_0086b2a8,
                          DAT_0086b2a0, DAT_0086b298, DAT_0086b29c);
    DAT_0086bab0->SetPalette(DAT_0086b6b0);

    return done;
}
