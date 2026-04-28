// 00519F40 TRIBE_Panel_Button::draw
// Source: tpnl_btn.cpp lines 109-317, 1573 bytes
// FLAGS: default
// Best variant: variant_lab G0000 (int* vt pattern), verified 1536 bytes
// Attempt log:
// - Original scratch: comments-only. Built from scratch: 47% -> 79% -> 96.6% -> 98.7%
// - variant_lab showed sub esp=38h vs 2Ch — excess locals. Reduced stack from 0x38 to 0x34.
// - Current best: 1536/1573 (97.6%), matching lab G0000 group
// - First mismatch: sub esp=38h vs 2Ch (12 bytes excess stack from extra locals)
// - Remaining gap: VC5 backend stack frame allocation and register scheduling
// Left in scratch; structurally complete

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
    void* Lock(const char*, int);
    void Unlock(const char*);
    void* GetDc(const char*);
    void ReleaseDc(const char*);
    void SetClipRect(long, long, long, long);
};

class TShape {
public:
    char gap_00[4];
    void shape_draw(TDrawArea*, int, int, int, int, unsigned char*);
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
    long clip_x1;
    long clip_y1;
    long clip_x2;
    long clip_y2;
    char gap_34[0x0C];
    TButtonPanel* parent_panel;
    char gap_44[0x28];
    int field_6C;
    int field_70;
    char gap_74[0x14];
    HRGN clip_rgn;
    char gap_8C[0xC0];
    int shape_ptr;
    char gap_150[0x20];
    short frame_val;
    char gap_172[0x22];
    int text_flags;
    char* text1_ptr;
    char gap_19C[0x20];
    char* text2_ptr;
    char gap_1C0[0x28];
    void* ufont;
    int offs_val;
    short text_idx;
    int has_text2;
    char gap_1FC[0x0C];
    int text_clr;
    char gap_20C[0x20];
    int shadow_clr;
    char gap_230[0x80];
    int fog_on;
    char gap_2B4[4];
    int show_garr;
    int garr_num;
    unsigned char btn_type;
    char gap_2C1[3];
    int border_shape;
    unsigned char* color_tbl;
    int border_frm;

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
    virtual void draw();
};

class TRIBE_Panel_Button : public TButtonPanel {
public:
    virtual void draw();
};

void _ASMSet_Shadowing(int, int, int, int);
void _ASMSet_Color_Xform(int);

