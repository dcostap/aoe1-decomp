#include "RGE_Main_View.h"

#include "RGE_Base_Game.h"
#include "RGE_Game_World.h"
#include "RGE_Map.h"
#include "RGE_Player.h"
#include "RGE_Prog_Info.h"
#include "RGE_Static_Object.h"
#include "RGE_Master_Static_Object.h"
#include "RGE_Action_Object.h"
#include "RGE_Master_Action_Object.h"
#include "RGE_Pick_Info.h"
#include "RGE_Sprite.h"
#include "RGE_Active_Sprite_List.h"
#include "RGE_Task.h"
#include "RGE_Task_List.h"
#include "RGE_Visible_Map.h"
#include "TDrawArea.h"
#include "TDrawSystem.h"
#include "DisplaySelectedObjRec.h"
#include "debug_helpers.h"
#include "globals.h"

#include <windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>

extern RGE_Pick_Obj_Info Picked_Objects[0x40];

static const char* const kVwMainPath = "C:\\msdev\\work\\age1_x1\\vw_main.cpp";

static float calc_scroll_dist(unsigned long delta, unsigned long interval) {
    if (interval == 0) {
        return 0.0f;
    }

    const float f = (float)delta / (float)interval;
    const int base = (int)f;
    const float frac = f - (float)base;
    return (float)base + ((frac >= 0.5f) ? 0.5f : 0.0f);
}

RGE_Main_View::RGE_Main_View() {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053DAB0
    this->map_view = nullptr;
    this->last_mouse_scroll_time = 0;
    this->mouse_scrolling = 0;
    this->last_key_scroll_time = 0;
    this->key_scrolling = 0;
    this->save_player = nullptr;

    this->panel_type = 10;
    this->RGE_Main_View::mouse_last_x = -1;
    this->RGE_Main_View::mouse_last_y = -1;
}

RGE_Main_View::~RGE_Main_View() {
}

// -----------------------------------------------------------------------------
// Virtual forwarding layer (header redeclares TPanel virtuals)
// -----------------------------------------------------------------------------

long RGE_Main_View::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return RGE_View::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void RGE_Main_View::set_rect(tagRECT param_1) { RGE_View::set_rect(param_1); }
void RGE_Main_View::set_rect(long param_1, long param_2, long param_3, long param_4) { RGE_View::set_rect(param_1, param_2, param_3, param_4); }
void RGE_Main_View::set_color(uchar param_1) { TPanel::set_color(param_1); }
void RGE_Main_View::set_active(int param_1) { TPanel::set_active(param_1); }
void RGE_Main_View::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void RGE_Main_View::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void RGE_Main_View::set_redraw(RedrawMode param_1) { TPanel::set_redraw(param_1); }
void RGE_Main_View::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void RGE_Main_View::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void RGE_Main_View::draw_finish() { TPanel::draw_finish(); }
void RGE_Main_View::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); }
void RGE_Main_View::draw_offset(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset(param_1, param_2, param_3); }
void RGE_Main_View::draw_rect2(tagRECT* param_1) { TPanel::draw_rect2(param_1); }
void RGE_Main_View::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset2(param_1, param_2, param_3); }
void RGE_Main_View::paint() { TPanel::paint(); }
long RGE_Main_View::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long RGE_Main_View::handle_size(long param_1, long param_2) { return TPanel::handle_size(param_1, param_2); }
long RGE_Main_View::handle_paint() { return TPanel::handle_paint(); }
long RGE_Main_View::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Main_View::handle_char(long param_1, short param_2) { return TPanel::handle_char(param_1, param_2); }
long RGE_Main_View::handle_command(uint param_1, long param_2) { return TPanel::handle_command(param_1, param_2); }
long RGE_Main_View::handle_user_command(uint param_1, long param_2) { return TPanel::handle_user_command(param_1, param_2); }
long RGE_Main_View::handle_timer_command(uint param_1, long param_2) { return TPanel::handle_timer_command(param_1, param_2); }
long RGE_Main_View::handle_scroll(long param_1, long param_2) { return TPanel::handle_scroll(param_1, param_2); }
long RGE_Main_View::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Main_View::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long RGE_Main_View::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long RGE_Main_View::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Main_View::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long RGE_Main_View::char_action(long param_1, short param_2) { return TPanel::char_action(param_1, param_2); }
long RGE_Main_View::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TPanel::action(param_1, param_2, param_3, param_4); }
void RGE_Main_View::get_true_render_rect(tagRECT* param_1) { TPanel::get_true_render_rect(param_1); }
int RGE_Main_View::is_inside(long param_1, long param_2) { return TPanel::is_inside(param_1, param_2); }
void RGE_Main_View::set_focus(int param_1) { RGE_View::set_focus(param_1); }
void RGE_Main_View::set_tab_order(TPanel* param_1, TPanel* param_2) { TPanel::set_tab_order(param_1, param_2); }
void RGE_Main_View::set_tab_order(TPanel** param_1, short param_2) { TPanel::set_tab_order(param_1, param_2); }
void RGE_Main_View::stop_sound_system() { TPanel::stop_sound_system(); }
int RGE_Main_View::restart_sound_system() { return TPanel::restart_sound_system(); }
void RGE_Main_View::take_snapshot() { TPanel::take_snapshot(); }
void RGE_Main_View::handle_reactivate() { TPanel::handle_reactivate(); }
int RGE_Main_View::pick_through_fog(RGE_Static_Object* param_1) { return RGE_View::pick_through_fog(param_1); }
int RGE_Main_View::pick_weight(RGE_Static_Object* param_1, int param_2) { return RGE_View::pick_weight(param_1, param_2); }
void RGE_Main_View::end_scroll_view() { RGE_View::end_scroll_view(); }
int RGE_Main_View::do_paint(long param_1, long param_2, long param_3, long param_4, int param_5) { return RGE_View::do_paint(param_1, param_2, param_3, param_4, param_5); }

// -----------------------------------------------------------------------------
// vw_main.cpp transliterations
// -----------------------------------------------------------------------------

long RGE_Main_View::handle_idle() {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053DB40
    color_log('E', 'E', 5);
    this->do_auto_scroll();
    color_log('E', '\x16', 5);
    this->handle_keys();
    color_log('E', '$', 5);
    long ret = TPanel::handle_idle();
    color_log('E', '_', 5);
    return ret;
}

