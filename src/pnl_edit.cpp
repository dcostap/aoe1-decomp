#include "../include/pnl_edit.h"
#include "../include/game_globals.h"
#include <stdlib.h>
#include <string.h>

#include <mbstring.h>
extern int MouseCursorInChildContol;
extern int imc_retval;

static long __stdcall pnl_sub_wnd_proc(HWND wnd, unsigned int msg,
                                       unsigned int wparam, long lparam) {
    TEditPanel* panel = (TEditPanel*)GetWindowLongA(wnd, GWL_USERDATA);
    if (panel != 0) {
        return panel->sub_wnd_proc(wnd, msg, wparam, lparam);
    }
    return 0;
}

// pnl_edit.cpp lines 50-75.
TEditPanel::TEditPanel() : TPanel() {
    edit_wnd = 0;
    text = 0;
    fixed_len = 0;
    brush = 0;
    old_sub_wnd_proc = 0;
    text_color1 = 0;
    text_color2 = 0;
    highlight_text_color1 = 0;
    highlight_text_color2 = 0;
    back_color = 0;
    sel_len = 0;
    bevel_color1 = 0;
    bevel_color2 = 0;
    bevel_color3 = 0;
    bevel_color4 = 0;
    bevel_color5 = 0;
    bevel_color6 = 0;
    bevel_size = 0;
    imc = 0;
    enable_ime = 0;
    handle_mouse_input = 1;
    hidden = 1;
    bevel_type = 1;
    turn_ime_on = 0;
}

// pnl_edit.cpp lines 83-112.
TEditPanel::~TEditPanel() {
    if (this->edit_wnd != 0 && this->hidden == 0) {
        ShowWindow(this->edit_wnd, SW_HIDE);
        this->hidden = 1;
    }
    if (this->text != 0) {
        free(this->text);
        this->text = 0;
    }
    if (this->edit_wnd != 0) {
        if (this->imc != 0) {
            ImmNotifyIME(this->imc, 0x15, 4, 0);
            if (this->enable_ime != 0) {
                ImmReleaseContext(this->edit_wnd, this->imc);
            }
            this->imc = 0;
        }
        DestroyWindow(this->edit_wnd);
        this->edit_wnd = 0;
    }
}

// pnl_edit.cpp lines 121-189.
long TEditPanel::setup(
    TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in,
    long wid_in, long hgt_in, void* font_in, short fixed_len_in,
    char* text_in, TEditPanel::FormatType format_in, int auto_sel_in) {
    long result;

    this->format = format_in;
    if (fixed_len_in > 0) {
        fixed_len_in++;
    }
    this->fixed_len = fixed_len_in;
    this->font = font_in;
    this->auto_sel = auto_sel_in;

    result = TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0xFF);
    if (result == 0) {
        return 0;
    }

    int style;
    if (this->format != TEditPanel::FormatMultiLine)
        style = 0x40000080;
    else style = 0x40200044;
    this->edit_wnd = CreateWindowExA(0, "edit", 0, style, x_in + 1, y_in + 1, wid_in - 2, hgt_in - 2,
                                     (HWND)render_area_in->Wnd, (HMENU)1, ((TDrawSystem*)this->render_area->DrawSystem)->Inst, 0);
    if (this->edit_wnd == 0) {
        return 0;
    }

    SetWindowLongA(this->edit_wnd, GWL_USERDATA, (long)(void*)this);
    this->old_sub_wnd_proc = (WNDPROC)GetWindowLongA(this->edit_wnd, GWL_WNDPROC);
    SetWindowLongA(this->edit_wnd, GWL_WNDPROC, (long)(void*)pnl_sub_wnd_proc);

    {
        char* text_buffer = (char*)calloc(this->fixed_len + 2, 1);
        this->text = text_buffer;
        if (text_buffer == 0) {
            return 0;
        }
        *text_buffer = 0;
    }
    this->text_len = 0;
    if (text_in != 0 && *text_in != 0) {
        this->set_text(text_in);
    }
    this->brush = GetStockObject(BLACK_BRUSH);
    this->text_color1 = 0xFFFFFF;
    this->highlight_text_color1 = 0xFFFFFF;
    this->back_color = 0;
    this->text_color2 = 0;
    this->highlight_text_color2 = 0;
    if (this->font != 0) {
        SendMessageA(this->edit_wnd, WM_SETFONT, (unsigned int)this->font, 0);
    }
    this->draw_format = 0x2000;
    if (this->format != TEditPanel::FormatMultiLine)
        this->draw_format = 0x2020;
    else this->draw_format = 0x2010;
    return 1;
}

