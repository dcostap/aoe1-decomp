#include "../include/ui_core.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"
#include <string.h>

extern RGE_Base_Game* rge_base_game;

// Source of truth: panel.cpp.decomp @ 0x00465746
static long panel_abs_long(long value) {
    return (value < 0) ? -value : value;
}

// Source of truth: panel.cpp.decomp @ 0x00466170
static void panel_get_mouse_info(uint wparam, long lparam, long* out_x, long* out_y, int* out_ctrl, int* out_shift) {
    if (out_x) {
        uint ux = (uint)lparam & 0xFFFFu;
        long x = (long)ux;
        if (ux > 60000u) {
            x = (long)(ux - 0x10000u);
        }
        *out_x = x;
    }
    if (out_y) {
        uint uy = ((uint)lparam >> 16) & 0xFFFFu;
        long y = (long)uy;
        if (uy > 60000u) {
            y = (long)(uy - 0x10000u);
        }
        *out_y = y;
    }
    if (out_ctrl) {
        *out_ctrl = (int)(wparam & 0x8u);
    }
    if (out_shift) {
        *out_shift = (int)(wparam & 0x4u);
    }
}

// Source of truth: panel.cpp.decomp @ 0x00464B50
static void panel_add_node(TPanel* owner, PanelNode* node, PanelNode* anchor, int add_after) {
    if (!owner || !node) {
        return;
    }

    if (anchor == nullptr) {
        PanelNode* tail = owner->first_child_node;
        if (tail == nullptr) {
            node->prev_node = nullptr;
            node->next_node = nullptr;
        } else {
            for (PanelNode* next = tail->next_node; next != nullptr; next = next->next_node) {
                tail = next;
            }
            tail->next_node = node;
            node->prev_node = tail;
            node->next_node = nullptr;
        }
    } else if (add_after == 0) {
        PanelNode* prev = anchor->prev_node;
        node->next_node = anchor;
        node->prev_node = prev;
        anchor->prev_node = node;
        if (node->prev_node != nullptr) {
            node->prev_node->next_node = node;
        }
    } else {
        node->prev_node = anchor;
        node->next_node = anchor->next_node;
        anchor->next_node = node;
        if (node->next_node != nullptr) {
            node->next_node->prev_node = node;
        }
    }

    if (node->prev_node == nullptr) {
        owner->first_child_node = node;
    }
    if (node->next_node == nullptr) {
        owner->last_child_node = node;
    }
}

// Source of truth: panel.cpp.decomp @ 0x00464BF0
static void panel_remove_node(TPanel* owner, PanelNode* node) {
    if (!owner || !node) {
        return;
    }

    if (node == owner->first_child_node) {
        owner->first_child_node = node->next_node;
    }
    if (node == owner->last_child_node) {
        owner->last_child_node = node->prev_node;
    }
    if (node->prev_node != nullptr) {
        node->prev_node->next_node = node->next_node;
    }
    if (node->next_node != nullptr) {
        node->next_node->prev_node = node->prev_node;
    }

    node->prev_node = nullptr;
    node->next_node = nullptr;

    if (owner->curr_child == node->panel) {
        owner->curr_child = nullptr;
    }
}

// Source of truth: panel.cpp.decomp @ 0x00466490
static void panel_set_child_z_order(TPanel* owner, TPanel* child, unsigned char mode, short requested_z) {
    if (!owner || !child) {
        return;
    }

    if (mode == '\0') {
        PanelNode* n = owner->first_child_node;
        bool has_requested = false;
        if (n != nullptr) {
            for (PanelNode* it = n; it != nullptr; it = it->next_node) {
                if (it->panel->z_order == (int)requested_z) {
                    has_requested = true;
                    break;
                }
            }
        }

        if (has_requested && n != nullptr) {
            do {
                int z = n->panel->z_order;
                if ((int)requested_z <= z) {
                    n->panel->z_order = z + 1;
                }
                n = n->next_node;
            } while (n != nullptr);
        }

        child->z_order = (int)requested_z;
    } else if (mode == '\x01') {
        short max_z = 0;
        for (PanelNode* n = owner->first_child_node; n != nullptr; n = n->next_node) {
            TPanel* p = n->panel;
            if (p != child && (int)max_z < p->z_order) {
                max_z = (short)p->z_order;
            }
        }
        child->z_order = (int)(max_z + 1);
    } else if (mode == '\x02') {
        short min_z = 0;
        for (PanelNode* n = owner->first_child_node; n != nullptr; n = n->next_node) {
            TPanel* p = n->panel;
            if (p != child && p->z_order < (int)min_z) {
                min_z = (short)p->z_order;
            }
        }
        child->z_order = (int)(min_z - 1);
    }

    PanelNode* found = nullptr;
    TPanel* saved_curr_child = owner->curr_child;
    owner->curr_child = nullptr;

    for (PanelNode* n = owner->first_child_node; n != nullptr; n = n->next_node) {
        if (n->panel == child) {
            panel_remove_node(owner, n);
            found = n;
            break;
        }
    }

    if (found != nullptr) {
        PanelNode* n = owner->first_child_node;
        bool inserted = false;
        if (n != nullptr) {
            do {
                if (child->z_order < n->panel->z_order) {
                    panel_add_node(owner, found, n, 0);
                    inserted = true;
                    break;
                }
                n = n->next_node;
            } while (n != nullptr);
        }
        if (!inserted) {
            panel_add_node(owner, found, owner->last_child_node, 1);
        }
    }

    owner->curr_child = saved_curr_child;
}

