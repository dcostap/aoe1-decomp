// RGE_Command::command_add_to_group — real pass
// VA: 00435C50
#include "../../include/game_globals.h"

extern void* __fastcall _worldObj(void* world, int _, int id);
extern void __fastcall _submit(void* _this, int _, void* buf, int size);

void __fastcall command_add_to_group(void* _this, int _, int plr, int rec, int target, int angle)
{
    void* buf = calloc(1, 0x10);
    *((int*)((char*)buf + 4)) = rec;
    *((unsigned char*)buf) = 0x0E;
    *((unsigned char*)((char*)buf + 1)) = (unsigned char)plr;
    *((int*)((char*)buf + 0xC)) = target;
    *((int*)((char*)buf + 8)) = angle;
    void* world = *(void**)((char*)_this + 4);
    void* obj = _worldObj(world, 0, target);
    _submit(_this, 0, buf, 0x10);
}
