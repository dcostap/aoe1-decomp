// PointMaker::SetDefaultValues
// VA: 0044AB90
#include <string.h>

void __fastcall SetDefaultValues_PointMaker(void* _this, int _)
{
    int two = 2;
    int three = 3;
    int val118 = 0x118;
    int zero = 0;

    *(int*)((char*)_this + 0xFC4) = two;
    *(int*)((char*)_this + 0xFFC) = two;
    *(int*)((char*)_this + 0xFC0) = three;
    *(int*)((char*)_this + 0xFD8) = val118;
    *(int*)((char*)_this + 0xFD4) = val118;
    *(int*)((char*)_this + 0xFF8) = three;
    *(int*)((char*)_this + 0x100C) = three;
    *(int*)((char*)_this + 0xFC8) = 0x32;
    *(int*)((char*)_this + 0xFCC) = 6;
    *(int*)((char*)_this + 0x1000) = 4;
    *(int*)((char*)_this + 0x1040) = 0x0F;
    *(int*)((char*)_this + 0xFD0) = zero;
    *(int*)((char*)_this + 0x1008) = 1;
    *(int*)((char*)_this + 0x1018) = 0x10;
    *(int*)((char*)_this + 0xFDC) = 0x7D0;
    memset((char*)_this + 8, 0, 0xFA0);
    *(int*)((char*)_this + 0x1030) = zero;
    *(int*)((char*)_this + 0x1034) = zero;
    *(int*)((char*)_this + 0x103C) = zero;
    *(int*)((char*)_this + 0x1038) = zero;
}
