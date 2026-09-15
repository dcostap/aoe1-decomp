#include "../include/panel.h"
#include <string.h>
#include <stdio.h>

unsigned long __cdecl debug_timeGetTime(char* file, int line);

TPanelSystem::TPanelSystem(void) {
    int* counts;
    char (*files)[260];
    int i;

    ImeEnabled = 1;
    InputEnabled = 1;
    mouse_owner = 0;
    keyboard_owner = 0;
    modal_panel = 0;
    current_panel = 0;
    panel_list = 0;
    number_active_panels = 0;
    previous_current_child = 0;
    Imc = 0;
    ImeOn = 0;
    saved_colors = 0;
    counts = palette_use_count;
    files = palette_file;
    i = 10;
    do {
        counts[-660] = 0;
        (*files)[0] = 0;
        *counts = 0;
        counts[10] = 0;
        counts++;
        files++;
        i--;
    } while (i != 0);
    setup();
}

TPanelSystem::~TPanelSystem(void) {
    this->restore_system_colors();

    PanelNode* panel_list = this->panel_list;
    if (panel_list != 0) {
        PanelNode* node = panel_list->next_node;
        if (node != panel_list) {
            do {
                node = node->next_node;
                TPanel* panel = node->prev_node->panel;
                if (panel != 0) {
                    delete panel;
                }
                free(node->prev_node);
            } while (node != this->panel_list);
        }
        free(this->panel_list);
        this->panel_list = 0;
    }

    int (__stdcall* delete_object)(void*) = DeleteObject;
    for (int i = 0; i < 10; i++) {
        void** palette_entry = &this->palette[i];
        if (*palette_entry) {
            delete_object(*palette_entry);
            *palette_entry = 0;
            this->palette_file[i][0] = 0;
            this->palette_use_count[i] = 0;
            this->palette_id[0] = 0;
        }
    }

    this->EnableIME();
}

TPanel* TPanelSystem::currentPanel() const {
    return this->current_panel;
}

TPanel* TPanelSystem::previousPanel() const {
    if (current_panel)
        return current_panel->previousPanel();
    return 0;
}

TPanel* TPanelSystem::mouseOwner() const {
    return this->mouse_owner;
}

TPanel* TPanelSystem::keyboardOwner() const {
    return this->keyboard_owner;
}

TPanel* TPanelSystem::modalPanel() const {
    return this->modal_panel;
}

TPanel* TPanelSystem::panel(char* n) {
    PanelNode* node;

    node = findPanelNode(n);
    if (node != 0) {
        return node->panel;
    }
    return 0;
}

int TPanelSystem::numberActivePanels() const {
    return this->number_active_panels;
}

int TPanelSystem::addPanel(TPanel* p, int makeCurrent, int makeModal) {
    PanelNode* node;

    node = findPanelNode(p->panelName());
    if (node == 0) {
        node = (PanelNode*)calloc(1, 0x0C);
        if (node == 0) {
            return 0;
        }
        node->panel = p;
        p->setPreviousPanel(0);
        node->prev_node = panel_list->prev_node;
        node->next_node = panel_list;
        panel_list->prev_node = node;
        node->prev_node->next_node = node;
        number_active_panels = number_active_panels + 1;
    }
    if (makeCurrent != 0) {
        setCurrentPanel(p, makeModal);
    }
    return 1;
}

int TPanelSystem::removePanel(char* n) {
    PanelNode* node;

    if (n == 0) {
        return 0;
    }
    node = findPanelNode(n);
    if (node == 0) {
        return 0;
    }
    number_active_panels = number_active_panels - 1;
    node->prev_node->next_node = node->next_node;
    node->next_node->prev_node = node->prev_node;
    free(node);
    return 1;
}

int TPanelSystem::setCurrentPanel(char* n, int makeModal) {
    PanelNode* node;

    node = findPanelNode(n);
    if (node != 0) {
        if (mouse_owner != 0) {
            mouse_owner->release_mouse();
        }
        modal_panel = 0;
        keyboard_owner = 0;
        setCurrentPanel(node->panel, makeModal);
        return 1;
    }
    return 0;
}

int TPanelSystem::restorePreviousPanel(int destroyOldCurrentPanel) {
    TPanel* previous;
    TPanel* current;

    if (current_panel == 0) {
        return 0;
    }
    previous = current_panel->previousPanel();
    if (previous == 0) {
        return 0;
    }
    current = current_panel;
    if (destroyOldCurrentPanel == 0) {
        previous->setPreviousPanel(current);
    } else {
        if (previous->previousPanel() == current) {
            previous->setPreviousPanel(0);
        }
        destroyPanel(current->panelName());
    }
    current_panel = previous;
    previous->set_focus(1);
    current_panel->set_redraw(TPanel::RedrawImmediate);
    UpdateWindow(AppWnd);
    return 1;
}

void TPanelSystem::setMouseOwner(TPanel* p) {
    this->mouse_owner = p;
}

void TPanelSystem::setKeyboardOwner(TPanel* p) {
    this->keyboard_owner = p;
}

void TPanelSystem::setModalPanel(TPanel* p) {
    if (modal_panel != 0 && p != 0) {
        p->setPreviousModalPanel(modal_panel);
    }
    if (modal_panel == 0) {
        TPanel* previous = previous_current_child;
        if (previous != 0 && previous->parent_panel != 0) {
            previous->parent_panel->set_curr_child(previous);
        }
    } else if (modal_panel->tab_stop == 0 && modal_panel->parent_panel != 0) {
        modal_panel->parent_panel->set_curr_child(previous_current_child);
    }
    previous_current_child = 0;
    modal_panel = p;
    if (p != 0 && p != current_panel) {
        TPanel* parent;

        parent = p->parent_panel;
        if (parent != 0) {
            previous_current_child = parent->curr_child;
            parent->set_curr_child(p);
            return;
        }
        previous_current_child = 0;
        p->set_focus(1);
    }
}

void TPanelSystem::setCurrentPanelModal(void) {
    TPanel* modal;

    modal = modal_panel;
    if (modal != 0 && modal != current_panel) {
        current_panel->setPreviousModalPanel(modal);
    }
    modal_panel = current_panel;
}

int TPanelSystem::restorePreviousModalPanel(void) {
    TPanel* panel;

    if (modal_panel == 0) {
        return 0;
    }
    panel = modal_panel->previousModalPanel();
    if (panel == 0) {
        return 0;
    }
    panel->set_focus(1);
    setMouseOwner(panel);
    setKeyboardOwner(panel);
    modal_panel = panel;
    return 1;
}

int TPanelSystem::destroyPanel(char* n) {
    PanelNode* node;

    if (n == 0) {
        return 0;
    }
    node = findPanelNode(n);
    if (node == 0) {
        return 0;
    }
    number_active_panels = number_active_panels - 1;
    if (current_panel == node->panel) {
        current_panel = 0;
    }
    if (mouse_owner == node->panel) {
        mouse_owner = 0;
    }
    if (keyboard_owner == node->panel) {
        keyboard_owner = 0;
    }
    if (modal_panel == node->panel) {
        modal_panel = 0;
    }
    node->prev_node->next_node = node->next_node;
    node->next_node->prev_node = node->prev_node;
    if (node->panel != 0) {
        delete node->panel;
    }
    free(node);
    return 1;
}

