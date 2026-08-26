#include "../../include/pnl_edit_context.h"

extern "C" __declspec(dllimport) long __stdcall GetWindowLongA(void* wnd, int index);

static long __stdcall pnl_sub_wnd_proc(void* wnd, unsigned int msg, unsigned int wParam, long lParam) {
    TEditPanel* panel = (TEditPanel*)GetWindowLongA(wnd, -21);
    if (panel != 0) {
        return panel->sub_wnd_proc(wnd, msg, wParam, lParam);
    }
    return 0;
}