int RGE_Main_View::do_auto_scroll() {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053DBA0
    const int prog_mode = rge_base_game->prog_mode;
    if ((prog_mode != 4) && (prog_mode != 6) && (prog_mode != 7) && (prog_mode != 5)) {
        this->mouse_scrolling = 0;
        return 0;
    }
    if (rge_base_game->get_paused() != 0) {
        this->mouse_scrolling = 0;
        return 0;
    }
    if (rge_base_game->prog_info == nullptr || rge_base_game->prog_info->auto_scroll == 0) {
        this->mouse_scrolling = 0;
        return 0;
    }
    if (this->render_area == nullptr || this->render_area->Wnd == nullptr) {
        this->mouse_scrolling = 0;
        return 0;
    }
    if (GetForegroundWindow() != (HWND)this->render_area->Wnd) {
        this->mouse_scrolling = 0;
        return 0;
    }
    if (panel_system != nullptr && panel_system->modalPanelValue != nullptr) {
        this->mouse_scrolling = 0;
        return 0;
    }
    if (panel_system != nullptr && panel_system->mouseOwnerValue != nullptr && panel_system->mouseOwnerValue != this) {
        this->mouse_scrolling = 0;
        return 0;
    }
    if (this->key_scrolling != 0) {
        this->mouse_scrolling = 0;
        return 0;
    }

    tagRECT rect;
    tagPOINT point;
    GetWindowRect((HWND)this->render_area->Wnd, (RECT*)&rect);
    GetCursorPos((POINT*)&point);

    short vert_scroll = 0;
    short horz_scroll = 0;

    // If mouse buttons down, do not auto-scroll.
    if ((GetAsyncKeyState(VK_LBUTTON) < 0) || (GetAsyncKeyState(VK_RBUTTON) < 0)) {
        vert_scroll = 0;
        horz_scroll = 0;
        goto done;
    }

    const long edge = rge_base_game->prog_info->mouse_scroll_edge;
    if (point.y < rect.top + edge) {
        vert_scroll = -1;
    } else if (point.y > rect.bottom - edge) {
        vert_scroll = 1;
    }

    if (point.x < rect.left + edge) {
        horz_scroll = -1;
    } else if (point.x > rect.right - edge) {
        horz_scroll = 1;
    }

    if (vert_scroll == 0 && horz_scroll == 0) {
        goto done;
    }

    if (this->player == nullptr) {
        goto done;
    }

    const ulong now = debug_timeGetTime(kVwMainPath, 0xAA);
    float dist;
    if (this->mouse_scrolling == 0) {
        dist = 1.0f;
        this->mouse_scrolling = 1;
    } else {
        const ulong delta = now - this->last_mouse_scroll_time;
        dist = calc_scroll_dist(delta, rge_base_game->prog_info->key_scroll_interval);
    }

    if (dist > rge_base_game->prog_info->mouse_scroll_max_dist) {
        dist = rge_base_game->prog_info->mouse_scroll_max_dist;
    }
    if (dist <= 0.0f) {
        goto done;
    }

    const float dist2 = dist + dist;

    if (vert_scroll == -1) {
        this->player->set_view_loc(this->player->view_x - dist, this->player->view_y - dist);
    } else if (vert_scroll == 1) {
        this->player->set_view_loc(this->player->view_x + dist, this->player->view_y + dist);
    }

    if (horz_scroll == -1) {
        this->player->set_view_loc(this->player->view_x + dist2, this->player->view_y - dist2);
    } else if (horz_scroll == 1) {
        this->player->set_view_loc(this->player->view_x - dist2, this->player->view_y + dist2);
    }

    this->set_redraw(TPanel::RedrawMode::Redraw);
    if (this->map_view != nullptr) {
        this->map_view->set_redraw(TPanel::RedrawMode::Redraw);
    }
    this->last_mouse_scroll_time = now;

done:
    if (vert_scroll == 0 && horz_scroll == 0) {
        this->mouse_scrolling = 0;
    }
    return this->mouse_scrolling;
}

int RGE_Main_View::handle_keys() {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053DEB0
    if (rge_base_game->get_paused() != 0) {
        this->key_scrolling = 0;
        return 0;
    }

    const int prog_mode = rge_base_game->prog_mode;
    if ((prog_mode != 4) && (prog_mode != 6) && (prog_mode != 7) && (prog_mode != 5)) {
        this->key_scrolling = 0;
        return 0;
    }

    if (this->render_area == nullptr || this->render_area->Wnd == nullptr) {
        this->key_scrolling = 0;
        return 0;
    }
    if (GetForegroundWindow() != (HWND)this->render_area->Wnd) {
        this->key_scrolling = 0;
        return 0;
    }
    if (this->have_focus == 0) {
        this->key_scrolling = 0;
        return 0;
    }

    unsigned char pbKeyState[256];
    GetKeyboardState((PBYTE)pbKeyState);

    short lr_scroll = 0;
    short ud_scroll = 0;
    int changed = 0;

    RGE_Prog_Info* prog = rge_base_game->prog_info;
    if ((rge_base_game->game_mode == 0x12) && (this->player != nullptr) && (this->player->selected_obj != nullptr)) {
        RGE_Static_Object* obj = this->player->selected_obj;

        if (pbKeyState[VK_UP] > 1) {
            obj->teleport(obj->world_x + prog->key_scroll_object_move, obj->world_y - prog->key_scroll_object_move, 0.0f);
            changed = 1;
        }
        if (pbKeyState[VK_DOWN] > 1) {
            obj->teleport(obj->world_x - prog->key_scroll_object_move, obj->world_y + prog->key_scroll_object_move, 0.0f);
            changed = 1;
        }
        if (pbKeyState[VK_LEFT] > 1) {
            obj->teleport(obj->world_x - prog->key_scroll_object_move, obj->world_y - prog->key_scroll_object_move, 0.0f);
            changed = 1;
        }
        if (pbKeyState[VK_RIGHT] > 1) {
            obj->teleport(obj->world_x + prog->key_scroll_object_move, obj->world_y + prog->key_scroll_object_move, 0.0f);
            changed = 1;
        }

        goto done;
    }

    if (this->player == nullptr) {
        goto done;
    }

    if (pbKeyState[VK_LEFT] > 1) {
        lr_scroll = -1;
    } else if (pbKeyState[VK_RIGHT] > 1) {
        lr_scroll = 1;
    }

    if (pbKeyState[VK_UP] > 1) {
        ud_scroll = -1;
    } else if (pbKeyState[VK_DOWN] > 1) {
        ud_scroll = 1;
    }

    if (lr_scroll == 0 && ud_scroll == 0) {
        goto done;
    }

    {
        const ulong now = debug_timeGetTime(kVwMainPath, 0x153);
        float dist;
        if (this->key_scrolling == 0) {
            dist = 1.0f;
            this->key_scrolling = 1;
        } else {
            const ulong delta = now - this->last_key_scroll_time;
            dist = calc_scroll_dist(delta, prog->key_scroll_interval);
        }

        if (dist > prog->key_scroll_max_dist) {
            dist = prog->key_scroll_max_dist;
        }
        if (dist <= 0.0f) {
            goto done;
        }

        const float dist2 = dist + dist;

        if (lr_scroll == -1) {
            this->player->set_view_loc(this->player->view_x - dist, this->player->view_y - dist);
        } else if (lr_scroll == 1) {
            this->player->set_view_loc(this->player->view_x + dist, this->player->view_y + dist);
        }

        if (ud_scroll == -1) {
            this->player->set_view_loc(this->player->view_x + dist2, this->player->view_y - dist2);
        } else if (ud_scroll == 1) {
            this->player->set_view_loc(this->player->view_x - dist2, this->player->view_y + dist2);
        }

        this->last_key_scroll_time = now;
        changed = 1;
    }

done:
    if (lr_scroll == 0 && ud_scroll == 0) {
        this->key_scrolling = 0;
    }
    if (changed != 0) {
        this->set_redraw(TPanel::RedrawMode::Redraw);
        if (this->map_view != nullptr) {
            this->map_view->set_redraw(TPanel::RedrawMode::Redraw);
        }
    }
    return changed;
}

