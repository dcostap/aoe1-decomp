#include "../include/pnl_msg.h"
#include "../include/Shape.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include <string.h>

extern "C" int strncmp(const char*, const char*, unsigned int);
extern "C" char* strncpy(char*, const char*, unsigned int);
unsigned long __cdecl debug_timeGetTime(char*, int);

TMessagePanel::TMessagePanel(void* font_in, long font_wid_in, long font_hgt_in)
    : TPanel(),
      message_type(InfoMessage),
      showing_message(0),
      start_time(0),
      show_message_interval(8000),
      font(font_in),
      font_wid(font_wid_in),
      font_hgt(font_hgt_in),
      font_color(0),
      back_color(0),
      horz_just(LeftJust),
      vert_just(TopJust),
      word_wrap(0),
      image_clip_region(0),
      ImageBuffer(0),
      ImageTextActive(0),
      Icon1(0),
      Icon2(0),
      IconFrame1(0),
      IconFrame2(0),
      LastIBWidth(-1),
      LastIBHeight(-1) {
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

void TMessagePanel::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    TPanel::set_rect(x_in, y_in, wid_in, hgt_in);

    if (this->pnl_wid > this->LastIBWidth || this->pnl_hgt > this->LastIBHeight || x_in + this->LastIBWidth >= this->render_area->Width) {
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
        image_buffer->Init(this->render_area->DrawSystem, this->pnl_wid, this->pnl_hgt, 0, 0);
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

void TMessagePanel::set_justification(TMessagePanel::JustType horz_just_in, TMessagePanel::JustType vert_just_in, int word_wrap_in) {
    this->horz_just = horz_just_in;
    this->vert_just = vert_just_in;
    this->word_wrap = word_wrap_in;
}

void TMessagePanel::show_message(TMessagePanel::MessageType message_type_in, char* text_in, unsigned char colorIn, unsigned char backColorIn, void* font_in, long font_wid_in, long font_hgt_in) {
    if (this->showing_message && this->message_type == message_type_in &&
        strncmp(text_in, this->text, 0x1ff) == 0) {
        if (font_in == 0) {
            return;
        }
        if (font_in == this->font) {
            return;
        }
    }

    if (font_in != 0) {
        this->font = font_in;
        this->font_wid = font_wid_in;
        this->font_hgt = font_hgt_in;
    }

    this->message_type = message_type_in;
    for (int i = 0; i < 0x200; ++i) {
        this->text[i] = 0;
    }
    strncpy(this->text, text_in, 511);
    this->display_changed_count++;
    this->showing_message = 1;
    this->start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 158);
    this->font_color = colorIn;
    this->index_color = 1;
    this->back_color = backColorIn;

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
    TMessagePanel::MessageType message_type_in, char* text_in,
    unsigned long color1, unsigned long color2, void* font_in,
    long font_wid_in, long font_hgt_in, TShape* Icon1_in, int Frame1_in,
    TShape* Icon2_in, int Frame2_in) {
    if (this->showing_message && this->message_type == message_type_in &&
        strncmp(text_in, this->text, 0x1ff) == 0) {
        if (font_in == 0 || font_in == this->font) {
            if (this->Icon1 == Icon1_in && this->Icon2 == Icon2_in &&
                this->IconFrame1 == Frame1_in &&
                this->IconFrame2 == Frame2_in) {
                return;
            }
        }
    }

    if (font_in != 0) {
        this->font = font_in;
        this->font_wid = font_wid_in;
        this->font_hgt = font_hgt_in;
    }

    this->message_type = message_type_in;
    this->Icon1 = Icon1_in;
    this->IconFrame1 = Frame1_in;
    this->IconFrame2 = Frame2_in;
    this->Icon2 = Icon2_in;

    for (int i = 0; i < 0x200; ++i) {
        this->text[i] = 0;
    }
    strncpy(this->text, text_in, 511);
    this->display_changed_count++;
    this->showing_message = 1;
    this->start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 211);
    this->font_color1 = color1;
    this->index_color = 0;
    this->font_color2 = color2;

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

void TMessagePanel::draw(void) {
    tagPALETTEENTRY paletteColor;
    void* old_font;
    unsigned long font_rgb;
    unsigned long back_rgb;
    long x;
    long y;
    long wid;
    long hgt;
    tagSIZE ts;
    tagRECT rect;
    unsigned int flags;

    if (this->render_area == 0 || this->visible == 0 ||
        this->active == 0 || this->showing_message == 0) {
        this->need_redraw = 0;
        return;
    }

    this->draw_setup(0);

    if (this->ImageTextActive != 0 && this->ImageBuffer != 0) {
        if (this->need_restore != 0) {
            this->render_to_image_buffer();
            this->need_restore = 0;
            goto finish;
        }

        this->ImageBuffer->SetTrans(1, 1);
        this->ImageBuffer->Copy(this->render_area, this->UsedScreenRect.left, this->UsedScreenRect.top,
                                &this->UsedImageRect, 1);
        this->ImageBuffer->SetTrans(0, 1);
        goto finish;
    }

    if (this->text[0] == 0) {
        goto finish;
    }

    if (this->render_area->GetDc("pnl_msg::draw") == 0) {
        goto finish;
    }

    SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
    old_font = SelectObject(this->render_area->DrawDc, this->font);

    if (this->index_color != 0) {
        GetPaletteEntries(rge_base_game->draw_system->Pal, this->font_color, 1, &paletteColor);
        font_rgb = ((unsigned long)paletteColor.peBlue << 16) |
                   ((unsigned long)paletteColor.peGreen << 8) | paletteColor.peRed;
        GetPaletteEntries(rge_base_game->draw_system->Pal, this->back_color, 1, &paletteColor);
        back_rgb = ((unsigned long)paletteColor.peBlue << 16) |
                   ((unsigned long)paletteColor.peGreen << 8) | paletteColor.peRed;
    } else {
        font_rgb = this->font_color1;
        back_rgb = this->font_color2;
    }

    if (this->message_type == DebugMessage) {
        SetBkColor(this->render_area->DrawDc, 0);
        SetBkMode(this->render_area->DrawDc, OPAQUE);
    } else {
        SetBkMode(this->render_area->DrawDc, TRANSPARENT);
    }

    x = this->render_rect.left + 1;
    y = this->render_rect.top + 1;
    wid = this->pnl_wid - 2;
    hgt = this->pnl_hgt - 2;

    GetTextExtentPoint32A(this->render_area->DrawDc, this->text, strlen(this->text), &ts);

    if (this->message_type == BadMessage) {
        flags = DT_SINGLELINE | DT_CENTER;
    } else if (this->message_type == RightInfoMessage) {
        flags = DT_SINGLELINE | DT_RIGHT;
    } else {
        GetTextExtentPoint32A(this->render_area->DrawDc, this->text, strlen(this->text), &ts);
        if (this->word_wrap != 0 && ts.cx > wid) {
            flags = DT_WORDBREAK;
        } else {
            flags = DT_SINGLELINE;
        }

        if (this->horz_just == CenterJust) {
            flags |= DT_CENTER;
        } else if (this->horz_just == RightJust) {
            flags |= DT_RIGHT;
        }

        if (this->vert_just == CenterJust) {
            flags |= DT_VCENTER;
        } else if (this->vert_just == BottomJust) {
            flags |= DT_BOTTOM;
        }
    }

    SetTextColor(this->render_area->DrawDc, back_rgb);
    SetRect(&rect, x - 1, y - 1, x + wid - 2, y + hgt - 2);
    DrawTextA(this->render_area->DrawDc, this->text, -1, &rect, flags);
    SetRect(&rect, x - 1, y + 1, x + wid - 2, y + hgt);
    DrawTextA(this->render_area->DrawDc, this->text, -1, &rect, flags);
    SetRect(&rect, x + 1, y - 1, x + wid, y + hgt - 2);
    DrawTextA(this->render_area->DrawDc, this->text, -1, &rect, flags);
    SetRect(&rect, x + 1, y + 1, x + wid, y + hgt);
    DrawTextA(this->render_area->DrawDc, this->text, -1, &rect, flags);
    SetTextColor(this->render_area->DrawDc, font_rgb);
    SetRect(&rect, x, y, x + wid - 1, y + hgt - 1);
    DrawTextA(this->render_area->DrawDc, this->text, -1, &rect, flags);

    SelectObject(this->render_area->DrawDc, old_font);
    SelectClipRgn(this->render_area->DrawDc, 0);
    this->render_area->ReleaseDc("pnl_msg::draw");

finish:
    this->draw_finish();
}

void TMessagePanel::get_true_render_rect(tagRECT& drawRect) {
    if (this->ImageBuffer && this->render_area && this->visible &&
        this->active && this->showing_message) {
        drawRect = this->UsedScreenRect;
    } else {
        drawRect = this->render_rect;
    }
}

long TMessagePanel::handle_idle() {
    if (active && showing_message) {
        if (message_type == BadMessage || message_type == ChatMessage ||
            message_type == ColoredChatMessage) {
            long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 442);
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
    tagPALETTEENTRY paletteColor;
    unsigned long font_rgb;
    unsigned long back_rgb;
    long x;
    long Display_hgt;
    long y;
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
        SetRect(&this->UsedScreenRect, this->render_rect.left, this->render_rect.top, this->render_rect.left + 1,
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
        GetPaletteEntries(rge_base_game->draw_system->Pal, this->font_color, 1, &paletteColor);
        font_rgb = ((unsigned long)paletteColor.peBlue << 16) |
                   ((unsigned long)paletteColor.peGreen << 8) | paletteColor.peRed;
        GetPaletteEntries(rge_base_game->draw_system->Pal, this->back_color, 1, &paletteColor);
        back_rgb = ((unsigned long)paletteColor.peBlue << 16) |
                   ((unsigned long)paletteColor.peGreen << 8) | paletteColor.peRed;
    } else {
        font_rgb = this->font_color1;
        back_rgb = this->font_color2;
    }

    if (this->message_type == DebugMessage) {
        SetBkColor(this->ImageBuffer->DrawDc, 0);
        SetBkMode(this->ImageBuffer->DrawDc, OPAQUE);
    } else {
        SetBkMode(this->ImageBuffer->DrawDc, TRANSPARENT);
    }

    wid = this->pnl_wid - 2;
    x = image_rect->left + 1;
    y = this->ImageRect.top + 1;
    hgt = this->pnl_hgt - 2;

    if (GetTextExtentPoint32A(this->ImageBuffer->DrawDc, this->text, strlen(this->text), &ts) == 0) {
        SetRect(&rect, x - 1, y - 1, x + wid - 2, y + hgt - 2);
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        this->ImageTextActive = 0;
    } else {
        Display_hgt = ts.cy + 2;
        used_w = ts.cx + 2;
        used_y = 0;
        used_x = 0;
        tight = 1;

        if (this->message_type == BadMessage) {
            flags = DT_SINGLELINE | DT_CENTER;
            used_x = ((this->pnl_wid - used_w) >> 1) - 1;
        } else if (this->message_type == RightInfoMessage) {
            flags = DT_SINGLELINE | DT_RIGHT;
            used_x = (this->pnl_wid - used_w) - 1;
            used_y = 0;
        } else {
            if (this->word_wrap == 0 || ts.cx <= wid) {
                used_w = ts.cx + 1;
                flags = DT_SINGLELINE;
                Display_hgt = ts.cy + 1;
                tight = 1;
            } else {
                used_w = this->pnl_wid;
                Display_hgt = this->pnl_hgt;
                used_x = 0;
                used_y = 0;
                flags = DT_WORDBREAK;
                tight = 0;
            }
            if (this->horz_just == CenterJust) {
                flags |= DT_CENTER;
                if (tight) used_x = ((this->pnl_wid - used_w) >> 1) - 1;
            } else if (this->horz_just == RightJust) {
                flags |= DT_RIGHT;
                if (tight) used_x = (this->pnl_wid - used_w) - 1;
            } else if (tight) {
                used_x = 0;
            }
            if (this->vert_just == CenterJust) {
                flags |= DT_VCENTER;
                if (tight) used_y = ((this->pnl_hgt - Display_hgt) >> 1) - 1;
            } else if (this->vert_just == BottomJust) {
                flags |= DT_BOTTOM;
                if (tight) used_y = (this->pnl_hgt - Display_hgt) - 1;
            } else if (tight) {
                used_y = 0;
            }
        }

        if (used_y < 0) used_y = 0;
        if (used_x < 0) used_x = 0;

        this->UsedImageRect.left = used_x;
        this->UsedImageRect.top = used_y;
        this->UsedImageRect.right = used_x + used_w;
        this->UsedImageRect.bottom = used_y + Display_hgt;
        if (this->UsedImageRect.right > this->ImageRect.right)
            this->UsedImageRect.right = this->ImageRect.right;
        if (this->UsedImageRect.bottom > this->ImageRect.bottom)
            this->UsedImageRect.bottom = this->ImageRect.bottom;

        SetTextColor(this->ImageBuffer->DrawDc, back_rgb);
        SetRect(&rect, x - 1, y - 1, x + wid - 2, y + hgt - 2);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetRect(&rect, x - 1, y + 1, x + wid - 2, y + hgt);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetRect(&rect, x + 1, y - 1, x + wid, y + hgt - 2);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetRect(&rect, x + 1, y + 1, x + wid, y + hgt);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetTextColor(this->ImageBuffer->DrawDc, font_rgb);
        SetRect(&rect, x, y, x + wid - 1, y + hgt - 1);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);

        if (this->Icon1 != 0) {
            Shape_Info* info = this->Icon1->shape_info;
            long frame = this->IconFrame1;
            long width = info[frame].Width;
            this->Icon1->shape_draw(this->ImageBuffer, info[frame].Hotspot_X - width - 4 + this->UsedImageRect.left,
                                    info[frame].Hotspot_Y + 6 + this->UsedImageRect.top, frame, 0, 0);
            this->UsedImageRect.left += -4 - width;
        }
        if (this->Icon2 != 0) {
            Shape_Info* info = this->Icon2->shape_info;
            long frame = this->IconFrame2;
            Shape_Info* frame_info = info + frame;
            long width = frame_info->Width;
            this->Icon2->shape_draw(this->ImageBuffer, frame_info->Hotspot_X - width - 4 + this->UsedImageRect.left,
                                    frame_info->Hotspot_Y + 6 + this->UsedImageRect.top, frame, 0, 0);
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

void TMessagePanel::set_font(void* font_in, long font_wid_in, long font_hgt_in) {
    if (this->font != font_in) {
        this->font = font_in;
        this->font_wid = font_wid_in;
        this->font_hgt = font_hgt_in;
        this->need_restore = 1;
        this->set_redraw(TPanel::RedrawNormal);
    }
}
