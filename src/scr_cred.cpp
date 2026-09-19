
#include "../include/scr_cred.h"
#include "../include/game_globals.h"
#include "../include/music.h"
#include "../include/scr_main.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void* hpal, unsigned int start, unsigned int count, tagPALETTEENTRY* entries);

extern char scr_cred_draw_context_name[];

// Keep the module's original declaration order while the shared header owns
// the storage types and definitions.
extern float g_scroll_time_scale;
extern float g_fade_progress_scale;

void RGE_translate_palette(tagPALETTEENTRY*, tagPALETTEENTRY*,
                           tagPALETTEENTRY, long, int, int);
void RGE_fade_palette_start(TDrawArea* surface_in, tagPALETTEENTRY color_in,
                            float fade_time_in, unsigned char direction_in,
                            tagPALETTEENTRY* new_palette,
                            int ignore_color1_in, int ignore_color2_in);
int RGE_fade_palette_step();

TRIBE_Credits_Screen::TRIBE_Credits_Screen()
    : TScreenPanel("Credits Screen") {
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

    this->set_ideal_size(640, 480);

    RGE_Font* font = rge_base_game->get_font(RGE_FONT_COPPERPLATE_12_BOLD_ALT);
    char* file_buf = 0;
    int fd = _open("data2\\list.cr", _O_BINARY);
    int size = 0;
    if (fd != -1) {
        _lseek(fd, 0, SEEK_END);
        size = _tell(fd);
        file_buf = (char*)calloc(size + 1, 1024);
        if (file_buf != 0) {
            _lseek(fd, 0, SEEK_SET);
            _read(fd, file_buf, size);
        }
        _close(fd);
    }

    TScrollTextPanel* scroll_panel = new TScrollTextPanel(this, this->render_area,
                                                          (this->pnl_wid / 2) - 250, (this->pnl_hgt / 2) - 150, 500, 300, 30,
                                                          font->font, font->font_wid, font->font_hgt, file_buf);
    this->text_panel = scroll_panel;

    if (file_buf != 0) {
        free(file_buf);
    }

    int id = 0xC3EB;
    this->back_pics[0] = this->background_pic;
    TShape** shape_slot = &this->back_pics[1];
    for (; id - 0xC3EA < 7; ++id) {
        char temp_file_name[13];
        sprintf(temp_file_name, "credit%d", id - 0xC3E9);
        *shape_slot = new TShape(temp_file_name, id);
        ++shape_slot;
    }

    TMusic_System* music = rge_base_game->music_system;
    if (music != 0 && music->music_type == 1 && music->track_count == 15) {
        music->play_tracks(15, 15, 1, 0, 0);
    }
}

TRIBE_Credits_Screen::~TRIBE_Credits_Screen() {
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
    if (music != 0 && music->music_type == 1 && music->track_count == 15) {
        music->play_tracks(5, 14, 1, 0, 0);
    }
}

long TRIBE_Credits_Screen::handle_mouse_down(unsigned char mouse_button_in, long x,
                                             long y, int ctrl_key, int shift_key) {
    this->close_screen();
    return 1;
}

long TRIBE_Credits_Screen::handle_idle() {
    int current_mode = this->mode;

    if (current_mode == 1) {
        if (this->last_picture_time == 0) {
            goto set_time_f1;
        }

        if (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 245) - this->last_picture_time < 10000) {
            goto tail;
        }

        if (this->render_area->DrawSystem->ScreenMode == 2 || this->render_area->DrawSystem->DrawType == 1) {
            this->mode = 2;
            this->color.peRed = 0;
            this->color.peGreen = 0;
            this->color.peBlue = 0;

            if (this->palette == 0) {
                this->render_area->GetPalette(this->color_table);
            } else {
                GetPaletteEntries(this->palette, 0, 256, this->color_table);
            }

            RGE_fade_palette_start(this->render_area, this->color, 0.5f, 1, (tagPALETTEENTRY*)0, 0xFF, -1);
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
            this->last_pause_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 282);
            goto tail;
        }

        debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 286);
        this->mode = 5;
        ++this->picture_set;
        if (this->picture_set > 7) {
            this->picture_set = 1;
        }
        this->background_pic = this->back_pics[this->picture_set - 1];
        this->set_redraw(TPanel::RedrawNormal);
        this->handle_paint();
        this->render_area->DrawSystem->Paint((tagRECT*)0);

        if (this->render_area->DrawSystem->ScreenMode == 2 || this->render_area->DrawSystem->DrawType == 1) {
            RGE_fade_palette_start(this->render_area, this->color, 0.5f, 2, this->color_table, 0xFF, -1);
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
    this->last_picture_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 241);
    goto tail;

set_time_138:
    this->last_picture_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 312);
    goto tail;

