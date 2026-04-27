// UnitAIModule::attackObject — real pass
// VA: 00416340
#include "../../include/game_globals.h"

extern void* __fastcall _worldObj(void* world, int _, int id);
extern void __fastcall _setCurAction(void* _this, int _, int action);
extern void __fastcall _setCurTarget(void* _this, int _, int id, int x, int y, int z);

int __fastcall attackObject(void* _this, int _, int targetId, int flag)
{
    if (!flag && *(int*)((char*)_this + 0x30) != -1) return 0;
    void* unit = *(void**)((char*)_this + 4);
    void* world = *(void**)(*((int**)((char*)_this + 4))[3] + 0x3C);
    void* target = _worldObj(world, 0, targetId);
    if (!target) return 0;
    int r2 = (*(int(__stdcall**)(void*))(*(int*)_this + 0x50))(target);
    if (!r2) return 0;
    r2 = (*(int(__stdcall**)(int,int))(*(int*)unit + 0x150))(flag, targetId);
    if (r2 != 1) return 0;
    _setCurAction(_this, 0, 0x258);
    int x = *(int*)((char*)target + 0x38);
    int y = *(int*)((char*)target + 0x3C);
    int z = *(int*)((char*)target + 0x40);
    _setCurTarget(_this, 0, targetId, x, y, z);
    return 1;
}