// pnl_edit.cpp lines 195-215.
void TEditPanel::set_text(char* text_in) {
    if (edit_wnd) {
        if (text_in) {
            memset(this->text, 0, (short)fixed_len);
            strncpy(this->text, text_in, (short)fixed_len - 1);
            this->text[(short)fixed_len - 1] = 0;
            text_len = strlen(this->text);
        } else {
            this->text[0] = 0;
            text_len = 0;
        }
        SetWindowTextA(this->edit_wnd, this->text);
        sel_len = 0;
    }
    this->set_redraw(TPanel::RedrawNormal);
}

// pnl_edit.cpp lines 221-266.
void TEditPanel::update_text() {
    if (this->edit_wnd != 0) {
        GetWindowTextA(this->edit_wnd, this->text, this->fixed_len + 1);
        this->text_len = strlen(this->text);
        this->text[this->fixed_len - 1] = 0;
        if (this->text_len > this->fixed_len - 1) {
            SetWindowTextA(this->edit_wnd, this->text);
            MessageBeep((UINT)-1);
        }
        int end;
        int start;
        start = 0;
        end = 0;
        SendMessageA(this->edit_wnd, EM_GETSEL, (unsigned int)&start, (long)&end);
        this->sel_len = end - start;
    }
}

// pnl_edit.cpp lines 272-275.
char* TEditPanel::get_text() {
    this->update_text();
    return this->text;
}

// pnl_edit.cpp lines 281-284.
char* TEditPanel::get_input_buffer() {
    this->update_text();
    return this->text;
}

// pnl_edit.cpp lines 290-293.
char* TEditPanel::currentLine() {
    this->update_text();
    return this->text;
}

// pnl_edit.cpp lines 299-306.
void TEditPanel::set_active(int activ_in) {
    TPanel::set_active(activ_in);
    if (this->edit_wnd != 0 && this->active == 0) {
        ShowWindow(this->edit_wnd, SW_HIDE);
        this->hidden = 1;
    }
}

// pnl_edit.cpp lines 314-395.
void TEditPanel::set_focus(int have_focus_in) {
    int old_focus;
    HWND hwnd;
    unsigned long context;

    old_focus = this->have_focus;
    TPanel::set_focus(have_focus_in);
    if (this->edit_wnd != 0) {
        HWND current = GetFocus();
        if (this->have_focus != 0) {
            if (current != this->edit_wnd) {
                SetFocus(this->edit_wnd);
            }
            if (this->imc == 0) {
                if (this->enable_ime != 0) {
                    this->imc = (unsigned long)ImmGetContext(this->edit_wnd);
                } else {
                    this->imc = (unsigned long)ImmAssociateContext(this->edit_wnd, 0);
                }
            }
            context = this->imc;
            if (context != 0 && this->enable_ime != 0) {
                if (this->turn_ime_on != 0) {
                    imc_retval = ImmSetOpenStatus(context, 1);
                } else {
                    imc_retval = ImmSetOpenStatus(context, 0);
                }
            }
        } else if (current == this->edit_wnd) {
            hwnd = (HWND)this->render_area->Wnd;
            if (current != hwnd) {
                SetFocus(hwnd);
            }
        }
    }
    if (old_focus != 0 && this->have_focus == 0) {
        this->update_text();
        this->set_redraw(TPanel::RedrawNormal);
    }
    if (this->edit_wnd != 0 && this->have_focus != 0 && old_focus == 0 && this->auto_sel != 0) {
        SendMessageA(this->edit_wnd, EM_SETSEL, 0, -1);
    }
    if (DAT_0086b240 == 0 && this->edit_wnd != 0 && this->have_focus == 0 && this->hidden == 0) {
        ShowWindow(this->edit_wnd, SW_HIDE);
        this->hidden = 1;
    }
    if (this->have_focus != 0) {
        DAT_0086b244 = 0;
    }
}