set_time_142:
    this->last_picture_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 322);

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

long TRIBE_Credits_Screen::key_down_action(long key, short count, int alt_key,
                                           int ctrl_key, int shift_key) {
    if (key == VK_RETURN || key == VK_ESCAPE) {
        this->close_screen();
        return 1;
    }
    return 0;
}

long TRIBE_Credits_Screen::action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2) {
    long action_result;

    if (from_panel != 0 && from_panel == this->text_panel && (action_in == 1)) {
        this->text_done = 1;
        return 1;
    }
    action_result = this->TEasy_Panel::action(from_panel, action_in, action_val1, action_val2);
    return action_result;
}

void TRIBE_Credits_Screen::close_screen() {
    if (panel_system.panel("Game Screen")) {
        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system.setCurrentPanel("Game Screen", 0);
    } else {
        new TRIBE_Screen_Main_Menu();
        panel_system.setCurrentPanel("Main Menu", 0);
    }
    panel_system.destroyPanel("Credits Screen");
}

TScrollTextPanel::TScrollTextPanel(TPanel* parent_in,
                                   TDrawArea* render_area_in, long x, long y,
                                   long wid, long hgt, int speed_in,
                                   void* font_in, long font_wid_in,
                                   long font_hgt_in, char* text_in)
    : TTextPanel() {
    this->speed = speed_in;
    this->scroll = 0;
    this->last_time = 0;
    this->done = 0;

    char* no_text = 0;
    if (this->setup(render_area_in, parent_in, x, y, wid, hgt, font_in, font_wid_in, font_hgt_in, 0, 0, 0, 0, 0, 0,
                    no_text) != 0) {
        this->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignCenter);
        this->set_word_wrap(1);
        this->set_text(text_in);
        this->set_text_color(this->text_color1, this->text_color2);
    }
}

TScrollTextPanel::~TScrollTextPanel() {
}

void TScrollTextPanel::set_text(char* text_in) {
    TTextPanel::set_text(text_in);
    this->last_time = 0;
    this->scroll = 0;
    this->done = 0;
}

long TScrollTextPanel::handle_idle() {
    if (this->last_time == 0) {
        this->last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 476);
    } else {
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 479);
        __int64 elapsed = (unsigned long)(now - this->last_time);
        int amount = (long)(((double)elapsed * g_scroll_time_scale) * this->speed);
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

void TScrollTextPanel::draw() {
    this->need_redraw = 0;
    if (this->render_area != 0 && this->visible != 0 && this->active != 0) {
        this->draw_background();
        this->draw_setup(0);
        void* dc = this->render_area->GetDc(scr_cred_draw_context_name);
        if (dc != 0) {
            SelectClipRgn(dc, this->clip_rgn);
            void* old_font = SelectObject(dc, this->font);
            SetBkMode(dc, TRANSPARENT);
            for (short i = 0; i < this->num_lines; i++) {
                this->draw_scrolled_line(dc, i, i, this->text_color1, this->text_color2);
            }
            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc(scr_cred_draw_context_name);
        }
        this->draw_border();
        this->draw_finish();
    }
}

void TScrollTextPanel::draw_scrolled_line(void* dc, short draw_row,
                                          short text_line, unsigned long color1,
                                          unsigned long color2) {
    char* text;
    short text_len;
    char* temp_text2;
    short text2_len;
    RECT line_rect;
    long x2;
    long text_y;
    text_len = 0;
    text2_len = 0;
    text = this->get_text((long)text_line);
    temp_text2 = this->get_text2((long)text_line);
    if (text == 0) {
        if (temp_text2 == 0) return;
    }
    if (text != 0) {
        text_len = (short)strlen(text);
    }
    if (temp_text2 != 0) {
        text2_len = (short)strlen(temp_text2);
    }

    this->calc_line_pos(dc, draw_row, text_line, &line_rect, 0);

    x2 = line_rect.left;
    if ((this->horz_align != 0) && (this->horz_align != 6)) {
        x2 += 5;
    }
    long second_text_x = this->second_column_pos + x2;
    text_y = this->pnl_hgt - this->scroll + line_rect.top;
    if ((text_line == (short)this->num_lines - 1) && (this->font_hgt + text_y < this->pnl_y)) {
        this->done = 1;
    }

    if (this->clip_rgn2 != 0) {
        SelectClipRgn(dc, this->clip_rgn2);
    }

    switch (this->text_style) {
    case 0:
        SetTextColor(dc, color1);
        if (text != 0) {
            TextOutA(dc, x2, text_y, text, (int)text_len);
        }
        break;
    case 1:
        SetTextColor(dc, color1);
        if (text != 0) {
            TextOutA(dc, x2 - 1, text_y + 1, text, (int)text_len);
        }
        SetTextColor(dc, color2);
        if (text != 0) {
            TextOutA(dc, x2, text_y, text, (int)text_len);
        }
        break;
    case 2:
        SetTextColor(dc, color2);
        if (text != 0) {
            TextOutA(dc, x2 - 1, text_y + 1, text, (int)text_len);
        }
        SetTextColor(dc, color1);
        if (text != 0) {
            TextOutA(dc, x2, text_y, text, (int)text_len);
        }
        break;
    default:
        break;
    }

    if (temp_text2 == 0) return;

    if (this->clip_rgn2 != 0) {
        SelectClipRgn(dc, this->clip_rgn);
    }

    switch (this->text_style) {
    case 0:
        SetTextColor(dc, color1);
        TextOutA(dc, second_text_x, text_y, temp_text2, (int)text2_len);
        return;
    case 1:
        SetTextColor(dc, color1);
        TextOutA(dc, second_text_x - 1, text_y + 1, temp_text2, (int)text2_len);
        SetTextColor(dc, color2);
        TextOutA(dc, second_text_x, text_y, temp_text2, (int)text2_len);
        return;
    case 2:
        SetTextColor(dc, color2);
        TextOutA(dc, second_text_x - 1, text_y + 1, temp_text2, (int)text2_len);
        SetTextColor(dc, color1);
        TextOutA(dc, second_text_x, text_y, temp_text2, (int)text2_len);
        return;
    default:
        return;
    }
}

