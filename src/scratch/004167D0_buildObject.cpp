// UnitAIModule::buildObject — real pass
// VA: 004167D0
#include "../../include/game_globals.h"

int __fastcall buildObject(void* _this, int _, int targetId, int flag)
{
    if (!flag && *(int*)((char*)_this + 0x30) == 0x25A) return 0;
    void* unit = *(void**)((char*)_this + 4);
    int r = (*(int(__stdcall**)(int,int))(*(int*)unit + 0x174))(targetId, flag);
    if (r != 1) return 0;
    void* owner = *(void**)((int*)((char*)_this + 4) + 3);
    void* world = *(void**)((char*)owner + 0x3C);
    void* target = ((void*(__fastcall*)(void*,int,int))0x545D30)(world, 0, targetId);
    ((void(__fastcall*)(void*,int,int))0x413970)(_this, 0, 0x25A);
    if (!target) {
        ((void(__fastcall*)(void*,int,int,int,int,int,int))0x417600)(_this, 0, targetId, -1, 0, 0, 0);
    } else {
        int x = *(int*)((char*)target + 0x38);
        int y = *(int*)((char*)target + 0x3C);
        int z = *(int*)((char*)target + 0x40);
        int grp = *(short*)(*(int*)((char*)target + 8) + 0x14);
        ((void(__fastcall*)(void*,int,int,int,int,int,int))0x417600)(_this, 0, targetId, grp, x, y, z);
    }
    return 1;
}
