#include "../include/TMessagePanel.h"

#include "../include/RGE_Base_Game.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/TShape.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <string.h>
#include <windows.h>

namespace {
const char* const kPnlMsgSourcePath = "C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp";

static unsigned long palette_index_to_rgb(unsigned char index) {
    if (rge_base_game == nullptr || rge_base_game->draw_system == nullptr || rge_base_game->draw_system->Pal == nullptr) {
        return 0;
    }

    tagPALETTEENTRY color = {};
    GetPaletteEntries((HPALETTE)rge_base_game->draw_system->Pal, index, 1, &color);
    return ((unsigned long)(color.peBlue & 0xFF) << 16) | ((unsigned long)(color.peGreen & 0xFF) << 8) | (unsigned long)(color.peRed & 0xFF);
}

static void clear_text_buffer(TMessagePanel* panel) {
    memset(panel->text, 0, sizeof(panel->text));
}

static void mark_parent_redraw(TMessagePanel* panel) {
    if (panel->parent_panel != nullptr) {
        panel->parent_panel->set_redraw(TPanel::Redraw);
    }
}

static void init_fields(TMessagePanel* panel, void* font, long font_wid, long font_hgt) {
    panel->font = font;
    panel->font_wid = font_wid;
    panel->font_hgt = font_hgt;

    panel->message_type = TMessagePanel::InfoMessage;
    clear_text_buffer(panel);
    panel->showing_message = 0;
    panel->start_time = 0;
    panel->show_message_interval = 8000;
    panel->font_color = 0;
    panel->back_color = 0;
    panel->index_color = 0;
    panel->font_color1 = 0xFFFFFF;
    panel->font_color2 = 0;
    panel->horz_just = TMessagePanel::LeftJust;
    panel->vert_just = TMessagePanel::TopJust;
    panel->word_wrap = 0;

    panel->image_clip_region = nullptr;
    panel->ImageBuffer = nullptr;
    SetRect(&panel->ImageRect, 0, 0, 0, 0);
    SetRect(&panel->UsedImageRect, 0, 0, 0, 0);
    SetRect(&panel->UsedScreenRect, 0, 0, 0, 0);
    panel->LastIBWidth = -1;
    panel->LastIBHeight = -1;
    panel->ImageTextActive = 0;
    panel->Icon1 = nullptr;
    panel->Icon2 = nullptr;
    panel->IconFrame1 = 0;
    panel->IconFrame2 = 0;
}
}

TMessagePanel::TMessagePanel() : TPanel() {
    init_fields(this, nullptr, 0, 0);
    this->set_active(0);
}

TMessagePanel::TMessagePanel(void* param_1, long param_2, long param_3) : TPanel() {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x00478F40
    init_fields(this, param_1, param_2, param_3);
    this->set_active(0);
}

TMessagePanel::~TMessagePanel() {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x00479050
    if (this->image_clip_region != nullptr) {
        DeleteObject((HGDIOBJ)this->image_clip_region);
        this->image_clip_region = nullptr;
    }

    if (this->ImageBuffer != nullptr) {
        delete this->ImageBuffer;
        this->ImageBuffer = nullptr;
    }
}

void TMessagePanel::set_rect(tagRECT param_1) {
    this->set_rect(param_1.left, param_1.top, (param_1.right - param_1.left) + 1, (param_1.bottom - param_1.top) + 1);
}

void TMessagePanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x004790E0
    TPanel::set_rect(param_1, param_2, param_3, param_4);

    if (((this->LastIBWidth < this->pnl_wid) || (this->LastIBHeight < this->pnl_hgt)) ||
        ((this->render_area != nullptr) && (this->render_area->Width <= param_1 + this->LastIBWidth))) {
        if (this->image_clip_region != nullptr) {
            DeleteObject((HGDIOBJ)this->image_clip_region);
            this->image_clip_region = nullptr;
        }

        if (this->ImageBuffer != nullptr) {
            delete this->ImageBuffer;
            this->ImageBuffer = nullptr;
        }

        this->ImageBuffer = new TDrawArea((char*)"message panel");
        if (this->ImageBuffer != nullptr && this->render_area != nullptr) {
            this->ImageBuffer->Init(this->render_area->DrawSystem, this->render_area->Wnd, this->pnl_wid, this->pnl_hgt, 0, 0, 0);
        }

        this->LastIBWidth = this->pnl_wid;
        this->LastIBHeight = this->pnl_hgt;

        const int right = this->pnl_wid - 1;
        const int bottom = this->pnl_hgt - 1;
        this->ImageRect.left = 0;
        this->ImageRect.top = 0;
        this->ImageRect.right = right;
        this->ImageRect.bottom = bottom;
        this->image_clip_region = (void*)CreateRectRgn(0, 0, right, bottom);
    }

    if (this->ImageBuffer == nullptr) {
        this->LastIBWidth = -1;
        this->LastIBHeight = -1;
    } else {
        this->UsedImageRect = this->ImageRect;
    }

    this->need_restore = 1;
    this->set_redraw(TPanel::Redraw);
}