// pnl_edit.cpp lines 401-421.
void TEditPanel::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    TPanel::set_rect(x_in, y_in, wid_in, hgt_in);
    if (this->edit_wnd != 0) {
        int redraw;
        if (this->hidden == 0 && this->visible != 0 && this->active != 0) {
            redraw = 1;
        } else {
            redraw = 0;
        }
        int bevel = this->bevel_size;
        int left = this->pnl_x + bevel;
        int top = this->pnl_y + bevel;
        int width = this->pnl_wid - bevel * 2 - 1;
        int height = this->pnl_hgt - bevel * 2 - 1;
        MoveWindow(this->edit_wnd, left, top, width, height, redraw);
    }
    int format = this->format;
    if (format == 7) {
        this->draw_rect.left = this->render_rect.left + 1 + this->bevel_size;
        this->draw_rect.top = this->render_rect.top + this->bevel_size;
        this->draw_rect.right = this->render_rect.right - this->bevel_size -
                                GetSystemMetrics(SM_CXHSCROLL) - 1;
        this->draw_rect.bottom = this->render_rect.bottom - this->bevel_size;
    } else {
        this->draw_rect.left = this->render_rect.left + this->bevel_size + 8;
        this->draw_rect.top = this->render_rect.top + this->bevel_size;
        this->draw_rect.right = this->render_rect.right - this->bevel_size;
        this->draw_rect.bottom = this->render_rect.bottom - this->bevel_size;
    }
}

// pnl_edit.cpp lines 427-431.
void TEditPanel::set_redraw(TPanel::RedrawMode redraw_mode) {
    TPanel::set_redraw(TPanel::RedrawNormal);
    if (this->active != 0 && redraw_mode != 0 && this->edit_wnd != 0 && this->hidden == 0) {
        InvalidateRect(this->edit_wnd, 0, 1);
    }
}

// pnl_edit.cpp lines 437-441.
void TEditPanel::set_text_color(unsigned long val1, unsigned long val2) {
    text_color1 = val1;
    text_color2 = val2;
    set_redraw(TPanel::RedrawNormal);
}

// pnl_edit.cpp line 447.
void TEditPanel::set_highlight_text_color(unsigned long val1, unsigned long val2) {
}

// pnl_edit.cpp line 460.
void TEditPanel::set_back_color(void* brush_in, unsigned long brush_color_in, unsigned char color_in) {
}

// pnl_edit.cpp lines 474-509.
void TEditPanel::set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6) {
    bevel_type = bevel_type_in;
    bevel_color1 = (unsigned char)c1;
    bevel_color2 = (unsigned char)c2;
    bevel_color3 = (unsigned char)c3;
    bevel_color4 = (unsigned char)c4;
    bevel_color5 = (unsigned char)c5;
    bevel_color6 = (unsigned char)c6;
    switch (bevel_type_in) {
    case 1:
    case 2:
    case 5:
        this->bevel_size = 1;
        break;
    case 3:
    case 6:
        this->bevel_size = 2;
        break;
    case 4:
    case 7:
        this->bevel_size = 3;
        break;
    default:
        this->bevel_size = 0;
        break;
    }
    long btm = this->pnl_hgt;
    long rgt = this->pnl_wid;
    long tp = this->pnl_y;
    long lft = this->pnl_x;
    this->set_rect(lft, tp, rgt, btm);
    this->set_redraw(TPanel::RedrawNormal);
}

// pnl_edit.cpp lines 515-518.
void TEditPanel::set_ime_info(int enable_ime_in, int turn_ime_on_in) {
    this->enable_ime = enable_ime_in;
    this->turn_ime_on = turn_ime_on_in;
}

