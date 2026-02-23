#include "../include/TRIBE_Credits_Screen.h"

#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/TMusic_System.h"
#include "../include/RGE_Font.h"
#include "../include/TScrollTextPanel.h"
#include "../include/TRIBE_Screen_Main_Menu.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TShape.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <windows.h>

#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char* kScrCredSourcePath = "C:/msdev/work/age1_x1/scr_cred.cpp";

static void RGE_translate_palette(tagPALETTEENTRY* in_pal, tagPALETTEENTRY* out_pal, tagPALETTEENTRY target, long amount_percent, int skip1, int skip2) {
    // Fully verified. Source of truth: scr_cred.cpp.decomp @ 0x00493420
    for (int index1 = 0; index1 < 256; ++index1) {
        if (index1 == skip1 || index1 == skip2) {
            out_pal[index1] = in_pal[index1];
            continue;
        }

        const int red = (uint)in_pal[index1].peRed & 0xff;
        const int green = (uint)in_pal[index1].peGreen & 0xff;
        const int blue = (uint)in_pal[index1].peBlue & 0xff;

        int intense[3];
        intense[0] = red;
        intense[1] = green;
        intense[2] = blue;
        for (int pass = 0; pass < 2; ++pass) {
            for (int i = 0; i < 2; ++i) {
                if (intense[i] < intense[i + 1]) {
                    int t = intense[i];
                    intense[i] = intense[i + 1];
                    intense[i + 1] = t;
                }
            }
        }

        int iVar7 = (int)((uint)(intense[1] + intense[2]) * (uint)(0xff - intense[0]));
        iVar7 = ((iVar7 + ((iVar7 >> 0x1f) & 0x1ff)) >> 9) + intense[0];

        const int target_r = (((uint)target.peRed & 0xff) * iVar7) / 0xff;
        const int target_g = (((uint)target.peGreen & 0xff) * iVar7) / 0xff;
        const int target_b = (((uint)target.peBlue & 0xff) * iVar7) / 0xff;

        const int delta_r = (target_r - red) * (int)amount_percent;
        const int delta_g = (target_g - green) * (int)amount_percent;
        const int delta_b = (target_b - blue) * (int)amount_percent;

        out_pal[index1].peRed = (BYTE)(red + (delta_r / 100));
        out_pal[index1].peGreen = (BYTE)(green + (delta_g / 100));
        out_pal[index1].peBlue = (BYTE)(blue + (delta_b / 100));
        out_pal[index1].peFlags = in_pal[index1].peFlags;
    }
}

namespace {

tagPALETTEENTRY g_fade_target;
float g_fade_duration = 0.0f;
float g_fade_duration_sq = 0.0f;
uchar g_fade_type = 0;
int g_fade_skip1 = -1;
int g_fade_skip2 = -1;
TDrawArea* g_fade_area = nullptr;
ulong g_fade_start_time = 0;
int g_fade_amount = 0;
tagPALETTEENTRY g_fade_palette[256];
tagPALETTEENTRY g_fade_out_palette[256];

} // namespace

// Fully verified. Source of truth: scr_cred.cpp.decomp @ 0x00493420
void RGE_fade_palette_start(TDrawArea* param_1, tagPALETTEENTRY param_2, float param_3, uchar param_4, tagPALETTEENTRY* param_5, int param_6, int param_7) {
    g_fade_target = param_2;
    g_fade_duration = param_3;
    g_fade_duration_sq = g_fade_duration * g_fade_duration;
    g_fade_type = param_4;
    g_fade_skip1 = param_6;
    g_fade_skip2 = param_7;
    g_fade_area = param_1;

    memset(g_fade_palette, 0, sizeof(g_fade_palette));
    memset(g_fade_out_palette, 0, sizeof(g_fade_out_palette));

    if (param_5 == nullptr) {
        if (param_1) {
            param_1->GetPalette(g_fade_palette);
        }
    } else {
        memcpy(g_fade_palette, param_5, sizeof(tagPALETTEENTRY) * 256);
    }

    g_fade_start_time = debug_timeGetTime((char*)kScrCredSourcePath, 0x2B5);

    // fade out (type==1) starts at 0%, fade in (type!=1) starts at 100% (fully toward target)
    g_fade_amount = (g_fade_type == 1) ? 0 : 100;
}

