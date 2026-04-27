// RGE_Victory_Conditions::handle_attribute — first pass
// VA: 005326F0
#include "../../include/game_globals.h"

extern float* __fastcall _getAttribs(void* player);
extern float* __fastcall _getOtherAttribs(void* player);
extern int __fastcall _getPlayerNum(void* world);
extern void* __fastcall _getPlayerFromList(void* world, int idx);
extern int __fastcall _getAllyFlag(void* entry);
extern int __fastcall _getAlliedVictory(void* player);
extern int __fastcall _getRelations(void* player, int id);
extern int __fastcall _getPlayerId(void* player);

int __fastcall handle_attribute(void* _this, int _, void* entry)
{
    void* player = *(void**)((char*)_this + 0xC);
    if (!player) return 0;
    int attr_idx = *(int*)((char*)entry + 0x1C);
    float total = *(float*)((char*)player + 0x50 + attr_idx * 4);
    if (*(char*)((char*)entry + 0x2D) && *(char*)((char*)player + 0x104)) {
        void* world = *(void**)((char*)player + 0x3C);
        int num = *(short*)((char*)world + 0x3C);
        void* players = *(void**)((char*)world + 0x40);
        int id = *(short*)((char*)player + 0x4A);
        for (int i = num - 1; i >= 0; i--) {
            if (*(char*)((char*)player + 0x84 + i) == 0) {
                void* p = ((void**)players)[i];
                if (*(char*)((char*)p + 0x84 + id) == 0 && i != id && *(char*)((char*)p + 0x104)) {
                    total += *(float*)((char*)p + 0x50 + attr_idx * 4);
                }
            }
        }
    }
    float threshold = (float)*(int*)((char*)entry + 0x20);
    if (threshold <= total)
        *(char*)((char*)entry + 0x2E) = 2;
    else
        *(char*)((char*)entry + 0x2E) = 0;
    return 0;
}
