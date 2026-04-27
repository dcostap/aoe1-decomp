// THorizontalSliderPanel::setup
// VA: 0047BE40
// PDB: pnl_sld.cpp:141-156

#include "..\..\include\game_globals.h"

class TDrawArea {
public:
    char gap_00[0x4];
};

class TPanel {
public:
    char gap_00[0x4];
};

class TScrollBarPanel {
public:
    char gap_00[0x4];
    long setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, char* p7, char* p8, char* p9, char* p10, int p11, long p12, void* p13, long p14, int orientation);
};

class THorizontalSliderPanel : public TScrollBarPanel {
public:
    char gap_1C4[0x4];
    long minScrollVal;
    long maxScrollVal;
    long minVal_drawBox;
    long maxVal_spineWidth;

    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, long param_9, long param_10, long param_11, long param_12, int param_13, int param_14);
};

long THorizontalSliderPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, long param_9, long param_10, long param_11, long param_12, int param_13, int param_14)
{
    *(int*)((char*)this + 0x1C4) = param_13;
    *(int*)((char*)this + 0x1C8) = param_14;

    if (((TScrollBarPanel*)this)->setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0, 0, param_8, 0, param_9, 0, param_10, 1) == 0)
        return 0;

    *(long*)((char*)this + 0xFC) = param_11;
    *(long*)((char*)this + 0x100) = param_12;

    return 1;
}
