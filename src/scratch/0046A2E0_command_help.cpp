// TEasy_Panel::command_help — first pass (115B variant)
// VA: 0046A2E0

#include "../../include/game_globals.h"
extern void* __cdecl _opNew(int size);

int __fastcall command_help2(void* _this, int _, char* param_1, char* param_2, int param_3, int param_4, int param_5)
{
    if (param_2 && *param_2) {
        void* hd = _opNew(0x5A4);
        if (hd) {
            // THelpDialog::THelpDialog(hd, _this, param_1, param_2, param_3, param_4, param_5)
            // at 0043E8E0h
        }
    }
    return 0;
}
