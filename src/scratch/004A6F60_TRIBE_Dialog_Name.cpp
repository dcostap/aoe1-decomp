// TRIBE_Dialog_Name::~TRIBE_Dialog_Name — real pass (EH-framed)
// VA: 004A6F60
#include "../../include/game_globals.h"

void __fastcall dtor_TRIBE_Dialog_Name(void* _this, int _)
{
    // Delete 5 child panels at +0x490..0x4A0
    int i;
    for (i = 0; i < 5; i++)
        ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)_this + 0x490 + i * 4);
    // Base dtor
    ((void(__fastcall*)(void*,int))0x473E40)(_this, 0);  // TDialogPanel::~TDialogPanel
}
