#include "../include/RGE_Panel_Time.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/globals.h"

#include <cstdio>
#include <cstring>
#include <windows.h>

namespace {
const char* const kRpnlTimDraw = "rpnl_tim::draw";
}

RGE_Panel_Time::RGE_Panel_Time(TDrawArea* param_1, TPanel* param_2, void* param_3) : TPanel() {
    // Fully verified. Source of truth: rpnl_tim.cpp.decomp @ 0x0048A680
    this->font = param_3;
    this->error_code = 0;
    this->game_time = 0;
    this->last_game_time = 0;
    this->old_time = -1;
    this->real_time = 0;

    if (this->setup(param_1, param_2, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
    }
}

RGE_Panel_Time::~RGE_Panel_Time() {}

long RGE_Panel_Time::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); } // TODO: STUB
void RGE_Panel_Time::set_rect(tagRECT param_1) { TPanel::set_rect(param_1); } // TODO: STUB
void RGE_Panel_Time::set_rect(long param_1, long param_2, long param_3, long param_4) { TPanel::set_rect(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Panel_Time::set_color(uchar param_1) { TPanel::set_color(param_1); } // TODO: STUB
void RGE_Panel_Time::set_active(int param_1) { TPanel::set_active(param_1); } // TODO: STUB
void RGE_Panel_Time::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); } // TODO: STUB
void RGE_Panel_Time::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Panel_Time::set_redraw(RedrawMode param_1) { TPanel::set_redraw(param_1); } // TODO: STUB
void RGE_Panel_Time::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); } // TODO: STUB
void RGE_Panel_Time::draw_setup(int param_1) { TPanel::draw_setup(param_1); } // TODO: STUB
void RGE_Panel_Time::draw_finish() { TPanel::draw_finish(); } // TODO: STUB
void RGE_Panel_Time::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); } // TODO: STUB
void RGE_Panel_Time::draw_offset(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset(param_1, param_2, param_3); } // TODO: STUB
void RGE_Panel_Time::draw_rect2(tagRECT* param_1) { TPanel::draw_rect2(param_1); } // TODO: STUB
void RGE_Panel_Time::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset2(param_1, param_2, param_3); } // TODO: STUB
void RGE_Panel_Time::paint() { TPanel::paint(); } // TODO: STUB
long RGE_Panel_Time::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TPanel::wnd_proc(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::handle_size(long param_1, long param_2) { return TPanel::handle_size(param_1, param_2); } // TODO: STUB
long RGE_Panel_Time::handle_paint() { return TPanel::handle_paint(); } // TODO: STUB
long RGE_Panel_Time::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long RGE_Panel_Time::handle_char(long param_1, short param_2) { return TPanel::handle_char(param_1, param_2); } // TODO: STUB
long RGE_Panel_Time::handle_command(uint param_1, long param_2) { return TPanel::handle_command(param_1, param_2); } // TODO: STUB
long RGE_Panel_Time::handle_user_command(uint param_1, long param_2) { return TPanel::handle_user_command(param_1, param_2); } // TODO: STUB
long RGE_Panel_Time::handle_timer_command(uint param_1, long param_2) { return TPanel::handle_timer_command(param_1, param_2); } // TODO: STUB
long RGE_Panel_Time::handle_scroll(long param_1, long param_2) { return TPanel::handle_scroll(param_1, param_2); } // TODO: STUB
long RGE_Panel_Time::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long RGE_Panel_Time::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TPanel::handle_mouse_move(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long RGE_Panel_Time::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long RGE_Panel_Time::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_move_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); } // TODO: STUB
long RGE_Panel_Time::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); } // TODO: STUB
long RGE_Panel_Time::char_action(long param_1, short param_2) { return TPanel::char_action(param_1, param_2); } // TODO: STUB
long RGE_Panel_Time::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TPanel::action(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Panel_Time::get_true_render_rect(tagRECT* param_1) { TPanel::get_true_render_rect(param_1); } // TODO: STUB
int RGE_Panel_Time::is_inside(long param_1, long param_2) { return TPanel::is_inside(param_1, param_2); } // TODO: STUB
void RGE_Panel_Time::set_focus(int param_1) { TPanel::set_focus(param_1); } // TODO: STUB
void RGE_Panel_Time::set_tab_order(TPanel* param_1, TPanel* param_2) { TPanel::set_tab_order(param_1, param_2); } // TODO: STUB
void RGE_Panel_Time::set_tab_order(TPanel** param_1, short param_2) { TPanel::set_tab_order(param_1, param_2); } // TODO: STUB
uchar RGE_Panel_Time::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TPanel::get_help_info(param_1, param_2, param_3, param_4); } // TODO: STUB
void RGE_Panel_Time::stop_sound_system() { TPanel::stop_sound_system(); } // TODO: STUB
int RGE_Panel_Time::restart_sound_system() { return TPanel::restart_sound_system(); } // TODO: STUB
void RGE_Panel_Time::take_snapshot() { TPanel::take_snapshot(); } // TODO: STUB
void RGE_Panel_Time::handle_reactivate() { TPanel::handle_reactivate(); } // TODO: STUB