// Source of truth: panel.cpp.decomp @ 0x00464720
TPanel::TPanel(char* name) {
    memset((unsigned char*)this + 4, 0, sizeof(TPanel) - 4); // Keep vtable intact; initialize data fields.

    // Source of truth: panel.cpp.decomp @ 0x004648B0
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::TPanel(char*)` / `TPanel::TPanel(void)`).
    this->position_mode = TPanel::PositionMode::Fixed;
    this->need_redraw = TPanel::RedrawMode::RedrawFull;
    this->active = 1;
    this->visible = 0;
    this->overlapping_children = 1;
    this->handle_mouse_input = 1;
    this->mouse_hold_interval = 0xFA;
    this->help_string_id = -1;
    this->help_page_id = -1;

    if (name) this->panelNameValue = strdup(name);
    else this->panelNameValue = nullptr;

    // Source of truth: panel.cpp.decomp @ 0x004648B0
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464720.
    // Named panels are registered with panel_system for name-based lookup and destroyPanel flows.
    // TODO: parity note - original uses a global object (&panel_system); our build uses a pointer global.
    if (this->panelNameValue != nullptr && this->panelNameValue[0] != '\0' && panel_system != nullptr) {
        panel_system->add_panel(this);
    }
}

// Source of truth: panel.cpp.decomp @ 0x004649E0
TPanel::~TPanel() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x004649E0
    this->release_mouse();

    if (panel_system && this->panelNameValue != nullptr) {
        // Fully verified. Source of truth: panel.cpp.decomp @ 0x004649E0
        // Only remove if this panel is still registered in panel_system.
        TPanel* in_system = panel_system->panel(this->panelNameValue);
        if (in_system == this) {
            panel_system->remove_panel(this);
        }
    }

    if (this->node != nullptr) {
        if (this->parent_panel != nullptr) {
            panel_remove_node(this->parent_panel, this->node);
        }
        free(this->node);
        this->node = nullptr;
    }

    this->first_child_node = nullptr;
    this->last_child_node = nullptr;

    if (this->clip_rgn) {
        DeleteObject((HGDIOBJ)this->clip_rgn);
        this->clip_rgn = nullptr;
    }

    if (this->parent_panel != nullptr) {
        this->parent_panel->set_redraw(TPanel::RedrawMode::RedrawFull);
    }

    if (this->panelNameValue != nullptr) {
        free(this->panelNameValue);
        this->panelNameValue = nullptr;
    }
}
long TPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    // Source of truth: panel.cpp.decomp @ 0x00464A80
    this->parent_panel = param_2;
    this->render_area = param_1;

    // Original behavior for PositionFixed: cache border/size constraints from setup args.
    if (this->position_mode == TPanel::PositionMode::Fixed) {
        this->top_border = param_4;
        this->min_wid = param_5;
        this->max_wid = param_5;
        this->left_border = param_3;
        this->right_border = 0;
        this->bottom_border = 0;
        this->min_hgt = param_6;
        this->max_hgt = param_6;
    }

    // Keep current implementation model simple: fixed-position panels still get a concrete rect here.
    // The original setup routes through virtual size/color calls before node-linking.
    this->set_rect(param_3, param_4, param_5, param_6);
    this->set_color(param_7);
    this->mouse_captured = 0;

    // Link to parent once, matching original "allocate node if null" behavior.
    if (!this->node) {
        PanelNode* newNode = (PanelNode*)calloc(1, sizeof(PanelNode));
        if (!newNode) return 0;
        newNode->panel = this;
        newNode->next_node = nullptr;
        newNode->prev_node = nullptr;
        this->node = newNode;

        if (this->parent_panel) {
            newNode->prev_node = this->parent_panel->last_child_node;
            if (this->parent_panel->last_child_node) this->parent_panel->last_child_node->next_node = newNode;
            else this->parent_panel->first_child_node = newNode;
            this->parent_panel->last_child_node = newNode;
        }
    }

    return 1;
}
// Source of truth: panel.cpp.decomp @ 0x00464C50
void TPanel::set_rect(tagRECT param_1) {
    // Source of truth: `src/game/src/panel.cpp.decomp` uses inclusive rects.
    this->set_rect(param_1.left, param_1.top, (param_1.right - param_1.left) + 1, (param_1.bottom - param_1.top) + 1);
}

// Source of truth: panel.cpp.decomp @ 0x00464D70
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

// Source of truth: panel.cpp.decomp @ 0x00464DA0
void TPanel::set_color(uchar param_1) {
    this->color = param_1;
    if (this->active) this->set_redraw(TPanel::RedrawMode::RedrawFull);
}

// Source of truth: panel.cpp.decomp @ 0x00464DC0
void TPanel::set_active(int param_1) {
    if (this->active == param_1) return;

    this->active = param_1;
    if (param_1) {
        this->set_redraw(TPanel::RedrawMode::Redraw);
        return;
    }

    this->release_mouse();
    if (this->parent_panel) this->parent_panel->set_redraw(TPanel::RedrawMode::Redraw);
}
void TPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    // Source of truth: panel.cpp.decomp @ 0x00464E00
    // Source of truth: `panel.cpp.decomp` (`TPanel::set_positioning`).
    this->position_mode = param_1;
    this->right_border = param_4;
    this->max_wid = param_7;
    this->left_border = param_2;
    this->top_border = param_3;
    this->left_panel = param_10;
    this->bottom_border = param_5;
    this->min_wid = param_6;
    this->bottom_panel = param_13;
    this->min_hgt = param_8;
    this->max_hgt = param_9;
    this->top_panel = param_11;
    this->right_panel = param_12;

    long calc_w = 0;
    long calc_h = 0;
    if (this->render_area) {
        calc_w = this->render_area->Width;
        calc_h = this->render_area->Height;
    }

    this->handle_size(calc_w, calc_h);
    if (this->active) {
        this->set_redraw(TPanel::RedrawMode::RedrawFull);
    }
}

void TPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {
    // Source of truth: panel.cpp.decomp @ 0x00464EB0
    // Source of truth: `panel.cpp.decomp` (`TPanel::set_fixed_position`).
    this->set_positioning(
        TPanel::PositionMode::Fixed,
        param_1, param_2, 0, 0,
        param_3, param_3, param_4, param_4,
        nullptr, nullptr, nullptr, nullptr);
}
// Source of truth: panel.cpp.decomp @ 0x00464EE0
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
void TPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464F20
    // Redraw any higher-z siblings that overlap the invalidated panel rect.
    const long this_left = param_1->clip_rect.left;
    const long this_top = param_1->clip_rect.top;
    const long this_right = param_1->clip_rect.right;
    const long this_bottom = param_1->clip_rect.bottom;

    for (PanelNode* node = this->first_child_node; node != nullptr; node = node->next_node) {
        TPanel* panel = node->panel;
        if (panel == param_1 || panel == param_2) {
            continue;
        }

        if (param_1->z_order >= panel->z_order) {
            continue;
        }

        const long p_left = panel->clip_rect.left;
        const long p_top = panel->clip_rect.top;
        const long p_right = panel->clip_rect.right;
        const long p_bottom = panel->clip_rect.bottom;

        const int x_overlap =
            (((p_left <= this_left) && (this_left <= p_right)) ||
             ((p_left <= this_right) && (this_right <= p_right)) ||
             ((this_left < p_left) && (p_right < this_right)));

        const int y_overlap =
            (((p_top <= this_top) && (this_top <= p_bottom)) ||
             ((p_top <= this_bottom) && (this_bottom <= p_bottom)) ||
             ((this_top < p_top) && (p_bottom < this_bottom)));

        if (x_overlap && y_overlap) {
            panel->set_redraw(param_3);
        }
    }
}

// Source of truth: panel.cpp.decomp @ 0x00465050
void TPanel::set_any_overlapping_redraw(TPanel* param_1, RedrawMode param_2) {
    if (param_1 == nullptr) {
        return;
    }

    const long this_left = param_1->clip_rect.left;
    const long this_top = param_1->clip_rect.top;
    const long this_right = param_1->clip_rect.right;
    const long this_bottom = param_1->clip_rect.bottom;

    for (PanelNode* curr = this->first_child_node; curr != nullptr; curr = curr->next_node) {
        TPanel* panel = curr->panel;
        if (panel == param_1) {
            continue;
        }

        const long p_left = panel->clip_rect.left;
        const long p_top = panel->clip_rect.top;
        const long p_right = panel->clip_rect.right;
        const long p_bottom = panel->clip_rect.bottom;

        const int x_overlap =
            (((p_left <= this_left) && (this_left <= p_right)) ||
             ((p_left <= this_right) && (this_right <= p_right)) ||
             ((this_left < p_left) && (p_right < this_right)));
        const int y_overlap =
            (((p_top <= this_top) && (this_top <= p_bottom)) ||
             ((p_top <= this_bottom) && (this_bottom <= p_bottom)) ||
             ((this_top < p_top) && (p_bottom < this_bottom)));

        if (x_overlap && y_overlap) {
            panel->set_redraw(param_2);
        }
    }
}
// Source of truth: panel.cpp.decomp @ 0x00465320
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

// Source of truth: panel.cpp.decomp @ 0x00465370
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
// Source of truth: panel.cpp.decomp @ 0x00465160
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
// Source of truth: panel.cpp.decomp @ 0x004651C0
void TPanel::draw_rect(tagRECT* param_1) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw_rect`).
    if (!param_1) return;
    tagRECT save = this->clip_rect;
    this->clip_rect = *param_1;
    this->draw();
    this->clip_rect = save;
}

