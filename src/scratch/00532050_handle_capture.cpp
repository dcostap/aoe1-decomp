// RGE_Victory_Conditions::handle_capture — first pass
// VA: 00532050
#include "../../include/game_globals.h"

void __fastcall handle_capture(void* _this, int _, void* entry)
{
    void* tgt = *(void**)((char*)entry + 0x28);
    if (!tgt) return;
    if (*(char*)((char*)tgt + 0x48) > 2) {
        *(void**)((char*)entry + 0x28) = 0;
        if (*(char*)((char*)entry + 0x2E) == 0)
            *(char*)((char*)entry + 0x2E) = 1;
        return;
    }
    char state = *(char*)((char*)entry + 0x2E);
    if (state == 0) {
        void* p1 = *(void**)((char*)tgt + 0xC);
        void* p2 = *(void**)((char*)_this + 0xC);
        if (p1 == p2) {
            *(char*)((char*)entry + 0x2E) = 2;
            return;
        }
        if (!*(char*)((char*)entry + 0x2D)) return;
        if (!*(char*)((char*)p2 + 0x104)) return;
        int id1 = *(short*)((char*)p1 + 0x4A);
        if (*(char*)((char*)p2 + 0x84 + id1)) return;
        int id2 = *(short*)((char*)p2 + 0x4A);
        if (*(char*)((char*)p1 + 0x84 + id2)) return;
        if (!*(char*)((char*)p1 + 0x104)) return;
        *(char*)((char*)entry + 0x2E) = 2;
    } else if (state == 2) {
        void* p1 = *(void**)((char*)tgt + 0xC);
        void* p2 = *(void**)((char*)_this + 0xC);
        if (p1 == p2) return;
        if (!*(char*)((char*)entry + 0x2D)) {
            *(char*)((char*)entry + 0x2E) = 0;
            return;
        }
        int id1 = *(short*)((char*)p1 + 0x4A);
        if (*(char*)((char*)p2 + 0x84 + id1)) return;
    }
}