long RGE_Main_View::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053E280
    const ulong start = debug_timeGetTime(kVwMainPath, 0x1AE);
    long ret = TPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5);
    const ulong end = debug_timeGetTime(kVwMainPath, 0x1B0);
    rge_base_game->add_to_timing(0xD, end - start);
    return ret;
}

long RGE_Main_View::mouse_move_action(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: vw_main.cpp.decomp @ 0x0053E2F0
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;

    const int prog_mode = rge_base_game->prog_mode;
    if ((prog_mode != 4) && (prog_mode != 6) && (prog_mode != 7) && (prog_mode != 5)) {
        return 0;
    }

    const int game_mode = rge_base_game->game_mode;
    if ((game_mode == 1) || ((6 < game_mode) && (game_mode < 9))) {
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }
    return 1;
}

long RGE_Main_View::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053E340
    if (rge_base_game->get_paused() != 0) {
        return 0;
    }

    const int prog_mode = rge_base_game->prog_mode;
    if ((prog_mode != 4) && (prog_mode != 6) && (prog_mode != 7) && (prog_mode != 5)) {
        return 0;
    }

    const int game_mode = rge_base_game->game_mode;
    color_log('L', 0xBA, 1);

    switch (game_mode) {
    case 1: {
        RGE_Pick_Info pick_info;
        const uchar pick_res = this->pick1('(', '\0', param_1, param_2, &pick_info, nullptr, 1);
        if (pick_res == '3') {
            this->fixup_pick_info(&pick_info);
            const int master_obj_id = (int)rge_base_game->master_obj_id;
            if (master_obj_id != -1) {
                RGE_Master_Static_Object* master = this->player->master_objects[master_obj_id];
                if (master == nullptr && this->world != nullptr && this->world->players != nullptr) {
                    const short curr_player = this->world->curr_player;
                    if (curr_player >= 0) {
                        RGE_Player* world_player = this->world->players[curr_player];
                        if (world_player != nullptr && world_player->master_objects != nullptr) {
                            master = world_player->master_objects[master_obj_id];
                        }
                    }
                }
                if (master != nullptr) {
                    master->alignment(&pick_info.x, &pick_info.y, this->world, 0);
                    this->player->command_place_object((short)master_obj_id, pick_info.x, pick_info.y, 0.0f);
                }
            }
        }
        break;
    }

    case 2:
    case 3:
    case 0x11:
        if (this->player->selected_obj != nullptr) {
            this->player->unselect_object();
            this->set_redraw(TPanel::RedrawMode::Redraw);
        }
        // fallthrough
    case 0x15:
        this->start_scroll_view('\x03', param_1, param_2, param_3, param_4);
        break;

    case 9:
    case 10:
    case 0x13:
        if (this->player->selected_obj != nullptr) {
            this->player->unselect_object();
            this->set_redraw(TPanel::RedrawMode::Redraw);
        }
        if (game_mode == 0x13) {
            rge_base_game->set_game_mode(0x13, 0);
        }
        this->start_scroll_view('\t', param_1, param_2, param_3, param_4);
        break;

    case 0x0F: {
        RGE_Pick_Info pick_info;
        const uchar pick_res = this->pick1(')', '\0', param_1, param_2, &pick_info, this->player->selected_obj, 1);
        if ((pick_res == '4') && (pick_info.object->master_obj->id != 0x22)) {
            uchar draw_level = 0x14;
            if (pick_info.object->sprite_list != nullptr) {
                draw_level = pick_info.object->sprite_list->get_lowest_draw_level();
            } else if (pick_info.object->sprite != nullptr) {
                draw_level = pick_info.object->sprite->get_lowest_draw_level();
            }

            this->save_player = rge_base_game->get_player();
            rge_base_game->set_player(pick_info.object->owner->id);
            rge_base_game->master_obj_id = pick_info.object->master_obj->id;
            this->movable_object = pick_info.object;
            pick_info.object->object_state = 7;
            if (draw_level == '\0') {
                this->set_redraw(TPanel::RedrawMode::RedrawFull);
            }

            rge_base_game->set_game_mode(8, 1);
            if (this->movable_object->sprite != nullptr) {
                short max_y = 0;
                short max_x = 0;
                short min_y = 0;
                short min_x = 0;
                tagPOINT point = { 0, 0 };
                this->movable_object->get_frame(&max_y, &max_x, &min_y, &min_x);
                point.x = (int)pick_info.scr_x - (int)max_y;
                point.y = (int)pick_info.scr_y - (int)max_x;
                if (this->render_area != nullptr && this->render_area->DrawSystem != nullptr &&
                    this->render_area->DrawSystem->ScreenMode == 1) {
                    ClientToScreen((HWND)this->render_area->Wnd, &point);
                }
            }
            this->start_scroll_view('\t', param_1, param_2, param_3, param_4);
        }
        break;
    }

    case 0x12: {
        RGE_Pick_Info pick_info;
        const uchar pick_res = this->pick1(')', '\0', param_1, param_2, &pick_info, this->player->selected_obj, 1);
        if (pick_res == '4') {
            this->player->unselect_object();
            this->player->select_one_object(pick_info.object, 1);
            this->set_redraw(TPanel::RedrawMode::Redraw);
            if (pick_info.object != nullptr) {
                short max_y = 0;
                short max_x = 0;
                short min_y = 0;
                short min_x = 0;
                tagPOINT point = { 0, 0 };
                pick_info.object->get_frame(&max_y, &max_x, &min_y, &min_x);
                point.x = (int)pick_info.scr_x - (int)max_y;
                point.y = (int)pick_info.scr_y - (int)max_x;
                if (this->render_area != nullptr && this->render_area->DrawSystem != nullptr &&
                    this->render_area->DrawSystem->ScreenMode == 1) {
                    ClientToScreen((HWND)this->render_area->Wnd, &point);
                }
                if (this->render_area != nullptr && this->render_area->DrawSystem != nullptr &&
                    this->render_area->DrawSystem->ScreenMode == 1) {
                    ScreenToClient((HWND)this->render_area->Wnd, &point);
                }
                this->start_scroll_view('\x04', point.x, point.y, param_3, param_4);
            }
        }
        break;
    }

    default:
        this->capture_mouse();
        break;
    }

    color_log('L', '_', 1);
    return 1;
}

long RGE_Main_View::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053E7F0
    const int prog_mode = rge_base_game->prog_mode;
    if ((prog_mode != 4) && (prog_mode != 6) && (prog_mode != 7) && (prog_mode != 5)) {
        return 0;
    }

    if (rge_base_game->get_paused() != 0) {
        if (this->scroll_action != 0) {
            this->end_scroll_view();
            return 0;
        }
        this->release_mouse();
        return 0;
    }

    if (this->scroll_action != 0) {
        this->handle_scroll_view(param_1, param_2);
        return 1;
    }

    switch (rge_base_game->game_mode) {
    case 0:
        this->release_mouse();
        this->start_scroll_view('\x02', this->RGE_View::mouse_last_x, this->RGE_View::mouse_last_y, param_3, param_4);
        this->handle_scroll_view(param_3, param_4);
        return 1;
    case 1:
    case 7:
    case 8:
        this->set_redraw(TPanel::RedrawMode::Redraw);
        return 1;
    default:
        return 1;
    }
}

