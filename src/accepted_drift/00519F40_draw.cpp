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
// - Hoisted SIZE and msg to function scope from the binary local map; frame grew to 0x38 with no diff gain, then restored.
// - Tried the Ghidra local map with shared x/y/frame locals and direct state indexing; frame reached 0x28 but diff worsened to 1266, then restored.
// - Moved center calculations before text selection per original 0051A074 order; shape and diff worsened, then restored.
// - Tested explicit same-TU DLL-import declarations for the GDI and sprintf calls; VC5 output was unchanged, then restored.
// - Tested /GX from the exact same-TU constructor; VC5 output was unchanged, then removed the custom flag file.
// - Removed the cached state index; direct cur_state indexing improved frame and block shape but worsened positional diff.
// - Reloaded text2 after the first line; original reloads it before the second extent call.
// - Reused one x/y local for both text lines; this improved resync similarity without changing size.
// - Kept the first text2 layout test separate from the later text2[0] fallback, matching original branch behavior.
// - Applied the text offset predicate unconditionally; original converges both text2 layout paths before that test.
// - Function-scope center_y, frame, and text declarations matched no new emitted code; kept as natural local-map reconstruction.
// - New pass: tested 29 meaningful source hypotheses against the original.
// - Explicit positive/else text fallbacks restored the original branch shape.
// - Short text lengths restored the original movsx and stack-length paths.
// - Direct color-member rereads restored the original GDI load order.
// - Inline garrison coordinates restored the delayed message-position schedule.
// - Repeated the offset predicate for the second text line, as the binary proves.
// - Function-scope SIZE restored the 0x2C frame and exact total code size.
// - Reversed picture clip-arm source order restored most picture CFG shape.
// - Staged border-frame arithmetic and branch-local picture coordinates improved alignment.
// - Best final clean result: 575 differing bytes, 95.20% shape similarity,
//   55.49% exact-block coverage, 42/42 aligned calls, and matching frame/size.
// - Remaining drift is concentrated in register allocation, stack-slot reuse,
//   and four CFG edge shapes. No exact result reached in this pass.
// - Left in scratch: ordered calls and memory effects match; VC5 frame and text CFG remain nonexact.
// Accepted-drift review: the residual is border-frame boolean register choice,
// rotated private text-coordinate and length homes, and swapped EBX/EDI roles
// that preserve shape_draw argument positions. A later global zero store only
// shifts with the basin. All 42 calls, arguments, reads, panel stores, GDI
// state, unlocks, and returns match.
// Context pass 2026-08-23: canonical TPanel, TButtonPanel, TRIBE_Panel_Button,
// TDrawArea, TShape, and game color-table surfaces now compile through the
// PDB-ordered tpnl_btn_tu.cpp wrapper. The /GX grouped build preserves the
// 1573-byte frame and all 42 calls and reduces the relocation-masked body
// difference to 494 bytes. The standalone owner remains the 575-byte clean
// accepted-drift basin until the wrapper is registered.
// Exact-finish pass 2026-08-23: tested the canonical object-panel header,
// border-frame expression order, local declaration order and scope, picture
// coordinate types and aliases, and picture branch forms.
// A delayed pnl_y load reduced the standalone difference to 114 bytes and
// restored exact size, but moved the field read after SetClipRect. This fails
// the original fault order, so it was restored.
// PDB local symbols list one text pointer, not a text2 pointer. Reusing text
// for the second line restores the original text and x stack homes and reduces
// the standalone difference to 560 bytes. The PDB local declaration order was
// also tested and emits the same bytes.
// Reversing picture-coordinate updates restores size but moves the type-1 x
// field read after the type compare. This fails the original fault order.
// No tested natural form fixed the border EAX/EBX map or picture EDI/EBX map.
// Final source retains the PDB-supported text-local reduction at 560 bytes.

#include "..\..\include\game_globals.h"
#include <windows.h>
#include <string.h>
#include <stdio.h>

extern const char s_tpnl_btn_draw[];
extern const char s_tpnl_btn_draw2[];
extern const char s_tpnl_btn_draw3[];

#ifndef TPNL_BTN_SHARED_CONTEXT
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
#else
#include "../../include/tpnl_btn_context.h"
#endif

extern RGE_Base_Game* rge_base_game;
extern int fog_next_shape;
extern "C" void __cdecl _ASMSet_Shadowing(int, int, int, int);
extern "C" void __cdecl _ASMSet_Color_Xform(int);