void RGE_Panel_Time::draw() {
    // Fully verified. Source of truth: rpnl_tim.cpp.decomp @ 0x0048A740
    if (this->render_area == nullptr || this->active == 0 || this->visible == 0) {
        return;
    }

    this->draw_setup(0);

    HDC dc = (HDC)this->render_area->GetDc((char*)kRpnlTimDraw);
    if (dc != nullptr) {
        SelectClipRgn(dc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);

        char str[100];
        if (rge_base_game->get_paused() != 0) {
            SetBkColor(dc, 0xFFFFFF);
            SetBkMode(dc, 2);
            SetTextColor(dc, 0x0000FF);
            sprintf(str, "Paused");
            TextOutA(dc, this->pnl_x, this->pnl_y - 2, str, (int)strlen(str));
        } else {
            SetBkMode(dc, 1);
            SetTextColor(dc, 0xFFFFFF);

            long seconds = this->game_time;
            long minutes = 0;
            long hours = 0;
            if (seconds > 0x3B) {
                minutes = seconds / 0x3C;
                seconds = seconds % 0x3C;
                if (minutes > 0x3B) {
                    hours = minutes / 0x3C;
                    minutes = minutes % 0x3C;
                }
            }

            sprintf(str, "%02ld:%02ld:%02ld (%3.1f)", hours, minutes, seconds, (double)rge_base_game->world->game_speed);
            TextOutA(dc, this->pnl_x, this->pnl_y - 2, str, (int)strlen(str));

            long player_count = (long)rge_base_game->world->player_num;
            long row_y = 0x0D;
            for (long i = 1; i < player_count; ++i) {
                long countdown_timer = -1;
                rge_base_game->get_countdown_timer(i, &countdown_timer);
                if (countdown_timer < 0) {
                    continue;
                }

                tagPALETTEENTRY palette_color;
                GetPaletteEntries((HPALETTE)rge_base_game->draw_system->Pal,
                                  rge_base_game->world->players[i]->color_table->map_color,
                                  1,
                                  &palette_color);
                COLORREF color = RGB(palette_color.peRed, palette_color.peGreen, palette_color.peBlue);
                SetTextColor(dc, color);

                sprintf(str, this->get_string(0x2C24), countdown_timer);
                TextOutA(dc, this->pnl_x, this->pnl_y + row_y, str, (int)strlen(str));
                row_y += 0x0D;
            }
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc((char*)kRpnlTimDraw);
    }

    this->draw_finish();
}

long RGE_Panel_Time::handle_idle() {
    // Fully verified. Source of truth: rpnl_tim.cpp.decomp @ 0x0048AA70
    TPanel::handle_idle();

    this->game_time = (long)(rge_base_game->world->world_time / 1000);
    unsigned long old_world_time = (unsigned long)(rge_base_game->world->old_time / 1000);
    if (old_world_time != 0) {
        if (this->old_time == -1) {
            this->old_time = (long)old_world_time;
            this->real_time = 0;
        } else {
            this->real_time = (long)old_world_time - this->old_time;
        }
    }

    if (this->game_time != this->last_game_time) {
        this->set_redraw(TPanel::Redraw);
        if (this->parent_panel != nullptr) {
            this->parent_panel->set_redraw(TPanel::Redraw);
        }
        this->last_game_time = this->game_time;
    }

    return 0;
}