int TPanelSystem::inSystem(char* n) {
    return findPanelNode(n) != 0;
}

int TPanelSystem::inSystem(TPanel* p) {
    if (p != 0) {
        if (findPanelNode(p->panelName()) != 0) {
            return 1;
        }
    }
    return 0;
}

int TPanelSystem::setup(void) {
    panel_list = (PanelNode*)calloc(1, 0x0C);
    if (panel_list == 0) {
        return 0;
    }
    panel_list->panel = 0;
    panel_list->prev_node = panel_list;
    panel_list->next_node = panel_list;
    save_back_color = GetSysColor(COLOR_WINDOW);
    save_text_color = GetSysColor(COLOR_WINDOWTEXT);
    saved_colors = 1;
    return 1;
}

PanelNode* TPanelSystem::findPanelNode(char* n) {
    TPanelSystem* self;
    char* target;
    PanelNode* node;

    self = this;
    target = n;
    if (target == 0) {
        return 0;
    }
    node = self->panel_list->next_node;
    while (node != self->panel_list && strcmp(node->panel->panelName(), target) != 0) {
        node = node->next_node;
    }
    if (node != self->panel_list && strcmp(node->panel->panelName(), target) == 0) {
        return node;
    }
    return 0;
}

void TPanelSystem::setCurrentPanel(TPanel* p, int makeModal) {
    p->setPreviousPanel(current_panel);
    if (current_panel != 0) {
        current_panel->set_focus(0);
    }
    current_panel = p;
    p->set_focus(1);
    current_panel->set_redraw(TPanel::RedrawImmediate);
    UpdateWindow(AppWnd);
    if (makeModal != 0) {
        setCurrentPanelModal();
    }
}

void* TPanelSystem::get_palette(char* file_name, long res_id) {
    char file_name2[260];

    if (file_name == 0) {
        file_name2[0] = 0;
    } else {
        if (strchr(file_name, '.') == 0) {
            sprintf(file_name2, "%s.pal", file_name);
        } else {
            strcpy(file_name2, file_name);
        }
        strupr(file_name2);
    }

    int found = -1;
    int i;

    for (i = 0; i < 10; i++) {
        if (this->palette[i] != 0) {
            if ((res_id != -1 && this->palette_id[i] == res_id) ||
                strcmp(this->palette_file[i], file_name2) == 0) {
                this->palette_use_count[i]++;
                return this->palette[i];
            }
        } else if (found == -1) {
            found = i;
        }
    }

    if (found == -1) return 0;

    this->palette[found] = ReadPalette(file_name2, res_id, 1);
    if (this->palette[found] == 0) return 0;

    this->palette_use_count[found]++;
    strcpy(this->palette_file[found], file_name2);
    this->palette_id[found] = res_id;
    return this->palette[found];
}

void TPanelSystem::release_palette(void* pal) {
    int i;

    for (i = 0; i < 10; i++) {
        if (palette[i] == pal) {
            palette_use_count[i]--;
            if (palette_use_count[i] == 0) {
                DeleteObject(palette[i]);
                palette[i] = 0;
                palette_file[i][0] = 0;
            }
            return;
        }
    }
}

void TPanelSystem::DisableIME(void) {
    if (ImeEnabled != 0) {
        Imc = ImmAssociateContext(AppWnd, 0);
        ImeEnabled = 0;
    }
}

void TPanelSystem::EnableIME(void) {
    if (Imc != 0 && ImeEnabled == 0) {
        ImmAssociateContext(AppWnd, Imc);
    }
}

int TPanelSystem::IsIMEEnabled() {
    return this->ImeEnabled;
}

void TPanelSystem::TurnIMEOn(void) {
    if (ImeOn == 0 && ImeEnabled != 0 && Imc != 0) {
        ImmSetOpenStatus(Imc, 1);
        ImeOn = 1;
    }
}

void TPanelSystem::TurnIMEOff(void) {
    if (ImeOn != 0 && ImeEnabled != 0 && Imc != 0) {
        ImmSetOpenStatus(Imc, 0);
        ImeOn = 0;
    }
}

int TPanelSystem::IsIMEOn() {
    return this->ImeOn;
}

int TPanelSystem::GetInputEnabled() {
    return this->InputEnabled;
}

void TPanelSystem::EnableInput() {
    this->InputEnabled = 1;
}

void TPanelSystem::DisableInput() {
    this->InputEnabled = 0;
}

void TPanelSystem::stop_sound_system(void) {
    PanelNode* node;

    node = panel_list->next_node;
    while (node != 0 && node != panel_list) {
        if (node->panel != 0) {
            node->panel->stop_sound_system();
        }
        node = node->next_node;
    }
}

int TPanelSystem::restart_sound_system(void) {
    PanelNode* node;
    int ok;

    ok = 1;
    node = panel_list->next_node;
    while (node != 0 && node != panel_list) {
        if (node->panel != 0 && node->panel->restart_sound_system() == 0) {
            ok = 0;
        }
        node = node->next_node;
    }
    return ok;
}

void TPanelSystem::restore_system_colors(void) {
    int elems[2];
    unsigned long colors[2];

    if (saved_colors != 0) {
        if (GetSysColor(COLOR_WINDOW) == save_back_color && GetSysColor(COLOR_WINDOWTEXT) == save_text_color) {
            return;
        }
        colors[0] = save_back_color;
        elems[0] = COLOR_WINDOW;
        elems[1] = COLOR_WINDOWTEXT;
        colors[1] = save_text_color;
        SetSysColors(2, elems, colors);
    }
}

void TPanelSystem::set_restore(void) {
    PanelNode* node;

    node = panel_list->next_node;
    if (node != panel_list) {
        do {
            if (node->panel != 0) {
                node->panel->need_restore = 1;
            }
            node = node->next_node;
        } while (node != panel_list);
    }
}

TPanel::TPanel(char* name)
    : previous_panel(0), previous_modal_panel(0), pnl_x(0), pnl_y(0),
      pnl_wid(0), pnl_hgt(0), panel_name(0), render_area(0), position_mode(0),
      need_redraw(TPanel::RedrawImmediate), curr_child(0), parent_panel(0), left_panel(0),
      top_panel(0), right_panel(0), bottom_panel(0), node(0),
      first_child_node(0), last_child_node(0), tab_prev_panel(0),
      tab_next_panel(0), mouse_captured(0), active(1), visible(0), tab_stop(0),
      have_focus(0), overlapping_children(1), handle_mouse_input(1),
      just_drawn(0), clip_rgn(0), left_border(0), top_border(0),
      right_border(0), bottom_border(0), min_wid(0), max_wid(0), min_hgt(0),
      max_hgt(0), mouse_hold_interval(250), mouse_move_tolerance(0),
      mouse_down_x(0), mouse_down_y(0), mouse_down_ctrl(0),
      mouse_down_shift(0), mouse_down_time(0), error_code(0), z_order(0),
      display_changed_count(0), mouse_action(0), mouse_down_button(0),
      panel_type(0), color(0), fill_in_background(0), draw_rect2_flag(0) {
    render_rect.left = 0;
    render_rect.top = 0;
    render_rect.right = 0;
    render_rect.bottom = 0;
    setPanelName(name);
    need_restore = 0;
    help_string_id = -1;
    help_page_id = -1;
    if (panel_name != 0 && panel_name[0] != 0) {
        panel_system.addPanel(this, 0, 0);
    }
}

