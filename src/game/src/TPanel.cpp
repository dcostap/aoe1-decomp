#include "../include/ui_core.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/custom_debug.h"
#include <string.h>

extern RGE_Base_Game* rge_base_game;

TPanel::TPanel(char* name) {
    memset((unsigned char*)this + 4, 0, sizeof(TPanel) - 4); // Clear everything after vtable
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
    this->visible = 1;

    // Link to parent
    if (this->parent_panel) {
        PanelNode* newNode = new PanelNode();
        newNode->panel = this;
        newNode->next_node = nullptr;
        newNode->prev_node = this->parent_panel->last_child_node;
        
        if (this->parent_panel->last_child_node) {
            this->parent_panel->last_child_node->next_node = newNode;
        } else {
            this->parent_panel->first_child_node = newNode;
        }
        this->parent_panel->last_child_node = newNode;
        this->node = newNode;
    }

    return 1;
}
void TPanel::set_rect(tagRECT param_1) {
    // Source of truth: `src/game/src/panel.cpp.decomp` uses inclusive rects.
    this->set_rect(param_1.left, param_1.top, (param_1.right - param_1.left) + 1, (param_1.bottom - param_1.top) + 1);
}

void TPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::set_rect(long,long,long,long)`).
    this->pnl_wid = param_3;
    this->pnl_hgt = param_4;

    const long right = param_1 + param_3 - 1;
    const long bottom = param_2 + param_4 - 1;

    this->pnl_x = param_1;
    this->pnl_y = param_2;

    this->render_rect.left = param_1;
    this->render_rect.top = param_2;
    this->render_rect.right = right;
    this->render_rect.bottom = bottom;

    this->clip_rect = this->render_rect;

    if (this->parent_panel && this->clip_to_parent) {
        if (this->clip_rect.left < this->parent_panel->clip_rect.left) this->clip_rect.left = this->parent_panel->clip_rect.left;
        if (this->clip_rect.top < this->parent_panel->clip_rect.top) this->clip_rect.top = this->parent_panel->clip_rect.top;
        if (this->clip_rect.right > this->parent_panel->clip_rect.right) this->clip_rect.right = this->parent_panel->clip_rect.right;
        if (this->clip_rect.bottom > this->parent_panel->clip_rect.bottom) this->clip_rect.bottom = this->parent_panel->clip_rect.bottom;
    }

    if (this->clip_rect.left < 0) this->clip_rect.left = 0;
    if (this->clip_rect.top < 0) this->clip_rect.top = 0;

    if (this->render_area) {
        if (this->render_area->Width > 0 && this->clip_rect.right >= this->render_area->Width) this->clip_rect.right = this->render_area->Width - 1;
        if (this->render_area->Height > 0 && this->clip_rect.bottom >= this->render_area->Height) this->clip_rect.bottom = this->render_area->Height - 1;
    }

    if (this->clip_rgn) {
        DeleteObject((HGDIOBJ)this->clip_rgn);
        this->clip_rgn = 0;
    }

    if (this->clip_rect.left <= this->clip_rect.right && this->clip_rect.top <= this->clip_rect.bottom) {
        this->visible = 1;
        // NOTE: The original passes inclusive coords to CreateRectRgn (Win32 uses exclusive right/bottom).
        // Keep this as-is for now to match the reference behavior.
        this->clip_rgn = (void*)CreateRectRgn(this->clip_rect.left, this->clip_rect.top, this->clip_rect.right, this->clip_rect.bottom);
    } else {
        this->visible = 0;
    }

    if (this->active) {
        this->set_redraw(TPanel::RedrawMode::RedrawFull);
    }
}

void TPanel::set_color(uchar param_1) { this->color = param_1; }
void TPanel::set_active(int param_1) { this->active = param_1; }
void TPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {}
void TPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {}
void TPanel::set_redraw(RedrawMode param_1) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::set_redraw`).
    if (param_1 == NoRedraw) {
        this->need_redraw = NoRedraw;
        return;
    }

    if (this->need_redraw != RedrawFull) {
        this->need_redraw = param_1;
    }

    if (this->render_area && this->render_area->Wnd && this->visible && this->active) {
        InvalidateRect((HWND)this->render_area->Wnd, (RECT*)&this->clip_rect, FALSE);
    }
}
void TPanel::set_overlapped_redraw(RedrawMode param_1) {}
void TPanel::draw_setup(int param_1) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw_setup`).
    if (!this->render_area) return;
    if (this->render_area->DrawDc) {
        SelectClipRgn((HDC)this->render_area->DrawDc, (HRGN)this->clip_rgn);
    }
    this->render_area->SetClipRect(&this->clip_rect);
    if (param_1) {
        this->render_area->Clear(&this->clip_rect, (int)this->color);
    }
}

void TPanel::draw_finish() {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw_finish`).
    this->need_redraw = NoRedraw;
    if (this->render_area && this->render_area->DrawDc) {
        SelectClipRgn((HDC)this->render_area->DrawDc, 0);
    }
    if (this->render_area) {
        this->render_area->SetClipRect((tagRECT*)0);
    }
    this->need_restore = 0;
}
void TPanel::draw() {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw`).
    this->need_redraw = NoRedraw;

    if (!this->render_area || !this->visible || !this->active) return;

    if (this->fill_in_background == 0 && this->parent_panel) {
        if (this->draw_rect2_flag) {
            this->parent_panel->draw_rect2(&this->clip_rect);
        } else {
            this->parent_panel->draw_rect(&this->clip_rect);
        }
        return;
    }

    this->render_area->Clear(&this->clip_rect, (int)this->color);
}
void TPanel::draw_rect(tagRECT* param_1) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw_rect`).
    if (!param_1) return;
    tagRECT save = this->clip_rect;
    this->clip_rect = *param_1;
    this->draw();
    this->clip_rect = save;
}

void TPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw_offset`).
    if (!param_3) return;
    this->pnl_x += param_1;
    this->pnl_y += param_2;
    tagRECT save = this->clip_rect;
    this->clip_rect = *param_3;
    this->draw();
    this->clip_rect = save;
    this->pnl_x -= param_1;
    this->pnl_y -= param_2;
}

void TPanel::draw_rect2(tagRECT* param_1) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw_rect2`).
    this->draw_rect2_flag = 1;
    this->draw_rect(param_1);
    this->draw_rect2_flag = 0;
}

void TPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw_offset2`).
    this->draw_rect2_flag = 1;
    this->draw_offset(param_1, param_2, param_3);
    this->draw_rect2_flag = 0;
}

void TPanel::paint() {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::paint`).
    if (!this->render_area || !this->visible || !this->active) return;
    if (this->render_area->DrawSystem) {
        this->render_area->DrawSystem->Paint((tagRECT*)0);
    }
    if (this->render_area->Wnd) {
        ValidateRect((HWND)this->render_area->Wnd, (RECT*)&this->clip_rect);
    }
}
long TPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    if (!this->active || !this->visible) return 0;

    switch (param_2) {
        case WM_MOUSEMOVE:
            return this->handle_mouse_move(LOWORD(param_4), HIWORD(param_4), (int)param_3, 0);
        case WM_LBUTTONDOWN:
            return this->handle_mouse_down(1, LOWORD(param_4), HIWORD(param_4), (int)param_3, 0);
        case WM_LBUTTONUP:
            return this->handle_mouse_up(1, LOWORD(param_4), HIWORD(param_4), (int)param_3, 0);
        case WM_RBUTTONDOWN:
            return this->handle_mouse_down(2, LOWORD(param_4), HIWORD(param_4), (int)param_3, 0);
        case WM_RBUTTONUP:
            return this->handle_mouse_up(2, LOWORD(param_4), HIWORD(param_4), (int)param_3, 0);
        case WM_KEYDOWN:
            return this->handle_key_down(param_3, 0, 0, 0, 0);
        case WM_CHAR:
            return this->handle_char(param_3, 0);
    }
    return 0;
}