// pnl_edit.cpp lines 524-598.
long TEditPanel::wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    HWND edit_window = edit_wnd;
    if (edit_window != 0 && active != 0 && visible != 0 && hidden == 0) {
        switch (msg) {
        case 7:
            return TPanel::wnd_proc(hwnd, 7, wParam, lParam);
        case 0x133:
            if (brush != 0 && (void*)(lParam & 0xFFFF) == edit_window) {
                SetBkColor((HDC)wParam, back_color);
                SetBkMode((HDC)wParam, OPAQUE);
                SetTextColor((HDC)wParam, highlight_text_color1);
                return (long)brush;
            }
            break;
        case 0x111:
            if ((void*)lParam == edit_window) {
                short notification = wParam >> 16;
                if (notification == 0x400) {
                    InvalidateRect(edit_window, 0, 1);
                }
            }
            break;
        }
    }
    return TPanel::wnd_proc(hwnd, msg, wParam, lParam);
}

// pnl_edit.cpp lines 604-753.
long TEditPanel::sub_wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    if (this->edit_wnd != 0 && this->active != 0 && this->visible != 0 && this->hidden == 0) {
        switch (msg) {
        case 0x0f:
            InvalidateRect((HWND)hwnd, 0, 1);
            break;

        case 0x14:
            if (this->brush != 0) {
                RECT rect;
                SelectObject((HDC)wParam, this->brush);
                GetClientRect((HWND)hwnd, &rect);
                FillRect((HDC)wParam, &rect, this->brush);
                return 1;
            }
            break;

        case 0x100:
            if (this->parent_panel != 0) {
                if (this->parent_panel->wnd_proc(hwnd, msg, wParam, lParam) != 0) {
                    return 0;
                }

                if (wParam == 9) {
                    int alt_down = GetKeyState(VK_MENU) < 0;
                    int control_down = GetKeyState(VK_CONTROL) < 0;
                    int shift_down = GetKeyState(VK_SHIFT) < 0;
                    DAT_0086b240 = 1;
                    this->handle_key_down(9, (short)lParam, alt_down, control_down, shift_down);
                    DAT_0086b240 = 0;
                    return 0;
                }
                if (wParam == 0x0d) {
                    this->parent_panel->action(this, 0, 0, 0);
                    return 0;
                }
                if (wParam == 0x1b) {
                    if (this->parent_panel->action(this, 1, 0, 0) == 0) {
                        SendMessageA(this->edit_wnd, EM_UNDO, 0, 0);
                    }
                    return 0;
                }
            } else if (wParam == 0x1b) {
                SendMessageA(this->edit_wnd, EM_UNDO, 0, 0);
                return 0;
            }
            break;

        case 0x101:
            if (wParam == 9) {
                return 0;
            }
            break;

        case 0x102:
            if (this->verify_char(wParam) == 0) {
                return 0;
            }
            break;

        case 0x104:
            if (this->imc == 0 || this->enable_ime == 0) {
                SetFocus((HWND)this->render_area->Wnd);
                PostMessageA((HWND)this->render_area->Wnd, msg, wParam, lParam);
            }
            return 0;

        case 0x200:
            if (rge_base_game->windows_mouse == 0) {
                MouseCursorInChildContol = 1;
                rge_base_game->mouse_off();
            }
            break;
        }
    }

    unsigned long old_start = 0;
    unsigned long old_end = 0;
    unsigned long new_start = 0;
    unsigned long new_end = 0;
    int check_sel = 0;

    if (this->edit_wnd != 0 && msg != 0xb0) {
        check_sel = 1;
        SendMessageA(this->edit_wnd, EM_GETSEL, (unsigned int)&old_start, (long)&old_end);
    }

    long result = CallWindowProcA((FARPROC)this->old_sub_wnd_proc, (HWND)hwnd, msg, wParam, lParam);

    if (check_sel != 0) {
        SendMessageA(this->edit_wnd, EM_GETSEL, (unsigned int)&new_start, (long)&new_end);
        if (new_start != old_start || new_end != old_end) {
            InvalidateRect(this->edit_wnd, 0, 1);
            UpdateWindow(this->edit_wnd);
        }
    }

    if (msg == 0x302) {
        this->update_text();
    }

    if (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONUP || msg == WM_RBUTTONDOWN || msg == WM_RBUTTONUP) {
        unsigned long x = this->pnl_x + ((unsigned long)lParam & 0xffff);
        unsigned long y = this->pnl_y + ((unsigned long)lParam >> 16);
        long position = (long)(((y & 0xffff) << 16) | (x & 0xffff));
        result = panel_system.currentPanel()->wnd_proc(this->render_area->Wnd, msg, wParam, position);
    }

    return result;
}