// Fully verified. Source of truth: scr_cred.cpp.decomp @ 0x00493540
int RGE_fade_palette_step() {
    int done = 0;
    if (g_fade_area == nullptr) {
        return 1;
    }

    const ulong now = debug_timeGetTime((char*)kScrCredSourcePath, (g_fade_type == 1) ? 0x2C8 : 0x2DC);
    const float delta_time = (float)(int)(now - g_fade_start_time) * 0.001f;

    // Source of truth: scr_cred.cpp.asm @ 0x00493540 uses a quadratic curve:
    //   fade-out: amount = (t^2 / duration^2) * 100
    //   fade-in:  amount = ((duration - t)^2 / duration^2) * 100
    if (g_fade_type == 1) {
        if ((g_fade_duration <= 0.0f) || (g_fade_duration < delta_time) || (delta_time < 0.0f)) {
            g_fade_amount = 100;
        } else {
            g_fade_amount = (int)(((delta_time * delta_time) / g_fade_duration_sq) * 100.0f);
        }

        if (g_fade_amount >= 100) {
            g_fade_amount = 100;
            done = 1;
        }
    } else {
        const float remaining = g_fade_duration - delta_time;
        if ((g_fade_duration <= 0.0f) || (g_fade_duration < remaining) || (remaining < 0.0f)) {
            g_fade_amount = 0;
        } else {
            g_fade_amount = (int)(((remaining * remaining) / g_fade_duration_sq) * 100.0f);
        }

        if (g_fade_amount <= 0) {
            g_fade_amount = 0;
            done = 1;
        }
    }

    RGE_translate_palette(g_fade_palette, g_fade_out_palette, g_fade_target, g_fade_amount, g_fade_skip1, g_fade_skip2);
    g_fade_area->SetPalette(g_fade_out_palette);
    return done;
}