void TMessagePanel::set_justification(int param_1, int param_2, int param_3) {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x00479270
    this->horz_just = (JustType)param_1;
    this->vert_just = (JustType)param_2;
    this->word_wrap = param_3;
}

void TMessagePanel::show_message(int param_1, char* param_2, unsigned char param_3, unsigned char param_4, void* param_5, long param_6, long param_7) {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x004792A0
    const char* message = (param_2 != nullptr) ? param_2 : "";

    if ((this->showing_message != 0) && (this->message_type == (MessageType)param_1) && (strncmp(message, this->text, 0x1FF) == 0)) {
        if ((param_5 == nullptr) || (param_5 == this->font)) {
            return;
        }
    }

    if (param_5 != nullptr) {
        this->font = param_5;
        this->font_wid = param_6;
        this->font_hgt = param_7;
    }

    this->message_type = (MessageType)param_1;
    clear_text_buffer(this);
    strncpy(this->text, message, 0x1FF);
    this->display_changed_count = this->display_changed_count + 1;
    this->showing_message = 1;
    this->start_time = debug_timeGetTime(kPnlMsgSourcePath, 0x9E);
    this->font_color = param_3;
    this->index_color = 1;
    this->back_color = param_4;

    if (this->ImageBuffer != nullptr) {
        this->render_to_image_buffer();
    }

    this->set_active(1);
    this->set_redraw(TPanel::Redraw);
    mark_parent_redraw(this);
}

void TMessagePanel::set_message(char* param_1) {
    if (param_1 == nullptr) {
        this->clear_message();
        return;
    }
    show_message(InfoMessage, param_1, this->font_color, this->back_color, nullptr, 0, 0);
}

void TMessagePanel::set_message(int param_1) {
    this->set_message(this->get_string(param_1));
}

void TMessagePanel::clear_message() {
    clear_text_buffer(this);
    this->remove_message();
}

void TMessagePanel::set_time(unsigned long param_1) {
    this->show_message_interval = (long)param_1;
}

void TMessagePanel::set_color(unsigned long param_1, unsigned long param_2) {
    this->font_color1 = param_1;
    this->font_color2 = param_2;
    this->font_color = (unsigned char)param_1;
    this->back_color = (unsigned char)param_2;
}

void TMessagePanel::set_style(int param_1) {
    this->index_color = param_1;
}

void TMessagePanel::set_alignment(int param_1, int param_2) {
    this->horz_just = (JustType)param_1;
    this->vert_just = (JustType)param_2;
}

void TMessagePanel::set_wrap(int param_1) {
    this->word_wrap = param_1;
}

void TMessagePanel::set_icon(int param_1) {
    this->IconFrame1 = param_1;
}

void TMessagePanel::show_message2(int param_1, char* param_2, unsigned long param_3, unsigned long param_4, void* param_5, long param_6, long param_7, TShape* param_8, int param_9, TShape* param_10, int param_11) {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x004793C0
    const char* message = (param_2 != nullptr) ? param_2 : "";

    if ((((((this->showing_message != 0) && (this->message_type == (MessageType)param_1)) && (strncmp(message, this->text, 0x1FF) == 0)) &&
          ((param_5 == nullptr) || (param_5 == this->font))) &&
         ((this->Icon1 == param_8) && ((this->Icon2 == param_10) && (this->IconFrame1 == param_9)))) &&
        (this->IconFrame2 == param_11)) {
        return;
    }

    if (param_5 != nullptr) {
        this->font = param_5;
        this->font_wid = param_6;
        this->font_hgt = param_7;
    }

    this->IconFrame1 = param_9;
    this->message_type = (MessageType)param_1;
    this->Icon1 = param_8;
    this->IconFrame2 = param_11;
    this->Icon2 = param_10;

    clear_text_buffer(this);
    strncpy(this->text, message, 0x1FF);

    this->showing_message = 1;
    this->display_changed_count = this->display_changed_count + 1;
    this->start_time = debug_timeGetTime(kPnlMsgSourcePath, 0xD3);
    this->font_color1 = param_3;
    this->index_color = 0;
    this->font_color2 = param_4;

    if (this->ImageBuffer != nullptr) {
        this->render_to_image_buffer();
    }

    this->set_active(1);
    this->set_redraw(TPanel::Redraw);
    mark_parent_redraw(this);
}

