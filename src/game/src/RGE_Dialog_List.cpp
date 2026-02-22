#include "../include/RGE_Dialog_List.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/TScreenPanel.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>
#include <windows.h>

static char s_none_text[] = "<None>";

static int __cdecl rdlg_list_compare(const void* a, const void* b) {
    // Fully verified. Source of truth: rdlg_lst.cpp.decomp @ 0x0047EAA0
    const char* pa = (const char*)a;
    const char* pb = (const char*)b;
    const int ret = CompareStringA(0x400, 1, pa, -1, pb, -1);
    if (ret == 1) {
        return -1;
    }
    return (ret == 3) ? 1 : 0;
}

static void sort_list(RGE_Dialog_List* self) {
    // Fully verified. Source of truth: rdlg_lst.cpp.decomp @ 0x0047EAD0
    qsort(self->list_info, (size_t)self->list_size, sizeof(rdlg_list_info), rdlg_list_compare);
}

static void calc_list_line(RGE_Dialog_List* self) {
    // Fully verified. Source of truth: rdlg_lst.cpp.decomp @ 0x0047EAF0
    self->list_line = -1;
    const short cur_id = self->get_cur_id();
    if (cur_id != -1) {
        short i = 0;
        if (0 < self->list_size) {
            do {
                if (self->list_info[i].id == cur_id) {
                    self->list_line = i;
                    break;
                }
                i = (short)(i + 1);
            } while (i < self->list_size);
        }
    }
    if (self->list_line == -1) {
        self->list_line = 0;
    }
}

RGE_Dialog_List::RGE_Dialog_List(char* name) : TListDialog(name) {
    // Fully verified. Source of truth: rdlg_lst.cpp.decomp @ 0x0047E670
}

int RGE_Dialog_List::setup(TScreenPanel* screen, char* popup_file, long popup_id, int list_type, char* title) {
    // Fully verified. Source of truth: rdlg_lst.cpp.decomp @ 0x0047E6B0
    this->list_type = list_type;
    this->list_info = nullptr;
    this->list_text = nullptr;
    if (screen == nullptr) {
        return 0;
    }

    if (this->create_list() == 0) {
        return 0;
    }
    sort_list(this);
    calc_list_line(this);

    this->list_text = (char**)calloc((size_t)this->list_size, 4);
    if (this->list_text == nullptr) {
        return 0;
    }

    for (int i = 0; i < this->list_size; ++i) {
        const char* src = this->list_info[i].text;
        const size_t len = strlen(src) + 1;
        this->list_text[i] = (char*)calloc(len, 1);
        if (this->list_text[i] == nullptr) {
            return 0;
        }
        memcpy(this->list_text[i], src, len);
    }

    const long ok = TListDialog::setup((TPanel*)screen, popup_file, popup_id,
        0x136, 400,
        10, 10, 0x122, 0x19, title,
        10, 0x2d, 0x122, 0x131,
        this->list_text, this->list_size, this->list_line,
        10, 0xa0, 0x168, 0x8c, 0x1e);
    return (ok != 0) ? 1 : 0;
}

RGE_Dialog_List::~RGE_Dialog_List() {
    // Fully verified. Source of truth: rdlg_lst.cpp.decomp @ 0x0047E830
    if (this->list_text != nullptr) {
        for (int i = 0; i < this->list_size; ++i) {
            if (this->list_text[i] != nullptr) {
                free(this->list_text[i]);
            }
        }
        free(this->list_text);
        this->list_text = nullptr;
    }
    if (this->list_info != nullptr) {
        free(this->list_info);
        this->list_info = nullptr;
    }
}

short RGE_Dialog_List::get_list_id() {
    // Fully verified. Source of truth: rdlg_lst.cpp.decomp @ 0x0047E8C0
    const short line = TListDialog::get_list_id();
    if (line == -1) {
        return -1;
    }
    return this->list_info[line].id;
}

char* RGE_Dialog_List::get_list_name() {
    return TListDialog::get_list_name();
}

