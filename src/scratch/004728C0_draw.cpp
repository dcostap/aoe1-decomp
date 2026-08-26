// VA: 004728C0 TButtonPanel::draw (2097 B)
// PDB source: Pnl_btn.cpp lines 586-840
// __thiscall this, returns void
//
// Canonical ownership (binary-proven offsets, matches 00471EC0 donor):
//   TPanel: +0x00 vtable, +0x0C pnl_x, +0x10 pnl_y, +0x14 pnl_wid,
//     +0x18 pnl_hgt, +0x20 render_area(TDrawArea*), +0x24 clip_rect(tagRECT),
//     +0x38 need_redraw, +0x40 parent_panel, +0x6C active, +0x70 visible,
//     +0x78 have_focus, +0x84 just_drawn, +0x88 clip_rgn, +0xEF color.
//   TButtonPanel: +0x140 drawTypeValue, +0x14C pic[9], +0x170 pic_index[9],
//     +0x184 auto_pic_pos, +0x188 pic_x, +0x18C pic_y, +0x194 draw_reverse,
//     +0x198 text1[9], +0x1BC text2[9], +0x1E0 text_x, +0x1E4 text_y,
//     +0x1E8 font, +0x1F0 font_hgt, +0x1F6 cur_state, +0x1F8 is_down,
//     +0x208 text_color1[9], +0x22C text_color2[9], +0x250 htext_color1[9],
//     +0x274 htext_color2[9], +0x2A0 bevel_type, +0x2A4..+0x2A9 bevel_color1-6,
//     +0x2B0 disabled.
// Virtual slots: this 0x28 draw_setup(int), 0x2C draw_finish();
//   parent 0x34/0x3C with one tagRECT* each. IAT: SelectClipRgn(88A5DC),
//   SelectObject(88A59C), SetBkMode(88A5EC), GetTextExtentPoint32A(88A5E8),
//   SetTextColor(88A5E4), TextOutA(88A5E0).
// Direct helpers (Drawarea.cpp / Shape.cpp thiscall): Clear 00444680,
//   Lock 00444270, Unlock 00444300, GetDc 00444340, ReleaseDc 00444390,
//   DrawRect 004459A0, DrawHorzLine 00445A60, DrawVertLine 00445AF0,
//   DrawBevel 00445C70, DrawBevel2 00445D20, DrawBevel3 00445E40,
//   DrawBevel21 00445FE0, DrawBevel32 004460C0, shape_minmax 004B9070,
//   shape_draw 004B9440.
//
// Attempt log:
// - baseline: full natural guarded reconstruction from original asm + PDB line
//   map per the matched Pnl_btn/Drawarea donors. Clean canonical source.
// - vslot fix: padded TPanel virtuals so slots land at 0x28 draw_setup / 0x2C
//   draw_finish / 0x34 / 0x3C (was off by one).
// - tagSIZE: reuse one text_size slot for both GetTextExtentPoint32A calls
//   (original reuses one stack slot); fixed frame 0x38->0x30.
// - bevel: placed UP arm first (condition dr != down) to match original
//   physical layout; DOWN second (dr == down). Ordered call alignment
//   86.96% -> 95.65%.
// Remaining drift (not yet proven behavior-equivalent):
//   * original keeps a dedicated zero in EBP (xor ebp,ebp) for all null guards
//     and need_redraw=0 (`cmp X,ebp`), rebuilt uses `test` intermediates.
//   * TextOutA IAT pointer is cached in a register (mov ebp,[88A5E0]) by the
//     original; rebuilt re-issues indirect calls.
//   * the two switch case-1 DrawRect(0xFF) calls are tail-merged by rebuilt
//     (3 vs 4 drawrect count); original keeps them as separate blocks while
//     sharing only the case-2 DrawBevel tail.
// Disabled-branch, pic/text/GetDc/GDI structure are reconstructed, but the
// missing call sites and broad structural drift still require exact work.
// - Binary branch audit: the first bevel switch is selected when
//   draw_reverse XOR is_down, not when their OR is true; the restored XOR
//   source preserves the original 00472E7D-00472EA7 predicate topology.
// Orchestrator layout audit: removed an erroneous 4-byte gap before clip_rgn;
// just_drawn ends at +0x88, so clip_rgn itself is at the proven +0x88 offset.
// Main-agent audit confirmed canonical panel/button/draw-area/shape ownership
// and removed redundant string-address casts; missing call structure remains.
// Binary operand audit: UP bevel case 1 draws from pnl_x+1,pnl_y+1; DOWN
// case 1 draws from pnl_x,pnl_y. Keeping these distinct restores the fourth
// DrawRect call and improves structural parity.
// - Probe record (23 meaningful variants): the clean source remains the best
//   call-surface model at 45/46 calls, 2044 bytes, and 1838-byte diff.
//   A windows.h + RECT/SIZE context improved shape (72.99%) and diff (1837),
//   but lost two indirect calls and shortened the body by 16 bytes.
//   Reversed have_focus source order improved shape in a combined context,
//   but retained the two-call gap. Explicit zero locals and zero casts were
//   codegen duplicates. Explicit no-redraw gotos were worse.
//   Direct this->pic[cur_state] reloads matched the minmax receiver setup and
//   raised exact-block coverage, but caused broad register drift; the named
//   alias remains the cleaner current source model. Coordinate operand-order
//   probes did not change the emitted code after the first schedule change.
// - Current pass: focus text arms are written first in both text passes. This
//   matches the original fall-through blocks and improves shape by 3.30 points
//   and exact-block coverage by 0.86 points. The one indirect TextOut gap stays.
//   Scoped zero locals and local TextOut pointer forms were codegen duplicates.

