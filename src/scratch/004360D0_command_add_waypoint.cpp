// RGE_Command::command_add_waypoint — real pass (124B)
// VA: 004360D0
#include "../../include/game_globals.h"

extern void* __fastcall _worldObj(void* world, int _, int id);
extern void __fastcall _submit(void* _this, int _, void* buf, int size);

void __fastcall command_add_waypoint2(void* _this, int _, int plr, int rec, unsigned char p3, unsigned char p4, unsigned char p5)
{
    void* buf = calloc(1, 0x18);
    *((unsigned char*)((char*)buf + 9)) = p3;
    *((unsigned char*)buf) = 0x0C;
    *((unsigned char*)((char*)buf + 1)) = (unsigned char)plr;
    *((int*)((char*)buf + 4)) = rec;
    *((unsigned char*)((char*)buf + 8)) = 1;
    *((unsigned char*)((char*)buf + 10)) = p4;
    *((unsigned char*)((char*)buf + 11)) = p5;
    void* world = *(void**)((char*)_this + 4);
    void* obj = _worldObj(world, 0, rec);
    _submit(_this, 0, buf, 0x18);
}
