// UnitAIModule::moveTo (1) — real pass
// VA: 00416AF0
#include "../../include/game_globals.h"

extern void* __fastcall _worldObj(void* world, int _, int id);

int __fastcall moveTo(void* _this, int _, int targetId, int flag)
{
    if (!flag && *(int*)((char*)_this + 0x30) != -1) return 0;
    void* unit = *(void**)((char*)_this + 4);
    int r = (*(int(__stdcall**)(int,int))(*(int*)unit + 0x15C))(targetId, flag);
    if (r != 1) return 0;
    void* owner = *(void**)((int*)((char*)_this + 4) + 3);
    void* world = *(void**)((char*)owner + 0x3C);
    void* target = _worldObj(world, 0, targetId);
    ((void(__fastcall*)(void*,int,int))0x413970)(_this, 0, 0x262);
    if (!target) {
        ((void(__fastcall*)(void*,int,int,int,int,int))0x4175B0)(_this, 0, targetId, 0, 0, 0);
    } else {
        int x = *(int*)((char*)target + 0x38);
        int y = *(int*)((char*)target + 0x3C);
        int z = *(int*)((char*)target + 0x40);
        ((void(__fastcall*)(void*,int,int,int,int,int))0x4175B0)(_this, 0, targetId, x, y, z);
    }
    return 1;
}