void TMessagePanel::remove_message() {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x00479540
    if (this->showing_message != 0) {
        this->showing_message = 0;
        this->set_active(0);
        this->set_redraw(TPanel::Redraw);
        mark_parent_redraw(this);
    }

    this->ImageTextActive = 0;
}

void TMessagePanel::draw() {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x00479590
    if ((this->render_area == nullptr) || (this->active == 0) || (this->visible == 0) || (this->showing_message == 0)) {
        this->just_drawn = 0;
        return;
    }

    this->draw_setup(0);

    if ((this->ImageTextActive != 0) && (this->ImageBuffer != nullptr)) {
        if (this->need_restore != 0) {
            this->render_to_image_buffer();
            this->need_restore = 0;
            this->draw_finish();
            return;
        }

        const int old_use_trans = this->ImageBuffer->UseTrans;
        const unsigned char old_trans_color = this->ImageBuffer->TransColor;
        this->ImageBuffer->UseTrans = 1;
        this->ImageBuffer->TransColor = 1;
        this->ImageBuffer->Copy(this->render_area, this->UsedScreenRect.left, this->UsedScreenRect.top, &this->UsedImageRect, 1);
        this->ImageBuffer->UseTrans = old_use_trans;
        this->ImageBuffer->TransColor = old_trans_color;
        this->draw_finish();
        return;
    }

    if (this->text[0] != '\0') {
        HDC dc = (HDC)this->render_area->GetDc((char*)"pnl_msg::draw");
        if (dc != nullptr) {
            SelectClipRgn(dc, (HRGN)this->clip_rgn);
            HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);

            unsigned long font_rgb;
            unsigned long back_rgb;
            if (this->index_color == 0) {
                font_rgb = this->font_color1;
                back_rgb = this->font_color2;
            } else {
                font_rgb = palette_index_to_rgb(this->font_color);
                back_rgb = palette_index_to_rgb(this->back_color);
            }

            if (this->message_type == DebugMessage) {
                SetBkColor(dc, 0);
                SetBkMode(dc, 2);
            } else {
                SetBkMode(dc, 1);
            }

            int x = (int)this->pnl_x;
            int y = (int)this->pnl_y;
            int wid = (int)this->pnl_wid - 2;
            int hgt = (int)this->pnl_hgt;
            SIZE ts = {};
            GetTextExtentPoint32A(dc, this->text, (int)strlen(this->text), &ts);

            UINT draw_flags;
            if (this->message_type == BadMessage) {
                draw_flags = 0x21;
            } else if (this->message_type == RightInfoMessage) {
                draw_flags = 0x22;
            } else {
                if ((this->word_wrap == 0) || (ts.cx <= wid)) {
                    draw_flags = 0x20;
                } else {
                    draw_flags = 0x10;
                }

                if (this->horz_just == CenterJust) {
                    draw_flags = draw_flags | 1;
                } else if (this->horz_just == RightJust) {
                    draw_flags = draw_flags | 2;
                }

                if (this->vert_just == CenterJust) {
                    draw_flags = draw_flags | 4;
                } else if (this->vert_just == BottomJust) {
                    draw_flags = draw_flags | 8;
                }
            }

            SetTextColor(dc, back_rgb);
            hgt = hgt - 2 + y + 1;
            wid = wid + x + 1;

            RECT rect;
            SetRect(&rect, x, y, wid - 2, hgt - 2);
            DrawTextA(dc, this->text, -1, &rect, draw_flags);
            SetRect(&rect, x, y + 2, wid - 2, hgt);
            DrawTextA(dc, this->text, -1, &rect, draw_flags);
            SetRect(&rect, x + 2, y, wid, hgt - 2);
            DrawTextA(dc, this->text, -1, &rect, draw_flags);
            SetRect(&rect, x + 2, y + 2, wid, hgt);
            DrawTextA(dc, this->text, -1, &rect, draw_flags);

            SetTextColor(dc, font_rgb);
            SetRect(&rect, x + 1, y + 1, wid - 1, hgt - 1);
            DrawTextA(dc, this->text, -1, &rect, draw_flags);

            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc((char*)"pnl_msg::draw");
        }
    }

    this->draw_finish();
}