TPanel::TPanel(void)
    : previous_panel(0), previous_modal_panel(0), pnl_x(0), pnl_y(0),
      pnl_wid(0), pnl_hgt(0), panel_name(0), render_area(0), position_mode(0),
      need_redraw(TPanel::RedrawImmediate), curr_child(0), parent_panel(0), left_panel(0),
      top_panel(0), right_panel(0), bottom_panel(0), node(0),
      first_child_node(0), last_child_node(0), tab_prev_panel(0),
      tab_next_panel(0), mouse_captured(0), active(1), visible(0), tab_stop(0),
      have_focus(0), overlapping_children(1), handle_mouse_input(1),
      clip_rgn(0), left_border(0), top_border(0), right_border(0),
      bottom_border(0), min_wid(0), max_wid(0), min_hgt(0), max_hgt(0),
      mouse_hold_interval(250), mouse_move_tolerance(0), mouse_down_x(0),
      mouse_down_y(0), mouse_down_ctrl(0), mouse_down_shift(0),
      mouse_down_time(0), error_code(0), z_order(0), display_changed_count(0),
      mouse_action(0), mouse_down_button(0), panel_type(0), color(0),
      fill_in_background(0), draw_rect2_flag(0) {
    render_rect.left = 0;
    render_rect.top = 0;
    render_rect.right = 0;
    render_rect.bottom = 0;
    help_string_id = -1;
    help_page_id = -1;
}

TPanel::~TPanel() {
    TPanel* self;

    self = this;
    release_mouse();
    if (panel_name != 0) {
        if (panel_system.inSystem(self) != 0) {
            panel_system.removePanel(panelName());
        }
    }
    if (node != 0) {
        if (parent_panel != 0) {
            parent_panel->remove_panel_node(node);
        }
        free(node);
        node = 0;
    }
    first_child_node = 0;
    if (clip_rgn != 0) {
        DeleteObject(clip_rgn);
        clip_rgn = 0;
    }
    if (parent_panel != 0) {
        parent_panel->set_redraw(TPanel::RedrawImmediate);
    }
    if (panel_name != 0) {
        free(panel_name);
    }
}

long TPanel::setup(TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in, unsigned char color_in) {
    render_area = render_area_in;
    parent_panel = parent_panel_in;
    if (position_mode == 0) {
        left_border = x_in;
        top_border = y_in;
        min_wid = wid_in;
        max_wid = wid_in;
        right_border = 0;
        bottom_border = 0;
        min_hgt = hgt_in;
        max_hgt = hgt_in;
    }
    if (render_area_in != 0) {
        handle_size(render_area_in->Width, render_area_in->Height);
    } else {
        handle_size(0, 0);
    }
    set_color((unsigned char)color_in);
    mouse_captured = 0;
    if (node == 0) {
        node = (PanelNode*)calloc(1, 0xC);
        if (node == 0) {
            return 0;
        }
        node->panel = this;
        node->prev_node = 0;
        node->next_node = 0;
        if (parent_panel != 0) {
            parent_panel->add_panel_node(node, 0, 0);
        }
    }
    return 1;
}

void TPanel::add_panel_node(PanelNode* node_in, PanelNode* by_node, int add_after) {
    if (by_node == 0) {
        by_node = first_child_node;
        if (by_node == 0) {
            node_in->prev_node = by_node;
            node_in->next_node = by_node;
            goto done;
        }
        while (by_node->next_node != 0) {
            by_node = by_node->next_node;
        }
        by_node->next_node = node_in;
        node_in->prev_node = by_node;
        node_in->next_node = 0;
        goto done;
    }
    if (add_after != 0) {
        node_in->prev_node = by_node;
        node_in->next_node = by_node->next_node;
        by_node->next_node = node_in;
        if (node_in->next_node != 0) {
            node_in->next_node->prev_node = node_in;
        }
    } else {
        node_in->prev_node = by_node->prev_node;
        node_in->next_node = by_node;
        by_node->prev_node = node_in;
        if (node_in->prev_node != 0) {
            node_in->prev_node->next_node = node_in;
        }
    }
done:
    if (node_in->prev_node == 0) {
        first_child_node = node_in;
    }
    if (node_in->next_node == 0) {
        last_child_node = node_in;
    }
}

void TPanel::remove_panel_node(PanelNode* node_in) {
    if (node_in == first_child_node) {
        first_child_node = node_in->next_node;
    }
    if (node_in == last_child_node) {
        last_child_node = node_in->prev_node;
    }
    if (node_in->prev_node != 0) {
        node_in->prev_node->next_node = node_in->next_node;
    }
    if (node_in->next_node != 0) {
        node_in->next_node->prev_node = node_in->prev_node;
    }
    node_in->prev_node = 0;
    node_in->next_node = 0;
    if (curr_child == node_in->panel) {
        curr_child = 0;
    }
}

void TPanel::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    pnl_wid = wid_in;
    pnl_hgt = hgt_in;
    long right = x_in + wid_in - 1;
    long bottom = y_in + hgt_in - 1;

    pnl_x = x_in;
    pnl_y = y_in;

    render_rect.left = x_in;
    render_rect.top = y_in;
    render_rect.right = right;
    render_rect.bottom = bottom;

    clip_rect.left = x_in;
    clip_rect.top = y_in;
    clip_rect.right = right;
    clip_rect.bottom = bottom;

    if (parent_panel != 0 && clip_to_parent != 0) {
        if (left < parent_panel->clip_rect.left) {
            clip_rect.left = parent_panel->clip_rect.left;
        }
        if (top < parent_panel->clip_rect.top) {
            clip_rect.top = parent_panel->clip_rect.top;
        }
        if (right > parent_panel->clip_rect.right) {
            clip_rect.right = parent_panel->clip_rect.right;
        }
        if (bottom > parent_panel->clip_rect.bottom) {
            clip_rect.bottom = parent_panel->clip_rect.bottom;
        }
    }

    if (clip_rect.left < 0) {
        clip_rect.left = 0;
    }
    if (clip_rect.top < 0) {
        clip_rect.top = 0;
    }

    if (render_area != 0) {
        if (clip_rect.right >= render_area->Width) {
            clip_rect.right = render_area->Width - 1;
        }
    }
    if (render_area != 0) {
        if (clip_rect.bottom >= render_area->Height) {
            clip_rect.bottom = render_area->Height - 1;
        }
    }

    if (clip_rgn != 0) {
        DeleteObject(clip_rgn);
        clip_rgn = 0;
    }

    if (clip_rect.right >= clip_rect.left && clip_rect.bottom >= clip_rect.top) {
        visible = 1;
        clip_rgn = CreateRectRgn(clip_rect.left, clip_rect.top, clip_rect.right, clip_rect.bottom);
    } else {
        visible = 0;
    }

    if (active != 0) {
        set_redraw(TPanel::RedrawImmediate);
    }
}

