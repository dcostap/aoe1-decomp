#include "../include/pnl_edit.h"
#include <stdlib.h>
#include <string.h>

extern "C" __declspec(dllimport) long __stdcall GetWindowLongA(
    HWND, int);
extern "C" __declspec(dllimport) HWND __stdcall CreateWindowExA(
    unsigned long, const char*, const char*, unsigned long, int, int, int,
    int, HWND, HMENU, HINSTANCE, void*);
extern "C" __declspec(dllimport) long __stdcall SetWindowLongA(HWND, int, long);
extern "C" __declspec(dllimport) HGDIOBJ __stdcall GetStockObject(int);
extern "C" __declspec(dllimport) int __stdcall GetWindowTextA(
    HWND, char*, int);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(
    HWND, const char*);
extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    HWND, unsigned int, unsigned int, long);
extern "C" __declspec(dllimport) int __stdcall ShowWindow(HWND, int);
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(HWND);
extern "C" __declspec(dllimport) HWND __stdcall GetFocus(void);
extern "C" int __stdcall ImmNotifyIME(
    unsigned long, unsigned int, unsigned int, unsigned int);
extern "C" int __stdcall ImmReleaseContext(
    HWND, unsigned long);
extern "C" unsigned long __stdcall ImmGetContext(HWND);
extern "C" unsigned long __stdcall ImmAssociateContext(HWND, unsigned long);
extern "C" int __stdcall ImmSetOpenStatus(unsigned long, int);
extern "C" __declspec(dllimport) void __stdcall MoveWindow(
    HWND, int, int, int, int, int);
extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int);
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(
    HWND, const tagRECT*, int);
extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(
    HDC, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(HDC, int);
extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(
    HDC, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(HDC, HRGN);
extern "C" __declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
extern "C" __declspec(dllimport) int __stdcall DrawTextExA(
    HDC, const char*, int, tagRECT*, unsigned int, void*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetNearestPaletteIndex(
    HPALETTE, COLORREF);
extern "C" __declspec(dllimport) int __stdcall FillRect(
    HDC, const tagRECT*, HBRUSH);
extern "C" __declspec(dllimport) int __stdcall GetClientRect(HWND, tagRECT*);
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int);
extern "C" __declspec(dllimport) int __stdcall PostMessageA(
    HWND, unsigned int, unsigned int, long);
extern "C" __declspec(dllimport) HWND __stdcall SetFocus(HWND);
extern "C" __declspec(dllimport) long __stdcall CallWindowProcA(
    FARPROC, HWND, unsigned int, unsigned int, long);
extern "C" __declspec(dllimport) int __stdcall UpdateWindow(HWND);
extern "C" int (__stdcall* const MessageBeep)(unsigned int);
extern "C" int (__stdcall* const IsDBCSLeadByte)(unsigned int);
extern "C" int __cdecl _mbscmp(const unsigned char*, const unsigned char*);
extern "C" unsigned char* __cdecl _mbschr(const unsigned char*, unsigned int);
extern "C" int __cdecl __ismbcspace(int);
extern "C" unsigned char* __cdecl __mbsinc(const unsigned char*);
extern "C" unsigned char* __cdecl __mbsdec(const unsigned char*, const unsigned char*);
extern "C" unsigned char* __cdecl _mbsncpy(
    unsigned char*, const unsigned char*, int);
extern "C" char* __cdecl strcpy(char*, const char*);
extern int imc_retval;

static long __stdcall pnl_sub_wnd_proc(
    HWND wnd, unsigned int msg, unsigned int wParam, long lParam)
{
    TEditPanel* panel = (TEditPanel*)GetWindowLongA(wnd, -21);
    if (panel != 0) {
        return panel->sub_wnd_proc(wnd, msg, wParam, lParam);
    }
    return 0;
}

// pnl_edit.cpp lines 50-75.
TEditPanel::TEditPanel() : TPanel()
{
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
TEditPanel::~TEditPanel()
{
    if (this->edit_wnd != 0 && this->hidden == 0) {
        ShowWindow(this->edit_wnd, 0);
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
    TDrawArea* param_1, TPanel* param_2, long param_3, long param_4,
    long param_5, long param_6, void* param_7, short param_8, char* param_9,
    int param_10, int param_11)
{
    long result;

    this->format = param_10;
    if (param_8 > 0) {
        param_8++;
    }
    this->fixed_len = param_8;
    this->font = param_7;
    this->auto_sel = param_11;

    result = TPanel::setup(param_1, param_2, param_3, param_4, param_5,
                           param_6, 0xFF);
    if (result == 0) {
        return 0;
    }

    int styleVal = ((this->format != 7 ? -1 : 0) & 0xFFE0003C) + 0x40200044;
    this->edit_wnd = CreateWindowExA(
        0, "edit", 0, styleVal,
        param_3 + 1, param_4 + 1, param_5 - 2, param_6 - 2,
        (HWND)param_1->Wnd, (HMENU)1,
        ((TDrawSystem*)this->render_area->DrawSystem)->Inst, 0);
    if (this->edit_wnd == 0) {
        return 0;
    }

    SetWindowLongA(this->edit_wnd, -0x15, (long)(void*)this);
    this->old_sub_wnd_proc = (WNDPROC)GetWindowLongA(this->edit_wnd, -4);
    SetWindowLongA(this->edit_wnd, -4, (long)(void*)pnl_sub_wnd_proc);

    {
        char* textBuf = (char*)calloc(this->fixed_len + 2, 1);
        this->text = textBuf;
        if (textBuf == 0) {
            return 0;
        }
        *textBuf = 0;
    }
    this->text_len = 0;
    if (param_9 != 0 && *param_9 != 0) {
        this->set_text(param_9);
    }
    this->brush = GetStockObject(4);
    this->text_color1 = 0xFFFFFF;
    this->highlight_text_color1 = 0xFFFFFF;
    this->back_color = 0;
    this->text_color2 = 0;
    this->highlight_text_color2 = 0;
    if (this->font != 0) {
        SendMessageA(this->edit_wnd, 0x30, (unsigned int)this->font, 0);
    }
    this->draw_format = 0x2000;
    {
        int df2 = this->format - 7;
        if (df2) {
            df2 = -1;
        }
        df2 &= 0x10;
        df2 += 0x2010;
        this->draw_format = df2;
    }
    return 1;
}

// pnl_edit.cpp lines 195-215.
void TEditPanel::set_text(char* text)
{
    if (edit_wnd) {
        if (text) {
            memset(this->text, 0, (short)fixed_len);
            strncpy(this->text, text, (short)fixed_len - 1);
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
void TEditPanel::update_text()
{
    if (this->edit_wnd != 0) {
        GetWindowTextA(this->edit_wnd, this->text, this->fixed_len + 1);
        this->text_len = strlen(this->text);
        this->text[this->fixed_len - 1] = 0;
        if (this->text_len > this->fixed_len - 1) {
            SetWindowTextA(this->edit_wnd, this->text);
            MessageBeep(0xffffffff);
        }
        int end;
        int start;
        start = 0;
        end = 0;
        SendMessageA(this->edit_wnd, 0xb0, (unsigned int)&start, (long)&end);
        this->sel_len = end - start;
    }
}

// pnl_edit.cpp lines 272-275.
char* TEditPanel::get_text()
{
    this->update_text();
    return this->text;
}

// pnl_edit.cpp lines 281-284.
char* TEditPanel::get_input_buffer()
{
    this->update_text();
    return this->text;
}

// pnl_edit.cpp lines 290-293.
char* TEditPanel::currentLine()
{
    this->update_text();
    return this->text;
}

// pnl_edit.cpp lines 299-306.
void TEditPanel::set_active(int active)
{
    TPanel::set_active(active);
    if (this->edit_wnd != 0 && this->active == 0) {
        ShowWindow(this->edit_wnd, 0);
        this->hidden = 1;
    }
}

// pnl_edit.cpp lines 314-395.
void TEditPanel::set_focus(int focus)
{
    int old_focus;
    HWND hwnd;
    unsigned long context;

    old_focus = this->have_focus;
    TPanel::set_focus(focus);
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
                    this->imc = (unsigned long)ImmAssociateContext(
                        this->edit_wnd, 0);
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
    if (this->edit_wnd != 0 && this->have_focus != 0 && old_focus == 0 &&
        this->auto_sel != 0) {
        SendMessageA(this->edit_wnd, 0xb1, 0, -1);
    }
    if (DAT_0086b240 == 0 && this->edit_wnd != 0 &&
        this->have_focus == 0 && this->hidden == 0) {
        ShowWindow(this->edit_wnd, 0);
        this->hidden = 1;
    }
    if (this->have_focus != 0) {
        DAT_0086b244 = 0;
    }
}

// pnl_edit.cpp lines 401-421.
void TEditPanel::set_rect(long param_1, long param_2, long param_3, long param_4)
{
    TPanel::set_rect(param_1, param_2, param_3, param_4);
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
                                GetSystemMetrics(0x15) - 1;
        this->draw_rect.bottom = this->render_rect.bottom - this->bevel_size;
    } else {
        this->draw_rect.left = this->render_rect.left + this->bevel_size + 8;
        this->draw_rect.top = this->render_rect.top + this->bevel_size;
        this->draw_rect.right = this->render_rect.right - this->bevel_size;
        this->draw_rect.bottom = this->render_rect.bottom - this->bevel_size;
    }
}

// pnl_edit.cpp lines 427-431.
void TEditPanel::set_redraw(TPanel::RedrawMode mode)
{
    TPanel::set_redraw(TPanel::RedrawNormal);
    if (this->active != 0 && mode != 0 && this->edit_wnd != 0 &&
        this->hidden == 0) {
        InvalidateRect(this->edit_wnd, 0, 1);
    }
}

// pnl_edit.cpp lines 437-441.
void TEditPanel::set_text_color(unsigned long a, unsigned long b)
{
    text_color1 = a;
    text_color2 = b;
    set_redraw(TPanel::RedrawNormal);
}

// pnl_edit.cpp line 447.
void TEditPanel::set_highlight_text_color(unsigned long, unsigned long)
{
}

// pnl_edit.cpp line 460.
void TEditPanel::set_back_color(void*, unsigned long, unsigned char)
{
}

// pnl_edit.cpp lines 474-509.
void TEditPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4,
                                int c5, int c6)
{
    this->bevel_color1 = (unsigned char)c1;
    this->bevel_color2 = (unsigned char)c2;
    this->bevel_type = type;
    this->bevel_color3 = (unsigned char)c3;
    this->bevel_color4 = (unsigned char)c4;
    this->bevel_color5 = (unsigned char)c5;
    this->bevel_color6 = (unsigned char)c6;
    switch (type) {
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
void TEditPanel::set_ime_info(int a, int b)
{
    this->enable_ime = a;
    this->turn_ime_on = b;
}

// pnl_edit.cpp lines 524-598.
long TEditPanel::wnd_proc(void* param_1, unsigned int param_2,
                          unsigned int param_3, long param_4)
{
    HWND edit_window = edit_wnd;
    if (edit_window != 0 && active != 0 && visible != 0 && hidden == 0) {
        switch (param_2) {
        case 7:
            return TPanel::wnd_proc(param_1, 7, param_3, param_4);
        case 0x133:
            if (brush != 0 && (void*)(param_4 & 0xFFFF) == edit_window) {
                SetBkColor((HDC)param_3, back_color);
                SetBkMode((HDC)param_3, 2);
                SetTextColor((HDC)param_3, highlight_text_color1);
                return (long)brush;
            }
            break;
        case 0x111:
            if ((void*)param_4 == edit_window) {
                short notification = param_3 >> 16;
                if (notification == 0x400) {
                    InvalidateRect(edit_window, 0, 1);
                }
            }
            break;
        }
    }
    return TPanel::wnd_proc(param_1, param_2, param_3, param_4);
}

// pnl_edit.cpp lines 604-753.
long TEditPanel::sub_wnd_proc(void* hwnd, unsigned int msg,
                              unsigned int wparam, long lparam)
{
    unsigned long sel_start_before;
    unsigned long sel_end_before;
    unsigned long sel_start_after;
    unsigned long sel_end_after;
    int track_selection;

    if (this->edit_wnd == 0) goto default_processing;
    if (this->active == 0) goto default_processing;
    if (this->visible == 0) goto default_processing;
    if (this->hidden != 0) goto default_processing;

    if (msg <= 0x14) {
        if (msg != 0x14) {
            if (msg == 0x0F) {
                InvalidateRect((HWND)hwnd, 0, 1);
            }
        } else if (this->brush != 0) {
            RECT rect;
            HDC hdc = (HDC)wparam;
            SelectObject(hdc, (HGDIOBJ)this->brush);
            GetClientRect((HWND)hwnd, &rect);
            FillRect(hdc, &rect, (HBRUSH)this->brush);
            return 1;
        }
    } else if (msg <= 0x200) {
        switch (msg) {
        case 0x200:
            if (rge_base_game->windows_mouse == 0) {
                DAT_0062c4c4 = 1;
                rge_base_game->mouse_off();
            }
            break;
        case 0x100:
            if (this->parent_panel == 0) {
                if (wparam == 0x1B) {
                    SendMessageA((HWND)this->edit_wnd, 0xC7, 0, 0);
                    return 0;
                }
            } else {
                long handled = this->parent_panel->wnd_proc(
                    hwnd, msg, wparam, lparam);
                if (handled != 0) {
                    return 0;
                }
                if (wparam == 9) {
                    int alt_down = (GetKeyState(0x12) < 0);
                    int ctrl_down = (GetKeyState(0x11) < 0);
                    int shift_down = (GetKeyState(0x10) < 0);
                    DAT_0086b240 = 1;
                    this->parent_panel->handle_key_down(
                        9, (short)lparam, alt_down, ctrl_down, shift_down);
                    DAT_0086b240 = 0;
                    return 0;
                }
                if (wparam == 0x0D) {
                    this->parent_panel->action(this, 0, 0, 0);
                    return 0;
                }
                if (wparam == 0x1B) {
                    long esc_handled = this->parent_panel->action(this, 1, 0, 0);
                    if (esc_handled != 0) {
                        return 0;
                    }
                    SendMessageA((HWND)this->edit_wnd, 0xC7, 0, 0);
                    return 0;
                }
            }
            break;
        case 0x101:
            if (wparam == 9) {
                return 0;
            }
            break;
        case 0x102:
            if (this->verify_char((int)wparam) == 0) {
                return 0;
            }
            break;
        case 0x104:
            if (this->imc == 0 || this->enable_ime == 0) {
                SetFocus((HWND)this->render_area->Wnd);
                PostMessageA((HWND)this->render_area->Wnd, msg, wparam,
                             lparam);
            }
            return 0;
        default:
            break;
        }
    }

default_processing:
    sel_start_before = 0;
    sel_end_before = 0;
    sel_start_after = 0;
    sel_end_after = 0;
    if (this->edit_wnd == 0 || msg == 0xB0) {
        track_selection = 0;
    } else {
        track_selection = 1;
        SendMessageA((HWND)this->edit_wnd, 0xB0,
                     (unsigned int)&sel_start_before,
                     (long)&sel_end_before);
    }
    WNDPROC old_proc = this->old_sub_wnd_proc;
    long ret = CallWindowProcA((FARPROC)old_proc, (HWND)hwnd, msg, wparam,
                               lparam);
    if (track_selection != 0) {
        SendMessageA((HWND)this->edit_wnd, 0xB0,
                     (unsigned int)&sel_start_after,
                     (long)&sel_end_after);
        if (sel_start_after != sel_start_before ||
            sel_end_after != sel_end_before) {
            InvalidateRect((HWND)this->edit_wnd, 0, 1);
            UpdateWindow((HWND)this->edit_wnd);
        }
    }
    if (msg == 0x302) {
        this->update_text();
    }
    if (msg == 0x201 || msg == 0x202 || msg == 0x204 || msg == 0x205) {
        long adjusted_x = this->pnl_x +
                          (long)((unsigned int)lparam & 0xFFFF);
        lparam = (long)((unsigned long)lparam >> 16) + this->pnl_y;
        TPanel* cp = panel_system.currentPanel();
        lparam = (long)((((unsigned long)lparam & 0xFFFF) << 16) |
                        ((unsigned long)adjusted_x & 0xFFFF));
        ret = cp->wnd_proc((void*)this->render_area->Wnd, msg, wparam,
                           lparam);
    }
    return ret;
}

// pnl_edit.cpp lines 760-853.
int TEditPanel::verify_char(int ch)
{
    if (DAT_0086b244 != 0) {
        DAT_0086b244 = 0;
        return 0;
    }
    if (ch == 9) return 0;
    if (ch == 13 && this->format != 7) return 0;
    if (ch == 8) return 1;
    this->update_text();
    if (this->sel_len == 0) {
        if (this->text_len >= this->fixed_len - 1) {
            MessageBeep(0xffffffff);
            return 0;
        }
    }
    if (this->sel_len == 0) {
        if (this->text_len >= this->fixed_len - 2 &&
            IsDBCSLeadByte(ch) != 0) {
            DAT_0086b244 = 1;
            MessageBeep(0xffffffff);
            return 0;
        }
    }
    int validation_result;
    switch (this->format) {
    case 0:
        goto valid;
    case 8:
        if (this->text_len < 2) {
            if (ch >= '0' && ch <= '9') goto valid;
        }
        if (this->text_len != 2 || ch != '0') goto invalid;
        validation_result = _mbscmp((const unsigned char*)"10",
                                    (const unsigned char*)this->text);
        break;
    case 1:
    case 2:
    case 3:
        this->update_text();
        if (ch >= '0' && ch <= '9') goto valid;
        if (ch == '-' && this->text[0] == 0 && this->format != 3) goto valid;
        if (ch != '.' || _mbschr((const unsigned char*)this->text, '.') == 0)
            goto invalid;
        if (this->format == 1) goto valid;
        MessageBeep(0xffffffff);
        return 0;
    case 4:
    case 5:
        this->update_text();
        if (ch == '.' && this->format == 4 &&
            _mbschr((const unsigned char*)this->text, '.') == 0) {
            goto valid;
        }
        if (ch == '.') goto invalid;
        if (ch == '\\') goto invalid;
        if (ch == ':') goto invalid;
        goto valid_chars;
    case 6:
        this->update_text();
        if (ch == ':' && this->text_len != 1) goto invalid;
        goto valid_chars;
    default:
        goto valid;
    }
    if (validation_result == 0) goto valid;
    MessageBeep(0xffffffff);
    return 0;
valid_chars:
    if (ch != '/' && ch != '"' && ch != '*' && ch != '?' &&
        ch != '>' && ch != '<' && ch != '|') goto valid;
    goto invalid;
invalid:
    MessageBeep(0xffffffff);
    return 0;
valid:
    return 1;
}

// pnl_edit.cpp lines 859-973.
void TEditPanel::draw()
{
    this->need_redraw = 0;
    if (this->visible == 0) return;
    RECT r;
    HGDIOBJ old_font;
    this->draw_setup(0);
    if (this->brush && this->active && this->have_focus) {
        unsigned char c = (unsigned char)GetNearestPaletteIndex(
            this->render_area->DrawSystem->Pal, this->back_color);
        this->render_area->Clear(&this->clip_rect, c);
    } else {
        TPanel* bg = this->parent_panel;
        if (bg) {
            if (this->bevel_type >= 2 && this->bevel_type <= 7) {
                bg->draw_rect2(&this->clip_rect);
            } else if (bg->just_drawn == 0) {
                bg->draw_rect(&this->clip_rect);
            }
        } else {
            this->render_area->Clear(&this->clip_rect, this->color);
        }
    }
    if (this->bevel_type != 0) {
        if (this->render_area->Lock("pnl_edit::draw", 1)) {
            switch (this->bevel_type) {
            case 1:
                this->render_area->DrawRect(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1, this->bevel_color1);
                break;
            case 2:
                this->render_area->DrawBevel(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->render_area->DrawBevel2(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->render_area->DrawBevel3(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color4, this->bevel_color3,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->render_area->DrawBevel(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->render_area->DrawBevel2(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->render_area->DrawBevel3(
                    this->pnl_x, this->pnl_y,
                    this->pnl_x + this->pnl_wid - 1,
                    this->pnl_y + this->pnl_hgt - 1,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color3, this->bevel_color4,
                    this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->render_area->Unlock("pnl_edit::draw");
    }
    if (this->edit_wnd && this->active) {
        if (this->have_focus) {
            if (this->hidden) {
                ShowWindow(this->edit_wnd, 5);
                InvalidateRect(this->edit_wnd, 0, 1);
                this->hidden = 0;
                this->draw_finish();
                return;
            }
        } else {
            if (!this->hidden) {
                ShowWindow(this->edit_wnd, 0);
                this->hidden = 1;
            }
            HDC dc = this->render_area->GetDc("pnl_edit::draw");
            if (dc) {
                SelectClipRgn(dc, this->clip_rgn);
                old_font = SelectObject(dc, this->font);
                SetBkMode(dc, 1);
                SetTextColor(dc, this->text_color2);
                r.left = this->draw_rect.left - 1;
                r.top = this->draw_rect.top + 1;
                r.right = this->draw_rect.right - 1;
                r.bottom = this->draw_rect.bottom + 1;
                DrawTextExA(dc, this->text, -1, &r, this->draw_format, 0);
                SetTextColor(dc, this->text_color1);
                DrawTextExA(dc, this->text, -1, &this->draw_rect,
                            this->draw_format, 0);
                SelectObject(dc, old_font);
                SelectClipRgn(dc, 0);
                this->render_area->ReleaseDc("pnl_edit::draw");
            }
        }
    }
    this->draw_finish();
}

// pnl_edit.cpp line 979.
void TEditPanel::paint()
{
}

// pnl_edit.cpp lines 987-1011.
int TEditPanel::is_blank()
{
    char* p;
    this->update_text();
    p = this->text;
    if (p == 0) goto blank;
    if (*p == 0) goto blank;
    while (1) {
        if (*p == '\0') goto blank;
        if (__ismbcspace((unsigned char)*p) == 0) return 0;
        p = (char*)__mbsinc((const unsigned char*)p);
    }
blank:
    return 1;
}

// pnl_edit.cpp lines 1017-1054.
char* TEditPanel::get_trimmed_str(char* dst, int maxlen)
{
    char temp_str[256];
    unsigned char* base;
    unsigned char* p;
    unsigned char* cur;
    this->update_text();
    memset(temp_str, 0, sizeof(temp_str));
    strcpy(temp_str, this->text);
    memset(dst, 0, maxlen);
    base = (unsigned char*)dst;
    p = base;
    cur = (unsigned char*)temp_str;
    while (__ismbcspace(*cur & 0xFF))
        cur = __mbsinc(cur);
    while (*cur) {
        _mbsncpy(p, cur, 1);
        p = __mbsinc(p);
        cur = __mbsinc(cur);
    }
    while (1) {
        *p = 0;
        if (p == base) break;
        p = __mbsdec(base, p);
        if (__ismbcspace(*p))
            continue;
        break;
    }
    return dst;
}

// pnl_edit.cpp lines 1060-1067.
void TEditPanel::handle_reactivate()
{
    if (this->edit_wnd && this->have_focus) {
        HWND focus = GetFocus();
        if (focus != this->edit_wnd) {
            SetFocus(this->edit_wnd);
        }
    }
}

// pnl_edit.cpp lines 1074-1077.
long TEditPanel::handle_mouse_down(unsigned char button, long x, long y,
                                   int flags, int area)
{
    return TPanel::handle_mouse_down(button, x, y, flags, area);
}