void TMessagePanel::get_true_render_rect(tagRECT* param_1) {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x00479A10
    if (param_1 == nullptr) {
        return;
    }

    if ((this->ImageBuffer != nullptr) && (this->render_area != nullptr) && (this->active != 0) && (this->visible != 0) && (this->showing_message != 0)) {
        *param_1 = this->UsedScreenRect;
        return;
    }

    param_1->left = this->pnl_x;
    param_1->top = this->pnl_y;
    param_1->right = this->pnl_x + this->pnl_wid - 1;
    param_1->bottom = this->pnl_y + this->pnl_hgt - 1;
}

long TMessagePanel::handle_idle() {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x00479A80
    if ((this->visible != 0) && (this->showing_message != 0) &&
        ((this->message_type == BadMessage) || (this->message_type == ChatMessage) || (this->message_type == ColoredChatMessage))) {
        const unsigned long now = debug_timeGetTime(kPnlMsgSourcePath, 0x1BA);
        if (this->show_message_interval <= (long)(now - this->start_time)) {
            this->remove_message();
        }
    }

    return 0;
}

int TMessagePanel::render_to_image_buffer() {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x00479AE0
    if (this->ImageBuffer == nullptr) {
        return 0;
    }

    this->ImageBuffer->PtrClear(&this->ImageRect, 1);
    if (this->text[0] == '\0') {
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        SetRect(&this->UsedScreenRect, this->pnl_x, this->pnl_y, this->pnl_x + 1, this->pnl_y + 1);
        this->ImageTextActive = 1;
        return 1;
    }

    HDC dc = (HDC)this->ImageBuffer->GetDc((char*)"pnl_msg::render_to_image_buffer");
    if (dc == nullptr) {
        return 0;
    }

    this->ImageBuffer->SetClipRect(&this->ImageRect);
    SelectClipRgn(dc, (HRGN)this->image_clip_region);
    HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);

    unsigned long font_rgb;
    unsigned long back_rgb;
    if (this->index_color == 0) {
        font_rgb = this->font_color1;
        back_rgb = this->font_color2;
    } else {
        font_rgb = palette_index_to_rgb(this->font_color);
        back_rgb = palette_index_to_rgb(this->back_color);
    }

    if (this->message_type == DebugMessage) {
        SetBkColor(dc, 0);
        SetBkMode(dc, 2);
    } else {
        SetBkMode(dc, 1);
    }

    const int i_wid = (int)this->pnl_wid;
    const int i_hgt = (int)this->pnl_hgt;
    const int img_left = this->ImageRect.left;
    const int img_top = this->ImageRect.top;
    const int max_wid = i_wid - 2;
    const int max_hgt = i_hgt - 2;
    const int text_left = img_left + 1;
    const int text_top = img_top + 1;

    SIZE ts = {};
    if (GetTextExtentPoint32A(dc, this->text, (int)strlen(this->text), &ts) == 0) {
        RECT rect;
        SetRect(&rect, img_left, img_top, (max_wid + text_left) - 2, (max_hgt + text_top) - 2);
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        this->ImageTextActive = 0;
    } else {
        int y = 0;
        int x = 0;
        int draw_hgt = ts.cy + 2;
        int draw_wid = ts.cx + 2;
        UINT draw_flags;

        if (this->message_type == BadMessage) {
            draw_flags = 0x21;
            x = ((i_wid - draw_wid) >> 1) - 1;
        } else if (this->message_type == RightInfoMessage) {
            draw_flags = 0x22;
            x = (i_wid - draw_wid) - 1;
            y = 0;
        } else {
            bool use_single_line;
            if ((this->word_wrap == 0) || (ts.cx <= max_wid)) {
                draw_wid = ts.cx + 1;
                draw_hgt = ts.cy + 1;
                draw_flags = 0x20;
                use_single_line = true;
            } else {
                draw_wid = i_wid;
                draw_hgt = i_hgt;
                draw_flags = 0x10;
                use_single_line = false;
            }

            if (this->horz_just == CenterJust) {
                draw_flags = draw_flags | 1;
                if (use_single_line) {
                    x = ((i_wid - draw_wid) >> 1) - 1;
                }
            } else if (this->horz_just == RightJust) {
                draw_flags = draw_flags | 2;
                if (use_single_line) {
                    x = (i_wid - draw_wid) - 1;
                }
            } else if (use_single_line) {
                x = 0;
            }

            if (this->vert_just == CenterJust) {
                draw_flags = draw_flags | 4;
                if (use_single_line) {
                    y = ((i_hgt - draw_hgt) >> 1) - 1;
                }
            } else if (this->vert_just == BottomJust) {
                draw_flags = draw_flags | 8;
                if (use_single_line) {
                    y = (i_hgt - draw_hgt) - 1;
                }
            } else if (use_single_line) {
                y = 0;
            }
        }

        if (y < 0) {
            y = 0;
        }
        if (x < 0) {
            x = 0;
        }

        this->UsedImageRect.left = x;
        this->UsedImageRect.top = y;
        this->UsedImageRect.right = x + draw_wid;
        this->UsedImageRect.bottom = y + draw_hgt;

        if (this->ImageRect.right < this->UsedImageRect.right) {
            this->UsedImageRect.right = this->ImageRect.right;
        }
        if (this->ImageRect.bottom < this->UsedImageRect.bottom) {
            this->UsedImageRect.bottom = this->ImageRect.bottom;
        }

        SetTextColor(dc, back_rgb);
        const int right = text_left + max_wid;
        const int bottom = text_top + max_hgt;
        RECT rect;
        SetRect(&rect, img_left, img_top, right - 2, bottom - 2);
        DrawTextA(dc, this->text, -1, &rect, draw_flags);
        SetRect(&rect, img_left, img_top + 2, right - 2, bottom);
        DrawTextA(dc, this->text, -1, &rect, draw_flags);
        SetRect(&rect, img_left + 2, img_top, right, bottom - 2);
        DrawTextA(dc, this->text, -1, &rect, draw_flags);
        SetRect(&rect, img_left + 2, img_top + 2, right, bottom);
        DrawTextA(dc, this->text, -1, &rect, draw_flags);

        SetTextColor(dc, font_rgb);
        SetRect(&rect, text_left, text_top, right - 1, bottom - 1);
        DrawTextA(dc, this->text, -1, &rect, draw_flags);

        if (this->Icon1 != nullptr && this->Icon1->shape_info != nullptr) {
            const long frame = (long)this->IconFrame1;
            Shape_Info* info = this->Icon1->shape_info;
            const int icon_wid = info[frame].Width;
             this->Icon1->shape_draw(this->ImageBuffer,
                                     (info[frame].Hotspot_X - icon_wid) - 4 + this->UsedImageRect.left,
                                     info[frame].Hotspot_Y + 6 + this->UsedImageRect.top,
                                     frame,
                                     0,
                                     nullptr);
            this->UsedImageRect.left = this->UsedImageRect.left + (-4 - icon_wid);
        }

        if (this->Icon2 != nullptr && this->Icon2->shape_info != nullptr) {
            const long frame = (long)this->IconFrame2;
            Shape_Info* info = this->Icon2->shape_info;
            const int icon_wid = info[frame].Width;
             this->Icon2->shape_draw(this->ImageBuffer,
                                     (info[frame].Hotspot_X - icon_wid) - 4 + this->UsedImageRect.left,
                                     info[frame].Hotspot_Y + 6 + this->UsedImageRect.top,
                                     frame,
                                     0,
                                     nullptr);
            this->UsedImageRect.left = this->UsedImageRect.left + (-4 - icon_wid);
        }

        this->ImageTextActive = 1;
    }

    SelectObject(dc, old_font);
    SelectClipRgn(dc, 0);
    this->ImageBuffer->ReleaseDc((char*)"pnl_msg::render_to_image_buffer");

    this->UsedScreenRect.left = this->UsedImageRect.left + this->pnl_x;
    this->UsedScreenRect.top = this->UsedImageRect.top + this->pnl_y;
    this->UsedScreenRect.right = this->UsedImageRect.right + this->pnl_x;
    this->UsedScreenRect.bottom = this->UsedImageRect.bottom + this->pnl_y;
    return this->ImageTextActive;
}

long TMessagePanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x0047A160
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    return 0;
}

long TMessagePanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x0047A170
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

long TMessagePanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x0047A180
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    return 0;
}

void TMessagePanel::set_font(void* param_1, long param_2, long param_3) {
    // Fully verified. Source of truth: pnl_msg.cpp.decomp @ 0x0047A190
    if (this->font != param_1) {
        this->font = param_1;
        this->font_wid = param_2;
        this->font_hgt = param_3;
        this->need_restore = 1;
        this->set_redraw(TPanel::Redraw);
    }
}
