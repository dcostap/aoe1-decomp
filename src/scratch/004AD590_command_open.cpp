// TRIBE_Screen_Sed::command_open — real pass (EH-framed)
// VA: 004AD590
#include "../../include/game_globals.h"

extern unsigned char __fastcall _needToSave(void* _this);
extern void __fastcall _popupYesNoCancel(void* _this, int _, int strId, char* title, int unk, int timeout);
extern void* __fastcall _operatorNew(int _, int size);
extern void __fastcall _openCtor(void* obj, int _);
extern int __fastcall _setCurrentPanel(void* sys, int _, char* name, int flag);

void __fastcall command_open(void* _this, int _)
{
    if (_needToSave(_this)) {
        _popupYesNoCancel(_this, 0, 0x2447, (char*)"OpenSaveDialog", 0x1C2, 100);
        return;
    }
    void* obj = _operatorNew(0, 0x490);
    if (obj)
        _openCtor(obj, 0);
    _setCurrentPanel((void*)0x62E870, 0, (char*)"Scenario Editor Open", 0);
}