long RGE_Main_View::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053E910
    const int prog_mode = rge_base_game->prog_mode;
    if ((prog_mode != 4) && (prog_mode != 6) && (prog_mode != 7) && (prog_mode != 5)) {
        return 0;
    }

    color_log('L', '\x16', 1);

    if (this->scroll_action != 0) {
        this->end_scroll_view();
        if (rge_base_game->game_mode == 0x15) {
            const int place_single = ((param_3 == 0) && (param_4 == 0)) ? 1 : 0;
            this->command_place_multi_object(this->sel_col1, this->sel_row1, this->sel_col2, this->sel_row2, place_single);
        }
        if (rge_base_game->game_mode == 8) {
            this->command_place_object(param_1, param_2, 1);
            if (rge_base_game->sub_game_mode == 1) {
                if (this->movable_object != nullptr) {
                    this->movable_object->object_state = 2;
                }
                this->movable_object = nullptr;
                rge_base_game->set_game_mode(0x0F, 0);
                if (this->save_player != nullptr) {
                    rge_base_game->set_player(this->save_player->id);
                    this->save_player = nullptr;
                }
            }
        }
        color_log('L', '_', 1);
        return 1;
    }

    this->release_mouse();
    if (rge_base_game->get_paused() != 0) {
        color_log('L', '_', 1);
        return 0;
    }

    const int game_mode = rge_base_game->game_mode;
    if (((param_4 != 0) || (param_3 != 0)) && (game_mode != 7) && (game_mode != 0x15)) {
        RGE_Pick_Info pick_info;
        const uchar pick_res = this->pick1(')', '\x02', param_1, param_2, &pick_info, nullptr, 0);
        if (pick_res == '4') {
            if ((pick_info.object->selected & 1) == 0) {
                if ((this->player->selected_obj != nullptr) &&
                    ((this->player->selected_obj->owner != this->player) ||
                     (this->player->get_select_level() != pick_info.object->master_obj->select_level))) {
                    this->player->unselect_object();
                }

                if (param_3 == 0) {
                    this->player->select_object(pick_info.object);
                } else {
                    this->player->select_one_object(pick_info.object, 1);
                }
            } else {
                this->player->unselect_one_object(pick_info.object);
            }
            this->set_redraw(TPanel::RedrawMode::Redraw);
        }

        if ((param_3 != 0) || (rge_base_game->prog_info->interface_style == 2)) {
            color_log('L', '_', 1);
            return 1;
        }
    }

    switch (game_mode) {
    case 0:
    case 6: {
        if (game_mode == 6) {
            rge_base_game->set_game_mode(0, 0);
        }

        if (rge_base_game->prog_info->interface_style == 2) {
            RGE_Static_Object* last = nullptr;
            if ((param_1 == this->RGE_Main_View::mouse_last_x) && (param_2 == this->RGE_Main_View::mouse_last_y)) {
                last = this->player->selected_obj;
            }

            RGE_Pick_Info pick_info;
            const uchar pick_res = this->pick1(')', '\x02', param_1, param_2, &pick_info, last, 0);
            this->RGE_Main_View::mouse_last_x = -1;
            this->RGE_Main_View::mouse_last_y = -1;
            if (pick_res == '4') {
                if ((pick_info.object->selected & 1) == 0) {
                    this->player->unselect_object();
                    this->player->select_object(pick_info.object);
                } else {
                    if (this->player->sel_count < 2) {
                        break;
                    }
                    this->player->unselect_object();
                    this->player->select_one_object(pick_info.object, 1);
                }
                this->set_redraw(TPanel::RedrawMode::Redraw);
                this->RGE_Main_View::mouse_last_x = param_1;
                this->RGE_Main_View::mouse_last_y = param_2;
            } else {
                this->player->unselect_object();
                this->set_redraw(TPanel::RedrawMode::Redraw);
            }
            break;
        }

        RGE_Static_Object* last = nullptr;
        if ((param_1 == this->RGE_Main_View::mouse_last_x) && (param_2 == this->RGE_Main_View::mouse_last_y)) {
            last = this->player->selected_obj;
        }

        RGE_Pick_Info pick_info;
        const uchar pick_res = this->pick1('*', '\x01', param_1, param_2, &pick_info, last, 1);
        if ((pick_res == '4') &&
            (param_1 == this->RGE_Main_View::mouse_last_x) &&
            (param_2 == this->RGE_Main_View::mouse_last_y) &&
            (pick_info.object != this->player->selected_obj)) {
            this->player->unselect_object();
            this->set_redraw(TPanel::RedrawMode::Redraw);
        }

        this->RGE_Main_View::mouse_last_x = -1;
        this->RGE_Main_View::mouse_last_y = -1;

        if (pick_res == '4') {
            if ((rge_base_game->prog_mode != 5) && (this->player->sel_count > 0) &&
                (rge_base_game->prog_mode != 7) &&
                (this->command_make_do(param_1, param_2, 0, -1) != 0)) {
                color_log('L', '_', 1);
                return 1;
            }

            if ((pick_info.object->selected & 1) != 0) {
                if (this->player->sel_count < 2) {
                    color_log('L', '_', 1);
                    return 1;
                }

                this->player->unselect_object();
                this->player->select_one_object(pick_info.object, 1);
                this->set_redraw(TPanel::RedrawMode::Redraw);
                this->RGE_Main_View::mouse_last_x = param_1;
                this->RGE_Main_View::mouse_last_y = param_2;
                color_log('L', '_', 1);
                return 1;
            }

            if ((pick_info.object->owner == this->player) || (this->player->sel_count == 0)) {
                if (pick_info.object->master_obj->select_level > 1) {
                    if ((this->map->map_visible_flag == '\0') &&
                        (this->player->visible->get_visible((int)pick_info.object->world_x, (int)pick_info.object->world_y) != '\x0f')) {
                        break;
                    }
                    this->player->unselect_object();
                    this->player->select_object(pick_info.object);
                    this->set_redraw(TPanel::RedrawMode::Redraw);
                    this->RGE_Main_View::mouse_last_x = param_1;
                    this->RGE_Main_View::mouse_last_y = param_2;
                }
                break;
            }

            if ((rge_base_game->prog_mode != 5) && (rge_base_game->prog_mode != 7) &&
                (this->command_make_do(param_1, param_2, 1, -1) != 0)) {
                break;
            }

            if (pick_info.object->master_obj->select_level > 1) {
                if ((this->map->map_visible_flag == '\0') &&
                    (this->player->visible->get_visible((int)pick_info.object->world_x, (int)pick_info.object->world_y) != '\x0f')) {
                    // Fall through to terrain command handling.
                } else {
                    this->player->unselect_object();
                    this->player->select_object(pick_info.object);
                    this->set_redraw(TPanel::RedrawMode::Redraw);
                    this->RGE_Main_View::mouse_last_x = param_1;
                    this->RGE_Main_View::mouse_last_y = param_2;
                    break;
                }
            }
        }

        if ((pick_res == '3') && (rge_base_game->prog_mode != 5) && (rge_base_game->prog_mode != 7)) {
            if (param_4 == 0) {
                this->command_make_do(param_1, param_2, 1, -1);
                break;
            }

            RGE_Static_Object** list = nullptr;
            short list_num = 0;
            const uchar ok = this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1);
            if (ok != '\0') {
                std::free(list);
                if (allow_user_commands != 0) {
                    this->fixup_pick_info(&pick_info);
                    this->player->command_add_waypoint(pick_info.x, pick_info.y, 1.0f);
                    this->reset_display_object_selection(2);
                    this->add_overlay_sprite(rge_base_game->shapes[1], 0, this->map_scr_x_offset + (int)param_1, this->map_scr_y_offset + (int)param_2, 0, 0x0f, nullptr, 1, 0xFA);
                    this->set_redraw(TPanel::RedrawMode::Redraw);
                }
            }
        }
        break;
    }

    case 4:
        this->command_make_move(param_1, param_2);
        break;

    case 5:
        this->command_make_work(param_1, param_2);
        break;

    case 7:
        if ((param_3 == 0) && (param_4 == 0)) {
            this->command_place_object(param_1, param_2, 1);
        } else {
            this->command_place_object(param_1, param_2, 0);
        }
        break;

    case 8:
        this->command_place_object(param_1, param_2, 1);
        if (rge_base_game->sub_game_mode == 1) {
            if (this->movable_object != nullptr) {
                this->movable_object->object_state = 2;
            }
            this->movable_object = nullptr;
            rge_base_game->set_game_mode(0x0F, 0);
            if (this->save_player != nullptr) {
                rge_base_game->set_player(this->save_player->id);
                this->save_player = nullptr;
            }
        }
        break;

    case 0x0E: {
        RGE_Pick_Info pick_info;
        const uchar pick_res = this->pick1(')', '\0', param_1, param_2, &pick_info, this->player->selected_obj, 1);
        if (pick_res == '4') {
            uchar draw_level = 0x14;
            if (pick_info.object->sprite_list != nullptr) {
                draw_level = pick_info.object->sprite_list->get_lowest_draw_level();
            } else if (pick_info.object->sprite != nullptr) {
                draw_level = pick_info.object->sprite->get_lowest_draw_level();
            }

            if (rge_base_game->prog_mode == 7) {
                if (pick_info.object != nullptr) {
                    delete pick_info.object;
                }
            } else {
                pick_info.object->destroy_obj();
            }

            if (draw_level == '\0') {
                this->set_redraw(TPanel::RedrawMode::RedrawFull);
            }
        }
        break;
    }

    case 0x10: {
        RGE_Pick_Info pick_info;
        const uchar pick_res = this->pick1(')', '\x01', param_1, param_2, &pick_info, this->player->selected_obj, 1);
        if (pick_res == '4') {
            if (this->parent_panel != nullptr) {
                this->parent_panel->action(this, 0x10, (ulong)pick_info.object, 0);
                this->player->select_one_object(pick_info.object, 1);
                this->set_redraw(TPanel::RedrawMode::Redraw);
            }
            rge_base_game->set_game_mode(0, 0);
        }
        break;
    }

    case 0x14: {
        RGE_Pick_Info pick_info;
        const uchar pick_res = this->pick1(')', '\x02', param_1, param_2, &pick_info, this->player->selected_obj, 1);
        if (pick_res == '4') {
            pick_info.object->rotate(1);
        }
        break;
    }

    default:
        break;
    }

    color_log('L', '_', 1);
    return 1;
}

