#include "../include/pnl_msg.h"
#include "../include/Shape.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include <string.h>

extern "C" int strncmp(const char*, const char*, unsigned int);
extern "C" char* strncpy(char*, const char*, unsigned int);
long __cdecl debug_timeGetTime(const char*, int);

TMessagePanel::TMessagePanel(void* font, long font_wid, long font_hgt)
    : TPanel() {
    this->font = font;
    this->font_wid = font_wid;
    this->font_hgt = font_hgt;
    this->LastIBWidth = -1;
    this->LastIBHeight = -1;
    this->message_type = InfoMessage;
    this->showing_message = 0;
    this->start_time = 0;
    this->show_message_interval = 8000;
    this->font_color = 0;
    this->back_color = 0;
    this->horz_just = LeftJust;
    this->vert_just = TopJust;
    this->word_wrap = 0;
    this->image_clip_region = 0;
    this->ImageBuffer = 0;
    this->ImageTextActive = 0;
    this->Icon1 = 0;
    this->Icon2 = 0;
    this->IconFrame1 = 0;
    this->IconFrame2 = 0;
    this->text[0] = 0;
    this->handle_mouse_input = 0;
    this->set_active(0);
}

TMessagePanel::~TMessagePanel(void) {
    if (this->image_clip_region != 0) {
        DeleteObject(this->image_clip_region);
        this->image_clip_region = 0;
    }
    TDrawArea* image_buffer = this->ImageBuffer;
    if (image_buffer != 0) {
        delete image_buffer;
        this->ImageBuffer = 0;
    }
}

void TMessagePanel::set_rect(long x, long y, long w, long h) {
    TPanel::set_rect(x, y, w, h);

    if (this->pnl_wid > this->LastIBWidth || this->pnl_hgt > this->LastIBHeight || x + this->LastIBWidth >= this->render_area->Width) {
        if (this->image_clip_region != 0) {
            DeleteObject(this->image_clip_region);
            this->image_clip_region = 0;
        }

        TDrawArea* image_buffer = this->ImageBuffer;
        if (image_buffer != 0) {
            delete image_buffer;
            this->ImageBuffer = 0;
        }

        image_buffer = new TDrawArea("message panel", 0);
        this->ImageBuffer = image_buffer;
        image_buffer->Init(this->render_area->DrawSystem, this->pnl_wid,
                           this->pnl_hgt, 0, 0);
        this->LastIBWidth = this->pnl_wid;
        this->LastIBHeight = this->pnl_hgt;

        long right = this->pnl_wid - 1;
        long bottom = this->pnl_hgt - 1;
        this->ImageRect.left = 0;
        this->ImageRect.top = 0;
        this->ImageRect.right = right;
        this->ImageRect.bottom = bottom;
        this->image_clip_region = CreateRectRgn(0, 0, right, bottom);
    }

    if (this->ImageBuffer != 0) {
        this->UsedImageRect = this->ImageRect;
    } else {
        this->LastIBWidth = -1;
        this->LastIBHeight = -1;
    }

    this->need_restore = 1;
    this->set_redraw(TPanel::RedrawNormal);
}

void TMessagePanel::set_justification(TMessagePanel::JustType a,
                                      TMessagePanel::JustType b, int c) {
    this->horz_just = a;
    this->vert_just = b;
    this->word_wrap = c;
}

void TMessagePanel::show_message(TMessagePanel::MessageType message_type,
                                  char* text, unsigned char font_color,
                                  unsigned char back_color, void* font,
                                  long font_wid, long font_hgt) {
    if (this->showing_message && this->message_type == message_type &&
        strncmp(text, this->text, 0x1ff) == 0) {
        if (font == 0) {
            return;
        }
        if (font == this->font) {
            return;
        }
    }

    if (font != 0) {
        this->font = font;
        this->font_wid = font_wid;
        this->font_hgt = font_hgt;
    }

    this->message_type = message_type;
    for (int i = 0; i < 0x200; ++i) {
        this->text[i] = 0;
    }
    strncpy(this->text, text, 0x1ff);
    this->display_changed_count++;
    this->showing_message = 1;
    this->start_time = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 0x9e);
    this->font_color = font_color;
    this->index_color = 1;
    this->back_color = back_color;

    if (this->ImageBuffer) {
        this->render_to_image_buffer();
    }

    this->set_active(1);
    this->set_redraw(TPanel::RedrawNormal);
    if (this->parent_panel) {
        this->parent_panel->set_redraw(TPanel::RedrawNormal);
    }
}

