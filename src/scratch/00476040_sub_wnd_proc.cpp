// VA 00476040 TEditPanel::sub_wnd_proc
// PDB source: pnl_edit.cpp:604-753
//
// Attempt log:
// - the packet-shaped first pass used synthetic router/filter helpers and was
//   125 bytes short with no aligned Win32 call targets;
// - replacing those with windows.h imports and the typed panel chain restored
//   the 25-call topology (the best intermediate was 80% ordered-call parity);
// - the current source follows the period-shaped local scopes and forwarding
//   surface recovered from the original PDB/decompiler line bands.  In
//   particular, the erase RECT is scoped to its paint branch and the four
//   selection DWORDs are separate post-default locals.
// - replacing the reused message output slot with sel_start_after improved
//   the structural diff (926 bytes, 54.26% shape) without changing calls.
// - making WM_MOUSEMOVE an ordinary switch arm produced the best structural
//   checkpoint: 96% ordered-call alignment, 923-byte diff, and -2-byte size
//   gap; the remaining frame is 0x20 versus the original 0x1C.
// - unresolved: switch/default block placement and the remaining frame/local
//   allocation drift; no further blind variants after the ten-probe budget.

#include <windows.h>

extern int DAT_0086b240;
extern int DAT_0062c4c4;

class RGE_Base_Game {
public:
    char gap_00[0x1D0];
    int windows_mouse;
    void mouse_off();
};
extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    void* DrawSystem;
    HWND Wnd;
};

class TPanel {
public:
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual long wnd_proc(void* hwnd, unsigned int msg,
                          unsigned int wparam, long lparam);
    virtual void v4C(); virtual void v50(); virtual void v54();
    virtual long handle_key_down(unsigned int key, short lparam,
                                 int alt, int ctrl, int shift);
    virtual void v5C(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6C(); virtual void v70();
    virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void v8C(); virtual void v90(); virtual void v94();
    virtual void v98(); virtual void v9C(); virtual void vA0();
    virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual long action(TPanel* panel, int a, int b, int c);

    char gap_04[8];
    long pnl_x;
    long pnl_y;
    long width;
    long height;
    char gap_1C[4];
    TDrawArea* render_area;
    RECT clip_rect;
    char gap_34[4];
    int need_redraw;
    char gap_3C[4];
    TPanel* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[4];
    int have_focus;
    char gap_7C[0x78];
};

class TEditPanel : public TPanel {
public:
    HWND edit_wnd;
    char gap_F8[0x0C];
    int hidden;
    HBRUSH brush;
    char gap_10C[4];
    WNDPROC old_sub_wnd_proc;
    char gap_114[0x4C];
    HIMC imc;
    int enable_ime;