void TRIBE_Panel_Button::draw()
{
    HGDIOBJ old_f;
    long calc_y;
    long y;
    short frame;
    long x;
    char* text;
    SIZE text_size;
    short tlen;

    if (this->tribe_button_type == 3) {
        this->TButtonPanel::draw();
        return;
    }
    if (this->render_area == 0 || this->field_70 == 0 || this->field_6C == 0) {
        this->need_redraw = 0;
        return;
    }

#ifdef TPNL_BTN_SHARED_CONTEXT
    this->draw_setup(0);
#else
    this->vf28(0);
#endif
    this->parent_panel->get_clip_rect(&this->clip_rect);

    int is_drawn = 1;
    if (this->tribe_button_type == 0 || this->tribe_button_type == 1) {
        if (this->border_pic) {
            if (this->render_area->Lock(s_tpnl_btn_draw, 1)) {
                is_drawn = 0;
                long border_frame = (this->is_down != 0);
                border_frame += this->border_frame;
                this->border_pic->shape_draw(
                    this->render_area, this->pnl_x, this->pnl_y,
                    border_frame, 0, 0);
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
            old_f = SelectObject(dc, (HGDIOBJ)this->font);
            SetBkMode(dc, 1);

            int center_x = this->pnl_cx / 2;
            calc_y = this->pnl_cy / 2;

            if (this->text1[this->cur_state]) {
                text = this->text1[this->cur_state];
            } else {
                text = this->text1[0];
            }

            if (text) {
                tlen = strlen(text);

                GetTextExtentPoint32A(dc, text, tlen, &text_size);

                x = center_x - text_size.cx / 2 + this->pnl_x;

                y = 0;
                if (this->text2[this->cur_state]) {
                    y = calc_y - this->font_hgt + this->pnl_y;
                } else {
                    y = calc_y - this->font_hgt / 2 + this->pnl_y;
                }

                if ((this->draw_reverse == 0 && this->is_down != 0) ||
                    (this->draw_reverse != 0 && this->is_down == 0)) {
                    x++;
                    y++;
                }

                SetTextColor(dc, this->text_color2[this->cur_state]);
                TextOutA(dc, x - 1, y + 1, text, tlen);
                SetTextColor(dc, this->text_color1[this->cur_state]);
                TextOutA(dc, x, y, text, tlen);

                if (this->text2[this->cur_state]) {
                    text = this->text2[this->cur_state];
                } else {
                    text = this->text2[0];
                }
                if (text) {
                    short t2len = strlen(text);

                    GetTextExtentPoint32A(dc, text, t2len, &text_size);

                    x = center_x - text_size.cx / 2 + this->pnl_x;
                    y = calc_y + this->pnl_y;

                    if ((this->draw_reverse == 0 && this->is_down != 0) ||
                        (this->draw_reverse != 0 && this->is_down == 0)) {
                        x++;
                        y++;
                    }

                    SetTextColor(dc, this->text_color2[this->cur_state]);
                    TextOutA(dc, x - 1, y + 1, text, t2len);
                    SetTextColor(dc, this->text_color1[this->cur_state]);
                    TextOutA(dc, x, y, text, t2len);
                }
            }

            SelectObject(dc, old_f);
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc(s_tpnl_btn_draw);
        }
    } else if (this->pic[0] && this->pic_index[0] >= 0) {
        if (this->render_area->Lock(s_tpnl_btn_draw3, 1)) {
            frame = this->pic_index[0];

            if (this->tribe_button_type == 0) {
                x = this->pnl_x;
                if (!this->is_down) {
                    y = this->pnl_y;
                    this->render_area->SetClipRect(
                        this->clip_rect.left + 2, this->clip_rect.top + 2,
                        this->clip_rect.right - 2, this->clip_rect.bottom - 2);
                    x += 2; y += 2;
                } else {
                    y = this->pnl_y;
                    this->render_area->SetClipRect(
                        this->clip_rect.left + 3, this->clip_rect.top + 3,
                        this->clip_rect.right - 2, this->clip_rect.bottom - 3);
                    x += 3; y += 3;
                }
            } else if (this->tribe_button_type == 1) {
                x = this->pnl_x;
                y = this->pnl_y;
                x++;
                y++;
                this->render_area->SetClipRect(
                    this->clip_rect.left + 1, this->clip_rect.top + 1,
                    this->clip_rect.right - 1, this->clip_rect.bottom - 1);
                if (this->is_down) {
                    x++;
                    y++;
                }
            } else {
                x = this->pnl_x;
                y = this->pnl_y;
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
                this->pic[0]->shape_draw(this->render_area, x, y,
                                         frame, 1,
                                         this->color_table);
            } else {
                this->pic[0]->shape_draw(this->render_area, x, y,
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

            SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
            SetBkMode(this->render_area->DrawDc, 1);
            SetTextColor(this->render_area->DrawDc, 0xCCCCCC);
            TextOutA(this->render_area->DrawDc,
                     this->pnl_x + 3 + (this->is_down != 0),
                     this->pnl_y + 2 + (this->is_down != 0),
                     msg, strlen(msg));
            SelectClipRgn(this->render_area->DrawDc, 0);

            this->render_area->ReleaseDc(s_tpnl_btn_draw2);
        }
    }

#ifdef TPNL_BTN_SHARED_CONTEXT
    this->draw_finish();
#else
    this->vf2c();
#endif
}