// Source of truth: panel.cpp.decomp @ 0x00465220
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

// Source of truth: panel.cpp.decomp @ 0x004652C0
void TPanel::draw_rect2(tagRECT* param_1) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw_rect2`).
    this->draw_rect2_flag = 1;
    this->draw_rect(param_1);
    this->draw_rect2_flag = 0;
}

// Source of truth: panel.cpp.decomp @ 0x004652F0
void TPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::draw_offset2`).
    this->draw_rect2_flag = 1;
    this->draw_offset(param_1, param_2, param_3);
    this->draw_rect2_flag = 0;
}

// Source of truth: panel.cpp.decomp @ 0x004653A0
void TPanel::paint() {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::paint`).
    if (!this->render_area || !this->visible || !this->active) return;
    if (this->render_area->DrawSystem) {
        this->render_area->DrawSystem->Paint((tagRECT*)&this->clip_rect);
    }
    if (this->render_area->Wnd) {
        ValidateRect((HWND)this->render_area->Wnd, (RECT*)&this->clip_rect);
    }
}
// Source of truth: panel.cpp.decomp @ 0x004653E0
long TPanel::wnd_proc(void* hwnd, uint msg, uint wparam, long lparam) {
    // Source of truth: `src/game/src/panel.cpp.decomp` (`TPanel::wnd_proc` @ 0x004653E0).
    if (!this->active) {
        return 0;
    }

    if (msg < 0x207) {
        if (msg >= 0x200) {
            // Mouse path: WM_MOUSEMOVE..WM_RBUTTONDBLCLK
            if (!this->render_area || hwnd != this->render_area->Wnd) {
                return 0;
            }
            if (!panel_system || panel_system->InputEnabled == 0) {
                return 0;
            }

            long x = 0;
            long y = 0;
            int ctrl = 0;
            int shift = 0;
            panel_get_mouse_info(wparam, lparam, &x, &y, &ctrl, &shift);

            TPanel* target = this;
            if (panel_system->mouseOwnerValue != nullptr) {
                target = panel_system->mouseOwnerValue;
            } else if (panel_system->keyboardOwnerValue != nullptr) {
                target = panel_system->keyboardOwnerValue;
            } else if (panel_system->modalPanelValue != nullptr) {
                target = panel_system->modalPanelValue;
            }

            switch (msg) {
            case WM_MOUSEMOVE:
                return target->handle_mouse_move(x, y, ctrl, shift);
            case WM_LBUTTONDOWN:
                return target->handle_mouse_down(1, x, y, ctrl, shift);
            case WM_LBUTTONUP:
                return target->handle_mouse_up(1, x, y, ctrl, shift);
            case WM_LBUTTONDBLCLK:
                return target->handle_mouse_dbl_click(1, x, y, ctrl, shift);
            case WM_RBUTTONDOWN:
                return target->handle_mouse_down(2, x, y, ctrl, shift);
            case WM_RBUTTONUP:
                return target->handle_mouse_up(2, x, y, ctrl, shift);
            case WM_RBUTTONDBLCLK:
                return target->handle_mouse_dbl_click(2, x, y, ctrl, shift);
            default:
                break;
            }
        } else {
            // Keyboard path: WM_KEYDOWN / WM_CHAR / WM_SYSKEYDOWN
            if ((msg == WM_KEYDOWN || msg == WM_CHAR || msg == WM_SYSKEYDOWN) &&
                this->render_area && hwnd == this->render_area->Wnd &&
                panel_system && panel_system->InputEnabled != 0) {
                TPanel* target = this;
                if (panel_system->keyboardOwnerValue != nullptr) {
                    target = panel_system->keyboardOwnerValue;
                } else if (panel_system->modalPanelValue != nullptr) {
                    target = panel_system->modalPanelValue;
                }

                if (msg == WM_CHAR) {
                    return target->handle_char((long)wparam, (short)lparam);
                }

                short alt_down = GetKeyState(VK_MENU);
                short ctrl_down = GetKeyState(VK_CONTROL);
                short shift_down = GetKeyState(VK_SHIFT);
                return target->handle_key_down((long)wparam, (short)lparam,
                                               (alt_down < 0) ? 1 : 0,
                                               (ctrl_down < 0) ? 1 : 0,
                                               (shift_down < 0) ? 1 : 0);
            }
        }
    }

    // Non-input messages: children first (reverse z-order), then this panel.
    for (PanelNode* curr = this->last_child_node; curr != nullptr; curr = curr->prev_node) {
        long child_res = curr->panel->wnd_proc(hwnd, msg, wparam, lparam);
        if (child_res != 0) {
            return child_res;
        }
    }

    if (msg < 0x401) {
        if (msg == WM_USER) {
            return this->handle_user_command(wparam, lparam);
        }
        switch (msg) {
        case WM_COMMAND:
            return this->handle_command(wparam, lparam);
        case WM_TIMER:
            return this->handle_timer_command(wparam, lparam);
        case WM_HSCROLL:
        case WM_VSCROLL:
            return this->handle_scroll((long)(wparam & 0xFFFFu), (long)((wparam >> 16) & 0xFFFFu));
        default:
            break;
        }
    }

    return 0;
}

long TPanel::handle_mouse_move(long x, long y, int wparam, int param_4) {
    // Source of truth: panel.cpp.decomp @ 0x00465DC0
    if (!this->active) {
        return 0;
    }

    if (!this->mouse_captured) {
        if (!this->is_inside(x, y)) {
            return 0;
        }

        for (PanelNode* curr = this->last_child_node; curr; curr = curr->prev_node) {
            long child_res = curr->panel->handle_mouse_move(x, y, wparam, param_4);
            if (child_res != 0) {
                return child_res;
            }
        }

        if (!this->handle_mouse_input) {
            return 0;
        }

        return this->mouse_move_action(x, y, wparam, param_4);
    }

    if (!this->handle_mouse_input) {
        return 0;
    }

    if (this->mouse_action == 1 || this->mouse_action == 2) {
        if (this->mouse_down_button == 1) {
            if (panel_abs_long(x - this->mouse_down_x) <= this->mouse_move_tolerance &&
                panel_abs_long(y - this->mouse_down_y) <= this->mouse_move_tolerance) {
                return 1;
            }
        } else {
            if (panel_abs_long(x - this->mouse_down_x) <= 10 &&
                panel_abs_long(y - this->mouse_down_y) <= 10) {
                return 1;
            }
        }
    }

    this->mouse_action = 3;

    if (this->mouse_down_button == 1) {
        this->mouse_left_move_action(x, y, wparam, param_4);
        return 1;
    }

    if (this->mouse_down_button == 2) {
        this->mouse_right_move_action(x, y, wparam, param_4);
        return 1;
    }

    this->mouse_move_action(x, y, wparam, param_4);
    return 1;
}

long TPanel::handle_mouse_down(uchar button, long x, long y, int wparam, int param_5) {
    // Source of truth: panel.cpp.decomp @ 0x00465C70
    if (!this->active) {
        return 0;
    }

    if (!this->mouse_captured) {
        if (!this->is_inside(x, y)) {
            return 0;
        }

        for (PanelNode* curr = this->last_child_node; curr; curr = curr->prev_node) {
            long child_res = curr->panel->handle_mouse_down(button, x, y, wparam, param_5);
            if (child_res != 0) {
                return child_res;
            }
        }

        if (!this->handle_mouse_input) {
            return 0;
        }

        this->mouse_down_button = button;
        this->mouse_down_x = x;
        this->mouse_down_y = y;
        this->mouse_down_ctrl = wparam;
        this->mouse_down_shift = param_5;
        this->mouse_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Panel.cpp", 0x72c);
        this->mouse_action = 1;

        if (this->tab_stop && this->parent_panel && this->mouse_down_button == 1) {
            this->parent_panel->set_curr_child(this);
        }
    }

    if (!this->handle_mouse_input) {
        return 0;
    }

    if (this->mouse_down_button == 1) {
        this->mouse_left_down_action(x, y, wparam, param_5);
    } else {
        this->mouse_right_down_action(x, y, wparam, param_5);
    }
    return 1;
}

long TPanel::handle_mouse_up(uchar button, long x, long y, int wparam, int param_5) {
    // Source of truth: panel.cpp.decomp @ 0x00465F70
    if (!this->active) {
        return 0;
    }

    if (!this->mouse_captured) {
        if (!this->is_inside(x, y)) {
            return 0;
        }

        for (PanelNode* curr = this->last_child_node; curr; curr = curr->prev_node) {
            long child_res = curr->panel->handle_mouse_up(button, x, y, wparam, param_5);
            if (child_res != 0) {
                return child_res;
            }
        }

        return 0;
    }

    if (!this->handle_mouse_input) {
        return 0;
    }

    long action_res;
    if (this->mouse_down_button == 1) {
        action_res = this->mouse_left_up_action(x, y, wparam, param_5);
    } else {
        action_res = this->mouse_right_up_action(x, y, wparam, param_5);
    }

    if (action_res != 0) {
        return 0;
    }

    if (button == this->mouse_down_button) {
        this->mouse_down_button = 0;
        this->mouse_action = 0;
    }

    return 1;
}

// Source of truth: panel.cpp.decomp @ 0x00465780
long TPanel::handle_idle() {
    // Source of truth: `panel.cpp.decomp` (`TPanel::handle_idle`).
    // We keep the original hold-transition behavior because button/list panels depend on it.
    if (this->active && this->mouse_action == 1) {
        ulong now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Panel.cpp", 0x5fd);
        if (this->mouse_hold_interval <= (long)(now - this->mouse_down_time)) {
            this->mouse_action = 2;
            if (this->mouse_down_button == 1) {
                this->mouse_left_hold_action(this->mouse_down_x, this->mouse_down_y, this->mouse_down_ctrl, this->mouse_down_shift);
            } else {
                this->mouse_right_hold_action(this->mouse_down_x, this->mouse_down_y, this->mouse_down_ctrl, this->mouse_down_shift);
            }
        }
    }

    for (PanelNode* curr = this->last_child_node; curr; curr = curr->prev_node) {
        long child_res = curr->panel->handle_idle();
        if (child_res != 0) {
            return child_res;
        }
    }

    return 0;
}
// Source of truth: panel.cpp.decomp @ 0x00465820
long TPanel::handle_size(long param_1, long param_2) {
    // Source of truth: `panel.cpp.asm/.decomp` (`TPanel::handle_size`).
    // Numeric mode values used by the original layout logic:
    //   0 = fixed, 2 = centered, 3/7/8 = left-anchored width clamp, 4/7/9 = top-anchored height clamp.
    const int MODE_FIXED = 0;
    const int MODE_CENTERED = 2;
    const int MODE_LEFT = 3;
    const int MODE_TOP = 4;
    const int MODE_LEFT_TOP = 7;
    const int MODE_LEFT_BOTTOM = 8;
    const int MODE_RIGHT_TOP = 9;

    long parent_left;
    long parent_top;
    long right;
    long bottom;

    if (this->parent_panel) {
        parent_left = this->parent_panel->render_rect.left;
        parent_top = this->parent_panel->render_rect.top;
        right = this->parent_panel->render_rect.right;
        bottom = this->parent_panel->render_rect.bottom;
        param_1 = (right - parent_left) + 1;
        param_2 = (bottom - parent_top) + 1;
    } else {
        parent_left = 0;
        parent_top = 0;
        right = param_1 - 1;
        bottom = param_2 - 1;
    }

    long calc_x = 0;
    long calc_y = 0;
    long calc_bottom_span = 0;

    if ((int)this->position_mode == MODE_FIXED) {
        calc_bottom_span = this->min_hgt;
        calc_x = this->left_border + parent_left;
        calc_y = this->top_border + parent_top;
        right = calc_x + this->min_wid - 1;
    } else {
        if (this->left_panel && this->left_panel->active) {
            calc_x = this->left_border + this->left_panel->render_rect.right + 1;
        } else {
            calc_x = this->left_border + parent_left;
        }

        if (this->top_panel && this->top_panel->active) {
            calc_y = this->top_border + this->top_panel->render_rect.bottom + 1;
        } else {
            calc_y = this->top_border + parent_top;
        }

        if (this->right_panel && this->right_panel->active) {
            right = this->right_panel->render_rect.left - this->right_border - 1;
        } else {
            right -= this->right_border;
        }

        if (this->bottom_panel && this->bottom_panel->active) {
            bottom = this->bottom_panel->render_rect.top - this->bottom_border - 1;
        } else {
            bottom -= this->bottom_border;
        }

        long calc_w = (right - calc_x) + 1;
        long calc_h = (bottom - calc_y) + 1;
        calc_bottom_span = calc_h;

        if (this->min_wid != 0 && calc_w < this->min_wid) {
            right = calc_x + this->min_wid - 1;
        } else if (this->max_wid != 0 && calc_w > this->max_wid) {
            const int pm = (int)this->position_mode;
            if (pm == MODE_LEFT || pm == MODE_LEFT_TOP || pm == MODE_LEFT_BOTTOM) {
                right = calc_x + this->max_wid - 1;
            } else {
                calc_x = right - this->max_wid + 1;
            }
        }

        if (this->min_hgt != 0 && calc_h < this->min_hgt) {
            bottom = calc_y + this->min_hgt - 1;
            calc_bottom_span = this->min_hgt;
        } else if (this->max_hgt != 0 && calc_h > this->max_hgt) {
            const int pm = (int)this->position_mode;
            if (pm == MODE_TOP || pm == MODE_LEFT_TOP || pm == MODE_RIGHT_TOP) {
                bottom = calc_y + this->max_hgt - 1;
            } else {
                calc_y = bottom - this->max_hgt + 1;
            }
            calc_bottom_span = this->max_hgt;
        }

        if ((int)this->position_mode == MODE_CENTERED) {
            long width = (right - calc_x) + 1;
            long height = (bottom - calc_y) + 1;
            calc_bottom_span = height;

            if (width == param_1) {
                calc_x = 0;
            } else {
                calc_x = (param_1 / 2) - (width / 2);
            }
            right = calc_x + width - 1;

            if (height == param_2) {
                calc_y = 0;
            } else {
                calc_y = (param_2 / 2) - (height / 2);
            }
        }
    }

    bottom = calc_y + calc_bottom_span - 1;

    tagRECT rect;
    rect.left = calc_x;
    rect.top = calc_y;
    rect.right = right;
    rect.bottom = bottom;
    this->set_rect(rect);

    // Original code runs child layout passes twice.
    for (int pass = 0; pass < 2; ++pass) {
        for (PanelNode* n = this->first_child_node; n; n = n->next_node) {
            long rc = n->panel->handle_size(param_1, param_2);
            if (rc != 0) {
                return rc;
            }
        }
    }

    return 0;
}
// Source of truth: panel.cpp.decomp @ 0x00465A70
long TPanel::handle_paint() {
    // Source of truth: panel.cpp.decomp @ 0x00465A70 (TPanel::handle_paint).
    if (((this->render_area != nullptr) && (this->visible != 0)) && (this->active != 0)) {
        if (rge_base_game->prog_active != 0 && IsIconic((HWND)this->render_area->Wnd) == 0) {
            if (this->need_redraw != NoRedraw) {
                for (PanelNode* n = this->first_child_node; n != nullptr; n = n->next_node) {
                    n->panel->set_redraw(this->need_redraw);
                }

                TPanel* parent = this->parent_panel;
                if (parent != nullptr && parent->overlapping_children != 0) {
                    parent->set_overlapped_redraw(this, this, this->need_redraw);
                }

                this->draw();
                this->need_redraw = NoRedraw;
                this->just_drawn = 1;
            }

            for (PanelNode* n = this->first_child_node; n != nullptr; n = n->next_node) {
                n->panel->handle_paint();
            }

            this->just_drawn = 0;
        }
    }
    return 0;
}
long TPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // Source of truth: panel.cpp.decomp @ 0x00465B30
    if (this->curr_child && this->curr_child->active && this->curr_child->visible) {
        if (this->curr_child->handle_key_down(param_1, param_2, param_3, param_4, param_5)) {
            return 1;
        }
    }
    return this->key_down_action(param_1, param_2, param_3, param_4, param_5);
}
// Source of truth: panel.cpp.decomp @ 0x00465BE0
long TPanel::handle_char(long param_1, short param_2) {
    if (this->curr_child && this->curr_child->active && this->curr_child->visible) {
        if (this->curr_child->handle_char(param_1, param_2)) {
            return 1;
        }
    }
    return this->char_action(param_1, param_2);
}
// Source of truth: panel.cpp.decomp @ 0x00465C30
long TPanel::handle_command(uint param_1, long param_2) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00465C40
long TPanel::handle_user_command(uint param_1, long param_2) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00465C50
long TPanel::handle_timer_command(uint param_1, long param_2) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00465C60
long TPanel::handle_scroll(long param_1, long param_2) { return 0; }
long TPanel::handle_mouse_dbl_click(uchar button, long x, long y, int wparam, int param_5) {
    // Source of truth: panel.cpp.decomp @ 0x00466060
    if (!this->active) {
        return 0;
    }

    if (!this->mouse_captured) {
        if (!this->is_inside(x, y)) {
            return 0;
        }

        for (PanelNode* curr = this->last_child_node; curr; curr = curr->prev_node) {
            long child_res = curr->panel->handle_mouse_dbl_click(button, x, y, wparam, param_5);
            if (child_res != 0) {
                return child_res;
            }
        }
    }

    if (!this->handle_mouse_input) {
        return 0;
    }

    long action_res;
    if (button == 1) {
        action_res = this->mouse_left_dbl_click_action(x, y, wparam, param_5);
    } else {
        action_res = this->mouse_right_dbl_click_action(x, y, wparam, param_5);
    }

    // Original fallback: if dbl-click action does nothing, run normal mouse-down path.
    if (action_res == 0) {
        this->handle_mouse_down(button, x, y, wparam, param_5);
        return 1;
    }

    return action_res;
}

// Source of truth: panel.cpp.decomp @ 0x00437110
long TPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00437230
long TPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00437240
long TPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00437250
long TPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00437260
long TPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00437270
long TPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00437280
long TPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00437290
long TPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x004372A0
long TPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x004372B0
long TPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x00437490
long TPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x004374A0
long TPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
// Source of truth: panel.cpp.decomp @ 0x004374B0
long TPanel::char_action(long param_1, short param_2) { return 0; }
long TPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Source of truth: panel.cpp.decomp @ 0x00466140
    if (this->parent_panel) {
        return this->parent_panel->action(param_1, param_2, param_3, param_4);
    }
    return 0;
}
// Source of truth: panel.cpp.decomp @ 0x004669F0
void TPanel::get_true_render_rect(tagRECT* param_1) {}
// Source of truth: panel.cpp.decomp @ 0x004662E0
int TPanel::is_inside(long x, long y) {
    if (!this->active) {
        return 0;
    }

    if (x < this->clip_rect.left || x > this->clip_rect.right) {
        return 0;
    }
    if (y < this->clip_rect.top || y > this->clip_rect.bottom) {
        return 0;
    }
    return 1;
}
// Source of truth: panel.cpp.decomp @ 0x004663F0
void TPanel::set_focus(int param_1) {
    if (param_1 != this->have_focus) {
        this->have_focus = param_1;
        this->set_redraw(TPanel::RedrawMode::Redraw);
        if (this->curr_child) {
            this->curr_child->set_focus(this->have_focus);
        }
    }
}
// Source of truth: panel.cpp.decomp @ 0x00466600
void TPanel::set_tab_order(TPanel* param_1, TPanel* param_2) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00466650
    this->tab_prev_panel = param_1;
    this->tab_next_panel = param_2;
    this->tab_stop = 1;
}
// Source of truth: panel.cpp.decomp @ 0x00466650
void TPanel::set_tab_order(TPanel** param_1, short param_2) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00466600
    int count = (int)param_2;
    if (count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        TPanel* prev = (i == 0) ? param_1[count - 1] : param_1[i - 1];
        TPanel* next = (i == count - 1) ? param_1[0] : param_1[i + 1];
        param_1[i]->set_tab_order(prev, next);
    }
}
uchar TPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x004668D0
    if ((this->active != 0) && (this->is_inside(param_3, param_4) != 0)) {
        for (PanelNode* node = this->last_child_node; node != nullptr; node = node->prev_node) {
            if (node->panel && node->panel->get_help_info(param_1, param_2, param_3, param_4) != 0) {
                return 1;
            }
        }

        if (this->help_string_id >= 0) {
            char* str = this->get_string((int)this->help_string_id);
            // NOTE: Parity with original (panel.cpp.asm @ 0x004668D0): copy into caller-provided buffer
            // with no bounds check. Callers are expected to provide sufficient space (string source is 0x200).
            strcpy(*param_1, str);
            *param_2 = this->help_page_id;
            return 1;
        }
    }

    return 0;
}
// Source of truth: panel.cpp.decomp @ 0x00466980
void TPanel::stop_sound_system() {}
// Source of truth: panel.cpp.decomp @ 0x004669A0
int TPanel::restart_sound_system() { return 1; }
// Source of truth: panel.cpp.decomp @ 0x00437610
void TPanel::take_snapshot() {}
// Source of truth: panel.cpp.decomp @ 0x004669D0
void TPanel::handle_reactivate() {}

// Source of truth: panel.cpp.decomp @ 0x00466820
void TPanel::delete_panel(TPanel** panel) {
    // Source of truth: panel.cpp.decomp @ 0x00466820
    // If the panel pointer is valid, delete the panel and null the pointer
    if (panel && *panel) {
        delete *panel;
        *panel = nullptr;
    }
}

// Source of truth: panel.cpp.decomp @ 0x004663A0
void TPanel::set_curr_child(TPanel* child) {
    // Source of truth: panel.cpp.decomp @ 0x004663A0
    if (child == this->curr_child) {
        return;
    }

    if (this->curr_child && this->have_focus) {
        this->curr_child->set_focus(0);
    }

    this->curr_child = child;

    if (this->curr_child && this->have_focus) {
        this->curr_child->set_focus(1);
    }
}

// Source of truth: panel.cpp.decomp @ 0x004668B0
void TPanel::set_help_info(long help_id, long page_id) {
    // Source of truth: panel.cpp.decomp
    // Set help information for this panel
    this->help_string_id = help_id;
    this->help_page_id = page_id;
}

// Source of truth: panel.cpp.decomp @ 0x00466890
long TPanel::get_help_message() {
    return this->help_string_id;
}

// Source of truth: panel.cpp.decomp @ 0x004668A0
long TPanel::get_help_page() {
    return this->help_page_id;
}

// Source of truth: panel.cpp.decomp @ 0x00466840
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

// Source of truth: panel.cpp.decomp @ 0x00466870
char* TPanel::get_string(int resid) {
    static char static_buffer[0x200];
    // Source of truth: panel.cpp.decomp @ 0x00466870
    this->get_string(resid, static_buffer, sizeof(static_buffer));
    return static_buffer;
}

// Source of truth: panel.cpp.decomp @ 0x004666B0
char* TPanel::panelName() const {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x004666B0 (TPanel::panelName)
    return this->panelNameValue;
}

// Source of truth: panel.cpp.decomp @ 0x00466770
long TPanel::xPosition() const { return this->pnl_x; }
// Source of truth: panel.cpp.decomp @ 0x00466780
long TPanel::yPosition() const { return this->pnl_y; }
// Source of truth: panel.cpp.decomp @ 0x00466790
long TPanel::width() const { return this->pnl_wid; }
// Source of truth: panel.cpp.decomp @ 0x004667A0
long TPanel::height() const { return this->pnl_hgt; }

// Source of truth: panel.cpp.decomp @ 0x00466430
void TPanel::set_z_order(char param_1, int param_2) {
    // Source of truth: panel.cpp.decomp @ 0x00466430 + set_child_z_order @ 0x00466490
    if (this->parent_panel != nullptr) {
        panel_set_child_z_order(this->parent_panel, this, (unsigned char)param_1, (short)param_2);
        return;
    }

    if (param_1 == '\0') {
        this->z_order = (int)(short)param_2;
    } else if (param_1 == '\x01') {
        this->z_order = 0;
    } else if (param_1 == '\x02') {
        this->z_order = 0;
    }
}

// Source of truth: panel.cpp.decomp @ 0x00466220
int TPanel::capture_mouse() {
    if (panel_system) {
        if (panel_system->mouseOwnerValue != nullptr) {
            if (panel_system->mouseOwnerValue != this) {
                return 0; // Another panel owns the mouse
            }
            return 1; // Already captured by us
        }
    }

    if (this->render_area && this->render_area->Wnd) {
        SetCapture((HWND)this->render_area->Wnd);
    }

    if (panel_system) {
        panel_system->mouseOwnerValue = this;
    }
    this->mouse_captured = 1;
    return 1;
}

// Source of truth: panel.cpp.decomp @ 0x00466280
void TPanel::release_mouse() {
    if (!this->mouse_captured) {
        return;
    }

    if (panel_system && panel_system->mouseOwnerValue == this) {
        panel_system->mouseOwnerValue = nullptr;
        ReleaseCapture();
    }

    this->mouse_captured = 0;
}

// Source of truth: panel.cpp.decomp @ 0x004662C0
uchar TPanel::is_redraw_needed() {
    if (this->render_area != nullptr && this->visible != 0 && this->active != 0) {
        return (uchar)this->need_redraw;
    }
    return 0;
}

// Source of truth: panel.cpp.decomp @ 0x00466320
int TPanel::is_inside_rect(long param_1, long param_2, tagRECT* param_3) {
    if (param_3 == nullptr) {
        return 0;
    }
    if (param_3->left <= param_1 && param_1 <= param_3->right &&
        param_3->top <= param_2 && param_2 <= param_3->bottom) {
        return 1;
    }
    return 0;
}

// Source of truth: panel.cpp.decomp @ 0x00466420
int TPanel::get_focus() {
    return this->have_focus;
}

// Source of truth: panel.cpp.decomp @ 0x004661D0
void TPanel::get_mouse_pos(tagPOINT* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    GetCursorPos(param_1);
    if (this->render_area != nullptr &&
        this->render_area->DrawSystem != nullptr &&
        this->render_area->DrawSystem->ScreenMode != 2) {
        ScreenToClient((HWND)this->render_area->Wnd, param_1);
        if (60000 < (uint)param_1->x) {
            param_1->x = param_1->x - 0x10000;
        }
        if (60000 < (uint)param_1->y) {
            param_1->y = param_1->y - 0x10000;
        }
    }
}

// Source of truth: panel.cpp.decomp @ 0x00466670
TPanel* TPanel::previousPanel() {
    return this->previousPanelValue;
}

// Source of truth: panel.cpp.decomp @ 0x00466680
void TPanel::setPreviousPanel(TPanel* panel) {
    this->previousPanelValue = panel;
}

// Source of truth: panel.cpp.decomp @ 0x00466690
TPanel* TPanel::previousModalPanel() {
    return this->previousModalPanelValue;
}

// Source of truth: panel.cpp.decomp @ 0x004666A0
void TPanel::setPreviousModalPanel(TPanel* panel) {
    this->previousModalPanelValue = panel;
}

// Source of truth: panel.cpp.decomp @ 0x004666C0
void TPanel::setPanelName(char* name) {
    if (this->panelNameValue != nullptr) {
        free(this->panelNameValue);
    }
    this->panelNameValue = (name != nullptr) ? strdup(name) : nullptr;
}

// Source of truth: panel.cpp.decomp @ 0x004667B0
TDrawArea* TPanel::renderArea() {
    return this->render_area;
}

// Source of truth: panel.cpp.decomp @ 0x004667C0
tagRECT TPanel::clipRectangle() {
    tagRECT rect;
    rect.left = this->clip_rect.left;
    rect.top = this->clip_rect.top;
    rect.right = this->clip_rect.right;
    rect.bottom = this->clip_rect.bottom;
    return rect;
}

// Source of truth: panel.cpp.decomp @ 0x004667F0
void TPanel::setClipRectangle(tagRECT rect) {
    this->clip_rect = rect;
}

// Source of truth: panel.cpp.decomp @ 0x00466350
int TPanel::bound_point(long* param_1, long* param_2) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00466350 (TPanel::bound_point).
    int iVar1 = 0;

    int iVar2 = this->clip_rect.left + 1;
    if ((*param_1 < iVar2) || (iVar2 = this->clip_rect.right + -1, iVar2 < *param_1)) {
        *param_1 = iVar2;
        iVar1 = 1;
    }

    iVar2 = this->clip_rect.top + 1;
    if (*param_2 < iVar2) {
        *param_2 = iVar2;
        return 1;
    }

    iVar2 = this->clip_rect.bottom + -1;
    if (iVar2 < *param_2) {
        *param_2 = iVar2;
        iVar1 = 1;
    }

    return iVar1;
}

void TPanel::draw_tree() {
    // Source of truth: panel.cpp.decomp @ 0x00465A70
    // Parity traversal adapter: delegate to TPanel::handle_paint (panel.cpp.decomp/.asm @ 0x00465A70).
    this->handle_paint();
}
