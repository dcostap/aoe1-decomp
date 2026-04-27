// RGE_Victory_Conditions::handle_bring_object — first pass
// VA: 00532610
#include "../../include/game_globals.h"

void __fastcall handle_bring_object(void* _this, int _, void* entry)
{
    if (*(char*)((char*)entry + 0x2E)) return;
    void* tp = *(void**)((char*)entry + 8);
    if (!tp) return;
    void* lst = *(void**)((char*)tp + 0x28);
    void* node = *(void**)((char*)lst + 4);
    while (node) {
        void* obj = *(void**)node;
        void* mo = *(void**)((char*)obj + 8);
        int cid = *(short*)((char*)mo + 0x12);
        if (cid == *(int*)((char*)entry + 4))
            (*(int*)((char*)entry + 0x20))++;
        node = *(void**)((char*)node + 4);
    }
    if (*(int*)((char*)entry + 0x20) >= *(int*)((char*)entry + 0x1C))
        *(char*)((char*)entry + 0x2E) = 2;
}