#include <string.h>

extern const char s_pnl_btn_draw[];    // "pnl_btn::draw" @ 0x5852F8
extern const char s_pnl_btn_draw2[];   // "pnl_btn::draw2" @ 0x5852E8

extern "C" {
__declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* object);
__declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* rgn);
__declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);
__declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color);
__declspec(dllimport) int __stdcall TextOutA(void* hdc, int x, int y, const char* s, int len);
#ifndef PNL_BTN_SHARED_CONTEXT
__declspec(dllimport) int __stdcall GetTextExtentPoint32A(void* hdc, const char* s, int len, void* size);
#endif
}

#ifndef PNL_BTN_SHARED_CONTEXT
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
struct tagSIZE {
    long cx;
    long cy;
};
#endif /* PNL_BTN_SHARED_CONTEXT */

class TPanel;
class TButtonPanel;

void TButtonPanel::draw()
{
    long x_min, y_min, x_max, y_max;
    int text_len;
    char* text;
    long x, y;

    if (this->render_area == 0 || this->visible == 0 || this->active == 0 ||
        this->drawTypeValue == 1) {
        this->need_redraw = 0;
        return;
    }

    if (this->drawTypeValue == 5) {
        this->render_area->Clear(&this->clip_rect, this->color);
    } else {
        TPanel* parent = this->parent_panel;
        if (parent != 0) {
            if (this->bevel_type >= 2 && this->bevel_type <= 4) {
                parent->draw_rect2(&this->clip_rect);
            } else if (parent->just_drawn == 0) {
                parent->draw_rect(&this->clip_rect);
            }
        }
    }

    this->draw_setup(0);

    if (this->drawTypeValue == 2 || this->drawTypeValue == 4 ||
        this->drawTypeValue == 6) {
        if (this->render_area->Lock(s_pnl_btn_draw, 1) != 0) {
            TShape* pic = this->pic[this->cur_state];
            if (pic != 0) {
                if (this->auto_pic_pos != 0) {
                    pic->shape_minmax(&x_min, &y_min, &x_max, &y_max,
                                      this->pic_index[this->cur_state]);
                    this->pic_x = (short)((this->pnl_wid / 2) -
                                          (((x_max - x_min) + 1) / 2) - x_min);
                    this->pic_y = (short)((this->pnl_hgt / 2) -
                                          (((y_max - y_min) + 1) / 2) - y_min);
                }
                x = this->pic_x + this->pnl_x;
                y = this->pic_y + this->pnl_y;
                if (this->draw_reverse == 0) {
                    if (this->is_down != 0) {
                        x = x + 1;
                        y = y - 1;
                    }
                } else if (this->is_down == 0) {
                    x = x + 1;
                    y = y - 1;
                }
                pic->shape_draw(this->render_area, x, y,
                                this->pic_index[this->cur_state], 0, 0);
            }
            this->render_area->Unlock(s_pnl_btn_draw);
        }
    }

    if (this->drawTypeValue == 3 || this->drawTypeValue == 4 ||
        this->drawTypeValue == 5) {
        void* dc = this->render_area->GetDc(s_pnl_btn_draw);
        if (dc != 0) {
            SelectClipRgn(dc, this->clip_rgn);
            void* old_font = SelectObject(dc, this->font);
            SetBkMode(dc, 1);

            long tx = this->text_x;
            if (tx == -1) {
                tx = this->pnl_wid / 2;
            }
            long ty = this->text_y;
            if (ty == -1) {
                ty = this->pnl_hgt / 2;
            }

            text = this->text1[this->cur_state];
            if (text == 0) {
                text = this->text1[0];
            }
            if (text != 0) {
                text_len = (short)strlen(text);
                tagSIZE text_size;
                GetTextExtentPoint32A(dc, text, text_len, &text_size);
                x = (tx - text_size.cx / 2) + this->pnl_x;
                long fontH = this->font_hgt;
                if (this->text2[this->cur_state] == 0) {
                    fontH = this->font_hgt / 2;
                }
                y = (ty - fontH) + this->pnl_y;
                if (this->draw_reverse == 0) {
                    if (this->is_down != 0) {
                        x = x + 1;
                        y = y - 1;
                    }
                } else if (this->is_down == 0) {
                    x = x + 1;
                    y = y - 1;
                }
                if (this->have_focus != 0) {
                    SetTextColor(dc, this->highlight_text_color2[this->cur_state]);
                    TextOutA(dc, x - 1, y + 1, text, text_len);
                    SetTextColor(dc, this->highlight_text_color1[this->cur_state]);
                    TextOutA(dc, x, y, text, text_len);
                } else {
                    SetTextColor(dc, this->text_color2[this->cur_state]);
                    TextOutA(dc, x - 1, y + 1, text, text_len);
                    SetTextColor(dc, this->text_color1[this->cur_state]);
                    TextOutA(dc, x, y, text, text_len);
                }

                text = this->text2[this->cur_state];
                if (text == 0) {
                    text = this->text2[0];
                }
                if (text != 0) {
                    text_len = (short)strlen(text);
                    GetTextExtentPoint32A(dc, text, text_len, &text_size);
                    x = (tx - text_size.cx / 2) + this->pnl_x;
                    y = ty + this->pnl_y;
                    if (this->draw_reverse == 0) {
                        if (this->is_down != 0) {
                            x = x + 1;
                            y = y - 1;
                        }
                    } else if (this->is_down == 0) {
                        x = x + 1;
                        y = y - 1;
                    }
                    if (this->have_focus != 0) {
                        SetTextColor(dc, this->highlight_text_color2[this->cur_state]);
                        TextOutA(dc, x - 1, y + 1, text, text_len);
                        SetTextColor(dc, this->highlight_text_color1[this->cur_state]);
                        TextOutA(dc, x, y, text, text_len);
                    } else {
                        SetTextColor(dc, this->text_color2[this->cur_state]);
                        TextOutA(dc, x - 1, y + 1, text, text_len);
                        SetTextColor(dc, this->text_color1[this->cur_state]);
                        TextOutA(dc, x, y, text, text_len);
                    }
                }
            }
            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc(s_pnl_btn_draw);
        }
    }

    if (this->drawTypeValue == 3 || this->drawTypeValue == 4 ||
        this->drawTypeValue == 5 || this->drawTypeValue == 6) {
        if (this->render_area->Lock(s_pnl_btn_draw2, 1) != 0) {
            if (this->disabled != 0) {
                this->render_area->DrawRect(this->pnl_x, this->pnl_y,
                        this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color6);
                this->render_area->DrawRect(this->pnl_x + 1, this->pnl_y + 1,
                        this->pnl_x + this->pnl_wid - 2, this->pnl_y + this->pnl_hgt - 2,
                        this->bevel_color1);
            } else if ((this->draw_reverse != 0) != (this->is_down != 0)) {
                // UP shape (this placed first in binary)
                switch (this->bevel_type) {
                case 1:
                    this->render_area->DrawRect(this->pnl_x + 1, this->pnl_y + 1,
                        this->pnl_x + this->pnl_wid - 2, this->pnl_y + this->pnl_hgt - 2, 0xFF);
                    break;
                case 2:
                    this->render_area->DrawBevel(this->pnl_x, this->pnl_y,
                        this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color6, this->bevel_color1);
                    break;
                case 3:
                    this->render_area->DrawBevel21(this->pnl_x, this->pnl_y,
                        this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color6, this->bevel_color5,
                        this->bevel_color2, this->bevel_color1);
                    break;
                case 4:
                    this->render_area->DrawBevel32(this->pnl_x, this->pnl_y,
                        this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color6, this->bevel_color5, this->bevel_color4,
                        this->bevel_color3, this->bevel_color2, this->bevel_color1);
                    break;
                }
            } else {
                // DOWN shape
                switch (this->bevel_type) {
                case 1:
                    this->render_area->DrawVertLine(this->pnl_x, this->pnl_y,
                        this->pnl_y + this->pnl_hgt - 1, 0);
                    this->render_area->DrawHorzLine(this->pnl_x + 1, this->pnl_x + this->pnl_wid - 1,
                        this->pnl_y + this->pnl_hgt - 1, 0);
                    this->render_area->DrawRect(this->pnl_x, this->pnl_y,
                        this->pnl_x + this->pnl_wid - 2, this->pnl_y + this->pnl_hgt - 2, 0xFF);
                    break;
                case 2:
                    this->render_area->DrawBevel(this->pnl_x, this->pnl_y,
                        this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color1, this->bevel_color6);
                    break;
                case 3:
                    this->render_area->DrawBevel2(this->pnl_x, this->pnl_y,
                        this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color3, this->bevel_color4,
                        this->bevel_color5, this->bevel_color6);
                    break;
                case 4:
                    this->render_area->DrawBevel3(this->pnl_x, this->pnl_y,
                        this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                        this->bevel_color1, this->bevel_color2, this->bevel_color3,
                        this->bevel_color4, this->bevel_color5, this->bevel_color6);
                    break;
                }
            }
            this->render_area->Unlock(s_pnl_btn_draw2);
        }
    }

    this->draw_finish();
}
