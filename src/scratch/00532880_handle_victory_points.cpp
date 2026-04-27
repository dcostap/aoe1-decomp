// RGE_Victory_Conditions::handle_victory_points — first pass
// VA: 00532880
#include "../../include/game_globals.h"

extern int __fastcall _getVP(void* vc);

int __fastcall handle_victory_points(void* _this, int _, void* entry)
{
    void* player = *(void**)((char*)_this + 0xC);
    if (!player) return 0;
    int total = *(int*)((char*)_this + 0x1C);
    int count = 1;
    if (*(char*)((char*)entry + 0x2D) && *(char*)((char*)player + 0x104)) {
        void* world = *(void**)((char*)player + 0x3C);
        int num = *(short*)((char*)world + 0x3C);
        void* players = *(void**)((char*)world + 0x40);
        int id = *(short*)((char*)player + 0x4A);
        for (int i = num - 1; i >= 0; i--) {
            if (*(char*)((char*)player + 0x84 + i) == 0) {
                void* p = ((void**)players)[i];
                if (*(char*)((char*)p + 0x84 + id) == 0 && i != id && *(char*)((char*)p + 0x104)) {
                    void* vc = *(void**)((char*)p + 0x34);
                    total += _getVP(vc);
                    count++;
                }
            }
        }
    }
    if (total / count >= *(int*)((char*)entry + 0x20))
        *(char*)((char*)entry + 0x2E) = 2;
    return 0;
}