long RGE_Main_View::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053F220
    if (rge_base_game->get_paused() != 0) {
        return 0;
    }

    const int prog_mode = rge_base_game->prog_mode;
    if ((prog_mode != 4) && (prog_mode != 6) && (prog_mode != 7) && (prog_mode != 5)) {
        return 0;
    }

    color_log('L', '$', 1);
    if (rge_base_game->game_mode == 0x13) {
        if (this->player->selected_obj != nullptr) {
            this->player->unselect_object();
            this->set_redraw(TPanel::RedrawMode::Redraw);
        }
        rge_base_game->set_game_mode(0x13, 1);
        this->start_scroll_view('\t', param_1, param_2, param_3, param_4);
    } else {
        this->capture_mouse();
    }
    color_log('L', '_', 1);
    return 1;
}

long RGE_Main_View::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053F2F0
    const int prog_mode = rge_base_game->prog_mode;
    if ((prog_mode != 4) && (prog_mode != 6) && (prog_mode != 7) && (prog_mode != 5)) {
        return 0;
    }

    if (rge_base_game->get_paused() != 0) {
        if (this->scroll_action != 0) {
            this->end_scroll_view();
            return 0;
        }
        this->release_mouse();
        return 0;
    }

    if (this->scroll_action != 0) {
        this->handle_scroll_view(param_1, param_2);
        return 1;
    }

    if (this->player->sel_count == 0) {
        this->release_mouse();
        this->start_scroll_view('\x01', this->RGE_View::mouse_last_x, this->RGE_View::mouse_last_y, param_3, param_4);
        this->handle_scroll_view(param_3, param_4);
        return 1;
    }

    return 0;
}

long RGE_Main_View::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053F3D0
    (void)param_3;

    const int prog_mode = rge_base_game->prog_mode;
    if ((prog_mode != 4) && (prog_mode != 6) && (prog_mode != 7) && (prog_mode != 5)) {
        return 0;
    }

    color_log('L', '2', 1);

    if (this->scroll_action == 0) {
        this->release_mouse();

        if (rge_base_game->game_mode == 0x14) {
            RGE_Pick_Info pick_info;
            const uchar res = this->pick1(')', '\x02', param_1, param_2, &pick_info, this->player->selected_obj, 1);
            if (res == '4') {
                pick_info.object->rotate(-1);
            }
            return 1;
        }

        if ((rge_base_game->get_paused() != 0) || ((this->mouse_action != 1) && (this->mouse_action != 2))) {
            color_log('L', '_', 1);
            return 0;
        }

        if (rge_base_game->prog_info != nullptr && rge_base_game->prog_info->interface_style == 2) {
            if (prog_mode == 5 || prog_mode == 7) {
                goto done;
            }

            if (rge_base_game->game_mode != 0) {
                if (rge_base_game->game_mode == 0x15) {
                    this->set_selection_area(-1, -1, -1, -1);
                    this->set_redraw(TPanel::RedrawMode::Redraw);
                }
                rge_base_game->set_game_mode(0, 0);
                goto done;
            }

            if (param_4 == 0) {
                this->command_make_do(param_1, param_2, 1, -1);
                goto done;
            }

            RGE_Static_Object** list = nullptr;
            short list_num = 0;
            const uchar ok = this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1);
            if (ok != '\0') {
                std::free(list);
                if (allow_user_commands != 0) {
                    RGE_Pick_Info pick_info;
                    const uchar pick_res = this->pick1('(', '\0', param_1, param_2, &pick_info, nullptr, 1);
                    if (pick_res == '3') {
                        this->fixup_pick_info(&pick_info);
                        this->player->command_add_waypoint(pick_info.x, pick_info.y, 1.0f);
                        this->reset_display_object_selection(2);
                        this->add_overlay_sprite(rge_base_game->shapes[1], 0, this->map_scr_x_offset + (int)param_1, this->map_scr_y_offset + (int)param_2, 0, 0x0f, nullptr, 1, 0xFA);
                    }
                }
                this->set_redraw(TPanel::RedrawMode::Redraw);
            }
        } else {
            if (prog_mode == 7) {
                goto done;
            }
            if (rge_base_game->game_mode != 0) {
                rge_base_game->set_game_mode(0, 0);
                goto done;
            }
            this->player->unselect_object();
        }

        this->set_redraw(TPanel::RedrawMode::Redraw);
    } else {
        this->end_scroll_view();
    }