void TPanel::set_rect(tagRECT rect_in) {
    set_rect(rect_in.left, rect_in.top, (rect_in.right - rect_in.left) + 1, (rect_in.bottom - rect_in.top) + 1);
}

void TPanel::set_color(unsigned char color_in) {
    this->color = color_in;
    if (active != 0) {
        set_redraw(TPanel::RedrawImmediate);
    }
}

void TPanel::set_active(int active_in) {
    if (active != active_in) {
        active = active_in;
        if (active_in != 0) {
            set_redraw(TPanel::RedrawNormal);
            return;
        }
        release_mouse();
        if (parent_panel != 0) {
            parent_panel->set_redraw(TPanel::RedrawNormal);
        }
    }
}

void TPanel::set_positioning(TPanel::PositionMode position_mode_in, long left_border_in, long top_border_in, long right_border_in,
                             long bottom_border_in, long min_wid_in, long max_wid_in, long min_hgt_in,
                             long max_hgt_in, TPanel* left_panel_in, TPanel* top_panel_in,
                             TPanel* right_panel_in, TPanel* bottom_panel_in) {
    position_mode = position_mode_in;
    left_border = left_border_in;
    top_border = top_border_in;
    right_border = right_border_in;
    bottom_border = bottom_border_in;
    min_wid = min_wid_in;
    max_wid = max_wid_in;
    min_hgt = min_hgt_in;
    max_hgt = max_hgt_in;
    left_panel = left_panel_in;
    top_panel = top_panel_in;
    right_panel = right_panel_in;
    bottom_panel = bottom_panel_in;

    if (render_area != 0) {
        handle_size(render_area->Width, render_area->Height);
    } else {
        handle_size(0, 0);
    }

    if (active != 0) {
        set_redraw(TPanel::RedrawImmediate);
    }
}

void TPanel::set_fixed_position(long left_border_in, long top_border_in, long wid_in, long hgt_in) {
    set_positioning(TPanel::PositionFixed, left_border_in, top_border_in, 0, 0, wid_in, wid_in, hgt_in, hgt_in, 0, 0, 0, 0);
}

void TPanel::set_redraw(TPanel::RedrawMode redraw_mode) {
    if (redraw_mode == TPanel::RedrawNormal && need_redraw == TPanel::RedrawImmediate) {
        return;
    }
    need_redraw = redraw_mode;
    if (redraw_mode != 0 && render_area != 0 && visible != 0 && active != 0) {
        InvalidateRect(render_area->Wnd, &clip_rect, 0);
    }
}

void TPanel::set_overlapped_redraw(TPanel* redraw_panel, TPanel* calling_panel, TPanel::RedrawMode redraw_mode) {
    tagRECT this_rect = redraw_panel->clip_rect;
    int this_left = this_rect.left;
    int this_top = this_rect.top;
    int this_right = this_rect.right;
    int this_bottom = this_rect.bottom;

    PanelNode* temp_node = first_child_node;
    if (temp_node == 0) return;

    do {
        TPanel* panel = temp_node->panel;
        if (panel != redraw_panel && panel != calling_panel && panel->z_order > redraw_panel->z_order) {
            tagRECT panel_rect = panel->clip_rect;
            int panel_left = panel_rect.left;
            int panel_top = panel_rect.top;
            int panel_right = panel_rect.right;
            int panel_bottom = panel_rect.bottom;

            if ((((panel_left < this_left || panel_left > this_right) &&
                  (panel_right < this_left || panel_right > this_right)) &&
                 (panel_left >= this_left || panel_right <= this_right)) ||
                (((panel_top < this_top || panel_top > this_bottom) &&
                  (panel_bottom < this_top || panel_bottom > this_bottom)) &&
                  (panel_top >= this_top || panel_bottom <= this_bottom))) {
                if ((((this_left >= panel_left && this_left <= panel_right) ||
                      (this_right >= panel_left && this_right <= panel_right)) ||
                     (this_left < panel_left && this_right > panel_right)) &&
                    (((this_top >= panel_top && this_top <= panel_bottom) ||
                      (this_bottom >= panel_top && this_bottom <= panel_bottom)) ||
                     (this_top < panel_top && this_bottom > panel_bottom))) {
                    panel->set_redraw(redraw_mode);
                }
            } else {
                panel->set_redraw(redraw_mode);
            }
        }
        temp_node = temp_node->next_node;
    } while (temp_node != 0);
}

void TPanel::set_any_overlapping_redraw(TPanel* redraw_panel, TPanel::RedrawMode redraw_mode) {
    tagRECT this_rect = redraw_panel->clip_rect;
    PanelNode* temp_node = this->first_child_node;

    while (temp_node != 0) {
        TPanel* panel = temp_node->panel;
        if (panel != redraw_panel) {
            tagRECT panel_rect = panel->clip_rect;

            if (((((panel_rect.left < this_rect.left) ||
                   (panel_rect.left > this_rect.right)) &&
                  ((panel_rect.right < this_rect.left) ||
                   (panel_rect.right > this_rect.right))) &&
                 ((panel_rect.left >= this_rect.left) ||
                  (panel_rect.right <= this_rect.right))) ||
                (((panel_rect.top < this_rect.top) ||
                  (panel_rect.top > this_rect.bottom)) &&
                 (((panel_rect.bottom < this_rect.top) ||
                   (panel_rect.bottom > this_rect.bottom)) &&
                  ((panel_rect.top >= this_rect.top) ||
                   (panel_rect.bottom <= this_rect.bottom))))) {
                if (((((this_rect.left >= panel_rect.left) &&
                       (this_rect.left <= panel_rect.right)) ||
                      ((this_rect.right >= panel_rect.left) &&
                       (this_rect.right <= panel_rect.right))) ||
                     ((this_rect.left < panel_rect.left) &&
                      (this_rect.right > panel_rect.right))) &&
                    (((this_rect.top >= panel_rect.top) &&
                      (this_rect.top <= panel_rect.bottom)) ||
                     ((this_rect.bottom >= panel_rect.top) &&
                      (this_rect.bottom <= panel_rect.bottom)) ||
                     ((this_rect.top < panel_rect.top) &&
                      (this_rect.bottom > panel_rect.bottom)))) {
                    panel->set_redraw(redraw_mode);
                }
            } else {
                panel->set_redraw(redraw_mode);
            }
        }
        temp_node = temp_node->next_node;
    }
}

