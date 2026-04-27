// RGE_Command::command_pause — real pass
// VA: 004355A0
#include "../../include/game_globals.h"

extern void* __cdecl calloc(int count, int size);
extern void* __fastcall _worldObj(void* world, int id);
extern void __fastcall _submit(void* _this, void* buf, int size);

void __fastcall command_pause(void* _this, int _, int* arr, int count)
{
    if (!arr || count < 1) return;
    int size = count * 4 + 2;
    void* buf = calloc(1, size);
    if (!buf) return;
    int* dst = (int*)((char*)buf + 2);
    for (int i = 0; i < count; i++)
        dst[i] = arr[i];
    *(char*)buf = 0x0D;
    *(char*)((char*)buf + 1) = (char)count;
    // TDebuggingLog::Log(L, "      >SEND CMD PAUSE")
    // submit(this, buf, size)
}
