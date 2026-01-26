#include "../include/TPanel.h"
#include <string.h>

TPanel::TPanel(char* name) {
    if (name) {
        this->panelNameValue = strdup(name);
    } else {
        this->panelNameValue = nullptr;
    }
}

TPanel::~TPanel() {}
long TPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    this->parent_panel = param_2;
    this->render_area = param_1;
    
    // In original engine, setup sets these "base" values which might be borders or min/max
    this->left_border = param_3;
    this->top_border = param_4;
    this->min_wid = param_5;
    this->max_wid = param_5;
    this->min_hgt = param_6;
    this->max_hgt = param_6;

    this->set_rect(param_3, param_4, param_5, param_6);
    this->color = param_7;
    this->active = 1;
    // set_rect sets visible to 1

    return 1;
}
void TPanel::set_rect(tagRECT param_1) {
    this->set_rect(param_1.left, param_1.top, param_1.right - param_1.left, param_1.bottom - param_1.top);
}

void TPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    this->pnl_x = param_1;
    this->pnl_y = param_2;
    this->pnl_wid = param_3;
    this->pnl_hgt = param_4;
    
    // Set render_rect relative to panel for now, or screen absolute?
    // TDrawArea::Clear takes a rect. TButtonPanel::draw clears using render_rect.
    // Assuming screen logic:
    this->render_rect.left = param_1;
    this->render_rect.top = param_2;
    this->render_rect.right = param_1 + param_3;
    this->render_rect.bottom = param_2 + param_4;

    this->visible = 1;
}

void TPanel::set_color(uchar param_1) { this->color = param_1; }
void TPanel::set_active(int param_1) { this->active = param_1; }
void TPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {}
void TPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {}
void TPanel::set_redraw(RedrawMode param_1) {}
void TPanel::set_overlapped_redraw(RedrawMode param_1) {}
void TPanel::draw_setup(int param_1) {}
void TPanel::draw_finish() {}
void TPanel::draw() {
    if (!this->visible || !this->active) return;
    
    // Draw children
    PanelNode* node = this->first_child_node;
    while (node) {
        if (node->panel) {
            node->panel->draw();
        }
        node = node->next_node;
    }
}
void TPanel::draw_rect(tagRECT* param_1) {}
void TPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) {}
void TPanel::draw_rect2(tagRECT* param_1) {}
void TPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) {}
void TPanel::paint() {}
long TPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return 0; }
long TPanel::handle_idle() { return 0; }
long TPanel::handle_size(long param_1, long param_2) { return 0; }
long TPanel::handle_paint() { return 0; }
long TPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TPanel::handle_char(long param_1, short param_2) { return 0; }
long TPanel::handle_command(uint param_1, long param_2) { return 0; }
long TPanel::handle_user_command(uint param_1, long param_2) { return 0; }
long TPanel::handle_timer_command(uint param_1, long param_2) { return 0; }
long TPanel::handle_scroll(long param_1, long param_2) { return 0; }
long TPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TPanel::char_action(long param_1, short param_2) { return 0; }
long TPanel::action(long param_1, ulong param_2, ulong param_3) { return 0; }
void TPanel::get_true_render_rect(tagRECT* param_1) {}
int TPanel::is_inside(long param_1, long param_2) { return 0; }
void TPanel::set_focus(int param_1) {}
void TPanel::set_tab_order() {}
void TPanel::set_tab_order(TPanel** param_1, short param_2) {}
uchar TPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return 0; }
void TPanel::stop_sound_system() {}
int TPanel::restart_sound_system() { return 1; }
void TPanel::take_snapshot() {}
void TPanel::handle_reactivate() {}

int TPanel::get_string(int resid, char* buffer, int len) {
    if (!buffer || len <= 0) return 0;
    return LoadStringA(GetModuleHandle(NULL), resid, buffer, len);
}

char* TPanel::get_string(int resid) {
    static char static_buffer[1024];
    if (this->get_string(resid, static_buffer, sizeof(static_buffer))) {
        return static_buffer;
    }
    return nullptr;
}