void TPanel::draw(void) {
    TDrawArea* area;

    need_redraw = 0;
    area = render_area;
    if (area != 0 && visible != 0 && active != 0) {
        if (fill_in_background == 0 && parent_panel != 0) {
            if (draw_rect2_flag != 0) {
                parent_panel->draw_rect2(&clip_rect);
                return;
            }
            parent_panel->draw_rect(&clip_rect);
            return;
        }
        area->Clear(&clip_rect, color);
    }
}

void TPanel::draw_rect(tagRECT* rect) {
    tagRECT save_rect;

    save_rect = clip_rect;
    clip_rect = *rect;
    draw();
    clip_rect = save_rect;
}

void TPanel::draw_offset(long x_offset, long y_offset, tagRECT* rect) {
    tagRECT save_rect;

    pnl_x = pnl_x + x_offset;
    pnl_y = pnl_y + y_offset;
    save_rect = clip_rect;
    clip_rect = *rect;
    draw();
    clip_rect = save_rect;
    pnl_x = pnl_x - x_offset;
    pnl_y = pnl_y - y_offset;
}

void TPanel::draw_rect2(tagRECT* rect) {
    draw_rect2_flag = 1;
    draw_rect(rect);
    draw_rect2_flag = 0;
}

void TPanel::draw_offset2(long x_offset, long y_offset, tagRECT* rect) {
    draw_rect2_flag = 1;
    draw_offset(x_offset, y_offset, rect);
    draw_rect2_flag = 0;
}

void TPanel::draw_setup(int clear) {
    void* dc;
    tagRECT* rect;

    dc = render_area->DrawDc;
    if (dc != 0) {
        SelectClipRgn(dc, clip_rgn);
    }
    rect = &clip_rect;
    render_area->SetClipRect(rect);
    if (clear != 0) {
        render_area->Clear(rect, color);
    }
}

void TPanel::draw_finish(void) {
    void* dc;

    need_redraw = 0;
    dc = render_area->DrawDc;
    if (dc != 0) {
        SelectClipRgn(dc, 0);
    }
    render_area->SetClipRect(0);
    need_restore = 0;
}

void TPanel::paint(void) {
    if (render_area != 0 && visible != 0 && active != 0) {
        render_area->DrawSystem->Paint(&clip_rect);
        ValidateRect(render_area->Wnd, &clip_rect);
    }
}

long TPanel::wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    POINT point;
    TPanel* target;
    int ctrl_key;
    int shift_key;
    PanelNode* node;
    long result;

    if (this->active == 0) {
        return 0;
    }

    if (msg <= WM_RBUTTONDBLCLK) {
        if (msg < WM_MOUSEFIRST) {
            switch (msg) {
            case WM_KEYDOWN:
            case WM_CHAR:
            case WM_SYSKEYDOWN:
                break;
            default:
                goto child_input;
            }
        } else {
            if (hwnd != this->render_area->Wnd) {
                return 0;
            }
            if (panel_system.GetInputEnabled() == 0) {
                return 0;
            }

            this->get_mouse_info(wParam, lParam, point, ctrl_key, shift_key);
            if (panel_system.mouseOwner() != 0) {
                target = panel_system.mouseOwner();
            } else if (panel_system.keyboardOwner() != 0) {
                target = panel_system.keyboardOwner();
            } else if (panel_system.modalPanel() != 0) {
                target = panel_system.modalPanel();
            } else {
                target = this;
            }

            switch (msg) {
            case WM_MOUSEMOVE:
                return target->handle_mouse_move(point.x, point.y, ctrl_key, shift_key);
            case WM_LBUTTONDOWN:
                return target->handle_mouse_down(1, point.x, point.y, ctrl_key, shift_key);
            case WM_LBUTTONUP:
                return target->handle_mouse_up(1, point.x, point.y, ctrl_key, shift_key);
            case WM_LBUTTONDBLCLK:
                return target->handle_mouse_dbl_click(1, point.x, point.y, ctrl_key, shift_key);
            case WM_RBUTTONDOWN:
                return target->handle_mouse_down(2, point.x, point.y, ctrl_key, shift_key);
            case WM_RBUTTONUP:
                return target->handle_mouse_up(2, point.x, point.y, ctrl_key, shift_key);
            case WM_RBUTTONDBLCLK:
                return target->handle_mouse_dbl_click(2, point.x, point.y, ctrl_key, shift_key);
            }
        }

        if (hwnd != this->render_area->Wnd) {
            return 0;
        }
        if (panel_system.GetInputEnabled() == 0) {
            return 0;
        }

        if (panel_system.keyboardOwner() != 0) {
            target = panel_system.keyboardOwner();
        } else if (panel_system.modalPanel() != 0) {
            target = panel_system.modalPanel();
        } else {
            target = this;
        }

        if (msg != WM_KEYDOWN && msg != WM_SYSKEYDOWN) {
            return target->handle_char(wParam, (short)lParam);
        }
        int alt = GetKeyState(VK_MENU) < 0;
        ctrl_key = GetKeyState(VK_CONTROL) < 0;
        shift_key = GetKeyState(VK_SHIFT) < 0;
        return target->handle_key_down(wParam, (short)lParam, alt, ctrl_key, shift_key);
    }

child_input:
    node = this->last_child_node;
    while (node != 0) {
        result = node->panel->wnd_proc(hwnd, msg, wParam, lParam);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }

    if (msg <= WM_USER) {
        switch (msg) {
        case WM_COMMAND:
            return this->handle_command(wParam, lParam);
        case WM_USER:
            return this->handle_user_command(wParam, lParam);
        case WM_TIMER:
            return this->handle_timer_command(wParam, lParam);
        case WM_HSCROLL:
        case WM_VSCROLL:
            return this->handle_scroll((long)(wParam & 0xFFFF), (long)(wParam >> 16));
        }
    }

    return 0;
}

