// UnitAIModule::convertObject — action wrapper family
// VA: 00416550
#include "../../include/game_globals.h"

extern void* __fastcall _worldObj(void* world, int _, int id);
extern void __fastcall _setCurAction(void* _this, int _, int action);
extern void __fastcall _setCurTarget(void* _this, int _, int id, int grp, int x, int y, int z);

int __fastcall convertObject(void* _this, int _, int targetId, int flag)
{
    if (!flag && *(int*)((char*)_this + 0x30) == 0x25C) return 0;
    void* unit = *(void**)((char*)_this + 4);
    int r = (*(int(__stdcall**)(int,int))(*(int*)unit + 0x16C))(targetId, flag);
    if (r != 1) return 0;
    void* world = *(void**)(*((int**)((char*)_this + 4))[3] + 0x3C);
    void* target = _worldObj(world, 0, targetId);
    _setCurAction(_this, 0, 0x25C);
    if (!target) {
        _setCurTarget(_this, 0, targetId, -1, 0, 0, 0);
    } else {
        int x = *(int*)((char*)target + 0x38);
        int y = *(int*)((char*)target + 0x3C);
        int z = *(int*)((char*)target + 0x40);
        int grp = *(short*)(*(int*)((char*)target + 8) + 0x14);
        _setCurTarget(_this, 0, targetId, grp, x, y, z);
    }
    return 1;
}