int RGE_Dialog_List::create_list() {
    // Fully verified. Source of truth: rdlg_lst.cpp.decomp @ 0x0047E8F0
    if (this->list_type != 1) {
        return 0;
    }

    // create_object_list (rdlg_lst.cpp.decomp @ 0x0047E910)
    RGE_Player* player = rge_base_game->get_player();
    if (player == nullptr) {
        return 0;
    }

    this->list_size = 1;
    const short count = player->master_object_num;
    if (0 < count) {
        for (int i = 0; i < count; ++i) {
            RGE_Master_Static_Object* obj = player->master_objects[i];
            if ((obj != nullptr) && (obj->hide_in_scenario_editor == 0)) {
                this->list_size = (short)(this->list_size + 1);
            }
        }
    }

    if (this->list_size == 0) {
        return 0;
    }

    this->list_info = (rdlg_list_info*)calloc((size_t)this->list_size, sizeof(rdlg_list_info));
    if (this->list_info == nullptr) {
        return 0;
    }

    this->list_info[0].id = -1;
    strcpy_s(this->list_info[0].text, sizeof(this->list_info[0].text), s_none_text);

    short out_i = 1;
    for (short j = 0; j < count; ++j) {
        RGE_Master_Static_Object* obj = player->master_objects[j];
        if ((obj != nullptr) && (obj->hide_in_scenario_editor == 0)) {
            this->list_info[out_i].id = j;
            const short str_id = obj->string_id;
            if (str_id < 1) {
                if (obj->name != nullptr) {
                    strcpy_s(this->list_info[out_i].text, sizeof(this->list_info[out_i].text), obj->name);
                } else {
                    this->list_info[out_i].text[0] = '\0';
                }
            } else {
                // Writes into list_info[out_i].text (struct begins with text buffer).
                rge_base_game->get_string(2, (long)str_id, (char*)(this->list_info + out_i), 100);
            }
            out_i = (short)(out_i + 1);
        }
    }
    return 1;
}

short RGE_Dialog_List::get_cur_id() {
    // Fully verified. Source of truth: rdlg_lst.cpp.decomp @ 0x0047EB60
    if (this->list_type != 1) {
        return -1;
    }
    return rge_base_game->master_obj_id;
}

