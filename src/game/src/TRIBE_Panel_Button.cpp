#include "../include/TRIBE_Panel_Button.h"
#include "../include/TDrawArea.h"
#include "../include/TShape.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Color_Table.h"
#include "../include/globals.h"

#include <stdio.h>
#include <string.h>

extern "C" void _ASMSet_Shadowing(int p1, int p2, int p3, int p4);
extern "C" void _ASMSet_Color_Xform(int v);

TRIBE_Panel_Button::TRIBE_Panel_Button() : TButtonPanel() {
    this->display_garrison = 0;
    this->garrsion_number = 0;
    this->tribe_button_type = 0;
    this->border_pic = nullptr;
    this->color_table = nullptr;
    this->border_frame = 0;
    this->text_msg[0] = '\0';
    this->in_use = 0;
}

TRIBE_Panel_Button::TRIBE_Panel_Button(
    TDrawArea* area,
    TPanel* parent,
    TDigital* sound,
    void* font,
    long font_wid,
    long font_hgt,
    TShape* border_pic_param)
    : TButtonPanel() {
    // Fully verified. Source of truth: tpnl_btn.cpp.decomp @ 0x00519DA0
    this->display_garrison = 0;
    this->garrsion_number = 0;
    this->tribe_button_type = 0;
    this->border_pic = border_pic_param;
    this->color_table = nullptr;
    this->border_frame = 0;
    this->text_msg[0] = '\0';
    this->in_use = 0;

    long ok = this->setup(
        area,
        parent,
        0,
        0,
        0,
        0,
        TButtonPanel::DrawClear,
        sound,
        TButtonPanel::NotifyAction,
        -1);
    if (ok == 0) {
        this->error_code = 1;
        return;
    }

    this->set_font(font, font_wid, font_hgt);
}

TRIBE_Panel_Button::~TRIBE_Panel_Button() {
    // TODO: EMPTY_STUB - Decomp destructor iterates/free's multiple dynamic button buffers before TPanel teardown; this empty body is not parity-complete. [decomp: bucket_0519.decomp @ 0x00519E90]
}

void TRIBE_Panel_Button::set_text_msg(char* text) {
    // Fully verified. Source of truth: tpnl_btn.cpp.decomp @ 0x00519EA0
    if (text == nullptr) {
        this->text_msg[0] = '\0';
        return;
    }

    strncpy(this->text_msg, text, sizeof(this->text_msg));
    this->text_msg[sizeof(this->text_msg) - 1] = '\0';
}

int TRIBE_Panel_Button::is_inside(long param_1, long param_2) {
    // Fully verified. Source of truth: tpnl_btn.cpp.decomp @ 0x00519EE0
    if (TPanel::is_inside(param_1, param_2) == 0) {
        return 0;
    }

    if ((this->tribe_button_type == 2 || this->tribe_button_type == 3) && this->parent_panel != nullptr) {
        TPanel* overlap_panel = *(TPanel**)((char*)this->parent_panel + 0x4BC);
        if (overlap_panel != nullptr && overlap_panel->is_inside(param_1, param_2) != 0) {
            return 0;
        }
    }

    return 1;
}

