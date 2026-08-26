// VA: 00475B60 TEditPanel::set_focus | pnl_edit.cpp:314-395
// BINARY NOTE: The focus-loss path reads TDrawArea::Wnd at this->render_area + 4.

#include "../../include/pnl_edit_context.h"

typedef unsigned int UINT;
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef long LRESULT;

extern "C" __declspec(dllimport) HWND __stdcall GetFocus(void);
extern "C" __declspec(dllimport) HWND __stdcall SetFocus(HWND wnd);
extern "C" __declspec(dllimport) LRESULT __stdcall SendMessageA(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
extern "C" __declspec(dllimport) int __stdcall ShowWindow(HWND wnd, int cmd);
extern "C" unsigned long __stdcall ImmGetContext(HWND wnd);
extern "C" unsigned long __stdcall ImmAssociateContext(HWND wnd, unsigned long context);
extern "C" int __stdcall ImmSetOpenStatus(unsigned long context, int open);

extern int imc_retval;
extern int DAT_0086b240;
extern unsigned int DAT_0086b244;

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
        } else {
            if (current == this->edit_wnd) {
                hwnd = (HWND)this->render_area->Wnd;
                if (current != hwnd) {
                    SetFocus(hwnd);
                }
            }
        }
    }

    if (old_focus != 0 && this->have_focus == 0) {
        this->update_text();
        this->set_redraw(TPanel::RedrawNormal);
    }
    if (this->edit_wnd != 0 && this->have_focus != 0 && old_focus == 0 && this->auto_sel != 0) {
        SendMessageA(this->edit_wnd, 0xb1, 0, -1);
    }
    if (DAT_0086b240 == 0 && this->edit_wnd != 0 && this->have_focus == 0 && this->hidden == 0) {
        ShowWindow(this->edit_wnd, 0);
        this->hidden = 1;
    }
    if (this->have_focus != 0) {
        DAT_0086b244 = 0;
    }
}
