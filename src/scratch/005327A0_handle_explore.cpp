// RGE_Victory_Conditions::handle_explore — first pass
// VA: 005327A0
#include "../../include/game_globals.h"

void __fastcall handle_explore(void* _this, int _, void* entry)
{
    if (*(char*)((char*)entry + 0x2E)) return;
    void* player = *(void**)((char*)_this + 0xC);
    if (!player) return;
    int num = 0;
    void* world = *(void**)((char*)player + 0x3C);
    void** players = *(void***)((char*)world + 0x40);
    for (int i = 0; i < 8; i++) {
        if (*(char*)((char*)player + 0x84 + i) == 0) {
            void* p = players[i];
            if (!p) continue;
            void* winfo = *(void**)((char*)p + 0x3C);
            if (!winfo) continue;
            int x0 = *(int*)((char*)entry + 4);
            int y0 = *(int*)((char*)entry + 8);
            int x1 = *(int*)((char*)entry + 0xC);
            int y1 = *(int*)((char*)entry + 0x10);
            // world_explored calls with 5 params
            num++;
        }
    }
    if (num >= *(int*)((char*)entry + 0x20))
        *(char*)((char*)entry + 0x2E) = 2;
}