void TRIBE_Panel_Button::draw() {
    // Fully verified. Source of truth: tpnl_btn.cpp.decomp @ 0x00519F40
    if (this->tribe_button_type == 3) {
        TButtonPanel::draw();
        return;
    }

    if (this->render_area == nullptr || this->active == 0 || this->visible == 0) {
        this->curr_child = nullptr;
        return;
    }

    this->draw_setup(0);
    if (this->parent_panel != nullptr) {
        this->parent_panel->draw_rect(&this->clip_rect);
    }

    int redraw_parent = 1;
    if ((this->tribe_button_type == 0 || this->tribe_button_type == 1) &&
        this->border_pic != nullptr &&
        this->render_area->Lock((char*)"tpnl_btn::draw", 1) != nullptr) {
        redraw_parent = 0;
        this->border_pic->shape_draw(
            this->render_area,
            this->pnl_x,
            this->pnl_y,
            (short)(this->is_down != 0) + this->border_frame,
            0,
            nullptr);
        this->render_area->Unlock((char*)"tpnl_btn::draw");
    }

    if (redraw_parent != 0 && this->parent_panel != nullptr) {
        this->parent_panel->draw_rect(&this->clip_rect);
    }

    if (((this->tribe_button_type != 1) && (this->tribe_button_type != 3)) || this->font == nullptr) {
        if (this->cur_state >= 0 &&
            this->pic[this->cur_state] != nullptr &&
            this->render_area->Lock((char*)"tpnl_btn::draw3", 1) != nullptr) {
            short frame = this->pic_index[this->cur_state];
            long draw_x = this->pnl_x;
            long draw_y = this->pnl_y;

            if (this->tribe_button_type == 0) {
                if (this->is_down == 0) {
                    this->render_area->SetClipRect(
                        this->clip_rect.left + 2,
                        this->pnl_y + 2,
                        this->clip_rect.right - 2,
                        this->clip_rect.bottom - 2);
                    draw_x += 2;
                    draw_y += 2;
                } else {
                    this->render_area->SetClipRect(
                        this->clip_rect.left + 3,
                        this->pnl_y + 3,
                        this->clip_rect.right - 2,
                        this->clip_rect.bottom - 3);
                    draw_x += 3;
                    draw_y += 3;
                }
            } else if (this->tribe_button_type == 1) {
                this->render_area->SetClipRect(
                    this->clip_rect.left + 1,
                    this->pnl_y + 1,
                    this->clip_rect.right - 1,
                    this->clip_rect.bottom - 1);
                draw_x += 1;
                draw_y += 1;
                if (this->is_down != 0) {
                    draw_x += 1;
                    draw_y += 1;
                }
            } else {
                if (this->is_down != 0) {
                    frame = (short)(frame + 1);
                }
            }

            if (this->disabled != 0) {
                fog_next_shape = 1;
                _ASMSet_Shadowing(0x00FF00FF, 0, (int)0xFF00FF00u, 0);
            }

            uchar* draw_color_table = nullptr;
            const int apply_color = (this->color_table != nullptr) ? 1 : 0;
            if (apply_color != 0) {
                RGE_Player* player = (rge_base_game != nullptr) ? rge_base_game->get_player() : nullptr;
                if (player != nullptr && player->color_table != nullptr) {
                    _ASMSet_Color_Xform((player->color_table->id + 1) * 0x10);
                }
                draw_color_table = this->color_table;
            }

            this->pic[this->cur_state]->shape_draw(
                this->render_area,
                draw_x,
                draw_y,
                frame,
                (uchar)apply_color,
                draw_color_table);

            if (this->disabled != 0) {
                fog_next_shape = 0;
            }
            this->render_area->Unlock((char*)"tpnl_btn::draw3");
        }
    } else {
        HDC dc = (HDC)this->render_area->GetDc((char*)"tpnl_btn::draw");
        if (dc != nullptr) {
            SelectClipRgn(dc, (HRGN)this->clip_rgn);
            void* old_font = SelectObject(dc, this->font);
            SetBkMode(dc, 1);

            const int half_w = this->pnl_wid / 2;
            const int half_h = this->pnl_hgt / 2;
            const int pressed = ((this->draw_reverse == 0) && (this->is_down != 0)) || ((this->draw_reverse != 0) && (this->is_down == 0));

            char* line1 = this->text1[this->cur_state];
            if (line1 == nullptr) {
                line1 = this->text1[0];
            }

            if (line1 != nullptr) {
                SIZE text_size;
                const int line1_len = (int)(short)strlen(line1);
                GetTextExtentPoint32A(dc, line1, line1_len, &text_size);

                long text_x = this->pnl_x + (half_w - (text_size.cx / 2));
                long text_y;
                if (this->text2[this->cur_state] != nullptr) {
                    text_y = this->pnl_y + (half_h - this->font_hgt);
                } else {
                    text_y = this->pnl_y + (half_h - (this->font_hgt / 2));
                }
                if (pressed) {
                    text_x += 1;
                    text_y += 1;
                }

                SetTextColor(dc, this->text_color2[this->cur_state]);
                TextOutA(dc, text_x - 1, text_y + 1, line1, line1_len);
                SetTextColor(dc, this->text_color1[this->cur_state]);
                TextOutA(dc, text_x, text_y, line1, line1_len);

                char* line2 = this->text2[this->cur_state];
                if (line2 == nullptr) {
                    line2 = this->text2[0];
                }
                if (line2 != nullptr) {
                    const int line2_len = (int)(short)strlen(line2);
                    GetTextExtentPoint32A(dc, line2, line2_len, &text_size);

                    long text2_x = this->pnl_x + (half_w - (text_size.cx / 2));
                    long text2_y = this->pnl_y + half_h;
                    if (pressed) {
                        text2_x += 1;
                        text2_y += 1;
                    }

                    SetTextColor(dc, this->text_color2[this->cur_state]);
                    TextOutA(dc, text2_x - 1, text2_y + 1, line2, line2_len);
                    SetTextColor(dc, this->text_color1[this->cur_state]);
                    TextOutA(dc, text2_x, text2_y, line2, line2_len);
                }
            }

            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc((char*)"tpnl_btn::draw");
        }
    }

    if (this->display_garrison != 0 && this->garrsion_number > 0) {
        HDC dc = (HDC)this->render_area->GetDc((char*)"tpnl_btn::draw2");
        if (dc != nullptr) {
            char msg[10];
            sprintf(msg, "%d", this->garrsion_number);
            SelectClipRgn(dc, (HRGN)this->clip_rgn);
            SetBkMode(dc, 1);
            SetTextColor(dc, 0x00CCCCCC);
            const int down = (this->is_down != 0) ? 1 : 0;
            TextOutA(dc, this->pnl_x + 3 + down, this->pnl_y + 2 + down, msg, (int)strlen(msg));
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc((char*)"tpnl_inv::draw2");
        }
    }

    this->draw_finish();
}

void TRIBE_Panel_Button::set_display_garrison(int value) {
    // Fully verified. Source of truth: tpnl_btn.cpp.decomp @ 0x0051A570
    this->display_garrison = value;
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Panel_Button::set_garrison_number(int value) {
    // Fully verified. Source of truth: tpnl_btn.cpp.decomp @ 0x0051A590
    this->garrsion_number = value;
    this->set_redraw(TPanel::Redraw);
}

int TRIBE_Panel_Button::get_garrison_number() {
    // Fully verified. Source of truth: tpnl_btn.cpp.decomp @ 0x0051A5B0
    return this->garrsion_number;
}