done:
    color_log('L', '_', 1);
    return 1;
}

int RGE_Main_View::start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: vw_main.cpp.decomp @ 0x0053F660
    int ok = RGE_View::start_scroll_view(param_1, param_2, param_3, param_4, param_5);
    if (ok != 0) {
        if (this->map_view != nullptr) {
            this->map_view->set_redraw(TPanel::RedrawMode::Redraw);
        }
        return 1;
    }
    return 0;
}

int RGE_Main_View::handle_scroll_view(long param_1, long param_2) {
    // Fully verified. Source of truth: vw_main.cpp.decomp @ 0x0053F6B0
    int ok = RGE_View::handle_scroll_view(param_1, param_2);
    if (ok != 0) {
        if (this->map_view != nullptr) {
            this->map_view->set_redraw(TPanel::RedrawMode::Redraw);
        }
        return 1;
    }
    return 0;
}

void RGE_Main_View::draw() {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053F6F0
    const ulong start = debug_timeGetTime(kVwMainPath, 0x522);
    const ulong accum0 = rge_base_game->get_accum_time(0xB);

    if ((this->world == nullptr) || (this->player == nullptr)) {
        this->draw_setup(0);
        if (this->render_area != nullptr) {
            this->render_area->Clear(&this->clip_rect, (int)this->color);
        }
        this->draw_finish();
    } else {
        if (do_draw_log != 0) {
            write_draw_log2((char*)"<vs>");
        }
        color_log('L', 'L', 1);
        RGE_View::draw();
        color_log('L', '_', 1);
        if (do_draw_log != 0) {
            write_draw_log2((char*)"<vf>\n");
        }
    }

    const ulong accum1 = rge_base_game->get_accum_time(0xB);
    const ulong end = debug_timeGetTime(kVwMainPath, 0x542);

    rge_base_game->add_to_timing(6, (end - start) - (accum1 - accum0));
    rge_base_game->increment_view_update_count();
    rge_base_game->add_to_timing(0xC, accum1 - accum0);
}

void RGE_Main_View::draw_multi_object_outline() {
    // Fully verified. Source of truth: vw_main.cpp.decomp @ 0x0053F800
    return;
}

int RGE_Main_View::command_place_object(long param_1, long param_2, int param_3) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053F810
    if (allow_user_commands == 0) {
        return 0;
    }

    RGE_Pick_Info pick_info;
    const uchar pick_res = this->pick1('(', '\0', param_1, param_2, &pick_info, nullptr, 1);
    if (pick_res != '3') {
        return 0;
    }

    this->fixup_pick_info(&pick_info);

    const int master_obj_id = (int)rge_base_game->master_obj_id;
    if (master_obj_id == -1) {
        return 0;
    }

    RGE_Player* cur_player = rge_base_game->get_player();
    RGE_Master_Static_Object* master = cur_player->master_objects[master_obj_id];
    if (master == nullptr) {
        return 0;
    }

    // Align placement to map/world rules.
    master->alignment(&pick_info.x, &pick_info.y, this->world, (uchar)(rge_base_game->sub_game_mode != 3));

    const uchar elev_flag = master->elevation_flag;
    const uchar bad = master->check_placement(cur_player, pick_info.x, pick_info.y, nullptr, 1, elev_flag, 0, 1, 1, 1);
    if (bad != '\0') {
        return 0;
    }

    if (rge_base_game->game_mode == 1) {
        const uchar ok = cur_player->command_place_object((short)master_obj_id, pick_info.x, pick_info.y, 0.0f);
        if (ok != '\0') {
            if (param_3 != 0) {
                rge_base_game->set_game_mode(0, 0);
            }
            return 1;
        }
        return 0;
    }

    if (rge_base_game->game_mode == 8) {
        RGE_Static_Object* obj = nullptr;
        if (rge_base_game->sub_game_mode == 1) {
            obj = this->movable_object;
            obj->teleport(pick_info.x, pick_info.y, 0.0f);
        } else {
            obj = cur_player->make_new_object(master_obj_id, pick_info.x, pick_info.y, 0.0f, 1);
        }

        if (obj != nullptr) {
            uchar dl = 0x14;
            if (obj->sprite_list != nullptr) {
                dl = obj->sprite_list->get_lowest_draw_level();
            } else if (obj->sprite != nullptr) {
                dl = obj->sprite->get_lowest_draw_level();
            }

            if (dl != '\0') {
                this->set_redraw(TPanel::RedrawMode::Redraw);
                return 1;
            }

            this->set_redraw(TPanel::RedrawMode::RedrawFull);
            return 1;
        }
    }

    return 0;
}

int RGE_Main_View::command_make_do(long param_1, long param_2, int param_3, short param_4) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053FA10
    if (allow_user_commands == 0) {
        return 0;
    }

    RGE_Static_Object** list = nullptr;
    short list_num = 0;
    const uchar ok = this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1);
    if (ok == '\0') {
        return 0;
    }
    std::free(list);

    color_log('L', 0xBA, 2);

    int attacking = 0;
    RGE_Static_Object* target = this->pick_best_target(param_1, param_2, &attacking, param_4);
    if (target != nullptr) {
        const uint res = (uint)this->player->command_make_do(target, target->world_x, target->world_y);
        if ((res & 0xFFu) != 0) {
            this->display_object_selection((int)target->id, 0x5DC, 2, 2);
        }
        this->reset_overlay_sprites();
        this->set_redraw(TPanel::RedrawMode::Redraw);
        color_log('L', '_', 2);
        return (int)(res & 0xFFu);
    }

    if (param_3 != 0) {
        RGE_Pick_Info pick_info;
        const uchar pick_res = this->pick1('(', '\0', param_1, param_2, &pick_info, nullptr, 1);
        if (pick_res == '3') {
            this->fixup_pick_info(&pick_info);
            const uint res = (uint)this->player->command_make_move(nullptr, pick_info.x, pick_info.y);
            if ((res & 0xFFu) != 0) {
                this->reset_display_object_selection(2);
                this->add_overlay_sprite(rge_base_game->shapes[2], 0, this->map_scr_x_offset + (int)param_1, this->map_scr_y_offset + (int)param_2, 0, 0x0f, nullptr, 2, 0x5A);
                this->set_redraw(TPanel::RedrawMode::Redraw);
            }
            color_log('L', '_', 2);
            return (int)(res & 0xFFu);
        }
    }

    this->reset_overlay_sprites();
    this->set_redraw(TPanel::RedrawMode::Redraw);
    color_log('L', '_', 2);
    return 0;
}

