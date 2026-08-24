// TVerticalSliderPanel::setup
// VA: 0047BD40
// PDB: pnl_sld.cpp:39-54

#include "../../include/pnl_sld_context.h"

long TVerticalSliderPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, long param_9, long param_10, long param_11, long param_12, int param_13, int param_14)
{
    *(int*)((char*)this + 0x1C4) = param_13;
    *(int*)((char*)this + 0x1C8) = param_14;

    if (((TScrollBarPanel*)this)->setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0, 0, param_8, 0, param_9, 0, param_10, 0) == 0)
        return 0;

    *(long*)((char*)this + 0xFC) = param_11;
    *(long*)((char*)this + 0x100) = param_12;

    return 1;
}