long TPanel::handle_idle(void) {
    PanelNode* node;
    long result;

    if (active != 0 && mouse_action == 1) {
        if ((int)(debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Panel.cpp", 0x5FD) - mouse_down_time) >= mouse_hold_interval) {
            mouse_action = 2;
            if (mouse_down_button == 1) {
                mouse_left_hold_action(mouse_down_x, mouse_down_y, mouse_down_ctrl, mouse_down_shift);
            } else {
                mouse_right_hold_action(mouse_down_x, mouse_down_y, mouse_down_ctrl, mouse_down_shift);
            }
        }
    }

    node = last_child_node;
    while (node != 0) {
        result = node->panel->handle_idle();
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }
    return 0;
}

long TPanel::handle_size(long win_wid, long win_hgt) {
    PanelNode* node;
    long left;
    long top;
    long right;
    long bottom;
    long calc_wid;
    long calc_hgt;
    int i;
    tagRECT rect;

    if (this->parent_panel != 0) {
        right = this->parent_panel->render_rect.right;
        left = this->parent_panel->render_rect.left;
        top = this->parent_panel->render_rect.top;
        bottom = this->parent_panel->render_rect.bottom;
        win_wid = (right - left) + 1;
        win_hgt = (bottom - top) + 1;
    } else {
        left = 0;
        top = 0;
        right = win_wid - 1;
        bottom = win_hgt - 1;
    }

    if (this->position_mode == PositionFixed) {
        left = this->left_border + left;
        top = this->top_border + top;
        right = this->min_wid + left - 1;
        bottom = this->min_hgt + top - 1;
    } else {
        if (this->left_panel == 0 || this->left_panel->active == 0) {
            left = this->left_border + left;
        } else {
            left = this->left_border + this->left_panel->render_rect.right + 1;
        }

        if (this->top_panel == 0 || this->top_panel->active == 0) {
            top = this->top_border + top;
        } else {
            top = this->top_border + this->top_panel->render_rect.bottom + 1;
        }

        if (this->right_panel == 0 || this->right_panel->active == 0) {
            right = right - this->right_border;
        } else {
            right = this->right_panel->render_rect.left - this->right_border - 1;
        }

        if (this->bottom_panel == 0 || this->bottom_panel->active == 0) {
            bottom = bottom - this->bottom_border;
        } else {
            bottom = this->bottom_panel->render_rect.top - this->bottom_border - 1;
        }

        calc_wid = (right - left) + 1;
        calc_hgt = (bottom - top) + 1;
        if (this->min_wid != 0 && calc_wid < this->min_wid) {
            right = left + this->min_wid - 1;
        } else {
            if (this->max_wid != 0 && calc_wid > this->max_wid) {
                if (this->position_mode == PositionLeft ||
                    this->position_mode == PositionLeftTop ||
                    this->position_mode == PositionLeftBottom) {
                    right = left + this->max_wid - 1;
                } else {
                    left = right - this->max_wid + 1;
                }
            }
        }

        if (this->min_hgt != 0 && calc_hgt < this->min_hgt) {
            bottom = top + this->min_hgt - 1;
        } else {
            if (this->max_hgt != 0 && calc_hgt > this->max_hgt) {
                if (this->position_mode == PositionTop ||
                    this->position_mode == PositionLeftTop ||
                    this->position_mode == PositionRightTop) {
                    bottom = top + this->max_hgt - 1;
                } else {
                    top = bottom - this->max_hgt + 1;
                }
            }
        }

        if (this->position_mode == PositionCentered) {
            calc_wid = (right - left) + 1;
            calc_hgt = (bottom - top) + 1;
            if (calc_wid == win_wid) {
                left = 0;
            } else {
                left = win_wid / 2 - calc_wid / 2;
            }
            right = calc_wid + left - 1;
            if (calc_hgt == win_hgt) {
                top = 0;
            } else {
                top = win_hgt / 2 - calc_hgt / 2;
            }
            bottom = calc_hgt + top - 1;
        }
    }

    rect.left = left;
    rect.top = top;
    rect.right = right;
    rect.bottom = bottom;
    this->set_rect(rect);

    i = 0;
    do {
        node = this->first_child_node;
        while (node != 0) {
            long result = node->panel->handle_size(win_wid, win_hgt);
            if (result != 0) {
                return result;
            }
            node = node->next_node;
        }
        i++;
    } while (i < 2);

    return 0;
}

long TPanel::handle_paint() {
    if (this->render_area == 0) {
        return 0;
    }
    if (this->visible == 0) {
        return 0;
    }
    if (this->active == 0) {
        return 0;
    }
    if (rge_base_game->prog_active == 0) {
        return 0;
    }
    if (IsIconic(this->render_area->Wnd) != 0) {
        return 0;
    }

    if (this->need_redraw != 0) {
        for (PanelNode* node = this->first_child_node;
             node != 0;
             node = node->next_node) {
            node->panel->set_redraw(
                static_cast<TPanel::RedrawMode>(this->need_redraw));
        }

        if (this->parent_panel != 0 && this->parent_panel->overlapping_children != 0) {
            this->parent_panel->set_overlapped_redraw(
                this, this, static_cast<TPanel::RedrawMode>(this->need_redraw));
        }
        this->draw();
        this->need_redraw = 0;
        this->just_drawn = 1;
    }

    for (PanelNode* node = this->first_child_node;
         node != 0;
         node = node->next_node) {
        node->panel->handle_paint();
    }

    this->just_drawn = 0;
    return 0;
}

long TPanel::handle_key_down(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    PanelNode* node;
    long result;
    TPanel* target;

    if (have_focus == 0) {
        return 0;
    }

    node = last_child_node;
    while (node != 0) {
        result = node->panel->handle_key_down(key, count, alt_key, ctrl_key, shift_key);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }

    result = key_down_action(key, count, alt_key, ctrl_key, shift_key);
    if (result != 0) {
        return result;
    }

    if (alt_key == 0 && ctrl_key == 0 && key == VK_TAB && tab_stop != 0 && parent_panel != 0) {
        if (shift_key != 0) {
            target = tab_prev_panel;
        } else {
            target = tab_next_panel;
        }
        if (target != 0) {
            parent_panel->set_curr_child(target);
            return 1;
        }
    }

    return 0;
}

long TPanel::handle_char(long key, short count) {
    PanelNode* node;
    long result;

    if (have_focus == 0) {
        return 0;
    }
    node = last_child_node;
    while (node != 0) {
        result = node->panel->handle_char(key, count);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }
    return char_action(key, count);
}

long TPanel::handle_command(unsigned int wParam, long lParam) {
    return 0;
}

long TPanel::handle_user_command(unsigned int wParam, long lParam) {
    return 0;
}

long TPanel::handle_timer_command(unsigned int wParam, long lParam) {
    return 0;
}

long TPanel::handle_scroll(long scroll_cmd, long line_num) {
    return 0;
}

long TPanel::handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key) {
    if (this->active == 0)
        return 0;

    if (this->mouse_captured == 0) {
        if (this->is_inside(x, y) == 0)
            return 0;

        for (PanelNode* node = this->last_child_node; node != 0; node = node->prev_node) {
            long result = node->panel->handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
            if (result != 0)
                return result;
        }

        if (this->handle_mouse_input == 0)
            return 0;

        this->mouse_down_button = mouse_button_in;
        this->mouse_down_x = x;
        this->mouse_down_y = y;
        this->mouse_down_ctrl = ctrl_key;
        this->mouse_down_shift = shift_key;
        this->mouse_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Panel.cpp", 0x72C);
        this->mouse_action = 1;

        if (this->tab_stop != 0 && this->parent_panel != 0 && this->mouse_down_button == 1) {
            this->parent_panel->set_curr_child(this);
        }
    }

    if (this->handle_mouse_input == 0)
        return 0;

    if (this->mouse_down_button == 1) {
        this->mouse_left_down_action(x, y, ctrl_key, shift_key);
    } else {
        this->mouse_right_down_action(x, y, ctrl_key, shift_key);
    }
    return 1;
}

