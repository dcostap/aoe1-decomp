// TRIBE_Screen_Sed::create_button — real pass
// VA: 004A8840
#include "../../include/game_globals.h"

extern int __fastcall _easyCreateBtn(void* _this, int _, void* parent, void* btnOut,
    char* t1, char* t2, int a, int b, int c, int d, int h, int w, int e);

extern void __fastcall _btnSetText(void* btnArr, int _, int slot, char* txt);
extern void __fastcall _setZOrder(void* panel, int _, int z, int flag);
extern void __fastcall _btnSetBevel(void* btnArr, int _, int count, int c0, int c1, int c2, int c3, int c4, int c5);

int __fastcall create_button(void* _this, int _, void* parent, void* btnOut,
    char* t1, char* t2, char* t3, char* t4)
{
    int ok = _easyCreateBtn(_this, 0, parent, btnOut, t1, t2, 0, 0, 0, 0, 10, 1, 0);
    if (!ok) return 0;
    if (t3) _btnSetText(*(void**)btnOut, 0, 2, t3);
    if (t4) _btnSetText(*(void**)btnOut, 0, 3, t4);
    _setZOrder(*(void**)btnOut, 0, 1, 0);
    (*(void(__stdcall**)(int))(*(*(int**)btnOut)))(0);
    if (*(int*)((char*)_this + 0x31C)) {
        int c0 = *(unsigned char*)((char*)_this + 0x320);
        int c1 = *(unsigned char*)((char*)_this + 0x321);
        int c2 = *(unsigned char*)((char*)_this + 0x322);
        int c3 = *(unsigned char*)((char*)_this + 0x323);
        int c4 = *(unsigned char*)((char*)_this + 0x324);
        int c5 = *(unsigned char*)((char*)_this + 0x325);
        _btnSetBevel(*(void**)btnOut, 0, 3, c0, c1, c2, c3, c4, c5);
    }
    return 1;
}
