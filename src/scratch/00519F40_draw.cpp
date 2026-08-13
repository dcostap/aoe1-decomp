// 00519F40 TRIBE_Panel_Button::draw
// Source: tpnl_btn.cpp lines 109-317, 1573 bytes
// FLAGS: default
// Attempt log:
// - Baseline: recovered TButtonPanel arrays, typed draw calls, and player color-table ownership.
// - Replaced the second shadow helper call with the binary-proven fog-state reset global.
// - Matched the packet's short frame local and char[10] garrison message buffer.
// - Restored the binary-shaped c1/c2 text-offset predicate after a direct-XOR probe lost CFG detail.
// - Replaced hand-written text scans with natural strlen calls; VC5 emitted the original scasb shape and improved positional diff by 5 bytes.
// - Best emitted code: 1191 differing bytes; current strlen source is 1217 differing bytes.
// - Left in scratch: call order and memory effects match; VC5 frame and text CFG remain nonexact.

#include "..\..\include\game_globals.h"
#include <windows.h>
#include <string.h>
#include <stdio.h>

extern const char s_tpnl_btn_draw[];
extern const char s_tpnl_btn_draw2[];
extern const char s_tpnl_btn_draw3[];

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;
    unsigned char* Lock(const char*, int);
    void Unlock(const char*);
    void* GetDc(const char*);
    void ReleaseDc(const char*);
    void SetClipRect(long, long, long, long);
};

class TShape {
public:
    char gap_00[4];
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char,
                             unsigned char*);
};

class TButtonPanel {
public:
    char gap_04[8];
    long pnl_x;
    long pnl_y;
    long pnl_cx;
    long pnl_cy;
    char gap_1C[4];
    TDrawArea* render_area;
    RECT clip_rect;
    char gap_34[4];
    int need_redraw;
    char gap_3C[4];
    TButtonPanel* parent_panel;
    char gap_44[0x28];
    int field_6C;
    int field_70;
    char gap_74[0x14];
    HRGN clip_rgn;
    char gap_8C[0xC0];
    TShape* pic[9];
    short pic_index[9];
    char gap_182[2];
    int auto_pic_pos;
    long pic_x;
    long pic_y;
    int all_hot;
    int draw_reverse;
    char* text1[9];
    char* text2[9];
    long text_x;
    long text_y;
    void* font;
    long font_wid;
    long font_hgt;
    short num_states;
    short cur_state;
    int is_down;
    TButtonPanel** radio_buttons;
    short num_radio_buttons;
    char gap_202[2];
    unsigned long button_down_time;
    unsigned long text_color1[9];
    unsigned long text_color2[9];
    unsigned long highlight_text_color1[9];
    unsigned long highlight_text_color2[9];
    long hotkey;
    int hotkey_shift;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_2AA[2];
    long key_down;
    int disabled;
    int sound_number;

    virtual ~TButtonPanel();
    virtual void v04();
    virtual void v08();
    virtual long v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void set_redraw(int);
    virtual long handle_idle();
    virtual void vf28(int);
    virtual void vf2c();
    virtual void vf30();
    virtual void get_clip_rect(RECT*);
    virtual void set_clip_rect(RECT*);
    void draw();
};

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison;
    int garrsion_number;
    unsigned char tribe_button_type;
    char gap_2C1[3];
    TShape* border_pic;
    unsigned char* color_table;
    int border_frame;
    char text_msg[0x100];
    int in_use;

    virtual void draw();
};

class RGE_Color_Table {
public:
    char gap_00[0x26];
    short id;
};

class RGE_Player {
public:
    char gap_00[0x108];
    RGE_Color_Table* color_table;
};

