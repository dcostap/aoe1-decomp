// TEasy_Panel::popupYesNoDialog — first pass (192B)
// VA: 0046A090

#include "../../include/game_globals.h"
extern void* __cdecl _opNew(int size);
extern void __fastcall _msgDialogCtor(void* _this, void* parent, char* str);

int __fastcall popupYesNoDialog(void* _this, int _, char* str, int p2, int p3, int p4)
{
    if (str && *str) {
        void* dlg = _opNew(0x4A4);
        if (dlg) {
            _msgDialogCtor(dlg, _this, str);
            return (int)dlg;
        }
    } else {
        void* dlg = _opNew(0x4A4);
        if (dlg) {
            _msgDialogCtor(dlg, _this, "584EC0h");
            return (int)dlg;
        }
    }
    return 0;
}