int RGE_Main_View::command_make_move(long param_1, long param_2) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x00540350
    if (allow_user_commands == 0) {
        return 0;
    }

    RGE_Static_Object** list = nullptr;
    short list_num = 0;
    const uchar ok = this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1);
    if (ok == '\0') {
        return 0;
    }
    std::free(list);

    uint res = 0;
    RGE_Pick_Info pick_info;
    const uchar pick_res = this->pick1('*', '\x01', param_1, param_2, &pick_info, nullptr, 1);
    if (pick_res != '2') {
        this->fixup_pick_info(&pick_info);
        res = (uint)this->player->command_make_move(pick_info.object, pick_info.x, pick_info.y);
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }

    rge_base_game->set_game_mode(0, 0);
    return (int)(res & 0xFFu);
}

int RGE_Main_View::command_make_work(long param_1, long param_2) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x00540420
    if (allow_user_commands == 0) {
        return 0;
    }

    RGE_Static_Object** list = nullptr;
    short list_num = 0;
    const uchar ok = this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1);
    if (ok == '\0') {
        return 0;
    }
    std::free(list);

    int attacking = 0;
    RGE_Static_Object* target = this->pick_best_target(param_1, param_2, &attacking, -1);
    if (target != nullptr) {
        const uint res = (uint)this->player->command_make_work(target, target->world_x, target->world_y);
        if ((res & 0xFFu) != 0) {
            this->display_object_selection((int)target->id, 0x5DC, 2, 2);
        }
        this->reset_overlay_sprites();
        this->set_redraw(TPanel::RedrawMode::Redraw);
        rge_base_game->set_game_mode(0, 0);
        return (int)(res & 0xFFu);
    }

    RGE_Pick_Info pick_info;
    const uchar pick_res = this->pick1('(', '\0', param_1, param_2, &pick_info, nullptr, 1);
    if (pick_res == '3') {
        this->fixup_pick_info(&pick_info);
        const uint res = (uint)this->player->command_make_work(nullptr, pick_info.x, pick_info.y);
        if ((res & 0xFFu) != 0) {
            this->reset_display_object_selection(2);
            this->add_overlay_sprite(rge_base_game->shapes[2], 0, this->map_scr_x_offset + (int)param_1, this->map_scr_y_offset + (int)param_2, 0, 0x0f, nullptr, 2, 0x5A);
        }
        this->set_redraw(TPanel::RedrawMode::Redraw);
        rge_base_game->set_game_mode(0, 0);
        return (int)(res & 0xFFu);
    }

    this->reset_overlay_sprites();
    this->set_redraw(TPanel::RedrawMode::Redraw);
    rge_base_game->set_game_mode(0, 0);
    return 0;
}

int RGE_Main_View::command_place_multi_object(long param_1, long param_2, long param_3, long param_4, int param_5) {
    // Fully verified. Source of truth: vw_main.cpp.decomp @ 0x005405C0
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;

    this->set_selection_area(-1, -1, -1, -1);
    this->set_redraw(TPanel::RedrawMode::Redraw);
    return 0;
}

uchar RGE_Main_View::get_help_info(char** param_1, long* param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: vw_main.cpp.decomp @ 0x005405E0
    RGE_Pick_Info pick_info;
    const uchar res = this->pick1(')', '\x02', param_3, param_4, &pick_info, nullptr, 1);
    if (res != '4' || pick_info.object == nullptr || pick_info.object->master_obj == nullptr) {
        return TPanel::get_help_info(param_1, param_2, param_3, param_4);
    }

    const long msg_id = pick_info.object->master_obj->get_help_message();
    const char* msg = this->get_string((int)msg_id);
    if (param_1 != nullptr && *param_1 != nullptr) {
        if (msg == nullptr) {
            (*param_1)[0] = '\0';
        } else {
            std::memcpy(*param_1, msg, std::strlen(msg) + 1);
        }
    }

    if (param_2 != nullptr) {
        *param_2 = pick_info.object->master_obj->get_help_page();
    }

    return '\x01';
}

void RGE_Main_View::fixup_pick_info(RGE_Pick_Info* param_1) {
    // Fully verified. Source of truth: vw_main.cpp.decomp @ 0x00540680
    if (this->map == nullptr || param_1 == nullptr) {
        return;
    }

    if (param_1->x < 0.0f) {
        param_1->x = 0.0f;
    } else {
        const float max_x = (float)this->map->map_width;
        if (param_1->x >= max_x) {
            param_1->x = max_x - 1.0f;
        }
    }

    if (param_1->y < 0.0f) {
        param_1->y = 0.0f;
    } else {
        const float max_y = (float)this->map->map_height;
        if (param_1->y >= max_y) {
            param_1->y = max_y - 1.0f;
        }
    }
}

void RGE_Main_View::reset_display_object_selection(int param_1) {
    // Fully verified. Source of truth: vw_main.cpp.decomp @ 0x00540700
    if (this->DispSel_List == nullptr) {
        return;
    }

    for (int i = 0; i < this->DispSel_List_Max; ++i) {
        DisplaySelectedObjRec* rec = &this->DispSel_List[i];
        if (rec->active == 1 && rec->select_type == param_1) {
            rec->start_time -= rec->duration;
        }
    }
}