// pnl_edit.cpp lines 760-853.
int TEditPanel::verify_char(int key) {
    if (DAT_0086b244 != 0) {
        DAT_0086b244 = 0;
        return 0;
    }
    if (key == 9) return 0;
    if (key == 13 && this->format != 7) return 0;
    if (key == 8) return 1;
    this->update_text();
    if (this->sel_len == 0) {
        if (this->text_len >= this->fixed_len - 1) {
            MessageBeep((UINT)-1);
            return 0;
        }
    }
    if (this->sel_len == 0) {
        if (this->text_len >= this->fixed_len - 2 && IsDBCSLeadByte(key) != 0) {
            DAT_0086b244 = 1;
            MessageBeep((UINT)-1);
            return 0;
        }
    }
    int validation_result;
    switch (this->format) {
    case 0:
        goto valid;
    case 8:
        if (this->text_len < 2) {
            if (key >= '0' && key <= '9') goto valid;
        }
        if (this->text_len != 2 || key != '0') goto invalid;
        validation_result = _mbscmp((const unsigned char*)"10", (const unsigned char*)this->text);
        break;
    case 1:
    case 2:
    case 3:
        this->update_text();
        if (key >= '0' && key <= '9') goto valid;
        if (key == '-' && this->text[0] == 0 && this->format != 3) goto valid;
        if (key != '.' || _mbschr((const unsigned char*)this->text, '.') == 0)
            goto invalid;
        if (this->format == 1) goto valid;
        MessageBeep((UINT)-1);
        return 0;
    case 4:
    case 5:
        this->update_text();
        if (key == '.' && this->format == 4 && _mbschr((const unsigned char*)this->text, '.') == 0) {
            goto valid;
        }
        if (key == '.') goto invalid;
        if (key == '\\') goto invalid;
        if (key == ':') goto invalid;
        goto valid_chars;
    case 6:
        this->update_text();
        if (key == ':' && this->text_len != 1) goto invalid;
        goto valid_chars;
    default:
        goto valid;
    }
    if (validation_result == 0) goto valid;
    MessageBeep((UINT)-1);
    return 0;
valid_chars:
    if (key != '/' && key != '"' && key != '*' && key != '?' && key != '>' && key != '<' && key != '|') goto valid;
    goto invalid;
invalid:
    MessageBeep((UINT)-1);
    return 0;
valid:
    return 1;
}