// Fully verified. Source of truth: scr_cred.cpp.asm @ 0x004926E0
TRIBE_Credits_Screen::TRIBE_Credits_Screen()
    : TScreenPanel((char*)"Credits Screen") {
    this->text_panel = nullptr;
    this->text_set = 1;
    this->picture_set = 1;
    this->last_picture_time = 0;
    this->last_pause_time = 0;
    this->mode = ModeNone;
    this->first_draw = 1;
    this->text_done = 0;
    for (int i = 0; i < 7; ++i) {
        this->back_pics[i] = nullptr;
    }

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    if (!TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr_cred", 0xc38b, 1)) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1e0);

    RGE_Font* font = rge_base_game->get_font(4);

    char* credits_text = nullptr;
    int fd = _open("data2\\list.cr", _O_BINARY);
    if (fd != -1) {
        _lseek(fd, 0, SEEK_END);
        const long size = _tell(fd);
        credits_text = (char*)calloc(size + 1, 0x400);
        if (credits_text != nullptr) {
            _lseek(fd, 0, SEEK_SET);
            _read(fd, credits_text, size);
        }
        _close(fd);
    }

    this->text_panel = new TScrollTextPanel((TPanel*)this, this->render_area,
                                            (this->ideal_width / 2) - 0xfa,
                                            (this->ideal_height / 2) - 0x96,
                                            500, 300, 0x1e,
                                            font ? font->font : nullptr,
                                            font ? font->font_wid : 0,
                                            font ? font->font_hgt : 0,
                                            credits_text);

    if (credits_text != nullptr) {
        free(credits_text);
    }

    this->back_pics[0] = this->background_pic;
    char temp_file_name[32];
    int file_id = 0xc3eb;
    for (int idx = 1; idx < 7; ++idx) {
        sprintf(temp_file_name, "credit%d", file_id - 0xc3e9);
        this->back_pics[idx] = new TShape(temp_file_name, file_id);
        ++file_id;
    }

    TMusic_System* music = rge_base_game->music_system;
    if (music != nullptr && music->music_type == 1 && music->track_count == 0xf) {
        music->play_tracks(0xf, 0xf, 1, 0, 0);
    }
}

// Fully verified. Source of truth: scr_cred.cpp.asm @ 0x00492970
TRIBE_Credits_Screen::~TRIBE_Credits_Screen() {
    for (int i = 0; i < 7; ++i) {
        if (this->back_pics[i] != nullptr) {
            delete this->back_pics[i];
            this->back_pics[i] = nullptr;
        }
    }
    this->background_pic = nullptr;

    if (this->text_panel != nullptr) {
        delete this->text_panel;
        this->text_panel = nullptr;
    }

    TMusic_System* music = rge_base_game ? rge_base_game->music_system : nullptr;
    if (music != nullptr && music->music_type == 1 && music->track_count == 0xf) {
        music->play_tracks(5, 0xe, 1, 0, 0);
    }
}

// Fully verified. Source of truth: scr_cred.cpp.asm @ 0x00492A40
long TRIBE_Credits_Screen::handle_mouse_down(uchar /*param_1*/, long /*param_2*/, long /*param_3*/, int /*param_4*/, int /*param_5*/) {
    this->close_screen();
    return 1;
}

// Fully verified. Source of truth: scr_cred.cpp.asm @ 0x00492A50
long TRIBE_Credits_Screen::handle_idle() {
    if (this->mode == ModeNone) {
        if (this->last_picture_time == 0) {
            this->last_picture_time = debug_timeGetTime((char*)kScrCredSourcePath, 0xf1);
        } else {
            const ulong now = debug_timeGetTime((char*)kScrCredSourcePath, 0xf5);
            if ((now - this->last_picture_time) >= 0x2710) {
                const bool palette_mode =
                    (this->render_area != nullptr) &&
                    (this->render_area->DrawSystem != nullptr) &&
                    ((this->render_area->DrawSystem->ScreenMode == 2) || (this->render_area->DrawSystem->DrawType == 1));

                if (palette_mode) {
                    this->mode = ModeFadeOut;
                    this->color.peRed = 0;
                    this->color.peGreen = 0;
                    this->color.peBlue = 0;
                    this->color.peFlags = 0;

                    if (this->palette == nullptr) {
                        this->render_area->GetPalette(this->color_table);
                    } else {
                        GetPaletteEntries((HPALETTE)this->palette, 0, 0x100, this->color_table);
                    }

                    RGE_fade_palette_start(this->render_area, this->color, 0.5f, 1, nullptr, 0xff, -1);
                } else {
                    this->mode = ModePause;
                }
            }
        }
    } else if (this->mode == ModeFadeOut) {
        if (RGE_fade_palette_step() != 0) {
            this->mode = ModePause;
            this->last_pause_time = 0;
            this->set_redraw(TPanel::RedrawMode::Redraw);
            this->handle_paint();
            if (this->render_area != nullptr && this->render_area->DrawSystem != nullptr) {
                this->render_area->DrawSystem->Paint(nullptr);
            }
        }
    } else if (this->mode == ModePause) {
        if (this->last_pause_time == 0) {
            this->last_pause_time = debug_timeGetTime((char*)kScrCredSourcePath, 0x11a);
        } else {
            debug_timeGetTime((char*)kScrCredSourcePath, 0x11e);

            this->picture_set = this->picture_set + 1;
            this->mode = ModeFadeIn;
            if (this->picture_set > 7) {
                this->picture_set = 1;
            }

            this->background_pic = this->back_pics[this->picture_set - 1];
            this->set_redraw(TPanel::RedrawMode::Redraw);
            this->handle_paint();
            if (this->render_area != nullptr && this->render_area->DrawSystem != nullptr) {
                this->render_area->DrawSystem->Paint(nullptr);
            }

            const bool palette_mode =
                (this->render_area != nullptr) &&
                (this->render_area->DrawSystem != nullptr) &&
                ((this->render_area->DrawSystem->ScreenMode == 2) || (this->render_area->DrawSystem->DrawType == 1));
            if (palette_mode) {
                RGE_fade_palette_start(this->render_area, this->color, 0.5f, 2, this->color_table, 0xff, -1);
            } else {
                this->mode = ModeNone;
                this->last_picture_time = debug_timeGetTime((char*)kScrCredSourcePath, 0x138);
            }
        }
    } else if (this->mode == ModeFadeIn) {
        if (RGE_fade_palette_step() != 0) {
            this->mode = ModeNone;
            this->last_picture_time = debug_timeGetTime((char*)kScrCredSourcePath, 0x142);
        }
    }

    if (this->text_done != 0) {
        this->close_screen();
        return 1;
    }
    return TPanel::handle_idle();
}

// Fully verified. Source of truth: scr_cred.cpp.asm @ 0x00492CC0
void TRIBE_Credits_Screen::draw() {
    if (this->mode == ModePause) {
        const bool palette_mode =
            (this->render_area != nullptr) &&
            (this->render_area->DrawSystem != nullptr) &&
            ((this->render_area->DrawSystem->ScreenMode == 2) || (this->render_area->DrawSystem->DrawType == 1));
        if (palette_mode) {
            this->render_area->Clear(&this->clip_rect, 0);
            return;
        }
    }

    if (this->first_draw != 0) {
        for (int i = 0; i < 7; ++i) {
            this->background_pic = this->back_pics[i];
            TScreenPanel::draw();
        }
        this->first_draw = 0;
        this->background_pic = this->back_pics[0];
    }

    TScreenPanel::draw();
}

// Fully verified. Source of truth: scr_cred.cpp.asm @ 0x00492D50
long TRIBE_Credits_Screen::key_down_action(long param_1, short /*param_2*/, int /*param_3*/, int /*param_4*/, int /*param_5*/) {
    if ((param_1 != 0xd) && (param_1 != 0x1b)) {
        return 0;
    }
    this->close_screen();
    return 1;
}

// Fully verified. Source of truth: scr_cred.cpp.asm @ 0x00492D70
long TRIBE_Credits_Screen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 != nullptr && (param_1 == (TPanel*)this->text_panel) && (param_2 == 1)) {
        this->text_done = 1;
        return 1;
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: scr_cred.cpp.asm @ 0x00492DB0
void TRIBE_Credits_Screen::close_screen() {
    if (panel_system == nullptr) {
        return;
    }

    TPanel* game_screen = panel_system->panel((char*)"Game Screen");
    char* next_name = nullptr;
    if (game_screen == nullptr) {
        new TRIBE_Screen_Main_Menu();
        next_name = (char*)"Main Menu";
    } else {
        if (rge_base_game != nullptr && rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        next_name = (char*)"Game Screen";
    }

    panel_system->setCurrentPanel(next_name, 0);
    panel_system->destroyPanel((char*)"Credits Screen");
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TRIBE_Credits_Screen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Credits_Screen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Credits_Screen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Credits_Screen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Credits_Screen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Credits_Screen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Credits_Screen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Credits_Screen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Credits_Screen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Credits_Screen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Credits_Screen::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Credits_Screen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Credits_Screen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Credits_Screen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Credits_Screen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Credits_Screen::paint() { TScreenPanel::paint(); }
long TRIBE_Credits_Screen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Credits_Screen::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Credits_Screen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Credits_Screen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Credits_Screen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Credits_Screen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Credits_Screen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Credits_Screen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Credits_Screen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Credits_Screen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Credits_Screen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Credits_Screen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Credits_Screen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Credits_Screen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Credits_Screen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Credits_Screen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Credits_Screen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Credits_Screen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Credits_Screen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Credits_Screen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Credits_Screen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Credits_Screen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Credits_Screen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Credits_Screen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Credits_Screen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Credits_Screen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Credits_Screen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Credits_Screen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Credits_Screen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Credits_Screen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Credits_Screen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Credits_Screen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Credits_Screen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Credits_Screen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Credits_Screen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Credits_Screen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Credits_Screen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Credits_Screen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Credits_Screen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Credits_Screen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

