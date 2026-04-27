// RGE_Command::command_stop — real pass (171B)
// VA: 004354F0
#include "../../include/game_globals.h"

extern void* __fastcall _worldObj(void* world, int _, int id);
extern void __fastcall _submit(void* _this, int _, void* buf, int size);

void __fastcall command_stop2(void* _this, int _, int* arr, int count)
{
    if (!arr || count < 1) return;
    int size = count * 4 + 2;
    void* buf = calloc(1, size);
    if (!buf) return;
    if (count > 0) {
        int* dst = (int*)((char*)buf + 2);
        for (int i = 0; i < count; i++)
            dst[i] = arr[i];
    }
    *((unsigned char*)buf) = 1;
    *((unsigned char*)((char*)buf + 1)) = (unsigned char)count;
    void* world = *(void**)((char*)_this + 4);
    int first = arr[0];
    void* obj = _worldObj(world, 0, first);
    _submit(_this, 0, buf, size);
}