void RGE_fade_palette_start(TDrawArea* surface_in, tagPALETTEENTRY color_in,
                            float fade_time_in, unsigned char direction_in,
                            tagPALETTEENTRY* new_palette,
                            int ignore_color1_in, int ignore_color2_in) {
    palette_fade_surface = surface_in;
    palette_fade_color = color_in;
    palette_fade_duration = fade_time_in;
    palette_fade_direction = direction_in;
    palette_fade_ignore_color1 = ignore_color1_in;
    palette_fade_ignore_color2 = ignore_color2_in;

    for (int i = 0; i < 256; i++) {
        palette_fade_source[i].peRed = 0;
        palette_fade_result[i].peRed = 0;
        palette_fade_source[i].peBlue = 0;
        palette_fade_result[i].peBlue = 0;
        palette_fade_source[i].peGreen = 0;
        palette_fade_result[i].peGreen = 0;
        palette_fade_source[i].peFlags = 0;
        palette_fade_result[i].peFlags = 0;
    }

    if (new_palette == 0) {
        surface_in->GetPalette(palette_fade_source);
    } else {
        tagPALETTEENTRY* target = palette_fade_source;
        tagPALETTEENTRY* source = new_palette;
        do {
            target->peRed = source->peRed;
            target->peBlue = source->peBlue;
            target->peGreen = source->peGreen;
            target->peFlags = source->peFlags;
            ++target;
            ++source;
        } while ((int)target < (int)palette_fade_result);
    }

    palette_fade_start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 693);
    palette_fade_duration_squared = palette_fade_duration * palette_fade_duration;

    if (palette_fade_direction == 1) {
        palette_fade_amount = 0;
    } else {
        palette_fade_amount = 100;
    }
}

int RGE_fade_palette_step() {
    float delta_time;
    int amount;
    unsigned char done = 0;

    if (palette_fade_direction == 1) {
        unsigned int cur = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 712);
        int ticks = cur - palette_fade_start_time;
        delta_time = (float)ticks * 0.001f;

        if (palette_fade_duration <= 0.0 || delta_time > palette_fade_duration || delta_time < 0.0f) {
            amount = 100;
        } else {
            float v = delta_time * delta_time / palette_fade_duration_squared * g_fade_progress_scale;
            amount = (long)v;
        }
        palette_fade_amount = amount;
        if (amount >= 100) {
            palette_fade_amount = 100;
            done = 1;
        }
    } else {
        unsigned int cur = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 732);
        int ticks = cur - palette_fade_start_time;
        delta_time = palette_fade_duration - (float)ticks * 0.001f;

        if (palette_fade_duration <= 0.0 || delta_time > palette_fade_duration || delta_time < 0.0f) {
            amount = 0;
        } else {
            float v = delta_time * delta_time / palette_fade_duration_squared * g_fade_progress_scale;
            amount = (long)v;
        }
        palette_fade_amount = amount;
        if (amount <= 0) {
            palette_fade_amount = 0;
            done = 1;
        }
    }

    RGE_translate_palette(palette_fade_source, palette_fade_result, palette_fade_color, palette_fade_amount,
                          palette_fade_ignore_color1, palette_fade_ignore_color2);
    palette_fade_surface->SetPalette(palette_fade_result);

    return done;
}
