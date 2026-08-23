// VA: 00475A30 TEditPanel::update_text (pnl_edit.cpp:221-266, 192B)
// Baseline: canonical TPanel-derived layout and the natural edit-buffer
// synchronization source shape reconstructed from the original call/field
// sequence.
// Attempt log:
// 1: natural layout/body baseline; exact size/frame/calls, but comparison used
//    the opposite operand order (4 bytes differed).
// 2: wrote the overflow test as text_len > fixed_len - 1; reduced drift to the
//    original cmp/jle family (2 bytes differed in EM_GETSEL local stores).
// 3: kept the ordinary end/start locals but assigned start before end; exact.

#include <string.h>
#include "../../include/pnl_edit_context.h"

extern "C" __declspec(dllimport) int __stdcall GetWindowTextA(
    void* hwnd, char* text, int max_count);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(
    void* hwnd, const char* text);
extern "C" int (__stdcall* const MessageBeep)(unsigned int);
extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    HWND hwnd, unsigned int message, unsigned int wparam, long lparam);

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
        SendMessageA(this->edit_wnd, 0xb0,
                     (unsigned int)&start, (long)&end);
        this->sel_len = end - start;
    }
}
