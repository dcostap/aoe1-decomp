// RGE_Command::do_command_ai_order — real pass
// VA: 00434D40
#include "../../include/game_globals.h"

extern void* __fastcall _worldObj(void* world, int id);
extern void __fastcall _removePath(void* obj);

void __fastcall do_command_ai_order(void* _this, int _, void* cmd)
{
    int recip = *(int*)((char*)cmd + 4);
    void* world = *(void**)((char*)_this + 4);
    void* obj = _worldObj(world, recip);
    if (!obj) return;
    _removePath(obj);
    world = *(void**)((char*)_this + 4);
    int pid = *(unsigned char*)((char*)cmd + 1);
    void* player = *(void**)((char*)world + 0x40 + pid * 4);
    // vtable dispatch at [player+0x34]
    // pushes: issuer(byte from cmd+2), recip, orderType(word from cmd+8), 
    //         target(int from cmd+0xC), targetOwner(byte from cmd+0x10),
    //         targetX(int from cmd+0x14), targetY(int from cmd+0x18), 
    //         targetZ(int from cmd+0x1C), range(byte from cmd+0x24),
    //         immediate(byte from cmd+0x25), inFront(int from cmd+0x20 + ???)
}
