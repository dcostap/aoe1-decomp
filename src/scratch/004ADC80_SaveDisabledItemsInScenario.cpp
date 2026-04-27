// TRIBE_Screen_Sed::SaveDisabledItemsInScenario — real pass
// VA: 004ADC80
#include "../../include/game_globals.h"

extern int __fastcall _getBtnState(void* btn);
extern long __fastcall _getDropLine(void* drop);
extern void __fastcall _setDisabledTech(void* scenario, int _, int plr, int idx, int flag);

void __fastcall SaveDisabledItemsInScenario(void* _this, int _)
{
    if (*(short*)((char*)_this + 0x4B8) == 0)
        *(short*)((char*)_this + 0x4B8) = 1;
    void** btns = (void**)((char*)_this + 0x7D4);
    for (int i = 0; i < 16; i++) {
        int state = _getBtnState(btns[i]);
        void* scenario = *(void**)(*(int*)((char*)_this + 0x928) + 0x5C);
        int idx = (int)*(short*)((char*)_this + 0x4B8) - 1;
        _setDisabledTech(scenario, 0, idx, i, state ? 0 : 1);
    }
    long line = _getDropLine(*(void**)((char*)_this + 0x7CC));
    *(short*)((char*)_this + 0x4B8) = (short)(line + 1);
}
