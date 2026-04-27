// DibDraw — first pass
// VA: 0043A420
#include "../../include/game_globals.h"

typedef int (__stdcall *_StretchDIBitsFn)(int, int, int, int, int, int, int, int, int, void*, void*, unsigned int, long);
extern _StretchDIBitsFn _StretchDIBits;

int __cdecl DibDraw(int hdc, int x, int y, int w, int h, void* info, int sx, int sy, int sw, int sh, long usage, unsigned int rop)
{
    if (!info) return 0;
    if (sw == -1 && sh == -1) {
        sw = *(int*)((char*)info + 4);
        sh = *(int*)((char*)info + 8);
    }
    if (w == -1 && h == -1) {
        w = sw;
        h = sh;
    }
    int bitsOff;
    if (*(int*)((char*)info + 0x10) == 3)
        bitsOff = *(int*)((char*)info) + 0xC;
    else
        bitsOff = *(int*)((char*)info) + *(int*)((char*)info + 0x20) * 4;
    return _StretchDIBits(hdc, x, y, w, h, sx, sy, sw, sh, (char*)info + bitsOff, info, rop, usage);
}