class RGE_Base_Game {
public:
    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;
extern int fog_next_shape;
extern "C" void __cdecl _ASMSet_Shadowing(int, int, int, int);
extern "C" void __cdecl _ASMSet_Color_Xform(int);

void TRIBE_Panel_Button::draw()
{
    if (this->tribe_button_type == 3) {
        this->TButtonPanel::draw();
        return;
    }
    if (this->render_area == 0 || this->field_70 == 0 || this->field_6C == 0) {
        this->need_redraw = 0;
        return;
    }

    this->vf28(0);
    this->parent_panel->get_clip_rect(&this->clip_rect);

    int is_drawn = 1;
    if (this->tribe_button_type == 0 || this->tribe_button_type == 1) {
        if (this->border_pic) {
            if (this->render_area->Lock(s_tpnl_btn_draw, 1)) {
                is_drawn = 0;
                this->border_pic->shape_draw(
                    this->render_area, this->pnl_x, this->pnl_y,
                    (this->is_down != 0) + this->border_frame, 0, 0);
                this->render_area->Unlock(s_tpnl_btn_draw);
            }
        }
    }
    if (is_drawn) {
        this->parent_panel->get_clip_rect(&this->clip_rect);
    }

    if ((this->tribe_button_type == 1 || this->tribe_button_type == 3) &&
        this->text1[0]) {
        HDC dc = (HDC)this->render_area->GetDc(s_tpnl_btn_draw);
        if (dc) {
            SelectClipRgn(dc, this->clip_rgn);
            HGDIOBJ old_f = SelectObject(dc, (HGDIOBJ)this->font);
            SetBkMode(dc, 1);

            int center_x = this->pnl_cx / 2;
            int center_y = this->pnl_cy / 2;

            int idx = (int)this->cur_state;
            char* text = this->text1[idx];
            if (text == 0) text = this->text1[0];

            if (text) {
                int tlen = strlen(text);

                SIZE text_size;
                GetTextExtentPoint32A(dc, text, tlen, &text_size);

                int text_x_pos = center_x - text_size.cx / 2 + this->pnl_x;

                char* text2 = this->text2[idx];
                if (text2 == 0) text2 = this->text2[0];

                int text_y_pos;
                if (text2) {
                    text_y_pos = center_y - this->font_hgt + this->pnl_y;
                } else {
                    text_y_pos = center_y - this->font_hgt / 2 + this->pnl_y;
                }

                if (text2) {
                    int c1 = (this->draw_reverse == 0 && this->is_down == 0);
                    int c2 = (this->draw_reverse != 0 && this->is_down != 0);
                    if (!(c1 || c2)) {
                        text_x_pos++;
                        text_y_pos++;
                    }
                }

                int sc = this->text_color2[idx];
                int tc = this->text_color1[idx];

                SetTextColor(dc, sc);
                TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text, tlen);
                SetTextColor(dc, tc);
                TextOutA(dc, text_x_pos, text_y_pos, text, tlen);

                if (text2) {
                    int t2len = strlen(text2);
                    
                    GetTextExtentPoint32A(dc, text2, t2len, &text_size);

                    int t2_x = center_x - text_size.cx / 2 + this->pnl_x;
                    int t2_y = center_y + this->pnl_y;

                    int sc = this->text_color2[idx];
                    int tc = this->text_color1[idx];

                    SetTextColor(dc, sc);
                    TextOutA(dc, t2_x - 1, t2_y + 1, text2, t2len);
                    SetTextColor(dc, tc);
                    TextOutA(dc, t2_x, t2_y, text2, t2len);
                }
            }

            SelectObject(dc, old_f);
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc(s_tpnl_btn_draw);
        }
    } else if (this->pic[0] && this->pic_index[0] >= 0) {
        if (this->render_area->Lock(s_tpnl_btn_draw3, 1)) {
            short frame = this->pic_index[0];
            int draw_x = this->pnl_x;
            int draw_y = this->pnl_y;

            if (this->tribe_button_type == 0) {
                if (this->is_down) {
                    this->render_area->SetClipRect(
                        this->clip_rect.left + 3, this->clip_rect.top + 3,
                        this->clip_rect.right - 2, this->clip_rect.bottom - 3);
                    draw_x += 3; draw_y += 3;
                } else {
                    this->render_area->SetClipRect(
                        this->clip_rect.left + 2, this->clip_rect.top + 2,
                        this->clip_rect.right - 2, this->clip_rect.bottom - 2);
                    draw_x += 2; draw_y += 2;
                }
            } else if (this->tribe_button_type == 1) {
                draw_x++;
                draw_y++;
                this->render_area->SetClipRect(
                    this->clip_rect.left + 1, this->clip_rect.top + 1,
                    this->clip_rect.right - 1, this->clip_rect.bottom - 1);
                if (this->is_down) {
                    draw_x++;
                    draw_y++;
                }
            } else {
                if (this->is_down) {
                    frame++;
                }
            }

            if (this->disabled) {
                fog_next_shape = 1;
                _ASMSet_Shadowing(0xFF00FF, 0, 0x00FF00FF, 0);
            }

            if (this->color_table) {
                _ASMSet_Color_Xform(
                    (rge_base_game->get_player()->color_table->id + 1) * 0x10);
                this->pic[0]->shape_draw(this->render_area, draw_x, draw_y,
                                         frame, 1,
                                         this->color_table);
            } else {
                this->pic[0]->shape_draw(this->render_area, draw_x, draw_y,
                                         frame, 0, 0);
            }

            if (this->disabled)
                fog_next_shape = 0;
            this->render_area->Unlock(s_tpnl_btn_draw3);
        }
    }

    if (this->display_garrison && this->garrsion_number > 0) {
        HDC gdc = (HDC)this->render_area->GetDc(s_tpnl_btn_draw2);
        if (gdc) {
            char msg[10];
            sprintf(msg, "%d", this->garrsion_number);

            int hf = this->is_down ? 1 : 0;
            int xpos = this->pnl_x + 3 + hf;
            int ypos = this->pnl_y + 2 + hf;

            SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
            SetBkMode(this->render_area->DrawDc, 1);
            SetTextColor(this->render_area->DrawDc, 0xCCCCCC);
            TextOutA(this->render_area->DrawDc, xpos, ypos, msg, strlen(msg));
            SelectClipRgn(this->render_area->DrawDc, 0);

            this->render_area->ReleaseDc(s_tpnl_btn_draw2);
        }
    }

    this->vf2c();
}