long TPanel::handle_mouse_move(long x, long y, int ctrl_key, int shift_key) {
    if (this->active == 0)
        return 0;

    if (this->mouse_captured == 0) {
        if (this->is_inside(x, y) == 0)
            return 0;

        for (PanelNode* node = this->last_child_node; node != 0; node = node->prev_node) {
            long result = node->panel->handle_mouse_move(x, y, ctrl_key, shift_key);
            if (result != 0)
                return result;
        }

        if (this->handle_mouse_input == 0)
            return 0;

        return this->mouse_move_action(x, y, ctrl_key, shift_key);
    }

    if (this->handle_mouse_input == 0)
        return 0;

    if (this->mouse_action == 1 || this->mouse_action == 2) {
        if (this->mouse_down_button == 1) {
            if (abs(x - this->mouse_down_x) <= this->mouse_move_tolerance &&
                abs(y - this->mouse_down_y) <= this->mouse_move_tolerance)
                return 1;
        } else {
            if (abs(x - this->mouse_down_x) <= 10 &&
                abs(y - this->mouse_down_y) <= 10)
                return 1;
        }
    }

    this->mouse_action = 3;
    if (this->mouse_down_button == 1) {
        this->mouse_left_move_action(x, y, ctrl_key, shift_key);
    } else if (this->mouse_down_button == 2) {
        this->mouse_right_move_action(x, y, ctrl_key, shift_key);
    } else {
        this->mouse_move_action(x, y, ctrl_key, shift_key);
    }
    return 1;
}

long TPanel::handle_mouse_up(unsigned char mouse_button_in, long x, long y,
                             int ctrl_key, int shift_key) {
    if (this->active == 0)
        return 0;

    if (this->mouse_captured == 0) {
        if (this->is_inside(x, y) == 0)
            return 0;

        for (PanelNode* node = this->last_child_node; node != 0; node = node->prev_node) {
            long result = node->panel->handle_mouse_up(mouse_button_in, x, y, ctrl_key, shift_key);
            if (result != 0)
                return result;
        }
    } else {
        if (this->handle_mouse_input == 0)
            return 0;

        long result;
        if (this->mouse_down_button == 1)
            result = this->mouse_left_up_action(x, y, ctrl_key, shift_key);
        else
            result = this->mouse_right_up_action(x, y, ctrl_key, shift_key);

        if (result != 0)
            return 0;

        if (mouse_button_in == this->mouse_down_button) {
            this->mouse_down_button = 0;
            this->mouse_action = 0;
        }

        return 1;
    }

    return 0;
}

long TPanel::handle_mouse_dbl_click(unsigned char mouse_button_in, long x, long y,
                                    int ctrl_key, int shift_key) {
    if (!active)
        return 0;

    if (!mouse_captured) {
        if (!is_inside(x, y))
            return 0;

        for (PanelNode* node = last_child_node; node; node = node->prev_node) {
            long child_result = node->panel->handle_mouse_dbl_click(
                mouse_button_in, x, y, ctrl_key, shift_key);
            if (child_result)
                return child_result;
        }
    }

    if (!handle_mouse_input)
        return 0;

    long result;
    if (mouse_button_in == 1)
        result = mouse_left_dbl_click_action(x, y, ctrl_key, shift_key);
    else
        result = mouse_right_dbl_click_action(x, y, ctrl_key, shift_key);

    if (!result) {
        handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
        return 1;
    }

    return result;
}

long TPanel::action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2) {
    if (parent_panel != 0) {
        return parent_panel->action(from_panel, action_in, action_val1, action_val2);
    }
    return 0;
}

void TPanel::get_mouse_info(unsigned int wParam, long lParam, tagPOINT& point, int& ctrl_key, int& shift_key) {
    int x;
    int y;

    x = ((unsigned int)lParam) & 0xFFFF;
    y = ((unsigned int)lParam) >> 16;
    point.x = x;
    point.y = y;
    if (x > 60000) {
        point.x = x - 0x10000;
    }
    if (y > 60000) {
        point.y = y - 0x10000;
    }
    ctrl_key = wParam & MK_CONTROL;
    shift_key = wParam & MK_SHIFT;
}

void TPanel::get_mouse_pos(tagPOINT& point) {
    GetCursorPos(&point);
    if (render_area->DrawSystem->ScreenMode != 2) {
        ScreenToClient(render_area->Wnd, &point);
        if (point.x > 60000) {
            point.x += -0x10000;
        }
        if (point.y > 60000) {
            point.y += -0x10000;
        }
    }
}

int TPanel::capture_mouse(void) {
    TPanel* owner;

    owner = panel_system.mouseOwner();
    if (owner != 0) {
        owner = panel_system.mouseOwner();
        if (owner != this) {
            return 0;
        }
    }
    if (panel_system.mouseOwner() == this) {
        return 1;
    }
    SetCapture(render_area->Wnd);
    panel_system.setMouseOwner(this);
    mouse_captured = 1;
    return 1;
}

void TPanel::release_mouse(void) {
    if (mouse_captured != 0) {
        if (panel_system.mouseOwner() == this) {
            panel_system.setMouseOwner(0);
            ReleaseCapture();
        }
        mouse_captured = 0;
    }
}

unsigned char TPanel::is_redraw_needed(void) {
    if (render_area != 0 && visible != 0 && active != 0) {
        return need_redraw;
    }
    return 0;
}

