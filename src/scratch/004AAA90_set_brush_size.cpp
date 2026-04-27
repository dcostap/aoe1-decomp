// TRIBE_Screen_Sed::set_brush_size — real pass
// VA: 004AAA90
#include "../../include/game_globals.h"

extern void __fastcall _setRadioBtn(void* panel, int _);

void __fastcall set_brush_size(void* _this, int _, int sz)
{
    if (!sz) return;
    *(int*)((char*)_this + 0x4B0) = sz;
    void* btn = *(void**)((char*)_this + sz * 4 + 0x554);
    _setRadioBtn(btn, 0);
    int val;
    switch (sz - 1) {
    case 0: val = 1; break;
    case 1: val = 3; break;
    case 2: val = 5; break;
    case 3: val = 7; break;
    case 4: val = 9; break;
    default: val = 2; break;
    }
    *(short*)((char*)rge_base_game + 0x402) = (short)val;
}
