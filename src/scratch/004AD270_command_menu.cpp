// TRIBE_Screen_Sed::command_menu — real pass (EH-framed)
// VA: 004AD270
#include "../../include/game_globals.h"

extern void* __fastcall _operatorNew(int _, int size);
extern void __fastcall _menuCtor(void* obj, int _, void* screen);

int __fastcall command_menu(void* _this, int _)
{
    void* obj = _operatorNew(0, 0x4B4);
    if (!obj) return 1;
    _menuCtor(obj, 0, _this);
    if (obj && *(void**)((char*)obj + 0xD8)) {
        (*(void(__stdcall**)(int))(*(int*)obj))(1);
        return 0;
    }
    return 1;
}
