#include "../include/panel.h"
#include <string.h>
#include <stdio.h>

// 00463BB0 $E1, Panel.cpp lines 31-31.
void $E1(void) {
    panel_system.TPanelSystem::TPanelSystem();
}

// 00463BE0 TPanelSystem, Panel.cpp lines 49-61.
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

// 00463C50 ~TPanelSystem, Panel.cpp lines 66-103.
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

// 00463D00 currentPanel, Panel.cpp lines 108-110.
TPanel* TPanelSystem::currentPanel() const {
    return this->current_panel;
}

// 00463D10 previousPanel, Panel.cpp lines 115-119.
TPanel* TPanelSystem::previousPanel() const {
    if (current_panel)
        return current_panel->previousPanel();
    return 0;
}

// 00463D20 mouseOwner, Panel.cpp lines 124-126.
TPanel* TPanelSystem::mouseOwner() const {
    return this->mouse_owner;
}

// 00463D30 keyboardOwner, Panel.cpp lines 131-133.
TPanel* TPanelSystem::keyboardOwner() const {
    return this->keyboard_owner;
}

// 00463D40 modalPanel, Panel.cpp lines 138-140.
TPanel* TPanelSystem::modalPanel() const {
    return this->modal_panel;
}

// 00463D50 panel, Panel.cpp lines 145-150.
TPanel* TPanelSystem::panel(char* name) {
    PanelNode* node;

    node = findPanelNode(name);
    if (node != 0) {
        return node->panel;
    }
    return 0;
}

// 00463D70 numberActivePanels, Panel.cpp lines 155-157.
int TPanelSystem::numberActivePanels() const {
    return this->number_active_panels;
}

// 00463D80 addPanel, Panel.cpp lines 162-190.
int TPanelSystem::addPanel(TPanel* panel, int make_current, int mode) {
    PanelNode* node;

    node = findPanelNode(panel->panelName());
    if (node == 0) {
        node = (PanelNode*)calloc(1, 0x0C);
        if (node == 0) {
            return 0;
        }
        node->panel = panel;
        panel->setPreviousPanel(0);
        node->prev_node = panel_list->prev_node;
        node->next_node = panel_list;
        panel_list->prev_node = node;
        node->prev_node->next_node = node;
        number_active_panels = number_active_panels + 1;
    }
    if (make_current != 0) {
        setCurrentPanel(panel, mode);
    }
    return 1;
}

// 00463E10 removePanel, Panel.cpp lines 195-217.
int TPanelSystem::removePanel(char* name) {
    PanelNode* node;

    if (name == 0) {
        return 0;
    }
    node = findPanelNode(name);
    if (node == 0) {
        return 0;
    }
    number_active_panels = number_active_panels - 1;
    node->prev_node->next_node = node->next_node;
    node->next_node->prev_node = node->prev_node;
    free(node);
    return 1;
}

// 00463E60 setCurrentPanel, Panel.cpp lines 222-240.
int TPanelSystem::setCurrentPanel(char* name, int mode) {
    PanelNode* node;

    node = findPanelNode(name);
    if (node != 0) {
        if (mouse_owner != 0) {
            mouse_owner->release_mouse();
        }
        modal_panel = 0;
        keyboard_owner = 0;
        setCurrentPanel(node->panel, mode);
        return 1;
    }
    return 0;
}

