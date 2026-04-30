// RGE_Victory_Conditions::handle_destroy_all — first pass
// VA: 005324A0
#include "../../include/game_globals.h"

void __fastcall handle_destroy_all(void* _this, int _, void* entry)
{
    if (*(char*)((char*)entry + 0x2E)) return;
    void* tp = *(void**)((char*)entry + 8);
    if (tp) {
        void* lst = *(void**)((char*)tp + 0x28);
        void* node = *(void**)((char*)lst + 4);
        while (node) {
            void* obj = *(void**)node;
            if (*(char*)((char*)obj + 0x48) == 7)
                (*(int*)((char*)entry + 0x20))++;
            node = *(void**)((char*)node + 4);
        }
    } else {
        void* player = *(void**)((char*)_this + 0xC);
        void* world = *(void**)((char*)player + 0x3C);
        int num = *(short*)((char*)world + 0x3C);
        void** players = *(void***)((char*)world + 0x40);
        for (int i = 0; i < num; i++) {
            if (*(char*)((char*)player + 0x84 + i)) {
                void* lst = *(void**)((char*)players[i] + 0x28);
                void* node = *(void**)((char*)lst + 4);
                while (node) {
                    void* obj = *(void**)node;
                    if (*(char*)((char*)obj + 0x48) == 7)
                        (*(int*)((char*)entry + 0x20))++;
                    node = *(void**)((char*)node + 4);
                }
                player = *(void**)((char*)_this + 0xC);
            }
        }
    }
    if (*(int*)((char*)entry + 0x20) >= *(int*)((char*)entry + 0x1C))
        *(char*)((char*)entry + 0x2E) = 2;
}
