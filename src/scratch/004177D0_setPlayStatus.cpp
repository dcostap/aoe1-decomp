// UnitAIModule::setPlayStatus — real pass (EH-framed)
// VA: 004177D0
#include "../../include/game_globals.h"

void __fastcall setPlayStatus(void* _this, int _, void* status)
{
    void* ps = *(void**)((char*)_this + 0x12C);
    if (!ps) {
        ps = operator new(0x1C8);
        if (ps) {
            ((void(__fastcall*)(void*,int))0x40FC30)(ps, 0);
        }
        *(void**)((char*)_this + 0x12C) = ps;
    }
    if (status) {
        ((void(__fastcall*)(void*,int,void*))0x410050)(*(void**)((char*)_this + 0x12C), 0, status);
    }
}