void TRIBE_Panel_Button::draw()
{
    if (this->btn_type == 3) {
        this->TButtonPanel::draw();
        return;
    }
    if (this->render_area == 0 || this->field_70 == 0 || this->field_6C == 0) {
        *(int*)((int)this + 0x38) = 0;
        return;
    }

    int* vt = *(int**)this;
    ((void(*)(TRIBE_Panel_Button*, int))vt[0x28/4])(this, 0);
    ((void(*)(TButtonPanel*, RECT*))((int**)this->parent_panel)[0x34/4])(this->parent_panel, (RECT*)&this->clip_x1);

    int is_drawn = 1;
    if (this->btn_type == 0 || this->btn_type == 1) {
        if (this->border_shape) {
            if (this->render_area->Lock(s_tpnl_btn_draw, 1)) {
                is_drawn = 0;
                ((TShape*)this->border_shape)->shape_draw(
                    this->render_area, this->pnl_x, this->pnl_y,
                    (this->has_text2 != 0) + this->border_frm, 0, 0);
                this->render_area->Unlock(s_tpnl_btn_draw);
            }
        }
    }
    if (is_drawn) {
        ((void(*)(TButtonPanel*, RECT*))((int**)this->parent_panel)[0x34/4])(this->parent_panel, (RECT*)&this->clip_x1);
    }

    if ((this->btn_type == 1 || this->btn_type == 3) && this->text1_ptr) {
        HDC dc = (HDC)this->render_area->GetDc(s_tpnl_btn_draw);
        if (dc) {
            SelectClipRgn(dc, this->clip_rgn);
            HGDIOBJ old_f = SelectObject(dc, (HGDIOBJ)this->ufont);
            SetBkMode(dc, 1);

            int center_x = this->pnl_cx / 2;
            int center_y = this->pnl_cy / 2;

            int idx = (int)(short)this->text_idx;
            char* text = *(char**)((int)this + 0x198 + idx * 4);
            if (text == 0) text = (char*)this->text1_ptr;

            if (text) {
                int tlen = 0;
                char* tp = text;
                while (*tp) { tlen++; tp++; }

                SIZE tsz;
                GetTextExtentPoint32A(dc, text, tlen, &tsz);

                int text_x_pos = center_x - tsz.cx / 2 + this->pnl_x;

                char* text2 = *(char**)((int)this + 0x1BC + idx * 4);
                if (text2 == 0) text2 = (char*)this->text2_ptr;

                int text_y_pos;
                if (text2) {
                    text_y_pos = center_y - this->offs_val + this->pnl_y;
                } else {
                    text_y_pos = center_y - this->offs_val / 2 + this->pnl_y;
                }

                if (text2) {
                    int c1 = (this->text_flags == 0 && this->has_text2 == 0);
                    int c2 = (this->text_flags != 0 && this->has_text2 != 0);
                    if (!(c1 || c2)) { text_x_pos++; text_y_pos++; }
                }

                int sc = *(int*)((int)this + 0x22C + idx * 4);
                int tc = *(int*)((int)this + 0x208 + idx * 4);

                SetTextColor(dc, sc);
                TextOutA(dc, text_x_pos - 1, text_y_pos + 1, text, tlen);
                SetTextColor(dc, tc);
                TextOutA(dc, text_x_pos, text_y_pos, text, tlen);

                if (text2) {
                    int t2len = 0;
                    char* t2p = text2;
                    while (*t2p) { t2len++; t2p++; }
                    
                    SIZE tsz2;
                    GetTextExtentPoint32A(dc, text2, t2len, &tsz2);

                    int t2_x = center_x - tsz2.cx / 2 + this->pnl_x;
                    int t2_y = center_y + this->pnl_y;

                    int sc = *(int*)((int)this + 0x22C + idx * 4);
                    int tc = *(int*)((int)this + 0x208 + idx * 4);

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
    } else if (this->shape_ptr && (signed short)this->frame_val >= 0) {
        if (this->render_area->Lock(s_tpnl_btn_draw3, 1)) {
            int draw_x = this->pnl_x;
            int draw_y = this->pnl_y;

            if (this->btn_type == 0) {
                if (this->has_text2) {
                    this->render_area->SetClipRect(
                        this->clip_x1 + 3, this->clip_y1 + 3,
                        this->clip_x2 - 2, this->clip_y2 - 3);
                    draw_x += 3; draw_y += 3;
                } else {
                    this->render_area->SetClipRect(
                        this->clip_x1 + 2, this->clip_y1 + 2,
                        this->clip_x2 - 2, this->clip_y2 - 2);
                    draw_x += 2; draw_y += 2;
                }
            } else if (this->btn_type == 1) {
                draw_x++;
                draw_y++;
                this->render_area->SetClipRect(
                    this->clip_x1 + 1, this->clip_y1 + 1,
                    this->clip_x2 - 1, this->clip_y2 - 1);
                if (this->has_text2) {
                    draw_x++;
                    draw_y++;
                }
            } else {
                if (this->has_text2) {
                    this->frame_val++;
                }
            }

            if (this->fog_on)
                _ASMSet_Shadowing(0xFF00FF, 0, 0x00FF00FF, 0);

            if (this->color_tbl) {
                _ASMSet_Color_Xform(*(int*)this->color_tbl);
                ((TShape*)this->shape_ptr)->shape_draw(this->render_area, draw_x, draw_y, this->frame_val, 1, this->color_tbl);
            } else {
                ((TShape*)this->shape_ptr)->shape_draw(this->render_area, draw_x, draw_y, this->frame_val, 0, 0);
            }

            if (this->fog_on)
                _ASMSet_Shadowing(0, 0, 0, 0);
            this->render_area->Unlock(s_tpnl_btn_draw3);
        }
    }

    if (this->show_garr && this->garr_num > 0) {
        HDC gdc = (HDC)this->render_area->GetDc(s_tpnl_btn_draw2);
        if (gdc) {
            char buf[16];
            sprintf(buf, "%d", this->garr_num);

            int hf = this->has_text2 ? 1 : 0;
            int xpos = this->pnl_x + 3 + hf;
            int ypos = this->pnl_y + 2 + hf;

            SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
            SetBkMode(this->render_area->DrawDc, 1);
            SetTextColor(this->render_area->DrawDc, 0xCCCCCC);
            TextOutA(this->render_area->DrawDc, xpos, ypos, buf, strlen(buf));
            SelectClipRgn(this->render_area->DrawDc, 0);

            this->render_area->ReleaseDc(s_tpnl_btn_draw2);
        }
    }

    ((void(*)(TRIBE_Panel_Button*))vt[0x2C/4])(this);
}