long TPanel::handle_mouse_move(long x, long y, int wparam, int param_4) {
    PanelNode* curr = this->last_child_node;
    while (curr) {
        if (curr->panel && curr->panel->active && curr->panel->visible) {
            if (curr->panel->is_inside(x, y)) {
                if (curr->panel->handle_mouse_move(x, y, wparam, param_4)) return 1;
            }
        }
        curr = curr->prev_node;
    }
    return this->mouse_move_action(x, y, wparam, param_4);
}

long TPanel::handle_mouse_down(uchar button, long x, long y, int wparam, int param_5) {
    PanelNode* curr = this->last_child_node;
    while (curr) {
        if (curr->panel && curr->panel->active && curr->panel->visible) {
            if (curr->panel->is_inside(x, y)) {
                if (curr->panel->handle_mouse_down(button, x, y, wparam, param_5)) return 1;
            }
        }
        curr = curr->prev_node;
    }
    if (button == 1) return this->mouse_left_down_action(x, y, wparam, param_5);
    if (button == 2) return this->mouse_right_down_action(x, y, wparam, param_5);
    return 0;
}

long TPanel::handle_mouse_up(uchar button, long x, long y, int wparam, int param_5) {
    PanelNode* curr = this->last_child_node;
    while (curr) {
        if (curr->panel && curr->panel->active && curr->panel->visible) {
            if (curr->panel->is_inside(x, y)) {
                if (curr->panel->handle_mouse_up(button, x, y, wparam, param_5)) return 1;
            }
        }
        curr = curr->prev_node;
    }
    if (button == 1) return this->mouse_left_up_action(x, y, wparam, param_5);
    if (button == 2) return this->mouse_right_up_action(x, y, wparam, param_5);
    return 0;
}

long TPanel::handle_idle() { return 0; }
long TPanel::handle_size(long param_1, long param_2) { return 0; }
long TPanel::handle_paint() { return 0; }
long TPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TPanel::handle_char(long param_1, short param_2) { return 0; }
long TPanel::handle_command(uint param_1, long param_2) { return 0; }
long TPanel::handle_user_command(uint param_1, long param_2) { return 0; }
long TPanel::handle_timer_command(uint param_1, long param_2) { return 0; }
long TPanel::handle_scroll(long param_1, long param_2) { return 0; }
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
long TPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return 0; }
void TPanel::get_true_render_rect(tagRECT* param_1) {}
int TPanel::is_inside(long x, long y) {
    return (x >= this->pnl_x && x < this->pnl_x + this->pnl_wid &&
            y >= this->pnl_y && y < this->pnl_y + this->pnl_hgt);
}
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
    
    if (rge_base_game) {
        if (rge_base_game->get_string(resid, buffer, len)) {
            // Check if string was found (not empty)
            if (buffer[0] != '\0') return 1;
        }
    }
    
    // Fallback: try loading from module resources directly (just in case)
    if (LoadStringA(GetModuleHandle(NULL), resid, buffer, len) > 0) {
        return 1;
    }
    
    buffer[0] = '\0';
    return 0;
}

char* TPanel::get_string(int resid) {
    static char static_buffer[1024];
    if (this->get_string(resid, static_buffer, sizeof(static_buffer))) {
        return static_buffer;
    }
    return nullptr;
}

long TPanel::xPosition() const { return this->pnl_x; }
long TPanel::yPosition() const { return this->pnl_y; }
long TPanel::width() const { return this->pnl_wid; }
long TPanel::height() const { return this->pnl_hgt; }

void TPanel::draw_tree() {
    // Non-original helper (see `ui_core.h`); used by the current simplified game loop.
    this->draw();
    PanelNode* n = this->first_child_node;
    while (n) {
        if (n->panel) {
            n->panel->draw_tree();
        }
        n = n->next_node;
    }
}