void TMessagePanel::show_message2(
    TMessagePanel::MessageType message_type, char* text,
    unsigned long font_color1, unsigned long font_color2, void* font,
    long font_wid, long font_hgt, TShape* Icon1, int IconFrame1,
    TShape* Icon2, int IconFrame2) {
    if (this->showing_message && this->message_type == message_type &&
        strncmp(text, this->text, 0x1ff) == 0) {
        if (font == 0 || font == this->font) {
            if (this->Icon1 == Icon1 && this->Icon2 == Icon2 &&
                this->IconFrame1 == IconFrame1 &&
                this->IconFrame2 == IconFrame2) {
                return;
            }
        }
    }

    if (font != 0) {
        this->font = font;
        this->font_wid = font_wid;
        this->font_hgt = font_hgt;
    }

    this->message_type = message_type;
    this->Icon1 = Icon1;
    this->IconFrame1 = IconFrame1;
    this->IconFrame2 = IconFrame2;
    this->Icon2 = Icon2;

    for (int i = 0; i < 0x200; ++i) {
        this->text[i] = 0;
    }
    strncpy(this->text, text, 0x1ff);
    this->display_changed_count++;
    this->showing_message = 1;
    this->start_time = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 0xd3);
    this->font_color1 = font_color1;
    this->index_color = 0;
    this->font_color2 = font_color2;

    if (this->ImageBuffer) {
        this->render_to_image_buffer();
    }

    this->set_active(1);
    this->set_redraw(TPanel::RedrawNormal);
    if (this->parent_panel) {
        this->parent_panel->set_redraw(TPanel::RedrawNormal);
    }
}

void TMessagePanel::remove_message(void) {
    if (this->showing_message != 0) {
        this->showing_message = 0;
        this->set_active(0);
        this->set_redraw(TPanel::RedrawNormal);
        if (this->parent_panel != 0) {
            this->parent_panel->set_redraw(TPanel::RedrawNormal);
        }
    }
    this->ImageTextActive = 0;
}

void TMessagePanel::draw() {
    if (this->render_area == 0 || this->visible == 0 || this->active == 0 || this->showing_message == 0) {
        this->need_redraw = 0;
        return;
    }

    long y;
    long x;
    long wid;
    long hgt;
    COLORREF font_rgb;
    HGDIOBJ old_font;
    COLORREF back_rgb;
    tagPALETTEENTRY p;
    tagSIZE ts;
    tagRECT rect;
    int len;
    this->draw_setup(0);

    if (this->ImageTextActive != 0 && this->ImageBuffer != 0) {
        if (this->need_restore != 0) {
            this->render_to_image_buffer();
            this->need_restore = 0;
            this->draw_finish();
            return;
        }
        this->ImageBuffer->SetTrans(1, 1);
        this->ImageBuffer->Copy(this->render_area, this->UsedScreenRect.left,
                                this->UsedScreenRect.top, &this->UsedImageRect,
                                1);
        this->ImageBuffer->SetTrans(0, 1);
        this->draw_finish();
        return;
    }

    char* msg = this->text;
    if (msg[0] != 0) {
        void* dc = this->render_area->GetDc("pnl_msg::draw");
        if (dc != 0) {
            SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
            old_font = SelectObject(this->render_area->DrawDc, this->font);
            if (this->index_color != 0) {
                GetPaletteEntries(rge_base_game->draw_system->Pal,
                                  this->font_color, 1, &p);
                font_rgb = ((unsigned long)p.peBlue << 16) |
                           ((unsigned long)p.peGreen << 8) | p.peRed;
                GetPaletteEntries(rge_base_game->draw_system->Pal,
                                  this->back_color, 1, &p);
                back_rgb = ((unsigned long)p.peBlue << 16) |
                           ((unsigned long)p.peGreen << 8) | p.peRed;
            } else {
                font_rgb = this->font_color1;
                back_rgb = this->font_color2;
            }

            if (this->message_type == 2) {
                SetBkColor(this->render_area->DrawDc, 0);
                SetBkMode(this->render_area->DrawDc, 2);
            } else {
                SetBkMode(this->render_area->DrawDc, 1);
            }

            x = this->render_rect.left;
            y = this->render_rect.top;
            wid = this->pnl_wid - 2;
            hgt = this->pnl_hgt - 2;

            len = strlen(msg);
            GetTextExtentPoint32A(this->render_area->DrawDc, msg, len, &ts);

            unsigned int flags;
            if (this->message_type == 1) {
                flags = 0x21;
            } else if (this->message_type == 5) {
                flags = 0x22;
            } else {
                len = strlen(msg);
                GetTextExtentPoint32A(this->render_area->DrawDc, msg, len, &ts);
                flags = (this->word_wrap == 0 ||
                         ts.cx <= this->pnl_wid - 2) ? 0x20 : 0x10;
                if (this->horz_just == 4) flags |= 1;
                else if (this->horz_just == 3) flags |= 2;
                if (this->vert_just == 4) flags |= 4;
                else if (this->vert_just == 1) flags |= 8;
            }

            wid = wid + x + 1;
            hgt = hgt + y + 1;
            SetTextColor(this->render_area->DrawDc, back_rgb);
            SetRect(&rect, x, y, wid - 2, hgt - 2);
            DrawTextA(this->render_area->DrawDc, msg, -1, &rect, flags);
            SetRect(&rect, x, y + 2, wid - 2, hgt);
            DrawTextA(this->render_area->DrawDc, msg, -1, &rect, flags);
            SetRect(&rect, x + 2, y, wid, hgt - 2);
            DrawTextA(this->render_area->DrawDc, msg, -1, &rect, flags);
            SetRect(&rect, x + 2, y + 2, wid, hgt);
            DrawTextA(this->render_area->DrawDc, msg, -1, &rect, flags);
            SetTextColor(this->render_area->DrawDc, font_rgb);
            SetRect(&rect, x + 1, y + 1, wid - 1, hgt - 1);
            DrawTextA(this->render_area->DrawDc, msg, -1, &rect, flags);

            SelectObject(this->render_area->DrawDc, old_font);
            SelectClipRgn(this->render_area->DrawDc, 0);
            this->render_area->ReleaseDc("pnl_msg::draw");
        }
    }

    this->draw_finish();
}