uchar RGE_Main_View::pick1(uchar param_1, uchar param_2, long param_3, long param_4, RGE_Pick_Info* param_5, RGE_Static_Object* param_6, int param_7) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x0053FBD0
    if (param_1 != ')') {
        if (param_1 == '*') {
            const uchar res = this->pick1(')', param_2, param_3, param_4, param_5, param_6, 1);
            if (res == '4') {
                return '4';
            }
        }
        return RGE_View::pick('(', param_2, param_3, param_4, param_5, param_6);
    }

    param_5->x = 0.0f;
    param_5->y = 0.0f;
    param_5->scr_x = 0;
    param_5->scr_y = 0;
    param_5->object = nullptr;
    param_5->tile = nullptr;

    int max_level = 0x28;
    int start_level = 0;
    if (param_2 != '\0') {
        max_level = 0x14;
        start_level = 10;
    }

    const int num = this->pick_objects((int)param_3, (int)param_4, start_level, max_level, 0x0f, 4, 1);
    if (num == 0) {
        return '2';
    }

    RGE_Static_Object* picked = nullptr;
    short picked_scr_x = 0;
    short picked_scr_y = 0;

    if (param_6 == nullptr) {
        int best_weight = 0;

        for (int i = 0; i < num; ++i) {
            const int obj_id = Picked_Objects[i].object_id;
            if (obj_id < 0) {
                continue;
            }
            RGE_Static_Object* obj = this->world->objectsValue[obj_id];
            if (obj == nullptr || obj->object_state >= 7) {
                continue;
            }
            if ((uchar)param_2 > (uchar)obj->master_obj->select_level) {
                continue;
            }

            if ((param_7 == 0) && (this->map->map_visible_flag == '\0') && (this->pick_through_fog(obj) == 0)) {
                const int row = (int)obj->world_y;
                const int col = (int)obj->world_x;
                if (this->player->visible->get_visible(col, row) != '\x0f') {
                    continue;
                }
            }

            const int w = this->pick_weight(obj, (int)Picked_Objects[i].confidence);
            if (best_weight < w) {
                best_weight = w;
                picked = obj;
                picked_scr_x = (short)(this->pnl_x + Picked_Objects[i].draw_x);
                picked_scr_y = (short)(this->pnl_y + Picked_Objects[i].draw_y);
            }
        }
    } else {
        bool found_last = false;
        int found_index = 0;

        for (int i = 0; i < num; ++i) {
            const int obj_id = Picked_Objects[i].object_id;
            if (obj_id < 0) {
                continue;
            }
            RGE_Static_Object* obj = this->world->objectsValue[obj_id];
            if (obj == nullptr || obj->object_state >= 7) {
                continue;
            }
            if ((uchar)param_2 > (uchar)obj->master_obj->select_level) {
                continue;
            }
            if (this->pick_weight(obj, (int)Picked_Objects[i].confidence) <= 0) {
                continue;
            }

            if ((param_7 == 0) && (this->map->map_visible_flag == '\0') && (this->pick_through_fog(obj) == 0)) {
                const int row = (int)obj->world_y;
                const int col = (int)obj->world_x;
                if (this->player->visible->get_visible(col, row) != '\x0f') {
                    continue;
                }
            }

            if (obj == param_6) {
                found_last = true;
                found_index = i;
                continue;
            }

            if (found_last) {
                picked = obj;
                picked_scr_x = (short)(this->pnl_x + Picked_Objects[i].draw_x);
                picked_scr_y = (short)(this->pnl_y + Picked_Objects[i].draw_y);
                break;
            }

            if (picked == nullptr) {
                picked = obj;
                picked_scr_x = (short)(this->pnl_x + Picked_Objects[i].draw_x);
                picked_scr_y = (short)(this->pnl_y + Picked_Objects[i].draw_y);
            }
        }

        if (found_last && picked == nullptr) {
            picked = param_6;
            picked_scr_x = (short)(this->pnl_x + Picked_Objects[found_index].draw_x);
            picked_scr_y = (short)(this->pnl_y + Picked_Objects[found_index].draw_y);
        }
    }

    if (picked != nullptr) {
        param_5->object = picked;
        param_5->scr_x = picked_scr_x;
        param_5->scr_y = picked_scr_y;
        param_5->x = picked->world_x;
        param_5->y = picked->world_y;
        return '4';
    }

    return '2';
}

int RGE_Main_View::pick_objects1(long param_1, long param_2, RGE_Static_Object** param_3, int param_4) {
    // Fully verified. Source of truth: vw_main.cpp.decomp @ 0x0053FFB0
    int count = 0;
    RGE_Static_Object* last = nullptr;
    RGE_Static_Object** out = param_3;

    while (count != param_4) {
        RGE_Pick_Info pick_info;
        const uchar res = RGE_View::pick(')', '\0', param_1, param_2, &pick_info, last);
        if (res != '4' || pick_info.object == nullptr) {
            break;
        }
        if (count > 0 && pick_info.object == param_3[0]) {
            return count;
        }
        *out++ = pick_info.object;
        ++count;
        last = pick_info.object;
    }

    return count;
}

RGE_Static_Object* RGE_Main_View::pick_best_target(long param_1, long param_2, int* param_3, short param_4) {
    // Fully verified. Source of truth: vw_main.cpp.asm @ 0x00540010
    if (param_3 != nullptr) {
        *param_3 = 0;
    }

    const int target_count = this->pick_objects((int)param_1, (int)param_2, 10, 0x14, 0x0f, 4, 1);
    if (target_count == 0) {
        return nullptr;
    }

    RGE_Static_Object** selected_objects = nullptr;
    short selected_count = 0;
    const uchar selected_ok = this->player->get_selected_objects_to_command(&selected_objects, &selected_count, -1, -1, -1, -1);
    if (selected_ok == '\0') {
        return nullptr;
    }

    int valid_target_count[64];
    int attacking[64];
    for (int i = 0; i < target_count; ++i) {
        valid_target_count[i] = 0;
        attacking[i] = 0;
    }

    for (int j = 0; j < selected_count; ++j) {
        RGE_Static_Object* selected_obj = selected_objects[j];
        RGE_Master_Action_Object* master_obj = (RGE_Master_Action_Object*)selected_obj->master_obj;

        for (int target_index = 0; target_index < target_count; ++target_index) {
            const int obj_id = Picked_Objects[target_index].object_id;
            if (obj_id < 0) {
                continue;
            }

            RGE_Static_Object* target_obj = this->world->objectsValue[obj_id];
            if (target_obj == nullptr || target_obj->object_state >= 7) {
                continue;
            }

            RGE_Task* target_task = nullptr;
            if (master_obj->tasks != nullptr) {
                target_task = master_obj->tasks->get_target_task((RGE_Action_Object*)selected_obj, target_obj, 0.0f, 0.0f, 0.0f);
            }

            if (target_task != nullptr) {
                if ((param_4 != -1) && (target_task->id != param_4)) {
                    target_task = nullptr;
                }
                if (target_task != nullptr) {
                    valid_target_count[target_index] += this->pick_weight(target_obj, (int)Picked_Objects[target_index].confidence);
                    if (master_obj->tasks->is_attack_task(target_task) != 0) {
                        attacking[target_index] = 1;
                    }
                    continue;
                }
            }

            if (master_obj->task_by_group == '\0') {
                continue;
            }

            RGE_Player* owner_player = selected_obj->owner;
            if (owner_player == nullptr || owner_player->master_objects == nullptr) {
                continue;
            }

            for (short i = 0; i < owner_player->master_object_num; ++i) {
                RGE_Master_Action_Object* group_master = (RGE_Master_Action_Object*)owner_player->master_objects[i];
                if (group_master == nullptr) {
                    continue;
                }
                if ((group_master->id != master_obj->id) ||
                    (group_master->master_type != master_obj->master_type) ||
                    (group_master->task_by_group != master_obj->task_by_group)) {
                    continue;
                }
                if (group_master->tasks == nullptr) {
                    continue;
                }

                RGE_Task* group_task = group_master->tasks->get_target_task((RGE_Action_Object*)selected_obj, target_obj, 0.0f, 0.0f, 0.0f);
                if (group_task == nullptr) {
                    continue;
                }
                if ((param_4 != -1) && (group_task->id != param_4)) {
                    continue;
                }

                valid_target_count[target_index] += this->pick_weight(target_obj, (int)Picked_Objects[target_index].confidence);
                if (group_master->tasks->is_attack_task(group_task) != 0) {
                    attacking[target_index] = 1;
                }
                break;
            }
        }
    }

    std::free(selected_objects);

    int best_weight = 0;
    RGE_Static_Object* best_target = nullptr;
    for (int i = 0; i < target_count; ++i) {
        if (best_weight < valid_target_count[i]) {
            best_weight = valid_target_count[i];
            best_target = this->world->objectsValue[Picked_Objects[i].object_id];
            if (param_3 != nullptr) {
                *param_3 = attacking[i];
            }
        }
    }

    return best_target;
}