// 00463EB0 restorePreviousPanel, Panel.cpp lines 245-278.
int TPanelSystem::restorePreviousPanel(int destroy_current) {
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
    if (destroy_current == 0) {
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

// 00463F40 setMouseOwner, Panel.cpp lines 283-285.
void TPanelSystem::setMouseOwner(TPanel* v) {
    this->mouse_owner = v;
}

// 00463F50 setKeyboardOwner, Panel.cpp lines 290-292.
void TPanelSystem::setKeyboardOwner(TPanel* v) {
    this->keyboard_owner = v;
}

// 00463F60 setModalPanel, Panel.cpp lines 297-337.
void TPanelSystem::setModalPanel(TPanel* panel) {
    if (modal_panel != 0 && panel != 0) {
        panel->setPreviousModalPanel(modal_panel);
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
    modal_panel = panel;
    if (panel != 0 && panel != current_panel) {
        TPanel* parent;

        parent = panel->parent_panel;
        if (parent != 0) {
            previous_current_child = parent->curr_child;
            parent->set_curr_child(panel);
            return;
        }
        previous_current_child = 0;
        panel->set_focus(1);
    }
}

// 00463FF0 setCurrentPanelModal, Panel.cpp lines 342-349.
void TPanelSystem::setCurrentPanelModal(void) {
    TPanel* modal;

    modal = modal_panel;
    if (modal != 0 && modal != current_panel) {
        current_panel->setPreviousModalPanel(modal);
    }
    modal_panel = current_panel;
}

// 00464010 restorePreviousModalPanel, Panel.cpp lines 354-371.
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

// 00464060 destroyPanel, Panel.cpp lines 376-404.
int TPanelSystem::destroyPanel(char* name) {
    PanelNode* node;

    if (name == 0) {
        return 0;
    }
    node = findPanelNode(name);
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

// 00464100 inSystem, Panel.cpp lines 409-413.
int TPanelSystem::inSystem(char* name) {
    return findPanelNode(name) != 0;
}

// 00464120 inSystem, Panel.cpp lines 418-422.
int TPanelSystem::inSystem(TPanel* panel) {
    if (panel != 0) {
        if (findPanelNode(panel->panelName()) != 0) {
            return 1;
        }
    }
    return 0;
}

// 00464150 setup, Panel.cpp lines 427-443.
int TPanelSystem::setup(void) {
    panel_list = (PanelNode*)calloc(1, 0x0C);
    if (panel_list == 0) {
        return 0;
    }
    panel_list->panel = 0;
    panel_list->prev_node = panel_list;
    panel_list->next_node = panel_list;
    save_back_color = GetSysColor(5);
    save_text_color = GetSysColor(8);
    saved_colors = 1;
    return 1;
}

// 004641B0 findPanelNode, Panel.cpp lines 448-462.
PanelNode* TPanelSystem::findPanelNode(char* name) {
    TPanelSystem* self;
    char* target;
    PanelNode* node;

    self = this;
    target = name;
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

// 00464260 setCurrentPanel, Panel.cpp lines 467-484.
void TPanelSystem::setCurrentPanel(TPanel* panel, int mode) {
    panel->setPreviousPanel(current_panel);
    if (current_panel != 0) {
        current_panel->set_focus(0);
    }
    current_panel = panel;
    panel->set_focus(1);
    current_panel->set_redraw(TPanel::RedrawImmediate);
    UpdateWindow(AppWnd);
    if (mode != 0) {
        setCurrentPanelModal();
    }
}

// 004642C0 get_palette, Panel.cpp lines 490-532.
void* TPanelSystem::get_palette(char* param_1, long param_2)
{
    char file_name[260];

    if (param_1 == 0) {
        file_name[0] = 0;
    } else {
        if (strchr(param_1, '.') == 0) {
            sprintf(file_name, "%s.pal", param_1);
        } else {
            strcpy(file_name, param_1);
        }
        strupr(file_name);
    }

    int found = -1;
    int i;

    for (i = 0; i < 10; i++) {
        if (this->palette[i] != 0) {
            if ((param_2 != -1 && this->palette_id[i] == param_2) ||
                strcmp(this->palette_file[i], file_name) == 0) {
                this->palette_use_count[i]++;
                return this->palette[i];
            }
        } else if (found == -1) {
            found = i;
        }
    }

    if (found == -1) return 0;

    this->palette[found] = ReadPalette(file_name, param_2, 1);
    if (this->palette[found] == 0) return 0;

    this->palette_use_count[found]++;
    strcpy(this->palette_file[found], file_name);
    this->palette_id[found] = param_2;
    return this->palette[found];
}

// 00464480 release_palette, Panel.cpp lines 538-555.
void TPanelSystem::release_palette(void* target_palette) {
    int i;

    for (i = 0; i < 10; i++) {
        if (palette[i] == target_palette) {
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

// 004644E0 DisableIME, Panel.cpp lines 561-568.
void TPanelSystem::DisableIME(void) {
    if (ImeEnabled != 0) {
        Imc = ImmAssociateContext(AppWnd, 0);
        ImeEnabled = 0;
    }
}

// 00464510 EnableIME, Panel.cpp lines 575-583.
void TPanelSystem::EnableIME(void) {
    if (Imc != 0 && ImeEnabled == 0) {
        ImmAssociateContext(AppWnd, Imc);
    }
}

// 00464540 IsIMEEnabled, Panel.cpp lines 589-591.
int TPanelSystem::IsIMEEnabled() {
    return this->ImeEnabled;
}

// 00464550 TurnIMEOn, Panel.cpp lines 597-610.
void TPanelSystem::TurnIMEOn(void) {
    if (ImeOn == 0 && ImeEnabled != 0 && Imc != 0) {
        ImmSetOpenStatus(Imc, 1);
        ImeOn = 1;
    }
}

// 00464590 TurnIMEOff, Panel.cpp lines 616-629.
void TPanelSystem::TurnIMEOff(void) {
    if (ImeOn != 0 && ImeEnabled != 0 && Imc != 0) {
        ImmSetOpenStatus(Imc, 0);
        ImeOn = 0;
    }
}

// 004645D0 IsIMEOn, Panel.cpp lines 635-637.
int TPanelSystem::IsIMEOn() {
    return this->ImeOn;
}

// 004645E0 GetInputEnabled, Panel.cpp lines 643-645.
int TPanelSystem::GetInputEnabled() {
    return this->InputEnabled;
}

// 004645F0 EnableInput, Panel.cpp lines 651-653.
void TPanelSystem::EnableInput() {
    this->InputEnabled = 1;
}

// 00464600 DisableInput, Panel.cpp lines 659-661.
void TPanelSystem::DisableInput() {
    this->InputEnabled = 0;
}

// 00464610 stop_sound_system, Panel.cpp lines 667-680.
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

// 00464640 restart_sound_system, Panel.cpp lines 686-704.
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

// 00464680 restore_system_colors, Panel.cpp lines 710-725.
void TPanelSystem::restore_system_colors(void) {
    int elems[2];
    unsigned long colors[2];

    if (saved_colors != 0) {
        if (GetSysColor(5) == save_back_color && GetSysColor(8) == save_text_color) {
            return;
        }
        colors[0] = save_back_color;
        elems[0] = 5;
        elems[1] = 8;
        colors[1] = save_text_color;
        SetSysColors(2, elems, colors);
    }
}

// 004646F0 set_restore, Panel.cpp lines 731-739.
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

// 00464720 TPanel, Panel.cpp lines 799-813.
TPanel::TPanel(char* name) {
    previous_panel = 0;
    previous_modal_panel = 0;
    pnl_x = 0;
    pnl_y = 0;
    pnl_wid = 0;
    pnl_hgt = 0;
    panel_name = 0;
    render_area = 0;
    position_mode = 0;
    need_redraw = 2;
    curr_child = 0;
    parent_panel = 0;
    left_panel = 0;
    top_panel = 0;
    right_panel = 0;
    bottom_panel = 0;
    node = 0;
    first_child_node = 0;
    last_child_node = 0;
    tab_prev_panel = 0;
    tab_next_panel = 0;
    mouse_captured = 0;
    active = 1;
    visible = 0;
    tab_stop = 0;
    have_focus = 0;
    have_focus = 0;
    overlapping_children = 1;
    handle_mouse_input = 1;
    just_drawn = 0;
    clip_rgn = 0;
    left_border = 0;
    top_border = 0;
    right_border = 0;
    bottom_border = 0;
    min_wid = 0;
    max_wid = 0;
    min_hgt = 0;
    max_hgt = 0;
    mouse_hold_interval = 250;
    mouse_move_tolerance = 0;
    mouse_down_x = 0;
    mouse_down_y = 0;
    mouse_down_ctrl = 0;
    mouse_down_shift = 0;
    mouse_down_time = 0;
    error_code = 0;
    z_order = 0;
    display_changed_count = 0;
    mouse_action = 0;
    mouse_down_button = 0;
    panel_type = 0;
    color = 0;
    fill_in_background = 0;
    draw_rect2_flag = 0;
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

// 004648B0 TPanel, Panel.cpp lines 872-879.
TPanel::TPanel(void) {
    previous_panel = 0;
    previous_modal_panel = 0;
    pnl_x = 0;
    pnl_y = 0;
    pnl_wid = 0;
    pnl_hgt = 0;
    panel_name = 0;
    render_area = 0;
    position_mode = 0;
    need_redraw = 2;
    curr_child = 0;
    parent_panel = 0;
    left_panel = 0;
    top_panel = 0;
    right_panel = 0;
    bottom_panel = 0;
    node = 0;
    first_child_node = 0;
    last_child_node = 0;
    tab_prev_panel = 0;
    tab_next_panel = 0;
    mouse_captured = 0;
    active = 1;
    visible = 0;
    tab_stop = 0;
    have_focus = 0;
    have_focus = 0;
    overlapping_children = 1;
    handle_mouse_input = 1;
    clip_rgn = 0;
    left_border = 0;
    top_border = 0;
    right_border = 0;
    bottom_border = 0;
    min_wid = 0;
    max_wid = 0;
    min_hgt = 0;
    max_hgt = 0;
    mouse_move_tolerance = 0;
    mouse_down_x = 0;
    mouse_down_y = 0;
    mouse_down_ctrl = 0;
    mouse_down_shift = 0;
    mouse_down_time = 0;
    error_code = 0;
    z_order = 0;
    display_changed_count = 0;
    mouse_action = 0;
    mouse_down_button = 0;
    panel_type = 0;
    color = 0;
    fill_in_background = 0;
    draw_rect2_flag = 0;
    render_rect.left = 0;
    render_rect.top = 0;
    render_rect.right = 0;
    render_rect.bottom = 0;
    mouse_hold_interval = 250;
    help_string_id = -1;
    help_page_id = -1;
}

// 004649E0 ~TPanel, Panel.cpp lines 884-922.
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

// 00464A80 setup, Panel.cpp lines 928-966.
long TPanel::setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, unsigned char value) {
    render_area = area;
    parent_panel = parent;
    if (position_mode == 0) {
        left_border = left;
        top_border = top;
        min_wid = width;
        max_wid = width;
        right_border = 0;
        bottom_border = 0;
        min_hgt = height;
        max_hgt = height;
    }
    if (area != 0) {
        handle_size(area->Width, area->Height);
    } else {
        handle_size(0, 0);
    }
    set_color((unsigned char)value);
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

// 00464B50 add_panel_node, Panel.cpp lines 972-1021.
void TPanel::add_panel_node(PanelNode* node, PanelNode* sibling, int after) {
    if (sibling == 0) {
        sibling = first_child_node;
        if (sibling == 0) {
            node->prev_node = sibling;
            node->next_node = sibling;
            goto done;
        }
        while (sibling->next_node != 0) {
            sibling = sibling->next_node;
        }
        sibling->next_node = node;
        node->prev_node = sibling;
        node->next_node = 0;
        goto done;
    }
    if (after != 0) {
        node->prev_node = sibling;
        node->next_node = sibling->next_node;
        sibling->next_node = node;
        if (node->next_node != 0) {
            node->next_node->prev_node = node;
        }
    } else {
        node->prev_node = sibling->prev_node;
        node->next_node = sibling;
        sibling->prev_node = node;
        if (node->prev_node != 0) {
            node->prev_node->next_node = node;
        }
    }
done:
    if (node->prev_node == 0) {
        first_child_node = node;
    }
    if (node->next_node == 0) {
        last_child_node = node;
    }
}

// 00464BF0 remove_panel_node, Panel.cpp lines 1027-1045.
void TPanel::remove_panel_node(PanelNode* node) {
    if (node == first_child_node) {
        first_child_node = node->next_node;
    }
    if (node == last_child_node) {
        last_child_node = node->prev_node;
    }
    if (node->prev_node != 0) {
        node->prev_node->next_node = node->next_node;
    }
    if (node->next_node != 0) {
        node->next_node->prev_node = node->prev_node;
    }
    node->prev_node = 0;
    node->next_node = 0;
    if (curr_child == node->panel) {
        curr_child = 0;
    }
}

// 00464C50 set_rect, Panel.cpp lines 1051-1112.
void TPanel::set_rect(long left, long top, long width, long height)
{
    pnl_wid = width;
    pnl_hgt = height;
    long right = left + width - 1;
    long bottom = top + height - 1;

    pnl_x = left;
    pnl_y = top;

    render_rect.left = left;
    render_rect.top = top;
    render_rect.right = right;
    render_rect.bottom = bottom;

    clip_rect.left = left;
    clip_rect.top = top;
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

// 00464D70 set_rect, Panel.cpp lines 1118-1120.
void TPanel::set_rect(tagRECT rect) {
    set_rect(rect.left, rect.top, (rect.right - rect.left) + 1, (rect.bottom - rect.top) + 1);
}

// 00464DA0 set_color, Panel.cpp lines 1126-1130.
void TPanel::set_color(unsigned char color) {
    this->color = color;
    if (active != 0) {
        set_redraw(TPanel::RedrawImmediate);
    }
}

// 00464DC0 set_active, Panel.cpp lines 1136-1150.
void TPanel::set_active(int is_active) {
    if (active != is_active) {
        active = is_active;
        if (is_active != 0) {
        set_redraw(TPanel::RedrawNormal);
            return;
        }
        release_mouse();
        if (parent_panel != 0) {
            parent_panel->set_redraw(TPanel::RedrawNormal);
        }
    }
}

// 00464E00 set_positioning, Panel.cpp lines 1158-1183.
void TPanel::set_positioning(TPanel::PositionMode p1, long p2, long p3, long p4,
                             long p5, long p6, long p7, long p8,
                             long p9, TPanel* p10, TPanel* p11,
                             TPanel* p12, TPanel* p13)
{
    position_mode = p1;
    left_border = p2;
    top_border = p3;
    right_border = p4;
    bottom_border = p5;
    min_wid = p6;
    max_wid = p7;
    min_hgt = p8;
    max_hgt = p9;
    left_panel = p10;
    top_panel = p11;
    right_panel = p12;
    bottom_panel = p13;

    if (render_area != 0) {
        handle_size(render_area->Width, render_area->Height);
    } else {
        handle_size(0, 0);
    }

    if (active != 0) {
        set_redraw(TPanel::RedrawImmediate);
    }
}

// 00464EB0 set_fixed_position, Panel.cpp lines 1189-1192.
void TPanel::set_fixed_position(long left, long top, long right, long bottom) {
    set_positioning(TPanel::PositionFixed, left, top, 0, 0, right, right, bottom, bottom, 0, 0, 0, 0);
}

// 00464EE0 set_redraw, Panel.cpp lines 1198-1206.
void TPanel::set_redraw(TPanel::RedrawMode mode) {
    if (mode == 1 && need_redraw == 2) {
        return;
    }
    need_redraw = mode;
    if (mode != 0 && render_area != 0 && visible != 0 && active != 0) {
        InvalidateRect(render_area->Wnd, &clip_rect, 0);
    }
}

// 00464F20 set_overlapped_redraw, Panel.cpp lines 1216-1256.
void TPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, TPanel::RedrawMode param_3)
{
    tagRECT p1_rect = param_1->clip_rect;
    int p1_left = p1_rect.left;
    int p1_top = p1_rect.top;
    int p1_right = p1_rect.right;
    int p1_bottom = p1_rect.bottom;

    PanelNode* node = first_child_node;
    if (node == 0) return;

    do {
        TPanel* panel = node->panel;
        if (panel != param_1 && panel != param_2 && param_1->z_order < panel->z_order) {
            tagRECT n_rect = panel->clip_rect;
            int n_left = n_rect.left;
            int n_top = n_rect.top;
            int n_right = n_rect.right;
            int n_bottom = n_rect.bottom;

            if ((((n_left < p1_left || p1_right < n_left) &&
                  (n_right < p1_left || p1_right < n_right)) &&
                 (p1_left <= n_left || n_right <= p1_right)) ||
                (((n_top < p1_top || p1_bottom < n_top) &&
                  (n_bottom < p1_top || p1_bottom < n_bottom)) &&
                 (p1_top <= n_top || n_bottom <= p1_bottom)))
            {
                if ((((n_left <= p1_left && p1_left <= n_right) ||
                      (n_left <= p1_right && p1_right <= n_right)) ||
                     (p1_left < n_left && n_right < p1_right)) &&
                    (((n_top <= p1_top && p1_top <= n_bottom) ||
                      (n_top <= p1_bottom && p1_bottom <= n_bottom)) ||
                     (p1_top < n_top && n_bottom < p1_bottom)))
                {
                    panel->set_redraw(param_3);
                }
            } else {
                    panel->set_redraw(param_3);
            }
        }
        node = node->next_node;
    } while (node != 0);
}

// 00465050 set_any_overlapping_redraw, Panel.cpp lines 1264-1294.
void TPanel::set_any_overlapping_redraw(TPanel* param_1, TPanel::RedrawMode param_2)
{
    tagRECT this_rect = param_1->clip_rect;
    PanelNode* temp_node = this->first_child_node;

    while (temp_node != 0) {
        TPanel* panel = temp_node->panel;
        if (panel != param_1) {
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
                    panel->set_redraw(param_2);
                }
            } else {
                panel->set_redraw(param_2);
            }
        }
        temp_node = temp_node->next_node;
    }
}

// 00465160 draw, Panel.cpp lines 1300-1320.
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

// 004651C0 draw_rect, Panel.cpp lines 1326-1333.
void TPanel::draw_rect(tagRECT* rect) {
    tagRECT save_rect;

    save_rect = clip_rect;
    clip_rect = *rect;
    draw();
    clip_rect = save_rect;
}

// 00465220 draw_offset, Panel.cpp lines 1339-1352.
void TPanel::draw_offset(long x, long y, tagRECT* rect) {
    tagRECT save_rect;

    pnl_x = pnl_x + x;
    pnl_y = pnl_y + y;
    save_rect = clip_rect;
    clip_rect = *rect;
    draw();
    clip_rect = save_rect;
    pnl_x = pnl_x - x;
    pnl_y = pnl_y - y;
}

// 004652C0 draw_rect2, Panel.cpp lines 1358-1362.
void TPanel::draw_rect2(tagRECT* rect) {
    draw_rect2_flag = 1;
    draw_rect(rect);
    draw_rect2_flag = 0;
}

// 004652F0 draw_offset2, Panel.cpp lines 1368-1372.
void TPanel::draw_offset2(long x, long y, tagRECT* rect) {
    draw_rect2_flag = 1;
    draw_offset(x, y, rect);
    draw_rect2_flag = 0;
}

// 00465320 draw_setup, Panel.cpp lines 1385-1395.
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

// 00465370 draw_finish, Panel.cpp lines 1401-1407.
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

// 004653A0 paint, Panel.cpp lines 1413-1419.
void TPanel::paint(void) {
    if (render_area != 0 && visible != 0 && active != 0) {
        render_area->DrawSystem->Paint(&clip_rect);
        ValidateRect(render_area->Wnd, &clip_rect);
    }
}

// 004653E0 wnd_proc, Panel.cpp lines 1425-1521.
long TPanel::wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    POINT point;
    TPanel* target;
    PanelNode* node;
    long result;

    if (this->active == 0) {
        goto done;
    }

    if (msg <= 0x206) {
        if (msg >= 0x200) {
            goto mouse_input;
        } else if (msg != 0x100 && msg != 0x102 && msg != 0x104) {
            ;
        } else {
            goto keyboard_input;
        }
    }

    node = this->last_child_node;
    while (node != 0) {
        result = node->panel->wnd_proc(hwnd, msg, wParam, lParam);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }

    if (msg <= 0x400) {
        switch (msg) {
        case 0x111:
            return this->handle_command(wParam, lParam);
        case 0x113:
            return this->handle_timer_command(wParam, lParam);
        case 0x114:
        case 0x115:
            return this->handle_scroll(wParam, lParam);
        case 0x400:
            return this->handle_user_command(wParam, lParam);
        }
    }

done:
    return 0;

mouse_input:
{
    int focus_flag;
    int capture_flag;
    if (this->render_area->Wnd != hwnd) {
        goto done;
    }
    if (panel_system.GetInputEnabled() == 0) {
        goto done;
    }

    this->get_mouse_info(wParam, lParam, point, focus_flag, capture_flag);
    target = this;
    if (panel_system.mouseOwner() != 0) {
        target = panel_system.mouseOwner();
    } else if (panel_system.keyboardOwner() != 0) {
        target = panel_system.keyboardOwner();
    } else if (panel_system.modalPanel() != 0) {
        target = panel_system.modalPanel();
    }

    switch (msg) {
    case 0x200:
        return target->handle_mouse_move(point.x, point.y, focus_flag, capture_flag);
    case 0x201:
        return target->handle_mouse_down(1, point.x, point.y, focus_flag, capture_flag);
    case 0x202:
        return target->handle_mouse_up(1, point.x, point.y, focus_flag, capture_flag);
    case 0x203:
        return target->handle_mouse_dbl_click(1, point.x, point.y, focus_flag, capture_flag);
    case 0x204:
        return target->handle_mouse_down(2, point.x, point.y, focus_flag, capture_flag);
    case 0x205:
        return target->handle_mouse_up(2, point.x, point.y, focus_flag, capture_flag);
    case 0x206:
        return target->handle_mouse_dbl_click(2, point.x, point.y, focus_flag, capture_flag);
    }
    goto done;
}

keyboard_input:
{
    int alt;
    int ctrl;
    int shift;
    if (this->render_area->Wnd != hwnd) {
        goto done;
    }
    if (panel_system.GetInputEnabled() == 0) {
        goto done;
    }

    target = this;
    if (panel_system.keyboardOwner() != 0) {
        target = panel_system.keyboardOwner();
    } else if (panel_system.modalPanel() != 0) {
        target = panel_system.modalPanel();
    }

    if (msg == 0x102) {
        return target->handle_char(wParam, (short)lParam);
    }

    alt = GetKeyState(0x12) < 0;
    ctrl = GetKeyState(0x11) < 0;
    shift = GetKeyState(0x10) < 0;
    return target->handle_key_down(wParam, (short)lParam, alt, ctrl, shift);
}
}

// 00465780 handle_idle, Panel.cpp lines 1527-1552.
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

// 00465820 handle_size, Panel.cpp lines 1558-1670.
long TPanel::handle_size(long wid, long hgt)
{
    TPanel* p = this->parent_panel;
    long left;
    long top;
    long right;
    long bottom;
    long calc_hgt;

    if (p != 0) {
        right = p->render_rect.right;
        left = p->render_rect.left;
        top = p->render_rect.top;
        bottom = p->render_rect.bottom;
        wid = right - left + 1;
        hgt = bottom - top + 1;
    } else {
        left = 0;
        top = 0;
        right = wid - 1;
        bottom = hgt - 1;
    }

    if (this->position_mode == PositionFixed) {
        left = this->left_border + left;
        top = this->top_border + top;
        bottom = this->min_hgt + top - 1;
        right = this->min_wid + left - 1;
    } else {
        p = this->left_panel;
        if (p != 0 && p->active != 0) {
            left = this->left_border + p->render_rect.right + 1;
        } else {
            left = this->left_border + left;
        }
        p = this->top_panel;
        if (p != 0 && p->active != 0) {
            top = this->top_border + p->render_rect.bottom + 1;
        } else {
            top = this->top_border + top;
        }
        p = this->right_panel;
        if (p != 0 && p->active != 0) {
            right = p->render_rect.left - this->right_border - 1;
        } else {
            right -= this->right_border;
        }
        p = this->bottom_panel;
        if (p != 0 && p->active != 0) {
            bottom = p->render_rect.top - this->bottom_border - 1;
        } else {
            bottom -= this->bottom_border;
        }

        calc_hgt = bottom - top + 1;
        long limit = this->min_wid;
        if (limit != 0 && right - left + 1 < limit) {
            right = left + limit - 1;
        } else {
            limit = this->max_wid;
            if (limit != 0 && right - left + 1 > limit) {
                if (this->position_mode == PositionLeft || this->position_mode == PositionLeftTop || this->position_mode == PositionLeftBottom) {
                    right = left + limit - 1;
                } else {
                    left = right - limit + 1;
                }
            }
        }
        limit = this->min_hgt;
        if (limit != 0 && calc_hgt < limit) {
            bottom = top + limit - 1;
        } else {
            limit = this->max_hgt;
            if (limit != 0 && calc_hgt > limit) {
                if (this->position_mode == PositionTop || this->position_mode == PositionLeftTop || this->position_mode == PositionRightTop) {
                    bottom = top + limit - 1;
                } else {
                    top = bottom - limit + 1;
                }
            }
        }

        if (this->position_mode == PositionCentered) {
            long real_w = right - left + 1;
            long real_h = bottom - top + 1;
            long xoff;
            if (real_w == wid) {
                xoff = 0;
            } else {
                xoff = wid / 2 - real_w / 2;
            }
            right = real_w + xoff - 1;
            if (real_h == hgt) {
                top = 0;
            } else {
                top = hgt / 2 - real_h / 2;
            }
            bottom = real_h + top - 1;
            left = xoff;
        }
    }

    this->set_rect(left, top, right, bottom);
    int pass = 0;
    do {
        for (PanelNode* node = this->first_child_node; node != 0; node = node->next_node) {
            TPanel* child = node->panel;
            long r = child->handle_size(wid, hgt);
            if (r != 0) {
                return r;
            }
        }
        ++pass;
    } while (pass < 2);
    return 0;
}

// 00465A70 handle_paint, Panel.cpp lines 1676-1700.
long TPanel::handle_paint(void) {
    PanelNode* node = 0;
        TPanel* parent;

    if (render_area != 0 && visible != 0 && active != 0 && rge_base_game->prog_active != 0 && IsIconic(render_area->Wnd) == 0) {
        if (need_redraw != 0) {
            node = first_child_node;
            while (node != 0) {
                node->panel->set_redraw((TPanel::RedrawMode)need_redraw);
                node = node->next_node;
            }
            parent = parent_panel;
            if (parent != 0 && parent->overlapping_children != 0) {
                parent->set_overlapped_redraw(this, this, (TPanel::RedrawMode)need_redraw);
            }
            draw();
            need_redraw = 0;
            just_drawn = 1;
        }
        node = first_child_node;
        while (node != 0) {
            node->panel->handle_paint();
            node = node->next_node;
        }
        just_drawn = 0;
    }
    if (node == 0)
        return 0;
    return (long)node;
}

// 00465B30 handle_key_down, Panel.cpp lines 1706-1746.
long TPanel::handle_key_down(long key, short ch, int a3, int a4, int a5) {
    PanelNode* node;
    long result;
    TPanel* target;

    if (have_focus == 0) {
        return 0;
    }

    node = last_child_node;
    while (node != 0) {
        result = node->panel->handle_key_down(key, ch, a3, a4, a5);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }

    result = key_down_action(key, ch, a3, a4, a5);
    if (result != 0) {
        return result;
    }

    if (a3 == 0 && a4 == 0 && key == 9 && tab_stop != 0 && parent_panel != 0) {
        if (a5 != 0) {
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

// 00465BE0 handle_char, Panel.cpp lines 1752-1768.
long TPanel::handle_char(long key, short ch) {
    PanelNode* node;
    long result;

    if (have_focus == 0) {
        return 0;
    }
    node = last_child_node;
    while (node != 0) {
        result = node->panel->handle_char(key, ch);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }
    return char_action(key, ch);
}

// 00465C30 handle_command, Panel.cpp lines 1774-1776.
long TPanel::handle_command(unsigned int, long) {
    return 0;
}

// 00465C40 handle_user_command, Panel.cpp lines 1783-1785.
long TPanel::handle_user_command(unsigned int, long) {
    return 0;
}

// 00465C50 handle_timer_command, Panel.cpp lines 1792-1794.
long TPanel::handle_timer_command(unsigned int, long) {
    return 0;
}

// 00465C60 handle_scroll, Panel.cpp lines 1800-1802.
long TPanel::handle_scroll(long, long) {
    return 0;
}

// 00465C70 handle_mouse_down, Panel.cpp lines 1808-1851.
long TPanel::handle_mouse_down(unsigned char param_1, long param_2, long param_3, int param_4, int param_5)
{
    if (this->active == 0)
        return 0;

    if (this->mouse_captured == 0) {
        if (this->is_inside(param_2, param_3) == 0)
            return 0;

        for (PanelNode* node = this->last_child_node; node != 0; node = node->prev_node) {
            long result = node->panel->handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
            if (result != 0)
                return result;
        }

        if (this->handle_mouse_input == 0)
            return 0;

        this->mouse_down_button = param_1;
        this->mouse_down_x = param_2;
        this->mouse_down_y = param_3;
        this->mouse_down_ctrl = param_4;
        this->mouse_down_shift = param_5;
        this->mouse_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Panel.cpp", 0x72C);
        this->mouse_action = 1;

        if (this->tab_stop != 0 && this->parent_panel != 0 && this->mouse_down_button == 1) {
            this->parent_panel->set_curr_child(this);
        }
    }

    if (this->handle_mouse_input == 0)
        return 0;

    if (this->mouse_down_button == 1) {
        this->mouse_left_down_action(param_2, param_3, param_4, param_5);
    } else {
        this->mouse_right_down_action(param_2, param_3, param_4, param_5);
    }
    return 1;
}

// 00465DC0 handle_mouse_move, Panel.cpp lines 1857-1913.
long TPanel::handle_mouse_move(long x, long y, int a, int b)
{
    if (this->active == 0) {
        return 0;
    }

    if (this->mouse_captured == 0) {
        if (!this->is_inside(x, y)) {
            return 0;
        }
        PanelNode* node = this->last_child_node;
        while (node != 0) {
            int r = node->panel->handle_mouse_move(x, y, a, b);
            if (r != 0) {
                return r;
            }
            node = node->prev_node;
        }
        if (this->handle_mouse_input == 0) {
            return 0;
        }
        return this->mouse_move_action(x, y, a, b);
    }

    if (this->handle_mouse_input == 0) {
        return 0;
    }

    if (this->mouse_action == 1 || this->mouse_action == 2) {
        if (this->mouse_down_button == 1) {
            if (abs(x - this->mouse_down_x) <= this->mouse_move_tolerance &&
                abs(y - this->mouse_down_y) <= this->mouse_move_tolerance) {
                return 1;
            }
        } else {
            if (abs(x - this->mouse_down_x) <= 10 &&
                abs(y - this->mouse_down_y) <= 10) {
                return 1;
            }
        }
    }

    this->mouse_action = 3;
    if (this->mouse_down_button == 1) {
        this->mouse_left_move_action(x, y, a, b);
        return 1;
    }
    if (this->mouse_down_button == 2) {
        this->mouse_right_move_action(x, y, a, b);
        return 1;
    }
    this->mouse_move_action(x, y, a, b);
    return 1;
}

// 00465F70 handle_mouse_up, Panel.cpp lines 1919-1959.
long TPanel::handle_mouse_up(unsigned char param_1, long param_2, long param_3,
                             int param_4, int param_5)
{
    if (this->active == 0)
        return 0;

    if (this->mouse_captured == 0) {
        if (this->is_inside(param_2, param_3) == 0)
            return 0;

        for (PanelNode* node = this->last_child_node; node != 0; node = node->prev_node) {
            long result = node->panel->handle_mouse_up(param_1, param_2, param_3, param_4, param_5);
            if (result != 0)
                return result;
        }
    } else {
        if (this->handle_mouse_input == 0)
            return 0;

        long result;
        if (this->mouse_down_button == 1)
            result = this->mouse_left_up_action(param_2, param_3, param_4, param_5);
        else
            result = this->mouse_right_up_action(param_2, param_3, param_4, param_5);

        if (result != 0)
            return 0;

        if (param_1 == this->mouse_down_button) {
            this->mouse_down_button = 0;
            this->mouse_action = 0;
        }

        return 1;
    }

    return 0;
}

// 00466060 handle_mouse_dbl_click, Panel.cpp lines 1965-1998.
long TPanel::handle_mouse_dbl_click(unsigned char param_1, long param_2, long param_3,
                                    int param_4, int param_5)
{
    if (!active)
        return 0;

    if (!mouse_captured) {
        if (!is_inside(param_2, param_3))
            return 0;

        for (PanelNode* node = last_child_node; node; node = node->prev_node) {
            long child_result = node->panel->handle_mouse_dbl_click(
                param_1, param_2, param_3, param_4, param_5);
            if (child_result)
                return child_result;
        }
    }

    if (!handle_mouse_input)
        return 0;

    long result;
    if (param_1 == 1)
        result = mouse_left_dbl_click_action(param_2, param_3, param_4, param_5);
    else
        result = mouse_right_dbl_click_action(param_2, param_3, param_4, param_5);

    if (!result) {
        handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
        return 1;
    }

    return result;
}

// 00466140 action, Panel.cpp lines 2004-2008.
long TPanel::action(TPanel* panel, long a2, unsigned long a3, unsigned long a4) {
    if (parent_panel != 0) {
        return parent_panel->action(panel, a2, a3, a4);
    }
    return 0;
}

// 00466170 get_mouse_info, Panel.cpp lines 2014-2026.
void TPanel::get_mouse_info(unsigned int keys, long packed_pos, tagPOINT& pt, int& focus_flag, int& capture_flag) {
    int x;
    int y;

    x = ((unsigned int)packed_pos) & 0xFFFF;
    y = ((unsigned int)packed_pos) >> 16;
    pt.x = x;
    pt.y = y;
    if (x > 60000) {
        pt.x = x - 0x10000;
    }
    if (y > 60000) {
        pt.y = y - 0x10000;
    }
    focus_flag = keys & 8;
    capture_flag = keys & 4;
}

// 004661D0 get_mouse_pos, Panel.cpp lines 2032-2042.
void TPanel::get_mouse_pos(tagPOINT& pt) {
    GetCursorPos(&pt);
    if (render_area->DrawSystem->ScreenMode != 2) {
        ScreenToClient(render_area->Wnd, &pt);
        if (pt.x > 60000) {
            pt.x += -0x10000;
        }
        if (pt.y > 60000) {
            pt.y += -0x10000;
        }
    }
}

// 00466220 capture_mouse, Panel.cpp lines 2048-2060.
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

// 00466280 release_mouse, Panel.cpp lines 2066-2076.
void TPanel::release_mouse(void) {
    if (mouse_captured != 0) {
        if (panel_system.mouseOwner() == this) {
            panel_system.setMouseOwner(0);
            ReleaseCapture();
        }
        mouse_captured = 0;
    }
}

// 004662C0 is_redraw_needed, Panel.cpp lines 2082-2087.
unsigned char TPanel::is_redraw_needed(void) {
    if (render_area != 0 && visible != 0 && active != 0) {
        return need_redraw;
    }
    return 0;
}

// 004662E0 is_inside, Panel.cpp lines 2093-2102.
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

// 00466320 is_inside_rect, Panel.cpp lines 2108-2114.
int TPanel::is_inside_rect(long x, long y, tagRECT* rect) {
    if (x < rect->left || x > rect->right || y < rect->top || y > rect->bottom) {
        return 0;
    }
    return 1;
}

// 00466350 bound_point, Panel.cpp lines 2120-2148.
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

// 004663A0 set_curr_child, Panel.cpp lines 2154-2165.
void TPanel::set_curr_child(TPanel* child) {
    TPanel* old_child;

    old_child = curr_child;
    if (child != old_child) {
        if (old_child != 0 && have_focus != 0) {
        old_child->set_focus(0);
        }
        curr_child = child;
        if (child != 0 && have_focus != 0) {
        child->set_focus(1);
        }
    }
}

// 004663F0 set_focus, Panel.cpp lines 2171-2181.
void TPanel::set_focus(int focus) {
    if (focus != have_focus) {
        have_focus = focus;
        set_redraw(TPanel::RedrawNormal);
        if (curr_child != 0) {
            curr_child->set_focus(have_focus);
        }
    }
}

// 00466420 get_focus, Panel.cpp lines 2187-2189.
int TPanel::get_focus() {
    return this->have_focus;
}

// 00466430 set_z_order, Panel.cpp lines 2195-2216.
void TPanel::set_z_order(unsigned char mode, short order) {
    if (this->parent_panel != 0) {
        this->parent_panel->set_child_z_order(this, mode, order);
        return;
    }

    switch ((int)mode) {
    case 0:
        this->z_order = order;
        break;
    case 1:
        this->z_order = 0;
        return;
    case 2:
        this->z_order = 0;
        return;
    }
}

// 00466490 set_child_z_order, Panel.cpp lines 2222-2322.
void TPanel::set_child_z_order(TPanel* child, unsigned char mode, short order)
{
    PanelNode* node;
    PanelNode* found_node;
    TPanel* old_curr;

    switch (mode) {
    case 0: {
        PanelNode* start = this->first_child_node;
        int found = 0;
        for (PanelNode* scan = start;
             scan != 0;
             scan = scan->next_node) {
            if (scan->panel->z_order == (int)order) {
                found = 1;
                break;
            }
        }
        if (found) {
            PanelNode* update = this->first_child_node;
            if (update != 0) {
                int ord = (int)order;
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
        child->z_order = (int)order;
        break;
    }
    case 1: {
        short v = 0;
        node = this->first_child_node;
        if (node != 0) {
            do {
                TPanel* p = node->panel;
                if (p != child && p->z_order > (int)v) {
                    v = (short)p->z_order;
                }
                node = node->next_node;
            } while (node != 0);
        }
        child->z_order = (int)v + 1;
        break;
    }
    case 2: {
        short v = 0;
        node = this->first_child_node;
        if (node != 0) {
            do {
                TPanel* p = node->panel;
                if (p != child && p->z_order < (int)v) {
                    v = (short)p->z_order;
                }
                node = node->next_node;
            } while (node != 0);
        }
        child->z_order = (int)v - 1;
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
        if (node->panel == child) {
            found_node = node;
            this->remove_panel_node(node);
            break;
        }
    }

    if (found_node != 0) {
        int inserted = 0;
        node = this->first_child_node;
        for (; node != 0; node = node->next_node) {
            if (node->panel->z_order > child->z_order) {
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

// 00466600 set_tab_order, Panel.cpp lines 2328-2347.
void TPanel::set_tab_order(TPanel** panels, short count) {
    int i;
    int total;

    total = (int)count;
    i = 0;
    if (0 < total) {
        do {
            TPanel* prev;
            TPanel* next;

            if (i == 0) {
                prev = panels[total - 1];
            } else {
                prev = panels[i - 1];
            }
            if (i == total - 1) {
                next = panels[0];
            } else {
                next = panels[i + 1];
            }
            panels[i]->set_tab_order(prev, next);
            i++;
        } while (i < total);
    }
}

// 00466650 set_tab_order, Panel.cpp lines 2353-2357.
void TPanel::set_tab_order(TPanel* param1, TPanel* param2) {
    tab_prev_panel = param1;
    tab_next_panel = param2;
    tab_stop = 1;
}

// 00466670 previousPanel, Panel.cpp lines 2363-2365.
TPanel* TPanel::previousPanel() const {
    return previous_panel;
}

// 00466680 setPreviousPanel, Panel.cpp lines 2370-2372.
void TPanel::setPreviousPanel(TPanel* v) {
    this->previous_panel = v;
}

// 00466690 previousModalPanel, Panel.cpp lines 2377-2379.
TPanel* TPanel::previousModalPanel() const {
    return this->previous_modal_panel;
}

// 004666A0 setPreviousModalPanel, Panel.cpp lines 2384-2386.
void TPanel::setPreviousModalPanel(TPanel* v) {
    this->previous_modal_panel = v;
}

// 004666B0 panelName, Panel.cpp lines 2391-2393.
char* TPanel::panelName() const {
    return this->panel_name;
}

// 004666C0 setPanelName, Panel.cpp lines 2398-2413.
void TPanel::setPanelName(char* name) {
    if (name != 0 && strlen(name) != 0) {
        char* old = panel_name;
        if (old == 0) goto alloc;
        if (strlen(old) >= strlen(name)) goto copy;
        if (panel_name == 0) goto alloc;
        free(panel_name);
alloc:
        panel_name = (char*)malloc(strlen(name) + 1);
copy:
        strcpy(panel_name, name);
    } else {
        if (panel_name != 0) {
            free(panel_name);
            panel_name = 0;
        }
    }
}

// 00466770 xPosition, Panel.cpp lines 2418-2420.
long TPanel::xPosition() const {
    return this->pnl_x;
}

// 00466780 yPosition, Panel.cpp lines 2425-2427.
long TPanel::yPosition() const {
    return this->pnl_y;
}

// 00466790 width, Panel.cpp lines 2432-2434.
long TPanel::width() const {
    return this->pnl_wid;
}

// 004667A0 height, Panel.cpp lines 2439-2441.
long TPanel::height() const {
    return this->pnl_hgt;
}

// 004667B0 renderArea, Panel.cpp lines 2446-2448.
TDrawArea* TPanel::renderArea() const {
    return this->render_area;
}

// 004667C0 clipRectangle, Panel.cpp lines 2453-2455.
tagRECT TPanel::clipRectangle(void) const {
    return clip_rect;
}

// 004667F0 setClipRectangle, Panel.cpp lines 2460-2462.
void TPanel::setClipRectangle(tagRECT rect) {
    this->clip_rect = rect;
}

// 00466820 delete_panel, Panel.cpp lines 2468-2474.
void TPanel::delete_panel(TPanel** panel) {
    if (*panel != 0) {
    delete *panel;
        *panel = 0;
    }
}

// 00466840 get_string, Panel.cpp lines 2480-2493.
int TPanel::get_string(int string_id, char* buffer, int length) {
    rge_base_game->get_string(string_id, buffer, length);
    return buffer[0] != 0;
}

// 00466870 get_string, Panel.cpp lines 2499-2502.
char* TPanel::get_string(int string_id) {
    get_string(string_id, DAT_0062E670, 0x200);
    return DAT_0062E670;
}

// 00466890 get_help_message, Panel.cpp lines 2508-2510.
long TPanel::get_help_message() {
    return this->help_string_id;
}

// 004668A0 get_help_page, Panel.cpp lines 2516-2518.
long TPanel::get_help_page() {
    return this->help_page_id;
}

// 004668B0 set_help_info, Panel.cpp lines 2524-2527.
void TPanel::set_help_info(long a, long b) {
    this->help_string_id = a;
    this->help_page_id = b;
}

// 004668D0 get_help_info, Panel.cpp lines 2533-2555.
unsigned char TPanel::get_help_info(char*& out_str, long& out_page, long x, long y) {
    PanelNode* node;

    if (active == 0) {
        return 0;
    }
    if (is_inside(x, y) == 0) {
        return 0;
    }
    node = last_child_node;
    while (node != 0) {
        if (node->panel->get_help_info(out_str, out_page, x, y)) {
            return 1;
        }
        node = node->prev_node;
    }
    if (help_string_id >= 0) {
        strcpy(out_str, get_string(help_string_id));
        out_page = help_page_id;
        return 1;
    }
    return 0;
}

// 00466980 stop_sound_system, Panel.cpp lines 2561-2569.
void TPanel::stop_sound_system(void) {
    PanelNode* node;

    node = first_child_node;
    while (node != 0) {
        node->panel->stop_sound_system();
        node = node->next_node;
    }
}

// 004669A0 restart_sound_system, Panel.cpp lines 2575-2589.
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

// 004669D0 handle_reactivate, Panel.cpp lines 2595-2598.
void TPanel::handle_reactivate(void) {
    PanelNode* node;

    node = first_child_node;
    while (node != 0) {
        node->panel->handle_reactivate();
        node = node->next_node;
    }
}

// 004669F0 get_true_render_rect, Panel.cpp lines 2605-2612.
void TPanel::get_true_render_rect(tagRECT& rect) {
    rect.left = render_rect.left;
    rect.top = render_rect.top;
    rect.right = render_rect.right;
    rect.bottom = render_rect.bottom;
}
