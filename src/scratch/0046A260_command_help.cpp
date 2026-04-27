// TEasy_Panel::command_help — first pass
// VA: 0046A260
// EH-framed, ret 14h

#include "../../include/game_globals.h"

extern char* __fastcall _getString(void* _this, int id);
extern void* __cdecl _opNew(int size);

int __fastcall command_help(void* _this, int _, char* param_1, int param_2, int param_3, int param_4, int param_5)
{
    if (param_2 >= 0) {
        char* str = _getString(_this, param_2);
        if (str && *str) {
            void* hd = _opNew(0x5A4);
            if (hd) {
                // THelpDialog::THelpDialog(hd, _this, param_1, param_2, param_3, param_4, param_5)
                // at 0043E840h
            }
        }
    }
    return 0;
}
