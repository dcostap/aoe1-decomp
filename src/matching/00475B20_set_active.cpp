#include "../../include/pnl_edit_context.h"

extern "C" __declspec(dllimport) int __stdcall ShowWindow(HWND hWnd, int nCmdShow);

void TEditPanel::set_active(int active) {
    TPanel::set_active(active);
    if ((this->edit_wnd != 0) && (this->active == 0)) {
        ShowWindow(this->edit_wnd, 0);
        this->hidden = 1;
    }
}