// pnl_edit.cpp lines 859-973.
void TEditPanel::draw() {
    this->need_redraw = 0;
    if (this->visible == 0) {
        return;
    }

    this->draw_setup(0);

    if (this->brush != 0 && this->active != 0 && this->have_focus != 0) {
        unsigned char temp_color = (unsigned char)GetNearestPaletteIndex((HPALETTE)this->render_area->DrawSystem->Pal,
                                                                         this->back_color);
        this->render_area->Clear(&this->clip_rect, temp_color);
    } else if (this->parent_panel != 0) {
        if (this->bevel_type >= 2 && this->bevel_type <= 7) {
            this->parent_panel->draw_rect2(&this->clip_rect);
        } else if (this->parent_panel->just_drawn == 0) {
            this->parent_panel->draw_rect(&this->clip_rect);
        }
    } else {
        this->render_area->Clear(&this->clip_rect, this->color);
    }

    if (this->bevel_type != 0) {
        if (this->render_area->Lock("pnl_edit::draw", 1) != 0) {
            switch (this->bevel_type) {
            case 1:
                this->render_area->DrawRect(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1,
                                            this->pnl_y + this->pnl_hgt - 1, this->bevel_color1);
                break;
            case 2:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1,
                                             this->pnl_y + this->pnl_hgt - 1, this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1,
                                              this->pnl_y + this->pnl_hgt - 1, this->bevel_color6, this->bevel_color5,
                                              this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1,
                                              this->pnl_y + this->pnl_hgt - 1, this->bevel_color6, this->bevel_color5,
                                              this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1,
                                             this->pnl_y + this->pnl_hgt - 1, this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1,
                                              this->pnl_y + this->pnl_hgt - 1, this->bevel_color1, this->bevel_color2,
                                              this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1,
                                              this->pnl_y + this->pnl_hgt - 1, this->bevel_color1, this->bevel_color2,
                                              this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->render_area->Unlock("pnl_edit::draw");
    }

    if (this->edit_wnd != 0 && this->active != 0) {
        if (this->have_focus != 0) {
            if (this->hidden != 0) {
                ShowWindow(this->edit_wnd, SW_SHOW);
                InvalidateRect(this->edit_wnd, 0, 1);
                this->hidden = 0;
            }
        } else {
            if (this->hidden == 0) {
                ShowWindow(this->edit_wnd, SW_HIDE);
                this->hidden = 1;
            }

            HDC dc = (HDC)this->render_area->GetDc("pnl_edit::draw");
            if (dc != 0) {
                SelectClipRgn(dc, (HRGN)this->clip_rgn);
                HGDIOBJ old_font = SelectObject(dc, this->font);
                SetBkMode(dc, TRANSPARENT);
                SetTextColor(dc, this->text_color2);

                tagRECT r;
                r.left = this->draw_rect.left - 1;
                r.top = this->draw_rect.top + 1;
                r.right = this->draw_rect.right - 1;
                r.bottom = this->draw_rect.bottom + 1;
                DrawTextExA(dc, this->text, -1, &r, this->draw_format, 0);

                SetTextColor(dc, this->text_color1);
                DrawTextExA(dc, this->text, -1, &this->draw_rect, this->draw_format, 0);
                SelectObject(dc, old_font);
                SelectClipRgn(dc, 0);
                this->render_area->ReleaseDc("pnl_edit::draw");
            }
        }
    }

    this->draw_finish();
}

// pnl_edit.cpp line 979.
void TEditPanel::paint() {
}

// pnl_edit.cpp lines 987-1011.
int TEditPanel::is_blank() {
    char* p;
    this->update_text();
    p = this->text;
    if (p == 0) goto blank;
    if (*p == 0) goto blank;
    while (1) {
        if (*p == '\0') goto blank;
        if (_ismbcspace((unsigned char)*p) == 0) return 0;
        p = (char*)_mbsinc((const unsigned char*)p);
    }
blank:
    return 1;
}

// pnl_edit.cpp lines 1017-1054.
char* TEditPanel::get_trimmed_str(char* str, int str_len) {
    char temp_str[256];
    unsigned char* base;
    unsigned char* p;
    unsigned char* cur;
    this->update_text();
    memset(temp_str, 0, sizeof(temp_str));
    strcpy(temp_str, this->text);
    memset(str, 0, str_len);
    base = (unsigned char*)str;
    p = base;
    cur = (unsigned char*)temp_str;
    while (_ismbcspace(*cur & 0xFF))
        cur = _mbsinc(cur);
    while (*cur) {
        _mbsncpy(p, cur, 1);
        p = _mbsinc(p);
        cur = _mbsinc(cur);
    }
    while (1) {
        *p = 0;
        if (p == base) break;
        p = _mbsdec(base, p);
        if (_ismbcspace(*p))
            continue;
        break;
    }
    return str;
}

// pnl_edit.cpp lines 1060-1067.
void TEditPanel::handle_reactivate() {
    if (this->edit_wnd && this->have_focus) {
        HWND focus = GetFocus();
        if (focus != this->edit_wnd) {
            SetFocus(this->edit_wnd);
        }
    }
}

// pnl_edit.cpp lines 1074-1077.
long TEditPanel::handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key) {
    return TPanel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
}