void TMessagePanel::get_true_render_rect(tagRECT& rect) {
    if (this->ImageBuffer && this->render_area && this->visible &&
        this->active && this->showing_message) {
        rect = this->UsedScreenRect;
    } else {
        rect = this->render_rect;
    }
}

long TMessagePanel::handle_idle() {
    if (active && showing_message) {
        if (message_type == 1 || message_type == 3 || message_type == 4) {
            long now = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 0x1BA);
            if (now - start_time >= show_message_interval) {
                remove_message();
            }
        }
    }
    return 0;
}

int TMessagePanel::render_to_image_buffer() {
    tagRECT* image_rect;
    void* old_font;
    tagPALETTEENTRY p;
    unsigned long font_rgb;
    unsigned long back_rgb;
    long x1;
    long display_hgt;
    long y1;
    long wid;
    long hgt;
    tagSIZE ts;
    tagRECT rect;
    unsigned int flags;
    long used_x;
    long used_y;
    long used_w;
    int tight;

    if (this->ImageBuffer == 0) {
        return 0;
    }

    image_rect = &this->ImageRect;
    this->ImageBuffer->PtrClear(image_rect, 1);
    char* text = this->text;
    if (this->text[0] == 0) {
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        SetRect(&this->UsedScreenRect, this->render_rect.left,
                this->render_rect.top, this->render_rect.left + 1,
                this->render_rect.top + 1);
        this->ImageTextActive = 1;
        return 1;
    }

    if (this->ImageBuffer->GetDc("pnl_msg::render_to_image_buffer") == 0) {
        return 0;
    }

    this->ImageBuffer->SetClipRect(image_rect);
    SelectClipRgn(this->ImageBuffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->ImageBuffer->DrawDc, this->font);

    if (this->index_color != 0) {
        GetPaletteEntries(rge_base_game->draw_system->Pal,
                          this->font_color, 1, &p);
        font_rgb = ((unsigned long)p.peBlue << 16) |
                   ((unsigned long)p.peGreen << 8) | p.peRed;
        GetPaletteEntries(rge_base_game->draw_system->Pal,
                          this->back_color, 1, &p);
        back_rgb = ((unsigned long)p.peBlue << 16) |
                   ((unsigned long)p.peGreen << 8) | p.peRed;
    } else {
        font_rgb = this->font_color1;
        back_rgb = this->font_color2;
    }

    if (this->message_type == 2) {
        SetBkColor(this->ImageBuffer->DrawDc, 0);
        SetBkMode(this->ImageBuffer->DrawDc, 2);
    } else {
        SetBkMode(this->ImageBuffer->DrawDc, 1);
    }

    wid = this->pnl_wid - 2;
    x1 = image_rect->left + 1;
    y1 = this->ImageRect.top + 1;
    hgt = this->pnl_hgt - 2;

    if (GetTextExtentPoint32A(this->ImageBuffer->DrawDc, this->text,
                              strlen(this->text), &ts) == 0) {
        SetRect(&rect, x1 - 1, y1 - 1, x1 + wid - 2, y1 + hgt - 2);
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        this->ImageTextActive = 0;
    } else {
        used_x = 0;
        used_y = 0;
        display_hgt = ts.cy + 2;
        used_w = ts.cx + 2;
        int message_type = this->message_type;
        tight = 1;

        if (message_type == 1) {
            flags = 0x21;
            used_x = ((this->pnl_wid - used_w) >> 1) - 1;
        } else if (message_type == 5) {
            flags = 0x22;
            used_x = (this->pnl_wid - used_w) - 1;
            used_y = 0;
        } else {
            if (this->word_wrap == 0 || ts.cx <= wid) {
                used_w = ts.cx + 1;
                display_hgt = ts.cy + 1;
                flags = 0x20;
                tight = 1;
            } else {
                used_w = this->pnl_wid;
                display_hgt = this->pnl_hgt;
                flags = 0x10;
                tight = 0;
            }
            used_x = 0;
            used_y = 0;
            if (this->horz_just == 4) {
                flags |= 1;
                if (tight) used_x = ((this->pnl_wid - used_w) >> 1) - 1;
            } else if (this->horz_just == 3) {
                flags |= 2;
                if (tight) used_x = (this->pnl_wid - used_w) - 1;
            } else if (tight) {
                used_x = 0;
            }
            if (this->vert_just == 4) {
                flags |= 4;
                if (tight) used_y = ((this->pnl_hgt - display_hgt) >> 1) - 1;
            } else if (this->vert_just == 1) {
                flags |= 8;
                if (tight) used_y = (this->pnl_hgt - display_hgt) - 1;
            } else if (tight) {
                used_y = 0;
            }
        }

        if (used_y < 0) used_y = 0;
        if (used_x < 0) used_x = 0;

        this->UsedImageRect.left = used_x;
        this->UsedImageRect.top = used_y;
        this->UsedImageRect.right = used_x + used_w;
        this->UsedImageRect.bottom = used_y + display_hgt;
        if (this->UsedImageRect.right > this->ImageRect.right)
            this->UsedImageRect.right = this->ImageRect.right;
        if (this->UsedImageRect.bottom > this->ImageRect.bottom)
            this->UsedImageRect.bottom = this->ImageRect.bottom;

        SetTextColor(this->ImageBuffer->DrawDc, back_rgb);
        SetRect(&rect, x1 - 1, y1 - 1, x1 + wid - 2, y1 + hgt - 2);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetRect(&rect, x1 - 1, y1 + 1, x1 + wid - 2, y1 + hgt);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetRect(&rect, x1 + 1, y1 - 1, x1 + wid, y1 + hgt - 2);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetRect(&rect, x1 + 1, y1 + 1, x1 + wid, y1 + hgt);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetTextColor(this->ImageBuffer->DrawDc, font_rgb);
        SetRect(&rect, x1, y1, x1 + wid - 1, y1 + hgt - 1);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);

        if (this->Icon1 != 0) {
            Shape_Info* info = this->Icon1->shape_info;
            long frame = this->IconFrame1;
            long width = info[frame].Width;
            this->Icon1->shape_draw(
                this->ImageBuffer,
                info[frame].Hotspot_X - width - 4 +
                    this->UsedImageRect.left,
                info[frame].Hotspot_Y + 6 + this->UsedImageRect.top,
                frame, 0, 0);
            this->UsedImageRect.left += -4 - width;
        }
        if (this->Icon2 != 0) {
            Shape_Info* info = this->Icon2->shape_info;
            long frame = this->IconFrame2;
            long width = info[frame].Width;
            this->Icon2->shape_draw(
                this->ImageBuffer,
                info[frame].Hotspot_X - width - 4 +
                    this->UsedImageRect.left,
                info[frame].Hotspot_Y + 6 + this->UsedImageRect.top,
                frame, 0, 0);
            this->UsedImageRect.left += -4 - width;
        }
        this->ImageTextActive = 1;
    }

    SelectObject(this->ImageBuffer->DrawDc, old_font);
    SelectClipRgn(this->ImageBuffer->DrawDc, 0);
    this->ImageBuffer->ReleaseDc("pnl_msg::render_to_image_buffer");

    this->UsedScreenRect.left = this->UsedImageRect.left + this->render_rect.left;
    this->UsedScreenRect.top = this->UsedImageRect.top + this->render_rect.top;
    this->UsedScreenRect.right = this->UsedImageRect.right + this->render_rect.left;
    this->UsedScreenRect.bottom = this->UsedImageRect.bottom + this->render_rect.top;
    return this->ImageTextActive;
}

void TMessagePanel::set_font(void* param_1, long param_2, long param_3) {
    if (this->font != param_1) {
        this->font = param_1;
        this->font_wid = param_2;
        this->font_hgt = param_3;
        this->need_restore = 1;
        this->set_redraw(TPanel::RedrawNormal);
    }
}
