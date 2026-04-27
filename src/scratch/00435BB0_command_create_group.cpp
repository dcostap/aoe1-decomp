// RGE_Command::command_create_group — real pass (153B)
// VA: 00435BB0
#include "../../include/game_globals.h"

extern void* __fastcall _worldObj(void* world, int _, int id);
extern void __fastcall _submit(void* _this, int _, void* buf, int size);

void __fastcall command_create_group(void* _this, int _, unsigned char plr, int unk, int* units, int count, int angle)
{
    void* buf = calloc(1, 0x74);
    *((unsigned char*)buf) = 8;
    *((unsigned char*)((char*)buf + 1)) = plr;
    *((int*)((char*)buf + 4)) = unk;
    if (count > 0) {
        int* dst = (int*)((char*)buf + 0xC);
        for (int i = 0; i < count; i++)
            dst[i] = units[i];
    }
    *((unsigned char*)((char*)buf + 0x70)) = (unsigned char)count;
    *((int*)((char*)buf + 8)) = angle;
    void* world = *(void**)((char*)_this + 4);
    int first = units[0];
    void* obj = _worldObj(world, 0, first);
    _submit(_this, 0, buf, 0x74);
}