    long sub_wnd_proc(void* hwnd, unsigned int msg,
                      unsigned int wparam, long lparam);
    int verify_char(int ch);
    void update_text();
};

class TPanelSystem {
public:
    char gap_00[0x0C];
    TPanel* current_panel;
    TPanel* currentPanel();
};
extern TPanelSystem panel_system;

long TEditPanel::sub_wnd_proc(void* hwnd, unsigned int msg,
                              unsigned int wparam, long lparam)
{
    unsigned int saved_msg = msg;
    long saved_lparam = lparam;
    DWORD sel_start_before;
    DWORD sel_end_before;
    DWORD sel_start_after;
    DWORD sel_end_after;

    if (this->edit_wnd != 0 && this->active != 0 &&
        this->visible != 0 && this->hidden == 0) {
        if (saved_msg < 0x15) {
            if (saved_msg == WM_ERASEBKGND) {
                if (this->brush != 0) {
                    RECT rect;
                    HDC hdc = (HDC)wparam;
                    SelectObject(hdc, (HGDIOBJ)this->brush);
                    GetClientRect((HWND)hwnd, &rect);
                    FillRect(hdc, &rect, (HBRUSH)this->brush);
                    return 1;
                }
            } else if (saved_msg == WM_PAINT) {
                InvalidateRect((HWND)hwnd, 0, TRUE);
            }
        } else {
            if (saved_msg < 0x201) {
                switch (saved_msg) {
                case WM_MOUSEMOVE:
                    if (rge_base_game->windows_mouse == 0) {
                        DAT_0062c4c4 = 1;
                        rge_base_game->mouse_off();
                    }
                    break;
                case WM_KEYDOWN:
                    if (this->parent_panel == 0) {
                        if (wparam == VK_ESCAPE) {
                            SendMessageA((HWND)this->edit_wnd,
                                         EM_UNDO, 0, 0);
                            return 0;
                        }
                    } else {
                        const long handled = this->parent_panel->wnd_proc(
                            hwnd, saved_msg, wparam, saved_lparam);
                        if (handled != 0) {
                            return 0;
                        }
                        if (wparam == VK_TAB) {
                            const int alt_down = (GetKeyState(VK_MENU) < 0);
                            const int ctrl_down = (GetKeyState(VK_CONTROL) < 0);
                            const int shift_down = (GetKeyState(VK_SHIFT) < 0);
                            DAT_0086b240 = 1;
                            this->parent_panel->handle_key_down(
                                VK_TAB, (short)saved_lparam, alt_down,
                                ctrl_down, shift_down);
                            DAT_0086b240 = 0;
                            return 0;
                        }
                        if (wparam == VK_RETURN) {
                            this->parent_panel->action(this, 0, 0, 0);
                            return 0;
                        }
                        if (wparam == VK_ESCAPE) {
                            const long esc_handled =
                                this->parent_panel->action(this, 1, 0, 0);
                            if (esc_handled != 0) {
                                return 0;
                            }
                            SendMessageA((HWND)this->edit_wnd,
                                         EM_UNDO, 0, 0);
                            return 0;
                        }
                    }
                    break;
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
                        PostMessageA((HWND)this->render_area->Wnd,
                                     (UINT)saved_msg, (WPARAM)wparam,
                                     (LPARAM)saved_lparam);
                    }
                    return 0;
                default:
                    break;
                }
            }
        }
    }

default_processing:
    sel_start_before = 0;
    sel_end_before = 0;
    sel_start_after = 0;
    sel_end_after = 0;

    if (this->edit_wnd == 0 || saved_msg == EM_GETSEL) {
        lparam = 0;
    } else {
        lparam = 1;
        SendMessageA((HWND)this->edit_wnd, EM_GETSEL,
                     (WPARAM)&sel_start_before,
                     (LPARAM)&sel_end_before);
    }

    WNDPROC old_proc = (WNDPROC)this->old_sub_wnd_proc;
    long ret = (long)CallWindowProcA((FARPROC)old_proc, (HWND)hwnd,
                                     (UINT)saved_msg, (WPARAM)wparam,
                                     (LPARAM)saved_lparam);

    if (lparam != 0) {
        SendMessageA((HWND)this->edit_wnd, EM_GETSEL,
                     (WPARAM)&sel_start_after,
                     (LPARAM)&sel_end_after);
        if (sel_start_after != sel_start_before ||
            sel_end_after != sel_end_before) {
            InvalidateRect((HWND)this->edit_wnd, 0, TRUE);
            UpdateWindow((HWND)this->edit_wnd);
        }
    }

    if (saved_msg == WM_PASTE) {
        this->update_text();
    }

    if (saved_msg == WM_LBUTTONDOWN || saved_msg == WM_LBUTTONUP ||
        saved_msg == WM_RBUTTONDOWN || saved_msg == WM_RBUTTONUP) {
        const unsigned int x = (unsigned int)saved_lparam & 0xFFFF;
        const unsigned int y = ((unsigned int)saved_lparam >> 16) & 0xFFFF;
        const unsigned int nx =
            (unsigned int)(this->pnl_x + (long)x) & 0xFFFF;
        const unsigned int ny =
            (unsigned int)(this->pnl_y + (long)y) & 0xFFFF;
        const long new_lparam = (long)((ny << 16) | nx);
        TPanel* cp = panel_system.currentPanel();
        ret = cp->wnd_proc((void*)this->render_area->Wnd,
                           saved_msg, wparam, new_lparam);
    }

    return ret;
}
