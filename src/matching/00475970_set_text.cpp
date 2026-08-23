// VA: 00475970 TEditPanel::set_text
// pnl_edit.cpp

#include <string.h>
#include "../../include/pnl_edit_context.h"

void __cdecl strncpy(char* dst, char* src, int n);
extern int (__stdcall *SetWindowTextA_ptr)(int, char*);
#pragma comment(linker, "/alternatename:_SetWindowTextA_ptr=__imp__SetWindowTextA@8")

void TEditPanel::set_text(char* text) {
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
        SetWindowTextA_ptr((int)edit_wnd, this->text);
        sel_len = 0;
    }
    this->set_redraw(1);
}