int TPanel::is_inside(long x, long y) {
    if (active != 0) {
        if (x >= clip_rect.left) {
            if (x <= clip_rect.right) {
                if (y >= clip_rect.top) {
                    if (y <= clip_rect.bottom) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int TPanel::is_inside_rect(long x, long y, tagRECT* rect) {
    if (x < rect->left || x > rect->right || y < rect->top || y > rect->bottom) {
        return 0;
    }
    return 1;
}

int TPanel::bound_point(long& x, long& y) {
    int bounded;
    long limit;

    bounded = 0;
    limit = clip_rect.left + 1;
    if (x < limit || ((limit = clip_rect.right - 1), x > limit)) {
        x = limit;
        bounded = 1;
    }
    limit = clip_rect.top + 1;
    if (y < limit) {
        y = limit;
        return 1;
    }
    limit = clip_rect.bottom - 1;
    if (y > limit) {
        y = limit;
        bounded = 1;
    }
    return bounded;
}

void TPanel::set_curr_child(TPanel* curr_child_in) {
    TPanel* old_child;

    old_child = curr_child;
    if (curr_child_in != old_child) {
        if (old_child != 0 && have_focus != 0) {
            old_child->set_focus(0);
        }
        curr_child = curr_child_in;
        if (curr_child_in != 0 && have_focus != 0) {
            curr_child_in->set_focus(1);
        }
    }
}

void TPanel::set_focus(int have_focus_in) {
    if (have_focus_in != have_focus) {
        have_focus = have_focus_in;
        set_redraw(TPanel::RedrawNormal);
        if (curr_child != 0) {
            curr_child->set_focus(have_focus);
        }
    }
}

int TPanel::get_focus() {
    return this->have_focus;
}

void TPanel::set_z_order(unsigned char z_order_type, short z_order_in) {
    if (this->parent_panel != 0) {
        this->parent_panel->set_child_z_order(this, z_order_type, z_order_in);
        return;
    }

    switch ((int)z_order_type) {
    case 0:
        this->z_order = z_order_in;
        break;
    case 1:
        this->z_order = 0;
        return;
    case 2:
        this->z_order = 0;
        return;
    }
}

void TPanel::set_child_z_order(TPanel* child_panel, unsigned char z_order_type, short z_order_in) {
    PanelNode* node;
    PanelNode* found_node;
    TPanel* old_curr;

    switch (z_order_type) {
    case 0: {
        PanelNode* start = this->first_child_node;
        int found = 0;
        for (PanelNode* scan = start;
             scan != 0;
             scan = scan->next_node) {
            if (scan->panel->z_order == (int)z_order_in) {
                found = 1;
                break;
            }
        }
        if (found) {
            PanelNode* update = this->first_child_node;
            if (update != 0) {
                int ord = (int)z_order_in;
                do {
                    TPanel* p = update->panel;
                    int z = p->z_order;
                    if (z >= ord) {
                        p->z_order = z + 1;
                    }
                    update = update->next_node;
                } while (update != 0);
            }
        }
        child_panel->z_order = (int)z_order_in;
        break;
    }
    case 1: {
        short v = 0;
        node = this->first_child_node;
        if (node != 0) {
            do {
                TPanel* p = node->panel;
                if (p != child_panel && p->z_order > (int)v) {
                    v = (short)p->z_order;
                }
                node = node->next_node;
            } while (node != 0);
        }
        child_panel->z_order = (int)v + 1;
        break;
    }
    case 2: {
        short v = 0;
        node = this->first_child_node;
        if (node != 0) {
            do {
                TPanel* p = node->panel;
                if (p != child_panel && p->z_order < (int)v) {
                    v = (short)p->z_order;
                }
                node = node->next_node;
            } while (node != 0);
        }
        child_panel->z_order = (int)v - 1;
        break;
    }
    default:
        break;
    }

    node = this->first_child_node;
    old_curr = this->curr_child;
    found_node = 0;
    this->curr_child = 0;
    for (; node != 0; node = node->next_node) {
        if (node->panel == child_panel) {
            found_node = node;
            this->remove_panel_node(node);
            break;
        }
    }

    if (found_node != 0) {
        int inserted = 0;
        node = this->first_child_node;
        for (; node != 0; node = node->next_node) {
            if (node->panel->z_order > child_panel->z_order) {
                this->add_panel_node(found_node, node, 0);
                inserted = 1;
                break;
            }
        }
        if (!inserted) {
            this->add_panel_node(found_node, this->last_child_node, 1);
        }
    }
    this->curr_child = old_curr;
}

void TPanel::set_tab_order(TPanel** panel_list, short panel_count) {
    int i;
    int total;

    total = (int)panel_count;
    i = 0;
    if (0 < total) {
        do {
            TPanel* prev;
            TPanel* next;

            if (i == 0) {
                prev = panel_list[total - 1];
            } else {
                prev = panel_list[i - 1];
            }
            if (i == total - 1) {
                next = panel_list[0];
            } else {
                next = panel_list[i + 1];
            }
            panel_list[i]->set_tab_order(prev, next);
            i++;
        } while (i < total);
    }
}

void TPanel::set_tab_order(TPanel* prev_panel, TPanel* next_panel) {
    tab_prev_panel = prev_panel;
    tab_next_panel = next_panel;
    tab_stop = 1;
}

TPanel* TPanel::previousPanel() const {
    return previous_panel;
}

void TPanel::setPreviousPanel(TPanel* p) {
    this->previous_panel = p;
}

TPanel* TPanel::previousModalPanel() const {
    return this->previous_modal_panel;
}

void TPanel::setPreviousModalPanel(TPanel* p) {
    this->previous_modal_panel = p;
}

char* TPanel::panelName() const {
    return this->panel_name;
}

void TPanel::setPanelName(char* v) {
    if (v != 0 && strlen(v) != 0) {
        char* old = panel_name;
        unsigned int name_length;
        if (old == 0) goto alloc;
        name_length = strlen(v);
        if (strlen(old) >= name_length) goto copy;
        if (panel_name == 0) goto alloc;
        free(panel_name);
alloc:
        panel_name = (char*)malloc(strlen(v) + 1);
copy:
        strcpy(panel_name, v);
    } else {
        if (panel_name != 0) {
            free(panel_name);
            panel_name = 0;
        }
    }
}

long TPanel::xPosition() const {
    return this->pnl_x;
}

long TPanel::yPosition() const {
    return this->pnl_y;
}

long TPanel::width() const {
    return this->pnl_wid;
}

long TPanel::height() const {
    return this->pnl_hgt;
}

TDrawArea* TPanel::renderArea() const {
    return this->render_area;
}

tagRECT TPanel::clipRectangle(void) const {
    return clip_rect;
}

void TPanel::setClipRectangle(tagRECT r) {
    this->clip_rect = r;
}

void TPanel::delete_panel(TPanel** panel) {
    if (*panel != 0) {
        delete *panel;
        *panel = 0;
    }
}

int TPanel::get_string(int text_id, char* str, int size) {
    rge_base_game->get_string(text_id, str, size);
    return str[0] != 0;
}

char* TPanel::get_string(int text_id) {
    get_string(text_id, DAT_0062E670, 0x200);
    return DAT_0062E670;
}

long TPanel::get_help_message() {
    return this->help_string_id;
}

long TPanel::get_help_page() {
    return this->help_page_id;
}

void TPanel::set_help_info(long string, long page) {
    this->help_string_id = string;
    this->help_page_id = page;
}

unsigned char TPanel::get_help_info(char*& string, long& page, long x, long y) {
    PanelNode* node;

    if (active == 0) {
        return 0;
    }
    if (is_inside(x, y) == 0) {
        return 0;
    }
    node = last_child_node;
    while (node != 0) {
        if (node->panel->get_help_info(string, page, x, y)) {
            return 1;
        }
        node = node->prev_node;
    }
    if (help_string_id >= 0) {
        strcpy(string, get_string(help_string_id));
        page = help_page_id;
        return 1;
    }
    return 0;
}

void TPanel::stop_sound_system(void) {
    PanelNode* node;

    node = first_child_node;
    while (node != 0) {
        node->panel->stop_sound_system();
        node = node->next_node;
    }
}

int TPanel::restart_sound_system(void) {
    PanelNode* node;
    int ok;

    node = first_child_node;
    ok = 1;
    while (node != 0) {
        if (node->panel->restart_sound_system() == 0) {
            ok = 0;
        }
        node = node->next_node;
    }
    return ok;
}

void TPanel::handle_reactivate(void) {
    PanelNode* node;

    node = first_child_node;
    while (node != 0) {
        node->panel->handle_reactivate();
        node = node->next_node;
    }
}

void TPanel::get_true_render_rect(tagRECT& drawRect) {
    drawRect.left = render_rect.left;
    drawRect.top = render_rect.top;
    drawRect.right = render_rect.right;
    drawRect.bottom = render_rect.bottom;
}