// ---- Virtual forwarders ----
long RGE_Dialog_List::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TListDialog::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void RGE_Dialog_List::set_rect(tagRECT param_1) { TListDialog::set_rect(param_1); }
void RGE_Dialog_List::set_rect(long param_1, long param_2, long param_3, long param_4) { TListDialog::set_rect(param_1, param_2, param_3, param_4); }
void RGE_Dialog_List::set_color(uchar param_1) { TListDialog::set_color(param_1); }
void RGE_Dialog_List::set_active(int param_1) { TListDialog::set_active(param_1); }
void RGE_Dialog_List::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TListDialog::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void RGE_Dialog_List::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TListDialog::set_fixed_position(param_1, param_2, param_3, param_4); }
void RGE_Dialog_List::set_redraw(RedrawMode param_1) { TListDialog::set_redraw(param_1); }
void RGE_Dialog_List::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TListDialog::set_overlapped_redraw(param_1, param_2, param_3); }
void RGE_Dialog_List::draw_setup(int param_1) { TListDialog::draw_setup(param_1); }
void RGE_Dialog_List::draw_finish() { TListDialog::draw_finish(); }
void RGE_Dialog_List::draw() { TListDialog::draw(); }
void RGE_Dialog_List::draw_rect(tagRECT* param_1) { TListDialog::draw_rect(param_1); }
void RGE_Dialog_List::draw_offset(long param_1, long param_2, tagRECT* param_3) { TListDialog::draw_offset(param_1, param_2, param_3); }
void RGE_Dialog_List::draw_rect2(tagRECT* param_1) { TListDialog::draw_rect2(param_1); }
void RGE_Dialog_List::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TListDialog::draw_offset2(param_1, param_2, param_3); }
void RGE_Dialog_List::paint() { TListDialog::paint(); }
long RGE_Dialog_List::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TListDialog::wnd_proc(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::handle_idle() { return TListDialog::handle_idle(); }
long RGE_Dialog_List::handle_size(long param_1, long param_2) { return TListDialog::handle_size(param_1, param_2); }
long RGE_Dialog_List::handle_paint() { return TListDialog::handle_paint(); }
long RGE_Dialog_List::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TListDialog::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Dialog_List::handle_char(long param_1, short param_2) { return TListDialog::handle_char(param_1, param_2); }
long RGE_Dialog_List::handle_command(uint param_1, long param_2) { return TListDialog::handle_command(param_1, param_2); }
long RGE_Dialog_List::handle_user_command(uint param_1, long param_2) { return TListDialog::handle_user_command(param_1, param_2); }
long RGE_Dialog_List::handle_timer_command(uint param_1, long param_2) { return TListDialog::handle_timer_command(param_1, param_2); }
long RGE_Dialog_List::handle_scroll(long param_1, long param_2) { return TListDialog::handle_scroll(param_1, param_2); }
long RGE_Dialog_List::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TListDialog::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Dialog_List::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TListDialog::handle_mouse_move(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TListDialog::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long RGE_Dialog_List::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TListDialog::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long RGE_Dialog_List::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_move_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TListDialog::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Dialog_List::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TListDialog::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long RGE_Dialog_List::char_action(long param_1, short param_2) { return TListDialog::char_action(param_1, param_2); }
long RGE_Dialog_List::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TListDialog::action(param_1, param_2, param_3, param_4); }
void RGE_Dialog_List::get_true_render_rect(tagRECT* param_1) { TListDialog::get_true_render_rect(param_1); }
int RGE_Dialog_List::is_inside(long param_1, long param_2) { return TListDialog::is_inside(param_1, param_2); }
void RGE_Dialog_List::set_focus(int param_1) { TListDialog::set_focus(param_1); }
void RGE_Dialog_List::set_tab_order(TPanel* param_1, TPanel* param_2) { TListDialog::set_tab_order(param_1, param_2); }
void RGE_Dialog_List::set_tab_order(TPanel** param_1, short param_2) { TListDialog::set_tab_order(param_1, param_2); }
uchar RGE_Dialog_List::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TListDialog::get_help_info(param_1, param_2, param_3, param_4); }
void RGE_Dialog_List::stop_sound_system() { TListDialog::stop_sound_system(); }
int RGE_Dialog_List::restart_sound_system() { return TListDialog::restart_sound_system(); }
void RGE_Dialog_List::take_snapshot() { TListDialog::take_snapshot(); }
void RGE_Dialog_List::handle_reactivate() { TListDialog::handle_reactivate(); }
void RGE_Dialog_List::draw_background(int param_1) { TListDialog::draw_background(param_1); }
void RGE_Dialog_List::set_ideal_size(long param_1, long param_2) { TListDialog::set_ideal_size(param_1, param_2); }
int RGE_Dialog_List::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TListDialog::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int RGE_Dialog_List::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TListDialog::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int RGE_Dialog_List::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TListDialog::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int RGE_Dialog_List::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TListDialog::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int RGE_Dialog_List::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TListDialog::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int RGE_Dialog_List::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TListDialog::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int RGE_Dialog_List::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TListDialog::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int RGE_Dialog_List::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TListDialog::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int RGE_Dialog_List::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TListDialog::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int RGE_Dialog_List::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TListDialog::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int RGE_Dialog_List::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TListDialog::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int RGE_Dialog_List::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TListDialog::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int RGE_Dialog_List::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TListDialog::create_auto_scrollbar(param_1, param_2, param_3); }
int RGE_Dialog_List::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TListDialog::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int RGE_Dialog_List::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TListDialog::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void RGE_Dialog_List::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TListDialog::position_panel(param_1, param_2, param_3, param_4, param_5); }
int RGE_Dialog_List::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, uchar param_5, int param_6) { return TListDialog::setup(param_1, param_2, param_3, param_4, param_5, param_6); }
int RGE_Dialog_List::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, char* param_5, long param_6, int param_7) { return TListDialog::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }

