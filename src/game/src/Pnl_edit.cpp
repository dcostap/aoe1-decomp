#include "../include/TEditPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TDrawArea.h"
#include "../include/RGE_Base_Game.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>
#include <mbstring.h>
#include <imm.h>

static LRESULT CALLBACK pnl_sub_wnd_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    TEditPanel* panel = (TEditPanel*)GetWindowLongPtrA(hwnd, GWLP_USERDATA);
    if (panel) {
        return (LRESULT)panel->sub_wnd_proc(hwnd, msg, (uint)wparam, (long)lparam);
    }
    return 0;
}

TEditPanel::TEditPanel() : TPanel(nullptr) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x004755C0
    this->edit_wnd = nullptr;
    this->text = nullptr;
    this->fixed_len = 0;
    this->brush = nullptr;
    this->old_sub_wnd_proc = nullptr;
    this->text_color1 = 0;
    this->text_color2 = 0;
    this->highlight_text_color1 = 0;
    this->highlight_text_color2 = 0;
    this->back_color = 0;
    this->sel_len = 0;
    this->bevel_color1 = 0;
    this->bevel_color2 = 0;
    this->bevel_color3 = 0;
    this->bevel_color4 = 0;
    this->bevel_color5 = 0;
    this->bevel_color6 = 0;
    this->bevel_size = 0;
    this->imc = 0;
    this->enable_ime = 0;
    this->turn_ime_on = 0;
    this->hidden = 1;
    this->bevel_type = 1;
    this->stock_brush = 0;
    this->text_len = 0;
    this->format = FormatAny;
    this->font = nullptr;
    this->multi_line = 0;
    memset(&this->draw_rect_value, 0, sizeof(this->draw_rect_value));
    this->draw_format = 0;
    this->auto_sel = 0;
}

TEditPanel::~TEditPanel() {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475690
    if (this->edit_wnd && this->hidden == 0) {
        ShowWindow((HWND)this->edit_wnd, SW_HIDE);
        this->hidden = 1;
    }
    if (this->text) {
        free(this->text);
        this->text = nullptr;
    }
    if (this->edit_wnd) {
        if (this->imc != 0) {
            ImmNotifyIME((HIMC)this->imc, 0x15, 4, 0);
            if (this->enable_ime != 0) {
                ImmReleaseContext((HWND)this->edit_wnd, (HIMC)this->imc);
            }
            this->imc = 0;
        }
        DestroyWindow((HWND)this->edit_wnd);
        this->edit_wnd = nullptr;
    }
}

long TEditPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

long TEditPanel::setup(TDrawArea* render_area, TPanel* parent, long x, long y, long w, long h, void* font, short fixed_len_in, char* initial_text, FormatType format_in, int auto_sel_in) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475770
    this->format = format_in;
    if (0 < fixed_len_in) {
        fixed_len_in = fixed_len_in + 1;
    }
    this->fixed_len = fixed_len_in;
    this->font = font;
    this->auto_sel = auto_sel_in;

    if (!TPanel::setup(render_area, parent, x, y, w, h, 0xFF)) {
        return 0;
    }

    const int is_multiline = (this->format == FormatMultiLine);
    DWORD style = WS_CHILD | WS_TABSTOP | ES_LEFT | ES_NOHIDESEL;
    if (is_multiline) {
        style |= ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL | ES_WANTRETURN;
    } else {
        style |= ES_AUTOHSCROLL;
    }

    HWND hwnd = CreateWindowExA(
        0,
        "edit",
        nullptr,
        style,
        (int)x + 1,
        (int)y + 1,
        (int)w - 2,
        (int)h - 2,
        (HWND)(render_area ? render_area->Wnd : nullptr),
        (HMENU)1,
        AppInst,
        nullptr);

    this->edit_wnd = hwnd;
    if (!hwnd) {
        return 0;
    }

    SetWindowLongPtrA(hwnd, GWLP_USERDATA, (LONG_PTR)this);
    this->old_sub_wnd_proc = (int(__stdcall*)())GetWindowLongPtrA(hwnd, GWLP_WNDPROC);
    SetWindowLongPtrA(hwnd, GWLP_WNDPROC, (LONG_PTR)pnl_sub_wnd_proc);

    this->text = (char*)calloc((size_t)this->fixed_len + 2, 1);
    if (!this->text) {
        return 0;
    }
    this->text[0] = '\0';
    this->text_len = 0;

    if (initial_text && *initial_text) {
        this->set_text(initial_text);
    }

    this->brush = GetStockObject(WHITE_BRUSH);
    this->stock_brush = 1;
    this->text_color1 = 0x00FFFFFF;
    this->highlight_text_color1 = 0x00FFFFFF;
    this->back_color = 0;
    this->text_color2 = 0;
    this->highlight_text_color2 = 0;

    if (this->font) {
        SendMessageA(hwnd, WM_SETFONT, (WPARAM)this->font, 0);
    }

    this->draw_format = is_multiline ? 0x2010 : 0x2020;
    return 1;
}

void TEditPanel::set_text(char* s) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475970
    if (this->edit_wnd) {
        if (!s) {
            if (this->text) this->text[0] = '\0';
            this->text_len = 0;
        } else if (this->text) {
            memset(this->text, 0, (size_t)this->fixed_len);
            strncpy(this->text, s, (size_t)this->fixed_len - 1);
            this->text[(size_t)this->fixed_len - 1] = '\0';
            this->text_len = (int)strlen(this->text);
        }
        SetWindowTextA((HWND)this->edit_wnd, this->text ? this->text : "");
        this->sel_len = 0;
    }
    this->set_redraw(TPanel::RedrawMode::RedrawFull);
}

void TEditPanel::update_text() {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475A30
    if (!this->edit_wnd || !this->text) return;
    GetWindowTextA((HWND)this->edit_wnd, this->text, (int)this->fixed_len + 1);
    this->text_len = (int)strlen(this->text);
    this->text[(size_t)this->fixed_len - 1] = '\0';
    if ((int)((size_t)this->fixed_len - 1) < this->text_len) {
        SetWindowTextA((HWND)this->edit_wnd, this->text);
        MessageBeep((UINT)-1);
    }
    DWORD start = 0;
    DWORD end = 0;
    SendMessageA((HWND)this->edit_wnd, EM_GETSEL, (WPARAM)&start, (LPARAM)&end);
    this->sel_len = (int)(end - start);
}

char* TEditPanel::get_text() {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475AF0
    this->update_text();
    return this->text;
}

char* TEditPanel::get_input_buffer() {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475B00
    this->update_text();
    return this->text;
}

char* TEditPanel::currentLine() {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475B10
    this->update_text();
    return this->text;
}

void TEditPanel::set_active(int param_1) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475B20
    TPanel::set_active(param_1);
    if (this->edit_wnd && this->active == 0) {
        ShowWindow((HWND)this->edit_wnd, SW_HIDE);
        this->hidden = 1;
    }
}

void TEditPanel::set_focus(int param_1) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475B60
    const int had_focus = this->have_focus;
    TPanel::set_focus(param_1);

    if (this->edit_wnd) {
        const HWND focus_wnd = GetFocus();
        const HWND edit_wnd = (HWND)this->edit_wnd;

        if (this->have_focus == 0) {
            if (focus_wnd == edit_wnd) {
                const HWND render_wnd = (HWND)this->render_area->Wnd;
                if (focus_wnd != render_wnd) {
                    SetFocus(render_wnd);
                }
            }
        } else {
            if (focus_wnd != edit_wnd) {
                SetFocus(edit_wnd);
            }

            if (this->imc == 0) {
                if (this->enable_ime == 0) {
                    this->imc = (unsigned long)ImmAssociateContext(edit_wnd, 0);
                } else {
                    this->imc = (unsigned long)ImmGetContext(edit_wnd);
                }
            }

            if (this->imc != 0 && this->enable_ime != 0) {
                ImmSetOpenStatus((HIMC)this->imc, this->turn_ime_on != 0);
            }
        }
    }
    if (had_focus != 0 && this->have_focus == 0) {
        this->update_text();
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }
    if (this->edit_wnd && this->have_focus && had_focus == 0 && this->auto_sel) {
        SendMessageA((HWND)this->edit_wnd, EM_SETSEL, 0, (LPARAM)-1);
    }

    if (DAT_0086b240 == 0 && this->edit_wnd && this->have_focus == 0 && this->hidden == 0) {
        ShowWindow((HWND)this->edit_wnd, SW_HIDE);
        this->hidden = 1;
    }

    if (this->have_focus != 0) {
        DAT_0086b244 = 0;
    }
}

void TEditPanel::set_rect(tagRECT param_1) {
    TPanel::set_rect(param_1);
}

void TEditPanel::set_rect(long x, long y, long w, long h) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475CC0
    TPanel::set_rect(x, y, w, h);
    if (this->edit_wnd) {
        const int bs = this->bevel_size;
        const BOOL do_redraw = (this->hidden == 0 && this->visible != 0 && this->active != 0);
        MoveWindow((HWND)this->edit_wnd,
            (int)(this->pnl_x + bs),
            (int)(this->pnl_y + bs),
            (int)(this->pnl_wid - bs * 2 - 1),
            (int)(this->pnl_hgt - bs * 2 - 1),
            do_redraw);
    }

    const int bs = this->bevel_size;
    if (this->format == FormatMultiLine) {
        this->draw_rect_value.left = (LONG)(this->render_rect.left + 1 + bs);
        this->draw_rect_value.top = (LONG)(this->render_rect.top + bs);
        const int sb_wid = GetSystemMetrics(SM_CXVSCROLL);
        this->draw_rect_value.right = (LONG)(((this->render_rect.right - bs) - sb_wid) - 1);
        this->draw_rect_value.bottom = (LONG)(this->render_rect.bottom - bs);
        return;
    }

    this->draw_rect_value.left = (LONG)(this->render_rect.left + 8 + bs);
    this->draw_rect_value.top = (LONG)(this->render_rect.top + bs);
    this->draw_rect_value.right = (LONG)(this->render_rect.right - bs);
    this->draw_rect_value.bottom = (LONG)(this->render_rect.bottom - bs);
}

void TEditPanel::set_redraw(RedrawMode param_1) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475DD0
    TPanel::set_redraw(TPanel::RedrawMode::Redraw);
    if (this->have_focus && param_1 != TPanel::RedrawMode::NoRedraw && this->edit_wnd && this->hidden == 0) {
        InvalidateRect((HWND)this->edit_wnd, nullptr, TRUE);
    }
}

void TEditPanel::set_text_color(unsigned long c1, unsigned long c2) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475E10
    this->text_color1 = c1;
    this->text_color2 = c2;
    this->set_redraw(TPanel::RedrawMode::RedrawFull);
}

void TEditPanel::set_highlight_text_color(unsigned long c1, unsigned long c2) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475E30 (no-op)
    (void)c1;
    (void)c2;
}

void TEditPanel::set_back_color(void* brush_in, unsigned long brush_color_in, unsigned char back_color_in) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475E40 (no-op)
    (void)brush_in;
    (void)brush_color_in;
    (void)back_color_in;
}

void TEditPanel::set_bevel_info(int bevel_type_in, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475E50
    this->bevel_type = bevel_type_in;
    this->bevel_color1 = c1;
    this->bevel_color2 = c2;
    this->bevel_color3 = c3;
    this->bevel_color4 = c4;
    this->bevel_color5 = c5;
    this->bevel_color6 = c6;

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

    this->set_rect(this->pnl_x, this->pnl_y, this->pnl_wid, this->pnl_hgt);
    this->set_redraw(TPanel::RedrawMode::RedrawFull);
}

void TEditPanel::set_ime_info(int enable, int turn_on) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475F20
    this->enable_ime = enable;
    this->turn_ime_on = turn_on;
}

long TEditPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00475F40
    void* pvVar1 = this->edit_wnd;
    if (pvVar1 != nullptr && this->active != 0 && this->visible != 0 && this->hidden == 0) {
        if (param_2 == WM_SETFOCUS) {
            return TPanel::wnd_proc(param_1, WM_SETFOCUS, param_3, param_4);
        }
        if (param_2 == WM_COMMAND) {
            if ((void*)param_4 == pvVar1 && (short)(param_3 >> 16) == 0x400) {
                InvalidateRect((HWND)pvVar1, nullptr, TRUE);
            }
        } else if (param_2 == WM_CTLCOLOREDIT && this->brush != nullptr && (HWND)(param_4 & 0xFFFF) == (HWND)pvVar1) {
            HDC hdc = (HDC)param_3;
            SetBkColor(hdc, (COLORREF)this->back_color);
            SetBkMode(hdc, 2);
            SetTextColor(hdc, (COLORREF)this->highlight_text_color1);
            return (long)this->brush;
        }
    }
    return TPanel::wnd_proc(param_1, param_2, param_3, param_4);
}

long TEditPanel::sub_wnd_proc(void* hwnd, uint msg, uint wparam, long lparam) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00476040
    if (this->edit_wnd != nullptr && this->active != 0 && this->visible != 0 && this->hidden == 0) {
        if (msg < 0x15) {
            if (msg == WM_ERASEBKGND) {
                if (this->brush != nullptr) {
                    tagRECT rect{};
                    HDC hdc = (HDC)wparam;
                    SelectObject(hdc, (HGDIOBJ)this->brush);
                    GetClientRect((HWND)hwnd, &rect);
                    FillRect(hdc, &rect, (HBRUSH)this->brush);
                    return 1;
                }
            } else if (msg == WM_PAINT) {
                InvalidateRect((HWND)hwnd, nullptr, TRUE);
            }
        } else if (msg < 0x201) {
            if (msg == WM_MOUSEMOVE) {
                if (rge_base_game->windows_mouse == 0) {
                    MouseCursorInChildContol = 1;
                    rge_base_game->mouse_off();
                }
            } else {
                switch (msg) {
                case WM_KEYDOWN: {
                    if (this->parent_panel == nullptr) {
                        if (wparam == VK_ESCAPE) {
                            SendMessageA((HWND)this->edit_wnd, EM_UNDO, 0, 0);
                            return 0;
                        }
                    } else {
                        const long handled = this->parent_panel->wnd_proc(hwnd, msg, wparam, lparam);
                        if (handled != 0) {
                            return 0;
                        }

                        if (wparam == VK_TAB) {
                            const int alt_down = (GetKeyState(VK_MENU) < 0);
                            const int ctrl_down = (GetKeyState(VK_CONTROL) < 0);
                            const int shift_down = (GetKeyState(VK_SHIFT) < 0);
                            DAT_0086b240 = 1;
                            this->handle_key_down(VK_TAB, (short)lparam, alt_down, ctrl_down, shift_down);
                            DAT_0086b240 = 0;
                            return 0;
                        }
                        if (wparam == VK_RETURN) {
                            this->parent_panel->action((TPanel*)this, 0, 0, 0);
                            return 0;
                        }
                        if (wparam == VK_ESCAPE) {
                            const long esc_handled = this->parent_panel->action((TPanel*)this, 1, 0, 0);
                            if (esc_handled != 0) {
                                return 0;
                            }
                            SendMessageA((HWND)this->edit_wnd, EM_UNDO, 0, 0);
                            return 0;
                        }
                    }
                    break;
                }
                case WM_KEYUP:
                    if (wparam == VK_TAB) {
                        return 0;
                    }
                    break;
                case WM_CHAR:
                    if (this->verify_char((int)wparam) == 0) {
                        return 0;
                    }
                    break;
                case WM_SYSKEYDOWN:
                    if (this->imc == 0 || this->enable_ime == 0) {
                        SetFocus((HWND)this->render_area->Wnd);
                        PostMessageA((HWND)this->render_area->Wnd, (UINT)msg, (WPARAM)wparam, (LPARAM)lparam);
                    }
                    return 0;
                default:
                    break;
                }
            }
        }
    }

    DWORD sel_start_before = 0;
    DWORD sel_end_before = 0;
    DWORD sel_start_after = 0;
    DWORD sel_end_after = 0;
    int track_sel = 0;

    if (this->edit_wnd == nullptr || msg == EM_GETSEL) {
        track_sel = 0;
    } else {
        track_sel = 1;
        SendMessageA((HWND)this->edit_wnd, EM_GETSEL, (WPARAM)&sel_start_before, (LPARAM)&sel_end_before);
    }

    long ret = 0;
    WNDPROC old_proc = (WNDPROC)this->old_sub_wnd_proc;
    if (old_proc != nullptr) {
        ret = (long)CallWindowProcA(old_proc, (HWND)hwnd, (UINT)msg, (WPARAM)wparam, (LPARAM)lparam);
    }

    if (track_sel != 0) {
        SendMessageA((HWND)this->edit_wnd, EM_GETSEL, (WPARAM)&sel_start_after, (LPARAM)&sel_end_after);
        if (sel_start_after != sel_start_before || sel_end_after != sel_end_before) {
            InvalidateRect((HWND)this->edit_wnd, nullptr, TRUE);
            UpdateWindow((HWND)this->edit_wnd);
        }
    }

    if (msg == WM_PASTE) {
        this->update_text();
    }

    if (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONUP || msg == WM_RBUTTONDOWN || msg == WM_RBUTTONUP) {
        const uint x = (uint)lparam & 0xFFFF;
        const uint y = ((uint)lparam >> 16) & 0xFFFF;
        const uint nx = ((uint)(this->pnl_x + (long)x)) & 0xFFFF;
        const uint ny = ((uint)(this->pnl_y + (long)y)) & 0xFFFF;
        const long new_lparam = (long)((ny << 16) | nx);
        TPanel* cp = panel_system->currentPanel();
        ret = cp->wnd_proc((void*)this->render_area->Wnd, msg, wparam, new_lparam);
    }

    return ret;
}

int TEditPanel::verify_char(int param_1) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00476440
    if (DAT_0086b244 != 0) {
        DAT_0086b244 = 0;
        return 0;
    }
    if (param_1 == VK_TAB) {
        return 0;
    }
    if (param_1 == VK_RETURN && this->format != FormatMultiLine) {
        return 0;
    }
    if (param_1 == VK_BACK) {
        return 1;
    }

    this->update_text();

    if (this->sel_len == 0) {
        if ((int)this->fixed_len - 1 <= this->text_len) {
            MessageBeep((UINT)-1);
            return 0;
        }
        if ((int)this->fixed_len - 2 <= this->text_len && IsDBCSLeadByte((BYTE)param_1) != 0) {
            DAT_0086b244 = 1;
            MessageBeep((UINT)-1);
            return 0;
        }
    }

    switch (this->format) {
    default:
        return 1;
    case FormatNumber:
    case FormatInteger:
    case FormatUnsignedInt:
        this->update_text();
        if (0x2f < param_1 && param_1 < 0x3a) {
            return 1;
        }
        if (param_1 == 0x2d && this->text != nullptr && *this->text == '\0' && this->format != FormatUnsignedInt) {
            return 1;
        }
        if (param_1 == 0x2e) {
            if (_mbschr((unsigned char*)this->text, 0x2e) == nullptr) {
                MessageBeep((UINT)-1);
                return 0;
            }
            if (this->format == FormatNumber) {
                return 1;
            }
        }
        MessageBeep((UINT)-1);
        return 0;
    case FormatFile:
    case FormatFileNoExt:
        this->update_text();
        if (param_1 == 0x2e) {
            if (this->format == FormatFile && _mbschr((unsigned char*)this->text, 0x2e) == nullptr) {
                return 1;
            }
            MessageBeep((UINT)-1);
            return 0;
        }
        if (param_1 == 0x5c || param_1 == 0x3a) {
            MessageBeep((UINT)-1);
            return 0;
        }
        goto format_path_common;
    case FormatPath:
        this->update_text();
        if (param_1 == 0x3a && this->text_len != 1) {
            MessageBeep((UINT)-1);
            return 0;
        }
    format_path_common:
        if (param_1 != 0x2f && param_1 != 0x22 && param_1 != 0x2a && param_1 != 0x3f && param_1 != 0x3e && param_1 != 0x3c &&
            param_1 != 0x7c) {
            return 1;
        }
        MessageBeep((UINT)-1);
        return 0;
    case FormatPercent:
        if (this->text_len < 2 && 0x2f < param_1 && param_1 < 0x3a) {
            return 1;
        }
        if (this->text_len == 2 && param_1 == 0x30) {
            const int cmp = _mbscmp((const unsigned char*)"10", (const unsigned char*)this->text);
            if (cmp == 0) {
                return 1;
            }
        }
        MessageBeep((UINT)-1);
        return 0;
    }
}

int TEditPanel::is_blank() {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00476A60
    this->update_text();
    char* s = this->text;
    if (s && *s) {
        for (; *s; s = (char*)_mbsinc((unsigned char*)s)) {
            if (_ismbcspace((unsigned char)*s) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

char* TEditPanel::get_trimmed_str(char* out, int out_len) {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00476AB0
    if (!out || out_len <= 0) {
        return out;
    }

    this->update_text();
    memset(out, 0, (size_t)out_len);

    char temp[256];
    memset(temp, 0, sizeof(temp));

    const char* cur = this->text;
    if (!cur) cur = "";
    strncpy(temp + 4, cur, sizeof(temp) - 5);

    unsigned char* s = (unsigned char*)(temp + 4);
    while (*s && _ismbcspace(*s) != 0) {
        s = _mbsinc(s);
    }

    unsigned char* d = (unsigned char*)out;
    while (*s) {
        _mbsncpy(d, s, 1);
        d = _mbsinc(d);
        s = _mbsinc(s);
    }

    while (d != (unsigned char*)out) {
        *d = '\0';
        unsigned char* prev = _mbsdec((unsigned char*)out, d);
        if (!prev || _ismbcspace(*prev) == 0) {
            break;
        }
        d = prev;
    }
    return out;
}

// Boilerplate virtual forwards
void TEditPanel::set_color(uchar param_1) { TPanel::set_color(param_1); }
void TEditPanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void TEditPanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TEditPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TEditPanel::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void TEditPanel::draw_finish() { TPanel::draw_finish(); }
void TEditPanel::draw() { TPanel::draw(); }
void TEditPanel::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); }
void TEditPanel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset(param_1, param_2, param_3); }
void TEditPanel::draw_rect2(tagRECT* param_1) { TPanel::draw_rect2(param_1); }
void TEditPanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset2(param_1, param_2, param_3); }
void TEditPanel::paint() { TPanel::paint(); }
long TEditPanel::handle_idle() { return TPanel::handle_idle(); }
long TEditPanel::handle_size(long param_1, long param_2) { return TPanel::handle_size(param_1, param_2); }
long TEditPanel::handle_paint() { return TPanel::handle_paint(); }
long TEditPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TEditPanel::handle_char(long param_1, short param_2) { return TPanel::handle_char(param_1, param_2); }
long TEditPanel::handle_command(uint param_1, long param_2) { return TPanel::handle_command(param_1, param_2); }
long TEditPanel::handle_user_command(uint param_1, long param_2) { return TPanel::handle_user_command(param_1, param_2); }
long TEditPanel::handle_timer_command(uint param_1, long param_2) { return TPanel::handle_timer_command(param_1, param_2); }
long TEditPanel::handle_scroll(long param_1, long param_2) { return TPanel::handle_scroll(param_1, param_2); }
long TEditPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TEditPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TEditPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TEditPanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TEditPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TEditPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TEditPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TEditPanel::char_action(long param_1, short param_2) { return TPanel::char_action(param_1, param_2); }
long TEditPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TPanel::action(param_1, param_2, param_3, param_4); }
void TEditPanel::get_true_render_rect(tagRECT* param_1) { TPanel::get_true_render_rect(param_1); }
int TEditPanel::is_inside(long param_1, long param_2) { return TPanel::is_inside(param_1, param_2); }
void TEditPanel::set_tab_order(TPanel* param_1, TPanel* param_2) { TPanel::set_tab_order(param_1, param_2); }
void TEditPanel::set_tab_order(TPanel** param_1, short param_2) { TPanel::set_tab_order(param_1, param_2); }
uchar TEditPanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TEditPanel::stop_sound_system() { TPanel::stop_sound_system(); }
int TEditPanel::restart_sound_system() { return TPanel::restart_sound_system(); }
void TEditPanel::take_snapshot() { TPanel::take_snapshot(); }
void TEditPanel::handle_reactivate() {
    // Fully verified. Source of truth: pnl_edit.cpp.decomp @ 0x00476BB0
    if (this->edit_wnd && this->have_focus != 0) {
        HWND focused = GetFocus();
        HWND edit = (HWND)this->edit_wnd;
        if (focused != edit) {
            SetFocus(edit);
        }
    }
}

